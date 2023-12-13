#[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub struct KeyCreationWithAuthInfo {
  pub user_auth_type: crate::mangled::_7_android_8_security_7_metrics_25_HardwareAuthenticatorType,
  pub log10_auth_key_timeout_seconds: i32,
  pub security_level: crate::mangled::_7_android_8_security_7_metrics_13_SecurityLevel,
}
pub(crate) mod mangled { pub use super::KeyCreationWithAuthInfo as _7_android_8_security_7_metrics_23_KeyCreationWithAuthInfo; }
impl Default for KeyCreationWithAuthInfo {
  fn default() -> Self {
    Self {
      user_auth_type: Default::default(),
      log10_auth_key_timeout_seconds: 0,
      security_level: Default::default(),
    }
  }
}
impl binder::parcel::Serialize for KeyCreationWithAuthInfo {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for KeyCreationWithAuthInfo {}
impl binder::parcel::SerializeOption for KeyCreationWithAuthInfo {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.user_auth_type)?;
      subparcel.write(&this.log10_auth_key_timeout_seconds)?;
      subparcel.write(&this.security_level)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for KeyCreationWithAuthInfo {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for KeyCreationWithAuthInfo {}
impl binder::parcel::DeserializeOption for KeyCreationWithAuthInfo {
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
    result.user_auth_type = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.log10_auth_key_timeout_seconds = parcel.read()?;
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
