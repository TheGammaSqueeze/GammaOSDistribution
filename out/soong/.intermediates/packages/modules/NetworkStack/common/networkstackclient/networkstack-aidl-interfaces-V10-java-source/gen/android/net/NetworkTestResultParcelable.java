/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
public class NetworkTestResultParcelable implements android.os.Parcelable
{
  public long timestampMillis = 0L;
  public int result = 0;
  public int probesSucceeded = 0;
  public int probesAttempted = 0;
  public java.lang.String redirectUrl;
  public static final android.os.Parcelable.Creator<NetworkTestResultParcelable> CREATOR = new android.os.Parcelable.Creator<NetworkTestResultParcelable>() {
    @Override
    public NetworkTestResultParcelable createFromParcel(android.os.Parcel _aidl_source) {
      NetworkTestResultParcelable _aidl_out = new NetworkTestResultParcelable();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public NetworkTestResultParcelable[] newArray(int _aidl_size) {
      return new NetworkTestResultParcelable[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeLong(timestampMillis);
    _aidl_parcel.writeInt(result);
    _aidl_parcel.writeInt(probesSucceeded);
    _aidl_parcel.writeInt(probesAttempted);
    _aidl_parcel.writeString(redirectUrl);
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
      timestampMillis = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      result = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      probesSucceeded = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      probesAttempted = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      redirectUrl = _aidl_parcel.readString();
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
    _aidl_sj.add("timestampMillis: " + (timestampMillis));
    _aidl_sj.add("result: " + (result));
    _aidl_sj.add("probesSucceeded: " + (probesSucceeded));
    _aidl_sj.add("probesAttempted: " + (probesAttempted));
    _aidl_sj.add("redirectUrl: " + (java.util.Objects.toString(redirectUrl)));
    return "android.net.NetworkTestResultParcelable" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    return _mask;
  }
}
