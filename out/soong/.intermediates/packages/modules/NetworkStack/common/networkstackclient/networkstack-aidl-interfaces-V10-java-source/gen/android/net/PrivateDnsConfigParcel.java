/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
public class PrivateDnsConfigParcel implements android.os.Parcelable
{
  public java.lang.String hostname;
  public java.lang.String[] ips;
  public static final android.os.Parcelable.Creator<PrivateDnsConfigParcel> CREATOR = new android.os.Parcelable.Creator<PrivateDnsConfigParcel>() {
    @Override
    public PrivateDnsConfigParcel createFromParcel(android.os.Parcel _aidl_source) {
      PrivateDnsConfigParcel _aidl_out = new PrivateDnsConfigParcel();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public PrivateDnsConfigParcel[] newArray(int _aidl_size) {
      return new PrivateDnsConfigParcel[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeString(hostname);
    _aidl_parcel.writeStringArray(ips);
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
      hostname = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      ips = _aidl_parcel.createStringArray();
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
    _aidl_sj.add("hostname: " + (java.util.Objects.toString(hostname)));
    _aidl_sj.add("ips: " + (java.util.Arrays.toString(ips)));
    return "android.net.PrivateDnsConfigParcel" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    return _mask;
  }
}
