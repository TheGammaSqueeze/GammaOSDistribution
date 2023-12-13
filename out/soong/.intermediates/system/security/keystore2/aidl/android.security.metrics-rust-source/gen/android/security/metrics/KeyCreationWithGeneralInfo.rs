#[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub struct KeyCreationWithGeneralInfo {
  pub algorithm: crate::mangled::_7_android_8_security_7_metrics_9_Algorithm,
  pub key_size: i32,
  pub ec_curve: crate::mangled::_7_android_8_security_7_metrics_7_EcCurve,
  pub key_origin: crate::mangled::_7_android_8_security_7_metrics_9_KeyOrigin,
  pub error_code: i32,
  pub attestation_requested: bool,
}
pub(crate) mod mangled { pub use super::KeyCreationWithGeneralInfo as _7_android_8_security_7_metrics_26_KeyCreationWithGeneralInfo; }
impl Default for KeyCreationWithGeneralInfo {
  fn default() -> Self {
    Self {
      algorithm: Default::default(),
      key_size: 0,
      ec_curve: Default::default(),
      key_origin: Default::default(),
      error_code: 0,
      attestation_requested: false,
    }
  }
}
impl binder::parcel::Serialize for KeyCreationWithGeneralInfo {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for KeyCreationWithGeneralInfo {}
impl binder::parcel::SerializeOption for KeyCreationWithGeneralInfo {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.algorithm)?;
      subparcel.write(&this.key_size)?;
      subparcel.write(&this.ec_curve)?;
      subparcel.write(&this.key_origin)?;
      subparcel.write(&this.error_code)?;
      subparcel.write(&this.attestation_requested)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for KeyCreationWithGeneralInfo {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for KeyCreationWithGeneralInfo {}
impl binder::parcel::DeserializeOption for KeyCreationWithGeneralInfo {
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
    result.key_size = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.ec_curve = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.key_origin = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.error_code = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.attestation_requested = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
