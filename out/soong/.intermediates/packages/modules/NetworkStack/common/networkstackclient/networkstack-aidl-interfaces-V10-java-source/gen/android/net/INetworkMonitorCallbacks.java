/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
/** @hide */
public interface INetworkMonitorCallbacks extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 10;
  public static final String HASH = "4925f4fdbb270e4f35cc5519a15ed8dd8c69a549";
  /** Default implementation for INetworkMonitorCallbacks. */
  public static class Default implements android.net.INetworkMonitorCallbacks
  {
    @Override public void onNetworkMonitorCreated(android.net.INetworkMonitor networkMonitor) throws android.os.RemoteException
    {
    }
    @Override public void notifyNetworkTested(int testResult, java.lang.String redirectUrl) throws android.os.RemoteException
    {
    }
    @Override public void notifyPrivateDnsConfigResolved(android.net.PrivateDnsConfigParcel config) throws android.os.RemoteException
    {
    }
    @Override public void showProvisioningNotification(java.lang.String action, java.lang.String packageName) throws android.os.RemoteException
    {
    }
    @Override public void hideProvisioningNotification() throws android.os.RemoteException
    {
    }
    @Override public void notifyProbeStatusChanged(int probesCompleted, int probesSucceeded) throws android.os.RemoteException
    {
    }
    @Override public void notifyNetworkTestedWithExtras(android.net.NetworkTestResultParcelable result) throws android.os.RemoteException
    {
    }
    @Override public void notifyDataStallSuspected(android.net.DataStallReportParcelable report) throws android.os.RemoteException
    {
    }
    @Override public void notifyCaptivePortalDataChanged(android.net.CaptivePortalData data) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.net.INetworkMonitorCallbacks
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.net.INetworkMonitorCallbacks interface,
     * generating a proxy if needed.
     */
    public static android.net.INetworkMonitorCallbacks asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.net.INetworkMonitorCallbacks))) {
        return ((android.net.INetworkMonitorCallbacks)iin);
      }
      return new android.net.INetworkMonitorCallbacks.Stub.Proxy(obj);
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
        case TRANSACTION_onNetworkMonitorCreated:
        {
          data.enforceInterface(descriptor);
          android.net.INetworkMonitor _arg0;
          _arg0 = android.net.INetworkMonitor.Stub.asInterface(data.readStrongBinder());
          this.onNetworkMonitorCreated(_arg0);
          return true;
        }
        case TRANSACTION_notifyNetworkTested:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _arg1;
          _arg1 = data.readString();
          this.notifyNetworkTested(_arg0, _arg1);
          return true;
        }
        case TRANSACTION_notifyPrivateDnsConfigResolved:
        {
          data.enforceInterface(descriptor);
          android.net.PrivateDnsConfigParcel _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.PrivateDnsConfigParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.notifyPrivateDnsConfigResolved(_arg0);
          return true;
        }
        case TRANSACTION_showProvisioningNotification:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          this.showProvisioningNotification(_arg0, _arg1);
          return true;
        }
        case TRANSACTION_hideProvisioningNotification:
        {
          data.enforceInterface(descriptor);
          this.hideProvisioningNotification();
          return true;
        }
        case TRANSACTION_notifyProbeStatusChanged:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          this.notifyProbeStatusChanged(_arg0, _arg1);
          return true;
        }
        case TRANSACTION_notifyNetworkTestedWithExtras:
        {
          data.enforceInterface(descriptor);
          android.net.NetworkTestResultParcelable _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.NetworkTestResultParcelable.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.notifyNetworkTestedWithExtras(_arg0);
          return true;
        }
        case TRANSACTION_notifyDataStallSuspected:
        {
          data.enforceInterface(descriptor);
          android.net.DataStallReportParcelable _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.DataStallReportParcelable.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.notifyDataStallSuspected(_arg0);
          return true;
        }
        case TRANSACTION_notifyCaptivePortalDataChanged:
        {
          data.enforceInterface(descriptor);
          android.net.CaptivePortalData _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.CaptivePortalData.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.notifyCaptivePortalDataChanged(_arg0);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.net.INetworkMonitorCallbacks
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
      @Override public void onNetworkMonitorCreated(android.net.INetworkMonitor networkMonitor) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((networkMonitor!=null))?(networkMonitor.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_onNetworkMonitorCreated, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onNetworkMonitorCreated(networkMonitor);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onNetworkMonitorCreated is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void notifyNetworkTested(int testResult, java.lang.String redirectUrl) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(testResult);
          _data.writeString(redirectUrl);
          boolean _status = mRemote.transact(Stub.TRANSACTION_notifyNetworkTested, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().notifyNetworkTested(testResult, redirectUrl);
              return;
            }
            else {
              throw new android.os.RemoteException("Method notifyNetworkTested is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void notifyPrivateDnsConfigResolved(android.net.PrivateDnsConfigParcel config) throws android.os.RemoteException
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
          boolean _status = mRemote.transact(Stub.TRANSACTION_notifyPrivateDnsConfigResolved, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().notifyPrivateDnsConfigResolved(config);
              return;
            }
            else {
              throw new android.os.RemoteException("Method notifyPrivateDnsConfigResolved is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void showProvisioningNotification(java.lang.String action, java.lang.String packageName) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(action);
          _data.writeString(packageName);
          boolean _status = mRemote.transact(Stub.TRANSACTION_showProvisioningNotification, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().showProvisioningNotification(action, packageName);
              return;
            }
            else {
              throw new android.os.RemoteException("Method showProvisioningNotification is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void hideProvisioningNotification() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_hideProvisioningNotification, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().hideProvisioningNotification();
              return;
            }
            else {
              throw new android.os.RemoteException("Method hideProvisioningNotification is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void notifyProbeStatusChanged(int probesCompleted, int probesSucceeded) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(probesCompleted);
          _data.writeInt(probesSucceeded);
          boolean _status = mRemote.transact(Stub.TRANSACTION_notifyProbeStatusChanged, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().notifyProbeStatusChanged(probesCompleted, probesSucceeded);
              return;
            }
            else {
              throw new android.os.RemoteException("Method notifyProbeStatusChanged is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void notifyNetworkTestedWithExtras(android.net.NetworkTestResultParcelable result) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((result!=null)) {
            _data.writeInt(1);
            result.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_notifyNetworkTestedWithExtras, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().notifyNetworkTestedWithExtras(result);
              return;
            }
            else {
              throw new android.os.RemoteException("Method notifyNetworkTestedWithExtras is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void notifyDataStallSuspected(android.net.DataStallReportParcelable report) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((report!=null)) {
            _data.writeInt(1);
            report.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_notifyDataStallSuspected, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().notifyDataStallSuspected(report);
              return;
            }
            else {
              throw new android.os.RemoteException("Method notifyDataStallSuspected is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void notifyCaptivePortalDataChanged(android.net.CaptivePortalData data) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((data!=null)) {
            _data.writeInt(1);
            data.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_notifyCaptivePortalDataChanged, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().notifyCaptivePortalDataChanged(data);
              return;
            }
            else {
              throw new android.os.RemoteException("Method notifyCaptivePortalDataChanged is unimplemented.");
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
      public static android.net.INetworkMonitorCallbacks sDefaultImpl;
    }
    static final int TRANSACTION_onNetworkMonitorCreated = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_notifyNetworkTested = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_notifyPrivateDnsConfigResolved = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_showProvisioningNotification = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_hideProvisioningNotification = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_notifyProbeStatusChanged = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_notifyNetworkTestedWithExtras = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_notifyDataStallSuspected = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
    static final int TRANSACTION_notifyCaptivePortalDataChanged = (android.os.IBinder.FIRST_CALL_TRANSACTION + 8);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.net.INetworkMonitorCallbacks impl) {
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
    public static android.net.INetworkMonitorCallbacks getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$net$INetworkMonitorCallbacks".replace('$', '.');
  public void onNetworkMonitorCreated(android.net.INetworkMonitor networkMonitor) throws android.os.RemoteException;
  public void notifyNetworkTested(int testResult, java.lang.String redirectUrl) throws android.os.RemoteException;
  public void notifyPrivateDnsConfigResolved(android.net.PrivateDnsConfigParcel config) throws android.os.RemoteException;
  public void showProvisioningNotification(java.lang.String action, java.lang.String packageName) throws android.os.RemoteException;
  public void hideProvisioningNotification() throws android.os.RemoteException;
  public void notifyProbeStatusChanged(int probesCompleted, int probesSucceeded) throws android.os.RemoteException;
  public void notifyNetworkTestedWithExtras(android.net.NetworkTestResultParcelable result) throws android.os.RemoteException;
  public void notifyDataStallSuspected(android.net.DataStallReportParcelable report) throws android.os.RemoteException;
  public void notifyCaptivePortalDataChanged(android.net.CaptivePortalData data) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
