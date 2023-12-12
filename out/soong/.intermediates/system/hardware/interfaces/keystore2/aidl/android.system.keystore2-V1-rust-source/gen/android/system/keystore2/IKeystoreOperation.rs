#![allow(non_upper_case_globals)]
#![allow(non_snake_case)]
#[allow(unused_imports)] use binder::IBinderInternal;
use binder::declare_binder_interface;
declare_binder_interface! {
  IKeystoreOperation["android.system.keystore2.IKeystoreOperation"] {
    native: BnKeystoreOperation(on_transact),
    proxy: BpKeystoreOperation {
      cached_version: std::sync::atomic::AtomicI32 = std::sync::atomic::AtomicI32::new(-1),
      cached_hash: std::sync::Mutex<Option<String>> = std::sync::Mutex::new(None)
    },
  stability: binder::Stability::Vintf,
  }
}
pub trait IKeystoreOperation: binder::Interface + Send {
  fn get_descriptor() -> &'static str where Self: Sized { "android.system.keystore2.IKeystoreOperation" }
  fn updateAad(&self, _arg_aadInput: &[u8]) -> binder::public_api::Result<()>;
  fn update(&self, _arg_input: &[u8]) -> binder::public_api::Result<Option<Vec<u8>>>;
  fn finish(&self, _arg_input: Option<&[u8]>, _arg_signature: Option<&[u8]>) -> binder::public_api::Result<Option<Vec<u8>>>;
  fn abort(&self) -> binder::public_api::Result<()>;
  fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
    Ok(VERSION)
  }
  fn getInterfaceHash(&self) -> binder::public_api::Result<String> {
    Ok(HASH.into())
  }
  fn getDefaultImpl() -> IKeystoreOperationDefaultRef where Self: Sized {
    DEFAULT_IMPL.lock().unwrap().clone()
  }
  fn setDefaultImpl(d: IKeystoreOperationDefaultRef) -> IKeystoreOperationDefaultRef where Self: Sized {
    std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
  }
}
pub trait IKeystoreOperationDefault: Send + Sync {
  fn updateAad(&self, _arg_aadInput: &[u8]) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn update(&self, _arg_input: &[u8]) -> binder::public_api::Result<Option<Vec<u8>>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn finish(&self, _arg_input: Option<&[u8]>, _arg_signature: Option<&[u8]>) -> binder::public_api::Result<Option<Vec<u8>>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn abort(&self) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
}
pub mod transactions {
  pub const updateAad: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
  pub const update: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
  pub const finish: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
  pub const abort: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 3;
  pub const getInterfaceVersion: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777214;
  pub const getInterfaceHash: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777213;
}
pub type IKeystoreOperationDefaultRef = Option<std::sync::Arc<dyn IKeystoreOperationDefault>>;
use lazy_static::lazy_static;
lazy_static! {
  static ref DEFAULT_IMPL: std::sync::Mutex<IKeystoreOperationDefaultRef> = std::sync::Mutex::new(None);
}
pub(crate) mod mangled { pub use super::IKeystoreOperation as _7_android_6_system_9_keystore2_18_IKeystoreOperation; }
pub const VERSION: i32 = 1;
pub const HASH: &str = "19e8b65277839bad0ab335c781e3c652324920ce";
impl IKeystoreOperation for BpKeystoreOperation {
  fn updateAad(&self, _arg_aadInput: &[u8]) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::updateAad, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_aadInput)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreOperation>::getDefaultImpl() {
        return _aidl_default_impl.updateAad(_arg_aadInput);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn update(&self, _arg_input: &[u8]) -> binder::public_api::Result<Option<Vec<u8>>> {
    let _aidl_reply = self.binder.transact(transactions::update, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_input)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreOperation>::getDefaultImpl() {
        return _aidl_default_impl.update(_arg_input);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: Option<Vec<u8>> = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn finish(&self, _arg_input: Option<&[u8]>, _arg_signature: Option<&[u8]>) -> binder::public_api::Result<Option<Vec<u8>>> {
    let _aidl_reply = self.binder.transact(transactions::finish, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(&_arg_input)?;
      _aidl_data.write(&_arg_signature)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreOperation>::getDefaultImpl() {
        return _aidl_default_impl.finish(_arg_input, _arg_signature);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: Option<Vec<u8>> = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn abort(&self) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::abort, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreOperation>::getDefaultImpl() {
        return _aidl_default_impl.abort();
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
impl IKeystoreOperation for binder::Binder<BnKeystoreOperation> {
  fn updateAad(&self, _arg_aadInput: &[u8]) -> binder::public_api::Result<()> { self.0.updateAad(_arg_aadInput) }
  fn update(&self, _arg_input: &[u8]) -> binder::public_api::Result<Option<Vec<u8>>> { self.0.update(_arg_input) }
  fn finish(&self, _arg_input: Option<&[u8]>, _arg_signature: Option<&[u8]>) -> binder::public_api::Result<Option<Vec<u8>>> { self.0.finish(_arg_input, _arg_signature) }
  fn abort(&self) -> binder::public_api::Result<()> { self.0.abort() }
  fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> { self.0.getInterfaceVersion() }
  fn getInterfaceHash(&self) -> binder::public_api::Result<String> { self.0.getInterfaceHash() }
}
fn on_transact(_aidl_service: &dyn IKeystoreOperation, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
  match _aidl_code {
    transactions::updateAad => {
      let _arg_aadInput: Vec<u8> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.updateAad(&_arg_aadInput);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::update => {
      let _arg_input: Vec<u8> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.update(&_arg_input);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::finish => {
      let _arg_input: Option<Vec<u8>> = _aidl_data.read()?;
      let _arg_signature: Option<Vec<u8>> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.finish(_arg_input.as_deref(), _arg_signature.as_deref());
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::abort => {
      let _aidl_return = _aidl_service.abort();
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
