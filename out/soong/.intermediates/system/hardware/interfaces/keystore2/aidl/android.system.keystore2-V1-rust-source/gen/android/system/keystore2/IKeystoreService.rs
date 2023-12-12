#![allow(non_upper_case_globals)]
#![allow(non_snake_case)]
#[allow(unused_imports)] use binder::IBinderInternal;
use binder::declare_binder_interface;
declare_binder_interface! {
  IKeystoreService["android.system.keystore2.IKeystoreService"] {
    native: BnKeystoreService(on_transact),
    proxy: BpKeystoreService {
      cached_version: std::sync::atomic::AtomicI32 = std::sync::atomic::AtomicI32::new(-1),
      cached_hash: std::sync::Mutex<Option<String>> = std::sync::Mutex::new(None)
    },
  stability: binder::Stability::Vintf,
  }
}
pub trait IKeystoreService: binder::Interface + Send {
  fn get_descriptor() -> &'static str where Self: Sized { "android.system.keystore2.IKeystoreService" }
  fn getSecurityLevel(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_6_system_9_keystore2_22_IKeystoreSecurityLevel>>;
  fn getKeyEntry(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_16_KeyEntryResponse>;
  fn updateSubcomponent(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_publicCert: Option<&[u8]>, _arg_certificateChain: Option<&[u8]>) -> binder::public_api::Result<()>;
  fn listEntries(&self, _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain, _arg_nspace: i64) -> binder::public_api::Result<Vec<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>>;
  fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()>;
  fn grant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32, _arg_accessVector: i32) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>;
  fn ungrant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32) -> binder::public_api::Result<()>;
  fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
    Ok(VERSION)
  }
  fn getInterfaceHash(&self) -> binder::public_api::Result<String> {
    Ok(HASH.into())
  }
  fn getDefaultImpl() -> IKeystoreServiceDefaultRef where Self: Sized {
    DEFAULT_IMPL.lock().unwrap().clone()
  }
  fn setDefaultImpl(d: IKeystoreServiceDefaultRef) -> IKeystoreServiceDefaultRef where Self: Sized {
    std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
  }
}
pub trait IKeystoreServiceDefault: Send + Sync {
  fn getSecurityLevel(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_6_system_9_keystore2_22_IKeystoreSecurityLevel>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn getKeyEntry(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_16_KeyEntryResponse> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn updateSubcomponent(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_publicCert: Option<&[u8]>, _arg_certificateChain: Option<&[u8]>) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn listEntries(&self, _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain, _arg_nspace: i64) -> binder::public_api::Result<Vec<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn grant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32, _arg_accessVector: i32) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn ungrant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
}
pub mod transactions {
  pub const getSecurityLevel: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
  pub const getKeyEntry: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
  pub const updateSubcomponent: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
  pub const listEntries: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 3;
  pub const deleteKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 4;
  pub const grant: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 5;
  pub const ungrant: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 6;
  pub const getInterfaceVersion: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777214;
  pub const getInterfaceHash: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777213;
}
pub type IKeystoreServiceDefaultRef = Option<std::sync::Arc<dyn IKeystoreServiceDefault>>;
use lazy_static::lazy_static;
lazy_static! {
  static ref DEFAULT_IMPL: std::sync::Mutex<IKeystoreServiceDefaultRef> = std::sync::Mutex::new(None);
}
pub(crate) mod mangled { pub use super::IKeystoreService as _7_android_6_system_9_keystore2_16_IKeystoreService; }
pub const VERSION: i32 = 1;
pub const HASH: &str = "19e8b65277839bad0ab335c781e3c652324920ce";
impl IKeystoreService for BpKeystoreService {
  fn getSecurityLevel(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_6_system_9_keystore2_22_IKeystoreSecurityLevel>> {
    let _aidl_reply = self.binder.transact(transactions::getSecurityLevel, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(&_arg_securityLevel)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreService>::getDefaultImpl() {
        return _aidl_default_impl.getSecurityLevel(_arg_securityLevel);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: binder::Strong<dyn crate::mangled::_7_android_6_system_9_keystore2_22_IKeystoreSecurityLevel> = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn getKeyEntry(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_16_KeyEntryResponse> {
    let _aidl_reply = self.binder.transact(transactions::getKeyEntry, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_key)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreService>::getDefaultImpl() {
        return _aidl_default_impl.getKeyEntry(_arg_key);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_6_system_9_keystore2_16_KeyEntryResponse = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn updateSubcomponent(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_publicCert: Option<&[u8]>, _arg_certificateChain: Option<&[u8]>) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::updateSubcomponent, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_key)?;
      _aidl_data.write(&_arg_publicCert)?;
      _aidl_data.write(&_arg_certificateChain)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreService>::getDefaultImpl() {
        return _aidl_default_impl.updateSubcomponent(_arg_key, _arg_publicCert, _arg_certificateChain);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn listEntries(&self, _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain, _arg_nspace: i64) -> binder::public_api::Result<Vec<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>> {
    let _aidl_reply = self.binder.transact(transactions::listEntries, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(&_arg_domain)?;
      _aidl_data.write(&_arg_nspace)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreService>::getDefaultImpl() {
        return _aidl_default_impl.listEntries(_arg_domain, _arg_nspace);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: Vec<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor> = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::deleteKey, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_key)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreService>::getDefaultImpl() {
        return _aidl_default_impl.deleteKey(_arg_key);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn grant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32, _arg_accessVector: i32) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor> {
    let _aidl_reply = self.binder.transact(transactions::grant, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_key)?;
      _aidl_data.write(&_arg_granteeUid)?;
      _aidl_data.write(&_arg_accessVector)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreService>::getDefaultImpl() {
        return _aidl_default_impl.grant(_arg_key, _arg_granteeUid, _arg_accessVector);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn ungrant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::ungrant, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_key)?;
      _aidl_data.write(&_arg_granteeUid)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreService>::getDefaultImpl() {
        return _aidl_default_impl.ungrant(_arg_key, _arg_granteeUid);
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
impl IKeystoreService for binder::Binder<BnKeystoreService> {
  fn getSecurityLevel(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_6_system_9_keystore2_22_IKeystoreSecurityLevel>> { self.0.getSecurityLevel(_arg_securityLevel) }
  fn getKeyEntry(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_16_KeyEntryResponse> { self.0.getKeyEntry(_arg_key) }
  fn updateSubcomponent(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_publicCert: Option<&[u8]>, _arg_certificateChain: Option<&[u8]>) -> binder::public_api::Result<()> { self.0.updateSubcomponent(_arg_key, _arg_publicCert, _arg_certificateChain) }
  fn listEntries(&self, _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain, _arg_nspace: i64) -> binder::public_api::Result<Vec<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>> { self.0.listEntries(_arg_domain, _arg_nspace) }
  fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> { self.0.deleteKey(_arg_key) }
  fn grant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32, _arg_accessVector: i32) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor> { self.0.grant(_arg_key, _arg_granteeUid, _arg_accessVector) }
  fn ungrant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32) -> binder::public_api::Result<()> { self.0.ungrant(_arg_key, _arg_granteeUid) }
  fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> { self.0.getInterfaceVersion() }
  fn getInterfaceHash(&self) -> binder::public_api::Result<String> { self.0.getInterfaceHash() }
}
fn on_transact(_aidl_service: &dyn IKeystoreService, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
  match _aidl_code {
    transactions::getSecurityLevel => {
      let _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel = _aidl_data.read()?;
      let _aidl_return = _aidl_service.getSecurityLevel(_arg_securityLevel);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::getKeyEntry => {
      let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
      let _aidl_return = _aidl_service.getKeyEntry(&_arg_key);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::updateSubcomponent => {
      let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
      let _arg_publicCert: Option<Vec<u8>> = _aidl_data.read()?;
      let _arg_certificateChain: Option<Vec<u8>> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.updateSubcomponent(&_arg_key, _arg_publicCert.as_deref(), _arg_certificateChain.as_deref());
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::listEntries => {
      let _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain = _aidl_data.read()?;
      let _arg_nspace: i64 = _aidl_data.read()?;
      let _aidl_return = _aidl_service.listEntries(_arg_domain, _arg_nspace);
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
    transactions::grant => {
      let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
      let _arg_granteeUid: i32 = _aidl_data.read()?;
      let _arg_accessVector: i32 = _aidl_data.read()?;
      let _aidl_return = _aidl_service.grant(&_arg_key, _arg_granteeUid, _arg_accessVector);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::ungrant => {
      let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
      let _arg_granteeUid: i32 = _aidl_data.read()?;
      let _aidl_return = _aidl_service.ungrant(&_arg_key, _arg_granteeUid);
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
