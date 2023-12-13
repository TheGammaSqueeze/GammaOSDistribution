#[derive(Debug)]
pub struct KeyMetadata {
  pub key: crate::mangled::_7_android_6_system_9_keystore2_13_KeyDescriptor,
  pub keySecurityLevel: crate::mangled::_7_android_8_hardware_8_security_7_keymint_13_SecurityLevel,
  pub authorizations: Vec<crate::mangled::_7_android_6_system_9_keystore2_13_Authorization>,
  pub certificate: Option<Vec<u8>>,
  pub certificateChain: Option<Vec<u8>>,
  pub modificationTimeMs: i64,
}
pub(crate) mod mangled { pub use super::KeyMetadata as _7_android_6_system_9_keystore2_11_KeyMetadata; }
impl Default for KeyMetadata {
  fn default() -> Self {
    Self {
      key: Default::default(),
      keySecurityLevel: Default::default(),
      authorizations: Default::default(),
      certificate: Default::default(),
      certificateChain: Default::default(),
      modificationTimeMs: 0,
    }
  }
}
impl binder::parcel::Serialize for KeyMetadata {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for KeyMetadata {}
impl binder::parcel::SerializeOption for KeyMetadata {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.key)?;
      subparcel.write(&this.keySecurityLevel)?;
      subparcel.write(&this.authorizations)?;
      subparcel.write(&this.certificate)?;
      subparcel.write(&this.certificateChain)?;
      subparcel.write(&this.modificationTimeMs)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for KeyMetadata {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for KeyMetadata {}
impl binder::parcel::DeserializeOption for KeyMetadata {
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
    result.key = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.keySecurityLevel = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.authorizations = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.certificate = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.certificateChain = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.modificationTimeMs = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
