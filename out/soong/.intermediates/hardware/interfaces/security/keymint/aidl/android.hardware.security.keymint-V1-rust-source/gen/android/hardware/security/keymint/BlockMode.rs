#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { BlockMode : i32 {
  ECB = 1,
  CBC = 2,
  CTR = 3,
  GCM = 32,
} }
pub(crate) mod mangled { pub use super::BlockMode as _7_android_8_hardware_8_security_7_keymint_9_BlockMode; }
