/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.security.metrics;
/**
 * Count of keys in the attestation key pool related to Remote Key Provisioning (RKP).
 * @hide
 */
public class RkpPoolStats implements android.os.Parcelable
{
  public int security_level;
  public int expiring = 0;
  public int unassigned = 0;
  public int attested = 0;
  public int total = 0;
  public static final android.os.Parcelable.Creator<RkpPoolStats> CREATOR = new android.os.Parcelable.Creator<RkpPoolStats>() {
    @Override
    public RkpPoolStats createFromParcel(android.os.Parcel _aidl_source) {
      RkpPoolStats _aidl_out = new RkpPoolStats();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public RkpPoolStats[] newArray(int _aidl_size) {
      return new RkpPoolStats[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(security_level);
    _aidl_parcel.writeInt(expiring);
    _aidl_parcel.writeInt(unassigned);
    _aidl_parcel.writeInt(attested);
    _aidl_parcel.writeInt(total);
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
      security_level = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      expiring = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      unassigned = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      attested = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      total = _aidl_parcel.readInt();
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
    return _mask;
  }
}
