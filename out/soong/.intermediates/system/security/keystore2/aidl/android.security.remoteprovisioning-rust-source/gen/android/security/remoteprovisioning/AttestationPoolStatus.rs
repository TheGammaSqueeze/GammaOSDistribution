#[derive(Debug)]
pub struct AttestationPoolStatus {
  pub expiring: i32,
  pub unassigned: i32,
  pub attested: i32,
  pub total: i32,
}
pub(crate) mod mangled { pub use super::AttestationPoolStatus as _7_android_8_security_18_remoteprovisioning_21_AttestationPoolStatus; }
impl Default for AttestationPoolStatus {
  fn default() -> Self {
    Self {
      expiring: 0,
      unassigned: 0,
      attested: 0,
      total: 0,
    }
  }
}
impl binder::parcel::Serialize for AttestationPoolStatus {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for AttestationPoolStatus {}
impl binder::parcel::SerializeOption for AttestationPoolStatus {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.expiring)?;
      subparcel.write(&this.unassigned)?;
      subparcel.write(&this.attested)?;
      subparcel.write(&this.total)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for AttestationPoolStatus {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for AttestationPoolStatus {}
impl binder::parcel::DeserializeOption for AttestationPoolStatus {
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
    result.expiring = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.unassigned = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.attested = parcel.read()?;
    if (parcel.get_data_position() - start_pos) == parcelable_size {
      return Ok(Some(result));
    }
    result.total = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
