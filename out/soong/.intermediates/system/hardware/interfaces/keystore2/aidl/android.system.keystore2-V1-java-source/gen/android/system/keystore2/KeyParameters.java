/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.system.keystore2;
/** @hide */
public class KeyParameters implements android.os.Parcelable
{
  public android.hardware.security.keymint.KeyParameter[] keyParameter;
  @Override
   public final int getStability() { return android.os.Parcelable.PARCELABLE_STABILITY_VINTF; }
  public static final android.os.Parcelable.Creator<KeyParameters> CREATOR = new android.os.Parcelable.Creator<KeyParameters>() {
    @Override
    public KeyParameters createFromParcel(android.os.Parcel _aidl_source) {
      KeyParameters _aidl_out = new KeyParameters();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public KeyParameters[] newArray(int _aidl_size) {
      return new KeyParameters[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeTypedArray(keyParameter, 0);
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
      keyParameter = _aidl_parcel.createTypedArray(android.hardware.security.keymint.KeyParameter.CREATOR);
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
    _mask |= describeContents(keyParameter);
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
