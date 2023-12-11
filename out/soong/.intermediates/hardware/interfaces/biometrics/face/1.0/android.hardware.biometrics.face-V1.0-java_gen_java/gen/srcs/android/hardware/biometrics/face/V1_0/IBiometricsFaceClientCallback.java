package android.hardware.biometrics.face.V1_0;

/**
 * This callback interface is used by clients to recieve updates from the face
 * HAL.
 */
public interface IBiometricsFaceClientCallback extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.biometrics.face@1.0::IBiometricsFaceClientCallback";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IBiometricsFaceClientCallback asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IBiometricsFaceClientCallback)) {
            return (IBiometricsFaceClientCallback)iface;
        }

        IBiometricsFaceClientCallback proxy = new IBiometricsFaceClientCallback.Proxy(binder);

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
    public static IBiometricsFaceClientCallback castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IBiometricsFaceClientCallback.asInterface(iface.asBinder());
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
    public static IBiometricsFaceClientCallback getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IBiometricsFaceClientCallback.asInterface(android.os.HwBinder.getService("android.hardware.biometrics.face@1.0::IBiometricsFaceClientCallback", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IBiometricsFaceClientCallback getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IBiometricsFaceClientCallback getService(String serviceName) throws android.os.RemoteException {
        return IBiometricsFaceClientCallback.asInterface(android.os.HwBinder.getService("android.hardware.biometrics.face@1.0::IBiometricsFaceClientCallback", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IBiometricsFaceClientCallback getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * A callback invoked when one enrollment step has been completed.
     *
     * @param deviceId A unique id associated with the HAL implementation
     *     service that processed this enrollment step.
     * @param faceId The id of the face template being enrolled.
     * @param userId The active user id for the template being enrolled.
     * @param remaining The number of remaining steps before enrolllment is
     *     complete or 0 if enrollment has completed successfully.
     */
    void onEnrollResult(long deviceId, int faceId, int userId, int remaining)
        throws android.os.RemoteException;
    /**
     * A callback invoked when a face has been successfully authenticated.
     *
     * @param deviceId A unique id associated with the HAL implementation
     *     service that processed this authentication attempt.
     * @param faceId The id of the face template that passed the authentication
     *     challenge.
     * @param userId The active user id for the authenticated face.
     * @param token The hardware authentication token associated with this
     *     authenticate operation.
     */
    void onAuthenticated(long deviceId, int faceId, int userId, java.util.ArrayList<Byte> token)
        throws android.os.RemoteException;
    /**
     * A callback invoked when a face is acquired.
     *
     * If a non-critical, recoverable error occurs during an enrollment or
     * authentication attempt, the HAL implementation must invoke this callback
     * to allow clients to inform the user that some actionable change must be
     * made.
     *
     * @param deviceId A unique id associated with the HAL implementation
     *     service that acquired a face.
     * @param userId The id of the active user associated with the attempted
     *     face acquisition.
     * @param acquiredInfo A message about the quality of the acquired image.
     * @param vendorCode An optional vendor-specific message. This is only valid
     *     when acquiredInfo == FaceAcquiredInfo.VENDOR. This message is opaque
     *     to the framework, and vendors must provide code to handle it. For
     *     example this can be used to guide enrollment in Settings or provide
     *     a message during authentication that is vendor-specific. The vendor
     *     is expected to provide help strings to cover all known values.
     */
    void onAcquired(long deviceId, int userId, int acquiredInfo, int vendorCode)
        throws android.os.RemoteException;
    /**
     * A callback invoked when an error has occured.
     *
     * @param deviceId A unique id associated with the HAL implementation
     *     service where this error occured.
     * @param userId The id of the active user when the error occured, or
     *     UserHandle::NONE if an active user had not been set yet.
     * @param error A message about the error that occurred.
     * @param vendorCode An optional, vendor-speicifc error message. Only valid
     *     when error == FaceError.VENDOR. This message is opaque to the
     *     framework, and vendors must provide code to handle it. For example,
     *     this scan be used to show the user an error message specific to the
     *     device. The vendor is expected to provide error strings to cover
     *     all known values.
     */
    void onError(long deviceId, int userId, int error, int vendorCode)
        throws android.os.RemoteException;
    /**
     * A callback invoked when a face template has been removed.
     *
     * @param deviceId A unique id associated with the HAL implementation
     *     service that processed this removal.
     * @param removed A list of ids that were removed.
     * @param userId The active user id for the removed face template.
     */
    void onRemoved(long deviceId, java.util.ArrayList<Integer> removed, int userId)
        throws android.os.RemoteException;
    /**
     * A callback invoked to enumerate all current face templates.
     *
     * @param deviceId A unique id associated with the HAL implementation
     *     service that processed this enumeration.
     * @param faceIds A list of ids of all currently enrolled face templates.
     * @param userId The active user id for the enumerated face template.
     */
    void onEnumerate(long deviceId, java.util.ArrayList<Integer> faceIds, int userId)
        throws android.os.RemoteException;
    /**
     * A callback invoked when the lockout state changes.
     *
     * This method must only be invoked when setActiveUser() is called,
     * when lockout starts, and when lockout ends. When lockout starts,
     * duration must be greater than 0, and when lockout ends, duration must
     * be 0. This must be called before calling onError() with parameters
     * LOCKOUT or LOCKOUT_PERMANENT. If the user is permanently locked out,
     * the duration must be MAX_UINT64.
     *
     * @param duration the remaining lockout duration in milliseconds, or 0
     *     if the user is not locked out.
     */
    void onLockoutChanged(long duration)
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

    public static final class Proxy implements IBiometricsFaceClientCallback {
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
            return "[class or subclass of " + IBiometricsFaceClientCallback.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::biometrics::face::V1_0::IBiometricsFaceClientCallback follow.
        @Override
        public void onEnrollResult(long deviceId, int faceId, int userId, int remaining)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName);
            _hidl_request.writeInt64(deviceId);
            _hidl_request.writeInt32(faceId);
            _hidl_request.writeInt32(userId);
            _hidl_request.writeInt32(remaining);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* onEnrollResult */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onAuthenticated(long deviceId, int faceId, int userId, java.util.ArrayList<Byte> token)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName);
            _hidl_request.writeInt64(deviceId);
            _hidl_request.writeInt32(faceId);
            _hidl_request.writeInt32(userId);
            _hidl_request.writeInt8Vector(token);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* onAuthenticated */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onAcquired(long deviceId, int userId, int acquiredInfo, int vendorCode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName);
            _hidl_request.writeInt64(deviceId);
            _hidl_request.writeInt32(userId);
            _hidl_request.writeInt32(acquiredInfo);
            _hidl_request.writeInt32(vendorCode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* onAcquired */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onError(long deviceId, int userId, int error, int vendorCode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName);
            _hidl_request.writeInt64(deviceId);
            _hidl_request.writeInt32(userId);
            _hidl_request.writeInt32(error);
            _hidl_request.writeInt32(vendorCode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* onError */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onRemoved(long deviceId, java.util.ArrayList<Integer> removed, int userId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName);
            _hidl_request.writeInt64(deviceId);
            _hidl_request.writeInt32Vector(removed);
            _hidl_request.writeInt32(userId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* onRemoved */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onEnumerate(long deviceId, java.util.ArrayList<Integer> faceIds, int userId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName);
            _hidl_request.writeInt64(deviceId);
            _hidl_request.writeInt32Vector(faceIds);
            _hidl_request.writeInt32(userId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* onEnumerate */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onLockoutChanged(long duration)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName);
            _hidl_request.writeInt64(duration);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* onLockoutChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
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

    public static abstract class Stub extends android.os.HwBinder implements IBiometricsFaceClientCallback {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-74,-27,93,119,-107,-69,-81,-48,17,-5,-107,-93,-74,-45,-107,75,-10,108,52,-98,20,-49,16,127,59,114,3,44,-29,-50,-76,72} /* b6e55d7795bbafd011fb95a3b6d3954bf66c349e14cf107f3b72032ce3ceb448 */,
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
                case 1 /* onEnrollResult */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName);

                    long deviceId = _hidl_request.readInt64();
                    int faceId = _hidl_request.readInt32();
                    int userId = _hidl_request.readInt32();
                    int remaining = _hidl_request.readInt32();
                    onEnrollResult(deviceId, faceId, userId, remaining);
                    break;
                }

                case 2 /* onAuthenticated */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName);

                    long deviceId = _hidl_request.readInt64();
                    int faceId = _hidl_request.readInt32();
                    int userId = _hidl_request.readInt32();
                    java.util.ArrayList<Byte> token = _hidl_request.readInt8Vector();
                    onAuthenticated(deviceId, faceId, userId, token);
                    break;
                }

                case 3 /* onAcquired */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName);

                    long deviceId = _hidl_request.readInt64();
                    int userId = _hidl_request.readInt32();
                    int acquiredInfo = _hidl_request.readInt32();
                    int vendorCode = _hidl_request.readInt32();
                    onAcquired(deviceId, userId, acquiredInfo, vendorCode);
                    break;
                }

                case 4 /* onError */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName);

                    long deviceId = _hidl_request.readInt64();
                    int userId = _hidl_request.readInt32();
                    int error = _hidl_request.readInt32();
                    int vendorCode = _hidl_request.readInt32();
                    onError(deviceId, userId, error, vendorCode);
                    break;
                }

                case 5 /* onRemoved */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName);

                    long deviceId = _hidl_request.readInt64();
                    java.util.ArrayList<Integer> removed = _hidl_request.readInt32Vector();
                    int userId = _hidl_request.readInt32();
                    onRemoved(deviceId, removed, userId);
                    break;
                }

                case 6 /* onEnumerate */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName);

                    long deviceId = _hidl_request.readInt64();
                    java.util.ArrayList<Integer> faceIds = _hidl_request.readInt32Vector();
                    int userId = _hidl_request.readInt32();
                    onEnumerate(deviceId, faceIds, userId);
                    break;
                }

                case 7 /* onLockoutChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.kInterfaceName);

                    long duration = _hidl_request.readInt64();
                    onLockoutChanged(duration);
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
