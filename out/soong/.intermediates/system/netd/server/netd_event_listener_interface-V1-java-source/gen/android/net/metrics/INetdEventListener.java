/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net.metrics;
public interface INetdEventListener extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 1;
  public static final String HASH = "8e27594d285ca7c567d87e8cf74766c27647e02b";
  /** Default implementation for INetdEventListener. */
  public static class Default implements android.net.metrics.INetdEventListener
  {
    @Override public void onDnsEvent(int netId, int eventType, int returnCode, int latencyMs, java.lang.String hostname, java.lang.String[] ipAddresses, int ipAddressesCount, int uid) throws android.os.RemoteException
    {
    }
    @Override public void onPrivateDnsValidationEvent(int netId, java.lang.String ipAddress, java.lang.String hostname, boolean validated) throws android.os.RemoteException
    {
    }
    @Override public void onConnectEvent(int netId, int error, int latencyMs, java.lang.String ipAddr, int port, int uid) throws android.os.RemoteException
    {
    }
    @Override public void onWakeupEvent(java.lang.String prefix, int uid, int ethertype, int ipNextHeader, byte[] dstHw, java.lang.String srcIp, java.lang.String dstIp, int srcPort, int dstPort, long timestampNs) throws android.os.RemoteException
    {
    }
    @Override public void onTcpSocketStatsEvent(int[] networkIds, int[] sentPackets, int[] lostPackets, int[] rttUs, int[] sentAckDiffMs) throws android.os.RemoteException
    {
    }
    @Override public void onNat64PrefixEvent(int netId, boolean added, java.lang.String prefixString, int prefixLength) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.net.metrics.INetdEventListener
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.net.metrics.INetdEventListener interface,
     * generating a proxy if needed.
     */
    public static android.net.metrics.INetdEventListener asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.net.metrics.INetdEventListener))) {
        return ((android.net.metrics.INetdEventListener)iin);
      }
      return new android.net.metrics.INetdEventListener.Stub.Proxy(obj);
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
        case TRANSACTION_onDnsEvent:
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
          java.lang.String _arg4;
          _arg4 = data.readString();
          java.lang.String[] _arg5;
          _arg5 = data.createStringArray();
          int _arg6;
          _arg6 = data.readInt();
          int _arg7;
          _arg7 = data.readInt();
          this.onDnsEvent(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7);
          return true;
        }
        case TRANSACTION_onPrivateDnsValidationEvent:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _arg1;
          _arg1 = data.readString();
          java.lang.String _arg2;
          _arg2 = data.readString();
          boolean _arg3;
          _arg3 = (0!=data.readInt());
          this.onPrivateDnsValidationEvent(_arg0, _arg1, _arg2, _arg3);
          return true;
        }
        case TRANSACTION_onConnectEvent:
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
          int _arg4;
          _arg4 = data.readInt();
          int _arg5;
          _arg5 = data.readInt();
          this.onConnectEvent(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5);
          return true;
        }
        case TRANSACTION_onWakeupEvent:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          int _arg1;
          _arg1 = data.readInt();
          int _arg2;
          _arg2 = data.readInt();
          int _arg3;
          _arg3 = data.readInt();
          byte[] _arg4;
          _arg4 = data.createByteArray();
          java.lang.String _arg5;
          _arg5 = data.readString();
          java.lang.String _arg6;
          _arg6 = data.readString();
          int _arg7;
          _arg7 = data.readInt();
          int _arg8;
          _arg8 = data.readInt();
          long _arg9;
          _arg9 = data.readLong();
          this.onWakeupEvent(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9);
          return true;
        }
        case TRANSACTION_onTcpSocketStatsEvent:
        {
          data.enforceInterface(descriptor);
          int[] _arg0;
          _arg0 = data.createIntArray();
          int[] _arg1;
          _arg1 = data.createIntArray();
          int[] _arg2;
          _arg2 = data.createIntArray();
          int[] _arg3;
          _arg3 = data.createIntArray();
          int[] _arg4;
          _arg4 = data.createIntArray();
          this.onTcpSocketStatsEvent(_arg0, _arg1, _arg2, _arg3, _arg4);
          return true;
        }
        case TRANSACTION_onNat64PrefixEvent:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          boolean _arg1;
          _arg1 = (0!=data.readInt());
          java.lang.String _arg2;
          _arg2 = data.readString();
          int _arg3;
          _arg3 = data.readInt();
          this.onNat64PrefixEvent(_arg0, _arg1, _arg2, _arg3);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.net.metrics.INetdEventListener
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
      @Override public void onDnsEvent(int netId, int eventType, int returnCode, int latencyMs, java.lang.String hostname, java.lang.String[] ipAddresses, int ipAddressesCount, int uid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeInt(eventType);
          _data.writeInt(returnCode);
          _data.writeInt(latencyMs);
          _data.writeString(hostname);
          _data.writeStringArray(ipAddresses);
          _data.writeInt(ipAddressesCount);
          _data.writeInt(uid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onDnsEvent, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onDnsEvent(netId, eventType, returnCode, latencyMs, hostname, ipAddresses, ipAddressesCount, uid);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onDnsEvent is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onPrivateDnsValidationEvent(int netId, java.lang.String ipAddress, java.lang.String hostname, boolean validated) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeString(ipAddress);
          _data.writeString(hostname);
          _data.writeInt(((validated)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_onPrivateDnsValidationEvent, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onPrivateDnsValidationEvent(netId, ipAddress, hostname, validated);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onPrivateDnsValidationEvent is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onConnectEvent(int netId, int error, int latencyMs, java.lang.String ipAddr, int port, int uid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeInt(error);
          _data.writeInt(latencyMs);
          _data.writeString(ipAddr);
          _data.writeInt(port);
          _data.writeInt(uid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onConnectEvent, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onConnectEvent(netId, error, latencyMs, ipAddr, port, uid);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onConnectEvent is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onWakeupEvent(java.lang.String prefix, int uid, int ethertype, int ipNextHeader, byte[] dstHw, java.lang.String srcIp, java.lang.String dstIp, int srcPort, int dstPort, long timestampNs) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(prefix);
          _data.writeInt(uid);
          _data.writeInt(ethertype);
          _data.writeInt(ipNextHeader);
          _data.writeByteArray(dstHw);
          _data.writeString(srcIp);
          _data.writeString(dstIp);
          _data.writeInt(srcPort);
          _data.writeInt(dstPort);
          _data.writeLong(timestampNs);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onWakeupEvent, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onWakeupEvent(prefix, uid, ethertype, ipNextHeader, dstHw, srcIp, dstIp, srcPort, dstPort, timestampNs);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onWakeupEvent is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onTcpSocketStatsEvent(int[] networkIds, int[] sentPackets, int[] lostPackets, int[] rttUs, int[] sentAckDiffMs) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeIntArray(networkIds);
          _data.writeIntArray(sentPackets);
          _data.writeIntArray(lostPackets);
          _data.writeIntArray(rttUs);
          _data.writeIntArray(sentAckDiffMs);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onTcpSocketStatsEvent, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onTcpSocketStatsEvent(networkIds, sentPackets, lostPackets, rttUs, sentAckDiffMs);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onTcpSocketStatsEvent is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onNat64PrefixEvent(int netId, boolean added, java.lang.String prefixString, int prefixLength) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeInt(((added)?(1):(0)));
          _data.writeString(prefixString);
          _data.writeInt(prefixLength);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onNat64PrefixEvent, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onNat64PrefixEvent(netId, added, prefixString, prefixLength);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onNat64PrefixEvent is unimplemented.");
            }
          }
        }
        finally {
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
      public static android.net.metrics.INetdEventListener sDefaultImpl;
    }
    static final int TRANSACTION_onDnsEvent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_onPrivateDnsValidationEvent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_onConnectEvent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_onWakeupEvent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_onTcpSocketStatsEvent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_onNat64PrefixEvent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.net.metrics.INetdEventListener impl) {
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
    public static android.net.metrics.INetdEventListener getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$net$metrics$INetdEventListener".replace('$', '.');
  public static final int EVENT_GETADDRINFO = 1;
  public static final int EVENT_GETHOSTBYNAME = 2;
  public static final int EVENT_GETHOSTBYADDR = 3;
  public static final int EVENT_RES_NSEND = 4;
  public static final int REPORTING_LEVEL_NONE = 0;
  public static final int REPORTING_LEVEL_METRICS = 1;
  public static final int REPORTING_LEVEL_FULL = 2;
  public static final int DNS_REPORTED_IP_ADDRESSES_LIMIT = 10;
  public void onDnsEvent(int netId, int eventType, int returnCode, int latencyMs, java.lang.String hostname, java.lang.String[] ipAddresses, int ipAddressesCount, int uid) throws android.os.RemoteException;
  public void onPrivateDnsValidationEvent(int netId, java.lang.String ipAddress, java.lang.String hostname, boolean validated) throws android.os.RemoteException;
  public void onConnectEvent(int netId, int error, int latencyMs, java.lang.String ipAddr, int port, int uid) throws android.os.RemoteException;
  public void onWakeupEvent(java.lang.String prefix, int uid, int ethertype, int ipNextHeader, byte[] dstHw, java.lang.String srcIp, java.lang.String dstIp, int srcPort, int dstPort, long timestampNs) throws android.os.RemoteException;
  public void onTcpSocketStatsEvent(int[] networkIds, int[] sentPackets, int[] lostPackets, int[] rttUs, int[] sentAckDiffMs) throws android.os.RemoteException;
  public void onNat64PrefixEvent(int netId, boolean added, java.lang.String prefixString, int prefixLength) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
