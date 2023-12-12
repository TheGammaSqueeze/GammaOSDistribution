/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.system.keystore2;
/** @hide */
public interface IKeystoreSecurityLevel extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 1;
  public static final String HASH = "19e8b65277839bad0ab335c781e3c652324920ce";
  /** Default implementation for IKeystoreSecurityLevel. */
  public static class Default implements android.system.keystore2.IKeystoreSecurityLevel
  {
    @Override public android.system.keystore2.CreateOperationResponse createOperation(android.system.keystore2.KeyDescriptor key, android.hardware.security.keymint.KeyParameter[] operationParameters, boolean forced) throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.system.keystore2.KeyMetadata generateKey(android.system.keystore2.KeyDescriptor key, android.system.keystore2.KeyDescriptor attestationKey, android.hardware.security.keymint.KeyParameter[] params, int flags, byte[] entropy) throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.system.keystore2.KeyMetadata importKey(android.system.keystore2.KeyDescriptor key, android.system.keystore2.KeyDescriptor attestationKey, android.hardware.security.keymint.KeyParameter[] params, int flags, byte[] keyData) throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.system.keystore2.KeyMetadata importWrappedKey(android.system.keystore2.KeyDescriptor key, android.system.keystore2.KeyDescriptor wrappingKey, byte[] maskingKey, android.hardware.security.keymint.KeyParameter[] params, android.system.keystore2.AuthenticatorSpec[] authenticators) throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.system.keystore2.EphemeralStorageKeyResponse convertStorageKeyToEphemeral(android.system.keystore2.KeyDescriptor storageKey) throws android.os.RemoteException
    {
      return null;
    }
    @Override public void deleteKey(android.system.keystore2.KeyDescriptor key) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.system.keystore2.IKeystoreSecurityLevel
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.markVintfStability();
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.system.keystore2.IKeystoreSecurityLevel interface,
     * generating a proxy if needed.
     */
    public static android.system.keystore2.IKeystoreSecurityLevel asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.system.keystore2.IKeystoreSecurityLevel))) {
        return ((android.system.keystore2.IKeystoreSecurityLevel)iin);
      }
      return new android.system.keystore2.IKeystoreSecurityLevel.Stub.Proxy(obj);
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
        case TRANSACTION_createOperation:
        {
          data.enforceInterface(descriptor);
          android.system.keystore2.KeyDescriptor _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          android.hardware.security.keymint.KeyParameter[] _arg1;
          _arg1 = data.createTypedArray(android.hardware.security.keymint.KeyParameter.CREATOR);
          boolean _arg2;
          _arg2 = (0!=data.readInt());
          android.system.keystore2.CreateOperationResponse _result = this.createOperation(_arg0, _arg1, _arg2);
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
        case TRANSACTION_generateKey:
        {
          data.enforceInterface(descriptor);
          android.system.keystore2.KeyDescriptor _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          android.system.keystore2.KeyDescriptor _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          android.hardware.security.keymint.KeyParameter[] _arg2;
          _arg2 = data.createTypedArray(android.hardware.security.keymint.KeyParameter.CREATOR);
          int _arg3;
          _arg3 = data.readInt();
          byte[] _arg4;
          _arg4 = data.createByteArray();
          android.system.keystore2.KeyMetadata _result = this.generateKey(_arg0, _arg1, _arg2, _arg3, _arg4);
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
        case TRANSACTION_importKey:
        {
          data.enforceInterface(descriptor);
          android.system.keystore2.KeyDescriptor _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          android.system.keystore2.KeyDescriptor _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          android.hardware.security.keymint.KeyParameter[] _arg2;
          _arg2 = data.createTypedArray(android.hardware.security.keymint.KeyParameter.CREATOR);
          int _arg3;
          _arg3 = data.readInt();
          byte[] _arg4;
          _arg4 = data.createByteArray();
          android.system.keystore2.KeyMetadata _result = this.importKey(_arg0, _arg1, _arg2, _arg3, _arg4);
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
        case TRANSACTION_importWrappedKey:
        {
          data.enforceInterface(descriptor);
          android.system.keystore2.KeyDescriptor _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          android.system.keystore2.KeyDescriptor _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          byte[] _arg2;
          _arg2 = data.createByteArray();
          android.hardware.security.keymint.KeyParameter[] _arg3;
          _arg3 = data.createTypedArray(android.hardware.security.keymint.KeyParameter.CREATOR);
          android.system.keystore2.AuthenticatorSpec[] _arg4;
          _arg4 = data.createTypedArray(android.system.keystore2.AuthenticatorSpec.CREATOR);
          android.system.keystore2.KeyMetadata _result = this.importWrappedKey(_arg0, _arg1, _arg2, _arg3, _arg4);
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
        case TRANSACTION_convertStorageKeyToEphemeral:
        {
          data.enforceInterface(descriptor);
          android.system.keystore2.KeyDescriptor _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.system.keystore2.KeyDescriptor.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          android.system.keystore2.EphemeralStorageKeyResponse _result = this.convertStorageKeyToEphemeral(_arg0);
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
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.system.keystore2.IKeystoreSecurityLevel
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
      @Override public android.system.keystore2.CreateOperationResponse createOperation(android.system.keystore2.KeyDescriptor key, android.hardware.security.keymint.KeyParameter[] operationParameters, boolean forced) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        android.system.keystore2.CreateOperationResponse _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((key!=null)) {
            _data.writeInt(1);
            key.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeTypedArray(operationParameters, 0);
          _data.writeInt(((forced)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_createOperation, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().createOperation(key, operationParameters, forced);
            }
            else {
              throw new android.os.RemoteException("Method createOperation is unimplemented.");
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.system.keystore2.CreateOperationResponse.CREATOR.createFromParcel(_reply);
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
      @Override public android.system.keystore2.KeyMetadata generateKey(android.system.keystore2.KeyDescriptor key, android.system.keystore2.KeyDescriptor attestationKey, android.hardware.security.keymint.KeyParameter[] params, int flags, byte[] entropy) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        android.system.keystore2.KeyMetadata _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((key!=null)) {
            _data.writeInt(1);
            key.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          if ((attestationKey!=null)) {
            _data.writeInt(1);
            attestationKey.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeTypedArray(params, 0);
          _data.writeInt(flags);
          _data.writeByteArray(entropy);
          boolean _status = mRemote.transact(Stub.TRANSACTION_generateKey, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().generateKey(key, attestationKey, params, flags, entropy);
            }
            else {
              throw new android.os.RemoteException("Method generateKey is unimplemented.");
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.system.keystore2.KeyMetadata.CREATOR.createFromParcel(_reply);
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
      @Override public android.system.keystore2.KeyMetadata importKey(android.system.keystore2.KeyDescriptor key, android.system.keystore2.KeyDescriptor attestationKey, android.hardware.security.keymint.KeyParameter[] params, int flags, byte[] keyData) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        android.system.keystore2.KeyMetadata _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((key!=null)) {
            _data.writeInt(1);
            key.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          if ((attestationKey!=null)) {
            _data.writeInt(1);
            attestationKey.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeTypedArray(params, 0);
          _data.writeInt(flags);
          _data.writeByteArray(keyData);
          boolean _status = mRemote.transact(Stub.TRANSACTION_importKey, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().importKey(key, attestationKey, params, flags, keyData);
            }
            else {
              throw new android.os.RemoteException("Method importKey is unimplemented.");
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.system.keystore2.KeyMetadata.CREATOR.createFromParcel(_reply);
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
      @Override public android.system.keystore2.KeyMetadata importWrappedKey(android.system.keystore2.KeyDescriptor key, android.system.keystore2.KeyDescriptor wrappingKey, byte[] maskingKey, android.hardware.security.keymint.KeyParameter[] params, android.system.keystore2.AuthenticatorSpec[] authenticators) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        android.system.keystore2.KeyMetadata _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((key!=null)) {
            _data.writeInt(1);
            key.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          if ((wrappingKey!=null)) {
            _data.writeInt(1);
            wrappingKey.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeByteArray(maskingKey);
          _data.writeTypedArray(params, 0);
          _data.writeTypedArray(authenticators, 0);
          boolean _status = mRemote.transact(Stub.TRANSACTION_importWrappedKey, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().importWrappedKey(key, wrappingKey, maskingKey, params, authenticators);
            }
            else {
              throw new android.os.RemoteException("Method importWrappedKey is unimplemented.");
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.system.keystore2.KeyMetadata.CREATOR.createFromParcel(_reply);
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
      @Override public android.system.keystore2.EphemeralStorageKeyResponse convertStorageKeyToEphemeral(android.system.keystore2.KeyDescriptor storageKey) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        android.system.keystore2.EphemeralStorageKeyResponse _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((storageKey!=null)) {
            _data.writeInt(1);
            storageKey.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_convertStorageKeyToEphemeral, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().convertStorageKeyToEphemeral(storageKey);
            }
            else {
              throw new android.os.RemoteException("Method convertStorageKeyToEphemeral is unimplemented.");
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.system.keystore2.EphemeralStorageKeyResponse.CREATOR.createFromParcel(_reply);
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
      @Override public void deleteKey(android.system.keystore2.KeyDescriptor key) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((key!=null)) {
            _data.writeInt(1);
            key.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_deleteKey, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
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
      public static android.system.keystore2.IKeystoreSecurityLevel sDefaultImpl;
    }
    static final int TRANSACTION_createOperation = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_generateKey = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_importKey = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_importWrappedKey = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_convertStorageKeyToEphemeral = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_deleteKey = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.system.keystore2.IKeystoreSecurityLevel impl) {
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
    public static android.system.keystore2.IKeystoreSecurityLevel getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$system$keystore2$IKeystoreSecurityLevel".replace('$', '.');
  public static final int KEY_FLAG_AUTH_BOUND_WITHOUT_CRYPTOGRAPHIC_LSKF_BINDING = 1;
  public android.system.keystore2.CreateOperationResponse createOperation(android.system.keystore2.KeyDescriptor key, android.hardware.security.keymint.KeyParameter[] operationParameters, boolean forced) throws android.os.RemoteException;
  public android.system.keystore2.KeyMetadata generateKey(android.system.keystore2.KeyDescriptor key, android.system.keystore2.KeyDescriptor attestationKey, android.hardware.security.keymint.KeyParameter[] params, int flags, byte[] entropy) throws android.os.RemoteException;
  public android.system.keystore2.KeyMetadata importKey(android.system.keystore2.KeyDescriptor key, android.system.keystore2.KeyDescriptor attestationKey, android.hardware.security.keymint.KeyParameter[] params, int flags, byte[] keyData) throws android.os.RemoteException;
  public android.system.keystore2.KeyMetadata importWrappedKey(android.system.keystore2.KeyDescriptor key, android.system.keystore2.KeyDescriptor wrappingKey, byte[] maskingKey, android.hardware.security.keymint.KeyParameter[] params, android.system.keystore2.AuthenticatorSpec[] authenticators) throws android.os.RemoteException;
  public android.system.keystore2.EphemeralStorageKeyResponse convertStorageKeyToEphemeral(android.system.keystore2.KeyDescriptor storageKey) throws android.os.RemoteException;
  public void deleteKey(android.system.keystore2.KeyDescriptor key) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
