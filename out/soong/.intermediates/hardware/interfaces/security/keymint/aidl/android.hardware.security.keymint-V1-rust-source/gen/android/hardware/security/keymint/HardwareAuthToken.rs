#[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub struct HardwareAuthToken {
  pub challenge: i64,
  pub userId: i64,
  pub authenticatorId: i64,
  pub authenticatorType: crate::mangled::_7_android_8_hardware_8_security_7_keymint_25_HardwareAuthenticatorType,
  pub timestamp: crate::mangled::_7_android_8_hardware_8_security_11_secureclock_9_Timestamp,
  pub mac: Vec<u8>,
}
pub(crate) mod mangled { pub use super::HardwareAuthToken as _7_android_8_hardware_8_security_7_keymint_17_HardwareAuthToken; }
impl Default for HardwareAuthToken {
  fn default() -> Self {
    Self {
      challenge: 0,
      userId: 0,
      authenticatorId: 0,
      authenticatorType: crate::mangled::_7_android_8_hardware_8_security_7_keymint_25_HardwareAuthenticatorType::NONE,
      timestamp: Default::default(),
      mac: Default::default(),
    }
  }
}
impl binder::parcel::Serialize for HardwareAuthToken {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for HardwareAuthToken {}
impl binder::parcel::SerializeOption for HardwareAuthToken {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.challenge)?;
      subparcel.write(&this.userId)?;
      subparcel.write(&this.authenticatorId)?;
      subparcel.write(&this.authenticatorType)?;
      subparcel.write(&this.timestamp)?;
      subparcel.write(&this.mac)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for HardwareAuthToken {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for HardwareAuthToken {}
impl binder::parcel::DeserializeOption for HardwareAuthToken {
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
    result.challenge = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.userId = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.authenticatorId = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.authenticatorType = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.timestamp = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.mac = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
