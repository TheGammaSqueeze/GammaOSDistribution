package vendor.huawei.hardware.tp.V1_0;

public interface ITouchscreen extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "vendor.huawei.hardware.tp@1.0::ITouchscreen";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static ITouchscreen asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof ITouchscreen)) {
            return (ITouchscreen)iface;
        }

        ITouchscreen proxy = new ITouchscreen.Proxy(binder);

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
    public static ITouchscreen castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : ITouchscreen.asInterface(iface.asBinder());
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
    public static ITouchscreen getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return ITouchscreen.asInterface(android.os.HwBinder.getService("vendor.huawei.hardware.tp@1.0::ITouchscreen", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static ITouchscreen getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static ITouchscreen getService(String serviceName) throws android.os.RemoteException {
        return ITouchscreen.asInterface(android.os.HwBinder.getService("vendor.huawei.hardware.tp@1.0::ITouchscreen", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static ITouchscreen getService() throws android.os.RemoteException {
        return getService("default");
    }

    boolean hwTsSetGloveMode(boolean status)
        throws android.os.RemoteException;
    boolean hwTsSetCoverMode(boolean status)
        throws android.os.RemoteException;
    boolean hwTsSetCoverWindowSize(boolean status, int x0, int y0, int x1, int y1)
        throws android.os.RemoteException;
    boolean hwTsSetRoiEnable(boolean status)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface hwTsGetRoiDataCallback {
        public void onValues(boolean ret, java.util.ArrayList<Integer> arg);
    }

    void hwTsGetRoiData(hwTsGetRoiDataCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface hwTsGetChipInfoCallback {
        public void onValues(boolean ret, String chip_info);
    }

    void hwTsGetChipInfo(hwTsGetChipInfoCallback _hidl_cb)
        throws android.os.RemoteException;
    boolean hwTsSetEasyWeakupGesture(int gesture)
        throws android.os.RemoteException;
    boolean hwTsSetEasyWeakupGestureReportEnable(boolean status)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface hwTsGetEasyWeakupGuestureDataCallback {
        public void onValues(boolean ret, java.util.ArrayList<Integer> gusture_data);
    }

    void hwTsGetEasyWeakupGuestureData(hwTsGetEasyWeakupGuestureDataCallback _hidl_cb)
        throws android.os.RemoteException;
    void hwTsSetDozeMode(int optype, int status, int delaytime)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface hwTsCapacitanceMmiTestCallback {
        public void onValues(int ret, String fail_reason);
    }

    void hwTsCapacitanceMmiTest(hwTsCapacitanceMmiTestCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface hwTsCapacitanceRunningTestCallback {
        public void onValues(int ret, String fail_reason);
    }

    void hwTsCapacitanceRunningTest(int runningTestStatus, hwTsCapacitanceRunningTestCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface hwTsCalibrationTestCallback {
        public void onValues(int ret, String fail_reason);
    }

    void hwTsCalibrationTest(int testMode, hwTsCalibrationTestCallback _hidl_cb)
        throws android.os.RemoteException;
    int hwTsSnrTest()
        throws android.os.RemoteException;
    boolean hwTsPressCalSetEndTimeOfAgeing()
        throws android.os.RemoteException;
    long hwTsPressCalGetLeftTimeOfStartCalibration()
        throws android.os.RemoteException;
    boolean hwTsPressCalIsSupportCalibration()
        throws android.os.RemoteException;
    boolean hwTsPressCalSetTypeOfCalibration(int type)
        throws android.os.RemoteException;
    boolean hwTsPressCalSet_range_of_spec(int range)
        throws android.os.RemoteException;
    boolean hwTsPressCalGetStateOfHandle()
        throws android.os.RemoteException;
    boolean hwTsPressCalSetCountOfCalibration(int count)
        throws android.os.RemoteException;
    boolean hwTsPressCalGetCountOfCalibration()
        throws android.os.RemoteException;
    boolean hwTsPressCalSetSizeOfVerifyPoint(int size)
        throws android.os.RemoteException;
    int hwTsPressCalGetSizeOfVerifyPoint()
        throws android.os.RemoteException;
    int hwTsPressCalGetResultOfVerifyPoint(int point)
        throws android.os.RemoteException;
    boolean hwTsPressCalOpenCalibrationModule()
        throws android.os.RemoteException;
    boolean hwTsPressCalCloseCalibrationModule()
        throws android.os.RemoteException;
    boolean hwTsPressCalStartCalibration(int number)
        throws android.os.RemoteException;
    boolean hwTsPressCalStopCalibration(int number)
        throws android.os.RemoteException;
    boolean hwTsPressCalStartVerify(int number)
        throws android.os.RemoteException;
    boolean hwTsPressCalStopVerify(int number)
        throws android.os.RemoteException;
    int hwTsPressCalGetVersionInformation(int type)
        throws android.os.RemoteException;
    int hwTsPressCalZcalPosChecking(int p, int x, int y)
        throws android.os.RemoteException;
    int hwTsSetAftAlgoState(int enable)
        throws android.os.RemoteException;
    int hwTsSetAftAlgoOrientation(int orientation)
        throws android.os.RemoteException;
    int hwTsSetAftConfig(String config)
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

    public static final class Proxy implements ITouchscreen {
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
            return "[class or subclass of " + ITouchscreen.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::vendor::huawei::hardware::tp::V1_0::ITouchscreen follow.
        @Override
        public boolean hwTsSetGloveMode(boolean status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeBool(status);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* hwTsSetGloveMode */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsSetCoverMode(boolean status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeBool(status);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* hwTsSetCoverMode */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsSetCoverWindowSize(boolean status, int x0, int y0, int x1, int y1)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeBool(status);
            _hidl_request.writeInt32(x0);
            _hidl_request.writeInt32(y0);
            _hidl_request.writeInt32(x1);
            _hidl_request.writeInt32(y1);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* hwTsSetCoverWindowSize */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsSetRoiEnable(boolean status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeBool(status);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* hwTsSetRoiEnable */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void hwTsGetRoiData(hwTsGetRoiDataCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* hwTsGetRoiData */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                java.util.ArrayList<Integer> _hidl_out_arg = _hidl_reply.readInt32Vector();
                _hidl_cb.onValues(_hidl_out_ret, _hidl_out_arg);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void hwTsGetChipInfo(hwTsGetChipInfoCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* hwTsGetChipInfo */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                String _hidl_out_chip_info = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_ret, _hidl_out_chip_info);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsSetEasyWeakupGesture(int gesture)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(gesture);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* hwTsSetEasyWeakupGesture */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsSetEasyWeakupGestureReportEnable(boolean status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeBool(status);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* hwTsSetEasyWeakupGestureReportEnable */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void hwTsGetEasyWeakupGuestureData(hwTsGetEasyWeakupGuestureDataCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* hwTsGetEasyWeakupGuestureData */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                java.util.ArrayList<Integer> _hidl_out_gusture_data = _hidl_reply.readInt32Vector();
                _hidl_cb.onValues(_hidl_out_ret, _hidl_out_gusture_data);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void hwTsSetDozeMode(int optype, int status, int delaytime)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(optype);
            _hidl_request.writeInt32(status);
            _hidl_request.writeInt32(delaytime);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* hwTsSetDozeMode */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void hwTsCapacitanceMmiTest(hwTsCapacitanceMmiTestCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* hwTsCapacitanceMmiTest */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_ret = _hidl_reply.readInt32();
                String _hidl_out_fail_reason = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_ret, _hidl_out_fail_reason);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void hwTsCapacitanceRunningTest(int runningTestStatus, hwTsCapacitanceRunningTestCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(runningTestStatus);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* hwTsCapacitanceRunningTest */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_ret = _hidl_reply.readInt32();
                String _hidl_out_fail_reason = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_ret, _hidl_out_fail_reason);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void hwTsCalibrationTest(int testMode, hwTsCalibrationTestCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(testMode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* hwTsCalibrationTest */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_ret = _hidl_reply.readInt32();
                String _hidl_out_fail_reason = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_ret, _hidl_out_fail_reason);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int hwTsSnrTest()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* hwTsSnrTest */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_ret = _hidl_reply.readInt32();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsPressCalSetEndTimeOfAgeing()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* hwTsPressCalSetEndTimeOfAgeing */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public long hwTsPressCalGetLeftTimeOfStartCalibration()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* hwTsPressCalGetLeftTimeOfStartCalibration */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                long _hidl_out_left_time = _hidl_reply.readInt64();
                return _hidl_out_left_time;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsPressCalIsSupportCalibration()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* hwTsPressCalIsSupportCalibration */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsPressCalSetTypeOfCalibration(int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(18 /* hwTsPressCalSetTypeOfCalibration */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsPressCalSet_range_of_spec(int range)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(range);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(19 /* hwTsPressCalSet_range_of_spec */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsPressCalGetStateOfHandle()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(20 /* hwTsPressCalGetStateOfHandle */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsPressCalSetCountOfCalibration(int count)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(count);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(21 /* hwTsPressCalSetCountOfCalibration */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsPressCalGetCountOfCalibration()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(22 /* hwTsPressCalGetCountOfCalibration */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsPressCalSetSizeOfVerifyPoint(int size)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(size);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(23 /* hwTsPressCalSetSizeOfVerifyPoint */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int hwTsPressCalGetSizeOfVerifyPoint()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(24 /* hwTsPressCalGetSizeOfVerifyPoint */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_count = _hidl_reply.readInt32();
                return _hidl_out_count;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int hwTsPressCalGetResultOfVerifyPoint(int point)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(point);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(25 /* hwTsPressCalGetResultOfVerifyPoint */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_result = _hidl_reply.readInt32();
                return _hidl_out_result;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsPressCalOpenCalibrationModule()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(26 /* hwTsPressCalOpenCalibrationModule */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsPressCalCloseCalibrationModule()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(27 /* hwTsPressCalCloseCalibrationModule */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsPressCalStartCalibration(int number)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(number);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(28 /* hwTsPressCalStartCalibration */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsPressCalStopCalibration(int number)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(number);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(29 /* hwTsPressCalStopCalibration */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsPressCalStartVerify(int number)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(number);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(30 /* hwTsPressCalStartVerify */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean hwTsPressCalStopVerify(int number)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(number);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(31 /* hwTsPressCalStopVerify */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_ret = _hidl_reply.readBool();
                return _hidl_out_ret;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int hwTsPressCalGetVersionInformation(int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(32 /* hwTsPressCalGetVersionInformation */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_version = _hidl_reply.readInt32();
                return _hidl_out_version;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int hwTsPressCalZcalPosChecking(int p, int x, int y)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(p);
            _hidl_request.writeInt32(x);
            _hidl_request.writeInt32(y);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(33 /* hwTsPressCalZcalPosChecking */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_code = _hidl_reply.readInt32();
                return _hidl_out_code;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int hwTsSetAftAlgoState(int enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(34 /* hwTsSetAftAlgoState */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_code = _hidl_reply.readInt32();
                return _hidl_out_code;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int hwTsSetAftAlgoOrientation(int orientation)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeInt32(orientation);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(35 /* hwTsSetAftAlgoOrientation */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_code = _hidl_reply.readInt32();
                return _hidl_out_code;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int hwTsSetAftConfig(String config)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);
            _hidl_request.writeString(config);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(36 /* hwTsSetAftConfig */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_code = _hidl_reply.readInt32();
                return _hidl_out_code;
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

    public static abstract class Stub extends android.os.HwBinder implements ITouchscreen {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} /* 0000000000000000000000000000000000000000000000000000000000000000 */,
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
                case 1 /* hwTsSetGloveMode */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    boolean status = _hidl_request.readBool();
                    boolean _hidl_out_ret = hwTsSetGloveMode(status);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 2 /* hwTsSetCoverMode */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    boolean status = _hidl_request.readBool();
                    boolean _hidl_out_ret = hwTsSetCoverMode(status);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 3 /* hwTsSetCoverWindowSize */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    boolean status = _hidl_request.readBool();
                    int x0 = _hidl_request.readInt32();
                    int y0 = _hidl_request.readInt32();
                    int x1 = _hidl_request.readInt32();
                    int y1 = _hidl_request.readInt32();
                    boolean _hidl_out_ret = hwTsSetCoverWindowSize(status, x0, y0, x1, y1);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 4 /* hwTsSetRoiEnable */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    boolean status = _hidl_request.readBool();
                    boolean _hidl_out_ret = hwTsSetRoiEnable(status);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 5 /* hwTsGetRoiData */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    hwTsGetRoiData(new hwTsGetRoiDataCallback() {
                        @Override
                        public void onValues(boolean ret, java.util.ArrayList<Integer> arg) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeBool(ret);
                            _hidl_reply.writeInt32Vector(arg);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 6 /* hwTsGetChipInfo */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    hwTsGetChipInfo(new hwTsGetChipInfoCallback() {
                        @Override
                        public void onValues(boolean ret, String chip_info) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeBool(ret);
                            _hidl_reply.writeString(chip_info);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 7 /* hwTsSetEasyWeakupGesture */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int gesture = _hidl_request.readInt32();
                    boolean _hidl_out_ret = hwTsSetEasyWeakupGesture(gesture);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 8 /* hwTsSetEasyWeakupGestureReportEnable */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    boolean status = _hidl_request.readBool();
                    boolean _hidl_out_ret = hwTsSetEasyWeakupGestureReportEnable(status);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 9 /* hwTsGetEasyWeakupGuestureData */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    hwTsGetEasyWeakupGuestureData(new hwTsGetEasyWeakupGuestureDataCallback() {
                        @Override
                        public void onValues(boolean ret, java.util.ArrayList<Integer> gusture_data) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeBool(ret);
                            _hidl_reply.writeInt32Vector(gusture_data);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 10 /* hwTsSetDozeMode */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int optype = _hidl_request.readInt32();
                    int status = _hidl_request.readInt32();
                    int delaytime = _hidl_request.readInt32();
                    hwTsSetDozeMode(optype, status, delaytime);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 11 /* hwTsCapacitanceMmiTest */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    hwTsCapacitanceMmiTest(new hwTsCapacitanceMmiTestCallback() {
                        @Override
                        public void onValues(int ret, String fail_reason) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(ret);
                            _hidl_reply.writeString(fail_reason);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 12 /* hwTsCapacitanceRunningTest */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int runningTestStatus = _hidl_request.readInt32();
                    hwTsCapacitanceRunningTest(runningTestStatus, new hwTsCapacitanceRunningTestCallback() {
                        @Override
                        public void onValues(int ret, String fail_reason) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(ret);
                            _hidl_reply.writeString(fail_reason);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 13 /* hwTsCalibrationTest */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int testMode = _hidl_request.readInt32();
                    hwTsCalibrationTest(testMode, new hwTsCalibrationTestCallback() {
                        @Override
                        public void onValues(int ret, String fail_reason) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(ret);
                            _hidl_reply.writeString(fail_reason);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 14 /* hwTsSnrTest */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int _hidl_out_ret = hwTsSnrTest();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 15 /* hwTsPressCalSetEndTimeOfAgeing */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    boolean _hidl_out_ret = hwTsPressCalSetEndTimeOfAgeing();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 16 /* hwTsPressCalGetLeftTimeOfStartCalibration */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    long _hidl_out_left_time = hwTsPressCalGetLeftTimeOfStartCalibration();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt64(_hidl_out_left_time);
                    _hidl_reply.send();
                    break;
                }

                case 17 /* hwTsPressCalIsSupportCalibration */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    boolean _hidl_out_ret = hwTsPressCalIsSupportCalibration();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 18 /* hwTsPressCalSetTypeOfCalibration */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    boolean _hidl_out_ret = hwTsPressCalSetTypeOfCalibration(type);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 19 /* hwTsPressCalSet_range_of_spec */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int range = _hidl_request.readInt32();
                    boolean _hidl_out_ret = hwTsPressCalSet_range_of_spec(range);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 20 /* hwTsPressCalGetStateOfHandle */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    boolean _hidl_out_ret = hwTsPressCalGetStateOfHandle();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 21 /* hwTsPressCalSetCountOfCalibration */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int count = _hidl_request.readInt32();
                    boolean _hidl_out_ret = hwTsPressCalSetCountOfCalibration(count);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 22 /* hwTsPressCalGetCountOfCalibration */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    boolean _hidl_out_ret = hwTsPressCalGetCountOfCalibration();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 23 /* hwTsPressCalSetSizeOfVerifyPoint */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int size = _hidl_request.readInt32();
                    boolean _hidl_out_ret = hwTsPressCalSetSizeOfVerifyPoint(size);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 24 /* hwTsPressCalGetSizeOfVerifyPoint */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int _hidl_out_count = hwTsPressCalGetSizeOfVerifyPoint();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_count);
                    _hidl_reply.send();
                    break;
                }

                case 25 /* hwTsPressCalGetResultOfVerifyPoint */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int point = _hidl_request.readInt32();
                    int _hidl_out_result = hwTsPressCalGetResultOfVerifyPoint(point);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_result);
                    _hidl_reply.send();
                    break;
                }

                case 26 /* hwTsPressCalOpenCalibrationModule */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    boolean _hidl_out_ret = hwTsPressCalOpenCalibrationModule();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 27 /* hwTsPressCalCloseCalibrationModule */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    boolean _hidl_out_ret = hwTsPressCalCloseCalibrationModule();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 28 /* hwTsPressCalStartCalibration */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int number = _hidl_request.readInt32();
                    boolean _hidl_out_ret = hwTsPressCalStartCalibration(number);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 29 /* hwTsPressCalStopCalibration */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int number = _hidl_request.readInt32();
                    boolean _hidl_out_ret = hwTsPressCalStopCalibration(number);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 30 /* hwTsPressCalStartVerify */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int number = _hidl_request.readInt32();
                    boolean _hidl_out_ret = hwTsPressCalStartVerify(number);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 31 /* hwTsPressCalStopVerify */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int number = _hidl_request.readInt32();
                    boolean _hidl_out_ret = hwTsPressCalStopVerify(number);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_ret);
                    _hidl_reply.send();
                    break;
                }

                case 32 /* hwTsPressCalGetVersionInformation */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    int _hidl_out_version = hwTsPressCalGetVersionInformation(type);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_version);
                    _hidl_reply.send();
                    break;
                }

                case 33 /* hwTsPressCalZcalPosChecking */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int p = _hidl_request.readInt32();
                    int x = _hidl_request.readInt32();
                    int y = _hidl_request.readInt32();
                    int _hidl_out_code = hwTsPressCalZcalPosChecking(p, x, y);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_code);
                    _hidl_reply.send();
                    break;
                }

                case 34 /* hwTsSetAftAlgoState */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int enable = _hidl_request.readInt32();
                    int _hidl_out_code = hwTsSetAftAlgoState(enable);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_code);
                    _hidl_reply.send();
                    break;
                }

                case 35 /* hwTsSetAftAlgoOrientation */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    int orientation = _hidl_request.readInt32();
                    int _hidl_out_code = hwTsSetAftAlgoOrientation(orientation);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_code);
                    _hidl_reply.send();
                    break;
                }

                case 36 /* hwTsSetAftConfig */:
                {
                    _hidl_request.enforceInterface(vendor.huawei.hardware.tp.V1_0.ITouchscreen.kInterfaceName);

                    String config = _hidl_request.readString();
                    int _hidl_out_code = hwTsSetAftConfig(config);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_code);
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
