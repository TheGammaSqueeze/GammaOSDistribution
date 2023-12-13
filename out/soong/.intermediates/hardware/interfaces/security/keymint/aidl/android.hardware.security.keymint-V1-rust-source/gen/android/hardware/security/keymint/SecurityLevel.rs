#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { SecurityLevel : i32 {
  SOFTWARE = 0,
  TRUSTED_ENVIRONMENT = 1,
  STRONGBOX = 2,
  KEYSTORE = 100,
} }
pub(crate) mod mangled { pub use super::SecurityLevel as _7_android_8_hardware_8_security_7_keymint_13_SecurityLevel; }
