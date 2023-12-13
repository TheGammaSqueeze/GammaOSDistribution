/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.security.metrics;
/**
 * IKeystoreMetrics interface exposes the method for system server to pull metrics from keystore.
 * @hide
 */
public interface IKeystoreMetrics extends android.os.IInterface
{
  /** Default implementation for IKeystoreMetrics. */
  public static class Default implements android.security.metrics.IKeystoreMetrics
  {
    /**
         * Allows the metrics routing proxy to pull the metrics from keystore.
         *
         * @return an array of KeystoreAtom objects with the atomID. There can be multiple atom objects
         * for the same atomID, encapsulating different combinations of values for the atom fields.
         * If there is no atom object found for the atomID in the metrics store, an empty array is
         * returned.
         *
         * Callers require 'PullMetrics' permission.
         *
         * @param atomID - ID of the atom to be pulled.
         *
         * Errors are reported as service specific errors.
         */
    @Override public android.security.metrics.KeystoreAtom[] pullMetrics(int atomID) throws android.os.RemoteException
    {
      return null;
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements android.security.metrics.IKeystoreMetrics
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.security.metrics.IKeystoreMetrics interface,
     * generating a proxy if needed.
     */
    public static android.security.metrics.IKeystoreMetrics asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.security.metrics.IKeystoreMetrics))) {
        return ((android.security.metrics.IKeystoreMetrics)iin);
      }
      return new android.security.metrics.IKeystoreMetrics.Stub.Proxy(obj);
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
        case TRANSACTION_pullMetrics:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.security.metrics.KeystoreAtom[] _result = this.pullMetrics(_arg0);
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
    private static class Proxy implements android.security.metrics.IKeystoreMetrics
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
           * Allows the metrics routing proxy to pull the metrics from keystore.
           *
           * @return an array of KeystoreAtom objects with the atomID. There can be multiple atom objects
           * for the same atomID, encapsulating different combinations of values for the atom fields.
           * If there is no atom object found for the atomID in the metrics store, an empty array is
           * returned.
           *
           * Callers require 'PullMetrics' permission.
           *
           * @param atomID - ID of the atom to be pulled.
           *
           * Errors are reported as service specific errors.
           */
      @Override public android.security.metrics.KeystoreAtom[] pullMetrics(int atomID) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.security.metrics.KeystoreAtom[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(atomID);
          boolean _status = mRemote.transact(Stub.TRANSACTION_pullMetrics, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().pullMetrics(atomID);
            }
          }
          _reply.readException();
          _result = _reply.createTypedArray(android.security.metrics.KeystoreAtom.CREATOR);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      public static android.security.metrics.IKeystoreMetrics sDefaultImpl;
    }
    static final int TRANSACTION_pullMetrics = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    public static boolean setDefaultImpl(android.security.metrics.IKeystoreMetrics impl) {
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
    public static android.security.metrics.IKeystoreMetrics getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$security$metrics$IKeystoreMetrics".replace('$', '.');
  /**
       * Allows the metrics routing proxy to pull the metrics from keystore.
       *
       * @return an array of KeystoreAtom objects with the atomID. There can be multiple atom objects
       * for the same atomID, encapsulating different combinations of values for the atom fields.
       * If there is no atom object found for the atomID in the metrics store, an empty array is
       * returned.
       *
       * Callers require 'PullMetrics' permission.
       *
       * @param atomID - ID of the atom to be pulled.
       *
       * Errors are reported as service specific errors.
       */
  public android.security.metrics.KeystoreAtom[] pullMetrics(int atomID) throws android.os.RemoteException;
}
