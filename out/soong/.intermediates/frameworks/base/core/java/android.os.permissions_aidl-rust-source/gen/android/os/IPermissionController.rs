#![allow(non_upper_case_globals)]
#![allow(non_snake_case)]
#[allow(unused_imports)] use binder::IBinderInternal;
use binder::declare_binder_interface;
declare_binder_interface! {
  IPermissionController["android.os.IPermissionController"] {
    native: BnPermissionController(on_transact),
    proxy: BpPermissionController {
    },
  }
}
pub trait IPermissionController: binder::Interface + Send {
  fn get_descriptor() -> &'static str where Self: Sized { "android.os.IPermissionController" }
  fn checkPermission(&self, _arg_permission: &str, _arg_pid: i32, _arg_uid: i32) -> binder::public_api::Result<bool>;
  fn noteOp(&self, _arg_op: &str, _arg_uid: i32, _arg_packageName: &str) -> binder::public_api::Result<i32>;
  fn getPackagesForUid(&self, _arg_uid: i32) -> binder::public_api::Result<Vec<String>>;
  fn isRuntimePermission(&self, _arg_permission: &str) -> binder::public_api::Result<bool>;
  fn getPackageUid(&self, _arg_packageName: &str, _arg_flags: i32) -> binder::public_api::Result<i32>;
  fn getDefaultImpl() -> IPermissionControllerDefaultRef where Self: Sized {
    DEFAULT_IMPL.lock().unwrap().clone()
  }
  fn setDefaultImpl(d: IPermissionControllerDefaultRef) -> IPermissionControllerDefaultRef where Self: Sized {
    std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
  }
}
pub trait IPermissionControllerDefault: Send + Sync {
  fn checkPermission(&self, _arg_permission: &str, _arg_pid: i32, _arg_uid: i32) -> binder::public_api::Result<bool> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn noteOp(&self, _arg_op: &str, _arg_uid: i32, _arg_packageName: &str) -> binder::public_api::Result<i32> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn getPackagesForUid(&self, _arg_uid: i32) -> binder::public_api::Result<Vec<String>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn isRuntimePermission(&self, _arg_permission: &str) -> binder::public_api::Result<bool> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn getPackageUid(&self, _arg_packageName: &str, _arg_flags: i32) -> binder::public_api::Result<i32> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
}
pub mod transactions {
  pub const checkPermission: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
  pub const noteOp: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
  pub const getPackagesForUid: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
  pub const isRuntimePermission: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 3;
  pub const getPackageUid: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 4;
}
pub type IPermissionControllerDefaultRef = Option<std::sync::Arc<dyn IPermissionControllerDefault>>;
use lazy_static::lazy_static;
lazy_static! {
  static ref DEFAULT_IMPL: std::sync::Mutex<IPermissionControllerDefaultRef> = std::sync::Mutex::new(None);
}
pub(crate) mod mangled { pub use super::IPermissionController as _7_android_2_os_21_IPermissionController; }
impl IPermissionController for BpPermissionController {
  fn checkPermission(&self, _arg_permission: &str, _arg_pid: i32, _arg_uid: i32) -> binder::public_api::Result<bool> {
    let _aidl_reply = self.binder.transact(transactions::checkPermission, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_permission)?;
      _aidl_data.write(&_arg_pid)?;
      _aidl_data.write(&_arg_uid)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IPermissionController>::getDefaultImpl() {
        return _aidl_default_impl.checkPermission(_arg_permission, _arg_pid, _arg_uid);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: bool = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn noteOp(&self, _arg_op: &str, _arg_uid: i32, _arg_packageName: &str) -> binder::public_api::Result<i32> {
    let _aidl_reply = self.binder.transact(transactions::noteOp, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_op)?;
      _aidl_data.write(&_arg_uid)?;
      _aidl_data.write(_arg_packageName)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IPermissionController>::getDefaultImpl() {
        return _aidl_default_impl.noteOp(_arg_op, _arg_uid, _arg_packageName);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: i32 = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn getPackagesForUid(&self, _arg_uid: i32) -> binder::public_api::Result<Vec<String>> {
    let _aidl_reply = self.binder.transact(transactions::getPackagesForUid, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(&_arg_uid)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IPermissionController>::getDefaultImpl() {
        return _aidl_default_impl.getPackagesForUid(_arg_uid);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: Vec<String> = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn isRuntimePermission(&self, _arg_permission: &str) -> binder::public_api::Result<bool> {
    let _aidl_reply = self.binder.transact(transactions::isRuntimePermission, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_permission)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IPermissionController>::getDefaultImpl() {
        return _aidl_default_impl.isRuntimePermission(_arg_permission);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: bool = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn getPackageUid(&self, _arg_packageName: &str, _arg_flags: i32) -> binder::public_api::Result<i32> {
    let _aidl_reply = self.binder.transact(transactions::getPackageUid, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_packageName)?;
      _aidl_data.write(&_arg_flags)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IPermissionController>::getDefaultImpl() {
        return _aidl_default_impl.getPackageUid(_arg_packageName, _arg_flags);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: i32 = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
}
impl IPermissionController for binder::Binder<BnPermissionController> {
  fn checkPermission(&self, _arg_permission: &str, _arg_pid: i32, _arg_uid: i32) -> binder::public_api::Result<bool> { self.0.checkPermission(_arg_permission, _arg_pid, _arg_uid) }
  fn noteOp(&self, _arg_op: &str, _arg_uid: i32, _arg_packageName: &str) -> binder::public_api::Result<i32> { self.0.noteOp(_arg_op, _arg_uid, _arg_packageName) }
  fn getPackagesForUid(&self, _arg_uid: i32) -> binder::public_api::Result<Vec<String>> { self.0.getPackagesForUid(_arg_uid) }
  fn isRuntimePermission(&self, _arg_permission: &str) -> binder::public_api::Result<bool> { self.0.isRuntimePermission(_arg_permission) }
  fn getPackageUid(&self, _arg_packageName: &str, _arg_flags: i32) -> binder::public_api::Result<i32> { self.0.getPackageUid(_arg_packageName, _arg_flags) }
}
fn on_transact(_aidl_service: &dyn IPermissionController, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
  match _aidl_code {
    transactions::checkPermission => {
      let _arg_permission: String = _aidl_data.read()?;
      let _arg_pid: i32 = _aidl_data.read()?;
      let _arg_uid: i32 = _aidl_data.read()?;
      let _aidl_return = _aidl_service.checkPermission(&_arg_permission, _arg_pid, _arg_uid);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::noteOp => {
      let _arg_op: String = _aidl_data.read()?;
      let _arg_uid: i32 = _aidl_data.read()?;
      let _arg_packageName: String = _aidl_data.read()?;
      let _aidl_return = _aidl_service.noteOp(&_arg_op, _arg_uid, &_arg_packageName);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::getPackagesForUid => {
      let _arg_uid: i32 = _aidl_data.read()?;
      let _aidl_return = _aidl_service.getPackagesForUid(_arg_uid);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::isRuntimePermission => {
      let _arg_permission: String = _aidl_data.read()?;
      let _aidl_return = _aidl_service.isRuntimePermission(&_arg_permission);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::getPackageUid => {
      let _arg_packageName: String = _aidl_data.read()?;
      let _arg_flags: i32 = _aidl_data.read()?;
      let _aidl_return = _aidl_service.getPackageUid(&_arg_packageName, _arg_flags);
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
