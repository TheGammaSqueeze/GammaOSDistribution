package android.hardware.gnss.V2_0;

/**
 * This interface is required for the HAL to communicate certain information
 * like status and location info back to the platform, the platform implements
 * the interfaces and passes a handle to the HAL.
 */
public interface IGnssCallback extends android.hardware.gnss.V1_1.IGnssCallback {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.gnss@2.0::IGnssCallback";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IGnssCallback asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IGnssCallback)) {
            return (IGnssCallback)iface;
        }

        IGnssCallback proxy = new IGnssCallback.Proxy(binder);

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
    public static IGnssCallback castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IGnssCallback.asInterface(iface.asBinder());
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
    public static IGnssCallback getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IGnssCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@2.0::IGnssCallback", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IGnssCallback getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IGnssCallback getService(String serviceName) throws android.os.RemoteException {
        return IGnssCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@2.0::IGnssCallback", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IGnssCallback getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Flags for the gnssSetCapabilities callback.
     */
    public static final class Capabilities {
        /**
         * GNSS HAL schedules fixes for RECURRENCE_PERIODIC mode.
         * If this is not set, then the framework will use 1000ms for
         * minInterval and will call start() and stop() to schedule the GNSS.
         */
        public static final int SCHEDULING = 1 /* 1 << 0 */;
        /**
         * GNSS supports MS-Based AGNSS mode
         */
        public static final int MSB = 2 /* 1 << 1 */;
        /**
         * GNSS supports MS-Assisted AGNSS mode
         */
        public static final int MSA = 4 /* 1 << 2 */;
        /**
         * GNSS supports single-shot fixes
         */
        public static final int SINGLE_SHOT = 8 /* 1 << 3 */;
        /**
         * GNSS supports on demand time injection
         */
        public static final int ON_DEMAND_TIME = 16 /* 1 << 4 */;
        /**
         * GNSS supports Geofencing
         */
        public static final int GEOFENCING = 32 /* 1 << 5 */;
        /**
         * GNSS supports Measurements for at least GPS.
         */
        public static final int MEASUREMENTS = 64 /* 1 << 6 */;
        /**
         * GNSS supports Navigation Messages
         */
        public static final int NAV_MESSAGES = 128 /* 1 << 7 */;
        /**
         * GNSS supports low power mode
         */
        public static final int LOW_POWER_MODE = 256 /* 1 << 8 */;
        /**
         * GNSS supports blacklisting satellites
         */
        public static final int SATELLITE_BLACKLIST = 512 /* 1 << 9 */;
        /**
         * GNSS supports measurement corrections
         */
        public static final int MEASUREMENT_CORRECTIONS = 1024 /* 1 << 10 */;
        public static final String toString(int o) {
            if (o == SCHEDULING) {
                return "SCHEDULING";
            }
            if (o == MSB) {
                return "MSB";
            }
            if (o == MSA) {
                return "MSA";
            }
            if (o == SINGLE_SHOT) {
                return "SINGLE_SHOT";
            }
            if (o == ON_DEMAND_TIME) {
                return "ON_DEMAND_TIME";
            }
            if (o == GEOFENCING) {
                return "GEOFENCING";
            }
            if (o == MEASUREMENTS) {
                return "MEASUREMENTS";
            }
            if (o == NAV_MESSAGES) {
                return "NAV_MESSAGES";
            }
            if (o == LOW_POWER_MODE) {
                return "LOW_POWER_MODE";
            }
            if (o == SATELLITE_BLACKLIST) {
                return "SATELLITE_BLACKLIST";
            }
            if (o == MEASUREMENT_CORRECTIONS) {
                return "MEASUREMENT_CORRECTIONS";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & SCHEDULING) == SCHEDULING) {
                list.add("SCHEDULING");
                flipped |= SCHEDULING;
            }
            if ((o & MSB) == MSB) {
                list.add("MSB");
                flipped |= MSB;
            }
            if ((o & MSA) == MSA) {
                list.add("MSA");
                flipped |= MSA;
            }
            if ((o & SINGLE_SHOT) == SINGLE_SHOT) {
                list.add("SINGLE_SHOT");
                flipped |= SINGLE_SHOT;
            }
            if ((o & ON_DEMAND_TIME) == ON_DEMAND_TIME) {
                list.add("ON_DEMAND_TIME");
                flipped |= ON_DEMAND_TIME;
            }
            if ((o & GEOFENCING) == GEOFENCING) {
                list.add("GEOFENCING");
                flipped |= GEOFENCING;
            }
            if ((o & MEASUREMENTS) == MEASUREMENTS) {
                list.add("MEASUREMENTS");
                flipped |= MEASUREMENTS;
            }
            if ((o & NAV_MESSAGES) == NAV_MESSAGES) {
                list.add("NAV_MESSAGES");
                flipped |= NAV_MESSAGES;
            }
            if ((o & LOW_POWER_MODE) == LOW_POWER_MODE) {
                list.add("LOW_POWER_MODE");
                flipped |= LOW_POWER_MODE;
            }
            if ((o & SATELLITE_BLACKLIST) == SATELLITE_BLACKLIST) {
                list.add("SATELLITE_BLACKLIST");
                flipped |= SATELLITE_BLACKLIST;
            }
            if ((o & MEASUREMENT_CORRECTIONS) == MEASUREMENT_CORRECTIONS) {
                list.add("MEASUREMENT_CORRECTIONS");
                flipped |= MEASUREMENT_CORRECTIONS;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Extends a GnssSvInfo, replacing the GnssConstellationType.
     */
    public final static class GnssSvInfo {
        /**
         * GNSS satellite information for a single satellite and frequency.
         *
         * In this version of the HAL, the field 'constellation' in the v1_0 struct is deprecated,
         * and is no longer used by the framework. The constellation type is instead reported in
         * @2.0::IGnssCallback.GnssSvInfo.constellation.
         */
        public android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo v1_0 = new android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo();
        /**
         * Defines the constellation of the given SV.
         */
        public byte constellation = 0;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V2_0.IGnssCallback.GnssSvInfo.class) {
                return false;
            }
            android.hardware.gnss.V2_0.IGnssCallback.GnssSvInfo other = (android.hardware.gnss.V2_0.IGnssCallback.GnssSvInfo)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.v1_0, other.v1_0)) {
                return false;
            }
            if (this.constellation != other.constellation) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.v1_0), 
                    android.os.HidlSupport.deepHashCode(this.constellation));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".v1_0 = ");
            builder.append(this.v1_0);
            builder.append(", .constellation = ");
            builder.append(android.hardware.gnss.V2_0.GnssConstellationType.toString(this.constellation));
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(28 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssSvInfo> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssSvInfo> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 28,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_0.IGnssCallback.GnssSvInfo _hidl_vec_element = new android.hardware.gnss.V2_0.IGnssCallback.GnssSvInfo();
                    ((android.hardware.gnss.V2_0.IGnssCallback.GnssSvInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 28);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            ((android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo) v1_0).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
            constellation = _hidl_blob.getInt8(_hidl_offset + 24);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(28 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<GnssSvInfo> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 28));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 28);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            v1_0.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
            _hidl_blob.putInt8(_hidl_offset + 24, constellation);
        }
    };

    /**
     * Callback to inform framework of the GNSS HAL implementation's capabilities.
     *
     * @param capabilities Capability parameter is a bit field of the Capabilities enum.
     */
    void gnssSetCapabilitiesCb_2_0(int capabilities)
        throws android.os.RemoteException;
    /**
     * Called when a GNSS location is available.
     *
     * @param location Location information from HAL.
     */
    void gnssLocationCb_2_0(android.hardware.gnss.V2_0.GnssLocation location)
        throws android.os.RemoteException;
    /**
     * Callback for requesting Location.
     *
     * HAL implementation must call this when it wants the framework to provide locations to assist
     * with GNSS HAL operation, for example, to assist with time to first fix, error recovery, or to
     * supplement GNSS location for other clients of the GNSS HAL.
     *
     * If a request is made with independentFromGnss set to true, the framework must avoid
     * providing locations derived from GNSS locations (such as "fused" location), to help improve
     * information independence for situations such as error recovery.
     *
     * In response to this method call, GNSS HAL can expect zero, one, or more calls to
     * IGnss::injectLocation or IGnss::injectBestLocation, dependent on availability of location
     * from other sources, which may happen at some arbitrary delay. Generally speaking, HAL
     * implementations must be able to handle calls to IGnss::injectLocation or
     * IGnss::injectBestLocation at any time.
     *
     * @param independentFromGnss True if requesting a location that is independent from GNSS.
     * @param isUserEmergency True if the location request is for delivery of this location to an
     *        emergency services endpoint, during a user-initiated emergency session (e.g.
     *        during-call to E911, or up to 5 minutes after end-of-call or text to E911).
     */
    void gnssRequestLocationCb_2_0(boolean independentFromGnss, boolean isUserEmergency)
        throws android.os.RemoteException;
    /**
     * Callback for the HAL to pass a vector of GnssSvInfo back to the client.
     *
     * @param svInfo SV status information from HAL.
     */
    void gnssSvStatusCb_2_0(java.util.ArrayList<android.hardware.gnss.V2_0.IGnssCallback.GnssSvInfo> svInfoList)
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

    public static final class Proxy implements IGnssCallback {
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
            return "[class or subclass of " + IGnssCallback.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::gnss::V1_0::IGnssCallback follow.
        @Override
        public void gnssLocationCb(android.hardware.gnss.V1_0.GnssLocation location)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);
            ((android.hardware.gnss.V1_0.GnssLocation) location).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* gnssLocationCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssStatusCb(byte status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);
            _hidl_request.writeInt8(status);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* gnssStatusCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssSvStatusCb(android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus svInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);
            ((android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus) svInfo).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* gnssSvStatusCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssNmeaCb(long timestamp, String nmea)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);
            _hidl_request.writeInt64(timestamp);
            _hidl_request.writeString(nmea);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* gnssNmeaCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssSetCapabilitesCb(int capabilities)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);
            _hidl_request.writeInt32(capabilities);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* gnssSetCapabilitesCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssAcquireWakelockCb()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* gnssAcquireWakelockCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssReleaseWakelockCb()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* gnssReleaseWakelockCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssRequestTimeCb()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* gnssRequestTimeCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssSetSystemInfoCb(android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);
            ((android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* gnssSetSystemInfoCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::gnss::V1_1::IGnssCallback follow.
        @Override
        public void gnssNameCb(String name)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_1.IGnssCallback.kInterfaceName);
            _hidl_request.writeString(name);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* gnssNameCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssRequestLocationCb(boolean independentFromGnss)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_1.IGnssCallback.kInterfaceName);
            _hidl_request.writeBool(independentFromGnss);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* gnssRequestLocationCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::gnss::V2_0::IGnssCallback follow.
        @Override
        public void gnssSetCapabilitiesCb_2_0(int capabilities)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnssCallback.kInterfaceName);
            _hidl_request.writeInt32(capabilities);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* gnssSetCapabilitiesCb_2_0 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssLocationCb_2_0(android.hardware.gnss.V2_0.GnssLocation location)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnssCallback.kInterfaceName);
            ((android.hardware.gnss.V2_0.GnssLocation) location).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* gnssLocationCb_2_0 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssRequestLocationCb_2_0(boolean independentFromGnss, boolean isUserEmergency)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnssCallback.kInterfaceName);
            _hidl_request.writeBool(independentFromGnss);
            _hidl_request.writeBool(isUserEmergency);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* gnssRequestLocationCb_2_0 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssSvStatusCb_2_0(java.util.ArrayList<android.hardware.gnss.V2_0.IGnssCallback.GnssSvInfo> svInfoList)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnssCallback.kInterfaceName);
            android.hardware.gnss.V2_0.IGnssCallback.GnssSvInfo.writeVectorToParcel(_hidl_request, svInfoList);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* gnssSvStatusCb_2_0 */, _hidl_request, _hidl_reply, 0 /* flags */);
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

    public static abstract class Stub extends android.os.HwBinder implements IGnssCallback {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.gnss.V2_0.IGnssCallback.kInterfaceName,
                    android.hardware.gnss.V1_1.IGnssCallback.kInterfaceName,
                    android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.gnss.V2_0.IGnssCallback.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{100,35,32,55,16,-102,94,95,83,-85,3,119,-25,85,-20,73,74,-23,63,-53,82,121,-26,-18,-89,29,-20,46,122,-58,-5,-4} /* 64232037109a5e5f53ab0377e755ec494ae93fcb5279e6eea71dec2e7ac6fbfc */,
                    new byte[/* 32 */]{-118,-43,91,-61,91,-77,-88,62,101,-64,24,-67,-3,-25,-82,94,-68,116,-97,-14,-65,107,121,65,45,-19,11,-58,-56,-101,-105,-40} /* 8ad55bc35bb3a83e65c018bdfde7ae5ebc749ff2bf6b79412ded0bc6c89b97d8 */,
                    new byte[/* 32 */]{-100,-77,-33,43,-34,44,108,-43,-3,-106,-73,-60,21,85,66,12,-84,-41,-30,118,-91,86,-58,-124,-81,-111,-73,70,28,-122,70,15} /* 9cb3df2bde2c6cd5fd96b7c41555420cacd7e276a556c684af91b7461c86460f */,
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
                case 1 /* gnssLocationCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    android.hardware.gnss.V1_0.GnssLocation location = new android.hardware.gnss.V1_0.GnssLocation();
                    ((android.hardware.gnss.V1_0.GnssLocation) location).readFromParcel(_hidl_request);
                    gnssLocationCb(location);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 2 /* gnssStatusCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    byte status = _hidl_request.readInt8();
                    gnssStatusCb(status);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 3 /* gnssSvStatusCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus svInfo = new android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus();
                    ((android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus) svInfo).readFromParcel(_hidl_request);
                    gnssSvStatusCb(svInfo);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 4 /* gnssNmeaCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    long timestamp = _hidl_request.readInt64();
                    String nmea = _hidl_request.readString();
                    gnssNmeaCb(timestamp, nmea);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 5 /* gnssSetCapabilitesCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    int capabilities = _hidl_request.readInt32();
                    gnssSetCapabilitesCb(capabilities);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 6 /* gnssAcquireWakelockCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    gnssAcquireWakelockCb();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 7 /* gnssReleaseWakelockCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    gnssReleaseWakelockCb();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 8 /* gnssRequestTimeCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    gnssRequestTimeCb();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 9 /* gnssSetSystemInfoCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo info = new android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo();
                    ((android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo) info).readFromParcel(_hidl_request);
                    gnssSetSystemInfoCb(info);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 10 /* gnssNameCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_1.IGnssCallback.kInterfaceName);

                    String name = _hidl_request.readString();
                    gnssNameCb(name);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 11 /* gnssRequestLocationCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_1.IGnssCallback.kInterfaceName);

                    boolean independentFromGnss = _hidl_request.readBool();
                    gnssRequestLocationCb(independentFromGnss);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 12 /* gnssSetCapabilitiesCb_2_0 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnssCallback.kInterfaceName);

                    int capabilities = _hidl_request.readInt32();
                    gnssSetCapabilitiesCb_2_0(capabilities);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 13 /* gnssLocationCb_2_0 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnssCallback.kInterfaceName);

                    android.hardware.gnss.V2_0.GnssLocation location = new android.hardware.gnss.V2_0.GnssLocation();
                    ((android.hardware.gnss.V2_0.GnssLocation) location).readFromParcel(_hidl_request);
                    gnssLocationCb_2_0(location);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 14 /* gnssRequestLocationCb_2_0 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnssCallback.kInterfaceName);

                    boolean independentFromGnss = _hidl_request.readBool();
                    boolean isUserEmergency = _hidl_request.readBool();
                    gnssRequestLocationCb_2_0(independentFromGnss, isUserEmergency);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 15 /* gnssSvStatusCb_2_0 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnssCallback.kInterfaceName);

                    java.util.ArrayList<android.hardware.gnss.V2_0.IGnssCallback.GnssSvInfo> svInfoList = android.hardware.gnss.V2_0.IGnssCallback.GnssSvInfo.readVectorFromParcel(_hidl_request);
                    gnssSvStatusCb_2_0(svInfoList);
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
