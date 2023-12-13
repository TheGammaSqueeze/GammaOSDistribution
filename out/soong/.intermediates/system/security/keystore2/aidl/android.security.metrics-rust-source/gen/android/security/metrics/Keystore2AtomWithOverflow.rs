#[derive(Debug, Clone, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub struct Keystore2AtomWithOverflow {
  pub atom_id: crate::mangled::_7_android_8_security_7_metrics_6_AtomID,
}
pub(crate) mod mangled { pub use super::Keystore2AtomWithOverflow as _7_android_8_security_7_metrics_25_Keystore2AtomWithOverflow; }
impl Default for Keystore2AtomWithOverflow {
  fn default() -> Self {
    Self {
      atom_id: Default::default(),
    }
  }
}
impl binder::parcel::Serialize for Keystore2AtomWithOverflow {
  fn serialize(&self, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    <Self as binder::parcel::SerializeOption>::serialize_option(Some(self), parcel)
  }
}
impl binder::parcel::SerializeArray for Keystore2AtomWithOverflow {}
impl binder::parcel::SerializeOption for Keystore2AtomWithOverflow {
  fn serialize_option(this: Option<&Self>, parcel: &mut binder::parcel::Parcel) -> binder::Result<()> {
    let this = if let Some(this) = this {
      parcel.write(&1i32)?;
      this
    } else {
      return parcel.write(&0i32);
    };
    parcel.sized_write(|subparcel| {
      subparcel.write(&this.atom_id)?;
      Ok(())
    })
  }
}
impl binder::parcel::Deserialize for Keystore2AtomWithOverflow {
  fn deserialize(parcel: &binder::parcel::Parcel) -> binder::Result<Self> {
    <Self as binder::parcel::DeserializeOption>::deserialize_option(parcel)
       .transpose()
       .unwrap_or(Err(binder::StatusCode::UNEXPECTED_NULL))
  }
}
impl binder::parcel::DeserializeArray for Keystore2AtomWithOverflow {}
impl binder::parcel::DeserializeOption for Keystore2AtomWithOverflow {
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
    result.atom_id = parcel.read()?;
    unsafe {
      parcel.set_data_position(start_pos + parcelable_size)?;
    }
    Ok(Some(result))
  }
}
