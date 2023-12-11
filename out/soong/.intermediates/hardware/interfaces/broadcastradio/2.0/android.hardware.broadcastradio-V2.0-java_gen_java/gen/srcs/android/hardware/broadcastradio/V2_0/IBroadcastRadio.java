package android.hardware.broadcastradio.V2_0;

/**
 * Represents a hardware broadcast radio module. A single module may contain
 * multiple hardware tuners (i.e. with an additional background tuner), but the
 * layers above the HAL see them as a single logical unit.
 */
public interface IBroadcastRadio extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.broadcastradio@2.0::IBroadcastRadio";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IBroadcastRadio asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IBroadcastRadio)) {
            return (IBroadcastRadio)iface;
        }

        IBroadcastRadio proxy = new IBroadcastRadio.Proxy(binder);

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
    public static IBroadcastRadio castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IBroadcastRadio.asInterface(iface.asBinder());
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
    public static IBroadcastRadio getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IBroadcastRadio.asInterface(android.os.HwBinder.getService("android.hardware.broadcastradio@2.0::IBroadcastRadio", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IBroadcastRadio getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IBroadcastRadio getService(String serviceName) throws android.os.RemoteException {
        return IBroadcastRadio.asInterface(android.os.HwBinder.getService("android.hardware.broadcastradio@2.0::IBroadcastRadio", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IBroadcastRadio getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Returns module properties: a description of a module and its
     * capabilities. This method must not fail.
     *
     * @return properties Module description.
     */
    android.hardware.broadcastradio.V2_0.Properties getProperties()
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getAmFmRegionConfigCallback {
        public void onValues(int result, android.hardware.broadcastradio.V2_0.AmFmRegionConfig config);
    }

    /**
     * Fetches current or possible AM/FM region configuration.
     *
     * @param full If true, returns full hardware capabilities.
     *             If false, returns current regional configuration.
     * @return result OK in case of success.
     *                NOT_SUPPORTED if the tuner doesn't support AM/FM.
     * @return config Hardware capabilities (full=true) or
     *                current configuration (full=false).
     */
    void getAmFmRegionConfig(boolean full, getAmFmRegionConfigCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getDabRegionConfigCallback {
        public void onValues(int result, java.util.ArrayList<android.hardware.broadcastradio.V2_0.DabTableEntry> config);
    }

    /**
     * Fetches current DAB region configuration.
     *
     * @return result OK in case of success.
     *                NOT_SUPPORTED if the tuner doesn't support DAB.
     * @return config Current configuration.
     */
    void getDabRegionConfig(getDabRegionConfigCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface openSessionCallback {
        public void onValues(int result, android.hardware.broadcastradio.V2_0.ITunerSession session);
    }

    /**
     * Opens a new tuner session.
     *
     * There may be only one session active at a time. If the new session was
     * requested when the old one was active, the old must be terminated
     * (aggressive open).
     *
     * @param callback The callback interface.
     * @return result OK in case of success.
     * @return session The session interface.
     */
    void openSession(android.hardware.broadcastradio.V2_0.ITunerCallback callback, openSessionCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Fetch image from radio module cache.
     *
     * This is out-of-band transport mechanism for images carried with metadata.
     * The metadata vector only passes the identifier, so the client may cache
     * images or even not fetch them.
     *
     * The identifier may be any arbitrary number (i.e. sha256 prefix) selected
     * by the vendor. It must be stable across sessions so the application may
     * cache it.
     *
     * The data must be a valid PNG, JPEG, GIF or BMP file.
     * Image data with an invalid format must be handled gracefully in the same
     * way as a missing image.
     *
     * The image identifier may become invalid after some time from passing it
     * with metadata struct (due to resource cleanup at the HAL implementation).
     * However, it must remain valid for a currently tuned program at least
     * until onCurrentProgramInfoChanged is called.
     *
     * There is still a race condition possible between
     * onCurrentProgramInfoChanged callback and the HAL implementation eagerly
     * clearing the cache (because the next onCurrentProgramInfoChanged came).
     * In such case, client application may expect the new
     * onCurrentProgramInfoChanged callback with updated image identifier.
     *
     * @param id Identifier of an image (value of Constants::INVALID_IMAGE is
     *           reserved and must be treated as invalid image).
     * @return image A binary blob with image data
     *               or a zero-length vector if identifier doesn't exist.
     */
    java.util.ArrayList<Byte> getImage(int id)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface registerAnnouncementListenerCallback {
        public void onValues(int result, android.hardware.broadcastradio.V2_0.ICloseHandle closeHandle);
    }

    /**
     * Registers announcement listener.
     *
     * If there is at least one observer registered, HAL implementation must
     * notify about announcements even if no sessions are active.
     *
     * If the observer dies, the HAL implementation must unregister observer
     * automatically.
     *
     * @param enabled The list of announcement types to watch for.
     * @param listener The listener interface.
     * @return result OK in case of success.
     *                NOT_SUPPORTED if the tuner doesn't support announcements.
     * @return closeHandle A handle to unregister observer,
     *                     nullptr if result was not OK.
     */
    void registerAnnouncementListener(java.util.ArrayList<Byte> enabled, android.hardware.broadcastradio.V2_0.IAnnouncementListener listener, registerAnnouncementListenerCallback _hidl_cb)
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

    public static final class Proxy implements IBroadcastRadio {
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
            return "[class or subclass of " + IBroadcastRadio.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::broadcastradio::V2_0::IBroadcastRadio follow.
        @Override
        public android.hardware.broadcastradio.V2_0.Properties getProperties()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.IBroadcastRadio.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* getProperties */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.broadcastradio.V2_0.Properties _hidl_out_properties = new android.hardware.broadcastradio.V2_0.Properties();
                ((android.hardware.broadcastradio.V2_0.Properties) _hidl_out_properties).readFromParcel(_hidl_reply);
                return _hidl_out_properties;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getAmFmRegionConfig(boolean full, getAmFmRegionConfigCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.IBroadcastRadio.kInterfaceName);
            _hidl_request.writeBool(full);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* getAmFmRegionConfig */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_result = _hidl_reply.readInt32();
                android.hardware.broadcastradio.V2_0.AmFmRegionConfig _hidl_out_config = new android.hardware.broadcastradio.V2_0.AmFmRegionConfig();
                ((android.hardware.broadcastradio.V2_0.AmFmRegionConfig) _hidl_out_config).readFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_result, _hidl_out_config);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDabRegionConfig(getDabRegionConfigCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.IBroadcastRadio.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* getDabRegionConfig */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_result = _hidl_reply.readInt32();
                java.util.ArrayList<android.hardware.broadcastradio.V2_0.DabTableEntry> _hidl_out_config = android.hardware.broadcastradio.V2_0.DabTableEntry.readVectorFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_result, _hidl_out_config);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void openSession(android.hardware.broadcastradio.V2_0.ITunerCallback callback, openSessionCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.IBroadcastRadio.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* openSession */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_result = _hidl_reply.readInt32();
                android.hardware.broadcastradio.V2_0.ITunerSession _hidl_out_session = android.hardware.broadcastradio.V2_0.ITunerSession.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_result, _hidl_out_session);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public java.util.ArrayList<Byte> getImage(int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.IBroadcastRadio.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* getImage */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<Byte> _hidl_out_image = _hidl_reply.readInt8Vector();
                return _hidl_out_image;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void registerAnnouncementListener(java.util.ArrayList<Byte> enabled, android.hardware.broadcastradio.V2_0.IAnnouncementListener listener, registerAnnouncementListenerCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.broadcastradio.V2_0.IBroadcastRadio.kInterfaceName);
            _hidl_request.writeInt8Vector(enabled);
            _hidl_request.writeStrongBinder(listener == null ? null : listener.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* registerAnnouncementListener */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_result = _hidl_reply.readInt32();
                android.hardware.broadcastradio.V2_0.ICloseHandle _hidl_out_closeHandle = android.hardware.broadcastradio.V2_0.ICloseHandle.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_result, _hidl_out_closeHandle);
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

    public static abstract class Stub extends android.os.HwBinder implements IBroadcastRadio {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.broadcastradio.V2_0.IBroadcastRadio.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.broadcastradio.V2_0.IBroadcastRadio.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{68,1,124,66,-26,-12,-40,-53,48,-16,126,-79,-38,4,84,10,-104,115,106,51,106,-62,-116,126,14,-46,-26,-98,21,-119,-8,-47} /* 44017c42e6f4d8cb30f07eb1da04540a98736a336ac28c7e0ed2e69e1589f8d1 */,
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
                case 1 /* getProperties */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.IBroadcastRadio.kInterfaceName);

                    android.hardware.broadcastradio.V2_0.Properties _hidl_out_properties = getProperties();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.broadcastradio.V2_0.Properties) _hidl_out_properties).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 2 /* getAmFmRegionConfig */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.IBroadcastRadio.kInterfaceName);

                    boolean full = _hidl_request.readBool();
                    getAmFmRegionConfig(full, new getAmFmRegionConfigCallback() {
                        @Override
                        public void onValues(int result, android.hardware.broadcastradio.V2_0.AmFmRegionConfig config) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(result);
                            ((android.hardware.broadcastradio.V2_0.AmFmRegionConfig) config).writeToParcel(_hidl_reply);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 3 /* getDabRegionConfig */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.IBroadcastRadio.kInterfaceName);

                    getDabRegionConfig(new getDabRegionConfigCallback() {
                        @Override
                        public void onValues(int result, java.util.ArrayList<android.hardware.broadcastradio.V2_0.DabTableEntry> config) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(result);
                            android.hardware.broadcastradio.V2_0.DabTableEntry.writeVectorToParcel(_hidl_reply, config);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 4 /* openSession */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.IBroadcastRadio.kInterfaceName);

                    android.hardware.broadcastradio.V2_0.ITunerCallback callback = android.hardware.broadcastradio.V2_0.ITunerCallback.asInterface(_hidl_request.readStrongBinder());
                    openSession(callback, new openSessionCallback() {
                        @Override
                        public void onValues(int result, android.hardware.broadcastradio.V2_0.ITunerSession session) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(result);
                            _hidl_reply.writeStrongBinder(session == null ? null : session.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 5 /* getImage */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.IBroadcastRadio.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    java.util.ArrayList<Byte> _hidl_out_image = getImage(id);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt8Vector(_hidl_out_image);
                    _hidl_reply.send();
                    break;
                }

                case 6 /* registerAnnouncementListener */:
                {
                    _hidl_request.enforceInterface(android.hardware.broadcastradio.V2_0.IBroadcastRadio.kInterfaceName);

                    java.util.ArrayList<Byte> enabled = _hidl_request.readInt8Vector();
                    android.hardware.broadcastradio.V2_0.IAnnouncementListener listener = android.hardware.broadcastradio.V2_0.IAnnouncementListener.asInterface(_hidl_request.readStrongBinder());
                    registerAnnouncementListener(enabled, listener, new registerAnnouncementListenerCallback() {
                        @Override
                        public void onValues(int result, android.hardware.broadcastradio.V2_0.ICloseHandle closeHandle) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(result);
                            _hidl_reply.writeStrongBinder(closeHandle == null ? null : closeHandle.asBinder());
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
