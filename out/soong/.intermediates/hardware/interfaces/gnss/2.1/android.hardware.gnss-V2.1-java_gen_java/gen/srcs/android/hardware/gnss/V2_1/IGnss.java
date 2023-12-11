package android.hardware.gnss.V2_1;

/**
 * Represents the standard GNSS (Global Navigation Satellite System) interface.
 */
public interface IGnss extends android.hardware.gnss.V2_0.IGnss {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.gnss@2.1::IGnss";

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
        return IGnss.asInterface(android.os.HwBinder.getService("android.hardware.gnss@2.1::IGnss", serviceName, retry));
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
        return IGnss.asInterface(android.os.HwBinder.getService("android.hardware.gnss@2.1::IGnss", serviceName));
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
    boolean setCallback_2_1(android.hardware.gnss.V2_1.IGnssCallback callback)
        throws android.os.RemoteException;
    /**
     * This method returns the IGnssMeasurement interface.
     *
     * getExtensionGnssMeasurement(), getExtensionGnssMeasurement_1_1(),
     * getExtensionGnssMeasurement_2_0(), and getExtensionGnssMeasurement_2_1() methods must return
     * non-null. They can all return the same, latest version of IGnssMeasurement.
     *
     * @return gnssMeasurementIface Handle to the IGnssMeasurement interface.
     */
    android.hardware.gnss.V2_1.IGnssMeasurement getExtensionGnssMeasurement_2_1()
        throws android.os.RemoteException;
    /**
     * This method returns the IGnssConfiguration interface.
     *
     * getExtensionGnssConfiguration(), getExtensionGnssConfiguration_1_1(),
     * getExtensionGnssConfiguration_2_0(), and getExtensionGnssConfiguration_2_1() methods must
     * return non-null. They can all return the same, latest version of IGnssConfiguration.
     *
     * @return gnssConfigurationIface Handle to the IGnssConfiguration interface.
     */
    android.hardware.gnss.V2_1.IGnssConfiguration getExtensionGnssConfiguration_2_1()
        throws android.os.RemoteException;
    /**
     * This method returns the IMeasurementCorrections interface.
     *
     * Both getExtensionMeasurementCorrections and getExtensionMeasurementCorrections_1_1 must
     * return non-null. Both methods can return the same V1.1 IMeasurementCorrections object.
     *
     * @return measurementCorrectionsIface Handle to the IMeasurementCorrections interface.
     */
    android.hardware.gnss.measurement_corrections.V1_1.IMeasurementCorrections getExtensionMeasurementCorrections_1_1()
        throws android.os.RemoteException;
    /**
     * This method returns the IGnssAntennaInfo interface.
     *
     * This method must return non-null.
     *
     * @return gnssAntennaInfoIface Handle to the IGnssAntennaInfo interface.
     */
    android.hardware.gnss.V2_1.IGnssAntennaInfo getExtensionGnssAntennaInfo()
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

        // Methods from ::android::hardware::gnss::V1_1::IGnss follow.
        @Override
        public boolean setCallback_1_1(android.hardware.gnss.V1_1.IGnssCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_1.IGnss.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(19 /* setCallback_1_1 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean setPositionMode_1_1(byte mode, int recurrence, int minIntervalMs, int preferredAccuracyMeters, int preferredTimeMs, boolean lowPowerMode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_1.IGnss.kInterfaceName);
            _hidl_request.writeInt8(mode);
            _hidl_request.writeInt32(recurrence);
            _hidl_request.writeInt32(minIntervalMs);
            _hidl_request.writeInt32(preferredAccuracyMeters);
            _hidl_request.writeInt32(preferredTimeMs);
            _hidl_request.writeBool(lowPowerMode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(20 /* setPositionMode_1_1 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V1_1.IGnssConfiguration getExtensionGnssConfiguration_1_1()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_1.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(21 /* getExtensionGnssConfiguration_1_1 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V1_1.IGnssConfiguration _hidl_out_gnssConfigurationIface = android.hardware.gnss.V1_1.IGnssConfiguration.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_gnssConfigurationIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V1_1.IGnssMeasurement getExtensionGnssMeasurement_1_1()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_1.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(22 /* getExtensionGnssMeasurement_1_1 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V1_1.IGnssMeasurement _hidl_out_gnssMeasurementIface = android.hardware.gnss.V1_1.IGnssMeasurement.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_gnssMeasurementIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean injectBestLocation(android.hardware.gnss.V1_0.GnssLocation location)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_1.IGnss.kInterfaceName);
            ((android.hardware.gnss.V1_0.GnssLocation) location).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(23 /* injectBestLocation */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::gnss::V2_0::IGnss follow.
        @Override
        public boolean setCallback_2_0(android.hardware.gnss.V2_0.IGnssCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnss.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(24 /* setCallback_2_0 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V2_0.IGnssConfiguration getExtensionGnssConfiguration_2_0()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(25 /* getExtensionGnssConfiguration_2_0 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V2_0.IGnssConfiguration _hidl_out_gnssConfigurationIface = android.hardware.gnss.V2_0.IGnssConfiguration.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_gnssConfigurationIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V2_0.IGnssDebug getExtensionGnssDebug_2_0()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(26 /* getExtensionGnssDebug_2_0 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V2_0.IGnssDebug _hidl_out_gnssDebugIface = android.hardware.gnss.V2_0.IGnssDebug.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_gnssDebugIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V2_0.IAGnss getExtensionAGnss_2_0()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(27 /* getExtensionAGnss_2_0 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V2_0.IAGnss _hidl_out_aGnssIface = android.hardware.gnss.V2_0.IAGnss.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_aGnssIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V2_0.IAGnssRil getExtensionAGnssRil_2_0()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(28 /* getExtensionAGnssRil_2_0 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V2_0.IAGnssRil _hidl_out_aGnssRilIface = android.hardware.gnss.V2_0.IAGnssRil.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_aGnssRilIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V2_0.IGnssMeasurement getExtensionGnssMeasurement_2_0()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(29 /* getExtensionGnssMeasurement_2_0 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V2_0.IGnssMeasurement _hidl_out_gnssMeasurementIface = android.hardware.gnss.V2_0.IGnssMeasurement.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_gnssMeasurementIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.measurement_corrections.V1_0.IMeasurementCorrections getExtensionMeasurementCorrections()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(30 /* getExtensionMeasurementCorrections */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.measurement_corrections.V1_0.IMeasurementCorrections _hidl_out_measurementCorrectionsIface = android.hardware.gnss.measurement_corrections.V1_0.IMeasurementCorrections.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_measurementCorrectionsIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControl getExtensionVisibilityControl()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(31 /* getExtensionVisibilityControl */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControl _hidl_out_visibilityControlIface = android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControl.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_visibilityControlIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V2_0.IGnssBatching getExtensionGnssBatching_2_0()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(32 /* getExtensionGnssBatching_2_0 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V2_0.IGnssBatching _hidl_out_batchingIface = android.hardware.gnss.V2_0.IGnssBatching.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_batchingIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean injectBestLocation_2_0(android.hardware.gnss.V2_0.GnssLocation location)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnss.kInterfaceName);
            ((android.hardware.gnss.V2_0.GnssLocation) location).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(33 /* injectBestLocation_2_0 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::gnss::V2_1::IGnss follow.
        @Override
        public boolean setCallback_2_1(android.hardware.gnss.V2_1.IGnssCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_1.IGnss.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(34 /* setCallback_2_1 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V2_1.IGnssMeasurement getExtensionGnssMeasurement_2_1()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_1.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(35 /* getExtensionGnssMeasurement_2_1 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V2_1.IGnssMeasurement _hidl_out_gnssMeasurementIface = android.hardware.gnss.V2_1.IGnssMeasurement.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_gnssMeasurementIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V2_1.IGnssConfiguration getExtensionGnssConfiguration_2_1()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_1.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(36 /* getExtensionGnssConfiguration_2_1 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V2_1.IGnssConfiguration _hidl_out_gnssConfigurationIface = android.hardware.gnss.V2_1.IGnssConfiguration.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_gnssConfigurationIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.measurement_corrections.V1_1.IMeasurementCorrections getExtensionMeasurementCorrections_1_1()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_1.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(37 /* getExtensionMeasurementCorrections_1_1 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.measurement_corrections.V1_1.IMeasurementCorrections _hidl_out_measurementCorrectionsIface = android.hardware.gnss.measurement_corrections.V1_1.IMeasurementCorrections.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_measurementCorrectionsIface;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.gnss.V2_1.IGnssAntennaInfo getExtensionGnssAntennaInfo()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_1.IGnss.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(38 /* getExtensionGnssAntennaInfo */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V2_1.IGnssAntennaInfo _hidl_out_gnssAntennaInfoIface = android.hardware.gnss.V2_1.IGnssAntennaInfo.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_gnssAntennaInfoIface;
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
                    android.hardware.gnss.V2_1.IGnss.kInterfaceName,
                    android.hardware.gnss.V2_0.IGnss.kInterfaceName,
                    android.hardware.gnss.V1_1.IGnss.kInterfaceName,
                    android.hardware.gnss.V1_0.IGnss.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.gnss.V2_1.IGnss.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-61,25,-26,-117,3,-126,-103,88,64,68,2,-62,-39,-58,-126,1,-106,120,8,125,96,73,88,7,-64,-89,68,78,10,106,-7,-127} /* c319e68b03829958404402c2d9c682019678087d60495807c0a7444e0a6af981 */,
                    new byte[/* 32 */]{-11,96,95,72,-62,-5,-97,35,22,21,-35,-109,43,-9,48,-82,-107,64,-12,-7,-117,91,122,-30,-78,105,-105,95,69,47,109,115} /* f5605f48c2fb9f231615dd932bf730ae9540f4f98b5b7ae2b269975f452f6d73 */,
                    new byte[/* 32 */]{-75,-15,-12,-63,-67,109,-25,26,-114,113,-41,15,87,-51,-85,-112,74,-64,36,-95,47,61,-18,62,33,115,119,10,69,-125,-68,-62} /* b5f1f4c1bd6de71a8e71d70f57cdab904ac024a12f3dee3e2173770a4583bcc2 */,
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

                case 19 /* setCallback_1_1 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_1.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_1.IGnssCallback callback = android.hardware.gnss.V1_1.IGnssCallback.asInterface(_hidl_request.readStrongBinder());
                    boolean _hidl_out_success = setCallback_1_1(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 20 /* setPositionMode_1_1 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_1.IGnss.kInterfaceName);

                    byte mode = _hidl_request.readInt8();
                    int recurrence = _hidl_request.readInt32();
                    int minIntervalMs = _hidl_request.readInt32();
                    int preferredAccuracyMeters = _hidl_request.readInt32();
                    int preferredTimeMs = _hidl_request.readInt32();
                    boolean lowPowerMode = _hidl_request.readBool();
                    boolean _hidl_out_success = setPositionMode_1_1(mode, recurrence, minIntervalMs, preferredAccuracyMeters, preferredTimeMs, lowPowerMode);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 21 /* getExtensionGnssConfiguration_1_1 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_1.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_1.IGnssConfiguration _hidl_out_gnssConfigurationIface = getExtensionGnssConfiguration_1_1();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_gnssConfigurationIface == null ? null : _hidl_out_gnssConfigurationIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 22 /* getExtensionGnssMeasurement_1_1 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_1.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_1.IGnssMeasurement _hidl_out_gnssMeasurementIface = getExtensionGnssMeasurement_1_1();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_gnssMeasurementIface == null ? null : _hidl_out_gnssMeasurementIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 23 /* injectBestLocation */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_1.IGnss.kInterfaceName);

                    android.hardware.gnss.V1_0.GnssLocation location = new android.hardware.gnss.V1_0.GnssLocation();
                    ((android.hardware.gnss.V1_0.GnssLocation) location).readFromParcel(_hidl_request);
                    boolean _hidl_out_success = injectBestLocation(location);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 24 /* setCallback_2_0 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V2_0.IGnssCallback callback = android.hardware.gnss.V2_0.IGnssCallback.asInterface(_hidl_request.readStrongBinder());
                    boolean _hidl_out_success = setCallback_2_0(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 25 /* getExtensionGnssConfiguration_2_0 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V2_0.IGnssConfiguration _hidl_out_gnssConfigurationIface = getExtensionGnssConfiguration_2_0();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_gnssConfigurationIface == null ? null : _hidl_out_gnssConfigurationIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 26 /* getExtensionGnssDebug_2_0 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V2_0.IGnssDebug _hidl_out_gnssDebugIface = getExtensionGnssDebug_2_0();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_gnssDebugIface == null ? null : _hidl_out_gnssDebugIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 27 /* getExtensionAGnss_2_0 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V2_0.IAGnss _hidl_out_aGnssIface = getExtensionAGnss_2_0();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_aGnssIface == null ? null : _hidl_out_aGnssIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 28 /* getExtensionAGnssRil_2_0 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V2_0.IAGnssRil _hidl_out_aGnssRilIface = getExtensionAGnssRil_2_0();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_aGnssRilIface == null ? null : _hidl_out_aGnssRilIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 29 /* getExtensionGnssMeasurement_2_0 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V2_0.IGnssMeasurement _hidl_out_gnssMeasurementIface = getExtensionGnssMeasurement_2_0();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_gnssMeasurementIface == null ? null : _hidl_out_gnssMeasurementIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 30 /* getExtensionMeasurementCorrections */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

                    android.hardware.gnss.measurement_corrections.V1_0.IMeasurementCorrections _hidl_out_measurementCorrectionsIface = getExtensionMeasurementCorrections();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_measurementCorrectionsIface == null ? null : _hidl_out_measurementCorrectionsIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 31 /* getExtensionVisibilityControl */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

                    android.hardware.gnss.visibility_control.V1_0.IGnssVisibilityControl _hidl_out_visibilityControlIface = getExtensionVisibilityControl();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_visibilityControlIface == null ? null : _hidl_out_visibilityControlIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 32 /* getExtensionGnssBatching_2_0 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V2_0.IGnssBatching _hidl_out_batchingIface = getExtensionGnssBatching_2_0();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_batchingIface == null ? null : _hidl_out_batchingIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 33 /* injectBestLocation_2_0 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnss.kInterfaceName);

                    android.hardware.gnss.V2_0.GnssLocation location = new android.hardware.gnss.V2_0.GnssLocation();
                    ((android.hardware.gnss.V2_0.GnssLocation) location).readFromParcel(_hidl_request);
                    boolean _hidl_out_success = injectBestLocation_2_0(location);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 34 /* setCallback_2_1 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_1.IGnss.kInterfaceName);

                    android.hardware.gnss.V2_1.IGnssCallback callback = android.hardware.gnss.V2_1.IGnssCallback.asInterface(_hidl_request.readStrongBinder());
                    boolean _hidl_out_success = setCallback_2_1(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 35 /* getExtensionGnssMeasurement_2_1 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_1.IGnss.kInterfaceName);

                    android.hardware.gnss.V2_1.IGnssMeasurement _hidl_out_gnssMeasurementIface = getExtensionGnssMeasurement_2_1();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_gnssMeasurementIface == null ? null : _hidl_out_gnssMeasurementIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 36 /* getExtensionGnssConfiguration_2_1 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_1.IGnss.kInterfaceName);

                    android.hardware.gnss.V2_1.IGnssConfiguration _hidl_out_gnssConfigurationIface = getExtensionGnssConfiguration_2_1();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_gnssConfigurationIface == null ? null : _hidl_out_gnssConfigurationIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 37 /* getExtensionMeasurementCorrections_1_1 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_1.IGnss.kInterfaceName);

                    android.hardware.gnss.measurement_corrections.V1_1.IMeasurementCorrections _hidl_out_measurementCorrectionsIface = getExtensionMeasurementCorrections_1_1();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_measurementCorrectionsIface == null ? null : _hidl_out_measurementCorrectionsIface.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 38 /* getExtensionGnssAntennaInfo */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_1.IGnss.kInterfaceName);

                    android.hardware.gnss.V2_1.IGnssAntennaInfo _hidl_out_gnssAntennaInfoIface = getExtensionGnssAntennaInfo();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_gnssAntennaInfoIface == null ? null : _hidl_out_gnssAntennaInfoIface.asBinder());
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
