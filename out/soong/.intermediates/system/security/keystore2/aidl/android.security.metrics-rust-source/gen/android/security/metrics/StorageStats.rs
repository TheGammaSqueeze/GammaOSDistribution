#[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub struct StorageStats {
  pub storage_type: crate::mangled::_7_android_8_security_7_metrics_7_Storage,
  pub size: i32,
  pub unused_size: i32,
}
pub(crate) mod mangled { pub use super::StorageStats as _7_android_8_security_7_metrics_12_StorageStats; }
impl Default for StorageStats {
  fn default() -> Self {
    Self {
      storage_type: Default::default(),
      size: 0,
      unused_size: 0,
    }
  }
}
impl binder::parcel::Serialize for StorageStats {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for StorageStats {}
impl binder::parcel::SerializeOption for StorageStats {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.storage_type)?;
      subparcel.write(&this.size)?;
      subparcel.write(&this.unused_size)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for StorageStats {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for StorageStats {}
impl binder::parcel::DeserializeOption for StorageStats {
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
    result.storage_type = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.size = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.unused_size = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
