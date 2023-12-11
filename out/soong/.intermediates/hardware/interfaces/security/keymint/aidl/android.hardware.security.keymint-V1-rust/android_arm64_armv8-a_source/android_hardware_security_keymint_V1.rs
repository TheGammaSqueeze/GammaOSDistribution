#![allow(non_snake_case)]
#![allow(missing_docs)]
pub use binder::public_api as binder;
pub mod aidl {
  pub mod android {
    pub mod hardware {
      pub mod security {
        pub mod keymint {
          pub mod Algorithm {
            #![allow(non_upper_case_globals)]
            use binder::declare_binder_enum;
            declare_binder_enum! { Algorithm : i32 {
              RSA = 1,
              EC = 3,
              AES = 32,
              TRIPLE_DES = 33,
              HMAC = 128,
            } }
            pub(crate) mod mangled { pub use super::Algorithm as _7_android_8_hardware_8_security_7_keymint_9_Algorithm; }
          }
          pub mod AttestationKey {
            #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
            pub struct AttestationKey {
              pub keyBlob: Vec<u8>,
              pub attestKeyParams: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter>,
              pub issuerSubjectName: Vec<u8>,
            }
            pub(crate) mod mangled { pub use super::AttestationKey as _7_android_8_hardware_8_security_7_keymint_14_AttestationKey; }
            impl Default for AttestationKey {
              fn default() -> Self {
                Self {
                  keyBlob: Default::default(),
                  attestKeyParams: Default::default(),
                  issuerSubjectName: Default::default(),
                }
              }
            }
            impl binder::parcel::Serialize for AttestationKey {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for AttestationKey {}
            impl binder::parcel::SerializeOption for AttestationKey {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.keyBlob)?;
                  subparcel.write(&this.attestKeyParams)?;
                  subparcel.write(&this.issuerSubjectName)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for AttestationKey {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for AttestationKey {}
            impl binder::parcel::DeserializeOption for AttestationKey {
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
                result.keyBlob = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.attestKeyParams = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.issuerSubjectName = parcel.read()?;
                unsafe {
                  parcel.set_data_position(start_pos + parcelable_size)?;
                }
                Ok(Some(result))
              }
            }
          }
          pub mod BeginResult {
            #[derive(Debug)]
            pub struct BeginResult {
              pub challenge: i64,
              pub params: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter>,
              pub operation: Option<binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_IKeyMintOperation>>,
            }
            pub(crate) mod mangled { pub use super::BeginResult as _7_android_8_hardware_8_security_7_keymint_11_BeginResult; }
            impl Default for BeginResult {
              fn default() -> Self {
                Self {
                  challenge: 0,
                  params: Default::default(),
                  operation: Default::default(),
                }
              }
            }
            impl binder::parcel::Serialize for BeginResult {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for BeginResult {}
            impl binder::parcel::SerializeOption for BeginResult {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.challenge)?;
                  subparcel.write(&this.params)?;
                  let __field_ref = this.operation.as_ref().ok_or(binder::StatusCode::UNEXPECTED_NULL)?;
                  subparcel.write(__field_ref)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for BeginResult {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for BeginResult {}
            impl binder::parcel::DeserializeOption for BeginResult {
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
                result.params = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.operation = Some(parcel.read()?);
                unsafe {
                  parcel.set_data_position(start_pos + parcelable_size)?;
                }
                Ok(Some(result))
              }
            }
          }
          pub mod BlockMode {
            #![allow(non_upper_case_globals)]
            use binder::declare_binder_enum;
            declare_binder_enum! { BlockMode : i32 {
              ECB = 1,
              CBC = 2,
              CTR = 3,
              GCM = 32,
            } }
            pub(crate) mod mangled { pub use super::BlockMode as _7_android_8_hardware_8_security_7_keymint_9_BlockMode; }
          }
          pub mod Certificate {
            #[derive(Debug)]
            pub struct Certificate {
              pub encodedCertificate: Vec<u8>,
            }
            pub(crate) mod mangled { pub use super::Certificate as _7_android_8_hardware_8_security_7_keymint_11_Certificate; }
            impl Default for Certificate {
              fn default() -> Self {
                Self {
                  encodedCertificate: Default::default(),
                }
              }
            }
            impl binder::parcel::Serialize for Certificate {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for Certificate {}
            impl binder::parcel::SerializeOption for Certificate {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.encodedCertificate)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for Certificate {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for Certificate {}
            impl binder::parcel::DeserializeOption for Certificate {
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
                result.encodedCertificate = parcel.read()?;
                unsafe {
                  parcel.set_data_position(start_pos + parcelable_size)?;
                }
                Ok(Some(result))
              }
            }
          }
          pub mod DeviceInfo {
            #[derive(Debug)]
            pub struct DeviceInfo {
              pub deviceInfo: Vec<u8>,
            }
            pub(crate) mod mangled { pub use super::DeviceInfo as _7_android_8_hardware_8_security_7_keymint_10_DeviceInfo; }
            impl Default for DeviceInfo {
              fn default() -> Self {
                Self {
                  deviceInfo: Default::default(),
                }
              }
            }
            impl binder::parcel::Serialize for DeviceInfo {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for DeviceInfo {}
            impl binder::parcel::SerializeOption for DeviceInfo {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.deviceInfo)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for DeviceInfo {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for DeviceInfo {}
            impl binder::parcel::DeserializeOption for DeviceInfo {
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
                result.deviceInfo = parcel.read()?;
                unsafe {
                  parcel.set_data_position(start_pos + parcelable_size)?;
                }
                Ok(Some(result))
              }
            }
          }
          pub mod Digest {
            #![allow(non_upper_case_globals)]
            use binder::declare_binder_enum;
            declare_binder_enum! { Digest : i32 {
              NONE = 0,
              MD5 = 1,
              SHA1 = 2,
              SHA_2_224 = 3,
              SHA_2_256 = 4,
              SHA_2_384 = 5,
              SHA_2_512 = 6,
            } }
            pub(crate) mod mangled { pub use super::Digest as _7_android_8_hardware_8_security_7_keymint_6_Digest; }
          }
          pub mod EcCurve {
            #![allow(non_upper_case_globals)]
            use binder::declare_binder_enum;
            declare_binder_enum! { EcCurve : i32 {
              P_224 = 0,
              P_256 = 1,
              P_384 = 2,
              P_521 = 3,
            } }
            pub(crate) mod mangled { pub use super::EcCurve as _7_android_8_hardware_8_security_7_keymint_7_EcCurve; }
          }
          pub mod ErrorCode {
            #![allow(non_upper_case_globals)]
            use binder::declare_binder_enum;
            declare_binder_enum! { ErrorCode : i32 {
              OK = 0,
              ROOT_OF_TRUST_ALREADY_SET = -1,
              UNSUPPORTED_PURPOSE = -2,
              INCOMPATIBLE_PURPOSE = -3,
              UNSUPPORTED_ALGORITHM = -4,
              INCOMPATIBLE_ALGORITHM = -5,
              UNSUPPORTED_KEY_SIZE = -6,
              UNSUPPORTED_BLOCK_MODE = -7,
              INCOMPATIBLE_BLOCK_MODE = -8,
              UNSUPPORTED_MAC_LENGTH = -9,
              UNSUPPORTED_PADDING_MODE = -10,
              INCOMPATIBLE_PADDING_MODE = -11,
              UNSUPPORTED_DIGEST = -12,
              INCOMPATIBLE_DIGEST = -13,
              INVALID_EXPIRATION_TIME = -14,
              INVALID_USER_ID = -15,
              INVALID_AUTHORIZATION_TIMEOUT = -16,
              UNSUPPORTED_KEY_FORMAT = -17,
              INCOMPATIBLE_KEY_FORMAT = -18,
              UNSUPPORTED_KEY_ENCRYPTION_ALGORITHM = -19,
              UNSUPPORTED_KEY_VERIFICATION_ALGORITHM = -20,
              INVALID_INPUT_LENGTH = -21,
              KEY_EXPORT_OPTIONS_INVALID = -22,
              DELEGATION_NOT_ALLOWED = -23,
              KEY_NOT_YET_VALID = -24,
              KEY_EXPIRED = -25,
              KEY_USER_NOT_AUTHENTICATED = -26,
              OUTPUT_PARAMETER_NULL = -27,
              INVALID_OPERATION_HANDLE = -28,
              INSUFFICIENT_BUFFER_SPACE = -29,
              VERIFICATION_FAILED = -30,
              TOO_MANY_OPERATIONS = -31,
              UNEXPECTED_NULL_POINTER = -32,
              INVALID_KEY_BLOB = -33,
              IMPORTED_KEY_NOT_ENCRYPTED = -34,
              IMPORTED_KEY_DECRYPTION_FAILED = -35,
              IMPORTED_KEY_NOT_SIGNED = -36,
              IMPORTED_KEY_VERIFICATION_FAILED = -37,
              INVALID_ARGUMENT = -38,
              UNSUPPORTED_TAG = -39,
              INVALID_TAG = -40,
              MEMORY_ALLOCATION_FAILED = -41,
              IMPORT_PARAMETER_MISMATCH = -44,
              SECURE_HW_ACCESS_DENIED = -45,
              OPERATION_CANCELLED = -46,
              CONCURRENT_ACCESS_CONFLICT = -47,
              SECURE_HW_BUSY = -48,
              SECURE_HW_COMMUNICATION_FAILED = -49,
              UNSUPPORTED_EC_FIELD = -50,
              MISSING_NONCE = -51,
              INVALID_NONCE = -52,
              MISSING_MAC_LENGTH = -53,
              KEY_RATE_LIMIT_EXCEEDED = -54,
              CALLER_NONCE_PROHIBITED = -55,
              KEY_MAX_OPS_EXCEEDED = -56,
              INVALID_MAC_LENGTH = -57,
              MISSING_MIN_MAC_LENGTH = -58,
              UNSUPPORTED_MIN_MAC_LENGTH = -59,
              UNSUPPORTED_KDF = -60,
              UNSUPPORTED_EC_CURVE = -61,
              KEY_REQUIRES_UPGRADE = -62,
              ATTESTATION_CHALLENGE_MISSING = -63,
              KEYMINT_NOT_CONFIGURED = -64,
              ATTESTATION_APPLICATION_ID_MISSING = -65,
              CANNOT_ATTEST_IDS = -66,
              ROLLBACK_RESISTANCE_UNAVAILABLE = -67,
              HARDWARE_TYPE_UNAVAILABLE = -68,
              PROOF_OF_PRESENCE_REQUIRED = -69,
              CONCURRENT_PROOF_OF_PRESENCE_REQUESTED = -70,
              NO_USER_CONFIRMATION = -71,
              DEVICE_LOCKED = -72,
              EARLY_BOOT_ENDED = -73,
              ATTESTATION_KEYS_NOT_PROVISIONED = -74,
              ATTESTATION_IDS_NOT_PROVISIONED = -75,
              INVALID_OPERATION = -76,
              STORAGE_KEY_UNSUPPORTED = -77,
              INCOMPATIBLE_MGF_DIGEST = -78,
              UNSUPPORTED_MGF_DIGEST = -79,
              MISSING_NOT_BEFORE = -80,
              MISSING_NOT_AFTER = -81,
              MISSING_ISSUER_SUBJECT = -82,
              INVALID_ISSUER_SUBJECT = -83,
              BOOT_LEVEL_EXCEEDED = -84,
              HARDWARE_NOT_YET_AVAILABLE = -85,
              UNIMPLEMENTED = -100,
              VERSION_MISMATCH = -101,
              UNKNOWN_ERROR = -1000,
            } }
            pub(crate) mod mangled { pub use super::ErrorCode as _7_android_8_hardware_8_security_7_keymint_9_ErrorCode; }
          }
          pub mod HardwareAuthToken {
            #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
            pub struct HardwareAuthToken {
              pub challenge: i64,
              pub userId: i64,
              pub authenticatorId: i64,
              pub authenticatorType: crate::mangled::_7_android_8_hardware_8_security_7_keymint_25_HardwareAuthenticatorType,
              pub timestamp: crate::mangled::_7_android_8_hardware_8_security_11_secureclock_9_Timestamp,
              pub mac: Vec<u8>,
            }
            pub(crate) mod mangled { pub use super::HardwareAuthToken as _7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken; }
            impl Default for HardwareAuthToken {
              fn default() -> Self {
                Self {
                  challenge: 0,
                  userId: 0,
                  authenticatorId: 0,
                  authenticatorType: crate::mangled::_7_android_8_hardware_8_security_7_keymint_25_HardwareAuthenticatorType::NONE,
                  timestamp: Default::default(),
                  mac: Default::default(),
                }
              }
            }
            impl binder::parcel::Serialize for HardwareAuthToken {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for HardwareAuthToken {}
            impl binder::parcel::SerializeOption for HardwareAuthToken {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.challenge)?;
                  subparcel.write(&this.userId)?;
                  subparcel.write(&this.authenticatorId)?;
                  subparcel.write(&this.authenticatorType)?;
                  subparcel.write(&this.timestamp)?;
                  subparcel.write(&this.mac)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for HardwareAuthToken {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for HardwareAuthToken {}
            impl binder::parcel::DeserializeOption for HardwareAuthToken {
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
                result.userId = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.authenticatorId = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.authenticatorType = parcel.read()?;
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
          pub mod HardwareAuthenticatorType {
            #![allow(non_upper_case_globals)]
            use binder::declare_binder_enum;
            declare_binder_enum! { HardwareAuthenticatorType : i32 {
              NONE = 0,
              PASSWORD = 1,
              FINGERPRINT = 2,
              ANY = -1,
            } }
            pub(crate) mod mangled { pub use super::HardwareAuthenticatorType as _7_android_8_hardware_8_security_7_keymint_25_HardwareAuthenticatorType; }
          }
          pub mod IKeyMintDevice {
            #![allow(non_upper_case_globals)]
            #![allow(non_snake_case)]
            #[allow(unused_imports)] use binder::IBinderInternal;
            use binder::declare_binder_interface;
            declare_binder_interface! {
              IKeyMintDevice["android.hardware.security.keymint.IKeyMintDevice"] {
                native: BnKeyMintDevice(on_transact),
                proxy: BpKeyMintDevice {
                  cached_version: std::sync::atomic::AtomicI32 = std::sync::atomic::AtomicI32::new(-1),
                  cached_hash: std::sync::Mutex<Option<String>> = std::sync::Mutex::new(None)
                },
              stability: binder::Stability::Vintf,
              }
            }
            pub trait IKeyMintDevice: binder::Interface + Send {
              fn get_descriptor() -> &'static str where Self: Sized { "android.hardware.security.keymint.IKeyMintDevice" }
              fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_19_KeyMintHardwareInfo>;
              fn addRngEntropy(&self, _arg_data: &[u8]) -> binder::public_api::Result<()>;
              fn generateKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult>;
              fn importKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_keyFormat: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_KeyFormat, _arg_keyData: &[u8], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult>;
              fn importWrappedKey(&self, _arg_wrappedKeyData: &[u8], _arg_wrappingKeyBlob: &[u8], _arg_maskingKey: &[u8], _arg_unwrappingParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_passwordSid: i64, _arg_biometricSid: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult>;
              fn upgradeKey(&self, _arg_keyBlobToUpgrade: &[u8], _arg_upgradeParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter]) -> binder::public_api::Result<Vec<u8>>;
              fn deleteKey(&self, _arg_keyBlob: &[u8]) -> binder::public_api::Result<()>;
              fn deleteAllKeys(&self) -> binder::public_api::Result<()>;
              fn destroyAttestationIds(&self) -> binder::public_api::Result<()>;
              fn begin(&self, _arg_purpose: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_KeyPurpose, _arg_keyBlob: &[u8], _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_BeginResult>;
              fn deviceLocked(&self, _arg_passwordOnly: bool, _arg_timestampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<()>;
              fn earlyBootEnded(&self) -> binder::public_api::Result<()>;
              fn convertStorageKeyToEphemeral(&self, _arg_storageKeyBlob: &[u8]) -> binder::public_api::Result<Vec<u8>>;
              fn getKeyCharacteristics(&self, _arg_keyBlob: &[u8], _arg_appId: &[u8], _arg_appData: &[u8]) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_18_KeyCharacteristics>>;
              fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
                Ok(VERSION)
              }
              fn getInterfaceHash(&self) -> binder::public_api::Result<String> {
                Ok(HASH.into())
              }
              fn getDefaultImpl() -> IKeyMintDeviceDefaultRef where Self: Sized {
                DEFAULT_IMPL.lock().unwrap().clone()
              }
              fn setDefaultImpl(d: IKeyMintDeviceDefaultRef) -> IKeyMintDeviceDefaultRef where Self: Sized {
                std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
              }
            }
            pub trait IKeyMintDeviceDefault: Send + Sync {
              fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_19_KeyMintHardwareInfo> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn addRngEntropy(&self, _arg_data: &[u8]) -> binder::public_api::Result<()> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn generateKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn importKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_keyFormat: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_KeyFormat, _arg_keyData: &[u8], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn importWrappedKey(&self, _arg_wrappedKeyData: &[u8], _arg_wrappingKeyBlob: &[u8], _arg_maskingKey: &[u8], _arg_unwrappingParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_passwordSid: i64, _arg_biometricSid: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn upgradeKey(&self, _arg_keyBlobToUpgrade: &[u8], _arg_upgradeParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter]) -> binder::public_api::Result<Vec<u8>> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn deleteKey(&self, _arg_keyBlob: &[u8]) -> binder::public_api::Result<()> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn deleteAllKeys(&self) -> binder::public_api::Result<()> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn destroyAttestationIds(&self) -> binder::public_api::Result<()> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn begin(&self, _arg_purpose: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_KeyPurpose, _arg_keyBlob: &[u8], _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_BeginResult> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn deviceLocked(&self, _arg_passwordOnly: bool, _arg_timestampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<()> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn earlyBootEnded(&self) -> binder::public_api::Result<()> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn convertStorageKeyToEphemeral(&self, _arg_storageKeyBlob: &[u8]) -> binder::public_api::Result<Vec<u8>> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn getKeyCharacteristics(&self, _arg_keyBlob: &[u8], _arg_appId: &[u8], _arg_appData: &[u8]) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_18_KeyCharacteristics>> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
            }
            pub mod transactions {
              pub const getHardwareInfo: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
              pub const addRngEntropy: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
              pub const generateKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
              pub const importKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 3;
              pub const importWrappedKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 4;
              pub const upgradeKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 5;
              pub const deleteKey: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 6;
              pub const deleteAllKeys: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 7;
              pub const destroyAttestationIds: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 8;
              pub const begin: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 9;
              pub const deviceLocked: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 10;
              pub const earlyBootEnded: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 11;
              pub const convertStorageKeyToEphemeral: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 12;
              pub const getKeyCharacteristics: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 13;
              pub const getInterfaceVersion: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777214;
              pub const getInterfaceHash: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777213;
            }
            pub type IKeyMintDeviceDefaultRef = Option<std::sync::Arc<dyn IKeyMintDeviceDefault>>;
            use lazy_static::lazy_static;
            lazy_static! {
              static ref DEFAULT_IMPL: std::sync::Mutex<IKeyMintDeviceDefaultRef> = std::sync::Mutex::new(None);
            }
            pub const AUTH_TOKEN_MAC_LENGTH: i32 = 32;
            pub(crate) mod mangled { pub use super::IKeyMintDevice as _7_android_8_hardware_8_security_7_keymint_14_IKeyMintDevice; }
            pub const VERSION: i32 = 1;
            pub const HASH: &str = "976674616001f714f4a4df49ee45f548de828524";
            impl IKeyMintDevice for BpKeyMintDevice {
              fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_19_KeyMintHardwareInfo> {
                let _aidl_reply = self.binder.transact(transactions::getHardwareInfo, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
                    return _aidl_default_impl.getHardwareInfo();
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: crate::mangled::_7_android_8_hardware_8_security_7_keymint_19_KeyMintHardwareInfo = _aidl_reply.read()?;
                Ok(_aidl_return)
              }
              fn addRngEntropy(&self, _arg_data: &[u8]) -> binder::public_api::Result<()> {
                let _aidl_reply = self.binder.transact(transactions::addRngEntropy, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  _aidl_data.write(_arg_data)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
                    return _aidl_default_impl.addRngEntropy(_arg_data);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                Ok(())
              }
              fn generateKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> {
                let _aidl_reply = self.binder.transact(transactions::generateKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  _aidl_data.write(_arg_keyParams)?;
                  _aidl_data.write(&_arg_attestationKey)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
                    return _aidl_default_impl.generateKey(_arg_keyParams, _arg_attestationKey);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult = _aidl_reply.read()?;
                Ok(_aidl_return)
              }
              fn importKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_keyFormat: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_KeyFormat, _arg_keyData: &[u8], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> {
                let _aidl_reply = self.binder.transact(transactions::importKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  _aidl_data.write(_arg_keyParams)?;
                  _aidl_data.write(&_arg_keyFormat)?;
                  _aidl_data.write(_arg_keyData)?;
                  _aidl_data.write(&_arg_attestationKey)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
                    return _aidl_default_impl.importKey(_arg_keyParams, _arg_keyFormat, _arg_keyData, _arg_attestationKey);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult = _aidl_reply.read()?;
                Ok(_aidl_return)
              }
              fn importWrappedKey(&self, _arg_wrappedKeyData: &[u8], _arg_wrappingKeyBlob: &[u8], _arg_maskingKey: &[u8], _arg_unwrappingParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_passwordSid: i64, _arg_biometricSid: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> {
                let _aidl_reply = self.binder.transact(transactions::importWrappedKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  _aidl_data.write(_arg_wrappedKeyData)?;
                  _aidl_data.write(_arg_wrappingKeyBlob)?;
                  _aidl_data.write(_arg_maskingKey)?;
                  _aidl_data.write(_arg_unwrappingParams)?;
                  _aidl_data.write(&_arg_passwordSid)?;
                  _aidl_data.write(&_arg_biometricSid)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
                    return _aidl_default_impl.importWrappedKey(_arg_wrappedKeyData, _arg_wrappingKeyBlob, _arg_maskingKey, _arg_unwrappingParams, _arg_passwordSid, _arg_biometricSid);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult = _aidl_reply.read()?;
                Ok(_aidl_return)
              }
              fn upgradeKey(&self, _arg_keyBlobToUpgrade: &[u8], _arg_upgradeParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter]) -> binder::public_api::Result<Vec<u8>> {
                let _aidl_reply = self.binder.transact(transactions::upgradeKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  _aidl_data.write(_arg_keyBlobToUpgrade)?;
                  _aidl_data.write(_arg_upgradeParams)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
                    return _aidl_default_impl.upgradeKey(_arg_keyBlobToUpgrade, _arg_upgradeParams);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: Vec<u8> = _aidl_reply.read()?;
                Ok(_aidl_return)
              }
              fn deleteKey(&self, _arg_keyBlob: &[u8]) -> binder::public_api::Result<()> {
                let _aidl_reply = self.binder.transact(transactions::deleteKey, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  _aidl_data.write(_arg_keyBlob)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
                    return _aidl_default_impl.deleteKey(_arg_keyBlob);
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
                  if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
                    return _aidl_default_impl.deleteAllKeys();
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                Ok(())
              }
              fn destroyAttestationIds(&self) -> binder::public_api::Result<()> {
                let _aidl_reply = self.binder.transact(transactions::destroyAttestationIds, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
                    return _aidl_default_impl.destroyAttestationIds();
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                Ok(())
              }
              fn begin(&self, _arg_purpose: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_KeyPurpose, _arg_keyBlob: &[u8], _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_BeginResult> {
                let _aidl_reply = self.binder.transact(transactions::begin, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  _aidl_data.write(&_arg_purpose)?;
                  _aidl_data.write(_arg_keyBlob)?;
                  _aidl_data.write(_arg_params)?;
                  _aidl_data.write(&_arg_authToken)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
                    return _aidl_default_impl.begin(_arg_purpose, _arg_keyBlob, _arg_params, _arg_authToken);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_BeginResult = _aidl_reply.read()?;
                Ok(_aidl_return)
              }
              fn deviceLocked(&self, _arg_passwordOnly: bool, _arg_timestampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<()> {
                let _aidl_reply = self.binder.transact(transactions::deviceLocked, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  _aidl_data.write(&_arg_passwordOnly)?;
                  _aidl_data.write(&_arg_timestampToken)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
                    return _aidl_default_impl.deviceLocked(_arg_passwordOnly, _arg_timestampToken);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                Ok(())
              }
              fn earlyBootEnded(&self) -> binder::public_api::Result<()> {
                let _aidl_reply = self.binder.transact(transactions::earlyBootEnded, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
                    return _aidl_default_impl.earlyBootEnded();
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                Ok(())
              }
              fn convertStorageKeyToEphemeral(&self, _arg_storageKeyBlob: &[u8]) -> binder::public_api::Result<Vec<u8>> {
                let _aidl_reply = self.binder.transact(transactions::convertStorageKeyToEphemeral, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  _aidl_data.write(_arg_storageKeyBlob)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
                    return _aidl_default_impl.convertStorageKeyToEphemeral(_arg_storageKeyBlob);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: Vec<u8> = _aidl_reply.read()?;
                Ok(_aidl_return)
              }
              fn getKeyCharacteristics(&self, _arg_keyBlob: &[u8], _arg_appId: &[u8], _arg_appData: &[u8]) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_18_KeyCharacteristics>> {
                let _aidl_reply = self.binder.transact(transactions::getKeyCharacteristics, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  _aidl_data.write(_arg_keyBlob)?;
                  _aidl_data.write(_arg_appId)?;
                  _aidl_data.write(_arg_appData)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintDevice>::getDefaultImpl() {
                    return _aidl_default_impl.getKeyCharacteristics(_arg_keyBlob, _arg_appId, _arg_appData);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_18_KeyCharacteristics> = _aidl_reply.read()?;
                Ok(_aidl_return)
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
            impl IKeyMintDevice for binder::Binder<BnKeyMintDevice> {
              fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_19_KeyMintHardwareInfo> { self.0.getHardwareInfo() }
              fn addRngEntropy(&self, _arg_data: &[u8]) -> binder::public_api::Result<()> { self.0.addRngEntropy(_arg_data) }
              fn generateKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> { self.0.generateKey(_arg_keyParams, _arg_attestationKey) }
              fn importKey(&self, _arg_keyParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_keyFormat: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_KeyFormat, _arg_keyData: &[u8], _arg_attestationKey: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> { self.0.importKey(_arg_keyParams, _arg_keyFormat, _arg_keyData, _arg_attestationKey) }
              fn importWrappedKey(&self, _arg_wrappedKeyData: &[u8], _arg_wrappingKeyBlob: &[u8], _arg_maskingKey: &[u8], _arg_unwrappingParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_passwordSid: i64, _arg_biometricSid: i64) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult> { self.0.importWrappedKey(_arg_wrappedKeyData, _arg_wrappingKeyBlob, _arg_maskingKey, _arg_unwrappingParams, _arg_passwordSid, _arg_biometricSid) }
              fn upgradeKey(&self, _arg_keyBlobToUpgrade: &[u8], _arg_upgradeParams: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter]) -> binder::public_api::Result<Vec<u8>> { self.0.upgradeKey(_arg_keyBlobToUpgrade, _arg_upgradeParams) }
              fn deleteKey(&self, _arg_keyBlob: &[u8]) -> binder::public_api::Result<()> { self.0.deleteKey(_arg_keyBlob) }
              fn deleteAllKeys(&self) -> binder::public_api::Result<()> { self.0.deleteAllKeys() }
              fn destroyAttestationIds(&self) -> binder::public_api::Result<()> { self.0.destroyAttestationIds() }
              fn begin(&self, _arg_purpose: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_KeyPurpose, _arg_keyBlob: &[u8], _arg_params: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_BeginResult> { self.0.begin(_arg_purpose, _arg_keyBlob, _arg_params, _arg_authToken) }
              fn deviceLocked(&self, _arg_passwordOnly: bool, _arg_timestampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<()> { self.0.deviceLocked(_arg_passwordOnly, _arg_timestampToken) }
              fn earlyBootEnded(&self) -> binder::public_api::Result<()> { self.0.earlyBootEnded() }
              fn convertStorageKeyToEphemeral(&self, _arg_storageKeyBlob: &[u8]) -> binder::public_api::Result<Vec<u8>> { self.0.convertStorageKeyToEphemeral(_arg_storageKeyBlob) }
              fn getKeyCharacteristics(&self, _arg_keyBlob: &[u8], _arg_appId: &[u8], _arg_appData: &[u8]) -> binder::public_api::Result<Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_18_KeyCharacteristics>> { self.0.getKeyCharacteristics(_arg_keyBlob, _arg_appId, _arg_appData) }
              fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> { self.0.getInterfaceVersion() }
              fn getInterfaceHash(&self) -> binder::public_api::Result<String> { self.0.getInterfaceHash() }
            }
            fn on_transact(_aidl_service: &dyn IKeyMintDevice, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
              match _aidl_code {
                transactions::getHardwareInfo => {
                  let _aidl_return = _aidl_service.getHardwareInfo();
                  match &_aidl_return {
                    Ok(_aidl_return) => {
                      _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                      _aidl_reply.write(_aidl_return)?;
                    }
                    Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                  }
                  Ok(())
                }
                transactions::addRngEntropy => {
                  let _arg_data: Vec<u8> = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.addRngEntropy(&_arg_data);
                  match &_aidl_return {
                    Ok(_aidl_return) => {
                      _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    }
                    Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                  }
                  Ok(())
                }
                transactions::generateKey => {
                  let _arg_keyParams: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
                  let _arg_attestationKey: Option<crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey> = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.generateKey(&_arg_keyParams, _arg_attestationKey.as_ref());
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
                  let _arg_keyParams: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
                  let _arg_keyFormat: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_KeyFormat = _aidl_data.read()?;
                  let _arg_keyData: Vec<u8> = _aidl_data.read()?;
                  let _arg_attestationKey: Option<crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_AttestationKey> = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.importKey(&_arg_keyParams, _arg_keyFormat, &_arg_keyData, _arg_attestationKey.as_ref());
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
                  let _arg_wrappedKeyData: Vec<u8> = _aidl_data.read()?;
                  let _arg_wrappingKeyBlob: Vec<u8> = _aidl_data.read()?;
                  let _arg_maskingKey: Vec<u8> = _aidl_data.read()?;
                  let _arg_unwrappingParams: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
                  let _arg_passwordSid: i64 = _aidl_data.read()?;
                  let _arg_biometricSid: i64 = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.importWrappedKey(&_arg_wrappedKeyData, &_arg_wrappingKeyBlob, &_arg_maskingKey, &_arg_unwrappingParams, _arg_passwordSid, _arg_biometricSid);
                  match &_aidl_return {
                    Ok(_aidl_return) => {
                      _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                      _aidl_reply.write(_aidl_return)?;
                    }
                    Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                  }
                  Ok(())
                }
                transactions::upgradeKey => {
                  let _arg_keyBlobToUpgrade: Vec<u8> = _aidl_data.read()?;
                  let _arg_upgradeParams: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.upgradeKey(&_arg_keyBlobToUpgrade, &_arg_upgradeParams);
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
                  let _arg_keyBlob: Vec<u8> = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.deleteKey(&_arg_keyBlob);
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
                transactions::destroyAttestationIds => {
                  let _aidl_return = _aidl_service.destroyAttestationIds();
                  match &_aidl_return {
                    Ok(_aidl_return) => {
                      _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                    }
                    Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                  }
                  Ok(())
                }
                transactions::begin => {
                  let _arg_purpose: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_KeyPurpose = _aidl_data.read()?;
                  let _arg_keyBlob: Vec<u8> = _aidl_data.read()?;
                  let _arg_params: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter> = _aidl_data.read()?;
                  let _arg_authToken: Option<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken> = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.begin(_arg_purpose, &_arg_keyBlob, &_arg_params, _arg_authToken.as_ref());
                  match &_aidl_return {
                    Ok(_aidl_return) => {
                      _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                      _aidl_reply.write(_aidl_return)?;
                    }
                    Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                  }
                  Ok(())
                }
                transactions::deviceLocked => {
                  let _arg_passwordOnly: bool = _aidl_data.read()?;
                  let _arg_timestampToken: Option<crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken> = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.deviceLocked(_arg_passwordOnly, _arg_timestampToken.as_ref());
                  match &_aidl_return {
                    Ok(_aidl_return) => {
                      _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
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
                transactions::convertStorageKeyToEphemeral => {
                  let _arg_storageKeyBlob: Vec<u8> = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.convertStorageKeyToEphemeral(&_arg_storageKeyBlob);
                  match &_aidl_return {
                    Ok(_aidl_return) => {
                      _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                      _aidl_reply.write(_aidl_return)?;
                    }
                    Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                  }
                  Ok(())
                }
                transactions::getKeyCharacteristics => {
                  let _arg_keyBlob: Vec<u8> = _aidl_data.read()?;
                  let _arg_appId: Vec<u8> = _aidl_data.read()?;
                  let _arg_appData: Vec<u8> = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.getKeyCharacteristics(&_arg_keyBlob, &_arg_appId, &_arg_appData);
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
          pub mod IKeyMintOperation {
            #![allow(non_upper_case_globals)]
            #![allow(non_snake_case)]
            #[allow(unused_imports)] use binder::IBinderInternal;
            use binder::declare_binder_interface;
            declare_binder_interface! {
              IKeyMintOperation["android.hardware.security.keymint.IKeyMintOperation"] {
                native: BnKeyMintOperation(on_transact),
                proxy: BpKeyMintOperation {
                  cached_version: std::sync::atomic::AtomicI32 = std::sync::atomic::AtomicI32::new(-1),
                  cached_hash: std::sync::Mutex<Option<String>> = std::sync::Mutex::new(None)
                },
              stability: binder::Stability::Vintf,
              }
            }
            pub trait IKeyMintOperation: binder::Interface + Send {
              fn get_descriptor() -> &'static str where Self: Sized { "android.hardware.security.keymint.IKeyMintOperation" }
              fn updateAad(&self, _arg_input: &[u8], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>, _arg_timeStampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<()>;
              fn update(&self, _arg_input: &[u8], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>, _arg_timeStampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<Vec<u8>>;
              fn finish(&self, _arg_input: Option<&[u8]>, _arg_signature: Option<&[u8]>, _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>, _arg_timestampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>, _arg_confirmationToken: Option<&[u8]>) -> binder::public_api::Result<Vec<u8>>;
              fn abort(&self) -> binder::public_api::Result<()>;
              fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
                Ok(VERSION)
              }
              fn getInterfaceHash(&self) -> binder::public_api::Result<String> {
                Ok(HASH.into())
              }
              fn getDefaultImpl() -> IKeyMintOperationDefaultRef where Self: Sized {
                DEFAULT_IMPL.lock().unwrap().clone()
              }
              fn setDefaultImpl(d: IKeyMintOperationDefaultRef) -> IKeyMintOperationDefaultRef where Self: Sized {
                std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
              }
            }
            pub trait IKeyMintOperationDefault: Send + Sync {
              fn updateAad(&self, _arg_input: &[u8], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>, _arg_timeStampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<()> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn update(&self, _arg_input: &[u8], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>, _arg_timeStampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<Vec<u8>> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn finish(&self, _arg_input: Option<&[u8]>, _arg_signature: Option<&[u8]>, _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>, _arg_timestampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>, _arg_confirmationToken: Option<&[u8]>) -> binder::public_api::Result<Vec<u8>> {
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
            pub type IKeyMintOperationDefaultRef = Option<std::sync::Arc<dyn IKeyMintOperationDefault>>;
            use lazy_static::lazy_static;
            lazy_static! {
              static ref DEFAULT_IMPL: std::sync::Mutex<IKeyMintOperationDefaultRef> = std::sync::Mutex::new(None);
            }
            pub(crate) mod mangled { pub use super::IKeyMintOperation as _7_android_8_hardware_8_security_7_keymint_17_IKeyMintOperation; }
            pub const VERSION: i32 = 1;
            pub const HASH: &str = "976674616001f714f4a4df49ee45f548de828524";
            impl IKeyMintOperation for BpKeyMintOperation {
              fn updateAad(&self, _arg_input: &[u8], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>, _arg_timeStampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<()> {
                let _aidl_reply = self.binder.transact(transactions::updateAad, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  _aidl_data.write(_arg_input)?;
                  _aidl_data.write(&_arg_authToken)?;
                  _aidl_data.write(&_arg_timeStampToken)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintOperation>::getDefaultImpl() {
                    return _aidl_default_impl.updateAad(_arg_input, _arg_authToken, _arg_timeStampToken);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                Ok(())
              }
              fn update(&self, _arg_input: &[u8], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>, _arg_timeStampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<Vec<u8>> {
                let _aidl_reply = self.binder.transact(transactions::update, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  _aidl_data.write(_arg_input)?;
                  _aidl_data.write(&_arg_authToken)?;
                  _aidl_data.write(&_arg_timeStampToken)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintOperation>::getDefaultImpl() {
                    return _aidl_default_impl.update(_arg_input, _arg_authToken, _arg_timeStampToken);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: Vec<u8> = _aidl_reply.read()?;
                Ok(_aidl_return)
              }
              fn finish(&self, _arg_input: Option<&[u8]>, _arg_signature: Option<&[u8]>, _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>, _arg_timestampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>, _arg_confirmationToken: Option<&[u8]>) -> binder::public_api::Result<Vec<u8>> {
                let _aidl_reply = self.binder.transact(transactions::finish, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  _aidl_data.write(&_arg_input)?;
                  _aidl_data.write(&_arg_signature)?;
                  _aidl_data.write(&_arg_authToken)?;
                  _aidl_data.write(&_arg_timestampToken)?;
                  _aidl_data.write(&_arg_confirmationToken)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintOperation>::getDefaultImpl() {
                    return _aidl_default_impl.finish(_arg_input, _arg_signature, _arg_authToken, _arg_timestampToken, _arg_confirmationToken);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: Vec<u8> = _aidl_reply.read()?;
                Ok(_aidl_return)
              }
              fn abort(&self) -> binder::public_api::Result<()> {
                let _aidl_reply = self.binder.transact(transactions::abort, binder::FLAG_CLEAR_BUF | binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.mark_sensitive();
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IKeyMintOperation>::getDefaultImpl() {
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
            impl IKeyMintOperation for binder::Binder<BnKeyMintOperation> {
              fn updateAad(&self, _arg_input: &[u8], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>, _arg_timeStampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<()> { self.0.updateAad(_arg_input, _arg_authToken, _arg_timeStampToken) }
              fn update(&self, _arg_input: &[u8], _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>, _arg_timeStampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>) -> binder::public_api::Result<Vec<u8>> { self.0.update(_arg_input, _arg_authToken, _arg_timeStampToken) }
              fn finish(&self, _arg_input: Option<&[u8]>, _arg_signature: Option<&[u8]>, _arg_authToken: Option<&crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken>, _arg_timestampToken: Option<&crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken>, _arg_confirmationToken: Option<&[u8]>) -> binder::public_api::Result<Vec<u8>> { self.0.finish(_arg_input, _arg_signature, _arg_authToken, _arg_timestampToken, _arg_confirmationToken) }
              fn abort(&self) -> binder::public_api::Result<()> { self.0.abort() }
              fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> { self.0.getInterfaceVersion() }
              fn getInterfaceHash(&self) -> binder::public_api::Result<String> { self.0.getInterfaceHash() }
            }
            fn on_transact(_aidl_service: &dyn IKeyMintOperation, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
              match _aidl_code {
                transactions::updateAad => {
                  let _arg_input: Vec<u8> = _aidl_data.read()?;
                  let _arg_authToken: Option<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken> = _aidl_data.read()?;
                  let _arg_timeStampToken: Option<crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken> = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.updateAad(&_arg_input, _arg_authToken.as_ref(), _arg_timeStampToken.as_ref());
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
                  let _arg_authToken: Option<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken> = _aidl_data.read()?;
                  let _arg_timeStampToken: Option<crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken> = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.update(&_arg_input, _arg_authToken.as_ref(), _arg_timeStampToken.as_ref());
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
                  let _arg_authToken: Option<crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken> = _aidl_data.read()?;
                  let _arg_timestampToken: Option<crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken> = _aidl_data.read()?;
                  let _arg_confirmationToken: Option<Vec<u8>> = _aidl_data.read()?;
                  let _aidl_return = _aidl_service.finish(_arg_input.as_deref(), _arg_signature.as_deref(), _arg_authToken.as_ref(), _arg_timestampToken.as_ref(), _arg_confirmationToken.as_deref());
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
          pub mod IRemotelyProvisionedComponent {
            #![allow(non_upper_case_globals)]
            #![allow(non_snake_case)]
            #[allow(unused_imports)] use binder::IBinderInternal;
            use binder::declare_binder_interface;
            declare_binder_interface! {
              IRemotelyProvisionedComponent["android.hardware.security.keymint.IRemotelyProvisionedComponent"] {
                native: BnRemotelyProvisionedComponent(on_transact),
                proxy: BpRemotelyProvisionedComponent {
                  cached_version: std::sync::atomic::AtomicI32 = std::sync::atomic::AtomicI32::new(-1),
                  cached_hash: std::sync::Mutex<Option<String>> = std::sync::Mutex::new(None)
                },
              stability: binder::Stability::Vintf,
              }
            }
            pub trait IRemotelyProvisionedComponent: binder::Interface + Send {
              fn get_descriptor() -> &'static str where Self: Sized { "android.hardware.security.keymint.IRemotelyProvisionedComponent" }
              fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_15_RpcHardwareInfo>;
              fn generateEcdsaP256KeyPair(&self, _arg_testMode: bool, _arg_macedPublicKey: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey) -> binder::public_api::Result<Vec<u8>>;
              fn generateCertificateRequest(&self, _arg_testMode: bool, _arg_keysToSign: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey], _arg_endpointEncryptionCertChain: &[u8], _arg_challenge: &[u8], _arg_deviceInfo: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo, _arg_protectedData: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData) -> binder::public_api::Result<Vec<u8>>;
              fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> {
                Ok(VERSION)
              }
              fn getInterfaceHash(&self) -> binder::public_api::Result<String> {
                Ok(HASH.into())
              }
              fn getDefaultImpl() -> IRemotelyProvisionedComponentDefaultRef where Self: Sized {
                DEFAULT_IMPL.lock().unwrap().clone()
              }
              fn setDefaultImpl(d: IRemotelyProvisionedComponentDefaultRef) -> IRemotelyProvisionedComponentDefaultRef where Self: Sized {
                std::mem::replace(&mut *DEFAULT_IMPL.lock().unwrap(), d)
              }
            }
            pub trait IRemotelyProvisionedComponentDefault: Send + Sync {
              fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_15_RpcHardwareInfo> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn generateEcdsaP256KeyPair(&self, _arg_testMode: bool, _arg_macedPublicKey: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey) -> binder::public_api::Result<Vec<u8>> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
              fn generateCertificateRequest(&self, _arg_testMode: bool, _arg_keysToSign: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey], _arg_endpointEncryptionCertChain: &[u8], _arg_challenge: &[u8], _arg_deviceInfo: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo, _arg_protectedData: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData) -> binder::public_api::Result<Vec<u8>> {
                Err(binder::StatusCode::UNKNOWN_TRANSACTION.into())
              }
            }
            pub mod transactions {
              pub const getHardwareInfo: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 0;
              pub const generateEcdsaP256KeyPair: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 1;
              pub const generateCertificateRequest: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 2;
              pub const getInterfaceVersion: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777214;
              pub const getInterfaceHash: binder::TransactionCode = binder::FIRST_CALL_TRANSACTION + 16777213;
            }
            pub type IRemotelyProvisionedComponentDefaultRef = Option<std::sync::Arc<dyn IRemotelyProvisionedComponentDefault>>;
            use lazy_static::lazy_static;
            lazy_static! {
              static ref DEFAULT_IMPL: std::sync::Mutex<IRemotelyProvisionedComponentDefaultRef> = std::sync::Mutex::new(None);
            }
            pub const STATUS_FAILED: i32 = 1;
            pub const STATUS_INVALID_MAC: i32 = 2;
            pub const STATUS_PRODUCTION_KEY_IN_TEST_REQUEST: i32 = 3;
            pub const STATUS_TEST_KEY_IN_PRODUCTION_REQUEST: i32 = 4;
            pub const STATUS_INVALID_EEK: i32 = 5;
            pub(crate) mod mangled { pub use super::IRemotelyProvisionedComponent as _7_android_8_hardware_8_security_7_keymint_29_IRemotelyProvisionedComponent; }
            pub const VERSION: i32 = 1;
            pub const HASH: &str = "976674616001f714f4a4df49ee45f548de828524";
            impl IRemotelyProvisionedComponent for BpRemotelyProvisionedComponent {
              fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_15_RpcHardwareInfo> {
                let _aidl_reply = self.binder.transact(transactions::getHardwareInfo, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IRemotelyProvisionedComponent>::getDefaultImpl() {
                    return _aidl_default_impl.getHardwareInfo();
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: crate::mangled::_7_android_8_hardware_8_security_7_keymint_15_RpcHardwareInfo = _aidl_reply.read()?;
                Ok(_aidl_return)
              }
              fn generateEcdsaP256KeyPair(&self, _arg_testMode: bool, _arg_macedPublicKey: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey) -> binder::public_api::Result<Vec<u8>> {
                let _aidl_reply = self.binder.transact(transactions::generateEcdsaP256KeyPair, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.write(&_arg_testMode)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IRemotelyProvisionedComponent>::getDefaultImpl() {
                    return _aidl_default_impl.generateEcdsaP256KeyPair(_arg_testMode, _arg_macedPublicKey);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: Vec<u8> = _aidl_reply.read()?;
                *_arg_macedPublicKey = _aidl_reply.read()?;
                Ok(_aidl_return)
              }
              fn generateCertificateRequest(&self, _arg_testMode: bool, _arg_keysToSign: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey], _arg_endpointEncryptionCertChain: &[u8], _arg_challenge: &[u8], _arg_deviceInfo: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo, _arg_protectedData: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData) -> binder::public_api::Result<Vec<u8>> {
                let _aidl_reply = self.binder.transact(transactions::generateCertificateRequest, binder::FLAG_PRIVATE_LOCAL, |_aidl_data| {
                  _aidl_data.write(&_arg_testMode)?;
                  _aidl_data.write(_arg_keysToSign)?;
                  _aidl_data.write(_arg_endpointEncryptionCertChain)?;
                  _aidl_data.write(_arg_challenge)?;
                  Ok(())
                });
                if let Err(binder::StatusCode::UNKNOWN_TRANSACTION) = _aidl_reply {
                  if let Some(_aidl_default_impl) = <Self as IRemotelyProvisionedComponent>::getDefaultImpl() {
                    return _aidl_default_impl.generateCertificateRequest(_arg_testMode, _arg_keysToSign, _arg_endpointEncryptionCertChain, _arg_challenge, _arg_deviceInfo, _arg_protectedData);
                  }
                }
                let _aidl_reply = _aidl_reply?;
                let _aidl_status: binder::Status = _aidl_reply.read()?;
                if !_aidl_status.is_ok() { return Err(_aidl_status); }
                let _aidl_return: Vec<u8> = _aidl_reply.read()?;
                *_arg_deviceInfo = _aidl_reply.read()?;
                *_arg_protectedData = _aidl_reply.read()?;
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
            impl IRemotelyProvisionedComponent for binder::Binder<BnRemotelyProvisionedComponent> {
              fn getHardwareInfo(&self) -> binder::public_api::Result<crate::mangled::_7_android_8_hardware_8_security_7_keymint_15_RpcHardwareInfo> { self.0.getHardwareInfo() }
              fn generateEcdsaP256KeyPair(&self, _arg_testMode: bool, _arg_macedPublicKey: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey) -> binder::public_api::Result<Vec<u8>> { self.0.generateEcdsaP256KeyPair(_arg_testMode, _arg_macedPublicKey) }
              fn generateCertificateRequest(&self, _arg_testMode: bool, _arg_keysToSign: &[crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey], _arg_endpointEncryptionCertChain: &[u8], _arg_challenge: &[u8], _arg_deviceInfo: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo, _arg_protectedData: &mut crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData) -> binder::public_api::Result<Vec<u8>> { self.0.generateCertificateRequest(_arg_testMode, _arg_keysToSign, _arg_endpointEncryptionCertChain, _arg_challenge, _arg_deviceInfo, _arg_protectedData) }
              fn getInterfaceVersion(&self) -> binder::public_api::Result<i32> { self.0.getInterfaceVersion() }
              fn getInterfaceHash(&self) -> binder::public_api::Result<String> { self.0.getInterfaceHash() }
            }
            fn on_transact(_aidl_service: &dyn IRemotelyProvisionedComponent, _aidl_code: binder::TransactionCode, _aidl_data: &binder::parcel::Parcel, _aidl_reply: &mut binder::parcel::Parcel) -> binder::Result<()> {
              match _aidl_code {
                transactions::getHardwareInfo => {
                  let _aidl_return = _aidl_service.getHardwareInfo();
                  match &_aidl_return {
                    Ok(_aidl_return) => {
                      _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                      _aidl_reply.write(_aidl_return)?;
                    }
                    Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                  }
                  Ok(())
                }
                transactions::generateEcdsaP256KeyPair => {
                  let _arg_testMode: bool = _aidl_data.read()?;
                  let mut _arg_macedPublicKey: crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey = Default::default();
                  let _aidl_return = _aidl_service.generateEcdsaP256KeyPair(_arg_testMode, &mut _arg_macedPublicKey);
                  match &_aidl_return {
                    Ok(_aidl_return) => {
                      _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                      _aidl_reply.write(_aidl_return)?;
                      _aidl_reply.write(&_arg_macedPublicKey)?;
                    }
                    Err(_aidl_status) => _aidl_reply.write(_aidl_status)?
                  }
                  Ok(())
                }
                transactions::generateCertificateRequest => {
                  let _arg_testMode: bool = _aidl_data.read()?;
                  let _arg_keysToSign: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey> = _aidl_data.read()?;
                  let _arg_endpointEncryptionCertChain: Vec<u8> = _aidl_data.read()?;
                  let _arg_challenge: Vec<u8> = _aidl_data.read()?;
                  let mut _arg_deviceInfo: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_DeviceInfo = Default::default();
                  let mut _arg_protectedData: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_ProtectedData = Default::default();
                  let _aidl_return = _aidl_service.generateCertificateRequest(_arg_testMode, &_arg_keysToSign, &_arg_endpointEncryptionCertChain, &_arg_challenge, &mut _arg_deviceInfo, &mut _arg_protectedData);
                  match &_aidl_return {
                    Ok(_aidl_return) => {
                      _aidl_reply.write(&binder::Status::from(binder::StatusCode::OK))?;
                      _aidl_reply.write(_aidl_return)?;
                      _aidl_reply.write(&_arg_deviceInfo)?;
                      _aidl_reply.write(&_arg_protectedData)?;
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
          pub mod KeyCharacteristics {
            #[derive(Debug)]
            pub struct KeyCharacteristics {
              pub securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel,
              pub authorizations: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter>,
            }
            pub(crate) mod mangled { pub use super::KeyCharacteristics as _7_android_8_hardware_8_security_7_keymint_18_KeyCharacteristics; }
            impl Default for KeyCharacteristics {
              fn default() -> Self {
                Self {
                  securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel::SOFTWARE,
                  authorizations: Default::default(),
                }
              }
            }
            impl binder::parcel::Serialize for KeyCharacteristics {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for KeyCharacteristics {}
            impl binder::parcel::SerializeOption for KeyCharacteristics {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.securityLevel)?;
                  subparcel.write(&this.authorizations)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for KeyCharacteristics {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for KeyCharacteristics {}
            impl binder::parcel::DeserializeOption for KeyCharacteristics {
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
                result.authorizations = parcel.read()?;
                unsafe {
                  parcel.set_data_position(start_pos + parcelable_size)?;
                }
                Ok(Some(result))
              }
            }
          }
          pub mod KeyCreationResult {
            #[derive(Debug)]
            pub struct KeyCreationResult {
              pub keyBlob: Vec<u8>,
              pub keyCharacteristics: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_18_KeyCharacteristics>,
              pub certificateChain: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_Certificate>,
            }
            pub(crate) mod mangled { pub use super::KeyCreationResult as _7_android_8_hardware_8_security_7_keymint_17_KeyCreationResult; }
            impl Default for KeyCreationResult {
              fn default() -> Self {
                Self {
                  keyBlob: Default::default(),
                  keyCharacteristics: Default::default(),
                  certificateChain: Default::default(),
                }
              }
            }
            impl binder::parcel::Serialize for KeyCreationResult {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for KeyCreationResult {}
            impl binder::parcel::SerializeOption for KeyCreationResult {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.keyBlob)?;
                  subparcel.write(&this.keyCharacteristics)?;
                  subparcel.write(&this.certificateChain)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for KeyCreationResult {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for KeyCreationResult {}
            impl binder::parcel::DeserializeOption for KeyCreationResult {
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
                result.keyBlob = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.keyCharacteristics = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.certificateChain = parcel.read()?;
                unsafe {
                  parcel.set_data_position(start_pos + parcelable_size)?;
                }
                Ok(Some(result))
              }
            }
          }
          pub mod KeyFormat {
            #![allow(non_upper_case_globals)]
            use binder::declare_binder_enum;
            declare_binder_enum! { KeyFormat : i32 {
              X509 = 0,
              PKCS8 = 1,
              RAW = 3,
            } }
            pub(crate) mod mangled { pub use super::KeyFormat as _7_android_8_hardware_8_security_7_keymint_9_KeyFormat; }
          }
          pub mod KeyMintHardwareInfo {
            #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
            pub struct KeyMintHardwareInfo {
              pub versionNumber: i32,
              pub securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel,
              pub keyMintName: String,
              pub keyMintAuthorName: String,
              pub timestampTokenRequired: bool,
            }
            pub(crate) mod mangled { pub use super::KeyMintHardwareInfo as _7_android_8_hardware_8_security_7_keymint_19_KeyMintHardwareInfo; }
            impl Default for KeyMintHardwareInfo {
              fn default() -> Self {
                Self {
                  versionNumber: 0,
                  securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel::SOFTWARE,
                  keyMintName: Default::default(),
                  keyMintAuthorName: Default::default(),
                  timestampTokenRequired: false,
                }
              }
            }
            impl binder::parcel::Serialize for KeyMintHardwareInfo {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for KeyMintHardwareInfo {}
            impl binder::parcel::SerializeOption for KeyMintHardwareInfo {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.versionNumber)?;
                  subparcel.write(&this.securityLevel)?;
                  subparcel.write(&this.keyMintName)?;
                  subparcel.write(&this.keyMintAuthorName)?;
                  subparcel.write(&this.timestampTokenRequired)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for KeyMintHardwareInfo {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for KeyMintHardwareInfo {}
            impl binder::parcel::DeserializeOption for KeyMintHardwareInfo {
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
                result.versionNumber = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.securityLevel = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.keyMintName = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.keyMintAuthorName = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.timestampTokenRequired = parcel.read()?;
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
              GENERATED = 0,
              DERIVED = 1,
              IMPORTED = 2,
              RESERVED = 3,
              SECURELY_IMPORTED = 4,
            } }
            pub(crate) mod mangled { pub use super::KeyOrigin as _7_android_8_hardware_8_security_7_keymint_9_KeyOrigin; }
          }
          pub mod KeyParameter {
            #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
            pub struct KeyParameter {
              pub tag: crate::mangled::_7_android_8_hardware_8_security_7_keymint_3_Tag,
              pub value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyParameterValue,
            }
            pub(crate) mod mangled { pub use super::KeyParameter as _7_android_8_hardware_8_security_7_keymint_12_KeyParameter; }
            impl Default for KeyParameter {
              fn default() -> Self {
                Self {
                  tag: crate::mangled::_7_android_8_hardware_8_security_7_keymint_3_Tag::INVALID,
                  value: Default::default(),
                }
              }
            }
            impl binder::parcel::Serialize for KeyParameter {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for KeyParameter {}
            impl binder::parcel::SerializeOption for KeyParameter {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.tag)?;
                  subparcel.write(&this.value)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for KeyParameter {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for KeyParameter {}
            impl binder::parcel::DeserializeOption for KeyParameter {
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
                result.tag = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.value = parcel.read()?;
                unsafe {
                  parcel.set_data_position(start_pos + parcelable_size)?;
                }
                Ok(Some(result))
              }
            }
          }
          pub mod KeyParameterValue {
            #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
            pub enum KeyParameterValue {
              Invalid(i32),
              Algorithm(crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_Algorithm),
              BlockMode(crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_BlockMode),
              PaddingMode(crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_PaddingMode),
              Digest(crate::mangled::_7_android_8_hardware_8_security_7_keymint_6_Digest),
              EcCurve(crate::mangled::_7_android_8_hardware_8_security_7_keymint_7_EcCurve),
              Origin(crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_KeyOrigin),
              KeyPurpose(crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_KeyPurpose),
              HardwareAuthenticatorType(crate::mangled::_7_android_8_hardware_8_security_7_keymint_25_HardwareAuthenticatorType),
              SecurityLevel(crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel),
              BoolValue(bool),
              Integer(i32),
              LongInteger(i64),
              DateTime(i64),
              Blob(Vec<u8>),
            }
            pub(crate) mod mangled { pub use super::KeyParameterValue as _7_android_8_hardware_8_security_7_keymint_17_KeyParameterValue; }
            impl Default for KeyParameterValue {
              fn default() -> Self {
                Self::Invalid(0)
              }
            }
            impl binder::parcel::Serialize for KeyParameterValue {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for KeyParameterValue {}
            impl binder::parcel::SerializeOption for KeyParameterValue {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                match this {
                  Self::Invalid(v) => {
                    parcel.write(&0i32)?;
                    parcel.write(v)
                  }
                  Self::Algorithm(v) => {
                    parcel.write(&1i32)?;
                    parcel.write(v)
                  }
                  Self::BlockMode(v) => {
                    parcel.write(&2i32)?;
                    parcel.write(v)
                  }
                  Self::PaddingMode(v) => {
                    parcel.write(&3i32)?;
                    parcel.write(v)
                  }
                  Self::Digest(v) => {
                    parcel.write(&4i32)?;
                    parcel.write(v)
                  }
                  Self::EcCurve(v) => {
                    parcel.write(&5i32)?;
                    parcel.write(v)
                  }
                  Self::Origin(v) => {
                    parcel.write(&6i32)?;
                    parcel.write(v)
                  }
                  Self::KeyPurpose(v) => {
                    parcel.write(&7i32)?;
                    parcel.write(v)
                  }
                  Self::HardwareAuthenticatorType(v) => {
                    parcel.write(&8i32)?;
                    parcel.write(v)
                  }
                  Self::SecurityLevel(v) => {
                    parcel.write(&9i32)?;
                    parcel.write(v)
                  }
                  Self::BoolValue(v) => {
                    parcel.write(&10i32)?;
                    parcel.write(v)
                  }
                  Self::Integer(v) => {
                    parcel.write(&11i32)?;
                    parcel.write(v)
                  }
                  Self::LongInteger(v) => {
                    parcel.write(&12i32)?;
                    parcel.write(v)
                  }
                  Self::DateTime(v) => {
                    parcel.write(&13i32)?;
                    parcel.write(v)
                  }
                  Self::Blob(v) => {
                    parcel.write(&14i32)?;
                    parcel.write(v)
                  }
                }
              }
            }
            impl binder::parcel::Deserialize for KeyParameterValue {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for KeyParameterValue {}
            impl binder::parcel::DeserializeOption for KeyParameterValue {
              fn deserialize_option(parcel: &binder::parcel::Parcel) -> binder::Result<Option<Self>> {
                let status: i32 = parcel.read()?;
                if status == 0 { return Ok(None); }
                let tag: i32 = parcel.read()?;
                match tag {
                  0 => {
                    let value: i32 = parcel.read()?;
                    Ok(Some(Self::Invalid(value)))
                  }
                  1 => {
                    let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_Algorithm = parcel.read()?;
                    Ok(Some(Self::Algorithm(value)))
                  }
                  2 => {
                    let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_BlockMode = parcel.read()?;
                    Ok(Some(Self::BlockMode(value)))
                  }
                  3 => {
                    let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_PaddingMode = parcel.read()?;
                    Ok(Some(Self::PaddingMode(value)))
                  }
                  4 => {
                    let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_6_Digest = parcel.read()?;
                    Ok(Some(Self::Digest(value)))
                  }
                  5 => {
                    let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_7_EcCurve = parcel.read()?;
                    Ok(Some(Self::EcCurve(value)))
                  }
                  6 => {
                    let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_KeyOrigin = parcel.read()?;
                    Ok(Some(Self::Origin(value)))
                  }
                  7 => {
                    let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_KeyPurpose = parcel.read()?;
                    Ok(Some(Self::KeyPurpose(value)))
                  }
                  8 => {
                    let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_25_HardwareAuthenticatorType = parcel.read()?;
                    Ok(Some(Self::HardwareAuthenticatorType(value)))
                  }
                  9 => {
                    let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel = parcel.read()?;
                    Ok(Some(Self::SecurityLevel(value)))
                  }
                  10 => {
                    let value: bool = parcel.read()?;
                    Ok(Some(Self::BoolValue(value)))
                  }
                  11 => {
                    let value: i32 = parcel.read()?;
                    Ok(Some(Self::Integer(value)))
                  }
                  12 => {
                    let value: i64 = parcel.read()?;
                    Ok(Some(Self::LongInteger(value)))
                  }
                  13 => {
                    let value: i64 = parcel.read()?;
                    Ok(Some(Self::DateTime(value)))
                  }
                  14 => {
                    let value: Vec<u8> = parcel.read()?;
                    Ok(Some(Self::Blob(value)))
                  }
                  _ => {
                    Err(binder::StatusCode::BAD_VALUE)
                  }
                }
              }
            }
          }
          pub mod KeyPurpose {
            #![allow(non_upper_case_globals)]
            use binder::declare_binder_enum;
            declare_binder_enum! { KeyPurpose : i32 {
              ENCRYPT = 0,
              DECRYPT = 1,
              SIGN = 2,
              VERIFY = 3,
              WRAP_KEY = 5,
              AGREE_KEY = 6,
              ATTEST_KEY = 7,
            } }
            pub(crate) mod mangled { pub use super::KeyPurpose as _7_android_8_hardware_8_security_7_keymint_10_KeyPurpose; }
          }
          pub mod MacedPublicKey {
            #[derive(Debug)]
            pub struct MacedPublicKey {
              pub macedKey: Vec<u8>,
            }
            pub(crate) mod mangled { pub use super::MacedPublicKey as _7_android_8_hardware_8_security_7_keymint_14_MacedPublicKey; }
            impl Default for MacedPublicKey {
              fn default() -> Self {
                Self {
                  macedKey: Default::default(),
                }
              }
            }
            impl binder::parcel::Serialize for MacedPublicKey {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for MacedPublicKey {}
            impl binder::parcel::SerializeOption for MacedPublicKey {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.macedKey)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for MacedPublicKey {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for MacedPublicKey {}
            impl binder::parcel::DeserializeOption for MacedPublicKey {
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
                result.macedKey = parcel.read()?;
                unsafe {
                  parcel.set_data_position(start_pos + parcelable_size)?;
                }
                Ok(Some(result))
              }
            }
          }
          pub mod PaddingMode {
            #![allow(non_upper_case_globals)]
            use binder::declare_binder_enum;
            declare_binder_enum! { PaddingMode : i32 {
              NONE = 1,
              RSA_OAEP = 2,
              RSA_PSS = 3,
              RSA_PKCS1_1_5_ENCRYPT = 4,
              RSA_PKCS1_1_5_SIGN = 5,
              PKCS7 = 64,
            } }
            pub(crate) mod mangled { pub use super::PaddingMode as _7_android_8_hardware_8_security_7_keymint_11_PaddingMode; }
          }
          pub mod ProtectedData {
            #[derive(Debug)]
            pub struct ProtectedData {
              pub protectedData: Vec<u8>,
            }
            pub(crate) mod mangled { pub use super::ProtectedData as _7_android_8_hardware_8_security_7_keymint_13_ProtectedData; }
            impl Default for ProtectedData {
              fn default() -> Self {
                Self {
                  protectedData: Default::default(),
                }
              }
            }
            impl binder::parcel::Serialize for ProtectedData {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for ProtectedData {}
            impl binder::parcel::SerializeOption for ProtectedData {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.protectedData)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for ProtectedData {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for ProtectedData {}
            impl binder::parcel::DeserializeOption for ProtectedData {
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
                result.protectedData = parcel.read()?;
                unsafe {
                  parcel.set_data_position(start_pos + parcelable_size)?;
                }
                Ok(Some(result))
              }
            }
          }
          pub mod RpcHardwareInfo {
            #[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
            pub struct RpcHardwareInfo {
              pub versionNumber: i32,
              pub rpcAuthorName: String,
              pub supportedEekCurve: i32,
            }
            pub const CURVE_NONE: i32 = 0;
            pub const CURVE_P256: i32 = 1;
            pub const CURVE_25519: i32 = 2;
            pub(crate) mod mangled { pub use super::RpcHardwareInfo as _7_android_8_hardware_8_security_7_keymint_15_RpcHardwareInfo; }
            impl Default for RpcHardwareInfo {
              fn default() -> Self {
                Self {
                  versionNumber: 0,
                  rpcAuthorName: Default::default(),
                  supportedEekCurve: 0,
                }
              }
            }
            impl binder::parcel::Serialize for RpcHardwareInfo {
              fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
              }
            }
            impl binder::parcel::SerializeArray for RpcHardwareInfo {}
            impl binder::parcel::SerializeOption for RpcHardwareInfo {
              fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
                let this = if let Some(this) = this {
                  parcel.write(&1i32)?;
                  this
                } else {
                  return parcel.write(&0i32);
                };
                parcel.sized_write(|subparcel| {
                  subparcel.write(&this.versionNumber)?;
                  subparcel.write(&this.rpcAuthorName)?;
                  subparcel.write(&this.supportedEekCurve)?;
                  Ok(())
                })
              }
            }
            impl binder::parcel::Deserialize for RpcHardwareInfo {
              fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
                <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
                   .transpose()
                   .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
              }
            }
            impl binder::parcel::DeserializeArray for RpcHardwareInfo {}
            impl binder::parcel::DeserializeOption for RpcHardwareInfo {
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
                result.versionNumber = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.rpcAuthorName = parcel.read()?;
                if (parcel.get_data_position() - start_pos) == parcelable_size {
                  return Ok(Some(result));
                }
                result.supportedEekCurve = parcel.read()?;
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
              SOFTWARE = 0,
              TRUSTED_ENVIRONMENT = 1,
              STRONGBOX = 2,
              KEYSTORE = 100,
            } }
            pub(crate) mod mangled { pub use super::SecurityLevel as _7_android_8_hardware_8_security_7_keymint_13_SecurityLevel; }
          }
          pub mod Tag {
            #![allow(non_upper_case_globals)]
            use binder::declare_binder_enum;
            declare_binder_enum! { Tag : i32 {
              INVALID = 0,
              PURPOSE = 536870913,
              ALGORITHM = 268435458,
              KEY_SIZE = 805306371,
              BLOCK_MODE = 536870916,
              DIGEST = 536870917,
              PADDING = 536870918,
              CALLER_NONCE = 1879048199,
              MIN_MAC_LENGTH = 805306376,
              EC_CURVE = 268435466,
              RSA_PUBLIC_EXPONENT = 1342177480,
              INCLUDE_UNIQUE_ID = 1879048394,
              RSA_OAEP_MGF_DIGEST = 536871115,
              BOOTLOADER_ONLY = 1879048494,
              ROLLBACK_RESISTANCE = 1879048495,
              HARDWARE_TYPE = 268435760,
              EARLY_BOOT_ONLY = 1879048497,
              ACTIVE_DATETIME = 1610613136,
              ORIGINATION_EXPIRE_DATETIME = 1610613137,
              USAGE_EXPIRE_DATETIME = 1610613138,
              MIN_SECONDS_BETWEEN_OPS = 805306771,
              MAX_USES_PER_BOOT = 805306772,
              USAGE_COUNT_LIMIT = 805306773,
              USER_ID = 805306869,
              USER_SECURE_ID = -1610612234,
              NO_AUTH_REQUIRED = 1879048695,
              USER_AUTH_TYPE = 268435960,
              AUTH_TIMEOUT = 805306873,
              ALLOW_WHILE_ON_BODY = 1879048698,
              TRUSTED_USER_PRESENCE_REQUIRED = 1879048699,
              TRUSTED_CONFIRMATION_REQUIRED = 1879048700,
              UNLOCKED_DEVICE_REQUIRED = 1879048701,
              APPLICATION_ID = -1879047591,
              APPLICATION_DATA = -1879047492,
              CREATION_DATETIME = 1610613437,
              ORIGIN = 268436158,
              ROOT_OF_TRUST = -1879047488,
              OS_VERSION = 805307073,
              OS_PATCHLEVEL = 805307074,
              UNIQUE_ID = -1879047485,
              ATTESTATION_CHALLENGE = -1879047484,
              ATTESTATION_APPLICATION_ID = -1879047483,
              ATTESTATION_ID_BRAND = -1879047482,
              ATTESTATION_ID_DEVICE = -1879047481,
              ATTESTATION_ID_PRODUCT = -1879047480,
              ATTESTATION_ID_SERIAL = -1879047479,
              ATTESTATION_ID_IMEI = -1879047478,
              ATTESTATION_ID_MEID = -1879047477,
              ATTESTATION_ID_MANUFACTURER = -1879047476,
              ATTESTATION_ID_MODEL = -1879047475,
              VENDOR_PATCHLEVEL = 805307086,
              BOOT_PATCHLEVEL = 805307087,
              DEVICE_UNIQUE_ATTESTATION = 1879048912,
              IDENTITY_CREDENTIAL_KEY = 1879048913,
              STORAGE_KEY = 1879048914,
              ASSOCIATED_DATA = -1879047192,
              NONCE = -1879047191,
              MAC_LENGTH = 805307371,
              RESET_SINCE_ID_ROTATION = 1879049196,
              CONFIRMATION_TOKEN = -1879047187,
              CERTIFICATE_SERIAL = -2147482642,
              CERTIFICATE_SUBJECT = -1879047185,
              CERTIFICATE_NOT_BEFORE = 1610613744,
              CERTIFICATE_NOT_AFTER = 1610613745,
              MAX_BOOT_LEVEL = 805307378,
            } }
            pub(crate) mod mangled { pub use super::Tag as _7_android_8_hardware_8_security_7_keymint_3_Tag; }
          }
          pub mod TagType {
            #![allow(non_upper_case_globals)]
            use binder::declare_binder_enum;
            declare_binder_enum! { TagType : i32 {
              INVALID = 0,
              ENUM = 268435456,
              ENUM_REP = 536870912,
              UINT = 805306368,
              UINT_REP = 1073741824,
              ULONG = 1342177280,
              DATE = 1610612736,
              BOOL = 1879048192,
              BIGNUM = -2147483648,
              BYTES = -1879048192,
              ULONG_REP = -1610612736,
            } }
            pub(crate) mod mangled { pub use super::TagType as _7_android_8_hardware_8_security_7_keymint_7_TagType; }
          }
        }
      }
    }
  }
}
pub mod mangled {
  pub use super::aidl::android::hardware::security::keymint::Algorithm::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::AttestationKey::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::BeginResult::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::BlockMode::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::Certificate::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::DeviceInfo::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::Digest::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::EcCurve::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::ErrorCode::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::HardwareAuthToken::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::HardwareAuthenticatorType::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::IKeyMintDevice::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::IKeyMintOperation::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::IRemotelyProvisionedComponent::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::KeyCharacteristics::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::KeyCreationResult::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::KeyFormat::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::KeyMintHardwareInfo::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::KeyOrigin::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::KeyParameter::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::KeyParameterValue::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::KeyPurpose::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::MacedPublicKey::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::PaddingMode::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::ProtectedData::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::RpcHardwareInfo::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::SecurityLevel::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::Tag::mangled::*;
  pub use super::aidl::android::hardware::security::keymint::TagType::mangled::*;
  pub(crate) use android_hardware_security_secureclock::mangled::*;
}
