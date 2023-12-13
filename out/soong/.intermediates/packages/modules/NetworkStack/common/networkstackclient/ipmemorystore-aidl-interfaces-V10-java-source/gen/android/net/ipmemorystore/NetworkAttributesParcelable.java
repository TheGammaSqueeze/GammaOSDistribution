/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net.ipmemorystore;
/** @hide */
public class NetworkAttributesParcelable implements android.os.Parcelable
{
  public byte[] assignedV4Address;
  public long assignedV4AddressExpiry = 0L;
  public java.lang.String cluster;
  public android.net.ipmemorystore.Blob[] dnsAddresses;
  public int mtu = 0;
  public android.net.networkstack.aidl.quirks.IPv6ProvisioningLossQuirkParcelable ipv6ProvisioningLossQuirk;
  public static final android.os.Parcelable.Creator<NetworkAttributesParcelable> CREATOR = new android.os.Parcelable.Creator<NetworkAttributesParcelable>() {
    @Override
    public NetworkAttributesParcelable createFromParcel(android.os.Parcel _aidl_source) {
      NetworkAttributesParcelable _aidl_out = new NetworkAttributesParcelable();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public NetworkAttributesParcelable[] newArray(int _aidl_size) {
      return new NetworkAttributesParcelable[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeByteArray(assignedV4Address);
    _aidl_parcel.writeLong(assignedV4AddressExpiry);
    _aidl_parcel.writeString(cluster);
    _aidl_parcel.writeTypedArray(dnsAddresses, 0);
    _aidl_parcel.writeInt(mtu);
    if ((ipv6ProvisioningLossQuirk!=null)) {
      _aidl_parcel.writeInt(1);
      ipv6ProvisioningLossQuirk.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
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
      assignedV4Address = _aidl_parcel.createByteArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      assignedV4AddressExpiry = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      cluster = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      dnsAddresses = _aidl_parcel.createTypedArray(android.net.ipmemorystore.Blob.CREATOR);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      mtu = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        ipv6ProvisioningLossQuirk = android.net.networkstack.aidl.quirks.IPv6ProvisioningLossQuirkParcelable.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        ipv6ProvisioningLossQuirk = null;
      }
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
    _aidl_sj.add("assignedV4Address: " + (java.util.Arrays.toString(assignedV4Address)));
    _aidl_sj.add("assignedV4AddressExpiry: " + (assignedV4AddressExpiry));
    _aidl_sj.add("cluster: " + (java.util.Objects.toString(cluster)));
    _aidl_sj.add("dnsAddresses: " + (java.util.Arrays.toString(dnsAddresses)));
    _aidl_sj.add("mtu: " + (mtu));
    _aidl_sj.add("ipv6ProvisioningLossQuirk: " + (java.util.Objects.toString(ipv6ProvisioningLossQuirk)));
    return "android.net.ipmemorystore.NetworkAttributesParcelable" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    _mask |= describeContents(dnsAddresses);
    _mask |= describeContents(ipv6ProvisioningLossQuirk);
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
