#[derive(Debug)]
pub struct AuthorizationTokens {
  pub authToken: crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken,
  pub timestampToken: crate::mangled::_7_android_8_hardware_8_security_11_secureclock_14_TimeStampToken,
}
pub(crate) mod mangled { pub use super::AuthorizationTokens as _7_android_8_security_13_authorization_19_AuthorizationTokens; }
impl Default for AuthorizationTokens {
  fn default() -> Self {
    Self {
      authToken: Default::default(),
      timestampToken: Default::default(),
    }
  }
}
impl binder::parcel::Serialize for AuthorizationTokens {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for AuthorizationTokens {}
impl binder::parcel::SerializeOption for AuthorizationTokens {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.authToken)?;
      subparcel.write(&this.timestampToken)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for AuthorizationTokens {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for AuthorizationTokens {}
impl binder::parcel::DeserializeOption for AuthorizationTokens {
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
    result.authToken = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.timestampToken = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
