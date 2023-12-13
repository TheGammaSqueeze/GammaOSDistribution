#![allow(non_upper_case_globals)]
#![allow(non_snake_case)]
#[allow(unused_imports)] use binder::IBinderInternal;
use binder::declare_binder_interface;
declare_binder_interface! {
  IConfirmationCallback["android.security.apc.IConfirmationCallback"] {
    native: BnConfirmationCallback(on_transact),
    proxy: BpConfirmationCallback {
    },
  }
}
pub trait IConfirmationCallback: binder::Interface + Send {
  fn get_descriptor() -> &'static str where Self: Sized { "android.security.apc.IConfirmationCallback" }
  fn onCompleted(&self, _arg_result: crate::mangled::_7_android_8_security_3_apc_12_ResponseCode, _arg_dataConfirmed: Option<&[u8]>) -> binder::public_api::Result<()>;
  fn getDefaultImpl() -> IConfirmationCallbackDefaultRef where Self: Sized {
    DEFAULT_IMPL.lock().unwrap().clone()
  }
  fn setDefaultImpl(d: IConfirmationCallbackDefaultRef) -> IConfirmationCallbackDefaultRef where Self: Sized {
    std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
  }
}
pub trait IConfirmationCallbackDefault: Send + Sync {
  fn onCompleted(&self, _arg_result: crate::mangled::_7_android_8_security_3_apc_12_ResponseCode, _arg_dataConfirmed: Option<&[u8]>) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
}
pub mod transactions {
  pub const onCompleted: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
}
pub type IConfirmationCallbackDefaultRef = Option<std::sync::Arc<dyn IConfirmationCallbackDefault>>;
use lazy_static::lazy_static;
lazy_static! {
  static ref DEFAULT_IMPL: std::sync::Mutex<IConfirmationCallbackDefaultRef> = std::sync::Mutex::new(None);
}
pub(crate) mod mangled { pub use super::IConfirmationCallback as _7_android_8_security_3_apc_21_IConfirmationCallback; }
impl IConfirmationCallback for BpConfirmationCallback {
  fn onCompleted(&self, _arg_result: crate::mangled::_7_android_8_security_3_apc_12_ResponseCode, _arg_dataConfirmed: Option<&[u8]>) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::onCompleted, binder::FLAG_ONEWAY | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(&_arg_result)?;
      _aidl_data.write(&_arg_dataConfirmed)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IConfirmationCallback>::getDefaultImpl() {
        return _aidl_default_impl.onCompleted(_arg_result, _arg_dataConfirmed);
      }
    }
    let _aidl_reply = _aidl_reply?;
    Ok(())
  }
}
impl IConfirmationCallback for binder::Binder<BnConfirmationCallback> {
  fn onCompleted(&self, _arg_result: crate::mangled::_7_android_8_security_3_apc_12_ResponseCode, _arg_dataConfirmed: Option<&[u8]>) -> binder::public_api::Result<()> { self.0.onCompleted(_arg_result, _arg_dataConfirmed) }
}
fn on_transact(_aidl_service: &dyn IConfirmationCallback, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
  match _aidl_code {
    transactions::onCompleted => {
      let _arg_result: crate::mangled::_7_android_8_security_3_apc_12_ResponseCode = _aidl_data.read()?;
      let _arg_dataConfirmed: Option<Vec<u8>> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.onCompleted(_arg_result, _arg_dataConfirmed.as_deref());
      Ok(())
    }
    _ => Err(binder::StatusCode::UNKNOWN_TRANSACTION)
  }
}
