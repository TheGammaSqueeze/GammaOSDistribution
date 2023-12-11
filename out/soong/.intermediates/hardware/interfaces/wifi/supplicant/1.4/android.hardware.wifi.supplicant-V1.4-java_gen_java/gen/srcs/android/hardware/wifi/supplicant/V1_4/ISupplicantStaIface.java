package android.hardware.wifi.supplicant.V1_4;

/**
 * Interface exposed by the supplicant for each station mode network
 * interface (e.g wlan0) it controls.
 */
public interface ISupplicantStaIface extends android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.wifi.supplicant@1.4::ISupplicantStaIface";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static ISupplicantStaIface asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof ISupplicantStaIface)) {
            return (ISupplicantStaIface)iface;
        }

        ISupplicantStaIface proxy = new ISupplicantStaIface.Proxy(binder);

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
    public static ISupplicantStaIface castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : ISupplicantStaIface.asInterface(iface.asBinder());
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
    public static ISupplicantStaIface getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return ISupplicantStaIface.asInterface(android.os.HwBinder.getService("android.hardware.wifi.supplicant@1.4::ISupplicantStaIface", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static ISupplicantStaIface getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static ISupplicantStaIface getService(String serviceName) throws android.os.RemoteException {
        return ISupplicantStaIface.asInterface(android.os.HwBinder.getService("android.hardware.wifi.supplicant@1.4::ISupplicantStaIface", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static ISupplicantStaIface getService() throws android.os.RemoteException {
        return getService("default");
    }


    @java.lang.FunctionalInterface
    public interface getConnectionCapabilities_1_4Callback {
        public void onValues(android.hardware.wifi.supplicant.V1_4.SupplicantStatus status, android.hardware.wifi.supplicant.V1_4.ConnectionCapabilities capabilities);
    }

    /**
     * Get Connection capabilities
     *
     * @return status Status of the operation, and connection capabilities.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     */
    void getConnectionCapabilities_1_4(getConnectionCapabilities_1_4Callback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Register for callbacks from this interface.
     *
     * These callbacks are invoked for events that are specific to this interface.
     * Registration of multiple callback objects is supported. These objects must
     * be automatically deleted when the corresponding client process is dead or
     * if this interface is removed.
     *
     * @param callback An instance of the |ISupplicantStaIfaceCallback| HIDL
     *        interface object.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_4.SupplicantStatus registerCallback_1_4(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIfaceCallback callback)
        throws android.os.RemoteException;
    /**
     * Initiate Venue URL ANQP (for IEEE 802.11u Interworking/Hotspot 2.0) query with the
     * specified access point. This specific query can be used only post connection, once security
     * is established and PMF is enabled, to avoid spoofing preassociation ANQP responses.
     * The ANQP data fetched must be returned in the
     * |ISupplicantStaIfaceCallback.onAnqpQueryDone| callback.
     *
     * @param macAddress MAC address of the access point.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_4.SupplicantStatus initiateVenueUrlAnqpQuery(byte[/* 6 */] macAddress)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getWpaDriverCapabilities_1_4Callback {
        public void onValues(android.hardware.wifi.supplicant.V1_4.SupplicantStatus status, int driverCapabilitiesMask);
    }

    /**
     * Get wpa driver capabilities.
     *
     * @return status Status of the operation, and a bitmap of wpa driver features.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     */
    void getWpaDriverCapabilities_1_4(getWpaDriverCapabilities_1_4Callback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface generateDppBootstrapInfoForResponderCallback {
        public void onValues(android.hardware.wifi.supplicant.V1_4.SupplicantStatus status, android.hardware.wifi.supplicant.V1_4.DppResponderBootstrapInfo bootstrapInfo);
    }

    /**
     * Generates DPP bootstrap information: Bootstrap ID, DPP URI and listen
     * channel for responder mode.
     *
     * @param MacAddress MAC address of the interface for the DPP operation.
     * @param deviceInfo Device specific information.
     *        As per DPP Specification V1.0 section 5.2,
     *        allowed Range of ASCII characters in deviceInfo - %x20-7E
     *        semicolon is not allowed.
     * @param DppCurve Elliptic curve cryptography type used to generate DPP
     * public/private key pair.
     * @return status of operation and bootstrap info.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|
     *         |SupplicantStatusCode.FAILURE_UNSUPPORTED|
     */
    void generateDppBootstrapInfoForResponder(byte[/* 6 */] macAddress, String deviceInfo, int curve, generateDppBootstrapInfoForResponderCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Start DPP in Enrollee-Responder mode.
     * Framework must first call |generateDppBootstrapInfoForResponder| to generate
     * the bootstrapping information: Bootstrap ID, DPP URI and the listen channel.
     * Then call this API with derived listen channel to start listening for
     * authentication request from Peer initiator.
     *
     * @param listenChannel DPP listen channel.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     *         |SupplicantStatusCode.FAILURE_UNSUPPORTED|
     */
    android.hardware.wifi.supplicant.V1_4.SupplicantStatus startDppEnrolleeResponder(int listenChannel)
        throws android.os.RemoteException;
    /**
     * Stop DPP Responder operation - Remove the bootstrap code and stop listening.
     *
     * @param ownBootstrapId Local device's URI ID obtained through
     *        |generateDppBootstrapInfoForResponder| call.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     *         |SupplicantStatusCode.FAILURE_UNSUPPORTED|
     */
    android.hardware.wifi.supplicant.V1_4.SupplicantStatus stopDppResponder(int ownBootstrapId)
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

    public static final class Proxy implements ISupplicantStaIface {
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
            return "[class or subclass of " + ISupplicantStaIface.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_0::ISupplicantIface follow.
        @Override
        public void getName(getNameCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* getName */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_name = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_name);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getType(getTypeCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* getType */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_type = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_type);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void addNetwork(addNetworkCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* addNetwork */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork _hidl_out_network = android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_network);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus removeNetwork(int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* removeNetwork */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getNetwork(int id, getNetworkCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* getNetwork */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork _hidl_out_network = android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_network);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void listNetworks(listNetworksCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* listNetworks */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Integer> _hidl_out_networkIds = _hidl_reply.readInt32Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_networkIds);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWpsDeviceName(String name)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeString(name);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* setWpsDeviceName */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWpsDeviceType(byte[/* 8 */] type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(8 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 8 */]) type;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 8) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 8 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* setWpsDeviceType */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWpsManufacturer(String manufacturer)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeString(manufacturer);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* setWpsManufacturer */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWpsModelName(String modelName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeString(modelName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* setWpsModelName */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWpsModelNumber(String modelNumber)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeString(modelNumber);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* setWpsModelNumber */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWpsSerialNumber(String serialNumber)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeString(serialNumber);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* setWpsSerialNumber */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWpsConfigMethods(short configMethods)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeInt16(configMethods);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* setWpsConfigMethods */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaIface follow.
        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus registerCallback(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* registerCallback */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus reassociate()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* reassociate */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus reconnect()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* reconnect */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus disconnect()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* disconnect */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setPowerSave(boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(18 /* setPowerSave */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus initiateTdlsDiscover(byte[/* 6 */] macAddress)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) macAddress;

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
                mRemote.transact(19 /* initiateTdlsDiscover */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus initiateTdlsSetup(byte[/* 6 */] macAddress)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) macAddress;

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
                mRemote.transact(20 /* initiateTdlsSetup */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus initiateTdlsTeardown(byte[/* 6 */] macAddress)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) macAddress;

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
                mRemote.transact(21 /* initiateTdlsTeardown */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus initiateAnqpQuery(byte[/* 6 */] macAddress, java.util.ArrayList<Short> infoElements, java.util.ArrayList<Integer> subTypes)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) macAddress;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeInt16Vector(infoElements);
            _hidl_request.writeInt32Vector(subTypes);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(22 /* initiateAnqpQuery */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus initiateHs20IconQuery(byte[/* 6 */] macAddress, String fileName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) macAddress;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeString(fileName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(23 /* initiateHs20IconQuery */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getMacAddress(getMacAddressCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(24 /* getMacAddress */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                byte[/* 6 */] _hidl_out_macAddr = new byte[6];
                {
                    android.os.HwBlob _hidl_blob = _hidl_reply.readBuffer(6 /* size */);
                    {
                        long _hidl_array_offset_0 = 0 /* offset */;
                        _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) _hidl_out_macAddr, 6 /* size */);
                        _hidl_array_offset_0 += 6 * 1;
                    }
                }
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_macAddr);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus startRxFilter()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(25 /* startRxFilter */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus stopRxFilter()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(26 /* stopRxFilter */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus addRxFilter(byte type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeInt8(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(27 /* addRxFilter */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus removeRxFilter(byte type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeInt8(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(28 /* removeRxFilter */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setBtCoexistenceMode(byte mode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeInt8(mode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(29 /* setBtCoexistenceMode */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setBtCoexistenceScanModeEnabled(boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(30 /* setBtCoexistenceScanModeEnabled */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setSuspendModeEnabled(boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(31 /* setSuspendModeEnabled */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setCountryCode(byte[/* 2 */] code)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(2 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 2 */]) code;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 2) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 2 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(32 /* setCountryCode */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus startWpsRegistrar(byte[/* 6 */] bssid, String pin)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeString(pin);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(33 /* startWpsRegistrar */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus startWpsPbc(byte[/* 6 */] bssid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

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
                mRemote.transact(34 /* startWpsPbc */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus startWpsPinKeypad(String pin)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeString(pin);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(35 /* startWpsPinKeypad */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void startWpsPinDisplay(byte[/* 6 */] bssid, startWpsPinDisplayCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

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
                mRemote.transact(36 /* startWpsPinDisplay */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_generatedPin = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_generatedPin);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus cancelWps()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(37 /* cancelWps */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setExternalSim(boolean useExternalSim)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeBool(useExternalSim);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(38 /* setExternalSim */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void addExtRadioWork(String name, int freqInMhz, int timeoutInSec, addExtRadioWorkCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeString(name);
            _hidl_request.writeInt32(freqInMhz);
            _hidl_request.writeInt32(timeoutInSec);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(39 /* addExtRadioWork */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_id = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_id);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus removeExtRadioWork(int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(40 /* removeExtRadioWork */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus enableAutoReconnect(boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(41 /* enableAutoReconnect */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIface follow.
        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus registerCallback_1_1(android.hardware.wifi.supplicant.V1_1.ISupplicantStaIfaceCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_1.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(42 /* registerCallback_1_1 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_2::ISupplicantStaIface follow.
        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus registerCallback_1_2(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIfaceCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(43 /* registerCallback_1_2 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getKeyMgmtCapabilities(getKeyMgmtCapabilitiesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(44 /* getKeyMgmtCapabilities */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_keyMgmtMask = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_keyMgmtMask);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void addDppPeerUri(String uri, addDppPeerUriCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeString(uri);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(45 /* addDppPeerUri */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_id = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_id);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus removeDppUri(int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(46 /* removeDppUri */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus startDppConfiguratorInitiator(int peerBootstrapId, int ownBootstrapId, String ssid, String password, String psk, int netRole, int securityAkm)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeInt32(peerBootstrapId);
            _hidl_request.writeInt32(ownBootstrapId);
            _hidl_request.writeString(ssid);
            _hidl_request.writeString(password);
            _hidl_request.writeString(psk);
            _hidl_request.writeInt32(netRole);
            _hidl_request.writeInt32(securityAkm);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(47 /* startDppConfiguratorInitiator */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus startDppEnrolleeInitiator(int peerBootstrapId, int ownBootstrapId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeInt32(peerBootstrapId);
            _hidl_request.writeInt32(ownBootstrapId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(48 /* startDppEnrolleeInitiator */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus stopDppInitiator()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(49 /* stopDppInitiator */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_3::ISupplicantStaIface follow.
        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus registerCallback_1_3(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(50 /* registerCallback_1_3 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getConnectionCapabilities(getConnectionCapabilitiesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(51 /* getConnectionCapabilities */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.supplicant.V1_3.ConnectionCapabilities _hidl_out_capabilities = new android.hardware.wifi.supplicant.V1_3.ConnectionCapabilities();
                ((android.hardware.wifi.supplicant.V1_3.ConnectionCapabilities) _hidl_out_capabilities).readFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_capabilities);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getWpaDriverCapabilities(getWpaDriverCapabilitiesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(52 /* getWpaDriverCapabilities */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_driverCapabilitiesMask = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_driverCapabilitiesMask);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setMboCellularDataStatus(boolean available)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeBool(available);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(53 /* setMboCellularDataStatus */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getKeyMgmtCapabilities_1_3(getKeyMgmtCapabilities_1_3Callback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(54 /* getKeyMgmtCapabilities_1_3 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_keyMgmtMask = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_keyMgmtMask);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus filsHlpFlushRequest()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(55 /* filsHlpFlushRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus filsHlpAddRequest(byte[/* 6 */] dst_mac, java.util.ArrayList<Byte> pkt)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) dst_mac;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeInt8Vector(pkt);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(56 /* filsHlpAddRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_4::ISupplicantStaIface follow.
        @Override
        public void getConnectionCapabilities_1_4(getConnectionCapabilities_1_4Callback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(57 /* getConnectionCapabilities_1_4 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_4.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_4.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_4.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.supplicant.V1_4.ConnectionCapabilities _hidl_out_capabilities = new android.hardware.wifi.supplicant.V1_4.ConnectionCapabilities();
                ((android.hardware.wifi.supplicant.V1_4.ConnectionCapabilities) _hidl_out_capabilities).readFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_capabilities);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_4.SupplicantStatus registerCallback_1_4(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIfaceCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(58 /* registerCallback_1_4 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_4.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_4.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_4.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_4.SupplicantStatus initiateVenueUrlAnqpQuery(byte[/* 6 */] macAddress)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) macAddress;

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
                mRemote.transact(59 /* initiateVenueUrlAnqpQuery */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_4.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_4.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_4.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getWpaDriverCapabilities_1_4(getWpaDriverCapabilities_1_4Callback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(60 /* getWpaDriverCapabilities_1_4 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_4.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_4.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_4.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_driverCapabilitiesMask = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_driverCapabilitiesMask);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void generateDppBootstrapInfoForResponder(byte[/* 6 */] macAddress, String deviceInfo, int curve, generateDppBootstrapInfoForResponderCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) macAddress;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeString(deviceInfo);
            _hidl_request.writeInt32(curve);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(61 /* generateDppBootstrapInfoForResponder */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_4.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_4.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_4.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.supplicant.V1_4.DppResponderBootstrapInfo _hidl_out_bootstrapInfo = new android.hardware.wifi.supplicant.V1_4.DppResponderBootstrapInfo();
                ((android.hardware.wifi.supplicant.V1_4.DppResponderBootstrapInfo) _hidl_out_bootstrapInfo).readFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_bootstrapInfo);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_4.SupplicantStatus startDppEnrolleeResponder(int listenChannel)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeInt32(listenChannel);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(62 /* startDppEnrolleeResponder */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_4.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_4.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_4.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_4.SupplicantStatus stopDppResponder(int ownBootstrapId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName);
            _hidl_request.writeInt32(ownBootstrapId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(63 /* stopDppResponder */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_4.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_4.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_4.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
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

    public static abstract class Stub extends android.os.HwBinder implements ISupplicantStaIface {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName,
                    android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName,
                    android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName,
                    android.hardware.wifi.supplicant.V1_1.ISupplicantStaIface.kInterfaceName,
                    android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName,
                    android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{2,107,-102,70,101,-114,-24,43,21,78,-26,36,-83,-61,10,69,79,100,1,35,13,-75,-21,68,110,-83,66,-25,-17,81,-4,-128} /* 026b9a46658ee82b154ee624adc30a454f6401230db5eb446ead42e7ef51fc80 */,
                    new byte[/* 32 */]{21,-99,72,-55,-17,-72,-127,-12,77,93,-19,-88,-111,123,-119,-5,77,-94,104,55,-16,25,68,109,109,115,-73,62,-91,1,14,-54} /* 159d48c9efb881f44d5deda8917b89fb4da26837f019446d6d73b73ea5010eca */,
                    new byte[/* 32 */]{126,-2,43,5,126,-97,-109,-121,-77,80,14,103,-81,-105,-108,42,-89,-56,0,-114,110,-25,-40,-36,-86,-28,16,127,-38,-124,1,107} /* 7efe2b057e9f9387b3500e67af97942aa7c8008e6ee7d8dcaae4107fda84016b */,
                    new byte[/* 32 */]{33,117,125,14,93,-44,-73,-28,-67,-104,26,74,32,83,27,-54,60,50,39,26,-39,119,123,23,-73,78,-75,-95,-22,80,-125,-124} /* 21757d0e5dd4b7e4bd981a4a20531bca3c32271ad9777b17b74eb5a1ea508384 */,
                    new byte[/* 32 */]{119,82,-31,-34,-109,-86,-11,-2,-45,112,17,-62,25,-84,36,112,105,-10,-81,50,11,8,16,-38,-87,-123,16,88,74,16,-25,-76} /* 7752e1de93aaf5fed37011c219ac247069f6af320b0810daa98510584a10e7b4 */,
                    new byte[/* 32 */]{53,-70,123,-51,-15,-113,36,-88,102,-89,-27,66,-107,72,-16,103,104,-69,32,-94,87,-9,91,16,-93,-105,-60,-40,37,-17,-124,56} /* 35ba7bcdf18f24a866a7e5429548f06768bb20a257f75b10a397c4d825ef8438 */,
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
                case 1 /* getName */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    getName(new getNameCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String name) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(name);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 2 /* getType */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    getType(new getTypeCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int type) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(type);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 3 /* addNetwork */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    addNetwork(new addNetworkCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork network) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(network == null ? null : network.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 4 /* removeNetwork */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = removeNetwork(id);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 5 /* getNetwork */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    getNetwork(id, new getNetworkCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork network) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(network == null ? null : network.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 6 /* listNetworks */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    listNetworks(new listNetworksCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, java.util.ArrayList<Integer> networkIds) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32Vector(networkIds);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 7 /* setWpsDeviceName */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    String name = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWpsDeviceName(name);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 8 /* setWpsDeviceType */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    byte[/* 8 */] type = new byte[8];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(8 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 8 */]) type, 8 /* size */);
                            _hidl_array_offset_0 += 8 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWpsDeviceType(type);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 9 /* setWpsManufacturer */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    String manufacturer = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWpsManufacturer(manufacturer);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 10 /* setWpsModelName */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    String modelName = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWpsModelName(modelName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 11 /* setWpsModelNumber */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    String modelNumber = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWpsModelNumber(modelNumber);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 12 /* setWpsSerialNumber */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    String serialNumber = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWpsSerialNumber(serialNumber);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 13 /* setWpsConfigMethods */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    short configMethods = _hidl_request.readInt16();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWpsConfigMethods(configMethods);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 14 /* registerCallback */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback callback = android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = registerCallback(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 15 /* reassociate */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = reassociate();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 16 /* reconnect */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = reconnect();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 17 /* disconnect */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = disconnect();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 18 /* setPowerSave */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    boolean enable = _hidl_request.readBool();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setPowerSave(enable);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 19 /* initiateTdlsDiscover */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    byte[/* 6 */] macAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) macAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = initiateTdlsDiscover(macAddress);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 20 /* initiateTdlsSetup */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    byte[/* 6 */] macAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) macAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = initiateTdlsSetup(macAddress);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 21 /* initiateTdlsTeardown */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    byte[/* 6 */] macAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) macAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = initiateTdlsTeardown(macAddress);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 22 /* initiateAnqpQuery */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    byte[/* 6 */] macAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) macAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    java.util.ArrayList<Short> infoElements = _hidl_request.readInt16Vector();
                    java.util.ArrayList<Integer> subTypes = _hidl_request.readInt32Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = initiateAnqpQuery(macAddress, infoElements, subTypes);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 23 /* initiateHs20IconQuery */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    byte[/* 6 */] macAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) macAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    String fileName = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = initiateHs20IconQuery(macAddress, fileName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 24 /* getMacAddress */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    getMacAddress(new getMacAddressCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, byte[/* 6 */] macAddr) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            {
                                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                                {
                                    long _hidl_array_offset_0 = 0 /* offset */;
                                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) macAddr;

                                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                                        throw new IllegalArgumentException("Array element is not of the expected length");
                                    }

                                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                                    _hidl_array_offset_0 += 6 * 1;
                                }
                                _hidl_reply.writeBuffer(_hidl_blob);
                            }
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 25 /* startRxFilter */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = startRxFilter();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 26 /* stopRxFilter */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = stopRxFilter();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 27 /* addRxFilter */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    byte type = _hidl_request.readInt8();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = addRxFilter(type);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 28 /* removeRxFilter */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    byte type = _hidl_request.readInt8();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = removeRxFilter(type);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 29 /* setBtCoexistenceMode */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    byte mode = _hidl_request.readInt8();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setBtCoexistenceMode(mode);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 30 /* setBtCoexistenceScanModeEnabled */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    boolean enable = _hidl_request.readBool();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setBtCoexistenceScanModeEnabled(enable);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 31 /* setSuspendModeEnabled */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    boolean enable = _hidl_request.readBool();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setSuspendModeEnabled(enable);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 32 /* setCountryCode */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    byte[/* 2 */] code = new byte[2];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(2 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 2 */]) code, 2 /* size */);
                            _hidl_array_offset_0 += 2 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setCountryCode(code);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 33 /* startWpsRegistrar */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    String pin = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = startWpsRegistrar(bssid, pin);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 34 /* startWpsPbc */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = startWpsPbc(bssid);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 35 /* startWpsPinKeypad */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    String pin = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = startWpsPinKeypad(pin);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 36 /* startWpsPinDisplay */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    startWpsPinDisplay(bssid, new startWpsPinDisplayCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String generatedPin) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(generatedPin);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 37 /* cancelWps */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = cancelWps();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 38 /* setExternalSim */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    boolean useExternalSim = _hidl_request.readBool();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setExternalSim(useExternalSim);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 39 /* addExtRadioWork */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    String name = _hidl_request.readString();
                    int freqInMhz = _hidl_request.readInt32();
                    int timeoutInSec = _hidl_request.readInt32();
                    addExtRadioWork(name, freqInMhz, timeoutInSec, new addExtRadioWorkCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int id) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(id);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 40 /* removeExtRadioWork */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = removeExtRadioWork(id);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 41 /* enableAutoReconnect */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIface.kInterfaceName);

                    boolean enable = _hidl_request.readBool();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = enableAutoReconnect(enable);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 42 /* registerCallback_1_1 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_1.ISupplicantStaIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_1.ISupplicantStaIfaceCallback callback = android.hardware.wifi.supplicant.V1_1.ISupplicantStaIfaceCallback.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = registerCallback_1_1(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 43 /* registerCallback_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_2.ISupplicantStaIfaceCallback callback = android.hardware.wifi.supplicant.V1_2.ISupplicantStaIfaceCallback.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = registerCallback_1_2(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 44 /* getKeyMgmtCapabilities */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName);

                    getKeyMgmtCapabilities(new getKeyMgmtCapabilitiesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int keyMgmtMask) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(keyMgmtMask);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 45 /* addDppPeerUri */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName);

                    String uri = _hidl_request.readString();
                    addDppPeerUri(uri, new addDppPeerUriCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int id) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(id);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 46 /* removeDppUri */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = removeDppUri(id);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 47 /* startDppConfiguratorInitiator */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName);

                    int peerBootstrapId = _hidl_request.readInt32();
                    int ownBootstrapId = _hidl_request.readInt32();
                    String ssid = _hidl_request.readString();
                    String password = _hidl_request.readString();
                    String psk = _hidl_request.readString();
                    int netRole = _hidl_request.readInt32();
                    int securityAkm = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = startDppConfiguratorInitiator(peerBootstrapId, ownBootstrapId, ssid, password, psk, netRole, securityAkm);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 48 /* startDppEnrolleeInitiator */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName);

                    int peerBootstrapId = _hidl_request.readInt32();
                    int ownBootstrapId = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = startDppEnrolleeInitiator(peerBootstrapId, ownBootstrapId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 49 /* stopDppInitiator */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = stopDppInitiator();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 50 /* registerCallback_1_3 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback callback = android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = registerCallback_1_3(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 51 /* getConnectionCapabilities */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName);

                    getConnectionCapabilities(new getConnectionCapabilitiesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, android.hardware.wifi.supplicant.V1_3.ConnectionCapabilities capabilities) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            ((android.hardware.wifi.supplicant.V1_3.ConnectionCapabilities) capabilities).writeToParcel(_hidl_reply);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 52 /* getWpaDriverCapabilities */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName);

                    getWpaDriverCapabilities(new getWpaDriverCapabilitiesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int driverCapabilitiesMask) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(driverCapabilitiesMask);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 53 /* setMboCellularDataStatus */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName);

                    boolean available = _hidl_request.readBool();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setMboCellularDataStatus(available);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 54 /* getKeyMgmtCapabilities_1_3 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName);

                    getKeyMgmtCapabilities_1_3(new getKeyMgmtCapabilities_1_3Callback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int keyMgmtMask) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(keyMgmtMask);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 55 /* filsHlpFlushRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = filsHlpFlushRequest();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 56 /* filsHlpAddRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIface.kInterfaceName);

                    byte[/* 6 */] dst_mac = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) dst_mac, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    java.util.ArrayList<Byte> pkt = _hidl_request.readInt8Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = filsHlpAddRequest(dst_mac, pkt);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 57 /* getConnectionCapabilities_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName);

                    getConnectionCapabilities_1_4(new getConnectionCapabilities_1_4Callback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_4.SupplicantStatus status, android.hardware.wifi.supplicant.V1_4.ConnectionCapabilities capabilities) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_4.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            ((android.hardware.wifi.supplicant.V1_4.ConnectionCapabilities) capabilities).writeToParcel(_hidl_reply);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 58 /* registerCallback_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_4.ISupplicantStaIfaceCallback callback = android.hardware.wifi.supplicant.V1_4.ISupplicantStaIfaceCallback.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.wifi.supplicant.V1_4.SupplicantStatus _hidl_out_status = registerCallback_1_4(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_4.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 59 /* initiateVenueUrlAnqpQuery */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName);

                    byte[/* 6 */] macAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) macAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_4.SupplicantStatus _hidl_out_status = initiateVenueUrlAnqpQuery(macAddress);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_4.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 60 /* getWpaDriverCapabilities_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName);

                    getWpaDriverCapabilities_1_4(new getWpaDriverCapabilities_1_4Callback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_4.SupplicantStatus status, int driverCapabilitiesMask) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_4.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(driverCapabilitiesMask);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 61 /* generateDppBootstrapInfoForResponder */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName);

                    byte[/* 6 */] macAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) macAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    String deviceInfo = _hidl_request.readString();
                    int curve = _hidl_request.readInt32();
                    generateDppBootstrapInfoForResponder(macAddress, deviceInfo, curve, new generateDppBootstrapInfoForResponderCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_4.SupplicantStatus status, android.hardware.wifi.supplicant.V1_4.DppResponderBootstrapInfo bootstrapInfo) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_4.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            ((android.hardware.wifi.supplicant.V1_4.DppResponderBootstrapInfo) bootstrapInfo).writeToParcel(_hidl_reply);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 62 /* startDppEnrolleeResponder */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName);

                    int listenChannel = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_4.SupplicantStatus _hidl_out_status = startDppEnrolleeResponder(listenChannel);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_4.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 63 /* stopDppResponder */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_4.ISupplicantStaIface.kInterfaceName);

                    int ownBootstrapId = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_4.SupplicantStatus _hidl_out_status = stopDppResponder(ownBootstrapId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_4.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
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
