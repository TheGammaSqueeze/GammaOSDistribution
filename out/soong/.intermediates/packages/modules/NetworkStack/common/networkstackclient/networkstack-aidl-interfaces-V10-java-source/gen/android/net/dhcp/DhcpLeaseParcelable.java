/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net.dhcp;
public class DhcpLeaseParcelable implements android.os.Parcelable
{
  public byte[] clientId;
  public byte[] hwAddr;
  public int netAddr = 0;
  public int prefixLength = 0;
  public long expTime = 0L;
  public java.lang.String hostname;
  public static final android.os.Parcelable.Creator<DhcpLeaseParcelable> CREATOR = new android.os.Parcelable.Creator<DhcpLeaseParcelable>() {
    @Override
    public DhcpLeaseParcelable createFromParcel(android.os.Parcel _aidl_source) {
      DhcpLeaseParcelable _aidl_out = new DhcpLeaseParcelable();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public DhcpLeaseParcelable[] newArray(int _aidl_size) {
      return new DhcpLeaseParcelable[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeByteArray(clientId);
    _aidl_parcel.writeByteArray(hwAddr);
    _aidl_parcel.writeInt(netAddr);
    _aidl_parcel.writeInt(prefixLength);
    _aidl_parcel.writeLong(expTime);
    _aidl_parcel.writeString(hostname);
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
      clientId = _aidl_parcel.createByteArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      hwAddr = _aidl_parcel.createByteArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      netAddr = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      prefixLength = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      expTime = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      hostname = _aidl_parcel.readString();
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
    _aidl_sj.add("clientId: " + (java.util.Arrays.toString(clientId)));
    _aidl_sj.add("hwAddr: " + (java.util.Arrays.toString(hwAddr)));
    _aidl_sj.add("netAddr: " + (netAddr));
    _aidl_sj.add("prefixLength: " + (prefixLength));
    _aidl_sj.add("expTime: " + (expTime));
    _aidl_sj.add("hostname: " + (java.util.Objects.toString(hostname)));
    return "android.net.dhcp.DhcpLeaseParcelable" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    return _mask;
  }
}
