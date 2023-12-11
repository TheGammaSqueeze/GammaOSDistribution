package android.hardware.gnss.V1_0;

/**
 * GNSS Network Initiated callback interface.
 */
public interface IGnssNiCallback extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.gnss@1.0::IGnssNiCallback";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IGnssNiCallback asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IGnssNiCallback)) {
            return (IGnssNiCallback)iface;
        }

        IGnssNiCallback proxy = new IGnssNiCallback.Proxy(binder);

        try {
            for (String descriptor : proxy.interfaceChain()) {
                if (descriptor.equals(kInterfaceName)) {
                    return proxy;
                }
            }
        } catch (android.os.RemoteException e) {
        }

        return null;
    }

    /**
     * Does a checked conversion from any interface to this class.
     */
    public static IGnssNiCallback castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IGnssNiCallback.asInterface(iface.asBinder());
    }

    @Override
    public android.os.IHwBinder asBinder();

    /**
     * This will invoke the equivalent of the C++ getService(std::string) if retry is
     * true or tryGetService(std::string) if retry is false. If the service is
     * available on the device and retry is true, this will wait for the service to
     * start.
     *
     * @throws NoSuchElementException if this service is not available
     */
    public static IGnssNiCallback getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IGnssNiCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@1.0::IGnssNiCallback", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IGnssNiCallback getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IGnssNiCallback getService(String serviceName) throws android.os.RemoteException {
        return IGnssNiCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@1.0::IGnssNiCallback", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IGnssNiCallback getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * GnssNiType constants
     */
    public static final class GnssNiType {
        public static final byte VOICE = 1;
        public static final byte UMTS_SUPL = 2;
        public static final byte UMTS_CTRL_PLANE = 3;
        public static final byte EMERGENCY_SUPL = 4;
        public static final String toString(byte o) {
            if (o == VOICE) {
                return "VOICE";
            }
            if (o == UMTS_SUPL) {
                return "UMTS_SUPL";
            }
            if (o == UMTS_CTRL_PLANE) {
                return "UMTS_CTRL_PLANE";
            }
            if (o == EMERGENCY_SUPL) {
                return "EMERGENCY_SUPL";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            if ((o & VOICE) == VOICE) {
                list.add("VOICE");
                flipped |= VOICE;
            }
            if ((o & UMTS_SUPL) == UMTS_SUPL) {
                list.add("UMTS_SUPL");
                flipped |= UMTS_SUPL;
            }
            if ((o & UMTS_CTRL_PLANE) == UMTS_CTRL_PLANE) {
                list.add("UMTS_CTRL_PLANE");
                flipped |= UMTS_CTRL_PLANE;
            }
            if ((o & EMERGENCY_SUPL) == EMERGENCY_SUPL) {
                list.add("EMERGENCY_SUPL");
                flipped |= EMERGENCY_SUPL;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * GnssNiNotifyFlags constants
     */
    public static final class GnssNiNotifyFlags {
        /**
         * NI requires notification
         */
        public static final int NEED_NOTIFY = 1 /* 0x0001 */;
        /**
         * NI requires verification
         */
        public static final int NEED_VERIFY = 2 /* 0x0002 */;
        /**
         * NI requires privacy override, no notification/minimal trace
         */
        public static final int PRIVACY_OVERRIDE = 4 /* 0x0004 */;
        public static final String toString(int o) {
            if (o == NEED_NOTIFY) {
                return "NEED_NOTIFY";
            }
            if (o == NEED_VERIFY) {
                return "NEED_VERIFY";
            }
            if (o == PRIVACY_OVERRIDE) {
                return "PRIVACY_OVERRIDE";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & NEED_NOTIFY) == NEED_NOTIFY) {
                list.add("NEED_NOTIFY");
                flipped |= NEED_NOTIFY;
            }
            if ((o & NEED_VERIFY) == NEED_VERIFY) {
                list.add("NEED_VERIFY");
                flipped |= NEED_VERIFY;
            }
            if ((o & PRIVACY_OVERRIDE) == PRIVACY_OVERRIDE) {
                list.add("PRIVACY_OVERRIDE");
                flipped |= PRIVACY_OVERRIDE;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * GNSS NI responses, used to define the response in
     * NI structures
     */
    public static final class GnssUserResponseType {
        public static final byte RESPONSE_ACCEPT = 1;
        public static final byte RESPONSE_DENY = 2;
        public static final byte RESPONSE_NORESP = 3;
        public static final String toString(byte o) {
            if (o == RESPONSE_ACCEPT) {
                return "RESPONSE_ACCEPT";
            }
            if (o == RESPONSE_DENY) {
                return "RESPONSE_DENY";
            }
            if (o == RESPONSE_NORESP) {
                return "RESPONSE_NORESP";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            if ((o & RESPONSE_ACCEPT) == RESPONSE_ACCEPT) {
                list.add("RESPONSE_ACCEPT");
                flipped |= RESPONSE_ACCEPT;
            }
            if ((o & RESPONSE_DENY) == RESPONSE_DENY) {
                list.add("RESPONSE_DENY");
                flipped |= RESPONSE_DENY;
            }
            if ((o & RESPONSE_NORESP) == RESPONSE_NORESP) {
                list.add("RESPONSE_NORESP");
                flipped |= RESPONSE_NORESP;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * NI data encoding scheme
     */
    public static final class GnssNiEncodingType {
        public static final int ENC_NONE = 0;
        public static final int ENC_SUPL_GSM_DEFAULT = 1;
        public static final int ENC_SUPL_UTF8 = 2;
        public static final int ENC_SUPL_UCS2 = 3;
        public static final int ENC_UNKNOWN = -1 /* -1 */;
        public static final String toString(int o) {
            if (o == ENC_NONE) {
                return "ENC_NONE";
            }
            if (o == ENC_SUPL_GSM_DEFAULT) {
                return "ENC_SUPL_GSM_DEFAULT";
            }
            if (o == ENC_SUPL_UTF8) {
                return "ENC_SUPL_UTF8";
            }
            if (o == ENC_SUPL_UCS2) {
                return "ENC_SUPL_UCS2";
            }
            if (o == ENC_UNKNOWN) {
                return "ENC_UNKNOWN";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            list.add("ENC_NONE"); // ENC_NONE == 0
            if ((o & ENC_SUPL_GSM_DEFAULT) == ENC_SUPL_GSM_DEFAULT) {
                list.add("ENC_SUPL_GSM_DEFAULT");
                flipped |= ENC_SUPL_GSM_DEFAULT;
            }
            if ((o & ENC_SUPL_UTF8) == ENC_SUPL_UTF8) {
                list.add("ENC_SUPL_UTF8");
                flipped |= ENC_SUPL_UTF8;
            }
            if ((o & ENC_SUPL_UCS2) == ENC_SUPL_UCS2) {
                list.add("ENC_SUPL_UCS2");
                flipped |= ENC_SUPL_UCS2;
            }
            if ((o & ENC_UNKNOWN) == ENC_UNKNOWN) {
                list.add("ENC_UNKNOWN");
                flipped |= ENC_UNKNOWN;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Represents an NI request
     */
    public final static class GnssNiNotification {
        /**
         * An ID generated by HAL to associate NI notifications and UI
         * responses.
         */
        public int notificationId = 0;
        /**
         * A type used to distinguish different categories of NI
         * events, such as VOICE, UMTS_SUPL etc.
         */
        public byte niType = 0;
        /**
         * Notification/verification options, combinations of GnssNiNotifyFlags
         * constants.
         */
        public int notifyFlags;
        /**
         * Timeout period to wait for user response.
         * Set to 0 for no timeout limit. Specified in seconds.
         */
        public int timeoutSec = 0;
        /**
         * Default response when timeout.
         */
        public byte defaultResponse = 0;
        /**
         * String representing the requester of the network inititated location
         * request.
         */
        public String requestorId = new String();
        /**
         * Notification message. String representing the service(for eg. SUPL-service)
         * who sent the network initiated location request.
         */
        public String notificationMessage = new String();
        /**
         * requestorId decoding scheme.
         */
        public int requestorIdEncoding = 0;
        /**
         * notificationId decoding scheme
         */
        public int notificationIdEncoding = 0;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiNotification.class) {
                return false;
            }
            android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiNotification other = (android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiNotification)otherObject;
            if (this.notificationId != other.notificationId) {
                return false;
            }
            if (this.niType != other.niType) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.notifyFlags, other.notifyFlags)) {
                return false;
            }
            if (this.timeoutSec != other.timeoutSec) {
                return false;
            }
            if (this.defaultResponse != other.defaultResponse) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.requestorId, other.requestorId)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.notificationMessage, other.notificationMessage)) {
                return false;
            }
            if (this.requestorIdEncoding != other.requestorIdEncoding) {
                return false;
            }
            if (this.notificationIdEncoding != other.notificationIdEncoding) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.notificationId), 
                    android.os.HidlSupport.deepHashCode(this.niType), 
                    android.os.HidlSupport.deepHashCode(this.notifyFlags), 
                    android.os.HidlSupport.deepHashCode(this.timeoutSec), 
                    android.os.HidlSupport.deepHashCode(this.defaultResponse), 
                    android.os.HidlSupport.deepHashCode(this.requestorId), 
                    android.os.HidlSupport.deepHashCode(this.notificationMessage), 
                    android.os.HidlSupport.deepHashCode(this.requestorIdEncoding), 
                    android.os.HidlSupport.deepHashCode(this.notificationIdEncoding));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".notificationId = ");
            builder.append(this.notificationId);
            builder.append(", .niType = ");
            builder.append(android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiType.toString(this.niType));
            builder.append(", .notifyFlags = ");
            builder.append(android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiNotifyFlags.dumpBitfield(this.notifyFlags));
            builder.append(", .timeoutSec = ");
            builder.append(this.timeoutSec);
            builder.append(", .defaultResponse = ");
            builder.append(android.hardware.gnss.V1_0.IGnssNiCallback.GnssUserResponseType.toString(this.defaultResponse));
            builder.append(", .requestorId = ");
            builder.append(this.requestorId);
            builder.append(", .notificationMessage = ");
            builder.append(this.notificationMessage);
            builder.append(", .requestorIdEncoding = ");
            builder.append(android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiEncodingType.toString(this.requestorIdEncoding));
            builder.append(", .notificationIdEncoding = ");
            builder.append(android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiEncodingType.toString(this.notificationIdEncoding));
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(64 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssNiNotification> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssNiNotification> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 64,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiNotification _hidl_vec_element = new android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiNotification();
                    ((android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiNotification) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 64);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            notificationId = _hidl_blob.getInt32(_hidl_offset + 0);
            niType = _hidl_blob.getInt8(_hidl_offset + 4);
            notifyFlags = _hidl_blob.getInt32(_hidl_offset + 8);
            timeoutSec = _hidl_blob.getInt32(_hidl_offset + 12);
            defaultResponse = _hidl_blob.getInt8(_hidl_offset + 16);
            requestorId = _hidl_blob.getString(_hidl_offset + 24);

            parcel.readEmbeddedBuffer(
                    ((String) requestorId).getBytes().length + 1,
                    _hidl_blob.handle(),
                    _hidl_offset + 24 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

            notificationMessage = _hidl_blob.getString(_hidl_offset + 40);

            parcel.readEmbeddedBuffer(
                    ((String) notificationMessage).getBytes().length + 1,
                    _hidl_blob.handle(),
                    _hidl_offset + 40 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

            requestorIdEncoding = _hidl_blob.getInt32(_hidl_offset + 56);
            notificationIdEncoding = _hidl_blob.getInt32(_hidl_offset + 60);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(64 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<GnssNiNotification> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 64));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 64);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt32(_hidl_offset + 0, notificationId);
            _hidl_blob.putInt8(_hidl_offset + 4, niType);
            _hidl_blob.putInt32(_hidl_offset + 8, notifyFlags);
            _hidl_blob.putInt32(_hidl_offset + 12, timeoutSec);
            _hidl_blob.putInt8(_hidl_offset + 16, defaultResponse);
            _hidl_blob.putString(_hidl_offset + 24, requestorId);
            _hidl_blob.putString(_hidl_offset + 40, notificationMessage);
            _hidl_blob.putInt32(_hidl_offset + 56, requestorIdEncoding);
            _hidl_blob.putInt32(_hidl_offset + 60, notificationIdEncoding);
        }
    };

    /**
     * Callback with a network initiated request.
     *
     * @param notification network initiated request.
     */
    void niNotifyCb(android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiNotification notification)
        throws android.os.RemoteException;
    /*
     * Provides run-time type information for this object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceChain on an IChild object must yield the following:
     *     ["android.hardware.foo@1.0::IChild",
     *      "android.hardware.foo@1.0::IParent"
     *      "android.hidl.base@1.0::IBase"]
     *
     * @return descriptors a vector of descriptors of the run-time type of the
     *         object.
     */
    java.util.ArrayList<String> interfaceChain()
        throws android.os.RemoteException;
    /*
     * Emit diagnostic information to the given file.
     *
     * Optionally overriden.
     *
     * @param fd      File descriptor to dump data to.
     *                Must only be used for the duration of this call.
     * @param options Arguments for debugging.
     *                Must support empty for default debug information.
     */
    void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options)
        throws android.os.RemoteException;
    /*
     * Provides run-time type information for this object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceDescriptor on an IChild object must yield
     *     "android.hardware.foo@1.0::IChild"
     *
     * @return descriptor a descriptor of the run-time type of the
     *         object (the first element of the vector returned by
     *         interfaceChain())
     */
    String interfaceDescriptor()
        throws android.os.RemoteException;
    /*
     * Returns hashes of the source HAL files that define the interfaces of the
     * runtime type information on the object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceChain on an IChild object must yield the following:
     *     [(hash of IChild.hal),
     *      (hash of IParent.hal)
     *      (hash of IBase.hal)].
     *
     * SHA-256 is used as the hashing algorithm. Each hash has 32 bytes
     * according to SHA-256 standard.
     *
     * @return hashchain a vector of SHA-1 digests
     */
    java.util.ArrayList<byte[/* 32 */]> getHashChain()
        throws android.os.RemoteException;
    /*
     * This method trigger the interface to enable/disable instrumentation based
     * on system property hal.instrumentation.enable.
     */
    void setHALInstrumentation()
        throws android.os.RemoteException;
    /*
     * Registers a death recipient, to be called when the process hosting this
     * interface dies.
     *
     * @param recipient a hidl_death_recipient callback object
     * @param cookie a cookie that must be returned with the callback
     * @return success whether the death recipient was registered successfully.
     */
    boolean linkToDeath(android.os.IHwBinder.DeathRecipient recipient, long cookie)
        throws android.os.RemoteException;
    /*
     * Provides way to determine if interface is running without requesting
     * any functionality.
     */
    void ping()
        throws android.os.RemoteException;
    /*
     * Get debug information on references on this interface.
     * @return info debugging information. See comments of DebugInfo.
     */
    android.hidl.base.V1_0.DebugInfo getDebugInfo()
        throws android.os.RemoteException;
    /*
     * This method notifies the interface that one or more system properties
     * have changed. The default implementation calls
     * (C++)  report_sysprop_change() in libcutils or
     * (Java) android.os.SystemProperties.reportSyspropChanged,
     * which in turn calls a set of registered callbacks (eg to update trace
     * tags).
     */
    void notifySyspropsChanged()
        throws android.os.RemoteException;
    /*
     * Unregisters the registered death recipient. If this service was registered
     * multiple times with the same exact death recipient, this unlinks the most
     * recently registered one.
     *
     * @param recipient a previously registered hidl_death_recipient callback
     * @return success whether the death recipient was unregistered successfully.
     */
    boolean unlinkToDeath(android.os.IHwBinder.DeathRecipient recipient)
        throws android.os.RemoteException;

    public static final class Proxy implements IGnssNiCallback {
        private android.os.IHwBinder mRemote;

        public Proxy(android.os.IHwBinder remote) {
            mRemote = java.util.Objects.requireNonNull(remote);
        }

        @Override
        public android.os.IHwBinder asBinder() {
            return mRemote;
        }

        @Override
        public String toString() {
            try {
                return this.interfaceDescriptor() + "@Proxy";
            } catch (android.os.RemoteException ex) {
                /* ignored; handled below. */
            }
            return "[class or subclass of " + IGnssNiCallback.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::gnss::V1_0::IGnssNiCallback follow.
        @Override
        public void niNotifyCb(android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiNotification notification)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssNiCallback.kInterfaceName);
            ((android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiNotification) notification).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* niNotifyCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hidl::base::V1_0::IBase follow.
        @Override
        public java.util.ArrayList<String> interfaceChain()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256067662 /* interfaceChain */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<String> _hidl_out_descriptors = _hidl_reply.readStringVector();
                return _hidl_out_descriptors;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);
            _hidl_request.writeNativeHandle(fd);
            _hidl_request.writeStringVector(options);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256131655 /* debug */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public String interfaceDescriptor()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256136003 /* interfaceDescriptor */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                String _hidl_out_descriptor = _hidl_reply.readString();
                return _hidl_out_descriptor;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public java.util.ArrayList<byte[/* 32 */]> getHashChain()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256398152 /* getHashChain */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<byte[/* 32 */]> _hidl_out_hashchain =  new java.util.ArrayList<byte[/* 32 */]>();
                {
                    android.os.HwBlob _hidl_blob = _hidl_reply.readBuffer(16 /* size */);
                    {
                        int _hidl_vec_size = _hidl_blob.getInt32(0 /* offset */ + 8 /* offsetof(hidl_vec<T>, mSize) */);
                        android.os.HwBlob childBlob = _hidl_reply.readEmbeddedBuffer(
                                _hidl_vec_size * 32,_hidl_blob.handle(),
                                0 /* offset */ + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                        ((java.util.ArrayList<byte[/* 32 */]>) _hidl_out_hashchain).clear();
                        for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                            byte[/* 32 */] _hidl_vec_element = new byte[32];
                            {
                                long _hidl_array_offset_1 = _hidl_index_0 * 32;
                                childBlob.copyToInt8Array(_hidl_array_offset_1, (byte[/* 32 */]) _hidl_vec_element, 32 /* size */);
                                _hidl_array_offset_1 += 32 * 1;
                            }
                            ((java.util.ArrayList<byte[/* 32 */]>) _hidl_out_hashchain).add(_hidl_vec_element);
                        }
                    }
                }
                return _hidl_out_hashchain;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setHALInstrumentation()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256462420 /* setHALInstrumentation */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean linkToDeath(android.os.IHwBinder.DeathRecipient recipient, long cookie)
                throws android.os.RemoteException {
            return mRemote.linkToDeath(recipient, cookie);
        }
        @Override
        public void ping()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256921159 /* ping */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hidl.base.V1_0.DebugInfo getDebugInfo()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(257049926 /* getDebugInfo */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hidl.base.V1_0.DebugInfo _hidl_out_info = new android.hidl.base.V1_0.DebugInfo();
                ((android.hidl.base.V1_0.DebugInfo) _hidl_out_info).readFromParcel(_hidl_reply);
                return _hidl_out_info;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifySyspropsChanged()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(257120595 /* notifySyspropsChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean unlinkToDeath(android.os.IHwBinder.DeathRecipient recipient)
                throws android.os.RemoteException {
            return mRemote.unlinkToDeath(recipient);
        }
    }

    public static abstract class Stub extends android.os.HwBinder implements IGnssNiCallback {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.gnss.V1_0.IGnssNiCallback.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.gnss.V1_0.IGnssNiCallback.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-57,-127,-73,-79,37,-10,-117,-27,-37,-118,-116,61,65,45,82,106,-51,-67,-9,125,-52,89,42,76,14,-41,11,-116,-28,-2,108,73} /* c781b7b125f68be5db8a8c3d412d526acdbdf77dcc592a4c0ed70b8ce4fe6c49 */,
                    new byte[/* 32 */]{-20,127,-41,-98,-48,45,-6,-123,-68,73,-108,38,-83,-82,62,-66,35,-17,5,36,-13,-51,105,87,19,-109,36,-72,59,24,-54,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */));

        }

        @Override
        public final void setHALInstrumentation() {

        }

        @Override
        public final boolean linkToDeath(android.os.IHwBinder.DeathRecipient recipient, long cookie) {
            return true;

        }

        @Override
        public final void ping() {
            return;

        }

        @Override
        public final android.hidl.base.V1_0.DebugInfo getDebugInfo() {
            android.hidl.base.V1_0.DebugInfo info = new android.hidl.base.V1_0.DebugInfo();
            info.pid = android.os.HidlSupport.getPidIfSharable();
            info.ptr = 0;
            info.arch = android.hidl.base.V1_0.DebugInfo.Architecture.UNKNOWN;
            return info;

        }

        @Override
        public final void notifySyspropsChanged() {
            android.os.HwBinder.enableInstrumentation();

        }

        @Override
        public final boolean unlinkToDeath(android.os.IHwBinder.DeathRecipient recipient) {
            return true;

        }

        @Override
        public android.os.IHwInterface queryLocalInterface(String descriptor) {
            if (kInterfaceName.equals(descriptor)) {
                return this;
            }
            return null;
        }

        public void registerAsService(String serviceName) throws android.os.RemoteException {
            registerService(serviceName);
        }

        @Override
        public String toString() {
            return this.interfaceDescriptor() + "@Stub";
        }

        @Override
        public void onTransact(int _hidl_code, android.os.HwParcel _hidl_request, final android.os.HwParcel _hidl_reply, int _hidl_flags)
                throws android.os.RemoteException {
            switch (_hidl_code) {
                case 1 /* niNotifyCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssNiCallback.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiNotification notification = new android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiNotification();
                    ((android.hardware.gnss.V1_0.IGnssNiCallback.GnssNiNotification) notification).readFromParcel(_hidl_request);
                    niNotifyCb(notification);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 256067662 /* interfaceChain */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    java.util.ArrayList<String> _hidl_out_descriptors = interfaceChain();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStringVector(_hidl_out_descriptors);
                    _hidl_reply.send();
                    break;
                }

                case 256131655 /* debug */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    android.os.NativeHandle fd = _hidl_request.readNativeHandle();
                    java.util.ArrayList<String> options = _hidl_request.readStringVector();
                    debug(fd, options);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 256136003 /* interfaceDescriptor */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    String _hidl_out_descriptor = interfaceDescriptor();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeString(_hidl_out_descriptor);
                    _hidl_reply.send();
                    break;
                }

                case 256398152 /* getHashChain */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    java.util.ArrayList<byte[/* 32 */]> _hidl_out_hashchain = getHashChain();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    {
                        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* size */);
                        {
                            int _hidl_vec_size = _hidl_out_hashchain.size();
                            _hidl_blob.putInt32(0 /* offset */ + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                            _hidl_blob.putBool(0 /* offset */ + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
                            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                                {
                                    long _hidl_array_offset_1 = _hidl_index_0 * 32;
                                    byte[] _hidl_array_item_1 = (byte[/* 32 */]) _hidl_out_hashchain.get(_hidl_index_0);

                                    if (_hidl_array_item_1 == null || _hidl_array_item_1.length != 32) {
                                        throw new IllegalArgumentException("Array element is not of the expected length");
                                    }

                                    childBlob.putInt8Array(_hidl_array_offset_1, _hidl_array_item_1);
                                    _hidl_array_offset_1 += 32 * 1;
                                }
                            }
                            _hidl_blob.putBlob(0 /* offset */ + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
                        }
                        _hidl_reply.writeBuffer(_hidl_blob);
                    }
                    _hidl_reply.send();
                    break;
                }

                case 256462420 /* setHALInstrumentation */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    setHALInstrumentation();
                    break;
                }

                case 256660548 /* linkToDeath */:
                {
                break;
                }

                case 256921159 /* ping */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    ping();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 257049926 /* getDebugInfo */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    android.hidl.base.V1_0.DebugInfo _hidl_out_info = getDebugInfo();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hidl.base.V1_0.DebugInfo) _hidl_out_info).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 257120595 /* notifySyspropsChanged */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    notifySyspropsChanged();
                    break;
                }

                case 257250372 /* unlinkToDeath */:
                {
                break;
                }

            }
        }
    }
}
