#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { ResponseCode : i32 {
  NO_AUTH_TOKEN_FOUND = 1,
  AUTH_TOKEN_EXPIRED = 2,
  SYSTEM_ERROR = 4,
  PERMISSION_DENIED = 6,
  KEY_NOT_FOUND = 7,
  VALUE_CORRUPTED = 8,
  INVALID_ARGUMENT = 20,
} }
pub(crate) mod mangled { pub use super::ResponseCode as _7_android_8_security_13_authorization_12_ResponseCode; }
