#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { ResponseCode : i32 {
  LOCKED = 2,
  UNINITIALIZED = 3,
  SYSTEM_ERROR = 4,
  PERMISSION_DENIED = 6,
  KEY_NOT_FOUND = 7,
  VALUE_CORRUPTED = 8,
  KEY_PERMANENTLY_INVALIDATED = 17,
  BACKEND_BUSY = 18,
  OPERATION_BUSY = 19,
  INVALID_ARGUMENT = 20,
  TOO_MUCH_DATA = 21,
  OUT_OF_KEYS = 22,
} }
pub(crate) mod mangled { pub use super::ResponseCode as _7_android_6_system_9_keystore2_12_ResponseCode; }
