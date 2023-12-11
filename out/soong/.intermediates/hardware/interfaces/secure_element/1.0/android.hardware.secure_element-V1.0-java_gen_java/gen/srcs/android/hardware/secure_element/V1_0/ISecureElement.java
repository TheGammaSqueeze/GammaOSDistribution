package android.hardware.secure_element.V1_0;

/**
 * According to ISO/IEC 7816
 */
public interface ISecureElement extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.secure_element@1.0::ISecureElement";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static ISecureElement asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof ISecureElement)) {
            return (ISecureElement)iface;
        }

        ISecureElement proxy = new ISecureElement.Proxy(binder);

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
    public static ISecureElement castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : ISecureElement.asInterface(iface.asBinder());
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
    public static ISecureElement getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return ISecureElement.asInterface(android.os.HwBinder.getService("android.hardware.secure_element@1.0::ISecureElement", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static ISecureElement getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static ISecureElement getService(String serviceName) throws android.os.RemoteException {
        return ISecureElement.asInterface(android.os.HwBinder.getService("android.hardware.secure_element@1.0::ISecureElement", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static ISecureElement getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Initializes the Secure Element. This may include updating the applet
     * and/or vendor-specific initialization.
     *
     * HAL service must send onStateChange() with connected equal to true
     * after all the initialization has been successfully completed.
     * Clients must wait for a onStateChange(true) before opening channels.
     *
     * @param clientCallback callback used to sent status of the SE back to the
     *                       client
     */
    void init(android.hardware.secure_element.V1_0.ISecureElementHalCallback clientCallback)
        throws android.os.RemoteException;
    /**
     * Returns Answer to Reset as per ISO/IEC 7816
     *
     * @return response containing the response. Empty vector if Secure Element
     *                  doesn't support ATR.
     */
    java.util.ArrayList<Byte> getAtr()
        throws android.os.RemoteException;
    /**
     * Returns the current state of the card.
     *
     * This is particularly useful for removable
     * Secure Elements like UICC, Secure Elements on SD cards etc.
     *
     * @return present true if present, false otherwise
     */
    boolean isCardPresent()
        throws android.os.RemoteException;
    /**
     * Transmits an APDU command (as per ISO/IEC 7816) to the SE.
     *
     * @param data APDU command to be sent
     * @return response to the command. In case of error in communicating with
     *                  the secure element, an empty vector is returned.
     */
    java.util.ArrayList<Byte> transmit(java.util.ArrayList<Byte> data)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface openLogicalChannelCallback {
        public void onValues(android.hardware.secure_element.V1_0.LogicalChannelResponse response, byte status);
    }

    /**
     * Opens a logical channel with the Secure Element, selecting the applet
     * represented by the Application ID (AID).
     *
     * @param aid AID to uniquely identify the applet on the Secure Element
     * @param p2 P2 paramter of SELECT APDU as per ISO 7816-4
     * @return status SecureElementStatus::SUCCESS on success,
     *                SecureElementStatus::CHANNEL_NOT_AVAILABLE if secure
     *                element has reached the maximum limit on the number of
     *                channels it can support,
     *                SecureElementStatus::NO_SUCH_ELEMENT_ERROR if AID provided
     *                doesn't match any applet on the secure element and
     *                SecureElementStatus::UNSUPPORTED_OPERATION if operation
     *                provided by the P2 parameter is not permitted by the
     *                applet.
     *                SecureElementStatus::IOERROR if there was an error
     *                communicating with the Secure Element.
     * @return response On success, response to SELECT command is returned
     *                        empty vector on failure.
     */
    void openLogicalChannel(java.util.ArrayList<Byte> aid, byte p2, openLogicalChannelCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface openBasicChannelCallback {
        public void onValues(java.util.ArrayList<Byte> selectResponse, byte status);
    }

    /**
     * Opens a basic channel with the Secure Element, selecting the applet
     * represented by the Application ID (AID).
     *
     * @param aid AID to uniquely identify the applet on the Secure Element
     * @param p2 P2 paramter of SELECT APDU as per ISO 7816-4
     * @return status SecureElementStatus::SUCCESS on success,
     *                SecureElementStatus::CHANNEL_NOT_AVAILABLE if secure
     *                element has reached the maximum limit on the number of
     *                channels it can support,
     *                SecureElementStatus::NO_SUCH_ELEMENT_ERROR if AID provided
     *                doesn't match any applet on the secure element and
     *                SecureElementStatus::UNSUPPORTED_OPERATION if operation
     *                provided by the P2 parameter is not permitted by the
     *                applet.
     *                SecureElementStatus::IOERROR if there was an error
     *                communicating with the Secure Element.
     * @return selectResponse On success, response to SELECT command is returned
     *                        empty vector on failure.
     */
    void openBasicChannel(java.util.ArrayList<Byte> aid, byte p2, openBasicChannelCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Closes the channel indicated by the channelNumber.
     *
     * Closing a basic channel, i.e with channelNumber 0 must return
     * SecureElementStatus::FAILED.
     *
     * @param channelNumber to be closed
     * @return status SecureElementStatus::SUCCESS on success and
     *                SecureElementStatus::FAILED on error.
     */
    byte closeChannel(byte channelNumber)
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

    public static final class Proxy implements ISecureElement {
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
            return "[class or subclass of " + ISecureElement.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::secure_element::V1_0::ISecureElement follow.
        @Override
        public void init(android.hardware.secure_element.V1_0.ISecureElementHalCallback clientCallback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName);
            _hidl_request.writeStrongBinder(clientCallback == null ? null : clientCallback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* init */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public java.util.ArrayList<Byte> getAtr()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* getAtr */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<Byte> _hidl_out_response = _hidl_reply.readInt8Vector();
                return _hidl_out_response;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean isCardPresent()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* isCardPresent */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_present = _hidl_reply.readBool();
                return _hidl_out_present;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public java.util.ArrayList<Byte> transmit(java.util.ArrayList<Byte> data)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName);
            _hidl_request.writeInt8Vector(data);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* transmit */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<Byte> _hidl_out_response = _hidl_reply.readInt8Vector();
                return _hidl_out_response;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void openLogicalChannel(java.util.ArrayList<Byte> aid, byte p2, openLogicalChannelCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName);
            _hidl_request.writeInt8Vector(aid);
            _hidl_request.writeInt8(p2);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* openLogicalChannel */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.secure_element.V1_0.LogicalChannelResponse _hidl_out_response = new android.hardware.secure_element.V1_0.LogicalChannelResponse();
                ((android.hardware.secure_element.V1_0.LogicalChannelResponse) _hidl_out_response).readFromParcel(_hidl_reply);
                byte _hidl_out_status = _hidl_reply.readInt8();
                _hidl_cb.onValues(_hidl_out_response, _hidl_out_status);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void openBasicChannel(java.util.ArrayList<Byte> aid, byte p2, openBasicChannelCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName);
            _hidl_request.writeInt8Vector(aid);
            _hidl_request.writeInt8(p2);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* openBasicChannel */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<Byte> _hidl_out_selectResponse = _hidl_reply.readInt8Vector();
                byte _hidl_out_status = _hidl_reply.readInt8();
                _hidl_cb.onValues(_hidl_out_selectResponse, _hidl_out_status);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public byte closeChannel(byte channelNumber)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName);
            _hidl_request.writeInt8(channelNumber);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* closeChannel */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                byte _hidl_out_status = _hidl_reply.readInt8();
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

    public static abstract class Stub extends android.os.HwBinder implements ISecureElement {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-67,118,-103,-16,123,-91,57,35,16,-2,-3,51,-22,-106,78,1,-12,-12,-90,96,21,20,104,69,-56,80,85,0,72,35,-52,-127} /* bd7699f07ba5392310fefd33ea964e01f4f4a66015146845c85055004823cc81 */,
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
                case 1 /* init */:
                {
                    _hidl_request.enforceInterface(android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName);

                    android.hardware.secure_element.V1_0.ISecureElementHalCallback clientCallback = android.hardware.secure_element.V1_0.ISecureElementHalCallback.asInterface(_hidl_request.readStrongBinder());
                    init(clientCallback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 2 /* getAtr */:
                {
                    _hidl_request.enforceInterface(android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName);

                    java.util.ArrayList<Byte> _hidl_out_response = getAtr();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt8Vector(_hidl_out_response);
                    _hidl_reply.send();
                    break;
                }

                case 3 /* isCardPresent */:
                {
                    _hidl_request.enforceInterface(android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName);

                    boolean _hidl_out_present = isCardPresent();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_present);
                    _hidl_reply.send();
                    break;
                }

                case 4 /* transmit */:
                {
                    _hidl_request.enforceInterface(android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName);

                    java.util.ArrayList<Byte> data = _hidl_request.readInt8Vector();
                    java.util.ArrayList<Byte> _hidl_out_response = transmit(data);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt8Vector(_hidl_out_response);
                    _hidl_reply.send();
                    break;
                }

                case 5 /* openLogicalChannel */:
                {
                    _hidl_request.enforceInterface(android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName);

                    java.util.ArrayList<Byte> aid = _hidl_request.readInt8Vector();
                    byte p2 = _hidl_request.readInt8();
                    openLogicalChannel(aid, p2, new openLogicalChannelCallback() {
                        @Override
                        public void onValues(android.hardware.secure_element.V1_0.LogicalChannelResponse response, byte status) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.secure_element.V1_0.LogicalChannelResponse) response).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt8(status);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 6 /* openBasicChannel */:
                {
                    _hidl_request.enforceInterface(android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName);

                    java.util.ArrayList<Byte> aid = _hidl_request.readInt8Vector();
                    byte p2 = _hidl_request.readInt8();
                    openBasicChannel(aid, p2, new openBasicChannelCallback() {
                        @Override
                        public void onValues(java.util.ArrayList<Byte> selectResponse, byte status) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt8Vector(selectResponse);
                            _hidl_reply.writeInt8(status);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 7 /* closeChannel */:
                {
                    _hidl_request.enforceInterface(android.hardware.secure_element.V1_0.ISecureElement.kInterfaceName);

                    byte channelNumber = _hidl_request.readInt8();
                    byte _hidl_out_status = closeChannel(channelNumber);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt8(_hidl_out_status);
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
