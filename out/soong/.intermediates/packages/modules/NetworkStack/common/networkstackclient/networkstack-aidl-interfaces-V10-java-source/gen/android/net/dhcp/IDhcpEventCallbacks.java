/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net.dhcp;
public interface IDhcpEventCallbacks extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 10;
  public static final String HASH = "4925f4fdbb270e4f35cc5519a15ed8dd8c69a549";
  /** Default implementation for IDhcpEventCallbacks. */
  public static class Default implements android.net.dhcp.IDhcpEventCallbacks
  {
    @Override public void onLeasesChanged(java.util.List<android.net.dhcp.DhcpLeaseParcelable> newLeases) throws android.os.RemoteException
    {
    }
    @Override public void onNewPrefixRequest(android.net.IpPrefix currentPrefix) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.net.dhcp.IDhcpEventCallbacks
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.net.dhcp.IDhcpEventCallbacks interface,
     * generating a proxy if needed.
     */
    public static android.net.dhcp.IDhcpEventCallbacks asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.net.dhcp.IDhcpEventCallbacks))) {
        return ((android.net.dhcp.IDhcpEventCallbacks)iin);
      }
      return new android.net.dhcp.IDhcpEventCallbacks.Stub.Proxy(obj);
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
        case TRANSACTION_onLeasesChanged:
        {
          data.enforceInterface(descriptor);
          java.util.List<android.net.dhcp.DhcpLeaseParcelable> _arg0;
          _arg0 = data.createTypedArrayList(android.net.dhcp.DhcpLeaseParcelable.CREATOR);
          this.onLeasesChanged(_arg0);
          return true;
        }
        case TRANSACTION_onNewPrefixRequest:
        {
          data.enforceInterface(descriptor);
          android.net.IpPrefix _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.IpPrefix.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.onNewPrefixRequest(_arg0);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.net.dhcp.IDhcpEventCallbacks
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
      @Override public void onLeasesChanged(java.util.List<android.net.dhcp.DhcpLeaseParcelable> newLeases) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeTypedList(newLeases);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onLeasesChanged, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onLeasesChanged(newLeases);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onLeasesChanged is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onNewPrefixRequest(android.net.IpPrefix currentPrefix) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((currentPrefix!=null)) {
            _data.writeInt(1);
            currentPrefix.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_onNewPrefixRequest, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onNewPrefixRequest(currentPrefix);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onNewPrefixRequest is unimplemented.");
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
      public static android.net.dhcp.IDhcpEventCallbacks sDefaultImpl;
    }
    static final int TRANSACTION_onLeasesChanged = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_onNewPrefixRequest = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.net.dhcp.IDhcpEventCallbacks impl) {
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
    public static android.net.dhcp.IDhcpEventCallbacks getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$net$dhcp$IDhcpEventCallbacks".replace('$', '.');
  public void onLeasesChanged(java.util.List<android.net.dhcp.DhcpLeaseParcelable> newLeases) throws android.os.RemoteException;
  public void onNewPrefixRequest(android.net.IpPrefix currentPrefix) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
