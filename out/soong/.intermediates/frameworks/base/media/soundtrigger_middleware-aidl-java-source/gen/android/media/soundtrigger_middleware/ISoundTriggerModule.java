/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * A sound-trigger module.
 *
 * This interface allows a client to operate a sound-trigger device, intended for low-power
 * detection of various sound patterns, represented by a "sound model".
 *
 * Basic operation is to load a sound model (either a generic one or a "phrase" model), then
 * initiate recognition on this model. A trigger will be delivered asynchronously via a callback
 * provided by the caller earlier, when attaching to this interface.
 *
 * In additon to recognition events, this module will also produce abort events in cases where
 * recognition has been externally preempted.
 *
 * {@hide}
 */
public interface ISoundTriggerModule extends android.os.IInterface
{
  /** Default implementation for ISoundTriggerModule. */
  public static class Default implements android.media.soundtrigger_middleware.ISoundTriggerModule
  {
    /**
         * Load a sound model. Will return a handle to the model on success or will throw a
         * ServiceSpecificException with one of the {@link Status} error codes upon a recoverable error
         * (for example, lack of resources of loading a model at the time of call.
         * Model must eventually be unloaded using {@link #unloadModel(int)} prior to detaching.
         *
         * May throw a ServiceSpecificException with an RESOURCE_CONTENTION status to indicate that
         * resources required for loading the model are currently consumed by other clients.
         */
    @Override public int loadModel(android.media.soundtrigger_middleware.SoundModel model) throws android.os.RemoteException
    {
      return 0;
    }
    /**
         * Load a phrase sound model. Will return a handle to the model on success or will throw a
         * ServiceSpecificException with one of the {@link Status} error codes upon a recoverable error
         * (for example, lack of resources of loading a model at the time of call.
         * Model must eventually be unloaded using unloadModel prior to detaching.
         *
         * May throw a ServiceSpecificException with an RESOURCE_CONTENTION status to indicate that
         * resources required for loading the model are currently consumed by other clients.
         */
    @Override public int loadPhraseModel(android.media.soundtrigger_middleware.PhraseSoundModel model) throws android.os.RemoteException
    {
      return 0;
    }
    /**
         * Unload a model, previously loaded with loadModel or loadPhraseModel. After unloading, model
         * can no longer be used for recognition and the resources occupied by it are released.
         * Model must not be active at the time of unloading. Cient may call stopRecognition to ensure
         * that.
         */
    @Override public void unloadModel(int modelHandle) throws android.os.RemoteException
    {
    }
    /**
         * Initiate recognition on a previously loaded model.
         * Recognition event would eventually be delivered via the client-provided callback, typically
         * supplied during attachment to this interface.
         *
         * Once a recognition event is passed to the client, the recognition automatically become
         * inactive, unless the event is of the RecognitionStatus.FORCED kind. Client can also shut down
         * the recognition explicitly, via stopRecognition.
         */
    @Override public void startRecognition(int modelHandle, android.media.soundtrigger_middleware.RecognitionConfig config) throws android.os.RemoteException
    {
    }
    /**
         * Stop a recognition of a previously active recognition. Will NOT generate a recognition event.
         * This call is idempotent - calling it on an inactive model has no effect. However, it must
         * only be used with a loaded model handle.
         */
    @Override public void stopRecognition(int modelHandle) throws android.os.RemoteException
    {
    }
    /**
         * Force generation of a recognition event. Handle must be that of a loaded model. If
         * recognition is inactive, will do nothing. If recognition is active, will asynchronously
         * deliever an event with RecognitionStatus.FORCED status and leave recognition in active state.
         * To avoid any race conditions, once an event signalling the automatic stopping of recognition
         * is sent, no more forced events will get sent (even if previously requested) until recognition
         * is explicitly started again.
         *
         * Since not all module implementations support this feature, may throw a
         * ServiceSpecificException with an OPERATION_NOT_SUPPORTED status.
         */
    @Override public void forceRecognitionEvent(int modelHandle) throws android.os.RemoteException
    {
    }
    /**
         * Set a model specific parameter with the given value. This parameter
         * will keep its value for the duration the model is loaded regardless of starting and stopping
         * recognition. Once the model is unloaded, the value will be lost.
         * It is expected to check if the handle supports the parameter via the
         * queryModelParameterSupport API prior to calling this method.
         *
         * @param modelHandle The sound model handle indicating which model to modify parameters
         * @param modelParam Parameter to set which will be validated against the
         *                   ModelParameter type.
         * @param value The value to set for the given model parameter
         */
    @Override public void setModelParameter(int modelHandle, int modelParam, int value) throws android.os.RemoteException
    {
    }
    /**
         * Get a model specific parameter. This parameter will keep its value
         * for the duration the model is loaded regardless of starting and stopping recognition.
         * Once the model is unloaded, the value will be lost. If the value is not set, a default
         * value is returned. See ModelParameter for parameter default values.
         * It is expected to check if the handle supports the parameter via the
         * queryModelParameterSupport API prior to calling this method.
         *
         * @param modelHandle The sound model associated with given modelParam
         * @param modelParam Parameter to set which will be validated against the
         *                   ModelParameter type.
         * @return Value set to the requested parameter.
         */
    @Override public int getModelParameter(int modelHandle, int modelParam) throws android.os.RemoteException
    {
      return 0;
    }
    /**
         * Determine if parameter control is supported for the given model handle, and its valid value
         * range if it is.
         *
         * @param modelHandle The sound model handle indicating which model to query
         * @param modelParam Parameter to set which will be validated against the
         *                   ModelParameter type.
         * @return If parameter is supported, the return value is its valid range, otherwise null.
         */
    @Override public android.media.soundtrigger_middleware.ModelParameterRange queryModelParameterSupport(int modelHandle, int modelParam) throws android.os.RemoteException
    {
      return null;
    }
    /**
         * Detach from the module, releasing any active resources.
         * This will ensure the client callback is no longer called after this call returns.
         * All models must have been unloaded prior to calling this method.
         */
    @Override public void detach() throws android.os.RemoteException
    {
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements android.media.soundtrigger_middleware.ISoundTriggerModule
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.media.soundtrigger_middleware.ISoundTriggerModule interface,
     * generating a proxy if needed.
     */
    public static android.media.soundtrigger_middleware.ISoundTriggerModule asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.media.soundtrigger_middleware.ISoundTriggerModule))) {
        return ((android.media.soundtrigger_middleware.ISoundTriggerModule)iin);
      }
      return new android.media.soundtrigger_middleware.ISoundTriggerModule.Stub.Proxy(obj);
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
        case TRANSACTION_loadModel:
        {
          data.enforceInterface(descriptor);
          android.media.soundtrigger_middleware.SoundModel _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.media.soundtrigger_middleware.SoundModel.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          int _result = this.loadModel(_arg0);
          reply.writeNoException();
          reply.writeInt(_result);
          return true;
        }
        case TRANSACTION_loadPhraseModel:
        {
          data.enforceInterface(descriptor);
          android.media.soundtrigger_middleware.PhraseSoundModel _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.media.soundtrigger_middleware.PhraseSoundModel.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          int _result = this.loadPhraseModel(_arg0);
          reply.writeNoException();
          reply.writeInt(_result);
          return true;
        }
        case TRANSACTION_unloadModel:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.unloadModel(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_startRecognition:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          android.media.soundtrigger_middleware.RecognitionConfig _arg1;
          if ((0!=data.readInt())) {
            _arg1 = android.media.soundtrigger_middleware.RecognitionConfig.CREATOR.createFromParcel(data);
          }
          else {
            _arg1 = null;
          }
          this.startRecognition(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_stopRecognition:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.stopRecognition(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_forceRecognitionEvent:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.forceRecognitionEvent(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setModelParameter:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          int _arg2;
          _arg2 = data.readInt();
          this.setModelParameter(_arg0, _arg1, _arg2);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getModelParameter:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          int _result = this.getModelParameter(_arg0, _arg1);
          reply.writeNoException();
          reply.writeInt(_result);
          return true;
        }
        case TRANSACTION_queryModelParameterSupport:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          android.media.soundtrigger_middleware.ModelParameterRange _result = this.queryModelParameterSupport(_arg0, _arg1);
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
        case TRANSACTION_detach:
        {
          data.enforceInterface(descriptor);
          this.detach();
          reply.writeNoException();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.media.soundtrigger_middleware.ISoundTriggerModule
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
           * Load a sound model. Will return a handle to the model on success or will throw a
           * ServiceSpecificException with one of the {@link Status} error codes upon a recoverable error
           * (for example, lack of resources of loading a model at the time of call.
           * Model must eventually be unloaded using {@link #unloadModel(int)} prior to detaching.
           *
           * May throw a ServiceSpecificException with an RESOURCE_CONTENTION status to indicate that
           * resources required for loading the model are currently consumed by other clients.
           */
      @Override public int loadModel(android.media.soundtrigger_middleware.SoundModel model) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((model!=null)) {
            _data.writeInt(1);
            model.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_loadModel, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().loadModel(model);
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
      /**
           * Load a phrase sound model. Will return a handle to the model on success or will throw a
           * ServiceSpecificException with one of the {@link Status} error codes upon a recoverable error
           * (for example, lack of resources of loading a model at the time of call.
           * Model must eventually be unloaded using unloadModel prior to detaching.
           *
           * May throw a ServiceSpecificException with an RESOURCE_CONTENTION status to indicate that
           * resources required for loading the model are currently consumed by other clients.
           */
      @Override public int loadPhraseModel(android.media.soundtrigger_middleware.PhraseSoundModel model) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((model!=null)) {
            _data.writeInt(1);
            model.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_loadPhraseModel, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().loadPhraseModel(model);
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
      /**
           * Unload a model, previously loaded with loadModel or loadPhraseModel. After unloading, model
           * can no longer be used for recognition and the resources occupied by it are released.
           * Model must not be active at the time of unloading. Cient may call stopRecognition to ensure
           * that.
           */
      @Override public void unloadModel(int modelHandle) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(modelHandle);
          boolean _status = mRemote.transact(Stub.TRANSACTION_unloadModel, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().unloadModel(modelHandle);
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
           * Initiate recognition on a previously loaded model.
           * Recognition event would eventually be delivered via the client-provided callback, typically
           * supplied during attachment to this interface.
           *
           * Once a recognition event is passed to the client, the recognition automatically become
           * inactive, unless the event is of the RecognitionStatus.FORCED kind. Client can also shut down
           * the recognition explicitly, via stopRecognition.
           */
      @Override public void startRecognition(int modelHandle, android.media.soundtrigger_middleware.RecognitionConfig config) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(modelHandle);
          if ((config!=null)) {
            _data.writeInt(1);
            config.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_startRecognition, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().startRecognition(modelHandle, config);
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
           * Stop a recognition of a previously active recognition. Will NOT generate a recognition event.
           * This call is idempotent - calling it on an inactive model has no effect. However, it must
           * only be used with a loaded model handle.
           */
      @Override public void stopRecognition(int modelHandle) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(modelHandle);
          boolean _status = mRemote.transact(Stub.TRANSACTION_stopRecognition, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().stopRecognition(modelHandle);
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
           * Force generation of a recognition event. Handle must be that of a loaded model. If
           * recognition is inactive, will do nothing. If recognition is active, will asynchronously
           * deliever an event with RecognitionStatus.FORCED status and leave recognition in active state.
           * To avoid any race conditions, once an event signalling the automatic stopping of recognition
           * is sent, no more forced events will get sent (even if previously requested) until recognition
           * is explicitly started again.
           *
           * Since not all module implementations support this feature, may throw a
           * ServiceSpecificException with an OPERATION_NOT_SUPPORTED status.
           */
      @Override public void forceRecognitionEvent(int modelHandle) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(modelHandle);
          boolean _status = mRemote.transact(Stub.TRANSACTION_forceRecognitionEvent, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().forceRecognitionEvent(modelHandle);
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
           * Set a model specific parameter with the given value. This parameter
           * will keep its value for the duration the model is loaded regardless of starting and stopping
           * recognition. Once the model is unloaded, the value will be lost.
           * It is expected to check if the handle supports the parameter via the
           * queryModelParameterSupport API prior to calling this method.
           *
           * @param modelHandle The sound model handle indicating which model to modify parameters
           * @param modelParam Parameter to set which will be validated against the
           *                   ModelParameter type.
           * @param value The value to set for the given model parameter
           */
      @Override public void setModelParameter(int modelHandle, int modelParam, int value) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(modelHandle);
          _data.writeInt(modelParam);
          _data.writeInt(value);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setModelParameter, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setModelParameter(modelHandle, modelParam, value);
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
           * Get a model specific parameter. This parameter will keep its value
           * for the duration the model is loaded regardless of starting and stopping recognition.
           * Once the model is unloaded, the value will be lost. If the value is not set, a default
           * value is returned. See ModelParameter for parameter default values.
           * It is expected to check if the handle supports the parameter via the
           * queryModelParameterSupport API prior to calling this method.
           *
           * @param modelHandle The sound model associated with given modelParam
           * @param modelParam Parameter to set which will be validated against the
           *                   ModelParameter type.
           * @return Value set to the requested parameter.
           */
      @Override public int getModelParameter(int modelHandle, int modelParam) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(modelHandle);
          _data.writeInt(modelParam);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getModelParameter, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getModelParameter(modelHandle, modelParam);
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
      /**
           * Determine if parameter control is supported for the given model handle, and its valid value
           * range if it is.
           *
           * @param modelHandle The sound model handle indicating which model to query
           * @param modelParam Parameter to set which will be validated against the
           *                   ModelParameter type.
           * @return If parameter is supported, the return value is its valid range, otherwise null.
           */
      @Override public android.media.soundtrigger_middleware.ModelParameterRange queryModelParameterSupport(int modelHandle, int modelParam) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.media.soundtrigger_middleware.ModelParameterRange _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(modelHandle);
          _data.writeInt(modelParam);
          boolean _status = mRemote.transact(Stub.TRANSACTION_queryModelParameterSupport, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().queryModelParameterSupport(modelHandle, modelParam);
            }
          }
          _reply.readException();
          if ((0!=_reply.readInt())) {
            _result = android.media.soundtrigger_middleware.ModelParameterRange.CREATOR.createFromParcel(_reply);
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
      /**
           * Detach from the module, releasing any active resources.
           * This will ensure the client callback is no longer called after this call returns.
           * All models must have been unloaded prior to calling this method.
           */
      @Override public void detach() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_detach, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().detach();
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
      public static android.media.soundtrigger_middleware.ISoundTriggerModule sDefaultImpl;
    }
    static final int TRANSACTION_loadModel = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_loadPhraseModel = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_unloadModel = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_startRecognition = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_stopRecognition = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_forceRecognitionEvent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_setModelParameter = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_getModelParameter = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
    static final int TRANSACTION_queryModelParameterSupport = (android.os.IBinder.FIRST_CALL_TRANSACTION + 8);
    static final int TRANSACTION_detach = (android.os.IBinder.FIRST_CALL_TRANSACTION + 9);
    public static boolean setDefaultImpl(android.media.soundtrigger_middleware.ISoundTriggerModule impl) {
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
    public static android.media.soundtrigger_middleware.ISoundTriggerModule getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$media$soundtrigger_middleware$ISoundTriggerModule".replace('$', '.');
  /**
       * Load a sound model. Will return a handle to the model on success or will throw a
       * ServiceSpecificException with one of the {@link Status} error codes upon a recoverable error
       * (for example, lack of resources of loading a model at the time of call.
       * Model must eventually be unloaded using {@link #unloadModel(int)} prior to detaching.
       *
       * May throw a ServiceSpecificException with an RESOURCE_CONTENTION status to indicate that
       * resources required for loading the model are currently consumed by other clients.
       */
  public int loadModel(android.media.soundtrigger_middleware.SoundModel model) throws android.os.RemoteException;
  /**
       * Load a phrase sound model. Will return a handle to the model on success or will throw a
       * ServiceSpecificException with one of the {@link Status} error codes upon a recoverable error
       * (for example, lack of resources of loading a model at the time of call.
       * Model must eventually be unloaded using unloadModel prior to detaching.
       *
       * May throw a ServiceSpecificException with an RESOURCE_CONTENTION status to indicate that
       * resources required for loading the model are currently consumed by other clients.
       */
  public int loadPhraseModel(android.media.soundtrigger_middleware.PhraseSoundModel model) throws android.os.RemoteException;
  /**
       * Unload a model, previously loaded with loadModel or loadPhraseModel. After unloading, model
       * can no longer be used for recognition and the resources occupied by it are released.
       * Model must not be active at the time of unloading. Cient may call stopRecognition to ensure
       * that.
       */
  public void unloadModel(int modelHandle) throws android.os.RemoteException;
  /**
       * Initiate recognition on a previously loaded model.
       * Recognition event would eventually be delivered via the client-provided callback, typically
       * supplied during attachment to this interface.
       *
       * Once a recognition event is passed to the client, the recognition automatically become
       * inactive, unless the event is of the RecognitionStatus.FORCED kind. Client can also shut down
       * the recognition explicitly, via stopRecognition.
       */
  public void startRecognition(int modelHandle, android.media.soundtrigger_middleware.RecognitionConfig config) throws android.os.RemoteException;
  /**
       * Stop a recognition of a previously active recognition. Will NOT generate a recognition event.
       * This call is idempotent - calling it on an inactive model has no effect. However, it must
       * only be used with a loaded model handle.
       */
  public void stopRecognition(int modelHandle) throws android.os.RemoteException;
  /**
       * Force generation of a recognition event. Handle must be that of a loaded model. If
       * recognition is inactive, will do nothing. If recognition is active, will asynchronously
       * deliever an event with RecognitionStatus.FORCED status and leave recognition in active state.
       * To avoid any race conditions, once an event signalling the automatic stopping of recognition
       * is sent, no more forced events will get sent (even if previously requested) until recognition
       * is explicitly started again.
       *
       * Since not all module implementations support this feature, may throw a
       * ServiceSpecificException with an OPERATION_NOT_SUPPORTED status.
       */
  public void forceRecognitionEvent(int modelHandle) throws android.os.RemoteException;
  /**
       * Set a model specific parameter with the given value. This parameter
       * will keep its value for the duration the model is loaded regardless of starting and stopping
       * recognition. Once the model is unloaded, the value will be lost.
       * It is expected to check if the handle supports the parameter via the
       * queryModelParameterSupport API prior to calling this method.
       *
       * @param modelHandle The sound model handle indicating which model to modify parameters
       * @param modelParam Parameter to set which will be validated against the
       *                   ModelParameter type.
       * @param value The value to set for the given model parameter
       */
  public void setModelParameter(int modelHandle, int modelParam, int value) throws android.os.RemoteException;
  /**
       * Get a model specific parameter. This parameter will keep its value
       * for the duration the model is loaded regardless of starting and stopping recognition.
       * Once the model is unloaded, the value will be lost. If the value is not set, a default
       * value is returned. See ModelParameter for parameter default values.
       * It is expected to check if the handle supports the parameter via the
       * queryModelParameterSupport API prior to calling this method.
       *
       * @param modelHandle The sound model associated with given modelParam
       * @param modelParam Parameter to set which will be validated against the
       *                   ModelParameter type.
       * @return Value set to the requested parameter.
       */
  public int getModelParameter(int modelHandle, int modelParam) throws android.os.RemoteException;
  /**
       * Determine if parameter control is supported for the given model handle, and its valid value
       * range if it is.
       *
       * @param modelHandle The sound model handle indicating which model to query
       * @param modelParam Parameter to set which will be validated against the
       *                   ModelParameter type.
       * @return If parameter is supported, the return value is its valid range, otherwise null.
       */
  public android.media.soundtrigger_middleware.ModelParameterRange queryModelParameterSupport(int modelHandle, int modelParam) throws android.os.RemoteException;
  /**
       * Detach from the module, releasing any active resources.
       * This will ensure the client callback is no longer called after this call returns.
       * All models must have been unloaded prior to calling this method.
       */
  public void detach() throws android.os.RemoteException;
}
