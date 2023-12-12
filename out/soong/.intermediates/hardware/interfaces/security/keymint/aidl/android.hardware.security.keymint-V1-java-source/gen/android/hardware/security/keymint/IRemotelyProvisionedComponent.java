/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.hardware.security.keymint;
/** @hide */
public interface IRemotelyProvisionedComponent extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 1;
  public static final String HASH = "976674616001f714f4a4df49ee45f548de828524";
  /** Default implementation for IRemotelyProvisionedComponent. */
  public static class Default implements android.hardware.security.keymint.IRemotelyProvisionedComponent
  {
    @Override public android.hardware.security.keymint.RpcHardwareInfo getHardwareInfo() throws android.os.RemoteException
    {
      return null;
    }
    @Override public byte[] generateEcdsaP256KeyPair(boolean testMode, android.hardware.security.keymint.MacedPublicKey macedPublicKey) throws android.os.RemoteException
    {
      return null;
    }
    @Override public byte[] generateCertificateRequest(boolean testMode, android.hardware.security.keymint.MacedPublicKey[] keysToSign, byte[] endpointEncryptionCertChain, byte[] challenge, android.hardware.security.keymint.DeviceInfo deviceInfo, android.hardware.security.keymint.ProtectedData protectedData) throws android.os.RemoteException
    {
      return null;
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
  public static abstract class Stub extends android.os.Binder implements android.hardware.security.keymint.IRemotelyProvisionedComponent
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.markVintfStability();
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.hardware.security.keymint.IRemotelyProvisionedComponent interface,
     * generating a proxy if needed.
     */
    public static android.hardware.security.keymint.IRemotelyProvisionedComponent asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.hardware.security.keymint.IRemotelyProvisionedComponent))) {
        return ((android.hardware.security.keymint.IRemotelyProvisionedComponent)iin);
      }
      return new android.hardware.security.keymint.IRemotelyProvisionedComponent.Stub.Proxy(obj);
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
        case TRANSACTION_getHardwareInfo:
        {
          data.enforceInterface(descriptor);
          android.hardware.security.keymint.RpcHardwareInfo _result = this.getHardwareInfo();
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
        case TRANSACTION_generateEcdsaP256KeyPair:
        {
          data.enforceInterface(descriptor);
          boolean _arg0;
          _arg0 = (0!=data.readInt());
          android.hardware.security.keymint.MacedPublicKey _arg1;
          _arg1 = new android.hardware.security.keymint.MacedPublicKey();
          byte[] _result = this.generateEcdsaP256KeyPair(_arg0, _arg1);
          reply.writeNoException();
          reply.writeByteArray(_result);
          if ((_arg1!=null)) {
            reply.writeInt(1);
            _arg1.writeToParcel(reply, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          }
          else {
            reply.writeInt(0);
          }
          return true;
        }
        case TRANSACTION_generateCertificateRequest:
        {
          data.enforceInterface(descriptor);
          boolean _arg0;
          _arg0 = (0!=data.readInt());
          android.hardware.security.keymint.MacedPublicKey[] _arg1;
          _arg1 = data.createTypedArray(android.hardware.security.keymint.MacedPublicKey.CREATOR);
          byte[] _arg2;
          _arg2 = data.createByteArray();
          byte[] _arg3;
          _arg3 = data.createByteArray();
          android.hardware.security.keymint.DeviceInfo _arg4;
          _arg4 = new android.hardware.security.keymint.DeviceInfo();
          android.hardware.security.keymint.ProtectedData _arg5;
          _arg5 = new android.hardware.security.keymint.ProtectedData();
          byte[] _result = this.generateCertificateRequest(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5);
          reply.writeNoException();
          reply.writeByteArray(_result);
          if ((_arg4!=null)) {
            reply.writeInt(1);
            _arg4.writeToParcel(reply, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          }
          else {
            reply.writeInt(0);
          }
          if ((_arg5!=null)) {
            reply.writeInt(1);
            _arg5.writeToParcel(reply, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          }
          else {
            reply.writeInt(0);
          }
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.hardware.security.keymint.IRemotelyProvisionedComponent
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
      @Override public android.hardware.security.keymint.RpcHardwareInfo getHardwareInfo() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.security.keymint.RpcHardwareInfo _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getHardwareInfo, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getHardwareInfo();
            }
            else {
              throw new android.os.RemoteException("Method getHardwareInfo is unimplemented.");
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.hardware.security.keymint.RpcHardwareInfo.CREATOR.createFromParcel(_reply);
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
      @Override public byte[] generateEcdsaP256KeyPair(boolean testMode, android.hardware.security.keymint.MacedPublicKey macedPublicKey) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        byte[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(((testMode)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_generateEcdsaP256KeyPair, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().generateEcdsaP256KeyPair(testMode, macedPublicKey);
            }
            else {
              throw new android.os.RemoteException("Method generateEcdsaP256KeyPair is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createByteArray();
          if ((0!=_reply.readInt())) {
            macedPublicKey.readFromParcel(_reply);
          }
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public byte[] generateCertificateRequest(boolean testMode, android.hardware.security.keymint.MacedPublicKey[] keysToSign, byte[] endpointEncryptionCertChain, byte[] challenge, android.hardware.security.keymint.DeviceInfo deviceInfo, android.hardware.security.keymint.ProtectedData protectedData) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        byte[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(((testMode)?(1):(0)));
          _data.writeTypedArray(keysToSign, 0);
          _data.writeByteArray(endpointEncryptionCertChain);
          _data.writeByteArray(challenge);
          boolean _status = mRemote.transact(Stub.TRANSACTION_generateCertificateRequest, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().generateCertificateRequest(testMode, keysToSign, endpointEncryptionCertChain, challenge, deviceInfo, protectedData);
            }
            else {
              throw new android.os.RemoteException("Method generateCertificateRequest is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createByteArray();
          if ((0!=_reply.readInt())) {
            deviceInfo.readFromParcel(_reply);
          }
          if ((0!=_reply.readInt())) {
            protectedData.readFromParcel(_reply);
          }
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
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
      public static android.hardware.security.keymint.IRemotelyProvisionedComponent sDefaultImpl;
    }
    static final int TRANSACTION_getHardwareInfo = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_generateEcdsaP256KeyPair = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_generateCertificateRequest = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.hardware.security.keymint.IRemotelyProvisionedComponent impl) {
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
    public static android.hardware.security.keymint.IRemotelyProvisionedComponent getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$hardware$security$keymint$IRemotelyProvisionedComponent".replace('$', '.');
  public static final int STATUS_FAILED = 1;
  public static final int STATUS_INVALID_MAC = 2;
  public static final int STATUS_PRODUCTION_KEY_IN_TEST_REQUEST = 3;
  public static final int STATUS_TEST_KEY_IN_PRODUCTION_REQUEST = 4;
  public static final int STATUS_INVALID_EEK = 5;
  public android.hardware.security.keymint.RpcHardwareInfo getHardwareInfo() throws android.os.RemoteException;
  public byte[] generateEcdsaP256KeyPair(boolean testMode, android.hardware.security.keymint.MacedPublicKey macedPublicKey) throws android.os.RemoteException;
  public byte[] generateCertificateRequest(boolean testMode, android.hardware.security.keymint.MacedPublicKey[] keysToSign, byte[] endpointEncryptionCertChain, byte[] challenge, android.hardware.security.keymint.DeviceInfo deviceInfo, android.hardware.security.keymint.ProtectedData protectedData) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
