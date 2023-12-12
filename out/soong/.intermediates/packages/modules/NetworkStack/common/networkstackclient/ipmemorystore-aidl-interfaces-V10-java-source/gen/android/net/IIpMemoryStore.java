/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
/** @hide */
public interface IIpMemoryStore extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 10;
  public static final String HASH = "d5ea5eb3ddbdaa9a986ce6ba70b0804ca3e39b0c";
  /** Default implementation for IIpMemoryStore. */
  public static class Default implements android.net.IIpMemoryStore
  {
    @Override public void storeNetworkAttributes(java.lang.String l2Key, android.net.ipmemorystore.NetworkAttributesParcelable attributes, android.net.ipmemorystore.IOnStatusListener listener) throws android.os.RemoteException
    {
    }
    @Override public void storeBlob(java.lang.String l2Key, java.lang.String clientId, java.lang.String name, android.net.ipmemorystore.Blob data, android.net.ipmemorystore.IOnStatusListener listener) throws android.os.RemoteException
    {
    }
    @Override public void findL2Key(android.net.ipmemorystore.NetworkAttributesParcelable attributes, android.net.ipmemorystore.IOnL2KeyResponseListener listener) throws android.os.RemoteException
    {
    }
    @Override public void isSameNetwork(java.lang.String l2Key1, java.lang.String l2Key2, android.net.ipmemorystore.IOnSameL3NetworkResponseListener listener) throws android.os.RemoteException
    {
    }
    @Override public void retrieveNetworkAttributes(java.lang.String l2Key, android.net.ipmemorystore.IOnNetworkAttributesRetrievedListener listener) throws android.os.RemoteException
    {
    }
    @Override public void retrieveBlob(java.lang.String l2Key, java.lang.String clientId, java.lang.String name, android.net.ipmemorystore.IOnBlobRetrievedListener listener) throws android.os.RemoteException
    {
    }
    @Override public void factoryReset() throws android.os.RemoteException
    {
    }
    @Override public void delete(java.lang.String l2Key, boolean needWipe, android.net.ipmemorystore.IOnStatusAndCountListener listener) throws android.os.RemoteException
    {
    }
    @Override public void deleteCluster(java.lang.String cluster, boolean needWipe, android.net.ipmemorystore.IOnStatusAndCountListener listener) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.net.IIpMemoryStore
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.net.IIpMemoryStore interface,
     * generating a proxy if needed.
     */
    public static android.net.IIpMemoryStore asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.net.IIpMemoryStore))) {
        return ((android.net.IIpMemoryStore)iin);
      }
      return new android.net.IIpMemoryStore.Stub.Proxy(obj);
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
        case TRANSACTION_storeNetworkAttributes:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          android.net.ipmemorystore.NetworkAttributesParcelable _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.net.ipmemorystore.NetworkAttributesParcelable.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          android.net.ipmemorystore.IOnStatusListener _arg2;
          _arg2 = android.net.ipmemorystore.IOnStatusListener.Stub.asInterface(data.readStrongBinder());
          this.storeNetworkAttributes(_arg0, _arg1, _arg2);
          return true;
        }
        case TRANSACTION_storeBlob:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          java.lang.String _arg2;
          _arg2 = data.readString();
          android.net.ipmemorystore.Blob _arg3;
          if ((0!=data.readInt())) {
            _arg3 = android.net.ipmemorystore.Blob.CREATOR.createFromParcel(data);
          }
          else {
            _arg3 = null;
          }
          android.net.ipmemorystore.IOnStatusListener _arg4;
          _arg4 = android.net.ipmemorystore.IOnStatusListener.Stub.asInterface(data.readStrongBinder());
          this.storeBlob(_arg0, _arg1, _arg2, _arg3, _arg4);
          return true;
        }
        case TRANSACTION_findL2Key:
        {
          data.enforceInterface(descriptor);
          android.net.ipmemorystore.NetworkAttributesParcelable _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.ipmemorystore.NetworkAttributesParcelable.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          android.net.ipmemorystore.IOnL2KeyResponseListener _arg1;
          _arg1 = android.net.ipmemorystore.IOnL2KeyResponseListener.Stub.asInterface(data.readStrongBinder());
          this.findL2Key(_arg0, _arg1);
          return true;
        }
        case TRANSACTION_isSameNetwork:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          android.net.ipmemorystore.IOnSameL3NetworkResponseListener _arg2;
          _arg2 = android.net.ipmemorystore.IOnSameL3NetworkResponseListener.Stub.asInterface(data.readStrongBinder());
          this.isSameNetwork(_arg0, _arg1, _arg2);
          return true;
        }
        case TRANSACTION_retrieveNetworkAttributes:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          android.net.ipmemorystore.IOnNetworkAttributesRetrievedListener _arg1;
          _arg1 = android.net.ipmemorystore.IOnNetworkAttributesRetrievedListener.Stub.asInterface(data.readStrongBinder());
          this.retrieveNetworkAttributes(_arg0, _arg1);
          return true;
        }
        case TRANSACTION_retrieveBlob:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          java.lang.String _arg1;
          _arg1 = data.readString();
          java.lang.String _arg2;
          _arg2 = data.readString();
          android.net.ipmemorystore.IOnBlobRetrievedListener _arg3;
          _arg3 = android.net.ipmemorystore.IOnBlobRetrievedListener.Stub.asInterface(data.readStrongBinder());
          this.retrieveBlob(_arg0, _arg1, _arg2, _arg3);
          return true;
        }
        case TRANSACTION_factoryReset:
        {
          data.enforceInterface(descriptor);
          this.factoryReset();
          return true;
        }
        case TRANSACTION_delete:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          boolean _arg1;
          _arg1 = (0!=data.readInt());
          android.net.ipmemorystore.IOnStatusAndCountListener _arg2;
          _arg2 = android.net.ipmemorystore.IOnStatusAndCountListener.Stub.asInterface(data.readStrongBinder());
          this.delete(_arg0, _arg1, _arg2);
          return true;
        }
        case TRANSACTION_deleteCluster:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          boolean _arg1;
          _arg1 = (0!=data.readInt());
          android.net.ipmemorystore.IOnStatusAndCountListener _arg2;
          _arg2 = android.net.ipmemorystore.IOnStatusAndCountListener.Stub.asInterface(data.readStrongBinder());
          this.deleteCluster(_arg0, _arg1, _arg2);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.net.IIpMemoryStore
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
      @Override public void storeNetworkAttributes(java.lang.String l2Key, android.net.ipmemorystore.NetworkAttributesParcelable attributes, android.net.ipmemorystore.IOnStatusListener listener) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(l2Key);
          if ((attributes!=null)) {
            _data.writeInt(1);
            attributes.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeStrongBinder((((listener!=null))?(listener.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_storeNetworkAttributes, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().storeNetworkAttributes(l2Key, attributes, listener);
              return;
            }
            else {
              throw new android.os.RemoteException("Method storeNetworkAttributes is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void storeBlob(java.lang.String l2Key, java.lang.String clientId, java.lang.String name, android.net.ipmemorystore.Blob data, android.net.ipmemorystore.IOnStatusListener listener) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(l2Key);
          _data.writeString(clientId);
          _data.writeString(name);
          if ((data!=null)) {
            _data.writeInt(1);
            data.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeStrongBinder((((listener!=null))?(listener.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_storeBlob, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().storeBlob(l2Key, clientId, name, data, listener);
              return;
            }
            else {
              throw new android.os.RemoteException("Method storeBlob is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void findL2Key(android.net.ipmemorystore.NetworkAttributesParcelable attributes, android.net.ipmemorystore.IOnL2KeyResponseListener listener) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((attributes!=null)) {
            _data.writeInt(1);
            attributes.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeStrongBinder((((listener!=null))?(listener.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_findL2Key, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().findL2Key(attributes, listener);
              return;
            }
            else {
              throw new android.os.RemoteException("Method findL2Key is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void isSameNetwork(java.lang.String l2Key1, java.lang.String l2Key2, android.net.ipmemorystore.IOnSameL3NetworkResponseListener listener) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(l2Key1);
          _data.writeString(l2Key2);
          _data.writeStrongBinder((((listener!=null))?(listener.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_isSameNetwork, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().isSameNetwork(l2Key1, l2Key2, listener);
              return;
            }
            else {
              throw new android.os.RemoteException("Method isSameNetwork is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void retrieveNetworkAttributes(java.lang.String l2Key, android.net.ipmemorystore.IOnNetworkAttributesRetrievedListener listener) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(l2Key);
          _data.writeStrongBinder((((listener!=null))?(listener.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_retrieveNetworkAttributes, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().retrieveNetworkAttributes(l2Key, listener);
              return;
            }
            else {
              throw new android.os.RemoteException("Method retrieveNetworkAttributes is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void retrieveBlob(java.lang.String l2Key, java.lang.String clientId, java.lang.String name, android.net.ipmemorystore.IOnBlobRetrievedListener listener) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(l2Key);
          _data.writeString(clientId);
          _data.writeString(name);
          _data.writeStrongBinder((((listener!=null))?(listener.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_retrieveBlob, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().retrieveBlob(l2Key, clientId, name, listener);
              return;
            }
            else {
              throw new android.os.RemoteException("Method retrieveBlob is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void factoryReset() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_factoryReset, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().factoryReset();
              return;
            }
            else {
              throw new android.os.RemoteException("Method factoryReset is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void delete(java.lang.String l2Key, boolean needWipe, android.net.ipmemorystore.IOnStatusAndCountListener listener) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(l2Key);
          _data.writeInt(((needWipe)?(1):(0)));
          _data.writeStrongBinder((((listener!=null))?(listener.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_delete, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().delete(l2Key, needWipe, listener);
              return;
            }
            else {
              throw new android.os.RemoteException("Method delete is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void deleteCluster(java.lang.String cluster, boolean needWipe, android.net.ipmemorystore.IOnStatusAndCountListener listener) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(cluster);
          _data.writeInt(((needWipe)?(1):(0)));
          _data.writeStrongBinder((((listener!=null))?(listener.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_deleteCluster, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().deleteCluster(cluster, needWipe, listener);
              return;
            }
            else {
              throw new android.os.RemoteException("Method deleteCluster is unimplemented.");
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
      public static android.net.IIpMemoryStore sDefaultImpl;
    }
    static final int TRANSACTION_storeNetworkAttributes = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_storeBlob = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_findL2Key = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_isSameNetwork = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_retrieveNetworkAttributes = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_retrieveBlob = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_factoryReset = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_delete = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
    static final int TRANSACTION_deleteCluster = (android.os.IBinder.FIRST_CALL_TRANSACTION + 8);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.net.IIpMemoryStore impl) {
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
    public static android.net.IIpMemoryStore getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$net$IIpMemoryStore".replace('$', '.');
  public void storeNetworkAttributes(java.lang.String l2Key, android.net.ipmemorystore.NetworkAttributesParcelable attributes, android.net.ipmemorystore.IOnStatusListener listener) throws android.os.RemoteException;
  public void storeBlob(java.lang.String l2Key, java.lang.String clientId, java.lang.String name, android.net.ipmemorystore.Blob data, android.net.ipmemorystore.IOnStatusListener listener) throws android.os.RemoteException;
  public void findL2Key(android.net.ipmemorystore.NetworkAttributesParcelable attributes, android.net.ipmemorystore.IOnL2KeyResponseListener listener) throws android.os.RemoteException;
  public void isSameNetwork(java.lang.String l2Key1, java.lang.String l2Key2, android.net.ipmemorystore.IOnSameL3NetworkResponseListener listener) throws android.os.RemoteException;
  public void retrieveNetworkAttributes(java.lang.String l2Key, android.net.ipmemorystore.IOnNetworkAttributesRetrievedListener listener) throws android.os.RemoteException;
  public void retrieveBlob(java.lang.String l2Key, java.lang.String clientId, java.lang.String name, android.net.ipmemorystore.IOnBlobRetrievedListener listener) throws android.os.RemoteException;
  public void factoryReset() throws android.os.RemoteException;
  public void delete(java.lang.String l2Key, boolean needWipe, android.net.ipmemorystore.IOnStatusAndCountListener listener) throws android.os.RemoteException;
  public void deleteCluster(java.lang.String cluster, boolean needWipe, android.net.ipmemorystore.IOnStatusAndCountListener listener) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
