#![allow(non_upper_case_globals)]
#![allow(non_snake_case)]
#[allow(unused_imports)] use binder::IBinderInternal;
use binder::declare_binder_interface;
declare_binder_interface! {
  IKeystoreMetrics["android.security.metrics.IKeystoreMetrics"] {
    native: BnKeystoreMetrics(on_transact),
    proxy: BpKeystoreMetrics {
    },
  }
}
pub trait IKeystoreMetrics: binder::Interface + Send {
  fn get_descriptor() -> &'static str where Self: Sized { "android.security.metrics.IKeystoreMetrics" }
  fn pullMetrics(&self, _arg_atomID: crate::mangled::_7_android_8_security_7_metrics_6_AtomID) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_security_7_metrics_12_KeystoreAtom>>;
  fn getDefaultImpl() -> IKeystoreMetricsDefaultRef where Self: Sized {
    DEFAULT_IMPL.lock().unwrap().clone()
  }
  fn setDefaultImpl(d: IKeystoreMetricsDefaultRef) -> IKeystoreMetricsDefaultRef where Self: Sized {
    std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
  }
}
pub trait IKeystoreMetricsDefault: Send + Sync {
  fn pullMetrics(&self, _arg_atomID: crate::mangled::_7_android_8_security_7_metrics_6_AtomID) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_security_7_metrics_12_KeystoreAtom>> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
}
pub mod transactions {
  pub const pullMetrics: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
}
pub type IKeystoreMetricsDefaultRef = Option<std::sync::Arc<dyn IKeystoreMetricsDefault>>;
use lazy_static::lazy_static;
lazy_static! {
  static ref DEFAULT_IMPL: std::sync::Mutex<IKeystoreMetricsDefaultRef> = std::sync::Mutex::new(None);
}
pub(crate) mod mangled { pub use super::IKeystoreMetrics as _7_android_8_security_7_metrics_16_IKeystoreMetrics; }
impl IKeystoreMetrics for BpKeystoreMetrics {
  fn pullMetrics(&self, _arg_atomID: crate::mangled::_7_android_8_security_7_metrics_6_AtomID) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_security_7_metrics_12_KeystoreAtom>> {
    let _aidl_reply = self.binder.transact(transactions::pullMetrics, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(&_arg_atomID)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreMetrics>::getDefaultImpl() {
        return _aidl_default_impl.pullMetrics(_arg_atomID);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: Vec<crate::mangled::_7_android_8_security_7_metrics_12_KeystoreAtom> = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
}
impl IKeystoreMetrics for binder::Binder<BnKeystoreMetrics> {
  fn pullMetrics(&self, _arg_atomID: crate::mangled::_7_android_8_security_7_metrics_6_AtomID) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_security_7_metrics_12_KeystoreAtom>> { self.0.pullMetrics(_arg_atomID) }
}
fn on_transact(_aidl_service: &dyn IKeystoreMetrics, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
  match _aidl_code {
    transactions::pullMetrics => {
      let _arg_atomID: crate::mangled::_7_android_8_security_7_metrics_6_AtomID = _aidl_data.read()?;
      let _aidl_return = _aidl_service.pullMetrics(_arg_atomID);
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
