/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.system.keystore2;
/** @hide */
public class KeyMetadata implements android.os.Parcelable
{
  public android.system.keystore2.KeyDescriptor key;
  public int keySecurityLevel;
  public android.system.keystore2.Authorization[] authorizations;
  public byte[] certificate;
  public byte[] certificateChain;
  public long modificationTimeMs = 0L;
  @Override
   public final int getStability() { return android.os.Parcelable.PARCELABLE_STABILITY_VINTF; }
  public static final android.os.Parcelable.Creator<KeyMetadata> CREATOR = new android.os.Parcelable.Creator<KeyMetadata>() {
    @Override
    public KeyMetadata createFromParcel(android.os.Parcel _aidl_source) {
      KeyMetadata _aidl_out = new KeyMetadata();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public KeyMetadata[] newArray(int _aidl_size) {
      return new KeyMetadata[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    if ((key!=null)) {
      _aidl_parcel.writeInt(1);
      key.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeInt(keySecurityLevel);
    _aidl_parcel.writeTypedArray(authorizations, 0);
    _aidl_parcel.writeByteArray(certificate);
    _aidl_parcel.writeByteArray(certificateChain);
    _aidl_parcel.writeLong(modificationTimeMs);
    int _aidl_end_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.setDataPosition(_aidl_start_pos);
    _aidl_parcel.writeInt(_aidl_end_pos - _aidl_start_pos);
    _aidl_parcel.setDataPosition(_aidl_end_pos);
  }
  public final void readFromParcel(android.os.Parcel _aidl_parcel)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    int _aidl_parcelable_size = _aidl_parcel.readInt();
    try {
      if (_aidl_parcelable_size < 0) return;
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        key = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        key = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      keySecurityLevel = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      authorizations = _aidl_parcel.createTypedArray(android.system.keystore2.Authorization.CREATOR);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      certificate = _aidl_parcel.createByteArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      certificateChain = _aidl_parcel.createByteArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      modificationTimeMs = _aidl_parcel.readLong();
    } finally {
      if (_aidl_start_pos > (Integer.MAX_VALUE - _aidl_parcelable_size)) {
        throw new android.os.BadParcelableException("Overflow in the size of parcelable");
      }
      _aidl_parcel.setDataPosition(_aidl_start_pos + _aidl_parcelable_size);
    }
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    _mask |= describeContents(key);
    _mask |= describeContents(authorizations);
    return _mask;
  }
  private int describeContents(Object _v) {
    if (_v == null) return 0;
    Class<?> _clazz = _v.getClass();
    if (_clazz.isArray() && _clazz.getComponentType() == Object.class) {
      int _mask = 0;
      for (Object o : (Object[]) _v) {
        _mask |= describeContents(o);
      }
      return _mask;
    }
    if (_v instanceof android.os.Parcelable) {
      return ((android.os.Parcelable) _v).describeContents();
    }
    return 0;
  }
}
