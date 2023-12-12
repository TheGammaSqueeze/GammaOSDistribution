/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.system.suspend.internal;
/**
 * Interface exposed by the suspend hal that allows framework to toggle the suspend loop and
 * monitor native wakelocks.
 * @hide
 */
public interface ISuspendControlServiceInternal extends android.os.IInterface
{
  /** Default implementation for ISuspendControlServiceInternal. */
  public static class Default implements android.system.suspend.internal.ISuspendControlServiceInternal
  {
    /**
         * Starts automatic system suspension.
         *
         * @return true on success, false otherwise.
         */
    @Override public boolean enableAutosuspend() throws android.os.RemoteException
    {
      return false;
    }
    /**
         * Suspends the system even if there are wakelocks being held.
         */
    @Override public boolean forceSuspend() throws android.os.RemoteException
    {
      return false;
    }
    /**
         * Returns a list of wake lock stats.
         */
    @Override public android.system.suspend.internal.WakeLockInfo[] getWakeLockStats() throws android.os.RemoteException
    {
      return null;
    }
    /**
         * Returns a list of wakeup stats.
         */
    @Override public android.system.suspend.internal.WakeupInfo[] getWakeupStats() throws android.os.RemoteException
    {
      return null;
    }
    /**
         * Returns stats related to suspend.
         */
    @Override public android.system.suspend.internal.SuspendInfo getSuspendStats() throws android.os.RemoteException
    {
      return null;
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements android.system.suspend.internal.ISuspendControlServiceInternal
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.system.suspend.internal.ISuspendControlServiceInternal interface,
     * generating a proxy if needed.
     */
    public static android.system.suspend.internal.ISuspendControlServiceInternal asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.system.suspend.internal.ISuspendControlServiceInternal))) {
        return ((android.system.suspend.internal.ISuspendControlServiceInternal)iin);
      }
      return new android.system.suspend.internal.ISuspendControlServiceInternal.Stub.Proxy(obj);
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
      }
      switch (code)
      {
        case TRANSACTION_enableAutosuspend:
        {
          data.enforceInterface(descriptor);
          boolean _result = this.enableAutosuspend();
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        case TRANSACTION_forceSuspend:
        {
          data.enforceInterface(descriptor);
          boolean _result = this.forceSuspend();
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        case TRANSACTION_getWakeLockStats:
        {
          data.enforceInterface(descriptor);
          android.system.suspend.internal.WakeLockInfo[] _result = this.getWakeLockStats();
          reply.writeNoException();
          reply.writeTypedArray(_result, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          return true;
        }
        case TRANSACTION_getWakeupStats:
        {
          data.enforceInterface(descriptor);
          android.system.suspend.internal.WakeupInfo[] _result = this.getWakeupStats();
          reply.writeNoException();
          reply.writeTypedArray(_result, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          return true;
        }
        case TRANSACTION_getSuspendStats:
        {
          data.enforceInterface(descriptor);
          android.system.suspend.internal.SuspendInfo _result = this.getSuspendStats();
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
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.system.suspend.internal.ISuspendControlServiceInternal
    {
      private android.os.IBinder mRemote;
      Proxy(android.os.IBinder remote)
      {
        mRemote = remote;
      }
      @Override public android.os.IBinder asBinder()
      {
        return mRemote;
      }
      public java.lang.String getInterfaceDescriptor()
      {
        return DESCRIPTOR;
      }
      /**
           * Starts automatic system suspension.
           *
           * @return true on success, false otherwise.
           */
      @Override public boolean enableAutosuspend() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_enableAutosuspend, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().enableAutosuspend();
            }
          }
          _reply.readException();
          _result = (0!=_reply.readInt());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      /**
           * Suspends the system even if there are wakelocks being held.
           */
      @Override public boolean forceSuspend() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_forceSuspend, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().forceSuspend();
            }
          }
          _reply.readException();
          _result = (0!=_reply.readInt());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      /**
           * Returns a list of wake lock stats.
           */
      @Override public android.system.suspend.internal.WakeLockInfo[] getWakeLockStats() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.system.suspend.internal.WakeLockInfo[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getWakeLockStats, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getWakeLockStats();
            }
          }
          _reply.readException();
          _result = _reply.createTypedArray(android.system.suspend.internal.WakeLockInfo.CREATOR);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      /**
           * Returns a list of wakeup stats.
           */
      @Override public android.system.suspend.internal.WakeupInfo[] getWakeupStats() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.system.suspend.internal.WakeupInfo[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getWakeupStats, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getWakeupStats();
            }
          }
          _reply.readException();
          _result = _reply.createTypedArray(android.system.suspend.internal.WakeupInfo.CREATOR);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      /**
           * Returns stats related to suspend.
           */
      @Override public android.system.suspend.internal.SuspendInfo getSuspendStats() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.system.suspend.internal.SuspendInfo _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getSuspendStats, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getSuspendStats();
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.system.suspend.internal.SuspendInfo.CREATOR.createFromParcel(_reply);
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
      public static android.system.suspend.internal.ISuspendControlServiceInternal sDefaultImpl;
    }
    static final int TRANSACTION_enableAutosuspend = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_forceSuspend = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_getWakeLockStats = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_getWakeupStats = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_getSuspendStats = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    public static boolean setDefaultImpl(android.system.suspend.internal.ISuspendControlServiceInternal impl) {
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
    public static android.system.suspend.internal.ISuspendControlServiceInternal getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$system$suspend$internal$ISuspendControlServiceInternal".replace('$', '.');
  /**
       * Starts automatic system suspension.
       *
       * @return true on success, false otherwise.
       */
  public boolean enableAutosuspend() throws android.os.RemoteException;
  /**
       * Suspends the system even if there are wakelocks being held.
       */
  public boolean forceSuspend() throws android.os.RemoteException;
  /**
       * Returns a list of wake lock stats.
       */
  public android.system.suspend.internal.WakeLockInfo[] getWakeLockStats() throws android.os.RemoteException;
  /**
       * Returns a list of wakeup stats.
       */
  public android.system.suspend.internal.WakeupInfo[] getWakeupStats() throws android.os.RemoteException;
  /**
       * Returns stats related to suspend.
       */
  public android.system.suspend.internal.SuspendInfo getSuspendStats() throws android.os.RemoteException;
}
