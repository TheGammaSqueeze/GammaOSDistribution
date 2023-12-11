package android.hardware.radio.V1_4;

/**
 * Interface declaring unsolicited radio indications.
 */
public interface IRadioIndication extends android.hardware.radio.V1_3.IRadioIndication {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.radio@1.4::IRadioIndication";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IRadioIndication asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IRadioIndication)) {
            return (IRadioIndication)iface;
        }

        IRadioIndication proxy = new IRadioIndication.Proxy(binder);

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
    public static IRadioIndication castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IRadioIndication.asInterface(iface.asBinder());
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
    public static IRadioIndication getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IRadioIndication.asInterface(android.os.HwBinder.getService("android.hardware.radio@1.4::IRadioIndication", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IRadioIndication getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IRadioIndication getService(String serviceName) throws android.os.RemoteException {
        return IRadioIndication.asInterface(android.os.HwBinder.getService("android.hardware.radio@1.4::IRadioIndication", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IRadioIndication getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Report the current list of emergency numbers
     *
     * Each emergency number (@1.4::EmergencyNumber) in the emergency number list contains a
     * dialing number, zero or more service category(s), zero or more emergency uniform resource
     * names, mobile country code, mobile network code, and source(s) that indicate where it comes
     * from.
     *
     * Radio must report all the valid emergency numbers with known mobile country code, mobile
     * network code, emergency service categories, and emergency uniform resource names from all
     * available sources including network signaling, sim, modem/oem configuration, and default
     * configuration (112 and 911 must be always available; additionally, 000, 08, 110, 999, 118
     * and 119 must be available when sim is not present). Radio shall not report emergency numbers
     * that are invalid in the current locale. The reported emergency number list must not have
     * duplicate @1.4::EmergencyNumber entries. Please refer the documentation of
     * @1.4::EmergencyNumber to construct each emergency number to report.
     *
     * Radio must report the complete list of emergency numbers whenever the emergency numbers in
     * the list are changed or whenever the client and the radio server are connected.
     *
     * Reference: 3gpp 22.101, Section 10 - Emergency Calls;
     *            3gpp 24.008, Section 9.2.13.4 - Emergency Number List
     *
     * @param type Type of radio indication
     * @param emergencyNumberList Current list of emergency numbers known to radio.
     */
    void currentEmergencyNumberList(int type, java.util.ArrayList<android.hardware.radio.V1_4.EmergencyNumber> emergencyNumberList)
        throws android.os.RemoteException;
    /**
     * Report all of the current cell information known to the radio.
     *
     * @param type Type of radio indication
     * @param records Current cell information
     */
    void cellInfoList_1_4(int type, java.util.ArrayList<android.hardware.radio.V1_4.CellInfo> records)
        throws android.os.RemoteException;
    /**
     * Incremental network scan results
     */
    void networkScanResult_1_4(int type, android.hardware.radio.V1_4.NetworkScanResult result)
        throws android.os.RemoteException;
    /**
     * Indicates physical channel configurations.
     *
     * An empty configs list indicates that the radio is in idle mode.
     *
     * @param type Type of radio indication
     * @param configs Vector of PhysicalChannelConfigs
     */
    void currentPhysicalChannelConfigs_1_4(int type, java.util.ArrayList<android.hardware.radio.V1_4.PhysicalChannelConfig> configs)
        throws android.os.RemoteException;
    /**
     * Indicates data call contexts have changed.
     *
     * @param type Type of radio indication
     * @param dcList Array of SetupDataCallResult identical to that returned by
     *        IRadio.getDataCallList(). It is the complete list of current data contexts including
     *        new contexts that have been activated. A data call is only removed from this list
     *        when below conditions matched.
     *        1. The framework sends a IRadio.deactivateDataCall().
     *        2. The radio is powered off/on.
     *        3. Unsolicited disconnect from either modem or network side.
     */
    void dataCallListChanged_1_4(int type, java.util.ArrayList<android.hardware.radio.V1_4.SetupDataCallResult> dcList)
        throws android.os.RemoteException;
    /**
     * Indicates current signal strength of the radio.
     *
     * @param type Type of radio indication
     * @param signalStrength SignalStrength information
     */
    void currentSignalStrength_1_4(int type, android.hardware.radio.V1_4.SignalStrength signalStrength)
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

    public static final class Proxy implements IRadioIndication {
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
            return "[class or subclass of " + IRadioIndication.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::radio::V1_0::IRadioIndication follow.
        @Override
        public void radioStateChanged(int type, int radioState)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeInt32(radioState);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* radioStateChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void callStateChanged(int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* callStateChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void networkStateChanged(int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* networkStateChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void newSms(int type, java.util.ArrayList<Byte> pdu)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeInt8Vector(pdu);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* newSms */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void newSmsStatusReport(int type, java.util.ArrayList<Byte> pdu)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeInt8Vector(pdu);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* newSmsStatusReport */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void newSmsOnSim(int type, int recordNumber)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeInt32(recordNumber);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* newSmsOnSim */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onUssd(int type, int modeType, String msg)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeInt32(modeType);
            _hidl_request.writeString(msg);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* onUssd */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void nitzTimeReceived(int type, String nitzTime, long receivedTime)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeString(nitzTime);
            _hidl_request.writeInt64(receivedTime);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* nitzTimeReceived */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void currentSignalStrength(int type, android.hardware.radio.V1_0.SignalStrength signalStrength)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_0.SignalStrength) signalStrength).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* currentSignalStrength */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void dataCallListChanged(int type, java.util.ArrayList<android.hardware.radio.V1_0.SetupDataCallResult> dcList)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            android.hardware.radio.V1_0.SetupDataCallResult.writeVectorToParcel(_hidl_request, dcList);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* dataCallListChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void suppSvcNotify(int type, android.hardware.radio.V1_0.SuppSvcNotification suppSvc)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_0.SuppSvcNotification) suppSvc).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* suppSvcNotify */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void stkSessionEnd(int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* stkSessionEnd */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void stkProactiveCommand(int type, String cmd)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeString(cmd);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* stkProactiveCommand */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void stkEventNotify(int type, String cmd)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeString(cmd);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* stkEventNotify */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void stkCallSetup(int type, long timeout)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeInt64(timeout);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* stkCallSetup */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void simSmsStorageFull(int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* simSmsStorageFull */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void simRefresh(int type, android.hardware.radio.V1_0.SimRefreshResult refreshResult)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_0.SimRefreshResult) refreshResult).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* simRefresh */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void callRing(int type, boolean isGsm, android.hardware.radio.V1_0.CdmaSignalInfoRecord record)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeBool(isGsm);
            ((android.hardware.radio.V1_0.CdmaSignalInfoRecord) record).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(18 /* callRing */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void simStatusChanged(int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(19 /* simStatusChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cdmaNewSms(int type, android.hardware.radio.V1_0.CdmaSmsMessage msg)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_0.CdmaSmsMessage) msg).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(20 /* cdmaNewSms */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void newBroadcastSms(int type, java.util.ArrayList<Byte> data)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeInt8Vector(data);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(21 /* newBroadcastSms */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cdmaRuimSmsStorageFull(int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(22 /* cdmaRuimSmsStorageFull */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void restrictedStateChanged(int type, int state)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeInt32(state);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(23 /* restrictedStateChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void enterEmergencyCallbackMode(int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(24 /* enterEmergencyCallbackMode */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cdmaCallWaiting(int type, android.hardware.radio.V1_0.CdmaCallWaiting callWaitingRecord)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_0.CdmaCallWaiting) callWaitingRecord).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(25 /* cdmaCallWaiting */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cdmaOtaProvisionStatus(int type, int status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeInt32(status);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(26 /* cdmaOtaProvisionStatus */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cdmaInfoRec(int type, android.hardware.radio.V1_0.CdmaInformationRecords records)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_0.CdmaInformationRecords) records).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(27 /* cdmaInfoRec */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void indicateRingbackTone(int type, boolean start)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeBool(start);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(28 /* indicateRingbackTone */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void resendIncallMute(int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(29 /* resendIncallMute */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cdmaSubscriptionSourceChanged(int type, int cdmaSource)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeInt32(cdmaSource);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(30 /* cdmaSubscriptionSourceChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cdmaPrlChanged(int type, int version)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeInt32(version);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(31 /* cdmaPrlChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void exitEmergencyCallbackMode(int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(32 /* exitEmergencyCallbackMode */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void rilConnected(int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(33 /* rilConnected */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void voiceRadioTechChanged(int type, int rat)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeInt32(rat);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(34 /* voiceRadioTechChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cellInfoList(int type, java.util.ArrayList<android.hardware.radio.V1_0.CellInfo> records)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            android.hardware.radio.V1_0.CellInfo.writeVectorToParcel(_hidl_request, records);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(35 /* cellInfoList */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void imsNetworkStateChanged(int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(36 /* imsNetworkStateChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void subscriptionStatusChanged(int type, boolean activate)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeBool(activate);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(37 /* subscriptionStatusChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void srvccStateNotify(int type, int state)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeInt32(state);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(38 /* srvccStateNotify */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void hardwareConfigChanged(int type, java.util.ArrayList<android.hardware.radio.V1_0.HardwareConfig> configs)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            android.hardware.radio.V1_0.HardwareConfig.writeVectorToParcel(_hidl_request, configs);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(39 /* hardwareConfigChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void radioCapabilityIndication(int type, android.hardware.radio.V1_0.RadioCapability rc)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_0.RadioCapability) rc).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(40 /* radioCapabilityIndication */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onSupplementaryServiceIndication(int type, android.hardware.radio.V1_0.StkCcUnsolSsResult ss)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_0.StkCcUnsolSsResult) ss).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(41 /* onSupplementaryServiceIndication */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void stkCallControlAlphaNotify(int type, String alpha)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeString(alpha);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(42 /* stkCallControlAlphaNotify */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void lceData(int type, android.hardware.radio.V1_0.LceDataInfo lce)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_0.LceDataInfo) lce).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(43 /* lceData */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void pcoData(int type, android.hardware.radio.V1_0.PcoDataInfo pco)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_0.PcoDataInfo) pco).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(44 /* pcoData */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void modemReset(int type, String reason)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            _hidl_request.writeString(reason);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(45 /* modemReset */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::radio::V1_1::IRadioIndication follow.
        @Override
        public void carrierInfoForImsiEncryption(int info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_1.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(info);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(46 /* carrierInfoForImsiEncryption */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void networkScanResult(int type, android.hardware.radio.V1_1.NetworkScanResult result)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_1.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_1.NetworkScanResult) result).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(47 /* networkScanResult */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void keepaliveStatus(int type, android.hardware.radio.V1_1.KeepaliveStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_1.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_1.KeepaliveStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(48 /* keepaliveStatus */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::radio::V1_2::IRadioIndication follow.
        @Override
        public void networkScanResult_1_2(int type, android.hardware.radio.V1_2.NetworkScanResult result)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_2.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_2.NetworkScanResult) result).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(49 /* networkScanResult_1_2 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cellInfoList_1_2(int type, java.util.ArrayList<android.hardware.radio.V1_2.CellInfo> records)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_2.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            android.hardware.radio.V1_2.CellInfo.writeVectorToParcel(_hidl_request, records);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(50 /* cellInfoList_1_2 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void currentLinkCapacityEstimate(int type, android.hardware.radio.V1_2.LinkCapacityEstimate lce)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_2.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_2.LinkCapacityEstimate) lce).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(51 /* currentLinkCapacityEstimate */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void currentPhysicalChannelConfigs(int type, java.util.ArrayList<android.hardware.radio.V1_2.PhysicalChannelConfig> configs)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_2.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            android.hardware.radio.V1_2.PhysicalChannelConfig.writeVectorToParcel(_hidl_request, configs);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(52 /* currentPhysicalChannelConfigs */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void currentSignalStrength_1_2(int type, android.hardware.radio.V1_2.SignalStrength signalStrength)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_2.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_2.SignalStrength) signalStrength).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(53 /* currentSignalStrength_1_2 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::radio::V1_4::IRadioIndication follow.
        @Override
        public void currentEmergencyNumberList(int type, java.util.ArrayList<android.hardware.radio.V1_4.EmergencyNumber> emergencyNumberList)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            android.hardware.radio.V1_4.EmergencyNumber.writeVectorToParcel(_hidl_request, emergencyNumberList);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(54 /* currentEmergencyNumberList */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cellInfoList_1_4(int type, java.util.ArrayList<android.hardware.radio.V1_4.CellInfo> records)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            android.hardware.radio.V1_4.CellInfo.writeVectorToParcel(_hidl_request, records);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(55 /* cellInfoList_1_4 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void networkScanResult_1_4(int type, android.hardware.radio.V1_4.NetworkScanResult result)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_4.NetworkScanResult) result).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(56 /* networkScanResult_1_4 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void currentPhysicalChannelConfigs_1_4(int type, java.util.ArrayList<android.hardware.radio.V1_4.PhysicalChannelConfig> configs)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            android.hardware.radio.V1_4.PhysicalChannelConfig.writeVectorToParcel(_hidl_request, configs);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(57 /* currentPhysicalChannelConfigs_1_4 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void dataCallListChanged_1_4(int type, java.util.ArrayList<android.hardware.radio.V1_4.SetupDataCallResult> dcList)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            android.hardware.radio.V1_4.SetupDataCallResult.writeVectorToParcel(_hidl_request, dcList);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(58 /* dataCallListChanged_1_4 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void currentSignalStrength_1_4(int type, android.hardware.radio.V1_4.SignalStrength signalStrength)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioIndication.kInterfaceName);
            _hidl_request.writeInt32(type);
            ((android.hardware.radio.V1_4.SignalStrength) signalStrength).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(59 /* currentSignalStrength_1_4 */, _hidl_request, _hidl_reply, 1 /* oneway */);
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

    public static abstract class Stub extends android.os.HwBinder implements IRadioIndication {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.radio.V1_4.IRadioIndication.kInterfaceName,
                    android.hardware.radio.V1_3.IRadioIndication.kInterfaceName,
                    android.hardware.radio.V1_2.IRadioIndication.kInterfaceName,
                    android.hardware.radio.V1_1.IRadioIndication.kInterfaceName,
                    android.hardware.radio.V1_0.IRadioIndication.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.radio.V1_4.IRadioIndication.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{51,-39,-26,-119,92,-54,-104,-86,86,41,107,-80,23,32,-47,-117,-118,-51,14,77,-28,-106,11,-21,113,46,99,-83,20,116,56,-91} /* 33d9e6895cca98aa56296bb01720d18b8acd0e4de4960beb712e63ad147438a5 */,
                    new byte[/* 32 */]{-23,-48,-15,26,82,113,95,90,41,-40,-98,45,-114,46,33,-37,30,22,-92,49,116,-81,107,-99,81,-90,45,112,92,-38,20,85} /* e9d0f11a52715f5a29d89e2d8e2e21db1e16a43174af6b9d51a62d705cda1455 */,
                    new byte[/* 32 */]{-51,-89,82,-82,-85,-86,-68,32,72,106,-126,-84,87,-93,-35,16,119,-123,-64,6,9,74,52,-101,-59,-30,36,-24,-86,34,-95,124} /* cda752aeabaabc20486a82ac57a3dd107785c006094a349bc5e224e8aa22a17c */,
                    new byte[/* 32 */]{-4,-59,-56,-56,-117,-123,-87,-10,63,-70,103,-39,-26,116,-38,70,108,114,-87,-116,-94,-121,-13,67,-5,87,33,-48,-104,113,63,-122} /* fcc5c8c88b85a9f63fba67d9e674da466c72a98ca287f343fb5721d098713f86 */,
                    new byte[/* 32 */]{-119,-41,-113,-92,-101,9,-30,-13,24,18,-69,99,-31,-65,-84,43,-13,24,-87,86,20,115,-58,-80,-19,105,4,-50,24,55,125,84} /* 89d78fa49b09e2f31812bb63e1bfac2bf318a9561473c6b0ed6904ce18377d54 */,
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
                case 1 /* radioStateChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    int radioState = _hidl_request.readInt32();
                    radioStateChanged(type, radioState);
                    break;
                }

                case 2 /* callStateChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    callStateChanged(type);
                    break;
                }

                case 3 /* networkStateChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    networkStateChanged(type);
                    break;
                }

                case 4 /* newSms */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    java.util.ArrayList<Byte> pdu = _hidl_request.readInt8Vector();
                    newSms(type, pdu);
                    break;
                }

                case 5 /* newSmsStatusReport */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    java.util.ArrayList<Byte> pdu = _hidl_request.readInt8Vector();
                    newSmsStatusReport(type, pdu);
                    break;
                }

                case 6 /* newSmsOnSim */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    int recordNumber = _hidl_request.readInt32();
                    newSmsOnSim(type, recordNumber);
                    break;
                }

                case 7 /* onUssd */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    int modeType = _hidl_request.readInt32();
                    String msg = _hidl_request.readString();
                    onUssd(type, modeType, msg);
                    break;
                }

                case 8 /* nitzTimeReceived */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    String nitzTime = _hidl_request.readString();
                    long receivedTime = _hidl_request.readInt64();
                    nitzTimeReceived(type, nitzTime, receivedTime);
                    break;
                }

                case 9 /* currentSignalStrength */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.SignalStrength signalStrength = new android.hardware.radio.V1_0.SignalStrength();
                    ((android.hardware.radio.V1_0.SignalStrength) signalStrength).readFromParcel(_hidl_request);
                    currentSignalStrength(type, signalStrength);
                    break;
                }

                case 10 /* dataCallListChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    java.util.ArrayList<android.hardware.radio.V1_0.SetupDataCallResult> dcList = android.hardware.radio.V1_0.SetupDataCallResult.readVectorFromParcel(_hidl_request);
                    dataCallListChanged(type, dcList);
                    break;
                }

                case 11 /* suppSvcNotify */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.SuppSvcNotification suppSvc = new android.hardware.radio.V1_0.SuppSvcNotification();
                    ((android.hardware.radio.V1_0.SuppSvcNotification) suppSvc).readFromParcel(_hidl_request);
                    suppSvcNotify(type, suppSvc);
                    break;
                }

                case 12 /* stkSessionEnd */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    stkSessionEnd(type);
                    break;
                }

                case 13 /* stkProactiveCommand */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    String cmd = _hidl_request.readString();
                    stkProactiveCommand(type, cmd);
                    break;
                }

                case 14 /* stkEventNotify */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    String cmd = _hidl_request.readString();
                    stkEventNotify(type, cmd);
                    break;
                }

                case 15 /* stkCallSetup */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    long timeout = _hidl_request.readInt64();
                    stkCallSetup(type, timeout);
                    break;
                }

                case 16 /* simSmsStorageFull */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    simSmsStorageFull(type);
                    break;
                }

                case 17 /* simRefresh */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.SimRefreshResult refreshResult = new android.hardware.radio.V1_0.SimRefreshResult();
                    ((android.hardware.radio.V1_0.SimRefreshResult) refreshResult).readFromParcel(_hidl_request);
                    simRefresh(type, refreshResult);
                    break;
                }

                case 18 /* callRing */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    boolean isGsm = _hidl_request.readBool();
                    android.hardware.radio.V1_0.CdmaSignalInfoRecord record = new android.hardware.radio.V1_0.CdmaSignalInfoRecord();
                    ((android.hardware.radio.V1_0.CdmaSignalInfoRecord) record).readFromParcel(_hidl_request);
                    callRing(type, isGsm, record);
                    break;
                }

                case 19 /* simStatusChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    simStatusChanged(type);
                    break;
                }

                case 20 /* cdmaNewSms */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.CdmaSmsMessage msg = new android.hardware.radio.V1_0.CdmaSmsMessage();
                    ((android.hardware.radio.V1_0.CdmaSmsMessage) msg).readFromParcel(_hidl_request);
                    cdmaNewSms(type, msg);
                    break;
                }

                case 21 /* newBroadcastSms */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    java.util.ArrayList<Byte> data = _hidl_request.readInt8Vector();
                    newBroadcastSms(type, data);
                    break;
                }

                case 22 /* cdmaRuimSmsStorageFull */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    cdmaRuimSmsStorageFull(type);
                    break;
                }

                case 23 /* restrictedStateChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    int state = _hidl_request.readInt32();
                    restrictedStateChanged(type, state);
                    break;
                }

                case 24 /* enterEmergencyCallbackMode */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    enterEmergencyCallbackMode(type);
                    break;
                }

                case 25 /* cdmaCallWaiting */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.CdmaCallWaiting callWaitingRecord = new android.hardware.radio.V1_0.CdmaCallWaiting();
                    ((android.hardware.radio.V1_0.CdmaCallWaiting) callWaitingRecord).readFromParcel(_hidl_request);
                    cdmaCallWaiting(type, callWaitingRecord);
                    break;
                }

                case 26 /* cdmaOtaProvisionStatus */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    int status = _hidl_request.readInt32();
                    cdmaOtaProvisionStatus(type, status);
                    break;
                }

                case 27 /* cdmaInfoRec */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.CdmaInformationRecords records = new android.hardware.radio.V1_0.CdmaInformationRecords();
                    ((android.hardware.radio.V1_0.CdmaInformationRecords) records).readFromParcel(_hidl_request);
                    cdmaInfoRec(type, records);
                    break;
                }

                case 28 /* indicateRingbackTone */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    boolean start = _hidl_request.readBool();
                    indicateRingbackTone(type, start);
                    break;
                }

                case 29 /* resendIncallMute */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    resendIncallMute(type);
                    break;
                }

                case 30 /* cdmaSubscriptionSourceChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    int cdmaSource = _hidl_request.readInt32();
                    cdmaSubscriptionSourceChanged(type, cdmaSource);
                    break;
                }

                case 31 /* cdmaPrlChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    int version = _hidl_request.readInt32();
                    cdmaPrlChanged(type, version);
                    break;
                }

                case 32 /* exitEmergencyCallbackMode */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    exitEmergencyCallbackMode(type);
                    break;
                }

                case 33 /* rilConnected */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    rilConnected(type);
                    break;
                }

                case 34 /* voiceRadioTechChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    int rat = _hidl_request.readInt32();
                    voiceRadioTechChanged(type, rat);
                    break;
                }

                case 35 /* cellInfoList */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    java.util.ArrayList<android.hardware.radio.V1_0.CellInfo> records = android.hardware.radio.V1_0.CellInfo.readVectorFromParcel(_hidl_request);
                    cellInfoList(type, records);
                    break;
                }

                case 36 /* imsNetworkStateChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    imsNetworkStateChanged(type);
                    break;
                }

                case 37 /* subscriptionStatusChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    boolean activate = _hidl_request.readBool();
                    subscriptionStatusChanged(type, activate);
                    break;
                }

                case 38 /* srvccStateNotify */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    int state = _hidl_request.readInt32();
                    srvccStateNotify(type, state);
                    break;
                }

                case 39 /* hardwareConfigChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    java.util.ArrayList<android.hardware.radio.V1_0.HardwareConfig> configs = android.hardware.radio.V1_0.HardwareConfig.readVectorFromParcel(_hidl_request);
                    hardwareConfigChanged(type, configs);
                    break;
                }

                case 40 /* radioCapabilityIndication */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.RadioCapability rc = new android.hardware.radio.V1_0.RadioCapability();
                    ((android.hardware.radio.V1_0.RadioCapability) rc).readFromParcel(_hidl_request);
                    radioCapabilityIndication(type, rc);
                    break;
                }

                case 41 /* onSupplementaryServiceIndication */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.StkCcUnsolSsResult ss = new android.hardware.radio.V1_0.StkCcUnsolSsResult();
                    ((android.hardware.radio.V1_0.StkCcUnsolSsResult) ss).readFromParcel(_hidl_request);
                    onSupplementaryServiceIndication(type, ss);
                    break;
                }

                case 42 /* stkCallControlAlphaNotify */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    String alpha = _hidl_request.readString();
                    stkCallControlAlphaNotify(type, alpha);
                    break;
                }

                case 43 /* lceData */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.LceDataInfo lce = new android.hardware.radio.V1_0.LceDataInfo();
                    ((android.hardware.radio.V1_0.LceDataInfo) lce).readFromParcel(_hidl_request);
                    lceData(type, lce);
                    break;
                }

                case 44 /* pcoData */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.PcoDataInfo pco = new android.hardware.radio.V1_0.PcoDataInfo();
                    ((android.hardware.radio.V1_0.PcoDataInfo) pco).readFromParcel(_hidl_request);
                    pcoData(type, pco);
                    break;
                }

                case 45 /* modemReset */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    String reason = _hidl_request.readString();
                    modemReset(type, reason);
                    break;
                }

                case 46 /* carrierInfoForImsiEncryption */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_1.IRadioIndication.kInterfaceName);

                    int info = _hidl_request.readInt32();
                    carrierInfoForImsiEncryption(info);
                    break;
                }

                case 47 /* networkScanResult */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_1.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_1.NetworkScanResult result = new android.hardware.radio.V1_1.NetworkScanResult();
                    ((android.hardware.radio.V1_1.NetworkScanResult) result).readFromParcel(_hidl_request);
                    networkScanResult(type, result);
                    break;
                }

                case 48 /* keepaliveStatus */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_1.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_1.KeepaliveStatus status = new android.hardware.radio.V1_1.KeepaliveStatus();
                    ((android.hardware.radio.V1_1.KeepaliveStatus) status).readFromParcel(_hidl_request);
                    keepaliveStatus(type, status);
                    break;
                }

                case 49 /* networkScanResult_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_2.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_2.NetworkScanResult result = new android.hardware.radio.V1_2.NetworkScanResult();
                    ((android.hardware.radio.V1_2.NetworkScanResult) result).readFromParcel(_hidl_request);
                    networkScanResult_1_2(type, result);
                    break;
                }

                case 50 /* cellInfoList_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_2.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    java.util.ArrayList<android.hardware.radio.V1_2.CellInfo> records = android.hardware.radio.V1_2.CellInfo.readVectorFromParcel(_hidl_request);
                    cellInfoList_1_2(type, records);
                    break;
                }

                case 51 /* currentLinkCapacityEstimate */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_2.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_2.LinkCapacityEstimate lce = new android.hardware.radio.V1_2.LinkCapacityEstimate();
                    ((android.hardware.radio.V1_2.LinkCapacityEstimate) lce).readFromParcel(_hidl_request);
                    currentLinkCapacityEstimate(type, lce);
                    break;
                }

                case 52 /* currentPhysicalChannelConfigs */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_2.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    java.util.ArrayList<android.hardware.radio.V1_2.PhysicalChannelConfig> configs = android.hardware.radio.V1_2.PhysicalChannelConfig.readVectorFromParcel(_hidl_request);
                    currentPhysicalChannelConfigs(type, configs);
                    break;
                }

                case 53 /* currentSignalStrength_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_2.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_2.SignalStrength signalStrength = new android.hardware.radio.V1_2.SignalStrength();
                    ((android.hardware.radio.V1_2.SignalStrength) signalStrength).readFromParcel(_hidl_request);
                    currentSignalStrength_1_2(type, signalStrength);
                    break;
                }

                case 54 /* currentEmergencyNumberList */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    java.util.ArrayList<android.hardware.radio.V1_4.EmergencyNumber> emergencyNumberList = android.hardware.radio.V1_4.EmergencyNumber.readVectorFromParcel(_hidl_request);
                    currentEmergencyNumberList(type, emergencyNumberList);
                    break;
                }

                case 55 /* cellInfoList_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    java.util.ArrayList<android.hardware.radio.V1_4.CellInfo> records = android.hardware.radio.V1_4.CellInfo.readVectorFromParcel(_hidl_request);
                    cellInfoList_1_4(type, records);
                    break;
                }

                case 56 /* networkScanResult_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_4.NetworkScanResult result = new android.hardware.radio.V1_4.NetworkScanResult();
                    ((android.hardware.radio.V1_4.NetworkScanResult) result).readFromParcel(_hidl_request);
                    networkScanResult_1_4(type, result);
                    break;
                }

                case 57 /* currentPhysicalChannelConfigs_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    java.util.ArrayList<android.hardware.radio.V1_4.PhysicalChannelConfig> configs = android.hardware.radio.V1_4.PhysicalChannelConfig.readVectorFromParcel(_hidl_request);
                    currentPhysicalChannelConfigs_1_4(type, configs);
                    break;
                }

                case 58 /* dataCallListChanged_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    java.util.ArrayList<android.hardware.radio.V1_4.SetupDataCallResult> dcList = android.hardware.radio.V1_4.SetupDataCallResult.readVectorFromParcel(_hidl_request);
                    dataCallListChanged_1_4(type, dcList);
                    break;
                }

                case 59 /* currentSignalStrength_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioIndication.kInterfaceName);

                    int type = _hidl_request.readInt32();
                    android.hardware.radio.V1_4.SignalStrength signalStrength = new android.hardware.radio.V1_4.SignalStrength();
                    ((android.hardware.radio.V1_4.SignalStrength) signalStrength).readFromParcel(_hidl_request);
                    currentSignalStrength_1_4(type, signalStrength);
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
