#[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub struct KeyMintHardwareInfo {
  pub versionNumber: i32,
  pub securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel,
  pub keyMintName: String,
  pub keyMintAuthorName: String,
  pub timestampTokenRequired: bool,
}
pub(crate) mod mangled { pub use super::KeyMintHardwareInfo as _7_android_8_hardware_8_security_7_keymint_19_KeyMintHardwareInfo; }
impl Default for KeyMintHardwareInfo {
  fn default() -> Self {
    Self {
      versionNumber: 0,
      securityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel::SOFTWARE,
      keyMintName: Default::default(),
      keyMintAuthorName: Default::default(),
      timestampTokenRequired: false,
    }
  }
}
impl binder::parcel::Serialize for KeyMintHardwareInfo {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for KeyMintHardwareInfo {}
impl binder::parcel::SerializeOption for KeyMintHardwareInfo {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.versionNumber)?;
      subparcel.write(&this.securityLevel)?;
      subparcel.write(&this.keyMintName)?;
      subparcel.write(&this.keyMintAuthorName)?;
      subparcel.write(&this.timestampTokenRequired)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for KeyMintHardwareInfo {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for KeyMintHardwareInfo {}
impl binder::parcel::DeserializeOption for KeyMintHardwareInfo {
  fn deserialize_option(parcel: &binder::parcel::Parcel) -> binder::Result<Option<Self>> {
    let status: i32 = parcel.read()?;
    if status == 0 { return Ok(None); }
    let start_pos = parcel.get_data_position();
    let parcelable_size: i32 = parcel.read()?;
    if parcelable_size < 0 { return Err(binder::StatusCode::BAD_VALUE); }
    if start_pos.checked_add(parcelable_size).is_none() {
      return Err(binder::StatusCode::BAD_VALUE);
    }
    let mut result = Self::default();
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.versionNumber = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.securityLevel = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.keyMintName = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.keyMintAuthorName = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.timestampTokenRequired = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
