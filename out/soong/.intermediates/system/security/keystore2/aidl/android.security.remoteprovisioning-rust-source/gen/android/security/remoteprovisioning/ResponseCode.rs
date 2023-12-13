#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { ResponseCode : i32 {
  NO_UNSIGNED_KEYS = 1,
  PERMISSION_DENIED = 2,
  SYSTEM_ERROR = 3,
} }
pub(crate) mod mangled { pub use super::ResponseCode as _7_android_8_security_18_remoteprovisioning_12_ResponseCode; }
