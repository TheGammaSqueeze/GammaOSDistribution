/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
public class InitialConfigurationParcelable implements android.os.Parcelable
{
  public android.net.LinkAddress[] ipAddresses;
  public android.net.IpPrefix[] directlyConnectedRoutes;
  public java.lang.String[] dnsServers;
  public java.lang.String gateway;
  public static final android.os.Parcelable.Creator<InitialConfigurationParcelable> CREATOR = new android.os.Parcelable.Creator<InitialConfigurationParcelable>() {
    @Override
    public InitialConfigurationParcelable createFromParcel(android.os.Parcel _aidl_source) {
      InitialConfigurationParcelable _aidl_out = new InitialConfigurationParcelable();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public InitialConfigurationParcelable[] newArray(int _aidl_size) {
      return new InitialConfigurationParcelable[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeTypedArray(ipAddresses, 0);
    _aidl_parcel.writeTypedArray(directlyConnectedRoutes, 0);
    _aidl_parcel.writeStringArray(dnsServers);
    _aidl_parcel.writeString(gateway);
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
      ipAddresses = _aidl_parcel.createTypedArray(android.net.LinkAddress.CREATOR);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      directlyConnectedRoutes = _aidl_parcel.createTypedArray(android.net.IpPrefix.CREATOR);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      dnsServers = _aidl_parcel.createStringArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      gateway = _aidl_parcel.readString();
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
    _aidl_sj.add("ipAddresses: " + (java.util.Arrays.toString(ipAddresses)));
    _aidl_sj.add("directlyConnectedRoutes: " + (java.util.Arrays.toString(directlyConnectedRoutes)));
    _aidl_sj.add("dnsServers: " + (java.util.Arrays.toString(dnsServers)));
    _aidl_sj.add("gateway: " + (java.util.Objects.toString(gateway)));
    return "android.net.InitialConfigurationParcelable" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    _mask |= describeContents(ipAddresses);
    _mask |= describeContents(directlyConnectedRoutes);
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
