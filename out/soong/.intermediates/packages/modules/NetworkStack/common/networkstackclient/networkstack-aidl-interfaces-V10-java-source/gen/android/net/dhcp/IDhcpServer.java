/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net.dhcp;
/** @hide */
public interface IDhcpServer extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 10;
  public static final String HASH = "4925f4fdbb270e4f35cc5519a15ed8dd8c69a549";
  /** Default implementation for IDhcpServer. */
  public static class Default implements android.net.dhcp.IDhcpServer
  {
    @Override public void start(android.net.INetworkStackStatusCallback cb) throws android.os.RemoteException
    {
    }
    @Override public void startWithCallbacks(android.net.INetworkStackStatusCallback statusCb, android.net.dhcp.IDhcpEventCallbacks eventCb) throws android.os.RemoteException
    {
    }
    @Override public void updateParams(android.net.dhcp.DhcpServingParamsParcel params, android.net.INetworkStackStatusCallback cb) throws android.os.RemoteException
    {
    }
    @Override public void stop(android.net.INetworkStackStatusCallback cb) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.net.dhcp.IDhcpServer
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.net.dhcp.IDhcpServer interface,
     * generating a proxy if needed.
     */
    public static android.net.dhcp.IDhcpServer asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.net.dhcp.IDhcpServer))) {
        return ((android.net.dhcp.IDhcpServer)iin);
      }
      return new android.net.dhcp.IDhcpServer.Stub.Proxy(obj);
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
        case TRANSACTION_start:
        {
          data.enforceInterface(descriptor);
          android.net.INetworkStackStatusCallback _arg0;
          _arg0 = android.net.INetworkStackStatusCallback.Stub.asInterface(data.readStrongBinder());
          this.start(_arg0);
          return true;
        }
        case TRANSACTION_startWithCallbacks:
        {
          data.enforceInterface(descriptor);
          android.net.INetworkStackStatusCallback _arg0;
          _arg0 = android.net.INetworkStackStatusCallback.Stub.asInterface(data.readStrongBinder());
          android.net.dhcp.IDhcpEventCallbacks _arg1;
          _arg1 = android.net.dhcp.IDhcpEventCallbacks.Stub.asInterface(data.readStrongBinder());
          this.startWithCallbacks(_arg0, _arg1);
          return true;
        }
        case TRANSACTION_updateParams:
        {
          data.enforceInterface(descriptor);
          android.net.dhcp.DhcpServingParamsParcel _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.dhcp.DhcpServingParamsParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          android.net.INetworkStackStatusCallback _arg1;
          _arg1 = android.net.INetworkStackStatusCallback.Stub.asInterface(data.readStrongBinder());
          this.updateParams(_arg0, _arg1);
          return true;
        }
        case TRANSACTION_stop:
        {
          data.enforceInterface(descriptor);
          android.net.INetworkStackStatusCallback _arg0;
          _arg0 = android.net.INetworkStackStatusCallback.Stub.asInterface(data.readStrongBinder());
          this.stop(_arg0);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.net.dhcp.IDhcpServer
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
      @Override public void start(android.net.INetworkStackStatusCallback cb) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((cb!=null))?(cb.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_start, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().start(cb);
              return;
            }
            else {
              throw new android.os.RemoteException("Method start is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void startWithCallbacks(android.net.INetworkStackStatusCallback statusCb, android.net.dhcp.IDhcpEventCallbacks eventCb) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((statusCb!=null))?(statusCb.asBinder()):(null)));
          _data.writeStrongBinder((((eventCb!=null))?(eventCb.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_startWithCallbacks, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().startWithCallbacks(statusCb, eventCb);
              return;
            }
            else {
              throw new android.os.RemoteException("Method startWithCallbacks is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void updateParams(android.net.dhcp.DhcpServingParamsParcel params, android.net.INetworkStackStatusCallback cb) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((params!=null)) {
            _data.writeInt(1);
            params.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeStrongBinder((((cb!=null))?(cb.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_updateParams, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().updateParams(params, cb);
              return;
            }
            else {
              throw new android.os.RemoteException("Method updateParams is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void stop(android.net.INetworkStackStatusCallback cb) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((cb!=null))?(cb.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_stop, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().stop(cb);
              return;
            }
            else {
              throw new android.os.RemoteException("Method stop is unimplemented.");
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
      public static android.net.dhcp.IDhcpServer sDefaultImpl;
    }
    static final int TRANSACTION_start = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_startWithCallbacks = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_updateParams = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_stop = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.net.dhcp.IDhcpServer impl) {
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
    public static android.net.dhcp.IDhcpServer getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$net$dhcp$IDhcpServer".replace('$', '.');
  public static final int STATUS_UNKNOWN = 0;
  public static final int STATUS_SUCCESS = 1;
  public static final int STATUS_INVALID_ARGUMENT = 2;
  public static final int STATUS_UNKNOWN_ERROR = 3;
  public void start(android.net.INetworkStackStatusCallback cb) throws android.os.RemoteException;
  public void startWithCallbacks(android.net.INetworkStackStatusCallback statusCb, android.net.dhcp.IDhcpEventCallbacks eventCb) throws android.os.RemoteException;
  public void updateParams(android.net.dhcp.DhcpServingParamsParcel params, android.net.INetworkStackStatusCallback cb) throws android.os.RemoteException;
  public void stop(android.net.INetworkStackStatusCallback cb) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
