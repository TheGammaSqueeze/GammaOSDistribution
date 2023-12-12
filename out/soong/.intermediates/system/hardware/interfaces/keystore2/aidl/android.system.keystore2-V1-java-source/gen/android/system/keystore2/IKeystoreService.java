/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.system.keystore2;
/** @hide */
public interface IKeystoreService extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 1;
  public static final String HASH = "19e8b65277839bad0ab335c781e3c652324920ce";
  /** Default implementation for IKeystoreService. */
  public static class Default implements android.system.keystore2.IKeystoreService
  {
    @Override public android.system.keystore2.IKeystoreSecurityLevel getSecurityLevel(int securityLevel) throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.system.keystore2.KeyEntryResponse getKeyEntry(android.system.keystore2.KeyDescriptor key) throws android.os.RemoteException
    {
      return null;
    }
    @Override public void updateSubcomponent(android.system.keystore2.KeyDescriptor key, byte[] publicCert, byte[] certificateChain) throws android.os.RemoteException
    {
    }
    @Override public android.system.keystore2.KeyDescriptor[] listEntries(int domain, long nspace) throws android.os.RemoteException
    {
      return null;
    }
    @Override public void deleteKey(android.system.keystore2.KeyDescriptor key) throws android.os.RemoteException
    {
    }
    @Override public android.system.keystore2.KeyDescriptor grant(android.system.keystore2.KeyDescriptor key, int granteeUid, int accessVector) throws android.os.RemoteException
    {
      return null;
    }
    @Override public void ungrant(android.system.keystore2.KeyDescriptor key, int granteeUid) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.system.keystore2.IKeystoreService
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.markVintfStability();
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.system.keystore2.IKeystoreService interface,
     * generating a proxy if needed.
     */
    public static android.system.keystore2.IKeystoreService asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.system.keystore2.IKeystoreService))) {
        return ((android.system.keystore2.IKeystoreService)iin);
      }
      return new android.system.keystore2.IKeystoreService.Stub.Proxy(obj);
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
        case TRANSACTION_getSecurityLevel:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.system.keystore2.IKeystoreSecurityLevel _result = this.getSecurityLevel(_arg0);
          reply.writeNoException();
          reply.writeStrongBinder((((_result!=null))?(_result.asBinder()):(null)));
          return true;
        }
        case TRANSACTION_getKeyEntry:
        {
          data.enforceInterface(descriptor);
          android.system.keystore2.KeyDescriptor _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          android.system.keystore2.KeyEntryResponse _result = this.getKeyEntry(_arg0);
          reply.writeNoException();
          if ((_result!=null)) {
            reply.writeInt(1);
            _result.writeToParcel(reply, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          }
          else {
            reply.writeInt(0);
          }
          return true;
        }
        case TRANSACTION_updateSubcomponent:
        {
          data.enforceInterface(descriptor);
          android.system.keystore2.KeyDescriptor _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          byte[] _arg1;
          _arg1 = data.createByteArray();
          byte[] _arg2;
          _arg2 = data.createByteArray();
          this.updateSubcomponent(_arg0, _arg1, _arg2);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_listEntries:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          long _arg1;
          _arg1 = data.readLong();
          android.system.keystore2.KeyDescriptor[] _result = this.listEntries(_arg0, _arg1);
          reply.writeNoException();
          reply.writeTypedArray(_result, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          return true;
        }
        case TRANSACTION_deleteKey:
        {
          data.enforceInterface(descriptor);
          android.system.keystore2.KeyDescriptor _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.deleteKey(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_grant:
        {
          data.enforceInterface(descriptor);
          android.system.keystore2.KeyDescriptor _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          int _arg1;
          _arg1 = data.readInt();
          int _arg2;
          _arg2 = data.readInt();
          android.system.keystore2.KeyDescriptor _result = this.grant(_arg0, _arg1, _arg2);
          reply.writeNoException();
          if ((_result!=null)) {
            reply.writeInt(1);
            _result.writeToParcel(reply, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          }
          else {
            reply.writeInt(0);
          }
          return true;
        }
        case TRANSACTION_ungrant:
        {
          data.enforceInterface(descriptor);
          android.system.keystore2.KeyDescriptor _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          int _arg1;
          _arg1 = data.readInt();
          this.ungrant(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.system.keystore2.IKeystoreService
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
      @Override public android.system.keystore2.IKeystoreSecurityLevel getSecurityLevel(int securityLevel) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.system.keystore2.IKeystoreSecurityLevel _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(securityLevel);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getSecurityLevel, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getSecurityLevel(securityLevel);
            }
            else {
              throw new android.os.RemoteException("Method getSecurityLevel is unimplemented.");
            }
          }
          _reply.readException();
          _result = android.system.keystore2.IKeystoreSecurityLevel.Stub.asInterface(_reply.readStrongBinder());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public android.system.keystore2.KeyEntryResponse getKeyEntry(android.system.keystore2.KeyDescriptor key) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.system.keystore2.KeyEntryResponse _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((key!=null)) {
            _data.writeInt(1);
            key.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_getKeyEntry, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getKeyEntry(key);
            }
            else {
              throw new android.os.RemoteException("Method getKeyEntry is unimplemented.");
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.system.keystore2.KeyEntryResponse.CREATOR.createFromParcel(_reply);
          }
          else {
            _result = null;
          }
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void updateSubcomponent(android.system.keystore2.KeyDescriptor key, byte[] publicCert, byte[] certificateChain) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((key!=null)) {
            _data.writeInt(1);
            key.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeByteArray(publicCert);
          _data.writeByteArray(certificateChain);
          boolean _status = mRemote.transact(Stub.TRANSACTION_updateSubcomponent, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().updateSubcomponent(key, publicCert, certificateChain);
              return;
            }
            else {
              throw new android.os.RemoteException("Method updateSubcomponent is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public android.system.keystore2.KeyDescriptor[] listEntries(int domain, long nspace) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.system.keystore2.KeyDescriptor[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(domain);
          _data.writeLong(nspace);
          boolean _status = mRemote.transact(Stub.TRANSACTION_listEntries, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().listEntries(domain, nspace);
            }
            else {
              throw new android.os.RemoteException("Method listEntries is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createTypedArray(android.system.keystore2.KeyDescriptor.CREATOR);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void deleteKey(android.system.keystore2.KeyDescriptor key) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((key!=null)) {
            _data.writeInt(1);
            key.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_deleteKey, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().deleteKey(key);
              return;
            }
            else {
              throw new android.os.RemoteException("Method deleteKey is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public android.system.keystore2.KeyDescriptor grant(android.system.keystore2.KeyDescriptor key, int granteeUid, int accessVector) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.system.keystore2.KeyDescriptor _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((key!=null)) {
            _data.writeInt(1);
            key.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeInt(granteeUid);
          _data.writeInt(accessVector);
          boolean _status = mRemote.transact(Stub.TRANSACTION_grant, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().grant(key, granteeUid, accessVector);
            }
            else {
              throw new android.os.RemoteException("Method grant is unimplemented.");
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(_reply);
          }
          else {
            _result = null;
          }
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void ungrant(android.system.keystore2.KeyDescriptor key, int granteeUid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((key!=null)) {
            _data.writeInt(1);
            key.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeInt(granteeUid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_ungrant, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().ungrant(key, granteeUid);
              return;
            }
            else {
              throw new android.os.RemoteException("Method ungrant is unimplemented.");
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
      public static android.system.keystore2.IKeystoreService sDefaultImpl;
    }
    static final int TRANSACTION_getSecurityLevel = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_getKeyEntry = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_updateSubcomponent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_listEntries = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_deleteKey = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_grant = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_ungrant = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.system.keystore2.IKeystoreService impl) {
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
    public static android.system.keystore2.IKeystoreService getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$system$keystore2$IKeystoreService".replace('$', '.');
  public android.system.keystore2.IKeystoreSecurityLevel getSecurityLevel(int securityLevel) throws android.os.RemoteException;
  public android.system.keystore2.KeyEntryResponse getKeyEntry(android.system.keystore2.KeyDescriptor key) throws android.os.RemoteException;
  public void updateSubcomponent(android.system.keystore2.KeyDescriptor key, byte[] publicCert, byte[] certificateChain) throws android.os.RemoteException;
  public android.system.keystore2.KeyDescriptor[] listEntries(int domain, long nspace) throws android.os.RemoteException;
  public void deleteKey(android.system.keystore2.KeyDescriptor key) throws android.os.RemoteException;
  public android.system.keystore2.KeyDescriptor grant(android.system.keystore2.KeyDescriptor key, int granteeUid, int accessVector) throws android.os.RemoteException;
  public void ungrant(android.system.keystore2.KeyDescriptor key, int granteeUid) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
