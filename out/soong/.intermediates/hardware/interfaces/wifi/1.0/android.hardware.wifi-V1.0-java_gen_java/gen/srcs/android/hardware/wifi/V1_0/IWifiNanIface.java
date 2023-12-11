package android.hardware.wifi.V1_0;

/**
 * Interface used to represent a single NAN(Neighbour Aware Network) iface.
 *
 * References to "NAN Spec" are to the Wi-Fi Alliance "Wi-Fi Neighbor Awareness
 * Networking (NAN) Technical Specification".
 */
public interface IWifiNanIface extends android.hardware.wifi.V1_0.IWifiIface {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.wifi@1.0::IWifiNanIface";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IWifiNanIface asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IWifiNanIface)) {
            return (IWifiNanIface)iface;
        }

        IWifiNanIface proxy = new IWifiNanIface.Proxy(binder);

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
    public static IWifiNanIface castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IWifiNanIface.asInterface(iface.asBinder());
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
    public static IWifiNanIface getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IWifiNanIface.asInterface(android.os.HwBinder.getService("android.hardware.wifi@1.0::IWifiNanIface", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IWifiNanIface getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IWifiNanIface getService(String serviceName) throws android.os.RemoteException {
        return IWifiNanIface.asInterface(android.os.HwBinder.getService("android.hardware.wifi@1.0::IWifiNanIface", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IWifiNanIface getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Requests notifications of significant events on this iface. Multiple calls
     * to this must register multiple callbacks each of which must receive all
     * events.
     *
     * @param callback An instance of the |IWifiNanIfaceEventCallback| HIDL interface
     *        object.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|
     */
    android.hardware.wifi.V1_0.WifiStatus registerEventCallback(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback callback)
        throws android.os.RemoteException;
    /**
     * Get NAN capabilities. Asynchronous response is with
     * |IWifiNanIfaceEventCallback.notifyCapabilitiesResponse|.
     *
     * @param cmdId command Id to use for this invocation.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus getCapabilitiesRequest(short cmdId)
        throws android.os.RemoteException;
    /**
     * Enable NAN: configures and activates NAN clustering (does not start
     * a discovery session or set up data-interfaces or data-paths). Use the
     * |IWifiNanIface.configureRequest| method to change the configuration of an already enabled
     * NAN interface.
     * Asynchronous response is with |IWifiNanIfaceEventCallback.notifyEnableResponse|.
     *
     * @param cmdId command Id to use for this invocation.
     * @param msg Instance of |NanEnableRequest|.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus enableRequest(short cmdId, android.hardware.wifi.V1_0.NanEnableRequest msg)
        throws android.os.RemoteException;
    /**
     * Configure NAN: configures an existing NAN functionality (i.e. assumes
     * |IWifiNanIface.enableRequest| already submitted and succeeded).
     * Asynchronous response is with |IWifiNanIfaceEventCallback.notifyConfigResponse|.
     *
     * @param cmdId command Id to use for this invocation.
     * @param msg Instance of |NanConfigRequest|.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus configRequest(short cmdId, android.hardware.wifi.V1_0.NanConfigRequest msg)
        throws android.os.RemoteException;
    /**
     * Disable NAN functionality.
     * Asynchronous response is with |IWifiNanIfaceEventCallback.notifyDisableResponse|.
     *
     * @param cmdId command Id to use for this invocation.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus disableRequest(short cmdId)
        throws android.os.RemoteException;
    /**
     * Publish request to start advertising a discovery service.
     * Asynchronous response is with |IWifiNanIfaceEventCallback.notifyStartPublishResponse|.
     *
     * @param cmdId command Id to use for this invocation.
     * @param msg Instance of |NanPublishRequest|.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus startPublishRequest(short cmdId, android.hardware.wifi.V1_0.NanPublishRequest msg)
        throws android.os.RemoteException;
    /**
     * Stop publishing a discovery service.
     * Asynchronous response is with |IWifiNanIfaceEventCallback.notifyStopPublishResponse|.
     *
     * @param cmdId command Id to use for this invocation.
     * @param sessionId ID of the publish discovery session to be stopped.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus stopPublishRequest(short cmdId, byte sessionId)
        throws android.os.RemoteException;
    /**
     * Subscribe request to start searching for a discovery service.
     * Asynchronous response is with |IWifiNanIfaceEventCallback.notifyStartSubscribeResponse|.
     *
     * @param cmdId command Id to use for this invocation.
     * @param msg Instance of |NanSubscribeRequest|.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus startSubscribeRequest(short cmdId, android.hardware.wifi.V1_0.NanSubscribeRequest msg)
        throws android.os.RemoteException;
    /**
     * Stop subscribing to a discovery service.
     * Asynchronous response is with |IWifiNanIfaceEventCallback.notifyStopSubscribeResponse|.
     *
     * @param cmdId command Id to use for this invocation.
     * @param sessionId ID of the subscribe discovery session to be stopped.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus stopSubscribeRequest(short cmdId, byte sessionId)
        throws android.os.RemoteException;
    /**
     * NAN transmit follow up message request.
     * Asynchronous response is with |IWifiNanIfaceEventCallback.notifyTransmitFollowupResponse|.
     *
     * @param cmdId command Id to use for this invocation.
     * @param msg Instance of |NanTransmitFollowupRequest|.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus transmitFollowupRequest(short cmdId, android.hardware.wifi.V1_0.NanTransmitFollowupRequest msg)
        throws android.os.RemoteException;
    /**
     * Create a NAN Data Interface.
     * Asynchronous response is with |IWifiNanIfaceEventCallback.notifyCreateDataInterfaceResponse|.
     *
     * @param cmdId command Id to use for this invocation.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus createDataInterfaceRequest(short cmdId, String ifaceName)
        throws android.os.RemoteException;
    /**
     * Delete a NAN Data Interface.
     * Asynchronous response is with |IWifiNanIfaceEventCallback.notifyDeleteDataInterfaceResponse|.
     *
     * @param cmdId command Id to use for this invocation.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus deleteDataInterfaceRequest(short cmdId, String ifaceName)
        throws android.os.RemoteException;
    /**
     * Initiate a data-path (NDP) setup operation: Initiator.
     * Asynchronous response is with |IWifiNanIfaceEventCallback.notifyInitiateDataPathResponse|.
     *
     * @param cmdId command Id to use for this invocation.
     * @param msg Instance of |NanInitiateDataPathRequest|.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus initiateDataPathRequest(short cmdId, android.hardware.wifi.V1_0.NanInitiateDataPathRequest msg)
        throws android.os.RemoteException;
    /**
     * Respond to a received data indication as part of a data-path (NDP) setup operation. An
     * indication is received by the Responder from the Initiator.
     * Asynchronous response is with
     * |IWifiNanIfaceEventCallback.notifyRespondToDataPathIndicationResponse|.
     *
     * @param cmdId command Id to use for this invocation.
     * @param msg Instance of |NanRespondToDataPathIndicationRequest|.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus respondToDataPathIndicationRequest(short cmdId, android.hardware.wifi.V1_0.NanRespondToDataPathIndicationRequest msg)
        throws android.os.RemoteException;
    /**
     * Data-path (NDP) termination request: executed by either Initiator or Responder.
     * Asynchronous response is with |IWifiNanIfaceEventCallback.notifyTerminateDataPathResponse|.
     *
     * @param cmdId command Id to use for this invocation.
     * @param ndpInstanceId Data-path instance ID to be terminated.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus terminateDataPathRequest(short cmdId, int ndpInstanceId)
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

    public static final class Proxy implements IWifiNanIface {
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
            return "[class or subclass of " + IWifiNanIface.kInterfaceName + "]@Proxy";
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

        // Methods from ::android::hardware::wifi::V1_0::IWifiNanIface follow.
        @Override
        public android.hardware.wifi.V1_0.WifiStatus registerEventCallback(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
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
        public android.hardware.wifi.V1_0.WifiStatus getCapabilitiesRequest(short cmdId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
            _hidl_request.writeInt16(cmdId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* getCapabilitiesRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
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
        public android.hardware.wifi.V1_0.WifiStatus enableRequest(short cmdId, android.hardware.wifi.V1_0.NanEnableRequest msg)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
            _hidl_request.writeInt16(cmdId);
            ((android.hardware.wifi.V1_0.NanEnableRequest) msg).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* enableRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
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
        public android.hardware.wifi.V1_0.WifiStatus configRequest(short cmdId, android.hardware.wifi.V1_0.NanConfigRequest msg)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
            _hidl_request.writeInt16(cmdId);
            ((android.hardware.wifi.V1_0.NanConfigRequest) msg).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* configRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
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
        public android.hardware.wifi.V1_0.WifiStatus disableRequest(short cmdId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
            _hidl_request.writeInt16(cmdId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* disableRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
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
        public android.hardware.wifi.V1_0.WifiStatus startPublishRequest(short cmdId, android.hardware.wifi.V1_0.NanPublishRequest msg)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
            _hidl_request.writeInt16(cmdId);
            ((android.hardware.wifi.V1_0.NanPublishRequest) msg).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* startPublishRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
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
        public android.hardware.wifi.V1_0.WifiStatus stopPublishRequest(short cmdId, byte sessionId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
            _hidl_request.writeInt16(cmdId);
            _hidl_request.writeInt8(sessionId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* stopPublishRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
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
        public android.hardware.wifi.V1_0.WifiStatus startSubscribeRequest(short cmdId, android.hardware.wifi.V1_0.NanSubscribeRequest msg)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
            _hidl_request.writeInt16(cmdId);
            ((android.hardware.wifi.V1_0.NanSubscribeRequest) msg).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* startSubscribeRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
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
        public android.hardware.wifi.V1_0.WifiStatus stopSubscribeRequest(short cmdId, byte sessionId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
            _hidl_request.writeInt16(cmdId);
            _hidl_request.writeInt8(sessionId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* stopSubscribeRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
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
        public android.hardware.wifi.V1_0.WifiStatus transmitFollowupRequest(short cmdId, android.hardware.wifi.V1_0.NanTransmitFollowupRequest msg)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
            _hidl_request.writeInt16(cmdId);
            ((android.hardware.wifi.V1_0.NanTransmitFollowupRequest) msg).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* transmitFollowupRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
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
        public android.hardware.wifi.V1_0.WifiStatus createDataInterfaceRequest(short cmdId, String ifaceName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
            _hidl_request.writeInt16(cmdId);
            _hidl_request.writeString(ifaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* createDataInterfaceRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
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
        public android.hardware.wifi.V1_0.WifiStatus deleteDataInterfaceRequest(short cmdId, String ifaceName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
            _hidl_request.writeInt16(cmdId);
            _hidl_request.writeString(ifaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* deleteDataInterfaceRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
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
        public android.hardware.wifi.V1_0.WifiStatus initiateDataPathRequest(short cmdId, android.hardware.wifi.V1_0.NanInitiateDataPathRequest msg)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
            _hidl_request.writeInt16(cmdId);
            ((android.hardware.wifi.V1_0.NanInitiateDataPathRequest) msg).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* initiateDataPathRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
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
        public android.hardware.wifi.V1_0.WifiStatus respondToDataPathIndicationRequest(short cmdId, android.hardware.wifi.V1_0.NanRespondToDataPathIndicationRequest msg)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
            _hidl_request.writeInt16(cmdId);
            ((android.hardware.wifi.V1_0.NanRespondToDataPathIndicationRequest) msg).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* respondToDataPathIndicationRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
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
        public android.hardware.wifi.V1_0.WifiStatus terminateDataPathRequest(short cmdId, int ndpInstanceId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);
            _hidl_request.writeInt16(cmdId);
            _hidl_request.writeInt32(ndpInstanceId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* terminateDataPathRequest */, _hidl_request, _hidl_reply, 0 /* flags */);
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

    public static abstract class Stub extends android.os.HwBinder implements IWifiNanIface {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName,
                    android.hardware.wifi.V1_0.IWifiIface.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-70,90,-89,79,27,-89,20,-16,9,56,100,34,121,35,73,40,8,121,91,-38,97,-103,-60,-22,8,-111,50,45,39,-8,-55,49} /* ba5aa74f1ba714f0093864227923492808795bda6199c4ea0891322d27f8c931 */,
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
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback callback = android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = registerEventCallback(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 4 /* getCapabilitiesRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    short cmdId = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = getCapabilitiesRequest(cmdId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 5 /* enableRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    short cmdId = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.NanEnableRequest msg = new android.hardware.wifi.V1_0.NanEnableRequest();
                    ((android.hardware.wifi.V1_0.NanEnableRequest) msg).readFromParcel(_hidl_request);
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = enableRequest(cmdId, msg);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 6 /* configRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    short cmdId = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.NanConfigRequest msg = new android.hardware.wifi.V1_0.NanConfigRequest();
                    ((android.hardware.wifi.V1_0.NanConfigRequest) msg).readFromParcel(_hidl_request);
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = configRequest(cmdId, msg);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 7 /* disableRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    short cmdId = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = disableRequest(cmdId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 8 /* startPublishRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    short cmdId = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.NanPublishRequest msg = new android.hardware.wifi.V1_0.NanPublishRequest();
                    ((android.hardware.wifi.V1_0.NanPublishRequest) msg).readFromParcel(_hidl_request);
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = startPublishRequest(cmdId, msg);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 9 /* stopPublishRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    short cmdId = _hidl_request.readInt16();
                    byte sessionId = _hidl_request.readInt8();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = stopPublishRequest(cmdId, sessionId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 10 /* startSubscribeRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    short cmdId = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.NanSubscribeRequest msg = new android.hardware.wifi.V1_0.NanSubscribeRequest();
                    ((android.hardware.wifi.V1_0.NanSubscribeRequest) msg).readFromParcel(_hidl_request);
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = startSubscribeRequest(cmdId, msg);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 11 /* stopSubscribeRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    short cmdId = _hidl_request.readInt16();
                    byte sessionId = _hidl_request.readInt8();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = stopSubscribeRequest(cmdId, sessionId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 12 /* transmitFollowupRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    short cmdId = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.NanTransmitFollowupRequest msg = new android.hardware.wifi.V1_0.NanTransmitFollowupRequest();
                    ((android.hardware.wifi.V1_0.NanTransmitFollowupRequest) msg).readFromParcel(_hidl_request);
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = transmitFollowupRequest(cmdId, msg);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 13 /* createDataInterfaceRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    short cmdId = _hidl_request.readInt16();
                    String ifaceName = _hidl_request.readString();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = createDataInterfaceRequest(cmdId, ifaceName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 14 /* deleteDataInterfaceRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    short cmdId = _hidl_request.readInt16();
                    String ifaceName = _hidl_request.readString();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = deleteDataInterfaceRequest(cmdId, ifaceName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 15 /* initiateDataPathRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    short cmdId = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.NanInitiateDataPathRequest msg = new android.hardware.wifi.V1_0.NanInitiateDataPathRequest();
                    ((android.hardware.wifi.V1_0.NanInitiateDataPathRequest) msg).readFromParcel(_hidl_request);
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = initiateDataPathRequest(cmdId, msg);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 16 /* respondToDataPathIndicationRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    short cmdId = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.NanRespondToDataPathIndicationRequest msg = new android.hardware.wifi.V1_0.NanRespondToDataPathIndicationRequest();
                    ((android.hardware.wifi.V1_0.NanRespondToDataPathIndicationRequest) msg).readFromParcel(_hidl_request);
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = respondToDataPathIndicationRequest(cmdId, msg);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 17 /* terminateDataPathRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIface.kInterfaceName);

                    short cmdId = _hidl_request.readInt16();
                    int ndpInstanceId = _hidl_request.readInt32();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = terminateDataPathRequest(cmdId, ndpInstanceId);
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
