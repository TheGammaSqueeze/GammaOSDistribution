#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { Storage : i32 {
  STORAGE_UNSPECIFIED = 0,
  KEY_ENTRY = 1,
  KEY_ENTRY_ID_INDEX = 2,
  KEY_ENTRY_DOMAIN_NAMESPACE_INDEX = 3,
  BLOB_ENTRY = 4,
  BLOB_ENTRY_KEY_ENTRY_ID_INDEX = 5,
  KEY_PARAMETER = 6,
  KEY_PARAMETER_KEY_ENTRY_ID_INDEX = 7,
  KEY_METADATA = 8,
  KEY_METADATA_KEY_ENTRY_ID_INDEX = 9,
  GRANT = 10,
  AUTH_TOKEN = 11,
  BLOB_METADATA = 12,
  BLOB_METADATA_BLOB_ENTRY_ID_INDEX = 13,
  METADATA = 14,
  DATABASE = 15,
  LEGACY_STORAGE = 16,
} }
pub(crate) mod mangled { pub use super::Storage as _7_android_8_security_7_metrics_7_Storage; }
