/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
/** @hide */
public class NativeNetworkConfig implements android.os.Parcelable
{
  public final int netId;
  public final int networkType;
  public final int permission;
  public final boolean secure;
  public final int vpnType;
  public static final class Builder
  {
    private int netId = 0;
    public Builder setNetId(int netId) {
      this.netId = netId;
      return this;
    }
    private int networkType = android.net.NativeNetworkType.PHYSICAL;
    public Builder setNetworkType(int networkType) {
      this.networkType = networkType;
      return this;
    }
    private int permission = 0;
    public Builder setPermission(int permission) {
      this.permission = permission;
      return this;
    }
    private boolean secure = false;
    public Builder setSecure(boolean secure) {
      this.secure = secure;
      return this;
    }
    private int vpnType = android.net.NativeVpnType.PLATFORM;
    public Builder setVpnType(int vpnType) {
      this.vpnType = vpnType;
      return this;
    }
    public android.net.NativeNetworkConfig build() {
      return new android.net.NativeNetworkConfig(netId, networkType, permission, secure, vpnType);
    }
  }
  public static final android.os.Parcelable.Creator<NativeNetworkConfig> CREATOR = new android.os.Parcelable.Creator<NativeNetworkConfig>() {
    @Override
    public NativeNetworkConfig createFromParcel(android.os.Parcel _aidl_source) {
      return internalCreateFromParcel(_aidl_source);
    }
    @Override
    public NativeNetworkConfig[] newArray(int _aidl_size) {
      return new NativeNetworkConfig[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(netId);
    _aidl_parcel.writeInt(networkType);
    _aidl_parcel.writeInt(permission);
    _aidl_parcel.writeInt(((secure)?(1):(0)));
    _aidl_parcel.writeInt(vpnType);
    int _aidl_end_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.setDataPosition(_aidl_start_pos);
    _aidl_parcel.writeInt(_aidl_end_pos - _aidl_start_pos);
    _aidl_parcel.setDataPosition(_aidl_end_pos);
  }
  public NativeNetworkConfig(int netId, int networkType, int permission, boolean secure, int vpnType)
  {
    this.netId = netId;
    this.networkType = networkType;
    this.permission = permission;
    this.secure = secure;
    this.vpnType = vpnType;
  }
  private static NativeNetworkConfig internalCreateFromParcel(android.os.Parcel _aidl_parcel)
  {
    Builder _aidl_parcelable_builder = new Builder();
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    int _aidl_parcelable_size = _aidl_parcel.readInt();
    try {
      if (_aidl_parcelable_size < 0) return _aidl_parcelable_builder.build();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return _aidl_parcelable_builder.build();
      int _aidl_temp_netId;
      _aidl_temp_netId = _aidl_parcel.readInt();
      _aidl_parcelable_builder.setNetId(_aidl_temp_netId);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return _aidl_parcelable_builder.build();
      int _aidl_temp_networkType;
      _aidl_temp_networkType = _aidl_parcel.readInt();
      _aidl_parcelable_builder.setNetworkType(_aidl_temp_networkType);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return _aidl_parcelable_builder.build();
      int _aidl_temp_permission;
      _aidl_temp_permission = _aidl_parcel.readInt();
      _aidl_parcelable_builder.setPermission(_aidl_temp_permission);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return _aidl_parcelable_builder.build();
      boolean _aidl_temp_secure;
      _aidl_temp_secure = (0!=_aidl_parcel.readInt());
      _aidl_parcelable_builder.setSecure(_aidl_temp_secure);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return _aidl_parcelable_builder.build();
      int _aidl_temp_vpnType;
      _aidl_temp_vpnType = _aidl_parcel.readInt();
      _aidl_parcelable_builder.setVpnType(_aidl_temp_vpnType);
    } finally {
      if (_aidl_start_pos > (Integer.MAX_VALUE - _aidl_parcelable_size)) {
        throw new android.os.BadParcelableException("Overflow in the size of parcelable");
      }
      _aidl_parcel.setDataPosition(_aidl_start_pos + _aidl_parcelable_size);
      return _aidl_parcelable_builder.build();
    }
  }
  @Override
  public String toString() {
    java.util.StringJoiner _aidl_sj = new java.util.StringJoiner(", ", "{", "}");
    _aidl_sj.add("netId: " + (netId));
    _aidl_sj.add("networkType: " + (networkType));
    _aidl_sj.add("permission: " + (permission));
    _aidl_sj.add("secure: " + (secure));
    _aidl_sj.add("vpnType: " + (vpnType));
    return "android.net.NativeNetworkConfig" + _aidl_sj.toString()  ;
  }
  @Override
  public boolean equals(Object other) {
    if (this == other) return true;
    if (other == null) return false;
    if (!(other instanceof NativeNetworkConfig)) return false;
    NativeNetworkConfig that = (NativeNetworkConfig)other;
    if (!java.util.Objects.deepEquals(netId, that.netId)) return false;
    if (!java.util.Objects.deepEquals(networkType, that.networkType)) return false;
    if (!java.util.Objects.deepEquals(permission, that.permission)) return false;
    if (!java.util.Objects.deepEquals(secure, that.secure)) return false;
    if (!java.util.Objects.deepEquals(vpnType, that.vpnType)) return false;
    return true;
  }

  @Override
  public int hashCode() {
    return java.util.Arrays.deepHashCode(java.util.Arrays.asList(netId, networkType, permission, secure, vpnType).toArray());
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    return _mask;
  }
}
