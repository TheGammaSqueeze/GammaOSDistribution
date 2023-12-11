/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
/** @hide */
public interface IDnsResolver extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 9;
  public static final String HASH = "882638dc86e8afd0924ecf7c28db6cce572f7e7d";
  /** Default implementation for IDnsResolver. */
  public static class Default implements android.net.IDnsResolver
  {
    @Override public boolean isAlive() throws android.os.RemoteException
    {
      return false;
    }
    @Override public void registerEventListener(android.net.metrics.INetdEventListener listener) throws android.os.RemoteException
    {
    }
    @Override public void setResolverConfiguration(android.net.ResolverParamsParcel resolverParams) throws android.os.RemoteException
    {
    }
    @Override public void getResolverInfo(int netId, java.lang.String[] servers, java.lang.String[] domains, java.lang.String[] tlsServers, int[] params, int[] stats, int[] wait_for_pending_req_timeout_count) throws android.os.RemoteException
    {
    }
    @Override public void startPrefix64Discovery(int netId) throws android.os.RemoteException
    {
    }
    @Override public void stopPrefix64Discovery(int netId) throws android.os.RemoteException
    {
    }
    @Override public java.lang.String getPrefix64(int netId) throws android.os.RemoteException
    {
      return null;
    }
    @Override public void createNetworkCache(int netId) throws android.os.RemoteException
    {
    }
    @Override public void destroyNetworkCache(int netId) throws android.os.RemoteException
    {
    }
    @Override public void setLogSeverity(int logSeverity) throws android.os.RemoteException
    {
    }
    @Override public void flushNetworkCache(int netId) throws android.os.RemoteException
    {
    }
    @Override public void setPrefix64(int netId, java.lang.String prefix) throws android.os.RemoteException
    {
    }
    @Override public void registerUnsolicitedEventListener(android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener listener) throws android.os.RemoteException
    {
    }
    @Override public void setResolverOptions(int netId, android.net.ResolverOptionsParcel optionParams) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.net.IDnsResolver
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.net.IDnsResolver interface,
     * generating a proxy if needed.
     */
    public static android.net.IDnsResolver asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.net.IDnsResolver))) {
        return ((android.net.IDnsResolver)iin);
      }
      return new android.net.IDnsResolver.Stub.Proxy(obj);
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
        case TRANSACTION_registerEventListener:
        {
          data.enforceInterface(descriptor);
          android.net.metrics.INetdEventListener _arg0;
          _arg0 = android.net.metrics.INetdEventListener.Stub.asInterface(data.readStrongBinder());
          this.registerEventListener(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setResolverConfiguration:
        {
          data.enforceInterface(descriptor);
          android.net.ResolverParamsParcel _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.ResolverParamsParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.setResolverConfiguration(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getResolverInfo:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String[] _arg1;
          int _arg1_length = data.readInt();
          if ((_arg1_length<0)) {
            _arg1 = null;
          }
          else {
            _arg1 = new java.lang.String[_arg1_length];
          }
          java.lang.String[] _arg2;
          int _arg2_length = data.readInt();
          if ((_arg2_length<0)) {
            _arg2 = null;
          }
          else {
            _arg2 = new java.lang.String[_arg2_length];
          }
          java.lang.String[] _arg3;
          int _arg3_length = data.readInt();
          if ((_arg3_length<0)) {
            _arg3 = null;
          }
          else {
            _arg3 = new java.lang.String[_arg3_length];
          }
          int[] _arg4;
          int _arg4_length = data.readInt();
          if ((_arg4_length<0)) {
            _arg4 = null;
          }
          else {
            _arg4 = new int[_arg4_length];
          }
          int[] _arg5;
          int _arg5_length = data.readInt();
          if ((_arg5_length<0)) {
            _arg5 = null;
          }
          else {
            _arg5 = new int[_arg5_length];
          }
          int[] _arg6;
          int _arg6_length = data.readInt();
          if ((_arg6_length<0)) {
            _arg6 = null;
          }
          else {
            _arg6 = new int[_arg6_length];
          }
          this.getResolverInfo(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6);
          reply.writeNoException();
          reply.writeStringArray(_arg1);
          reply.writeStringArray(_arg2);
          reply.writeStringArray(_arg3);
          reply.writeIntArray(_arg4);
          reply.writeIntArray(_arg5);
          reply.writeIntArray(_arg6);
          return true;
        }
        case TRANSACTION_startPrefix64Discovery:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.startPrefix64Discovery(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_stopPrefix64Discovery:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.stopPrefix64Discovery(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getPrefix64:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _result = this.getPrefix64(_arg0);
          reply.writeNoException();
          reply.writeString(_result);
          return true;
        }
        case TRANSACTION_createNetworkCache:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.createNetworkCache(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_destroyNetworkCache:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.destroyNetworkCache(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setLogSeverity:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.setLogSeverity(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_flushNetworkCache:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.flushNetworkCache(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setPrefix64:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _arg1;
          _arg1 = data.readString();
          this.setPrefix64(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_registerUnsolicitedEventListener:
        {
          data.enforceInterface(descriptor);
          android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener _arg0;
          _arg0 = android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener.Stub.asInterface(data.readStrongBinder());
          this.registerUnsolicitedEventListener(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setResolverOptions:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.net.ResolverOptionsParcel _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.net.ResolverOptionsParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          this.setResolverOptions(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.net.IDnsResolver
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
      @Override public void registerEventListener(android.net.metrics.INetdEventListener listener) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((listener!=null))?(listener.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_registerEventListener, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().registerEventListener(listener);
              return;
            }
            else {
              throw new android.os.RemoteException("Method registerEventListener is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void setResolverConfiguration(android.net.ResolverParamsParcel resolverParams) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((resolverParams!=null)) {
            _data.writeInt(1);
            resolverParams.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_setResolverConfiguration, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setResolverConfiguration(resolverParams);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setResolverConfiguration is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void getResolverInfo(int netId, java.lang.String[] servers, java.lang.String[] domains, java.lang.String[] tlsServers, int[] params, int[] stats, int[] wait_for_pending_req_timeout_count) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          if ((servers==null)) {
            _data.writeInt(-1);
          }
          else {
            _data.writeInt(servers.length);
          }
          if ((domains==null)) {
            _data.writeInt(-1);
          }
          else {
            _data.writeInt(domains.length);
          }
          if ((tlsServers==null)) {
            _data.writeInt(-1);
          }
          else {
            _data.writeInt(tlsServers.length);
          }
          if ((params==null)) {
            _data.writeInt(-1);
          }
          else {
            _data.writeInt(params.length);
          }
          if ((stats==null)) {
            _data.writeInt(-1);
          }
          else {
            _data.writeInt(stats.length);
          }
          if ((wait_for_pending_req_timeout_count==null)) {
            _data.writeInt(-1);
          }
          else {
            _data.writeInt(wait_for_pending_req_timeout_count.length);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_getResolverInfo, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().getResolverInfo(netId, servers, domains, tlsServers, params, stats, wait_for_pending_req_timeout_count);
              return;
            }
            else {
              throw new android.os.RemoteException("Method getResolverInfo is unimplemented.");
            }
          }
          _reply.readException();
          _reply.readStringArray(servers);
          _reply.readStringArray(domains);
          _reply.readStringArray(tlsServers);
          _reply.readIntArray(params);
          _reply.readIntArray(stats);
          _reply.readIntArray(wait_for_pending_req_timeout_count);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void startPrefix64Discovery(int netId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_startPrefix64Discovery, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().startPrefix64Discovery(netId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method startPrefix64Discovery is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void stopPrefix64Discovery(int netId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_stopPrefix64Discovery, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().stopPrefix64Discovery(netId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method stopPrefix64Discovery is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public java.lang.String getPrefix64(int netId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        java.lang.String _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getPrefix64, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getPrefix64(netId);
            }
            else {
              throw new android.os.RemoteException("Method getPrefix64 is unimplemented.");
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
      @Override public void createNetworkCache(int netId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_createNetworkCache, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().createNetworkCache(netId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method createNetworkCache is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void destroyNetworkCache(int netId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_destroyNetworkCache, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().destroyNetworkCache(netId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method destroyNetworkCache is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void setLogSeverity(int logSeverity) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(logSeverity);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setLogSeverity, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setLogSeverity(logSeverity);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setLogSeverity is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void flushNetworkCache(int netId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_flushNetworkCache, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().flushNetworkCache(netId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method flushNetworkCache is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void setPrefix64(int netId, java.lang.String prefix) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          _data.writeString(prefix);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setPrefix64, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setPrefix64(netId, prefix);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setPrefix64 is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void registerUnsolicitedEventListener(android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener listener) throws android.os.RemoteException
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
      @Override public void setResolverOptions(int netId, android.net.ResolverOptionsParcel optionParams) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(netId);
          if ((optionParams!=null)) {
            _data.writeInt(1);
            optionParams.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_setResolverOptions, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setResolverOptions(netId, optionParams);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setResolverOptions is unimplemented.");
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
      public static android.net.IDnsResolver sDefaultImpl;
    }
    static final int TRANSACTION_isAlive = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_registerEventListener = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_setResolverConfiguration = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_getResolverInfo = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_startPrefix64Discovery = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_stopPrefix64Discovery = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_getPrefix64 = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_createNetworkCache = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
    static final int TRANSACTION_destroyNetworkCache = (android.os.IBinder.FIRST_CALL_TRANSACTION + 8);
    static final int TRANSACTION_setLogSeverity = (android.os.IBinder.FIRST_CALL_TRANSACTION + 9);
    static final int TRANSACTION_flushNetworkCache = (android.os.IBinder.FIRST_CALL_TRANSACTION + 10);
    static final int TRANSACTION_setPrefix64 = (android.os.IBinder.FIRST_CALL_TRANSACTION + 11);
    static final int TRANSACTION_registerUnsolicitedEventListener = (android.os.IBinder.FIRST_CALL_TRANSACTION + 12);
    static final int TRANSACTION_setResolverOptions = (android.os.IBinder.FIRST_CALL_TRANSACTION + 13);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.net.IDnsResolver impl) {
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
    public static android.net.IDnsResolver getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$net$IDnsResolver".replace('$', '.');
  public static final int RESOLVER_PARAMS_SAMPLE_VALIDITY = 0;
  public static final int RESOLVER_PARAMS_SUCCESS_THRESHOLD = 1;
  public static final int RESOLVER_PARAMS_MIN_SAMPLES = 2;
  public static final int RESOLVER_PARAMS_MAX_SAMPLES = 3;
  public static final int RESOLVER_PARAMS_BASE_TIMEOUT_MSEC = 4;
  public static final int RESOLVER_PARAMS_RETRY_COUNT = 5;
  public static final int RESOLVER_PARAMS_COUNT = 6;
  public static final int RESOLVER_STATS_SUCCESSES = 0;
  public static final int RESOLVER_STATS_ERRORS = 1;
  public static final int RESOLVER_STATS_TIMEOUTS = 2;
  public static final int RESOLVER_STATS_INTERNAL_ERRORS = 3;
  public static final int RESOLVER_STATS_RTT_AVG = 4;
  public static final int RESOLVER_STATS_LAST_SAMPLE_TIME = 5;
  public static final int RESOLVER_STATS_USABLE = 6;
  public static final int RESOLVER_STATS_COUNT = 7;
  public static final int DNS_RESOLVER_LOG_VERBOSE = 0;
  public static final int DNS_RESOLVER_LOG_DEBUG = 1;
  public static final int DNS_RESOLVER_LOG_INFO = 2;
  public static final int DNS_RESOLVER_LOG_WARNING = 3;
  public static final int DNS_RESOLVER_LOG_ERROR = 4;
  public static final int TC_MODE_DEFAULT = 0;
  public static final int TC_MODE_UDP_TCP = 1;
  public static final int TRANSPORT_UNKNOWN = -1;
  public static final int TRANSPORT_CELLULAR = 0;
  public static final int TRANSPORT_WIFI = 1;
  public static final int TRANSPORT_BLUETOOTH = 2;
  public static final int TRANSPORT_ETHERNET = 3;
  public static final int TRANSPORT_VPN = 4;
  public static final int TRANSPORT_WIFI_AWARE = 5;
  public static final int TRANSPORT_LOWPAN = 6;
  public static final int TRANSPORT_TEST = 7;
  public static final int TRANSPORT_USB = 8;
  public boolean isAlive() throws android.os.RemoteException;
  public void registerEventListener(android.net.metrics.INetdEventListener listener) throws android.os.RemoteException;
  public void setResolverConfiguration(android.net.ResolverParamsParcel resolverParams) throws android.os.RemoteException;
  public void getResolverInfo(int netId, java.lang.String[] servers, java.lang.String[] domains, java.lang.String[] tlsServers, int[] params, int[] stats, int[] wait_for_pending_req_timeout_count) throws android.os.RemoteException;
  public void startPrefix64Discovery(int netId) throws android.os.RemoteException;
  public void stopPrefix64Discovery(int netId) throws android.os.RemoteException;
  public java.lang.String getPrefix64(int netId) throws android.os.RemoteException;
  public void createNetworkCache(int netId) throws android.os.RemoteException;
  public void destroyNetworkCache(int netId) throws android.os.RemoteException;
  public void setLogSeverity(int logSeverity) throws android.os.RemoteException;
  public void flushNetworkCache(int netId) throws android.os.RemoteException;
  public void setPrefix64(int netId, java.lang.String prefix) throws android.os.RemoteException;
  public void registerUnsolicitedEventListener(android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener listener) throws android.os.RemoteException;
  public void setResolverOptions(int netId, android.net.ResolverOptionsParcel optionParams) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
