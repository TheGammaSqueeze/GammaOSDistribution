/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.permission;
/**
 * Interface to communicate directly with the permission checker service.
 */
public interface IPermissionChecker extends android.os.IInterface
{
  /** Default implementation for IPermissionChecker. */
  public static class Default implements android.permission.IPermissionChecker
  {
    @Override public int checkPermission(java.lang.String permission, android.content.AttributionSourceState attributionSource, java.lang.String message, boolean forDataDelivery, boolean startDataDelivery, boolean fromDatasource, int attributedOp) throws android.os.RemoteException
    {
      return 0;
    }
    @Override public void finishDataDelivery(int op, android.content.AttributionSourceState attributionSource, boolean fromDatasource) throws android.os.RemoteException
    {
    }
    @Override public int checkOp(int op, android.content.AttributionSourceState attributionSource, java.lang.String message, boolean forDataDelivery, boolean startDataDelivery) throws android.os.RemoteException
    {
      return 0;
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements android.permission.IPermissionChecker
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.permission.IPermissionChecker interface,
     * generating a proxy if needed.
     */
    public static android.permission.IPermissionChecker asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.permission.IPermissionChecker))) {
        return ((android.permission.IPermissionChecker)iin);
      }
      return new android.permission.IPermissionChecker.Stub.Proxy(obj);
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
        case TRANSACTION_checkPermission:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          android.content.AttributionSourceState _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.content.AttributionSourceState.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          java.lang.String _arg2;
          _arg2 = data.readString();
          boolean _arg3;
          _arg3 = (0!=data.readInt());
          boolean _arg4;
          _arg4 = (0!=data.readInt());
          boolean _arg5;
          _arg5 = (0!=data.readInt());
          int _arg6;
          _arg6 = data.readInt();
          int _result = this.checkPermission(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6);
          reply.writeNoException();
          reply.writeInt(_result);
          return true;
        }
        case TRANSACTION_finishDataDelivery:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.content.AttributionSourceState _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.content.AttributionSourceState.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          boolean _arg2;
          _arg2 = (0!=data.readInt());
          this.finishDataDelivery(_arg0, _arg1, _arg2);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_checkOp:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.content.AttributionSourceState _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.content.AttributionSourceState.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          java.lang.String _arg2;
          _arg2 = data.readString();
          boolean _arg3;
          _arg3 = (0!=data.readInt());
          boolean _arg4;
          _arg4 = (0!=data.readInt());
          int _result = this.checkOp(_arg0, _arg1, _arg2, _arg3, _arg4);
          reply.writeNoException();
          reply.writeInt(_result);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.permission.IPermissionChecker
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
      @Override public int checkPermission(java.lang.String permission, android.content.AttributionSourceState attributionSource, java.lang.String message, boolean forDataDelivery, boolean startDataDelivery, boolean fromDatasource, int attributedOp) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(permission);
          if ((attributionSource!=null)) {
            _data.writeInt(1);
            attributionSource.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeString(message);
          _data.writeInt(((forDataDelivery)?(1):(0)));
          _data.writeInt(((startDataDelivery)?(1):(0)));
          _data.writeInt(((fromDatasource)?(1):(0)));
          _data.writeInt(attributedOp);
          boolean _status = mRemote.transact(Stub.TRANSACTION_checkPermission, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().checkPermission(permission, attributionSource, message, forDataDelivery, startDataDelivery, fromDatasource, attributedOp);
            }
          }
          _reply.readException();
          _result = _reply.readInt();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void finishDataDelivery(int op, android.content.AttributionSourceState attributionSource, boolean fromDatasource) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(op);
          if ((attributionSource!=null)) {
            _data.writeInt(1);
            attributionSource.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeInt(((fromDatasource)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_finishDataDelivery, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().finishDataDelivery(op, attributionSource, fromDatasource);
              return;
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public int checkOp(int op, android.content.AttributionSourceState attributionSource, java.lang.String message, boolean forDataDelivery, boolean startDataDelivery) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(op);
          if ((attributionSource!=null)) {
            _data.writeInt(1);
            attributionSource.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeString(message);
          _data.writeInt(((forDataDelivery)?(1):(0)));
          _data.writeInt(((startDataDelivery)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_checkOp, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().checkOp(op, attributionSource, message, forDataDelivery, startDataDelivery);
            }
          }
          _reply.readException();
          _result = _reply.readInt();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      public static android.permission.IPermissionChecker sDefaultImpl;
    }
    static final int TRANSACTION_checkPermission = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_finishDataDelivery = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_checkOp = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    public static boolean setDefaultImpl(android.permission.IPermissionChecker impl) {
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
    public static android.permission.IPermissionChecker getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$permission$IPermissionChecker".replace('$', '.');
  public static final int PERMISSION_GRANTED = 0;
  public static final int PERMISSION_SOFT_DENIED = 1;
  public static final int PERMISSION_HARD_DENIED = 2;
  public int checkPermission(java.lang.String permission, android.content.AttributionSourceState attributionSource, java.lang.String message, boolean forDataDelivery, boolean startDataDelivery, boolean fromDatasource, int attributedOp) throws android.os.RemoteException;
  public void finishDataDelivery(int op, android.content.AttributionSourceState attributionSource, boolean fromDatasource) throws android.os.RemoteException;
  public int checkOp(int op, android.content.AttributionSourceState attributionSource, java.lang.String message, boolean forDataDelivery, boolean startDataDelivery) throws android.os.RemoteException;
}
