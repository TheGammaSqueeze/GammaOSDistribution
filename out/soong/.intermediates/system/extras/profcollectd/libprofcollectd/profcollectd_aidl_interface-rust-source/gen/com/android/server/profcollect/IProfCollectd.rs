#![allow(non_upper_case_globals)]
#![allow(non_snake_case)]
#[allow(unused_imports)] use binder::IBinderInternal;
use binder::declare_binder_interface;
declare_binder_interface! {
  IProfCollectd["com.android.server.profcollect.IProfCollectd"] {
    native: BnProfCollectd(on_transact),
    proxy: BpProfCollectd {
    },
  }
}
pub trait IProfCollectd: binder::Interface + Send {
  fn get_descriptor() -> &'static str where Self: Sized { "com.android.server.profcollect.IProfCollectd" }
  fn schedule(&self) -> binder::public_api::Result<()>;
  fn terminate(&self) -> binder::public_api::Result<()>;
  fn trace_once(&self, _arg_tag: &str) -> binder::public_api::Result<()>;
  fn process(&self, _arg_blocking: bool) -> binder::public_api::Result<()>;
  fn report(&self) -> binder::public_api::Result<String>;
  fn copy_report_to_bb(&self, _arg_bb_profile_id: i32, _arg_report: &str) -> binder::public_api::Result<()>;
  fn delete_report(&self, _arg_report: &str) -> binder::public_api::Result<()>;
  fn get_supported_provider(&self) -> binder::public_api::Result<String>;
  fn getDefaultImpl() -> IProfCollectdDefaultRef where Self: Sized {
    DEFAULT_IMPL.lock().unwrap().clone()
  }
  fn setDefaultImpl(d: IProfCollectdDefaultRef) -> IProfCollectdDefaultRef where Self: Sized {
    std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
  }
}
pub trait IProfCollectdDefault: Send + Sync {
  fn schedule(&self) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn terminate(&self) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn trace_once(&self, _arg_tag: &str) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn process(&self, _arg_blocking: bool) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn report(&self) -> binder::public_api::Result<String> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn copy_report_to_bb(&self, _arg_bb_profile_id: i32, _arg_report: &str) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn delete_report(&self, _arg_report: &str) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn get_supported_provider(&self) -> binder::public_api::Result<String> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
}
pub mod transactions {
  pub const schedule: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
  pub const terminate: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
  pub const trace_once: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
  pub const process: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 3;
  pub const report: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 4;
  pub const copy_report_to_bb: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 5;
  pub const delete_report: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 6;
  pub const get_supported_provider: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 7;
}
pub type IProfCollectdDefaultRef = Option<std::sync::Arc<dyn IProfCollectdDefault>>;
use lazy_static::lazy_static;
lazy_static! {
  static ref DEFAULT_IMPL: std::sync::Mutex<IProfCollectdDefaultRef> = std::sync::Mutex::new(None);
}
pub(crate) mod mangled { pub use super::IProfCollectd as _3_com_7_android_6_server_11_profcollect_13_IProfCollectd; }
impl IProfCollectd for BpProfCollectd {
  fn schedule(&self) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::schedule, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IProfCollectd>::getDefaultImpl() {
        return _aidl_default_impl.schedule();
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn terminate(&self) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::terminate, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IProfCollectd>::getDefaultImpl() {
        return _aidl_default_impl.terminate();
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn trace_once(&self, _arg_tag: &str) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::trace_once, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_tag)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IProfCollectd>::getDefaultImpl() {
        return _aidl_default_impl.trace_once(_arg_tag);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn process(&self, _arg_blocking: bool) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::process, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(&_arg_blocking)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IProfCollectd>::getDefaultImpl() {
        return _aidl_default_impl.process(_arg_blocking);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn report(&self) -> binder::public_api::Result<String> {
    let _aidl_reply = self.binder.transact(transactions::report, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IProfCollectd>::getDefaultImpl() {
        return _aidl_default_impl.report();
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: String = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
  fn copy_report_to_bb(&self, _arg_bb_profile_id: i32, _arg_report: &str) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::copy_report_to_bb, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(&_arg_bb_profile_id)?;
      _aidl_data.write(_arg_report)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IProfCollectd>::getDefaultImpl() {
        return _aidl_default_impl.copy_report_to_bb(_arg_bb_profile_id, _arg_report);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn delete_report(&self, _arg_report: &str) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::delete_report, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.write(_arg_report)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IProfCollectd>::getDefaultImpl() {
        return _aidl_default_impl.delete_report(_arg_report);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn get_supported_provider(&self) -> binder::public_api::Result<String> {
    let _aidl_reply = self.binder.transact(transactions::get_supported_provider, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IProfCollectd>::getDefaultImpl() {
        return _aidl_default_impl.get_supported_provider();
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: String = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
}
impl IProfCollectd for binder::Binder<BnProfCollectd> {
  fn schedule(&self) -> binder::public_api::Result<()> { self.0.schedule() }
  fn terminate(&self) -> binder::public_api::Result<()> { self.0.terminate() }
  fn trace_once(&self, _arg_tag: &str) -> binder::public_api::Result<()> { self.0.trace_once(_arg_tag) }
  fn process(&self, _arg_blocking: bool) -> binder::public_api::Result<()> { self.0.process(_arg_blocking) }
  fn report(&self) -> binder::public_api::Result<String> { self.0.report() }
  fn copy_report_to_bb(&self, _arg_bb_profile_id: i32, _arg_report: &str) -> binder::public_api::Result<()> { self.0.copy_report_to_bb(_arg_bb_profile_id, _arg_report) }
  fn delete_report(&self, _arg_report: &str) -> binder::public_api::Result<()> { self.0.delete_report(_arg_report) }
  fn get_supported_provider(&self) -> binder::public_api::Result<String> { self.0.get_supported_provider() }
}
fn on_transact(_aidl_service: &dyn IProfCollectd, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
  match _aidl_code {
    transactions::schedule => {
      let _aidl_return = _aidl_service.schedule();
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::terminate => {
      let _aidl_return = _aidl_service.terminate();
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::trace_once => {
      let _arg_tag: String = _aidl_data.read()?;
      let _aidl_return = _aidl_service.trace_once(&_arg_tag);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::process => {
      let _arg_blocking: bool = _aidl_data.read()?;
      let _aidl_return = _aidl_service.process(_arg_blocking);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::report => {
      let _aidl_return = _aidl_service.report();
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
          _aidl_reply.write(_aidl_return)?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::copy_report_to_bb => {
      let _arg_bb_profile_id: i32 = _aidl_data.read()?;
      let _arg_report: String = _aidl_data.read()?;
      let _aidl_return = _aidl_service.copy_report_to_bb(_arg_bb_profile_id, &_arg_report);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::delete_report => {
      let _arg_report: String = _aidl_data.read()?;
      let _aidl_return = _aidl_service.delete_report(&_arg_report);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::get_supported_provider => {
      let _aidl_return = _aidl_service.get_supported_provider();
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
