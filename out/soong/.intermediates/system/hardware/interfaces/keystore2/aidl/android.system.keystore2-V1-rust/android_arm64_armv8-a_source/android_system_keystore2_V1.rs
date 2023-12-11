#![allow(non_snake_case)]
#![allow(missing_docs)]
pub use binder::public_api as binder;
pub mod aidl {
  pub mod android {
    pub mod system {
      pub mod keystore2 {
        pub mod AuthenticatorSpec {
          #[derive(Debug)]
          pub struct AuthenticatorSpec {
            pub authenticatorType: crate::mangled::_7_android_8_hardware_8_security_7_keymint_25_HardwareAuthenticatorType,
            pub authenticatorId: i64,
          }
          pub(crate) mod mangled { pub use super::AuthenticatorSpec as _7_android_6_system_9_keystore2_17_AuthenticatorSpec; }
          impl Default for AuthenticatorSpec {
            fn default() -> Self {
              Self {
                authenticatorType: Default::default(),
                authenticatorId: 0,
              }
            }
          }
          impl binder::parcel::Serialize for AuthenticatorSpec {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for AuthenticatorSpec {}
          impl binder::parcel::SerializeOption for AuthenticatorSpec {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.authenticatorType)?;
                subparcel.write(&this.authenticatorId)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for AuthenticatorSpec {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for AuthenticatorSpec {}
          impl binder::parcel::DeserializeOption for AuthenticatorSpec {
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
              result.authenticatorType = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.authenticatorId = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod Authorization {
          #[derive(Debug)]
          pub struct Authorization {
            pub securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel,
            pub keyParameter: crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter,
          }
          pub(crate) mod mangled { pub use super::Authorization as _7_android_6_system_9_keystore2_13_Authorization; }
          impl Default for Authorization {
            fn default() -> Self {
              Self {
                securityLevel: Default::default(),
                keyParameter: Default::default(),
              }
            }
          }
          impl binder::parcel::Serialize for Authorization {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for Authorization {}
          impl binder::parcel::SerializeOption for Authorization {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.securityLevel)?;
                subparcel.write(&this.keyParameter)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for Authorization {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for Authorization {}
          impl binder::parcel::DeserializeOption for Authorization {
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
              result.securityLevel = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.keyParameter = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod CreateOperationResponse {
          #[derive(Debug)]
          pub struct CreateOperationResponse {
            pub iOperation: Option<binder::Strong<dyn crate::mangled::_7_android_6_system_9_keystore2_18_IKeystoreOperation>>,
            pub operationChallenge: Option<crate::mangled::_7_android_6_system_9_keystore2_18_OperationChallenge>,
            pub parameters: Option<crate::mangled::_7_android_6_system_9_keystore2_13_KeyParameters>,
            pub upgradedBlob: Option<Vec<u8>>,
          }
          pub(crate) mod mangled { pub use super::CreateOperationResponse as _7_android_6_system_9_keystore2_23_CreateOperationResponse; }
          impl Default for CreateOperationResponse {
            fn default() -> Self {
              Self {
                iOperation: Default::default(),
                operationChallenge: Default::default(),
                parameters: Default::default(),
                upgradedBlob: Default::default(),
              }
            }
          }
          impl binder::parcel::Serialize for CreateOperationResponse {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for CreateOperationResponse {}
          impl binder::parcel::SerializeOption for CreateOperationResponse {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                let __field_ref = this.iOperation.as_ref().ok_or(binder::StatusCode::UNEXPECTED_NULL)?;
                subparcel.write(__field_ref)?;
                subparcel.write(&this.operationChallenge)?;
                subparcel.write(&this.parameters)?;
                subparcel.write(&this.upgradedBlob)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for CreateOperationResponse {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for CreateOperationResponse {}
          impl binder::parcel::DeserializeOption for CreateOperationResponse {
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
              result.iOperation = Some(parcel.read()?);
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.operationChallenge = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.parameters = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.upgradedBlob = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod Domain {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { Domain : i32 {
            APP = 0,
            GRANT = 1,
            SELINUX = 2,
            BLOB = 3,
            KEY_ID = 4,
          } }
          pub(crate) mod mangled { pub use super::Domain as _7_android_6_system_9_keystore2_6_Domain; }
        }
        pub mod EphemeralStorageKeyResponse {
          #[derive(Debug)]
          pub struct EphemeralStorageKeyResponse {
            pub ephemeralKey: Vec<u8>,
            pub upgradedBlob: Option<Vec<u8>>,
          }
          pub(crate) mod mangled { pub use super::EphemeralStorageKeyResponse as _7_android_6_system_9_keystore2_27_EphemeralStorageKeyResponse; }
          impl Default for EphemeralStorageKeyResponse {
            fn default() -> Self {
              Self {
                ephemeralKey: Default::default(),
                upgradedBlob: Default::default(),
              }
            }
          }
          impl binder::parcel::Serialize for EphemeralStorageKeyResponse {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for EphemeralStorageKeyResponse {}
          impl binder::parcel::SerializeOption for EphemeralStorageKeyResponse {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.ephemeralKey)?;
                subparcel.write(&this.upgradedBlob)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for EphemeralStorageKeyResponse {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for EphemeralStorageKeyResponse {}
          impl binder::parcel::DeserializeOption for EphemeralStorageKeyResponse {
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
              result.ephemeralKey = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.upgradedBlob = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod IKeystoreOperation {
          #![allow(non_upper_case_globals)]
          #![allow(non_snake_case)]
          #[allow(unused_imports)] use binder::IBinderInternal;
          use binder::declare_binder_interface;
          declare_binder_interface! {
            IKeystoreOperation["android.system.keystore2.IKeystoreOperation"] {
              native: BnKeystoreOperation(on_transact),
              proxy: BpKeystoreOperation {
                cached_version: std::sync::atomic::AtomicI32 = std::sync::atomic::AtomicI32::new(-1),
                cached_hash: std::sync::Mutex<Option<String>> = std::sync::Mutex::new(None)
              },
            stability: binder::Stability::Vintf,
            }
          }
          pub trait IKeystoreOperation: binder::Interface + Send {
            fn get_descriptor() -> &'static str where Self: Sized { "android.system.keystore2.IKeystoreOperation" }
            fn updateAad(&self, _arg_aadInput: &[u8]) -> binder::public_api::Result<()>;
            fn update(&self, _arg_input: &[u8]) -> binder::public_api::Result<Option<Vec<u8>>>;
            fn finish(&self, _arg_input: Option<&[u8]>, _arg_signature: Option<&[u8]>) -> binder::public_api::Result<Option<Vec<u8>>>;
            fn abort(&self) -> binder::public_api::Result<()>;
            fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
              Ok(VERSION)
            }
            fn getInterfaceHash(&self) -> binder::public_api::Result<String> {
              Ok(HASH.into())
            }
            fn getDefaultImpl() -> IKeystoreOperationDefaultRef where Self: Sized {
              DEFAULT_IMPL.lock().unwrap().clone()
            }
            fn setDefaultImpl(d: IKeystoreOperationDefaultRef) -> IKeystoreOperationDefaultRef where Self: Sized {
              std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
            }
          }
          pub trait IKeystoreOperationDefault: Send + Sync {
            fn updateAad(&self, _arg_aadInput: &[u8]) -> binder::public_api::Result<()> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn update(&self, _arg_input: &[u8]) -> binder::public_api::Result<Option<Vec<u8>>> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn finish(&self, _arg_input: Option<&[u8]>, _arg_signature: Option<&[u8]>) -> binder::public_api::Result<Option<Vec<u8>>> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn abort(&self) -> binder::public_api::Result<()> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
          }
          pub mod transactions {
            pub const updateAad: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
            pub const update: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
            pub const finish: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
            pub const abort: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 3;
            pub const getInterfaceVersion: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777214;
            pub const getInterfaceHash: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777213;
          }
          pub type IKeystoreOperationDefaultRef = Option<std::sync::Arc<dyn IKeystoreOperationDefault>>;
          use lazy_static::lazy_static;
          lazy_static! {
            static ref DEFAULT_IMPL: std::sync::Mutex<IKeystoreOperationDefaultRef> = std::sync::Mutex::new(None);
          }
          pub(crate) mod mangled { pub use super::IKeystoreOperation as _7_android_6_system_9_keystore2_18_IKeystoreOperation; }
          pub const VERSION: i32 = 1;
          pub const HASH: &str = "19e8b65277839bad0ab335c781e3c652324920ce";
          impl IKeystoreOperation for BpKeystoreOperation {
            fn updateAad(&self, _arg_aadInput: &[u8]) -> binder::public_api::Result<()> {
              let _aidl_reply = self.binder.transact(transactions::updateAad, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(_arg_aadInput)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreOperation>::getDefaultImpl() {
                  return _aidl_default_impl.updateAad(_arg_aadInput);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              Ok(())
            }
            fn update(&self, _arg_input: &[u8]) -> binder::public_api::Result<Option<Vec<u8>>> {
              let _aidl_reply = self.binder.transact(transactions::update, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(_arg_input)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreOperation>::getDefaultImpl() {
                  return _aidl_default_impl.update(_arg_input);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: Option<Vec<u8>> = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
            fn finish(&self, _arg_input: Option<&[u8]>, _arg_signature: Option<&[u8]>) -> binder::public_api::Result<Option<Vec<u8>>> {
              let _aidl_reply = self.binder.transact(transactions::finish, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(&_arg_input)?;
                _aidl_data.write(&_arg_signature)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreOperation>::getDefaultImpl() {
                  return _aidl_default_impl.finish(_arg_input, _arg_signature);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: Option<Vec<u8>> = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
            fn abort(&self) -> binder::public_api::Result<()> {
              let _aidl_reply = self.binder.transact(transactions::abort, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreOperation>::getDefaultImpl() {
                  return _aidl_default_impl.abort();
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              Ok(())
            }
            fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
              let _aidl_version = self.cached_version.load(std::sync::atomic::Ordering::Relaxed);
              if _aidl_version != -1 { return Ok(_aidl_version); }
              let _aidl_reply = self.binder.transact(transactions::getInterfaceVersion, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
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
              let _aidl_reply = self.binder.transact(transactions::getInterfaceHash, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
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
          impl IKeystoreOperation for binder::Binder<BnKeystoreOperation> {
            fn updateAad(&self, _arg_aadInput: &[u8]) -> binder::public_api::Result<()> { self.0.updateAad(_arg_aadInput) }
            fn update(&self, _arg_input: &[u8]) -> binder::public_api::Result<Option<Vec<u8>>> { self.0.update(_arg_input) }
            fn finish(&self, _arg_input: Option<&[u8]>, _arg_signature: Option<&[u8]>) -> binder::public_api::Result<Option<Vec<u8>>> { self.0.finish(_arg_input, _arg_signature) }
            fn abort(&self) -> binder::public_api::Result<()> { self.0.abort() }
            fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> { self.0.getInterfaceVersion() }
            fn getInterfaceHash(&self) -> binder::public_api::Result<String> { self.0.getInterfaceHash() }
          }
          fn on_transact(_aidl_service: &dyn IKeystoreOperation, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
            match _aidl_code {
              transactions::updateAad => {
                let _arg_aadInput: Vec<u8> = _aidl_data.read()?;
                let _aidl_return = _aidl_service.updateAad(&_arg_aadInput);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::update => {
                let _arg_input: Vec<u8> = _aidl_data.read()?;
                let _aidl_return = _aidl_service.update(&_arg_input);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    _aidl_reply.write(_aidl_return)?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::finish => {
                let _arg_input: Option<Vec<u8>> = _aidl_data.read()?;
                let _arg_signature: Option<Vec<u8>> = _aidl_data.read()?;
                let _aidl_return = _aidl_service.finish(_arg_input.as_deref(), _arg_signature.as_deref());
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    _aidl_reply.write(_aidl_return)?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::abort => {
                let _aidl_return = _aidl_service.abort();
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
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
        pub mod IKeystoreSecurityLevel {
          #![allow(non_upper_case_globals)]
          #![allow(non_snake_case)]
          #[allow(unused_imports)] use binder::IBinderInternal;
          use binder::declare_binder_interface;
          declare_binder_interface! {
            IKeystoreSecurityLevel["android.system.keystore2.IKeystoreSecurityLevel"] {
              native: BnKeystoreSecurityLevel(on_transact),
              proxy: BpKeystoreSecurityLevel {
                cached_version: std::sync::atomic::AtomicI32 = std::sync::atomic::AtomicI32::new(-1),
                cached_hash: std::sync::Mutex<Option<String>> = std::sync::Mutex::new(None)
              },
            stability: binder::Stability::Vintf,
            }
          }
          pub trait IKeystoreSecurityLevel: binder::Interface + Send {
            fn get_descriptor() -> &'static str where Self: Sized { "android.system.keystore2.IKeystoreSecurityLevel" }
            fn createOperation(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_operationParameters: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_forced: bool) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_23_CreateOperationResponse>;
            fn generateKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_entropy: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata>;
            fn importKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_keyData: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata>;
            fn importWrappedKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_wrappingKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_maskingKey: Option<&[u8]>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authenticators: &[crate::mangled::_7_android_6_system_9_keystore2_17_AuthenticatorSpec]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata>;
            fn convertStorageKeyToEphemeral(&self, _arg_storageKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_27_EphemeralStorageKeyResponse>;
            fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()>;
            fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
              Ok(VERSION)
            }
            fn getInterfaceHash(&self) -> binder::public_api::Result<String> {
              Ok(HASH.into())
            }
            fn getDefaultImpl() -> IKeystoreSecurityLevelDefaultRef where Self: Sized {
              DEFAULT_IMPL.lock().unwrap().clone()
            }
            fn setDefaultImpl(d: IKeystoreSecurityLevelDefaultRef) -> IKeystoreSecurityLevelDefaultRef where Self: Sized {
              std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
            }
          }
          pub trait IKeystoreSecurityLevelDefault: Send + Sync {
            fn createOperation(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_operationParameters: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_forced: bool) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_23_CreateOperationResponse> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn generateKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_entropy: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn importKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_keyData: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn importWrappedKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_wrappingKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_maskingKey: Option<&[u8]>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authenticators: &[crate::mangled::_7_android_6_system_9_keystore2_17_AuthenticatorSpec]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn convertStorageKeyToEphemeral(&self, _arg_storageKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_27_EphemeralStorageKeyResponse> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
          }
          pub mod transactions {
            pub const createOperation: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
            pub const generateKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
            pub const importKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
            pub const importWrappedKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 3;
            pub const convertStorageKeyToEphemeral: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 4;
            pub const deleteKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 5;
            pub const getInterfaceVersion: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777214;
            pub const getInterfaceHash: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777213;
          }
          pub type IKeystoreSecurityLevelDefaultRef = Option<std::sync::Arc<dyn IKeystoreSecurityLevelDefault>>;
          use lazy_static::lazy_static;
          lazy_static! {
            static ref DEFAULT_IMPL: std::sync::Mutex<IKeystoreSecurityLevelDefaultRef> = std::sync::Mutex::new(None);
          }
          pub const KEY_FLAG_AUTH_BOUND_WITHOUT_CRYPTOGRAPHIC_LSKF_BINDING: i32 = 1;
          pub(crate) mod mangled { pub use super::IKeystoreSecurityLevel as _7_android_6_system_9_keystore2_22_IKeystoreSecurityLevel; }
          pub const VERSION: i32 = 1;
          pub const HASH: &str = "19e8b65277839bad0ab335c781e3c652324920ce";
          impl IKeystoreSecurityLevel for BpKeystoreSecurityLevel {
            fn createOperation(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_operationParameters: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_forced: bool) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_23_CreateOperationResponse> {
              let _aidl_reply = self.binder.transact(transactions::createOperation, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(_arg_key)?;
                _aidl_data.write(_arg_operationParameters)?;
                _aidl_data.write(&_arg_forced)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreSecurityLevel>::getDefaultImpl() {
                  return _aidl_default_impl.createOperation(_arg_key, _arg_operationParameters, _arg_forced);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: crate::mangled::_7_android_6_system_9_keystore2_23_CreateOperationResponse = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
            fn generateKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_entropy: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> {
              let _aidl_reply = self.binder.transact(transactions::generateKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(_arg_key)?;
                _aidl_data.write(&_arg_attestationKey)?;
                _aidl_data.write(_arg_params)?;
                _aidl_data.write(&_arg_flags)?;
                _aidl_data.write(_arg_entropy)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreSecurityLevel>::getDefaultImpl() {
                  return _aidl_default_impl.generateKey(_arg_key, _arg_attestationKey, _arg_params, _arg_flags, _arg_entropy);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
            fn importKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_keyData: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> {
              let _aidl_reply = self.binder.transact(transactions::importKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(_arg_key)?;
                _aidl_data.write(&_arg_attestationKey)?;
                _aidl_data.write(_arg_params)?;
                _aidl_data.write(&_arg_flags)?;
                _aidl_data.write(_arg_keyData)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreSecurityLevel>::getDefaultImpl() {
                  return _aidl_default_impl.importKey(_arg_key, _arg_attestationKey, _arg_params, _arg_flags, _arg_keyData);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
            fn importWrappedKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_wrappingKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_maskingKey: Option<&[u8]>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authenticators: &[crate::mangled::_7_android_6_system_9_keystore2_17_AuthenticatorSpec]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> {
              let _aidl_reply = self.binder.transact(transactions::importWrappedKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(_arg_key)?;
                _aidl_data.write(_arg_wrappingKey)?;
                _aidl_data.write(&_arg_maskingKey)?;
                _aidl_data.write(_arg_params)?;
                _aidl_data.write(_arg_authenticators)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreSecurityLevel>::getDefaultImpl() {
                  return _aidl_default_impl.importWrappedKey(_arg_key, _arg_wrappingKey, _arg_maskingKey, _arg_params, _arg_authenticators);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
            fn convertStorageKeyToEphemeral(&self, _arg_storageKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_27_EphemeralStorageKeyResponse> {
              let _aidl_reply = self.binder.transact(transactions::convertStorageKeyToEphemeral, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(_arg_storageKey)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreSecurityLevel>::getDefaultImpl() {
                  return _aidl_default_impl.convertStorageKeyToEphemeral(_arg_storageKey);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: crate::mangled::_7_android_6_system_9_keystore2_27_EphemeralStorageKeyResponse = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
            fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> {
              let _aidl_reply = self.binder.transact(transactions::deleteKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
                _aidl_data.write(_arg_key)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreSecurityLevel>::getDefaultImpl() {
                  return _aidl_default_impl.deleteKey(_arg_key);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              Ok(())
            }
            fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
              let _aidl_version = self.cached_version.load(std::sync::atomic::Ordering::Relaxed);
              if _aidl_version != -1 { return Ok(_aidl_version); }
              let _aidl_reply = self.binder.transact(transactions::getInterfaceVersion, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
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
              let _aidl_reply = self.binder.transact(transactions::getInterfaceHash, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.mark_sensitive();
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
          impl IKeystoreSecurityLevel for binder::Binder<BnKeystoreSecurityLevel> {
            fn createOperation(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_operationParameters: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_forced: bool) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_23_CreateOperationResponse> { self.0.createOperation(_arg_key, _arg_operationParameters, _arg_forced) }
            fn generateKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_entropy: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> { self.0.generateKey(_arg_key, _arg_attestationKey, _arg_params, _arg_flags, _arg_entropy) }
            fn importKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_attestationKey: Option<&crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_flags: i32, _arg_keyData: &[u8]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> { self.0.importKey(_arg_key, _arg_attestationKey, _arg_params, _arg_flags, _arg_keyData) }
            fn importWrappedKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_wrappingKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_maskingKey: Option<&[u8]>, _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authenticators: &[crate::mangled::_7_android_6_system_9_keystore2_17_AuthenticatorSpec]) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata> { self.0.importWrappedKey(_arg_key, _arg_wrappingKey, _arg_maskingKey, _arg_params, _arg_authenticators) }
            fn convertStorageKeyToEphemeral(&self, _arg_storageKey: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_27_EphemeralStorageKeyResponse> { self.0.convertStorageKeyToEphemeral(_arg_storageKey) }
            fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> { self.0.deleteKey(_arg_key) }
            fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> { self.0.getInterfaceVersion() }
            fn getInterfaceHash(&self) -> binder::public_api::Result<String> { self.0.getInterfaceHash() }
          }
          fn on_transact(_aidl_service: &dyn IKeystoreSecurityLevel, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
            match _aidl_code {
              transactions::createOperation => {
                let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
                let _arg_operationParameters: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
                let _arg_forced: bool = _aidl_data.read()?;
                let _aidl_return = _aidl_service.createOperation(&_arg_key, &_arg_operationParameters, _arg_forced);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    _aidl_reply.write(_aidl_return)?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::generateKey => {
                let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
                let _arg_attestationKey: Option<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor> = _aidl_data.read()?;
                let _arg_params: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
                let _arg_flags: i32 = _aidl_data.read()?;
                let _arg_entropy: Vec<u8> = _aidl_data.read()?;
                let _aidl_return = _aidl_service.generateKey(&_arg_key, _arg_attestationKey.as_ref(), &_arg_params, _arg_flags, &_arg_entropy);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    _aidl_reply.write(_aidl_return)?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::importKey => {
                let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
                let _arg_attestationKey: Option<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor> = _aidl_data.read()?;
                let _arg_params: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
                let _arg_flags: i32 = _aidl_data.read()?;
                let _arg_keyData: Vec<u8> = _aidl_data.read()?;
                let _aidl_return = _aidl_service.importKey(&_arg_key, _arg_attestationKey.as_ref(), &_arg_params, _arg_flags, &_arg_keyData);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    _aidl_reply.write(_aidl_return)?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::importWrappedKey => {
                let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
                let _arg_wrappingKey: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
                let _arg_maskingKey: Option<Vec<u8>> = _aidl_data.read()?;
                let _arg_params: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
                let _arg_authenticators: Vec<crate::mangled::_7_android_6_system_9_keystore2_17_AuthenticatorSpec> = _aidl_data.read()?;
                let _aidl_return = _aidl_service.importWrappedKey(&_arg_key, &_arg_wrappingKey, _arg_maskingKey.as_deref(), &_arg_params, &_arg_authenticators);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    _aidl_reply.write(_aidl_return)?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::convertStorageKeyToEphemeral => {
                let _arg_storageKey: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
                let _aidl_return = _aidl_service.convertStorageKeyToEphemeral(&_arg_storageKey);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    _aidl_reply.write(_aidl_return)?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::deleteKey => {
                let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
                let _aidl_return = _aidl_service.deleteKey(&_arg_key);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
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
        pub mod IKeystoreService {
          #![allow(non_upper_case_globals)]
          #![allow(non_snake_case)]
          #[allow(unused_imports)] use binder::IBinderInternal;
          use binder::declare_binder_interface;
          declare_binder_interface! {
            IKeystoreService["android.system.keystore2.IKeystoreService"] {
              native: BnKeystoreService(on_transact),
              proxy: BpKeystoreService {
                cached_version: std::sync::atomic::AtomicI32 = std::sync::atomic::AtomicI32::new(-1),
                cached_hash: std::sync::Mutex<Option<String>> = std::sync::Mutex::new(None)
              },
            stability: binder::Stability::Vintf,
            }
          }
          pub trait IKeystoreService: binder::Interface + Send {
            fn get_descriptor() -> &'static str where Self: Sized { "android.system.keystore2.IKeystoreService" }
            fn getSecurityLevel(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_6_system_9_keystore2_22_IKeystoreSecurityLevel>>;
            fn getKeyEntry(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_16_KeyEntryResponse>;
            fn updateSubcomponent(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_publicCert: Option<&[u8]>, _arg_certificateChain: Option<&[u8]>) -> binder::public_api::Result<()>;
            fn listEntries(&self, _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain, _arg_nspace: i64) -> binder::public_api::Result<Vec<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>>;
            fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()>;
            fn grant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32, _arg_accessVector: i32) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>;
            fn ungrant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32) -> binder::public_api::Result<()>;
            fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
              Ok(VERSION)
            }
            fn getInterfaceHash(&self) -> binder::public_api::Result<String> {
              Ok(HASH.into())
            }
            fn getDefaultImpl() -> IKeystoreServiceDefaultRef where Self: Sized {
              DEFAULT_IMPL.lock().unwrap().clone()
            }
            fn setDefaultImpl(d: IKeystoreServiceDefaultRef) -> IKeystoreServiceDefaultRef where Self: Sized {
              std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
            }
          }
          pub trait IKeystoreServiceDefault: Send + Sync {
            fn getSecurityLevel(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_6_system_9_keystore2_22_IKeystoreSecurityLevel>> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn getKeyEntry(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_16_KeyEntryResponse> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn updateSubcomponent(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_publicCert: Option<&[u8]>, _arg_certificateChain: Option<&[u8]>) -> binder::public_api::Result<()> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn listEntries(&self, _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain, _arg_nspace: i64) -> binder::public_api::Result<Vec<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn grant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32, _arg_accessVector: i32) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
            fn ungrant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32) -> binder::public_api::Result<()> {
              Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
            }
          }
          pub mod transactions {
            pub const getSecurityLevel: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
            pub const getKeyEntry: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
            pub const updateSubcomponent: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
            pub const listEntries: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 3;
            pub const deleteKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 4;
            pub const grant: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 5;
            pub const ungrant: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 6;
            pub const getInterfaceVersion: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777214;
            pub const getInterfaceHash: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777213;
          }
          pub type IKeystoreServiceDefaultRef = Option<std::sync::Arc<dyn IKeystoreServiceDefault>>;
          use lazy_static::lazy_static;
          lazy_static! {
            static ref DEFAULT_IMPL: std::sync::Mutex<IKeystoreServiceDefaultRef> = std::sync::Mutex::new(None);
          }
          pub(crate) mod mangled { pub use super::IKeystoreService as _7_android_6_system_9_keystore2_16_IKeystoreService; }
          pub const VERSION: i32 = 1;
          pub const HASH: &str = "19e8b65277839bad0ab335c781e3c652324920ce";
          impl IKeystoreService for BpKeystoreService {
            fn getSecurityLevel(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_6_system_9_keystore2_22_IKeystoreSecurityLevel>> {
              let _aidl_reply = self.binder.transact(transactions::getSecurityLevel, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.write(&_arg_securityLevel)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreService>::getDefaultImpl() {
                  return _aidl_default_impl.getSecurityLevel(_arg_securityLevel);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: binder::Strong<dyn crate::mangled::_7_android_6_system_9_keystore2_22_IKeystoreSecurityLevel> = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
            fn getKeyEntry(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_16_KeyEntryResponse> {
              let _aidl_reply = self.binder.transact(transactions::getKeyEntry, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.write(_arg_key)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreService>::getDefaultImpl() {
                  return _aidl_default_impl.getKeyEntry(_arg_key);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: crate::mangled::_7_android_6_system_9_keystore2_16_KeyEntryResponse = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
            fn updateSubcomponent(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_publicCert: Option<&[u8]>, _arg_certificateChain: Option<&[u8]>) -> binder::public_api::Result<()> {
              let _aidl_reply = self.binder.transact(transactions::updateSubcomponent, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.write(_arg_key)?;
                _aidl_data.write(&_arg_publicCert)?;
                _aidl_data.write(&_arg_certificateChain)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreService>::getDefaultImpl() {
                  return _aidl_default_impl.updateSubcomponent(_arg_key, _arg_publicCert, _arg_certificateChain);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              Ok(())
            }
            fn listEntries(&self, _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain, _arg_nspace: i64) -> binder::public_api::Result<Vec<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>> {
              let _aidl_reply = self.binder.transact(transactions::listEntries, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.write(&_arg_domain)?;
                _aidl_data.write(&_arg_nspace)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreService>::getDefaultImpl() {
                  return _aidl_default_impl.listEntries(_arg_domain, _arg_nspace);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: Vec<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor> = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
            fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> {
              let _aidl_reply = self.binder.transact(transactions::deleteKey, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.write(_arg_key)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreService>::getDefaultImpl() {
                  return _aidl_default_impl.deleteKey(_arg_key);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              Ok(())
            }
            fn grant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32, _arg_accessVector: i32) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor> {
              let _aidl_reply = self.binder.transact(transactions::grant, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.write(_arg_key)?;
                _aidl_data.write(&_arg_granteeUid)?;
                _aidl_data.write(&_arg_accessVector)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreService>::getDefaultImpl() {
                  return _aidl_default_impl.grant(_arg_key, _arg_granteeUid, _arg_accessVector);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              let _aidl_return: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_reply.read()?;
              Ok(_aidl_return)
            }
            fn ungrant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32) -> binder::public_api::Result<()> {
              let _aidl_reply = self.binder.transact(transactions::ungrant, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                _aidl_data.write(_arg_key)?;
                _aidl_data.write(&_arg_granteeUid)?;
                Ok(())
              });
              if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                if let Some(_aidl_default_impl) = <Self as IKeystoreService>::getDefaultImpl() {
                  return _aidl_default_impl.ungrant(_arg_key, _arg_granteeUid);
                }
              }
              let _aidl_reply = _aidl_reply?;
              let _aidl_status: binder::Status = _aidl_reply.read()?;
              if !_aidl_status.is_ok() { return Err(_aidl_status); }
              Ok(())
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
          impl IKeystoreService for binder::Binder<BnKeystoreService> {
            fn getSecurityLevel(&self, _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel) -> binder::public_api::Result<binder::Strong<dyn crate::mangled::_7_android_6_system_9_keystore2_22_IKeystoreSecurityLevel>> { self.0.getSecurityLevel(_arg_securityLevel) }
            fn getKeyEntry(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_16_KeyEntryResponse> { self.0.getKeyEntry(_arg_key) }
            fn updateSubcomponent(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_publicCert: Option<&[u8]>, _arg_certificateChain: Option<&[u8]>) -> binder::public_api::Result<()> { self.0.updateSubcomponent(_arg_key, _arg_publicCert, _arg_certificateChain) }
            fn listEntries(&self, _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain, _arg_nspace: i64) -> binder::public_api::Result<Vec<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor>> { self.0.listEntries(_arg_domain, _arg_nspace) }
            fn deleteKey(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor) -> binder::public_api::Result<()> { self.0.deleteKey(_arg_key) }
            fn grant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32, _arg_accessVector: i32) -> binder::public_api::Result<crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor> { self.0.grant(_arg_key, _arg_granteeUid, _arg_accessVector) }
            fn ungrant(&self, _arg_key: &crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor, _arg_granteeUid: i32) -> binder::public_api::Result<()> { self.0.ungrant(_arg_key, _arg_granteeUid) }
            fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> { self.0.getInterfaceVersion() }
            fn getInterfaceHash(&self) -> binder::public_api::Result<String> { self.0.getInterfaceHash() }
          }
          fn on_transact(_aidl_service: &dyn IKeystoreService, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
            match _aidl_code {
              transactions::getSecurityLevel => {
                let _arg_securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel = _aidl_data.read()?;
                let _aidl_return = _aidl_service.getSecurityLevel(_arg_securityLevel);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    _aidl_reply.write(_aidl_return)?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::getKeyEntry => {
                let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
                let _aidl_return = _aidl_service.getKeyEntry(&_arg_key);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    _aidl_reply.write(_aidl_return)?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::updateSubcomponent => {
                let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
                let _arg_publicCert: Option<Vec<u8>> = _aidl_data.read()?;
                let _arg_certificateChain: Option<Vec<u8>> = _aidl_data.read()?;
                let _aidl_return = _aidl_service.updateSubcomponent(&_arg_key, _arg_publicCert.as_deref(), _arg_certificateChain.as_deref());
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::listEntries => {
                let _arg_domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain = _aidl_data.read()?;
                let _arg_nspace: i64 = _aidl_data.read()?;
                let _aidl_return = _aidl_service.listEntries(_arg_domain, _arg_nspace);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    _aidl_reply.write(_aidl_return)?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::deleteKey => {
                let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
                let _aidl_return = _aidl_service.deleteKey(&_arg_key);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::grant => {
                let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
                let _arg_granteeUid: i32 = _aidl_data.read()?;
                let _arg_accessVector: i32 = _aidl_data.read()?;
                let _aidl_return = _aidl_service.grant(&_arg_key, _arg_granteeUid, _arg_accessVector);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    _aidl_reply.write(_aidl_return)?;
                  }
                  Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                }
                Ok(())
              }
              transactions::ungrant => {
                let _arg_key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor = _aidl_data.read()?;
                let _arg_granteeUid: i32 = _aidl_data.read()?;
                let _aidl_return = _aidl_service.ungrant(&_arg_key, _arg_granteeUid);
                match &_aidl_return {
                  Ok(_aidl_return) => {
                    _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
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
        pub mod KeyDescriptor {
          #[derive(Debug, Clone, Eq, Ord, PartialEq, PartialOrd)]
          pub struct KeyDescriptor {
            pub domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain,
            pub nspace: i64,
            pub alias: Option<String>,
            pub blob: Option<Vec<u8>>,
          }
          pub(crate) mod mangled { pub use super::KeyDescriptor as _7_android_6_system_9_keystore2_13_KeyDescriptor; }
          impl Default for KeyDescriptor {
            fn default() -> Self {
              Self {
                domain: Default::default(),
                nspace: 0,
                alias: Default::default(),
                blob: Default::default(),
              }
            }
          }
          impl binder::parcel::Serialize for KeyDescriptor {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for KeyDescriptor {}
          impl binder::parcel::SerializeOption for KeyDescriptor {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.domain)?;
                subparcel.write(&this.nspace)?;
                subparcel.write(&this.alias)?;
                subparcel.write(&this.blob)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for KeyDescriptor {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for KeyDescriptor {}
          impl binder::parcel::DeserializeOption for KeyDescriptor {
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
              result.domain = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.nspace = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.alias = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.blob = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod KeyEntryResponse {
          #[derive(Debug)]
          pub struct KeyEntryResponse {
            pub iSecurityLevel: Option<binder::Strong<dyn crate::mangled::_7_android_6_system_9_keystore2_22_IKeystoreSecurityLevel>>,
            pub metadata: crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata,
          }
          pub(crate) mod mangled { pub use super::KeyEntryResponse as _7_android_6_system_9_keystore2_16_KeyEntryResponse; }
          impl Default for KeyEntryResponse {
            fn default() -> Self {
              Self {
                iSecurityLevel: Default::default(),
                metadata: Default::default(),
              }
            }
          }
          impl binder::parcel::Serialize for KeyEntryResponse {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for KeyEntryResponse {}
          impl binder::parcel::SerializeOption for KeyEntryResponse {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.iSecurityLevel)?;
                subparcel.write(&this.metadata)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for KeyEntryResponse {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for KeyEntryResponse {}
          impl binder::parcel::DeserializeOption for KeyEntryResponse {
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
              result.iSecurityLevel = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.metadata = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod KeyMetadata {
          #[derive(Debug)]
          pub struct KeyMetadata {
            pub key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor,
            pub keySecurityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel,
            pub authorizations: Vec<crate::mangled::_7_android_6_system_9_keystore2_13_Authorization>,
            pub certificate: Option<Vec<u8>>,
            pub certificateChain: Option<Vec<u8>>,
            pub modificationTimeMs: i64,
          }
          pub(crate) mod mangled { pub use super::KeyMetadata as _7_android_6_system_9_keystore2_11_KeyMetadata; }
          impl Default for KeyMetadata {
            fn default() -> Self {
              Self {
                key: Default::default(),
                keySecurityLevel: Default::default(),
                authorizations: Default::default(),
                certificate: Default::default(),
                certificateChain: Default::default(),
                modificationTimeMs: 0,
              }
            }
          }
          impl binder::parcel::Serialize for KeyMetadata {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for KeyMetadata {}
          impl binder::parcel::SerializeOption for KeyMetadata {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.key)?;
                subparcel.write(&this.keySecurityLevel)?;
                subparcel.write(&this.authorizations)?;
                subparcel.write(&this.certificate)?;
                subparcel.write(&this.certificateChain)?;
                subparcel.write(&this.modificationTimeMs)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for KeyMetadata {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for KeyMetadata {}
          impl binder::parcel::DeserializeOption for KeyMetadata {
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
              result.key = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.keySecurityLevel = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.authorizations = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.certificate = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.certificateChain = parcel.read()?;
              if (parcel.get_data_position() - start_pos) == parcelable_size {
                return Ok(Some(result));
              }
              result.modificationTimeMs = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod KeyParameters {
          #[derive(Debug)]
          pub struct KeyParameters {
            pub keyParameter: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter>,
          }
          pub(crate) mod mangled { pub use super::KeyParameters as _7_android_6_system_9_keystore2_13_KeyParameters; }
          impl Default for KeyParameters {
            fn default() -> Self {
              Self {
                keyParameter: Default::default(),
              }
            }
          }
          impl binder::parcel::Serialize for KeyParameters {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for KeyParameters {}
          impl binder::parcel::SerializeOption for KeyParameters {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.keyParameter)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for KeyParameters {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for KeyParameters {}
          impl binder::parcel::DeserializeOption for KeyParameters {
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
              result.keyParameter = parcel.read()?;
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod KeyPermission {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { KeyPermission : i32 {
            NONE = 0,
            DELETE = 1,
            GEN_UNIQUE_ID = 2,
            GET_INFO = 4,
            GRANT = 8,
            MANAGE_BLOB = 16,
            REBIND = 32,
            REQ_FORCED_OP = 64,
            UPDATE = 128,
            USE = 256,
            USE_DEV_ID = 512,
            USE_NO_LSKF_BINDING = 1024,
            CONVERT_STORAGE_KEY_TO_EPHEMERAL = 2048,
          } }
          pub(crate) mod mangled { pub use super::KeyPermission as _7_android_6_system_9_keystore2_13_KeyPermission; }
        }
        pub mod OperationChallenge {
          #[derive(Debug)]
          pub struct OperationChallenge {
            pub challenge: i64,
          }
          pub(crate) mod mangled { pub use super::OperationChallenge as _7_android_6_system_9_keystore2_18_OperationChallenge; }
          impl Default for OperationChallenge {
            fn default() -> Self {
              Self {
                challenge: 0,
              }
            }
          }
          impl binder::parcel::Serialize for OperationChallenge {
            fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
            }
          }
          impl binder::parcel::SerializeArray for OperationChallenge {}
          impl binder::parcel::SerializeOption for OperationChallenge {
            fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
              let this = if let Some(this) = this {
                parcel.write(&1i32)?;
                this
              } else {
                return parcel.write(&0i32);
              };
              parcel.sized_write(|subparcel| {
                subparcel.write(&this.challenge)?;
                Ok(())
              })
            }
          }
          impl binder::parcel::Deserialize for OperationChallenge {
            fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
              <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                 .transpose()
                 .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
            }
          }
          impl binder::parcel::DeserializeArray for OperationChallenge {}
          impl binder::parcel::DeserializeOption for OperationChallenge {
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
              unsafe {
                parcel.set_data_position(start_pos + parcelable_size)?;
              }
              Ok(Some(result))
            }
          }
        }
        pub mod ResponseCode {
          #![allow(non_upper_case_globals)]
          use binder::declare_binder_enum;
          declare_binder_enum! { ResponseCode : i32 {
            LOCKED = 2,
            UNINITIALIZED = 3,
            SYSTEM_ERROR = 4,
            PERMISSION_DENIED = 6,
            KEY_NOT_FOUND = 7,
            VALUE_CORRUPTED = 8,
            KEY_PERMANENTLY_INVALIDATED = 17,
            BACKEND_BUSY = 18,
            OPERATION_BUSY = 19,
            INVALID_ARGUMENT = 20,
            TOO_MUCH_DATA = 21,
            OUT_OF_KEYS = 22,
          } }
          pub(crate) mod mangled { pub use super::ResponseCode as _7_android_6_system_9_keystore2_12_ResponseCode; }
        }
      }
    }
  }
}
pub mod mangled {
  pub use super::aidl::android::system::keystore2::AuthenticatorSpec::mangled::*;
  pub use super::aidl::android::system::keystore2::Authorization::mangled::*;
  pub use super::aidl::android::system::keystore2::CreateOperationResponse::mangled::*;
  pub use super::aidl::android::system::keystore2::Domain::mangled::*;
  pub use super::aidl::android::system::keystore2::EphemeralStorageKeyResponse::mangled::*;
  pub use super::aidl::android::system::keystore2::IKeystoreOperation::mangled::*;
  pub use super::aidl::android::system::keystore2::IKeystoreSecurityLevel::mangled::*;
  pub use super::aidl::android::system::keystore2::IKeystoreService::mangled::*;
  pub use super::aidl::android::system::keystore2::KeyDescriptor::mangled::*;
  pub use super::aidl::android::system::keystore2::KeyEntryResponse::mangled::*;
  pub use super::aidl::android::system::keystore2::KeyMetadata::mangled::*;
  pub use super::aidl::android::system::keystore2::KeyParameters::mangled::*;
  pub use super::aidl::android::system::keystore2::KeyPermission::mangled::*;
  pub use super::aidl::android::system::keystore2::OperationChallenge::mangled::*;
  pub use super::aidl::android::system::keystore2::ResponseCode::mangled::*;
  pub(crate) use android_hardware_security_keymint::mangled::*;
}
