package android.hardware.gnss.V1_0;

/**
 * Represents the standard GNSS (Global Navigation Satellite System) interface.
 */
public interface IGnss extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.gnss@1.0::IGnss";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IGnss asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IGnss)) {
            return (IGnss)iface;
        }

        IGnss proxy = new IGnss.Proxy(binder);

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
    public static IGnss castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IGnss.asInterface(iface.asBinder());
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
    public static IGnss getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IGnss.asInterface(android.os.HwBinder.getService("android.hardware.gnss@1.0::IGnss", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IGnss getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IGnss getService(String serviceName) throws android.os.RemoteException {
        return IGnss.asInterface(android.os.HwBinder.getService("android.hardware.gnss@1.0::IGnss", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IGnss getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Requested operational mode for GNSS operation.
     */
    public static final class GnssPositionMode {
        /**
         * Mode for running GNSS standalone (no assistance).
         */
        public static final byte STANDALONE = 0;
        /**
         * AGNSS MS-Based mode.
         */
        public static final byte MS_BASED = 1;
        /**
         * AGNSS MS-Assisted mode. This mode is not maintained by the platform anymore.
         * It is strongly recommended to use MS_BASED instead.
         */
        public static final byte MS_ASSISTED = 2;
        public static final String toString(byte o) {
            if (o == STANDALONE) {
                return "STANDALONE";
            }
            if (o == MS_BASED) {
                return "MS_BASED";
            }
            if (o == MS_ASSISTED) {
                return "MS_ASSISTED";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("STANDALONE"); // STANDALONE == 0
            if ((o & MS_BASED) == MS_BASED) {
                list.add("MS_BASED");
                flipped |= MS_BASED;
            }
            if ((o & MS_ASSISTED) == MS_ASSISTED) {
                list.add("MS_ASSISTED");
                flipped |= MS_ASSISTED;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Requested recurrence mode for GNSS operation.
     */
    public static final class GnssPositionRecurrence {
        /**
         * Receive GNSS fixes on a recurring basis at a specified period.
         */
        public static final int RECURRENCE_PERIODIC = 0;
        /**
         * Request a single shot GNSS fix.
         */
        public static final int RECURRENCE_SINGLE = 1;
        public static final String toString(int o) {
            if (o == RECURRENCE_PERIODIC) {
                return "RECURRENCE_PERIODIC";
            }
            if (o == RECURRENCE_SINGLE) {
                return "RECURRENCE_SINGLE";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            list.add("RECURRENCE_PERIODIC"); // RECURRENCE_PERIODIC == 0
            if ((o & RECURRENCE_SINGLE) == RECURRENCE_SINGLE) {
                list.add("RECURRENCE_SINGLE");
                flipped |= RECURRENCE_SINGLE;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Flags used to specify which aiding data to delete when calling
     * deleteAidingData().
     */
    public static final class GnssAidingData {
        public static final short DELETE_EPHEMERIS = 1 /* 0x0001 */;
        public static final short DELETE_ALMANAC = 2 /* 0x0002 */;
        public static final short DELETE_POSITION = 4 /* 0x0004 */;
        public static final short DELETE_TIME = 8 /* 0x0008 */;
        public static final short DELETE_IONO = 16 /* 0x0010 */;
        public static final short DELETE_UTC = 32 /* 0x0020 */;
        public static final short DELETE_HEALTH = 64 /* 0x0040 */;
        public static final short DELETE_SVDIR = 128 /* 0x0080 */;
        public static final short DELETE_SVSTEER = 256 /* 0x0100 */;
        public static final short DELETE_SADATA = 512 /* 0x0200 */;
        public static final short DELETE_RTI = 1024 /* 0x0400 */;
        public static final short DELETE_CELLDB_INFO = -32768 /* 0x8000 */;
        public static final short DELETE_ALL = -1 /* 0xFFFF */;
        public static final String toString(short o) {
            if (o == DELETE_EPHEMERIS) {
                return "DELETE_EPHEMERIS";
            }
            if (o == DELETE_ALMANAC) {
                return "DELETE_ALMANAC";
            }
            if (o == DELETE_POSITION) {
                return "DELETE_POSITION";
            }
            if (o == DELETE_TIME) {
                return "DELETE_TIME";
            }
            if (o == DELETE_IONO) {
                return "DELETE_IONO";
            }
            if (o == DELETE_UTC) {
                return "DELETE_UTC";
            }
            if (o == DELETE_HEALTH) {
                return "DELETE_HEALTH";
            }
            if (o == DELETE_SVDIR) {
                return "DELETE_SVDIR";
            }
            if (o == DELETE_SVSTEER) {
                return "DELETE_SVSTEER";
            }
            if (o == DELETE_SADATA) {
                return "DELETE_SADATA";
            }
            if (o == DELETE_RTI) {
                return "DELETE_RTI";
            }
            if (o == DELETE_CELLDB_INFO) {
                return "DELETE_CELLDB_INFO";
            }
            if (o == DELETE_ALL) {
                return "DELETE_ALL";
            }
            return "0x" + Integer.toHexString(Short.toUnsignedInt((short)(o)));
        }

        public static final String dumpBitfield(short o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            short flipped = 0;
            if ((o & DELETE_EPHEMERIS) == DELETE_EPHEMERIS) {
                list.add("DELETE_EPHEMERIS");
                flipped |= DELETE_EPHEMERIS;
            }
            if ((o & DELETE_ALMANAC) == DELETE_ALMANAC) {
                list.add("DELETE_ALMANAC");
                flipped |= DELETE_ALMANAC;
            }
            if ((o & DELETE_POSITION) == DELETE_POSITION) {
                list.add("DELETE_POSITION");
                flipped |= DELETE_POSITION;
            }
            if ((o & DELETE_TIME) == DELETE_TIME) {
                list.add("DELETE_TIME");
                flipped |= DELETE_TIME;
            }
            if ((o & DELETE_IONO) == DELETE_IONO) {
                list.add("DELETE_IONO");
                flipped |= DELETE_IONO;
            }
            if ((o & DELETE_UTC) == DELETE_UTC) {
                list.add("DELETE_UTC");
                flipped |= DELETE_UTC;
            }
            if ((o & DELETE_HEALTH) == DELETE_HEALTH) {
                list.add("DELETE_HEALTH");
                flipped |= DELETE_HEALTH;
            }
            if ((o & DELETE_SVDIR) == DELETE_SVDIR) {
                list.add("DELETE_SVDIR");
                flipped |= DELETE_SVDIR;
            }
            if ((o & DELETE_SVSTEER) == DELETE_SVSTEER) {
                list.add("DELETE_SVSTEER");
                flipped |= DELETE_SVSTEER;
            }
            if ((o & DELETE_SADATA) == DELETE_SADATA) {
                list.add("DELETE_SADATA");
                flipped |= DELETE_SADATA;
            }
            if ((o & DELETE_RTI) == DELETE_RTI) {
                list.add("DELETE_RTI");
                flipped |= DELETE_RTI;
            }
            if ((o & DELETE_CELLDB_INFO) == DELETE_CELLDB_INFO) {
                list.add("DELETE_CELLDB_INFO");
                flipped |= DELETE_CELLDB_INFO;
            }
            if ((o & DELETE_ALL) == DELETE_ALL) {
                list.add("DELETE_ALL");
                flipped |= DELETE_ALL;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Short.toUnsignedInt((short)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Opens the interface and provides the callback routines to the implementation of this
     * interface.
     *
     * The framework calls this method to instruct the GPS engine to prepare for serving requests
     * from the framework. The GNSS HAL implementation must respond to all GNSS requests from the
     * framework upon successful return from this method until cleanup() method is called to
     * close this interface.
     *
     * @param callback Callback interface for IGnss.
     *
     * @return success Returns true on success.
     */
    boolean setCallback(android.hardware.gnss.V1_0.IGnssCallback callback)
        throws android.os.RemoteException;
    /**
     * Starts a location output stream using the IGnssCallback
     * gnssLocationCb(), following the settings from the most recent call to
     * setPositionMode().
     *
     * This output must operate independently of any GNSS location batching
     * operations, see the IGnssBatching.hal for details.
     *
     * @return success Returns true on success.
     */
    boolean start()
        throws android.os.RemoteException;
    /**
     * Stops the location output stream.
     *
     * @return success Returns true on success.
     */
    boolean stop()
        throws android.os.RemoteException;
    /**
     * Closes the interface.
     *
     * The cleanup() method is called by the framework to tell the GNSS HAL implementation to
     * not expect any GNSS requests in the immediate future - e.g. this may be called when
     * location is disabled by a user setting or low battery conditions. The GNSS HAL
     * implementation must immediately stop responding to any existing requests until the
     * setCallback() method is called again and the requests are re-initiated by the framework.
     *
     * After this method is called, the GNSS HAL implementation may choose to modify GNSS hardware
     * states to save power. It is expected that when setCallback() method is called again to
     * reopen this interface, to serve requests, there may be some minor delays in GNSS response
     * requests as hardware readiness states are restored, not to exceed those that occur on normal
     * device boot up.
     */
    void cleanup()
        throws android.os.RemoteException;
    /**
     * Injects the current time.
     *
     * @param timeMs This is the UTC time received from the NTP server, its value
     * is given in milliseconds since January 1, 1970.
     * @param timeReferenceMs The corresponding value of
     * SystemClock.elapsedRealtime() from the device when the NTP response was
     * received in milliseconds.
     * @param uncertaintyMs Uncertainty associated with the value represented by
     * time. Represented in milliseconds.
     *
     * @return success Returns true if the operation is successful.
     */
    boolean injectTime(long timeMs, long timeReferenceMs, int uncertaintyMs)
        throws android.os.RemoteException;
    /**
     * Injects current location from another location provider (typically cell
     * ID).
     *
     * @param latitudeDegrees Measured in Degrees.
     * @param longitudeDegrees Measured in Degrees.
     * @param accuracyMeters Measured in meters.
     *
     * @return success Returns true if successful.
     */
    boolean injectLocation(double latitudeDegrees, double longitudeDegrees, float accuracyMeters)
        throws android.os.RemoteException;
    /**
     * Specifies that the next call to start will not use the
     * information defined in the flags. GnssAidingData value of DELETE_ALL is
     * passed for a cold start.
     *
     * @param aidingDataFlags Flags specifying the aiding data to be deleted.
     */
    void deleteAidingData(short aidingDataFlags)
        throws android.os.RemoteException;
    /**
     * Sets the GnssPositionMode parameter,its associated recurrence value,
     * the time between fixes,requested fix accuracy and time to first fix.
     *
     * @param mode  Parameter must be one of MS_BASED or STANDALONE.
     * It is allowed by the platform (and it is recommended) to fallback to
     * MS_BASED if MS_ASSISTED is passed in, and MS_BASED is supported.
     * @recurrence GNSS position recurrence value, either periodic or single.
     * @param minIntervalMs Represents the time between fixes in milliseconds.
     * @param preferredAccuracyMeters Represents the requested fix accuracy in meters.
     * @param preferredTimeMs Represents the requested time to first fix in milliseconds.
     *
     * @return success Returns true if successful.
     */
    boolean setPositionMode(byte mode, int recurrence, int minIntervalMs, int preferredAccuracyMeters, int preferredTimeMs)
        throws android.os.RemoteException;
    /**
     * This method returns the IAGnssRil Interface.
     *
     * @return aGnssRilIface Handle to the IAGnssRil interface.
     */
    android.hardware.gnss.V1_0.IAGnssRil getExtensionAGnssRil()
        throws android.os.RemoteException;
    /**
     * This method returns the IGnssGeofencing Interface.
     *
     * @return gnssGeofencingIface Handle to the IGnssGeofencing interface.
     */
    android.hardware.gnss.V1_0.IGnssGeofencing getExtensionGnssGeofencing()
        throws android.os.RemoteException;
    /**
     * This method returns the IAGnss Interface.
     *
     * @return aGnssIface Handle to the IAGnss interface.
     */
    android.hardware.gnss.V1_0.IAGnss getExtensionAGnss()
        throws android.os.RemoteException;
    /**
     * This method returns the IGnssNi interface.
     *
     * @return gnssNiIface Handle to the IGnssNi interface.
     */
    android.hardware.gnss.V1_0.IGnssNi getExtensionGnssNi()
        throws android.os.RemoteException;
    /**
     * This method returns the IGnssMeasurement interface.
     *
     * @return gnssMeasurementIface Handle to the IGnssMeasurement interface.
     */
    android.hardware.gnss.V1_0.IGnssMeasurement getExtensionGnssMeasurement()
        throws android.os.RemoteException;
    /**
     * This method returns the IGnssNavigationMessage interface.
     *
     * @return gnssNavigationIface gnssNavigationIface to the IGnssNavigationMessage interface.
     */
    android.hardware.gnss.V1_0.IGnssNavigationMessage getExtensionGnssNavigationMessage()
        throws android.os.RemoteException;
    /**
     * This method returns the IGnssXtra interface.
     *
     * @return xtraIface Handle to the IGnssXtra interface.
     */
    android.hardware.gnss.V1_0.IGnssXtra getExtensionXtra()
        throws android.os.RemoteException;
    /**
     * This method returns the IGnssConfiguration interface.
     *
     * @return gnssConfigIface Handle to the IGnssConfiguration interface.
     */
    android.hardware.gnss.V1_0.IGnssConfiguration getExtensionGnssConfiguration()
        throws android.os.RemoteException;
    /**
     * This method returns the IGnssDebug interface.
     *
     * @return debugIface Handle to the IGnssDebug interface.
     */
    android.hardware.gnss.V1_0.IGnssDebug getExtensionGnssDebug()
        throws android.os.RemoteException;
    /**
     * This method returns the IGnssBatching interface.
     *
     * @return batchingIface Handle to the IGnssBatching interface.
     */
    android.hardware.gnss.V1_0.IGnssBatching getExtensionGnssBatching()
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

    public static final class Proxy implements IGnss {
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
            return "[class or subclass of " + IGnss.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::gnss::V1_0::IGnss follow.
        @Override
        public boolean setCallback(android.hardware.gnss.V1_0.IGnssCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* setCallback */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean start()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* start */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean stop()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* stop */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cleanup()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* cleanup */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean injectTime(long timeMs, long timeReferenceMs, int uncertaintyMs)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);
            _hidl_request.writeInt64(timeMs);
            _hidl_request.writeInt64(timeReferenceMs);
            _hidl_request.writeInt32(uncertaintyMs);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* injectTime */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean injectLocation(double latitudeDegrees, double longitudeDegrees, float accuracyMeters)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);
            _hidl_request.writeDouble(latitudeDegrees);
            _hidl_request.writeDouble(longitudeDegrees);
            _hidl_request.writeFloat(accuracyMeters);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* injectLocation */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void deleteAidingData(short aidingDataFlags)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);
            _hidl_request.writeInt16(aidingDataFlags);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* deleteAidingData */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean setPositionMode(byte mode, int recurrence, int minIntervalMs, int preferredAccuracyMeters, int preferredTimeMs)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);
            _hidl_request.writeInt8(mode);
            _hidl_request.writeInt32(recurrence);
            _hidl_request.writeInt32(minIntervalMs);
            _hidl_request.writeInt32(preferredAccuracyMeters);
            _hidl_request.writeInt32(preferredTimeMs);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* setPositionMode */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V1_0.IAGnssRil getExtensionAGnssRil()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* getExtensionAGnssRil */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V1_0.IAGnssRil _hidl_out_aGnssRilIface = android.hardware.gnss.V1_0.IAGnssRil.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_aGnssRilIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V1_0.IGnssGeofencing getExtensionGnssGeofencing()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* getExtensionGnssGeofencing */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V1_0.IGnssGeofencing _hidl_out_gnssGeofencingIface = android.hardware.gnss.V1_0.IGnssGeofencing.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_gnssGeofencingIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V1_0.IAGnss getExtensionAGnss()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* getExtensionAGnss */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V1_0.IAGnss _hidl_out_aGnssIface = android.hardware.gnss.V1_0.IAGnss.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_aGnssIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V1_0.IGnssNi getExtensionGnssNi()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* getExtensionGnssNi */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V1_0.IGnssNi _hidl_out_gnssNiIface = android.hardware.gnss.V1_0.IGnssNi.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_gnssNiIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V1_0.IGnssMeasurement getExtensionGnssMeasurement()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* getExtensionGnssMeasurement */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V1_0.IGnssMeasurement _hidl_out_gnssMeasurementIface = android.hardware.gnss.V1_0.IGnssMeasurement.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_gnssMeasurementIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V1_0.IGnssNavigationMessage getExtensionGnssNavigationMessage()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* getExtensionGnssNavigationMessage */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V1_0.IGnssNavigationMessage _hidl_out_gnssNavigationIface = android.hardware.gnss.V1_0.IGnssNavigationMessage.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_gnssNavigationIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V1_0.IGnssXtra getExtensionXtra()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* getExtensionXtra */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V1_0.IGnssXtra _hidl_out_xtraIface = android.hardware.gnss.V1_0.IGnssXtra.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_xtraIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V1_0.IGnssConfiguration getExtensionGnssConfiguration()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* getExtensionGnssConfiguration */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V1_0.IGnssConfiguration _hidl_out_gnssConfigIface = android.hardware.gnss.V1_0.IGnssConfiguration.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_gnssConfigIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V1_0.IGnssDebug getExtensionGnssDebug()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* getExtensionGnssDebug */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V1_0.IGnssDebug _hidl_out_debugIface = android.hardware.gnss.V1_0.IGnssDebug.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_debugIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V1_0.IGnssBatching getExtensionGnssBatching()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(18 /* getExtensionGnssBatching */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V1_0.IGnssBatching _hidl_out_batchingIface = android.hardware.gnss.V1_0.IGnssBatching.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_batchingIface;
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

    public static abstract class Stub extends android.os.HwBinder implements IGnss {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.gnss.V1_0.IGnss.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.gnss.V1_0.IGnss.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-19,-26,-105,16,-61,-87,92,44,-66,-127,-114,108,-117,-73,44,120,22,-126,63,-84,-27,-4,33,-63,119,49,-78,111,65,-39,77,101} /* ede69710c3a95c2cbe818e6c8bb72c7816823face5fc21c17731b26f41d94d65 */,
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
                case 1 /* setCallback */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssCallback callback = android.hardware.gnss.V1_0.IGnssCallback.asInterface(_hidl_request.readStrongBinder());
                    boolean _hidl_out_success = setCallback(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 2 /* start */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    boolean _hidl_out_success = start();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 3 /* stop */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    boolean _hidl_out_success = stop();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 4 /* cleanup */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    cleanup();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 5 /* injectTime */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    long timeMs = _hidl_request.readInt64();
                    long timeReferenceMs = _hidl_request.readInt64();
                    int uncertaintyMs = _hidl_request.readInt32();
                    boolean _hidl_out_success = injectTime(timeMs, timeReferenceMs, uncertaintyMs);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 6 /* injectLocation */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    double latitudeDegrees = _hidl_request.readDouble();
                    double longitudeDegrees = _hidl_request.readDouble();
                    float accuracyMeters = _hidl_request.readFloat();
                    boolean _hidl_out_success = injectLocation(latitudeDegrees, longitudeDegrees, accuracyMeters);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 7 /* deleteAidingData */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    short aidingDataFlags = _hidl_request.readInt16();
                    deleteAidingData(aidingDataFlags);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 8 /* setPositionMode */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    byte mode = _hidl_request.readInt8();
                    int recurrence = _hidl_request.readInt32();
                    int minIntervalMs = _hidl_request.readInt32();
                    int preferredAccuracyMeters = _hidl_request.readInt32();
                    int preferredTimeMs = _hidl_request.readInt32();
                    boolean _hidl_out_success = setPositionMode(mode, recurrence, minIntervalMs, preferredAccuracyMeters, preferredTimeMs);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 9 /* getExtensionAGnssRil */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_0.IAGnssRil _hidl_out_aGnssRilIface = getExtensionAGnssRil();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_aGnssRilIface == null ? null : _hidl_out_aGnssRilIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 10 /* getExtensionGnssGeofencing */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssGeofencing _hidl_out_gnssGeofencingIface = getExtensionGnssGeofencing();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_gnssGeofencingIface == null ? null : _hidl_out_gnssGeofencingIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 11 /* getExtensionAGnss */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_0.IAGnss _hidl_out_aGnssIface = getExtensionAGnss();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_aGnssIface == null ? null : _hidl_out_aGnssIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 12 /* getExtensionGnssNi */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssNi _hidl_out_gnssNiIface = getExtensionGnssNi();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_gnssNiIface == null ? null : _hidl_out_gnssNiIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 13 /* getExtensionGnssMeasurement */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssMeasurement _hidl_out_gnssMeasurementIface = getExtensionGnssMeasurement();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_gnssMeasurementIface == null ? null : _hidl_out_gnssMeasurementIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 14 /* getExtensionGnssNavigationMessage */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssNavigationMessage _hidl_out_gnssNavigationIface = getExtensionGnssNavigationMessage();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_gnssNavigationIface == null ? null : _hidl_out_gnssNavigationIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 15 /* getExtensionXtra */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssXtra _hidl_out_xtraIface = getExtensionXtra();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_xtraIface == null ? null : _hidl_out_xtraIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 16 /* getExtensionGnssConfiguration */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssConfiguration _hidl_out_gnssConfigIface = getExtensionGnssConfiguration();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_gnssConfigIface == null ? null : _hidl_out_gnssConfigIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 17 /* getExtensionGnssDebug */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssDebug _hidl_out_debugIface = getExtensionGnssDebug();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_debugIface == null ? null : _hidl_out_debugIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 18 /* getExtensionGnssBatching */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssBatching _hidl_out_batchingIface = getExtensionGnssBatching();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_batchingIface == null ? null : _hidl_out_batchingIface.asBinder());
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
