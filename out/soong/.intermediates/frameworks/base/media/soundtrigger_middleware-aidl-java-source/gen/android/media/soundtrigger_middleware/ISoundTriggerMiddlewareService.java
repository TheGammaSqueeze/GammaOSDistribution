/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * Main entry point into this module.
 *
 * Allows the client to enumerate the available soundtrigger devices and their capabilities, then
 * attach to either one of them in order to use it.
 *
 * {@hide}
 */
public interface ISoundTriggerMiddlewareService extends android.os.IInterface
{
  /** Default implementation for ISoundTriggerMiddlewareService. */
  public static class Default implements android.media.soundtrigger_middleware.ISoundTriggerMiddlewareService
  {
    /**
         * Query the available modules and their capabilities.
         *
         * This variant is intended for use by the originator of the operations for permission
         * enforcement purposes. The provided identity's uid/pid fields will be ignored and overridden
         * by the ones provided by Binder.getCallingUid() / Binder.getCallingPid().
         */
    @Override public android.media.soundtrigger_middleware.SoundTriggerModuleDescriptor[] listModulesAsOriginator(android.media.permission.Identity identity) throws android.os.RemoteException
    {
      return null;
    }
    /**
         * Query the available modules and their capabilities.
         *
         * This variant is intended for use by a trusted "middleman", acting on behalf of some identity
         * other than itself. The caller must provide:
         * - Its own identity, which will be used to establish trust via the
         *   SOUNDTRIGGER_DELEGATE_IDENTITY permission. This identity's uid/pid fields will be ignored
         *   and overridden by the ones provided by Binder.getCallingUid() / Binder.getCallingPid().
         *   This implies that the caller must clear its caller identity to protect from the case where
         *   it resides in the same process as the callee.
         * - The identity of the entity on behalf of which module operations are to be performed.
         */
    @Override public android.media.soundtrigger_middleware.SoundTriggerModuleDescriptor[] listModulesAsMiddleman(android.media.permission.Identity middlemanIdentity, android.media.permission.Identity originatorIdentity) throws android.os.RemoteException
    {
      return null;
    }
    /**
         * Attach to one of the available modules.
         *
         * This variant is intended for use by the originator of the operations for permission
         * enforcement purposes. The provided identity's uid/pid fields will be ignored and overridden
         * by the ones provided by Binder.getCallingUid() / Binder.getCallingPid().
         *
         * listModules() must be called prior to calling this method and the provided handle must be
         * one of the handles from the returned list.
         */
    @Override public android.media.soundtrigger_middleware.ISoundTriggerModule attachAsOriginator(int handle, android.media.permission.Identity identity, android.media.soundtrigger_middleware.ISoundTriggerCallback callback) throws android.os.RemoteException
    {
      return null;
    }
    /**
         * Attach to one of the available modules.
         *
         * This variant is intended for use by a trusted "middleman", acting on behalf of some identity
         * other than itself. The caller must provide:
         * - Its own identity, which will be used to establish trust via the
         *   SOUNDTRIGGER_DELEGATE_IDENTITY permission. This identity's uid/pid fields will be ignored
         *   and overridden by the ones provided by Binder.getCallingUid() / Binder.getCallingPid().
         *   This implies that the caller must clear its caller identity to protect from the case where
         *   it resides in the same process as the callee.
         * - The identity of the entity on behalf of which module operations are to be performed.
         *
         * listModules() must be called prior to calling this method and the provided handle must be
         * one of the handles from the returned list.
         */
    @Override public android.media.soundtrigger_middleware.ISoundTriggerModule attachAsMiddleman(int handle, android.media.permission.Identity middlemanIdentity, android.media.permission.Identity originatorIdentity, android.media.soundtrigger_middleware.ISoundTriggerCallback callback) throws android.os.RemoteException
    {
      return null;
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements android.media.soundtrigger_middleware.ISoundTriggerMiddlewareService
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.media.soundtrigger_middleware.ISoundTriggerMiddlewareService interface,
     * generating a proxy if needed.
     */
    public static android.media.soundtrigger_middleware.ISoundTriggerMiddlewareService asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.media.soundtrigger_middleware.ISoundTriggerMiddlewareService))) {
        return ((android.media.soundtrigger_middleware.ISoundTriggerMiddlewareService)iin);
      }
      return new android.media.soundtrigger_middleware.ISoundTriggerMiddlewareService.Stub.Proxy(obj);
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
        case TRANSACTION_listModulesAsOriginator:
        {
          data.enforceInterface(descriptor);
          android.media.permission.Identity _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.media.permission.Identity.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          android.media.soundtrigger_middleware.SoundTriggerModuleDescriptor[] _result = this.listModulesAsOriginator(_arg0);
          reply.writeNoException();
          reply.writeTypedArray(_result, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          return true;
        }
        case TRANSACTION_listModulesAsMiddleman:
        {
          data.enforceInterface(descriptor);
          android.media.permission.Identity _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.media.permission.Identity.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          android.media.permission.Identity _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.media.permission.Identity.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          android.media.soundtrigger_middleware.SoundTriggerModuleDescriptor[] _result = this.listModulesAsMiddleman(_arg0, _arg1);
          reply.writeNoException();
          reply.writeTypedArray(_result, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          return true;
        }
        case TRANSACTION_attachAsOriginator:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.media.permission.Identity _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.media.permission.Identity.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          android.media.soundtrigger_middleware.ISoundTriggerCallback _arg2;
          _arg2 = android.media.soundtrigger_middleware.ISoundTriggerCallback.Stub.asInterface(data.readStrongBinder());
          android.media.soundtrigger_middleware.ISoundTriggerModule _result = this.attachAsOriginator(_arg0, _arg1, _arg2);
          reply.writeNoException();
          reply.writeStrongBinder((((_result!=null))?(_result.asBinder()):(null)));
          return true;
        }
        case TRANSACTION_attachAsMiddleman:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.media.permission.Identity _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.media.permission.Identity.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          android.media.permission.Identity _arg2;
          if ((0!=data.readInt())) {
            _arg2 = android.media.permission.Identity.CREATOR.createFromParcel(data);
          }
          else {
            _arg2 = null;
          }
          android.media.soundtrigger_middleware.ISoundTriggerCallback _arg3;
          _arg3 = android.media.soundtrigger_middleware.ISoundTriggerCallback.Stub.asInterface(data.readStrongBinder());
          android.media.soundtrigger_middleware.ISoundTriggerModule _result = this.attachAsMiddleman(_arg0, _arg1, _arg2, _arg3);
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
    private static class Proxy implements android.media.soundtrigger_middleware.ISoundTriggerMiddlewareService
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
           * Query the available modules and their capabilities.
           *
           * This variant is intended for use by the originator of the operations for permission
           * enforcement purposes. The provided identity's uid/pid fields will be ignored and overridden
           * by the ones provided by Binder.getCallingUid() / Binder.getCallingPid().
           */
      @Override public android.media.soundtrigger_middleware.SoundTriggerModuleDescriptor[] listModulesAsOriginator(android.media.permission.Identity identity) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.media.soundtrigger_middleware.SoundTriggerModuleDescriptor[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((identity!=null)) {
            _data.writeInt(1);
            identity.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_listModulesAsOriginator, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().listModulesAsOriginator(identity);
            }
          }
          _reply.readException();
          _result = _reply.createTypedArray(android.media.soundtrigger_middleware.SoundTriggerModuleDescriptor.CREATOR);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      /**
           * Query the available modules and their capabilities.
           *
           * This variant is intended for use by a trusted "middleman", acting on behalf of some identity
           * other than itself. The caller must provide:
           * - Its own identity, which will be used to establish trust via the
           *   SOUNDTRIGGER_DELEGATE_IDENTITY permission. This identity's uid/pid fields will be ignored
           *   and overridden by the ones provided by Binder.getCallingUid() / Binder.getCallingPid().
           *   This implies that the caller must clear its caller identity to protect from the case where
           *   it resides in the same process as the callee.
           * - The identity of the entity on behalf of which module operations are to be performed.
           */
      @Override public android.media.soundtrigger_middleware.SoundTriggerModuleDescriptor[] listModulesAsMiddleman(android.media.permission.Identity middlemanIdentity, android.media.permission.Identity originatorIdentity) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.media.soundtrigger_middleware.SoundTriggerModuleDescriptor[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((middlemanIdentity!=null)) {
            _data.writeInt(1);
            middlemanIdentity.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          if ((originatorIdentity!=null)) {
            _data.writeInt(1);
            originatorIdentity.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_listModulesAsMiddleman, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().listModulesAsMiddleman(middlemanIdentity, originatorIdentity);
            }
          }
          _reply.readException();
          _result = _reply.createTypedArray(android.media.soundtrigger_middleware.SoundTriggerModuleDescriptor.CREATOR);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      /**
           * Attach to one of the available modules.
           *
           * This variant is intended for use by the originator of the operations for permission
           * enforcement purposes. The provided identity's uid/pid fields will be ignored and overridden
           * by the ones provided by Binder.getCallingUid() / Binder.getCallingPid().
           *
           * listModules() must be called prior to calling this method and the provided handle must be
           * one of the handles from the returned list.
           */
      @Override public android.media.soundtrigger_middleware.ISoundTriggerModule attachAsOriginator(int handle, android.media.permission.Identity identity, android.media.soundtrigger_middleware.ISoundTriggerCallback callback) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.media.soundtrigger_middleware.ISoundTriggerModule _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(handle);
          if ((identity!=null)) {
            _data.writeInt(1);
            identity.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeStrongBinder((((callback!=null))?(callback.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_attachAsOriginator, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().attachAsOriginator(handle, identity, callback);
            }
          }
          _reply.readException();
          _result = android.media.soundtrigger_middleware.ISoundTriggerModule.Stub.asInterface(_reply.readStrongBinder());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      /**
           * Attach to one of the available modules.
           *
           * This variant is intended for use by a trusted "middleman", acting on behalf of some identity
           * other than itself. The caller must provide:
           * - Its own identity, which will be used to establish trust via the
           *   SOUNDTRIGGER_DELEGATE_IDENTITY permission. This identity's uid/pid fields will be ignored
           *   and overridden by the ones provided by Binder.getCallingUid() / Binder.getCallingPid().
           *   This implies that the caller must clear its caller identity to protect from the case where
           *   it resides in the same process as the callee.
           * - The identity of the entity on behalf of which module operations are to be performed.
           *
           * listModules() must be called prior to calling this method and the provided handle must be
           * one of the handles from the returned list.
           */
      @Override public android.media.soundtrigger_middleware.ISoundTriggerModule attachAsMiddleman(int handle, android.media.permission.Identity middlemanIdentity, android.media.permission.Identity originatorIdentity, android.media.soundtrigger_middleware.ISoundTriggerCallback callback) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.media.soundtrigger_middleware.ISoundTriggerModule _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(handle);
          if ((middlemanIdentity!=null)) {
            _data.writeInt(1);
            middlemanIdentity.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          if ((originatorIdentity!=null)) {
            _data.writeInt(1);
            originatorIdentity.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          _data.writeStrongBinder((((callback!=null))?(callback.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_attachAsMiddleman, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().attachAsMiddleman(handle, middlemanIdentity, originatorIdentity, callback);
            }
          }
          _reply.readException();
          _result = android.media.soundtrigger_middleware.ISoundTriggerModule.Stub.asInterface(_reply.readStrongBinder());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      public static android.media.soundtrigger_middleware.ISoundTriggerMiddlewareService sDefaultImpl;
    }
    static final int TRANSACTION_listModulesAsOriginator = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_listModulesAsMiddleman = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_attachAsOriginator = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_attachAsMiddleman = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    public static boolean setDefaultImpl(android.media.soundtrigger_middleware.ISoundTriggerMiddlewareService impl) {
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
    public static android.media.soundtrigger_middleware.ISoundTriggerMiddlewareService getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$media$soundtrigger_middleware$ISoundTriggerMiddlewareService".replace('$', '.');
  /**
       * Query the available modules and their capabilities.
       *
       * This variant is intended for use by the originator of the operations for permission
       * enforcement purposes. The provided identity's uid/pid fields will be ignored and overridden
       * by the ones provided by Binder.getCallingUid() / Binder.getCallingPid().
       */
  public android.media.soundtrigger_middleware.SoundTriggerModuleDescriptor[] listModulesAsOriginator(android.media.permission.Identity identity) throws android.os.RemoteException;
  /**
       * Query the available modules and their capabilities.
       *
       * This variant is intended for use by a trusted "middleman", acting on behalf of some identity
       * other than itself. The caller must provide:
       * - Its own identity, which will be used to establish trust via the
       *   SOUNDTRIGGER_DELEGATE_IDENTITY permission. This identity's uid/pid fields will be ignored
       *   and overridden by the ones provided by Binder.getCallingUid() / Binder.getCallingPid().
       *   This implies that the caller must clear its caller identity to protect from the case where
       *   it resides in the same process as the callee.
       * - The identity of the entity on behalf of which module operations are to be performed.
       */
  public android.media.soundtrigger_middleware.SoundTriggerModuleDescriptor[] listModulesAsMiddleman(android.media.permission.Identity middlemanIdentity, android.media.permission.Identity originatorIdentity) throws android.os.RemoteException;
  /**
       * Attach to one of the available modules.
       *
       * This variant is intended for use by the originator of the operations for permission
       * enforcement purposes. The provided identity's uid/pid fields will be ignored and overridden
       * by the ones provided by Binder.getCallingUid() / Binder.getCallingPid().
       *
       * listModules() must be called prior to calling this method and the provided handle must be
       * one of the handles from the returned list.
       */
  public android.media.soundtrigger_middleware.ISoundTriggerModule attachAsOriginator(int handle, android.media.permission.Identity identity, android.media.soundtrigger_middleware.ISoundTriggerCallback callback) throws android.os.RemoteException;
  /**
       * Attach to one of the available modules.
       *
       * This variant is intended for use by a trusted "middleman", acting on behalf of some identity
       * other than itself. The caller must provide:
       * - Its own identity, which will be used to establish trust via the
       *   SOUNDTRIGGER_DELEGATE_IDENTITY permission. This identity's uid/pid fields will be ignored
       *   and overridden by the ones provided by Binder.getCallingUid() / Binder.getCallingPid().
       *   This implies that the caller must clear its caller identity to protect from the case where
       *   it resides in the same process as the callee.
       * - The identity of the entity on behalf of which module operations are to be performed.
       *
       * listModules() must be called prior to calling this method and the provided handle must be
       * one of the handles from the returned list.
       */
  public android.media.soundtrigger_middleware.ISoundTriggerModule attachAsMiddleman(int handle, android.media.permission.Identity middlemanIdentity, android.media.permission.Identity originatorIdentity, android.media.soundtrigger_middleware.ISoundTriggerCallback callback) throws android.os.RemoteException;
}
