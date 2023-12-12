/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.hardware.gnss;
public interface IGnss extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 1;
  public static final String HASH = "10839720b90aaec329521e810d9e0501cfcef0d3";
  /** Default implementation for IGnss. */
  public static class Default implements android.hardware.gnss.IGnss
  {
    @Override public void setCallback(android.hardware.gnss.IGnssCallback callback) throws android.os.RemoteException
    {
    }
    @Override public void close() throws android.os.RemoteException
    {
    }
    @Override public android.hardware.gnss.IGnssPsds getExtensionPsds() throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.hardware.gnss.IGnssConfiguration getExtensionGnssConfiguration() throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.hardware.gnss.IGnssMeasurementInterface getExtensionGnssMeasurement() throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.hardware.gnss.IGnssPowerIndication getExtensionGnssPowerIndication() throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.hardware.gnss.IGnss
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.markVintfStability();
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.hardware.gnss.IGnss interface,
     * generating a proxy if needed.
     */
    public static android.hardware.gnss.IGnss asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.hardware.gnss.IGnss))) {
        return ((android.hardware.gnss.IGnss)iin);
      }
      return new android.hardware.gnss.IGnss.Stub.Proxy(obj);
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
        case TRANSACTION_setCallback:
        {
          data.enforceInterface(descriptor);
          android.hardware.gnss.IGnssCallback _arg0;
          _arg0 = android.hardware.gnss.IGnssCallback.Stub.asInterface(data.readStrongBinder());
          this.setCallback(_arg0);
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
        case TRANSACTION_getExtensionPsds:
        {
          data.enforceInterface(descriptor);
          android.hardware.gnss.IGnssPsds _result = this.getExtensionPsds();
          reply.writeNoException();
          reply.writeStrongBinder((((_result!=null))?(_result.asBinder()):(null)));
          return true;
        }
        case TRANSACTION_getExtensionGnssConfiguration:
        {
          data.enforceInterface(descriptor);
          android.hardware.gnss.IGnssConfiguration _result = this.getExtensionGnssConfiguration();
          reply.writeNoException();
          reply.writeStrongBinder((((_result!=null))?(_result.asBinder()):(null)));
          return true;
        }
        case TRANSACTION_getExtensionGnssMeasurement:
        {
          data.enforceInterface(descriptor);
          android.hardware.gnss.IGnssMeasurementInterface _result = this.getExtensionGnssMeasurement();
          reply.writeNoException();
          reply.writeStrongBinder((((_result!=null))?(_result.asBinder()):(null)));
          return true;
        }
        case TRANSACTION_getExtensionGnssPowerIndication:
        {
          data.enforceInterface(descriptor);
          android.hardware.gnss.IGnssPowerIndication _result = this.getExtensionGnssPowerIndication();
          reply.writeNoException();
          reply.writeStrongBinder((((_result!=null))?(_result.asBinder()):(null)));
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.hardware.gnss.IGnss
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
      @Override public void setCallback(android.hardware.gnss.IGnssCallback callback) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((callback!=null))?(callback.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_setCallback, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setCallback(callback);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setCallback is unimplemented.");
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
      @Override public android.hardware.gnss.IGnssPsds getExtensionPsds() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.gnss.IGnssPsds _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getExtensionPsds, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getExtensionPsds();
            }
            else {
              throw new android.os.RemoteException("Method getExtensionPsds is unimplemented.");
            }
          }
          _reply.readException();
          _result = android.hardware.gnss.IGnssPsds.Stub.asInterface(_reply.readStrongBinder());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public android.hardware.gnss.IGnssConfiguration getExtensionGnssConfiguration() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.gnss.IGnssConfiguration _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getExtensionGnssConfiguration, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getExtensionGnssConfiguration();
            }
            else {
              throw new android.os.RemoteException("Method getExtensionGnssConfiguration is unimplemented.");
            }
          }
          _reply.readException();
          _result = android.hardware.gnss.IGnssConfiguration.Stub.asInterface(_reply.readStrongBinder());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public android.hardware.gnss.IGnssMeasurementInterface getExtensionGnssMeasurement() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.gnss.IGnssMeasurementInterface _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getExtensionGnssMeasurement, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getExtensionGnssMeasurement();
            }
            else {
              throw new android.os.RemoteException("Method getExtensionGnssMeasurement is unimplemented.");
            }
          }
          _reply.readException();
          _result = android.hardware.gnss.IGnssMeasurementInterface.Stub.asInterface(_reply.readStrongBinder());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public android.hardware.gnss.IGnssPowerIndication getExtensionGnssPowerIndication() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.gnss.IGnssPowerIndication _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getExtensionGnssPowerIndication, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getExtensionGnssPowerIndication();
            }
            else {
              throw new android.os.RemoteException("Method getExtensionGnssPowerIndication is unimplemented.");
            }
          }
          _reply.readException();
          _result = android.hardware.gnss.IGnssPowerIndication.Stub.asInterface(_reply.readStrongBinder());
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
      public static android.hardware.gnss.IGnss sDefaultImpl;
    }
    static final int TRANSACTION_setCallback = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_close = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_getExtensionPsds = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_getExtensionGnssConfiguration = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_getExtensionGnssMeasurement = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_getExtensionGnssPowerIndication = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.hardware.gnss.IGnss impl) {
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
    public static android.hardware.gnss.IGnss getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$hardware$gnss$IGnss".replace('$', '.');
  public static final int ERROR_INVALID_ARGUMENT = 1;
  public static final int ERROR_ALREADY_INIT = 2;
  public static final int ERROR_GENERIC = 3;
  public void setCallback(android.hardware.gnss.IGnssCallback callback) throws android.os.RemoteException;
  public void close() throws android.os.RemoteException;
  public android.hardware.gnss.IGnssPsds getExtensionPsds() throws android.os.RemoteException;
  public android.hardware.gnss.IGnssConfiguration getExtensionGnssConfiguration() throws android.os.RemoteException;
  public android.hardware.gnss.IGnssMeasurementInterface getExtensionGnssMeasurement() throws android.os.RemoteException;
  public android.hardware.gnss.IGnssPowerIndication getExtensionGnssPowerIndication() throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
