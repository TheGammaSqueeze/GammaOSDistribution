#![allow(non_snake_case)]
#![allow(missing_docs)]
pub use binder::public_api as binder;
pub mod aidl {
  pub mod android {
    pub mod security {
      pub mod metrics {
        pub mod Algorithm {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { Algorithm : i32 {
            ALGORITHM_UNSPECIFIED = 0,
            RSA = 1,
            EC = 3,
            AES = 32,
            TRIPLE_DES = 33,
            HMAC = 128,
          } }
          pub(crate) mod mangled { pub use super::Algorithm as _7_android_8_security_7_metrics_9_Algorithm; }
        }
        pub mod AtomID {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { AtomID : i32 {
            STORAGE_STATS = 10103,
            RKP_POOL_STATS = 10104,
            KEY_CREATION_WITH_GENERAL_INFO = 10118,
            KEY_CREATION_WITH_AUTH_INFO = 10119,
            KEY_CREATION_WITH_PURPOSE_AND_MODES_INFO = 10120,
            KEYSTORE2_ATOM_WITH_OVERFLOW = 10121,
            KEY_OPERATION_WITH_PURPOSE_AND_MODES_INFO = 10122,
            KEY_OPERATION_WITH_GENERAL_INFO = 10123,
            RKP_ERROR_STATS = 10124,
            CRASH_STATS = 10125,
          } }
          pub(crate) mod mangled { pub use super::AtomID as _7_android_8_security_7_metrics_6_AtomID; }
        }
        pub mod CrashStats {
          #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
          pub struct CrashStats {
            pub count_of_crash_events: i32,
          }
          pub(crate) mod mangled { pub use super::CrashStats as _7_android_8_security_7_metrics_10_CrashStats; }
          impl Default for CrashStats {
            fn default() -> Self {
              Self {
                count_of_crash_events: 0,
              }
            }
          }
          impl binder::parcel::Serialize for CrashStats {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for CrashStats {}
          impl binder::parcel::SerializeOption for CrashStats {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.count_of_crash_events)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for CrashStats {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for CrashStats {}
          impl binder::parcel::DeserializeOption for CrashStats {
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
              result.count_of_crash_events = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod EcCurve {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { EcCurve : i32 {
            EC_CURVE_UNSPECIFIED = 0,
            P_224 = 1,
            P_256 = 2,
            P_384 = 3,
            P_521 = 4,
          } }
          pub(crate) mod mangled { pub use super::EcCurve as _7_android_8_security_7_metrics_7_EcCurve; }
        }
        pub mod HardwareAuthenticatorType {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { HardwareAuthenticatorType : i32 {
            AUTH_TYPE_UNSPECIFIED = 0,
            NONE = 1,
            PASSWORD = 2,
            FINGERPRINT = 3,
            ANY = 5,
          } }
          pub(crate) mod mangled { pub use super::HardwareAuthenticatorType as _7_android_8_security_7_metrics_25_HardwareAuthenticatorType; }
        }
        pub mod IKeystoreMetrics {
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
        }
        pub mod KeyCreationWithAuthInfo {
          #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
          pub struct KeyCreationWithAuthInfo {
            pub user_auth_type: crate::mangled::_7_android_8_security_7_metrics_25_HardwareAuthenticatorType,
            pub log10_auth_key_timeout_seconds: i32,
            pub security_level: crate::mangled::_7_android_8_security_7_metrics_13_SecurityLevel,
          }
          pub(crate) mod mangled { pub use super::KeyCreationWithAuthInfo as _7_android_8_security_7_metrics_23_KeyCreationWithAuthInfo; }
          impl Default for KeyCreationWithAuthInfo {
            fn default() -> Self {
              Self {
                user_auth_type: Default::default(),
                log10_auth_key_timeout_seconds: 0,
                security_level: Default::default(),
              }
            }
          }
          impl binder::parcel::Serialize for KeyCreationWithAuthInfo {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for KeyCreationWithAuthInfo {}
          impl binder::parcel::SerializeOption for KeyCreationWithAuthInfo {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.user_auth_type)?;
                subparcel.write(&this.log10_auth_key_timeout_seconds)?;
                subparcel.write(&this.security_level)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for KeyCreationWithAuthInfo {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for KeyCreationWithAuthInfo {}
          impl binder::parcel::DeserializeOption for KeyCreationWithAuthInfo {
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
              result.user_auth_type = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.log10_auth_key_timeout_seconds = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.security_level = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod KeyCreationWithGeneralInfo {
          #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
          pub struct KeyCreationWithGeneralInfo {
            pub algorithm: crate::mangled::_7_android_8_security_7_metrics_9_Algorithm,
            pub key_size: i32,
            pub ec_curve: crate::mangled::_7_android_8_security_7_metrics_7_EcCurve,
            pub key_origin: crate::mangled::_7_android_8_security_7_metrics_9_KeyOrigin,
            pub error_code: i32,
            pub attestation_requested: bool,
          }
          pub(crate) mod mangled { pub use super::KeyCreationWithGeneralInfo as _7_android_8_security_7_metrics_26_KeyCreationWithGeneralInfo; }
          impl Default for KeyCreationWithGeneralInfo {
            fn default() -> Self {
              Self {
                algorithm: Default::default(),
                key_size: 0,
                ec_curve: Default::default(),
                key_origin: Default::default(),
                error_code: 0,
                attestation_requested: false,
              }
            }
          }
          impl binder::parcel::Serialize for KeyCreationWithGeneralInfo {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for KeyCreationWithGeneralInfo {}
          impl binder::parcel::SerializeOption for KeyCreationWithGeneralInfo {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.algorithm)?;
                subparcel.write(&this.key_size)?;
                subparcel.write(&this.ec_curve)?;
                subparcel.write(&this.key_origin)?;
                subparcel.write(&this.error_code)?;
                subparcel.write(&this.attestation_requested)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for KeyCreationWithGeneralInfo {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for KeyCreationWithGeneralInfo {}
          impl binder::parcel::DeserializeOption for KeyCreationWithGeneralInfo {
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
              result.algorithm = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.key_size = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.ec_curve = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.key_origin = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.error_code = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.attestation_requested = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod KeyCreationWithPurposeAndModesInfo {
          #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
          pub struct KeyCreationWithPurposeAndModesInfo {
            pub algorithm: crate::mangled::_7_android_8_security_7_metrics_9_Algorithm,
            pub purpose_bitmap: i32,
            pub padding_mode_bitmap: i32,
            pub digest_bitmap: i32,
            pub block_mode_bitmap: i32,
          }
          pub(crate) mod mangled { pub use super::KeyCreationWithPurposeAndModesInfo as _7_android_8_security_7_metrics_34_KeyCreationWithPurposeAndModesInfo; }
          impl Default for KeyCreationWithPurposeAndModesInfo {
            fn default() -> Self {
              Self {
                algorithm: Default::default(),
                purpose_bitmap: 0,
                padding_mode_bitmap: 0,
                digest_bitmap: 0,
                block_mode_bitmap: 0,
              }
            }
          }
          impl binder::parcel::Serialize for KeyCreationWithPurposeAndModesInfo {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for KeyCreationWithPurposeAndModesInfo {}
          impl binder::parcel::SerializeOption for KeyCreationWithPurposeAndModesInfo {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.algorithm)?;
                subparcel.write(&this.purpose_bitmap)?;
                subparcel.write(&this.padding_mode_bitmap)?;
                subparcel.write(&this.digest_bitmap)?;
                subparcel.write(&this.block_mode_bitmap)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for KeyCreationWithPurposeAndModesInfo {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for KeyCreationWithPurposeAndModesInfo {}
          impl binder::parcel::DeserializeOption for KeyCreationWithPurposeAndModesInfo {
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
              result.algorithm = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.purpose_bitmap = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.padding_mode_bitmap = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.digest_bitmap = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.block_mode_bitmap = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod KeyOperationWithGeneralInfo {
          #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
          pub struct KeyOperationWithGeneralInfo {
            pub outcome: crate::mangled::_7_android_8_security_7_metrics_7_Outcome,
            pub error_code: i32,
            pub key_upgraded: bool,
            pub security_level: crate::mangled::_7_android_8_security_7_metrics_13_SecurityLevel,
          }
          pub(crate) mod mangled { pub use super::KeyOperationWithGeneralInfo as _7_android_8_security_7_metrics_27_KeyOperationWithGeneralInfo; }
          impl Default for KeyOperationWithGeneralInfo {
            fn default() -> Self {
              Self {
                outcome: Default::default(),
                error_code: 0,
                key_upgraded: false,
                security_level: Default::default(),
              }
            }
          }
          impl binder::parcel::Serialize for KeyOperationWithGeneralInfo {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for KeyOperationWithGeneralInfo {}
          impl binder::parcel::SerializeOption for KeyOperationWithGeneralInfo {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.outcome)?;
                subparcel.write(&this.error_code)?;
                subparcel.write(&this.key_upgraded)?;
                subparcel.write(&this.security_level)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for KeyOperationWithGeneralInfo {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for KeyOperationWithGeneralInfo {}
          impl binder::parcel::DeserializeOption for KeyOperationWithGeneralInfo {
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
              result.outcome = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.error_code = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.key_upgraded = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.security_level = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod KeyOperationWithPurposeAndModesInfo {
          #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
          pub struct KeyOperationWithPurposeAndModesInfo {
            pub purpose: crate::mangled::_7_android_8_security_7_metrics_7_Purpose,
            pub padding_mode_bitmap: i32,
            pub digest_bitmap: i32,
            pub block_mode_bitmap: i32,
          }
          pub(crate) mod mangled { pub use super::KeyOperationWithPurposeAndModesInfo as _7_android_8_security_7_metrics_35_KeyOperationWithPurposeAndModesInfo; }
          impl Default for KeyOperationWithPurposeAndModesInfo {
            fn default() -> Self {
              Self {
                purpose: Default::default(),
                padding_mode_bitmap: 0,
                digest_bitmap: 0,
                block_mode_bitmap: 0,
              }
            }
          }
          impl binder::parcel::Serialize for KeyOperationWithPurposeAndModesInfo {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for KeyOperationWithPurposeAndModesInfo {}
          impl binder::parcel::SerializeOption for KeyOperationWithPurposeAndModesInfo {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.purpose)?;
                subparcel.write(&this.padding_mode_bitmap)?;
                subparcel.write(&this.digest_bitmap)?;
                subparcel.write(&this.block_mode_bitmap)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for KeyOperationWithPurposeAndModesInfo {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for KeyOperationWithPurposeAndModesInfo {}
          impl binder::parcel::DeserializeOption for KeyOperationWithPurposeAndModesInfo {
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
              result.purpose = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.padding_mode_bitmap = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.digest_bitmap = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.block_mode_bitmap = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod KeyOrigin {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { KeyOrigin : i32 {
            ORIGIN_UNSPECIFIED = 0,
            GENERATED = 1,
            DERIVED = 2,
            IMPORTED = 3,
            RESERVED = 4,
            SECURELY_IMPORTED = 5,
          } }
          pub(crate) mod mangled { pub use super::KeyOrigin as _7_android_8_security_7_metrics_9_KeyOrigin; }
        }
        pub mod Keystore2AtomWithOverflow {
          #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
          pub struct Keystore2AtomWithOverflow {
            pub atom_id: crate::mangled::_7_android_8_security_7_metrics_6_AtomID,
          }
          pub(crate) mod mangled { pub use super::Keystore2AtomWithOverflow as _7_android_8_security_7_metrics_25_Keystore2AtomWithOverflow; }
          impl Default for Keystore2AtomWithOverflow {
            fn default() -> Self {
              Self {
                atom_id: Default::default(),
              }
            }
          }
          impl binder::parcel::Serialize for Keystore2AtomWithOverflow {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for Keystore2AtomWithOverflow {}
          impl binder::parcel::SerializeOption for Keystore2AtomWithOverflow {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.atom_id)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for Keystore2AtomWithOverflow {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for Keystore2AtomWithOverflow {}
          impl binder::parcel::DeserializeOption for Keystore2AtomWithOverflow {
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
              result.atom_id = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod KeystoreAtom {
          #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
          pub struct KeystoreAtom {
            pub payload: crate::mangled::_7_android_8_security_7_metrics_19_KeystoreAtomPayload,
            pub count: i32,
          }
          pub(crate) mod mangled { pub use super::KeystoreAtom as _7_android_8_security_7_metrics_12_KeystoreAtom; }
          impl Default for KeystoreAtom {
            fn default() -> Self {
              Self {
                payload: Default::default(),
                count: 0,
              }
            }
          }
          impl binder::parcel::Serialize for KeystoreAtom {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for KeystoreAtom {}
          impl binder::parcel::SerializeOption for KeystoreAtom {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.payload)?;
                subparcel.write(&this.count)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for KeystoreAtom {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for KeystoreAtom {}
          impl binder::parcel::DeserializeOption for KeystoreAtom {
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
              result.payload = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.count = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod KeystoreAtomPayload {
          #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
          pub enum KeystoreAtomPayload {
            StorageStats(crate::mangled::_7_android_8_security_7_metrics_12_StorageStats),
            RkpPoolStats(crate::mangled::_7_android_8_security_7_metrics_12_RkpPoolStats),
            KeyCreationWithGeneralInfo(crate::mangled::_7_android_8_security_7_metrics_26_KeyCreationWithGeneralInfo),
            KeyCreationWithAuthInfo(crate::mangled::_7_android_8_security_7_metrics_23_KeyCreationWithAuthInfo),
            KeyCreationWithPurposeAndModesInfo(crate::mangled::_7_android_8_security_7_metrics_34_KeyCreationWithPurposeAndModesInfo),
            Keystore2AtomWithOverflow(crate::mangled::_7_android_8_security_7_metrics_25_Keystore2AtomWithOverflow),
            KeyOperationWithPurposeAndModesInfo(crate::mangled::_7_android_8_security_7_metrics_35_KeyOperationWithPurposeAndModesInfo),
            KeyOperationWithGeneralInfo(crate::mangled::_7_android_8_security_7_metrics_27_KeyOperationWithGeneralInfo),
            RkpErrorStats(crate::mangled::_7_android_8_security_7_metrics_13_RkpErrorStats),
            CrashStats(crate::mangled::_7_android_8_security_7_metrics_10_CrashStats),
          }
          pub(crate) mod mangled { pub use super::KeystoreAtomPayload as _7_android_8_security_7_metrics_19_KeystoreAtomPayload; }
          impl Default for KeystoreAtomPayload {
            fn default() -> Self {
              Self::StorageStats(Default::default())
            }
          }
          impl binder::parcel::Serialize for KeystoreAtomPayload {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for KeystoreAtomPayload {}
          impl binder::parcel::SerializeOption for KeystoreAtomPayload {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              match this {
                Self::StorageStats(v) => {
                  parcel.write(&0i32)?;
                  parcel.write(v)
                }
                Self::RkpPoolStats(v) => {
                  parcel.write(&1i32)?;
                  parcel.write(v)
                }
                Self::KeyCreationWithGeneralInfo(v) => {
                  parcel.write(&2i32)?;
                  parcel.write(v)
                }
                Self::KeyCreationWithAuthInfo(v) => {
                  parcel.write(&3i32)?;
                  parcel.write(v)
                }
                Self::KeyCreationWithPurposeAndModesInfo(v) => {
                  parcel.write(&4i32)?;
                  parcel.write(v)
                }
                Self::Keystore2AtomWithOverflow(v) => {
                  parcel.write(&5i32)?;
                  parcel.write(v)
                }
                Self::KeyOperationWithPurposeAndModesInfo(v) => {
                  parcel.write(&6i32)?;
                  parcel.write(v)
                }
                Self::KeyOperationWithGeneralInfo(v) => {
                  parcel.write(&7i32)?;
                  parcel.write(v)
                }
                Self::RkpErrorStats(v) => {
                  parcel.write(&8i32)?;
                  parcel.write(v)
                }
                Self::CrashStats(v) => {
                  parcel.write(&9i32)?;
                  parcel.write(v)
                }
              }
            }
          }
          impl binder::parcel::Deserialize for KeystoreAtomPayload {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for KeystoreAtomPayload {}
          impl binder::parcel::DeserializeOption for KeystoreAtomPayload {
            fn deserialize_option(parcel: &binder::parcel::Parcel) -> binder::Result<Option<Self>> {
              let status: i32 = parcel.read()?;
              if status == 0 { return Ok(None); }
              let tag: i32 = parcel.read()?;
              match tag {
                0 => {
                  let value: crate::mangled::_7_android_8_security_7_metrics_12_StorageStats = parcel.read()?;
                  Ok(Some(Self::StorageStats(value)))
                }
                1 => {
                  let value: crate::mangled::_7_android_8_security_7_metrics_12_RkpPoolStats = parcel.read()?;
                  Ok(Some(Self::RkpPoolStats(value)))
                }
                2 => {
                  let value: crate::mangled::_7_android_8_security_7_metrics_26_KeyCreationWithGeneralInfo = parcel.read()?;
                  Ok(Some(Self::KeyCreationWithGeneralInfo(value)))
                }
                3 => {
                  let value: crate::mangled::_7_android_8_security_7_metrics_23_KeyCreationWithAuthInfo = parcel.read()?;
                  Ok(Some(Self::KeyCreationWithAuthInfo(value)))
                }
                4 => {
                  let value: crate::mangled::_7_android_8_security_7_metrics_34_KeyCreationWithPurposeAndModesInfo = parcel.read()?;
                  Ok(Some(Self::KeyCreationWithPurposeAndModesInfo(value)))
                }
                5 => {
                  let value: crate::mangled::_7_android_8_security_7_metrics_25_Keystore2AtomWithOverflow = parcel.read()?;
                  Ok(Some(Self::Keystore2AtomWithOverflow(value)))
                }
                6 => {
                  let value: crate::mangled::_7_android_8_security_7_metrics_35_KeyOperationWithPurposeAndModesInfo = parcel.read()?;
                  Ok(Some(Self::KeyOperationWithPurposeAndModesInfo(value)))
                }
                7 => {
                  let value: crate::mangled::_7_android_8_security_7_metrics_27_KeyOperationWithGeneralInfo = parcel.read()?;
                  Ok(Some(Self::KeyOperationWithGeneralInfo(value)))
                }
                8 => {
                  let value: crate::mangled::_7_android_8_security_7_metrics_13_RkpErrorStats = parcel.read()?;
                  Ok(Some(Self::RkpErrorStats(value)))
                }
                9 => {
                  let value: crate::mangled::_7_android_8_security_7_metrics_10_CrashStats = parcel.read()?;
                  Ok(Some(Self::CrashStats(value)))
                }
                _ => {
                  Err(binder::StatusCode::BAD_VALUE)
                }
              }
            }
          }
        }
        pub mod Outcome {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { Outcome : i32 {
            OUTCOME_UNSPECIFIED = 0,
            DROPPED = 1,
            SUCCESS = 2,
            ABORT = 3,
            PRUNED = 4,
            ERROR = 5,
          } }
          pub(crate) mod mangled { pub use super::Outcome as _7_android_8_security_7_metrics_7_Outcome; }
        }
        pub mod PoolStatus {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { PoolStatus : i32 {
            EXPIRING = 1,
            UNASSIGNED = 2,
            ATTESTED = 3,
            TOTAL = 4,
          } }
          pub(crate) mod mangled { pub use super::PoolStatus as _7_android_8_security_7_metrics_10_PoolStatus; }
        }
        pub mod Purpose {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { Purpose : i32 {
            KEY_PURPOSE_UNSPECIFIED = 0,
            ENCRYPT = 1,
            DECRYPT = 2,
            SIGN = 3,
            VERIFY = 4,
            WRAP_KEY = 6,
            AGREE_KEY = 7,
            ATTEST_KEY = 8,
          } }
          pub(crate) mod mangled { pub use super::Purpose as _7_android_8_security_7_metrics_7_Purpose; }
        }
        pub mod RkpError {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { RkpError : i32 {
            RKP_ERROR_UNSPECIFIED = 0,
            OUT_OF_KEYS = 1,
            FALL_BACK_DURING_HYBRID = 2,
          } }
          pub(crate) mod mangled { pub use super::RkpError as _7_android_8_security_7_metrics_8_RkpError; }
        }
        pub mod RkpErrorStats {
          #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
          pub struct RkpErrorStats {
            pub rkpError: crate::mangled::_7_android_8_security_7_metrics_8_RkpError,
          }
          pub(crate) mod mangled { pub use super::RkpErrorStats as _7_android_8_security_7_metrics_13_RkpErrorStats; }
          impl Default for RkpErrorStats {
            fn default() -> Self {
              Self {
                rkpError: Default::default(),
              }
            }
          }
          impl binder::parcel::Serialize for RkpErrorStats {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for RkpErrorStats {}
          impl binder::parcel::SerializeOption for RkpErrorStats {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.rkpError)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for RkpErrorStats {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for RkpErrorStats {}
          impl binder::parcel::DeserializeOption for RkpErrorStats {
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
              result.rkpError = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod RkpPoolStats {
          #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
          pub struct RkpPoolStats {
            pub security_level: crate::mangled::_7_android_8_security_7_metrics_13_SecurityLevel,
            pub expiring: i32,
            pub unassigned: i32,
            pub attested: i32,
            pub total: i32,
          }
          pub(crate) mod mangled { pub use super::RkpPoolStats as _7_android_8_security_7_metrics_12_RkpPoolStats; }
          impl Default for RkpPoolStats {
            fn default() -> Self {
              Self {
                security_level: Default::default(),
                expiring: 0,
                unassigned: 0,
                attested: 0,
                total: 0,
              }
            }
          }
          impl binder::parcel::Serialize for RkpPoolStats {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for RkpPoolStats {}
          impl binder::parcel::SerializeOption for RkpPoolStats {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.security_level)?;
                subparcel.write(&this.expiring)?;
                subparcel.write(&this.unassigned)?;
                subparcel.write(&this.attested)?;
                subparcel.write(&this.total)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for RkpPoolStats {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for RkpPoolStats {}
          impl binder::parcel::DeserializeOption for RkpPoolStats {
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
              result.security_level = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.expiring = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.unassigned = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.attested = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.total = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod SecurityLevel {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { SecurityLevel : i32 {
            SECURITY_LEVEL_UNSPECIFIED = 0,
            SECURITY_LEVEL_SOFTWARE = 1,
            SECURITY_LEVEL_TRUSTED_ENVIRONMENT = 2,
            SECURITY_LEVEL_STRONGBOX = 3,
            SECURITY_LEVEL_KEYSTORE = 4,
          } }
          pub(crate) mod mangled { pub use super::SecurityLevel as _7_android_8_security_7_metrics_13_SecurityLevel; }
        }
        pub mod Storage {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { Storage : i32 {
            STORAGE_UNSPECIFIED = 0,
            KEY_ENTRY = 1,
            KEY_ENTRY_ID_INDEX = 2,
            KEY_ENTRY_DOMAIN_NAMESPACE_INDEX = 3,
            BLOB_ENTRY = 4,
            BLOB_ENTRY_KEY_ENTRY_ID_INDEX = 5,
            KEY_PARAMETER = 6,
            KEY_PARAMETER_KEY_ENTRY_ID_INDEX = 7,
            KEY_METADATA = 8,
            KEY_METADATA_KEY_ENTRY_ID_INDEX = 9,
            GRANT = 10,
            AUTH_TOKEN = 11,
            BLOB_METADATA = 12,
            BLOB_METADATA_BLOB_ENTRY_ID_INDEX = 13,
            METADATA = 14,
            DATABASE = 15,
            LEGACY_STORAGE = 16,
          } }
          pub(crate) mod mangled { pub use super::Storage as _7_android_8_security_7_metrics_7_Storage; }
        }
        pub mod StorageStats {
          #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
          pub struct StorageStats {
            pub storage_type: crate::mangled::_7_android_8_security_7_metrics_7_Storage,
            pub size: i32,
            pub unused_size: i32,
          }
          pub(crate) mod mangled { pub use super::StorageStats as _7_android_8_security_7_metrics_12_StorageStats; }
          impl Default for StorageStats {
            fn default() -> Self {
              Self {
                storage_type: Default::default(),
                size: 0,
                unused_size: 0,
              }
            }
          }
          impl binder::parcel::Serialize for StorageStats {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for StorageStats {}
          impl binder::parcel::SerializeOption for StorageStats {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.storage_type)?;
                subparcel.write(&this.size)?;
                subparcel.write(&this.unused_size)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for StorageStats {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for StorageStats {}
          impl binder::parcel::DeserializeOption for StorageStats {
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
              result.storage_type = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.size = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.unused_size = parcel.read()?;
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
pub mod mangled {
  pub use super::aidl::android::security::metrics::Algorithm::mangled::*;
  pub use super::aidl::android::security::metrics::AtomID::mangled::*;
  pub use super::aidl::android::security::metrics::CrashStats::mangled::*;
  pub use super::aidl::android::security::metrics::EcCurve::mangled::*;
  pub use super::aidl::android::security::metrics::HardwareAuthenticatorType::mangled::*;
  pub use super::aidl::android::security::metrics::IKeystoreMetrics::mangled::*;
  pub use super::aidl::android::security::metrics::KeyCreationWithAuthInfo::mangled::*;
  pub use super::aidl::android::security::metrics::KeyCreationWithGeneralInfo::mangled::*;
  pub use super::aidl::android::security::metrics::KeyCreationWithPurposeAndModesInfo::mangled::*;
  pub use super::aidl::android::security::metrics::KeyOperationWithGeneralInfo::mangled::*;
  pub use super::aidl::android::security::metrics::KeyOperationWithPurposeAndModesInfo::mangled::*;
  pub use super::aidl::android::security::metrics::KeyOrigin::mangled::*;
  pub use super::aidl::android::security::metrics::Keystore2AtomWithOverflow::mangled::*;
  pub use super::aidl::android::security::metrics::KeystoreAtom::mangled::*;
  pub use super::aidl::android::security::metrics::KeystoreAtomPayload::mangled::*;
  pub use super::aidl::android::security::metrics::Outcome::mangled::*;
  pub use super::aidl::android::security::metrics::PoolStatus::mangled::*;
  pub use super::aidl::android::security::metrics::Purpose::mangled::*;
  pub use super::aidl::android::security::metrics::RkpError::mangled::*;
  pub use super::aidl::android::security::metrics::RkpErrorStats::mangled::*;
  pub use super::aidl::android::security::metrics::RkpPoolStats::mangled::*;
  pub use super::aidl::android::security::metrics::SecurityLevel::mangled::*;
  pub use super::aidl::android::security::metrics::Storage::mangled::*;
  pub use super::aidl::android::security::metrics::StorageStats::mangled::*;
  pub(crate) use android_system_keystore2::mangled::*;
}
