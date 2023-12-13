#![allow(non_upper_case_globals)]
use binder::declare_binder_enum;
declare_binder_enum! { TagType : i32 {
  INVALID = 0,
  ENUM = 268435456,
  ENUM_REP = 536870912,
  UINT = 805306368,
  UINT_REP = 1073741824,
  ULONG = 1342177280,
  DATE = 1610612736,
  BOOL = 1879048192,
  BIGNUM = -2147483648,
  BYTES = -1879048192,
  ULONG_REP = -1610612736,
} }
pub(crate) mod mangled { pub use super::TagType as _7_android_8_hardware_8_security_7_keymint_7_TagType; }
