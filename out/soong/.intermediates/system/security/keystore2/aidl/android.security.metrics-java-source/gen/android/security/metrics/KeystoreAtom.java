/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.security.metrics;
/**
 * Encapsulates a particular atom object of type KeystoreAtomPayload its count. Note that
 * the field: count is only relevant for the atom types that are stored in the
 * in-memory metrics store. E.g. count field is not relevant for the atom types such as StorageStats
 * and RkpPoolStats that are not stored in the metrics store.
 * @hide
 */
public class KeystoreAtom implements android.os.Parcelable
{
  public android.security.metrics.KeystoreAtomPayload payload;
  public int count = 0;
  public static final android.os.Parcelable.Creator<KeystoreAtom> CREATOR = new android.os.Parcelable.Creator<KeystoreAtom>() {
    @Override
    public KeystoreAtom createFromParcel(android.os.Parcel _aidl_source) {
      KeystoreAtom _aidl_out = new KeystoreAtom();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public KeystoreAtom[] newArray(int _aidl_size) {
      return new KeystoreAtom[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    if ((payload!=null)) {
      _aidl_parcel.writeInt(1);
      payload.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeInt(count);
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
        payload = android.security.metrics.KeystoreAtomPayload.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        payload = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      count = _aidl_parcel.readInt();
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
    _mask |= describeContents(payload);
    return _mask;
  }
  private int describeContents(Object _v) {
    if (_v == null) return 0;
    if (_v instanceof android.os.Parcelable) {
      return ((android.os.Parcelable) _v).describeContents();
    }
    return 0;
  }
}
