#[derive(Debug, Clone, Eq, Ord, PartialEq, PartialOrd)]
pub struct KeyDescriptor {
  pub domain: crate::mangled::_7_android_6_system_9_keystore2_6_Domain,
  pub nspace: i64,
  pub alias: Option<String>,
  pub blob: Option<Vec<u8>>,
}
pub(crate) mod mangled { pub use super::KeyDescriptor as _7_android_6_system_9_keystore2_13_KeyDescriptor; }
impl Default for KeyDescriptor {
  fn default() -> Self {
    Self {
      domain: Default::default(),
      nspace: 0,
      alias: Default::default(),
      blob: Default::default(),
    }
  }
}
impl binder::parcel::Serialize for KeyDescriptor {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for KeyDescriptor {}
impl binder::parcel::SerializeOption for KeyDescriptor {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.domain)?;
      subparcel.write(&this.nspace)?;
      subparcel.write(&this.alias)?;
      subparcel.write(&this.blob)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for KeyDescriptor {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for KeyDescriptor {}
impl binder::parcel::DeserializeOption for KeyDescriptor {
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
    result.domain = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.nspace = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.alias = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.blob = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
