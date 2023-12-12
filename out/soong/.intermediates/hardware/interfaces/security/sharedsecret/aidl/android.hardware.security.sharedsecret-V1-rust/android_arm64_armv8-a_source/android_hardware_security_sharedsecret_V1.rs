#![allow(non_snake_case)]
#![allow(missing_docs)]
pub use binder::public_api as binder;
pub mod aidl {
  pub mod android {
    pub mod hardware {
      pub mod security {
        pub mod sharedsecret {
          pub mod ISharedSecret {
            #![allow(non_upper_case_globals)]
            #![allow(non_snake_case)]
            #[allow(unused_imports)] use binder::IBinderInternal;
            use binder::declare_binder_interface;
            declare_binder_interface! {
              ISharedSecret["android.hardware.security.sharedsecret.ISharedSecret"] {
                native: BnSharedSecret(on_transact),
                proxy: BpSharedSecret {
                  cached_version: std::sync::atomic::AtomicI32 = std::sync::atomic::AtomicI32::new(-1),
                  cached_hash: std::sync::Mutex<Option<String>> = std::sync::Mutex::new(None)
                },
              stability: binder::Stability::Vintf,
              }
            }
            pub trait ISharedSecret: binder::Interface + Send {
              fn get_descriptor() -> &'static str where Self: Sized { "android.hardware.security.sharedsecret.ISharedSecret" }
              fn getSharedSecretParameters(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_22_SharedSecretParameters>;
              fn computeSharedSecret(&self, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_22_SharedSecretParameters]) -> binder::public_api::Result<Vec<u8>>;
              fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
                Ok(VERSION)
              }
              fn getInterfaceHash(&self) -> binder::public_api::Result<String> {
                Ok(HASH.into())
              }
              fn getDefaultImpl() -> ISharedSecretDefaultRef where Self: Sized {
                DEFAULT_IMPL.lock().unwrap().clone()
              }
              fn setDefaultImpl(d: ISharedSecretDefaultRef) -> ISharedSecretDefaultRef where Self: Sized {
                std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
              }
            }
            pub trait ISharedSecretDefault: Send + Sync {
              fn getSharedSecretParameters(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_22_SharedSecretParameters> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn computeSharedSecret(&self, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_22_SharedSecretParameters]) -> binder::public_api::Result<Vec<u8>> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
            }
            pub mod transactions {
              pub const getSharedSecretParameters: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
              pub const computeSharedSecret: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
              pub const getInterfaceVersion: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777214;
              pub const getInterfaceHash: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777213;
            }
            pub type ISharedSecretDefaultRef = Option<std::sync::Arc<dyn ISharedSecretDefault>>;
            use lazy_static::lazy_static;
            lazy_static! {
              static ref DEFAULT_IMPL: std::sync::Mutex<ISharedSecretDefaultRef> = std::sync::Mutex::new(None);
            }
            pub const KEY_AGREEMENT_LABEL: &str = "KeymasterSharedMac";
            pub const KEY_CHECK_LABEL: &str = "Keymaster HMAC Verification";
            pub(crate) mod mangled { pub use super::ISharedSecret as _7_android_8_hardware_8_security_12_sharedsecret_13_ISharedSecret; }
            pub const VERSION: i32 = 1;
            pub const HASH: &str = "aea3745b559d2977f0676952e510fb0547a52140";
            impl ISharedSecret for BpSharedSecret {
              fn getSharedSecretParameters(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_22_SharedSecretParameters> {
                let _aidl_reply = self.binder.transact(transactions::getSharedSecretParameters, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as ISharedSecret>::getDefaultImpl() {
                    return _aidl_default_impl.getSharedSecretParameters();
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_22_SharedSecretParameters = _aidl_reply.read()?;
                Ok(_aidl_return)
              }
              fn computeSharedSecret(&self, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_22_SharedSecretParameters]) -> binder::public_api::Result<Vec<u8>> {
                let _aidl_reply = self.binder.transact(transactions::computeSharedSecret, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.write(_arg_params)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as ISharedSecret>::getDefaultImpl() {
                    return _aidl_default_impl.computeSharedSecret(_arg_params);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: Vec<u8> = _aidl_reply.read()?;
                Ok(_aidl_return)
              }
              fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
                let _aidl_version = self.cached_version.load(std::sync::atomic::Ordering::Relaxed);
                if _aidl_version != -1 { return Ok(_aidl_version); }
                let _aidl_reply = self.binder.transact(transactions::getInterfaceVersion, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
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
                let _aidl_reply = self.binder.transact(transactions::getInterfaceHash, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
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
            impl ISharedSecret for binder::Binder<BnSharedSecret> {
              fn getSharedSecretParameters(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_22_SharedSecretParameters> { self.0.getSharedSecretParameters() }
              fn computeSharedSecret(&self, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_22_SharedSecretParameters]) -> binder::public_api::Result<Vec<u8>> { self.0.computeSharedSecret(_arg_params) }
              fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> { self.0.getInterfaceVersion() }
              fn getInterfaceHash(&self) -> binder::public_api::Result<String> { self.0.getInterfaceHash() }
            }
            fn on_transact(_aidl_service: &dyn ISharedSecret, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
              match _aidl_code {
                transactions::getSharedSecretParameters => {
                  let _aidl_return = _aidl_service.getSharedSecretParameters();
                  match &_aidl_return {
                    Ok(_aidl_return) => {
                      _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                      _aidl_reply.write(_aidl_return)?;
                    }
                    Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                  }
                  Ok(())
                }
                transactions::computeSharedSecret => {
                  let _arg_params: Vec<crate::mangled::_7_android_8_hardware_8_security_12_sharedsecret_22_SharedSecretParameters> = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.computeSharedSecret(&_arg_params);
                  match &_aidl_return {
                    Ok(_aidl_return) => {
                      _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                      _aidl_reply.write(_aidl_return)?;
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
          }
          pub mod SharedSecretParameters {
            #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
            pub struct SharedSecretParameters {
              pub seed: Vec<u8>,
              pub nonce: Vec<u8>,
            }
            pub(crate) mod mangled { pub use super::SharedSecretParameters as _7_android_8_hardware_8_security_12_sharedsecret_22_SharedSecretParameters; }
            impl Default for SharedSecretParameters {
              fn default() -> Self {
                Self {
                  seed: Default::default(),
                  nonce: Default::default(),
                }
              }
            }
            impl binder::parcel::Serialize for SharedSecretParameters {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for SharedSecretParameters {}
            impl binder::parcel::SerializeOption for SharedSecretParameters {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.seed)?;
                  subparcel.write(&this.nonce)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for SharedSecretParameters {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for SharedSecretParameters {}
            impl binder::parcel::DeserializeOption for SharedSecretParameters {
              fn deserialize_option(parcel: &binder::parcel::Parcel) -> binder::Result<Option<Self>> {
                let status: i32 = parcel.read()?;
                if status == 0 { return Ok(None); }
                let start_pos = parcel.get_data_position();
                let parcelable_size: i32 = parcel.read()?;
                if parcelable_size < 0 { return Err(binder::StatusCode::BAD_VALUE); }
                if start_pos.checked_add(parcelable_size).is_none() {
                  return Err(binder::StatusCode::BAD_VALUE);
                }
                let mut result = Self::default();
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.seed = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.nonce = parcel.read()?;
                unsafe {
                  parcel.set_data_position(start_pos + parcelable_size)?;
                }
                Ok(Some(result))
              }
            }
          }
        }
      }
    }
  }
}
pub mod mangled {
  pub use super::aidl::android::hardware::security::sharedsecret::ISharedSecret::mangled::*;
  pub use super::aidl::android::hardware::security::sharedsecret::SharedSecretParameters::mangled::*;
}
