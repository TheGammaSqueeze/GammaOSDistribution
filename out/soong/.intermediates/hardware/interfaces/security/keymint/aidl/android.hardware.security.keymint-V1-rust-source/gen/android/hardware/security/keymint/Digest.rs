#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { Digest : i32 {
  NONE = 0,
  MD5 = 1,
  SHA1 = 2,
  SHA_2_224 = 3,
  SHA_2_256 = 4,
  SHA_2_384 = 5,
  SHA_2_512 = 6,
} }
pub(crate) mod mangled { pub use super::Digest as _7_android_8_hardware_8_security_7_keymint_6_Digest; }
