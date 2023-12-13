#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { Domain : i32 {
  APP = 0,
  GRANT = 1,
  SELINUX = 2,
  BLOB = 3,
  KEY_ID = 4,
} }
pub(crate) mod mangled { pub use super::Domain as _7_android_6_system_9_keystore2_6_Domain; }
