/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.hardware.power.stats;
public interface IPowerStats extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 1;
  public static final String HASH = "93253458fae451cf1187db6120a59fab428f7d02";
  /** Default implementation for IPowerStats. */
  public static class Default implements android.hardware.power.stats.IPowerStats
  {
    @Override public android.hardware.power.stats.PowerEntity[] getPowerEntityInfo() throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.hardware.power.stats.StateResidencyResult[] getStateResidency(int[] powerEntityIds) throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.hardware.power.stats.EnergyConsumer[] getEnergyConsumerInfo() throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.hardware.power.stats.EnergyConsumerResult[] getEnergyConsumed(int[] energyConsumerIds) throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.hardware.power.stats.Channel[] getEnergyMeterInfo() throws android.os.RemoteException
    {
      return null;
    }
    @Override public android.hardware.power.stats.EnergyMeasurement[] readEnergyMeter(int[] channelIds) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.hardware.power.stats.IPowerStats
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.markVintfStability();
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.hardware.power.stats.IPowerStats interface,
     * generating a proxy if needed.
     */
    public static android.hardware.power.stats.IPowerStats asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.hardware.power.stats.IPowerStats))) {
        return ((android.hardware.power.stats.IPowerStats)iin);
      }
      return new android.hardware.power.stats.IPowerStats.Stub.Proxy(obj);
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
        case TRANSACTION_getPowerEntityInfo:
        {
          data.enforceInterface(descriptor);
          android.hardware.power.stats.PowerEntity[] _result = this.getPowerEntityInfo();
          reply.writeNoException();
          reply.writeTypedArray(_result, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          return true;
        }
        case TRANSACTION_getStateResidency:
        {
          data.enforceInterface(descriptor);
          int[] _arg0;
          _arg0 = data.createIntArray();
          android.hardware.power.stats.StateResidencyResult[] _result = this.getStateResidency(_arg0);
          reply.writeNoException();
          reply.writeTypedArray(_result, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          return true;
        }
        case TRANSACTION_getEnergyConsumerInfo:
        {
          data.enforceInterface(descriptor);
          android.hardware.power.stats.EnergyConsumer[] _result = this.getEnergyConsumerInfo();
          reply.writeNoException();
          reply.writeTypedArray(_result, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          return true;
        }
        case TRANSACTION_getEnergyConsumed:
        {
          data.enforceInterface(descriptor);
          int[] _arg0;
          _arg0 = data.createIntArray();
          android.hardware.power.stats.EnergyConsumerResult[] _result = this.getEnergyConsumed(_arg0);
          reply.writeNoException();
          reply.writeTypedArray(_result, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          return true;
        }
        case TRANSACTION_getEnergyMeterInfo:
        {
          data.enforceInterface(descriptor);
          android.hardware.power.stats.Channel[] _result = this.getEnergyMeterInfo();
          reply.writeNoException();
          reply.writeTypedArray(_result, android.os.Parcelable.PARCELABLE_WRITE_RETURN_VALUE);
          return true;
        }
        case TRANSACTION_readEnergyMeter:
        {
          data.enforceInterface(descriptor);
          int[] _arg0;
          _arg0 = data.createIntArray();
          android.hardware.power.stats.EnergyMeasurement[] _result = this.readEnergyMeter(_arg0);
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
    private static class Proxy implements android.hardware.power.stats.IPowerStats
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
      @Override public android.hardware.power.stats.PowerEntity[] getPowerEntityInfo() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.power.stats.PowerEntity[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getPowerEntityInfo, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getPowerEntityInfo();
            }
            else {
              throw new android.os.RemoteException("Method getPowerEntityInfo is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createTypedArray(android.hardware.power.stats.PowerEntity.CREATOR);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public android.hardware.power.stats.StateResidencyResult[] getStateResidency(int[] powerEntityIds) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.power.stats.StateResidencyResult[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeIntArray(powerEntityIds);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getStateResidency, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getStateResidency(powerEntityIds);
            }
            else {
              throw new android.os.RemoteException("Method getStateResidency is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createTypedArray(android.hardware.power.stats.StateResidencyResult.CREATOR);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public android.hardware.power.stats.EnergyConsumer[] getEnergyConsumerInfo() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.power.stats.EnergyConsumer[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getEnergyConsumerInfo, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getEnergyConsumerInfo();
            }
            else {
              throw new android.os.RemoteException("Method getEnergyConsumerInfo is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createTypedArray(android.hardware.power.stats.EnergyConsumer.CREATOR);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public android.hardware.power.stats.EnergyConsumerResult[] getEnergyConsumed(int[] energyConsumerIds) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.power.stats.EnergyConsumerResult[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeIntArray(energyConsumerIds);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getEnergyConsumed, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getEnergyConsumed(energyConsumerIds);
            }
            else {
              throw new android.os.RemoteException("Method getEnergyConsumed is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createTypedArray(android.hardware.power.stats.EnergyConsumerResult.CREATOR);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public android.hardware.power.stats.Channel[] getEnergyMeterInfo() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.power.stats.Channel[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getEnergyMeterInfo, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().getEnergyMeterInfo();
            }
            else {
              throw new android.os.RemoteException("Method getEnergyMeterInfo is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createTypedArray(android.hardware.power.stats.Channel.CREATOR);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public android.hardware.power.stats.EnergyMeasurement[] readEnergyMeter(int[] channelIds) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        android.hardware.power.stats.EnergyMeasurement[] _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeIntArray(channelIds);
          boolean _status = mRemote.transact(Stub.TRANSACTION_readEnergyMeter, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              return getDefaultImpl().readEnergyMeter(channelIds);
            }
            else {
              throw new android.os.RemoteException("Method readEnergyMeter is unimplemented.");
            }
          }
          _reply.readException();
          _result = _reply.createTypedArray(android.hardware.power.stats.EnergyMeasurement.CREATOR);
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
      public static android.hardware.power.stats.IPowerStats sDefaultImpl;
    }
    static final int TRANSACTION_getPowerEntityInfo = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_getStateResidency = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_getEnergyConsumerInfo = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_getEnergyConsumed = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_getEnergyMeterInfo = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_readEnergyMeter = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.hardware.power.stats.IPowerStats impl) {
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
    public static android.hardware.power.stats.IPowerStats getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$hardware$power$stats$IPowerStats".replace('$', '.');
  public android.hardware.power.stats.PowerEntity[] getPowerEntityInfo() throws android.os.RemoteException;
  public android.hardware.power.stats.StateResidencyResult[] getStateResidency(int[] powerEntityIds) throws android.os.RemoteException;
  public android.hardware.power.stats.EnergyConsumer[] getEnergyConsumerInfo() throws android.os.RemoteException;
  public android.hardware.power.stats.EnergyConsumerResult[] getEnergyConsumed(int[] energyConsumerIds) throws android.os.RemoteException;
  public android.hardware.power.stats.Channel[] getEnergyMeterInfo() throws android.os.RemoteException;
  public android.hardware.power.stats.EnergyMeasurement[] readEnergyMeter(int[] channelIds) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
