package vendor.samsung.hardware.sysinput.V1_2;

public interface ISehSysInputDev extends vendor.samsung.hardware.sysinput.V1_1.ISehSysInputDev {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "vendor.samsung.hardware.sysinput@1.2::ISehSysInputDev";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static ISehSysInputDev asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof ISehSysInputDev)) {
            return (ISehSysInputDev)iface;
        }

        ISehSysInputDev proxy = new ISehSysInputDev.Proxy(binder);

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
    public static ISehSysInputDev castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : ISehSysInputDev.asInterface(iface.asBinder());
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
    public static ISehSysInputDev getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return ISehSysInputDev.asInterface(android.os.HwBinder.getService("vendor.samsung.hardware.sysinput@1.2::ISehSysInputDev", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static ISehSysInputDev getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static ISehSysInputDev getService(String serviceName) throws android.os.RemoteException {
        return ISehSysInputDev.asInterface(android.os.HwBinder.getService("vendor.samsung.hardware.sysinput@1.2::ISehSysInputDev", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static ISehSysInputDev getService() throws android.os.RemoteException {
        return getService("default");
    }


    @java.lang.FunctionalInterface
    public interface initTspRawDataCallback {
        public void onValues(int retval, java.util.ArrayList<Short> mmap_max_num);
    }

    void initTspRawData(int devid, int mode, initTspRawDataCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface pollTspIrqCallback {
        public void onValues(int retval, java.util.ArrayList<Short> count);
    }

    void pollTspIrq(int devId, pollTspIrqCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getTspRawdataCallback {
        public void onValues(int retval, java.util.ArrayList<Short> data);
    }

    void getTspRawdata(int devid, getTspRawdataCallback _hidl_cb)
        throws android.os.RemoteException;
    int openTaas()
        throws android.os.RemoteException;
    int closeTaas()
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface readTaasCallback {
        public void onValues(int retval, String outbuf);
    }

    void readTaas(readTaasCallback _hidl_cb)
        throws android.os.RemoteException;
    int writeTaas(String buf)
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

    public static final class Proxy implements ISehSysInputDev {
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
            return "[class or subclass of " + ISehSysInputDev.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::vendor::samsung::hardware::sysinput::V1_0::ISehSysInputDev follow.
        @Override
        public void getKeyCodePressed(int keycode, getKeyCodePressedCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeInt32(keycode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* getKeyCodePressed */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                String _hidl_out_outbuf = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_outbuf);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void runTspCmd(int devId, String cmdname, runTspCmdCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeInt32(devId);
            _hidl_request.writeString(cmdname);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* runTspCmd */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                String _hidl_out_outbuf = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_outbuf);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getTspScrubPosition(int devid, getTspScrubPositionCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeInt32(devid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* getTspScrubPosition */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                String _hidl_out_outbuf = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_outbuf);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getTspSupportFeature(int devid, getTspSupportFeatureCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeInt32(devid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* getTspSupportFeature */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                String _hidl_out_outbuf = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_outbuf);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getTspCommandList(int devid, getTspCommandListCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeInt32(devid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* getTspCommandList */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                String _hidl_out_outbuf = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_outbuf);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getTspAodActiveArea(int devid, getTspAodActiveAreaCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeInt32(devid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* getTspAodActiveArea */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                String _hidl_out_outbuf = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_outbuf);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getTspFodInformation(int devid, getTspFodInformationCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeInt32(devid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* getTspFodInformation */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                String _hidl_out_outbuf = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_outbuf);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getTspFodPosition(int devid, getTspFodPositionCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeInt32(devid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* getTspFodPosition */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                String _hidl_out_outbuf = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_outbuf);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void runSpenCmd(String cmdname, runSpenCmdCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeString(cmdname);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* runSpenCmd */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                String _hidl_out_outbuf = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_outbuf);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSpenPosition(getSpenPositionCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* getSpenPosition */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                String _hidl_out_outbuf = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_outbuf);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSpenCommandList(getSpenCommandListCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* getSpenCommandList */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                String _hidl_out_outbuf = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_outbuf);
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::vendor::samsung::hardware::sysinput::V1_1::ISehSysInputDev follow.
        @Override
        public int runTspCmdNoRead(int devid, String cmdname)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_1.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeInt32(devid);
            _hidl_request.writeString(cmdname);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* runTspCmdNoRead */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                return _hidl_out_retval;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int runSpenCmdNoRead(String cmdname)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_1.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeString(cmdname);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* runSpenCmdNoRead */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                return _hidl_out_retval;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int setTspEnable(int devid, int enable, boolean isBefore)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_1.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeInt32(devid);
            _hidl_request.writeInt32(enable);
            _hidl_request.writeBool(isBefore);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* setTspEnable */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                return _hidl_out_retval;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int setSpenEnable(int enable, boolean isBefore)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_1.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeInt32(enable);
            _hidl_request.writeBool(isBefore);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* setSpenEnable */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                return _hidl_out_retval;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::vendor::samsung::hardware::sysinput::V1_2::ISehSysInputDev follow.
        @Override
        public void initTspRawData(int devid, int mode, initTspRawDataCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeInt32(devid);
            _hidl_request.writeInt32(mode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* initTspRawData */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                java.util.ArrayList<Short> _hidl_out_mmap_max_num = _hidl_reply.readInt16Vector();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_mmap_max_num);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void pollTspIrq(int devId, pollTspIrqCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeInt32(devId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* pollTspIrq */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                java.util.ArrayList<Short> _hidl_out_count = _hidl_reply.readInt16Vector();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_count);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getTspRawdata(int devid, getTspRawdataCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeInt32(devid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(18 /* getTspRawdata */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                java.util.ArrayList<Short> _hidl_out_data = _hidl_reply.readInt16Vector();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_data);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int openTaas()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(19 /* openTaas */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                return _hidl_out_retval;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int closeTaas()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(20 /* closeTaas */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                return _hidl_out_retval;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void readTaas(readTaasCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(21 /* readTaas */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                String _hidl_out_outbuf = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_outbuf);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int writeTaas(String buf)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName);
            _hidl_request.writeString(buf);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(22 /* writeTaas */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                return _hidl_out_retval;
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

    public static abstract class Stub extends android.os.HwBinder implements ISehSysInputDev {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName,
                    vendor.samsung.hardware.sysinput.V1_1.ISehSysInputDev.kInterfaceName,
                    vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} /* 0000000000000000000000000000000000000000000000000000000000000000 */,
                    new byte[/* 32 */]{-116,76,-95,120,17,80,-121,-86,-124,105,33,-74,104,-36,76,21,-39,-30,101,-91,52,68,26,-116,-23,124,87,-101,-92,52,18,-1} /* 8c4ca178115087aa846921b668dc4c15d9e265a534441a8ce97c579ba43412ff */,
                    new byte[/* 32 */]{-13,-101,82,109,118,110,80,65,-128,31,39,100,-90,-1,-63,108,-125,118,-113,35,-20,-117,-11,66,11,16,-102,-45,-127,74,-120,-118} /* f39b526d766e5041801f2764a6ffc16c83768f23ec8bf5420b109ad3814a888a */,
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
                case 1 /* getKeyCodePressed */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);

                    int keycode = _hidl_request.readInt32();
                    getKeyCodePressed(keycode, new getKeyCodePressedCallback() {
                        @Override
                        public void onValues(int retval, String outbuf) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeString(outbuf);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 2 /* runTspCmd */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);

                    int devId = _hidl_request.readInt32();
                    String cmdname = _hidl_request.readString();
                    runTspCmd(devId, cmdname, new runTspCmdCallback() {
                        @Override
                        public void onValues(int retval, String outbuf) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeString(outbuf);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 3 /* getTspScrubPosition */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);

                    int devid = _hidl_request.readInt32();
                    getTspScrubPosition(devid, new getTspScrubPositionCallback() {
                        @Override
                        public void onValues(int retval, String outbuf) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeString(outbuf);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 4 /* getTspSupportFeature */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);

                    int devid = _hidl_request.readInt32();
                    getTspSupportFeature(devid, new getTspSupportFeatureCallback() {
                        @Override
                        public void onValues(int retval, String outbuf) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeString(outbuf);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 5 /* getTspCommandList */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);

                    int devid = _hidl_request.readInt32();
                    getTspCommandList(devid, new getTspCommandListCallback() {
                        @Override
                        public void onValues(int retval, String outbuf) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeString(outbuf);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 6 /* getTspAodActiveArea */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);

                    int devid = _hidl_request.readInt32();
                    getTspAodActiveArea(devid, new getTspAodActiveAreaCallback() {
                        @Override
                        public void onValues(int retval, String outbuf) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeString(outbuf);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 7 /* getTspFodInformation */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);

                    int devid = _hidl_request.readInt32();
                    getTspFodInformation(devid, new getTspFodInformationCallback() {
                        @Override
                        public void onValues(int retval, String outbuf) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeString(outbuf);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 8 /* getTspFodPosition */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);

                    int devid = _hidl_request.readInt32();
                    getTspFodPosition(devid, new getTspFodPositionCallback() {
                        @Override
                        public void onValues(int retval, String outbuf) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeString(outbuf);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 9 /* runSpenCmd */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);

                    String cmdname = _hidl_request.readString();
                    runSpenCmd(cmdname, new runSpenCmdCallback() {
                        @Override
                        public void onValues(int retval, String outbuf) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeString(outbuf);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 10 /* getSpenPosition */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);

                    getSpenPosition(new getSpenPositionCallback() {
                        @Override
                        public void onValues(int retval, String outbuf) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeString(outbuf);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 11 /* getSpenCommandList */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_0.ISehSysInputDev.kInterfaceName);

                    getSpenCommandList(new getSpenCommandListCallback() {
                        @Override
                        public void onValues(int retval, String outbuf) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeString(outbuf);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 12 /* runTspCmdNoRead */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_1.ISehSysInputDev.kInterfaceName);

                    int devid = _hidl_request.readInt32();
                    String cmdname = _hidl_request.readString();
                    int _hidl_out_retval = runTspCmdNoRead(devid, cmdname);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_retval);
                    _hidl_reply.send();
                    break;
                }

                case 13 /* runSpenCmdNoRead */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_1.ISehSysInputDev.kInterfaceName);

                    String cmdname = _hidl_request.readString();
                    int _hidl_out_retval = runSpenCmdNoRead(cmdname);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_retval);
                    _hidl_reply.send();
                    break;
                }

                case 14 /* setTspEnable */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_1.ISehSysInputDev.kInterfaceName);

                    int devid = _hidl_request.readInt32();
                    int enable = _hidl_request.readInt32();
                    boolean isBefore = _hidl_request.readBool();
                    int _hidl_out_retval = setTspEnable(devid, enable, isBefore);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_retval);
                    _hidl_reply.send();
                    break;
                }

                case 15 /* setSpenEnable */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_1.ISehSysInputDev.kInterfaceName);

                    int enable = _hidl_request.readInt32();
                    boolean isBefore = _hidl_request.readBool();
                    int _hidl_out_retval = setSpenEnable(enable, isBefore);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_retval);
                    _hidl_reply.send();
                    break;
                }

                case 16 /* initTspRawData */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName);

                    int devid = _hidl_request.readInt32();
                    int mode = _hidl_request.readInt32();
                    initTspRawData(devid, mode, new initTspRawDataCallback() {
                        @Override
                        public void onValues(int retval, java.util.ArrayList<Short> mmap_max_num) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeInt16Vector(mmap_max_num);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 17 /* pollTspIrq */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName);

                    int devId = _hidl_request.readInt32();
                    pollTspIrq(devId, new pollTspIrqCallback() {
                        @Override
                        public void onValues(int retval, java.util.ArrayList<Short> count) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeInt16Vector(count);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 18 /* getTspRawdata */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName);

                    int devid = _hidl_request.readInt32();
                    getTspRawdata(devid, new getTspRawdataCallback() {
                        @Override
                        public void onValues(int retval, java.util.ArrayList<Short> data) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeInt16Vector(data);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 19 /* openTaas */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName);

                    int _hidl_out_retval = openTaas();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_retval);
                    _hidl_reply.send();
                    break;
                }

                case 20 /* closeTaas */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName);

                    int _hidl_out_retval = closeTaas();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_retval);
                    _hidl_reply.send();
                    break;
                }

                case 21 /* readTaas */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName);

                    readTaas(new readTaasCallback() {
                        @Override
                        public void onValues(int retval, String outbuf) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeString(outbuf);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 22 /* writeTaas */:
                {
                    _hidl_request.enforceInterface(vendor.samsung.hardware.sysinput.V1_2.ISehSysInputDev.kInterfaceName);

                    String buf = _hidl_request.readString();
                    int _hidl_out_retval = writeTaas(buf);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_retval);
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
