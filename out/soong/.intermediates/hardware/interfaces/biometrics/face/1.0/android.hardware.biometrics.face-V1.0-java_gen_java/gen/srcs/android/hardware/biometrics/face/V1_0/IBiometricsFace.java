package android.hardware.biometrics.face.V1_0;

/**
 * The HAL interface for biometric face authentication.
 */
public interface IBiometricsFace extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.biometrics.face@1.0::IBiometricsFace";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IBiometricsFace asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IBiometricsFace)) {
            return (IBiometricsFace)iface;
        }

        IBiometricsFace proxy = new IBiometricsFace.Proxy(binder);

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
    public static IBiometricsFace castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IBiometricsFace.asInterface(iface.asBinder());
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
    public static IBiometricsFace getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IBiometricsFace.asInterface(android.os.HwBinder.getService("android.hardware.biometrics.face@1.0::IBiometricsFace", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IBiometricsFace getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IBiometricsFace getService(String serviceName) throws android.os.RemoteException {
        return IBiometricsFace.asInterface(android.os.HwBinder.getService("android.hardware.biometrics.face@1.0::IBiometricsFace", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IBiometricsFace getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Sets the current client callback.
     *
     * Registers a user function that must receive notifications from the HAL.
     * There is usually only one client (FaceService). This call must block
     * if the HAL state machine is in busy state until the HAL leaves the
     * busy state.
     *
     * All callback methods pass a deviceId to differentiate callback
     * invocations in the case where multiple sensors exist.
     *
     * @param clientCallback The client defined callback to register.
     * @return result, with its "value" parameter representing a "deviceId",
     *     which must be unique for a given sensor.
     */
    android.hardware.biometrics.face.V1_0.OptionalUint64 setCallback(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback clientCallback)
        throws android.os.RemoteException;
    /**
     * Sets the active user, which all subsequent HAL operations are applied to.
     *
     * HAL service implementors must ensure that operations are restricted to
     * the given user. Clients must not call any part of this interface, except
     * for setCallback(), without first having set an active user. The
     * implementation is responsible for cancelling the current operation and
     * returning to the idle state. Calling this method with the same userId
     * should have no effect on the state machine.
     *
     * Note that onLockoutChanged() MUST be invoked by the implementation in
     * response to a user change in order to update the framework with the
     * timeout of the new user (or 0 if the user is not locked out).
     *
     * @param userId A non-negative user identifier that must be unique and
     *     persistent for a given user.
     * @param storePath absolute filesystem path to the template storage
     *     directory. This must be the /data/vendor_de/<user>/facedata
     *     directory specified by the SeLinux policy.
     */
    int setActiveUser(int userId, String storePath)
        throws android.os.RemoteException;
    /**
     * Begins a secure transaction request, e.g. enroll() or resetLockout().
     *
     * Generates a unique and cryptographically secure random token used to
     * indicate the start of a secure transaction. generateChallenge() and
     * revokeChallenge() specify a window where the resulting HAT that is
     * generated in response to checking the user's PIN/pattern/password
     * can be used to verify/perform a secure transaction.
     *
     * generateChallenge() generates a challenge which must then be wrapped by
     * gatekeeper after verifying a successful strong authentication attempt,
     * which generates a Hardware Authentication Token. The challenge prevents
     * spoofing and replay attacks and ensures that only a transaction backed
     * by a user authentication (PIN/pattern/password) can proceed.
     *
     * The implementation should be tolerant of revokeChallenge() being invoked
     * after timeout has expired.
     *
     * @param challengeTimeoutSec A timeout in seconds, after which the driver
     *     must invalidate the challenge. This is to prevent bugs or crashes in
     *     the system from leaving a challenge enabled indefinitely.
     * @return result, with its "value" parameter representing a "challenge": a
     *     unique and cryptographically secure random token.
     */
    android.hardware.biometrics.face.V1_0.OptionalUint64 generateChallenge(int challengeTimeoutSec)
        throws android.os.RemoteException;
    /**
     * Enrolls a user's face.
     *
     * Note that the Hardware Authentication Token must be valid for the
     * duration of enrollment and thus should be explicitly invalidated by a
     * call to revokeChallenge() when enrollment is complete, to reduce the
     * window of opportunity to re-use the challenge and HAT. For example,
     * Settings calls generateChallenge() once to allow the user to enroll one
     * or more faces or toggle secure settings without having to re-enter the
     * PIN/pattern/password. Once the user completes the operation, Settings
     * invokes revokeChallenge() to close the transaction. If the HAT is expired,
     * the implementation must invoke onError with UNABLE_TO_PROCESS.
     *
     * This method triggers the IBiometricsFaceClientCallback#onEnrollResult()
     * method.
     *
     * @param hat A valid Hardware Authentication Token, generated as a result
     *     of a generateChallenge() challenge being wrapped by the gatekeeper
     *     after a successful strong authentication request.
     * @param timeoutSec A timeout in seconds, after which this enroll
     *     attempt is cancelled. Note that the framework can continue
     *     enrollment by calling this again with a valid HAT. This timeout is
     *     expected to be used to limit power usage if the device becomes idle
     *     during enrollment. The implementation is expected to send
     *     ERROR_TIMEOUT if this happens.
     * @param disabledFeatures A list of features to be disabled during
     *     enrollment. Note that all features are enabled by default.
     * @return status The status of this method call.
     */
    int enroll(java.util.ArrayList<Byte> hat, int timeoutSec, java.util.ArrayList<Integer> disabledFeatures)
        throws android.os.RemoteException;
    /**
     * Finishes the secure transaction by invalidating the challenge generated
     * by generateChallenge().
     *
     * Clients must call this method once the secure transaction (e.g. enroll
     * or setFeature) is completed. See generateChallenge().
     *
     * @return status The status of this method call.
     */
    int revokeChallenge()
        throws android.os.RemoteException;
    /**
     * Changes the state of previous enrollment setting. Because this may
     * decrease security, the user must enter their password before this method
     * is invoked (see @param HAT). The driver must verify the HAT before
     * changing any feature state. This method must return ILLEGAL_ARGUMENT if
     * the HAT or faceId is invalid. This must only be invoked after
     * setActiveUser() is called.
     *
     * Note: In some cases it may not be possible to change the state of this
     * flag without re-enrolling. For example, if the user didn't provide
     * attention during the original enrollment. This flag reflects the same
     * persistent state as the one passed to enroll().
     *
     * Note: This call may block for a short amount of time (few hundred
     * milliseconds). Clients are expected to invoke this asynchronously if it
     * takes much longer than the above limit. Also note that the result is
     * returned solely through Status (and not onError).
     *
     * @param feature The feature to be enabled or disabled.
     * @param enabled True to enable the feature, false to disable.
     * @param hat A valid Hardware Authentication Token, generated as a result
     *     of getChallenge().
     * @param faceId the ID of the enrollment returned by onEnrollResult() for
     *     the feature to update.
     * @return status The status of this method call.
     */
    int setFeature(int feature, boolean enabled, java.util.ArrayList<Byte> hat, int faceId)
        throws android.os.RemoteException;
    /**
     * Retrieves the current state of the feature. If the faceId is invalid,
     * the implementation must return ILLEGAL_ARGUMENT.
     *
     * @param faceId the ID of the enrollment returned by enroll().
     * @return result with the value set to true if the feature is enabled,
     *     false if disabled.
     */
    android.hardware.biometrics.face.V1_0.OptionalBool getFeature(int feature, int faceId)
        throws android.os.RemoteException;
    /**
     * Returns an identifier associated with the current face set.
     *
     * The authenticator ID must change whenever a new face is enrolled. The
     * authenticator ID must not be changed when a face is deleted. The
     * authenticator ID must be an entropy-encoded random number which all
     * current templates are tied to. The authenticator ID must be immutable
     * outside of an active enrollment window to prevent replay attacks.
     *
     * @return result, with its value parameter representing an
     *     "authenticatorId": an identifier associated to the user's current
     *     face enrollment.
     */
    android.hardware.biometrics.face.V1_0.OptionalUint64 getAuthenticatorId()
        throws android.os.RemoteException;
    /**
     * Cancels the current enroll, authenticate, remove, or enumerate operation.
     *
     * @return status The status of this method call.
     */
    int cancel()
        throws android.os.RemoteException;
    /**
     * Enumerates all face templates associated with the active user.
     *
     * The onEnumerate() callback method is invoked once for each face template
     * found.
     *
     * @return status The status of this method call.
     */
    int enumerate()
        throws android.os.RemoteException;
    /**
     * Removes a face template or all face templates associated with the active
     * user.
     *
     * This method triggers the IBiometricsFaceClientCallback#onRemoved() method.
     *
     * @param faceId The id correpsonding to the face to be removed; or 0 if all
     *    faces are to be removed.
     * @return status The status of this method call.
     */
    int remove(int faceId)
        throws android.os.RemoteException;
    /**
     * Authenticates the active user.
     *
     * An optional operationId can be specified as a token from the transaction
     * being authorized. The hardware may enter a standby state during
     * authentication, where the device is idle to conserve power while
     * authenticating, e.g. after 3 seconds without finding a face. See
     * IBiometricsFace#userActivity() for more info.
     *
     * @param operationId A non-zero operation id associated with a crypto
     * object instance; or 0 if not being used.
     * @return status The status of this method call.
     */
    int authenticate(long operationId)
        throws android.os.RemoteException;
    /**
     * A hint to the HAL to continue looking for faces.
     *
     * This method should only be used when the HAL is in the authenticating
     * or standby state. Using this method when the HAL is not in one of the
     * mentioned states must return OPERATION_NOT_SUPPORTED. Calling this
     * method while the HAL is already authenticating may extend the duration
     * where it's looking for a face.
     *
     * @return status The status of this method call.
     */
    int userActivity()
        throws android.os.RemoteException;
    /**
     * Reset lockout for the current user.
     *
     * Note: This call may block for a short amount of time (few hundred
     * milliseconds). Clients are expected to invoke this asynchronously if it
     * takes much longer than the above limit.
     *
     * @param hat A valid Hardware Authentication Token, generated when the
     *     user authenticates with PIN/pattern/pass. When the Hardware
     *     Authentication Token is verified, lockout must be reset and
     *     onLockoutChanged must be called with duration 0.
     * @return status The status of this method call.
     */
    int resetLockout(java.util.ArrayList<Byte> hat)
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

    public static final class Proxy implements IBiometricsFace {
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
            return "[class or subclass of " + IBiometricsFace.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::biometrics::face::V1_0::IBiometricsFace follow.
        @Override
        public android.hardware.biometrics.face.V1_0.OptionalUint64 setCallback(android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback clientCallback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);
            _hidl_request.writeStrongBinder(clientCallback == null ? null : clientCallback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* setCallback */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.biometrics.face.V1_0.OptionalUint64 _hidl_out_result = new android.hardware.biometrics.face.V1_0.OptionalUint64();
                ((android.hardware.biometrics.face.V1_0.OptionalUint64) _hidl_out_result).readFromParcel(_hidl_reply);
                return _hidl_out_result;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int setActiveUser(int userId, String storePath)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);
            _hidl_request.writeInt32(userId);
            _hidl_request.writeString(storePath);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* setActiveUser */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_status = _hidl_reply.readInt32();
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.biometrics.face.V1_0.OptionalUint64 generateChallenge(int challengeTimeoutSec)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);
            _hidl_request.writeInt32(challengeTimeoutSec);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* generateChallenge */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.biometrics.face.V1_0.OptionalUint64 _hidl_out_result = new android.hardware.biometrics.face.V1_0.OptionalUint64();
                ((android.hardware.biometrics.face.V1_0.OptionalUint64) _hidl_out_result).readFromParcel(_hidl_reply);
                return _hidl_out_result;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int enroll(java.util.ArrayList<Byte> hat, int timeoutSec, java.util.ArrayList<Integer> disabledFeatures)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);
            _hidl_request.writeInt8Vector(hat);
            _hidl_request.writeInt32(timeoutSec);
            _hidl_request.writeInt32Vector(disabledFeatures);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* enroll */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_status = _hidl_reply.readInt32();
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int revokeChallenge()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* revokeChallenge */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_status = _hidl_reply.readInt32();
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int setFeature(int feature, boolean enabled, java.util.ArrayList<Byte> hat, int faceId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);
            _hidl_request.writeInt32(feature);
            _hidl_request.writeBool(enabled);
            _hidl_request.writeInt8Vector(hat);
            _hidl_request.writeInt32(faceId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* setFeature */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_status = _hidl_reply.readInt32();
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.biometrics.face.V1_0.OptionalBool getFeature(int feature, int faceId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);
            _hidl_request.writeInt32(feature);
            _hidl_request.writeInt32(faceId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* getFeature */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.biometrics.face.V1_0.OptionalBool _hidl_out_result = new android.hardware.biometrics.face.V1_0.OptionalBool();
                ((android.hardware.biometrics.face.V1_0.OptionalBool) _hidl_out_result).readFromParcel(_hidl_reply);
                return _hidl_out_result;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.biometrics.face.V1_0.OptionalUint64 getAuthenticatorId()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* getAuthenticatorId */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.biometrics.face.V1_0.OptionalUint64 _hidl_out_result = new android.hardware.biometrics.face.V1_0.OptionalUint64();
                ((android.hardware.biometrics.face.V1_0.OptionalUint64) _hidl_out_result).readFromParcel(_hidl_reply);
                return _hidl_out_result;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int cancel()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* cancel */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_status = _hidl_reply.readInt32();
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int enumerate()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* enumerate */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_status = _hidl_reply.readInt32();
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int remove(int faceId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);
            _hidl_request.writeInt32(faceId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* remove */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_status = _hidl_reply.readInt32();
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int authenticate(long operationId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);
            _hidl_request.writeInt64(operationId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* authenticate */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_status = _hidl_reply.readInt32();
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int userActivity()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* userActivity */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_status = _hidl_reply.readInt32();
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int resetLockout(java.util.ArrayList<Byte> hat)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);
            _hidl_request.writeInt8Vector(hat);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* resetLockout */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_status = _hidl_reply.readInt32();
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

    public static abstract class Stub extends android.os.HwBinder implements IBiometricsFace {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-31,-113,-13,24,-13,-4,67,-37,55,-11,84,105,109,-60,-27,81,-85,-71,-79,25,-67,-27,57,80,-9,62,40,-50,51,-87,122,64} /* e18ff318f3fc43db37f554696dc4e551abb9b119bde53950f73e28ce33a97a40 */,
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
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

                    android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback clientCallback = android.hardware.biometrics.face.V1_0.IBiometricsFaceClientCallback.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.biometrics.face.V1_0.OptionalUint64 _hidl_out_result = setCallback(clientCallback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.biometrics.face.V1_0.OptionalUint64) _hidl_out_result).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 2 /* setActiveUser */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

                    int userId = _hidl_request.readInt32();
                    String storePath = _hidl_request.readString();
                    int _hidl_out_status = setActiveUser(userId, storePath);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_status);
                    _hidl_reply.send();
                    break;
                }

                case 3 /* generateChallenge */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

                    int challengeTimeoutSec = _hidl_request.readInt32();
                    android.hardware.biometrics.face.V1_0.OptionalUint64 _hidl_out_result = generateChallenge(challengeTimeoutSec);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.biometrics.face.V1_0.OptionalUint64) _hidl_out_result).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 4 /* enroll */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

                    java.util.ArrayList<Byte> hat = _hidl_request.readInt8Vector();
                    int timeoutSec = _hidl_request.readInt32();
                    java.util.ArrayList<Integer> disabledFeatures = _hidl_request.readInt32Vector();
                    int _hidl_out_status = enroll(hat, timeoutSec, disabledFeatures);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_status);
                    _hidl_reply.send();
                    break;
                }

                case 5 /* revokeChallenge */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

                    int _hidl_out_status = revokeChallenge();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_status);
                    _hidl_reply.send();
                    break;
                }

                case 6 /* setFeature */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

                    int feature = _hidl_request.readInt32();
                    boolean enabled = _hidl_request.readBool();
                    java.util.ArrayList<Byte> hat = _hidl_request.readInt8Vector();
                    int faceId = _hidl_request.readInt32();
                    int _hidl_out_status = setFeature(feature, enabled, hat, faceId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_status);
                    _hidl_reply.send();
                    break;
                }

                case 7 /* getFeature */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

                    int feature = _hidl_request.readInt32();
                    int faceId = _hidl_request.readInt32();
                    android.hardware.biometrics.face.V1_0.OptionalBool _hidl_out_result = getFeature(feature, faceId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.biometrics.face.V1_0.OptionalBool) _hidl_out_result).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 8 /* getAuthenticatorId */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

                    android.hardware.biometrics.face.V1_0.OptionalUint64 _hidl_out_result = getAuthenticatorId();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.biometrics.face.V1_0.OptionalUint64) _hidl_out_result).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 9 /* cancel */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

                    int _hidl_out_status = cancel();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_status);
                    _hidl_reply.send();
                    break;
                }

                case 10 /* enumerate */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

                    int _hidl_out_status = enumerate();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_status);
                    _hidl_reply.send();
                    break;
                }

                case 11 /* remove */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

                    int faceId = _hidl_request.readInt32();
                    int _hidl_out_status = remove(faceId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_status);
                    _hidl_reply.send();
                    break;
                }

                case 12 /* authenticate */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

                    long operationId = _hidl_request.readInt64();
                    int _hidl_out_status = authenticate(operationId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_status);
                    _hidl_reply.send();
                    break;
                }

                case 13 /* userActivity */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

                    int _hidl_out_status = userActivity();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_status);
                    _hidl_reply.send();
                    break;
                }

                case 14 /* resetLockout */:
                {
                    _hidl_request.enforceInterface(android.hardware.biometrics.face.V1_0.IBiometricsFace.kInterfaceName);

                    java.util.ArrayList<Byte> hat = _hidl_request.readInt8Vector();
                    int _hidl_out_status = resetLockout(hat);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_status);
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
