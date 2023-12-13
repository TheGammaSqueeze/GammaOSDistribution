#[derive(Debug)]
pub struct CreateOperationResponse {
  pub iOperation: Option<binder::Strong<dyn crate::mangled::_7_android_6_system_9_keystore2_18_IKeystoreOperation>>,
  pub operationChallenge: Option<crate::mangled::_7_android_6_system_9_keystore2_18_OperationChallenge>,
  pub parameters: Option<crate::mangled::_7_android_6_system_9_keystore2_13_KeyParameters>,
  pub upgradedBlob: Option<Vec<u8>>,
}
pub(crate) mod mangled { pub use super::CreateOperationResponse as _7_android_6_system_9_keystore2_23_CreateOperationResponse; }
impl Default for CreateOperationResponse {
  fn default() -> Self {
    Self {
      iOperation: Default::default(),
      operationChallenge: Default::default(),
      parameters: Default::default(),
      upgradedBlob: Default::default(),
    }
  }
}
impl binder::parcel::Serialize for CreateOperationResponse {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for CreateOperationResponse {}
impl binder::parcel::SerializeOption for CreateOperationResponse {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      let __field_ref = this.iOperation.as_ref().ok_or(binder::StatusCode::UNEXPECTED_NULL)?;
      subparcel.write(__field_ref)?;
      subparcel.write(&this.operationChallenge)?;
      subparcel.write(&this.parameters)?;
      subparcel.write(&this.upgradedBlob)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for CreateOperationResponse {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for CreateOperationResponse {}
impl binder::parcel::DeserializeOption for CreateOperationResponse {
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
    result.iOperation = Some(parcel.read()?);
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.operationChallenge = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.parameters = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.upgradedBlob = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
