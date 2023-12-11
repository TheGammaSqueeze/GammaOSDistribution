/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
/** @hide */
public interface INetd extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 3;
  public static final String HASH = "e17c1f9b2068b539b22e3a4a447edea3c80aee4b";
  /** Default implementation for INetd. */
  public static class Default implements android.net.INetd
  {
    @Override public boolean isAlive() throws android.os.RemoteException
    {
      return false;
    }
    @Override public boolean firewallReplaceUidChain(java.lang.String chainName, boolean isWhitelist, int[] uids) throws android.os.RemoteException
    {
      return false;
    }
    @Override public boolean bandwidthEnableDataSaver(boolean enable) throws android.os.RemoteException
    {
      return false;
    }
    @Override public void networkCreatePhysical(int netId, int permission) throws android.os.RemoteException
    {
    }
    @Override public void networkCreateVpn(int netId, boolean secure) throws android.os.RemoteException
    {
    }
    @Override public void networkDestroy(int netId) throws android.os.RemoteException
    {
    }
    @Override public void networkAddInterface(int netId, java.lang.String iface) throws android.os.RemoteException
    {
    }
    @Override public void networkRemoveInterface(int netId, java.lang.String iface) throws android.os.RemoteException
    {
    }
    @Override public void networkAddUidRanges(int netId, android.net.UidRangeParcel[] uidRanges) throws android.os.RemoteException
    {
    }
    @Override public void networkRemoveUidRanges(int netId, android.net.UidRangeParcel[] uidRanges) throws android.os.RemoteException
    {
    }
    @Override public void networkRejectNonSecureVpn(boolean add, android.net.UidRangeParcel[] uidRanges) throws android.os.RemoteException
    {
    }
    @Override public void socketDestroy(android.net.UidRangeParcel[] uidRanges, int[] exemptUids) throws android.os.RemoteException
    {
    }
    @Override public boolean tetherApplyDnsInterfaces() throws android.os.RemoteException
    {
      return false;
    }
    @Override public android.net.TetherStatsParcel[] tetherGetStats() throws android.os.RemoteException
    {
      return null;
    }
    @Override public void interfaceAddAddress(java.lang.String ifName, java.lang.String addrString, int prefixLength) throws android.os.RemoteException
    {
    }
    @Override public void interfaceDelAddress(java.lang.String ifName, java.lang.String addrString, int prefixLength) throws android.os.RemoteException
    {
    }
    @Override public java.lang.String getProcSysNet(int ipversion, int which, java.lang.String ifname, java.lang.String parameter) throws android.os.RemoteException
    {
      return null;
    }
    @Override public void setProcSysNet(int ipversion, int which, java.lang.String ifname, java.lang.String parameter, java.lang.String value) throws android.os.RemoteException
    {
    }
    @Override public void ipSecSetEncapSocketOwner(android.os.ParcelFileDescriptor socket, int newUid) throws android.os.RemoteException
    {
    }
    @Override public int ipSecAllocateSpi(int transformId, java.lang.String sourceAddress, java.lang.String destinationAddress, int spi) throws android.os.RemoteException
    {
      return 0;
    }
    @Override public void ipSecAddSecurityAssociation(int transformId, int mode, java.lang.String sourceAddress, java.lang.String destinationAddress, int underlyingNetId, int spi, int markValue, int markMask, java.lang.String authAlgo, byte[] authKey, int authTruncBits, java.lang.String cryptAlgo, byte[] cryptKey, int cryptTruncBits, java.lang.String aeadAlgo, byte[] aeadKey, int aeadIcvBits, int encapType, int encapLocalPort, int encapRemotePort, int interfaceId) throws android.os.RemoteException
    {
    }
    @Override public void ipSecDeleteSecurityAssociation(int transformId, java.lang.String sourceAddress, java.lang.String destinationAddress, int spi, int markValue, int markMask, int interfaceId) throws android.os.RemoteException
    {
    }
    @Override public void ipSecApplyTransportModeTransform(android.os.ParcelFileDescriptor socket, int transformId, int direction, java.lang.String sourceAddress, java.lang.String destinationAddress, int spi) throws android.os.RemoteException
    {
    }
    @Override public void ipSecRemoveTransportModeTransform(android.os.ParcelFileDescriptor socket) throws android.os.RemoteException
    {
    }
    @Override public void ipSecAddSecurityPolicy(int transformId, int selAddrFamily, int direction, java.lang.String tmplSrcAddress, java.lang.String tmplDstAddress, int spi, int markValue, int markMask, int interfaceId) throws android.os.RemoteException
    {
    }
    @Override public void ipSecUpdateSecurityPolicy(int transformId, int selAddrFamily, int direction, java.lang.String tmplSrcAddress, java.lang.String tmplDstAddress, int spi, int markValue, int markMask, int interfaceId) throws android.os.RemoteException
    {
    }
    @Override public void ipSecDeleteSecurityPolicy(int transformId, int selAddrFamily, int direction, int markValue, int markMask, int interfaceId) throws android.os.RemoteException
    {
    }
    @Override public void ipSecAddTunnelInterface(java.lang.String deviceName, java.lang.String localAddress, java.lang.String remoteAddress, int iKey, int oKey, int interfaceId) throws android.os.RemoteException
    {
    }
    @Override public void ipSecUpdateTunnelInterface(java.lang.String deviceName, java.lang.String localAddress, java.lang.String remoteAddress, int iKey, int oKey, int interfaceId) throws android.os.RemoteException
    {
    }
    @Override public void ipSecRemoveTunnelInterface(java.lang.String deviceName) throws android.os.RemoteException
    {
    }
    @Override public void wakeupAddInterface(java.lang.String ifName, java.lang.String prefix, int mark, int mask) throws android.os.RemoteException
    {
    }
    @Override public void wakeupDelInterface(java.lang.String ifName, java.lang.String prefix, int mark, int mask) throws android.os.RemoteException
    {
    }
    @Override public void setIPv6AddrGenMode(java.lang.String ifName, int mode) throws android.os.RemoteException
    {
    }
    @Override public void idletimerAddInterface(java.lang.String ifName, int timeout, java.lang.String classLabel) throws android.os.RemoteException
    {
    }
    @Override public void idletimerRemoveInterface(java.lang.String ifName, int timeout, java.lang.String classLabel) throws android.os.RemoteException
    {
    }
    @Override public void strictUidCleartextPenalty(int uid, int policyPenalty) throws android.os.RemoteException
    {
    }
    @Override public java.lang.String clatdStart(java.lang.String ifName, java.lang.String nat64Prefix) throws android.os.RemoteException
    {
      return null;
    }
    @Override public void clatdStop(java.lang.String ifName) throws android.os.RemoteException
    {
    }
    @Override public boolean ipfwdEnabled() throws android.os.RemoteException
    {
      return false;
    }
    @Override public java.lang.String[] ipfwdGetRequesterList() throws android.os.RemoteException
    {
      return null;
    }
    @Override public void ipfwdEnableForwarding(java.lang.String requester) throws android.os.RemoteException
    {
    }
    @Override public void ipfwdDisableForwarding(java.lang.String requester) throws android.os.RemoteException
    {
    }
    @Override public void ipfwdAddInterfaceForward(java.lang.String fromIface, java.lang.String toIface) throws android.os.RemoteException
    {
    }
    @Override public void ipfwdRemoveInterfaceForward(java.lang.String fromIface, java.lang.String toIface) throws android.os.RemoteException
    {
    }
    @Override public void bandwidthSetInterfaceQuota(java.lang.String ifName, long bytes) throws android.os.RemoteException
    {
    }
    @Override public void bandwidthRemoveInterfaceQuota(java.lang.String ifName) throws android.os.RemoteException
    {
    }
    @Override public void bandwidthSetInterfaceAlert(java.lang.String ifName, long bytes) throws android.os.RemoteException
    {
    }
    @Override public void bandwidthRemoveInterfaceAlert(java.lang.String ifName) throws android.os.RemoteException
    {
    }
    @Override public void bandwidthSetGlobalAlert(long bytes) throws android.os.RemoteException
    {
    }
    @Override public void bandwidthAddNaughtyApp(int uid) throws android.os.RemoteException
    {
    }
    @Override public void bandwidthRemoveNaughtyApp(int uid) throws android.os.RemoteException
    {
    }
    @Override public void bandwidthAddNiceApp(int uid) throws android.os.RemoteException
    {
    }
    @Override public void bandwidthRemoveNiceApp(int uid) throws android.os.RemoteException
    {
    }
    @Override public void tetherStart(java.lang.String[] dhcpRanges) throws android.os.RemoteException
    {
    }
    @Override public void tetherStop() throws android.os.RemoteException
    {
    }
    @Override public boolean tetherIsEnabled() throws android.os.RemoteException
    {
      return false;
    }
    @Override public void tetherInterfaceAdd(java.lang.String ifName) throws android.os.RemoteException
    {
    }
    @Override public void tetherInterfaceRemove(java.lang.String ifName) throws android.os.RemoteException
    {
    }
    @Override public java.lang.String[] tetherInterfaceList() throws android.os.RemoteException
    {
      return null;
    }
    @Override public void tetherDnsSet(int netId, java.lang.String[] dnsAddrs) throws android.os.RemoteException
    {
    }
    @Override public java.lang.String[] tetherDnsList() throws android.os.RemoteException
    {
      return null;
    }
    @Override public void networkAddRoute(int netId, java.lang.String ifName, java.lang.String destination, java.lang.String nextHop) throws android.os.RemoteException
    {
    }
    @Override public void networkRemoveRoute(int netId, java.lang.String ifName, java.lang.String destination, java.lang.String nextHop) throws android.os.RemoteException
    {
    }
    @Override public void networkAddLegacyRoute(int netId, java.lang.String ifName, java.lang.String destination, java.lang.String nextHop, int uid) throws android.os.RemoteException
    {
    }
    @Override public void networkRemoveLegacyRoute(int netId, java.lang.String ifName, java.lang.String destination, java.lang.String nextHop, int uid) throws android.os.RemoteException
    {
    }
    @Override public int networkGetDefault() throws android.os.RemoteException
    {
      return 0;
    }
    @Override public void networkSetDefault(int netId) throws android.os.RemoteException
    {
    }
    @Override public void networkClearDefault() throws android.os.RemoteException
    {
    }
    @Override public void networkSetPermissionForNetwork(int netId, int permission) throws android.os.RemoteException
    {
    }
    @Override public void networkSetPermissionForUser(int permission, int[] uids) throws android.os.RemoteException
    {
    }
    @Override public void networkClearPermissionForUser(int[] uids) throws android.os.RemoteException
    {
    }
    @Override public void trafficSetNetPermForUids(int permission, int[] uids) throws android.os.RemoteException
    {
    }
    @Override public void networkSetProtectAllow(int uid) throws android.os.RemoteException
    {
    }
    @Override public void networkSetProtectDeny(int uid) throws android.os.RemoteException
    {
    }
    @Override public boolean networkCanProtect(int uid) throws android.os.RemoteException
    {
      return false;
    }
    @Override public void firewallSetFirewallType(int firewalltype) throws android.os.RemoteException
    {
    }
    @Override public void firewallSetInterfaceRule(java.lang.String ifName, int firewallRule) throws android.os.RemoteException
    {
    }
    @Override public void firewallSetUidRule(int childChain, int uid, int firewallRule) throws android.os.RemoteException
    {
    }
    @Override public void firewallEnableChildChain(int childChain, boolean enable) throws android.os.RemoteException
    {
    }
    @Override public java.lang.String[] interfaceGetList() throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.net.InterfaceConfigurationParcel interfaceGetCfg(java.lang.String ifName) throws android.os.RemoteException
    {
      return null;
    }
    @Override public void interfaceSetCfg(android.net.InterfaceConfigurationParcel cfg) throws android.os.RemoteException
    {
    }
    @Override public void interfaceSetIPv6PrivacyExtensions(java.lang.String ifName, boolean enable) throws android.os.RemoteException
    {
    }
    @Override public void interfaceClearAddrs(java.lang.String ifName) throws android.os.RemoteException
    {
    }
    @Override public void interfaceSetEnableIPv6(java.lang.String ifName, boolean enable) throws android.os.RemoteException
    {
    }
    @Override public void interfaceSetMtu(java.lang.String ifName, int mtu) throws android.os.RemoteException
    {
    }
    @Override public void tetherAddForward(java.lang.String intIface, java.lang.String extIface) throws android.os.RemoteException
    {
    }
    @Override public void tetherRemoveForward(java.lang.String intIface, java.lang.String extIface) throws android.os.RemoteException
    {
    }
    @Override public void setTcpRWmemorySize(java.lang.String rmemValues, java.lang.String wmemValues) throws android.os.RemoteException
    {
    }
    @Override public void registerUnsolicitedEventListener(android.net.INetdUnsolicitedEventListener listener) throws android.os.RemoteException
    {
    }
    @Override public void firewallAddUidInterfaceRules(java.lang.String ifName, int[] uids) throws android.os.RemoteException
    {
    }
    @Override public void firewallRemoveUidInterfaceRules(int[] uids) throws android.os.RemoteException
    {
    }
    @Override public void trafficSwapActiveStatsMap() throws android.os.RemoteException
    {
    }
    @Override public android.os.IBinder getOemNetd() throws android.os.RemoteException
    {
      return null;
    }
    @Override public void tetherStartWithConfiguration(android.net.TetherConfigParcel config) throws android.os.RemoteException
    {
    }
    @Override public android.net.MarkMaskParcel getFwmarkForNetwork(int netId) throws android.os.RemoteException
    {
      return null;
    }
    @Override public void networkAddRouteParcel(int netId, android.net.RouteInfoParcel routeInfo) throws android.os.RemoteException
    {
    }
    @Override public void networkUpdateRouteParcel(int netId, android.net.RouteInfoParcel routeInfo) throws android.os.RemoteException
    {
    }
    @Override public void networkRemoveRouteParcel(int netId, android.net.RouteInfoParcel routeInfo) throws android.os.RemoteException
    {
    }
    @Override public void tetherOffloadRuleAdd(android.net.TetherOffloadRuleParcel rule) throws android.os.RemoteException
    {
    }
    @Override public void tetherOffloadRuleRemove(android.net.TetherOffloadRuleParcel rule) throws android.os.RemoteException
    {
    }
    @Override
    public int getInterfaceVersion() {
      return 0;
    }
    @Override
    public String getInterfaceHash() {
      return "";
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements android.net.INetd
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.net.INetd interface,
     * generating a proxy if needed.
     */
    public static android.net.INetd asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.net.INetd))) {
        return ((android.net.INetd)iin);
      }
      return new android.net.INetd.Stub.Proxy(obj);
    }
    @Override public android.os.IBinder asBinder()
    {
      return this;
    }
    @Override public boolean onTransact(int code, android.os.Parcel data, android.os.Parcel reply, int flags) throws android.os.RemoteException
    {
      java.lang.String descriptor = DESCRIPTOR;
      switch (code)
      {
        case INTERFACE_TRANSACTION:
        {
          reply.writeString(descriptor);
          return true;
        }
        case TRANSACTION_getInterfaceVersion:
        {
          data.enforceInterface(descriptor);
          reply.writeNoException();
          reply.writeInt(getInterfaceVersion());
          return true;
        }
        case TRANSACTION_getInterfaceHash:
        {
          data.enforceInterface(descriptor);
          reply.writeNoException();
          reply.writeString(getInterfaceHash());
          return true;
        }
      }
      switch (code)
      {
        case TRANSACTION_isAlive:
        {
          data.enforceInterface(descriptor);
          boolean _result = this.isAlive();
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        case TRANSACTION_firewallReplaceUidChain:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          boolean _arg1;
          _arg1 = (0!=data.readInt());
          int[] _arg2;
          _arg2 = data.createIntArray();
          boolean _result = this.firewallReplaceUidChain(_arg0, _arg1, _arg2);
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        case TRANSACTION_bandwidthEnableDataSaver:
        {
          data.enforceInterface(descriptor);
          boolean _arg0;
          _arg0 = (0!=data.readInt());
          boolean _result = this.bandwidthEnableDataSaver(_arg0);
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        case TRANSACTION_networkCreatePhysical:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          this.networkCreatePhysical(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkCreateVpn:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          boolean _arg1;
          _arg1 = (0!=data.readInt());
          this.networkCreateVpn(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkDestroy:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.networkDestroy(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkAddInterface:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _arg1;
          _arg1 = data.readString();
          this.networkAddInterface(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkRemoveInterface:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _arg1;
          _arg1 = data.readString();
          this.networkRemoveInterface(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkAddUidRanges:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.net.UidRangeParcel[] _arg1;
          _arg1 = data.createTypedArray(android.net.UidRangeParcel.CREATOR);
          this.networkAddUidRanges(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkRemoveUidRanges:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.net.UidRangeParcel[] _arg1;
          _arg1 = data.createTypedArray(android.net.UidRangeParcel.CREATOR);
          this.networkRemoveUidRanges(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkRejectNonSecureVpn:
        {
          data.enforceInterface(descriptor);
          boolean _arg0;
          _arg0 = (0!=data.readInt());
          android.net.UidRangeParcel[] _arg1;
          _arg1 = data.createTypedArray(android.net.UidRangeParcel.CREATOR);
          this.networkRejectNonSecureVpn(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_socketDestroy:
        {
          data.enforceInterface(descriptor);
          android.net.UidRangeParcel[] _arg0;
          _arg0 = data.createTypedArray(android.net.UidRangeParcel.CREATOR);
          int[] _arg1;
          _arg1 = data.createIntArray();
          this.socketDestroy(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_tetherApplyDnsInterfaces:
        {
          data.enforceInterface(descriptor);
          boolean _result = this.tetherApplyDnsInterfaces();
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        case TRANSACTION_tetherGetStats:
        {
          data.enforceInterface(descriptor);
          android.net.TetherStatsParcel[] _result = this.tetherGetStats();
          reply.writeNoException();
          reply.writeTypedArray(_result, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          return true;
        }
        case TRANSACTION_interfaceAddAddress:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          int _arg2;
          _arg2 = data.readInt();
          this.interfaceAddAddress(_arg0, _arg1, _arg2);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_interfaceDelAddress:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          int _arg2;
          _arg2 = data.readInt();
          this.interfaceDelAddress(_arg0, _arg1, _arg2);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getProcSysNet:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          java.lang.String _arg2;
          _arg2 = data.readString();
          java.lang.String _arg3;
          _arg3 = data.readString();
          java.lang.String _result = this.getProcSysNet(_arg0, _arg1, _arg2, _arg3);
          reply.writeNoException();
          reply.writeString(_result);
          return true;
        }
        case TRANSACTION_setProcSysNet:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          java.lang.String _arg2;
          _arg2 = data.readString();
          java.lang.String _arg3;
          _arg3 = data.readString();
          java.lang.String _arg4;
          _arg4 = data.readString();
          this.setProcSysNet(_arg0, _arg1, _arg2, _arg3, _arg4);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipSecSetEncapSocketOwner:
        {
          data.enforceInterface(descriptor);
          android.os.ParcelFileDescriptor _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.os.ParcelFileDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          int _arg1;
          _arg1 = data.readInt();
          this.ipSecSetEncapSocketOwner(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipSecAllocateSpi:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _arg1;
          _arg1 = data.readString();
          java.lang.String _arg2;
          _arg2 = data.readString();
          int _arg3;
          _arg3 = data.readInt();
          int _result = this.ipSecAllocateSpi(_arg0, _arg1, _arg2, _arg3);
          reply.writeNoException();
          reply.writeInt(_result);
          return true;
        }
        case TRANSACTION_ipSecAddSecurityAssociation:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          java.lang.String _arg2;
          _arg2 = data.readString();
          java.lang.String _arg3;
          _arg3 = data.readString();
          int _arg4;
          _arg4 = data.readInt();
          int _arg5;
          _arg5 = data.readInt();
          int _arg6;
          _arg6 = data.readInt();
          int _arg7;
          _arg7 = data.readInt();
          java.lang.String _arg8;
          _arg8 = data.readString();
          byte[] _arg9;
          _arg9 = data.createByteArray();
          int _arg10;
          _arg10 = data.readInt();
          java.lang.String _arg11;
          _arg11 = data.readString();
          byte[] _arg12;
          _arg12 = data.createByteArray();
          int _arg13;
          _arg13 = data.readInt();
          java.lang.String _arg14;
          _arg14 = data.readString();
          byte[] _arg15;
          _arg15 = data.createByteArray();
          int _arg16;
          _arg16 = data.readInt();
          int _arg17;
          _arg17 = data.readInt();
          int _arg18;
          _arg18 = data.readInt();
          int _arg19;
          _arg19 = data.readInt();
          int _arg20;
          _arg20 = data.readInt();
          this.ipSecAddSecurityAssociation(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipSecDeleteSecurityAssociation:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _arg1;
          _arg1 = data.readString();
          java.lang.String _arg2;
          _arg2 = data.readString();
          int _arg3;
          _arg3 = data.readInt();
          int _arg4;
          _arg4 = data.readInt();
          int _arg5;
          _arg5 = data.readInt();
          int _arg6;
          _arg6 = data.readInt();
          this.ipSecDeleteSecurityAssociation(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipSecApplyTransportModeTransform:
        {
          data.enforceInterface(descriptor);
          android.os.ParcelFileDescriptor _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.os.ParcelFileDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          int _arg1;
          _arg1 = data.readInt();
          int _arg2;
          _arg2 = data.readInt();
          java.lang.String _arg3;
          _arg3 = data.readString();
          java.lang.String _arg4;
          _arg4 = data.readString();
          int _arg5;
          _arg5 = data.readInt();
          this.ipSecApplyTransportModeTransform(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipSecRemoveTransportModeTransform:
        {
          data.enforceInterface(descriptor);
          android.os.ParcelFileDescriptor _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.os.ParcelFileDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.ipSecRemoveTransportModeTransform(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipSecAddSecurityPolicy:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          int _arg2;
          _arg2 = data.readInt();
          java.lang.String _arg3;
          _arg3 = data.readString();
          java.lang.String _arg4;
          _arg4 = data.readString();
          int _arg5;
          _arg5 = data.readInt();
          int _arg6;
          _arg6 = data.readInt();
          int _arg7;
          _arg7 = data.readInt();
          int _arg8;
          _arg8 = data.readInt();
          this.ipSecAddSecurityPolicy(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipSecUpdateSecurityPolicy:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          int _arg2;
          _arg2 = data.readInt();
          java.lang.String _arg3;
          _arg3 = data.readString();
          java.lang.String _arg4;
          _arg4 = data.readString();
          int _arg5;
          _arg5 = data.readInt();
          int _arg6;
          _arg6 = data.readInt();
          int _arg7;
          _arg7 = data.readInt();
          int _arg8;
          _arg8 = data.readInt();
          this.ipSecUpdateSecurityPolicy(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipSecDeleteSecurityPolicy:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          int _arg2;
          _arg2 = data.readInt();
          int _arg3;
          _arg3 = data.readInt();
          int _arg4;
          _arg4 = data.readInt();
          int _arg5;
          _arg5 = data.readInt();
          this.ipSecDeleteSecurityPolicy(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipSecAddTunnelInterface:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          java.lang.String _arg2;
          _arg2 = data.readString();
          int _arg3;
          _arg3 = data.readInt();
          int _arg4;
          _arg4 = data.readInt();
          int _arg5;
          _arg5 = data.readInt();
          this.ipSecAddTunnelInterface(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipSecUpdateTunnelInterface:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          java.lang.String _arg2;
          _arg2 = data.readString();
          int _arg3;
          _arg3 = data.readInt();
          int _arg4;
          _arg4 = data.readInt();
          int _arg5;
          _arg5 = data.readInt();
          this.ipSecUpdateTunnelInterface(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipSecRemoveTunnelInterface:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.ipSecRemoveTunnelInterface(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_wakeupAddInterface:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          int _arg2;
          _arg2 = data.readInt();
          int _arg3;
          _arg3 = data.readInt();
          this.wakeupAddInterface(_arg0, _arg1, _arg2, _arg3);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_wakeupDelInterface:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          int _arg2;
          _arg2 = data.readInt();
          int _arg3;
          _arg3 = data.readInt();
          this.wakeupDelInterface(_arg0, _arg1, _arg2, _arg3);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setIPv6AddrGenMode:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          int _arg1;
          _arg1 = data.readInt();
          this.setIPv6AddrGenMode(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_idletimerAddInterface:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          int _arg1;
          _arg1 = data.readInt();
          java.lang.String _arg2;
          _arg2 = data.readString();
          this.idletimerAddInterface(_arg0, _arg1, _arg2);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_idletimerRemoveInterface:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          int _arg1;
          _arg1 = data.readInt();
          java.lang.String _arg2;
          _arg2 = data.readString();
          this.idletimerRemoveInterface(_arg0, _arg1, _arg2);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_strictUidCleartextPenalty:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          this.strictUidCleartextPenalty(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_clatdStart:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          java.lang.String _result = this.clatdStart(_arg0, _arg1);
          reply.writeNoException();
          reply.writeString(_result);
          return true;
        }
        case TRANSACTION_clatdStop:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.clatdStop(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipfwdEnabled:
        {
          data.enforceInterface(descriptor);
          boolean _result = this.ipfwdEnabled();
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        case TRANSACTION_ipfwdGetRequesterList:
        {
          data.enforceInterface(descriptor);
          java.lang.String[] _result = this.ipfwdGetRequesterList();
          reply.writeNoException();
          reply.writeStringArray(_result);
          return true;
        }
        case TRANSACTION_ipfwdEnableForwarding:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.ipfwdEnableForwarding(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipfwdDisableForwarding:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.ipfwdDisableForwarding(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipfwdAddInterfaceForward:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          this.ipfwdAddInterfaceForward(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_ipfwdRemoveInterfaceForward:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          this.ipfwdRemoveInterfaceForward(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_bandwidthSetInterfaceQuota:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          long _arg1;
          _arg1 = data.readLong();
          this.bandwidthSetInterfaceQuota(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_bandwidthRemoveInterfaceQuota:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.bandwidthRemoveInterfaceQuota(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_bandwidthSetInterfaceAlert:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          long _arg1;
          _arg1 = data.readLong();
          this.bandwidthSetInterfaceAlert(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_bandwidthRemoveInterfaceAlert:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.bandwidthRemoveInterfaceAlert(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_bandwidthSetGlobalAlert:
        {
          data.enforceInterface(descriptor);
          long _arg0;
          _arg0 = data.readLong();
          this.bandwidthSetGlobalAlert(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_bandwidthAddNaughtyApp:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.bandwidthAddNaughtyApp(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_bandwidthRemoveNaughtyApp:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.bandwidthRemoveNaughtyApp(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_bandwidthAddNiceApp:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.bandwidthAddNiceApp(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_bandwidthRemoveNiceApp:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.bandwidthRemoveNiceApp(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_tetherStart:
        {
          data.enforceInterface(descriptor);
          java.lang.String[] _arg0;
          _arg0 = data.createStringArray();
          this.tetherStart(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_tetherStop:
        {
          data.enforceInterface(descriptor);
          this.tetherStop();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_tetherIsEnabled:
        {
          data.enforceInterface(descriptor);
          boolean _result = this.tetherIsEnabled();
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        case TRANSACTION_tetherInterfaceAdd:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.tetherInterfaceAdd(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_tetherInterfaceRemove:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.tetherInterfaceRemove(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_tetherInterfaceList:
        {
          data.enforceInterface(descriptor);
          java.lang.String[] _result = this.tetherInterfaceList();
          reply.writeNoException();
          reply.writeStringArray(_result);
          return true;
        }
        case TRANSACTION_tetherDnsSet:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String[] _arg1;
          _arg1 = data.createStringArray();
          this.tetherDnsSet(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_tetherDnsList:
        {
          data.enforceInterface(descriptor);
          java.lang.String[] _result = this.tetherDnsList();
          reply.writeNoException();
          reply.writeStringArray(_result);
          return true;
        }
        case TRANSACTION_networkAddRoute:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _arg1;
          _arg1 = data.readString();
          java.lang.String _arg2;
          _arg2 = data.readString();
          java.lang.String _arg3;
          _arg3 = data.readString();
          this.networkAddRoute(_arg0, _arg1, _arg2, _arg3);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkRemoveRoute:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _arg1;
          _arg1 = data.readString();
          java.lang.String _arg2;
          _arg2 = data.readString();
          java.lang.String _arg3;
          _arg3 = data.readString();
          this.networkRemoveRoute(_arg0, _arg1, _arg2, _arg3);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkAddLegacyRoute:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _arg1;
          _arg1 = data.readString();
          java.lang.String _arg2;
          _arg2 = data.readString();
          java.lang.String _arg3;
          _arg3 = data.readString();
          int _arg4;
          _arg4 = data.readInt();
          this.networkAddLegacyRoute(_arg0, _arg1, _arg2, _arg3, _arg4);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkRemoveLegacyRoute:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _arg1;
          _arg1 = data.readString();
          java.lang.String _arg2;
          _arg2 = data.readString();
          java.lang.String _arg3;
          _arg3 = data.readString();
          int _arg4;
          _arg4 = data.readInt();
          this.networkRemoveLegacyRoute(_arg0, _arg1, _arg2, _arg3, _arg4);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkGetDefault:
        {
          data.enforceInterface(descriptor);
          int _result = this.networkGetDefault();
          reply.writeNoException();
          reply.writeInt(_result);
          return true;
        }
        case TRANSACTION_networkSetDefault:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.networkSetDefault(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkClearDefault:
        {
          data.enforceInterface(descriptor);
          this.networkClearDefault();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkSetPermissionForNetwork:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          this.networkSetPermissionForNetwork(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkSetPermissionForUser:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int[] _arg1;
          _arg1 = data.createIntArray();
          this.networkSetPermissionForUser(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkClearPermissionForUser:
        {
          data.enforceInterface(descriptor);
          int[] _arg0;
          _arg0 = data.createIntArray();
          this.networkClearPermissionForUser(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_trafficSetNetPermForUids:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int[] _arg1;
          _arg1 = data.createIntArray();
          this.trafficSetNetPermForUids(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkSetProtectAllow:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.networkSetProtectAllow(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkSetProtectDeny:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.networkSetProtectDeny(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkCanProtect:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          boolean _result = this.networkCanProtect(_arg0);
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        case TRANSACTION_firewallSetFirewallType:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.firewallSetFirewallType(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_firewallSetInterfaceRule:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          int _arg1;
          _arg1 = data.readInt();
          this.firewallSetInterfaceRule(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_firewallSetUidRule:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          int _arg2;
          _arg2 = data.readInt();
          this.firewallSetUidRule(_arg0, _arg1, _arg2);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_firewallEnableChildChain:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          boolean _arg1;
          _arg1 = (0!=data.readInt());
          this.firewallEnableChildChain(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_interfaceGetList:
        {
          data.enforceInterface(descriptor);
          java.lang.String[] _result = this.interfaceGetList();
          reply.writeNoException();
          reply.writeStringArray(_result);
          return true;
        }
        case TRANSACTION_interfaceGetCfg:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          android.net.InterfaceConfigurationParcel _result = this.interfaceGetCfg(_arg0);
          reply.writeNoException();
          if ((_result!=null)) {
            reply.writeInt(1);
            _result.writeToParcel(reply, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          }
          else {
            reply.writeInt(0);
          }
          return true;
        }
        case TRANSACTION_interfaceSetCfg:
        {
          data.enforceInterface(descriptor);
          android.net.InterfaceConfigurationParcel _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.InterfaceConfigurationParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.interfaceSetCfg(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_interfaceSetIPv6PrivacyExtensions:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          boolean _arg1;
          _arg1 = (0!=data.readInt());
          this.interfaceSetIPv6PrivacyExtensions(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_interfaceClearAddrs:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.interfaceClearAddrs(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_interfaceSetEnableIPv6:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          boolean _arg1;
          _arg1 = (0!=data.readInt());
          this.interfaceSetEnableIPv6(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_interfaceSetMtu:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          int _arg1;
          _arg1 = data.readInt();
          this.interfaceSetMtu(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_tetherAddForward:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          this.tetherAddForward(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_tetherRemoveForward:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          this.tetherRemoveForward(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setTcpRWmemorySize:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          this.setTcpRWmemorySize(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_registerUnsolicitedEventListener:
        {
          data.enforceInterface(descriptor);
          android.net.INetdUnsolicitedEventListener _arg0;
          _arg0 = android.net.INetdUnsolicitedEventListener.Stub.asInterface(data.readStrongBinder());
          this.registerUnsolicitedEventListener(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_firewallAddUidInterfaceRules:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          int[] _arg1;
          _arg1 = data.createIntArray();
          this.firewallAddUidInterfaceRules(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_firewallRemoveUidInterfaceRules:
        {
          data.enforceInterface(descriptor);
          int[] _arg0;
          _arg0 = data.createIntArray();
          this.firewallRemoveUidInterfaceRules(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_trafficSwapActiveStatsMap:
        {
          data.enforceInterface(descriptor);
          this.trafficSwapActiveStatsMap();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getOemNetd:
        {
          data.enforceInterface(descriptor);
          android.os.IBinder _result = this.getOemNetd();
          reply.writeNoException();
          reply.writeStrongBinder(_result);
          return true;
        }
        case TRANSACTION_tetherStartWithConfiguration:
        {
          data.enforceInterface(descriptor);
          android.net.TetherConfigParcel _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.TetherConfigParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.tetherStartWithConfiguration(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getFwmarkForNetwork:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.net.MarkMaskParcel _result = this.getFwmarkForNetwork(_arg0);
          reply.writeNoException();
          if ((_result!=null)) {
            reply.writeInt(1);
            _result.writeToParcel(reply, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          }
          else {
            reply.writeInt(0);
          }
          return true;
        }
        case TRANSACTION_networkAddRouteParcel:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.net.RouteInfoParcel _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.net.RouteInfoParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          this.networkAddRouteParcel(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkUpdateRouteParcel:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.net.RouteInfoParcel _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.net.RouteInfoParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          this.networkUpdateRouteParcel(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_networkRemoveRouteParcel:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.net.RouteInfoParcel _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.net.RouteInfoParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          this.networkRemoveRouteParcel(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_tetherOffloadRuleAdd:
        {
          data.enforceInterface(descriptor);
          android.net.TetherOffloadRuleParcel _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.TetherOffloadRuleParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.tetherOffloadRuleAdd(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_tetherOffloadRuleRemove:
        {
          data.enforceInterface(descriptor);
          android.net.TetherOffloadRuleParcel _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.TetherOffloadRuleParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.tetherOffloadRuleRemove(_arg0);
          reply.writeNoException();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.net.INetd
    {
      private android.os.IBinder mRemote;
      Proxy(android.os.IBinder remote)
      {
        mRemote = remote;
      }
      private int mCachedVersion = -1;
      private String mCachedHash = "-1";
      @Override public android.os.IBinder asBinder()
      {
        return mRemote;
      }
      public java.lang.String getInterfaceDescriptor()
      {
        return DESCRIPTOR;
      }
      @Override public boolean isAlive() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_isAlive, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().isAlive();
            }
            else {
              throw new android.os.RemoteException("Method isAlive is unimplemented.");
            }
          }
          _reply.readException();
          _result = (0!=_reply.readInt());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public boolean firewallReplaceUidChain(java.lang.String chainName, boolean isWhitelist, int[] uids) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(chainName);
          _data.writeInt(((isWhitelist)?(1):(0)));
          _data.writeIntArray(uids);
          boolean _status = mRemote.transact(Stub.TRANSACTION_firewallReplaceUidChain, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().firewallReplaceUidChain(chainName, isWhitelist, uids);
            }
            else {
              throw new android.os.RemoteException("Method firewallReplaceUidChain is unimplemented.");
            }
          }
          _reply.readException();
          _result = (0!=_reply.readInt());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public boolean bandwidthEnableDataSaver(boolean enable) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(((enable)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_bandwidthEnableDataSaver, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().bandwidthEnableDataSaver(enable);
            }
            else {
              throw new android.os.RemoteException("Method bandwidthEnableDataSaver is unimplemented.");
            }
          }
          _reply.readException();
          _result = (0!=_reply.readInt());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void networkCreatePhysical(int netId, int permission) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeInt(permission);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkCreatePhysical, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkCreatePhysical(netId, permission);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkCreatePhysical is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkCreateVpn(int netId, boolean secure) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeInt(((secure)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkCreateVpn, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkCreateVpn(netId, secure);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkCreateVpn is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkDestroy(int netId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkDestroy, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkDestroy(netId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkDestroy is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkAddInterface(int netId, java.lang.String iface) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeString(iface);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkAddInterface, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkAddInterface(netId, iface);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkAddInterface is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkRemoveInterface(int netId, java.lang.String iface) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeString(iface);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkRemoveInterface, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkRemoveInterface(netId, iface);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkRemoveInterface is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkAddUidRanges(int netId, android.net.UidRangeParcel[] uidRanges) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeTypedArray(uidRanges, 0);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkAddUidRanges, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkAddUidRanges(netId, uidRanges);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkAddUidRanges is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkRemoveUidRanges(int netId, android.net.UidRangeParcel[] uidRanges) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeTypedArray(uidRanges, 0);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkRemoveUidRanges, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkRemoveUidRanges(netId, uidRanges);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkRemoveUidRanges is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkRejectNonSecureVpn(boolean add, android.net.UidRangeParcel[] uidRanges) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(((add)?(1):(0)));
          _data.writeTypedArray(uidRanges, 0);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkRejectNonSecureVpn, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkRejectNonSecureVpn(add, uidRanges);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkRejectNonSecureVpn is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void socketDestroy(android.net.UidRangeParcel[] uidRanges, int[] exemptUids) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeTypedArray(uidRanges, 0);
          _data.writeIntArray(exemptUids);
          boolean _status = mRemote.transact(Stub.TRANSACTION_socketDestroy, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().socketDestroy(uidRanges, exemptUids);
              return;
            }
            else {
              throw new android.os.RemoteException("Method socketDestroy is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public boolean tetherApplyDnsInterfaces() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherApplyDnsInterfaces, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().tetherApplyDnsInterfaces();
            }
            else {
              throw new android.os.RemoteException("Method tetherApplyDnsInterfaces is unimplemented.");
            }
          }
          _reply.readException();
          _result = (0!=_reply.readInt());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public android.net.TetherStatsParcel[] tetherGetStats() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.net.TetherStatsParcel[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherGetStats, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().tetherGetStats();
            }
            else {
              throw new android.os.RemoteException("Method tetherGetStats is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createTypedArray(android.net.TetherStatsParcel.CREATOR);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void interfaceAddAddress(java.lang.String ifName, java.lang.String addrString, int prefixLength) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeString(addrString);
          _data.writeInt(prefixLength);
          boolean _status = mRemote.transact(Stub.TRANSACTION_interfaceAddAddress, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().interfaceAddAddress(ifName, addrString, prefixLength);
              return;
            }
            else {
              throw new android.os.RemoteException("Method interfaceAddAddress is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void interfaceDelAddress(java.lang.String ifName, java.lang.String addrString, int prefixLength) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeString(addrString);
          _data.writeInt(prefixLength);
          boolean _status = mRemote.transact(Stub.TRANSACTION_interfaceDelAddress, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().interfaceDelAddress(ifName, addrString, prefixLength);
              return;
            }
            else {
              throw new android.os.RemoteException("Method interfaceDelAddress is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public java.lang.String getProcSysNet(int ipversion, int which, java.lang.String ifname, java.lang.String parameter) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        java.lang.String _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(ipversion);
          _data.writeInt(which);
          _data.writeString(ifname);
          _data.writeString(parameter);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getProcSysNet, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getProcSysNet(ipversion, which, ifname, parameter);
            }
            else {
              throw new android.os.RemoteException("Method getProcSysNet is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.readString();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void setProcSysNet(int ipversion, int which, java.lang.String ifname, java.lang.String parameter, java.lang.String value) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(ipversion);
          _data.writeInt(which);
          _data.writeString(ifname);
          _data.writeString(parameter);
          _data.writeString(value);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setProcSysNet, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setProcSysNet(ipversion, which, ifname, parameter, value);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setProcSysNet is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void ipSecSetEncapSocketOwner(android.os.ParcelFileDescriptor socket, int newUid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((socket!=null)) {
            _data.writeInt(1);
            socket.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeInt(newUid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipSecSetEncapSocketOwner, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipSecSetEncapSocketOwner(socket, newUid);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipSecSetEncapSocketOwner is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public int ipSecAllocateSpi(int transformId, java.lang.String sourceAddress, java.lang.String destinationAddress, int spi) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(transformId);
          _data.writeString(sourceAddress);
          _data.writeString(destinationAddress);
          _data.writeInt(spi);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipSecAllocateSpi, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().ipSecAllocateSpi(transformId, sourceAddress, destinationAddress, spi);
            }
            else {
              throw new android.os.RemoteException("Method ipSecAllocateSpi is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.readInt();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void ipSecAddSecurityAssociation(int transformId, int mode, java.lang.String sourceAddress, java.lang.String destinationAddress, int underlyingNetId, int spi, int markValue, int markMask, java.lang.String authAlgo, byte[] authKey, int authTruncBits, java.lang.String cryptAlgo, byte[] cryptKey, int cryptTruncBits, java.lang.String aeadAlgo, byte[] aeadKey, int aeadIcvBits, int encapType, int encapLocalPort, int encapRemotePort, int interfaceId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(transformId);
          _data.writeInt(mode);
          _data.writeString(sourceAddress);
          _data.writeString(destinationAddress);
          _data.writeInt(underlyingNetId);
          _data.writeInt(spi);
          _data.writeInt(markValue);
          _data.writeInt(markMask);
          _data.writeString(authAlgo);
          _data.writeByteArray(authKey);
          _data.writeInt(authTruncBits);
          _data.writeString(cryptAlgo);
          _data.writeByteArray(cryptKey);
          _data.writeInt(cryptTruncBits);
          _data.writeString(aeadAlgo);
          _data.writeByteArray(aeadKey);
          _data.writeInt(aeadIcvBits);
          _data.writeInt(encapType);
          _data.writeInt(encapLocalPort);
          _data.writeInt(encapRemotePort);
          _data.writeInt(interfaceId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipSecAddSecurityAssociation, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipSecAddSecurityAssociation(transformId, mode, sourceAddress, destinationAddress, underlyingNetId, spi, markValue, markMask, authAlgo, authKey, authTruncBits, cryptAlgo, cryptKey, cryptTruncBits, aeadAlgo, aeadKey, aeadIcvBits, encapType, encapLocalPort, encapRemotePort, interfaceId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipSecAddSecurityAssociation is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void ipSecDeleteSecurityAssociation(int transformId, java.lang.String sourceAddress, java.lang.String destinationAddress, int spi, int markValue, int markMask, int interfaceId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(transformId);
          _data.writeString(sourceAddress);
          _data.writeString(destinationAddress);
          _data.writeInt(spi);
          _data.writeInt(markValue);
          _data.writeInt(markMask);
          _data.writeInt(interfaceId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipSecDeleteSecurityAssociation, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipSecDeleteSecurityAssociation(transformId, sourceAddress, destinationAddress, spi, markValue, markMask, interfaceId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipSecDeleteSecurityAssociation is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void ipSecApplyTransportModeTransform(android.os.ParcelFileDescriptor socket, int transformId, int direction, java.lang.String sourceAddress, java.lang.String destinationAddress, int spi) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((socket!=null)) {
            _data.writeInt(1);
            socket.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeInt(transformId);
          _data.writeInt(direction);
          _data.writeString(sourceAddress);
          _data.writeString(destinationAddress);
          _data.writeInt(spi);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipSecApplyTransportModeTransform, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipSecApplyTransportModeTransform(socket, transformId, direction, sourceAddress, destinationAddress, spi);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipSecApplyTransportModeTransform is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void ipSecRemoveTransportModeTransform(android.os.ParcelFileDescriptor socket) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((socket!=null)) {
            _data.writeInt(1);
            socket.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipSecRemoveTransportModeTransform, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipSecRemoveTransportModeTransform(socket);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipSecRemoveTransportModeTransform is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void ipSecAddSecurityPolicy(int transformId, int selAddrFamily, int direction, java.lang.String tmplSrcAddress, java.lang.String tmplDstAddress, int spi, int markValue, int markMask, int interfaceId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(transformId);
          _data.writeInt(selAddrFamily);
          _data.writeInt(direction);
          _data.writeString(tmplSrcAddress);
          _data.writeString(tmplDstAddress);
          _data.writeInt(spi);
          _data.writeInt(markValue);
          _data.writeInt(markMask);
          _data.writeInt(interfaceId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipSecAddSecurityPolicy, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipSecAddSecurityPolicy(transformId, selAddrFamily, direction, tmplSrcAddress, tmplDstAddress, spi, markValue, markMask, interfaceId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipSecAddSecurityPolicy is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void ipSecUpdateSecurityPolicy(int transformId, int selAddrFamily, int direction, java.lang.String tmplSrcAddress, java.lang.String tmplDstAddress, int spi, int markValue, int markMask, int interfaceId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(transformId);
          _data.writeInt(selAddrFamily);
          _data.writeInt(direction);
          _data.writeString(tmplSrcAddress);
          _data.writeString(tmplDstAddress);
          _data.writeInt(spi);
          _data.writeInt(markValue);
          _data.writeInt(markMask);
          _data.writeInt(interfaceId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipSecUpdateSecurityPolicy, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipSecUpdateSecurityPolicy(transformId, selAddrFamily, direction, tmplSrcAddress, tmplDstAddress, spi, markValue, markMask, interfaceId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipSecUpdateSecurityPolicy is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void ipSecDeleteSecurityPolicy(int transformId, int selAddrFamily, int direction, int markValue, int markMask, int interfaceId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(transformId);
          _data.writeInt(selAddrFamily);
          _data.writeInt(direction);
          _data.writeInt(markValue);
          _data.writeInt(markMask);
          _data.writeInt(interfaceId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipSecDeleteSecurityPolicy, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipSecDeleteSecurityPolicy(transformId, selAddrFamily, direction, markValue, markMask, interfaceId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipSecDeleteSecurityPolicy is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void ipSecAddTunnelInterface(java.lang.String deviceName, java.lang.String localAddress, java.lang.String remoteAddress, int iKey, int oKey, int interfaceId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(deviceName);
          _data.writeString(localAddress);
          _data.writeString(remoteAddress);
          _data.writeInt(iKey);
          _data.writeInt(oKey);
          _data.writeInt(interfaceId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipSecAddTunnelInterface, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipSecAddTunnelInterface(deviceName, localAddress, remoteAddress, iKey, oKey, interfaceId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipSecAddTunnelInterface is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void ipSecUpdateTunnelInterface(java.lang.String deviceName, java.lang.String localAddress, java.lang.String remoteAddress, int iKey, int oKey, int interfaceId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(deviceName);
          _data.writeString(localAddress);
          _data.writeString(remoteAddress);
          _data.writeInt(iKey);
          _data.writeInt(oKey);
          _data.writeInt(interfaceId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipSecUpdateTunnelInterface, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipSecUpdateTunnelInterface(deviceName, localAddress, remoteAddress, iKey, oKey, interfaceId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipSecUpdateTunnelInterface is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void ipSecRemoveTunnelInterface(java.lang.String deviceName) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(deviceName);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipSecRemoveTunnelInterface, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipSecRemoveTunnelInterface(deviceName);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipSecRemoveTunnelInterface is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void wakeupAddInterface(java.lang.String ifName, java.lang.String prefix, int mark, int mask) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeString(prefix);
          _data.writeInt(mark);
          _data.writeInt(mask);
          boolean _status = mRemote.transact(Stub.TRANSACTION_wakeupAddInterface, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().wakeupAddInterface(ifName, prefix, mark, mask);
              return;
            }
            else {
              throw new android.os.RemoteException("Method wakeupAddInterface is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void wakeupDelInterface(java.lang.String ifName, java.lang.String prefix, int mark, int mask) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeString(prefix);
          _data.writeInt(mark);
          _data.writeInt(mask);
          boolean _status = mRemote.transact(Stub.TRANSACTION_wakeupDelInterface, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().wakeupDelInterface(ifName, prefix, mark, mask);
              return;
            }
            else {
              throw new android.os.RemoteException("Method wakeupDelInterface is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void setIPv6AddrGenMode(java.lang.String ifName, int mode) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeInt(mode);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setIPv6AddrGenMode, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setIPv6AddrGenMode(ifName, mode);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setIPv6AddrGenMode is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void idletimerAddInterface(java.lang.String ifName, int timeout, java.lang.String classLabel) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeInt(timeout);
          _data.writeString(classLabel);
          boolean _status = mRemote.transact(Stub.TRANSACTION_idletimerAddInterface, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().idletimerAddInterface(ifName, timeout, classLabel);
              return;
            }
            else {
              throw new android.os.RemoteException("Method idletimerAddInterface is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void idletimerRemoveInterface(java.lang.String ifName, int timeout, java.lang.String classLabel) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeInt(timeout);
          _data.writeString(classLabel);
          boolean _status = mRemote.transact(Stub.TRANSACTION_idletimerRemoveInterface, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().idletimerRemoveInterface(ifName, timeout, classLabel);
              return;
            }
            else {
              throw new android.os.RemoteException("Method idletimerRemoveInterface is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void strictUidCleartextPenalty(int uid, int policyPenalty) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(uid);
          _data.writeInt(policyPenalty);
          boolean _status = mRemote.transact(Stub.TRANSACTION_strictUidCleartextPenalty, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().strictUidCleartextPenalty(uid, policyPenalty);
              return;
            }
            else {
              throw new android.os.RemoteException("Method strictUidCleartextPenalty is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public java.lang.String clatdStart(java.lang.String ifName, java.lang.String nat64Prefix) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        java.lang.String _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeString(nat64Prefix);
          boolean _status = mRemote.transact(Stub.TRANSACTION_clatdStart, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().clatdStart(ifName, nat64Prefix);
            }
            else {
              throw new android.os.RemoteException("Method clatdStart is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.readString();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void clatdStop(java.lang.String ifName) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          boolean _status = mRemote.transact(Stub.TRANSACTION_clatdStop, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().clatdStop(ifName);
              return;
            }
            else {
              throw new android.os.RemoteException("Method clatdStop is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public boolean ipfwdEnabled() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipfwdEnabled, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().ipfwdEnabled();
            }
            else {
              throw new android.os.RemoteException("Method ipfwdEnabled is unimplemented.");
            }
          }
          _reply.readException();
          _result = (0!=_reply.readInt());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public java.lang.String[] ipfwdGetRequesterList() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        java.lang.String[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipfwdGetRequesterList, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().ipfwdGetRequesterList();
            }
            else {
              throw new android.os.RemoteException("Method ipfwdGetRequesterList is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createStringArray();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void ipfwdEnableForwarding(java.lang.String requester) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(requester);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipfwdEnableForwarding, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipfwdEnableForwarding(requester);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipfwdEnableForwarding is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void ipfwdDisableForwarding(java.lang.String requester) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(requester);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipfwdDisableForwarding, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipfwdDisableForwarding(requester);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipfwdDisableForwarding is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void ipfwdAddInterfaceForward(java.lang.String fromIface, java.lang.String toIface) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(fromIface);
          _data.writeString(toIface);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipfwdAddInterfaceForward, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipfwdAddInterfaceForward(fromIface, toIface);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipfwdAddInterfaceForward is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void ipfwdRemoveInterfaceForward(java.lang.String fromIface, java.lang.String toIface) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(fromIface);
          _data.writeString(toIface);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ipfwdRemoveInterfaceForward, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ipfwdRemoveInterfaceForward(fromIface, toIface);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ipfwdRemoveInterfaceForward is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void bandwidthSetInterfaceQuota(java.lang.String ifName, long bytes) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeLong(bytes);
          boolean _status = mRemote.transact(Stub.TRANSACTION_bandwidthSetInterfaceQuota, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().bandwidthSetInterfaceQuota(ifName, bytes);
              return;
            }
            else {
              throw new android.os.RemoteException("Method bandwidthSetInterfaceQuota is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void bandwidthRemoveInterfaceQuota(java.lang.String ifName) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          boolean _status = mRemote.transact(Stub.TRANSACTION_bandwidthRemoveInterfaceQuota, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().bandwidthRemoveInterfaceQuota(ifName);
              return;
            }
            else {
              throw new android.os.RemoteException("Method bandwidthRemoveInterfaceQuota is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void bandwidthSetInterfaceAlert(java.lang.String ifName, long bytes) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeLong(bytes);
          boolean _status = mRemote.transact(Stub.TRANSACTION_bandwidthSetInterfaceAlert, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().bandwidthSetInterfaceAlert(ifName, bytes);
              return;
            }
            else {
              throw new android.os.RemoteException("Method bandwidthSetInterfaceAlert is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void bandwidthRemoveInterfaceAlert(java.lang.String ifName) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          boolean _status = mRemote.transact(Stub.TRANSACTION_bandwidthRemoveInterfaceAlert, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().bandwidthRemoveInterfaceAlert(ifName);
              return;
            }
            else {
              throw new android.os.RemoteException("Method bandwidthRemoveInterfaceAlert is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void bandwidthSetGlobalAlert(long bytes) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeLong(bytes);
          boolean _status = mRemote.transact(Stub.TRANSACTION_bandwidthSetGlobalAlert, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().bandwidthSetGlobalAlert(bytes);
              return;
            }
            else {
              throw new android.os.RemoteException("Method bandwidthSetGlobalAlert is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void bandwidthAddNaughtyApp(int uid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(uid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_bandwidthAddNaughtyApp, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().bandwidthAddNaughtyApp(uid);
              return;
            }
            else {
              throw new android.os.RemoteException("Method bandwidthAddNaughtyApp is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void bandwidthRemoveNaughtyApp(int uid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(uid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_bandwidthRemoveNaughtyApp, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().bandwidthRemoveNaughtyApp(uid);
              return;
            }
            else {
              throw new android.os.RemoteException("Method bandwidthRemoveNaughtyApp is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void bandwidthAddNiceApp(int uid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(uid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_bandwidthAddNiceApp, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().bandwidthAddNiceApp(uid);
              return;
            }
            else {
              throw new android.os.RemoteException("Method bandwidthAddNiceApp is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void bandwidthRemoveNiceApp(int uid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(uid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_bandwidthRemoveNiceApp, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().bandwidthRemoveNiceApp(uid);
              return;
            }
            else {
              throw new android.os.RemoteException("Method bandwidthRemoveNiceApp is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void tetherStart(java.lang.String[] dhcpRanges) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStringArray(dhcpRanges);
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherStart, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().tetherStart(dhcpRanges);
              return;
            }
            else {
              throw new android.os.RemoteException("Method tetherStart is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void tetherStop() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherStop, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().tetherStop();
              return;
            }
            else {
              throw new android.os.RemoteException("Method tetherStop is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public boolean tetherIsEnabled() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherIsEnabled, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().tetherIsEnabled();
            }
            else {
              throw new android.os.RemoteException("Method tetherIsEnabled is unimplemented.");
            }
          }
          _reply.readException();
          _result = (0!=_reply.readInt());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void tetherInterfaceAdd(java.lang.String ifName) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherInterfaceAdd, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().tetherInterfaceAdd(ifName);
              return;
            }
            else {
              throw new android.os.RemoteException("Method tetherInterfaceAdd is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void tetherInterfaceRemove(java.lang.String ifName) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherInterfaceRemove, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().tetherInterfaceRemove(ifName);
              return;
            }
            else {
              throw new android.os.RemoteException("Method tetherInterfaceRemove is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public java.lang.String[] tetherInterfaceList() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        java.lang.String[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherInterfaceList, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().tetherInterfaceList();
            }
            else {
              throw new android.os.RemoteException("Method tetherInterfaceList is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createStringArray();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void tetherDnsSet(int netId, java.lang.String[] dnsAddrs) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeStringArray(dnsAddrs);
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherDnsSet, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().tetherDnsSet(netId, dnsAddrs);
              return;
            }
            else {
              throw new android.os.RemoteException("Method tetherDnsSet is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public java.lang.String[] tetherDnsList() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        java.lang.String[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherDnsList, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().tetherDnsList();
            }
            else {
              throw new android.os.RemoteException("Method tetherDnsList is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createStringArray();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void networkAddRoute(int netId, java.lang.String ifName, java.lang.String destination, java.lang.String nextHop) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeString(ifName);
          _data.writeString(destination);
          _data.writeString(nextHop);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkAddRoute, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkAddRoute(netId, ifName, destination, nextHop);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkAddRoute is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkRemoveRoute(int netId, java.lang.String ifName, java.lang.String destination, java.lang.String nextHop) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeString(ifName);
          _data.writeString(destination);
          _data.writeString(nextHop);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkRemoveRoute, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkRemoveRoute(netId, ifName, destination, nextHop);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkRemoveRoute is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkAddLegacyRoute(int netId, java.lang.String ifName, java.lang.String destination, java.lang.String nextHop, int uid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeString(ifName);
          _data.writeString(destination);
          _data.writeString(nextHop);
          _data.writeInt(uid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkAddLegacyRoute, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkAddLegacyRoute(netId, ifName, destination, nextHop, uid);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkAddLegacyRoute is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkRemoveLegacyRoute(int netId, java.lang.String ifName, java.lang.String destination, java.lang.String nextHop, int uid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeString(ifName);
          _data.writeString(destination);
          _data.writeString(nextHop);
          _data.writeInt(uid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkRemoveLegacyRoute, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkRemoveLegacyRoute(netId, ifName, destination, nextHop, uid);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkRemoveLegacyRoute is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public int networkGetDefault() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkGetDefault, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().networkGetDefault();
            }
            else {
              throw new android.os.RemoteException("Method networkGetDefault is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.readInt();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void networkSetDefault(int netId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkSetDefault, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkSetDefault(netId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkSetDefault is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkClearDefault() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkClearDefault, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkClearDefault();
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkClearDefault is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkSetPermissionForNetwork(int netId, int permission) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeInt(permission);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkSetPermissionForNetwork, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkSetPermissionForNetwork(netId, permission);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkSetPermissionForNetwork is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkSetPermissionForUser(int permission, int[] uids) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(permission);
          _data.writeIntArray(uids);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkSetPermissionForUser, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkSetPermissionForUser(permission, uids);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkSetPermissionForUser is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkClearPermissionForUser(int[] uids) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeIntArray(uids);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkClearPermissionForUser, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkClearPermissionForUser(uids);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkClearPermissionForUser is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void trafficSetNetPermForUids(int permission, int[] uids) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(permission);
          _data.writeIntArray(uids);
          boolean _status = mRemote.transact(Stub.TRANSACTION_trafficSetNetPermForUids, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().trafficSetNetPermForUids(permission, uids);
              return;
            }
            else {
              throw new android.os.RemoteException("Method trafficSetNetPermForUids is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkSetProtectAllow(int uid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(uid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkSetProtectAllow, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkSetProtectAllow(uid);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkSetProtectAllow is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkSetProtectDeny(int uid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(uid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkSetProtectDeny, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkSetProtectDeny(uid);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkSetProtectDeny is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public boolean networkCanProtect(int uid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(uid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkCanProtect, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().networkCanProtect(uid);
            }
            else {
              throw new android.os.RemoteException("Method networkCanProtect is unimplemented.");
            }
          }
          _reply.readException();
          _result = (0!=_reply.readInt());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void firewallSetFirewallType(int firewalltype) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(firewalltype);
          boolean _status = mRemote.transact(Stub.TRANSACTION_firewallSetFirewallType, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().firewallSetFirewallType(firewalltype);
              return;
            }
            else {
              throw new android.os.RemoteException("Method firewallSetFirewallType is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void firewallSetInterfaceRule(java.lang.String ifName, int firewallRule) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeInt(firewallRule);
          boolean _status = mRemote.transact(Stub.TRANSACTION_firewallSetInterfaceRule, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().firewallSetInterfaceRule(ifName, firewallRule);
              return;
            }
            else {
              throw new android.os.RemoteException("Method firewallSetInterfaceRule is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void firewallSetUidRule(int childChain, int uid, int firewallRule) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(childChain);
          _data.writeInt(uid);
          _data.writeInt(firewallRule);
          boolean _status = mRemote.transact(Stub.TRANSACTION_firewallSetUidRule, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().firewallSetUidRule(childChain, uid, firewallRule);
              return;
            }
            else {
              throw new android.os.RemoteException("Method firewallSetUidRule is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void firewallEnableChildChain(int childChain, boolean enable) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(childChain);
          _data.writeInt(((enable)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_firewallEnableChildChain, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().firewallEnableChildChain(childChain, enable);
              return;
            }
            else {
              throw new android.os.RemoteException("Method firewallEnableChildChain is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public java.lang.String[] interfaceGetList() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        java.lang.String[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_interfaceGetList, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().interfaceGetList();
            }
            else {
              throw new android.os.RemoteException("Method interfaceGetList is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createStringArray();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public android.net.InterfaceConfigurationParcel interfaceGetCfg(java.lang.String ifName) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.net.InterfaceConfigurationParcel _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          boolean _status = mRemote.transact(Stub.TRANSACTION_interfaceGetCfg, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().interfaceGetCfg(ifName);
            }
            else {
              throw new android.os.RemoteException("Method interfaceGetCfg is unimplemented.");
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.net.InterfaceConfigurationParcel.CREATOR.createFromParcel(_reply);
          }
          else {
            _result = null;
          }
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void interfaceSetCfg(android.net.InterfaceConfigurationParcel cfg) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((cfg!=null)) {
            _data.writeInt(1);
            cfg.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_interfaceSetCfg, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().interfaceSetCfg(cfg);
              return;
            }
            else {
              throw new android.os.RemoteException("Method interfaceSetCfg is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void interfaceSetIPv6PrivacyExtensions(java.lang.String ifName, boolean enable) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeInt(((enable)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_interfaceSetIPv6PrivacyExtensions, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().interfaceSetIPv6PrivacyExtensions(ifName, enable);
              return;
            }
            else {
              throw new android.os.RemoteException("Method interfaceSetIPv6PrivacyExtensions is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void interfaceClearAddrs(java.lang.String ifName) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          boolean _status = mRemote.transact(Stub.TRANSACTION_interfaceClearAddrs, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().interfaceClearAddrs(ifName);
              return;
            }
            else {
              throw new android.os.RemoteException("Method interfaceClearAddrs is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void interfaceSetEnableIPv6(java.lang.String ifName, boolean enable) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeInt(((enable)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_interfaceSetEnableIPv6, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().interfaceSetEnableIPv6(ifName, enable);
              return;
            }
            else {
              throw new android.os.RemoteException("Method interfaceSetEnableIPv6 is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void interfaceSetMtu(java.lang.String ifName, int mtu) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeInt(mtu);
          boolean _status = mRemote.transact(Stub.TRANSACTION_interfaceSetMtu, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().interfaceSetMtu(ifName, mtu);
              return;
            }
            else {
              throw new android.os.RemoteException("Method interfaceSetMtu is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void tetherAddForward(java.lang.String intIface, java.lang.String extIface) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(intIface);
          _data.writeString(extIface);
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherAddForward, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().tetherAddForward(intIface, extIface);
              return;
            }
            else {
              throw new android.os.RemoteException("Method tetherAddForward is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void tetherRemoveForward(java.lang.String intIface, java.lang.String extIface) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(intIface);
          _data.writeString(extIface);
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherRemoveForward, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().tetherRemoveForward(intIface, extIface);
              return;
            }
            else {
              throw new android.os.RemoteException("Method tetherRemoveForward is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void setTcpRWmemorySize(java.lang.String rmemValues, java.lang.String wmemValues) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(rmemValues);
          _data.writeString(wmemValues);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setTcpRWmemorySize, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setTcpRWmemorySize(rmemValues, wmemValues);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setTcpRWmemorySize is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void registerUnsolicitedEventListener(android.net.INetdUnsolicitedEventListener listener) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((listener!=null))?(listener.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_registerUnsolicitedEventListener, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().registerUnsolicitedEventListener(listener);
              return;
            }
            else {
              throw new android.os.RemoteException("Method registerUnsolicitedEventListener is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void firewallAddUidInterfaceRules(java.lang.String ifName, int[] uids) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeIntArray(uids);
          boolean _status = mRemote.transact(Stub.TRANSACTION_firewallAddUidInterfaceRules, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().firewallAddUidInterfaceRules(ifName, uids);
              return;
            }
            else {
              throw new android.os.RemoteException("Method firewallAddUidInterfaceRules is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void firewallRemoveUidInterfaceRules(int[] uids) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeIntArray(uids);
          boolean _status = mRemote.transact(Stub.TRANSACTION_firewallRemoveUidInterfaceRules, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().firewallRemoveUidInterfaceRules(uids);
              return;
            }
            else {
              throw new android.os.RemoteException("Method firewallRemoveUidInterfaceRules is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void trafficSwapActiveStatsMap() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_trafficSwapActiveStatsMap, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().trafficSwapActiveStatsMap();
              return;
            }
            else {
              throw new android.os.RemoteException("Method trafficSwapActiveStatsMap is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public android.os.IBinder getOemNetd() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.os.IBinder _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getOemNetd, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getOemNetd();
            }
            else {
              throw new android.os.RemoteException("Method getOemNetd is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.readStrongBinder();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void tetherStartWithConfiguration(android.net.TetherConfigParcel config) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((config!=null)) {
            _data.writeInt(1);
            config.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherStartWithConfiguration, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().tetherStartWithConfiguration(config);
              return;
            }
            else {
              throw new android.os.RemoteException("Method tetherStartWithConfiguration is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public android.net.MarkMaskParcel getFwmarkForNetwork(int netId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.net.MarkMaskParcel _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getFwmarkForNetwork, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getFwmarkForNetwork(netId);
            }
            else {
              throw new android.os.RemoteException("Method getFwmarkForNetwork is unimplemented.");
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.net.MarkMaskParcel.CREATOR.createFromParcel(_reply);
          }
          else {
            _result = null;
          }
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void networkAddRouteParcel(int netId, android.net.RouteInfoParcel routeInfo) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          if ((routeInfo!=null)) {
            _data.writeInt(1);
            routeInfo.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkAddRouteParcel, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkAddRouteParcel(netId, routeInfo);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkAddRouteParcel is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkUpdateRouteParcel(int netId, android.net.RouteInfoParcel routeInfo) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          if ((routeInfo!=null)) {
            _data.writeInt(1);
            routeInfo.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkUpdateRouteParcel, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkUpdateRouteParcel(netId, routeInfo);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkUpdateRouteParcel is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void networkRemoveRouteParcel(int netId, android.net.RouteInfoParcel routeInfo) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          if ((routeInfo!=null)) {
            _data.writeInt(1);
            routeInfo.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_networkRemoveRouteParcel, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().networkRemoveRouteParcel(netId, routeInfo);
              return;
            }
            else {
              throw new android.os.RemoteException("Method networkRemoveRouteParcel is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void tetherOffloadRuleAdd(android.net.TetherOffloadRuleParcel rule) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((rule!=null)) {
            _data.writeInt(1);
            rule.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherOffloadRuleAdd, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().tetherOffloadRuleAdd(rule);
              return;
            }
            else {
              throw new android.os.RemoteException("Method tetherOffloadRuleAdd is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void tetherOffloadRuleRemove(android.net.TetherOffloadRuleParcel rule) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((rule!=null)) {
            _data.writeInt(1);
            rule.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_tetherOffloadRuleRemove, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().tetherOffloadRuleRemove(rule);
              return;
            }
            else {
              throw new android.os.RemoteException("Method tetherOffloadRuleRemove is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override
      public int getInterfaceVersion() throws android.os.RemoteException {
        if (mCachedVersion == -1) {
          android.os.Parcel data = android.os.Parcel.obtain();
          android.os.Parcel reply = android.os.Parcel.obtain();
          try {
            data.writeInterfaceToken(DESCRIPTOR);
            boolean _status = mRemote.transact(Stub.TRANSACTION_getInterfaceVersion, data, reply, 0);
            if (!_status) {
              if (getDefaultImpl() != null) {
                return getDefaultImpl().getInterfaceVersion();
              }
            }
            reply.readException();
            mCachedVersion = reply.readInt();
          } finally {
            reply.recycle();
            data.recycle();
          }
        }
        return mCachedVersion;
      }
      @Override
      public synchronized String getInterfaceHash() throws android.os.RemoteException {
        if ("-1".equals(mCachedHash)) {
          android.os.Parcel data = android.os.Parcel.obtain();
          android.os.Parcel reply = android.os.Parcel.obtain();
          try {
            data.writeInterfaceToken(DESCRIPTOR);
            boolean _status = mRemote.transact(Stub.TRANSACTION_getInterfaceHash, data, reply, 0);
            if (!_status) {
              if (getDefaultImpl() != null) {
                return getDefaultImpl().getInterfaceHash();
              }
            }
            reply.readException();
            mCachedHash = reply.readString();
          } finally {
            reply.recycle();
            data.recycle();
          }
        }
        return mCachedHash;
      }
      public static android.net.INetd sDefaultImpl;
    }
    public static final java.lang.String DESCRIPTOR = "android$net$INetd".replace('$', '.');
    static final int TRANSACTION_isAlive = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_firewallReplaceUidChain = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_bandwidthEnableDataSaver = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_networkCreatePhysical = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_networkCreateVpn = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_networkDestroy = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_networkAddInterface = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_networkRemoveInterface = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
    static final int TRANSACTION_networkAddUidRanges = (android.os.IBinder.FIRST_CALL_TRANSACTION + 8);
    static final int TRANSACTION_networkRemoveUidRanges = (android.os.IBinder.FIRST_CALL_TRANSACTION + 9);
    static final int TRANSACTION_networkRejectNonSecureVpn = (android.os.IBinder.FIRST_CALL_TRANSACTION + 10);
    static final int TRANSACTION_socketDestroy = (android.os.IBinder.FIRST_CALL_TRANSACTION + 11);
    static final int TRANSACTION_tetherApplyDnsInterfaces = (android.os.IBinder.FIRST_CALL_TRANSACTION + 12);
    static final int TRANSACTION_tetherGetStats = (android.os.IBinder.FIRST_CALL_TRANSACTION + 13);
    static final int TRANSACTION_interfaceAddAddress = (android.os.IBinder.FIRST_CALL_TRANSACTION + 14);
    static final int TRANSACTION_interfaceDelAddress = (android.os.IBinder.FIRST_CALL_TRANSACTION + 15);
    static final int TRANSACTION_getProcSysNet = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16);
    static final int TRANSACTION_setProcSysNet = (android.os.IBinder.FIRST_CALL_TRANSACTION + 17);
    static final int TRANSACTION_ipSecSetEncapSocketOwner = (android.os.IBinder.FIRST_CALL_TRANSACTION + 18);
    static final int TRANSACTION_ipSecAllocateSpi = (android.os.IBinder.FIRST_CALL_TRANSACTION + 19);
    static final int TRANSACTION_ipSecAddSecurityAssociation = (android.os.IBinder.FIRST_CALL_TRANSACTION + 20);
    static final int TRANSACTION_ipSecDeleteSecurityAssociation = (android.os.IBinder.FIRST_CALL_TRANSACTION + 21);
    static final int TRANSACTION_ipSecApplyTransportModeTransform = (android.os.IBinder.FIRST_CALL_TRANSACTION + 22);
    static final int TRANSACTION_ipSecRemoveTransportModeTransform = (android.os.IBinder.FIRST_CALL_TRANSACTION + 23);
    static final int TRANSACTION_ipSecAddSecurityPolicy = (android.os.IBinder.FIRST_CALL_TRANSACTION + 24);
    static final int TRANSACTION_ipSecUpdateSecurityPolicy = (android.os.IBinder.FIRST_CALL_TRANSACTION + 25);
    static final int TRANSACTION_ipSecDeleteSecurityPolicy = (android.os.IBinder.FIRST_CALL_TRANSACTION + 26);
    static final int TRANSACTION_ipSecAddTunnelInterface = (android.os.IBinder.FIRST_CALL_TRANSACTION + 27);
    static final int TRANSACTION_ipSecUpdateTunnelInterface = (android.os.IBinder.FIRST_CALL_TRANSACTION + 28);
    static final int TRANSACTION_ipSecRemoveTunnelInterface = (android.os.IBinder.FIRST_CALL_TRANSACTION + 29);
    static final int TRANSACTION_wakeupAddInterface = (android.os.IBinder.FIRST_CALL_TRANSACTION + 30);
    static final int TRANSACTION_wakeupDelInterface = (android.os.IBinder.FIRST_CALL_TRANSACTION + 31);
    static final int TRANSACTION_setIPv6AddrGenMode = (android.os.IBinder.FIRST_CALL_TRANSACTION + 32);
    static final int TRANSACTION_idletimerAddInterface = (android.os.IBinder.FIRST_CALL_TRANSACTION + 33);
    static final int TRANSACTION_idletimerRemoveInterface = (android.os.IBinder.FIRST_CALL_TRANSACTION + 34);
    static final int TRANSACTION_strictUidCleartextPenalty = (android.os.IBinder.FIRST_CALL_TRANSACTION + 35);
    static final int TRANSACTION_clatdStart = (android.os.IBinder.FIRST_CALL_TRANSACTION + 36);
    static final int TRANSACTION_clatdStop = (android.os.IBinder.FIRST_CALL_TRANSACTION + 37);
    static final int TRANSACTION_ipfwdEnabled = (android.os.IBinder.FIRST_CALL_TRANSACTION + 38);
    static final int TRANSACTION_ipfwdGetRequesterList = (android.os.IBinder.FIRST_CALL_TRANSACTION + 39);
    static final int TRANSACTION_ipfwdEnableForwarding = (android.os.IBinder.FIRST_CALL_TRANSACTION + 40);
    static final int TRANSACTION_ipfwdDisableForwarding = (android.os.IBinder.FIRST_CALL_TRANSACTION + 41);
    static final int TRANSACTION_ipfwdAddInterfaceForward = (android.os.IBinder.FIRST_CALL_TRANSACTION + 42);
    static final int TRANSACTION_ipfwdRemoveInterfaceForward = (android.os.IBinder.FIRST_CALL_TRANSACTION + 43);
    static final int TRANSACTION_bandwidthSetInterfaceQuota = (android.os.IBinder.FIRST_CALL_TRANSACTION + 44);
    static final int TRANSACTION_bandwidthRemoveInterfaceQuota = (android.os.IBinder.FIRST_CALL_TRANSACTION + 45);
    static final int TRANSACTION_bandwidthSetInterfaceAlert = (android.os.IBinder.FIRST_CALL_TRANSACTION + 46);
    static final int TRANSACTION_bandwidthRemoveInterfaceAlert = (android.os.IBinder.FIRST_CALL_TRANSACTION + 47);
    static final int TRANSACTION_bandwidthSetGlobalAlert = (android.os.IBinder.FIRST_CALL_TRANSACTION + 48);
    static final int TRANSACTION_bandwidthAddNaughtyApp = (android.os.IBinder.FIRST_CALL_TRANSACTION + 49);
    static final int TRANSACTION_bandwidthRemoveNaughtyApp = (android.os.IBinder.FIRST_CALL_TRANSACTION + 50);
    static final int TRANSACTION_bandwidthAddNiceApp = (android.os.IBinder.FIRST_CALL_TRANSACTION + 51);
    static final int TRANSACTION_bandwidthRemoveNiceApp = (android.os.IBinder.FIRST_CALL_TRANSACTION + 52);
    static final int TRANSACTION_tetherStart = (android.os.IBinder.FIRST_CALL_TRANSACTION + 53);
    static final int TRANSACTION_tetherStop = (android.os.IBinder.FIRST_CALL_TRANSACTION + 54);
    static final int TRANSACTION_tetherIsEnabled = (android.os.IBinder.FIRST_CALL_TRANSACTION + 55);
    static final int TRANSACTION_tetherInterfaceAdd = (android.os.IBinder.FIRST_CALL_TRANSACTION + 56);
    static final int TRANSACTION_tetherInterfaceRemove = (android.os.IBinder.FIRST_CALL_TRANSACTION + 57);
    static final int TRANSACTION_tetherInterfaceList = (android.os.IBinder.FIRST_CALL_TRANSACTION + 58);
    static final int TRANSACTION_tetherDnsSet = (android.os.IBinder.FIRST_CALL_TRANSACTION + 59);
    static final int TRANSACTION_tetherDnsList = (android.os.IBinder.FIRST_CALL_TRANSACTION + 60);
    static final int TRANSACTION_networkAddRoute = (android.os.IBinder.FIRST_CALL_TRANSACTION + 61);
    static final int TRANSACTION_networkRemoveRoute = (android.os.IBinder.FIRST_CALL_TRANSACTION + 62);
    static final int TRANSACTION_networkAddLegacyRoute = (android.os.IBinder.FIRST_CALL_TRANSACTION + 63);
    static final int TRANSACTION_networkRemoveLegacyRoute = (android.os.IBinder.FIRST_CALL_TRANSACTION + 64);
    static final int TRANSACTION_networkGetDefault = (android.os.IBinder.FIRST_CALL_TRANSACTION + 65);
    static final int TRANSACTION_networkSetDefault = (android.os.IBinder.FIRST_CALL_TRANSACTION + 66);
    static final int TRANSACTION_networkClearDefault = (android.os.IBinder.FIRST_CALL_TRANSACTION + 67);
    static final int TRANSACTION_networkSetPermissionForNetwork = (android.os.IBinder.FIRST_CALL_TRANSACTION + 68);
    static final int TRANSACTION_networkSetPermissionForUser = (android.os.IBinder.FIRST_CALL_TRANSACTION + 69);
    static final int TRANSACTION_networkClearPermissionForUser = (android.os.IBinder.FIRST_CALL_TRANSACTION + 70);
    static final int TRANSACTION_trafficSetNetPermForUids = (android.os.IBinder.FIRST_CALL_TRANSACTION + 71);
    static final int TRANSACTION_networkSetProtectAllow = (android.os.IBinder.FIRST_CALL_TRANSACTION + 72);
    static final int TRANSACTION_networkSetProtectDeny = (android.os.IBinder.FIRST_CALL_TRANSACTION + 73);
    static final int TRANSACTION_networkCanProtect = (android.os.IBinder.FIRST_CALL_TRANSACTION + 74);
    static final int TRANSACTION_firewallSetFirewallType = (android.os.IBinder.FIRST_CALL_TRANSACTION + 75);
    static final int TRANSACTION_firewallSetInterfaceRule = (android.os.IBinder.FIRST_CALL_TRANSACTION + 76);
    static final int TRANSACTION_firewallSetUidRule = (android.os.IBinder.FIRST_CALL_TRANSACTION + 77);
    static final int TRANSACTION_firewallEnableChildChain = (android.os.IBinder.FIRST_CALL_TRANSACTION + 78);
    static final int TRANSACTION_interfaceGetList = (android.os.IBinder.FIRST_CALL_TRANSACTION + 79);
    static final int TRANSACTION_interfaceGetCfg = (android.os.IBinder.FIRST_CALL_TRANSACTION + 80);
    static final int TRANSACTION_interfaceSetCfg = (android.os.IBinder.FIRST_CALL_TRANSACTION + 81);
    static final int TRANSACTION_interfaceSetIPv6PrivacyExtensions = (android.os.IBinder.FIRST_CALL_TRANSACTION + 82);
    static final int TRANSACTION_interfaceClearAddrs = (android.os.IBinder.FIRST_CALL_TRANSACTION + 83);
    static final int TRANSACTION_interfaceSetEnableIPv6 = (android.os.IBinder.FIRST_CALL_TRANSACTION + 84);
    static final int TRANSACTION_interfaceSetMtu = (android.os.IBinder.FIRST_CALL_TRANSACTION + 85);
    static final int TRANSACTION_tetherAddForward = (android.os.IBinder.FIRST_CALL_TRANSACTION + 86);
    static final int TRANSACTION_tetherRemoveForward = (android.os.IBinder.FIRST_CALL_TRANSACTION + 87);
    static final int TRANSACTION_setTcpRWmemorySize = (android.os.IBinder.FIRST_CALL_TRANSACTION + 88);
    static final int TRANSACTION_registerUnsolicitedEventListener = (android.os.IBinder.FIRST_CALL_TRANSACTION + 89);
    static final int TRANSACTION_firewallAddUidInterfaceRules = (android.os.IBinder.FIRST_CALL_TRANSACTION + 90);
    static final int TRANSACTION_firewallRemoveUidInterfaceRules = (android.os.IBinder.FIRST_CALL_TRANSACTION + 91);
    static final int TRANSACTION_trafficSwapActiveStatsMap = (android.os.IBinder.FIRST_CALL_TRANSACTION + 92);
    static final int TRANSACTION_getOemNetd = (android.os.IBinder.FIRST_CALL_TRANSACTION + 93);
    static final int TRANSACTION_tetherStartWithConfiguration = (android.os.IBinder.FIRST_CALL_TRANSACTION + 94);
    static final int TRANSACTION_getFwmarkForNetwork = (android.os.IBinder.FIRST_CALL_TRANSACTION + 95);
    static final int TRANSACTION_networkAddRouteParcel = (android.os.IBinder.FIRST_CALL_TRANSACTION + 96);
    static final int TRANSACTION_networkUpdateRouteParcel = (android.os.IBinder.FIRST_CALL_TRANSACTION + 97);
    static final int TRANSACTION_networkRemoveRouteParcel = (android.os.IBinder.FIRST_CALL_TRANSACTION + 98);
    static final int TRANSACTION_tetherOffloadRuleAdd = (android.os.IBinder.FIRST_CALL_TRANSACTION + 99);
    static final int TRANSACTION_tetherOffloadRuleRemove = (android.os.IBinder.FIRST_CALL_TRANSACTION + 100);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.net.INetd impl) {
      // Only one user of this interface can use this function
      // at a time. This is a heuristic to detect if two different
      // users in the same process use this function.
      if (Stub.Proxy.sDefaultImpl != null) {
        throw new IllegalStateException("setDefaultImpl() called twice");
      }
      if (impl != null) {
        Stub.Proxy.sDefaultImpl = impl;
        return true;
      }
      return false;
    }
    public static android.net.INetd getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final int IPV4 = 4;
  public static final int IPV6 = 6;
  public static final int CONF = 1;
  public static final int NEIGH = 2;
  public static final String IPSEC_INTERFACE_PREFIX = "ipsec";
  public static final int IPV6_ADDR_GEN_MODE_EUI64 = 0;
  public static final int IPV6_ADDR_GEN_MODE_NONE = 1;
  public static final int IPV6_ADDR_GEN_MODE_STABLE_PRIVACY = 2;
  public static final int IPV6_ADDR_GEN_MODE_RANDOM = 3;
  public static final int IPV6_ADDR_GEN_MODE_DEFAULT = 0;
  public static final int PENALTY_POLICY_ACCEPT = 1;
  public static final int PENALTY_POLICY_LOG = 2;
  public static final int PENALTY_POLICY_REJECT = 3;
  public static final int LOCAL_NET_ID = 99;
  public static final String NEXTHOP_NONE = "";
  public static final String NEXTHOP_UNREACHABLE = "unreachable";
  public static final String NEXTHOP_THROW = "throw";
  public static final int PERMISSION_NONE = 0;
  public static final int PERMISSION_NETWORK = 1;
  public static final int PERMISSION_SYSTEM = 2;
  public static final int NO_PERMISSIONS = 0;
  public static final int PERMISSION_INTERNET = 4;
  public static final int PERMISSION_UPDATE_DEVICE_STATS = 8;
  public static final int PERMISSION_UNINSTALLED = -1;
  public static final int FIREWALL_WHITELIST = 0;
  public static final int FIREWALL_BLACKLIST = 1;
  public static final int FIREWALL_RULE_ALLOW = 1;
  public static final int FIREWALL_RULE_DENY = 2;
  public static final int FIREWALL_CHAIN_NONE = 0;
  public static final int FIREWALL_CHAIN_DOZABLE = 1;
  public static final int FIREWALL_CHAIN_STANDBY = 2;
  public static final int FIREWALL_CHAIN_POWERSAVE = 3;
  public static final String IF_STATE_UP = "up";
  public static final String IF_STATE_DOWN = "down";
  public static final String IF_FLAG_BROADCAST = "broadcast";
  public static final String IF_FLAG_LOOPBACK = "loopback";
  public static final String IF_FLAG_POINTOPOINT = "point-to-point";
  public static final String IF_FLAG_RUNNING = "running";
  public static final String IF_FLAG_MULTICAST = "multicast";
  public boolean isAlive() throws android.os.RemoteException;
  public boolean firewallReplaceUidChain(java.lang.String chainName, boolean isWhitelist, int[] uids) throws android.os.RemoteException;
  public boolean bandwidthEnableDataSaver(boolean enable) throws android.os.RemoteException;
  public void networkCreatePhysical(int netId, int permission) throws android.os.RemoteException;
  public void networkCreateVpn(int netId, boolean secure) throws android.os.RemoteException;
  public void networkDestroy(int netId) throws android.os.RemoteException;
  public void networkAddInterface(int netId, java.lang.String iface) throws android.os.RemoteException;
  public void networkRemoveInterface(int netId, java.lang.String iface) throws android.os.RemoteException;
  public void networkAddUidRanges(int netId, android.net.UidRangeParcel[] uidRanges) throws android.os.RemoteException;
  public void networkRemoveUidRanges(int netId, android.net.UidRangeParcel[] uidRanges) throws android.os.RemoteException;
  public void networkRejectNonSecureVpn(boolean add, android.net.UidRangeParcel[] uidRanges) throws android.os.RemoteException;
  public void socketDestroy(android.net.UidRangeParcel[] uidRanges, int[] exemptUids) throws android.os.RemoteException;
  public boolean tetherApplyDnsInterfaces() throws android.os.RemoteException;
  public android.net.TetherStatsParcel[] tetherGetStats() throws android.os.RemoteException;
  public void interfaceAddAddress(java.lang.String ifName, java.lang.String addrString, int prefixLength) throws android.os.RemoteException;
  public void interfaceDelAddress(java.lang.String ifName, java.lang.String addrString, int prefixLength) throws android.os.RemoteException;
  public java.lang.String getProcSysNet(int ipversion, int which, java.lang.String ifname, java.lang.String parameter) throws android.os.RemoteException;
  public void setProcSysNet(int ipversion, int which, java.lang.String ifname, java.lang.String parameter, java.lang.String value) throws android.os.RemoteException;
  public void ipSecSetEncapSocketOwner(android.os.ParcelFileDescriptor socket, int newUid) throws android.os.RemoteException;
  public int ipSecAllocateSpi(int transformId, java.lang.String sourceAddress, java.lang.String destinationAddress, int spi) throws android.os.RemoteException;
  public void ipSecAddSecurityAssociation(int transformId, int mode, java.lang.String sourceAddress, java.lang.String destinationAddress, int underlyingNetId, int spi, int markValue, int markMask, java.lang.String authAlgo, byte[] authKey, int authTruncBits, java.lang.String cryptAlgo, byte[] cryptKey, int cryptTruncBits, java.lang.String aeadAlgo, byte[] aeadKey, int aeadIcvBits, int encapType, int encapLocalPort, int encapRemotePort, int interfaceId) throws android.os.RemoteException;
  public void ipSecDeleteSecurityAssociation(int transformId, java.lang.String sourceAddress, java.lang.String destinationAddress, int spi, int markValue, int markMask, int interfaceId) throws android.os.RemoteException;
  public void ipSecApplyTransportModeTransform(android.os.ParcelFileDescriptor socket, int transformId, int direction, java.lang.String sourceAddress, java.lang.String destinationAddress, int spi) throws android.os.RemoteException;
  public void ipSecRemoveTransportModeTransform(android.os.ParcelFileDescriptor socket) throws android.os.RemoteException;
  public void ipSecAddSecurityPolicy(int transformId, int selAddrFamily, int direction, java.lang.String tmplSrcAddress, java.lang.String tmplDstAddress, int spi, int markValue, int markMask, int interfaceId) throws android.os.RemoteException;
  public void ipSecUpdateSecurityPolicy(int transformId, int selAddrFamily, int direction, java.lang.String tmplSrcAddress, java.lang.String tmplDstAddress, int spi, int markValue, int markMask, int interfaceId) throws android.os.RemoteException;
  public void ipSecDeleteSecurityPolicy(int transformId, int selAddrFamily, int direction, int markValue, int markMask, int interfaceId) throws android.os.RemoteException;
  public void ipSecAddTunnelInterface(java.lang.String deviceName, java.lang.String localAddress, java.lang.String remoteAddress, int iKey, int oKey, int interfaceId) throws android.os.RemoteException;
  public void ipSecUpdateTunnelInterface(java.lang.String deviceName, java.lang.String localAddress, java.lang.String remoteAddress, int iKey, int oKey, int interfaceId) throws android.os.RemoteException;
  public void ipSecRemoveTunnelInterface(java.lang.String deviceName) throws android.os.RemoteException;
  public void wakeupAddInterface(java.lang.String ifName, java.lang.String prefix, int mark, int mask) throws android.os.RemoteException;
  public void wakeupDelInterface(java.lang.String ifName, java.lang.String prefix, int mark, int mask) throws android.os.RemoteException;
  public void setIPv6AddrGenMode(java.lang.String ifName, int mode) throws android.os.RemoteException;
  public void idletimerAddInterface(java.lang.String ifName, int timeout, java.lang.String classLabel) throws android.os.RemoteException;
  public void idletimerRemoveInterface(java.lang.String ifName, int timeout, java.lang.String classLabel) throws android.os.RemoteException;
  public void strictUidCleartextPenalty(int uid, int policyPenalty) throws android.os.RemoteException;
  public java.lang.String clatdStart(java.lang.String ifName, java.lang.String nat64Prefix) throws android.os.RemoteException;
  public void clatdStop(java.lang.String ifName) throws android.os.RemoteException;
  public boolean ipfwdEnabled() throws android.os.RemoteException;
  public java.lang.String[] ipfwdGetRequesterList() throws android.os.RemoteException;
  public void ipfwdEnableForwarding(java.lang.String requester) throws android.os.RemoteException;
  public void ipfwdDisableForwarding(java.lang.String requester) throws android.os.RemoteException;
  public void ipfwdAddInterfaceForward(java.lang.String fromIface, java.lang.String toIface) throws android.os.RemoteException;
  public void ipfwdRemoveInterfaceForward(java.lang.String fromIface, java.lang.String toIface) throws android.os.RemoteException;
  public void bandwidthSetInterfaceQuota(java.lang.String ifName, long bytes) throws android.os.RemoteException;
  public void bandwidthRemoveInterfaceQuota(java.lang.String ifName) throws android.os.RemoteException;
  public void bandwidthSetInterfaceAlert(java.lang.String ifName, long bytes) throws android.os.RemoteException;
  public void bandwidthRemoveInterfaceAlert(java.lang.String ifName) throws android.os.RemoteException;
  public void bandwidthSetGlobalAlert(long bytes) throws android.os.RemoteException;
  public void bandwidthAddNaughtyApp(int uid) throws android.os.RemoteException;
  public void bandwidthRemoveNaughtyApp(int uid) throws android.os.RemoteException;
  public void bandwidthAddNiceApp(int uid) throws android.os.RemoteException;
  public void bandwidthRemoveNiceApp(int uid) throws android.os.RemoteException;
  public void tetherStart(java.lang.String[] dhcpRanges) throws android.os.RemoteException;
  public void tetherStop() throws android.os.RemoteException;
  public boolean tetherIsEnabled() throws android.os.RemoteException;
  public void tetherInterfaceAdd(java.lang.String ifName) throws android.os.RemoteException;
  public void tetherInterfaceRemove(java.lang.String ifName) throws android.os.RemoteException;
  public java.lang.String[] tetherInterfaceList() throws android.os.RemoteException;
  public void tetherDnsSet(int netId, java.lang.String[] dnsAddrs) throws android.os.RemoteException;
  public java.lang.String[] tetherDnsList() throws android.os.RemoteException;
  public void networkAddRoute(int netId, java.lang.String ifName, java.lang.String destination, java.lang.String nextHop) throws android.os.RemoteException;
  public void networkRemoveRoute(int netId, java.lang.String ifName, java.lang.String destination, java.lang.String nextHop) throws android.os.RemoteException;
  public void networkAddLegacyRoute(int netId, java.lang.String ifName, java.lang.String destination, java.lang.String nextHop, int uid) throws android.os.RemoteException;
  public void networkRemoveLegacyRoute(int netId, java.lang.String ifName, java.lang.String destination, java.lang.String nextHop, int uid) throws android.os.RemoteException;
  public int networkGetDefault() throws android.os.RemoteException;
  public void networkSetDefault(int netId) throws android.os.RemoteException;
  public void networkClearDefault() throws android.os.RemoteException;
  public void networkSetPermissionForNetwork(int netId, int permission) throws android.os.RemoteException;
  public void networkSetPermissionForUser(int permission, int[] uids) throws android.os.RemoteException;
  public void networkClearPermissionForUser(int[] uids) throws android.os.RemoteException;
  public void trafficSetNetPermForUids(int permission, int[] uids) throws android.os.RemoteException;
  public void networkSetProtectAllow(int uid) throws android.os.RemoteException;
  public void networkSetProtectDeny(int uid) throws android.os.RemoteException;
  public boolean networkCanProtect(int uid) throws android.os.RemoteException;
  public void firewallSetFirewallType(int firewalltype) throws android.os.RemoteException;
  public void firewallSetInterfaceRule(java.lang.String ifName, int firewallRule) throws android.os.RemoteException;
  public void firewallSetUidRule(int childChain, int uid, int firewallRule) throws android.os.RemoteException;
  public void firewallEnableChildChain(int childChain, boolean enable) throws android.os.RemoteException;
  public java.lang.String[] interfaceGetList() throws android.os.RemoteException;
  public android.net.InterfaceConfigurationParcel interfaceGetCfg(java.lang.String ifName) throws android.os.RemoteException;
  public void interfaceSetCfg(android.net.InterfaceConfigurationParcel cfg) throws android.os.RemoteException;
  public void interfaceSetIPv6PrivacyExtensions(java.lang.String ifName, boolean enable) throws android.os.RemoteException;
  public void interfaceClearAddrs(java.lang.String ifName) throws android.os.RemoteException;
  public void interfaceSetEnableIPv6(java.lang.String ifName, boolean enable) throws android.os.RemoteException;
  public void interfaceSetMtu(java.lang.String ifName, int mtu) throws android.os.RemoteException;
  public void tetherAddForward(java.lang.String intIface, java.lang.String extIface) throws android.os.RemoteException;
  public void tetherRemoveForward(java.lang.String intIface, java.lang.String extIface) throws android.os.RemoteException;
  public void setTcpRWmemorySize(java.lang.String rmemValues, java.lang.String wmemValues) throws android.os.RemoteException;
  public void registerUnsolicitedEventListener(android.net.INetdUnsolicitedEventListener listener) throws android.os.RemoteException;
  public void firewallAddUidInterfaceRules(java.lang.String ifName, int[] uids) throws android.os.RemoteException;
  public void firewallRemoveUidInterfaceRules(int[] uids) throws android.os.RemoteException;
  public void trafficSwapActiveStatsMap() throws android.os.RemoteException;
  public android.os.IBinder getOemNetd() throws android.os.RemoteException;
  public void tetherStartWithConfiguration(android.net.TetherConfigParcel config) throws android.os.RemoteException;
  public android.net.MarkMaskParcel getFwmarkForNetwork(int netId) throws android.os.RemoteException;
  public void networkAddRouteParcel(int netId, android.net.RouteInfoParcel routeInfo) throws android.os.RemoteException;
  public void networkUpdateRouteParcel(int netId, android.net.RouteInfoParcel routeInfo) throws android.os.RemoteException;
  public void networkRemoveRouteParcel(int netId, android.net.RouteInfoParcel routeInfo) throws android.os.RemoteException;
  public void tetherOffloadRuleAdd(android.net.TetherOffloadRuleParcel rule) throws android.os.RemoteException;
  public void tetherOffloadRuleRemove(android.net.TetherOffloadRuleParcel rule) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
