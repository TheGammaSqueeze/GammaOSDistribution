/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net.resolv.aidl;
/** @hide */
public class PrivateDnsValidationEventParcel implements android.os.Parcelable
{
  public int netId = 0;
  public java.lang.String ipAddress;
  public java.lang.String hostname;
  public int validation = 0;
  public static final android.os.Parcelable.Creator<PrivateDnsValidationEventParcel> CREATOR = new android.os.Parcelable.Creator<PrivateDnsValidationEventParcel>() {
    @Override
    public PrivateDnsValidationEventParcel createFromParcel(android.os.Parcel _aidl_source) {
      PrivateDnsValidationEventParcel _aidl_out = new PrivateDnsValidationEventParcel();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public PrivateDnsValidationEventParcel[] newArray(int _aidl_size) {
      return new PrivateDnsValidationEventParcel[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(netId);
    _aidl_parcel.writeString(ipAddress);
    _aidl_parcel.writeString(hostname);
    _aidl_parcel.writeInt(validation);
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
      ipAddress = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      hostname = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      validation = _aidl_parcel.readInt();
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
    _aidl_sj.add("ipAddress: " + (java.util.Objects.toString(ipAddress)));
    _aidl_sj.add("hostname: " + (java.util.Objects.toString(hostname)));
    _aidl_sj.add("validation: " + (validation));
    return "android.net.resolv.aidl.PrivateDnsValidationEventParcel" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    return _mask;
  }
}
