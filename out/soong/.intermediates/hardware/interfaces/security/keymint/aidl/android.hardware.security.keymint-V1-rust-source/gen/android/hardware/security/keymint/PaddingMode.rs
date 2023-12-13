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
