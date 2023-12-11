/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.hardware.biometrics.fingerprint;
public interface ISession extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 1;
  public static final String HASH = "3621eefdbae063097dad0037cd1f111792ff12ec";
  /** Default implementation for ISession. */
  public static class Default implements android.hardware.biometrics.fingerprint.ISession
  {
    @Override public void generateChallenge() throws android.os.RemoteException
    {
    }
    @Override public void revokeChallenge(long challenge) throws android.os.RemoteException
    {
    }
    @Override public android.hardware.biometrics.common.ICancellationSignal enroll(android.hardware.keymaster.HardwareAuthToken hat) throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.hardware.biometrics.common.ICancellationSignal authenticate(long operationId) throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.hardware.biometrics.common.ICancellationSignal detectInteraction() throws android.os.RemoteException
    {
      return null;
    }
    @Override public void enumerateEnrollments() throws android.os.RemoteException
    {
    }
    @Override public void removeEnrollments(int[] enrollmentIds) throws android.os.RemoteException
    {
    }
    @Override public void getAuthenticatorId() throws android.os.RemoteException
    {
    }
    @Override public void invalidateAuthenticatorId() throws android.os.RemoteException
    {
    }
    @Override public void resetLockout(android.hardware.keymaster.HardwareAuthToken hat) throws android.os.RemoteException
    {
    }
    @Override public void close() throws android.os.RemoteException
    {
    }
    @Override public void onPointerDown(int pointerId, int x, int y, float minor, float major) throws android.os.RemoteException
    {
    }
    @Override public void onPointerUp(int pointerId) throws android.os.RemoteException
    {
    }
    @Override public void onUiReady() throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.hardware.biometrics.fingerprint.ISession
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.markVintfStability();
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.hardware.biometrics.fingerprint.ISession interface,
     * generating a proxy if needed.
     */
    public static android.hardware.biometrics.fingerprint.ISession asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.hardware.biometrics.fingerprint.ISession))) {
        return ((android.hardware.biometrics.fingerprint.ISession)iin);
      }
      return new android.hardware.biometrics.fingerprint.ISession.Stub.Proxy(obj);
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
        case TRANSACTION_generateChallenge:
        {
          data.enforceInterface(descriptor);
          this.generateChallenge();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_revokeChallenge:
        {
          data.enforceInterface(descriptor);
          long _arg0;
          _arg0 = data.readLong();
          this.revokeChallenge(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_enroll:
        {
          data.enforceInterface(descriptor);
          android.hardware.keymaster.HardwareAuthToken _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.hardware.keymaster.HardwareAuthToken.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          android.hardware.biometrics.common.ICancellationSignal _result = this.enroll(_arg0);
          reply.writeNoException();
          reply.writeStrongBinder((((_result!=null))?(_result.asBinder()):(null)));
          return true;
        }
        case TRANSACTION_authenticate:
        {
          data.enforceInterface(descriptor);
          long _arg0;
          _arg0 = data.readLong();
          android.hardware.biometrics.common.ICancellationSignal _result = this.authenticate(_arg0);
          reply.writeNoException();
          reply.writeStrongBinder((((_result!=null))?(_result.asBinder()):(null)));
          return true;
        }
        case TRANSACTION_detectInteraction:
        {
          data.enforceInterface(descriptor);
          android.hardware.biometrics.common.ICancellationSignal _result = this.detectInteraction();
          reply.writeNoException();
          reply.writeStrongBinder((((_result!=null))?(_result.asBinder()):(null)));
          return true;
        }
        case TRANSACTION_enumerateEnrollments:
        {
          data.enforceInterface(descriptor);
          this.enumerateEnrollments();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_removeEnrollments:
        {
          data.enforceInterface(descriptor);
          int[] _arg0;
          _arg0 = data.createIntArray();
          this.removeEnrollments(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getAuthenticatorId:
        {
          data.enforceInterface(descriptor);
          this.getAuthenticatorId();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_invalidateAuthenticatorId:
        {
          data.enforceInterface(descriptor);
          this.invalidateAuthenticatorId();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_resetLockout:
        {
          data.enforceInterface(descriptor);
          android.hardware.keymaster.HardwareAuthToken _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.hardware.keymaster.HardwareAuthToken.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.resetLockout(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_close:
        {
          data.enforceInterface(descriptor);
          this.close();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onPointerDown:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          int _arg2;
          _arg2 = data.readInt();
          float _arg3;
          _arg3 = data.readFloat();
          float _arg4;
          _arg4 = data.readFloat();
          this.onPointerDown(_arg0, _arg1, _arg2, _arg3, _arg4);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onPointerUp:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.onPointerUp(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onUiReady:
        {
          data.enforceInterface(descriptor);
          this.onUiReady();
          reply.writeNoException();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.hardware.biometrics.fingerprint.ISession
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
      @Override public void generateChallenge() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_generateChallenge, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().generateChallenge();
              return;
            }
            else {
              throw new android.os.RemoteException("Method generateChallenge is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void revokeChallenge(long challenge) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeLong(challenge);
          boolean _status = mRemote.transact(Stub.TRANSACTION_revokeChallenge, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().revokeChallenge(challenge);
              return;
            }
            else {
              throw new android.os.RemoteException("Method revokeChallenge is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public android.hardware.biometrics.common.ICancellationSignal enroll(android.hardware.keymaster.HardwareAuthToken hat) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.biometrics.common.ICancellationSignal _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((hat!=null)) {
            _data.writeInt(1);
            hat.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_enroll, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().enroll(hat);
            }
            else {
              throw new android.os.RemoteException("Method enroll is unimplemented.");
            }
          }
          _reply.readException();
          _result = android.hardware.biometrics.common.ICancellationSignal.Stub.asInterface(_reply.readStrongBinder());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public android.hardware.biometrics.common.ICancellationSignal authenticate(long operationId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.biometrics.common.ICancellationSignal _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeLong(operationId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_authenticate, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().authenticate(operationId);
            }
            else {
              throw new android.os.RemoteException("Method authenticate is unimplemented.");
            }
          }
          _reply.readException();
          _result = android.hardware.biometrics.common.ICancellationSignal.Stub.asInterface(_reply.readStrongBinder());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public android.hardware.biometrics.common.ICancellationSignal detectInteraction() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.biometrics.common.ICancellationSignal _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_detectInteraction, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().detectInteraction();
            }
            else {
              throw new android.os.RemoteException("Method detectInteraction is unimplemented.");
            }
          }
          _reply.readException();
          _result = android.hardware.biometrics.common.ICancellationSignal.Stub.asInterface(_reply.readStrongBinder());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void enumerateEnrollments() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_enumerateEnrollments, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().enumerateEnrollments();
              return;
            }
            else {
              throw new android.os.RemoteException("Method enumerateEnrollments is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void removeEnrollments(int[] enrollmentIds) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeIntArray(enrollmentIds);
          boolean _status = mRemote.transact(Stub.TRANSACTION_removeEnrollments, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().removeEnrollments(enrollmentIds);
              return;
            }
            else {
              throw new android.os.RemoteException("Method removeEnrollments is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void getAuthenticatorId() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getAuthenticatorId, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().getAuthenticatorId();
              return;
            }
            else {
              throw new android.os.RemoteException("Method getAuthenticatorId is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void invalidateAuthenticatorId() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_invalidateAuthenticatorId, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().invalidateAuthenticatorId();
              return;
            }
            else {
              throw new android.os.RemoteException("Method invalidateAuthenticatorId is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void resetLockout(android.hardware.keymaster.HardwareAuthToken hat) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((hat!=null)) {
            _data.writeInt(1);
            hat.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_resetLockout, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().resetLockout(hat);
              return;
            }
            else {
              throw new android.os.RemoteException("Method resetLockout is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void close() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_close, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().close();
              return;
            }
            else {
              throw new android.os.RemoteException("Method close is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onPointerDown(int pointerId, int x, int y, float minor, float major) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(pointerId);
          _data.writeInt(x);
          _data.writeInt(y);
          _data.writeFloat(minor);
          _data.writeFloat(major);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onPointerDown, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onPointerDown(pointerId, x, y, minor, major);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onPointerDown is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onPointerUp(int pointerId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(pointerId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onPointerUp, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onPointerUp(pointerId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onPointerUp is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onUiReady() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onUiReady, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onUiReady();
              return;
            }
            else {
              throw new android.os.RemoteException("Method onUiReady is unimplemented.");
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
      public static android.hardware.biometrics.fingerprint.ISession sDefaultImpl;
    }
    static final int TRANSACTION_generateChallenge = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_revokeChallenge = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_enroll = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_authenticate = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_detectInteraction = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_enumerateEnrollments = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_removeEnrollments = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_getAuthenticatorId = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
    static final int TRANSACTION_invalidateAuthenticatorId = (android.os.IBinder.FIRST_CALL_TRANSACTION + 8);
    static final int TRANSACTION_resetLockout = (android.os.IBinder.FIRST_CALL_TRANSACTION + 9);
    static final int TRANSACTION_close = (android.os.IBinder.FIRST_CALL_TRANSACTION + 10);
    static final int TRANSACTION_onPointerDown = (android.os.IBinder.FIRST_CALL_TRANSACTION + 11);
    static final int TRANSACTION_onPointerUp = (android.os.IBinder.FIRST_CALL_TRANSACTION + 12);
    static final int TRANSACTION_onUiReady = (android.os.IBinder.FIRST_CALL_TRANSACTION + 13);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.hardware.biometrics.fingerprint.ISession impl) {
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
    public static android.hardware.biometrics.fingerprint.ISession getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$hardware$biometrics$fingerprint$ISession".replace('$', '.');
  public void generateChallenge() throws android.os.RemoteException;
  public void revokeChallenge(long challenge) throws android.os.RemoteException;
  public android.hardware.biometrics.common.ICancellationSignal enroll(android.hardware.keymaster.HardwareAuthToken hat) throws android.os.RemoteException;
  public android.hardware.biometrics.common.ICancellationSignal authenticate(long operationId) throws android.os.RemoteException;
  public android.hardware.biometrics.common.ICancellationSignal detectInteraction() throws android.os.RemoteException;
  public void enumerateEnrollments() throws android.os.RemoteException;
  public void removeEnrollments(int[] enrollmentIds) throws android.os.RemoteException;
  public void getAuthenticatorId() throws android.os.RemoteException;
  public void invalidateAuthenticatorId() throws android.os.RemoteException;
  public void resetLockout(android.hardware.keymaster.HardwareAuthToken hat) throws android.os.RemoteException;
  public void close() throws android.os.RemoteException;
  public void onPointerDown(int pointerId, int x, int y, float minor, float major) throws android.os.RemoteException;
  public void onPointerUp(int pointerId) throws android.os.RemoteException;
  public void onUiReady() throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
