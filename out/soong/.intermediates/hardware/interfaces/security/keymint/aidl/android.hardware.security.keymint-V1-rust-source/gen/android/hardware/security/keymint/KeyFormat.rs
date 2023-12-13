#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { KeyFormat : i32 {
  X509 = 0,
  PKCS8 = 1,
  RAW = 3,
} }
pub(crate) mod mangled { pub use super::KeyFormat as _7_android_8_hardware_8_security_7_keymint_9_KeyFormat; }
