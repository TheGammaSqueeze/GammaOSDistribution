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

//! This module implements utility functions used by the Keystore 2.0 service
//! implementation.

use crate::error::{map_binder_status, map_km_error, Error, ErrorCode};
use crate::key_parameter::KeyParameter;
use crate::permission;
use crate::permission::{KeyPerm, KeyPermSet, KeystorePerm};
use android_hardware_security_keymint::aidl::android::hardware::security::keymint::{
    IKeyMintDevice::IKeyMintDevice, KeyCharacteristics::KeyCharacteristics,
    KeyParameter::KeyParameter as KmKeyParameter, Tag::Tag,
};
use android_os_permissions_aidl::aidl::android::os::IPermissionController;
use android_security_apc::aidl::android::security::apc::{
    IProtectedConfirmation::{FLAG_UI_OPTION_INVERTED, FLAG_UI_OPTION_MAGNIFIED},
    ResponseCode::ResponseCode as ApcResponseCode,
};
use android_system_keystore2::aidl::android::system::keystore2::{
    Authorization::Authorization, KeyDescriptor::KeyDescriptor,
};
use anyhow::{anyhow, Context, Result};
use binder::{FromIBinder, SpIBinder, ThreadState};
use keystore2_apc_compat::{
    ApcCompatUiOptions, APC_COMPAT_ERROR_ABORTED, APC_COMPAT_ERROR_CANCELLED,
    APC_COMPAT_ERROR_IGNORED, APC_COMPAT_ERROR_OK, APC_COMPAT_ERROR_OPERATION_PENDING,
    APC_COMPAT_ERROR_SYSTEM_ERROR,
};
use keystore2_crypto::{aes_gcm_decrypt, aes_gcm_encrypt, ZVec};
use std::iter::IntoIterator;
use std::sync::Mutex;

/// This function uses its namesake in the permission module and in
/// combination with with_calling_sid from the binder crate to check
/// if the caller has the given keystore permission.
pub fn check_keystore_permission(perm: KeystorePerm) -> anyhow::Result<()> {
    ThreadState::with_calling_sid(|calling_sid| {
        permission::check_keystore_permission(
            &calling_sid.ok_or_else(Error::sys).context(
                "In check_keystore_permission: Cannot check permission without calling_sid.",
            )?,
            perm,
        )
    })
}

/// This function uses its namesake in the permission module and in
/// combination with with_calling_sid from the binder crate to check
/// if the caller has the given grant permission.
pub fn check_grant_permission(access_vec: KeyPermSet, key: &KeyDescriptor) -> anyhow::Result<()> {
    ThreadState::with_calling_sid(|calling_sid| {
        permission::check_grant_permission(
            &calling_sid.ok_or_else(Error::sys).context(
                "In check_grant_permission: Cannot check permission without calling_sid.",
            )?,
            access_vec,
            key,
        )
    })
}

/// This function uses its namesake in the permission module and in
/// combination with with_calling_sid from the binder crate to check
/// if the caller has the given key permission.
pub fn check_key_permission(
    perm: KeyPerm,
    key: &KeyDescriptor,
    access_vector: &Option<KeyPermSet>,
) -> anyhow::Result<()> {
    ThreadState::with_calling_sid(|calling_sid| {
        permission::check_key_permission(
            ThreadState::get_calling_uid(),
            &calling_sid
                .ok_or_else(Error::sys)
                .context("In check_key_permission: Cannot check permission without calling_sid.")?,
            perm,
            key,
            access_vector,
        )
    })
}

/// This function checks whether a given tag corresponds to the access of device identifiers.
pub fn is_device_id_attestation_tag(tag: Tag) -> bool {
    matches!(
        tag,
        Tag::ATTESTATION_ID_IMEI
            | Tag::ATTESTATION_ID_MEID
            | Tag::ATTESTATION_ID_SERIAL
            | Tag::DEVICE_UNIQUE_ATTESTATION
    )
}

/// This function checks whether the calling app has the Android permissions needed to attest device
/// identifiers. It throws an error if the permissions cannot be verified, or if the caller doesn't
/// have the right permissions, and returns silently otherwise.
pub fn check_device_attestation_permissions() -> anyhow::Result<()> {
    let permission_controller: binder::Strong<dyn IPermissionController::IPermissionController> =
        binder::get_interface("permission")?;

    let binder_result = {
        let _wp = watchdog::watch_millis(
            "In check_device_attestation_permissions: calling checkPermission.",
            500,
        );
        permission_controller.checkPermission(
            "android.permission.READ_PRIVILEGED_PHONE_STATE",
            ThreadState::get_calling_pid(),
            ThreadState::get_calling_uid() as i32,
        )
    };
    let has_permissions = map_binder_status(binder_result)
        .context("In check_device_attestation_permissions: checkPermission failed")?;
    match has_permissions {
        true => Ok(()),
        false => Err(Error::Km(ErrorCode::CANNOT_ATTEST_IDS)).context(concat!(
            "In check_device_attestation_permissions: ",
            "caller does not have the permission to attest device IDs"
        )),
    }
}

/// Thread safe wrapper around SpIBinder. It is safe to have SpIBinder smart pointers to the
/// same object in multiple threads, but cloning a SpIBinder is not thread safe.
/// Keystore frequently hands out binder tokens to the security level interface. If this
/// is to happen from a multi threaded thread pool, the SpIBinder needs to be protected by a
/// Mutex.
#[derive(Debug)]
pub struct Asp(Mutex<SpIBinder>);

impl Asp {
    /// Creates a new instance owning a SpIBinder wrapped in a Mutex.
    pub fn new(i: SpIBinder) -> Self {
        Self(Mutex::new(i))
    }

    /// Clones the owned SpIBinder and attempts to convert it into the requested interface.
    pub fn get_interface<T: FromIBinder + ?Sized>(&self) -> anyhow::Result<binder::Strong<T>> {
        // We can use unwrap here because we never panic when locked, so the mutex
        // can never be poisoned.
        let lock = self.0.lock().unwrap();
        (*lock)
            .clone()
            .into_interface()
            .map_err(|e| anyhow!(format!("get_interface failed with error code {:?}", e)))
    }
}

impl Clone for Asp {
    fn clone(&self) -> Self {
        let lock = self.0.lock().unwrap();
        Self(Mutex::new((*lock).clone()))
    }
}

/// Converts a set of key characteristics as returned from KeyMint into the internal
/// representation of the keystore service.
pub fn key_characteristics_to_internal(
    key_characteristics: Vec<KeyCharacteristics>,
) -> Vec<KeyParameter> {
    key_characteristics
        .into_iter()
        .flat_map(|aidl_key_char| {
            let sec_level = aidl_key_char.securityLevel;
            aidl_key_char
                .authorizations
                .into_iter()
                .map(move |aidl_kp| KeyParameter::new(aidl_kp.into(), sec_level))
        })
        .collect()
}

/// This function can be used to upgrade key blobs on demand. The return value of
/// `km_op` is inspected and if ErrorCode::KEY_REQUIRES_UPGRADE is encountered,
/// an attempt is made to upgrade the key blob. On success `new_blob_handler` is called
/// with the upgraded blob as argument. Then `km_op` is called a second time with the
/// upgraded blob as argument. On success a tuple of the `km_op`s result and the
/// optional upgraded blob is returned.
pub fn upgrade_keyblob_if_required_with<T, KmOp, NewBlobHandler>(
    km_dev: &dyn IKeyMintDevice,
    key_blob: &[u8],
    upgrade_params: &[KmKeyParameter],
    km_op: KmOp,
    new_blob_handler: NewBlobHandler,
) -> Result<(T, Option<Vec<u8>>)>
where
    KmOp: Fn(&[u8]) -> Result<T, Error>,
    NewBlobHandler: FnOnce(&[u8]) -> Result<()>,
{
    match km_op(key_blob) {
        Err(Error::Km(ErrorCode::KEY_REQUIRES_UPGRADE)) => {
            let upgraded_blob = {
                let _wp = watchdog::watch_millis(
                    "In utils::upgrade_keyblob_if_required_with: calling upgradeKey.",
                    500,
                );
                map_km_error(km_dev.upgradeKey(key_blob, upgrade_params))
            }
            .context("In utils::upgrade_keyblob_if_required_with: Upgrade failed.")?;

            new_blob_handler(&upgraded_blob)
                .context("In utils::upgrade_keyblob_if_required_with: calling new_blob_handler.")?;

            km_op(&upgraded_blob)
                .map(|v| (v, Some(upgraded_blob)))
                .context("In utils::upgrade_keyblob_if_required_with: Calling km_op after upgrade.")
        }
        r => r
            .map(|v| (v, None))
            .context("In utils::upgrade_keyblob_if_required_with: Calling km_op."),
    }
}

/// Converts a set of key characteristics from the internal representation into a set of
/// Authorizations as they are used to convey key characteristics to the clients of keystore.
pub fn key_parameters_to_authorizations(
    parameters: Vec<crate::key_parameter::KeyParameter>,
) -> Vec<Authorization> {
    parameters.into_iter().map(|p| p.into_authorization()).collect()
}

/// This returns the current time (in milliseconds) as an instance of a monotonic clock,
/// by invoking the system call since Rust does not support getting monotonic time instance
/// as an integer.
pub fn get_current_time_in_milliseconds() -> i64 {
    let mut current_time = libc::timespec { tv_sec: 0, tv_nsec: 0 };
    // Following unsafe block includes one system call to get monotonic time.
    // Therefore, it is not considered harmful.
    unsafe { libc::clock_gettime(libc::CLOCK_MONOTONIC_RAW, &mut current_time) };
    current_time.tv_sec as i64 * 1000 + (current_time.tv_nsec as i64 / 1_000_000)
}

/// Converts a response code as returned by the Android Protected Confirmation HIDL compatibility
/// module (keystore2_apc_compat) into a ResponseCode as defined by the APC AIDL
/// (android.security.apc) spec.
pub fn compat_2_response_code(rc: u32) -> ApcResponseCode {
    match rc {
        APC_COMPAT_ERROR_OK => ApcResponseCode::OK,
        APC_COMPAT_ERROR_CANCELLED => ApcResponseCode::CANCELLED,
        APC_COMPAT_ERROR_ABORTED => ApcResponseCode::ABORTED,
        APC_COMPAT_ERROR_OPERATION_PENDING => ApcResponseCode::OPERATION_PENDING,
        APC_COMPAT_ERROR_IGNORED => ApcResponseCode::IGNORED,
        APC_COMPAT_ERROR_SYSTEM_ERROR => ApcResponseCode::SYSTEM_ERROR,
        _ => ApcResponseCode::SYSTEM_ERROR,
    }
}

/// Converts the UI Options flags as defined by the APC AIDL (android.security.apc) spec into
/// UI Options flags as defined by the Android Protected Confirmation HIDL compatibility
/// module (keystore2_apc_compat).
pub fn ui_opts_2_compat(opt: i32) -> ApcCompatUiOptions {
    ApcCompatUiOptions {
        inverted: (opt & FLAG_UI_OPTION_INVERTED) != 0,
        magnified: (opt & FLAG_UI_OPTION_MAGNIFIED) != 0,
    }
}

/// AID offset for uid space partitioning.
pub const AID_USER_OFFSET: u32 = cutils_bindgen::AID_USER_OFFSET;

/// AID of the keystore process itself, used for keys that
/// keystore generates for its own use.
pub const AID_KEYSTORE: u32 = cutils_bindgen::AID_KEYSTORE;

/// Extracts the android user from the given uid.
pub fn uid_to_android_user(uid: u32) -> u32 {
    // Safety: No memory access
    unsafe { cutils_bindgen::multiuser_get_user_id(uid) }
}

/// This module provides helpers for simplified use of the watchdog module.
#[cfg(feature = "watchdog")]
pub mod watchdog {
    pub use crate::watchdog::WatchPoint;
    use crate::watchdog::Watchdog;
    use lazy_static::lazy_static;
    use std::sync::Arc;
    use std::time::Duration;

    lazy_static! {
        /// A Watchdog thread, that can be used to create watch points.
        static ref WD: Arc<Watchdog> = Watchdog::new(Duration::from_secs(10));
    }

    /// Sets a watch point with `id` and a timeout of `millis` milliseconds.
    pub fn watch_millis(id: &'static str, millis: u64) -> Option<WatchPoint> {
        Watchdog::watch(&WD, id, Duration::from_millis(millis))
    }

    /// Like `watch_millis` but with a callback that is called every time a report
    /// is printed about this watch point.
    pub fn watch_millis_with(
        id: &'static str,
        millis: u64,
        callback: impl Fn() -> String + Send + 'static,
    ) -> Option<WatchPoint> {
        Watchdog::watch_with(&WD, id, Duration::from_millis(millis), callback)
    }
}

/// Trait implemented by objects that can be used to decrypt cipher text using AES-GCM.
pub trait AesGcm {
    /// Deciphers `data` using the initialization vector `iv` and AEAD tag `tag`
    /// and AES-GCM. The implementation provides the key material and selects
    /// the implementation variant, e.g., AES128 or AES265.
    fn decrypt(&self, data: &[u8], iv: &[u8], tag: &[u8]) -> Result<ZVec>;

    /// Encrypts `data` and returns the ciphertext, the initialization vector `iv`
    /// and AEAD tag `tag`. The implementation provides the key material and selects
    /// the implementation variant, e.g., AES128 or AES265.
    fn encrypt(&self, plaintext: &[u8]) -> Result<(Vec<u8>, Vec<u8>, Vec<u8>)>;
}

/// Marks an object as AES-GCM key.
pub trait AesGcmKey {
    /// Provides access to the raw key material.
    fn key(&self) -> &[u8];
}

impl<T: AesGcmKey> AesGcm for T {
    fn decrypt(&self, data: &[u8], iv: &[u8], tag: &[u8]) -> Result<ZVec> {
        aes_gcm_decrypt(data, iv, tag, self.key())
            .context("In AesGcm<T>::decrypt: Decryption failed")
    }

    fn encrypt(&self, plaintext: &[u8]) -> Result<(Vec<u8>, Vec<u8>, Vec<u8>)> {
        aes_gcm_encrypt(plaintext, self.key()).context("In AesGcm<T>::encrypt: Encryption failed.")
    }
}

/// This module provides empty/noop implementations of the watch dog utility functions.
#[cfg(not(feature = "watchdog"))]
pub mod watchdog {
    /// Noop watch point.
    pub struct WatchPoint();
    /// Sets a Noop watch point.
    fn watch_millis(_: &'static str, _: u64) -> Option<WatchPoint> {
        None
    }

    pub fn watch_millis_with(
        _: &'static str,
        _: u64,
        _: impl Fn() -> String + Send + 'static,
    ) -> Option<WatchPoint> {
        None
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use anyhow::Result;

    #[test]
    fn check_device_attestation_permissions_test() -> Result<()> {
        check_device_attestation_permissions().or_else(|error| {
            match error.root_cause().downcast_ref::<Error>() {
                // Expected: the context for this test might not be allowed to attest device IDs.
                Some(Error::Km(ErrorCode::CANNOT_ATTEST_IDS)) => Ok(()),
                // Other errors are unexpected
                _ => Err(error),
            }
        })
    }
}
