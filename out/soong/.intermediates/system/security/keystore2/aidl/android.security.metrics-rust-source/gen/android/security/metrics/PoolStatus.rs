#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { PoolStatus : i32 {
  EXPIRING = 1,
  UNASSIGNED = 2,
  ATTESTED = 3,
  TOTAL = 4,
} }
pub(crate) mod mangled { pub use super::PoolStatus as _7_android_8_security_7_metrics_10_PoolStatus; }
