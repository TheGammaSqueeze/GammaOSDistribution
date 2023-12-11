// Copyright 2020, The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//! This crate implements the IKeystoreSecurityLevel interface.

use crate::attestation_key_utils::{get_attest_key_info, AttestationKeyInfo};
use crate::audit_log::{
    log_key_deleted, log_key_generated, log_key_imported, log_key_integrity_violation,
};
use crate::database::{BlobInfo, CertificateInfo, KeyIdGuard};
use crate::error::{self, map_km_error, map_or_log_err, Error, ErrorCode};
use crate::globals::{DB, ENFORCEMENTS, LEGACY_IMPORTER, SUPER_KEY};
use crate::key_parameter::KeyParameter as KsKeyParam;
use crate::key_parameter::KeyParameterValue as KsKeyParamValue;
use crate::metrics_store::log_key_creation_event_stats;
use crate::remote_provisioning::RemProvState;
use crate::super_key::{KeyBlob, SuperKeyManager};
use crate::utils::{
    check_device_attestation_permissions, check_key_permission, is_device_id_attestation_tag,
    key_characteristics_to_internal, uid_to_android_user, watchdog as wd, Asp,
};
use crate::{
    database::{
        BlobMetaData, BlobMetaEntry, DateTime, KeyEntry, KeyEntryLoadBits, KeyMetaData,
        KeyMetaEntry, KeyType, SubComponentType, Uuid,
    },
    operation::KeystoreOperation,
    operation::LoggingInfo,
    operation::OperationDb,
    permission::KeyPerm,
};
use crate::{globals::get_keymint_device, id_rotation::IdRotationState};
use android_hardware_security_keymint::aidl::android::hardware::security::keymint::{
    Algorithm::Algorithm, AttestationKey::AttestationKey,
    HardwareAuthenticatorType::HardwareAuthenticatorType, IKeyMintDevice::IKeyMintDevice,
    KeyCreationResult::KeyCreationResult, KeyFormat::KeyFormat,
    KeyMintHardwareInfo::KeyMintHardwareInfo, KeyParameter::KeyParameter,
    KeyParameterValue::KeyParameterValue, SecurityLevel::SecurityLevel, Tag::Tag,
};
use android_hardware_security_keymint::binder::{BinderFeatures, Strong, ThreadState};
use android_system_keystore2::aidl::android::system::keystore2::{
    AuthenticatorSpec::AuthenticatorSpec, CreateOperationResponse::CreateOperationResponse,
    Domain::Domain, EphemeralStorageKeyResponse::EphemeralStorageKeyResponse,
    IKeystoreOperation::IKeystoreOperation, IKeystoreSecurityLevel::BnKeystoreSecurityLevel,
    IKeystoreSecurityLevel::IKeystoreSecurityLevel, KeyDescriptor::KeyDescriptor,
    KeyMetadata::KeyMetadata, KeyParameters::KeyParameters, ResponseCode::ResponseCode,
};
use anyhow::{anyhow, Context, Result};
use std::convert::TryInto;
use std::time::SystemTime;

/// Implementation of the IKeystoreSecurityLevel Interface.
pub struct KeystoreSecurityLevel {
    security_level: SecurityLevel,
    keymint: Asp,
    hw_info: KeyMintHardwareInfo,
    km_uuid: Uuid,
    operation_db: OperationDb,
    rem_prov_state: RemProvState,
    id_rotation_state: IdRotationState,
}

// Blob of 32 zeroes used as empty masking key.
static ZERO_BLOB_32: &[u8] = &[0; 32];

// Per RFC 5280 4.1.2.5, an undefined expiration (not-after) field should be set to GeneralizedTime
// 999912312359559, which is 253402300799000 ms from Jan 1, 1970.
const UNDEFINED_NOT_AFTER: i64 = 253402300799000i64;

impl KeystoreSecurityLevel {
    /// Creates a new security level instance wrapped in a
    /// BnKeystoreSecurityLevel proxy object. It also enables
    /// `BinderFeatures::set_requesting_sid` on the new interface, because
    /// we need it for checking keystore permissions.
    pub fn new_native_binder(
        security_level: SecurityLevel,
        id_rotation_state: IdRotationState,
    ) -> Result<(Strong<dyn IKeystoreSecurityLevel>, Uuid)> {
        let (dev, hw_info, km_uuid) = get_keymint_device(&security_level)
            .context("In KeystoreSecurityLevel::new_native_binder.")?;
        let result = BnKeystoreSecurityLevel::new_binder(
            Self {
                security_level,
                keymint: dev,
                hw_info,
                km_uuid,
                operation_db: OperationDb::new(),
                rem_prov_state: RemProvState::new(security_level, km_uuid),
                id_rotation_state,
            },
            BinderFeatures { set_requesting_sid: true, ..BinderFeatures::default() },
        );
        Ok((result, km_uuid))
    }

    fn watch_millis(&self, id: &'static str, millis: u64) -> Option<wd::WatchPoint> {
        let sec_level = self.security_level;
        wd::watch_millis_with(id, millis, move || format!("SecurityLevel {:?}", sec_level))
    }

    fn store_new_key(
        &self,
        key: KeyDescriptor,
        creation_result: KeyCreationResult,
        user_id: u32,
        flags: Option<i32>,
    ) -> Result<KeyMetadata> {
        let KeyCreationResult {
            keyBlob: key_blob,
            keyCharacteristics: key_characteristics,
            certificateChain: mut certificate_chain,
        } = creation_result;

        let mut cert_info: CertificateInfo = CertificateInfo::new(
            match certificate_chain.len() {
                0 => None,
                _ => Some(certificate_chain.remove(0).encodedCertificate),
            },
            match certificate_chain.len() {
                0 => None,
                _ => Some(
                    certificate_chain
                        .iter()
                        .map(|c| c.encodedCertificate.iter())
                        .flatten()
                        .copied()
                        .collect(),
                ),
            },
        );

        let mut key_parameters = key_characteristics_to_internal(key_characteristics);

        key_parameters.push(KsKeyParam::new(
            KsKeyParamValue::UserID(user_id as i32),
            SecurityLevel::SOFTWARE,
        ));

        let creation_date = DateTime::now().context("Trying to make creation time.")?;

        let key = match key.domain {
            Domain::BLOB => KeyDescriptor {
                domain: Domain::BLOB,
                blob: Some(key_blob.to_vec()),
                ..Default::default()
            },
            _ => DB
                .with::<_, Result<KeyDescriptor>>(|db| {
                    let mut db = db.borrow_mut();

                    let (key_blob, mut blob_metadata) = SUPER_KEY
                        .handle_super_encryption_on_key_init(
                            &mut db,
                            &LEGACY_IMPORTER,
                            &(key.domain),
                            &key_parameters,
                            flags,
                            user_id,
                            &key_blob,
                        )
                        .context("In store_new_key. Failed to handle super encryption.")?;

                    let mut key_metadata = KeyMetaData::new();
                    key_metadata.add(KeyMetaEntry::CreationDate(creation_date));
                    blob_metadata.add(BlobMetaEntry::KmUuid(self.km_uuid));

                    let key_id = db
                        .store_new_key(
                            &key,
                            KeyType::Client,
                            &key_parameters,
                            &BlobInfo::new(&key_blob, &blob_metadata),
                            &cert_info,
                            &key_metadata,
                            &self.km_uuid,
                        )
                        .context("In store_new_key.")?;
                    Ok(KeyDescriptor {
                        domain: Domain::KEY_ID,
                        nspace: key_id.id(),
                        ..Default::default()
                    })
                })
                .context("In store_new_key.")?,
        };

        Ok(KeyMetadata {
            key,
            keySecurityLevel: self.security_level,
            certificate: cert_info.take_cert(),
            certificateChain: cert_info.take_cert_chain(),
            authorizations: crate::utils::key_parameters_to_authorizations(key_parameters),
            modificationTimeMs: creation_date.to_millis_epoch(),
        })
    }

    fn create_operation(
        &self,
        key: &KeyDescriptor,
        operation_parameters: &[KeyParameter],
        forced: bool,
    ) -> Result<CreateOperationResponse> {
        let caller_uid = ThreadState::get_calling_uid();
        // We use `scoping_blob` to extend the life cycle of the blob loaded from the database,
        // so that we can use it by reference like the blob provided by the key descriptor.
        // Otherwise, we would have to clone the blob from the key descriptor.
        let scoping_blob: Vec<u8>;
        let (km_blob, key_properties, key_id_guard, blob_metadata) = match key.domain {
            Domain::BLOB => {
                check_key_permission(KeyPerm::use_(), key, &None)
                    .context("In create_operation: checking use permission for Domain::BLOB.")?;
                if forced {
                    check_key_permission(KeyPerm::req_forced_op(), key, &None).context(
                        "In create_operation: checking forced permission for Domain::BLOB.",
                    )?;
                }
                (
                    match &key.blob {
                        Some(blob) => blob,
                        None => {
                            return Err(Error::sys()).context(concat!(
                                "In create_operation: Key blob must be specified when",
                                " using Domain::BLOB."
                            ))
                        }
                    },
                    None,
                    None,
                    BlobMetaData::new(),
                )
            }
            _ => {
                let super_key =
                    SUPER_KEY.get_per_boot_key_by_user_id(uid_to_android_user(caller_uid));
                let (key_id_guard, mut key_entry) = DB
                    .with::<_, Result<(KeyIdGuard, KeyEntry)>>(|db| {
                        LEGACY_IMPORTER.with_try_import(key, caller_uid, super_key, || {
                            db.borrow_mut().load_key_entry(
                                &key,
                                KeyType::Client,
                                KeyEntryLoadBits::KM,
                                caller_uid,
                                |k, av| {
                                    check_key_permission(KeyPerm::use_(), k, &av)?;
                                    if forced {
                                        check_key_permission(KeyPerm::req_forced_op(), k, &av)?;
                                    }
                                    Ok(())
                                },
                            )
                        })
                    })
                    .context("In create_operation: Failed to load key blob.")?;

                let (blob, blob_metadata) =
                    key_entry.take_key_blob_info().ok_or_else(Error::sys).context(concat!(
                        "In create_operation: Successfully loaded key entry, ",
                        "but KM blob was missing."
                    ))?;
                scoping_blob = blob;

                (
                    &scoping_blob,
                    Some((key_id_guard.id(), key_entry.into_key_parameters())),
                    Some(key_id_guard),
                    blob_metadata,
                )
            }
        };

        let purpose = operation_parameters.iter().find(|p| p.tag == Tag::PURPOSE).map_or(
            Err(Error::Km(ErrorCode::INVALID_ARGUMENT))
                .context("In create_operation: No operation purpose specified."),
            |kp| match kp.value {
                KeyParameterValue::KeyPurpose(p) => Ok(p),
                _ => Err(Error::Km(ErrorCode::INVALID_ARGUMENT))
                    .context("In create_operation: Malformed KeyParameter."),
            },
        )?;

        // Remove Tag::PURPOSE from the operation_parameters, since some keymaster devices return
        // an error on begin() if Tag::PURPOSE is in the operation_parameters.
        let op_params: Vec<KeyParameter> =
            operation_parameters.iter().filter(|p| p.tag != Tag::PURPOSE).cloned().collect();
        let operation_parameters = op_params.as_slice();

        let (immediate_hat, mut auth_info) = ENFORCEMENTS
            .authorize_create(
                purpose,
                key_properties.as_ref(),
                operation_parameters.as_ref(),
                self.hw_info.timestampTokenRequired,
            )
            .context("In create_operation.")?;

        let km_blob = SUPER_KEY
            .unwrap_key_if_required(&blob_metadata, km_blob)
            .context("In create_operation. Failed to handle super encryption.")?;

        let km_dev: Strong<dyn IKeyMintDevice> = self
            .keymint
            .get_interface()
            .context("In create_operation: Failed to get KeyMint device")?;

        let (begin_result, upgraded_blob) = self
            .upgrade_keyblob_if_required_with(
                &*km_dev,
                key_id_guard,
                &km_blob,
                blob_metadata.km_uuid().copied(),
                &operation_parameters,
                |blob| loop {
                    match map_km_error({
                        let _wp = self.watch_millis(
                            "In KeystoreSecurityLevel::create_operation: calling begin",
                            500,
                        );
                        km_dev.begin(purpose, blob, &operation_parameters, immediate_hat.as_ref())
                    }) {
                        Err(Error::Km(ErrorCode::TOO_MANY_OPERATIONS)) => {
                            self.operation_db.prune(caller_uid, forced)?;
                            continue;
                        }
                        v @ Err(Error::Km(ErrorCode::INVALID_KEY_BLOB)) => {
                            if let Some((key_id, _)) = key_properties {
                                if let Ok(Some(key)) =
                                    DB.with(|db| db.borrow_mut().load_key_descriptor(key_id))
                                {
                                    log_key_integrity_violation(&key);
                                } else {
                                    log::error!("Failed to load key descriptor for audit log");
                                }
                            }
                            return v;
                        }
                        v => return v,
                    }
                },
            )
            .context("In create_operation: Failed to begin operation.")?;

        let operation_challenge = auth_info.finalize_create_authorization(begin_result.challenge);

        let op_params: Vec<KeyParameter> = operation_parameters.to_vec();

        let operation = match begin_result.operation {
            Some(km_op) => self.operation_db.create_operation(
                km_op,
                caller_uid,
                auth_info,
                forced,
                LoggingInfo::new(self.security_level, purpose, op_params, upgraded_blob.is_some()),
            ),
            None => {
                return Err(Error::sys()).context(concat!(
                    "In create_operation: Begin operation returned successfully, ",
                    "but did not return a valid operation."
                ))
            }
        };

        let op_binder: binder::public_api::Strong<dyn IKeystoreOperation> =
            KeystoreOperation::new_native_binder(operation)
                .as_binder()
                .into_interface()
                .context("In create_operation: Failed to create IKeystoreOperation.")?;

        Ok(CreateOperationResponse {
            iOperation: Some(op_binder),
            operationChallenge: operation_challenge,
            parameters: match begin_result.params.len() {
                0 => None,
                _ => Some(KeyParameters { keyParameter: begin_result.params }),
            },
            // An upgraded blob should only be returned if the caller has permission
            // to use Domain::BLOB keys. If we got to this point, we already checked
            // that the caller had that permission.
            upgradedBlob: if key.domain == Domain::BLOB { upgraded_blob } else { None },
        })
    }

    fn add_required_parameters(
        &self,
        uid: u32,
        params: &[KeyParameter],
        key: &KeyDescriptor,
    ) -> Result<Vec<KeyParameter>> {
        let mut result = params.to_vec();

        // Unconditionally add the CREATION_DATETIME tag and prevent callers from
        // specifying it.
        if params.iter().any(|kp| kp.tag == Tag::CREATION_DATETIME) {
            return Err(Error::Rc(ResponseCode::INVALID_ARGUMENT)).context(
                "In KeystoreSecurityLevel::add_required_parameters: \
                Specifying Tag::CREATION_DATETIME is not allowed.",
            );
        }

        // Add CREATION_DATETIME only if the backend version Keymint V1 (100) or newer.
        if self.hw_info.versionNumber >= 100 {
            result.push(KeyParameter {
                tag: Tag::CREATION_DATETIME,
                value: KeyParameterValue::DateTime(
                    SystemTime::now()
                        .duration_since(SystemTime::UNIX_EPOCH)
                        .context(
                            "In KeystoreSecurityLevel::add_required_parameters: \
                        Failed to get epoch time.",
                        )?
                        .as_millis()
                        .try_into()
                        .context(
                            "In KeystoreSecurityLevel::add_required_parameters: \
                        Failed to convert epoch time.",
                        )?,
                ),
            });
        }

        // If there is an attestation challenge we need to get an application id.
        if params.iter().any(|kp| kp.tag == Tag::ATTESTATION_CHALLENGE) {
            let aaid = {
                let _wp = self.watch_millis(
                    "In KeystoreSecurityLevel::add_required_parameters calling: get_aaid",
                    500,
                );
                keystore2_aaid::get_aaid(uid).map_err(|e| {
                    anyhow!(format!("In add_required_parameters: get_aaid returned status {}.", e))
                })
            }?;

            result.push(KeyParameter {
                tag: Tag::ATTESTATION_APPLICATION_ID,
                value: KeyParameterValue::Blob(aaid),
            });
        }

        if params.iter().any(|kp| kp.tag == Tag::INCLUDE_UNIQUE_ID) {
            check_key_permission(KeyPerm::gen_unique_id(), key, &None).context(concat!(
                "In add_required_parameters: ",
                "Caller does not have the permission to generate a unique ID"
            ))?;
            if self.id_rotation_state.had_factory_reset_since_id_rotation().context(
                "In add_required_parameters: Call to had_factory_reset_since_id_rotation failed.",
            )? {
                result.push(KeyParameter {
                    tag: Tag::RESET_SINCE_ID_ROTATION,
                    value: KeyParameterValue::BoolValue(true),
                })
            }
        }

        // If the caller requests any device identifier attestation tag, check that they hold the
        // correct Android permission.
        if params.iter().any(|kp| is_device_id_attestation_tag(kp.tag)) {
            check_device_attestation_permissions().context(concat!(
                "In add_required_parameters: ",
                "Caller does not have the permission to attest device identifiers."
            ))?;
        }

        // If we are generating/importing an asymmetric key, we need to make sure
        // that NOT_BEFORE and NOT_AFTER are present.
        match params.iter().find(|kp| kp.tag == Tag::ALGORITHM) {
            Some(KeyParameter { tag: _, value: KeyParameterValue::Algorithm(Algorithm::RSA) })
            | Some(KeyParameter { tag: _, value: KeyParameterValue::Algorithm(Algorithm::EC) }) => {
                if !params.iter().any(|kp| kp.tag == Tag::CERTIFICATE_NOT_BEFORE) {
                    result.push(KeyParameter {
                        tag: Tag::CERTIFICATE_NOT_BEFORE,
                        value: KeyParameterValue::DateTime(0),
                    })
                }
                if !params.iter().any(|kp| kp.tag == Tag::CERTIFICATE_NOT_AFTER) {
                    result.push(KeyParameter {
                        tag: Tag::CERTIFICATE_NOT_AFTER,
                        value: KeyParameterValue::DateTime(UNDEFINED_NOT_AFTER),
                    })
                }
            }
            _ => {}
        }
        Ok(result)
    }

    fn generate_key(
        &self,
        key: &KeyDescriptor,
        attest_key_descriptor: Option<&KeyDescriptor>,
        params: &[KeyParameter],
        flags: i32,
        _entropy: &[u8],
    ) -> Result<KeyMetadata> {
        if key.domain != Domain::BLOB && key.alias.is_none() {
            return Err(error::Error::Km(ErrorCode::INVALID_ARGUMENT))
                .context("In generate_key: Alias must be specified");
        }
        let caller_uid = ThreadState::get_calling_uid();

        let key = match key.domain {
            Domain::APP => KeyDescriptor {
                domain: key.domain,
                nspace: caller_uid as i64,
                alias: key.alias.clone(),
                blob: None,
            },
            _ => key.clone(),
        };

        // generate_key requires the rebind permission.
        // Must return on error for security reasons.
        check_key_permission(KeyPerm::rebind(), &key, &None).context("In generate_key.")?;

        let attestation_key_info = match (key.domain, attest_key_descriptor) {
            (Domain::BLOB, _) => None,
            _ => DB
                .with(|db| {
                    get_attest_key_info(
                        &key,
                        caller_uid,
                        attest_key_descriptor,
                        params,
                        &self.rem_prov_state,
                        &mut db.borrow_mut(),
                    )
                })
                .context("In generate_key: Trying to get an attestation key")?,
        };
        let params = self
            .add_required_parameters(caller_uid, params, &key)
            .context("In generate_key: Trying to get aaid.")?;

        let km_dev: Strong<dyn IKeyMintDevice> = self.keymint.get_interface()?;

        let creation_result = match attestation_key_info {
            Some(AttestationKeyInfo::UserGenerated {
                key_id_guard,
                blob,
                blob_metadata,
                issuer_subject,
            }) => self
                .upgrade_keyblob_if_required_with(
                    &*km_dev,
                    Some(key_id_guard),
                    &KeyBlob::Ref(&blob),
                    blob_metadata.km_uuid().copied(),
                    &params,
                    |blob| {
                        let attest_key = Some(AttestationKey {
                            keyBlob: blob.to_vec(),
                            attestKeyParams: vec![],
                            issuerSubjectName: issuer_subject.clone(),
                        });
                        map_km_error({
                            let _wp = self.watch_millis(
                                concat!(
                                    "In KeystoreSecurityLevel::generate_key (UserGenerated): ",
                                    "calling generate_key."
                                ),
                                5000, // Generate can take a little longer.
                            );
                            km_dev.generateKey(&params, attest_key.as_ref())
                        })
                    },
                )
                .context("In generate_key: Using user generated attestation key.")
                .map(|(result, _)| result),
            Some(AttestationKeyInfo::RemoteProvisioned {
                key_id_guard,
                attestation_key,
                attestation_certs,
            }) => self
                .upgrade_keyblob_if_required_with(
                    &*km_dev,
                    Some(key_id_guard),
                    &KeyBlob::Ref(&attestation_key.keyBlob),
                    Some(self.rem_prov_state.get_uuid()),
                    &[],
                    |blob| {
                        map_km_error({
                            let _wp = self.watch_millis(
                                concat!(
                                    "In KeystoreSecurityLevel::generate_key (RemoteProvisioned): ",
                                    "calling generate_key.",
                                ),
                                5000, // Generate can take a little longer.
                            );
                            let dynamic_attest_key = Some(AttestationKey {
                                keyBlob: blob.to_vec(),
                                attestKeyParams: vec![],
                                issuerSubjectName: attestation_key.issuerSubjectName.clone(),
                            });
                            km_dev.generateKey(&params, dynamic_attest_key.as_ref())
                        })
                    },
                )
                .context("While generating Key with remote provisioned attestation key.")
                .map(|(mut result, _)| {
                    result.certificateChain.push(attestation_certs);
                    result
                }),
            None => map_km_error({
                let _wp = self.watch_millis(
                    concat!(
                        "In KeystoreSecurityLevel::generate_key (No attestation): ",
                        "calling generate_key.",
                    ),
                    5000, // Generate can take a little longer.
                );
                km_dev.generateKey(&params, None)
            })
            .context("While generating Key without explicit attestation key."),
        }
        .context("In generate_key.")?;

        let user_id = uid_to_android_user(caller_uid);
        self.store_new_key(key, creation_result, user_id, Some(flags)).context("In generate_key.")
    }

    fn import_key(
        &self,
        key: &KeyDescriptor,
        _attestation_key: Option<&KeyDescriptor>,
        params: &[KeyParameter],
        flags: i32,
        key_data: &[u8],
    ) -> Result<KeyMetadata> {
        if key.domain != Domain::BLOB && key.alias.is_none() {
            return Err(error::Error::Km(ErrorCode::INVALID_ARGUMENT))
                .context("In import_key: Alias must be specified");
        }
        let caller_uid = ThreadState::get_calling_uid();

        let key = match key.domain {
            Domain::APP => KeyDescriptor {
                domain: key.domain,
                nspace: caller_uid as i64,
                alias: key.alias.clone(),
                blob: None,
            },
            _ => key.clone(),
        };

        // import_key requires the rebind permission.
        check_key_permission(KeyPerm::rebind(), &key, &None).context("In import_key.")?;

        let params = self
            .add_required_parameters(caller_uid, params, &key)
            .context("In import_key: Trying to get aaid.")?;

        let format = params
            .iter()
            .find(|p| p.tag == Tag::ALGORITHM)
            .ok_or(error::Error::Km(ErrorCode::INVALID_ARGUMENT))
            .context("No KeyParameter 'Algorithm'.")
            .and_then(|p| match &p.value {
                KeyParameterValue::Algorithm(Algorithm::AES)
                | KeyParameterValue::Algorithm(Algorithm::HMAC)
                | KeyParameterValue::Algorithm(Algorithm::TRIPLE_DES) => Ok(KeyFormat::RAW),
                KeyParameterValue::Algorithm(Algorithm::RSA)
                | KeyParameterValue::Algorithm(Algorithm::EC) => Ok(KeyFormat::PKCS8),
                v => Err(error::Error::Km(ErrorCode::INVALID_ARGUMENT))
                    .context(format!("Unknown Algorithm {:?}.", v)),
            })
            .context("In import_key.")?;

        let km_dev: Strong<dyn IKeyMintDevice> =
            self.keymint.get_interface().context("In import_key: Trying to get the KM device")?;
        let creation_result = map_km_error({
            let _wp =
                self.watch_millis("In KeystoreSecurityLevel::import_key: calling importKey.", 500);
            km_dev.importKey(&params, format, key_data, None /* attestKey */)
        })
        .context("In import_key: Trying to call importKey")?;

        let user_id = uid_to_android_user(caller_uid);
        self.store_new_key(key, creation_result, user_id, Some(flags)).context("In import_key.")
    }

    fn import_wrapped_key(
        &self,
        key: &KeyDescriptor,
        wrapping_key: &KeyDescriptor,
        masking_key: Option<&[u8]>,
        params: &[KeyParameter],
        authenticators: &[AuthenticatorSpec],
    ) -> Result<KeyMetadata> {
        let wrapped_data: &[u8] = match key {
            KeyDescriptor { domain: Domain::APP, blob: Some(ref blob), alias: Some(_), .. }
            | KeyDescriptor {
                domain: Domain::SELINUX, blob: Some(ref blob), alias: Some(_), ..
            } => blob,
            _ => {
                return Err(error::Error::Km(ErrorCode::INVALID_ARGUMENT)).context(format!(
                    concat!(
                        "In import_wrapped_key: Alias and blob must be specified ",
                        "and domain must be APP or SELINUX. {:?}"
                    ),
                    key
                ))
            }
        };

        if wrapping_key.domain == Domain::BLOB {
            return Err(error::Error::Km(ErrorCode::INVALID_ARGUMENT)).context(
                "In import_wrapped_key: Import wrapped key not supported for self managed blobs.",
            );
        }

        let caller_uid = ThreadState::get_calling_uid();
        let user_id = uid_to_android_user(caller_uid);

        let key = match key.domain {
            Domain::APP => KeyDescriptor {
                domain: key.domain,
                nspace: caller_uid as i64,
                alias: key.alias.clone(),
                blob: None,
            },
            Domain::SELINUX => KeyDescriptor {
                domain: Domain::SELINUX,
                nspace: key.nspace,
                alias: key.alias.clone(),
                blob: None,
            },
            _ => panic!("Unreachable."),
        };

        // Import_wrapped_key requires the rebind permission for the new key.
        check_key_permission(KeyPerm::rebind(), &key, &None).context("In import_wrapped_key.")?;

        let super_key = SUPER_KEY.get_per_boot_key_by_user_id(user_id);

        let (wrapping_key_id_guard, mut wrapping_key_entry) = DB
            .with(|db| {
                LEGACY_IMPORTER.with_try_import(&key, caller_uid, super_key, || {
                    db.borrow_mut().load_key_entry(
                        &wrapping_key,
                        KeyType::Client,
                        KeyEntryLoadBits::KM,
                        caller_uid,
                        |k, av| check_key_permission(KeyPerm::use_(), k, &av),
                    )
                })
            })
            .context("Failed to load wrapping key.")?;

        let (wrapping_key_blob, wrapping_blob_metadata) = wrapping_key_entry
            .take_key_blob_info()
            .ok_or_else(error::Error::sys)
            .context("No km_blob after successfully loading key. This should never happen.")?;

        let wrapping_key_blob =
            SUPER_KEY.unwrap_key_if_required(&wrapping_blob_metadata, &wrapping_key_blob).context(
                "In import_wrapped_key. Failed to handle super encryption for wrapping key.",
            )?;

        // km_dev.importWrappedKey does not return a certificate chain.
        // TODO Do we assume that all wrapped keys are symmetric?
        // let certificate_chain: Vec<KmCertificate> = Default::default();

        let pw_sid = authenticators
            .iter()
            .find_map(|a| match a.authenticatorType {
                HardwareAuthenticatorType::PASSWORD => Some(a.authenticatorId),
                _ => None,
            })
            .unwrap_or(-1);

        let fp_sid = authenticators
            .iter()
            .find_map(|a| match a.authenticatorType {
                HardwareAuthenticatorType::FINGERPRINT => Some(a.authenticatorId),
                _ => None,
            })
            .unwrap_or(-1);

        let masking_key = masking_key.unwrap_or(ZERO_BLOB_32);

        let km_dev: Strong<dyn IKeyMintDevice> = self.keymint.get_interface()?;
        let (creation_result, _) = self
            .upgrade_keyblob_if_required_with(
                &*km_dev,
                Some(wrapping_key_id_guard),
                &wrapping_key_blob,
                wrapping_blob_metadata.km_uuid().copied(),
                &[],
                |wrapping_blob| {
                    let _wp = self.watch_millis(
                        "In KeystoreSecurityLevel::import_wrapped_key: calling importWrappedKey.",
                        500,
                    );
                    let creation_result = map_km_error(km_dev.importWrappedKey(
                        wrapped_data,
                        wrapping_blob,
                        masking_key,
                        &params,
                        pw_sid,
                        fp_sid,
                    ))?;
                    Ok(creation_result)
                },
            )
            .context("In import_wrapped_key.")?;

        self.store_new_key(key, creation_result, user_id, None)
            .context("In import_wrapped_key: Trying to store the new key.")
    }

    fn store_upgraded_keyblob(
        key_id_guard: KeyIdGuard,
        km_uuid: Option<Uuid>,
        key_blob: &KeyBlob,
        upgraded_blob: &[u8],
    ) -> Result<()> {
        let (upgraded_blob_to_be_stored, new_blob_metadata) =
            SuperKeyManager::reencrypt_if_required(key_blob, &upgraded_blob)
                .context("In store_upgraded_keyblob: Failed to handle super encryption.")?;

        let mut new_blob_metadata = new_blob_metadata.unwrap_or_default();
        if let Some(uuid) = km_uuid {
            new_blob_metadata.add(BlobMetaEntry::KmUuid(uuid));
        }

        DB.with(|db| {
            let mut db = db.borrow_mut();
            db.set_blob(
                &key_id_guard,
                SubComponentType::KEY_BLOB,
                Some(&upgraded_blob_to_be_stored),
                Some(&new_blob_metadata),
            )
        })
        .context("In store_upgraded_keyblob: Failed to insert upgraded blob into the database.")
    }

    fn upgrade_keyblob_if_required_with<T, F>(
        &self,
        km_dev: &dyn IKeyMintDevice,
        mut key_id_guard: Option<KeyIdGuard>,
        key_blob: &KeyBlob,
        km_uuid: Option<Uuid>,
        params: &[KeyParameter],
        f: F,
    ) -> Result<(T, Option<Vec<u8>>)>
    where
        F: Fn(&[u8]) -> Result<T, Error>,
    {
        let (v, upgraded_blob) = crate::utils::upgrade_keyblob_if_required_with(
            km_dev,
            key_blob,
            params,
            f,
            |upgraded_blob| {
                if key_id_guard.is_some() {
                    // Unwrap cannot panic, because the is_some was true.
                    let kid = key_id_guard.take().unwrap();
                    Self::store_upgraded_keyblob(kid, km_uuid, key_blob, upgraded_blob).context(
                        "In upgrade_keyblob_if_required_with: store_upgraded_keyblob failed",
                    )
                } else {
                    Ok(())
                }
            },
        )
        .context("In KeystoreSecurityLevel::upgrade_keyblob_if_required_with.")?;

        // If no upgrade was needed, use the opportunity to reencrypt the blob if required
        // and if the a key_id_guard is held. Note: key_id_guard can only be Some if no
        // upgrade was performed above and if one was given in the first place.
        if key_blob.force_reencrypt() {
            if let Some(kid) = key_id_guard {
                Self::store_upgraded_keyblob(kid, km_uuid, key_blob, key_blob).context(concat!(
                    "In upgrade_keyblob_if_required_with: ",
                    "store_upgraded_keyblob failed in forced reencrypt"
                ))?;
            }
        }
        Ok((v, upgraded_blob))
    }

    fn convert_storage_key_to_ephemeral(
        &self,
        storage_key: &KeyDescriptor,
    ) -> Result<EphemeralStorageKeyResponse> {
        if storage_key.domain != Domain::BLOB {
            return Err(error::Error::Km(ErrorCode::INVALID_ARGUMENT)).context(concat!(
                "In IKeystoreSecurityLevel convert_storage_key_to_ephemeral: ",
                "Key must be of Domain::BLOB"
            ));
        }
        let key_blob = storage_key
            .blob
            .as_ref()
            .ok_or(error::Error::Km(ErrorCode::INVALID_ARGUMENT))
            .context(
                "In IKeystoreSecurityLevel convert_storage_key_to_ephemeral: No key blob specified",
            )?;

        // convert_storage_key_to_ephemeral requires the associated permission
        check_key_permission(KeyPerm::convert_storage_key_to_ephemeral(), storage_key, &None)
            .context("In convert_storage_key_to_ephemeral: Check permission")?;

        let km_dev: Strong<dyn IKeyMintDevice> = self.keymint.get_interface().context(concat!(
            "In IKeystoreSecurityLevel convert_storage_key_to_ephemeral: ",
            "Getting keymint device interface"
        ))?;
        match {
            let _wp = self.watch_millis(
                concat!(
                    "In IKeystoreSecurityLevel::convert_storage_key_to_ephemeral: ",
                    "calling convertStorageKeyToEphemeral (1)"
                ),
                500,
            );
            map_km_error(km_dev.convertStorageKeyToEphemeral(key_blob))
        } {
            Ok(result) => {
                Ok(EphemeralStorageKeyResponse { ephemeralKey: result, upgradedBlob: None })
            }
            Err(error::Error::Km(ErrorCode::KEY_REQUIRES_UPGRADE)) => {
                let upgraded_blob = {
                    let _wp = self.watch_millis(
                        "In convert_storage_key_to_ephemeral: calling upgradeKey",
                        500,
                    );
                    map_km_error(km_dev.upgradeKey(key_blob, &[]))
                }
                .context("In convert_storage_key_to_ephemeral: Failed to upgrade key blob.")?;
                let ephemeral_key = {
                    let _wp = self.watch_millis(
                        "In convert_storage_key_to_ephemeral: calling convertStorageKeyToEphemeral (2)",
                        500,
                    );
                    map_km_error(km_dev.convertStorageKeyToEphemeral(&upgraded_blob))
                }
                    .context(concat!(
                        "In convert_storage_key_to_ephemeral: ",
                        "Failed to retrieve ephemeral key (after upgrade)."
                    ))?;
                Ok(EphemeralStorageKeyResponse {
                    ephemeralKey: ephemeral_key,
                    upgradedBlob: Some(upgraded_blob),
                })
            }
            Err(e) => Err(e)
                .context("In convert_storage_key_to_ephemeral: Failed to retrieve ephemeral key."),
        }
    }

    fn delete_key(&self, key: &KeyDescriptor) -> Result<()> {
        if key.domain != Domain::BLOB {
            return Err(error::Error::Km(ErrorCode::INVALID_ARGUMENT))
                .context("In IKeystoreSecurityLevel delete_key: Key must be of Domain::BLOB");
        }

        let key_blob = key
            .blob
            .as_ref()
            .ok_or(error::Error::Km(ErrorCode::INVALID_ARGUMENT))
            .context("In IKeystoreSecurityLevel delete_key: No key blob specified")?;

        check_key_permission(KeyPerm::delete(), key, &None)
            .context("In IKeystoreSecurityLevel delete_key: Checking delete permissions")?;

        let km_dev: Strong<dyn IKeyMintDevice> = self
            .keymint
            .get_interface()
            .context("In IKeystoreSecurityLevel delete_key: Getting keymint device interface")?;
        {
            let _wp =
                self.watch_millis("In KeystoreSecuritylevel::delete_key: calling deleteKey", 500);
            map_km_error(km_dev.deleteKey(&key_blob)).context("In keymint device deleteKey")
        }
    }
}

impl binder::Interface for KeystoreSecurityLevel {}

impl IKeystoreSecurityLevel for KeystoreSecurityLevel {
    fn createOperation(
        &self,
        key: &KeyDescriptor,
        operation_parameters: &[KeyParameter],
        forced: bool,
    ) -> binder::public_api::Result<CreateOperationResponse> {
        let _wp = self.watch_millis("IKeystoreSecurityLevel::createOperation", 500);
        map_or_log_err(self.create_operation(key, operation_parameters, forced), Ok)
    }
    fn generateKey(
        &self,
        key: &KeyDescriptor,
        attestation_key: Option<&KeyDescriptor>,
        params: &[KeyParameter],
        flags: i32,
        entropy: &[u8],
    ) -> binder::public_api::Result<KeyMetadata> {
        // Duration is set to 5 seconds, because generateKey - especially for RSA keys, takes more
        // time than other operations
        let _wp = self.watch_millis("IKeystoreSecurityLevel::generateKey", 5000);
        let result = self.generate_key(key, attestation_key, params, flags, entropy);
        log_key_creation_event_stats(self.security_level, params, &result);
        log_key_generated(key, ThreadState::get_calling_uid(), result.is_ok());
        map_or_log_err(result, Ok)
    }
    fn importKey(
        &self,
        key: &KeyDescriptor,
        attestation_key: Option<&KeyDescriptor>,
        params: &[KeyParameter],
        flags: i32,
        key_data: &[u8],
    ) -> binder::public_api::Result<KeyMetadata> {
        let _wp = self.watch_millis("IKeystoreSecurityLevel::importKey", 500);
        let result = self.import_key(key, attestation_key, params, flags, key_data);
        log_key_creation_event_stats(self.security_level, params, &result);
        log_key_imported(key, ThreadState::get_calling_uid(), result.is_ok());
        map_or_log_err(result, Ok)
    }
    fn importWrappedKey(
        &self,
        key: &KeyDescriptor,
        wrapping_key: &KeyDescriptor,
        masking_key: Option<&[u8]>,
        params: &[KeyParameter],
        authenticators: &[AuthenticatorSpec],
    ) -> binder::public_api::Result<KeyMetadata> {
        let _wp = self.watch_millis("IKeystoreSecurityLevel::importWrappedKey", 500);
        let result =
            self.import_wrapped_key(key, wrapping_key, masking_key, params, authenticators);
        log_key_creation_event_stats(self.security_level, params, &result);
        log_key_imported(key, ThreadState::get_calling_uid(), result.is_ok());
        map_or_log_err(result, Ok)
    }
    fn convertStorageKeyToEphemeral(
        &self,
        storage_key: &KeyDescriptor,
    ) -> binder::public_api::Result<EphemeralStorageKeyResponse> {
        let _wp = self.watch_millis("IKeystoreSecurityLevel::convertStorageKeyToEphemeral", 500);
        map_or_log_err(self.convert_storage_key_to_ephemeral(storage_key), Ok)
    }
    fn deleteKey(&self, key: &KeyDescriptor) -> binder::public_api::Result<()> {
        let _wp = self.watch_millis("IKeystoreSecurityLevel::deleteKey", 500);
        let result = self.delete_key(key);
        log_key_deleted(key, ThreadState::get_calling_uid(), result.is_ok());
        map_or_log_err(result, Ok)
    }
}
