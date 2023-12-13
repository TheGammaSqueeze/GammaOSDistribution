#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { Purpose : i32 {
  KEY_PURPOSE_UNSPECIFIED = 0,
  ENCRYPT = 1,
  DECRYPT = 2,
  SIGN = 3,
  VERIFY = 4,
  WRAP_KEY = 6,
  AGREE_KEY = 7,
  ATTEST_KEY = 8,
} }
pub(crate) mod mangled { pub use super::Purpose as _7_android_8_security_7_metrics_7_Purpose; }
