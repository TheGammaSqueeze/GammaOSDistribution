/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net.resolv.aidl;
/** @hide */
public class DnsHealthEventParcel implements android.os.Parcelable
{
  public int netId = 0;
  public int healthResult = 0;
  public int[] successRttMicros;
  public static final android.os.Parcelable.Creator<DnsHealthEventParcel> CREATOR = new android.os.Parcelable.Creator<DnsHealthEventParcel>() {
    @Override
    public DnsHealthEventParcel createFromParcel(android.os.Parcel _aidl_source) {
      DnsHealthEventParcel _aidl_out = new DnsHealthEventParcel();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public DnsHealthEventParcel[] newArray(int _aidl_size) {
      return new DnsHealthEventParcel[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(netId);
    _aidl_parcel.writeInt(healthResult);
    _aidl_parcel.writeIntArray(successRttMicros);
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
      netId = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      healthResult = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      successRttMicros = _aidl_parcel.createIntArray();
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
    _aidl_sj.add("netId: " + (netId));
    _aidl_sj.add("healthResult: " + (healthResult));
    _aidl_sj.add("successRttMicros: " + (java.util.Arrays.toString(successRttMicros)));
    return "android.net.resolv.aidl.DnsHealthEventParcel" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    return _mask;
  }
}
