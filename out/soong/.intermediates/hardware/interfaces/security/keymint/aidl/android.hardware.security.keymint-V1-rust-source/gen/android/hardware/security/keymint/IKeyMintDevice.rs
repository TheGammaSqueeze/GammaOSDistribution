#![allow(non_upper_case_globals)]
#![allow(non_snake_case)]
#[allow(unused_imports)] use binder::IBinderInternal;
use binder::declare_binder_interface;
declare_binder_interface! {
  IKeyMintDevice["android.hardware.security.keymint.IKeyMintDevice"] {
    native: BnKeyMintDevice(on_transact),
    proxy: BpKeyMintDevice {
      cached_version: std::sync::atomic::AtomicI32 = std::sync::atomic::AtomicI32::new(-1),
      cached_hash: std::sync::Mutex<Option<String>> = std::sync::Mutex::new(None)
    },
  stability: binder::Stability::Vintf,
  }
}
pub trait IKeyMintDevice: binder::Interface + Send {
  fn get_descriptor() -> &'static str where Self: Sized { "android.hardware.security.keymint.IKeyMintDevice" }
  fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_19_KeyMintHardwareInfo>;
  fn addRngEntropy(&self, _arg_data: &[u8]) -> binder::public_api::Result<()>;
  fn generateKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult>;
  fn importKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_keyFormat: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_KeyFormat, _arg_keyData: &[u8], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult>;
  fn importWrappedKey(&self, _arg_wrappedKeyData: &[u8], _arg_wrappingKeyBlob: &[u8], _arg_maskingKey: &[u8], _arg_unwrappingParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_passwordSid: i64, _arg_biometricSid: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult>;
  fn upgradeKey(&self, _arg_keyBlobToUpgrade: &[u8], _arg_upgradeParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter]) -> binder::public_api::Result<Vec<u8>>;
  fn deleteKey(&self, _arg_keyBlob: &[u8]) -> binder::public_api::Result<()>;
  fn deleteAllKeys(&self) -> binder::public_api::Result<()>;
  fn destroyAttestationIds(&self) -> binder::public_api::Result<()>;
  fn begin(&self, _arg_purpose: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_KeyPurpose, _arg_keyBlob: &[u8], _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_BeginResult>;
  fn deviceLocked(&self, _arg_passwordOnly: bool, _arg_timestampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<()>;
  fn earlyBootEnded(&self) -> binder::public_api::Result<()>;
  fn convertStorageKeyToEphemeral(&self, _arg_storageKeyBlob: &[u8]) -> binder::public_api::Result<Vec<u8>>;
  fn getKeyCharacteristics(&self, _arg_keyBlob: &[u8], _arg_appId: &[u8], _arg_appData: &[u8]) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_18_KeyCharacteristics>>;
  fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
    Ok(VERSION)
  }
  fn getInterfaceHash(&self) -> binder::public_api::Result<String> {
    Ok(HASH.into())
  }
  fn getDefaultImpl() -> IKeyMintDeviceDefaultRef where Self: Sized {
    DEFAULT_IMPL.lock().unwrap().clone()
  }
  fn setDefaultImpl(d: IKeyMintDeviceDefaultRef) -> IKeyMintDeviceDefaultRef where Self: Sized {
    std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
  }
}
pub trait IKeyMintDeviceDefault: Send + Sync {
  fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_19_KeyMintHardwareInfo> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn addRngEntropy(&self, _arg_data: &[u8]) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn generateKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn importKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_keyFormat: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_KeyFormat, _arg_keyData: &[u8], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn importWrappedKey(&self, _arg_wrappedKeyData: &[u8], _arg_wrappingKeyBlob: &[u8], _arg_maskingKey: &[u8], _arg_unwrappingParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_passwordSid: i64, _arg_biometricSid: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn upgradeKey(&self, _arg_keyBlobToUpgrade: &[u8], _arg_upgradeParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter]) -> binder::public_api::Result<Vec<u8>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn deleteKey(&self, _arg_keyBlob: &[u8]) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn deleteAllKeys(&self) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn destroyAttestationIds(&self) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn begin(&self, _arg_purpose: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_KeyPurpose, _arg_keyBlob: &[u8], _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_BeginResult> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn deviceLocked(&self, _arg_passwordOnly: bool, _arg_timestampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn earlyBootEnded(&self) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn convertStorageKeyToEphemeral(&self, _arg_storageKeyBlob: &[u8]) -> binder::public_api::Result<Vec<u8>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn getKeyCharacteristics(&self, _arg_keyBlob: &[u8], _arg_appId: &[u8], _arg_appData: &[u8]) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_18_KeyCharacteristics>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
}
pub mod transactions {
  pub const getHardwareInfo: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
  pub const addRngEntropy: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
  pub const generateKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
  pub const importKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 3;
  pub const importWrappedKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 4;
  pub const upgradeKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 5;
  pub const deleteKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 6;
  pub const deleteAllKeys: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 7;
  pub const destroyAttestationIds: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 8;
  pub const begin: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 9;
  pub const deviceLocked: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 10;
  pub const earlyBootEnded: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 11;
  pub const convertStorageKeyToEphemeral: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 12;
  pub const getKeyCharacteristics: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 13;
  pub const getInterfaceVersion: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777214;
  pub const getInterfaceHash: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777213;
}
pub type IKeyMintDeviceDefaultRef = Option<std::sync::Arc<dyn IKeyMintDeviceDefault>>;
use lazy_static::lazy_static;
lazy_static! {
  static ref DEFAULT_IMPL: std::sync::Mutex<IKeyMintDeviceDefaultRef> = std::sync::Mutex::new(None);
}
pub const AUTH_TOKEN_MAC_LENGTH: i32 = 32;
pub(crate) mod mangled { pub use super::IKeyMintDevice as _7_android_8_hardware_8_security_7_keymint_14_IKeyMintDevice; }
pub const VERSION: i32 = 1;
pub const HASH: &str = "976674616001f714f4a4df49ee45f548de828524";
impl IKeyMintDevice for BpKeyMintDevice {
  fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_19_KeyMintHardwareInfo> {
    let _aidl_reply = self.binder.transact(transactions::getHardwareInfo, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
        return _aidl_default_impl.getHardwareInfo();
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_8_hardware_8_security_7_keymint_19_KeyMintHardwareInfo = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn addRngEntropy(&self, _arg_data: &[u8]) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::addRngEntropy, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_data)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
        return _aidl_default_impl.addRngEntropy(_arg_data);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn generateKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> {
    let _aidl_reply = self.binder.transact(transactions::generateKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_keyParams)?;
      _aidl_data.write(&_arg_attestationKey)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
        return _aidl_default_impl.generateKey(_arg_keyParams, _arg_attestationKey);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn importKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_keyFormat: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_KeyFormat, _arg_keyData: &[u8], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> {
    let _aidl_reply = self.binder.transact(transactions::importKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_keyParams)?;
      _aidl_data.write(&_arg_keyFormat)?;
      _aidl_data.write(_arg_keyData)?;
      _aidl_data.write(&_arg_attestationKey)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
        return _aidl_default_impl.importKey(_arg_keyParams, _arg_keyFormat, _arg_keyData, _arg_attestationKey);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn importWrappedKey(&self, _arg_wrappedKeyData: &[u8], _arg_wrappingKeyBlob: &[u8], _arg_maskingKey: &[u8], _arg_unwrappingParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_passwordSid: i64, _arg_biometricSid: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> {
    let _aidl_reply = self.binder.transact(transactions::importWrappedKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_wrappedKeyData)?;
      _aidl_data.write(_arg_wrappingKeyBlob)?;
      _aidl_data.write(_arg_maskingKey)?;
      _aidl_data.write(_arg_unwrappingParams)?;
      _aidl_data.write(&_arg_passwordSid)?;
      _aidl_data.write(&_arg_biometricSid)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
        return _aidl_default_impl.importWrappedKey(_arg_wrappedKeyData, _arg_wrappingKeyBlob, _arg_maskingKey, _arg_unwrappingParams, _arg_passwordSid, _arg_biometricSid);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn upgradeKey(&self, _arg_keyBlobToUpgrade: &[u8], _arg_upgradeParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter]) -> binder::public_api::Result<Vec<u8>> {
    let _aidl_reply = self.binder.transact(transactions::upgradeKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_keyBlobToUpgrade)?;
      _aidl_data.write(_arg_upgradeParams)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
        return _aidl_default_impl.upgradeKey(_arg_keyBlobToUpgrade, _arg_upgradeParams);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: Vec<u8> = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn deleteKey(&self, _arg_keyBlob: &[u8]) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::deleteKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_keyBlob)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
        return _aidl_default_impl.deleteKey(_arg_keyBlob);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn deleteAllKeys(&self) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::deleteAllKeys, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
        return _aidl_default_impl.deleteAllKeys();
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn destroyAttestationIds(&self) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::destroyAttestationIds, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
        return _aidl_default_impl.destroyAttestationIds();
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn begin(&self, _arg_purpose: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_KeyPurpose, _arg_keyBlob: &[u8], _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_BeginResult> {
    let _aidl_reply = self.binder.transact(transactions::begin, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(&_arg_purpose)?;
      _aidl_data.write(_arg_keyBlob)?;
      _aidl_data.write(_arg_params)?;
      _aidl_data.write(&_arg_authToken)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
        return _aidl_default_impl.begin(_arg_purpose, _arg_keyBlob, _arg_params, _arg_authToken);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_BeginResult = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn deviceLocked(&self, _arg_passwordOnly: bool, _arg_timestampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::deviceLocked, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(&_arg_passwordOnly)?;
      _aidl_data.write(&_arg_timestampToken)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
        return _aidl_default_impl.deviceLocked(_arg_passwordOnly, _arg_timestampToken);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn earlyBootEnded(&self) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::earlyBootEnded, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
        return _aidl_default_impl.earlyBootEnded();
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn convertStorageKeyToEphemeral(&self, _arg_storageKeyBlob: &[u8]) -> binder::public_api::Result<Vec<u8>> {
    let _aidl_reply = self.binder.transact(transactions::convertStorageKeyToEphemeral, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_storageKeyBlob)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
        return _aidl_default_impl.convertStorageKeyToEphemeral(_arg_storageKeyBlob);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: Vec<u8> = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn getKeyCharacteristics(&self, _arg_keyBlob: &[u8], _arg_appId: &[u8], _arg_appData: &[u8]) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_18_KeyCharacteristics>> {
    let _aidl_reply = self.binder.transact(transactions::getKeyCharacteristics, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_keyBlob)?;
      _aidl_data.write(_arg_appId)?;
      _aidl_data.write(_arg_appData)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
        return _aidl_default_impl.getKeyCharacteristics(_arg_keyBlob, _arg_appId, _arg_appData);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_18_KeyCharacteristics> = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
    let _aidl_version = self.cached_version.load(std::sync::atomic::Ordering::Relaxed);
    if _aidl_version != -1 { return Ok(_aidl_version); }
    let _aidl_reply = self.binder.transact(transactions::getInterfaceVersion, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      Ok(())
    });
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: i32 = _aidl_reply.read()?;
    self.cached_version.store(_aidl_return, std::sync::atomic::Ordering::Relaxed);
    Ok(_aidl_return)
  }
  fn getInterfaceHash(&self) -> binder::public_api::Result<String> {
    {
      let _aidl_hash_lock = self.cached_hash.lock().unwrap();
      if let Some(ref _aidl_hash) = *_aidl_hash_lock {
        return Ok(_aidl_hash.clone());
      }
    }
    let _aidl_reply = self.binder.transact(transactions::getInterfaceHash, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      Ok(())
    });
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: String = _aidl_reply.read()?;
    *self.cached_hash.lock().unwrap() = Some(_aidl_return.clone());
    Ok(_aidl_return)
  }
}
impl IKeyMintDevice for binder::Binder<BnKeyMintDevice> {
  fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_19_KeyMintHardwareInfo> { self.0.getHardwareInfo() }
  fn addRngEntropy(&self, _arg_data: &[u8]) -> binder::public_api::Result<()> { self.0.addRngEntropy(_arg_data) }
  fn generateKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> { self.0.generateKey(_arg_keyParams, _arg_attestationKey) }
  fn importKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_keyFormat: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_KeyFormat, _arg_keyData: &[u8], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> { self.0.importKey(_arg_keyParams, _arg_keyFormat, _arg_keyData, _arg_attestationKey) }
  fn importWrappedKey(&self, _arg_wrappedKeyData: &[u8], _arg_wrappingKeyBlob: &[u8], _arg_maskingKey: &[u8], _arg_unwrappingParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_passwordSid: i64, _arg_biometricSid: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> { self.0.importWrappedKey(_arg_wrappedKeyData, _arg_wrappingKeyBlob, _arg_maskingKey, _arg_unwrappingParams, _arg_passwordSid, _arg_biometricSid) }
  fn upgradeKey(&self, _arg_keyBlobToUpgrade: &[u8], _arg_upgradeParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter]) -> binder::public_api::Result<Vec<u8>> { self.0.upgradeKey(_arg_keyBlobToUpgrade, _arg_upgradeParams) }
  fn deleteKey(&self, _arg_keyBlob: &[u8]) -> binder::public_api::Result<()> { self.0.deleteKey(_arg_keyBlob) }
  fn deleteAllKeys(&self) -> binder::public_api::Result<()> { self.0.deleteAllKeys() }
  fn destroyAttestationIds(&self) -> binder::public_api::Result<()> { self.0.destroyAttestationIds() }
  fn begin(&self, _arg_purpose: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_KeyPurpose, _arg_keyBlob: &[u8], _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_BeginResult> { self.0.begin(_arg_purpose, _arg_keyBlob, _arg_params, _arg_authToken) }
  fn deviceLocked(&self, _arg_passwordOnly: bool, _arg_timestampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<()> { self.0.deviceLocked(_arg_passwordOnly, _arg_timestampToken) }
  fn earlyBootEnded(&self) -> binder::public_api::Result<()> { self.0.earlyBootEnded() }
  fn convertStorageKeyToEphemeral(&self, _arg_storageKeyBlob: &[u8]) -> binder::public_api::Result<Vec<u8>> { self.0.convertStorageKeyToEphemeral(_arg_storageKeyBlob) }
  fn getKeyCharacteristics(&self, _arg_keyBlob: &[u8], _arg_appId: &[u8], _arg_appData: &[u8]) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_18_KeyCharacteristics>> { self.0.getKeyCharacteristics(_arg_keyBlob, _arg_appId, _arg_appData) }
  fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> { self.0.getInterfaceVersion() }
  fn getInterfaceHash(&self) -> binder::public_api::Result<String> { self.0.getInterfaceHash() }
}
fn on_transact(_aidl_service: &dyn IKeyMintDevice, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
  match _aidl_code {
    transactions::getHardwareInfo => {
      let _aidl_return = _aidl_service.getHardwareInfo();
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::addRngEntropy => {
      let _arg_data: Vec<u8> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.addRngEntropy(&_arg_data);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::generateKey => {
      let _arg_keyParams: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
      let _arg_attestationKey: Option<crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.generateKey(&_arg_keyParams, _arg_attestationKey.as_ref());
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::importKey => {
      let _arg_keyParams: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
      let _arg_keyFormat: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_KeyFormat = _aidl_data.read()?;
      let _arg_keyData: Vec<u8> = _aidl_data.read()?;
      let _arg_attestationKey: Option<crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.importKey(&_arg_keyParams, _arg_keyFormat, &_arg_keyData, _arg_attestationKey.as_ref());
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::importWrappedKey => {
      let _arg_wrappedKeyData: Vec<u8> = _aidl_data.read()?;
      let _arg_wrappingKeyBlob: Vec<u8> = _aidl_data.read()?;
      let _arg_maskingKey: Vec<u8> = _aidl_data.read()?;
      let _arg_unwrappingParams: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
      let _arg_passwordSid: i64 = _aidl_data.read()?;
      let _arg_biometricSid: i64 = _aidl_data.read()?;
      let _aidl_return = _aidl_service.importWrappedKey(&_arg_wrappedKeyData, &_arg_wrappingKeyBlob, &_arg_maskingKey, &_arg_unwrappingParams, _arg_passwordSid, _arg_biometricSid);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::upgradeKey => {
      let _arg_keyBlobToUpgrade: Vec<u8> = _aidl_data.read()?;
      let _arg_upgradeParams: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.upgradeKey(&_arg_keyBlobToUpgrade, &_arg_upgradeParams);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::deleteKey => {
      let _arg_keyBlob: Vec<u8> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.deleteKey(&_arg_keyBlob);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::deleteAllKeys => {
      let _aidl_return = _aidl_service.deleteAllKeys();
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::destroyAttestationIds => {
      let _aidl_return = _aidl_service.destroyAttestationIds();
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::begin => {
      let _arg_purpose: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_KeyPurpose = _aidl_data.read()?;
      let _arg_keyBlob: Vec<u8> = _aidl_data.read()?;
      let _arg_params: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
      let _arg_authToken: Option<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.begin(_arg_purpose, &_arg_keyBlob, &_arg_params, _arg_authToken.as_ref());
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::deviceLocked => {
      let _arg_passwordOnly: bool = _aidl_data.read()?;
      let _arg_timestampToken: Option<crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.deviceLocked(_arg_passwordOnly, _arg_timestampToken.as_ref());
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::earlyBootEnded => {
      let _aidl_return = _aidl_service.earlyBootEnded();
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::convertStorageKeyToEphemeral => {
      let _arg_storageKeyBlob: Vec<u8> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.convertStorageKeyToEphemeral(&_arg_storageKeyBlob);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::getKeyCharacteristics => {
      let _arg_keyBlob: Vec<u8> = _aidl_data.read()?;
      let _arg_appId: Vec<u8> = _aidl_data.read()?;
      let _arg_appData: Vec<u8> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.getKeyCharacteristics(&_arg_keyBlob, &_arg_appId, &_arg_appData);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::getInterfaceVersion => {
      let _aidl_return = _aidl_service.getInterfaceVersion();
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::getInterfaceHash => {
      let _aidl_return = _aidl_service.getInterfaceHash();
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    _ => Err(binder::StatusCode::UNKNOWN_TRANSACTION)
  }
}
