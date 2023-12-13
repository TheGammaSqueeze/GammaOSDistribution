#[derive(Debug)]
pub struct BeginResult {
  pub challenge: i64,
  pub params: Vec<crate::mangled::_7_android_8_hardware_8_security_7_keymint_12_KeyParameter>,
  pub operation: Option<binder::Strong<dyn crate::mangled::_7_android_8_hardware_8_security_7_keymint_17_IKeyMintOperation>>,
}
pub(crate) mod mangled { pub use super::BeginResult as _7_android_8_hardware_8_security_7_keymint_11_BeginResult; }
impl Default for BeginResult {
  fn default() -> Self {
    Self {
      challenge: 0,
      params: Default::default(),
      operation: Default::default(),
    }
  }
}
impl binder::parcel::Serialize for BeginResult {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for BeginResult {}
impl binder::parcel::SerializeOption for BeginResult {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.challenge)?;
      subparcel.write(&this.params)?;
      let __field_ref = this.operation.as_ref().ok_or(binder::StatusCode::UNEXPECTED_NULL)?;
      subparcel.write(__field_ref)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for BeginResult {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for BeginResult {}
impl binder::parcel::DeserializeOption for BeginResult {
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
    result.params = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.operation = Some(parcel.read()?);
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
