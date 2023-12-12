#![allow(non_upper_case_globals)]
#![allow(non_snake_case)]
#[allow(unused_imports)] use binder::IBinderInternal;
use binder::declare_binder_interface;
declare_binder_interface! {
  IKeystoreSecurityLevel["android.system.keystore2.IKeystoreSecurityLevel"] {
    native: BnKeystoreSecurityLevel(on_transact),
    proxy: BpKeystoreSecurityLevel {
      cached_version: std::sync::atomic::AtomicI32 = std::sync::atomic::AtomicI32::new(-1),
      cached_hash: std::sync::Mutex<Option<String>> = std::sync::Mutex::new(None)
    },
  stability: binder::Stability::Vintf,
  }
}
pub trait IKeystoreSecurityLevel: binder::Interface + Send {
  fn get_descriptor() -> &'static str where Self: Sized { "android.system.keystore2.IKeystoreSecurityLevel" }
  fn createOperation(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_operationParameters: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_forced: bool) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_23_CreateOperationResponse>;
  fn generateKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_entropy: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata>;
  fn importKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_keyData: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata>;
  fn importWrappedKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_wrappingKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_maskingKey: Option<&[u8]>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authenticators: &[crate::mangled::_7_android_6_system_9_keystore2_17_AuthenticatorSpec]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata>;
  fn convertStorageKeyToEphemeral(&self, _arg_storageKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_27_EphemeralStorageKeyResponse>;
  fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()>;
  fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
    Ok(VERSION)
  }
  fn getInterfaceHash(&self) -> binder::public_api::Result<String> {
    Ok(HASH.into())
  }
  fn getDefaultImpl() -> IKeystoreSecurityLevelDefaultRef where Self: Sized {
    DEFAULT_IMPL.lock().unwrap().clone()
  }
  fn setDefaultImpl(d: IKeystoreSecurityLevelDefaultRef) -> IKeystoreSecurityLevelDefaultRef where Self: Sized {
    std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
  }
}
pub trait IKeystoreSecurityLevelDefault: Send + Sync {
  fn createOperation(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_operationParameters: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_forced: bool) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_23_CreateOperationResponse> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn generateKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_entropy: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn importKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_keyData: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn importWrappedKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_wrappingKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_maskingKey: Option<&[u8]>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authenticators: &[crate::mangled::_7_android_6_system_9_keystore2_17_AuthenticatorSpec]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn convertStorageKeyToEphemeral(&self, _arg_storageKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_27_EphemeralStorageKeyResponse> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
}
pub mod transactions {
  pub const createOperation: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
  pub const generateKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
  pub const importKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
  pub const importWrappedKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 3;
  pub const convertStorageKeyToEphemeral: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 4;
  pub const deleteKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 5;
  pub const getInterfaceVersion: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777214;
  pub const getInterfaceHash: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777213;
}
pub type IKeystoreSecurityLevelDefaultRef = Option<std::sync::Arc<dyn IKeystoreSecurityLevelDefault>>;
use lazy_static::lazy_static;
lazy_static! {
  static ref DEFAULT_IMPL: std::sync::Mutex<IKeystoreSecurityLevelDefaultRef> = std::sync::Mutex::new(None);
}
pub const KEY_FLAG_AUTH_BOUND_WITHOUT_CRYPTOGRAPHIC_LSKF_BINDING: i32 = 1;
pub(crate) mod mangled { pub use super::IKeystoreSecurityLevel as _7_android_6_system_9_keystore2_22_IKeystoreSecurityLevel; }
pub const VERSION: i32 = 1;
pub const HASH: &str = "19e8b65277839bad0ab335c781e3c652324920ce";
impl IKeystoreSecurityLevel for BpKeystoreSecurityLevel {
  fn createOperation(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_operationParameters: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_forced: bool) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_23_CreateOperationResponse> {
    let _aidl_reply = self.binder.transact(transactions::createOperation, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_key)?;
      _aidl_data.write(_arg_operationParameters)?;
      _aidl_data.write(&_arg_forced)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreSecurityLevel>::getDefaultImpl() {
        return _aidl_default_impl.createOperation(_arg_key, _arg_operationParameters, _arg_forced);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_6_system_9_keystore2_23_CreateOperationResponse = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn generateKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_entropy: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> {
    let _aidl_reply = self.binder.transact(transactions::generateKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_key)?;
      _aidl_data.write(&_arg_attestationKey)?;
      _aidl_data.write(_arg_params)?;
      _aidl_data.write(&_arg_flags)?;
      _aidl_data.write(_arg_entropy)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreSecurityLevel>::getDefaultImpl() {
        return _aidl_default_impl.generateKey(_arg_key, _arg_attestationKey, _arg_params, _arg_flags, _arg_entropy);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn importKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_keyData: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> {
    let _aidl_reply = self.binder.transact(transactions::importKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_key)?;
      _aidl_data.write(&_arg_attestationKey)?;
      _aidl_data.write(_arg_params)?;
      _aidl_data.write(&_arg_flags)?;
      _aidl_data.write(_arg_keyData)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreSecurityLevel>::getDefaultImpl() {
        return _aidl_default_impl.importKey(_arg_key, _arg_attestationKey, _arg_params, _arg_flags, _arg_keyData);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn importWrappedKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_wrappingKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_maskingKey: Option<&[u8]>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authenticators: &[crate::mangled::_7_android_6_system_9_keystore2_17_AuthenticatorSpec]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> {
    let _aidl_reply = self.binder.transact(transactions::importWrappedKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_key)?;
      _aidl_data.write(_arg_wrappingKey)?;
      _aidl_data.write(&_arg_maskingKey)?;
      _aidl_data.write(_arg_params)?;
      _aidl_data.write(_arg_authenticators)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreSecurityLevel>::getDefaultImpl() {
        return _aidl_default_impl.importWrappedKey(_arg_key, _arg_wrappingKey, _arg_maskingKey, _arg_params, _arg_authenticators);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn convertStorageKeyToEphemeral(&self, _arg_storageKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_27_EphemeralStorageKeyResponse> {
    let _aidl_reply = self.binder.transact(transactions::convertStorageKeyToEphemeral, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_storageKey)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreSecurityLevel>::getDefaultImpl() {
        return _aidl_default_impl.convertStorageKeyToEphemeral(_arg_storageKey);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_6_system_9_keystore2_27_EphemeralStorageKeyResponse = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::deleteKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_key)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreSecurityLevel>::getDefaultImpl() {
        return _aidl_default_impl.deleteKey(_arg_key);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
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
impl IKeystoreSecurityLevel for binder::Binder<BnKeystoreSecurityLevel> {
  fn createOperation(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_operationParameters: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_forced: bool) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_23_CreateOperationResponse> { self.0.createOperation(_arg_key, _arg_operationParameters, _arg_forced) }
  fn generateKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_entropy: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> { self.0.generateKey(_arg_key, _arg_attestationKey, _arg_params, _arg_flags, _arg_entropy) }
  fn importKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_keyData: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> { self.0.importKey(_arg_key, _arg_attestationKey, _arg_params, _arg_flags, _arg_keyData) }
  fn importWrappedKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_wrappingKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_maskingKey: Option<&[u8]>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authenticators: &[crate::mangled::_7_android_6_system_9_keystore2_17_AuthenticatorSpec]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> { self.0.importWrappedKey(_arg_key, _arg_wrappingKey, _arg_maskingKey, _arg_params, _arg_authenticators) }
  fn convertStorageKeyToEphemeral(&self, _arg_storageKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_27_EphemeralStorageKeyResponse> { self.0.convertStorageKeyToEphemeral(_arg_storageKey) }
  fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> { self.0.deleteKey(_arg_key) }
  fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> { self.0.getInterfaceVersion() }
  fn getInterfaceHash(&self) -> binder::public_api::Result<String> { self.0.getInterfaceHash() }
}
fn on_transact(_aidl_service: &dyn IKeystoreSecurityLevel, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
  match _aidl_code {
    transactions::createOperation => {
      let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
      let _arg_operationParameters: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
      let _arg_forced: bool = _aidl_data.read()?;
      let _aidl_return = _aidl_service.createOperation(&_arg_key, &_arg_operationParameters, _arg_forced);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::generateKey => {
      let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
      let _arg_attestationKey: Option<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor> = _aidl_data.read()?;
      let _arg_params: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
      let _arg_flags: i32 = _aidl_data.read()?;
      let _arg_entropy: Vec<u8> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.generateKey(&_arg_key, _arg_attestationKey.as_ref(), &_arg_params, _arg_flags, &_arg_entropy);
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
      let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
      let _arg_attestationKey: Option<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor> = _aidl_data.read()?;
      let _arg_params: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
      let _arg_flags: i32 = _aidl_data.read()?;
      let _arg_keyData: Vec<u8> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.importKey(&_arg_key, _arg_attestationKey.as_ref(), &_arg_params, _arg_flags, &_arg_keyData);
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
      let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
      let _arg_wrappingKey: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
      let _arg_maskingKey: Option<Vec<u8>> = _aidl_data.read()?;
      let _arg_params: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
      let _arg_authenticators: Vec<crate::mangled::_7_android_6_system_9_keystore2_17_AuthenticatorSpec> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.importWrappedKey(&_arg_key, &_arg_wrappingKey, _arg_maskingKey.as_deref(), &_arg_params, &_arg_authenticators);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::convertStorageKeyToEphemeral => {
      let _arg_storageKey: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
      let _aidl_return = _aidl_service.convertStorageKeyToEphemeral(&_arg_storageKey);
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
      let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
      let _aidl_return = _aidl_service.deleteKey(&_arg_key);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
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
