/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
/** @hide */
public interface INetworkStackConnector extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 10;
  public static final String HASH = "4925f4fdbb270e4f35cc5519a15ed8dd8c69a549";
  /** Default implementation for INetworkStackConnector. */
  public static class Default implements android.net.INetworkStackConnector
  {
    @Override public void makeDhcpServer(java.lang.String ifName, android.net.dhcp.DhcpServingParamsParcel params, android.net.dhcp.IDhcpServerCallbacks cb) throws android.os.RemoteException
    {
    }
    @Override public void makeNetworkMonitor(android.net.Network network, java.lang.String name, android.net.INetworkMonitorCallbacks cb) throws android.os.RemoteException
    {
    }
    @Override public void makeIpClient(java.lang.String ifName, android.net.ip.IIpClientCallbacks callbacks) throws android.os.RemoteException
    {
    }
    @Override public void fetchIpMemoryStore(android.net.IIpMemoryStoreCallbacks cb) throws android.os.RemoteException
    {
    }
    @Override public void allowTestUid(int uid, android.net.INetworkStackStatusCallback cb) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.net.INetworkStackConnector
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.net.INetworkStackConnector interface,
     * generating a proxy if needed.
     */
    public static android.net.INetworkStackConnector asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.net.INetworkStackConnector))) {
        return ((android.net.INetworkStackConnector)iin);
      }
      return new android.net.INetworkStackConnector.Stub.Proxy(obj);
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
        case TRANSACTION_makeDhcpServer:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          android.net.dhcp.DhcpServingParamsParcel _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.net.dhcp.DhcpServingParamsParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          android.net.dhcp.IDhcpServerCallbacks _arg2;
          _arg2 = android.net.dhcp.IDhcpServerCallbacks.Stub.asInterface(data.readStrongBinder());
          this.makeDhcpServer(_arg0, _arg1, _arg2);
          return true;
        }
        case TRANSACTION_makeNetworkMonitor:
        {
          data.enforceInterface(descriptor);
          android.net.Network _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.Network.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          java.lang.String _arg1;
          _arg1 = data.readString();
          android.net.INetworkMonitorCallbacks _arg2;
          _arg2 = android.net.INetworkMonitorCallbacks.Stub.asInterface(data.readStrongBinder());
          this.makeNetworkMonitor(_arg0, _arg1, _arg2);
          return true;
        }
        case TRANSACTION_makeIpClient:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          android.net.ip.IIpClientCallbacks _arg1;
          _arg1 = android.net.ip.IIpClientCallbacks.Stub.asInterface(data.readStrongBinder());
          this.makeIpClient(_arg0, _arg1);
          return true;
        }
        case TRANSACTION_fetchIpMemoryStore:
        {
          data.enforceInterface(descriptor);
          android.net.IIpMemoryStoreCallbacks _arg0;
          _arg0 = android.net.IIpMemoryStoreCallbacks.Stub.asInterface(data.readStrongBinder());
          this.fetchIpMemoryStore(_arg0);
          return true;
        }
        case TRANSACTION_allowTestUid:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.net.INetworkStackStatusCallback _arg1;
          _arg1 = android.net.INetworkStackStatusCallback.Stub.asInterface(data.readStrongBinder());
          this.allowTestUid(_arg0, _arg1);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.net.INetworkStackConnector
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
      @Override public void makeDhcpServer(java.lang.String ifName, android.net.dhcp.DhcpServingParamsParcel params, android.net.dhcp.IDhcpServerCallbacks cb) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          if ((params!=null)) {
            _data.writeInt(1);
            params.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeStrongBinder((((cb!=null))?(cb.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_makeDhcpServer, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().makeDhcpServer(ifName, params, cb);
              return;
            }
            else {
              throw new android.os.RemoteException("Method makeDhcpServer is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void makeNetworkMonitor(android.net.Network network, java.lang.String name, android.net.INetworkMonitorCallbacks cb) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((network!=null)) {
            _data.writeInt(1);
            network.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeString(name);
          _data.writeStrongBinder((((cb!=null))?(cb.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_makeNetworkMonitor, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().makeNetworkMonitor(network, name, cb);
              return;
            }
            else {
              throw new android.os.RemoteException("Method makeNetworkMonitor is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void makeIpClient(java.lang.String ifName, android.net.ip.IIpClientCallbacks callbacks) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeStrongBinder((((callbacks!=null))?(callbacks.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_makeIpClient, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().makeIpClient(ifName, callbacks);
              return;
            }
            else {
              throw new android.os.RemoteException("Method makeIpClient is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void fetchIpMemoryStore(android.net.IIpMemoryStoreCallbacks cb) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((cb!=null))?(cb.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_fetchIpMemoryStore, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().fetchIpMemoryStore(cb);
              return;
            }
            else {
              throw new android.os.RemoteException("Method fetchIpMemoryStore is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void allowTestUid(int uid, android.net.INetworkStackStatusCallback cb) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(uid);
          _data.writeStrongBinder((((cb!=null))?(cb.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_allowTestUid, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().allowTestUid(uid, cb);
              return;
            }
            else {
              throw new android.os.RemoteException("Method allowTestUid is unimplemented.");
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
      public static android.net.INetworkStackConnector sDefaultImpl;
    }
    static final int TRANSACTION_makeDhcpServer = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_makeNetworkMonitor = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_makeIpClient = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_fetchIpMemoryStore = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_allowTestUid = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.net.INetworkStackConnector impl) {
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
    public static android.net.INetworkStackConnector getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$net$INetworkStackConnector".replace('$', '.');
  public void makeDhcpServer(java.lang.String ifName, android.net.dhcp.DhcpServingParamsParcel params, android.net.dhcp.IDhcpServerCallbacks cb) throws android.os.RemoteException;
  public void makeNetworkMonitor(android.net.Network network, java.lang.String name, android.net.INetworkMonitorCallbacks cb) throws android.os.RemoteException;
  public void makeIpClient(java.lang.String ifName, android.net.ip.IIpClientCallbacks callbacks) throws android.os.RemoteException;
  public void fetchIpMemoryStore(android.net.IIpMemoryStoreCallbacks cb) throws android.os.RemoteException;
  public void allowTestUid(int uid, android.net.INetworkStackStatusCallback cb) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
