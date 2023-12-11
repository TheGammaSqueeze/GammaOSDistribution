package android.hardware.broadcastradio.V2_0;

public interface ITunerSession extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.broadcastradio@2.0::ITunerSession";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static ITunerSession asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof ITunerSession)) {
            return (ITunerSession)iface;
        }

        ITunerSession proxy = new ITunerSession.Proxy(binder);

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
    public static ITunerSession castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : ITunerSession.asInterface(iface.asBinder());
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
    public static ITunerSession getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return ITunerSession.asInterface(android.os.HwBinder.getService("android.hardware.broadcastradio@2.0::ITunerSession", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static ITunerSession getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static ITunerSession getService(String serviceName) throws android.os.RemoteException {
        return ITunerSession.asInterface(android.os.HwBinder.getService("android.hardware.broadcastradio@2.0::ITunerSession", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static ITunerSession getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Tune to a specified program.
     *
     * Automatically cancels pending tune(), scan() or step().
     * If the method returns OK, tuneFailed or currentProgramInfoChanged
     * callback must be called.
     *
     * @param program Program to tune to.
     * @return result OK if successfully started tuning.
     *                NOT_SUPPORTED if the program selector doesn't contain any
     *                supported identifier.
     *                INVALID_ARGUMENTS if the program selector contains
     *                identifiers in invalid format (i.e. out of range).
     */
    int tune(android.hardware.broadcastradio.V2_0.ProgramSelector program)
        throws android.os.RemoteException;
    /**
     * Tune (seek) to the next valid program on the "air".
     *
     * This might more naturally be called "seek" but for legacy reasons, the
     * entry point remains "scan". This should not be confused with the actual
     * scan operation (where the radio seeks through programs in a loop until
     * user chooses to stay on one of them) nor background scan operation (that
     * a tuner may do in order to locate all available programs.  This function
     * is meant to advance to the next detected program and stay there.
     *
     * Automatically cancels pending tune(), scan() or step().
     * If the method returns OK, tuneFailed or currentProgramInfoChanged
     * callback must be called.
     *
     * The skipSubChannel parameter is used to skip digital radio subchannels:
     *  - HD Radio SPS;
     *  - DAB secondary service.
     *
     * As an implementation detail, the HAL has the option to perform an actual
     * seek or select the next program from the list retrieved in the
     * background, if one is not stale.
     *
     * @param directionUp True to change towards higher numeric values
     *                    (frequency, channel number), false towards lower.
     * @param skipSubChannel Don't tune to subchannels.
     * @return result OK if the operation has successfully started.
     */
    int scan(boolean directionUp, boolean skipSubChannel)
        throws android.os.RemoteException;
    /**
     * Tune to the adjacent channel, which may not be occupied by any program.
     *
     * Automatically cancels pending tune(), scan() or step().
     * If the method returns OK, tuneFailed or currentProgramInfoChanged
     * callback must be called.
     *
     * @param directionUp True to change towards higher numeric values
     *                    (frequency, channel number), false towards lower.
     * @return result OK successfully started tuning.
     *                NOT_SUPPORTED if tuning to an unoccupied channel is not
     *                supported (i.e. for satellite radio).
     */
    int step(boolean directionUp)
        throws android.os.RemoteException;
    /**
     * Cancel a pending tune(), scan() or step().
     *
     * If there is no such operation running, the call must be ignored.
     */
    void cancel()
        throws android.os.RemoteException;
    /**
     * Applies a filter to the program list and starts sending program list
     * updates over onProgramListUpdated callback.
     *
     * There may be only one updates stream active at the moment. Calling this
     * method again must result in cancelling the previous update request.
     *
     * This call clears the program list on the client side, the HAL must send
     * the whole list again.
     *
     * If the program list scanning hardware (i.e. background tuner) is
     * unavailable at the moment, the call must succeed and start updates
     * when it becomes available.
     *
     * @param filter Filter to apply on the fetched program list.
     * @return result OK successfully started fetching list updates.
     *                NOT_SUPPORTED program list scanning is not supported
     *                by the hardware.
     */
    int startProgramListUpdates(android.hardware.broadcastradio.V2_0.ProgramFilter filter)
        throws android.os.RemoteException;
    /**
     * Stops sending program list updates.
     */
    void stopProgramListUpdates()
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface isConfigFlagSetCallback {
        public void onValues(int result, boolean value);
    }

    /**
     * Fetches the current setting of a given config flag.
     *
     * The success/failure result must be consistent with setConfigFlag.
     *
     * @param flag Flag to fetch.
     * @return result OK successfully fetched the flag.
     *                INVALID_STATE if the flag is not applicable right now.
     *                NOT_SUPPORTED if the flag is not supported at all.
     * @return value The current value of the flag, if result is OK.
     */
    void isConfigFlagSet(int flag, isConfigFlagSetCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Sets the config flag.
     *
     * The success/failure result must be consistent with isConfigFlagSet.
     *
     * @param flag Flag to set.
     * @param value The new value of a given flag.
     * @return result OK successfully set the flag.
     *                INVALID_STATE if the flag is not applicable right now.
     *                NOT_SUPPORTED if the flag is not supported at all.
     */
    int setConfigFlag(int flag, boolean value)
        throws android.os.RemoteException;
    /**
     * Generic method for setting vendor-specific parameter values.
     * The framework does not interpret the parameters, they are passed
     * in an opaque manner between a vendor application and HAL.
     *
     * Framework does not make any assumptions on the keys or values, other than
     * ones stated in VendorKeyValue documentation (a requirement of key
     * prefixes).
     *
     * For each pair in the result vector, the key must be one of the keys
     * contained in the input (possibly with wildcards expanded), and the value
     * must be a vendor-specific result status (i.e. the string "OK" or an error
     * code). The implementation may choose to return an empty vector, or only
     * return a status for a subset of the provided inputs, at its discretion.
     *
     * Application and HAL must not use keys with unknown prefix. In particular,
     * it must not place a key-value pair in results vector for unknown key from
     * parameters vector - instead, an unknown key should simply be ignored.
     * In other words, results vector may contain a subset of parameter keys
     * (however, the framework doesn't enforce a strict subset - the only
     * formal requirement is vendor domain prefix for keys).
     *
     * @param parameters Vendor-specific key-value pairs.
     * @return results Operation completion status for parameters being set.
     */
    java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue> setParameters(java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue> parameters)
        throws android.os.RemoteException;
    /**
     * Generic method for retrieving vendor-specific parameter values.
     * The framework does not interpret the parameters, they are passed
     * in an opaque manner between a vendor application and HAL.
     *
     * Framework does not cache set/get requests, so it's allowed for
     * getParameter to return a different value than previous setParameter call.
     *
     * The syntax and semantics of keys are up to the vendor (as long as prefix
     * rules are obeyed). For instance, vendors may include some form of
     * wildcard support. In such case, result vector may be of different size
     * than requested keys vector. However, wildcards are not recognized by
     * framework and they are passed as-is to the HAL implementation.
     *
     * Unknown keys must be ignored and not placed into results vector.
     *
     * @param keys Parameter keys to fetch.
     * @return parameters Vendor-specific key-value pairs.
     */
    java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue> getParameters(java.util.ArrayList<String> keys)
        throws android.os.RemoteException;
    /**
     * Closes the session.
     *
     * The call must not fail and must only be issued once.
     *
     * After the close call is executed, no other calls to this interface
     * are allowed.
     */
    void close()
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

    public static final class Proxy implements ITunerSession {
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
            return "[class or subclass of " + ITunerSession.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::broadcastradio::V2_0::ITunerSession follow.
        @Override
        public int tune(android.hardware.broadcastradio.V2_0.ProgramSelector program)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);
            ((android.hardware.broadcastradio.V2_0.ProgramSelector) program).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* tune */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_result = _hidl_reply.readInt32();
                return _hidl_out_result;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int scan(boolean directionUp, boolean skipSubChannel)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);
            _hidl_request.writeBool(directionUp);
            _hidl_request.writeBool(skipSubChannel);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* scan */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_result = _hidl_reply.readInt32();
                return _hidl_out_result;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int step(boolean directionUp)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);
            _hidl_request.writeBool(directionUp);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* step */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_result = _hidl_reply.readInt32();
                return _hidl_out_result;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cancel()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* cancel */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int startProgramListUpdates(android.hardware.broadcastradio.V2_0.ProgramFilter filter)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);
            ((android.hardware.broadcastradio.V2_0.ProgramFilter) filter).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* startProgramListUpdates */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_result = _hidl_reply.readInt32();
                return _hidl_out_result;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void stopProgramListUpdates()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* stopProgramListUpdates */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void isConfigFlagSet(int flag, isConfigFlagSetCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);
            _hidl_request.writeInt32(flag);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* isConfigFlagSet */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_result = _hidl_reply.readInt32();
                boolean _hidl_out_value = _hidl_reply.readBool();
                _hidl_cb.onValues(_hidl_out_result, _hidl_out_value);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int setConfigFlag(int flag, boolean value)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);
            _hidl_request.writeInt32(flag);
            _hidl_request.writeBool(value);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* setConfigFlag */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_result = _hidl_reply.readInt32();
                return _hidl_out_result;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue> setParameters(java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue> parameters)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);
            android.hardware.broadcastradio.V2_0.VendorKeyValue.writeVectorToParcel(_hidl_request, parameters);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* setParameters */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue> _hidl_out_results = android.hardware.broadcastradio.V2_0.VendorKeyValue.readVectorFromParcel(_hidl_reply);
                return _hidl_out_results;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue> getParameters(java.util.ArrayList<String> keys)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);
            _hidl_request.writeStringVector(keys);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* getParameters */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue> _hidl_out_parameters = android.hardware.broadcastradio.V2_0.VendorKeyValue.readVectorFromParcel(_hidl_reply);
                return _hidl_out_parameters;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void close()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* close */, _hidl_request, _hidl_reply, 0 /* flags */);
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

    public static abstract class Stub extends android.os.HwBinder implements ITunerSession {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-41,4,100,-59,23,-92,-95,-75,22,119,48,-124,55,117,-87,127,69,81,2,-111,-98,-108,91,4,-9,23,-71,-38,57,12,15,57} /* d70464c517a4a1b5167730843775a97f455102919e945b04f717b9da390c0f39 */,
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
                case 1 /* tune */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);

                    android.hardware.broadcastradio.V2_0.ProgramSelector program = new android.hardware.broadcastradio.V2_0.ProgramSelector();
                    ((android.hardware.broadcastradio.V2_0.ProgramSelector) program).readFromParcel(_hidl_request);
                    int _hidl_out_result = tune(program);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_result);
                    _hidl_reply.send();
                    break;
                }

                case 2 /* scan */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);

                    boolean directionUp = _hidl_request.readBool();
                    boolean skipSubChannel = _hidl_request.readBool();
                    int _hidl_out_result = scan(directionUp, skipSubChannel);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_result);
                    _hidl_reply.send();
                    break;
                }

                case 3 /* step */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);

                    boolean directionUp = _hidl_request.readBool();
                    int _hidl_out_result = step(directionUp);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_result);
                    _hidl_reply.send();
                    break;
                }

                case 4 /* cancel */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);

                    cancel();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 5 /* startProgramListUpdates */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);

                    android.hardware.broadcastradio.V2_0.ProgramFilter filter = new android.hardware.broadcastradio.V2_0.ProgramFilter();
                    ((android.hardware.broadcastradio.V2_0.ProgramFilter) filter).readFromParcel(_hidl_request);
                    int _hidl_out_result = startProgramListUpdates(filter);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_result);
                    _hidl_reply.send();
                    break;
                }

                case 6 /* stopProgramListUpdates */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);

                    stopProgramListUpdates();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 7 /* isConfigFlagSet */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);

                    int flag = _hidl_request.readInt32();
                    isConfigFlagSet(flag, new isConfigFlagSetCallback() {
                        @Override
                        public void onValues(int result, boolean value) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(result);
                            _hidl_reply.writeBool(value);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 8 /* setConfigFlag */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);

                    int flag = _hidl_request.readInt32();
                    boolean value = _hidl_request.readBool();
                    int _hidl_out_result = setConfigFlag(flag, value);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_result);
                    _hidl_reply.send();
                    break;
                }

                case 9 /* setParameters */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);

                    java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue> parameters = android.hardware.broadcastradio.V2_0.VendorKeyValue.readVectorFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue> _hidl_out_results = setParameters(parameters);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    android.hardware.broadcastradio.V2_0.VendorKeyValue.writeVectorToParcel(_hidl_reply, _hidl_out_results);
                    _hidl_reply.send();
                    break;
                }

                case 10 /* getParameters */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);

                    java.util.ArrayList<String> keys = _hidl_request.readStringVector();
                    java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue> _hidl_out_parameters = getParameters(keys);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    android.hardware.broadcastradio.V2_0.VendorKeyValue.writeVectorToParcel(_hidl_reply, _hidl_out_parameters);
                    _hidl_reply.send();
                    break;
                }

                case 11 /* close */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.ITunerSession.kInterfaceName);

                    close();
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
