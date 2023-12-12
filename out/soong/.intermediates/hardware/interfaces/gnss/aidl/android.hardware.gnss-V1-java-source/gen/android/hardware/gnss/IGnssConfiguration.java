/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.hardware.gnss;
public interface IGnssConfiguration extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 1;
  public static final String HASH = "10839720b90aaec329521e810d9e0501cfcef0d3";
  /** Default implementation for IGnssConfiguration. */
  public static class Default implements android.hardware.gnss.IGnssConfiguration
  {
    @Override public void setSuplVersion(int version) throws android.os.RemoteException
    {
    }
    @Override public void setSuplMode(int mode) throws android.os.RemoteException
    {
    }
    @Override public void setLppProfile(int lppProfile) throws android.os.RemoteException
    {
    }
    @Override public void setGlonassPositioningProtocol(int protocol) throws android.os.RemoteException
    {
    }
    @Override public void setEmergencySuplPdn(boolean enable) throws android.os.RemoteException
    {
    }
    @Override public void setEsExtensionSec(int emergencyExtensionSeconds) throws android.os.RemoteException
    {
    }
    @Override public void setBlocklist(android.hardware.gnss.BlocklistedSource[] blocklist) throws android.os.RemoteException
    {
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
  public static abstract class Stub extends android.os.Binder implements android.hardware.gnss.IGnssConfiguration
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.markVintfStability();
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.hardware.gnss.IGnssConfiguration interface,
     * generating a proxy if needed.
     */
    public static android.hardware.gnss.IGnssConfiguration asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.hardware.gnss.IGnssConfiguration))) {
        return ((android.hardware.gnss.IGnssConfiguration)iin);
      }
      return new android.hardware.gnss.IGnssConfiguration.Stub.Proxy(obj);
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
        case TRANSACTION_setSuplVersion:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.setSuplVersion(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setSuplMode:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.setSuplMode(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setLppProfile:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.setLppProfile(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setGlonassPositioningProtocol:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.setGlonassPositioningProtocol(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setEmergencySuplPdn:
        {
          data.enforceInterface(descriptor);
          boolean _arg0;
          _arg0 = (0!=data.readInt());
          this.setEmergencySuplPdn(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setEsExtensionSec:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.setEsExtensionSec(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setBlocklist:
        {
          data.enforceInterface(descriptor);
          android.hardware.gnss.BlocklistedSource[] _arg0;
          _arg0 = data.createTypedArray(android.hardware.gnss.BlocklistedSource.CREATOR);
          this.setBlocklist(_arg0);
          reply.writeNoException();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.hardware.gnss.IGnssConfiguration
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
      @Override public void setSuplVersion(int version) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(version);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setSuplVersion, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setSuplVersion(version);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setSuplVersion is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void setSuplMode(int mode) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(mode);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setSuplMode, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setSuplMode(mode);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setSuplMode is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void setLppProfile(int lppProfile) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(lppProfile);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setLppProfile, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setLppProfile(lppProfile);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setLppProfile is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void setGlonassPositioningProtocol(int protocol) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(protocol);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setGlonassPositioningProtocol, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setGlonassPositioningProtocol(protocol);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setGlonassPositioningProtocol is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void setEmergencySuplPdn(boolean enable) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(((enable)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_setEmergencySuplPdn, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setEmergencySuplPdn(enable);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setEmergencySuplPdn is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void setEsExtensionSec(int emergencyExtensionSeconds) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(emergencyExtensionSeconds);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setEsExtensionSec, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setEsExtensionSec(emergencyExtensionSeconds);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setEsExtensionSec is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void setBlocklist(android.hardware.gnss.BlocklistedSource[] blocklist) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeTypedArray(blocklist, 0);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setBlocklist, _data, _reply, 0);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().setBlocklist(blocklist);
              return;
            }
            else {
              throw new android.os.RemoteException("Method setBlocklist is unimplemented.");
            }
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
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
      public static android.hardware.gnss.IGnssConfiguration sDefaultImpl;
    }
    static final int TRANSACTION_setSuplVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_setSuplMode = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_setLppProfile = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_setGlonassPositioningProtocol = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_setEmergencySuplPdn = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_setEsExtensionSec = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_setBlocklist = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.hardware.gnss.IGnssConfiguration impl) {
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
    public static android.hardware.gnss.IGnssConfiguration getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$hardware$gnss$IGnssConfiguration".replace('$', '.');
  public static final int SUPL_MODE_MSB = 1;
  public static final int SUPL_MODE_MSA = 2;
  public static final int LPP_PROFILE_USER_PLANE = 1;
  public static final int LPP_PROFILE_CONTROL_PLANE = 2;
  public static final int GLONASS_POS_PROTOCOL_RRC_CPLANE = 1;
  public static final int GLONASS_POS_PROTOCOL_RRLP_UPLANE = 2;
  public static final int GLONASS_POS_PROTOCOL_LPP_UPLANE = 4;
  public void setSuplVersion(int version) throws android.os.RemoteException;
  public void setSuplMode(int mode) throws android.os.RemoteException;
  public void setLppProfile(int lppProfile) throws android.os.RemoteException;
  public void setGlonassPositioningProtocol(int protocol) throws android.os.RemoteException;
  public void setEmergencySuplPdn(boolean enable) throws android.os.RemoteException;
  public void setEsExtensionSec(int emergencyExtensionSeconds) throws android.os.RemoteException;
  public void setBlocklist(android.hardware.gnss.BlocklistedSource[] blocklist) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
