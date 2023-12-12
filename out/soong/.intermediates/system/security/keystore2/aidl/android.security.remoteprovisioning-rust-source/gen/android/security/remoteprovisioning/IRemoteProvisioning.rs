#![allow(non_upper_case_globals)]
#![allow(non_snake_case)]
#[allow(unused_imports)] use binder::IBinderInternal;
use binder::declare_binder_interface;
declare_binder_interface! {
  IRemoteProvisioning["android.security.remoteprovisioning.IRemoteProvisioning"] {
    native: BnRemoteProvisioning(on_transact),
    proxy: BpRemoteProvisioning {
    },
  }
}
pub trait IRemoteProvisioning: binder::Interface + Send {
  fn get_descriptor() -> &'static str where Self: Sized { "android.security.remoteprovisioning.IRemoteProvisioning" }
  fn getPoolStatus(&self, _arg_expiredBy: i64, _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<crate::mangled::_7_android_8_security_18_remoteprovisioning_21_AttestationPoolStatus>;
  fn generateCsr(&self, _arg_testMode: bool, _arg_numCsr: i32, _arg_eek: &[u8], _arg_challenge: &[u8], _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel, _arg_protectedData: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData, _arg_deviceInfo: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo) -> binder::public_api::Result<Vec<u8>>;
  fn provisionCertChain(&self, _arg_publicKey: &[u8], _arg_batchCert: &[u8], _arg_certs: &[u8], _arg_expirationDate: i64, _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<()>;
  fn generateKeyPair(&self, _arg_is_test_mode: bool, _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<()>;
  fn getImplementationInfo(&self) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_security_18_remoteprovisioning_8_ImplInfo>>;
  fn deleteAllKeys(&self) -> binder::public_api::Result<i64>;
  fn getDefaultImpl() -> IRemoteProvisioningDefaultRef where Self: Sized {
    DEFAULT_IMPL.lock().unwrap().clone()
  }
  fn setDefaultImpl(d: IRemoteProvisioningDefaultRef) -> IRemoteProvisioningDefaultRef where Self: Sized {
    std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
  }
}
pub trait IRemoteProvisioningDefault: Send + Sync {
  fn getPoolStatus(&self, _arg_expiredBy: i64, _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<crate::mangled::_7_android_8_security_18_remoteprovisioning_21_AttestationPoolStatus> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn generateCsr(&self, _arg_testMode: bool, _arg_numCsr: i32, _arg_eek: &[u8], _arg_challenge: &[u8], _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel, _arg_protectedData: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData, _arg_deviceInfo: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo) -> binder::public_api::Result<Vec<u8>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn provisionCertChain(&self, _arg_publicKey: &[u8], _arg_batchCert: &[u8], _arg_certs: &[u8], _arg_expirationDate: i64, _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn generateKeyPair(&self, _arg_is_test_mode: bool, _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn getImplementationInfo(&self) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_security_18_remoteprovisioning_8_ImplInfo>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn deleteAllKeys(&self) -> binder::public_api::Result<i64> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
}
pub mod transactions {
  pub const getPoolStatus: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
  pub const generateCsr: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
  pub const provisionCertChain: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
  pub const generateKeyPair: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 3;
  pub const getImplementationInfo: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 4;
  pub const deleteAllKeys: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 5;
}
pub type IRemoteProvisioningDefaultRef = Option<std::sync::Arc<dyn IRemoteProvisioningDefault>>;
use lazy_static::lazy_static;
lazy_static! {
  static ref DEFAULT_IMPL: std::sync::Mutex<IRemoteProvisioningDefaultRef> = std::sync::Mutex::new(None);
}
pub(crate) mod mangled { pub use super::IRemoteProvisioning as _7_android_8_security_18_remoteprovisioning_19_IRemoteProvisioning; }
impl IRemoteProvisioning for BpRemoteProvisioning {
  fn getPoolStatus(&self, _arg_expiredBy: i64, _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<crate::mangled::_7_android_8_security_18_remoteprovisioning_21_AttestationPoolStatus> {
    let _aidl_reply = self.binder.transact(transactions::getPoolStatus, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(&_arg_expiredBy)?;
      _aidl_data.write(&_arg_secLevel)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IRemoteProvisioning>::getDefaultImpl() {
        return _aidl_default_impl.getPoolStatus(_arg_expiredBy, _arg_secLevel);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_8_security_18_remoteprovisioning_21_AttestationPoolStatus = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn generateCsr(&self, _arg_testMode: bool, _arg_numCsr: i32, _arg_eek: &[u8], _arg_challenge: &[u8], _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel, _arg_protectedData: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData, _arg_deviceInfo: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo) -> binder::public_api::Result<Vec<u8>> {
    let _aidl_reply = self.binder.transact(transactions::generateCsr, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(&_arg_testMode)?;
      _aidl_data.write(&_arg_numCsr)?;
      _aidl_data.write(_arg_eek)?;
      _aidl_data.write(_arg_challenge)?;
      _aidl_data.write(&_arg_secLevel)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IRemoteProvisioning>::getDefaultImpl() {
        return _aidl_default_impl.generateCsr(_arg_testMode, _arg_numCsr, _arg_eek, _arg_challenge, _arg_secLevel, _arg_protectedData, _arg_deviceInfo);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: Vec<u8> = _aidl_reply.read()?;
    *_arg_protectedData = _aidl_reply.read()?;
    *_arg_deviceInfo = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn provisionCertChain(&self, _arg_publicKey: &[u8], _arg_batchCert: &[u8], _arg_certs: &[u8], _arg_expirationDate: i64, _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::provisionCertChain, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_publicKey)?;
      _aidl_data.write(_arg_batchCert)?;
      _aidl_data.write(_arg_certs)?;
      _aidl_data.write(&_arg_expirationDate)?;
      _aidl_data.write(&_arg_secLevel)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IRemoteProvisioning>::getDefaultImpl() {
        return _aidl_default_impl.provisionCertChain(_arg_publicKey, _arg_batchCert, _arg_certs, _arg_expirationDate, _arg_secLevel);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn generateKeyPair(&self, _arg_is_test_mode: bool, _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::generateKeyPair, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(&_arg_is_test_mode)?;
      _aidl_data.write(&_arg_secLevel)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IRemoteProvisioning>::getDefaultImpl() {
        return _aidl_default_impl.generateKeyPair(_arg_is_test_mode, _arg_secLevel);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn getImplementationInfo(&self) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_security_18_remoteprovisioning_8_ImplInfo>> {
    let _aidl_reply = self.binder.transact(transactions::getImplementationInfo, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IRemoteProvisioning>::getDefaultImpl() {
        return _aidl_default_impl.getImplementationInfo();
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: Vec<crate::mangled::_7_android_8_security_18_remoteprovisioning_8_ImplInfo> = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn deleteAllKeys(&self) -> binder::public_api::Result<i64> {
    let _aidl_reply = self.binder.transact(transactions::deleteAllKeys, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IRemoteProvisioning>::getDefaultImpl() {
        return _aidl_default_impl.deleteAllKeys();
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: i64 = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
}
impl IRemoteProvisioning for binder::Binder<BnRemoteProvisioning> {
  fn getPoolStatus(&self, _arg_expiredBy: i64, _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<crate::mangled::_7_android_8_security_18_remoteprovisioning_21_AttestationPoolStatus> { self.0.getPoolStatus(_arg_expiredBy, _arg_secLevel) }
  fn generateCsr(&self, _arg_testMode: bool, _arg_numCsr: i32, _arg_eek: &[u8], _arg_challenge: &[u8], _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel, _arg_protectedData: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData, _arg_deviceInfo: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo) -> binder::public_api::Result<Vec<u8>> { self.0.generateCsr(_arg_testMode, _arg_numCsr, _arg_eek, _arg_challenge, _arg_secLevel, _arg_protectedData, _arg_deviceInfo) }
  fn provisionCertChain(&self, _arg_publicKey: &[u8], _arg_batchCert: &[u8], _arg_certs: &[u8], _arg_expirationDate: i64, _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<()> { self.0.provisionCertChain(_arg_publicKey, _arg_batchCert, _arg_certs, _arg_expirationDate, _arg_secLevel) }
  fn generateKeyPair(&self, _arg_is_test_mode: bool, _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<()> { self.0.generateKeyPair(_arg_is_test_mode, _arg_secLevel) }
  fn getImplementationInfo(&self) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_security_18_remoteprovisioning_8_ImplInfo>> { self.0.getImplementationInfo() }
  fn deleteAllKeys(&self) -> binder::public_api::Result<i64> { self.0.deleteAllKeys() }
}
fn on_transact(_aidl_service: &dyn IRemoteProvisioning, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
  match _aidl_code {
    transactions::getPoolStatus => {
      let _arg_expiredBy: i64 = _aidl_data.read()?;
      let _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel = _aidl_data.read()?;
      let _aidl_return = _aidl_service.getPoolStatus(_arg_expiredBy, _arg_secLevel);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::generateCsr => {
      let _arg_testMode: bool = _aidl_data.read()?;
      let _arg_numCsr: i32 = _aidl_data.read()?;
      let _arg_eek: Vec<u8> = _aidl_data.read()?;
      let _arg_challenge: Vec<u8> = _aidl_data.read()?;
      let _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel = _aidl_data.read()?;
      let mut _arg_protectedData: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData = Default::default();
      let mut _arg_deviceInfo: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo = Default::default();
      let _aidl_return = _aidl_service.generateCsr(_arg_testMode, _arg_numCsr, &_arg_eek, &_arg_challenge, _arg_secLevel, &mut _arg_protectedData, &mut _arg_deviceInfo);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
          _aidl_reply.write(&_arg_protectedData)?;
          _aidl_reply.write(&_arg_deviceInfo)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::provisionCertChain => {
      let _arg_publicKey: Vec<u8> = _aidl_data.read()?;
      let _arg_batchCert: Vec<u8> = _aidl_data.read()?;
      let _arg_certs: Vec<u8> = _aidl_data.read()?;
      let _arg_expirationDate: i64 = _aidl_data.read()?;
      let _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel = _aidl_data.read()?;
      let _aidl_return = _aidl_service.provisionCertChain(&_arg_publicKey, &_arg_batchCert, &_arg_certs, _arg_expirationDate, _arg_secLevel);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::generateKeyPair => {
      let _arg_is_test_mode: bool = _aidl_data.read()?;
      let _arg_secLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel = _aidl_data.read()?;
      let _aidl_return = _aidl_service.generateKeyPair(_arg_is_test_mode, _arg_secLevel);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::getImplementationInfo => {
      let _aidl_return = _aidl_service.getImplementationInfo();
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
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
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    _ => Err(binder::StatusCode::UNKNOWN_TRANSACTION)
  }
}
