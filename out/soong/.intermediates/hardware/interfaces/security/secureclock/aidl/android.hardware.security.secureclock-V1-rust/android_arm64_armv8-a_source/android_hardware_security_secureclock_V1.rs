#![allow(non_snake_case)]
#![allow(missing_docs)]
pub use binder::public_api as binder;
pub mod aidl {
  pub mod android {
    pub mod hardware {
      pub mod security {
        pub mod secureclock {
          pub mod ISecureClock {
            #![allow(non_upper_case_globals)]
            #![allow(non_snake_case)]
            #[allow(unused_imports)] use binder::IBinderInternal;
            use binder::declare_binder_interface;
            declare_binder_interface! {
              ISecureClock["android.hardware.security.secureclock.ISecureClock"] {
                native: BnSecureClock(on_transact),
                proxy: BpSecureClock {
                  cached_version: std::sync::atomic::AtomicI32 = std::sync::atomic::AtomicI32::new(-1),
                  cached_hash: std::sync::Mutex<Option<String>> = std::sync::Mutex::new(None)
                },
              stability: binder::Stability::Vintf,
              }
            }
            pub trait ISecureClock: binder::Interface + Send {
              fn get_descriptor() -> &'static str where Self: Sized { "android.hardware.security.secureclock.ISecureClock" }
              fn generateTimeStamp(&self, _arg_challenge: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>;
              fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
                Ok(VERSION)
              }
              fn getInterfaceHash(&self) -> binder::public_api::Result<String> {
                Ok(HASH.into())
              }
              fn getDefaultImpl() -> ISecureClockDefaultRef where Self: Sized {
                DEFAULT_IMPL.lock().unwrap().clone()
              }
              fn setDefaultImpl(d: ISecureClockDefaultRef) -> ISecureClockDefaultRef where Self: Sized {
                std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
              }
            }
            pub trait ISecureClockDefault: Send + Sync {
              fn generateTimeStamp(&self, _arg_challenge: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
            }
            pub mod transactions {
              pub const generateTimeStamp: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
              pub const getInterfaceVersion: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777214;
              pub const getInterfaceHash: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777213;
            }
            pub type ISecureClockDefaultRef = Option<std::sync::Arc<dyn ISecureClockDefault>>;
            use lazy_static::lazy_static;
            lazy_static! {
              static ref DEFAULT_IMPL: std::sync::Mutex<ISecureClockDefaultRef> = std::sync::Mutex::new(None);
            }
            pub const TIME_STAMP_MAC_LABEL: &str = "Auth Verification";
            pub(crate) mod mangled { pub use super::ISecureClock as _7_android_8_hardware_8_security_11_secureclock_12_ISecureClock; }
            pub const VERSION: i32 = 1;
            pub const HASH: &str = "cd55ca9963c6a57fa5f2f120a45c6e0c4fafb423";
            impl ISecureClock for BpSecureClock {
              fn generateTimeStamp(&self, _arg_challenge: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken> {
                let _aidl_reply = self.binder.transact(transactions::generateTimeStamp, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.write(&_arg_challenge)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as ISecureClock>::getDefaultImpl() {
                    return _aidl_default_impl.generateTimeStamp(_arg_challenge);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken = _aidl_reply.read()?;
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
            impl ISecureClock for binder::Binder<BnSecureClock> {
              fn generateTimeStamp(&self, _arg_challenge: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken> { self.0.generateTimeStamp(_arg_challenge) }
              fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> { self.0.getInterfaceVersion() }
              fn getInterfaceHash(&self) -> binder::public_api::Result<String> { self.0.getInterfaceHash() }
            }
            fn on_transact(_aidl_service: &dyn ISecureClock, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
              match _aidl_code {
                transactions::generateTimeStamp => {
                  let _arg_challenge: i64 = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.generateTimeStamp(_arg_challenge);
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
          pub mod TimeStampToken {
            #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
            pub struct TimeStampToken {
              pub challenge: i64,
              pub timestamp: crate::mangled::_7_android_8_hardware_8_security_11_secureclock_9_Timestamp,
              pub mac: Vec<u8>,
            }
            pub(crate) mod mangled { pub use super::TimeStampToken as _7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken; }
            impl Default for TimeStampToken {
              fn default() -> Self {
                Self {
                  challenge: 0,
                  timestamp: Default::default(),
                  mac: Default::default(),
                }
              }
            }
            impl binder::parcel::Serialize for TimeStampToken {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for TimeStampToken {}
            impl binder::parcel::SerializeOption for TimeStampToken {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.challenge)?;
                  subparcel.write(&this.timestamp)?;
                  subparcel.write(&this.mac)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for TimeStampToken {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for TimeStampToken {}
            impl binder::parcel::DeserializeOption for TimeStampToken {
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
                result.challenge = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.timestamp = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.mac = parcel.read()?;
                unsafe {
                  parcel.set_data_position(start_pos + parcelable_size)?;
                }
                Ok(Some(result))
              }
            }
          }
          pub mod Timestamp {
            #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
            pub struct Timestamp {
              pub milliSeconds: i64,
            }
            pub(crate) mod mangled { pub use super::Timestamp as _7_android_8_hardware_8_security_11_secureclock_9_Timestamp; }
            impl Default for Timestamp {
              fn default() -> Self {
                Self {
                  milliSeconds: 0,
                }
              }
            }
            impl binder::parcel::Serialize for Timestamp {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for Timestamp {}
            impl binder::parcel::SerializeOption for Timestamp {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.milliSeconds)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for Timestamp {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for Timestamp {}
            impl binder::parcel::DeserializeOption for Timestamp {
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
                result.milliSeconds = parcel.read()?;
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
  pub use super::aidl::android::hardware::security::secureclock::ISecureClock::mangled::*;
  pub use super::aidl::android::hardware::security::secureclock::TimeStampToken::mangled::*;
  pub use super::aidl::android::hardware::security::secureclock::Timestamp::mangled::*;
}
