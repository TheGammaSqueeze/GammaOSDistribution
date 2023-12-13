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
