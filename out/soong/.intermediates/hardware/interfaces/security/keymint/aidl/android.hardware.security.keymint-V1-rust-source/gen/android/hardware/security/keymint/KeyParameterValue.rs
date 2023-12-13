#[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub enum KeyParameterValue {
  Invalid(i32),
  Algorithm(crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_Algorithm),
  BlockMode(crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_BlockMode),
  PaddingMode(crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_PaddingMode),
  Digest(crate::mangled::_7_android_8_hardware_8_security_7_keymint_6_Digest),
  EcCurve(crate::mangled::_7_android_8_hardware_8_security_7_keymint_7_EcCurve),
  Origin(crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_KeyOrigin),
  KeyPurpose(crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_KeyPurpose),
  HardwareAuthenticatorType(crate::mangled::_7_android_8_hardware_8_security_7_keymint_25_HardwareAuthenticatorType),
  SecurityLevel(crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel),
  BoolValue(bool),
  Integer(i32),
  LongInteger(i64),
  DateTime(i64),
  Blob(Vec<u8>),
}
pub(crate) mod mangled { pub use super::KeyParameterValue as _7_android_8_hardware_8_security_7_keymint_17_KeyParameterValue; }
impl Default for KeyParameterValue {
  fn default() -> Self {
    Self::Invalid(0)
  }
}
impl binder::parcel::Serialize for KeyParameterValue {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for KeyParameterValue {}
impl binder::parcel::SerializeOption for KeyParameterValue {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    match this {
      Self::Invalid(v) => {
        parcel.write(&0i32)?;
        parcel.write(v)
      }
      Self::Algorithm(v) => {
        parcel.write(&1i32)?;
        parcel.write(v)
      }
      Self::BlockMode(v) => {
        parcel.write(&2i32)?;
        parcel.write(v)
      }
      Self::PaddingMode(v) => {
        parcel.write(&3i32)?;
        parcel.write(v)
      }
      Self::Digest(v) => {
        parcel.write(&4i32)?;
        parcel.write(v)
      }
      Self::EcCurve(v) => {
        parcel.write(&5i32)?;
        parcel.write(v)
      }
      Self::Origin(v) => {
        parcel.write(&6i32)?;
        parcel.write(v)
      }
      Self::KeyPurpose(v) => {
        parcel.write(&7i32)?;
        parcel.write(v)
      }
      Self::HardwareAuthenticatorType(v) => {
        parcel.write(&8i32)?;
        parcel.write(v)
      }
      Self::SecurityLevel(v) => {
        parcel.write(&9i32)?;
        parcel.write(v)
      }
      Self::BoolValue(v) => {
        parcel.write(&10i32)?;
        parcel.write(v)
      }
      Self::Integer(v) => {
        parcel.write(&11i32)?;
        parcel.write(v)
      }
      Self::LongInteger(v) => {
        parcel.write(&12i32)?;
        parcel.write(v)
      }
      Self::DateTime(v) => {
        parcel.write(&13i32)?;
        parcel.write(v)
      }
      Self::Blob(v) => {
        parcel.write(&14i32)?;
        parcel.write(v)
      }
    }
  }
}
impl binder::parcel::Deserialize for KeyParameterValue {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for KeyParameterValue {}
impl binder::parcel::DeserializeOption for KeyParameterValue {
  fn deserialize_option(parcel: &binder::parcel::Parcel) -> binder::Result<Option<Self>> {
    let status: i32 = parcel.read()?;
    if status == 0 { return Ok(None); }
    let tag: i32 = parcel.read()?;
    match tag {
      0 => {
        let value: i32 = parcel.read()?;
        Ok(Some(Self::Invalid(value)))
      }
      1 => {
        let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_Algorithm = parcel.read()?;
        Ok(Some(Self::Algorithm(value)))
      }
      2 => {
        let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_BlockMode = parcel.read()?;
        Ok(Some(Self::BlockMode(value)))
      }
      3 => {
        let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_11_PaddingMode = parcel.read()?;
        Ok(Some(Self::PaddingMode(value)))
      }
      4 => {
        let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_6_Digest = parcel.read()?;
        Ok(Some(Self::Digest(value)))
      }
      5 => {
        let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_7_EcCurve = parcel.read()?;
        Ok(Some(Self::EcCurve(value)))
      }
      6 => {
        let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_9_KeyOrigin = parcel.read()?;
        Ok(Some(Self::Origin(value)))
      }
      7 => {
        let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_10_KeyPurpose = parcel.read()?;
        Ok(Some(Self::KeyPurpose(value)))
      }
      8 => {
        let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_25_HardwareAuthenticatorType = parcel.read()?;
        Ok(Some(Self::HardwareAuthenticatorType(value)))
      }
      9 => {
        let value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel = parcel.read()?;
        Ok(Some(Self::SecurityLevel(value)))
      }
      10 => {
        let value: bool = parcel.read()?;
        Ok(Some(Self::BoolValue(value)))
      }
      11 => {
        let value: i32 = parcel.read()?;
        Ok(Some(Self::Integer(value)))
      }
      12 => {
        let value: i64 = parcel.read()?;
        Ok(Some(Self::LongInteger(value)))
      }
      13 => {
        let value: i64 = parcel.read()?;
        Ok(Some(Self::DateTime(value)))
      }
      14 => {
        let value: Vec<u8> = parcel.read()?;
        Ok(Some(Self::Blob(value)))
      }
      _ => {
        Err(binder::StatusCode::BAD_VALUE)
      }
    }
  }
}
