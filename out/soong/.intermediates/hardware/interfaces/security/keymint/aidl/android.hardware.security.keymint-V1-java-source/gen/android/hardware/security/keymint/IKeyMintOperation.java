/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.hardware.security.keymint;
/** @hide */
public interface IKeyMintOperation extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 1;
  public static final String HASH = "976674616001f714f4a4df49ee45f548de828524";
  /** Default implementation for IKeyMintOperation. */
  public static class Default implements android.hardware.security.keymint.IKeyMintOperation
  {
    @Override public void updateAad(byte[] input, android.hardware.security.keymint.HardwareAuthToken authToken, android.hardware.security.secureclock.TimeStampToken timeStampToken) throws android.os.RemoteException
    {
    }
    @Override public byte[] update(byte[] input, android.hardware.security.keymint.HardwareAuthToken authToken, android.hardware.security.secureclock.TimeStampToken timeStampToken) throws android.os.RemoteException
    {
      return null;
    }
    @Override public byte[] finish(byte[] input, byte[] signature, android.hardware.security.keymint.HardwareAuthToken authToken, android.hardware.security.secureclock.TimeStampToken timestampToken, byte[] confirmationToken) throws android.os.RemoteException
    {
      return null;
    }
    @Override public void abort() throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.hardware.security.keymint.IKeyMintOperation
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.markVintfStability();
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.hardware.security.keymint.IKeyMintOperation interface,
     * generating a proxy if needed.
     */
    public static android.hardware.security.keymint.IKeyMintOperation asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.hardware.security.keymint.IKeyMintOperation))) {
        return ((android.hardware.security.keymint.IKeyMintOperation)iin);
      }
      return new android.hardware.security.keymint.IKeyMintOperation.Stub.Proxy(obj);
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
        case TRANSACTION_updateAad:
        {
          data.enforceInterface(descriptor);
          byte[] _arg0;
          _arg0 = data.createByteArray();
          android.hardware.security.keymint.HardwareAuthToken _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.hardware.security.keymint.HardwareAuthToken.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          android.hardware.security.secureclock.TimeStampToken _arg2;
          if ((0!=data.readInt())) {
            _arg2 = android.hardware.security.secureclock.TimeStampToken.CREATOR.createFromParcel(data);
          }
          else {
            _arg2 = null;
          }
          this.updateAad(_arg0, _arg1, _arg2);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_update:
        {
          data.enforceInterface(descriptor);
          byte[] _arg0;
          _arg0 = data.createByteArray();
          android.hardware.security.keymint.HardwareAuthToken _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.hardware.security.keymint.HardwareAuthToken.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          android.hardware.security.secureclock.TimeStampToken _arg2;
          if ((0!=data.readInt())) {
            _arg2 = android.hardware.security.secureclock.TimeStampToken.CREATOR.createFromParcel(data);
          }
          else {
            _arg2 = null;
          }
          byte[] _result = this.update(_arg0, _arg1, _arg2);
          reply.writeNoException();
          reply.writeByteArray(_result);
          return true;
        }
        case TRANSACTION_finish:
        {
          data.enforceInterface(descriptor);
          byte[] _arg0;
          _arg0 = data.createByteArray();
          byte[] _arg1;
          _arg1 = data.createByteArray();
          android.hardware.security.keymint.HardwareAuthToken _arg2;
          if ((0!=data.readInt())) {
            _arg2 = android.hardware.security.keymint.HardwareAuthToken.CREATOR.createFromParcel(data);
          }
          else {
            _arg2 = null;
          }
          android.hardware.security.secureclock.TimeStampToken _arg3;
          if ((0!=data.readInt())) {
            _arg3 = android.hardware.security.secureclock.TimeStampToken.CREATOR.createFromParcel(data);
          }
          else {
            _arg3 = null;
          }
          byte[] _arg4;
          _arg4 = data.createByteArray();
          byte[] _result = this.finish(_arg0, _arg1, _arg2, _arg3, _arg4);
          reply.writeNoException();
          reply.writeByteArray(_result);
          return true;
        }
        case TRANSACTION_abort:
        {
          data.enforceInterface(descriptor);
          this.abort();
          reply.writeNoException();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.hardware.security.keymint.IKeyMintOperation
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
      @Override public void updateAad(byte[] input, android.hardware.security.keymint.HardwareAuthToken authToken, android.hardware.security.secureclock.TimeStampToken timeStampToken) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByteArray(input);
          if ((authToken!=null)) {
            _data.writeInt(1);
            authToken.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          if ((timeStampToken!=null)) {
            _data.writeInt(1);
            timeStampToken.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_updateAad, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().updateAad(input, authToken, timeStampToken);
              return;
            }
            else {
              throw new android.os.RemoteException("Method updateAad is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public byte[] update(byte[] input, android.hardware.security.keymint.HardwareAuthToken authToken, android.hardware.security.secureclock.TimeStampToken timeStampToken) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        byte[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByteArray(input);
          if ((authToken!=null)) {
            _data.writeInt(1);
            authToken.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          if ((timeStampToken!=null)) {
            _data.writeInt(1);
            timeStampToken.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_update, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().update(input, authToken, timeStampToken);
            }
            else {
              throw new android.os.RemoteException("Method update is unimplemented.");
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
      @Override public byte[] finish(byte[] input, byte[] signature, android.hardware.security.keymint.HardwareAuthToken authToken, android.hardware.security.secureclock.TimeStampToken timestampToken, byte[] confirmationToken) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        byte[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByteArray(input);
          _data.writeByteArray(signature);
          if ((authToken!=null)) {
            _data.writeInt(1);
            authToken.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          if ((timestampToken!=null)) {
            _data.writeInt(1);
            timestampToken.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeByteArray(confirmationToken);
          boolean _status = mRemote.transact(Stub.TRANSACTION_finish, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().finish(input, signature, authToken, timestampToken, confirmationToken);
            }
            else {
              throw new android.os.RemoteException("Method finish is unimplemented.");
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
      @Override public void abort() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        _data.markSensitive();android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_abort, _data, _reply, android.os.IBinder.FLAG_CLEAR_BUF);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().abort();
              return;
            }
            else {
              throw new android.os.RemoteException("Method abort is unimplemented.");
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
      public static android.hardware.security.keymint.IKeyMintOperation sDefaultImpl;
    }
    static final int TRANSACTION_updateAad = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_update = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_finish = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_abort = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.hardware.security.keymint.IKeyMintOperation impl) {
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
    public static android.hardware.security.keymint.IKeyMintOperation getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$hardware$security$keymint$IKeyMintOperation".replace('$', '.');
  public void updateAad(byte[] input, android.hardware.security.keymint.HardwareAuthToken authToken, android.hardware.security.secureclock.TimeStampToken timeStampToken) throws android.os.RemoteException;
  public byte[] update(byte[] input, android.hardware.security.keymint.HardwareAuthToken authToken, android.hardware.security.secureclock.TimeStampToken timeStampToken) throws android.os.RemoteException;
  public byte[] finish(byte[] input, byte[] signature, android.hardware.security.keymint.HardwareAuthToken authToken, android.hardware.security.secureclock.TimeStampToken timestampToken, byte[] confirmationToken) throws android.os.RemoteException;
  public void abort() throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
