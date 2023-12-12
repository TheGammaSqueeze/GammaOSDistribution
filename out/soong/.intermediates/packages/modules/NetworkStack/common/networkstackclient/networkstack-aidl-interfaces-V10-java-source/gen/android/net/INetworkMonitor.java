/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
/** @hide */
public interface INetworkMonitor extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 10;
  public static final String HASH = "4925f4fdbb270e4f35cc5519a15ed8dd8c69a549";
  /** Default implementation for INetworkMonitor. */
  public static class Default implements android.net.INetworkMonitor
  {
    @Override public void start() throws android.os.RemoteException
    {
    }
    @Override public void launchCaptivePortalApp() throws android.os.RemoteException
    {
    }
    @Override public void notifyCaptivePortalAppFinished(int response) throws android.os.RemoteException
    {
    }
    @Override public void setAcceptPartialConnectivity() throws android.os.RemoteException
    {
    }
    @Override public void forceReevaluation(int uid) throws android.os.RemoteException
    {
    }
    @Override public void notifyPrivateDnsChanged(android.net.PrivateDnsConfigParcel config) throws android.os.RemoteException
    {
    }
    @Override public void notifyDnsResponse(int returnCode) throws android.os.RemoteException
    {
    }
    @Override public void notifyNetworkConnected(android.net.LinkProperties lp, android.net.NetworkCapabilities nc) throws android.os.RemoteException
    {
    }
    @Override public void notifyNetworkDisconnected() throws android.os.RemoteException
    {
    }
    @Override public void notifyLinkPropertiesChanged(android.net.LinkProperties lp) throws android.os.RemoteException
    {
    }
    @Override public void notifyNetworkCapabilitiesChanged(android.net.NetworkCapabilities nc) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.net.INetworkMonitor
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.net.INetworkMonitor interface,
     * generating a proxy if needed.
     */
    public static android.net.INetworkMonitor asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.net.INetworkMonitor))) {
        return ((android.net.INetworkMonitor)iin);
      }
      return new android.net.INetworkMonitor.Stub.Proxy(obj);
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
          this.start();
          return true;
        }
        case TRANSACTION_launchCaptivePortalApp:
        {
          data.enforceInterface(descriptor);
          this.launchCaptivePortalApp();
          return true;
        }
        case TRANSACTION_notifyCaptivePortalAppFinished:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.notifyCaptivePortalAppFinished(_arg0);
          return true;
        }
        case TRANSACTION_setAcceptPartialConnectivity:
        {
          data.enforceInterface(descriptor);
          this.setAcceptPartialConnectivity();
          return true;
        }
        case TRANSACTION_forceReevaluation:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.forceReevaluation(_arg0);
          return true;
        }
        case TRANSACTION_notifyPrivateDnsChanged:
        {
          data.enforceInterface(descriptor);
          android.net.PrivateDnsConfigParcel _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.PrivateDnsConfigParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.notifyPrivateDnsChanged(_arg0);
          return true;
        }
        case TRANSACTION_notifyDnsResponse:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.notifyDnsResponse(_arg0);
          return true;
        }
        case TRANSACTION_notifyNetworkConnected:
        {
          data.enforceInterface(descriptor);
          android.net.LinkProperties _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.LinkProperties.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          android.net.NetworkCapabilities _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.net.NetworkCapabilities.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          this.notifyNetworkConnected(_arg0, _arg1);
          return true;
        }
        case TRANSACTION_notifyNetworkDisconnected:
        {
          data.enforceInterface(descriptor);
          this.notifyNetworkDisconnected();
          return true;
        }
        case TRANSACTION_notifyLinkPropertiesChanged:
        {
          data.enforceInterface(descriptor);
          android.net.LinkProperties _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.LinkProperties.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.notifyLinkPropertiesChanged(_arg0);
          return true;
        }
        case TRANSACTION_notifyNetworkCapabilitiesChanged:
        {
          data.enforceInterface(descriptor);
          android.net.NetworkCapabilities _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.NetworkCapabilities.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.notifyNetworkCapabilitiesChanged(_arg0);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.net.INetworkMonitor
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
      @Override public void start() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_start, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().start();
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
      @Override public void launchCaptivePortalApp() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_launchCaptivePortalApp, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().launchCaptivePortalApp();
              return;
            }
            else {
              throw new android.os.RemoteException("Method launchCaptivePortalApp is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void notifyCaptivePortalAppFinished(int response) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(response);
          boolean _status = mRemote.transact(Stub.TRANSACTION_notifyCaptivePortalAppFinished, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().notifyCaptivePortalAppFinished(response);
              return;
            }
            else {
              throw new android.os.RemoteException("Method notifyCaptivePortalAppFinished is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void setAcceptPartialConnectivity() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setAcceptPartialConnectivity, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setAcceptPartialConnectivity();
              return;
            }
            else {
              throw new android.os.RemoteException("Method setAcceptPartialConnectivity is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void forceReevaluation(int uid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(uid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_forceReevaluation, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().forceReevaluation(uid);
              return;
            }
            else {
              throw new android.os.RemoteException("Method forceReevaluation is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void notifyPrivateDnsChanged(android.net.PrivateDnsConfigParcel config) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((config!=null)) {
            _data.writeInt(1);
            config.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_notifyPrivateDnsChanged, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().notifyPrivateDnsChanged(config);
              return;
            }
            else {
              throw new android.os.RemoteException("Method notifyPrivateDnsChanged is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void notifyDnsResponse(int returnCode) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(returnCode);
          boolean _status = mRemote.transact(Stub.TRANSACTION_notifyDnsResponse, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().notifyDnsResponse(returnCode);
              return;
            }
            else {
              throw new android.os.RemoteException("Method notifyDnsResponse is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void notifyNetworkConnected(android.net.LinkProperties lp, android.net.NetworkCapabilities nc) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((lp!=null)) {
            _data.writeInt(1);
            lp.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          if ((nc!=null)) {
            _data.writeInt(1);
            nc.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_notifyNetworkConnected, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().notifyNetworkConnected(lp, nc);
              return;
            }
            else {
              throw new android.os.RemoteException("Method notifyNetworkConnected is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void notifyNetworkDisconnected() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_notifyNetworkDisconnected, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().notifyNetworkDisconnected();
              return;
            }
            else {
              throw new android.os.RemoteException("Method notifyNetworkDisconnected is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void notifyLinkPropertiesChanged(android.net.LinkProperties lp) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((lp!=null)) {
            _data.writeInt(1);
            lp.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_notifyLinkPropertiesChanged, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().notifyLinkPropertiesChanged(lp);
              return;
            }
            else {
              throw new android.os.RemoteException("Method notifyLinkPropertiesChanged is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void notifyNetworkCapabilitiesChanged(android.net.NetworkCapabilities nc) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((nc!=null)) {
            _data.writeInt(1);
            nc.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_notifyNetworkCapabilitiesChanged, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().notifyNetworkCapabilitiesChanged(nc);
              return;
            }
            else {
              throw new android.os.RemoteException("Method notifyNetworkCapabilitiesChanged is unimplemented.");
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
      public static android.net.INetworkMonitor sDefaultImpl;
    }
    static final int TRANSACTION_start = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_launchCaptivePortalApp = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_notifyCaptivePortalAppFinished = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_setAcceptPartialConnectivity = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_forceReevaluation = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_notifyPrivateDnsChanged = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_notifyDnsResponse = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_notifyNetworkConnected = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
    static final int TRANSACTION_notifyNetworkDisconnected = (android.os.IBinder.FIRST_CALL_TRANSACTION + 8);
    static final int TRANSACTION_notifyLinkPropertiesChanged = (android.os.IBinder.FIRST_CALL_TRANSACTION + 9);
    static final int TRANSACTION_notifyNetworkCapabilitiesChanged = (android.os.IBinder.FIRST_CALL_TRANSACTION + 10);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.net.INetworkMonitor impl) {
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
    public static android.net.INetworkMonitor getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$net$INetworkMonitor".replace('$', '.');
  public static final int NETWORK_TEST_RESULT_VALID = 0;
  public static final int NETWORK_TEST_RESULT_INVALID = 1;
  public static final int NETWORK_TEST_RESULT_PARTIAL_CONNECTIVITY = 2;
  public static final int NETWORK_VALIDATION_RESULT_VALID = 1;
  public static final int NETWORK_VALIDATION_RESULT_PARTIAL = 2;
  public static final int NETWORK_VALIDATION_PROBE_DNS = 4;
  public static final int NETWORK_VALIDATION_PROBE_HTTP = 8;
  public static final int NETWORK_VALIDATION_PROBE_HTTPS = 16;
  public static final int NETWORK_VALIDATION_PROBE_FALLBACK = 32;
  public static final int NETWORK_VALIDATION_PROBE_PRIVDNS = 64;
  public void start() throws android.os.RemoteException;
  public void launchCaptivePortalApp() throws android.os.RemoteException;
  public void notifyCaptivePortalAppFinished(int response) throws android.os.RemoteException;
  public void setAcceptPartialConnectivity() throws android.os.RemoteException;
  public void forceReevaluation(int uid) throws android.os.RemoteException;
  public void notifyPrivateDnsChanged(android.net.PrivateDnsConfigParcel config) throws android.os.RemoteException;
  public void notifyDnsResponse(int returnCode) throws android.os.RemoteException;
  public void notifyNetworkConnected(android.net.LinkProperties lp, android.net.NetworkCapabilities nc) throws android.os.RemoteException;
  public void notifyNetworkDisconnected() throws android.os.RemoteException;
  public void notifyLinkPropertiesChanged(android.net.LinkProperties lp) throws android.os.RemoteException;
  public void notifyNetworkCapabilitiesChanged(android.net.NetworkCapabilities nc) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
