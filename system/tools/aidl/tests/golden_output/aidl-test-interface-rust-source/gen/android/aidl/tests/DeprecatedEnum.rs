#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { DeprecatedEnum : i32 {
  A = 0,
  B = 1,
  C = 2,
} }
pub(crate) mod mangled { pub use super::DeprecatedEnum as _7_android_4_aidl_5_tests_14_DeprecatedEnum; }
