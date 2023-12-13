#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { HardwareAuthenticatorType : i32 {
  NONE = 0,
  PASSWORD = 1,
  FINGERPRINT = 2,
  ANY = -1,
} }
pub(crate) mod mangled { pub use super::HardwareAuthenticatorType as _7_android_8_hardware_8_security_7_keymint_25_HardwareAuthenticatorType; }
