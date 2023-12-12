/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net.resolv.aidl;
/** @hide */
public interface IDnsResolverUnsolicitedEventListener extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 9;
  public static final String HASH = "882638dc86e8afd0924ecf7c28db6cce572f7e7d";
  /** Default implementation for IDnsResolverUnsolicitedEventListener. */
  public static class Default implements android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener
  {
    @Override public void onDnsHealthEvent(android.net.resolv.aidl.DnsHealthEventParcel dnsHealthEvent) throws android.os.RemoteException
    {
    }
    @Override public void onNat64PrefixEvent(android.net.resolv.aidl.Nat64PrefixEventParcel nat64PrefixEvent) throws android.os.RemoteException
    {
    }
    @Override public void onPrivateDnsValidationEvent(android.net.resolv.aidl.PrivateDnsValidationEventParcel privateDnsValidationEvent) throws android.os.RemoteException
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
  public static abstract class Stub extends android.os.Binder implements android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener interface,
     * generating a proxy if needed.
     */
    public static android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener))) {
        return ((android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener)iin);
      }
      return new android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener.Stub.Proxy(obj);
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
        case TRANSACTION_onDnsHealthEvent:
        {
          data.enforceInterface(descriptor);
          android.net.resolv.aidl.DnsHealthEventParcel _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.resolv.aidl.DnsHealthEventParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.onDnsHealthEvent(_arg0);
          return true;
        }
        case TRANSACTION_onNat64PrefixEvent:
        {
          data.enforceInterface(descriptor);
          android.net.resolv.aidl.Nat64PrefixEventParcel _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.resolv.aidl.Nat64PrefixEventParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.onNat64PrefixEvent(_arg0);
          return true;
        }
        case TRANSACTION_onPrivateDnsValidationEvent:
        {
          data.enforceInterface(descriptor);
          android.net.resolv.aidl.PrivateDnsValidationEventParcel _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.net.resolv.aidl.PrivateDnsValidationEventParcel.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.onPrivateDnsValidationEvent(_arg0);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener
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
      @Override public void onDnsHealthEvent(android.net.resolv.aidl.DnsHealthEventParcel dnsHealthEvent) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((dnsHealthEvent!=null)) {
            _data.writeInt(1);
            dnsHealthEvent.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_onDnsHealthEvent, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onDnsHealthEvent(dnsHealthEvent);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onDnsHealthEvent is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onNat64PrefixEvent(android.net.resolv.aidl.Nat64PrefixEventParcel nat64PrefixEvent) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((nat64PrefixEvent!=null)) {
            _data.writeInt(1);
            nat64PrefixEvent.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_onNat64PrefixEvent, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onNat64PrefixEvent(nat64PrefixEvent);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onNat64PrefixEvent is unimplemented.");
            }
          }
        }
        finally {
          _data.recycle();
        }
      }
      @Override public void onPrivateDnsValidationEvent(android.net.resolv.aidl.PrivateDnsValidationEventParcel privateDnsValidationEvent) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((privateDnsValidationEvent!=null)) {
            _data.writeInt(1);
            privateDnsValidationEvent.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_onPrivateDnsValidationEvent, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status) {
            if (getDefaultImpl() != null) {
              getDefaultImpl().onPrivateDnsValidationEvent(privateDnsValidationEvent);
              return;
            }
            else {
              throw new android.os.RemoteException("Method onPrivateDnsValidationEvent is unimplemented.");
            }
          }
        }
        finally {
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
      public static android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener sDefaultImpl;
    }
    static final int TRANSACTION_onDnsHealthEvent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_onNat64PrefixEvent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_onPrivateDnsValidationEvent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
    public static boolean setDefaultImpl(android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener impl) {
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
    public static android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public static final java.lang.String DESCRIPTOR = "android$net$resolv$aidl$IDnsResolverUnsolicitedEventListener".replace('$', '.');
  public static final int DNS_HEALTH_RESULT_OK = 0;
  public static final int DNS_HEALTH_RESULT_TIMEOUT = 255;
  public static final int PREFIX_OPERATION_ADDED = 1;
  public static final int PREFIX_OPERATION_REMOVED = 2;
  public static final int VALIDATION_RESULT_SUCCESS = 1;
  public static final int VALIDATION_RESULT_FAILURE = 2;
  public void onDnsHealthEvent(android.net.resolv.aidl.DnsHealthEventParcel dnsHealthEvent) throws android.os.RemoteException;
  public void onNat64PrefixEvent(android.net.resolv.aidl.Nat64PrefixEventParcel nat64PrefixEvent) throws android.os.RemoteException;
  public void onPrivateDnsValidationEvent(android.net.resolv.aidl.PrivateDnsValidationEventParcel privateDnsValidationEvent) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
