package android.hardware.gnss.visibility_control.V1_0;

/**
 * GNSS location reporting permissions and notification callback interface.
 */
public interface IGnssVisibilityControlCallback extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.gnss.visibility_control@1.0::IGnssVisibilityControlCallback";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IGnssVisibilityControlCallback asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IGnssVisibilityControlCallback)) {
            return (IGnssVisibilityControlCallback)iface;
        }

        IGnssVisibilityControlCallback proxy = new IGnssVisibilityControlCallback.Proxy(binder);

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
    public static IGnssVisibilityControlCallback castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IGnssVisibilityControlCallback.asInterface(iface.asBinder());
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
    public static IGnssVisibilityControlCallback getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IGnssVisibilityControlCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss.visibility_control@1.0::IGnssVisibilityControlCallback", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IGnssVisibilityControlCallback getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IGnssVisibilityControlCallback getService(String serviceName) throws android.os.RemoteException {
        return IGnssVisibilityControlCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss.visibility_control@1.0::IGnssVisibilityControlCallback", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IGnssVisibilityControlCallback getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Protocol stack that is requesting the non-framework location information.
     */
    public static final class NfwProtocolStack {
        /**
         * Cellular control plane requests
         */
        public static final byte CTRL_PLANE = 0;
        /**
         * All types of SUPL requests
         */
        public static final byte SUPL = 1;
        /**
         * All types of requests from IMS
         */
        public static final byte IMS = 10;
        /**
         * All types of requests from SIM
         */
        public static final byte SIM = 11;
        /**
         * Requests from other protocol stacks
         */
        public static final byte OTHER_PROTOCOL_STACK = 100;
        public static final String toString(byte o) {
            if (o == CTRL_PLANE) {
                return "CTRL_PLANE";
            }
            if (o == SUPL) {
                return "SUPL";
            }
            if (o == IMS) {
                return "IMS";
            }
            if (o == SIM) {
                return "SIM";
            }
            if (o == OTHER_PROTOCOL_STACK) {
                return "OTHER_PROTOCOL_STACK";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("CTRL_PLANE"); // CTRL_PLANE == 0
            if ((o & SUPL) == SUPL) {
                list.add("SUPL");
                flipped |= SUPL;
            }
            if ((o & IMS) == IMS) {
                list.add("IMS");
                flipped |= IMS;
            }
            if ((o & SIM) == SIM) {
                list.add("SIM");
                flipped |= SIM;
            }
            if ((o & OTHER_PROTOCOL_STACK) == OTHER_PROTOCOL_STACK) {
                list.add("OTHER_PROTOCOL_STACK");
                flipped |= OTHER_PROTOCOL_STACK;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /*
     * Entity that is requesting/receiving the location information.
     */
    public static final class NfwRequestor {
        /**
         * Wireless service provider
         */
        public static final byte CARRIER = 0;
        /**
         * Device manufacturer
         */
        public static final byte OEM = 10;
        /**
         * Modem chipset vendor
         */
        public static final byte MODEM_CHIPSET_VENDOR = 11;
        /**
         * GNSS chipset vendor
         */
        public static final byte GNSS_CHIPSET_VENDOR = 12;
        /**
         * Other chipset vendor
         */
        public static final byte OTHER_CHIPSET_VENDOR = 13;
        /**
         * Automobile client
         */
        public static final byte AUTOMOBILE_CLIENT = 20;
        /**
         * Other sources
         */
        public static final byte OTHER_REQUESTOR = 100;
        public static final String toString(byte o) {
            if (o == CARRIER) {
                return "CARRIER";
            }
            if (o == OEM) {
                return "OEM";
            }
            if (o == MODEM_CHIPSET_VENDOR) {
                return "MODEM_CHIPSET_VENDOR";
            }
            if (o == GNSS_CHIPSET_VENDOR) {
                return "GNSS_CHIPSET_VENDOR";
            }
            if (o == OTHER_CHIPSET_VENDOR) {
                return "OTHER_CHIPSET_VENDOR";
            }
            if (o == AUTOMOBILE_CLIENT) {
                return "AUTOMOBILE_CLIENT";
            }
            if (o == OTHER_REQUESTOR) {
                return "OTHER_REQUESTOR";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("CARRIER"); // CARRIER == 0
            if ((o & OEM) == OEM) {
                list.add("OEM");
                flipped |= OEM;
            }
            if ((o & MODEM_CHIPSET_VENDOR) == MODEM_CHIPSET_VENDOR) {
                list.add("MODEM_CHIPSET_VENDOR");
                flipped |= MODEM_CHIPSET_VENDOR;
            }
            if ((o & GNSS_CHIPSET_VENDOR) == GNSS_CHIPSET_VENDOR) {
                list.add("GNSS_CHIPSET_VENDOR");
                flipped |= GNSS_CHIPSET_VENDOR;
            }
            if ((o & OTHER_CHIPSET_VENDOR) == OTHER_CHIPSET_VENDOR) {
                list.add("OTHER_CHIPSET_VENDOR");
                flipped |= OTHER_CHIPSET_VENDOR;
            }
            if ((o & AUTOMOBILE_CLIENT) == AUTOMOBILE_CLIENT) {
                list.add("AUTOMOBILE_CLIENT");
                flipped |= AUTOMOBILE_CLIENT;
            }
            if ((o & OTHER_REQUESTOR) == OTHER_REQUESTOR) {
                list.add("OTHER_REQUESTOR");
                flipped |= OTHER_REQUESTOR;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * GNSS response type for non-framework location requests.
     */
    public static final class NfwResponseType {
        /**
         * Request rejected because framework has not given permission for this use case
         */
        public static final byte REJECTED = 0;
        /**
         * Request accepted but could not provide location because of a failure
         */
        public static final byte ACCEPTED_NO_LOCATION_PROVIDED = 1;
        /**
         * Request accepted and location provided
         */
        public static final byte ACCEPTED_LOCATION_PROVIDED = 2;
        public static final String toString(byte o) {
            if (o == REJECTED) {
                return "REJECTED";
            }
            if (o == ACCEPTED_NO_LOCATION_PROVIDED) {
                return "ACCEPTED_NO_LOCATION_PROVIDED";
            }
            if (o == ACCEPTED_LOCATION_PROVIDED) {
                return "ACCEPTED_LOCATION_PROVIDED";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("REJECTED"); // REJECTED == 0
            if ((o & ACCEPTED_NO_LOCATION_PROVIDED) == ACCEPTED_NO_LOCATION_PROVIDED) {
                list.add("ACCEPTED_NO_LOCATION_PROVIDED");
                flipped |= ACCEPTED_NO_LOCATION_PROVIDED;
            }
            if ((o & ACCEPTED_LOCATION_PROVIDED) == ACCEPTED_LOCATION_PROVIDED) {
                list.add("ACCEPTED_LOCATION_PROVIDED");
                flipped |= ACCEPTED_LOCATION_PROVIDED;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Represents a non-framework location information request/response notification.
     */
    public final static class NfwNotification {
        /**
         * Package name of the Android proxy application representing the non-framework
         * entity that requested location. Set to empty string if unknown.
         *
         * For user-initiated emergency use cases, this field must be set to empty string
         * and the inEmergencyMode field must be set to true.
         */
        public String proxyAppPackageName = new String();
        /**
         * Protocol stack that initiated the non-framework location request.
         */
        public byte protocolStack = 0;
        /**
         * Name of the protocol stack if protocolStack field is set to OTHER_PROTOCOL_STACK.
         * Otherwise, set to empty string.
         *
         * This field is opaque to the framework and used for logging purposes.
         */
        public String otherProtocolStackName = new String();
        /**
         * Source initiating/receiving the location information.
         */
        public byte requestor = 0;
        /**
         * Identity of the endpoint receiving the location information. For example, carrier
         * name, OEM name, SUPL SLP/E-SLP FQDN, chipset vendor name, etc.
         *
         * This field is opaque to the framework and used for logging purposes.
         */
        public String requestorId = new String();
        /**
         * Indicates whether location information was provided for this request.
         */
        public byte responseType = 0;
        /**
         * Is the device in user initiated emergency session.
         */
        public boolean inEmergencyMode = false;
        /**
         * Is cached location provided
         */
        public boolean isCachedLocation = false;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwNotification.class) {
                return false;
            }
            android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwNotification other = (android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwNotification)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.proxyAppPackageName, other.proxyAppPackageName)) {
                return false;
            }
            if (this.protocolStack != other.protocolStack) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.otherProtocolStackName, other.otherProtocolStackName)) {
                return false;
            }
            if (this.requestor != other.requestor) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.requestorId, other.requestorId)) {
                return false;
            }
            if (this.responseType != other.responseType) {
                return false;
            }
            if (this.inEmergencyMode != other.inEmergencyMode) {
                return false;
            }
            if (this.isCachedLocation != other.isCachedLocation) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.proxyAppPackageName), 
                    android.os.HidlSupport.deepHashCode(this.protocolStack), 
                    android.os.HidlSupport.deepHashCode(this.otherProtocolStackName), 
                    android.os.HidlSupport.deepHashCode(this.requestor), 
                    android.os.HidlSupport.deepHashCode(this.requestorId), 
                    android.os.HidlSupport.deepHashCode(this.responseType), 
                    android.os.HidlSupport.deepHashCode(this.inEmergencyMode), 
                    android.os.HidlSupport.deepHashCode(this.isCachedLocation));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".proxyAppPackageName = ");
            builder.append(this.proxyAppPackageName);
            builder.append(", .protocolStack = ");
            builder.append(android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwProtocolStack.toString(this.protocolStack));
            builder.append(", .otherProtocolStackName = ");
            builder.append(this.otherProtocolStackName);
            builder.append(", .requestor = ");
            builder.append(android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwRequestor.toString(this.requestor));
            builder.append(", .requestorId = ");
            builder.append(this.requestorId);
            builder.append(", .responseType = ");
            builder.append(android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwResponseType.toString(this.responseType));
            builder.append(", .inEmergencyMode = ");
            builder.append(this.inEmergencyMode);
            builder.append(", .isCachedLocation = ");
            builder.append(this.isCachedLocation);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(72 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<NfwNotification> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<NfwNotification> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 72,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwNotification _hidl_vec_element = new android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwNotification();
                    ((android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwNotification) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 72);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            proxyAppPackageName = _hidl_blob.getString(_hidl_offset + 0);

            parcel.readEmbeddedBuffer(
                    ((String) proxyAppPackageName).getBytes().length + 1,
                    _hidl_blob.handle(),
                    _hidl_offset + 0 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

            protocolStack = _hidl_blob.getInt8(_hidl_offset + 16);
            otherProtocolStackName = _hidl_blob.getString(_hidl_offset + 24);

            parcel.readEmbeddedBuffer(
                    ((String) otherProtocolStackName).getBytes().length + 1,
                    _hidl_blob.handle(),
                    _hidl_offset + 24 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

            requestor = _hidl_blob.getInt8(_hidl_offset + 40);
            requestorId = _hidl_blob.getString(_hidl_offset + 48);

            parcel.readEmbeddedBuffer(
                    ((String) requestorId).getBytes().length + 1,
                    _hidl_blob.handle(),
                    _hidl_offset + 48 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

            responseType = _hidl_blob.getInt8(_hidl_offset + 64);
            inEmergencyMode = _hidl_blob.getBool(_hidl_offset + 65);
            isCachedLocation = _hidl_blob.getBool(_hidl_offset + 66);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(72 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<NfwNotification> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 72));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 72);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putString(_hidl_offset + 0, proxyAppPackageName);
            _hidl_blob.putInt8(_hidl_offset + 16, protocolStack);
            _hidl_blob.putString(_hidl_offset + 24, otherProtocolStackName);
            _hidl_blob.putInt8(_hidl_offset + 40, requestor);
            _hidl_blob.putString(_hidl_offset + 48, requestorId);
            _hidl_blob.putInt8(_hidl_offset + 64, responseType);
            _hidl_blob.putBool(_hidl_offset + 65, inEmergencyMode);
            _hidl_blob.putBool(_hidl_offset + 66, isCachedLocation);
        }
    };

    /**
     * Callback to report a non-framework delivered location.
     *
     * The GNSS HAL implementation must call this method to notify the framework whenever
     * a non-framework location request is made to the GNSS HAL.
     *
     * Non-framework entities like low power sensor hubs that request location from GNSS and
     * only pass location information through Android framework controls are exempt from this
     * power-spending reporting. However, low power sensor hubs or other chipsets which may send
     * the location information to anywhere other than Android framework (which provides user
     * visibility and control), must report location information use through this API whenever
     * location information (or events driven by that location such as "home" location detection)
     * leaves the domain of that low power chipset.
     *
     * To avoid overly spamming the framework, high speed location reporting of the exact same
     * type may be throttled to report location at a lower rate than the actual report rate, as
     * long as the location is reported with a latency of no more than the larger of 5 seconds,
     * or the next the Android processor awake time. For example, if an Automotive client is
     * getting location information from the GNSS location system at 20Hz, this method may be
     * called at 1Hz. As another example, if a low power processor is getting location from the
     * GNSS chipset, and the Android processor is asleep, the notification to the Android HAL may
     * be delayed until the next wake of the Android processor.
     *
     * @param notification Non-framework delivered location request/response description.
     */
    void nfwNotifyCb(android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwNotification notification)
        throws android.os.RemoteException;
    /**
     * Tells if the device is currently in an emergency session.
     *
     * Emergency session is defined as the device being actively in a user initiated emergency
     * call or in post emergency call extension time period.
     *
     * If the GNSS HAL implementation cannot determine if the device is in emergency session
     * mode, it must call this method to confirm that the device is in emergency session before
     * serving network initiated emergency SUPL and Control Plane location requests.
     *
     * @return success True if the framework determines that the device is in emergency session.
     */
    boolean isInEmergencySession()
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

    public static final class Proxy implements IGnssVisibilityControlCallback {
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
            return "[class or subclass of " + IGnssVisibilityControlCallback.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback follow.
        @Override
        public void nfwNotifyCb(android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwNotification notification)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.kInterfaceName);
            ((android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwNotification) notification).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* nfwNotifyCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean isInEmergencySession()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* isInEmergencySession */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
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

    public static abstract class Stub extends android.os.HwBinder implements IGnssVisibilityControlCallback {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{51,-90,-78,12,67,-81,0,-3,-5,48,93,-8,-111,-68,89,17,-64,109,-102,-111,48,-71,18,117,-106,73,-109,46,90,74,110,109} /* 33a6b20c43af00fdfb305df891bc5911c06d9a9130b912759649932e5a4a6e6d */,
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
                case 1 /* nfwNotifyCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.kInterfaceName);

                    android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwNotification notification = new android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwNotification();
                    ((android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.NfwNotification) notification).readFromParcel(_hidl_request);
                    nfwNotifyCb(notification);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 2 /* isInEmergencySession */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControlCallback.kInterfaceName);

                    boolean _hidl_out_success = isInEmergencySession();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
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
