package android.hardware.radio.V1_0;

/**
 * Interface declaring unsolicited radio indications.
 */
public interface IRadioIndication extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.radio@1.0::IRadioIndication";

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
        return IRadioIndication.asInterface(android.os.HwBinder.getService("android.hardware.radio@1.0::IRadioIndication", serviceName, retry));
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
        return IRadioIndication.asInterface(android.os.HwBinder.getService("android.hardware.radio@1.0::IRadioIndication", serviceName));
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
     * Indicates when radio state changes.
     *
     * @param type Type of radio indication
     * @param radioState Current radio state
     */
    void radioStateChanged(int type, int radioState)
        throws android.os.RemoteException;
    /**
     * Indicates when call state has changed.
     * Callee must invoke IRadio.getCurrentCalls()
     * Must be invoked on, for example,
     * "RING", "BUSY", "NO CARRIER", and also call state
     * transitions (DIALING->ALERTING ALERTING->ACTIVE)
     *
     * Redundent or extraneous invocations are tolerated
     *
     * @param type Type of radio indication
     */
    void callStateChanged(int type)
        throws android.os.RemoteException;
    /**
     * Indicates when voice or data network state changed
     * Callee must invoke IRadio.getVoiceRegistrationState(), IRadio.getDataRegistrationState(),
     * and IRadio.getOperator()
     *
     * @param type Type of radio indication
     */
    void networkStateChanged(int type)
        throws android.os.RemoteException;
    /**
     * Indicates when new SMS is received.
     * Callee must subsequently confirm the receipt of the SMS with a
     * acknowledgeLastIncomingGsmSms()
     *
     * Server must not send newSms() nor newSmsStatusReport() messages until a
     * acknowledgeLastIncomingGsmSms() has been received
     *
     * @param type Type of radio indication
     * @param pdu PDU of SMS-DELIVER represented as byte array.
     *        The PDU starts with the SMSC address per TS 27.005 (+CMT:)
     */
    void newSms(int type, java.util.ArrayList<Byte> pdu)
        throws android.os.RemoteException;
    /**
     * Indicates when new SMS Status Report is received.
     * Callee must subsequently confirm the receipt of the SMS with a
     * acknowledgeLastIncomingGsmSms()
     *
     * Server must not send newSms() nor newSmsStatusReport() messages until a
     * acknowledgeLastIncomingGsmSms() has been received
     *
     * @param type Type of radio indication
     * @param pdu PDU of SMS-STATUS-REPORT represented as byte array.
     *        The PDU starts with the SMSC address per TS 27.005 (+CMT:)
     */
    void newSmsStatusReport(int type, java.util.ArrayList<Byte> pdu)
        throws android.os.RemoteException;
    /**
     * Indicates when new SMS has been stored on SIM card
     *
     * @param type Type of radio indication
     * @param recordNumber Record number on the sim
     */
    void newSmsOnSim(int type, int recordNumber)
        throws android.os.RemoteException;
    /**
     * Indicates when a new USSD message is received.
     * The USSD session is assumed to persist if the type code is REQUEST, otherwise
     * the current session (if any) is assumed to have terminated.
     *
     * @param type Type of radio indication
     * @param modeType USSD type code
     * @param msg Message string in UTF-8, if applicable
     */
    void onUssd(int type, int modeType, String msg)
        throws android.os.RemoteException;
    /**
     * Indicates when radio has received a NITZ time message.
     *
     * @param type Type of radio indication
     * @param nitzTime NITZ time string in the form "yy/mm/dd,hh:mm:ss(+/-)tz,dt"
     * @param receivedTime milliseconds since boot that the NITZ time was received
     */
    void nitzTimeReceived(int type, String nitzTime, long receivedTime)
        throws android.os.RemoteException;
    /**
     * Indicates current signal strength of the radio.
     *
     * @param type Type of radio indication
     * @param signalStrength SignalStrength information as defined in types.hal
     */
    void currentSignalStrength(int type, android.hardware.radio.V1_0.SignalStrength signalStrength)
        throws android.os.RemoteException;
    /**
     * Indicates data call contexts have changed.
     *
     * @param type Type of radio indication
     * @param dcList array of SetupDataCallResult identical to that
     *        returned by IRadio.getDataCallList(). It is the complete list
     *        of current data contexts including new contexts that have been
     *        activated. A data call is only removed from this list when the
     *        framework sends a IRadio.deactivateDataCall() or the radio
     *        is powered off/on
     */
    void dataCallListChanged(int type, java.util.ArrayList<android.hardware.radio.V1_0.SetupDataCallResult> dcList)
        throws android.os.RemoteException;
    /**
     * Reports supplementary service related notification from the network.
     *
     * @param type Type of radio indication
     * @param suppSvc SuppSvcNotification as defined in types.hal
     */
    void suppSvcNotify(int type, android.hardware.radio.V1_0.SuppSvcNotification suppSvc)
        throws android.os.RemoteException;
    /**
     * Indicates when STK session is terminated by SIM.
     *
     * @param type Type of radio indication
     */
    void stkSessionEnd(int type)
        throws android.os.RemoteException;
    /**
     * Indicates when SIM issue a STK proactive command to applications
     *
     * @param type Type of radio indication
     * @param cmd SAT/USAT proactive represented as byte array starting with command tag.
     *        Refer ETSI TS 102.223 section 9.4 for command types
     */
    void stkProactiveCommand(int type, String cmd)
        throws android.os.RemoteException;
    /**
     * Indicates when SIM notifies applcations some event happens.
     *
     * @param type Type of radio indication
     * @param cmd SAT/USAT commands or responses
     *        sent by ME to SIM or commands handled by ME, represented as byte array
     *        starting with first byte of response data for command tag. Refer
     *        ETSI TS 102.223 section 9.4 for command types
     */
    void stkEventNotify(int type, String cmd)
        throws android.os.RemoteException;
    /**
     * Indicates when SIM wants application to setup a voice call.
     *
     * @param type Type of radio indication
     * @param timeout Timeout value in millisec for setting up voice call
     */
    void stkCallSetup(int type, long timeout)
        throws android.os.RemoteException;
    /**
     * Indicates that SMS storage on the SIM is full. Sent when the network
     * attempts to deliver a new SMS message. Messages cannot be saved on the
     * SIM until space is freed. In particular, incoming Class 2 messages must not
     * be stored
     *
     * @param type Type of radio indication
     */
    void simSmsStorageFull(int type)
        throws android.os.RemoteException;
    /**
     * Indicates that file(s) on the SIM have been updated, or the SIM
     * has been reinitialized.
     * Note: If the SIM state changes as a result of the SIM refresh (eg,
     * SIM_READY -> SIM_LOCKED_OR_ABSENT), simStatusChanged()
     * must be sent.
     *
     * @param type Type of radio indication
     * @param refreshResult Result of sim refresh
     */
    void simRefresh(int type, android.hardware.radio.V1_0.SimRefreshResult refreshResult)
        throws android.os.RemoteException;
    /**
     * Ring indication for an incoming call (eg, RING or CRING event).
     * There must be at least one callRing() at the beginning
     * of a call and sending multiple is optional. If the system property
     * ro.telephony.call_ring.multiple is false then the upper layers
     * must generate the multiple events internally. Otherwise the vendor
     * code must generate multiple callRing() if
     * ro.telephony.call_ring.multiple is true or if it is absent.
     *
     * The rate of these events is controlled by ro.telephony.call_ring.delay
     * and has a default value of 3000 (3 seconds) if absent.
     *
     * @param type Type of radio indication
     * @param isGsm true for GSM & false for CDMA
     * @param record Cdma Signal Information
     */
    void callRing(int type, boolean isGsm, android.hardware.radio.V1_0.CdmaSignalInfoRecord record)
        throws android.os.RemoteException;
    /**
     * Indicates that SIM state changes.
     * Callee must invoke getIccCardStatus()
     *
     * @param type Type of radio indication
     */
    void simStatusChanged(int type)
        throws android.os.RemoteException;
    /**
     * Indicates when new CDMA SMS is received
     * Callee must subsequently confirm the receipt of the SMS with
     * acknowledgeLastIncomingCdmaSms()
     * Server must not send cdmaNewSms() messages until
     * acknowledgeLastIncomingCdmaSms() has been received
     *
     * @param type Type of radio indication
     * @param msg Cdma Sms Message
     */
    void cdmaNewSms(int type, android.hardware.radio.V1_0.CdmaSmsMessage msg)
        throws android.os.RemoteException;
    /**
     * Indicates when new Broadcast SMS is received
     *
     * @param type Type of radio indication
     * @param data If received from GSM network, "data" is byte array of 88 bytes
     *        which indicates each page of a CBS Message sent to the MS by the
     *        BTS as coded in 3GPP 23.041 Section 9.4.1.2.
     *        If received from UMTS network, "data" is byte array of 90 up to 1252
     *        bytes which contain between 1 and 15 CBS Message pages sent as one
     *        packet to the MS by the BTS as coded in 3GPP 23.041 Section 9.4.2.2
     */
    void newBroadcastSms(int type, java.util.ArrayList<Byte> data)
        throws android.os.RemoteException;
    /**
     * Indicates that SMS storage on the RUIM is full. Messages
     * cannot be saved on the RUIM until space is freed.
     *
     * @param type Type of radio indication
     */
    void cdmaRuimSmsStorageFull(int type)
        throws android.os.RemoteException;
    /**
     * Indicates a restricted state change (eg, for Domain Specific Access Control).
     * Radio must send this msg after radio off/on cycle no matter it is changed or not.
     *
     * @param type Type of radio indication
     * @param state Bitmask of restricted state as defined by PhoneRestrictedState
     */
    void restrictedStateChanged(int type, int state)
        throws android.os.RemoteException;
    /**
     * Indicates that the radio system selection module has
     * autonomously entered emergency callback mode.
     *
     * @param type Type of radio indication
     */
    void enterEmergencyCallbackMode(int type)
        throws android.os.RemoteException;
    /**
     * Indicates when CDMA radio receives a call waiting indication.
     *
     * @param type Type of radio indication
     * @param callWaitingRecord Cdma CallWaiting information
     */
    void cdmaCallWaiting(int type, android.hardware.radio.V1_0.CdmaCallWaiting callWaitingRecord)
        throws android.os.RemoteException;
    /**
     * Indicates when CDMA radio receives an update of the progress of an OTASP/OTAPA call.
     *
     * @param type Type of radio indication
     * @param status Cdma OTA provision status
     */
    void cdmaOtaProvisionStatus(int type, int status)
        throws android.os.RemoteException;
    /**
     * Indicates when CDMA radio receives one or more info recs.
     *
     * @param type Type of radio indication
     * @param records New Cdma Information
     */
    void cdmaInfoRec(int type, android.hardware.radio.V1_0.CdmaInformationRecords records)
        throws android.os.RemoteException;
    /**
     * Indicates that nework doesn't have in-band information, need to
     * play out-band tone.
     *
     * @param type Type of radio indication
     * @param start true = start play ringback tone, false = stop playing ringback tone
     */
    void indicateRingbackTone(int type, boolean start)
        throws android.os.RemoteException;
    /**
     * Indicates that framework/application must reset the uplink mute state.
     *
     * @param type Type of radio indication
     */
    void resendIncallMute(int type)
        throws android.os.RemoteException;
    /**
     * Indicates when CDMA subscription source changed.
     *
     * @param type Type of radio indication
     * @param cdmaSource New Cdma SubscriptionSource
     */
    void cdmaSubscriptionSourceChanged(int type, int cdmaSource)
        throws android.os.RemoteException;
    /**
     * Indicates when PRL (preferred roaming list) changes.
     *
     * @param type Type of radio indication
     * @param version PRL version after PRL changes
     */
    void cdmaPrlChanged(int type, int version)
        throws android.os.RemoteException;
    /**
     * Indicates when Emergency Callback Mode Ends.
     * Indicates that the radio system selection module has
     * proactively exited emergency callback mode.
     *
     * @param type Type of radio indication
     */
    void exitEmergencyCallbackMode(int type)
        throws android.os.RemoteException;
    /**
     * Indicates the ril connects and returns the version
     *
     * @param type Type of radio indication
     */
    void rilConnected(int type)
        throws android.os.RemoteException;
    /**
     * Indicates that voice technology has changed. Responds with new rat.
     *
     * @param type Type of radio indication
     * @param rat Current new voice rat
     */
    void voiceRadioTechChanged(int type, int rat)
        throws android.os.RemoteException;
    /**
     * Same information as returned by getCellInfoList().
     *
     * @param type Type of radio indication
     * @param records Current cell information known to radio
     */
    void cellInfoList(int type, java.util.ArrayList<android.hardware.radio.V1_0.CellInfo> records)
        throws android.os.RemoteException;
    /**
     * Indicates when IMS registration state has changed.
     * To get IMS registration state and IMS SMS format, callee needs to invoke
     * getImsRegistrationState()
     *
     * @param type Type of radio indication
     */
    void imsNetworkStateChanged(int type)
        throws android.os.RemoteException;
    /**
     * Indicated when there is a change in subscription status.
     * This event must be sent in the following scenarios
     *  - subscription readiness at modem, which was selected by telephony layer
     *  - when subscription is deactivated by modem due to UICC card removal
     *  - when network invalidates the subscription i.e. attach reject due to authentication reject
     *
     * @param type Type of radio indication
     * @param activate false for subscription deactivated, true for subscription activated
     */
    void subscriptionStatusChanged(int type, boolean activate)
        throws android.os.RemoteException;
    /**
     * Indicates when Single Radio Voice Call Continuity (SRVCC)
     * progress state has changed
     *
     * @param type Type of radio indication
     * @param state New Srvcc State
     */
    void srvccStateNotify(int type, int state)
        throws android.os.RemoteException;
    /**
     * Indicates when the hardware configuration associated with the RILd changes.
     *
     * @param type Type of radio indication
     * @param configs Array of hardware configs
     */
    void hardwareConfigChanged(int type, java.util.ArrayList<android.hardware.radio.V1_0.HardwareConfig> configs)
        throws android.os.RemoteException;
    /**
     * Sent when setRadioCapability() completes.
     * Returns the phone radio capability exactly as
     * getRadioCapability() and must be the
     * same set as sent by setRadioCapability().
     *
     * @param type Type of radio indication
     * @param rc Current radio capability
     */
    void radioCapabilityIndication(int type, android.hardware.radio.V1_0.RadioCapability rc)
        throws android.os.RemoteException;
    /**
     * Indicates when Supplementary service(SS) response is received when DIAL/USSD/SS is changed to
     * SS by call control.
     *
     * @param type Type of radio indication
     */
    void onSupplementaryServiceIndication(int type, android.hardware.radio.V1_0.StkCcUnsolSsResult ss)
        throws android.os.RemoteException;
    /**
     * Indicates when there is an ALPHA from UICC during Call Control.
     *
     * @param type Type of radio indication
     * @param alpha ALPHA string from UICC in UTF-8 format
     */
    void stkCallControlAlphaNotify(int type, String alpha)
        throws android.os.RemoteException;
    /**
     * Indicates when there is an incoming Link Capacity Estimate (LCE) info report.
     *
     * @param type Type of radio indication
     * @param lce LceData information
     *
     * DEPRECATED in @1.2 and above, use
     * @1.2::IRadioIndication.currentLinkCapacityEstimate() instead.
     */
    void lceData(int type, android.hardware.radio.V1_0.LceDataInfo lce)
        throws android.os.RemoteException;
    /**
     * Indicates when there is new Carrier PCO data received for a data call. Ideally
     * only new data must be forwarded, though this is not required. Multiple
     * boxes of carrier PCO data for a given call must result in a series of
     * pcoData() calls.
     *
     * @param type Type of radio indication
     * @param pco New PcoData
     */
    void pcoData(int type, android.hardware.radio.V1_0.PcoDataInfo pco)
        throws android.os.RemoteException;
    /**
     * Indicates when there is a modem reset.
     *
     * When modem restarts, one of the following radio state transitions must happen
     * 1) RadioState:ON->RadioState:UNAVAILABLE->RadioState:ON or
     * 2) RadioState:OFF->RadioState:UNAVAILABLE->RadioState:OFF
     * This message must be sent either just before the Radio State changes to RadioState:UNAVAILABLE
     * or just after but must never be sent after the Radio State changes from RadioState:UNAVAILABLE
     * to RadioState:ON/RadioState:OFF again.
     * It must NOT be sent after the Radio state changes to RadioState:ON/RadioState:OFF after the
     * modem restart as that may be interpreted as a second modem reset by the
     * framework.
     *
     * @param type Type of radio indication
     * @param reason the reason for the reset. It
     *        may be a crash signature if the restart was due to a crash or some
     *        string such as "user-initiated restart" or "AT command initiated
     *        restart" that explains the cause of the modem restart
     */
    void modemReset(int type, String reason)
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
                    android.hardware.radio.V1_0.IRadioIndication.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.radio.V1_0.IRadioIndication.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
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
