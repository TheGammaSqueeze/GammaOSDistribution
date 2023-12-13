#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { Outcome : i32 {
  OUTCOME_UNSPECIFIED = 0,
  DROPPED = 1,
  SUCCESS = 2,
  ABORT = 3,
  PRUNED = 4,
  ERROR = 5,
} }
pub(crate) mod mangled { pub use super::Outcome as _7_android_8_security_7_metrics_7_Outcome; }
