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

//! Export into Rust a function to create a KeyMintDevice and add it as a service.

#[allow(missing_docs)] // TODO remove this
extern "C" {
    fn addKeyMintDeviceService() -> i32;
}

#[allow(missing_docs)] // TODO remove this
pub fn add_keymint_device_service() -> i32 {
    unsafe { addKeyMintDeviceService() }
}

#[cfg(test)]
mod tests {

    use super::*;
    use android_hardware_security_keymint::aidl::android::hardware::security::keymint::{
        Algorithm::Algorithm, BeginResult::BeginResult, BlockMode::BlockMode, Digest::Digest,
        ErrorCode::ErrorCode, IKeyMintDevice::IKeyMintDevice, KeyCreationResult::KeyCreationResult,
        KeyFormat::KeyFormat, KeyOrigin::KeyOrigin, KeyParameter::KeyParameter,
        KeyParameterValue::KeyParameterValue, KeyPurpose::KeyPurpose, PaddingMode::PaddingMode,
        SecurityLevel::SecurityLevel, Tag::Tag,
    };
    use android_hardware_security_keymint::binder::{self, Strong};
    use android_security_compat::aidl::android::security::compat::IKeystoreCompatService::IKeystoreCompatService;

    static COMPAT_NAME: &str = "android.security.compat";

    fn get_device() -> Option<Strong<dyn IKeyMintDevice>> {
        add_keymint_device_service();
        let compat_service: Strong<dyn IKeystoreCompatService> =
            binder::get_interface(COMPAT_NAME).ok()?;
        compat_service.getKeyMintDevice(SecurityLevel::TRUSTED_ENVIRONMENT).ok()
    }

    macro_rules! get_device_or_skip_test {
        () => {
            match get_device() {
                Some(dev) => dev,
                None => return,
            }
        };
    }

    #[test]
    fn test_get_hardware_info() {
        let legacy = get_device_or_skip_test!();
        let hinfo = legacy.getHardwareInfo();
        assert!(hinfo.is_ok());
    }

    #[test]
    fn test_add_rng_entropy() {
        let legacy = get_device_or_skip_test!();
        let result = legacy.addRngEntropy(&[42; 16]);
        assert!(result.is_ok(), "{:?}", result);
    }

    // TODO: If I only need the key itself, don't return the other things.
    fn generate_key(legacy: &dyn IKeyMintDevice, kps: Vec<KeyParameter>) -> KeyCreationResult {
        let creation_result =
            legacy.generateKey(&kps, None /* attest_key */).expect("Failed to generate key");
        assert_ne!(creation_result.keyBlob.len(), 0);
        creation_result
    }

    // Per RFC 5280 4.1.2.5, an undefined expiration (not-after) field should be set to GeneralizedTime
    // 999912312359559, which is 253402300799000 ms from Jan 1, 1970.
    const UNDEFINED_NOT_AFTER: i64 = 253402300799000i64;

    fn generate_rsa_key(legacy: &dyn IKeyMintDevice, encrypt: bool, attest: bool) -> Vec<u8> {
        let mut kps = vec![
            KeyParameter {
                tag: Tag::ALGORITHM,
                value: KeyParameterValue::Algorithm(Algorithm::RSA),
            },
            KeyParameter { tag: Tag::KEY_SIZE, value: KeyParameterValue::Integer(2048) },
            KeyParameter {
                tag: Tag::RSA_PUBLIC_EXPONENT,
                value: KeyParameterValue::LongInteger(65537),
            },
            KeyParameter { tag: Tag::DIGEST, value: KeyParameterValue::Digest(Digest::SHA_2_256) },
            KeyParameter {
                tag: Tag::PADDING,
                value: KeyParameterValue::PaddingMode(PaddingMode::RSA_PSS),
            },
            KeyParameter { tag: Tag::NO_AUTH_REQUIRED, value: KeyParameterValue::BoolValue(true) },
            KeyParameter {
                tag: Tag::PURPOSE,
                value: KeyParameterValue::KeyPurpose(KeyPurpose::SIGN),
            },
            KeyParameter {
                tag: Tag::CERTIFICATE_NOT_BEFORE,
                value: KeyParameterValue::DateTime(0),
            },
            KeyParameter {
                tag: Tag::CERTIFICATE_NOT_AFTER,
                value: KeyParameterValue::DateTime(UNDEFINED_NOT_AFTER),
            },
        ];
        if encrypt {
            kps.push(KeyParameter {
                tag: Tag::PURPOSE,
                value: KeyParameterValue::KeyPurpose(KeyPurpose::ENCRYPT),
            });
        }
        if attest {
            kps.push(KeyParameter {
                tag: Tag::ATTESTATION_CHALLENGE,
                value: KeyParameterValue::Blob(vec![42; 8]),
            });
            kps.push(KeyParameter {
                tag: Tag::ATTESTATION_APPLICATION_ID,
                value: KeyParameterValue::Blob(vec![42; 8]),
            });
        }
        let creation_result = generate_key(legacy, kps);
        if attest {
            // TODO: Will this always be greater than 1?
            assert!(creation_result.certificateChain.len() > 1);
        } else {
            assert_eq!(creation_result.certificateChain.len(), 1);
        }
        creation_result.keyBlob
    }

    #[test]
    fn test_generate_key_no_encrypt() {
        let legacy = get_device_or_skip_test!();
        generate_rsa_key(legacy.as_ref(), false, false);
    }

    #[test]
    fn test_generate_key_encrypt() {
        let legacy = get_device_or_skip_test!();
        generate_rsa_key(legacy.as_ref(), true, false);
    }

    #[test]
    fn test_generate_key_attested() {
        let legacy = get_device_or_skip_test!();
        generate_rsa_key(legacy.as_ref(), false, true);
    }

    #[test]
    fn test_import_key() {
        let legacy = get_device_or_skip_test!();
        let kps = [KeyParameter {
            tag: Tag::ALGORITHM,
            value: KeyParameterValue::Algorithm(Algorithm::AES),
        }];
        let kf = KeyFormat::RAW;
        let kd = [0; 16];
        let creation_result =
            legacy.importKey(&kps, kf, &kd, None /* attest_key */).expect("Failed to import key");
        assert_ne!(creation_result.keyBlob.len(), 0);
        assert_eq!(creation_result.certificateChain.len(), 0);
    }

    #[test]
    fn test_import_wrapped_key() {
        let legacy = get_device_or_skip_test!();
        let result = legacy.importWrappedKey(&[], &[], &[], &[], 0, 0);
        // For this test we only care that there was no crash.
        assert!(result.is_ok() || result.is_err());
    }

    #[test]
    fn test_upgrade_key() {
        let legacy = get_device_or_skip_test!();
        let blob = generate_rsa_key(legacy.as_ref(), false, false);
        let result = legacy.upgradeKey(&blob, &[]);
        // For this test we only care that there was no crash.
        assert!(result.is_ok() || result.is_err());
    }

    #[test]
    fn test_delete_key() {
        let legacy = get_device_or_skip_test!();
        let blob = generate_rsa_key(legacy.as_ref(), false, false);
        let result = legacy.deleteKey(&blob);
        assert!(result.is_ok(), "{:?}", result);
    }

    #[test]
    fn test_delete_all_keys() {
        let legacy = get_device_or_skip_test!();
        let result = legacy.deleteAllKeys();
        assert!(result.is_ok(), "{:?}", result);
    }

    #[test]
    fn test_destroy_attestation_ids() {
        let legacy = get_device_or_skip_test!();
        let result = legacy.destroyAttestationIds();
        assert!(result.is_err());
        assert_eq!(result.unwrap_err().service_specific_error(), ErrorCode::UNIMPLEMENTED.0,);
    }

    fn generate_aes_key(legacy: &dyn IKeyMintDevice) -> Vec<u8> {
        let kps = vec![
            KeyParameter {
                tag: Tag::ALGORITHM,
                value: KeyParameterValue::Algorithm(Algorithm::AES),
            },
            KeyParameter { tag: Tag::KEY_SIZE, value: KeyParameterValue::Integer(128) },
            KeyParameter {
                tag: Tag::BLOCK_MODE,
                value: KeyParameterValue::BlockMode(BlockMode::CBC),
            },
            KeyParameter {
                tag: Tag::PADDING,
                value: KeyParameterValue::PaddingMode(PaddingMode::NONE),
            },
            KeyParameter { tag: Tag::NO_AUTH_REQUIRED, value: KeyParameterValue::BoolValue(true) },
            KeyParameter {
                tag: Tag::PURPOSE,
                value: KeyParameterValue::KeyPurpose(KeyPurpose::ENCRYPT),
            },
            KeyParameter {
                tag: Tag::PURPOSE,
                value: KeyParameterValue::KeyPurpose(KeyPurpose::DECRYPT),
            },
        ];
        let creation_result = generate_key(legacy, kps);
        assert_eq!(creation_result.certificateChain.len(), 0);
        creation_result.keyBlob
    }

    fn begin(
        legacy: &dyn IKeyMintDevice,
        blob: &[u8],
        purpose: KeyPurpose,
        extra_params: Option<Vec<KeyParameter>>,
    ) -> BeginResult {
        let mut kps = vec![
            KeyParameter {
                tag: Tag::BLOCK_MODE,
                value: KeyParameterValue::BlockMode(BlockMode::CBC),
            },
            KeyParameter {
                tag: Tag::PADDING,
                value: KeyParameterValue::PaddingMode(PaddingMode::NONE),
            },
        ];
        if let Some(mut extras) = extra_params {
            kps.append(&mut extras);
        }
        let result = legacy.begin(purpose, &blob, &kps, None);
        assert!(result.is_ok(), "{:?}", result);
        result.unwrap()
    }

    #[test]
    fn test_begin_abort() {
        let legacy = get_device_or_skip_test!();
        let blob = generate_aes_key(legacy.as_ref());
        let begin_result = begin(legacy.as_ref(), &blob, KeyPurpose::ENCRYPT, None);
        let operation = begin_result.operation.unwrap();
        let result = operation.abort();
        assert!(result.is_ok(), "{:?}", result);
        let result = operation.abort();
        assert!(result.is_err());
    }

    #[test]
    fn test_begin_update_finish() {
        let legacy = get_device_or_skip_test!();
        let blob = generate_aes_key(legacy.as_ref());

        let begin_result = begin(legacy.as_ref(), &blob, KeyPurpose::ENCRYPT, None);
        let operation = begin_result.operation.unwrap();

        let update_aad_result = operation.updateAad(
            &b"foobar".to_vec(),
            None, /* authToken */
            None, /* timestampToken */
        );
        assert!(update_aad_result.is_ok(), "{:?}", update_aad_result);

        let message = [42; 128];
        let result = operation.finish(
            Some(&message),
            None, /* signature */
            None, /* authToken */
            None, /* timestampToken */
            None, /* confirmationToken */
        );
        assert!(result.is_ok(), "{:?}", result);
        let ciphertext = result.unwrap();
        assert!(!ciphertext.is_empty());

        let begin_result =
            begin(legacy.as_ref(), &blob, KeyPurpose::DECRYPT, Some(begin_result.params));

        let operation = begin_result.operation.unwrap();

        let update_aad_result = operation.updateAad(
            &b"foobar".to_vec(),
            None, /* authToken */
            None, /* timestampToken */
        );
        assert!(update_aad_result.is_ok(), "{:?}", update_aad_result);

        let result = operation.update(
            &ciphertext,
            None, /* authToken */
            None, /* timestampToken */
        );
        assert!(result.is_ok(), "{:?}", result);
        assert_eq!(result.unwrap(), message);
        let result = operation.finish(
            None, /* input */
            None, /* signature */
            None, /* authToken */
            None, /* timestampToken */
            None, /* confirmationToken */
        );
        assert!(result.is_ok(), "{:?}", result);
    }

    #[test]
    fn test_secure_clock() {
        add_keymint_device_service();
        let compat_service: binder::Strong<dyn IKeystoreCompatService> =
            match binder::get_interface(COMPAT_NAME) {
                Ok(cs) => cs,
                _ => return,
            };
        let secure_clock = match compat_service.getSecureClock() {
            Ok(sc) => sc,
            _ => return,
        };

        let challenge = 42;
        let result = secure_clock.generateTimeStamp(challenge);
        assert!(result.is_ok(), "{:?}", result);
        let result = result.unwrap();
        assert_eq!(result.challenge, challenge);
        assert_eq!(result.mac.len(), 32);
    }

    #[test]
    fn test_shared_secret() {
        add_keymint_device_service();
        let compat_service: binder::Strong<dyn IKeystoreCompatService> =
            match binder::get_interface(COMPAT_NAME) {
                Ok(cs) => cs,
                _ => return,
            };
        let shared_secret = match compat_service.getSharedSecret(SecurityLevel::TRUSTED_ENVIRONMENT)
        {
            Ok(ss) => ss,
            _ => return,
        };

        let result = shared_secret.getSharedSecretParameters();
        assert!(result.is_ok(), "{:?}", result);
        let params = result.unwrap();

        let result = shared_secret.computeSharedSecret(&[params]);
        assert!(result.is_ok(), "{:?}", result);
        assert_ne!(result.unwrap().len(), 0);
    }

    #[test]
    fn test_get_key_characteristics() {
        let legacy = get_device_or_skip_test!();
        let hw_info = legacy.getHardwareInfo().expect("GetHardwareInfo");

        let blob = generate_rsa_key(legacy.as_ref(), false, false);
        let characteristics =
            legacy.getKeyCharacteristics(&blob, &[], &[]).expect("GetKeyCharacteristics.");

        assert!(characteristics.iter().any(|kc| kc.securityLevel == hw_info.securityLevel));
        let sec_level_enforced = &characteristics
            .iter()
            .find(|kc| kc.securityLevel == hw_info.securityLevel)
            .expect("There should be characteristics matching the device's security level.")
            .authorizations;

        assert!(sec_level_enforced.iter().any(|kp| matches!(
            kp,
            KeyParameter {
                tag: Tag::PURPOSE,
                value: KeyParameterValue::KeyPurpose(KeyPurpose::SIGN)
            }
        )));
        assert!(sec_level_enforced.iter().any(|kp| matches!(
            kp,
            KeyParameter { tag: Tag::DIGEST, value: KeyParameterValue::Digest(Digest::SHA_2_256) }
        )));
        assert!(sec_level_enforced.iter().any(|kp| matches!(
            kp,
            KeyParameter {
                tag: Tag::PADDING,
                value: KeyParameterValue::PaddingMode(PaddingMode::RSA_PSS)
            }
        )));
        assert!(sec_level_enforced.iter().any(|kp| matches!(
            kp,
            KeyParameter {
                tag: Tag::ALGORITHM,
                value: KeyParameterValue::Algorithm(Algorithm::RSA)
            }
        )));
        assert!(sec_level_enforced.iter().any(|kp| matches!(
            kp,
            KeyParameter { tag: Tag::KEY_SIZE, value: KeyParameterValue::Integer(2048) }
        )));
        assert!(sec_level_enforced.iter().any(|kp| matches!(
            kp,
            KeyParameter {
                tag: Tag::RSA_PUBLIC_EXPONENT,
                value: KeyParameterValue::LongInteger(65537)
            }
        )));
        assert!(sec_level_enforced.iter().any(|kp| matches!(
            kp,
            KeyParameter { tag: Tag::NO_AUTH_REQUIRED, value: KeyParameterValue::BoolValue(true) }
        )));
        assert!(sec_level_enforced.iter().any(|kp| matches!(
            kp,
            KeyParameter {
                tag: Tag::ORIGIN,
                value: KeyParameterValue::Origin(KeyOrigin::GENERATED)
            }
        )));
        assert!(sec_level_enforced.iter().any(|kp| matches!(
            kp,
            KeyParameter { tag: Tag::OS_VERSION, value: KeyParameterValue::Integer(_) }
        )));
        assert!(sec_level_enforced.iter().any(|kp| matches!(
            kp,
            KeyParameter { tag: Tag::OS_PATCHLEVEL, value: KeyParameterValue::Integer(_) }
        )));
        assert!(sec_level_enforced.iter().any(|kp| matches!(
            kp,
            KeyParameter { tag: Tag::VENDOR_PATCHLEVEL, value: KeyParameterValue::Integer(_) }
        )));
        assert!(sec_level_enforced.iter().any(|kp| matches!(
            kp,
            KeyParameter { tag: Tag::BOOT_PATCHLEVEL, value: KeyParameterValue::Integer(_) }
        )));
    }
}
