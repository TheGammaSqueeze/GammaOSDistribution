#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { AtomID : i32 {
  STORAGE_STATS = 10103,
  RKP_POOL_STATS = 10104,
  KEY_CREATION_WITH_GENERAL_INFO = 10118,
  KEY_CREATION_WITH_AUTH_INFO = 10119,
  KEY_CREATION_WITH_PURPOSE_AND_MODES_INFO = 10120,
  KEYSTORE2_ATOM_WITH_OVERFLOW = 10121,
  KEY_OPERATION_WITH_PURPOSE_AND_MODES_INFO = 10122,
  KEY_OPERATION_WITH_GENERAL_INFO = 10123,
  RKP_ERROR_STATS = 10124,
  CRASH_STATS = 10125,
} }
pub(crate) mod mangled { pub use super::AtomID as _7_android_8_security_7_metrics_6_AtomID; }
