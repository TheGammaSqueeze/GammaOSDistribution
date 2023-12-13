#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { EcCurve : i32 {
  P_224 = 0,
  P_256 = 1,
  P_384 = 2,
  P_521 = 3,
} }
pub(crate) mod mangled { pub use super::EcCurve as _7_android_8_hardware_8_security_7_keymint_7_EcCurve; }
