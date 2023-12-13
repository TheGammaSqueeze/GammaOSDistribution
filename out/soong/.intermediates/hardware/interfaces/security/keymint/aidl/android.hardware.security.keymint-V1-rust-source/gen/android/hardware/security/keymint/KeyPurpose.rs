#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { KeyPurpose : i32 {
  ENCRYPT = 0,
  DECRYPT = 1,
  SIGN = 2,
  VERIFY = 3,
  WRAP_KEY = 5,
  AGREE_KEY = 6,
  ATTEST_KEY = 7,
} }
pub(crate) mod mangled { pub use super::KeyPurpose as _7_android_8_hardware_8_security_7_keymint_10_KeyPurpose; }
