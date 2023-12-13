#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { ResponseCode : i32 {
  OK = 0,
  CANCELLED = 1,
  ABORTED = 2,
  OPERATION_PENDING = 3,
  IGNORED = 4,
  SYSTEM_ERROR = 5,
  UNIMPLEMENTED = 6,
  PERMISSION_DENIED = 30,
} }
pub(crate) mod mangled { pub use super::ResponseCode as _7_android_8_security_3_apc_12_ResponseCode; }
