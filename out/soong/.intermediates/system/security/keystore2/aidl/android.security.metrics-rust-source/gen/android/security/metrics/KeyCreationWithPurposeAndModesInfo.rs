#[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub struct KeyCreationWithPurposeAndModesInfo {
  pub algorithm: crate::mangled::_7_android_8_security_7_metrics_9_Algorithm,
  pub purpose_bitmap: i32,
  pub padding_mode_bitmap: i32,
  pub digest_bitmap: i32,
  pub block_mode_bitmap: i32,
}
pub(crate) mod mangled { pub use super::KeyCreationWithPurposeAndModesInfo as _7_android_8_security_7_metrics_34_KeyCreationWithPurposeAndModesInfo; }
impl Default for KeyCreationWithPurposeAndModesInfo {
  fn default() -> Self {
    Self {
      algorithm: Default::default(),
      purpose_bitmap: 0,
      padding_mode_bitmap: 0,
      digest_bitmap: 0,
      block_mode_bitmap: 0,
    }
  }
}
impl binder::parcel::Serialize for KeyCreationWithPurposeAndModesInfo {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for KeyCreationWithPurposeAndModesInfo {}
impl binder::parcel::SerializeOption for KeyCreationWithPurposeAndModesInfo {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.algorithm)?;
      subparcel.write(&this.purpose_bitmap)?;
      subparcel.write(&this.padding_mode_bitmap)?;
      subparcel.write(&this.digest_bitmap)?;
      subparcel.write(&this.block_mode_bitmap)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for KeyCreationWithPurposeAndModesInfo {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for KeyCreationWithPurposeAndModesInfo {}
impl binder::parcel::DeserializeOption for KeyCreationWithPurposeAndModesInfo {
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
    result.algorithm = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.purpose_bitmap = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.padding_mode_bitmap = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.digest_bitmap = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.block_mode_bitmap = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
