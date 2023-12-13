#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { EcCurve : i32 {
  EC_CURVE_UNSPECIFIED = 0,
  P_224 = 1,
  P_256 = 2,
  P_384 = 3,
  P_521 = 4,
} }
pub(crate) mod mangled { pub use super::EcCurve as _7_android_8_security_7_metrics_7_EcCurve; }
