/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.security.apc;
/** @hide */
public interface IProtectedConfirmation extends android.os.IInterface
{
  /** Default implementation for IProtectedConfirmation. */
  public static class Default implements android.security.apc.IProtectedConfirmation
  {
    /**
         * Present the confirmation prompt. The caller must implement IConfirmationCallback and pass
         * it to this function as listener.
         *
         * @param listener Must implement IConfirmationCallback. Doubles as session identifier when
         *           passed to cancelPrompt.
         * @param promptText The text that will be displayed to the user using the protected
         *           confirmation UI.
         * @param extraData Extra data, e.g., a nonce, that will be included in the to-be-signed
         *           message.
         * @param locale The locale string is used to select the language for the instructions
         *           displayed by the confirmation prompt.
         * @param uiOptionFlags Bitwise combination of FLAG_UI_OPTION_* see above.
         *
         * Service specific error codes:
         *  - ResponseCode.OPERATION_PENDING If another prompt is already pending.
         *  - ResponseCode.SYSTEM_ERROR An unexpected error occurred.
         */
    @Override public void presentPrompt(android.security.apc.IConfirmationCallback listener, java.lang.String promptText, byte[] extraData, java.lang.String locale, int uiOptionFlags) throws android.os.RemoteException
    {
    }
    /**
         * Cancel an ongoing prompt.
         *
         * @param listener Must implement IConfirmationCallback, although in this context this binder
         *            token is only used to identify the session that is to be cancelled.
         *
         * Service specific error code:
         *  - ResponseCode.IGNORED If the listener does not represent an ongoing prompt session.
         */
    @Override public void cancelPrompt(android.security.apc.IConfirmationCallback listener) throws android.os.RemoteException
    {
    }
    /**
         * Returns true if the device supports Android Protected Confirmation.
         */
    @Override public boolean isSupported() throws android.os.RemoteException
    {
      return false;
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements android.security.apc.IProtectedConfirmation
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.security.apc.IProtectedConfirmation interface,
     * generating a proxy if needed.
     */
    public static android.security.apc.IProtectedConfirmation asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.security.apc.IProtectedConfirmation))) {
        return ((android.security.apc.IProtectedConfirmation)iin);
      }
      return new android.security.apc.IProtectedConfirmation.Stub.Proxy(obj);
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
        case TRANSACTION_presentPrompt:
        {
          data.enforceInterface(descriptor);
          android.security.apc.IConfirmationCallback _arg0;
          _arg0 = android.security.apc.IConfirmationCallback.Stub.asInterface(data.readStrongBinder());
          java.lang.String _arg1;
          _arg1 = data.readString();
          byte[] _arg2;
          _arg2 = data.createByteArray();
          java.lang.String _arg3;
          _arg3 = data.readString();
          int _arg4;
          _arg4 = data.readInt();
          this.presentPrompt(_arg0, _arg1, _arg2, _arg3, _arg4);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_cancelPrompt:
        {
          data.enforceInterface(descriptor);
          android.security.apc.IConfirmationCallback _arg0;
          _arg0 = android.security.apc.IConfirmationCallback.Stub.asInterface(data.readStrongBinder());
          this.cancelPrompt(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_isSupported:
        {
          data.enforceInterface(descriptor);
          boolean _result = this.isSupported();
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.security.apc.IProtectedConfirmation
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
           * Present the confirmation prompt. The caller must implement IConfirmationCallback and pass
           * it to this function as listener.
           *
           * @param listener Must implement IConfirmationCallback. Doubles as session identifier when
           *           passed to cancelPrompt.
           * @param promptText The text that will be displayed to the user using the protected
           *           confirmation UI.
           * @param extraData Extra data, e.g., a nonce, that will be included in the to-be-signed
           *           message.
           * @param locale The locale string is used to select the language for the instructions
           *           displayed by the confirmation prompt.
           * @param uiOptionFlags Bitwise combination of FLAG_UI_OPTION_* see above.
           *
           * Service specific error codes:
           *  - ResponseCode.OPERATION_PENDING If another prompt is already pending.
           *  - ResponseCode.SYSTEM_ERROR An unexpected error occurred.
           */
      @Override public void presentPrompt(android.security.apc.IConfirmationCallback listener, java.lang.String promptText, byte[] extraData, java.lang.String locale, int uiOptionFlags) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((listener!=null))?(listener.asBinder()):(null)));
          _data.writeString(promptText);
          _data.writeByteArray(extraData);
          _data.writeString(locale);
          _data.writeInt(uiOptionFlags);
          boolean _status = mRemote.transact(Stub.TRANSACTION_presentPrompt, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().presentPrompt(listener, promptText, extraData, locale, uiOptionFlags);
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
      /**
           * Cancel an ongoing prompt.
           *
           * @param listener Must implement IConfirmationCallback, although in this context this binder
           *            token is only used to identify the session that is to be cancelled.
           *
           * Service specific error code:
           *  - ResponseCode.IGNORED If the listener does not represent an ongoing prompt session.
           */
      @Override public void cancelPrompt(android.security.apc.IConfirmationCallback listener) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((listener!=null))?(listener.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_cancelPrompt, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().cancelPrompt(listener);
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
      /**
           * Returns true if the device supports Android Protected Confirmation.
           */
      @Override public boolean isSupported() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_isSupported, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().isSupported();
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
      public static android.security.apc.IProtectedConfirmation sDefaultImpl;
    }
    static final int TRANSACTION_presentPrompt = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_cancelPrompt = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_isSupported = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    public static boolean setDefaultImpl(android.security.apc.IProtectedConfirmation impl) {
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
    public static android.security.apc.IProtectedConfirmation getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$security$apc$IProtectedConfirmation".replace('$', '.');
  /**
       * When set in the uiOptionFlags parameter of presentPrompt, indicates to the implementation
       * that it shall use inverted color mode.
       */
  public static final int FLAG_UI_OPTION_INVERTED = 1;
  /**
       * When set in the uiOptionFlags parameter of presentPrompt, indicates to the implementation
       * that it shall use magnified font mode.
       */
  public static final int FLAG_UI_OPTION_MAGNIFIED = 2;
  /**
       * Present the confirmation prompt. The caller must implement IConfirmationCallback and pass
       * it to this function as listener.
       *
       * @param listener Must implement IConfirmationCallback. Doubles as session identifier when
       *           passed to cancelPrompt.
       * @param promptText The text that will be displayed to the user using the protected
       *           confirmation UI.
       * @param extraData Extra data, e.g., a nonce, that will be included in the to-be-signed
       *           message.
       * @param locale The locale string is used to select the language for the instructions
       *           displayed by the confirmation prompt.
       * @param uiOptionFlags Bitwise combination of FLAG_UI_OPTION_* see above.
       *
       * Service specific error codes:
       *  - ResponseCode.OPERATION_PENDING If another prompt is already pending.
       *  - ResponseCode.SYSTEM_ERROR An unexpected error occurred.
       */
  public void presentPrompt(android.security.apc.IConfirmationCallback listener, java.lang.String promptText, byte[] extraData, java.lang.String locale, int uiOptionFlags) throws android.os.RemoteException;
  /**
       * Cancel an ongoing prompt.
       *
       * @param listener Must implement IConfirmationCallback, although in this context this binder
       *            token is only used to identify the session that is to be cancelled.
       *
       * Service specific error code:
       *  - ResponseCode.IGNORED If the listener does not represent an ongoing prompt session.
       */
  public void cancelPrompt(android.security.apc.IConfirmationCallback listener) throws android.os.RemoteException;
  /**
       * Returns true if the device supports Android Protected Confirmation.
       */
  public boolean isSupported() throws android.os.RemoteException;
}
