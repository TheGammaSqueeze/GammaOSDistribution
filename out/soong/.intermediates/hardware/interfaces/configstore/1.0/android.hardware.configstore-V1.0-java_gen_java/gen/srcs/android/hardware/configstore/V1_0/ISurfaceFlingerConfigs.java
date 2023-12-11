package android.hardware.configstore.V1_0;

public interface ISurfaceFlingerConfigs extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.configstore@1.0::ISurfaceFlingerConfigs";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static ISurfaceFlingerConfigs asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof ISurfaceFlingerConfigs)) {
            return (ISurfaceFlingerConfigs)iface;
        }

        ISurfaceFlingerConfigs proxy = new ISurfaceFlingerConfigs.Proxy(binder);

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
    public static ISurfaceFlingerConfigs castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : ISurfaceFlingerConfigs.asInterface(iface.asBinder());
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
    public static ISurfaceFlingerConfigs getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return ISurfaceFlingerConfigs.asInterface(android.os.HwBinder.getService("android.hardware.configstore@1.0::ISurfaceFlingerConfigs", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static ISurfaceFlingerConfigs getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static ISurfaceFlingerConfigs getService(String serviceName) throws android.os.RemoteException {
        return ISurfaceFlingerConfigs.asInterface(android.os.HwBinder.getService("android.hardware.configstore@1.0::ISurfaceFlingerConfigs", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static ISurfaceFlingerConfigs getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * The following two methods define (respectively):
     *
     * - The phase offset between hardware vsync and when apps are woken up by the
     *   Choreographer callback
     * - The phase offset between hardware vsync and when SurfaceFlinger wakes up
     *   to consume input
     *
     * Their values may be tuned to trade off between display pipeline latency (both
     * overall latency and the lengths of the app --> SF and SF --> display phases)
     * and frame delivery jitter (which typically manifests as "jank" or "jerkiness"
     * while interacting with the device). The default values must produce a
     * relatively low amount of jitter at the expense of roughly two frames of
     * app --> display latency, and unless significant testing is performed to avoid
     * increased display jitter (both manual investigation using systrace [1] and
     * automated testing using dumpsys gfxinfo [2] are recommended), they should not
     * be modified.
     *
     * [1] https://developer.android.com/studio/profile/systrace.html
     * [2] https://developer.android.com/training/testing/performance.html
     */
    android.hardware.configstore.V1_0.OptionalInt64 vsyncEventPhaseOffsetNs()
        throws android.os.RemoteException;
    android.hardware.configstore.V1_0.OptionalInt64 vsyncSfEventPhaseOffsetNs()
        throws android.os.RemoteException;
    /**
     * Instruct the Render Engine to use EGL_IMG_context_priority hint if
     * availabe.
     */
    android.hardware.configstore.V1_0.OptionalBool useContextPriority()
        throws android.os.RemoteException;
    /**
     * hasWideColorDisplay indicates that the device has
     * or can support a wide-color display, e.g. color space
     * greater than sRGB. Typical display may have same
     * color primaries as DCI-P3.
     * Indicate support for this feature by setting
     * TARGET_HAS_WIDE_COLOR_DISPLAY to true in BoardConfig.mk
     * This also means that the device is color managed.
     * A color managed device will use the appropriate
     * display mode depending on the content on the screen.
     * Default is sRGB.
     */
    android.hardware.configstore.V1_0.OptionalBool hasWideColorDisplay()
        throws android.os.RemoteException;
    /**
     * hwHDRDisplay indicates that the device has an High Dynamic Range display.
     * A display is considered High Dynamic Range if it
     *
     *     1. is a wide color gamut display, typically DCI-P3 or lager
     *     2. has high luminance capability, typically 540 nits or higher at 10% OPR
     *
     * Indicate support for this feature by setting
     * TARGET_HAS_HDR_DISPLAY to true in BoardConfig.mk
     * TARGET_HAS_WIDE_COLOR_DISPLAY must be set to true when
     * TARGET_HAS_HDR_DISPLAY is true.
     */
    android.hardware.configstore.V1_0.OptionalBool hasHDRDisplay()
        throws android.os.RemoteException;
    /**
     * Specify the offset in nanoseconds to add to vsync time when timestamping
     * present fences.
     */
    android.hardware.configstore.V1_0.OptionalInt64 presentTimeOffsetFromVSyncNs()
        throws android.os.RemoteException;
    /**
     * Some hardware can do RGB->YUV conversion more efficiently in hardware
     * controlled by HWC than in hardware controlled by the video encoder.
     * This instruct VirtualDisplaySurface to use HWC for such conversion on
     * GL composition.
     */
    android.hardware.configstore.V1_0.OptionalBool useHwcForRGBtoYUV()
        throws android.os.RemoteException;
    /**
     *  Maximum dimension supported by HWC for virtual display.
     *  Must be equals to min(max_width, max_height).
     */
    android.hardware.configstore.V1_0.OptionalUInt64 maxVirtualDisplaySize()
        throws android.os.RemoteException;
    /**
     * Indicates if Sync framework is available. Sync framework provides fence
     * mechanism which significantly reduces buffer processing latency.
     */
    android.hardware.configstore.V1_0.OptionalBool hasSyncFramework()
        throws android.os.RemoteException;
    /**
     * Return true if surface flinger should use vr flinger for compatible vr
     * apps, false otherwise. Devices that will never be running vr apps should
     * return false to avoid extra resource usage. Daydream ready devices must
     * return true for full vr support.
     */
    android.hardware.configstore.V1_0.OptionalBool useVrFlinger()
        throws android.os.RemoteException;
    /**
     * Controls the number of buffers SurfaceFlinger will allocate for use in
     * FramebufferSurface.
     */
    android.hardware.configstore.V1_0.OptionalInt64 maxFrameBufferAcquiredBuffers()
        throws android.os.RemoteException;
    /**
     * Returns true if surface flinger should start
     * hardware.graphics.allocator@2.0::IAllocator service.
     */
    android.hardware.configstore.V1_0.OptionalBool startGraphicsAllocatorService()
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

    public static final class Proxy implements ISurfaceFlingerConfigs {
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
            return "[class or subclass of " + ISurfaceFlingerConfigs.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs follow.
        @Override
        public android.hardware.configstore.V1_0.OptionalInt64 vsyncEventPhaseOffsetNs()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* vsyncEventPhaseOffsetNs */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.configstore.V1_0.OptionalInt64 _hidl_out_value = new android.hardware.configstore.V1_0.OptionalInt64();
                ((android.hardware.configstore.V1_0.OptionalInt64) _hidl_out_value).readFromParcel(_hidl_reply);
                return _hidl_out_value;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.configstore.V1_0.OptionalInt64 vsyncSfEventPhaseOffsetNs()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* vsyncSfEventPhaseOffsetNs */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.configstore.V1_0.OptionalInt64 _hidl_out_value = new android.hardware.configstore.V1_0.OptionalInt64();
                ((android.hardware.configstore.V1_0.OptionalInt64) _hidl_out_value).readFromParcel(_hidl_reply);
                return _hidl_out_value;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.configstore.V1_0.OptionalBool useContextPriority()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* useContextPriority */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.configstore.V1_0.OptionalBool _hidl_out_value = new android.hardware.configstore.V1_0.OptionalBool();
                ((android.hardware.configstore.V1_0.OptionalBool) _hidl_out_value).readFromParcel(_hidl_reply);
                return _hidl_out_value;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.configstore.V1_0.OptionalBool hasWideColorDisplay()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* hasWideColorDisplay */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.configstore.V1_0.OptionalBool _hidl_out_value = new android.hardware.configstore.V1_0.OptionalBool();
                ((android.hardware.configstore.V1_0.OptionalBool) _hidl_out_value).readFromParcel(_hidl_reply);
                return _hidl_out_value;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.configstore.V1_0.OptionalBool hasHDRDisplay()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* hasHDRDisplay */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.configstore.V1_0.OptionalBool _hidl_out_value = new android.hardware.configstore.V1_0.OptionalBool();
                ((android.hardware.configstore.V1_0.OptionalBool) _hidl_out_value).readFromParcel(_hidl_reply);
                return _hidl_out_value;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.configstore.V1_0.OptionalInt64 presentTimeOffsetFromVSyncNs()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* presentTimeOffsetFromVSyncNs */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.configstore.V1_0.OptionalInt64 _hidl_out_value = new android.hardware.configstore.V1_0.OptionalInt64();
                ((android.hardware.configstore.V1_0.OptionalInt64) _hidl_out_value).readFromParcel(_hidl_reply);
                return _hidl_out_value;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.configstore.V1_0.OptionalBool useHwcForRGBtoYUV()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* useHwcForRGBtoYUV */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.configstore.V1_0.OptionalBool _hidl_out_value = new android.hardware.configstore.V1_0.OptionalBool();
                ((android.hardware.configstore.V1_0.OptionalBool) _hidl_out_value).readFromParcel(_hidl_reply);
                return _hidl_out_value;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.configstore.V1_0.OptionalUInt64 maxVirtualDisplaySize()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* maxVirtualDisplaySize */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.configstore.V1_0.OptionalUInt64 _hidl_out_value = new android.hardware.configstore.V1_0.OptionalUInt64();
                ((android.hardware.configstore.V1_0.OptionalUInt64) _hidl_out_value).readFromParcel(_hidl_reply);
                return _hidl_out_value;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.configstore.V1_0.OptionalBool hasSyncFramework()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* hasSyncFramework */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.configstore.V1_0.OptionalBool _hidl_out_value = new android.hardware.configstore.V1_0.OptionalBool();
                ((android.hardware.configstore.V1_0.OptionalBool) _hidl_out_value).readFromParcel(_hidl_reply);
                return _hidl_out_value;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.configstore.V1_0.OptionalBool useVrFlinger()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* useVrFlinger */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.configstore.V1_0.OptionalBool _hidl_out_value = new android.hardware.configstore.V1_0.OptionalBool();
                ((android.hardware.configstore.V1_0.OptionalBool) _hidl_out_value).readFromParcel(_hidl_reply);
                return _hidl_out_value;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.configstore.V1_0.OptionalInt64 maxFrameBufferAcquiredBuffers()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* maxFrameBufferAcquiredBuffers */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.configstore.V1_0.OptionalInt64 _hidl_out_value = new android.hardware.configstore.V1_0.OptionalInt64();
                ((android.hardware.configstore.V1_0.OptionalInt64) _hidl_out_value).readFromParcel(_hidl_reply);
                return _hidl_out_value;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.configstore.V1_0.OptionalBool startGraphicsAllocatorService()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* startGraphicsAllocatorService */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.configstore.V1_0.OptionalBool _hidl_out_value = new android.hardware.configstore.V1_0.OptionalBool();
                ((android.hardware.configstore.V1_0.OptionalBool) _hidl_out_value).readFromParcel(_hidl_reply);
                return _hidl_out_value;
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

    public static abstract class Stub extends android.os.HwBinder implements ISurfaceFlingerConfigs {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-38,51,35,68,3,-1,93,96,-13,71,55,17,-111,123,-103,72,-26,72,74,66,96,-75,36,122,-51,-81,-79,17,25,58,-99,-30} /* da33234403ff5d60f3473711917b9948e6484a4260b5247acdafb111193a9de2 */,
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
                case 1 /* vsyncEventPhaseOffsetNs */:
                {
                    _hidl_request.enforceInterface(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

                    android.hardware.configstore.V1_0.OptionalInt64 _hidl_out_value = vsyncEventPhaseOffsetNs();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.configstore.V1_0.OptionalInt64) _hidl_out_value).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 2 /* vsyncSfEventPhaseOffsetNs */:
                {
                    _hidl_request.enforceInterface(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

                    android.hardware.configstore.V1_0.OptionalInt64 _hidl_out_value = vsyncSfEventPhaseOffsetNs();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.configstore.V1_0.OptionalInt64) _hidl_out_value).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 3 /* useContextPriority */:
                {
                    _hidl_request.enforceInterface(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

                    android.hardware.configstore.V1_0.OptionalBool _hidl_out_value = useContextPriority();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.configstore.V1_0.OptionalBool) _hidl_out_value).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 4 /* hasWideColorDisplay */:
                {
                    _hidl_request.enforceInterface(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

                    android.hardware.configstore.V1_0.OptionalBool _hidl_out_value = hasWideColorDisplay();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.configstore.V1_0.OptionalBool) _hidl_out_value).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 5 /* hasHDRDisplay */:
                {
                    _hidl_request.enforceInterface(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

                    android.hardware.configstore.V1_0.OptionalBool _hidl_out_value = hasHDRDisplay();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.configstore.V1_0.OptionalBool) _hidl_out_value).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 6 /* presentTimeOffsetFromVSyncNs */:
                {
                    _hidl_request.enforceInterface(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

                    android.hardware.configstore.V1_0.OptionalInt64 _hidl_out_value = presentTimeOffsetFromVSyncNs();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.configstore.V1_0.OptionalInt64) _hidl_out_value).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 7 /* useHwcForRGBtoYUV */:
                {
                    _hidl_request.enforceInterface(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

                    android.hardware.configstore.V1_0.OptionalBool _hidl_out_value = useHwcForRGBtoYUV();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.configstore.V1_0.OptionalBool) _hidl_out_value).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 8 /* maxVirtualDisplaySize */:
                {
                    _hidl_request.enforceInterface(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

                    android.hardware.configstore.V1_0.OptionalUInt64 _hidl_out_value = maxVirtualDisplaySize();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.configstore.V1_0.OptionalUInt64) _hidl_out_value).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 9 /* hasSyncFramework */:
                {
                    _hidl_request.enforceInterface(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

                    android.hardware.configstore.V1_0.OptionalBool _hidl_out_value = hasSyncFramework();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.configstore.V1_0.OptionalBool) _hidl_out_value).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 10 /* useVrFlinger */:
                {
                    _hidl_request.enforceInterface(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

                    android.hardware.configstore.V1_0.OptionalBool _hidl_out_value = useVrFlinger();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.configstore.V1_0.OptionalBool) _hidl_out_value).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 11 /* maxFrameBufferAcquiredBuffers */:
                {
                    _hidl_request.enforceInterface(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

                    android.hardware.configstore.V1_0.OptionalInt64 _hidl_out_value = maxFrameBufferAcquiredBuffers();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.configstore.V1_0.OptionalInt64) _hidl_out_value).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 12 /* startGraphicsAllocatorService */:
                {
                    _hidl_request.enforceInterface(android.hardware.configstore.V1_0.ISurfaceFlingerConfigs.kInterfaceName);

                    android.hardware.configstore.V1_0.OptionalBool _hidl_out_value = startGraphicsAllocatorService();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.configstore.V1_0.OptionalBool) _hidl_out_value).writeToParcel(_hidl_reply);
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
