#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { KeyPermission : i32 {
  NONE = 0,
  DELETE = 1,
  GEN_UNIQUE_ID = 2,
  GET_INFO = 4,
  GRANT = 8,
  MANAGE_BLOB = 16,
  REBIND = 32,
  REQ_FORCED_OP = 64,
  UPDATE = 128,
  USE = 256,
  USE_DEV_ID = 512,
  USE_NO_LSKF_BINDING = 1024,
  CONVERT_STORAGE_KEY_TO_EPHEMERAL = 2048,
} }
pub(crate) mod mangled { pub use super::KeyPermission as _7_android_6_system_9_keystore2_13_KeyPermission; }
