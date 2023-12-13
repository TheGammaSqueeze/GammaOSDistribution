#[derive(Debug)]
pub struct KeyEntryResponse {
  pub iSecurityLevel: Option<binder::Strong<dyn crate::mangled::_7_android_6_system_9_keystore2_22_IKeystoreSecurityLevel>>,
  pub metadata: crate::mangled::_7_android_6_system_9_keystore2_11_KeyMetadata,
}
pub(crate) mod mangled { pub use super::KeyEntryResponse as _7_android_6_system_9_keystore2_16_KeyEntryResponse; }
impl Default for KeyEntryResponse {
  fn default() -> Self {
    Self {
      iSecurityLevel: Default::default(),
      metadata: Default::default(),
    }
  }
}
impl binder::parcel::Serialize for KeyEntryResponse {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for KeyEntryResponse {}
impl binder::parcel::SerializeOption for KeyEntryResponse {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.iSecurityLevel)?;
      subparcel.write(&this.metadata)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for KeyEntryResponse {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for KeyEntryResponse {}
impl binder::parcel::DeserializeOption for KeyEntryResponse {
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
    result.iSecurityLevel = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.metadata = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
