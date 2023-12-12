/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net.ip;
/** @hide */
public interface IIpClientCallbacks extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 10;
  public static final String HASH = "4925f4fdbb270e4f35cc5519a15ed8dd8c69a549";
  /** Default implementation for IIpClientCallbacks. */
  public static class Default implements android.net.ip.IIpClientCallbacks
  {
    @Override public void onIpClientCreated(android.net.ip.IIpClient ipClient) throws android.os.RemoteException
    {
    }
    @Override public void onPreDhcpAction() throws android.os.RemoteException
    {
    }
    @Override public void onPostDhcpAction() throws android.os.RemoteException
    {
    }
    @Override public void onNewDhcpResults(android.net.DhcpResultsParcelable dhcpResults) throws android.os.RemoteException
    {
    }
    @Override public void onProvisioningSuccess(android.net.LinkProperties newLp) throws android.os.RemoteException
    {
    }
    @Override public void onProvisioningFailure(android.net.LinkProperties newLp) throws android.os.RemoteException
    {
    }
    @Override public void onLinkPropertiesChange(android.net.LinkProperties newLp) throws android.os.RemoteException
    {
    }
    @Override public void onReachabilityLost(java.lang.String logMsg) throws android.os.RemoteException
    {
    }
    @Override public void onQuit() throws android.os.RemoteException
    {
    }
    @Override public void installPacketFilter(byte[] filter) throws android.os.RemoteException
    {
    }
    @Override public void startReadPacketFilter() throws android.os.RemoteException
    {
    }
    @Override public void setFallbackMulticastFilter(boolean enabled) throws android.os.RemoteException
    {
    }
    @Override public void setNeighborDiscoveryOffload(boolean enable) throws android.os.RemoteException
    {
    }
    @Override public void onPreconnectionStart(java.util.List<android.net.Layer2PacketParcelable> packets) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.net.ip.IIpClientCallbacks
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.net.ip.IIpClientCallbacks interface,
     * generating a proxy if needed.
     */
    public static android.net.ip.IIpClientCallbacks asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.net.ip.IIpClientCallbacks))) {
        return ((android.net.ip.IIpClientCallbacks)iin);
      }
      return new android.net.ip.IIpClientCallbacks.Stub.Proxy(obj);
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
        case TRANSACTION_onIpClientCreated:
        {
          data.enforceInterface(descriptor);
          android.net.ip.IIpClient _arg0;
          _arg0 = android.net.ip.IIpClient.Stub.asInterface(data.readStrongBinder());
          this.onIpClientCreated(_arg0);
          return true;
        }
        case TRANSACTION_onPreDhcpAction:
        {
          data.enforceInterface(descriptor);
          this.onPreDhcpAction();
          return true;
        }
        case TRANSACTION_onPostDhcpAction:
        {
          data.enforceInterface(descriptor);
          this.onPostDhcpAction();
          return true;
        }
        case TRANSACTION_onNewDhcpResults:
        {
          data.enforceInterface(descriptor);
          android.net.DhcpResultsParcelable _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.DhcpResultsParcelable.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.onNewDhcpResults(_arg0);
          return true;
        }
        case TRANSACTION_onProvisioningSuccess:
        {
          data.enforceInterface(descriptor);
          android.net.LinkProperties _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.LinkProperties.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.onProvisioningSuccess(_arg0);
          return true;
        }
        case TRANSACTION_onProvisioningFailure:
        {
          data.enforceInterface(descriptor);
          android.net.LinkProperties _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.LinkProperties.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.onProvisioningFailure(_arg0);
          return true;
        }
        case TRANSACTION_onLinkPropertiesChange:
        {
          data.enforceInterface(descriptor);
          android.net.LinkProperties _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.LinkProperties.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.onLinkPropertiesChange(_arg0);
          return true;
        }
        case TRANSACTION_onReachabilityLost:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.onReachabilityLost(_arg0);
          return true;
        }
        case TRANSACTION_onQuit:
        {
          data.enforceInterface(descriptor);
          this.onQuit();
          return true;
        }
        case TRANSACTION_installPacketFilter:
        {
          data.enforceInterface(descriptor);
          byte[] _arg0;
          _arg0 = data.createByteArray();
          this.installPacketFilter(_arg0);
          return true;
        }
        case TRANSACTION_startReadPacketFilter:
        {
          data.enforceInterface(descriptor);
          this.startReadPacketFilter();
          return true;
        }
        case TRANSACTION_setFallbackMulticastFilter:
        {
          data.enforceInterface(descriptor);
          boolean _arg0;
          _arg0 = (0!=data.readInt());
          this.setFallbackMulticastFilter(_arg0);
          return true;
        }
        case TRANSACTION_setNeighborDiscoveryOffload:
        {
          data.enforceInterface(descriptor);
          boolean _arg0;
          _arg0 = (0!=data.readInt());
          this.setNeighborDiscoveryOffload(_arg0);
          return true;
        }
        case TRANSACTION_onPreconnectionStart:
        {
          data.enforceInterface(descriptor);
          java.util.List<android.net.Layer2PacketParcelable> _arg0;
          _arg0 = data.createTypedArrayList(android.net.Layer2PacketParcelable.CREATOR);
          this.onPreconnectionStart(_arg0);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.net.ip.IIpClientCallbacks
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
      @Override public void onIpClientCreated(android.net.ip.IIpClient ipClient) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((ipClient!=null))?(ipClient.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_onIpClientCreated, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onIpClientCreated(ipClient);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onIpClientCreated is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onPreDhcpAction() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onPreDhcpAction, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onPreDhcpAction();
              return;
            }
            else {
              throw new android.os.RemoteException("Method onPreDhcpAction is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onPostDhcpAction() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onPostDhcpAction, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onPostDhcpAction();
              return;
            }
            else {
              throw new android.os.RemoteException("Method onPostDhcpAction is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onNewDhcpResults(android.net.DhcpResultsParcelable dhcpResults) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((dhcpResults!=null)) {
            _data.writeInt(1);
            dhcpResults.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_onNewDhcpResults, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onNewDhcpResults(dhcpResults);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onNewDhcpResults is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onProvisioningSuccess(android.net.LinkProperties newLp) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((newLp!=null)) {
            _data.writeInt(1);
            newLp.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_onProvisioningSuccess, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onProvisioningSuccess(newLp);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onProvisioningSuccess is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onProvisioningFailure(android.net.LinkProperties newLp) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((newLp!=null)) {
            _data.writeInt(1);
            newLp.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_onProvisioningFailure, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onProvisioningFailure(newLp);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onProvisioningFailure is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onLinkPropertiesChange(android.net.LinkProperties newLp) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((newLp!=null)) {
            _data.writeInt(1);
            newLp.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_onLinkPropertiesChange, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onLinkPropertiesChange(newLp);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onLinkPropertiesChange is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onReachabilityLost(java.lang.String logMsg) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(logMsg);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onReachabilityLost, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onReachabilityLost(logMsg);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onReachabilityLost is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onQuit() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onQuit, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onQuit();
              return;
            }
            else {
              throw new android.os.RemoteException("Method onQuit is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void installPacketFilter(byte[] filter) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByteArray(filter);
          boolean _status = mRemote.transact(Stub.TRANSACTION_installPacketFilter, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().installPacketFilter(filter);
              return;
            }
            else {
              throw new android.os.RemoteException("Method installPacketFilter is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void startReadPacketFilter() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_startReadPacketFilter, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().startReadPacketFilter();
              return;
            }
            else {
              throw new android.os.RemoteException("Method startReadPacketFilter is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void setFallbackMulticastFilter(boolean enabled) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(((enabled)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_setFallbackMulticastFilter, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setFallbackMulticastFilter(enabled);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setFallbackMulticastFilter is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void setNeighborDiscoveryOffload(boolean enable) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(((enable)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_setNeighborDiscoveryOffload, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setNeighborDiscoveryOffload(enable);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setNeighborDiscoveryOffload is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onPreconnectionStart(java.util.List<android.net.Layer2PacketParcelable> packets) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeTypedList(packets);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onPreconnectionStart, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onPreconnectionStart(packets);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onPreconnectionStart is unimplemented.");
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
      public static android.net.ip.IIpClientCallbacks sDefaultImpl;
    }
    static final int TRANSACTION_onIpClientCreated = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_onPreDhcpAction = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_onPostDhcpAction = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_onNewDhcpResults = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_onProvisioningSuccess = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_onProvisioningFailure = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_onLinkPropertiesChange = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_onReachabilityLost = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
    static final int TRANSACTION_onQuit = (android.os.IBinder.FIRST_CALL_TRANSACTION + 8);
    static final int TRANSACTION_installPacketFilter = (android.os.IBinder.FIRST_CALL_TRANSACTION + 9);
    static final int TRANSACTION_startReadPacketFilter = (android.os.IBinder.FIRST_CALL_TRANSACTION + 10);
    static final int TRANSACTION_setFallbackMulticastFilter = (android.os.IBinder.FIRST_CALL_TRANSACTION + 11);
    static final int TRANSACTION_setNeighborDiscoveryOffload = (android.os.IBinder.FIRST_CALL_TRANSACTION + 12);
    static final int TRANSACTION_onPreconnectionStart = (android.os.IBinder.FIRST_CALL_TRANSACTION + 13);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.net.ip.IIpClientCallbacks impl) {
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
    public static android.net.ip.IIpClientCallbacks getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$net$ip$IIpClientCallbacks".replace('$', '.');
  public void onIpClientCreated(android.net.ip.IIpClient ipClient) throws android.os.RemoteException;
  public void onPreDhcpAction() throws android.os.RemoteException;
  public void onPostDhcpAction() throws android.os.RemoteException;
  public void onNewDhcpResults(android.net.DhcpResultsParcelable dhcpResults) throws android.os.RemoteException;
  public void onProvisioningSuccess(android.net.LinkProperties newLp) throws android.os.RemoteException;
  public void onProvisioningFailure(android.net.LinkProperties newLp) throws android.os.RemoteException;
  public void onLinkPropertiesChange(android.net.LinkProperties newLp) throws android.os.RemoteException;
  public void onReachabilityLost(java.lang.String logMsg) throws android.os.RemoteException;
  public void onQuit() throws android.os.RemoteException;
  public void installPacketFilter(byte[] filter) throws android.os.RemoteException;
  public void startReadPacketFilter() throws android.os.RemoteException;
  public void setFallbackMulticastFilter(boolean enabled) throws android.os.RemoteException;
  public void setNeighborDiscoveryOffload(boolean enable) throws android.os.RemoteException;
  public void onPreconnectionStart(java.util.List<android.net.Layer2PacketParcelable> packets) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
