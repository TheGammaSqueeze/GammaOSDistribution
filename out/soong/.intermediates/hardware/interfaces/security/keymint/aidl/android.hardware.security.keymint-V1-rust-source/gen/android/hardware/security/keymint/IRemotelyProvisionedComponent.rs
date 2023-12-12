#![allow(non_upper_case_globals)]
#![allow(non_snake_case)]
#[allow(unused_imports)] use binder::IBinderInternal;
use binder::declare_binder_interface;
declare_binder_interface! {
  IRemotelyProvisionedComponent["android.hardware.security.keymint.IRemotelyProvisionedComponent"] {
    native: BnRemotelyProvisionedComponent(on_transact),
    proxy: BpRemotelyProvisionedComponent {
      cached_version: std::sync::atomic::AtomicI32 = std::sync::atomic::AtomicI32::new(-1),
      cached_hash: std::sync::Mutex<Option<String>> = std::sync::Mutex::new(None)
    },
  stability: binder::Stability::Vintf,
  }
}
pub trait IRemotelyProvisionedComponent: binder::Interface + Send {
  fn get_descriptor() -> &'static str where Self: Sized { "android.hardware.security.keymint.IRemotelyProvisionedComponent" }
  fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_15_RpcHardwareInfo>;
  fn generateEcdsaP256KeyPair(&self, _arg_testMode: bool, _arg_macedPublicKey: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey) -> binder::public_api::Result<Vec<u8>>;
  fn generateCertificateRequest(&self, _arg_testMode: bool, _arg_keysToSign: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey], _arg_endpointEncryptionCertChain: &[u8], _arg_challenge: &[u8], _arg_deviceInfo: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo, _arg_protectedData: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData) -> binder::public_api::Result<Vec<u8>>;
  fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
    Ok(VERSION)
  }
  fn getInterfaceHash(&self) -> binder::public_api::Result<String> {
    Ok(HASH.into())
  }
  fn getDefaultImpl() -> IRemotelyProvisionedComponentDefaultRef where Self: Sized {
    DEFAULT_IMPL.lock().unwrap().clone()
  }
  fn setDefaultImpl(d: IRemotelyProvisionedComponentDefaultRef) -> IRemotelyProvisionedComponentDefaultRef where Self: Sized {
    std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
  }
}
pub trait IRemotelyProvisionedComponentDefault: Send + Sync {
  fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_15_RpcHardwareInfo> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn generateEcdsaP256KeyPair(&self, _arg_testMode: bool, _arg_macedPublicKey: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey) -> binder::public_api::Result<Vec<u8>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn generateCertificateRequest(&self, _arg_testMode: bool, _arg_keysToSign: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey], _arg_endpointEncryptionCertChain: &[u8], _arg_challenge: &[u8], _arg_deviceInfo: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo, _arg_protectedData: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData) -> binder::public_api::Result<Vec<u8>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
}
pub mod transactions {
  pub const getHardwareInfo: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
  pub const generateEcdsaP256KeyPair: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
  pub const generateCertificateRequest: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
  pub const getInterfaceVersion: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777214;
  pub const getInterfaceHash: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777213;
}
pub type IRemotelyProvisionedComponentDefaultRef = Option<std::sync::Arc<dyn IRemotelyProvisionedComponentDefault>>;
use lazy_static::lazy_static;
lazy_static! {
  static ref DEFAULT_IMPL: std::sync::Mutex<IRemotelyProvisionedComponentDefaultRef> = std::sync::Mutex::new(None);
}
pub const STATUS_FAILED: i32 = 1;
pub const STATUS_INVALID_MAC: i32 = 2;
pub const STATUS_PRODUCTION_KEY_IN_TEST_REQUEST: i32 = 3;
pub const STATUS_TEST_KEY_IN_PRODUCTION_REQUEST: i32 = 4;
pub const STATUS_INVALID_EEK: i32 = 5;
pub(crate) mod mangled { pub use super::IRemotelyProvisionedComponent as _7_android_8_hardware_8_security_7_keymint_29_IRemotelyProvisionedComponent; }
pub const VERSION: i32 = 1;
pub const HASH: &str = "976674616001f714f4a4df49ee45f548de828524";
impl IRemotelyProvisionedComponent for BpRemotelyProvisionedComponent {
  fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_15_RpcHardwareInfo> {
    let _aidl_reply = self.binder.transact(transactions::getHardwareInfo, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IRemotelyProvisionedComponent>::getDefaultImpl() {
        return _aidl_default_impl.getHardwareInfo();
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_8_hardware_8_security_7_keymint_15_RpcHardwareInfo = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn generateEcdsaP256KeyPair(&self, _arg_testMode: bool, _arg_macedPublicKey: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey) -> binder::public_api::Result<Vec<u8>> {
    let _aidl_reply = self.binder.transact(transactions::generateEcdsaP256KeyPair, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(&_arg_testMode)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IRemotelyProvisionedComponent>::getDefaultImpl() {
        return _aidl_default_impl.generateEcdsaP256KeyPair(_arg_testMode, _arg_macedPublicKey);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: Vec<u8> = _aidl_reply.read()?;
    *_arg_macedPublicKey = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn generateCertificateRequest(&self, _arg_testMode: bool, _arg_keysToSign: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey], _arg_endpointEncryptionCertChain: &[u8], _arg_challenge: &[u8], _arg_deviceInfo: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo, _arg_protectedData: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData) -> binder::public_api::Result<Vec<u8>> {
    let _aidl_reply = self.binder.transact(transactions::generateCertificateRequest, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(&_arg_testMode)?;
      _aidl_data.write(_arg_keysToSign)?;
      _aidl_data.write(_arg_endpointEncryptionCertChain)?;
      _aidl_data.write(_arg_challenge)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IRemotelyProvisionedComponent>::getDefaultImpl() {
        return _aidl_default_impl.generateCertificateRequest(_arg_testMode, _arg_keysToSign, _arg_endpointEncryptionCertChain, _arg_challenge, _arg_deviceInfo, _arg_protectedData);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: Vec<u8> = _aidl_reply.read()?;
    *_arg_deviceInfo = _aidl_reply.read()?;
    *_arg_protectedData = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
    let _aidl_version = self.cached_version.load(std::sync::atomic::Ordering::Relaxed);
    if _aidl_version != -1 { return Ok(_aidl_version); }
    let _aidl_reply = self.binder.transact(transactions::getInterfaceVersion, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
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
    let _aidl_reply = self.binder.transact(transactions::getInterfaceHash, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
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
impl IRemotelyProvisionedComponent for binder::Binder<BnRemotelyProvisionedComponent> {
  fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_15_RpcHardwareInfo> { self.0.getHardwareInfo() }
  fn generateEcdsaP256KeyPair(&self, _arg_testMode: bool, _arg_macedPublicKey: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey) -> binder::public_api::Result<Vec<u8>> { self.0.generateEcdsaP256KeyPair(_arg_testMode, _arg_macedPublicKey) }
  fn generateCertificateRequest(&self, _arg_testMode: bool, _arg_keysToSign: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey], _arg_endpointEncryptionCertChain: &[u8], _arg_challenge: &[u8], _arg_deviceInfo: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo, _arg_protectedData: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData) -> binder::public_api::Result<Vec<u8>> { self.0.generateCertificateRequest(_arg_testMode, _arg_keysToSign, _arg_endpointEncryptionCertChain, _arg_challenge, _arg_deviceInfo, _arg_protectedData) }
  fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> { self.0.getInterfaceVersion() }
  fn getInterfaceHash(&self) -> binder::public_api::Result<String> { self.0.getInterfaceHash() }
}
fn on_transact(_aidl_service: &dyn IRemotelyProvisionedComponent, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
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
    transactions::generateEcdsaP256KeyPair => {
      let _arg_testMode: bool = _aidl_data.read()?;
      let mut _arg_macedPublicKey: crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey = Default::default();
      let _aidl_return = _aidl_service.generateEcdsaP256KeyPair(_arg_testMode, &mut _arg_macedPublicKey);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
          _aidl_reply.write(&_arg_macedPublicKey)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::generateCertificateRequest => {
      let _arg_testMode: bool = _aidl_data.read()?;
      let _arg_keysToSign: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey> = _aidl_data.read()?;
      let _arg_endpointEncryptionCertChain: Vec<u8> = _aidl_data.read()?;
      let _arg_challenge: Vec<u8> = _aidl_data.read()?;
      let mut _arg_deviceInfo: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo = Default::default();
      let mut _arg_protectedData: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData = Default::default();
      let _aidl_return = _aidl_service.generateCertificateRequest(_arg_testMode, &_arg_keysToSign, &_arg_endpointEncryptionCertChain, &_arg_challenge, &mut _arg_deviceInfo, &mut _arg_protectedData);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
          _aidl_reply.write(&_arg_deviceInfo)?;
          _aidl_reply.write(&_arg_protectedData)?;
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
