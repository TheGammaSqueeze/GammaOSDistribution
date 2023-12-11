package android.hardware.thermal.V2_0;

public interface IThermal extends android.hardware.thermal.V1_0.IThermal {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.thermal@2.0::IThermal";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IThermal asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IThermal)) {
            return (IThermal)iface;
        }

        IThermal proxy = new IThermal.Proxy(binder);

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
    public static IThermal castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IThermal.asInterface(iface.asBinder());
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
    public static IThermal getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IThermal.asInterface(android.os.HwBinder.getService("android.hardware.thermal@2.0::IThermal", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IThermal getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IThermal getService(String serviceName) throws android.os.RemoteException {
        return IThermal.asInterface(android.os.HwBinder.getService("android.hardware.thermal@2.0::IThermal", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IThermal getService() throws android.os.RemoteException {
        return getService("default");
    }


    @java.lang.FunctionalInterface
    public interface getCurrentTemperaturesCallback {
        public void onValues(android.hardware.thermal.V1_0.ThermalStatus status, java.util.ArrayList<android.hardware.thermal.V2_0.Temperature> temperatures);
    }

    /**
     * Retrieves temperatures in Celsius.
     *
     * @param filterType whether to filter the result for a given type.
     * @param type the TemperatureType such as battery or skin.
     *
     * @return status Status of the operation. If status code is FAILURE,
     *    the status.debugMessage must be populated with a human-readable
     *    error message.
     *
     * @return temperatures If status code is SUCCESS, it's filled with the
     *    current temperatures. The order of temperatures of built-in
     *    devices (such as CPUs, GPUs and etc.) in the list must be kept
     *    the same regardless of the number of calls to this method even if
     *    they go offline, if these devices exist on boot. The method
     *    always returns and never removes such temperatures.
     */
    void getCurrentTemperatures(boolean filterType, int type, getCurrentTemperaturesCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getTemperatureThresholdsCallback {
        public void onValues(android.hardware.thermal.V1_0.ThermalStatus status, java.util.ArrayList<android.hardware.thermal.V2_0.TemperatureThreshold> temperatureThresholds);
    }

    /**
     * Retrieves static temperature thresholds in Celsius.
     *
     * @param filterType whether to filter the result for a given type.
     * @param type the TemperatureType such as battery or skin.
     *
     * @return status Status of the operation. If status code is FAILURE,
     *    the status.debugMessage must be populated with a human-readable error message.
     * @return temperatureThresholds If status code is SUCCESS, it's filled with the
     *    temperatures thresholds. The order of temperatures of built-in
     *    devices (such as CPUs, GPUs and etc.) in the list must be kept
     *    the same regardless of the number of calls to this method even if
     *    they go offline, if these devices exist on boot. The method
     *    always returns and never removes such temperatures. The thresholds
     *    are returned as static values and must not change across calls. The actual
     *    throttling state is determined in device thermal mitigation policy/agorithm
     *    which might not be simple thresholds so these values Thermal HAL provided
     *    may not be accurate to detemin the throttling status. To get accurate
     *    throttling status, use getCurrentTemperatures or registerThermalChangedCallback
     *    and listen to the callback.
     */
    void getTemperatureThresholds(boolean filterType, int type, getTemperatureThresholdsCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Register an IThermalChangedCallback, used by the Thermal HAL
     * to receive thermal events when thermal mitigation status changed.
     * Multiple registrations with different IThermalChangedCallback must be allowed.
     * Multiple registrations with same IThermalChangedCallback is not allowed, client
     * should unregister the given IThermalChangedCallback first.
     *
     * @param callback the IThermalChangedCallback to use for receiving
     *    thermal events (nullptr callback will lead to failure with status code FAILURE).
     * @param filterType if filter for given sensor type.
     * @param type the type to be filtered.
     *
     * @return status Status of the operation. If status code is FAILURE,
     *    the status.debugMessage must be populated with a human-readable error message.
     */
    android.hardware.thermal.V1_0.ThermalStatus registerThermalChangedCallback(android.hardware.thermal.V2_0.IThermalChangedCallback callback, boolean filterType, int type)
        throws android.os.RemoteException;
    /**
     * Unregister an IThermalChangedCallback, used by the Thermal HAL
     * to receive thermal events when thermal mitigation status changed.
     *
     * @param callback the IThermalChangedCallback used for receiving
     *    thermal events (nullptr callback will lead to failure with status code FAILURE).
     *
     * @return status Status of the operation. If status code is FAILURE,
     *    the status.debugMessage must be populated with a human-readable error message.
     */
    android.hardware.thermal.V1_0.ThermalStatus unregisterThermalChangedCallback(android.hardware.thermal.V2_0.IThermalChangedCallback callback)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getCurrentCoolingDevicesCallback {
        public void onValues(android.hardware.thermal.V1_0.ThermalStatus status, java.util.ArrayList<android.hardware.thermal.V2_0.CoolingDevice> devices);
    }

    /**
     * Retrieves the cooling devices information.
     *
     * @param filterType whether to filter the result for a given type.
     * @param type the CoolingDevice such as CPU/GPU.
     *
     * @return status Status of the operation. If status code is FAILURE,
     *    the status.debugMessage must be populated with the human-readable
     *    error message.
     * @return devices If status code is SUCCESS, it's filled with the current
     *    cooling device information. The order of built-in cooling
     *    devices in the list must be kept the same regardless of the number
     *    of calls to this method even if they go offline, if these devices
     *    exist on boot. The method always returns and never removes from
     *    the list such cooling devices.
     */
    void getCurrentCoolingDevices(boolean filterType, int type, getCurrentCoolingDevicesCallback _hidl_cb)
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

    public static final class Proxy implements IThermal {
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
            return "[class or subclass of " + IThermal.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::thermal::V1_0::IThermal follow.
        @Override
        public void getTemperatures(getTemperaturesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.thermal.V1_0.IThermal.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* getTemperatures */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.thermal.V1_0.ThermalStatus _hidl_out_status = new android.hardware.thermal.V1_0.ThermalStatus();
                ((android.hardware.thermal.V1_0.ThermalStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<android.hardware.thermal.V1_0.Temperature> _hidl_out_temperatures = android.hardware.thermal.V1_0.Temperature.readVectorFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_temperatures);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCpuUsages(getCpuUsagesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.thermal.V1_0.IThermal.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* getCpuUsages */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.thermal.V1_0.ThermalStatus _hidl_out_status = new android.hardware.thermal.V1_0.ThermalStatus();
                ((android.hardware.thermal.V1_0.ThermalStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<android.hardware.thermal.V1_0.CpuUsage> _hidl_out_cpuUsages = android.hardware.thermal.V1_0.CpuUsage.readVectorFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_cpuUsages);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCoolingDevices(getCoolingDevicesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.thermal.V1_0.IThermal.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* getCoolingDevices */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.thermal.V1_0.ThermalStatus _hidl_out_status = new android.hardware.thermal.V1_0.ThermalStatus();
                ((android.hardware.thermal.V1_0.ThermalStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<android.hardware.thermal.V1_0.CoolingDevice> _hidl_out_devices = android.hardware.thermal.V1_0.CoolingDevice.readVectorFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_devices);
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::thermal::V2_0::IThermal follow.
        @Override
        public void getCurrentTemperatures(boolean filterType, int type, getCurrentTemperaturesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.thermal.V2_0.IThermal.kInterfaceName);
            _hidl_request.writeBool(filterType);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* getCurrentTemperatures */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.thermal.V1_0.ThermalStatus _hidl_out_status = new android.hardware.thermal.V1_0.ThermalStatus();
                ((android.hardware.thermal.V1_0.ThermalStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<android.hardware.thermal.V2_0.Temperature> _hidl_out_temperatures = android.hardware.thermal.V2_0.Temperature.readVectorFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_temperatures);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getTemperatureThresholds(boolean filterType, int type, getTemperatureThresholdsCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.thermal.V2_0.IThermal.kInterfaceName);
            _hidl_request.writeBool(filterType);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* getTemperatureThresholds */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.thermal.V1_0.ThermalStatus _hidl_out_status = new android.hardware.thermal.V1_0.ThermalStatus();
                ((android.hardware.thermal.V1_0.ThermalStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<android.hardware.thermal.V2_0.TemperatureThreshold> _hidl_out_temperatureThresholds = android.hardware.thermal.V2_0.TemperatureThreshold.readVectorFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_temperatureThresholds);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.thermal.V1_0.ThermalStatus registerThermalChangedCallback(android.hardware.thermal.V2_0.IThermalChangedCallback callback, boolean filterType, int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.thermal.V2_0.IThermal.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());
            _hidl_request.writeBool(filterType);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* registerThermalChangedCallback */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.thermal.V1_0.ThermalStatus _hidl_out_status = new android.hardware.thermal.V1_0.ThermalStatus();
                ((android.hardware.thermal.V1_0.ThermalStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.thermal.V1_0.ThermalStatus unregisterThermalChangedCallback(android.hardware.thermal.V2_0.IThermalChangedCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.thermal.V2_0.IThermal.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* unregisterThermalChangedCallback */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.thermal.V1_0.ThermalStatus _hidl_out_status = new android.hardware.thermal.V1_0.ThermalStatus();
                ((android.hardware.thermal.V1_0.ThermalStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCurrentCoolingDevices(boolean filterType, int type, getCurrentCoolingDevicesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.thermal.V2_0.IThermal.kInterfaceName);
            _hidl_request.writeBool(filterType);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* getCurrentCoolingDevices */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.thermal.V1_0.ThermalStatus _hidl_out_status = new android.hardware.thermal.V1_0.ThermalStatus();
                ((android.hardware.thermal.V1_0.ThermalStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<android.hardware.thermal.V2_0.CoolingDevice> _hidl_out_devices = android.hardware.thermal.V2_0.CoolingDevice.readVectorFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_devices);
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

    public static abstract class Stub extends android.os.HwBinder implements IThermal {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.thermal.V2_0.IThermal.kInterfaceName,
                    android.hardware.thermal.V1_0.IThermal.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.thermal.V2_0.IThermal.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-67,-120,-76,-122,57,-54,-29,9,-126,2,16,36,-30,35,113,7,108,118,-6,-88,70,110,56,-54,89,-123,41,69,43,97,-114,-82} /* bd88b48639cae30982021024e22371076c76faa8466e38ca598529452b618eae */,
                    new byte[/* 32 */]{-105,-15,-20,68,96,67,-68,90,102,69,-73,69,41,-90,39,100,-106,-67,-77,94,10,-18,65,-19,-91,92,-71,45,81,-21,120,2} /* 97f1ec446043bc5a6645b74529a6276496bdb35e0aee41eda55cb92d51eb7802 */,
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
                case 1 /* getTemperatures */:
                {
                    _hidl_request.enforceInterface(android.hardware.thermal.V1_0.IThermal.kInterfaceName);

                    getTemperatures(new getTemperaturesCallback() {
                        @Override
                        public void onValues(android.hardware.thermal.V1_0.ThermalStatus status, java.util.ArrayList<android.hardware.thermal.V1_0.Temperature> temperatures) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.thermal.V1_0.ThermalStatus) status).writeToParcel(_hidl_reply);
                            android.hardware.thermal.V1_0.Temperature.writeVectorToParcel(_hidl_reply, temperatures);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 2 /* getCpuUsages */:
                {
                    _hidl_request.enforceInterface(android.hardware.thermal.V1_0.IThermal.kInterfaceName);

                    getCpuUsages(new getCpuUsagesCallback() {
                        @Override
                        public void onValues(android.hardware.thermal.V1_0.ThermalStatus status, java.util.ArrayList<android.hardware.thermal.V1_0.CpuUsage> cpuUsages) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.thermal.V1_0.ThermalStatus) status).writeToParcel(_hidl_reply);
                            android.hardware.thermal.V1_0.CpuUsage.writeVectorToParcel(_hidl_reply, cpuUsages);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 3 /* getCoolingDevices */:
                {
                    _hidl_request.enforceInterface(android.hardware.thermal.V1_0.IThermal.kInterfaceName);

                    getCoolingDevices(new getCoolingDevicesCallback() {
                        @Override
                        public void onValues(android.hardware.thermal.V1_0.ThermalStatus status, java.util.ArrayList<android.hardware.thermal.V1_0.CoolingDevice> devices) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.thermal.V1_0.ThermalStatus) status).writeToParcel(_hidl_reply);
                            android.hardware.thermal.V1_0.CoolingDevice.writeVectorToParcel(_hidl_reply, devices);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 4 /* getCurrentTemperatures */:
                {
                    _hidl_request.enforceInterface(android.hardware.thermal.V2_0.IThermal.kInterfaceName);

                    boolean filterType = _hidl_request.readBool();
                    int type = _hidl_request.readInt32();
                    getCurrentTemperatures(filterType, type, new getCurrentTemperaturesCallback() {
                        @Override
                        public void onValues(android.hardware.thermal.V1_0.ThermalStatus status, java.util.ArrayList<android.hardware.thermal.V2_0.Temperature> temperatures) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.thermal.V1_0.ThermalStatus) status).writeToParcel(_hidl_reply);
                            android.hardware.thermal.V2_0.Temperature.writeVectorToParcel(_hidl_reply, temperatures);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 5 /* getTemperatureThresholds */:
                {
                    _hidl_request.enforceInterface(android.hardware.thermal.V2_0.IThermal.kInterfaceName);

                    boolean filterType = _hidl_request.readBool();
                    int type = _hidl_request.readInt32();
                    getTemperatureThresholds(filterType, type, new getTemperatureThresholdsCallback() {
                        @Override
                        public void onValues(android.hardware.thermal.V1_0.ThermalStatus status, java.util.ArrayList<android.hardware.thermal.V2_0.TemperatureThreshold> temperatureThresholds) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.thermal.V1_0.ThermalStatus) status).writeToParcel(_hidl_reply);
                            android.hardware.thermal.V2_0.TemperatureThreshold.writeVectorToParcel(_hidl_reply, temperatureThresholds);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 6 /* registerThermalChangedCallback */:
                {
                    _hidl_request.enforceInterface(android.hardware.thermal.V2_0.IThermal.kInterfaceName);

                    android.hardware.thermal.V2_0.IThermalChangedCallback callback = android.hardware.thermal.V2_0.IThermalChangedCallback.asInterface(_hidl_request.readStrongBinder());
                    boolean filterType = _hidl_request.readBool();
                    int type = _hidl_request.readInt32();
                    android.hardware.thermal.V1_0.ThermalStatus _hidl_out_status = registerThermalChangedCallback(callback, filterType, type);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.thermal.V1_0.ThermalStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 7 /* unregisterThermalChangedCallback */:
                {
                    _hidl_request.enforceInterface(android.hardware.thermal.V2_0.IThermal.kInterfaceName);

                    android.hardware.thermal.V2_0.IThermalChangedCallback callback = android.hardware.thermal.V2_0.IThermalChangedCallback.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.thermal.V1_0.ThermalStatus _hidl_out_status = unregisterThermalChangedCallback(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.thermal.V1_0.ThermalStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 8 /* getCurrentCoolingDevices */:
                {
                    _hidl_request.enforceInterface(android.hardware.thermal.V2_0.IThermal.kInterfaceName);

                    boolean filterType = _hidl_request.readBool();
                    int type = _hidl_request.readInt32();
                    getCurrentCoolingDevices(filterType, type, new getCurrentCoolingDevicesCallback() {
                        @Override
                        public void onValues(android.hardware.thermal.V1_0.ThermalStatus status, java.util.ArrayList<android.hardware.thermal.V2_0.CoolingDevice> devices) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.thermal.V1_0.ThermalStatus) status).writeToParcel(_hidl_reply);
                            android.hardware.thermal.V2_0.CoolingDevice.writeVectorToParcel(_hidl_reply, devices);
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
