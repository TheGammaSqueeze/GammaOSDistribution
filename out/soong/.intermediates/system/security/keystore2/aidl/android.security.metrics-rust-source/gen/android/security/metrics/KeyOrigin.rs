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
