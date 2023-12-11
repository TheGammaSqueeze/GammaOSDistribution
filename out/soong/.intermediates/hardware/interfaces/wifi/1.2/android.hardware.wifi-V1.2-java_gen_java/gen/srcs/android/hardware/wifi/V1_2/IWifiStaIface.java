package android.hardware.wifi.V1_2;

/**
 * Interface used to represent a single STA iface.
 *
 * IWifiChip.createStaIface() must return a @1.2::IWifiStaIface when supported.
 */
public interface IWifiStaIface extends android.hardware.wifi.V1_0.IWifiStaIface {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.wifi@1.2::IWifiStaIface";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IWifiStaIface asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IWifiStaIface)) {
            return (IWifiStaIface)iface;
        }

        IWifiStaIface proxy = new IWifiStaIface.Proxy(binder);

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
    public static IWifiStaIface castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IWifiStaIface.asInterface(iface.asBinder());
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
    public static IWifiStaIface getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IWifiStaIface.asInterface(android.os.HwBinder.getService("android.hardware.wifi@1.2::IWifiStaIface", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IWifiStaIface getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IWifiStaIface getService(String serviceName) throws android.os.RemoteException {
        return IWifiStaIface.asInterface(android.os.HwBinder.getService("android.hardware.wifi@1.2::IWifiStaIface", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IWifiStaIface getService() throws android.os.RemoteException {
        return getService("default");
    }


    @java.lang.FunctionalInterface
    public interface readApfPacketFilterDataCallback {
        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<Byte> data);
    }

    /**
     * Fetches a consistent snapshot of the entire APF program and working
     * memory buffer and returns it to the host. The returned buffer contains
     * both code and data. Its length must match the most recently returned
     * |StaApfPacketFilterCapabilities.maxLength|.
     *
     * While the snapshot is being fetched, the APF intepreter must not execute
     * and all incoming packets must be passed to the host as if there was no
     * APF program installed.
     *
     * Must fail with |WifiStatusCode.ERROR_NOT_SUPPORTED| if
     * |StaIfaceCapabilityMask.APF| is not set.
     *
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_NOT_SUPPORTED|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     * @return data The entire APF working memory buffer when status is
     *         |WifiStatusCode.SUCCESS|, empty otherwise.
     * @see getApfPacketFilterCapabilities()
     * @see installApfPacketFilter()
     */
    void readApfPacketFilterData(readApfPacketFilterDataCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Changes the MAC address of the Sta Interface to the given
     * MAC address.
     *
     * @param mac MAC address to change into.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus setMacAddress(byte[/* 6 */] mac)
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

    public static final class Proxy implements IWifiStaIface {
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
            return "[class or subclass of " + IWifiStaIface.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::wifi::V1_0::IWifiIface follow.
        @Override
        public void getType(getTypeCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* getType */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_type = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_type);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getName(getNameCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* getName */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_name = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_name);
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::V1_0::IWifiStaIface follow.
        @Override
        public android.hardware.wifi.V1_0.WifiStatus registerEventCallback(android.hardware.wifi.V1_0.IWifiStaIfaceEventCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* registerEventCallback */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCapabilities(getCapabilitiesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* getCapabilities */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_capabilities = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_capabilities);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getApfPacketFilterCapabilities(getApfPacketFilterCapabilitiesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* getApfPacketFilterCapabilities */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.StaApfPacketFilterCapabilities _hidl_out_capabilities = new android.hardware.wifi.V1_0.StaApfPacketFilterCapabilities();
                ((android.hardware.wifi.V1_0.StaApfPacketFilterCapabilities) _hidl_out_capabilities).readFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_capabilities);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus installApfPacketFilter(int cmdId, java.util.ArrayList<Byte> program)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);
            _hidl_request.writeInt32(cmdId);
            _hidl_request.writeInt8Vector(program);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* installApfPacketFilter */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getBackgroundScanCapabilities(getBackgroundScanCapabilitiesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* getBackgroundScanCapabilities */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.StaBackgroundScanCapabilities _hidl_out_capabilities = new android.hardware.wifi.V1_0.StaBackgroundScanCapabilities();
                ((android.hardware.wifi.V1_0.StaBackgroundScanCapabilities) _hidl_out_capabilities).readFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_capabilities);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getValidFrequenciesForBand(int band, getValidFrequenciesForBandCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);
            _hidl_request.writeInt32(band);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* getValidFrequenciesForBand */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Integer> _hidl_out_frequencies = _hidl_reply.readInt32Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_frequencies);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus startBackgroundScan(int cmdId, android.hardware.wifi.V1_0.StaBackgroundScanParameters params)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);
            _hidl_request.writeInt32(cmdId);
            ((android.hardware.wifi.V1_0.StaBackgroundScanParameters) params).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* startBackgroundScan */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus stopBackgroundScan(int cmdId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);
            _hidl_request.writeInt32(cmdId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* stopBackgroundScan */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus enableLinkLayerStatsCollection(boolean debug)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);
            _hidl_request.writeBool(debug);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* enableLinkLayerStatsCollection */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus disableLinkLayerStatsCollection()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* disableLinkLayerStatsCollection */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getLinkLayerStats(getLinkLayerStatsCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* getLinkLayerStats */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.StaLinkLayerStats _hidl_out_stats = new android.hardware.wifi.V1_0.StaLinkLayerStats();
                ((android.hardware.wifi.V1_0.StaLinkLayerStats) _hidl_out_stats).readFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_stats);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus startRssiMonitoring(int cmdId, int maxRssi, int minRssi)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);
            _hidl_request.writeInt32(cmdId);
            _hidl_request.writeInt32(maxRssi);
            _hidl_request.writeInt32(minRssi);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* startRssiMonitoring */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus stopRssiMonitoring(int cmdId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);
            _hidl_request.writeInt32(cmdId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* stopRssiMonitoring */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getRoamingCapabilities(getRoamingCapabilitiesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* getRoamingCapabilities */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.StaRoamingCapabilities _hidl_out_caps = new android.hardware.wifi.V1_0.StaRoamingCapabilities();
                ((android.hardware.wifi.V1_0.StaRoamingCapabilities) _hidl_out_caps).readFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_caps);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus configureRoaming(android.hardware.wifi.V1_0.StaRoamingConfig config)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);
            ((android.hardware.wifi.V1_0.StaRoamingConfig) config).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* configureRoaming */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus setRoamingState(byte state)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);
            _hidl_request.writeInt8(state);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(18 /* setRoamingState */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus enableNdOffload(boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(19 /* enableNdOffload */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus startSendingKeepAlivePackets(int cmdId, java.util.ArrayList<Byte> ipPacketData, short etherType, byte[/* 6 */] srcAddress, byte[/* 6 */] dstAddress, int periodInMs)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);
            _hidl_request.writeInt32(cmdId);
            _hidl_request.writeInt8Vector(ipPacketData);
            _hidl_request.writeInt16(etherType);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) srcAddress;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) dstAddress;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeInt32(periodInMs);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(20 /* startSendingKeepAlivePackets */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus stopSendingKeepAlivePackets(int cmdId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);
            _hidl_request.writeInt32(cmdId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(21 /* stopSendingKeepAlivePackets */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus setScanningMacOui(byte[/* 3 */] oui)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(3 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 3 */]) oui;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 3) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 3 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(22 /* setScanningMacOui */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus startDebugPacketFateMonitoring()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(23 /* startDebugPacketFateMonitoring */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDebugTxPacketFates(getDebugTxPacketFatesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(24 /* getDebugTxPacketFates */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<android.hardware.wifi.V1_0.WifiDebugTxPacketFateReport> _hidl_out_fates = android.hardware.wifi.V1_0.WifiDebugTxPacketFateReport.readVectorFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_fates);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDebugRxPacketFates(getDebugRxPacketFatesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(25 /* getDebugRxPacketFates */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<android.hardware.wifi.V1_0.WifiDebugRxPacketFateReport> _hidl_out_fates = android.hardware.wifi.V1_0.WifiDebugRxPacketFateReport.readVectorFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_fates);
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::V1_2::IWifiStaIface follow.
        @Override
        public void readApfPacketFilterData(readApfPacketFilterDataCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_2.IWifiStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(26 /* readApfPacketFilterData */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Byte> _hidl_out_data = _hidl_reply.readInt8Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_data);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus setMacAddress(byte[/* 6 */] mac)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_2.IWifiStaIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) mac;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(27 /* setMacAddress */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
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

    public static abstract class Stub extends android.os.HwBinder implements IWifiStaIface {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.wifi.V1_2.IWifiStaIface.kInterfaceName,
                    android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName,
                    android.hardware.wifi.V1_0.IWifiIface.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.wifi.V1_2.IWifiStaIface.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-1,93,-40,33,-62,-57,-87,-57,-122,7,21,-100,77,120,-119,96,-73,37,72,114,99,-60,-99,-107,108,-91,-6,61,55,0,-117,69} /* ff5dd821c2c7a9c78607159c4d788960b725487263c49d956ca5fa3d37008b45 */,
                    new byte[/* 32 */]{59,-128,-109,-45,-98,-15,-31,14,67,-59,83,-118,-5,-11,-1,110,57,-72,-40,22,-114,-69,-31,-103,-115,-103,62,-119,-30,95,20,-91} /* 3b8093d39ef1e10e43c5538afbf5ff6e39b8d8168ebbe1998d993e89e25f14a5 */,
                    new byte[/* 32 */]{107,-102,-44,58,94,-5,-26,-54,33,79,117,30,34,-50,67,-49,92,-44,-43,-43,-14,-53,-88,15,36,-52,-45,117,90,114,64,28} /* 6b9ad43a5efbe6ca214f751e22ce43cf5cd4d5d5f2cba80f24ccd3755a72401c */,
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
                case 1 /* getType */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiIface.kInterfaceName);

                    getType(new getTypeCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, int type) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(type);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 2 /* getName */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiIface.kInterfaceName);

                    getName(new getNameCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, String name) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(name);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 3 /* registerEventCallback */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    android.hardware.wifi.V1_0.IWifiStaIfaceEventCallback callback = android.hardware.wifi.V1_0.IWifiStaIfaceEventCallback.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = registerEventCallback(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 4 /* getCapabilities */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    getCapabilities(new getCapabilitiesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, int capabilities) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(capabilities);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 5 /* getApfPacketFilterCapabilities */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    getApfPacketFilterCapabilities(new getApfPacketFilterCapabilitiesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.StaApfPacketFilterCapabilities capabilities) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            ((android.hardware.wifi.V1_0.StaApfPacketFilterCapabilities) capabilities).writeToParcel(_hidl_reply);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 6 /* installApfPacketFilter */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    int cmdId = _hidl_request.readInt32();
                    java.util.ArrayList<Byte> program = _hidl_request.readInt8Vector();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = installApfPacketFilter(cmdId, program);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 7 /* getBackgroundScanCapabilities */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    getBackgroundScanCapabilities(new getBackgroundScanCapabilitiesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.StaBackgroundScanCapabilities capabilities) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            ((android.hardware.wifi.V1_0.StaBackgroundScanCapabilities) capabilities).writeToParcel(_hidl_reply);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 8 /* getValidFrequenciesForBand */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    int band = _hidl_request.readInt32();
                    getValidFrequenciesForBand(band, new getValidFrequenciesForBandCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<Integer> frequencies) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32Vector(frequencies);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 9 /* startBackgroundScan */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    int cmdId = _hidl_request.readInt32();
                    android.hardware.wifi.V1_0.StaBackgroundScanParameters params = new android.hardware.wifi.V1_0.StaBackgroundScanParameters();
                    ((android.hardware.wifi.V1_0.StaBackgroundScanParameters) params).readFromParcel(_hidl_request);
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = startBackgroundScan(cmdId, params);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 10 /* stopBackgroundScan */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    int cmdId = _hidl_request.readInt32();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = stopBackgroundScan(cmdId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 11 /* enableLinkLayerStatsCollection */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    boolean debug = _hidl_request.readBool();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = enableLinkLayerStatsCollection(debug);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 12 /* disableLinkLayerStatsCollection */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = disableLinkLayerStatsCollection();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 13 /* getLinkLayerStats */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    getLinkLayerStats(new getLinkLayerStatsCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.StaLinkLayerStats stats) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            ((android.hardware.wifi.V1_0.StaLinkLayerStats) stats).writeToParcel(_hidl_reply);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 14 /* startRssiMonitoring */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    int cmdId = _hidl_request.readInt32();
                    int maxRssi = _hidl_request.readInt32();
                    int minRssi = _hidl_request.readInt32();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = startRssiMonitoring(cmdId, maxRssi, minRssi);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 15 /* stopRssiMonitoring */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    int cmdId = _hidl_request.readInt32();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = stopRssiMonitoring(cmdId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 16 /* getRoamingCapabilities */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    getRoamingCapabilities(new getRoamingCapabilitiesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.StaRoamingCapabilities caps) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            ((android.hardware.wifi.V1_0.StaRoamingCapabilities) caps).writeToParcel(_hidl_reply);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 17 /* configureRoaming */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    android.hardware.wifi.V1_0.StaRoamingConfig config = new android.hardware.wifi.V1_0.StaRoamingConfig();
                    ((android.hardware.wifi.V1_0.StaRoamingConfig) config).readFromParcel(_hidl_request);
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = configureRoaming(config);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 18 /* setRoamingState */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    byte state = _hidl_request.readInt8();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = setRoamingState(state);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 19 /* enableNdOffload */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    boolean enable = _hidl_request.readBool();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = enableNdOffload(enable);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 20 /* startSendingKeepAlivePackets */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    int cmdId = _hidl_request.readInt32();
                    java.util.ArrayList<Byte> ipPacketData = _hidl_request.readInt8Vector();
                    short etherType = _hidl_request.readInt16();
                    byte[/* 6 */] srcAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) srcAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    byte[/* 6 */] dstAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) dstAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    int periodInMs = _hidl_request.readInt32();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = startSendingKeepAlivePackets(cmdId, ipPacketData, etherType, srcAddress, dstAddress, periodInMs);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 21 /* stopSendingKeepAlivePackets */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    int cmdId = _hidl_request.readInt32();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = stopSendingKeepAlivePackets(cmdId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 22 /* setScanningMacOui */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    byte[/* 3 */] oui = new byte[3];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(3 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 3 */]) oui, 3 /* size */);
                            _hidl_array_offset_0 += 3 * 1;
                        }
                    }
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = setScanningMacOui(oui);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 23 /* startDebugPacketFateMonitoring */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = startDebugPacketFateMonitoring();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 24 /* getDebugTxPacketFates */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    getDebugTxPacketFates(new getDebugTxPacketFatesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<android.hardware.wifi.V1_0.WifiDebugTxPacketFateReport> fates) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            android.hardware.wifi.V1_0.WifiDebugTxPacketFateReport.writeVectorToParcel(_hidl_reply, fates);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 25 /* getDebugRxPacketFates */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiStaIface.kInterfaceName);

                    getDebugRxPacketFates(new getDebugRxPacketFatesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<android.hardware.wifi.V1_0.WifiDebugRxPacketFateReport> fates) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            android.hardware.wifi.V1_0.WifiDebugRxPacketFateReport.writeVectorToParcel(_hidl_reply, fates);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 26 /* readApfPacketFilterData */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_2.IWifiStaIface.kInterfaceName);

                    readApfPacketFilterData(new readApfPacketFilterDataCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<Byte> data) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt8Vector(data);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 27 /* setMacAddress */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_2.IWifiStaIface.kInterfaceName);

                    byte[/* 6 */] mac = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) mac, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = setMacAddress(mac);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
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
