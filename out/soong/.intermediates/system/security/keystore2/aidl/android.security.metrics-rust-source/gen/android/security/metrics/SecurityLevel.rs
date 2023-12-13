#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { SecurityLevel : i32 {
  SECURITY_LEVEL_UNSPECIFIED = 0,
  SECURITY_LEVEL_SOFTWARE = 1,
  SECURITY_LEVEL_TRUSTED_ENVIRONMENT = 2,
  SECURITY_LEVEL_STRONGBOX = 3,
  SECURITY_LEVEL_KEYSTORE = 4,
} }
pub(crate) mod mangled { pub use super::SecurityLevel as _7_android_8_security_7_metrics_13_SecurityLevel; }
