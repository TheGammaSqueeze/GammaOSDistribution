#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { UserState : i32 {
  UNINITIALIZED = 0,
  LSKF_UNLOCKED = 1,
  LSKF_LOCKED = 2,
} }
pub(crate) mod mangled { pub use super::UserState as _7_android_8_security_11_maintenance_9_UserState; }
