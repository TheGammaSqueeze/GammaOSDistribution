/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
public class ProvisioningConfigurationParcelable implements android.os.Parcelable
{
  public boolean enableIPv4 = false;
  public boolean enableIPv6 = false;
  public boolean usingMultinetworkPolicyTracker = false;
  public boolean usingIpReachabilityMonitor = false;
  public int requestedPreDhcpActionMs = 0;
  public android.net.InitialConfigurationParcelable initialConfig;
  public android.net.StaticIpConfiguration staticIpConfig;
  public android.net.apf.ApfCapabilities apfCapabilities;
  public int provisioningTimeoutMs = 0;
  public int ipv6AddrGenMode = 0;
  public android.net.Network network;
  public java.lang.String displayName;
  public boolean enablePreconnection = false;
  public android.net.ScanResultInfoParcelable scanResultInfo;
  public android.net.Layer2InformationParcelable layer2Info;
  public java.util.List<android.net.networkstack.aidl.dhcp.DhcpOption> options;
  public static final android.os.Parcelable.Creator<ProvisioningConfigurationParcelable> CREATOR = new android.os.Parcelable.Creator<ProvisioningConfigurationParcelable>() {
    @Override
    public ProvisioningConfigurationParcelable createFromParcel(android.os.Parcel _aidl_source) {
      ProvisioningConfigurationParcelable _aidl_out = new ProvisioningConfigurationParcelable();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public ProvisioningConfigurationParcelable[] newArray(int _aidl_size) {
      return new ProvisioningConfigurationParcelable[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(((enableIPv4)?(1):(0)));
    _aidl_parcel.writeInt(((enableIPv6)?(1):(0)));
    _aidl_parcel.writeInt(((usingMultinetworkPolicyTracker)?(1):(0)));
    _aidl_parcel.writeInt(((usingIpReachabilityMonitor)?(1):(0)));
    _aidl_parcel.writeInt(requestedPreDhcpActionMs);
    if ((initialConfig!=null)) {
      _aidl_parcel.writeInt(1);
      initialConfig.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    if ((staticIpConfig!=null)) {
      _aidl_parcel.writeInt(1);
      staticIpConfig.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    if ((apfCapabilities!=null)) {
      _aidl_parcel.writeInt(1);
      apfCapabilities.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeInt(provisioningTimeoutMs);
    _aidl_parcel.writeInt(ipv6AddrGenMode);
    if ((network!=null)) {
      _aidl_parcel.writeInt(1);
      network.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeString(displayName);
    _aidl_parcel.writeInt(((enablePreconnection)?(1):(0)));
    if ((scanResultInfo!=null)) {
      _aidl_parcel.writeInt(1);
      scanResultInfo.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    if ((layer2Info!=null)) {
      _aidl_parcel.writeInt(1);
      layer2Info.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeTypedList(options);
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
      enableIPv4 = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      enableIPv6 = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      usingMultinetworkPolicyTracker = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      usingIpReachabilityMonitor = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      requestedPreDhcpActionMs = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        initialConfig = android.net.InitialConfigurationParcelable.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        initialConfig = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        staticIpConfig = android.net.StaticIpConfiguration.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        staticIpConfig = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        apfCapabilities = android.net.apf.ApfCapabilities.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        apfCapabilities = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      provisioningTimeoutMs = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      ipv6AddrGenMode = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        network = android.net.Network.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        network = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      displayName = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      enablePreconnection = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        scanResultInfo = android.net.ScanResultInfoParcelable.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        scanResultInfo = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        layer2Info = android.net.Layer2InformationParcelable.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        layer2Info = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      options = _aidl_parcel.createTypedArrayList(android.net.networkstack.aidl.dhcp.DhcpOption.CREATOR);
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
    _aidl_sj.add("enableIPv4: " + (enableIPv4));
    _aidl_sj.add("enableIPv6: " + (enableIPv6));
    _aidl_sj.add("usingMultinetworkPolicyTracker: " + (usingMultinetworkPolicyTracker));
    _aidl_sj.add("usingIpReachabilityMonitor: " + (usingIpReachabilityMonitor));
    _aidl_sj.add("requestedPreDhcpActionMs: " + (requestedPreDhcpActionMs));
    _aidl_sj.add("initialConfig: " + (java.util.Objects.toString(initialConfig)));
    _aidl_sj.add("staticIpConfig: " + (java.util.Objects.toString(staticIpConfig)));
    _aidl_sj.add("apfCapabilities: " + (java.util.Objects.toString(apfCapabilities)));
    _aidl_sj.add("provisioningTimeoutMs: " + (provisioningTimeoutMs));
    _aidl_sj.add("ipv6AddrGenMode: " + (ipv6AddrGenMode));
    _aidl_sj.add("network: " + (java.util.Objects.toString(network)));
    _aidl_sj.add("displayName: " + (java.util.Objects.toString(displayName)));
    _aidl_sj.add("enablePreconnection: " + (enablePreconnection));
    _aidl_sj.add("scanResultInfo: " + (java.util.Objects.toString(scanResultInfo)));
    _aidl_sj.add("layer2Info: " + (java.util.Objects.toString(layer2Info)));
    _aidl_sj.add("options: " + (java.util.Objects.toString(options)));
    return "android.net.ProvisioningConfigurationParcelable" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    _mask |= describeContents(initialConfig);
    _mask |= describeContents(staticIpConfig);
    _mask |= describeContents(apfCapabilities);
    _mask |= describeContents(network);
    _mask |= describeContents(scanResultInfo);
    _mask |= describeContents(layer2Info);
    _mask |= describeContents(options);
    return _mask;
  }
  private int describeContents(Object _v) {
    if (_v == null) return 0;
    if (_v instanceof java.util.Collection) {
      int _mask = 0;
      for (Object o : (java.util.Collection) _v) {
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
