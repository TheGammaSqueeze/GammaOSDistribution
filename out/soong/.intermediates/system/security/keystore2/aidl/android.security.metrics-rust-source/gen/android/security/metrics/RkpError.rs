#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { RkpError : i32 {
  RKP_ERROR_UNSPECIFIED = 0,
  OUT_OF_KEYS = 1,
  FALL_BACK_DURING_HYBRID = 2,
} }
pub(crate) mod mangled { pub use super::RkpError as _7_android_8_security_7_metrics_8_RkpError; }
