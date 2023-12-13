/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net.dhcp;
public class DhcpServingParamsParcel implements android.os.Parcelable
{
  public int serverAddr = 0;
  public int serverAddrPrefixLength = 0;
  public int[] defaultRouters;
  public int[] dnsServers;
  public int[] excludedAddrs;
  public long dhcpLeaseTimeSecs = 0L;
  public int linkMtu = 0;
  public boolean metered = false;
  public int singleClientAddr = 0;
  public boolean changePrefixOnDecline = false;
  public static final android.os.Parcelable.Creator<DhcpServingParamsParcel> CREATOR = new android.os.Parcelable.Creator<DhcpServingParamsParcel>() {
    @Override
    public DhcpServingParamsParcel createFromParcel(android.os.Parcel _aidl_source) {
      DhcpServingParamsParcel _aidl_out = new DhcpServingParamsParcel();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public DhcpServingParamsParcel[] newArray(int _aidl_size) {
      return new DhcpServingParamsParcel[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(serverAddr);
    _aidl_parcel.writeInt(serverAddrPrefixLength);
    _aidl_parcel.writeIntArray(defaultRouters);
    _aidl_parcel.writeIntArray(dnsServers);
    _aidl_parcel.writeIntArray(excludedAddrs);
    _aidl_parcel.writeLong(dhcpLeaseTimeSecs);
    _aidl_parcel.writeInt(linkMtu);
    _aidl_parcel.writeInt(((metered)?(1):(0)));
    _aidl_parcel.writeInt(singleClientAddr);
    _aidl_parcel.writeInt(((changePrefixOnDecline)?(1):(0)));
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
      serverAddr = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      serverAddrPrefixLength = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      defaultRouters = _aidl_parcel.createIntArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      dnsServers = _aidl_parcel.createIntArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      excludedAddrs = _aidl_parcel.createIntArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      dhcpLeaseTimeSecs = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      linkMtu = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      metered = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      singleClientAddr = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      changePrefixOnDecline = (0!=_aidl_parcel.readInt());
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
    _aidl_sj.add("serverAddr: " + (serverAddr));
    _aidl_sj.add("serverAddrPrefixLength: " + (serverAddrPrefixLength));
    _aidl_sj.add("defaultRouters: " + (java.util.Arrays.toString(defaultRouters)));
    _aidl_sj.add("dnsServers: " + (java.util.Arrays.toString(dnsServers)));
    _aidl_sj.add("excludedAddrs: " + (java.util.Arrays.toString(excludedAddrs)));
    _aidl_sj.add("dhcpLeaseTimeSecs: " + (dhcpLeaseTimeSecs));
    _aidl_sj.add("linkMtu: " + (linkMtu));
    _aidl_sj.add("metered: " + (metered));
    _aidl_sj.add("singleClientAddr: " + (singleClientAddr));
    _aidl_sj.add("changePrefixOnDecline: " + (changePrefixOnDecline));
    return "android.net.dhcp.DhcpServingParamsParcel" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    return _mask;
  }
}
