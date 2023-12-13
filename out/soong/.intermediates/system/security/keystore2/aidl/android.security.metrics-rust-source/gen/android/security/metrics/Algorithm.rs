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
