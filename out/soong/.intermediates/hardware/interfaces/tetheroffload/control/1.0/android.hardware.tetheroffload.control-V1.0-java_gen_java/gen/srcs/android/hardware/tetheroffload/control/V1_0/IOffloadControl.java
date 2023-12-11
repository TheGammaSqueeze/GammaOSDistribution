package android.hardware.tetheroffload.control.V1_0;

/**
 * Interface used to control the lifecycle of tethering offload
 */
public interface IOffloadControl extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.tetheroffload.control@1.0::IOffloadControl";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IOffloadControl asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IOffloadControl)) {
            return (IOffloadControl)iface;
        }

        IOffloadControl proxy = new IOffloadControl.Proxy(binder);

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
    public static IOffloadControl castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IOffloadControl.asInterface(iface.asBinder());
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
    public static IOffloadControl getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IOffloadControl.asInterface(android.os.HwBinder.getService("android.hardware.tetheroffload.control@1.0::IOffloadControl", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IOffloadControl getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IOffloadControl getService(String serviceName) throws android.os.RemoteException {
        return IOffloadControl.asInterface(android.os.HwBinder.getService("android.hardware.tetheroffload.control@1.0::IOffloadControl", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IOffloadControl getService() throws android.os.RemoteException {
        return getService("default");
    }


    @java.lang.FunctionalInterface
    public interface initOffloadCallback {
        public void onValues(boolean success, String errMsg);
    }

    /**
     * Indicates intent to start offload for tethering in immediate future.
     *
     * This API must be called exactly once the first time that Tethering is requested by
     * the user.
     *
     * If this API is called multiple times without first calling stopOffload, then the subsequent
     * calls must fail without changing the state of the server.
     *
     * If for some reason, the hardware is currently unable to support offload, this call must fail.
     *
     * @param cb Assuming success, this callback must provide unsolicited updates of offload status.
     *           It is assumed to be valid until stopOffload is called.
     *
     * @return success true if initialization is successful, false otherwise
     * @return errMsg a human readable string if eror has occured.
     *
     * Remarks: Initializing offload does not imply that any upstreams or downstreams have yet been,
     * or even will be, chosen.  This API is symmetrical with stopOffload.
     */
    void initOffload(android.hardware.tetheroffload.control.V1_0.ITetheringOffloadCallback cb, initOffloadCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface stopOffloadCallback {
        public void onValues(boolean success, String errMsg);
    }

    /**
     * Indicate desire to tear down all tethering offload.
     *
     * Called after tethering is no longer requested by the user. Any remaining offload must
     * be subsequently torn down by the management process.  Upon success, the callback registered
     * in initOffload must be released, and offload must be stopped.
     *
     * @return success true if offload is stopped, false otherwise
     * @return errMsg a human readable string if eror has occured.
     *
     * Remarks: Statistics must be reset by this API.
     */
    void stopOffload(stopOffloadCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface setLocalPrefixesCallback {
        public void onValues(boolean success, String errMsg);
    }

    /**
     * Instruct management process not to forward traffic destined to or from the specified prefixes.
     *
     * This API may only be called after initOffload and before stopOffload.
     *
     * @param prefixes List containing fully specified prefixes. For e.g. 192.168.1.12/24
     * or 2001:4860:0684:0:0:0:0:0:1002/64
     *
     * @return success true if success, false otherwise
     * @return errMsg a human readable string if eror has occured.
     *
     * Remarks: This list overrides any previously specified list
     */
    void setLocalPrefixes(java.util.ArrayList<String> prefixes, setLocalPrefixesCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getForwardedStatsCallback {
        public void onValues(long rxBytes, long txBytes);
    }

    /**
     * Query offloaded traffic statistics forwarded to an upstream address.
     *
     * Return statistics that have transpired since the last query.  This would include
     * statistics from all offloaded downstream tether interfaces that have been forwarded to this
     * upstream interface.  After returning the statistics, the counters are reset to zero.
     *
     * Only offloaded statistics must be returned by this API, software stats must not be
     * returned.
     *
     * @param upstream Upstream interface on which traffic exited/entered
     *
     * @return rxBytes values depicting the received bytes
     * @return txBytes values depicting the transmitted bytes
     */
    void getForwardedStats(String upstream, getForwardedStatsCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface setDataLimitCallback {
        public void onValues(boolean success, String errMsg);
    }

    /**
     * Instruct hardware to stop forwarding traffic and send a callback after limit bytes have been
     * transferred in either direction on this upstream interface.
     *
     * The limit must be applied to all traffic on the given upstream interface.  This
     * includes hardware forwarded traffic, software forwarded traffic, and AP-originated traffic.
     * IPv4 and IPv6 traffic both count towards the same limit.  IP headers are included in the
     * byte count limit, but, link-layer headers are not.
     *
     * This API may only be called while offload is occurring on this upstream.  The hardware
     * management process is not expected to cache the value and apply the quota once offload is
     * started.  This cache is not expected, because the limit value would likely become stale over
     * time and would not reflect any new traffic that has occurred.
     *
     * This limit must replace any previous limit.  It may be interpreted as "tell me when
     * <limit> bytes have been transferred (in either direction) on <upstream>, starting
     * now and counting from zero."
     *
     * Once the limit is reached, the callback registered in initOffload must be called to indicate
     * this event and all offload must be stopped.  If offload is desired again, the hardware
     * management process must be completely reprogrammed by calling setUpstreamParameters and
     * addDownstream again.  Note that it is not necessary to call initOffload again to resume offload
     * if stopOffload was not called by the client.
     *
     * @param upstream Upstream interface name that limit must apply to
     * @param limit    Bytes limit that can occur before action must be taken
     *
     * @return success true if limit is applied, false otherwise
     * @return errMsg a human readable string if eror has occured.
     */
    void setDataLimit(String upstream, long limit, setDataLimitCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface setUpstreamParametersCallback {
        public void onValues(boolean success, String errMsg);
    }

    /**
     * Instruct hardware to start forwarding traffic to the specified upstream.
     *
     * When iface, v4Addr, and v4Gw are all non-null, the management process may begin forwarding
     * any currently configured or future configured IPv4 downstreams to this upstream interface.
     *
     * If any of the previously three mentioned parameters are null, then any current IPv4 offload
     * must be stopped.
     *
     * When iface and v6Gws are both non-null, and in the case of v6Gws, are not empty, the
     * management process may begin forwarding any currently configured or future configured IPv6
     * downstreams to this upstream interface.
     *
     * If either of the two above parameters are null, or no V6 Gateways are provided, then IPv6
     * offload must be stopped.
     *
     * This API may only be called after initOffload and before stopOffload.
     *
     * @param iface  Upstream interface name.  Note that only one is needed because IPv4 and IPv6
     *               interfaces cannot be different (only known that this can occur during software
     *               xlat, which cannot be offloaded through hardware anyways).  If the iface is
     *               null, offload must be stopped.
     * @param v4Addr The local IPv4 address assigned to the provided upstream interface, i.e. the
     *               IPv4 address the packets are NATed to. For e.g. 192.168.1.12.
     * @param v4Gw   The IPv4 address of the IPv4 gateway on the upstream interface.
     *               For e.g. 192.168.1.1
     * @param v6Gws  A list of IPv6 addresses (for e.g. 2001:4860:0684:0:0:0:0:0:1002) for possible
     *               IPv6 gateways on the upstream interface.
     *
     * @return success true if success, false otherwise
     * @return errMsg a human readable string if eror has occured.
     *
     * Remarks: This overrides any previously configured parameters.
     */
    void setUpstreamParameters(String iface, String v4Addr, String v4Gw, java.util.ArrayList<String> v6Gws, setUpstreamParametersCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface addDownstreamCallback {
        public void onValues(boolean success, String errMsg);
    }

    /**
     * Configure a downstream interface and prefix in the hardware management process that may be
     * forwarded.
     *
     * The prefix may be an IPv4 or an IPv6 address to signify which family can be offloaded from the
     * specified tether interface.  The list of IPv4 and IPv6 downstreams that are configured may
     * differ.
     *
     * If the given protocol, as determined by the prefix, has an upstream set,
     * the hardware may begin forwarding traffic between the upstream and any devices on the
     * downstream interface that have IP addresses within the specified prefix. Traffic from the same
     * downstream interfaces is unaffected and must be forwarded if and only if it was already
     * being forwarded.
     *
     * If no upstream is currently configured, then these downstream interface and prefixes must be
     * preserved so that offload may begin in the future when an upstream is set.
     *
     * This API does not replace any previously configured downstreams and must be explictly removed
     * by calling removeDownstream.
     *
     * This API may only be called after initOffload and before stopOffload.
     *
     * @param iface  Tether interface
     * @param prefix Downstream prefix depicting addresses that may be offloaded.
     *               For e.g. 192.168.1.12/24 or 2001:4860:0684::/64)
     *
     * @return success true if success, false otherwise
     * @return errMsg a human readable string if eror has occured.
     *
     * Remarks: The hardware management process may fail this call in a normal situation.  This can
     *          happen because the hardware cannot support the current number of prefixes, the
     *          hardware cannot support concurrent offload on multiple interfaces, the hardware
     *          cannot currently support offload on the tether interface for some reason, or any
     *          other dynamic configuration issues which may occur.  In this case,
     *          traffic must remain unaffected and must be forwarded if and only if it was already
     *          being forwarded.
     */
    void addDownstream(String iface, String prefix, addDownstreamCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface removeDownstreamCallback {
        public void onValues(boolean success, String errMsg);
    }

    /**
     * Remove a downstream prefix that may be forwarded from the hardware management process.
     *
     * The prefix may be an IPv4 or an IPv6 address. If it was not previously configured using
     * addDownstream, then this must be a no-op.
     *
     * This API may only be called after initOffload and before stopOffload.
     *
     * @param iface  Tether interface
     * @param prefix Downstream prefix depicting address that must no longer be offloaded
     *               For e.g. 192.168.1.12/24 or 2001:4860:0684::/64)
     *
     * @return success true if success, false otherwise
     * @return errMsg a human readable string if eror has occured.
     */
    void removeDownstream(String iface, String prefix, removeDownstreamCallback _hidl_cb)
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

    public static final class Proxy implements IOffloadControl {
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
            return "[class or subclass of " + IOffloadControl.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::tetheroffload::control::V1_0::IOffloadControl follow.
        @Override
        public void initOffload(android.hardware.tetheroffload.control.V1_0.ITetheringOffloadCallback cb, initOffloadCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);
            _hidl_request.writeStrongBinder(cb == null ? null : cb.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* initOffload */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                String _hidl_out_errMsg = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_success, _hidl_out_errMsg);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void stopOffload(stopOffloadCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* stopOffload */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                String _hidl_out_errMsg = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_success, _hidl_out_errMsg);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setLocalPrefixes(java.util.ArrayList<String> prefixes, setLocalPrefixesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);
            _hidl_request.writeStringVector(prefixes);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* setLocalPrefixes */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                String _hidl_out_errMsg = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_success, _hidl_out_errMsg);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getForwardedStats(String upstream, getForwardedStatsCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);
            _hidl_request.writeString(upstream);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* getForwardedStats */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                long _hidl_out_rxBytes = _hidl_reply.readInt64();
                long _hidl_out_txBytes = _hidl_reply.readInt64();
                _hidl_cb.onValues(_hidl_out_rxBytes, _hidl_out_txBytes);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setDataLimit(String upstream, long limit, setDataLimitCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);
            _hidl_request.writeString(upstream);
            _hidl_request.writeInt64(limit);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* setDataLimit */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                String _hidl_out_errMsg = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_success, _hidl_out_errMsg);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setUpstreamParameters(String iface, String v4Addr, String v4Gw, java.util.ArrayList<String> v6Gws, setUpstreamParametersCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);
            _hidl_request.writeString(iface);
            _hidl_request.writeString(v4Addr);
            _hidl_request.writeString(v4Gw);
            _hidl_request.writeStringVector(v6Gws);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* setUpstreamParameters */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                String _hidl_out_errMsg = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_success, _hidl_out_errMsg);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void addDownstream(String iface, String prefix, addDownstreamCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);
            _hidl_request.writeString(iface);
            _hidl_request.writeString(prefix);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* addDownstream */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                String _hidl_out_errMsg = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_success, _hidl_out_errMsg);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void removeDownstream(String iface, String prefix, removeDownstreamCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);
            _hidl_request.writeString(iface);
            _hidl_request.writeString(prefix);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* removeDownstream */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                String _hidl_out_errMsg = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_success, _hidl_out_errMsg);
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

    public static abstract class Stub extends android.os.HwBinder implements IOffloadControl {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{68,123,0,48,107,-55,90,122,-81,-20,29,102,15,111,62,-97,118,-84,-117,-64,53,49,-109,67,94,85,121,-85,-125,61,-90,25} /* 447b00306bc95a7aafec1d660f6f3e9f76ac8bc0353193435e5579ab833da619 */,
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
                case 1 /* initOffload */:
                {
                    _hidl_request.enforceInterface(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);

                    android.hardware.tetheroffload.control.V1_0.ITetheringOffloadCallback cb = android.hardware.tetheroffload.control.V1_0.ITetheringOffloadCallback.asInterface(_hidl_request.readStrongBinder());
                    initOffload(cb, new initOffloadCallback() {
                        @Override
                        public void onValues(boolean success, String errMsg) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeBool(success);
                            _hidl_reply.writeString(errMsg);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 2 /* stopOffload */:
                {
                    _hidl_request.enforceInterface(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);

                    stopOffload(new stopOffloadCallback() {
                        @Override
                        public void onValues(boolean success, String errMsg) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeBool(success);
                            _hidl_reply.writeString(errMsg);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 3 /* setLocalPrefixes */:
                {
                    _hidl_request.enforceInterface(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);

                    java.util.ArrayList<String> prefixes = _hidl_request.readStringVector();
                    setLocalPrefixes(prefixes, new setLocalPrefixesCallback() {
                        @Override
                        public void onValues(boolean success, String errMsg) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeBool(success);
                            _hidl_reply.writeString(errMsg);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 4 /* getForwardedStats */:
                {
                    _hidl_request.enforceInterface(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);

                    String upstream = _hidl_request.readString();
                    getForwardedStats(upstream, new getForwardedStatsCallback() {
                        @Override
                        public void onValues(long rxBytes, long txBytes) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt64(rxBytes);
                            _hidl_reply.writeInt64(txBytes);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 5 /* setDataLimit */:
                {
                    _hidl_request.enforceInterface(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);

                    String upstream = _hidl_request.readString();
                    long limit = _hidl_request.readInt64();
                    setDataLimit(upstream, limit, new setDataLimitCallback() {
                        @Override
                        public void onValues(boolean success, String errMsg) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeBool(success);
                            _hidl_reply.writeString(errMsg);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 6 /* setUpstreamParameters */:
                {
                    _hidl_request.enforceInterface(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);

                    String iface = _hidl_request.readString();
                    String v4Addr = _hidl_request.readString();
                    String v4Gw = _hidl_request.readString();
                    java.util.ArrayList<String> v6Gws = _hidl_request.readStringVector();
                    setUpstreamParameters(iface, v4Addr, v4Gw, v6Gws, new setUpstreamParametersCallback() {
                        @Override
                        public void onValues(boolean success, String errMsg) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeBool(success);
                            _hidl_reply.writeString(errMsg);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 7 /* addDownstream */:
                {
                    _hidl_request.enforceInterface(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);

                    String iface = _hidl_request.readString();
                    String prefix = _hidl_request.readString();
                    addDownstream(iface, prefix, new addDownstreamCallback() {
                        @Override
                        public void onValues(boolean success, String errMsg) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeBool(success);
                            _hidl_reply.writeString(errMsg);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 8 /* removeDownstream */:
                {
                    _hidl_request.enforceInterface(android.hardware.tetheroffload.control.V1_0.IOffloadControl.kInterfaceName);

                    String iface = _hidl_request.readString();
                    String prefix = _hidl_request.readString();
                    removeDownstream(iface, prefix, new removeDownstreamCallback() {
                        @Override
                        public void onValues(boolean success, String errMsg) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeBool(success);
                            _hidl_reply.writeString(errMsg);
                            _hidl_reply.send();
                            }});
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
