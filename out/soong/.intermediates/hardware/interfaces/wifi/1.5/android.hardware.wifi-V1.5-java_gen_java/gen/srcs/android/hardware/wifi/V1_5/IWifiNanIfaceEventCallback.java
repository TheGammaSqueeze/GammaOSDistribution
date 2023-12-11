package android.hardware.wifi.V1_5;

/**
 * NAN Response and Asynchronous Event Callbacks.
 *
 * References to "NAN Spec" are to the Wi-Fi Alliance "Wi-Fi Neighbor Awareness
 * Networking (NAN) Technical Specification".
 */
public interface IWifiNanIfaceEventCallback extends android.hardware.wifi.V1_2.IWifiNanIfaceEventCallback {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.wifi@1.5::IWifiNanIfaceEventCallback";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IWifiNanIfaceEventCallback asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IWifiNanIfaceEventCallback)) {
            return (IWifiNanIfaceEventCallback)iface;
        }

        IWifiNanIfaceEventCallback proxy = new IWifiNanIfaceEventCallback.Proxy(binder);

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
    public static IWifiNanIfaceEventCallback castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IWifiNanIfaceEventCallback.asInterface(iface.asBinder());
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
    public static IWifiNanIfaceEventCallback getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IWifiNanIfaceEventCallback.asInterface(android.os.HwBinder.getService("android.hardware.wifi@1.5::IWifiNanIfaceEventCallback", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IWifiNanIfaceEventCallback getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IWifiNanIfaceEventCallback getService(String serviceName) throws android.os.RemoteException {
        return IWifiNanIfaceEventCallback.asInterface(android.os.HwBinder.getService("android.hardware.wifi@1.5::IWifiNanIfaceEventCallback", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IWifiNanIfaceEventCallback getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Asynchronous callback invoked in response to a capability request
     * |IWifiNanIface.getCapabilitiesRequest|.
     *
     * Note: supersedes the @1.2::IWifiNanIfaceEventCallback.notifyCapabilitiesResponse() method
     * which is deprecated as of HAL version 1.5.
     *
     * @param cmdId command Id corresponding to the original request.
     * @param status WifiNanStatus of the operation. Possible status codes are:
     *        |NanStatusType.SUCCESS|
     * @param capabilities Capability data.
     */
    void notifyCapabilitiesResponse_1_5(short id, android.hardware.wifi.V1_0.WifiNanStatus status, android.hardware.wifi.V1_5.NanCapabilities capabilities)
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

    public static final class Proxy implements IWifiNanIfaceEventCallback {
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
            return "[class or subclass of " + IWifiNanIfaceEventCallback.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback follow.
        @Override
        public void notifyCapabilitiesResponse(short id, android.hardware.wifi.V1_0.WifiNanStatus status, android.hardware.wifi.V1_0.NanCapabilities capabilities)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);
            ((android.hardware.wifi.V1_0.NanCapabilities) capabilities).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* notifyCapabilitiesResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifyEnableResponse(short id, android.hardware.wifi.V1_0.WifiNanStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* notifyEnableResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifyConfigResponse(short id, android.hardware.wifi.V1_0.WifiNanStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* notifyConfigResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifyDisableResponse(short id, android.hardware.wifi.V1_0.WifiNanStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* notifyDisableResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifyStartPublishResponse(short id, android.hardware.wifi.V1_0.WifiNanStatus status, byte sessionId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);
            _hidl_request.writeInt8(sessionId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* notifyStartPublishResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifyStopPublishResponse(short id, android.hardware.wifi.V1_0.WifiNanStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* notifyStopPublishResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifyStartSubscribeResponse(short id, android.hardware.wifi.V1_0.WifiNanStatus status, byte sessionId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);
            _hidl_request.writeInt8(sessionId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* notifyStartSubscribeResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifyStopSubscribeResponse(short id, android.hardware.wifi.V1_0.WifiNanStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* notifyStopSubscribeResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifyTransmitFollowupResponse(short id, android.hardware.wifi.V1_0.WifiNanStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* notifyTransmitFollowupResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifyCreateDataInterfaceResponse(short id, android.hardware.wifi.V1_0.WifiNanStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* notifyCreateDataInterfaceResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifyDeleteDataInterfaceResponse(short id, android.hardware.wifi.V1_0.WifiNanStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* notifyDeleteDataInterfaceResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifyInitiateDataPathResponse(short id, android.hardware.wifi.V1_0.WifiNanStatus status, int ndpInstanceId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(ndpInstanceId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* notifyInitiateDataPathResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifyRespondToDataPathIndicationResponse(short id, android.hardware.wifi.V1_0.WifiNanStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* notifyRespondToDataPathIndicationResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifyTerminateDataPathResponse(short id, android.hardware.wifi.V1_0.WifiNanStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* notifyTerminateDataPathResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void eventClusterEvent(android.hardware.wifi.V1_0.NanClusterEventInd event)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            ((android.hardware.wifi.V1_0.NanClusterEventInd) event).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* eventClusterEvent */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void eventDisabled(android.hardware.wifi.V1_0.WifiNanStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* eventDisabled */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void eventPublishTerminated(byte sessionId, android.hardware.wifi.V1_0.WifiNanStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt8(sessionId);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* eventPublishTerminated */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void eventSubscribeTerminated(byte sessionId, android.hardware.wifi.V1_0.WifiNanStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt8(sessionId);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(18 /* eventSubscribeTerminated */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void eventMatch(android.hardware.wifi.V1_0.NanMatchInd event)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            ((android.hardware.wifi.V1_0.NanMatchInd) event).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(19 /* eventMatch */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void eventMatchExpired(byte discoverySessionId, int peerId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt8(discoverySessionId);
            _hidl_request.writeInt32(peerId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(20 /* eventMatchExpired */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void eventFollowupReceived(android.hardware.wifi.V1_0.NanFollowupReceivedInd event)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            ((android.hardware.wifi.V1_0.NanFollowupReceivedInd) event).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(21 /* eventFollowupReceived */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void eventTransmitFollowup(short id, android.hardware.wifi.V1_0.WifiNanStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(22 /* eventTransmitFollowup */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void eventDataPathRequest(android.hardware.wifi.V1_0.NanDataPathRequestInd event)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            ((android.hardware.wifi.V1_0.NanDataPathRequestInd) event).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(23 /* eventDataPathRequest */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void eventDataPathConfirm(android.hardware.wifi.V1_0.NanDataPathConfirmInd event)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            ((android.hardware.wifi.V1_0.NanDataPathConfirmInd) event).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(24 /* eventDataPathConfirm */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void eventDataPathTerminated(int ndpInstanceId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt32(ndpInstanceId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(25 /* eventDataPathTerminated */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::V1_2::IWifiNanIfaceEventCallback follow.
        @Override
        public void eventDataPathConfirm_1_2(android.hardware.wifi.V1_2.NanDataPathConfirmInd event)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_2.IWifiNanIfaceEventCallback.kInterfaceName);
            ((android.hardware.wifi.V1_2.NanDataPathConfirmInd) event).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(26 /* eventDataPathConfirm_1_2 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void eventDataPathScheduleUpdate(android.hardware.wifi.V1_2.NanDataPathScheduleUpdateInd event)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_2.IWifiNanIfaceEventCallback.kInterfaceName);
            ((android.hardware.wifi.V1_2.NanDataPathScheduleUpdateInd) event).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(27 /* eventDataPathScheduleUpdate */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::V1_5::IWifiNanIfaceEventCallback follow.
        @Override
        public void notifyCapabilitiesResponse_1_5(short id, android.hardware.wifi.V1_0.WifiNanStatus status, android.hardware.wifi.V1_5.NanCapabilities capabilities)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_5.IWifiNanIfaceEventCallback.kInterfaceName);
            _hidl_request.writeInt16(id);
            ((android.hardware.wifi.V1_0.WifiNanStatus) status).writeToParcel(_hidl_request);
            ((android.hardware.wifi.V1_5.NanCapabilities) capabilities).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(28 /* notifyCapabilitiesResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
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

    public static abstract class Stub extends android.os.HwBinder implements IWifiNanIfaceEventCallback {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.wifi.V1_5.IWifiNanIfaceEventCallback.kInterfaceName,
                    android.hardware.wifi.V1_2.IWifiNanIfaceEventCallback.kInterfaceName,
                    android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.wifi.V1_5.IWifiNanIfaceEventCallback.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-78,2,97,-71,115,89,-88,-72,120,71,0,-44,39,-118,-96,10,-122,102,-4,-39,-4,37,-100,58,-125,-122,-70,52,-70,-43,-20,-125} /* b20261b97359a8b8784700d4278aa00a8666fcd9fc259c3a8386ba34bad5ec83 */,
                    new byte[/* 32 */]{30,96,116,-17,-83,-99,-93,51,-128,63,-73,-63,-84,-37,113,-99,81,-61,11,46,30,-110,8,123,4,32,52,22,49,-61,11,96} /* 1e6074efad9da333803fb7c1acdb719d51c30b2e1e92087b0420341631c30b60 */,
                    new byte[/* 32 */]{50,92,-108,-13,-31,-91,101,-75,107,-68,116,-6,-35,-67,11,-89,-53,-126,79,38,61,-52,-7,-33,-1,45,-81,98,-72,110,-41,116} /* 325c94f3e1a565b56bbc74faddbd0ba7cb824f263dccf9dfff2daf62b86ed774 */,
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
                case 1 /* notifyCapabilitiesResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    android.hardware.wifi.V1_0.NanCapabilities capabilities = new android.hardware.wifi.V1_0.NanCapabilities();
                    ((android.hardware.wifi.V1_0.NanCapabilities) capabilities).readFromParcel(_hidl_request);
                    notifyCapabilitiesResponse(id, status, capabilities);
                    break;
                }

                case 2 /* notifyEnableResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    notifyEnableResponse(id, status);
                    break;
                }

                case 3 /* notifyConfigResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    notifyConfigResponse(id, status);
                    break;
                }

                case 4 /* notifyDisableResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    notifyDisableResponse(id, status);
                    break;
                }

                case 5 /* notifyStartPublishResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    byte sessionId = _hidl_request.readInt8();
                    notifyStartPublishResponse(id, status, sessionId);
                    break;
                }

                case 6 /* notifyStopPublishResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    notifyStopPublishResponse(id, status);
                    break;
                }

                case 7 /* notifyStartSubscribeResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    byte sessionId = _hidl_request.readInt8();
                    notifyStartSubscribeResponse(id, status, sessionId);
                    break;
                }

                case 8 /* notifyStopSubscribeResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    notifyStopSubscribeResponse(id, status);
                    break;
                }

                case 9 /* notifyTransmitFollowupResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    notifyTransmitFollowupResponse(id, status);
                    break;
                }

                case 10 /* notifyCreateDataInterfaceResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    notifyCreateDataInterfaceResponse(id, status);
                    break;
                }

                case 11 /* notifyDeleteDataInterfaceResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    notifyDeleteDataInterfaceResponse(id, status);
                    break;
                }

                case 12 /* notifyInitiateDataPathResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    int ndpInstanceId = _hidl_request.readInt32();
                    notifyInitiateDataPathResponse(id, status, ndpInstanceId);
                    break;
                }

                case 13 /* notifyRespondToDataPathIndicationResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    notifyRespondToDataPathIndicationResponse(id, status);
                    break;
                }

                case 14 /* notifyTerminateDataPathResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    notifyTerminateDataPathResponse(id, status);
                    break;
                }

                case 15 /* eventClusterEvent */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    android.hardware.wifi.V1_0.NanClusterEventInd event = new android.hardware.wifi.V1_0.NanClusterEventInd();
                    ((android.hardware.wifi.V1_0.NanClusterEventInd) event).readFromParcel(_hidl_request);
                    eventClusterEvent(event);
                    break;
                }

                case 16 /* eventDisabled */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    eventDisabled(status);
                    break;
                }

                case 17 /* eventPublishTerminated */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    byte sessionId = _hidl_request.readInt8();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    eventPublishTerminated(sessionId, status);
                    break;
                }

                case 18 /* eventSubscribeTerminated */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    byte sessionId = _hidl_request.readInt8();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    eventSubscribeTerminated(sessionId, status);
                    break;
                }

                case 19 /* eventMatch */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    android.hardware.wifi.V1_0.NanMatchInd event = new android.hardware.wifi.V1_0.NanMatchInd();
                    ((android.hardware.wifi.V1_0.NanMatchInd) event).readFromParcel(_hidl_request);
                    eventMatch(event);
                    break;
                }

                case 20 /* eventMatchExpired */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    byte discoverySessionId = _hidl_request.readInt8();
                    int peerId = _hidl_request.readInt32();
                    eventMatchExpired(discoverySessionId, peerId);
                    break;
                }

                case 21 /* eventFollowupReceived */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    android.hardware.wifi.V1_0.NanFollowupReceivedInd event = new android.hardware.wifi.V1_0.NanFollowupReceivedInd();
                    ((android.hardware.wifi.V1_0.NanFollowupReceivedInd) event).readFromParcel(_hidl_request);
                    eventFollowupReceived(event);
                    break;
                }

                case 22 /* eventTransmitFollowup */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    eventTransmitFollowup(id, status);
                    break;
                }

                case 23 /* eventDataPathRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    android.hardware.wifi.V1_0.NanDataPathRequestInd event = new android.hardware.wifi.V1_0.NanDataPathRequestInd();
                    ((android.hardware.wifi.V1_0.NanDataPathRequestInd) event).readFromParcel(_hidl_request);
                    eventDataPathRequest(event);
                    break;
                }

                case 24 /* eventDataPathConfirm */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    android.hardware.wifi.V1_0.NanDataPathConfirmInd event = new android.hardware.wifi.V1_0.NanDataPathConfirmInd();
                    ((android.hardware.wifi.V1_0.NanDataPathConfirmInd) event).readFromParcel(_hidl_request);
                    eventDataPathConfirm(event);
                    break;
                }

                case 25 /* eventDataPathTerminated */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiNanIfaceEventCallback.kInterfaceName);

                    int ndpInstanceId = _hidl_request.readInt32();
                    eventDataPathTerminated(ndpInstanceId);
                    break;
                }

                case 26 /* eventDataPathConfirm_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_2.IWifiNanIfaceEventCallback.kInterfaceName);

                    android.hardware.wifi.V1_2.NanDataPathConfirmInd event = new android.hardware.wifi.V1_2.NanDataPathConfirmInd();
                    ((android.hardware.wifi.V1_2.NanDataPathConfirmInd) event).readFromParcel(_hidl_request);
                    eventDataPathConfirm_1_2(event);
                    break;
                }

                case 27 /* eventDataPathScheduleUpdate */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_2.IWifiNanIfaceEventCallback.kInterfaceName);

                    android.hardware.wifi.V1_2.NanDataPathScheduleUpdateInd event = new android.hardware.wifi.V1_2.NanDataPathScheduleUpdateInd();
                    ((android.hardware.wifi.V1_2.NanDataPathScheduleUpdateInd) event).readFromParcel(_hidl_request);
                    eventDataPathScheduleUpdate(event);
                    break;
                }

                case 28 /* notifyCapabilitiesResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_5.IWifiNanIfaceEventCallback.kInterfaceName);

                    short id = _hidl_request.readInt16();
                    android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();
                    ((android.hardware.wifi.V1_0.WifiNanStatus) status).readFromParcel(_hidl_request);
                    android.hardware.wifi.V1_5.NanCapabilities capabilities = new android.hardware.wifi.V1_5.NanCapabilities();
                    ((android.hardware.wifi.V1_5.NanCapabilities) capabilities).readFromParcel(_hidl_request);
                    notifyCapabilitiesResponse_1_5(id, status, capabilities);
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
