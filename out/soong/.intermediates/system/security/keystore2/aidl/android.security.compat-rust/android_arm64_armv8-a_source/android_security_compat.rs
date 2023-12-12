#![allow(non_snake_case)]
#![allow(missing_docs)]
pub use binder::public_api as binder;
pub mod aidl {
  pub mod android {
    pub mod security {
      pub mod compat {
        pub mod IKeystoreCompatService {
          #![allow(non_upper_case_globals)]
          #![allow(non_snake_case)]
          #[allow(unused_imports)] use binder::IBinderInternal;
          use binder::declare_binder_interface;
          declare_binder_interface! {
            IKeystoreCompatService["android.security.compat.IKeystoreCompatService"] {
              native: BnKeystoreCompatService(on_transact),
              proxy: BpKeystoreCompatService {
              },
            }
          }
          pub trait IKeystoreCompatService: binder::Interface + Send {
            fn get_descriptor() -> &'static str where Self: Sized { "android.security.compat.IKeystoreCompatService" }
            fn getKeyMintDevice(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_IKeyMintDevice>>;
            fn getSecureClock(&self) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_11_secureclock_12_ISecureClock>>;
            fn getSharedSecret(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_13_ISharedSecret>>;
            fn getDefaultImpl() -> IKeystoreCompatServiceDefaultRef where Self: Sized {
              DEFAULT_IMPL.lock().unwrap().clone()
            }
            fn setDefaultImpl(d: IKeystoreCompatServiceDefaultRef) -> IKeystoreCompatServiceDefaultRef where Self: Sized {
              std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
            }
          }
          pub trait IKeystoreCompatServiceDefault: Send + Sync {
            fn getKeyMintDevice(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_IKeyMintDevice>> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn getSecureClock(&self) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_11_secureclock_12_ISecureClock>> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn getSharedSecret(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_13_ISharedSecret>> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
          }
          pub mod transactions {
            pub const getKeyMintDevice: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
            pub const getSecureClock: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
            pub const getSharedSecret: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
          }
          pub type IKeystoreCompatServiceDefaultRef = Option<std::sync::Arc<dyn IKeystoreCompatServiceDefault>>;
          use lazy_static::lazy_static;
          lazy_static! {
            static ref DEFAULT_IMPL: std::sync::Mutex<IKeystoreCompatServiceDefaultRef> = std::sync::Mutex::new(None);
          }
          pub(crate) mod mangled { pub use super::IKeystoreCompatService as _7_android_8_security_6_compat_22_IKeystoreCompatService; }
          impl IKeystoreCompatService for BpKeystoreCompatService {
            fn getKeyMintDevice(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_IKeyMintDevice>> {
              let _aidl_reply = self.binder.transact(transactions::getKeyMintDevice, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.write(&_arg_securityLevel)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreCompatService>::getDefaultImpl() {
                  return _aidl_default_impl.getKeyMintDevice(_arg_securityLevel);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_IKeyMintDevice> = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
            fn getSecureClock(&self) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_11_secureclock_12_ISecureClock>> {
              let _aidl_reply = self.binder.transact(transactions::getSecureClock, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreCompatService>::getDefaultImpl() {
                  return _aidl_default_impl.getSecureClock();
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_11_secureclock_12_ISecureClock> = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
            fn getSharedSecret(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_13_ISharedSecret>> {
              let _aidl_reply = self.binder.transact(transactions::getSharedSecret, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.write(&_arg_securityLevel)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreCompatService>::getDefaultImpl() {
                  return _aidl_default_impl.getSharedSecret(_arg_securityLevel);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_13_ISharedSecret> = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
          }
          impl IKeystoreCompatService for binder::Binder<BnKeystoreCompatService> {
            fn getKeyMintDevice(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_IKeyMintDevice>> { self.0.getKeyMintDevice(_arg_securityLevel) }
            fn getSecureClock(&self) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_11_secureclock_12_ISecureClock>> { self.0.getSecureClock() }
            fn getSharedSecret(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_13_ISharedSecret>> { self.0.getSharedSecret(_arg_securityLevel) }
          }
          fn on_transact(_aidl_service: &dyn IKeystoreCompatService, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
            match _aidl_code {
              transactions::getKeyMintDevice => {
                let _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel = _aidl_data.read()?;
                let _aidl_return = _aidl_service.getKeyMintDevice(_arg_securityLevel);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    _aidl_reply.write(_aidl_return)?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::getSecureClock => {
                let _aidl_return = _aidl_service.getSecureClock();
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    _aidl_reply.write(_aidl_return)?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::getSharedSecret => {
                let _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel = _aidl_data.read()?;
                let _aidl_return = _aidl_service.getSharedSecret(_arg_securityLevel);
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
        }
      }
    }
  }
}
pub mod mangled {
  pub use super::aidl::android::security::compat::IKeystoreCompatService::mangled::*;
  pub(crate) use android_hardware_security_keymint::mangled::*;
  pub(crate) use android_hardware_security_secureclock::mangled::*;
  pub(crate) use android_hardware_security_sharedsecret::mangled::*;
}
