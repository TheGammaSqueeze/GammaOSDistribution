/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.hardware.biometrics.face;
public interface ISessionCallback extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 1;
  public static final String HASH = "3b10f5094c5af9fe551093597fab007d1e148256";
  /** Default implementation for ISessionCallback. */
  public static class Default implements android.hardware.biometrics.face.ISessionCallback
  {
    @Override public void onChallengeGenerated(long challenge) throws android.os.RemoteException
    {
    }
    @Override public void onChallengeRevoked(long challenge) throws android.os.RemoteException
    {
    }
    @Override public void onAuthenticationFrame(android.hardware.biometrics.face.AuthenticationFrame frame) throws android.os.RemoteException
    {
    }
    @Override public void onEnrollmentFrame(android.hardware.biometrics.face.EnrollmentFrame frame) throws android.os.RemoteException
    {
    }
    @Override public void onError(byte error, int vendorCode) throws android.os.RemoteException
    {
    }
    @Override public void onEnrollmentProgress(int enrollmentId, int remaining) throws android.os.RemoteException
    {
    }
    @Override public void onAuthenticationSucceeded(int enrollmentId, android.hardware.keymaster.HardwareAuthToken hat) throws android.os.RemoteException
    {
    }
    @Override public void onAuthenticationFailed() throws android.os.RemoteException
    {
    }
    @Override public void onLockoutTimed(long durationMillis) throws android.os.RemoteException
    {
    }
    @Override public void onLockoutPermanent() throws android.os.RemoteException
    {
    }
    @Override public void onLockoutCleared() throws android.os.RemoteException
    {
    }
    @Override public void onInteractionDetected() throws android.os.RemoteException
    {
    }
    @Override public void onEnrollmentsEnumerated(int[] enrollmentIds) throws android.os.RemoteException
    {
    }
    @Override public void onFeaturesRetrieved(byte[] features) throws android.os.RemoteException
    {
    }
    @Override public void onFeatureSet(byte feature) throws android.os.RemoteException
    {
    }
    @Override public void onEnrollmentsRemoved(int[] enrollmentIds) throws android.os.RemoteException
    {
    }
    @Override public void onAuthenticatorIdRetrieved(long authenticatorId) throws android.os.RemoteException
    {
    }
    @Override public void onAuthenticatorIdInvalidated(long newAuthenticatorId) throws android.os.RemoteException
    {
    }
    @Override public void onSessionClosed() throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.hardware.biometrics.face.ISessionCallback
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.markVintfStability();
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.hardware.biometrics.face.ISessionCallback interface,
     * generating a proxy if needed.
     */
    public static android.hardware.biometrics.face.ISessionCallback asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.hardware.biometrics.face.ISessionCallback))) {
        return ((android.hardware.biometrics.face.ISessionCallback)iin);
      }
      return new android.hardware.biometrics.face.ISessionCallback.Stub.Proxy(obj);
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
        case TRANSACTION_onChallengeGenerated:
        {
          data.enforceInterface(descriptor);
          long _arg0;
          _arg0 = data.readLong();
          this.onChallengeGenerated(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onChallengeRevoked:
        {
          data.enforceInterface(descriptor);
          long _arg0;
          _arg0 = data.readLong();
          this.onChallengeRevoked(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onAuthenticationFrame:
        {
          data.enforceInterface(descriptor);
          android.hardware.biometrics.face.AuthenticationFrame _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.hardware.biometrics.face.AuthenticationFrame.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.onAuthenticationFrame(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onEnrollmentFrame:
        {
          data.enforceInterface(descriptor);
          android.hardware.biometrics.face.EnrollmentFrame _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.hardware.biometrics.face.EnrollmentFrame.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.onEnrollmentFrame(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onError:
        {
          data.enforceInterface(descriptor);
          byte _arg0;
          _arg0 = data.readByte();
          int _arg1;
          _arg1 = data.readInt();
          this.onError(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onEnrollmentProgress:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          this.onEnrollmentProgress(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onAuthenticationSucceeded:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.hardware.keymaster.HardwareAuthToken _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.hardware.keymaster.HardwareAuthToken.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          this.onAuthenticationSucceeded(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onAuthenticationFailed:
        {
          data.enforceInterface(descriptor);
          this.onAuthenticationFailed();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onLockoutTimed:
        {
          data.enforceInterface(descriptor);
          long _arg0;
          _arg0 = data.readLong();
          this.onLockoutTimed(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onLockoutPermanent:
        {
          data.enforceInterface(descriptor);
          this.onLockoutPermanent();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onLockoutCleared:
        {
          data.enforceInterface(descriptor);
          this.onLockoutCleared();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onInteractionDetected:
        {
          data.enforceInterface(descriptor);
          this.onInteractionDetected();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onEnrollmentsEnumerated:
        {
          data.enforceInterface(descriptor);
          int[] _arg0;
          _arg0 = data.createIntArray();
          this.onEnrollmentsEnumerated(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onFeaturesRetrieved:
        {
          data.enforceInterface(descriptor);
          byte[] _arg0;
          _arg0 = data.createByteArray();
          this.onFeaturesRetrieved(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onFeatureSet:
        {
          data.enforceInterface(descriptor);
          byte _arg0;
          _arg0 = data.readByte();
          this.onFeatureSet(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onEnrollmentsRemoved:
        {
          data.enforceInterface(descriptor);
          int[] _arg0;
          _arg0 = data.createIntArray();
          this.onEnrollmentsRemoved(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onAuthenticatorIdRetrieved:
        {
          data.enforceInterface(descriptor);
          long _arg0;
          _arg0 = data.readLong();
          this.onAuthenticatorIdRetrieved(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onAuthenticatorIdInvalidated:
        {
          data.enforceInterface(descriptor);
          long _arg0;
          _arg0 = data.readLong();
          this.onAuthenticatorIdInvalidated(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onSessionClosed:
        {
          data.enforceInterface(descriptor);
          this.onSessionClosed();
          reply.writeNoException();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.hardware.biometrics.face.ISessionCallback
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
      @Override public void onChallengeGenerated(long challenge) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeLong(challenge);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onChallengeGenerated, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onChallengeGenerated(challenge);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onChallengeGenerated is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onChallengeRevoked(long challenge) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeLong(challenge);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onChallengeRevoked, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onChallengeRevoked(challenge);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onChallengeRevoked is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onAuthenticationFrame(android.hardware.biometrics.face.AuthenticationFrame frame) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((frame!=null)) {
            _data.writeInt(1);
            frame.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_onAuthenticationFrame, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onAuthenticationFrame(frame);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onAuthenticationFrame is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onEnrollmentFrame(android.hardware.biometrics.face.EnrollmentFrame frame) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((frame!=null)) {
            _data.writeInt(1);
            frame.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_onEnrollmentFrame, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onEnrollmentFrame(frame);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onEnrollmentFrame is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onError(byte error, int vendorCode) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByte(error);
          _data.writeInt(vendorCode);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onError, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onError(error, vendorCode);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onError is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onEnrollmentProgress(int enrollmentId, int remaining) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(enrollmentId);
          _data.writeInt(remaining);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onEnrollmentProgress, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onEnrollmentProgress(enrollmentId, remaining);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onEnrollmentProgress is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onAuthenticationSucceeded(int enrollmentId, android.hardware.keymaster.HardwareAuthToken hat) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(enrollmentId);
          if ((hat!=null)) {
            _data.writeInt(1);
            hat.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_onAuthenticationSucceeded, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onAuthenticationSucceeded(enrollmentId, hat);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onAuthenticationSucceeded is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onAuthenticationFailed() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onAuthenticationFailed, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onAuthenticationFailed();
              return;
            }
            else {
              throw new android.os.RemoteException("Method onAuthenticationFailed is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onLockoutTimed(long durationMillis) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeLong(durationMillis);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onLockoutTimed, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onLockoutTimed(durationMillis);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onLockoutTimed is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onLockoutPermanent() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onLockoutPermanent, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onLockoutPermanent();
              return;
            }
            else {
              throw new android.os.RemoteException("Method onLockoutPermanent is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onLockoutCleared() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onLockoutCleared, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onLockoutCleared();
              return;
            }
            else {
              throw new android.os.RemoteException("Method onLockoutCleared is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onInteractionDetected() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onInteractionDetected, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onInteractionDetected();
              return;
            }
            else {
              throw new android.os.RemoteException("Method onInteractionDetected is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onEnrollmentsEnumerated(int[] enrollmentIds) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeIntArray(enrollmentIds);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onEnrollmentsEnumerated, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onEnrollmentsEnumerated(enrollmentIds);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onEnrollmentsEnumerated is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onFeaturesRetrieved(byte[] features) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByteArray(features);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onFeaturesRetrieved, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onFeaturesRetrieved(features);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onFeaturesRetrieved is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onFeatureSet(byte feature) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByte(feature);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onFeatureSet, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onFeatureSet(feature);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onFeatureSet is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onEnrollmentsRemoved(int[] enrollmentIds) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeIntArray(enrollmentIds);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onEnrollmentsRemoved, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onEnrollmentsRemoved(enrollmentIds);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onEnrollmentsRemoved is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onAuthenticatorIdRetrieved(long authenticatorId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeLong(authenticatorId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onAuthenticatorIdRetrieved, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onAuthenticatorIdRetrieved(authenticatorId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onAuthenticatorIdRetrieved is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onAuthenticatorIdInvalidated(long newAuthenticatorId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeLong(newAuthenticatorId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onAuthenticatorIdInvalidated, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onAuthenticatorIdInvalidated(newAuthenticatorId);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onAuthenticatorIdInvalidated is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onSessionClosed() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onSessionClosed, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onSessionClosed();
              return;
            }
            else {
              throw new android.os.RemoteException("Method onSessionClosed is unimplemented.");
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
      public static android.hardware.biometrics.face.ISessionCallback sDefaultImpl;
    }
    static final int TRANSACTION_onChallengeGenerated = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_onChallengeRevoked = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_onAuthenticationFrame = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_onEnrollmentFrame = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_onError = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_onEnrollmentProgress = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_onAuthenticationSucceeded = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_onAuthenticationFailed = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
    static final int TRANSACTION_onLockoutTimed = (android.os.IBinder.FIRST_CALL_TRANSACTION + 8);
    static final int TRANSACTION_onLockoutPermanent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 9);
    static final int TRANSACTION_onLockoutCleared = (android.os.IBinder.FIRST_CALL_TRANSACTION + 10);
    static final int TRANSACTION_onInteractionDetected = (android.os.IBinder.FIRST_CALL_TRANSACTION + 11);
    static final int TRANSACTION_onEnrollmentsEnumerated = (android.os.IBinder.FIRST_CALL_TRANSACTION + 12);
    static final int TRANSACTION_onFeaturesRetrieved = (android.os.IBinder.FIRST_CALL_TRANSACTION + 13);
    static final int TRANSACTION_onFeatureSet = (android.os.IBinder.FIRST_CALL_TRANSACTION + 14);
    static final int TRANSACTION_onEnrollmentsRemoved = (android.os.IBinder.FIRST_CALL_TRANSACTION + 15);
    static final int TRANSACTION_onAuthenticatorIdRetrieved = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16);
    static final int TRANSACTION_onAuthenticatorIdInvalidated = (android.os.IBinder.FIRST_CALL_TRANSACTION + 17);
    static final int TRANSACTION_onSessionClosed = (android.os.IBinder.FIRST_CALL_TRANSACTION + 18);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.hardware.biometrics.face.ISessionCallback impl) {
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
    public static android.hardware.biometrics.face.ISessionCallback getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$hardware$biometrics$face$ISessionCallback".replace('$', '.');
  public void onChallengeGenerated(long challenge) throws android.os.RemoteException;
  public void onChallengeRevoked(long challenge) throws android.os.RemoteException;
  public void onAuthenticationFrame(android.hardware.biometrics.face.AuthenticationFrame frame) throws android.os.RemoteException;
  public void onEnrollmentFrame(android.hardware.biometrics.face.EnrollmentFrame frame) throws android.os.RemoteException;
  public void onError(byte error, int vendorCode) throws android.os.RemoteException;
  public void onEnrollmentProgress(int enrollmentId, int remaining) throws android.os.RemoteException;
  public void onAuthenticationSucceeded(int enrollmentId, android.hardware.keymaster.HardwareAuthToken hat) throws android.os.RemoteException;
  public void onAuthenticationFailed() throws android.os.RemoteException;
  public void onLockoutTimed(long durationMillis) throws android.os.RemoteException;
  public void onLockoutPermanent() throws android.os.RemoteException;
  public void onLockoutCleared() throws android.os.RemoteException;
  public void onInteractionDetected() throws android.os.RemoteException;
  public void onEnrollmentsEnumerated(int[] enrollmentIds) throws android.os.RemoteException;
  public void onFeaturesRetrieved(byte[] features) throws android.os.RemoteException;
  public void onFeatureSet(byte feature) throws android.os.RemoteException;
  public void onEnrollmentsRemoved(int[] enrollmentIds) throws android.os.RemoteException;
  public void onAuthenticatorIdRetrieved(long authenticatorId) throws android.os.RemoteException;
  public void onAuthenticatorIdInvalidated(long newAuthenticatorId) throws android.os.RemoteException;
  public void onSessionClosed() throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
