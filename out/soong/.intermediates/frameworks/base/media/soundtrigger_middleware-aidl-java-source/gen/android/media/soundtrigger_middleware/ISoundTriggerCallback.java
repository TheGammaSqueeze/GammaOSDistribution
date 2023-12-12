/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * Main interface for a client to get notifications of events coming from this module.
 *
 * {@hide}
 */
public interface ISoundTriggerCallback extends android.os.IInterface
{
  /** Default implementation for ISoundTriggerCallback. */
  public static class Default implements android.media.soundtrigger_middleware.ISoundTriggerCallback
  {
    /**
         * Invoked whenever a recognition event is triggered (typically, on recognition, but also in
         * case of external aborting of a recognition or a forced recognition event - see the status
         * code in the event for determining).
         */
    @Override public void onRecognition(int modelHandle, android.media.soundtrigger_middleware.RecognitionEvent event) throws android.os.RemoteException
    {
    }
    /**
          * Invoked whenever a phrase recognition event is triggered (typically, on recognition, but
          * also in case of external aborting of a recognition or a forced recognition event - see the
          * status code in the event for determining).
          */
    @Override public void onPhraseRecognition(int modelHandle, android.media.soundtrigger_middleware.PhraseRecognitionEvent event) throws android.os.RemoteException
    {
    }
    /**
         * Notifies the client the recognition has become available after previously having been
         * unavailable, or vice versa. This method will always be invoked once immediately after
         * attachment, and then every time there is a change in availability.
         * When availability changes from available to unavailable, all active recognitions are aborted,
         * and this event will be sent in addition to the abort event.
         */
    @Override public void onRecognitionAvailabilityChange(boolean available) throws android.os.RemoteException
    {
    }
    /**
         * Notifies the client that the associated module has crashed and restarted. The module instance
         * is no longer usable and will throw a ServiceSpecificException with a Status.DEAD_OBJECT code
         * for every call. The client should detach, then re-attach to the module in order to get a new,
         * usable instance. All state for this module has been lost.
         */
    @Override public void onModuleDied() throws android.os.RemoteException
    {
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements android.media.soundtrigger_middleware.ISoundTriggerCallback
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.media.soundtrigger_middleware.ISoundTriggerCallback interface,
     * generating a proxy if needed.
     */
    public static android.media.soundtrigger_middleware.ISoundTriggerCallback asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.media.soundtrigger_middleware.ISoundTriggerCallback))) {
        return ((android.media.soundtrigger_middleware.ISoundTriggerCallback)iin);
      }
      return new android.media.soundtrigger_middleware.ISoundTriggerCallback.Stub.Proxy(obj);
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
        case TRANSACTION_onRecognition:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.media.soundtrigger_middleware.RecognitionEvent _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.media.soundtrigger_middleware.RecognitionEvent.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          this.onRecognition(_arg0, _arg1);
          return true;
        }
        case TRANSACTION_onPhraseRecognition:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.media.soundtrigger_middleware.PhraseRecognitionEvent _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.media.soundtrigger_middleware.PhraseRecognitionEvent.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          this.onPhraseRecognition(_arg0, _arg1);
          return true;
        }
        case TRANSACTION_onRecognitionAvailabilityChange:
        {
          data.enforceInterface(descriptor);
          boolean _arg0;
          _arg0 = (0!=data.readInt());
          this.onRecognitionAvailabilityChange(_arg0);
          return true;
        }
        case TRANSACTION_onModuleDied:
        {
          data.enforceInterface(descriptor);
          this.onModuleDied();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.media.soundtrigger_middleware.ISoundTriggerCallback
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
           * Invoked whenever a recognition event is triggered (typically, on recognition, but also in
           * case of external aborting of a recognition or a forced recognition event - see the status
           * code in the event for determining).
           */
      @Override public void onRecognition(int modelHandle, android.media.soundtrigger_middleware.RecognitionEvent event) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(modelHandle);
          if ((event!=null)) {
            _data.writeInt(1);
            event.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_onRecognition, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onRecognition(modelHandle, event);
              return;
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      /**
            * Invoked whenever a phrase recognition event is triggered (typically, on recognition, but
            * also in case of external aborting of a recognition or a forced recognition event - see the
            * status code in the event for determining).
            */
      @Override public void onPhraseRecognition(int modelHandle, android.media.soundtrigger_middleware.PhraseRecognitionEvent event) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(modelHandle);
          if ((event!=null)) {
            _data.writeInt(1);
            event.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_onPhraseRecognition, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onPhraseRecognition(modelHandle, event);
              return;
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      /**
           * Notifies the client the recognition has become available after previously having been
           * unavailable, or vice versa. This method will always be invoked once immediately after
           * attachment, and then every time there is a change in availability.
           * When availability changes from available to unavailable, all active recognitions are aborted,
           * and this event will be sent in addition to the abort event.
           */
      @Override public void onRecognitionAvailabilityChange(boolean available) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(((available)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_onRecognitionAvailabilityChange, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onRecognitionAvailabilityChange(available);
              return;
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      /**
           * Notifies the client that the associated module has crashed and restarted. The module instance
           * is no longer usable and will throw a ServiceSpecificException with a Status.DEAD_OBJECT code
           * for every call. The client should detach, then re-attach to the module in order to get a new,
           * usable instance. All state for this module has been lost.
           */
      @Override public void onModuleDied() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onModuleDied, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onModuleDied();
              return;
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      public static android.media.soundtrigger_middleware.ISoundTriggerCallback sDefaultImpl;
    }
    static final int TRANSACTION_onRecognition = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_onPhraseRecognition = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_onRecognitionAvailabilityChange = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_onModuleDied = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    public static boolean setDefaultImpl(android.media.soundtrigger_middleware.ISoundTriggerCallback impl) {
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
    public static android.media.soundtrigger_middleware.ISoundTriggerCallback getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$media$soundtrigger_middleware$ISoundTriggerCallback".replace('$', '.');
  /**
       * Invoked whenever a recognition event is triggered (typically, on recognition, but also in
       * case of external aborting of a recognition or a forced recognition event - see the status
       * code in the event for determining).
       */
  public void onRecognition(int modelHandle, android.media.soundtrigger_middleware.RecognitionEvent event) throws android.os.RemoteException;
  /**
        * Invoked whenever a phrase recognition event is triggered (typically, on recognition, but
        * also in case of external aborting of a recognition or a forced recognition event - see the
        * status code in the event for determining).
        */
  public void onPhraseRecognition(int modelHandle, android.media.soundtrigger_middleware.PhraseRecognitionEvent event) throws android.os.RemoteException;
  /**
       * Notifies the client the recognition has become available after previously having been
       * unavailable, or vice versa. This method will always be invoked once immediately after
       * attachment, and then every time there is a change in availability.
       * When availability changes from available to unavailable, all active recognitions are aborted,
       * and this event will be sent in addition to the abort event.
       */
  public void onRecognitionAvailabilityChange(boolean available) throws android.os.RemoteException;
  /**
       * Notifies the client that the associated module has crashed and restarted. The module instance
       * is no longer usable and will throw a ServiceSpecificException with a Status.DEAD_OBJECT code
       * for every call. The client should detach, then re-attach to the module in order to get a new,
       * usable instance. All state for this module has been lost.
       */
  public void onModuleDied() throws android.os.RemoteException;
}
