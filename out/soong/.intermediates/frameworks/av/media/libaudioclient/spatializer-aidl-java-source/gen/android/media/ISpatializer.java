/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * The ISpatializer interface is used to control the native audio service implementation
 * of the spatializer stage with headtracking when present on a platform.
 * It is intended for exclusive use by the java AudioService running in system_server.
 * It provides APIs to discover the feature availability and options as well as control and report
 * the active state and modes of the spatializer and head tracking effect.
 * {@hide}
 */
public interface ISpatializer extends android.os.IInterface
{
  /** Default implementation for ISpatializer. */
  public static class Default implements android.media.ISpatializer
  {
    /** Releases a ISpatializer interface previously acquired. */
    @Override public void release() throws android.os.RemoteException
    {
    }
    /** Reports the list of supported spatialization levels (see SpatializationLevel.aidl).
         * The list should never be empty if an ISpatializer interface was successfully
         * retrieved with IAudioPolicyService.getSpatializer().
         */
    @Override public byte[] getSupportedLevels() throws android.os.RemoteException
    {
      return null;
    }
    /** Selects the desired spatialization level (see SpatializationLevel.aidl). Selecting a level
         * different from SpatializationLevel.NONE with create the specialized multichannel output
         * mixer, create and enable the spatializer effect and let the audio policy attach eligible
         * AudioTrack to this output stream.
         */
    @Override public void setLevel(byte level) throws android.os.RemoteException
    {
    }
    /** Gets the selected spatialization level (see SpatializationLevel.aidl) */
    @Override public byte getLevel() throws android.os.RemoteException
    {
      return 0;
    }
    /** Reports if the spatializer engine supports head tracking or not.
         * This is a pre condition independent of the fact that a head tracking sensor is
         * registered or not.
         */
    @Override public boolean isHeadTrackingSupported() throws android.os.RemoteException
    {
      return false;
    }
    /** Reports the list of supported head tracking modes (see SpatializerHeadTrackingMode.aidl).
         * The list can be empty if the spatializer implementation does not support head tracking or if
         * no head tracking sensor is registered (see setHeadSensor() and setScreenSensor()).
         */
    @Override public byte[] getSupportedHeadTrackingModes() throws android.os.RemoteException
    {
      return null;
    }
    /** Selects the desired head tracking mode (see SpatializerHeadTrackingMode.aidl) */
    @Override public void setDesiredHeadTrackingMode(byte mode) throws android.os.RemoteException
    {
    }
    /** Gets the actual head tracking mode. Can be different from the desired mode if conditions to
         * enable the desired mode are not met (e.g if the head tracking device was removed)
         */
    @Override public byte getActualHeadTrackingMode() throws android.os.RemoteException
    {
      return 0;
    }
    /** Reset the head tracking algorithm to consider current head pose as neutral */
    @Override public void recenterHeadTracker() throws android.os.RemoteException
    {
    }
    /** Set the screen to stage transform to use by the head tracking algorithm
         * The screen to stage transform is conveyed as a vector of 6 elements,
         * where the first three are a translation vector and
         * the last three are a rotation vector.
         */
    @Override public void setGlobalTransform(float[] screenToStage) throws android.os.RemoteException
    {
    }
    /**
         * Set the sensor that is to be used for head-tracking.
         * -1 can be used to disable head-tracking.
         */
    @Override public void setHeadSensor(int sensorHandle) throws android.os.RemoteException
    {
    }
    /**
         * Set the sensor that is to be used for screen-tracking.
         * -1 can be used to disable screen-tracking.
         */
    @Override public void setScreenSensor(int sensorHandle) throws android.os.RemoteException
    {
    }
    /**
         * Sets the display orientation.
         * Orientation is expressed in the angle of rotation from the physical "up" side of the screen
         * to the logical "up" side of the content displayed the screen. Counterclockwise angles, as
         * viewed while facing the screen are positive.
         */
    @Override public void setDisplayOrientation(float physicalToLogicalAngle) throws android.os.RemoteException
    {
    }
    /**
         * Sets the hinge angle for foldable devices.
         */
    @Override public void setHingeAngle(float hingeAngle) throws android.os.RemoteException
    {
    }
    /** Reports the list of supported spatialization modess (see SpatializationMode.aidl).
         * The list should never be empty if an ISpatializer interface was successfully
         * retrieved with IAudioPolicyService.getSpatializer().
         */
    @Override public byte[] getSupportedModes() throws android.os.RemoteException
    {
      return null;
    }
    /**
         * Registers a callback to monitor head tracking functions.
         * Only one callback can be registered on a Spatializer.
         * The last callback registered wins and passing a nullptr unregisters
         * last registered callback.
         */
    @Override public void registerHeadTrackingCallback(android.media.ISpatializerHeadTrackingCallback callback) throws android.os.RemoteException
    {
    }
    /**
         * Sets a parameter to the spatializer engine. Used by effect implementor for vendor
         * specific configuration.
         */
    @Override public void setParameter(int key, byte[] value) throws android.os.RemoteException
    {
    }
    /**
         * Gets a parameter from the spatializer engine. Used by effect implementor for vendor
         * specific configuration.
         */
    @Override public void getParameter(int key, byte[] value) throws android.os.RemoteException
    {
    }
    /**
         * Gets the io handle of the output stream the spatializer is connected to.
         */
    @Override public int getOutput() throws android.os.RemoteException
    {
      return 0;
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements android.media.ISpatializer
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.media.ISpatializer interface,
     * generating a proxy if needed.
     */
    public static android.media.ISpatializer asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.media.ISpatializer))) {
        return ((android.media.ISpatializer)iin);
      }
      return new android.media.ISpatializer.Stub.Proxy(obj);
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
        case TRANSACTION_release:
        {
          data.enforceInterface(descriptor);
          this.release();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getSupportedLevels:
        {
          data.enforceInterface(descriptor);
          byte[] _result = this.getSupportedLevels();
          reply.writeNoException();
          reply.writeByteArray(_result);
          return true;
        }
        case TRANSACTION_setLevel:
        {
          data.enforceInterface(descriptor);
          byte _arg0;
          _arg0 = data.readByte();
          this.setLevel(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getLevel:
        {
          data.enforceInterface(descriptor);
          byte _result = this.getLevel();
          reply.writeNoException();
          reply.writeByte(_result);
          return true;
        }
        case TRANSACTION_isHeadTrackingSupported:
        {
          data.enforceInterface(descriptor);
          boolean _result = this.isHeadTrackingSupported();
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        case TRANSACTION_getSupportedHeadTrackingModes:
        {
          data.enforceInterface(descriptor);
          byte[] _result = this.getSupportedHeadTrackingModes();
          reply.writeNoException();
          reply.writeByteArray(_result);
          return true;
        }
        case TRANSACTION_setDesiredHeadTrackingMode:
        {
          data.enforceInterface(descriptor);
          byte _arg0;
          _arg0 = data.readByte();
          this.setDesiredHeadTrackingMode(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getActualHeadTrackingMode:
        {
          data.enforceInterface(descriptor);
          byte _result = this.getActualHeadTrackingMode();
          reply.writeNoException();
          reply.writeByte(_result);
          return true;
        }
        case TRANSACTION_recenterHeadTracker:
        {
          data.enforceInterface(descriptor);
          this.recenterHeadTracker();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setGlobalTransform:
        {
          data.enforceInterface(descriptor);
          float[] _arg0;
          _arg0 = data.createFloatArray();
          this.setGlobalTransform(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setHeadSensor:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.setHeadSensor(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setScreenSensor:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.setScreenSensor(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setDisplayOrientation:
        {
          data.enforceInterface(descriptor);
          float _arg0;
          _arg0 = data.readFloat();
          this.setDisplayOrientation(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setHingeAngle:
        {
          data.enforceInterface(descriptor);
          float _arg0;
          _arg0 = data.readFloat();
          this.setHingeAngle(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getSupportedModes:
        {
          data.enforceInterface(descriptor);
          byte[] _result = this.getSupportedModes();
          reply.writeNoException();
          reply.writeByteArray(_result);
          return true;
        }
        case TRANSACTION_registerHeadTrackingCallback:
        {
          data.enforceInterface(descriptor);
          android.media.ISpatializerHeadTrackingCallback _arg0;
          _arg0 = android.media.ISpatializerHeadTrackingCallback.Stub.asInterface(data.readStrongBinder());
          this.registerHeadTrackingCallback(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setParameter:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          byte[] _arg1;
          _arg1 = data.createByteArray();
          this.setParameter(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getParameter:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          byte[] _arg1;
          _arg1 = data.createByteArray();
          this.getParameter(_arg0, _arg1);
          reply.writeNoException();
          reply.writeByteArray(_arg1);
          return true;
        }
        case TRANSACTION_getOutput:
        {
          data.enforceInterface(descriptor);
          int _result = this.getOutput();
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
    private static class Proxy implements android.media.ISpatializer
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
      /** Releases a ISpatializer interface previously acquired. */
      @Override public void release() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_release, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().release();
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
      /** Reports the list of supported spatialization levels (see SpatializationLevel.aidl).
           * The list should never be empty if an ISpatializer interface was successfully
           * retrieved with IAudioPolicyService.getSpatializer().
           */
      @Override public byte[] getSupportedLevels() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        byte[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getSupportedLevels, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getSupportedLevels();
            }
          }
          _reply.readException();
          _result = _reply.createByteArray();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      /** Selects the desired spatialization level (see SpatializationLevel.aidl). Selecting a level
           * different from SpatializationLevel.NONE with create the specialized multichannel output
           * mixer, create and enable the spatializer effect and let the audio policy attach eligible
           * AudioTrack to this output stream.
           */
      @Override public void setLevel(byte level) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByte(level);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setLevel, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setLevel(level);
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
      /** Gets the selected spatialization level (see SpatializationLevel.aidl) */
      @Override public byte getLevel() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        byte _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getLevel, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getLevel();
            }
          }
          _reply.readException();
          _result = _reply.readByte();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      /** Reports if the spatializer engine supports head tracking or not.
           * This is a pre condition independent of the fact that a head tracking sensor is
           * registered or not.
           */
      @Override public boolean isHeadTrackingSupported() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_isHeadTrackingSupported, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().isHeadTrackingSupported();
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
      /** Reports the list of supported head tracking modes (see SpatializerHeadTrackingMode.aidl).
           * The list can be empty if the spatializer implementation does not support head tracking or if
           * no head tracking sensor is registered (see setHeadSensor() and setScreenSensor()).
           */
      @Override public byte[] getSupportedHeadTrackingModes() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        byte[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getSupportedHeadTrackingModes, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getSupportedHeadTrackingModes();
            }
          }
          _reply.readException();
          _result = _reply.createByteArray();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      /** Selects the desired head tracking mode (see SpatializerHeadTrackingMode.aidl) */
      @Override public void setDesiredHeadTrackingMode(byte mode) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByte(mode);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setDesiredHeadTrackingMode, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setDesiredHeadTrackingMode(mode);
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
      /** Gets the actual head tracking mode. Can be different from the desired mode if conditions to
           * enable the desired mode are not met (e.g if the head tracking device was removed)
           */
      @Override public byte getActualHeadTrackingMode() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        byte _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getActualHeadTrackingMode, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getActualHeadTrackingMode();
            }
          }
          _reply.readException();
          _result = _reply.readByte();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      /** Reset the head tracking algorithm to consider current head pose as neutral */
      @Override public void recenterHeadTracker() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_recenterHeadTracker, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().recenterHeadTracker();
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
      /** Set the screen to stage transform to use by the head tracking algorithm
           * The screen to stage transform is conveyed as a vector of 6 elements,
           * where the first three are a translation vector and
           * the last three are a rotation vector.
           */
      @Override public void setGlobalTransform(float[] screenToStage) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeFloatArray(screenToStage);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setGlobalTransform, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setGlobalTransform(screenToStage);
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
           * Set the sensor that is to be used for head-tracking.
           * -1 can be used to disable head-tracking.
           */
      @Override public void setHeadSensor(int sensorHandle) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(sensorHandle);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setHeadSensor, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setHeadSensor(sensorHandle);
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
           * Set the sensor that is to be used for screen-tracking.
           * -1 can be used to disable screen-tracking.
           */
      @Override public void setScreenSensor(int sensorHandle) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(sensorHandle);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setScreenSensor, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setScreenSensor(sensorHandle);
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
           * Sets the display orientation.
           * Orientation is expressed in the angle of rotation from the physical "up" side of the screen
           * to the logical "up" side of the content displayed the screen. Counterclockwise angles, as
           * viewed while facing the screen are positive.
           */
      @Override public void setDisplayOrientation(float physicalToLogicalAngle) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeFloat(physicalToLogicalAngle);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setDisplayOrientation, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setDisplayOrientation(physicalToLogicalAngle);
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
           * Sets the hinge angle for foldable devices.
           */
      @Override public void setHingeAngle(float hingeAngle) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeFloat(hingeAngle);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setHingeAngle, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setHingeAngle(hingeAngle);
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
      /** Reports the list of supported spatialization modess (see SpatializationMode.aidl).
           * The list should never be empty if an ISpatializer interface was successfully
           * retrieved with IAudioPolicyService.getSpatializer().
           */
      @Override public byte[] getSupportedModes() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        byte[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getSupportedModes, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getSupportedModes();
            }
          }
          _reply.readException();
          _result = _reply.createByteArray();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      /**
           * Registers a callback to monitor head tracking functions.
           * Only one callback can be registered on a Spatializer.
           * The last callback registered wins and passing a nullptr unregisters
           * last registered callback.
           */
      @Override public void registerHeadTrackingCallback(android.media.ISpatializerHeadTrackingCallback callback) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((callback!=null))?(callback.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_registerHeadTrackingCallback, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().registerHeadTrackingCallback(callback);
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
           * Sets a parameter to the spatializer engine. Used by effect implementor for vendor
           * specific configuration.
           */
      @Override public void setParameter(int key, byte[] value) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(key);
          _data.writeByteArray(value);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setParameter, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setParameter(key, value);
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
           * Gets a parameter from the spatializer engine. Used by effect implementor for vendor
           * specific configuration.
           */
      @Override public void getParameter(int key, byte[] value) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(key);
          _data.writeByteArray(value);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getParameter, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().getParameter(key, value);
              return;
            }
          }
          _reply.readException();
          _reply.readByteArray(value);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      /**
           * Gets the io handle of the output stream the spatializer is connected to.
           */
      @Override public int getOutput() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getOutput, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getOutput();
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
      public static android.media.ISpatializer sDefaultImpl;
    }
    static final int TRANSACTION_release = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_getSupportedLevels = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_setLevel = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_getLevel = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_isHeadTrackingSupported = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_getSupportedHeadTrackingModes = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_setDesiredHeadTrackingMode = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_getActualHeadTrackingMode = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
    static final int TRANSACTION_recenterHeadTracker = (android.os.IBinder.FIRST_CALL_TRANSACTION + 8);
    static final int TRANSACTION_setGlobalTransform = (android.os.IBinder.FIRST_CALL_TRANSACTION + 9);
    static final int TRANSACTION_setHeadSensor = (android.os.IBinder.FIRST_CALL_TRANSACTION + 10);
    static final int TRANSACTION_setScreenSensor = (android.os.IBinder.FIRST_CALL_TRANSACTION + 11);
    static final int TRANSACTION_setDisplayOrientation = (android.os.IBinder.FIRST_CALL_TRANSACTION + 12);
    static final int TRANSACTION_setHingeAngle = (android.os.IBinder.FIRST_CALL_TRANSACTION + 13);
    static final int TRANSACTION_getSupportedModes = (android.os.IBinder.FIRST_CALL_TRANSACTION + 14);
    static final int TRANSACTION_registerHeadTrackingCallback = (android.os.IBinder.FIRST_CALL_TRANSACTION + 15);
    static final int TRANSACTION_setParameter = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16);
    static final int TRANSACTION_getParameter = (android.os.IBinder.FIRST_CALL_TRANSACTION + 17);
    static final int TRANSACTION_getOutput = (android.os.IBinder.FIRST_CALL_TRANSACTION + 18);
    public static boolean setDefaultImpl(android.media.ISpatializer impl) {
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
    public static android.media.ISpatializer getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$media$ISpatializer".replace('$', '.');
  /** Releases a ISpatializer interface previously acquired. */
  public void release() throws android.os.RemoteException;
  /** Reports the list of supported spatialization levels (see SpatializationLevel.aidl).
       * The list should never be empty if an ISpatializer interface was successfully
       * retrieved with IAudioPolicyService.getSpatializer().
       */
  public byte[] getSupportedLevels() throws android.os.RemoteException;
  /** Selects the desired spatialization level (see SpatializationLevel.aidl). Selecting a level
       * different from SpatializationLevel.NONE with create the specialized multichannel output
       * mixer, create and enable the spatializer effect and let the audio policy attach eligible
       * AudioTrack to this output stream.
       */
  public void setLevel(byte level) throws android.os.RemoteException;
  /** Gets the selected spatialization level (see SpatializationLevel.aidl) */
  public byte getLevel() throws android.os.RemoteException;
  /** Reports if the spatializer engine supports head tracking or not.
       * This is a pre condition independent of the fact that a head tracking sensor is
       * registered or not.
       */
  public boolean isHeadTrackingSupported() throws android.os.RemoteException;
  /** Reports the list of supported head tracking modes (see SpatializerHeadTrackingMode.aidl).
       * The list can be empty if the spatializer implementation does not support head tracking or if
       * no head tracking sensor is registered (see setHeadSensor() and setScreenSensor()).
       */
  public byte[] getSupportedHeadTrackingModes() throws android.os.RemoteException;
  /** Selects the desired head tracking mode (see SpatializerHeadTrackingMode.aidl) */
  public void setDesiredHeadTrackingMode(byte mode) throws android.os.RemoteException;
  /** Gets the actual head tracking mode. Can be different from the desired mode if conditions to
       * enable the desired mode are not met (e.g if the head tracking device was removed)
       */
  public byte getActualHeadTrackingMode() throws android.os.RemoteException;
  /** Reset the head tracking algorithm to consider current head pose as neutral */
  public void recenterHeadTracker() throws android.os.RemoteException;
  /** Set the screen to stage transform to use by the head tracking algorithm
       * The screen to stage transform is conveyed as a vector of 6 elements,
       * where the first three are a translation vector and
       * the last three are a rotation vector.
       */
  public void setGlobalTransform(float[] screenToStage) throws android.os.RemoteException;
  /**
       * Set the sensor that is to be used for head-tracking.
       * -1 can be used to disable head-tracking.
       */
  public void setHeadSensor(int sensorHandle) throws android.os.RemoteException;
  /**
       * Set the sensor that is to be used for screen-tracking.
       * -1 can be used to disable screen-tracking.
       */
  public void setScreenSensor(int sensorHandle) throws android.os.RemoteException;
  /**
       * Sets the display orientation.
       * Orientation is expressed in the angle of rotation from the physical "up" side of the screen
       * to the logical "up" side of the content displayed the screen. Counterclockwise angles, as
       * viewed while facing the screen are positive.
       */
  public void setDisplayOrientation(float physicalToLogicalAngle) throws android.os.RemoteException;
  /**
       * Sets the hinge angle for foldable devices.
       */
  public void setHingeAngle(float hingeAngle) throws android.os.RemoteException;
  /** Reports the list of supported spatialization modess (see SpatializationMode.aidl).
       * The list should never be empty if an ISpatializer interface was successfully
       * retrieved with IAudioPolicyService.getSpatializer().
       */
  public byte[] getSupportedModes() throws android.os.RemoteException;
  /**
       * Registers a callback to monitor head tracking functions.
       * Only one callback can be registered on a Spatializer.
       * The last callback registered wins and passing a nullptr unregisters
       * last registered callback.
       */
  public void registerHeadTrackingCallback(android.media.ISpatializerHeadTrackingCallback callback) throws android.os.RemoteException;
  /**
       * Sets a parameter to the spatializer engine. Used by effect implementor for vendor
       * specific configuration.
       */
  public void setParameter(int key, byte[] value) throws android.os.RemoteException;
  /**
       * Gets a parameter from the spatializer engine. Used by effect implementor for vendor
       * specific configuration.
       */
  public void getParameter(int key, byte[] value) throws android.os.RemoteException;
  /**
       * Gets the io handle of the output stream the spatializer is connected to.
       */
  public int getOutput() throws android.os.RemoteException;
}
