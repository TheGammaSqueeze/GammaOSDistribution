/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
/** @hide */
public interface INetdUnsolicitedEventListener extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 3;
  public static final String HASH = "e17c1f9b2068b539b22e3a4a447edea3c80aee4b";
  /** Default implementation for INetdUnsolicitedEventListener. */
  public static class Default implements android.net.INetdUnsolicitedEventListener
  {
    @Override public void onInterfaceClassActivityChanged(boolean isActive, int timerLabel, long timestampNs, int uid) throws android.os.RemoteException
    {
    }
    @Override public void onQuotaLimitReached(java.lang.String alertName, java.lang.String ifName) throws android.os.RemoteException
    {
    }
    @Override public void onInterfaceDnsServerInfo(java.lang.String ifName, long lifetimeS, java.lang.String[] servers) throws android.os.RemoteException
    {
    }
    @Override public void onInterfaceAddressUpdated(java.lang.String addr, java.lang.String ifName, int flags, int scope) throws android.os.RemoteException
    {
    }
    @Override public void onInterfaceAddressRemoved(java.lang.String addr, java.lang.String ifName, int flags, int scope) throws android.os.RemoteException
    {
    }
    @Override public void onInterfaceAdded(java.lang.String ifName) throws android.os.RemoteException
    {
    }
    @Override public void onInterfaceRemoved(java.lang.String ifName) throws android.os.RemoteException
    {
    }
    @Override public void onInterfaceChanged(java.lang.String ifName, boolean up) throws android.os.RemoteException
    {
    }
    @Override public void onInterfaceLinkStateChanged(java.lang.String ifName, boolean up) throws android.os.RemoteException
    {
    }
    @Override public void onRouteChanged(boolean updated, java.lang.String route, java.lang.String gateway, java.lang.String ifName) throws android.os.RemoteException
    {
    }
    @Override public void onStrictCleartextDetected(int uid, java.lang.String hex) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.net.INetdUnsolicitedEventListener
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.net.INetdUnsolicitedEventListener interface,
     * generating a proxy if needed.
     */
    public static android.net.INetdUnsolicitedEventListener asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.net.INetdUnsolicitedEventListener))) {
        return ((android.net.INetdUnsolicitedEventListener)iin);
      }
      return new android.net.INetdUnsolicitedEventListener.Stub.Proxy(obj);
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
        case TRANSACTION_onInterfaceClassActivityChanged:
        {
          data.enforceInterface(descriptor);
          boolean _arg0;
          _arg0 = (0!=data.readInt());
          int _arg1;
          _arg1 = data.readInt();
          long _arg2;
          _arg2 = data.readLong();
          int _arg3;
          _arg3 = data.readInt();
          this.onInterfaceClassActivityChanged(_arg0, _arg1, _arg2, _arg3);
          return true;
        }
        case TRANSACTION_onQuotaLimitReached:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          this.onQuotaLimitReached(_arg0, _arg1);
          return true;
        }
        case TRANSACTION_onInterfaceDnsServerInfo:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          long _arg1;
          _arg1 = data.readLong();
          java.lang.String[] _arg2;
          _arg2 = data.createStringArray();
          this.onInterfaceDnsServerInfo(_arg0, _arg1, _arg2);
          return true;
        }
        case TRANSACTION_onInterfaceAddressUpdated:
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
          this.onInterfaceAddressUpdated(_arg0, _arg1, _arg2, _arg3);
          return true;
        }
        case TRANSACTION_onInterfaceAddressRemoved:
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
          this.onInterfaceAddressRemoved(_arg0, _arg1, _arg2, _arg3);
          return true;
        }
        case TRANSACTION_onInterfaceAdded:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.onInterfaceAdded(_arg0);
          return true;
        }
        case TRANSACTION_onInterfaceRemoved:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.onInterfaceRemoved(_arg0);
          return true;
        }
        case TRANSACTION_onInterfaceChanged:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          boolean _arg1;
          _arg1 = (0!=data.readInt());
          this.onInterfaceChanged(_arg0, _arg1);
          return true;
        }
        case TRANSACTION_onInterfaceLinkStateChanged:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          boolean _arg1;
          _arg1 = (0!=data.readInt());
          this.onInterfaceLinkStateChanged(_arg0, _arg1);
          return true;
        }
        case TRANSACTION_onRouteChanged:
        {
          data.enforceInterface(descriptor);
          boolean _arg0;
          _arg0 = (0!=data.readInt());
          java.lang.String _arg1;
          _arg1 = data.readString();
          java.lang.String _arg2;
          _arg2 = data.readString();
          java.lang.String _arg3;
          _arg3 = data.readString();
          this.onRouteChanged(_arg0, _arg1, _arg2, _arg3);
          return true;
        }
        case TRANSACTION_onStrictCleartextDetected:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _arg1;
          _arg1 = data.readString();
          this.onStrictCleartextDetected(_arg0, _arg1);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.net.INetdUnsolicitedEventListener
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
      @Override public void onInterfaceClassActivityChanged(boolean isActive, int timerLabel, long timestampNs, int uid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(((isActive)?(1):(0)));
          _data.writeInt(timerLabel);
          _data.writeLong(timestampNs);
          _data.writeInt(uid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onInterfaceClassActivityChanged, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onInterfaceClassActivityChanged(isActive, timerLabel, timestampNs, uid);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onInterfaceClassActivityChanged is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onQuotaLimitReached(java.lang.String alertName, java.lang.String ifName) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(alertName);
          _data.writeString(ifName);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onQuotaLimitReached, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onQuotaLimitReached(alertName, ifName);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onQuotaLimitReached is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onInterfaceDnsServerInfo(java.lang.String ifName, long lifetimeS, java.lang.String[] servers) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeLong(lifetimeS);
          _data.writeStringArray(servers);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onInterfaceDnsServerInfo, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onInterfaceDnsServerInfo(ifName, lifetimeS, servers);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onInterfaceDnsServerInfo is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onInterfaceAddressUpdated(java.lang.String addr, java.lang.String ifName, int flags, int scope) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(addr);
          _data.writeString(ifName);
          _data.writeInt(flags);
          _data.writeInt(scope);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onInterfaceAddressUpdated, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onInterfaceAddressUpdated(addr, ifName, flags, scope);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onInterfaceAddressUpdated is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onInterfaceAddressRemoved(java.lang.String addr, java.lang.String ifName, int flags, int scope) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(addr);
          _data.writeString(ifName);
          _data.writeInt(flags);
          _data.writeInt(scope);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onInterfaceAddressRemoved, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onInterfaceAddressRemoved(addr, ifName, flags, scope);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onInterfaceAddressRemoved is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onInterfaceAdded(java.lang.String ifName) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onInterfaceAdded, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onInterfaceAdded(ifName);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onInterfaceAdded is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onInterfaceRemoved(java.lang.String ifName) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onInterfaceRemoved, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onInterfaceRemoved(ifName);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onInterfaceRemoved is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onInterfaceChanged(java.lang.String ifName, boolean up) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeInt(((up)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_onInterfaceChanged, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onInterfaceChanged(ifName, up);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onInterfaceChanged is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onInterfaceLinkStateChanged(java.lang.String ifName, boolean up) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(ifName);
          _data.writeInt(((up)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_onInterfaceLinkStateChanged, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onInterfaceLinkStateChanged(ifName, up);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onInterfaceLinkStateChanged is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onRouteChanged(boolean updated, java.lang.String route, java.lang.String gateway, java.lang.String ifName) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(((updated)?(1):(0)));
          _data.writeString(route);
          _data.writeString(gateway);
          _data.writeString(ifName);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onRouteChanged, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onRouteChanged(updated, route, gateway, ifName);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onRouteChanged is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onStrictCleartextDetected(int uid, java.lang.String hex) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(uid);
          _data.writeString(hex);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onStrictCleartextDetected, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onStrictCleartextDetected(uid, hex);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onStrictCleartextDetected is unimplemented.");
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
      public static android.net.INetdUnsolicitedEventListener sDefaultImpl;
    }
    static final int TRANSACTION_onInterfaceClassActivityChanged = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_onQuotaLimitReached = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_onInterfaceDnsServerInfo = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_onInterfaceAddressUpdated = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_onInterfaceAddressRemoved = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_onInterfaceAdded = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_onInterfaceRemoved = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_onInterfaceChanged = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
    static final int TRANSACTION_onInterfaceLinkStateChanged = (android.os.IBinder.FIRST_CALL_TRANSACTION + 8);
    static final int TRANSACTION_onRouteChanged = (android.os.IBinder.FIRST_CALL_TRANSACTION + 9);
    static final int TRANSACTION_onStrictCleartextDetected = (android.os.IBinder.FIRST_CALL_TRANSACTION + 10);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.net.INetdUnsolicitedEventListener impl) {
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
    public static android.net.INetdUnsolicitedEventListener getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$net$INetdUnsolicitedEventListener".replace('$', '.');
  public void onInterfaceClassActivityChanged(boolean isActive, int timerLabel, long timestampNs, int uid) throws android.os.RemoteException;
  public void onQuotaLimitReached(java.lang.String alertName, java.lang.String ifName) throws android.os.RemoteException;
  public void onInterfaceDnsServerInfo(java.lang.String ifName, long lifetimeS, java.lang.String[] servers) throws android.os.RemoteException;
  public void onInterfaceAddressUpdated(java.lang.String addr, java.lang.String ifName, int flags, int scope) throws android.os.RemoteException;
  public void onInterfaceAddressRemoved(java.lang.String addr, java.lang.String ifName, int flags, int scope) throws android.os.RemoteException;
  public void onInterfaceAdded(java.lang.String ifName) throws android.os.RemoteException;
  public void onInterfaceRemoved(java.lang.String ifName) throws android.os.RemoteException;
  public void onInterfaceChanged(java.lang.String ifName, boolean up) throws android.os.RemoteException;
  public void onInterfaceLinkStateChanged(java.lang.String ifName, boolean up) throws android.os.RemoteException;
  public void onRouteChanged(boolean updated, java.lang.String route, java.lang.String gateway, java.lang.String ifName) throws android.os.RemoteException;
  public void onStrictCleartextDetected(int uid, java.lang.String hex) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
