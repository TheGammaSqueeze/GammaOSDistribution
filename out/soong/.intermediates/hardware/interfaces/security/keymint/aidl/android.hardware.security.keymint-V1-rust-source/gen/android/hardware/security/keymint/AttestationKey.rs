#[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub struct AttestationKey {
  pub keyBlob: Vec<u8>,
  pub attestKeyParams: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter>,
  pub issuerSubjectName: Vec<u8>,
}
pub(crate) mod mangled { pub use super::AttestationKey as _7_android_8_hardware_8_security_7_keymint_14_AttestationKey; }
impl Default for AttestationKey {
  fn default() -> Self {
    Self {
      keyBlob: Default::default(),
      attestKeyParams: Default::default(),
      issuerSubjectName: Default::default(),
    }
  }
}
impl binder::parcel::Serialize for AttestationKey {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for AttestationKey {}
impl binder::parcel::SerializeOption for AttestationKey {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.keyBlob)?;
      subparcel.write(&this.attestKeyParams)?;
      subparcel.write(&this.issuerSubjectName)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for AttestationKey {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for AttestationKey {}
impl binder::parcel::DeserializeOption for AttestationKey {
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
    result.keyBlob = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.attestKeyParams = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.issuerSubjectName = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
