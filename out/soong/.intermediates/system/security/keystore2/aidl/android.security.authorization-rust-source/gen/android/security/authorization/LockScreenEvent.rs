#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { LockScreenEvent : i32 {
  UNLOCK = 0,
  LOCK = 1,
} }
pub(crate) mod mangled { pub use super::LockScreenEvent as _7_android_8_security_13_authorization_15_LockScreenEvent; }
