#[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub struct KeyParameter {
  pub tag: crate::mangled::_7_android_8_hardware_8_security_7_keymint_3_Tag,
  pub value: crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_KeyParameterValue,
}
pub(crate) mod mangled { pub use super::KeyParameter as _7_android_8_hardware_8_security_7_keymint_12_KeyParameter; }
impl Default for KeyParameter {
  fn default() -> Self {
    Self {
      tag: crate::mangled::_7_android_8_hardware_8_security_7_keymint_3_Tag::INVALID,
      value: Default::default(),
    }
  }
}
impl binder::parcel::Serialize for KeyParameter {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for KeyParameter {}
impl binder::parcel::SerializeOption for KeyParameter {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.tag)?;
      subparcel.write(&this.value)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for KeyParameter {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for KeyParameter {}
impl binder::parcel::DeserializeOption for KeyParameter {
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
    result.tag = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.value = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
