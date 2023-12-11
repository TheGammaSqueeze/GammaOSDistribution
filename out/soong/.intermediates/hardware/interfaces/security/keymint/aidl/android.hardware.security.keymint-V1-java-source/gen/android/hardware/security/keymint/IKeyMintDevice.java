/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.hardware.security.keymint;
/** @hide */
public interface IKeyMintDevice extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 1;
  public static final String HASH = "976674616001f714f4a4df49ee45f548de828524";
  /** Default implementation for IKeyMintDevice. */
  public static class Default implements android.hardware.security.keymint.IKeyMintDevice
  {
    @Override public android.hardware.security.keymint.KeyMintHardwareInfo getHardwareInfo() throws android.os.RemoteException
    {
      return null;
    }
    @Override public void addRngEntropy(byte[] data) throws android.os.RemoteException
    {
    }
    @Override public android.hardware.security.keymint.KeyCreationResult generateKey(android.hardware.security.keymint.KeyParameter[] keyParams, android.hardware.security.keymint.AttestationKey attestationKey) throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.hardware.security.keymint.KeyCreationResult importKey(android.hardware.security.keymint.KeyParameter[] keyParams, int keyFormat, byte[] keyData, android.hardware.security.keymint.AttestationKey attestationKey) throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.hardware.security.keymint.KeyCreationResult importWrappedKey(byte[] wrappedKeyData, byte[] wrappingKeyBlob, byte[] maskingKey, android.hardware.security.keymint.KeyParameter[] unwrappingParams, long passwordSid, long biometricSid) throws android.os.RemoteException
    {
      return null;
    }
    @Override public byte[] upgradeKey(byte[] keyBlobToUpgrade, android.hardware.security.keymint.KeyParameter[] upgradeParams) throws android.os.RemoteException
    {
      return null;
    }
    @Override public void deleteKey(byte[] keyBlob) throws android.os.RemoteException
    {
    }
    @Override public void deleteAllKeys() throws android.os.RemoteException
    {
    }
    @Override public void destroyAttestationIds() throws android.os.RemoteException
    {
    }
    @Override public android.hardware.security.keymint.BeginResult begin(int purpose, byte[] keyBlob, android.hardware.security.keymint.KeyParameter[] params, android.hardware.security.keymint.HardwareAuthToken authToken) throws android.os.RemoteException
    {
      return null;
    }
    @Override public void deviceLocked(boolean passwordOnly, android.hardware.security.secureclock.TimeStampToken timestampToken) throws android.os.RemoteException
    {
    }
    @Override public void earlyBootEnded() throws android.os.RemoteException
    {
    }
    @Override public byte[] convertStorageKeyToEphemeral(byte[] storageKeyBlob) throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.hardware.security.keymint.KeyCharacteristics[] getKeyCharacteristics(byte[] keyBlob, byte[] appId, byte[] appData) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.hardware.security.keymint.IKeyMintDevice
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.markVintfStability();
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.hardware.security.keymint.IKeyMintDevice interface,
     * generating a proxy if needed.
     */
    public static android.hardware.security.keymint.IKeyMintDevice asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.hardware.security.keymint.IKeyMintDevice))) {
        return ((android.hardware.security.keymint.IKeyMintDevice)iin);
      }
      return new android.hardware.security.keymint.IKeyMintDevice.Stub.Proxy(obj);
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
          android.hardware.security.keymint.KeyMintHardwareInfo _result = this.getHardwareInfo();
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
        case TRANSACTION_addRngEntropy:
        {
          data.enforceInterface(descriptor);
          byte[] _arg0;
          _arg0 = data.createByteArray();
          this.addRngEntropy(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_generateKey:
        {
          data.enforceInterface(descriptor);
          android.hardware.security.keymint.KeyParameter[] _arg0;
          _arg0 = data.createTypedArray(android.hardware.security.keymint.KeyParameter.CREATOR);
          android.hardware.security.keymint.AttestationKey _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.hardware.security.keymint.AttestationKey.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          android.hardware.security.keymint.KeyCreationResult _result = this.generateKey(_arg0, _arg1);
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
          android.hardware.security.keymint.KeyParameter[] _arg0;
          _arg0 = data.createTypedArray(android.hardware.security.keymint.KeyParameter.CREATOR);
          int _arg1;
          _arg1 = data.readInt();
          byte[] _arg2;
          _arg2 = data.createByteArray();
          android.hardware.security.keymint.AttestationKey _arg3;
          if ((0!=data.readInt())) {
            _arg3 = android.hardware.security.keymint.AttestationKey.CREATOR.createFromParcel(data);
          }
          else {
            _arg3 = null;
          }
          android.hardware.security.keymint.KeyCreationResult _result = this.importKey(_arg0, _arg1, _arg2, _arg3);
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
          byte[] _arg0;
          _arg0 = data.createByteArray();
          byte[] _arg1;
          _arg1 = data.createByteArray();
          byte[] _arg2;
          _arg2 = data.createByteArray();
          android.hardware.security.keymint.KeyParameter[] _arg3;
          _arg3 = data.createTypedArray(android.hardware.security.keymint.KeyParameter.CREATOR);
          long _arg4;
          _arg4 = data.readLong();
          long _arg5;
          _arg5 = data.readLong();
          android.hardware.security.keymint.KeyCreationResult _result = this.importWrappedKey(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5);
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
        case TRANSACTION_upgradeKey:
        {
          data.enforceInterface(descriptor);
          byte[] _arg0;
          _arg0 = data.createByteArray();
          android.hardware.security.keymint.KeyParameter[] _arg1;
          _arg1 = data.createTypedArray(android.hardware.security.keymint.KeyParameter.CREATOR);
          byte[] _result = this.upgradeKey(_arg0, _arg1);
          reply.writeNoException();
          reply.writeByteArray(_result);
          return true;
        }
        case TRANSACTION_deleteKey:
        {
          data.enforceInterface(descriptor);
          byte[] _arg0;
          _arg0 = data.createByteArray();
          this.deleteKey(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_deleteAllKeys:
        {
          data.enforceInterface(descriptor);
          this.deleteAllKeys();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_destroyAttestationIds:
        {
          data.enforceInterface(descriptor);
          this.destroyAttestationIds();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_begin:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          byte[] _arg1;
          _arg1 = data.createByteArray();
          android.hardware.security.keymint.KeyParameter[] _arg2;
          _arg2 = data.createTypedArray(android.hardware.security.keymint.KeyParameter.CREATOR);
          android.hardware.security.keymint.HardwareAuthToken _arg3;
          if ((0!=data.readInt())) {
            _arg3 = android.hardware.security.keymint.HardwareAuthToken.CREATOR.createFromParcel(data);
          }
          else {
            _arg3 = null;
          }
          android.hardware.security.keymint.BeginResult _result = this.begin(_arg0, _arg1, _arg2, _arg3);
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
        case TRANSACTION_deviceLocked:
        {
          data.enforceInterface(descriptor);
          boolean _arg0;
          _arg0 = (0!=data.readInt());
          android.hardware.security.secureclock.TimeStampToken _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.hardware.security.secureclock.TimeStampToken.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          this.deviceLocked(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_earlyBootEnded:
        {
          data.enforceInterface(descriptor);
          this.earlyBootEnded();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_convertStorageKeyToEphemeral:
        {
          data.enforceInterface(descriptor);
          byte[] _arg0;
          _arg0 = data.createByteArray();
          byte[] _result = this.convertStorageKeyToEphemeral(_arg0);
          reply.writeNoException();
          reply.writeByteArray(_result);
          return true;
        }
        case TRANSACTION_getKeyCharacteristics:
        {
          data.enforceInterface(descriptor);
          byte[] _arg0;
          _arg0 = data.createByteArray();
          byte[] _arg1;
          _arg1 = data.createByteArray();
          byte[] _arg2;
          _arg2 = data.createByteArray();
          android.hardware.security.keymint.KeyCharacteristics[] _result = this.getKeyCharacteristics(_arg0, _arg1, _arg2);
          reply.writeNoException();
          reply.writeTypedArray(_result, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.hardware.security.keymint.IKeyMintDevice
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
      @Override public android.hardware.security.keymint.KeyMintHardwareInfo getHardwareInfo() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.security.keymint.KeyMintHardwareInfo _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getHardwareInfo, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
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
            _result = android.hardware.security.keymint.KeyMintHardwareInfo.CREATOR.createFromParcel(_reply);
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
      @Override public void addRngEntropy(byte[] data) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByteArray(data);
          boolean _status = mRemote.transact(Stub.TRANSACTION_addRngEntropy, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().addRngEntropy(data);
              return;
            }
            else {
              throw new android.os.RemoteException("Method addRngEntropy is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public android.hardware.security.keymint.KeyCreationResult generateKey(android.hardware.security.keymint.KeyParameter[] keyParams, android.hardware.security.keymint.AttestationKey attestationKey) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.security.keymint.KeyCreationResult _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeTypedArray(keyParams, 0);
          if ((attestationKey!=null)) {
            _data.writeInt(1);
            attestationKey.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_generateKey, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().generateKey(keyParams, attestationKey);
            }
            else {
              throw new android.os.RemoteException("Method generateKey is unimplemented.");
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.hardware.security.keymint.KeyCreationResult.CREATOR.createFromParcel(_reply);
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
      @Override public android.hardware.security.keymint.KeyCreationResult importKey(android.hardware.security.keymint.KeyParameter[] keyParams, int keyFormat, byte[] keyData, android.hardware.security.keymint.AttestationKey attestationKey) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.security.keymint.KeyCreationResult _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeTypedArray(keyParams, 0);
          _data.writeInt(keyFormat);
          _data.writeByteArray(keyData);
          if ((attestationKey!=null)) {
            _data.writeInt(1);
            attestationKey.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_importKey, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().importKey(keyParams, keyFormat, keyData, attestationKey);
            }
            else {
              throw new android.os.RemoteException("Method importKey is unimplemented.");
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.hardware.security.keymint.KeyCreationResult.CREATOR.createFromParcel(_reply);
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
      @Override public android.hardware.security.keymint.KeyCreationResult importWrappedKey(byte[] wrappedKeyData, byte[] wrappingKeyBlob, byte[] maskingKey, android.hardware.security.keymint.KeyParameter[] unwrappingParams, long passwordSid, long biometricSid) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.security.keymint.KeyCreationResult _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByteArray(wrappedKeyData);
          _data.writeByteArray(wrappingKeyBlob);
          _data.writeByteArray(maskingKey);
          _data.writeTypedArray(unwrappingParams, 0);
          _data.writeLong(passwordSid);
          _data.writeLong(biometricSid);
          boolean _status = mRemote.transact(Stub.TRANSACTION_importWrappedKey, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().importWrappedKey(wrappedKeyData, wrappingKeyBlob, maskingKey, unwrappingParams, passwordSid, biometricSid);
            }
            else {
              throw new android.os.RemoteException("Method importWrappedKey is unimplemented.");
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.hardware.security.keymint.KeyCreationResult.CREATOR.createFromParcel(_reply);
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
      @Override public byte[] upgradeKey(byte[] keyBlobToUpgrade, android.hardware.security.keymint.KeyParameter[] upgradeParams) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        byte[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByteArray(keyBlobToUpgrade);
          _data.writeTypedArray(upgradeParams, 0);
          boolean _status = mRemote.transact(Stub.TRANSACTION_upgradeKey, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().upgradeKey(keyBlobToUpgrade, upgradeParams);
            }
            else {
              throw new android.os.RemoteException("Method upgradeKey is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createByteArray();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void deleteKey(byte[] keyBlob) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByteArray(keyBlob);
          boolean _status = mRemote.transact(Stub.TRANSACTION_deleteKey, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().deleteKey(keyBlob);
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
      @Override public void deleteAllKeys() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_deleteAllKeys, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().deleteAllKeys();
              return;
            }
            else {
              throw new android.os.RemoteException("Method deleteAllKeys is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void destroyAttestationIds() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_destroyAttestationIds, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().destroyAttestationIds();
              return;
            }
            else {
              throw new android.os.RemoteException("Method destroyAttestationIds is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public android.hardware.security.keymint.BeginResult begin(int purpose, byte[] keyBlob, android.hardware.security.keymint.KeyParameter[] params, android.hardware.security.keymint.HardwareAuthToken authToken) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.security.keymint.BeginResult _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(purpose);
          _data.writeByteArray(keyBlob);
          _data.writeTypedArray(params, 0);
          if ((authToken!=null)) {
            _data.writeInt(1);
            authToken.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_begin, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().begin(purpose, keyBlob, params, authToken);
            }
            else {
              throw new android.os.RemoteException("Method begin is unimplemented.");
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.hardware.security.keymint.BeginResult.CREATOR.createFromParcel(_reply);
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
      @Override public void deviceLocked(boolean passwordOnly, android.hardware.security.secureclock.TimeStampToken timestampToken) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(((passwordOnly)?(1):(0)));
          if ((timestampToken!=null)) {
            _data.writeInt(1);
            timestampToken.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_deviceLocked, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().deviceLocked(passwordOnly, timestampToken);
              return;
            }
            else {
              throw new android.os.RemoteException("Method deviceLocked is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void earlyBootEnded() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_earlyBootEnded, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().earlyBootEnded();
              return;
            }
            else {
              throw new android.os.RemoteException("Method earlyBootEnded is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public byte[] convertStorageKeyToEphemeral(byte[] storageKeyBlob) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        byte[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByteArray(storageKeyBlob);
          boolean _status = mRemote.transact(Stub.TRANSACTION_convertStorageKeyToEphemeral, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().convertStorageKeyToEphemeral(storageKeyBlob);
            }
            else {
              throw new android.os.RemoteException("Method convertStorageKeyToEphemeral is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createByteArray();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public android.hardware.security.keymint.KeyCharacteristics[] getKeyCharacteristics(byte[] keyBlob, byte[] appId, byte[] appData) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.security.keymint.KeyCharacteristics[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByteArray(keyBlob);
          _data.writeByteArray(appId);
          _data.writeByteArray(appData);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getKeyCharacteristics, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getKeyCharacteristics(keyBlob, appId, appData);
            }
            else {
              throw new android.os.RemoteException("Method getKeyCharacteristics is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createTypedArray(android.hardware.security.keymint.KeyCharacteristics.CREATOR);
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
      public static android.hardware.security.keymint.IKeyMintDevice sDefaultImpl;
    }
    static final int TRANSACTION_getHardwareInfo = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_addRngEntropy = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_generateKey = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_importKey = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_importWrappedKey = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_upgradeKey = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_deleteKey = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_deleteAllKeys = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
    static final int TRANSACTION_destroyAttestationIds = (android.os.IBinder.FIRST_CALL_TRANSACTION + 8);
    static final int TRANSACTION_begin = (android.os.IBinder.FIRST_CALL_TRANSACTION + 9);
    static final int TRANSACTION_deviceLocked = (android.os.IBinder.FIRST_CALL_TRANSACTION + 10);
    static final int TRANSACTION_earlyBootEnded = (android.os.IBinder.FIRST_CALL_TRANSACTION + 11);
    static final int TRANSACTION_convertStorageKeyToEphemeral = (android.os.IBinder.FIRST_CALL_TRANSACTION + 12);
    static final int TRANSACTION_getKeyCharacteristics = (android.os.IBinder.FIRST_CALL_TRANSACTION + 13);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.hardware.security.keymint.IKeyMintDevice impl) {
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
    public static android.hardware.security.keymint.IKeyMintDevice getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$hardware$security$keymint$IKeyMintDevice".replace('$', '.');
  public static final int AUTH_TOKEN_MAC_LENGTH = 32;
  public android.hardware.security.keymint.KeyMintHardwareInfo getHardwareInfo() throws android.os.RemoteException;
  public void addRngEntropy(byte[] data) throws android.os.RemoteException;
  public android.hardware.security.keymint.KeyCreationResult generateKey(android.hardware.security.keymint.KeyParameter[] keyParams, android.hardware.security.keymint.AttestationKey attestationKey) throws android.os.RemoteException;
  public android.hardware.security.keymint.KeyCreationResult importKey(android.hardware.security.keymint.KeyParameter[] keyParams, int keyFormat, byte[] keyData, android.hardware.security.keymint.AttestationKey attestationKey) throws android.os.RemoteException;
  public android.hardware.security.keymint.KeyCreationResult importWrappedKey(byte[] wrappedKeyData, byte[] wrappingKeyBlob, byte[] maskingKey, android.hardware.security.keymint.KeyParameter[] unwrappingParams, long passwordSid, long biometricSid) throws android.os.RemoteException;
  public byte[] upgradeKey(byte[] keyBlobToUpgrade, android.hardware.security.keymint.KeyParameter[] upgradeParams) throws android.os.RemoteException;
  public void deleteKey(byte[] keyBlob) throws android.os.RemoteException;
  public void deleteAllKeys() throws android.os.RemoteException;
  public void destroyAttestationIds() throws android.os.RemoteException;
  public android.hardware.security.keymint.BeginResult begin(int purpose, byte[] keyBlob, android.hardware.security.keymint.KeyParameter[] params, android.hardware.security.keymint.HardwareAuthToken authToken) throws android.os.RemoteException;
  public void deviceLocked(boolean passwordOnly, android.hardware.security.secureclock.TimeStampToken timestampToken) throws android.os.RemoteException;
  public void earlyBootEnded() throws android.os.RemoteException;
  public byte[] convertStorageKeyToEphemeral(byte[] storageKeyBlob) throws android.os.RemoteException;
  public android.hardware.security.keymint.KeyCharacteristics[] getKeyCharacteristics(byte[] keyBlob, byte[] appId, byte[] appData) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
