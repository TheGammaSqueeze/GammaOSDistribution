#![allow(non_snake_case)]
#![allow(missing_docs)]
pub use binder::public_api as binder;
pub mod aidl {
  pub mod android {
    pub mod security {
      pub mod maintenance {
        pub mod IKeystoreMaintenance {
          #![allow(non_upper_case_globals)]
          #![allow(non_snake_case)]
          #[allow(unused_imports)] use binder::IBinderInternal;
          use binder::declare_binder_interface;
          declare_binder_interface! {
            IKeystoreMaintenance["android.security.maintenance.IKeystoreMaintenance"] {
              native: BnKeystoreMaintenance(on_transact),
              proxy: BpKeystoreMaintenance {
              },
            }
          }
          pub trait IKeystoreMaintenance: binder::Interface + Send {
            fn get_descriptor() -> &'static str where Self: Sized { "android.security.maintenance.IKeystoreMaintenance" }
            fn onUserAdded(&self, _arg_userId: i32) -> binder::public_api::Result<()>;
            fn onUserRemoved(&self, _arg_userId: i32) -> binder::public_api::Result<()>;
            fn onUserPasswordChanged(&self, _arg_userId: i32, _arg_password: Option<&[u8]>) -> binder::public_api::Result<()>;
            fn clearNamespace(&self, _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain, _arg_nspace: i64) -> binder::public_api::Result<()>;
            fn getState(&self, _arg_userId: i32) -> binder::public_api::Result<crate::mangled::_7_android_8_security_11_maintenance_9_UserState>;
            fn earlyBootEnded(&self) -> binder::public_api::Result<()>;
            fn onDeviceOffBody(&self) -> binder::public_api::Result<()>;
            fn migrateKeyNamespace(&self, _arg_source: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_destination: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()>;
            fn deleteAllKeys(&self) -> binder::public_api::Result<()>;
            fn getDefaultImpl() -> IKeystoreMaintenanceDefaultRef where Self: Sized {
              DEFAULT_IMPL.lock().unwrap().clone()
            }
            fn setDefaultImpl(d: IKeystoreMaintenanceDefaultRef) -> IKeystoreMaintenanceDefaultRef where Self: Sized {
              std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
            }
          }
          pub trait IKeystoreMaintenanceDefault: Send + Sync {
            fn onUserAdded(&self, _arg_userId: i32) -> binder::public_api::Result<()> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn onUserRemoved(&self, _arg_userId: i32) -> binder::public_api::Result<()> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn onUserPasswordChanged(&self, _arg_userId: i32, _arg_password: Option<&[u8]>) -> binder::public_api::Result<()> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn clearNamespace(&self, _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain, _arg_nspace: i64) -> binder::public_api::Result<()> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn getState(&self, _arg_userId: i32) -> binder::public_api::Result<crate::mangled::_7_android_8_security_11_maintenance_9_UserState> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn earlyBootEnded(&self) -> binder::public_api::Result<()> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn onDeviceOffBody(&self) -> binder::public_api::Result<()> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn migrateKeyNamespace(&self, _arg_source: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_destination: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn deleteAllKeys(&self) -> binder::public_api::Result<()> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
          }
          pub mod transactions {
            pub const onUserAdded: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
            pub const onUserRemoved: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
            pub const onUserPasswordChanged: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
            pub const clearNamespace: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 3;
            pub const getState: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 4;
            pub const earlyBootEnded: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 5;
            pub const onDeviceOffBody: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 6;
            pub const migrateKeyNamespace: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 7;
            pub const deleteAllKeys: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 8;
          }
          pub type IKeystoreMaintenanceDefaultRef = Option<std::sync::Arc<dyn IKeystoreMaintenanceDefault>>;
          use lazy_static::lazy_static;
          lazy_static! {
            static ref DEFAULT_IMPL: std::sync::Mutex<IKeystoreMaintenanceDefaultRef> = std::sync::Mutex::new(None);
          }
          pub(crate) mod mangled { pub use super::IKeystoreMaintenance as _7_android_8_security_11_maintenance_20_IKeystoreMaintenance; }
          impl IKeystoreMaintenance for BpKeystoreMaintenance {
            fn onUserAdded(&self, _arg_userId: i32) -> binder::public_api::Result<()> {
              let _aidl_reply = self.binder.transact(transactions::onUserAdded, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(&_arg_userId)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreMaintenance>::getDefaultImpl() {
                  return _aidl_default_impl.onUserAdded(_arg_userId);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              Ok(())
            }
            fn onUserRemoved(&self, _arg_userId: i32) -> binder::public_api::Result<()> {
              let _aidl_reply = self.binder.transact(transactions::onUserRemoved, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(&_arg_userId)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreMaintenance>::getDefaultImpl() {
                  return _aidl_default_impl.onUserRemoved(_arg_userId);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              Ok(())
            }
            fn onUserPasswordChanged(&self, _arg_userId: i32, _arg_password: Option<&[u8]>) -> binder::public_api::Result<()> {
              let _aidl_reply = self.binder.transact(transactions::onUserPasswordChanged, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(&_arg_userId)?;
                _aidl_data.write(&_arg_password)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreMaintenance>::getDefaultImpl() {
                  return _aidl_default_impl.onUserPasswordChanged(_arg_userId, _arg_password);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              Ok(())
            }
            fn clearNamespace(&self, _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain, _arg_nspace: i64) -> binder::public_api::Result<()> {
              let _aidl_reply = self.binder.transact(transactions::clearNamespace, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(&_arg_domain)?;
                _aidl_data.write(&_arg_nspace)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreMaintenance>::getDefaultImpl() {
                  return _aidl_default_impl.clearNamespace(_arg_domain, _arg_nspace);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              Ok(())
            }
            fn getState(&self, _arg_userId: i32) -> binder::public_api::Result<crate::mangled::_7_android_8_security_11_maintenance_9_UserState> {
              let _aidl_reply = self.binder.transact(transactions::getState, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(&_arg_userId)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreMaintenance>::getDefaultImpl() {
                  return _aidl_default_impl.getState(_arg_userId);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: crate::mangled::_7_android_8_security_11_maintenance_9_UserState = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
            fn earlyBootEnded(&self) -> binder::public_api::Result<()> {
              let _aidl_reply = self.binder.transact(transactions::earlyBootEnded, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreMaintenance>::getDefaultImpl() {
                  return _aidl_default_impl.earlyBootEnded();
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              Ok(())
            }
            fn onDeviceOffBody(&self) -> binder::public_api::Result<()> {
              let _aidl_reply = self.binder.transact(transactions::onDeviceOffBody, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreMaintenance>::getDefaultImpl() {
                  return _aidl_default_impl.onDeviceOffBody();
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              Ok(())
            }
            fn migrateKeyNamespace(&self, _arg_source: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_destination: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> {
              let _aidl_reply = self.binder.transact(transactions::migrateKeyNamespace, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(_arg_source)?;
                _aidl_data.write(_arg_destination)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreMaintenance>::getDefaultImpl() {
                  return _aidl_default_impl.migrateKeyNamespace(_arg_source, _arg_destination);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              Ok(())
            }
            fn deleteAllKeys(&self) -> binder::public_api::Result<()> {
              let _aidl_reply = self.binder.transact(transactions::deleteAllKeys, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreMaintenance>::getDefaultImpl() {
                  return _aidl_default_impl.deleteAllKeys();
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              Ok(())
            }
          }
          impl IKeystoreMaintenance for binder::Binder<BnKeystoreMaintenance> {
            fn onUserAdded(&self, _arg_userId: i32) -> binder::public_api::Result<()> { self.0.onUserAdded(_arg_userId) }
            fn onUserRemoved(&self, _arg_userId: i32) -> binder::public_api::Result<()> { self.0.onUserRemoved(_arg_userId) }
            fn onUserPasswordChanged(&self, _arg_userId: i32, _arg_password: Option<&[u8]>) -> binder::public_api::Result<()> { self.0.onUserPasswordChanged(_arg_userId, _arg_password) }
            fn clearNamespace(&self, _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain, _arg_nspace: i64) -> binder::public_api::Result<()> { self.0.clearNamespace(_arg_domain, _arg_nspace) }
            fn getState(&self, _arg_userId: i32) -> binder::public_api::Result<crate::mangled::_7_android_8_security_11_maintenance_9_UserState> { self.0.getState(_arg_userId) }
            fn earlyBootEnded(&self) -> binder::public_api::Result<()> { self.0.earlyBootEnded() }
            fn onDeviceOffBody(&self) -> binder::public_api::Result<()> { self.0.onDeviceOffBody() }
            fn migrateKeyNamespace(&self, _arg_source: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_destination: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> { self.0.migrateKeyNamespace(_arg_source, _arg_destination) }
            fn deleteAllKeys(&self) -> binder::public_api::Result<()> { self.0.deleteAllKeys() }
          }
          fn on_transact(_aidl_service: &dyn IKeystoreMaintenance, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
            match _aidl_code {
              transactions::onUserAdded => {
                let _arg_userId: i32 = _aidl_data.read()?;
                let _aidl_return = _aidl_service.onUserAdded(_arg_userId);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::onUserRemoved => {
                let _arg_userId: i32 = _aidl_data.read()?;
                let _aidl_return = _aidl_service.onUserRemoved(_arg_userId);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::onUserPasswordChanged => {
                let _arg_userId: i32 = _aidl_data.read()?;
                let _arg_password: Option<Vec<u8>> = _aidl_data.read()?;
                let _aidl_return = _aidl_service.onUserPasswordChanged(_arg_userId, _arg_password.as_deref());
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::clearNamespace => {
                let _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain = _aidl_data.read()?;
                let _arg_nspace: i64 = _aidl_data.read()?;
                let _aidl_return = _aidl_service.clearNamespace(_arg_domain, _arg_nspace);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::getState => {
                let _arg_userId: i32 = _aidl_data.read()?;
                let _aidl_return = _aidl_service.getState(_arg_userId);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    _aidl_reply.write(_aidl_return)?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::earlyBootEnded => {
                let _aidl_return = _aidl_service.earlyBootEnded();
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::onDeviceOffBody => {
                let _aidl_return = _aidl_service.onDeviceOffBody();
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::migrateKeyNamespace => {
                let _arg_source: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
                let _arg_destination: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
                let _aidl_return = _aidl_service.migrateKeyNamespace(&_arg_source, &_arg_destination);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::deleteAllKeys => {
                let _aidl_return = _aidl_service.deleteAllKeys();
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              _ => Err(binder::StatusCode::UNKNOWN_TRANSACTION)
            }
          }
        }
        pub mod UserState {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { UserState : i32 {
            UNINITIALIZED = 0,
            LSKF_UNLOCKED = 1,
            LSKF_LOCKED = 2,
          } }
          pub(crate) mod mangled { pub use super::UserState as _7_android_8_security_11_maintenance_9_UserState; }
        }
      }
    }
  }
}
pub mod mangled {
  pub use super::aidl::android::security::maintenance::IKeystoreMaintenance::mangled::*;
  pub use super::aidl::android::security::maintenance::UserState::mangled::*;
  pub(crate) use android_system_keystore2::mangled::*;
}
