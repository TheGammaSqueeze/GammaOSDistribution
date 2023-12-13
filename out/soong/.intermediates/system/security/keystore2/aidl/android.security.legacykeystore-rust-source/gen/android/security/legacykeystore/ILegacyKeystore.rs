#![allow(non_upper_case_globals)]
#![allow(non_snake_case)]
#[allow(unused_imports)] use binder::IBinderInternal;
use binder::declare_binder_interface;
declare_binder_interface! {
  ILegacyKeystore["android.security.legacykeystore.ILegacyKeystore"] {
    native: BnLegacyKeystore(on_transact),
    proxy: BpLegacyKeystore {
    },
  }
}
pub trait ILegacyKeystore: binder::Interface + Send {
  fn get_descriptor() -> &'static str where Self: Sized { "android.security.legacykeystore.ILegacyKeystore" }
  fn get(&self, _arg_alias: &str, _arg_uid: i32) -> binder::public_api::Result<Vec<u8>>;
  fn put(&self, _arg_alias: &str, _arg_uid: i32, _arg_blob: &[u8]) -> binder::public_api::Result<()>;
  fn remove(&self, _arg_alias: &str, _arg_uid: i32) -> binder::public_api::Result<()>;
  fn list(&self, _arg_prefix: &str, _arg_uid: i32) -> binder::public_api::Result<Vec<String>>;
  fn getDefaultImpl() -> ILegacyKeystoreDefaultRef where Self: Sized {
    DEFAULT_IMPL.lock().unwrap().clone()
  }
  fn setDefaultImpl(d: ILegacyKeystoreDefaultRef) -> ILegacyKeystoreDefaultRef where Self: Sized {
    std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
  }
}
pub trait ILegacyKeystoreDefault: Send + Sync {
  fn get(&self, _arg_alias: &str, _arg_uid: i32) -> binder::public_api::Result<Vec<u8>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn put(&self, _arg_alias: &str, _arg_uid: i32, _arg_blob: &[u8]) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn remove(&self, _arg_alias: &str, _arg_uid: i32) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn list(&self, _arg_prefix: &str, _arg_uid: i32) -> binder::public_api::Result<Vec<String>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
}
pub mod transactions {
  pub const get: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
  pub const put: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
  pub const remove: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
  pub const list: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 3;
}
pub type ILegacyKeystoreDefaultRef = Option<std::sync::Arc<dyn ILegacyKeystoreDefault>>;
use lazy_static::lazy_static;
lazy_static! {
  static ref DEFAULT_IMPL: std::sync::Mutex<ILegacyKeystoreDefaultRef> = std::sync::Mutex::new(None);
}
pub const UID_SELF: i32 = -1;
pub const ERROR_SYSTEM_ERROR: i32 = 4;
pub const ERROR_PERMISSION_DENIED: i32 = 6;
pub const ERROR_ENTRY_NOT_FOUND: i32 = 7;
pub(crate) mod mangled { pub use super::ILegacyKeystore as _7_android_8_security_14_legacykeystore_15_ILegacyKeystore; }
impl ILegacyKeystore for BpLegacyKeystore {
  fn get(&self, _arg_alias: &str, _arg_uid: i32) -> binder::public_api::Result<Vec<u8>> {
    let _aidl_reply = self.binder.transact(transactions::get, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_alias)?;
      _aidl_data.write(&_arg_uid)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as ILegacyKeystore>::getDefaultImpl() {
        return _aidl_default_impl.get(_arg_alias, _arg_uid);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: Vec<u8> = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn put(&self, _arg_alias: &str, _arg_uid: i32, _arg_blob: &[u8]) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::put, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_alias)?;
      _aidl_data.write(&_arg_uid)?;
      _aidl_data.write(_arg_blob)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as ILegacyKeystore>::getDefaultImpl() {
        return _aidl_default_impl.put(_arg_alias, _arg_uid, _arg_blob);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn remove(&self, _arg_alias: &str, _arg_uid: i32) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::remove, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_alias)?;
      _aidl_data.write(&_arg_uid)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as ILegacyKeystore>::getDefaultImpl() {
        return _aidl_default_impl.remove(_arg_alias, _arg_uid);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn list(&self, _arg_prefix: &str, _arg_uid: i32) -> binder::public_api::Result<Vec<String>> {
    let _aidl_reply = self.binder.transact(transactions::list, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_prefix)?;
      _aidl_data.write(&_arg_uid)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as ILegacyKeystore>::getDefaultImpl() {
        return _aidl_default_impl.list(_arg_prefix, _arg_uid);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: Vec<String> = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
}
impl ILegacyKeystore for binder::Binder<BnLegacyKeystore> {
  fn get(&self, _arg_alias: &str, _arg_uid: i32) -> binder::public_api::Result<Vec<u8>> { self.0.get(_arg_alias, _arg_uid) }
  fn put(&self, _arg_alias: &str, _arg_uid: i32, _arg_blob: &[u8]) -> binder::public_api::Result<()> { self.0.put(_arg_alias, _arg_uid, _arg_blob) }
  fn remove(&self, _arg_alias: &str, _arg_uid: i32) -> binder::public_api::Result<()> { self.0.remove(_arg_alias, _arg_uid) }
  fn list(&self, _arg_prefix: &str, _arg_uid: i32) -> binder::public_api::Result<Vec<String>> { self.0.list(_arg_prefix, _arg_uid) }
}
fn on_transact(_aidl_service: &dyn ILegacyKeystore, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
  match _aidl_code {
    transactions::get => {
      let _arg_alias: String = _aidl_data.read()?;
      let _arg_uid: i32 = _aidl_data.read()?;
      let _aidl_return = _aidl_service.get(&_arg_alias, _arg_uid);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::put => {
      let _arg_alias: String = _aidl_data.read()?;
      let _arg_uid: i32 = _aidl_data.read()?;
      let _arg_blob: Vec<u8> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.put(&_arg_alias, _arg_uid, &_arg_blob);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::remove => {
      let _arg_alias: String = _aidl_data.read()?;
      let _arg_uid: i32 = _aidl_data.read()?;
      let _aidl_return = _aidl_service.remove(&_arg_alias, _arg_uid);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::list => {
      let _arg_prefix: String = _aidl_data.read()?;
      let _arg_uid: i32 = _aidl_data.read()?;
      let _aidl_return = _aidl_service.list(&_arg_prefix, _arg_uid);
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
