#[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub struct KeyOperationWithGeneralInfo {
  pub outcome: crate::mangled::_7_android_8_security_7_metrics_7_Outcome,
  pub error_code: i32,
  pub key_upgraded: bool,
  pub security_level: crate::mangled::_7_android_8_security_7_metrics_13_SecurityLevel,
}
pub(crate) mod mangled { pub use super::KeyOperationWithGeneralInfo as _7_android_8_security_7_metrics_27_KeyOperationWithGeneralInfo; }
impl Default for KeyOperationWithGeneralInfo {
  fn default() -> Self {
    Self {
      outcome: Default::default(),
      error_code: 0,
      key_upgraded: false,
      security_level: Default::default(),
    }
  }
}
impl binder::parcel::Serialize for KeyOperationWithGeneralInfo {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for KeyOperationWithGeneralInfo {}
impl binder::parcel::SerializeOption for KeyOperationWithGeneralInfo {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.outcome)?;
      subparcel.write(&this.error_code)?;
      subparcel.write(&this.key_upgraded)?;
      subparcel.write(&this.security_level)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for KeyOperationWithGeneralInfo {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for KeyOperationWithGeneralInfo {}
impl binder::parcel::DeserializeOption for KeyOperationWithGeneralInfo {
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
    result.outcome = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.error_code = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.key_upgraded = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.security_level = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
