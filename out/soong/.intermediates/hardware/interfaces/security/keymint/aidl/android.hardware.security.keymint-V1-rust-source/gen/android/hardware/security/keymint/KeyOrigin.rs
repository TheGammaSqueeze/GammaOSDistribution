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
