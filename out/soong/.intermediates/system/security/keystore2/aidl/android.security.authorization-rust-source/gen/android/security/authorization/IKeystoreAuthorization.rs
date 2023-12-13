#![allow(non_upper_case_globals)]
#![allow(non_snake_case)]
#[allow(unused_imports)] use binder::IBinderInternal;
use binder::declare_binder_interface;
declare_binder_interface! {
  IKeystoreAuthorization["android.security.authorization.IKeystoreAuthorization"] {
    native: BnKeystoreAuthorization(on_transact),
    proxy: BpKeystoreAuthorization {
    },
  }
}
pub trait IKeystoreAuthorization: binder::Interface + Send {
  fn get_descriptor() -> &'static str where Self: Sized { "android.security.authorization.IKeystoreAuthorization" }
  fn addAuthToken(&self, _arg_authToken: &crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken) -> binder::public_api::Result<()>;
  fn onLockScreenEvent(&self, _arg_lockScreenEvent: crate::mangled::_7_android_8_security_13_authorization_15_LockScreenEvent, _arg_userId: i32, _arg_password: Option<&[u8]>, _arg_unlockingSids: Option<&[i64]>) -> binder::public_api::Result<()>;
  fn getAuthTokensForCredStore(&self, _arg_challenge: i64, _arg_secureUserId: i64, _arg_authTokenMaxAgeMillis: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_security_13_authorization_19_AuthorizationTokens>;
  fn getDefaultImpl() -> IKeystoreAuthorizationDefaultRef where Self: Sized {
    DEFAULT_IMPL.lock().unwrap().clone()
  }
  fn setDefaultImpl(d: IKeystoreAuthorizationDefaultRef) -> IKeystoreAuthorizationDefaultRef where Self: Sized {
    std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
  }
}
pub trait IKeystoreAuthorizationDefault: Send + Sync {
  fn addAuthToken(&self, _arg_authToken: &crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn onLockScreenEvent(&self, _arg_lockScreenEvent: crate::mangled::_7_android_8_security_13_authorization_15_LockScreenEvent, _arg_userId: i32, _arg_password: Option<&[u8]>, _arg_unlockingSids: Option<&[i64]>) -> binder::public_api::Result<()> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
  fn getAuthTokensForCredStore(&self, _arg_challenge: i64, _arg_secureUserId: i64, _arg_authTokenMaxAgeMillis: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_security_13_authorization_19_AuthorizationTokens> {
    Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
  }
}
pub mod transactions {
  pub const addAuthToken: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
  pub const onLockScreenEvent: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
  pub const getAuthTokensForCredStore: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
}
pub type IKeystoreAuthorizationDefaultRef = Option<std::sync::Arc<dyn IKeystoreAuthorizationDefault>>;
use lazy_static::lazy_static;
lazy_static! {
  static ref DEFAULT_IMPL: std::sync::Mutex<IKeystoreAuthorizationDefaultRef> = std::sync::Mutex::new(None);
}
pub(crate) mod mangled { pub use super::IKeystoreAuthorization as _7_android_8_security_13_authorization_22_IKeystoreAuthorization; }
impl IKeystoreAuthorization for BpKeystoreAuthorization {
  fn addAuthToken(&self, _arg_authToken: &crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::addAuthToken, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(_arg_authToken)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreAuthorization>::getDefaultImpl() {
        return _aidl_default_impl.addAuthToken(_arg_authToken);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn onLockScreenEvent(&self, _arg_lockScreenEvent: crate::mangled::_7_android_8_security_13_authorization_15_LockScreenEvent, _arg_userId: i32, _arg_password: Option<&[u8]>, _arg_unlockingSids: Option<&[i64]>) -> binder::public_api::Result<()> {
    let _aidl_reply = self.binder.transact(transactions::onLockScreenEvent, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(&_arg_lockScreenEvent)?;
      _aidl_data.write(&_arg_userId)?;
      _aidl_data.write(&_arg_password)?;
      _aidl_data.write(&_arg_unlockingSids)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreAuthorization>::getDefaultImpl() {
        return _aidl_default_impl.onLockScreenEvent(_arg_lockScreenEvent, _arg_userId, _arg_password, _arg_unlockingSids);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    Ok(())
  }
  fn getAuthTokensForCredStore(&self, _arg_challenge: i64, _arg_secureUserId: i64, _arg_authTokenMaxAgeMillis: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_security_13_authorization_19_AuthorizationTokens> {
    let _aidl_reply = self.binder.transact(transactions::getAuthTokensForCredStore, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
      _aidl_data.mark_sensitive();
      _aidl_data.write(&_arg_challenge)?;
      _aidl_data.write(&_arg_secureUserId)?;
      _aidl_data.write(&_arg_authTokenMaxAgeMillis)?;
      Ok(())
    });
    if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
      if let Some(_aidl_default_impl) = <Self as IKeystoreAuthorization>::getDefaultImpl() {
        return _aidl_default_impl.getAuthTokensForCredStore(_arg_challenge, _arg_secureUserId, _arg_authTokenMaxAgeMillis);
      }
    }
    let _aidl_reply = _aidl_reply?;
    let _aidl_status: binder::Status = _aidl_reply.read()?;
    if !_aidl_status.is_ok() { return Err(_aidl_status); }
    let _aidl_return: crate::mangled::_7_android_8_security_13_authorization_19_AuthorizationTokens = _aidl_reply.read()?;
    Ok(_aidl_return)
  }
}
impl IKeystoreAuthorization for binder::Binder<BnKeystoreAuthorization> {
  fn addAuthToken(&self, _arg_authToken: &crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken) -> binder::public_api::Result<()> { self.0.addAuthToken(_arg_authToken) }
  fn onLockScreenEvent(&self, _arg_lockScreenEvent: crate::mangled::_7_android_8_security_13_authorization_15_LockScreenEvent, _arg_userId: i32, _arg_password: Option<&[u8]>, _arg_unlockingSids: Option<&[i64]>) -> binder::public_api::Result<()> { self.0.onLockScreenEvent(_arg_lockScreenEvent, _arg_userId, _arg_password, _arg_unlockingSids) }
  fn getAuthTokensForCredStore(&self, _arg_challenge: i64, _arg_secureUserId: i64, _arg_authTokenMaxAgeMillis: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_security_13_authorization_19_AuthorizationTokens> { self.0.getAuthTokensForCredStore(_arg_challenge, _arg_secureUserId, _arg_authTokenMaxAgeMillis) }
}
fn on_transact(_aidl_service: &dyn IKeystoreAuthorization, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
  match _aidl_code {
    transactions::addAuthToken => {
      let _arg_authToken: crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken = _aidl_data.read()?;
      let _aidl_return = _aidl_service.addAuthToken(&_arg_authToken);
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::onLockScreenEvent => {
      let _arg_lockScreenEvent: crate::mangled::_7_android_8_security_13_authorization_15_LockScreenEvent = _aidl_data.read()?;
      let _arg_userId: i32 = _aidl_data.read()?;
      let _arg_password: Option<Vec<u8>> = _aidl_data.read()?;
      let _arg_unlockingSids: Option<Vec<i64>> = _aidl_data.read()?;
      let _aidl_return = _aidl_service.onLockScreenEvent(_arg_lockScreenEvent, _arg_userId, _arg_password.as_deref(), _arg_unlockingSids.as_deref());
      match &_aidl_return {
        Ok(_aidl_return) => {
          _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
        }
        Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
      }
      Ok(())
    }
    transactions::getAuthTokensForCredStore => {
      let _arg_challenge: i64 = _aidl_data.read()?;
      let _arg_secureUserId: i64 = _aidl_data.read()?;
      let _arg_authTokenMaxAgeMillis: i64 = _aidl_data.read()?;
      let _aidl_return = _aidl_service.getAuthTokensForCredStore(_arg_challenge, _arg_secureUserId, _arg_authTokenMaxAgeMillis);
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
