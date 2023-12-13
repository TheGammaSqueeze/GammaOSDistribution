#[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub enum KeystoreAtomPayload {
  StorageStats(crate::mangled::_7_android_8_security_7_metrics_12_StorageStats),
  RkpPoolStats(crate::mangled::_7_android_8_security_7_metrics_12_RkpPoolStats),
  KeyCreationWithGeneralInfo(crate::mangled::_7_android_8_security_7_metrics_26_KeyCreationWithGeneralInfo),
  KeyCreationWithAuthInfo(crate::mangled::_7_android_8_security_7_metrics_23_KeyCreationWithAuthInfo),
  KeyCreationWithPurposeAndModesInfo(crate::mangled::_7_android_8_security_7_metrics_34_KeyCreationWithPurposeAndModesInfo),
  Keystore2AtomWithOverflow(crate::mangled::_7_android_8_security_7_metrics_25_Keystore2AtomWithOverflow),
  KeyOperationWithPurposeAndModesInfo(crate::mangled::_7_android_8_security_7_metrics_35_KeyOperationWithPurposeAndModesInfo),
  KeyOperationWithGeneralInfo(crate::mangled::_7_android_8_security_7_metrics_27_KeyOperationWithGeneralInfo),
  RkpErrorStats(crate::mangled::_7_android_8_security_7_metrics_13_RkpErrorStats),
  CrashStats(crate::mangled::_7_android_8_security_7_metrics_10_CrashStats),
}
pub(crate) mod mangled { pub use super::KeystoreAtomPayload as _7_android_8_security_7_metrics_19_KeystoreAtomPayload; }
impl Default for KeystoreAtomPayload {
  fn default() -> Self {
    Self::StorageStats(Default::default())
  }
}
impl binder::parcel::Serialize for KeystoreAtomPayload {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for KeystoreAtomPayload {}
impl binder::parcel::SerializeOption for KeystoreAtomPayload {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    match this {
      Self::StorageStats(v) => {
        parcel.write(&0i32)?;
        parcel.write(v)
      }
      Self::RkpPoolStats(v) => {
        parcel.write(&1i32)?;
        parcel.write(v)
      }
      Self::KeyCreationWithGeneralInfo(v) => {
        parcel.write(&2i32)?;
        parcel.write(v)
      }
      Self::KeyCreationWithAuthInfo(v) => {
        parcel.write(&3i32)?;
        parcel.write(v)
      }
      Self::KeyCreationWithPurposeAndModesInfo(v) => {
        parcel.write(&4i32)?;
        parcel.write(v)
      }
      Self::Keystore2AtomWithOverflow(v) => {
        parcel.write(&5i32)?;
        parcel.write(v)
      }
      Self::KeyOperationWithPurposeAndModesInfo(v) => {
        parcel.write(&6i32)?;
        parcel.write(v)
      }
      Self::KeyOperationWithGeneralInfo(v) => {
        parcel.write(&7i32)?;
        parcel.write(v)
      }
      Self::RkpErrorStats(v) => {
        parcel.write(&8i32)?;
        parcel.write(v)
      }
      Self::CrashStats(v) => {
        parcel.write(&9i32)?;
        parcel.write(v)
      }
    }
  }
}
impl binder::parcel::Deserialize for KeystoreAtomPayload {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for KeystoreAtomPayload {}
impl binder::parcel::DeserializeOption for KeystoreAtomPayload {
  fn deserialize_option(parcel: &binder::parcel::Parcel) -> binder::Result<Option<Self>> {
    let status: i32 = parcel.read()?;
    if status == 0 { return Ok(None); }
    let tag: i32 = parcel.read()?;
    match tag {
      0 => {
        let value: crate::mangled::_7_android_8_security_7_metrics_12_StorageStats = parcel.read()?;
        Ok(Some(Self::StorageStats(value)))
      }
      1 => {
        let value: crate::mangled::_7_android_8_security_7_metrics_12_RkpPoolStats = parcel.read()?;
        Ok(Some(Self::RkpPoolStats(value)))
      }
      2 => {
        let value: crate::mangled::_7_android_8_security_7_metrics_26_KeyCreationWithGeneralInfo = parcel.read()?;
        Ok(Some(Self::KeyCreationWithGeneralInfo(value)))
      }
      3 => {
        let value: crate::mangled::_7_android_8_security_7_metrics_23_KeyCreationWithAuthInfo = parcel.read()?;
        Ok(Some(Self::KeyCreationWithAuthInfo(value)))
      }
      4 => {
        let value: crate::mangled::_7_android_8_security_7_metrics_34_KeyCreationWithPurposeAndModesInfo = parcel.read()?;
        Ok(Some(Self::KeyCreationWithPurposeAndModesInfo(value)))
      }
      5 => {
        let value: crate::mangled::_7_android_8_security_7_metrics_25_Keystore2AtomWithOverflow = parcel.read()?;
        Ok(Some(Self::Keystore2AtomWithOverflow(value)))
      }
      6 => {
        let value: crate::mangled::_7_android_8_security_7_metrics_35_KeyOperationWithPurposeAndModesInfo = parcel.read()?;
        Ok(Some(Self::KeyOperationWithPurposeAndModesInfo(value)))
      }
      7 => {
        let value: crate::mangled::_7_android_8_security_7_metrics_27_KeyOperationWithGeneralInfo = parcel.read()?;
        Ok(Some(Self::KeyOperationWithGeneralInfo(value)))
      }
      8 => {
        let value: crate::mangled::_7_android_8_security_7_metrics_13_RkpErrorStats = parcel.read()?;
        Ok(Some(Self::RkpErrorStats(value)))
      }
      9 => {
        let value: crate::mangled::_7_android_8_security_7_metrics_10_CrashStats = parcel.read()?;
        Ok(Some(Self::CrashStats(value)))
      }
      _ => {
        Err(binder::StatusCode::BAD_VALUE)
      }
    }
  }
}
