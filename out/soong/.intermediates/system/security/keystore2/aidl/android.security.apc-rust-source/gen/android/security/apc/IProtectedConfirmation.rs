#![allow(non_upper_case_globals)]
#![allow(non_snake_case)]
#[allow(unused_imports)] use binder::IBinderInternal;
use binder::declare_binder_interface;
declare_binder_interface! {
  IProtectedConfirmation["android.security.apc.IProtectedConfirmation"] {
    native: BnProtectedConfirmation(on_transact),
    proxy: BpProtectedConfirmation {
    },
  }
}
pub trait IProtectedConfirmation: binder::Interface + Send {
  fn get_descriptor() -> &'static str where Self: Sized { "android.security.apc.IProtectedConfirmation" }
  fn presentPrompt(&self, _arg_listener: &binder::Strong<dyn crate::mangled::_7_android_8_security_3_apc_21_IConfirmationCallback>, _arg_promptText: &str, _arg_extraData: &[u8], _arg_locale: &str, _arg_uiOptionFlags: i32) -> binder::public_api::Result<()>;
  fn cancelPrompt(&self, _arg_listener: &binder::Strong<dyn crate::mangled::_7_android_8_security_3_apc_21_IConfirmationCallback>) -> binder::public_api::Result<()>;
  fn isSupported(&self) -> binder::public_api::Result<bool>;
  fn getDefaultImpl() -> IProtectedConfirmationDefaultRef where Self: Sized {
    DEFAULT_IMPL.lock().unwrap().clone()
  }
  fn setDefaultImpl(d: IProtectedConfirmationDefaultRef) -> IProtectedConfirmationDefaultRef where Self: Sized {
    std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
  }
}
pub trait IProtectedConfirmationDefault: Send + Sync {
  fn presentPrompt(&self, _arg_listener: &binder::Strong<dyn crate::mangled::_7_android_8_security_3_apc_21_IConfirmationCallback>, _arg_promptText: &str, _arg_extraData: &[u8], _arg_locale: &str, _arg_uiOptionFlags: i32) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn cancelPrompt(&self, _arg_listener: &binder::Strong<dyn crate::mangled::_7_android_8_security_3_apc_21_IConfirmationCallback>) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn isSupported(&self) -> binder::public_api::Result<bool> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
}
pub mod transactions {
  pub const presentPrompt: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
  pub const cancelPrompt: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
  pub const isSupported: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
}
pub type IProtectedConfirmationDefaultRef = Option<std::sync::Arc<dyn IProtectedConfirmationDefault>>;
use lazy_static::lazy_static;
lazy_static! {
  static ref DEFAULT_IMPL: std::sync::Mutex<IProtectedConfirmationDefaultRef> = std::sync::Mutex::new(None);
}
pub const FLAG_UI_OPTION_INVERTED: i32 = 1;
pub const FLAG_UI_OPTION_MAGNIFIED: i32 = 2;
pub(crate) mod mangled { pub use super::IProtectedConfirmation as _7_android_8_security_3_apc_22_IProtectedConfirmation; }
impl IProtectedConfirmation for BpProtectedConfirmation {
  fn presentPrompt(&self, _arg_listener: &binder::Strong<dyn crate::mangled::_7_android_8_security_3_apc_21_IConfirmationCallback>, _arg_promptText: &str, _arg_extraData: &[u8], _arg_locale: &str, _arg_uiOptionFlags: i32) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::presentPrompt, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_listener)?;
      _aidl_data.write(_arg_promptText)?;
      _aidl_data.write(_arg_extraData)?;
      _aidl_data.write(_arg_locale)?;
      _aidl_data.write(&_arg_uiOptionFlags)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IProtectedConfirmation>::getDefaultImpl() {
        return _aidl_default_impl.presentPrompt(_arg_listener, _arg_promptText, _arg_extraData, _arg_locale, _arg_uiOptionFlags);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn cancelPrompt(&self, _arg_listener: &binder::Strong<dyn crate::mangled::_7_android_8_security_3_apc_21_IConfirmationCallback>) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::cancelPrompt, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_listener)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IProtectedConfirmation>::getDefaultImpl() {
        return _aidl_default_impl.cancelPrompt(_arg_listener);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn isSupported(&self) -> binder::public_api::Result<bool> {
    let _aidl_reply = self.binder.transact(transactions::isSupported, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IProtectedConfirmation>::getDefaultImpl() {
        return _aidl_default_impl.isSupported();
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: bool = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
}
impl IProtectedConfirmation for binder::Binder<BnProtectedConfirmation> {
  fn presentPrompt(&self, _arg_listener: &binder::Strong<dyn crate::mangled::_7_android_8_security_3_apc_21_IConfirmationCallback>, _arg_promptText: &str, _arg_extraData: &[u8], _arg_locale: &str, _arg_uiOptionFlags: i32) -> binder::public_api::Result<()> { self.0.presentPrompt(_arg_listener, _arg_promptText, _arg_extraData, _arg_locale, _arg_uiOptionFlags) }
  fn cancelPrompt(&self, _arg_listener: &binder::Strong<dyn crate::mangled::_7_android_8_security_3_apc_21_IConfirmationCallback>) -> binder::public_api::Result<()> { self.0.cancelPrompt(_arg_listener) }
  fn isSupported(&self) -> binder::public_api::Result<bool> { self.0.isSupported() }
}
fn on_transact(_aidl_service: &dyn IProtectedConfirmation, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
  match _aidl_code {
    transactions::presentPrompt => {
      let _arg_listener: binder::Strong<dyn crate::mangled::_7_android_8_security_3_apc_21_IConfirmationCallback> = _aidl_data.read()?;
      let _arg_promptText: String = _aidl_data.read()?;
      let _arg_extraData: Vec<u8> = _aidl_data.read()?;
      let _arg_locale: String = _aidl_data.read()?;
      let _arg_uiOptionFlags: i32 = _aidl_data.read()?;
      let _aidl_return = _aidl_service.presentPrompt(&_arg_listener, &_arg_promptText, &_arg_extraData, &_arg_locale, _arg_uiOptionFlags);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::cancelPrompt => {
      let _arg_listener: binder::Strong<dyn crate::mangled::_7_android_8_security_3_apc_21_IConfirmationCallback> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.cancelPrompt(&_arg_listener);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::isSupported => {
      let _aidl_return = _aidl_service.isSupported();
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
