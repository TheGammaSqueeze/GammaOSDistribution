/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net.networkstack.aidl.quirks;
public class IPv6ProvisioningLossQuirkParcelable implements android.os.Parcelable
{
  public int detectionCount = 0;
  public long quirkExpiry = 0L;
  public static final android.os.Parcelable.Creator<IPv6ProvisioningLossQuirkParcelable> CREATOR = new android.os.Parcelable.Creator<IPv6ProvisioningLossQuirkParcelable>() {
    @Override
    public IPv6ProvisioningLossQuirkParcelable createFromParcel(android.os.Parcel _aidl_source) {
      IPv6ProvisioningLossQuirkParcelable _aidl_out = new IPv6ProvisioningLossQuirkParcelable();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public IPv6ProvisioningLossQuirkParcelable[] newArray(int _aidl_size) {
      return new IPv6ProvisioningLossQuirkParcelable[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(detectionCount);
    _aidl_parcel.writeLong(quirkExpiry);
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
      detectionCount = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      quirkExpiry = _aidl_parcel.readLong();
    } finally {
      if (_aidl_start_pos > (Integer.MAX_VALUE - _aidl_parcelable_size)) {
        throw new android.os.BadParcelableException("Overflow in the size of parcelable");
      }
      _aidl_parcel.setDataPosition(_aidl_start_pos + _aidl_parcelable_size);
    }
  }
  @Override
  public String toString() {
    java.util.StringJoiner _aidl_sj = new java.util.StringJoiner(", ", "{", "}");
    _aidl_sj.add("detectionCount: " + (detectionCount));
    _aidl_sj.add("quirkExpiry: " + (quirkExpiry));
    return "android.net.networkstack.aidl.quirks.IPv6ProvisioningLossQuirkParcelable" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    return _mask;
  }
}
