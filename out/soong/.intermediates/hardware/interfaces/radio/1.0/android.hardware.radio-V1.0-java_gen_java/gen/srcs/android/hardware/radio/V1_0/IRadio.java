package android.hardware.radio.V1_0;

/**
 * This interface is used by telephony & telecom to talk to cellular radio.
 * All the functions have minimum one parameter:
 * serial: which corresponds to serial no. of request. Serial numbers must only be memorized for the
 * duration of a method call. If clients provide colliding serials (including passing the same
 * serial to different methods), multiple responses (one for each method call) must still be served.
 */
public interface IRadio extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.radio@1.0::IRadio";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IRadio asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IRadio)) {
            return (IRadio)iface;
        }

        IRadio proxy = new IRadio.Proxy(binder);

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
    public static IRadio castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IRadio.asInterface(iface.asBinder());
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
    public static IRadio getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IRadio.asInterface(android.os.HwBinder.getService("android.hardware.radio@1.0::IRadio", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IRadio getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IRadio getService(String serviceName) throws android.os.RemoteException {
        return IRadio.asInterface(android.os.HwBinder.getService("android.hardware.radio@1.0::IRadio", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IRadio getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Set response functions for radio requests & radio indications.
     *
     * @param radioResponse Object containing response functions
     * @param radioIndication Object containing radio indications
     */
    void setResponseFunctions(android.hardware.radio.V1_0.IRadioResponse radioResponse, android.hardware.radio.V1_0.IRadioIndication radioIndication)
        throws android.os.RemoteException;
    /**
     * Requests status of the ICC card
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getIccCardStatusResponse()
     *
     */
    void getIccCardStatus(int serial)
        throws android.os.RemoteException;
    /**
     * Supplies ICC PIN. Only called if CardStatus has AppState.PIN state
     *
     * @param serial Serial number of request.
     * @param pin PIN value
     * @param aid AID value, See ETSI 102.221 8.1 and 101.220 4, empty string if no value.
     *
     * Response function is IRadioResponse.supplyIccPinForAppResponse()
     *
     */
    void supplyIccPinForApp(int serial, String pin, String aid)
        throws android.os.RemoteException;
    /**
     * Supplies ICC PUK and new PIN.
     *
     * @param serial Serial number of request.
     * @param puk PUK value
     * @param pin New PIN value
     * @param aid AID value, See ETSI 102.221 8.1 and 101.220 4, empty string if no value.
     *
     * Response function is IRadioResponse.supplyIccPukForAppResponse()
     *
     */
    void supplyIccPukForApp(int serial, String puk, String pin, String aid)
        throws android.os.RemoteException;
    /**
     * Supplies ICC PIN2. Only called following operation where SIM_PIN2 was
     * returned as a a failure from a previous operation.
     *
     * @param serial Serial number of request.
     * @param pin2 PIN2 value
     * @param aid AID value, See ETSI 102.221 8.1 and 101.220 4, empty string if no value.
     *
     * Response function is IRadioResponse.supplyIccPin2ForAppResponse()
     *
     */
    void supplyIccPin2ForApp(int serial, String pin2, String aid)
        throws android.os.RemoteException;
    /**
     * Supplies ICC PUK2 and new PIN2.
     *
     * @param serial Serial number of request.
     * @param puk2 PUK2 value
     * @param pin2 New PIN2 value
     * @param aid AID value, See ETSI 102.221 8.1 and 101.220 4, empty string if no value.
     *
     * Response function is IRadioResponse.supplyIccPuk2ForAppResponse()
     *
     */
    void supplyIccPuk2ForApp(int serial, String puk2, String pin2, String aid)
        throws android.os.RemoteException;
    /**
     * Supplies old ICC PIN and new PIN.
     *
     * @param serial Serial number of request.
     * @param oldPin Old pin value
     * @param newPin New pin value
     * @param aid AID value, See ETSI 102.221 8.1 and 101.220 4, empty string if no value.
     *
     * Response function is IRadioResponse.changeIccPinForAppResponse()
     *
     */
    void changeIccPinForApp(int serial, String oldPin, String newPin, String aid)
        throws android.os.RemoteException;
    /**
     * Supplies old ICC PIN2 and new PIN2.
     *
     * @param serial Serial number of request.
     * @param oldPin2 Old pin2 value
     * @param newPin2 New pin2 value
     * @param aid AID value, See ETSI 102.221 8.1 and 101.220 4, empty string if no value.
     *
     * Response function is IRadioResponse.changeIccPin2ForAppResponse()
     *
     */
    void changeIccPin2ForApp(int serial, String oldPin2, String newPin2, String aid)
        throws android.os.RemoteException;
    /**
     * Requests that network personalization be deactivated
     *
     * @param serial Serial number of request.
     * @param netPin Network depersonlization code
     *
     * Response function is IRadioResponse.supplyNetworkDepersonalizationResponse()
     *
     */
    void supplyNetworkDepersonalization(int serial, String netPin)
        throws android.os.RemoteException;
    /**
     * Requests current call list
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getCurrentCallsResponse()
     *
     */
    void getCurrentCalls(int serial)
        throws android.os.RemoteException;
    /**
     * Initiate voice call.
     * This method is never used for supplementary service codes
     *
     * @param serial Serial number of request.
     * @param dialInfo Dial struct
     *
     * Response function is IRadioResponse.dialResponse()
     *
     */
    void dial(int serial, android.hardware.radio.V1_0.Dial dialInfo)
        throws android.os.RemoteException;
    /**
     * Get the SIM IMSI
     * Only valid when radio state is "RADIO_STATE_ON"
     *
     * @param serial Serial number of request.
     * @param aid AID value, See ETSI 102.221 8.1 and 101.220 4, empty string if no value.
     *
     * Response function is IRadioResponse.getImsiForAppResponse()
     *
     */
    void getImsiForApp(int serial, String aid)
        throws android.os.RemoteException;
    /**
     * Hang up a specific line (like AT+CHLD=1x)
     * After this HANGUP request returns, Radio must show the connection is NOT
     * active anymore in next requestGetCurrentCalls query.
     *
     * @param serial Serial number of request.
     * @param gsmIndex Connection index (value of 'x' in CHLD above)
     *
     * Response function is IRadioResponse.hangupResponse()
     *
     */
    void hangup(int serial, int gsmIndex)
        throws android.os.RemoteException;
    /**
     * Hang up waiting or held (like AT+CHLD=0)
     * After this HANGUP request returns, Radio must show the connection is NOT
     * active anymore in next getCurrentCalls() query.
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.hangupWaitingOrBackgroundResponse()
     *
     */
    void hangupWaitingOrBackground(int serial)
        throws android.os.RemoteException;
    /**
     * Hang up waiting or held (like AT+CHLD=1)
     * After this HANGUP request returns, Radio must show the connection is NOT
     * active anymore in next getCurrentCalls query.
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.hangupForegroundResumeBackgroundResponse()
     *
     */
    void hangupForegroundResumeBackground(int serial)
        throws android.os.RemoteException;
    /**
     * Switch waiting or holding call and active call (like AT+CHLD=2)
     * State transitions must be as follows:
     *
     * Call transitions must happen as shown below.
     *
     *   BEFORE                               AFTER
     * Call 1   Call 2                 Call 1       Call 2
     * ACTIVE   HOLDING                HOLDING     ACTIVE
     * ACTIVE   WAITING                HOLDING     ACTIVE
     * HOLDING  WAITING                HOLDING     ACTIVE
     * ACTIVE   IDLE                   HOLDING     IDLE
     * IDLE     IDLE                   IDLE        IDLE
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.switchWaitingOrHoldingAndActiveResponse()
     *
     */
    void switchWaitingOrHoldingAndActive(int serial)
        throws android.os.RemoteException;
    /**
     * Conference holding and active (like AT+CHLD=3)
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.conferenceResponse()
     *
     */
    void conference(int serial)
        throws android.os.RemoteException;
    /**
     * Send UDUB (user determined user busy) to ringing or
     * waiting call answer)
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.rejectCallResponse()
     *
     */
    void rejectCall(int serial)
        throws android.os.RemoteException;
    /**
     * Requests the failure cause code for the most recently terminated call.
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getLastCallFailCauseResponse()
     *
     */
    void getLastCallFailCause(int serial)
        throws android.os.RemoteException;
    /**
     * Requests current signal strength and associated information.
     * Must succeed if radio is on.
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getSignalStrengthResponse()
     */
    void getSignalStrength(int serial)
        throws android.os.RemoteException;
    /**
     * Request current voice registration state
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getVoiceRegistrationStateResponse()
     */
    void getVoiceRegistrationState(int serial)
        throws android.os.RemoteException;
    /**
     * Request current data registration state
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getDataRegistrationStateResponse()
     */
    void getDataRegistrationState(int serial)
        throws android.os.RemoteException;
    /**
     * Request current operator ONS or EONS
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getOperatorResponse()
     */
    void getOperator(int serial)
        throws android.os.RemoteException;
    /**
     * Toggle radio on and off (for "airplane" mode)
     * If the radio is turned off/on the radio modem subsystem
     * is expected return to an initialized state. For instance,
     * any voice and data calls must be terminated and all associated
     * lists emptied.
     *
     * @param serial Serial number of request.
     * @param on To turn on radio -> on = true, to turn off radio -> on = false.
     *
     * Response function is IRadioResponse.setRadioPowerResponse()
     */
    void setRadioPower(int serial, boolean on)
        throws android.os.RemoteException;
    /**
     * Send a DTMF tone
     *
     * If the implementation is currently playing a tone requested via
     * startDtmf(), that tone must be cancelled and the new tone
     * must be played instead
     *
     * @param serial Serial number of request.
     * @param s string with single char having one of 12 values: 0-9, *, #
     *
     * Response function is IRadioResponse.sendDtmfResponse()
     */
    void sendDtmf(int serial, String s)
        throws android.os.RemoteException;
    /**
     * Send an SMS message
     *
     * @param serial Serial number of request.
     * @param message GsmSmsMessage as defined in types.hal
     *
     * Response function is IRadioResponse.sendSmsResponse()
     *
     * Based on the return error, caller decides to resend if sending sms
     * fails. RadioError:SMS_SEND_FAIL_RETRY means retry (i.e. error cause is 332)
     * and RadioError:GENERIC_FAILURE means no retry (i.e. error cause is 500)
     */
    void sendSms(int serial, android.hardware.radio.V1_0.GsmSmsMessage message)
        throws android.os.RemoteException;
    /**
     * Send an SMS message. Identical to sendSms,
     * except that more messages are expected to be sent soon. If possible,
     * keep SMS relay protocol link open (eg TS 27.005 AT+CMMS command)
     *
     * @param serial Serial number of request.
     * @param message GsmSmsMessage as defined in types.hal
     *
     * Response function is IRadioResponse.sendSMSExpectMoreResponse()
     *
     * Based on the return error, caller decides to resend if sending sms
     * fails. RadioError:SMS_SEND_FAIL_RETRY means retry (i.e. error cause is 332)
     * and RadioError:GENERIC_FAILURE means no retry (i.e. error cause is 500)
     */
    void sendSMSExpectMore(int serial, android.hardware.radio.V1_0.GsmSmsMessage message)
        throws android.os.RemoteException;
    /**
     * Setup a packet data connection. If DataCallResponse.status
     * return DataCallFailCause:NONE it is added to the list of data calls and a
     * unsolDataCallListChanged() is sent. The call remains in the
     * list until deactivateDataCall() is issued or the
     * radio is powered off/on. This list is returned by getDataCallList()
     * and dataCallListChanged().
     *
     * The Radio is expected to:
     *  - Create one data call context.
     *  - Create and configure a dedicated interface for the context
     *  - The interface must be point to point.
     *  - The interface is configured with one or more addresses and
     *    is capable of sending and receiving packets. The prefix length
     *    of the addresses must be /32 for IPv4 and /128 for IPv6.
     *  - Must NOT change the linux routing table.
     *  - Support up to getDataRegistrationState response[5]
     *    number of simultaneous data call contexts.
     *
     * @param serial Serial number of request.
     * @param radioTechnology Radio technology to use.
     * @param dataProfileInfo data profile info.
     * @param modemCognitive Indicating this profile was sent to the modem through setDataProfile
     *                       earlier.
     * @param roamingAllowed Indicating data roaming is allowed or not by the user.
     * @param isRoaming Indicating the device is roaming or not. The 'protocol' parameter in the old
     *                  RIL API must be filled accordingly based on the roaming condition.
     *                  Note this is for backward compatibility with the old radio modem. The modem
     *                  must not use this param for any other reason.
     *
     * Response function is IRadioResponse.setupDataCallResponse() which may return
     * RadioError:REQUEST_NOT_SUPPORTED if @1.2::IRadio or higher is supported.
     *
     * DEPRECATED in @1.2 or higher, use @1.2::IRadio.setupDataCall_1_2() instead.
     */
    void setupDataCall(int serial, int radioTechnology, android.hardware.radio.V1_0.DataProfileInfo dataProfileInfo, boolean modemCognitive, boolean roamingAllowed, boolean isRoaming)
        throws android.os.RemoteException;
    /**
     * Request ICC I/O operation.
     * This is similar to the TS 27.007 "restricted SIM" operation
     * where it assumes all of the EF selection must be done by the
     * callee
     *
     * Arguments and responses that are unused for certain
     * values of "command" must be ignored or set to empty string
     *
     * @param serial Serial number of request.
     * @param iccIo IccIo
     *
     * Please note that IccIo has a "PIN2" field which may be empty string,
     * or may specify a PIN2 for operations that require a PIN2 (eg
     * updating FDN records)
     *
     * Response function is IRadioResponse.iccIOForAppResponse()
     */
    void iccIOForApp(int serial, android.hardware.radio.V1_0.IccIo iccIo)
        throws android.os.RemoteException;
    /**
     * Send a USSD message.
     *
     * If a USSD session already exists, the message must be sent in the
     * context of that session. Otherwise, a new session must be created.
     *
     * The network reply must be reported via unsolOnUssd
     *
     * Only one USSD session must exist at a time, and the session is assumed
     * to exist until:
     * a) The android system invokes cancelUssd()
     * b) The implementation sends a unsolOnUssd() with a type code
     * of "0" (USSD-Notify/no further action) or "2" (session terminated)
     *
     * @param serial Serial number of request.
     * @param ussd string containing the USSD request in UTF-8 format
     *
     * Response function is IRadioResponse.sendUssdResponse()
     *
     * See also requestCancelUssd, unsolOnUssd
     */
    void sendUssd(int serial, String ussd)
        throws android.os.RemoteException;
    /**
     * Cancel the current USSD session if one exists.
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.cancelPendingUssdResponse()
     */
    void cancelPendingUssd(int serial)
        throws android.os.RemoteException;
    /**
     * Gets current CLIR status
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getClirResponse()
     */
    void getClir(int serial)
        throws android.os.RemoteException;
    /**
     * Set current CLIR status
     *
     * @param serial Serial number of request.
     * @param status "n" parameter from TS 27.007 7.7
     *
     * Response function is IRadioResponse.setClirResponse()
     */
    void setClir(int serial, int status)
        throws android.os.RemoteException;
    /**
     * Request call forward status.
     *
     * @param serial Serial number of request.
     * @param callInfo CallForwardInfo
     *
     * Response function is IRadioResponse.getCallForwardStatusResponse()
     */
    void getCallForwardStatus(int serial, android.hardware.radio.V1_0.CallForwardInfo callInfo)
        throws android.os.RemoteException;
    /**
     * Configure call forward rule
     *
     * @param serial Serial number of request.
     * @param callInfo CallForwardInfo
     *
     * Response function is IRadioResponse.setCallForwardResponse()
     */
    void setCallForward(int serial, android.hardware.radio.V1_0.CallForwardInfo callInfo)
        throws android.os.RemoteException;
    /**
     * Query current call waiting state
     *
     * @param serial Serial number of request.
     * @param serviceClass Service class is the TS 27.007 service class to query
     *
     * Response function is IRadioResponse.getCallWaitingResponse()
     */
    void getCallWaiting(int serial, int serviceClass)
        throws android.os.RemoteException;
    /**
     * Configure current call waiting state
     *
     * @param serial Serial number of request.
     * @param enable is false for "disabled" and true for "enabled"
     * @param serviceClass is the TS 27.007 service class bit vector of services to modify
     *
     * Response function is IRadioResponse.setCallWaitingResponse()
     */
    void setCallWaiting(int serial, boolean enable, int serviceClass)
        throws android.os.RemoteException;
    /**
     * Acknowledge successful or failed receipt of SMS previously indicated
     * via unsolResponseNewSms
     *
     * @param serial Serial number of request.
     * @param success is true on successful receipt
     *        (basically, AT+CNMA=1 from TS 27.005 is 0 on failed receipt
     *        (basically, AT+CNMA=2 from TS 27.005)
     * @param cause: if success is false, this contains the failure cause as defined
     *        in TS 23.040, 9.2.3.22.
     *
     * Response function is IRadioResponse.acknowledgeLastIncomingGsmSmsResponse()
     */
    void acknowledgeLastIncomingGsmSms(int serial, boolean success, int cause)
        throws android.os.RemoteException;
    /**
     * Answer incoming call
     * Must not be called for WAITING calls.
     * switchWaitingOrHoldingAndActive() must be used in this case
     * instead
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.acceptCallResponse()
     */
    void acceptCall(int serial)
        throws android.os.RemoteException;
    /**
     * Deactivate packet data connection and remove from the
     * data call list if RadioError:NONE is returned. Any other return
     * values must also try to remove the call from the list. An
     * unsolDataCallListChanged must be
     * issued because of an deactivateDataCall.
     *
     * @param serial Serial number of request.
     * @param cid Indicates CID
     * @param reasonRadioShutDown Indicates Disconnect Reason
     *        false => No specific reason specified
     *        true => Radio shutdown requested
     *
     * Response function is IRadioResponse.deactivateDataCallResponse() which may return
     * RadioError:REQUEST_NOT_SUPPORTED if @1.2::IRadio or higher is supported.
     *
     * DEPRECATED in @1.2 or higher, use @1.2::IRadio.deactivateDataCall_1_2() instead.
     */
    void deactivateDataCall(int serial, int cid, boolean reasonRadioShutDown)
        throws android.os.RemoteException;
    /**
     * Query the status of a facility lock state
     *
     * @param serial Serial number of request.
     * @param facility is the facility string code from TS 27.007 7.4
     *        (eg "AO" for BAOC, "SC" for SIM lock)
     * @param password is the password, or "" if not required
     * @param serviceClass is the TS 27.007 service class bit vector of services to query
     * @param appId is AID value, See ETSI 102.221 8.1 and 101.220 4, empty string if no value.
     *        This is only applicable in the case of Fixed Dialing Numbers (FDN) requests.
     *
     * Response function is IRadioResponse.getFacilityLockForAppResponse()
     */
    void getFacilityLockForApp(int serial, String facility, String password, int serviceClass, String appId)
        throws android.os.RemoteException;
    /**
     * Enable/disable one facility lock
     *
     * @param serial Serial number of request.
     * @param facility is the facility string code from TS 27.007 7.4 (eg "AO" for BAOC)
     * @param lockState false for "unlock" and true for "lock"
     * @param password is the password
     * @param serviceClass is string representation of decimal TS 27.007
     *        service class bit vector. Eg, the string
     *        "1" means "set this facility for voice services"
     * @param appId is AID value, See ETSI 102.221 8.1 and 101.220 4, empty string if no value.
     *        This is only applicable in the case of Fixed Dialing Numbers (FDN) requests.
     *
     * Response function is IRadioResponse.setFacilityLockForAppResponse()
     */
    void setFacilityLockForApp(int serial, String facility, boolean lockState, String password, int serviceClass, String appId)
        throws android.os.RemoteException;
    /**
     * Change call barring facility password
     *
     * @param serial Serial number of request.
     * @param facility facility string code from TS 27.007 7.4 (eg "AO" for BAOC)
     * @param oldPassword old password
     * @param newPassword new password
     *
     * Response function is IRadioResponse.setBarringPasswordResponse()
     */
    void setBarringPassword(int serial, String facility, String oldPassword, String newPassword)
        throws android.os.RemoteException;
    /**
     * Query current network selection mode
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getNetworkSelectionModeResponse()
     */
    void getNetworkSelectionMode(int serial)
        throws android.os.RemoteException;
    /**
     * Specify that the network must be selected automatically.
     * This request must not respond until the new operator is selected and registered.
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.setNetworkSelectionModeAutomaticResponse()
     */
    void setNetworkSelectionModeAutomatic(int serial)
        throws android.os.RemoteException;
    /**
     * Manually select a specified network.
     * This request must not respond until the new operator is selected and registered.
     *
     * @param serial Serial number of request.
     * @param operatorNumeric string specifying MCCMNC of network to select (eg "310170")
     *
     * Response function is IRadioResponse.setNetworkSelectionModeManualResponse()
     */
    void setNetworkSelectionModeManual(int serial, String operatorNumeric)
        throws android.os.RemoteException;
    /**
     * Scans for available networks
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getAvailableNetworksResponse()
     */
    void getAvailableNetworks(int serial)
        throws android.os.RemoteException;
    /**
     * Start playing a DTMF tone. Continue playing DTMF tone until
     * stopDtmf is received.
     * If a startDtmf() is received while a tone is currently playing,
     * it must cancel the previous tone and play the new one.
     *
     * @param serial Serial number of request.
     * @param s string having a single character with one of 12 values: 0-9,*,#
     *
     * Response function is IRadioResponse.startDtmfResponse()
     */
    void startDtmf(int serial, String s)
        throws android.os.RemoteException;
    /**
     * Stop playing a currently playing DTMF tone.
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.stopDtmfResponse()
     */
    void stopDtmf(int serial)
        throws android.os.RemoteException;
    /**
     * Return string value indicating baseband version, eg response from AT+CGMR
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getBasebandVersionResponse()
     */
    void getBasebandVersion(int serial)
        throws android.os.RemoteException;
    /**
     * Separate a party from a multiparty call placing the multiparty call
     * (less the specified party) on hold and leaving the specified party
     * as the only other member of the current (active) call
     *
     * Like AT+CHLD=2x
     *
     * See TS 22.084 1.3.8.2 (iii)
     * TS 22.030 6.5.5 "Entering "2X followed by send"
     * TS 27.007 "AT+CHLD=2x"
     *
     * @param serial Serial number of request.
     * @param gsmIndex contains Connection index (value of 'x' in CHLD above)
     *
     * Response function is IRadioResponse.separateConnectionResponse()
     */
    void separateConnection(int serial, int gsmIndex)
        throws android.os.RemoteException;
    /**
     * Turn on or off uplink (microphone) mute.
     * Must only be sent while voice call is active.
     * Must always be reset to "disable mute" when a new voice call is initiated
     *
     * @param serial Serial number of request.
     * @param enable true for "enable mute" and false for "disable mute"
     *
     * Response function is IRadioResponse.setMuteResponse()
     */
    void setMute(int serial, boolean enable)
        throws android.os.RemoteException;
    /**
     * Queries the current state of the uplink mute setting
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getMuteResponse()
     */
    void getMute(int serial)
        throws android.os.RemoteException;
    /**
     * Queries the status of the CLIP supplementary service
     * (for MMI code "*#30#")
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getClipResponse()
     */
    void getClip(int serial)
        throws android.os.RemoteException;
    /**
     * Returns the data call list. An entry is added when a
     * setupDataCall() is issued and removed on a
     * deactivateDataCall(). The list is emptied when
     * setRadioPower() off/on is issued.
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getDataCallListResponse()
     */
    void getDataCallList(int serial)
        throws android.os.RemoteException;
    /**
     * Enables/disables supplementary service related notifications from the network.
     * Notifications are reported via unsolSuppSvcNotification().
     *
     * @param serial Serial number of request.
     * @param enable true = notifications enabled, false = notifications disabled.
     *
     * Response function is IRadioResponse.setSuppServiceNotificationsResponse()
     */
    void setSuppServiceNotifications(int serial, boolean enable)
        throws android.os.RemoteException;
    /**
     * Stores a SMS message to SIM memory.
     *
     * @param serial Serial number of request.
     * @param smsWriteArgs SmsWriteArgs defined in types.hal
     *
     * Response function is IRadioResponse.writeSmsToSimResponse()
     */
    void writeSmsToSim(int serial, android.hardware.radio.V1_0.SmsWriteArgs smsWriteArgs)
        throws android.os.RemoteException;
    /**
     * Deletes a SMS message from SIM memory.
     *
     * @param serial Serial number of request.
     * @param index Record index of the message to delete.
     *
     * Response function is IRadioResponse.deleteSmsOnSimResponse()
     */
    void deleteSmsOnSim(int serial, int index)
        throws android.os.RemoteException;
    /**
     * Assign a specified band for RF configuration.
     *
     * @param serial Serial number of request.
     * @param mode RadioBandMode defined in types.hal
     *
     * Response function is IRadioResponse.setBandModeResponse()
     */
    void setBandMode(int serial, int mode)
        throws android.os.RemoteException;
    /**
     * Get the list of band modes supported by RF.
     *
     * @param serial Serial number of request.
     *
     * Response function is IRadioResponse.getAvailableBandModesResponse()
     */
    void getAvailableBandModes(int serial)
        throws android.os.RemoteException;
    /**
     * Requests to send a SAT/USAT envelope command to SIM.
     * The SAT/USAT envelope command refers to 3GPP TS 11.14 and 3GPP TS 31.111
     *
     * @param serial Serial number of request.
     * @param command SAT/USAT command in hexadecimal format string starting with command tag
     *
     * Response function is IRadioResponse.sendEnvelopeResponse()
     */
    void sendEnvelope(int serial, String command)
        throws android.os.RemoteException;
    /**
     * Requests to send a terminal response to SIM for a received proactive command
     *
     * @param serial Serial number of request.
     * @param commandResponse SAT/USAT response in hexadecimal format string starting with
     *        first byte of response data
     *
     * Response function is IRadioResponse.sendTerminalResponseResponseToSim()
     */
    void sendTerminalResponseToSim(int serial, String commandResponse)
        throws android.os.RemoteException;
    /**
     * When STK application gets stkCallSetup(), the call actually has
     * been initialized by mobile device already. (We could see the call has been in the 'call
     * list') So, STK application needs to accept/reject the call according to user
     * operations.
     *
     * @param serial Serial number of request.
     * @param accept true = accept the call setup, false = reject the call setup
     *
     * Response callback is IRadioResponse.handleStkCallSetupRequestFromSimResponse()
     */
    void handleStkCallSetupRequestFromSim(int serial, boolean accept)
        throws android.os.RemoteException;
    /**
     * Connects the two calls and disconnects the subscriber from both calls.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.explicitCallTransferResponse()
     */
    void explicitCallTransfer(int serial)
        throws android.os.RemoteException;
    /**
     * Requests to set the preferred network type for searching and registering
     * (CS/PS domain, RAT, and operation mode)
     *
     * @param serial Serial number of request.
     * @param nwType PreferredNetworkType defined in types.hal
     *
     * Response callback is IRadioResponse.setPreferredNetworkTypeResponse()
     */
    void setPreferredNetworkType(int serial, int nwType)
        throws android.os.RemoteException;
    /**
     * Query the preferred network type (CS/PS domain, RAT, and operation mode)
     * for searching and registering
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getPreferredNetworkTypeResponse()
     */
    void getPreferredNetworkType(int serial)
        throws android.os.RemoteException;
    /**
     * Request neighboring cell id in GSM network
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getNeighboringCidsResponse()
     */
    void getNeighboringCids(int serial)
        throws android.os.RemoteException;
    /**
     * Enables/disables network state change notifications due to changes in
     * LAC and/or CID (for GSM) or BID/SID/NID/latitude/longitude (for CDMA).
     * Basically +CREG=2 vs. +CREG=1 (TS 27.007).
     * Note:  The Radio implementation must default to "updates enabled"
     * when the screen is on and "updates disabled" when the screen is off.
     *
     * @param serial Serial number of request.
     * @param enable true = updates enabled (+CREG=2), false = updates disabled (+CREG=1)
     *
     * Response callback is IRadioResponse.setLocationUpdatesResponse()
     */
    void setLocationUpdates(int serial, boolean enable)
        throws android.os.RemoteException;
    /**
     * Request to set the location where the CDMA subscription shall
     * be retrieved
     *
     * @param serial Serial number of request.
     * @param cdmaSub CdmaSubscriptionSource
     *
     * Response callback is IRadioResponse.setCdmaSubscriptionSourceResponse()
     */
    void setCdmaSubscriptionSource(int serial, int cdmaSub)
        throws android.os.RemoteException;
    /**
     * Request to set the roaming preferences in CDMA
     *
     * @param serial Serial number of request.
     * @param type CdmaRoamingType defined in types.hal
     *
     * Response callback is IRadioResponse.setCdmaRoamingPreferenceResponse()
     */
    void setCdmaRoamingPreference(int serial, int type)
        throws android.os.RemoteException;
    /**
     * Request the actual setting of the roaming preferences in CDMA in the modem
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getCdmaRoamingPreferenceResponse()
     */
    void getCdmaRoamingPreference(int serial)
        throws android.os.RemoteException;
    /**
     * Request to set the TTY mode
     *
     * @param serial Serial number of request.
     * @param mode TtyMode
     *
     * Response callback is IRadioResponse.setTTYModeResponse()
     */
    void setTTYMode(int serial, int mode)
        throws android.os.RemoteException;
    /**
     * Request the setting of TTY mode
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getTTYModeResponse()
     */
    void getTTYMode(int serial)
        throws android.os.RemoteException;
    /**
     * Request to set the preferred voice privacy mode used in voice scrambling.
     *
     * @param serial Serial number of request.
     * @param enable false for Standard Privacy Mode (Public Long Code Mask)
     *        true for Enhanced Privacy Mode (Private Long Code Mask)
     *
     * Response callback is IRadioResponse.setPreferredVoicePrivacyResponse()
     */
    void setPreferredVoicePrivacy(int serial, boolean enable)
        throws android.os.RemoteException;
    /**
     * Request the setting of preferred voice privacy mode.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getPreferredVoicePrivacyResponse()
     */
    void getPreferredVoicePrivacy(int serial)
        throws android.os.RemoteException;
    /**
     * Send FLASH command
     *
     * @param serial Serial number of request.
     * @param featureCode String associated with Flash command
     *
     * Response callback is IRadioResponse.sendCDMAFeatureCodeResponse()
     */
    void sendCDMAFeatureCode(int serial, String featureCode)
        throws android.os.RemoteException;
    /**
     * Send DTMF string
     *
     * @param serial Serial number of request.
     * @param dtmf DTMF string
     * @param on DTMF ON length in milliseconds, or 0 to use default
     * @param off is the DTMF OFF length in milliseconds, or 0 to use default
     *
     * Response callback is IRadioResponse.sendBurstDtmfResponse()
     */
    void sendBurstDtmf(int serial, String dtmf, int on, int off)
        throws android.os.RemoteException;
    /**
     * Send a CDMA SMS message
     *
     * @param serial Serial number of request.
     * @param sms Cdma Sms to be sent described by CdmaSmsMessage in types.hal
     *
     * Response callback is IRadioResponse.sendCdmaSmsResponse()
     */
    void sendCdmaSms(int serial, android.hardware.radio.V1_0.CdmaSmsMessage sms)
        throws android.os.RemoteException;
    /**
     * Acknowledge the success or failure in the receipt of SMS
     * previously indicated via responseCdmaNewSms()
     *
     * @param serial Serial number of request.
     * @param smsAck Cdma Sms ack to be sent described by CdmaSmsAck in types.hal
     *
     * Response callback is IRadioResponse.acknowledgeLastIncomingCdmaSmsResponse()
     */
    void acknowledgeLastIncomingCdmaSms(int serial, android.hardware.radio.V1_0.CdmaSmsAck smsAck)
        throws android.os.RemoteException;
    /**
     * Request the setting of GSM/WCDMA Cell Broadcast SMS config.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getGsmBroadcastConfigResponse()
     */
    void getGsmBroadcastConfig(int serial)
        throws android.os.RemoteException;
    /**
     * Set GSM/WCDMA Cell Broadcast SMS config
     *
     * @param serial Serial number of request.
     * @param configInfo Setting of GSM/WCDMA Cell broadcast config
     *
     * Response callback is IRadioResponse.setGsmBroadcastConfigResponse()
     */
    void setGsmBroadcastConfig(int serial, java.util.ArrayList<android.hardware.radio.V1_0.GsmBroadcastSmsConfigInfo> configInfo)
        throws android.os.RemoteException;
    /**
     * Enable or disable the reception of GSM/WCDMA Cell Broadcast SMS
     *
     * @param serial Serial number of request.
     * @param activate indicates to activate or turn off the reception of GSM/WCDMA
     *        Cell Broadcast SMS. true = activate, false = turn off
     *
     * Response callback is IRadioResponse.setGsmBroadcastActivationResponse()
     */
    void setGsmBroadcastActivation(int serial, boolean activate)
        throws android.os.RemoteException;
    /**
     * Request the setting of CDMA Broadcast SMS config
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getCdmaBroadcastConfigResponse()
     */
    void getCdmaBroadcastConfig(int serial)
        throws android.os.RemoteException;
    /**
     * Set CDMA Broadcast SMS config
     *
     * @param serial Serial number of request.
     * @param configInfo CDMA Broadcast SMS config to be set.
     *
     * Response callback is IRadioResponse.setCdmaBroadcastConfigResponse()
     */
    void setCdmaBroadcastConfig(int serial, java.util.ArrayList<android.hardware.radio.V1_0.CdmaBroadcastSmsConfigInfo> configInfo)
        throws android.os.RemoteException;
    /**
     * Enable or disable the reception of CDMA Cell Broadcast SMS
     *
     * @param serial Serial number of request.
     * @param activate indicates to activate or turn off the reception of CDMA
     *        Cell Broadcast SMS. true = activate, false = turn off
     *
     * Response callback is IRadioResponse.setCdmaBroadcastActivationResponse()
     */
    void setCdmaBroadcastActivation(int serial, boolean activate)
        throws android.os.RemoteException;
    /**
     * Request the device MDN / H_SID / H_NID.
     * The request is only allowed when CDMA subscription is available. When CDMA
     * subscription is changed, application layer must re-issue the request to
     * update the subscription information.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getCDMASubscriptionResponse()
     */
    void getCDMASubscription(int serial)
        throws android.os.RemoteException;
    /**
     * Stores a CDMA SMS message to RUIM memory.
     *
     * @param serial Serial number of request.
     * @param cdmaSms CDMA message as defined by CdmaSmsWriteArgs in types.hal
     *
     * Response callback is IRadioResponse.writeSmsToRuimResponse()
     */
    void writeSmsToRuim(int serial, android.hardware.radio.V1_0.CdmaSmsWriteArgs cdmaSms)
        throws android.os.RemoteException;
    /**
     * Deletes a CDMA SMS message from RUIM memory.
     *
     * @param serial Serial number of request.
     * @param index record index of the message to delete
     *
     * Response callback is IRadioResponse.deleteSmsOnRuimResponse()
     */
    void deleteSmsOnRuim(int serial, int index)
        throws android.os.RemoteException;
    /**
     * Request the device ESN / MEID / IMEI / IMEISV.
     * The request is always allowed and contains GSM and CDMA device identity.
     * When CDMA subscription is changed the ESN/MEID changes. The application
     * layer must re-issue the request to update the device identity in this case.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getDeviceIdentityResponse()
     */
    void getDeviceIdentity(int serial)
        throws android.os.RemoteException;
    /**
     * Request the radio's system selection module to exit emergency
     * callback mode. Radio must not respond with SUCCESS until the modem has
     * completely exited from Emergency Callback Mode.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.exitEmergencyCallbackModeResponse()
     */
    void exitEmergencyCallbackMode(int serial)
        throws android.os.RemoteException;
    /**
     * Get the default Short Message Service Center address on the device.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getSmscAddressResponse()
     */
    void getSmscAddress(int serial)
        throws android.os.RemoteException;
    /**
     * Set the default Short Message Service Center address on the device.
     *
     * @param serial Serial number of request.
     * @param smsc Short Message Service Center address to set
     *
     * Response callback is IRadioResponse.setSmscAddressResponse()
     */
    void setSmscAddress(int serial, String smsc)
        throws android.os.RemoteException;
    /**
     * Indicates whether there is storage available for new SMS messages.
     *
     * @param serial Serial number of request.
     * @param available true if memory is available for storing new messages,
     *        false if memory capacity is exceeded
     *
     * Response callback is IRadioResponse.reportSmsMemoryStatusResponse()
     */
    void reportSmsMemoryStatus(int serial, boolean available)
        throws android.os.RemoteException;
    /**
     * Indicates that the StkService is running and is
     * ready to receive unsolicited stkXXXXX commands.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.reportStkServiceIsRunningResponse()
     */
    void reportStkServiceIsRunning(int serial)
        throws android.os.RemoteException;
    /**
     * Request to query the location where the CDMA subscription shall be retrieved.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getCdmaSubscriptionSourceResponse()
     */
    void getCdmaSubscriptionSource(int serial)
        throws android.os.RemoteException;
    /**
     * Request the ISIM application on the UICC to perform AKA
     * challenge/response algorithm for IMS authentication
     *
     * @param serial Serial number of request.
     * @param challenge challenge string in Base64 format
     *
     * Response callback is IRadioResponse.requestIsimAuthenticationResponse()
     */
    void requestIsimAuthentication(int serial, String challenge)
        throws android.os.RemoteException;
    /**
     * Acknowledge successful or failed receipt of SMS previously indicated
     * via unsol responseNewSms(), including acknowledgement TPDU to send
     * as the RP-User-Data element of the RP-ACK or RP-ERROR PDU.
     *
     * @param serial Serial number of request.
     * @param success true on successful receipt (send RP-ACK)
     *        false on failed receipt (send RP-ERROR)
     * @param ackPdu acknowledgement TPDU in hexadecimal format
     *
     * Response callback is IRadioResponse.acknowledgeIncomingGsmSmsWithPduResponse()
     */
    void acknowledgeIncomingGsmSmsWithPdu(int serial, boolean success, String ackPdu)
        throws android.os.RemoteException;
    /**
     * Requests to send a SAT/USAT envelope command to SIM.
     * The SAT/USAT envelope command refers to 3GPP TS 11.14 and 3GPP TS 31.111.
     *
     * This request has one difference from sendEnvelope():
     * the SW1 and SW2 status bytes from the UICC response are returned along with
     * the response data, using the same structure as iccIOForApp().
     *
     * The implementation must perform normal processing of a '91XX'
     * response in SW1/SW2 to retrieve the pending proactive command and send it
     * as an unsolicited response, as sendEnvelope() does.
     *
     * @param serial Serial number of request.
     * @param contents SAT/USAT command in hexadecimal format starting with command tag
     *
     * Response callback is IRadioResponse.sendEnvelopeWithStatusResponse()
     */
    void sendEnvelopeWithStatus(int serial, String contents)
        throws android.os.RemoteException;
    /**
     * Query the radio technology type (3GPP/3GPP2) used for voice. Query is valid only
     * when radio state is not RADIO_STATE_UNAVAILABLE
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getVoiceRadioTechnologyResponse()
     */
    void getVoiceRadioTechnology(int serial)
        throws android.os.RemoteException;
    /**
     * Request all of the current cell information known to the radio. The radio
     * must return list of all current cells, including the neighboring cells. If for a particular
     * cell information isn't known then the appropriate unknown value will be returned.
     * This does not cause or change the rate of unsolicited cellInfoList().
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getCellInfoListResponse()
     */
    void getCellInfoList(int serial)
        throws android.os.RemoteException;
    /**
     * Sets the minimum time between when unsolicited cellInfoList() must be invoked.
     * A value of 0, means invoke cellInfoList() when any of the reported
     * information changes. Setting the value to INT_MAX(0x7fffffff) means never issue
     * a unsolicited cellInfoList().
     *
     * @param serial Serial number of request.
     * @param rate minimum time in milliseconds to indicate time between unsolicited cellInfoList()
     *
     * Response callback is IRadioResponse.setCellInfoListRateResponse()
     */
    void setCellInfoListRate(int serial, int rate)
        throws android.os.RemoteException;
    /**
     * Set an apn to initial attach network
     *
     * @param serial Serial number of request.
     * @param dataProfileInfo data profile containing APN settings
     * @param modemCognitive indicating the data profile was sent to the modem through
     *                       setDataProfile earlier.
     * @param isRoaming Indicating the device is roaming or not. The 'protocol' parameter in the old
     *                  RIL_InitialAttachApn must be filled accordingly based on the roaming
     *                  condition. Note this is for backward compatibility with the old radio modem.
     *                  The modem must not use this param for any other reason.
     *
     * Response callback is IRadioResponse.setInitialAttachApnResponse()
     */
    void setInitialAttachApn(int serial, android.hardware.radio.V1_0.DataProfileInfo dataProfileInfo, boolean modemCognitive, boolean isRoaming)
        throws android.os.RemoteException;
    /**
     * Request current IMS registration state
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getImsRegistrationStateResponse()
     */
    void getImsRegistrationState(int serial)
        throws android.os.RemoteException;
    /**
     * Send a SMS message over IMS.
     * Based on the return error, caller decides to resend if sending sms
     * fails. SMS_SEND_FAIL_RETRY means retry, and other errors means no retry.
     * In case of retry, data is encoded based on Voice Technology available.
     *
     * @param serial Serial number of request.
     * @param message ImsSmsMessage as defined in types.hal to be sent
     *
     * Response callback is IRadioResponse.sendImsSmsResponse()
     */
    void sendImsSms(int serial, android.hardware.radio.V1_0.ImsSmsMessage message)
        throws android.os.RemoteException;
    /**
     * Request APDU exchange on the basic channel. This command reflects TS 27.007
     * "generic SIM access" operation (+CSIM). The modem must ensure proper function
     * of GSM/CDMA, and filter commands appropriately. It must filter
     * channel management and SELECT by DF name commands.
     * "sessionid" field must be ignored.
     *
     * @param serial Serial number of request.
     * @param message SimApdu as defined in types.hal to be sent
     *
     * Response callback is IRadioResponse.iccTransmitApduBasicChannelResponse()
     */
    void iccTransmitApduBasicChannel(int serial, android.hardware.radio.V1_0.SimApdu message)
        throws android.os.RemoteException;
    /**
     * Open a new logical channel and select the given application. This command
     * reflects TS 27.007 "open logical channel" operation (+CCHO).
     *
     * @param serial Serial number of request.
     * @param aid AID value, See ETSI 102.221 and 101.220.
     * @param p2 P2 value, described in ISO 7816-4. Ignore if equal to P2Constant:NO_P2
     *
     * Response callback is IRadioResponse.iccOpenLogicalChannelResponse()
     */
    void iccOpenLogicalChannel(int serial, String aid, int p2)
        throws android.os.RemoteException;
    /**
     * Close a previously opened logical channel. This command reflects TS 27.007
     * "close logical channel" operation (+CCHC).
     *
     * @param serial Serial number of request.
     * @param channelId session id of the logical channel (+CCHC).
     *
     * Response callback is IRadioResponse.iccCloseLogicalChannelResponse()
     */
    void iccCloseLogicalChannel(int serial, int channelId)
        throws android.os.RemoteException;
    /**
     * Exchange APDUs with a UICC over a previously opened logical channel. This
     * command reflects TS 27.007 "generic logical channel access" operation
     * (+CGLA). The modem must filter channel management and SELECT by DF name
     * commands.
     *
     * @param serial Serial number of request.
     * @param message SimApdu as defined in types.hal to be sent
     *
     * Response callback is IRadioResponse.iccTransmitApduLogicalChannelResponse()
     */
    void iccTransmitApduLogicalChannel(int serial, android.hardware.radio.V1_0.SimApdu message)
        throws android.os.RemoteException;
    /**
     * Read one of the radio NV items.
     * This is used for device configuration by some CDMA operators.
     *
     * @param serial Serial number of request.
     * @param itemId NvItem is radio NV item as defined in types.hal
     *
     * Response callback is IRadioResponse.nvReadItemResponse()
     */
    void nvReadItem(int serial, int itemId)
        throws android.os.RemoteException;
    /**
     * Write one of the radio NV items.
     * This is used for device configuration by some CDMA operators.
     *
     * @param serial Serial number of request.
     * @param item NvWriteItem as defined in types.hal
     *
     * Response callback is IRadioResponse.nvWriteItemResponse()
     */
    void nvWriteItem(int serial, android.hardware.radio.V1_0.NvWriteItem item)
        throws android.os.RemoteException;
    /**
     * Update the CDMA Preferred Roaming List (PRL) in the radio NV storage.
     * This is used for device configuration by some CDMA operators.
     *
     * @param serial Serial number of request.
     * @param prl PRL as a byte array
     *
     * Response callback is IRadioResponse.nvWriteCdmaPrlResponse()
     */
    void nvWriteCdmaPrl(int serial, java.util.ArrayList<Byte> prl)
        throws android.os.RemoteException;
    /**
     * Reset the radio NV configuration to the factory state.
     * This is used for device configuration by some CDMA operators.
     *
     * @param serial Serial number of request.
     * @param resetType ResetNvType as defined in types.hal
     *
     * Response callback is IRadioResponse.nvResetConfigResponse()
     */
    void nvResetConfig(int serial, int resetType)
        throws android.os.RemoteException;
    /**
     * Selection/de-selection of a subscription from a SIM card
     *
     * @param serial Serial number of request.
     * @param uiccSub SelectUiccSub as defined in types.hal
     *
     * Response callback is IRadioResponse.setUiccSubscriptionResponse()
     */
    void setUiccSubscription(int serial, android.hardware.radio.V1_0.SelectUiccSub uiccSub)
        throws android.os.RemoteException;
    /**
     * Tells the modem whether data calls are allowed or not
     *
     * @param serial Serial number of request.
     * @param allow true to allow data calls, false to disallow data calls
     *
     * Response callback is IRadioResponse.setDataAllowedResponse()
     */
    void setDataAllowed(int serial, boolean allow)
        throws android.os.RemoteException;
    /**
     * Request all of the current hardware (modem and sim) associated with Radio.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getHardwareConfigResponse()
     */
    void getHardwareConfig(int serial)
        throws android.os.RemoteException;
    /**
     * Returns the response of SIM Authentication through Radio challenge request.
     *
     * @param serial Serial number of request.
     * @param authContext P2 value of authentication command, see P2 parameter in
     *        3GPP TS 31.102 7.1.2
     * @param authData the challenge string in Base64 format, see 3GPP TS 31.102 7.1.2
     * @param aid AID value, See ETSI 102.221 8.1 and 101.220 4, empty string if no value
     *
     * Response callback is IRadioResponse.requestIccSimAuthenticationResponse()
     */
    void requestIccSimAuthentication(int serial, int authContext, String authData, String aid)
        throws android.os.RemoteException;
    /**
     * Set data profile in modem.
     * Modem must erase existed profiles from framework, and apply new profiles
     *
     * @param serial Serial number of request.
     * @param profiles Array of DataProfiles to set.
     * @param isRoaming Indicating the device is roaming or not. The 'protocol' parameter in the old
     *                  RIL API RIL_DataProfileInfo must be filled accordingly based on the
     *                  roaming condition. Note this is for backward compatibility with the old
     *                  radio modem. The modem must not use this param for any other reason.
     *
     * Response callback is IRadioResponse.setDataProfileResponse()
     */
    void setDataProfile(int serial, java.util.ArrayList<android.hardware.radio.V1_0.DataProfileInfo> profiles, boolean isRoaming)
        throws android.os.RemoteException;
    /**
     * Device is shutting down. All further commands are ignored
     * and RADIO_NOT_AVAILABLE must be returned.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.requestShutdownResponse()
     */
    void requestShutdown(int serial)
        throws android.os.RemoteException;
    /**
     * Used to get phone radio capability.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getRadioCapabilityResponse()
     */
    void getRadioCapability(int serial)
        throws android.os.RemoteException;
    /**
     * Used to set the phones radio capability. Be VERY careful
     * using this request as it may cause some vendor modems to reset. Because
     * of the possible modem reset any radio commands after this one may not be
     * processed.
     *
     * @param serial Serial number of request.
     * @param rc RadioCapability structure to be set
     *
     * Response callback is IRadioResponse.setRadioCapabilityResponse()
     */
    void setRadioCapability(int serial, android.hardware.radio.V1_0.RadioCapability rc)
        throws android.os.RemoteException;
    /**
     * Start Link Capacity Estimate (LCE) service if supported by the radio.
     *
     * @param serial Serial number of request.
     * @param reportInterval desired reporting interval (ms).
     * @param pullMode LCE service mode. true: PULL; false: PUSH.
     *
     * Response callback is IRadioResponse.startLceServiceResponse() which may return
     * RadioError:REQUEST_NOT_SUPPORTED if @1.2::IRadio or higher is supported.
     *
     * DEPRECATED in @1.2 or higher which use the always-on LCE that relies on indications.
     */
    void startLceService(int serial, int reportInterval, boolean pullMode)
        throws android.os.RemoteException;
    /**
     * Stop Link Capacity Estimate (LCE) service, the STOP operation must be
     * idempotent for the radio modem.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.stopLceServiceResponse() which may return
     * RadioError:REQUEST_NOT_SUPPORTED if @1.2::IRadio or higher is supported.
     *
     * DEPRECATED in @1.2 or higher which use the always-on LCE that relies on indications.
     */
    void stopLceService(int serial)
        throws android.os.RemoteException;
    /**
     * Pull LCE service for capacity information.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.pullLceDataResponse() which may return
     * RadioError:REQUEST_NOT_SUPPORTED if @1.2::IRadio or higher is supported.
     *
     * DEPRECATED in @1.2 or higher which use the always-on LCE that relies on indications.
     */
    void pullLceData(int serial)
        throws android.os.RemoteException;
    /**
     * Get modem activity information for power consumption estimation.
     * Request clear-on-read statistics information that is used for
     * estimating the per-millisecond power consumption of the cellular
     * modem.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getModemActivityInfoResponse()
     */
    void getModemActivityInfo(int serial)
        throws android.os.RemoteException;
    /**
     * Set carrier restrictions. Expected modem behavior:
     *  If never receives this command
     *  - Must allow all carriers
     *  Receives this command with allAllowed true
     *  - Must allow all carriers. If a previously allowed SIM is present, modem must not reload
     *    the SIM. If a previously disallowed SIM is present, reload the SIM and notify Android.
     *  Receives this command with a list of carriers & allAllowed = false
     *  - Only allow specified carriers, persist across power cycles and FDR. If a present SIM
     *    is in the allowed list, modem must not reload the SIM. If a present SIM is *not* in
     *    the allowed list, modem must detach from the registered network and only keep emergency
     *    service, and notify Android SIM refresh reset with new SIM state being
     *    CardState:RESTRICTED. Emergency service must be enabled.
     *
     * @param serial Serial number of request.
     * @param allAllowed true only when all carriers are allowed. Ignore "carriers" struct.
     *        If false, consider "carriers" struct
     * @param carriers CarrierRestrictions consisting allowed and excluded carriers as defined
     *        in types.hal
     *
     * Response callback is IRadioResponse.setAllowedCarriersResponse()
     */
    void setAllowedCarriers(int serial, boolean allAllowed, android.hardware.radio.V1_0.CarrierRestrictions carriers)
        throws android.os.RemoteException;
    /**
     * Get carrier restrictions.
     *
     * @param serial Serial number of request.
     *
     * Response callback is IRadioResponse.getAllowedCarriersResponse()
     */
    void getAllowedCarriers(int serial)
        throws android.os.RemoteException;
    /**
     * Send the updated device state.
     * This is providing the device state information for the modem to perform power saving
     * strategies.
     *
     * @param serial Serial number of request.
     * @param deviceStateType The updated device state type.
     * @param state The updated state. See the definition of state at DeviceStateType.
     *
     * Response callback is IRadioResponse.sendDeviceStateResponse()
     */
    void sendDeviceState(int serial, int deviceStateType, boolean state)
        throws android.os.RemoteException;
    /**
     * Set the indication filter.
     * This is used to prevent unnecessary application processor wake up for power saving purposes
     * by suppressing the indications in certain scenarios.
     *
     * @param serial Serial number of request.
     * @param indicationFilter 32-bit bitmap of IndicationFilter. Bits set to 1 indicate the
     *        indications are enabled. See IndicationFilter for the definition of each bit.
     *
     * Response callback is IRadioResponse.setIndicationFilterResponse() which may return
     * RadioError:REQUEST_NOT_SUPPORTED if @1.2::IRadio or higher is supported.
     *
     * DEPRECATED in @1.2 or higher, use @1.2::IRadio.setIndicationFilter_1_2() instead.
     */
    void setIndicationFilter(int serial, int indicationFilter)
        throws android.os.RemoteException;
    /**
     * Set SIM card power state.
     * Request is equivalent to inserting or removing the card.
     *
     * The radio modem must generate IRadioIndication.simStatusChanged() as if the SIM had been
     * inserted or removed.
     *
     * @param serial Serial number of request
     * @param powerUp True if powering up the sim card
     *
     * Response callback is IRadioResponse.setSimCardPowerResponse() which may return
     * RadioError:REQUEST_NOT_SUPPORTED if @1.1::IRadio or higher is supported.
     *
     * DEPRECATED in @1.1 or higher, use @1.1::IRadio.setSimCardPower_1_1() instead.
     */
    void setSimCardPower(int serial, boolean powerUp)
        throws android.os.RemoteException;
    /**
     * When response type received from a radio indication or radio response is
     * RadioIndicationType:UNSOLICITED_ACK_EXP or RadioResponseType:SOLICITED_ACK_EXP respectively,
     * acknowledge the receipt of those messages by sending responseAcknowledgement().
     *
     */
    void responseAcknowledgement()
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

    public static final class Proxy implements IRadio {
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
            return "[class or subclass of " + IRadio.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::radio::V1_0::IRadio follow.
        @Override
        public void setResponseFunctions(android.hardware.radio.V1_0.IRadioResponse radioResponse, android.hardware.radio.V1_0.IRadioIndication radioIndication)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeStrongBinder(radioResponse == null ? null : radioResponse.asBinder());
            _hidl_request.writeStrongBinder(radioIndication == null ? null : radioIndication.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* setResponseFunctions */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getIccCardStatus(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* getIccCardStatus */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void supplyIccPinForApp(int serial, String pin, String aid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(pin);
            _hidl_request.writeString(aid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* supplyIccPinForApp */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void supplyIccPukForApp(int serial, String puk, String pin, String aid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(puk);
            _hidl_request.writeString(pin);
            _hidl_request.writeString(aid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* supplyIccPukForApp */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void supplyIccPin2ForApp(int serial, String pin2, String aid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(pin2);
            _hidl_request.writeString(aid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* supplyIccPin2ForApp */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void supplyIccPuk2ForApp(int serial, String puk2, String pin2, String aid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(puk2);
            _hidl_request.writeString(pin2);
            _hidl_request.writeString(aid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* supplyIccPuk2ForApp */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void changeIccPinForApp(int serial, String oldPin, String newPin, String aid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(oldPin);
            _hidl_request.writeString(newPin);
            _hidl_request.writeString(aid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* changeIccPinForApp */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void changeIccPin2ForApp(int serial, String oldPin2, String newPin2, String aid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(oldPin2);
            _hidl_request.writeString(newPin2);
            _hidl_request.writeString(aid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* changeIccPin2ForApp */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void supplyNetworkDepersonalization(int serial, String netPin)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(netPin);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* supplyNetworkDepersonalization */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCurrentCalls(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* getCurrentCalls */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void dial(int serial, android.hardware.radio.V1_0.Dial dialInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.Dial) dialInfo).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* dial */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getImsiForApp(int serial, String aid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(aid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* getImsiForApp */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void hangup(int serial, int gsmIndex)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(gsmIndex);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* hangup */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void hangupWaitingOrBackground(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* hangupWaitingOrBackground */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void hangupForegroundResumeBackground(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* hangupForegroundResumeBackground */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void switchWaitingOrHoldingAndActive(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* switchWaitingOrHoldingAndActive */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void conference(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* conference */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void rejectCall(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(18 /* rejectCall */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getLastCallFailCause(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(19 /* getLastCallFailCause */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSignalStrength(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(20 /* getSignalStrength */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getVoiceRegistrationState(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(21 /* getVoiceRegistrationState */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDataRegistrationState(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(22 /* getDataRegistrationState */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getOperator(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(23 /* getOperator */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setRadioPower(int serial, boolean on)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(on);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(24 /* setRadioPower */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendDtmf(int serial, String s)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(s);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(25 /* sendDtmf */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendSms(int serial, android.hardware.radio.V1_0.GsmSmsMessage message)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.GsmSmsMessage) message).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(26 /* sendSms */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendSMSExpectMore(int serial, android.hardware.radio.V1_0.GsmSmsMessage message)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.GsmSmsMessage) message).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(27 /* sendSMSExpectMore */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setupDataCall(int serial, int radioTechnology, android.hardware.radio.V1_0.DataProfileInfo dataProfileInfo, boolean modemCognitive, boolean roamingAllowed, boolean isRoaming)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(radioTechnology);
            ((android.hardware.radio.V1_0.DataProfileInfo) dataProfileInfo).writeToParcel(_hidl_request);
            _hidl_request.writeBool(modemCognitive);
            _hidl_request.writeBool(roamingAllowed);
            _hidl_request.writeBool(isRoaming);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(28 /* setupDataCall */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void iccIOForApp(int serial, android.hardware.radio.V1_0.IccIo iccIo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.IccIo) iccIo).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(29 /* iccIOForApp */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendUssd(int serial, String ussd)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(ussd);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(30 /* sendUssd */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cancelPendingUssd(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(31 /* cancelPendingUssd */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getClir(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(32 /* getClir */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setClir(int serial, int status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(status);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(33 /* setClir */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCallForwardStatus(int serial, android.hardware.radio.V1_0.CallForwardInfo callInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.CallForwardInfo) callInfo).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(34 /* getCallForwardStatus */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setCallForward(int serial, android.hardware.radio.V1_0.CallForwardInfo callInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.CallForwardInfo) callInfo).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(35 /* setCallForward */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCallWaiting(int serial, int serviceClass)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(serviceClass);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(36 /* getCallWaiting */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setCallWaiting(int serial, boolean enable, int serviceClass)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(enable);
            _hidl_request.writeInt32(serviceClass);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(37 /* setCallWaiting */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void acknowledgeLastIncomingGsmSms(int serial, boolean success, int cause)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(success);
            _hidl_request.writeInt32(cause);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(38 /* acknowledgeLastIncomingGsmSms */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void acceptCall(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(39 /* acceptCall */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void deactivateDataCall(int serial, int cid, boolean reasonRadioShutDown)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(cid);
            _hidl_request.writeBool(reasonRadioShutDown);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(40 /* deactivateDataCall */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getFacilityLockForApp(int serial, String facility, String password, int serviceClass, String appId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(facility);
            _hidl_request.writeString(password);
            _hidl_request.writeInt32(serviceClass);
            _hidl_request.writeString(appId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(41 /* getFacilityLockForApp */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setFacilityLockForApp(int serial, String facility, boolean lockState, String password, int serviceClass, String appId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(facility);
            _hidl_request.writeBool(lockState);
            _hidl_request.writeString(password);
            _hidl_request.writeInt32(serviceClass);
            _hidl_request.writeString(appId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(42 /* setFacilityLockForApp */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setBarringPassword(int serial, String facility, String oldPassword, String newPassword)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(facility);
            _hidl_request.writeString(oldPassword);
            _hidl_request.writeString(newPassword);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(43 /* setBarringPassword */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getNetworkSelectionMode(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(44 /* getNetworkSelectionMode */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setNetworkSelectionModeAutomatic(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(45 /* setNetworkSelectionModeAutomatic */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setNetworkSelectionModeManual(int serial, String operatorNumeric)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(operatorNumeric);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(46 /* setNetworkSelectionModeManual */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getAvailableNetworks(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(47 /* getAvailableNetworks */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void startDtmf(int serial, String s)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(s);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(48 /* startDtmf */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void stopDtmf(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(49 /* stopDtmf */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getBasebandVersion(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(50 /* getBasebandVersion */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void separateConnection(int serial, int gsmIndex)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(gsmIndex);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(51 /* separateConnection */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setMute(int serial, boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(52 /* setMute */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getMute(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(53 /* getMute */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getClip(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(54 /* getClip */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDataCallList(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(55 /* getDataCallList */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setSuppServiceNotifications(int serial, boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(56 /* setSuppServiceNotifications */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void writeSmsToSim(int serial, android.hardware.radio.V1_0.SmsWriteArgs smsWriteArgs)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.SmsWriteArgs) smsWriteArgs).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(57 /* writeSmsToSim */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void deleteSmsOnSim(int serial, int index)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(index);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(58 /* deleteSmsOnSim */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setBandMode(int serial, int mode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(mode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(59 /* setBandMode */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getAvailableBandModes(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(60 /* getAvailableBandModes */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendEnvelope(int serial, String command)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(command);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(61 /* sendEnvelope */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendTerminalResponseToSim(int serial, String commandResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(commandResponse);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(62 /* sendTerminalResponseToSim */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void handleStkCallSetupRequestFromSim(int serial, boolean accept)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(accept);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(63 /* handleStkCallSetupRequestFromSim */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void explicitCallTransfer(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(64 /* explicitCallTransfer */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setPreferredNetworkType(int serial, int nwType)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(nwType);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(65 /* setPreferredNetworkType */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getPreferredNetworkType(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(66 /* getPreferredNetworkType */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getNeighboringCids(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(67 /* getNeighboringCids */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setLocationUpdates(int serial, boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(68 /* setLocationUpdates */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setCdmaSubscriptionSource(int serial, int cdmaSub)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(cdmaSub);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(69 /* setCdmaSubscriptionSource */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setCdmaRoamingPreference(int serial, int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(70 /* setCdmaRoamingPreference */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCdmaRoamingPreference(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(71 /* getCdmaRoamingPreference */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setTTYMode(int serial, int mode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(mode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(72 /* setTTYMode */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getTTYMode(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(73 /* getTTYMode */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setPreferredVoicePrivacy(int serial, boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(74 /* setPreferredVoicePrivacy */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getPreferredVoicePrivacy(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(75 /* getPreferredVoicePrivacy */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendCDMAFeatureCode(int serial, String featureCode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(featureCode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(76 /* sendCDMAFeatureCode */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendBurstDtmf(int serial, String dtmf, int on, int off)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(dtmf);
            _hidl_request.writeInt32(on);
            _hidl_request.writeInt32(off);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(77 /* sendBurstDtmf */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendCdmaSms(int serial, android.hardware.radio.V1_0.CdmaSmsMessage sms)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.CdmaSmsMessage) sms).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(78 /* sendCdmaSms */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void acknowledgeLastIncomingCdmaSms(int serial, android.hardware.radio.V1_0.CdmaSmsAck smsAck)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.CdmaSmsAck) smsAck).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(79 /* acknowledgeLastIncomingCdmaSms */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getGsmBroadcastConfig(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(80 /* getGsmBroadcastConfig */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setGsmBroadcastConfig(int serial, java.util.ArrayList<android.hardware.radio.V1_0.GsmBroadcastSmsConfigInfo> configInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            android.hardware.radio.V1_0.GsmBroadcastSmsConfigInfo.writeVectorToParcel(_hidl_request, configInfo);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(81 /* setGsmBroadcastConfig */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setGsmBroadcastActivation(int serial, boolean activate)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(activate);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(82 /* setGsmBroadcastActivation */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCdmaBroadcastConfig(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(83 /* getCdmaBroadcastConfig */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setCdmaBroadcastConfig(int serial, java.util.ArrayList<android.hardware.radio.V1_0.CdmaBroadcastSmsConfigInfo> configInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            android.hardware.radio.V1_0.CdmaBroadcastSmsConfigInfo.writeVectorToParcel(_hidl_request, configInfo);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(84 /* setCdmaBroadcastConfig */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setCdmaBroadcastActivation(int serial, boolean activate)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(activate);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(85 /* setCdmaBroadcastActivation */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCDMASubscription(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(86 /* getCDMASubscription */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void writeSmsToRuim(int serial, android.hardware.radio.V1_0.CdmaSmsWriteArgs cdmaSms)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.CdmaSmsWriteArgs) cdmaSms).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(87 /* writeSmsToRuim */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void deleteSmsOnRuim(int serial, int index)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(index);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(88 /* deleteSmsOnRuim */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDeviceIdentity(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(89 /* getDeviceIdentity */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void exitEmergencyCallbackMode(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(90 /* exitEmergencyCallbackMode */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSmscAddress(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(91 /* getSmscAddress */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setSmscAddress(int serial, String smsc)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(smsc);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(92 /* setSmscAddress */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void reportSmsMemoryStatus(int serial, boolean available)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(available);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(93 /* reportSmsMemoryStatus */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void reportStkServiceIsRunning(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(94 /* reportStkServiceIsRunning */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCdmaSubscriptionSource(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(95 /* getCdmaSubscriptionSource */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void requestIsimAuthentication(int serial, String challenge)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(challenge);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(96 /* requestIsimAuthentication */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void acknowledgeIncomingGsmSmsWithPdu(int serial, boolean success, String ackPdu)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(success);
            _hidl_request.writeString(ackPdu);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(97 /* acknowledgeIncomingGsmSmsWithPdu */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendEnvelopeWithStatus(int serial, String contents)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(contents);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(98 /* sendEnvelopeWithStatus */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getVoiceRadioTechnology(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(99 /* getVoiceRadioTechnology */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCellInfoList(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(100 /* getCellInfoList */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setCellInfoListRate(int serial, int rate)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(rate);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(101 /* setCellInfoListRate */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setInitialAttachApn(int serial, android.hardware.radio.V1_0.DataProfileInfo dataProfileInfo, boolean modemCognitive, boolean isRoaming)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.DataProfileInfo) dataProfileInfo).writeToParcel(_hidl_request);
            _hidl_request.writeBool(modemCognitive);
            _hidl_request.writeBool(isRoaming);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(102 /* setInitialAttachApn */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getImsRegistrationState(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(103 /* getImsRegistrationState */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendImsSms(int serial, android.hardware.radio.V1_0.ImsSmsMessage message)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.ImsSmsMessage) message).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(104 /* sendImsSms */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void iccTransmitApduBasicChannel(int serial, android.hardware.radio.V1_0.SimApdu message)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.SimApdu) message).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(105 /* iccTransmitApduBasicChannel */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void iccOpenLogicalChannel(int serial, String aid, int p2)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeString(aid);
            _hidl_request.writeInt32(p2);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(106 /* iccOpenLogicalChannel */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void iccCloseLogicalChannel(int serial, int channelId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(channelId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(107 /* iccCloseLogicalChannel */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void iccTransmitApduLogicalChannel(int serial, android.hardware.radio.V1_0.SimApdu message)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.SimApdu) message).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(108 /* iccTransmitApduLogicalChannel */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void nvReadItem(int serial, int itemId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(itemId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(109 /* nvReadItem */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void nvWriteItem(int serial, android.hardware.radio.V1_0.NvWriteItem item)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.NvWriteItem) item).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(110 /* nvWriteItem */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void nvWriteCdmaPrl(int serial, java.util.ArrayList<Byte> prl)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt8Vector(prl);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(111 /* nvWriteCdmaPrl */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void nvResetConfig(int serial, int resetType)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(resetType);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(112 /* nvResetConfig */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setUiccSubscription(int serial, android.hardware.radio.V1_0.SelectUiccSub uiccSub)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.SelectUiccSub) uiccSub).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(113 /* setUiccSubscription */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setDataAllowed(int serial, boolean allow)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(allow);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(114 /* setDataAllowed */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getHardwareConfig(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(115 /* getHardwareConfig */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void requestIccSimAuthentication(int serial, int authContext, String authData, String aid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(authContext);
            _hidl_request.writeString(authData);
            _hidl_request.writeString(aid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(116 /* requestIccSimAuthentication */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setDataProfile(int serial, java.util.ArrayList<android.hardware.radio.V1_0.DataProfileInfo> profiles, boolean isRoaming)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            android.hardware.radio.V1_0.DataProfileInfo.writeVectorToParcel(_hidl_request, profiles);
            _hidl_request.writeBool(isRoaming);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(117 /* setDataProfile */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void requestShutdown(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(118 /* requestShutdown */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getRadioCapability(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(119 /* getRadioCapability */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setRadioCapability(int serial, android.hardware.radio.V1_0.RadioCapability rc)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            ((android.hardware.radio.V1_0.RadioCapability) rc).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(120 /* setRadioCapability */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void startLceService(int serial, int reportInterval, boolean pullMode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(reportInterval);
            _hidl_request.writeBool(pullMode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(121 /* startLceService */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void stopLceService(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(122 /* stopLceService */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void pullLceData(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(123 /* pullLceData */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getModemActivityInfo(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(124 /* getModemActivityInfo */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setAllowedCarriers(int serial, boolean allAllowed, android.hardware.radio.V1_0.CarrierRestrictions carriers)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(allAllowed);
            ((android.hardware.radio.V1_0.CarrierRestrictions) carriers).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(125 /* setAllowedCarriers */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getAllowedCarriers(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(126 /* getAllowedCarriers */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendDeviceState(int serial, int deviceStateType, boolean state)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(deviceStateType);
            _hidl_request.writeBool(state);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(127 /* sendDeviceState */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setIndicationFilter(int serial, int indicationFilter)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeInt32(indicationFilter);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(128 /* setIndicationFilter */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setSimCardPower(int serial, boolean powerUp)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);
            _hidl_request.writeInt32(serial);
            _hidl_request.writeBool(powerUp);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(129 /* setSimCardPower */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void responseAcknowledgement()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadio.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(130 /* responseAcknowledgement */, _hidl_request, _hidl_reply, 1 /* oneway */);
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

    public static abstract class Stub extends android.os.HwBinder implements IRadio {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.radio.V1_0.IRadio.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.radio.V1_0.IRadio.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-49,-86,-80,-28,92,93,123,53,-107,3,45,100,-99,-94,-98,-41,18,-23,32,-7,86,-63,54,113,-17,-45,86,2,-6,-127,-55,35} /* cfaab0e45c5d7b3595032d649da29ed712e920f956c13671efd35602fa81c923 */,
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
                case 1 /* setResponseFunctions */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    android.hardware.radio.V1_0.IRadioResponse radioResponse = android.hardware.radio.V1_0.IRadioResponse.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.radio.V1_0.IRadioIndication radioIndication = android.hardware.radio.V1_0.IRadioIndication.asInterface(_hidl_request.readStrongBinder());
                    setResponseFunctions(radioResponse, radioIndication);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 2 /* getIccCardStatus */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getIccCardStatus(serial);
                    break;
                }

                case 3 /* supplyIccPinForApp */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String pin = _hidl_request.readString();
                    String aid = _hidl_request.readString();
                    supplyIccPinForApp(serial, pin, aid);
                    break;
                }

                case 4 /* supplyIccPukForApp */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String puk = _hidl_request.readString();
                    String pin = _hidl_request.readString();
                    String aid = _hidl_request.readString();
                    supplyIccPukForApp(serial, puk, pin, aid);
                    break;
                }

                case 5 /* supplyIccPin2ForApp */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String pin2 = _hidl_request.readString();
                    String aid = _hidl_request.readString();
                    supplyIccPin2ForApp(serial, pin2, aid);
                    break;
                }

                case 6 /* supplyIccPuk2ForApp */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String puk2 = _hidl_request.readString();
                    String pin2 = _hidl_request.readString();
                    String aid = _hidl_request.readString();
                    supplyIccPuk2ForApp(serial, puk2, pin2, aid);
                    break;
                }

                case 7 /* changeIccPinForApp */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String oldPin = _hidl_request.readString();
                    String newPin = _hidl_request.readString();
                    String aid = _hidl_request.readString();
                    changeIccPinForApp(serial, oldPin, newPin, aid);
                    break;
                }

                case 8 /* changeIccPin2ForApp */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String oldPin2 = _hidl_request.readString();
                    String newPin2 = _hidl_request.readString();
                    String aid = _hidl_request.readString();
                    changeIccPin2ForApp(serial, oldPin2, newPin2, aid);
                    break;
                }

                case 9 /* supplyNetworkDepersonalization */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String netPin = _hidl_request.readString();
                    supplyNetworkDepersonalization(serial, netPin);
                    break;
                }

                case 10 /* getCurrentCalls */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getCurrentCalls(serial);
                    break;
                }

                case 11 /* dial */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.Dial dialInfo = new android.hardware.radio.V1_0.Dial();
                    ((android.hardware.radio.V1_0.Dial) dialInfo).readFromParcel(_hidl_request);
                    dial(serial, dialInfo);
                    break;
                }

                case 12 /* getImsiForApp */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String aid = _hidl_request.readString();
                    getImsiForApp(serial, aid);
                    break;
                }

                case 13 /* hangup */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int gsmIndex = _hidl_request.readInt32();
                    hangup(serial, gsmIndex);
                    break;
                }

                case 14 /* hangupWaitingOrBackground */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    hangupWaitingOrBackground(serial);
                    break;
                }

                case 15 /* hangupForegroundResumeBackground */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    hangupForegroundResumeBackground(serial);
                    break;
                }

                case 16 /* switchWaitingOrHoldingAndActive */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    switchWaitingOrHoldingAndActive(serial);
                    break;
                }

                case 17 /* conference */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    conference(serial);
                    break;
                }

                case 18 /* rejectCall */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    rejectCall(serial);
                    break;
                }

                case 19 /* getLastCallFailCause */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getLastCallFailCause(serial);
                    break;
                }

                case 20 /* getSignalStrength */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getSignalStrength(serial);
                    break;
                }

                case 21 /* getVoiceRegistrationState */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getVoiceRegistrationState(serial);
                    break;
                }

                case 22 /* getDataRegistrationState */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getDataRegistrationState(serial);
                    break;
                }

                case 23 /* getOperator */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getOperator(serial);
                    break;
                }

                case 24 /* setRadioPower */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean on = _hidl_request.readBool();
                    setRadioPower(serial, on);
                    break;
                }

                case 25 /* sendDtmf */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String s = _hidl_request.readString();
                    sendDtmf(serial, s);
                    break;
                }

                case 26 /* sendSms */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.GsmSmsMessage message = new android.hardware.radio.V1_0.GsmSmsMessage();
                    ((android.hardware.radio.V1_0.GsmSmsMessage) message).readFromParcel(_hidl_request);
                    sendSms(serial, message);
                    break;
                }

                case 27 /* sendSMSExpectMore */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.GsmSmsMessage message = new android.hardware.radio.V1_0.GsmSmsMessage();
                    ((android.hardware.radio.V1_0.GsmSmsMessage) message).readFromParcel(_hidl_request);
                    sendSMSExpectMore(serial, message);
                    break;
                }

                case 28 /* setupDataCall */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int radioTechnology = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.DataProfileInfo dataProfileInfo = new android.hardware.radio.V1_0.DataProfileInfo();
                    ((android.hardware.radio.V1_0.DataProfileInfo) dataProfileInfo).readFromParcel(_hidl_request);
                    boolean modemCognitive = _hidl_request.readBool();
                    boolean roamingAllowed = _hidl_request.readBool();
                    boolean isRoaming = _hidl_request.readBool();
                    setupDataCall(serial, radioTechnology, dataProfileInfo, modemCognitive, roamingAllowed, isRoaming);
                    break;
                }

                case 29 /* iccIOForApp */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.IccIo iccIo = new android.hardware.radio.V1_0.IccIo();
                    ((android.hardware.radio.V1_0.IccIo) iccIo).readFromParcel(_hidl_request);
                    iccIOForApp(serial, iccIo);
                    break;
                }

                case 30 /* sendUssd */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String ussd = _hidl_request.readString();
                    sendUssd(serial, ussd);
                    break;
                }

                case 31 /* cancelPendingUssd */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    cancelPendingUssd(serial);
                    break;
                }

                case 32 /* getClir */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getClir(serial);
                    break;
                }

                case 33 /* setClir */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int status = _hidl_request.readInt32();
                    setClir(serial, status);
                    break;
                }

                case 34 /* getCallForwardStatus */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.CallForwardInfo callInfo = new android.hardware.radio.V1_0.CallForwardInfo();
                    ((android.hardware.radio.V1_0.CallForwardInfo) callInfo).readFromParcel(_hidl_request);
                    getCallForwardStatus(serial, callInfo);
                    break;
                }

                case 35 /* setCallForward */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.CallForwardInfo callInfo = new android.hardware.radio.V1_0.CallForwardInfo();
                    ((android.hardware.radio.V1_0.CallForwardInfo) callInfo).readFromParcel(_hidl_request);
                    setCallForward(serial, callInfo);
                    break;
                }

                case 36 /* getCallWaiting */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int serviceClass = _hidl_request.readInt32();
                    getCallWaiting(serial, serviceClass);
                    break;
                }

                case 37 /* setCallWaiting */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean enable = _hidl_request.readBool();
                    int serviceClass = _hidl_request.readInt32();
                    setCallWaiting(serial, enable, serviceClass);
                    break;
                }

                case 38 /* acknowledgeLastIncomingGsmSms */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean success = _hidl_request.readBool();
                    int cause = _hidl_request.readInt32();
                    acknowledgeLastIncomingGsmSms(serial, success, cause);
                    break;
                }

                case 39 /* acceptCall */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    acceptCall(serial);
                    break;
                }

                case 40 /* deactivateDataCall */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int cid = _hidl_request.readInt32();
                    boolean reasonRadioShutDown = _hidl_request.readBool();
                    deactivateDataCall(serial, cid, reasonRadioShutDown);
                    break;
                }

                case 41 /* getFacilityLockForApp */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String facility = _hidl_request.readString();
                    String password = _hidl_request.readString();
                    int serviceClass = _hidl_request.readInt32();
                    String appId = _hidl_request.readString();
                    getFacilityLockForApp(serial, facility, password, serviceClass, appId);
                    break;
                }

                case 42 /* setFacilityLockForApp */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String facility = _hidl_request.readString();
                    boolean lockState = _hidl_request.readBool();
                    String password = _hidl_request.readString();
                    int serviceClass = _hidl_request.readInt32();
                    String appId = _hidl_request.readString();
                    setFacilityLockForApp(serial, facility, lockState, password, serviceClass, appId);
                    break;
                }

                case 43 /* setBarringPassword */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String facility = _hidl_request.readString();
                    String oldPassword = _hidl_request.readString();
                    String newPassword = _hidl_request.readString();
                    setBarringPassword(serial, facility, oldPassword, newPassword);
                    break;
                }

                case 44 /* getNetworkSelectionMode */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getNetworkSelectionMode(serial);
                    break;
                }

                case 45 /* setNetworkSelectionModeAutomatic */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    setNetworkSelectionModeAutomatic(serial);
                    break;
                }

                case 46 /* setNetworkSelectionModeManual */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String operatorNumeric = _hidl_request.readString();
                    setNetworkSelectionModeManual(serial, operatorNumeric);
                    break;
                }

                case 47 /* getAvailableNetworks */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getAvailableNetworks(serial);
                    break;
                }

                case 48 /* startDtmf */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String s = _hidl_request.readString();
                    startDtmf(serial, s);
                    break;
                }

                case 49 /* stopDtmf */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    stopDtmf(serial);
                    break;
                }

                case 50 /* getBasebandVersion */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getBasebandVersion(serial);
                    break;
                }

                case 51 /* separateConnection */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int gsmIndex = _hidl_request.readInt32();
                    separateConnection(serial, gsmIndex);
                    break;
                }

                case 52 /* setMute */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean enable = _hidl_request.readBool();
                    setMute(serial, enable);
                    break;
                }

                case 53 /* getMute */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getMute(serial);
                    break;
                }

                case 54 /* getClip */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getClip(serial);
                    break;
                }

                case 55 /* getDataCallList */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getDataCallList(serial);
                    break;
                }

                case 56 /* setSuppServiceNotifications */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean enable = _hidl_request.readBool();
                    setSuppServiceNotifications(serial, enable);
                    break;
                }

                case 57 /* writeSmsToSim */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.SmsWriteArgs smsWriteArgs = new android.hardware.radio.V1_0.SmsWriteArgs();
                    ((android.hardware.radio.V1_0.SmsWriteArgs) smsWriteArgs).readFromParcel(_hidl_request);
                    writeSmsToSim(serial, smsWriteArgs);
                    break;
                }

                case 58 /* deleteSmsOnSim */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int index = _hidl_request.readInt32();
                    deleteSmsOnSim(serial, index);
                    break;
                }

                case 59 /* setBandMode */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int mode = _hidl_request.readInt32();
                    setBandMode(serial, mode);
                    break;
                }

                case 60 /* getAvailableBandModes */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getAvailableBandModes(serial);
                    break;
                }

                case 61 /* sendEnvelope */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String command = _hidl_request.readString();
                    sendEnvelope(serial, command);
                    break;
                }

                case 62 /* sendTerminalResponseToSim */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String commandResponse = _hidl_request.readString();
                    sendTerminalResponseToSim(serial, commandResponse);
                    break;
                }

                case 63 /* handleStkCallSetupRequestFromSim */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean accept = _hidl_request.readBool();
                    handleStkCallSetupRequestFromSim(serial, accept);
                    break;
                }

                case 64 /* explicitCallTransfer */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    explicitCallTransfer(serial);
                    break;
                }

                case 65 /* setPreferredNetworkType */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int nwType = _hidl_request.readInt32();
                    setPreferredNetworkType(serial, nwType);
                    break;
                }

                case 66 /* getPreferredNetworkType */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getPreferredNetworkType(serial);
                    break;
                }

                case 67 /* getNeighboringCids */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getNeighboringCids(serial);
                    break;
                }

                case 68 /* setLocationUpdates */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean enable = _hidl_request.readBool();
                    setLocationUpdates(serial, enable);
                    break;
                }

                case 69 /* setCdmaSubscriptionSource */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int cdmaSub = _hidl_request.readInt32();
                    setCdmaSubscriptionSource(serial, cdmaSub);
                    break;
                }

                case 70 /* setCdmaRoamingPreference */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int type = _hidl_request.readInt32();
                    setCdmaRoamingPreference(serial, type);
                    break;
                }

                case 71 /* getCdmaRoamingPreference */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getCdmaRoamingPreference(serial);
                    break;
                }

                case 72 /* setTTYMode */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int mode = _hidl_request.readInt32();
                    setTTYMode(serial, mode);
                    break;
                }

                case 73 /* getTTYMode */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getTTYMode(serial);
                    break;
                }

                case 74 /* setPreferredVoicePrivacy */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean enable = _hidl_request.readBool();
                    setPreferredVoicePrivacy(serial, enable);
                    break;
                }

                case 75 /* getPreferredVoicePrivacy */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getPreferredVoicePrivacy(serial);
                    break;
                }

                case 76 /* sendCDMAFeatureCode */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String featureCode = _hidl_request.readString();
                    sendCDMAFeatureCode(serial, featureCode);
                    break;
                }

                case 77 /* sendBurstDtmf */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String dtmf = _hidl_request.readString();
                    int on = _hidl_request.readInt32();
                    int off = _hidl_request.readInt32();
                    sendBurstDtmf(serial, dtmf, on, off);
                    break;
                }

                case 78 /* sendCdmaSms */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.CdmaSmsMessage sms = new android.hardware.radio.V1_0.CdmaSmsMessage();
                    ((android.hardware.radio.V1_0.CdmaSmsMessage) sms).readFromParcel(_hidl_request);
                    sendCdmaSms(serial, sms);
                    break;
                }

                case 79 /* acknowledgeLastIncomingCdmaSms */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.CdmaSmsAck smsAck = new android.hardware.radio.V1_0.CdmaSmsAck();
                    ((android.hardware.radio.V1_0.CdmaSmsAck) smsAck).readFromParcel(_hidl_request);
                    acknowledgeLastIncomingCdmaSms(serial, smsAck);
                    break;
                }

                case 80 /* getGsmBroadcastConfig */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getGsmBroadcastConfig(serial);
                    break;
                }

                case 81 /* setGsmBroadcastConfig */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    java.util.ArrayList<android.hardware.radio.V1_0.GsmBroadcastSmsConfigInfo> configInfo = android.hardware.radio.V1_0.GsmBroadcastSmsConfigInfo.readVectorFromParcel(_hidl_request);
                    setGsmBroadcastConfig(serial, configInfo);
                    break;
                }

                case 82 /* setGsmBroadcastActivation */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean activate = _hidl_request.readBool();
                    setGsmBroadcastActivation(serial, activate);
                    break;
                }

                case 83 /* getCdmaBroadcastConfig */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getCdmaBroadcastConfig(serial);
                    break;
                }

                case 84 /* setCdmaBroadcastConfig */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    java.util.ArrayList<android.hardware.radio.V1_0.CdmaBroadcastSmsConfigInfo> configInfo = android.hardware.radio.V1_0.CdmaBroadcastSmsConfigInfo.readVectorFromParcel(_hidl_request);
                    setCdmaBroadcastConfig(serial, configInfo);
                    break;
                }

                case 85 /* setCdmaBroadcastActivation */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean activate = _hidl_request.readBool();
                    setCdmaBroadcastActivation(serial, activate);
                    break;
                }

                case 86 /* getCDMASubscription */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getCDMASubscription(serial);
                    break;
                }

                case 87 /* writeSmsToRuim */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.CdmaSmsWriteArgs cdmaSms = new android.hardware.radio.V1_0.CdmaSmsWriteArgs();
                    ((android.hardware.radio.V1_0.CdmaSmsWriteArgs) cdmaSms).readFromParcel(_hidl_request);
                    writeSmsToRuim(serial, cdmaSms);
                    break;
                }

                case 88 /* deleteSmsOnRuim */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int index = _hidl_request.readInt32();
                    deleteSmsOnRuim(serial, index);
                    break;
                }

                case 89 /* getDeviceIdentity */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getDeviceIdentity(serial);
                    break;
                }

                case 90 /* exitEmergencyCallbackMode */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    exitEmergencyCallbackMode(serial);
                    break;
                }

                case 91 /* getSmscAddress */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getSmscAddress(serial);
                    break;
                }

                case 92 /* setSmscAddress */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String smsc = _hidl_request.readString();
                    setSmscAddress(serial, smsc);
                    break;
                }

                case 93 /* reportSmsMemoryStatus */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean available = _hidl_request.readBool();
                    reportSmsMemoryStatus(serial, available);
                    break;
                }

                case 94 /* reportStkServiceIsRunning */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    reportStkServiceIsRunning(serial);
                    break;
                }

                case 95 /* getCdmaSubscriptionSource */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getCdmaSubscriptionSource(serial);
                    break;
                }

                case 96 /* requestIsimAuthentication */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String challenge = _hidl_request.readString();
                    requestIsimAuthentication(serial, challenge);
                    break;
                }

                case 97 /* acknowledgeIncomingGsmSmsWithPdu */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean success = _hidl_request.readBool();
                    String ackPdu = _hidl_request.readString();
                    acknowledgeIncomingGsmSmsWithPdu(serial, success, ackPdu);
                    break;
                }

                case 98 /* sendEnvelopeWithStatus */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String contents = _hidl_request.readString();
                    sendEnvelopeWithStatus(serial, contents);
                    break;
                }

                case 99 /* getVoiceRadioTechnology */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getVoiceRadioTechnology(serial);
                    break;
                }

                case 100 /* getCellInfoList */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getCellInfoList(serial);
                    break;
                }

                case 101 /* setCellInfoListRate */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int rate = _hidl_request.readInt32();
                    setCellInfoListRate(serial, rate);
                    break;
                }

                case 102 /* setInitialAttachApn */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.DataProfileInfo dataProfileInfo = new android.hardware.radio.V1_0.DataProfileInfo();
                    ((android.hardware.radio.V1_0.DataProfileInfo) dataProfileInfo).readFromParcel(_hidl_request);
                    boolean modemCognitive = _hidl_request.readBool();
                    boolean isRoaming = _hidl_request.readBool();
                    setInitialAttachApn(serial, dataProfileInfo, modemCognitive, isRoaming);
                    break;
                }

                case 103 /* getImsRegistrationState */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getImsRegistrationState(serial);
                    break;
                }

                case 104 /* sendImsSms */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.ImsSmsMessage message = new android.hardware.radio.V1_0.ImsSmsMessage();
                    ((android.hardware.radio.V1_0.ImsSmsMessage) message).readFromParcel(_hidl_request);
                    sendImsSms(serial, message);
                    break;
                }

                case 105 /* iccTransmitApduBasicChannel */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.SimApdu message = new android.hardware.radio.V1_0.SimApdu();
                    ((android.hardware.radio.V1_0.SimApdu) message).readFromParcel(_hidl_request);
                    iccTransmitApduBasicChannel(serial, message);
                    break;
                }

                case 106 /* iccOpenLogicalChannel */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    String aid = _hidl_request.readString();
                    int p2 = _hidl_request.readInt32();
                    iccOpenLogicalChannel(serial, aid, p2);
                    break;
                }

                case 107 /* iccCloseLogicalChannel */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int channelId = _hidl_request.readInt32();
                    iccCloseLogicalChannel(serial, channelId);
                    break;
                }

                case 108 /* iccTransmitApduLogicalChannel */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.SimApdu message = new android.hardware.radio.V1_0.SimApdu();
                    ((android.hardware.radio.V1_0.SimApdu) message).readFromParcel(_hidl_request);
                    iccTransmitApduLogicalChannel(serial, message);
                    break;
                }

                case 109 /* nvReadItem */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int itemId = _hidl_request.readInt32();
                    nvReadItem(serial, itemId);
                    break;
                }

                case 110 /* nvWriteItem */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.NvWriteItem item = new android.hardware.radio.V1_0.NvWriteItem();
                    ((android.hardware.radio.V1_0.NvWriteItem) item).readFromParcel(_hidl_request);
                    nvWriteItem(serial, item);
                    break;
                }

                case 111 /* nvWriteCdmaPrl */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    java.util.ArrayList<Byte> prl = _hidl_request.readInt8Vector();
                    nvWriteCdmaPrl(serial, prl);
                    break;
                }

                case 112 /* nvResetConfig */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int resetType = _hidl_request.readInt32();
                    nvResetConfig(serial, resetType);
                    break;
                }

                case 113 /* setUiccSubscription */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.SelectUiccSub uiccSub = new android.hardware.radio.V1_0.SelectUiccSub();
                    ((android.hardware.radio.V1_0.SelectUiccSub) uiccSub).readFromParcel(_hidl_request);
                    setUiccSubscription(serial, uiccSub);
                    break;
                }

                case 114 /* setDataAllowed */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean allow = _hidl_request.readBool();
                    setDataAllowed(serial, allow);
                    break;
                }

                case 115 /* getHardwareConfig */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getHardwareConfig(serial);
                    break;
                }

                case 116 /* requestIccSimAuthentication */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int authContext = _hidl_request.readInt32();
                    String authData = _hidl_request.readString();
                    String aid = _hidl_request.readString();
                    requestIccSimAuthentication(serial, authContext, authData, aid);
                    break;
                }

                case 117 /* setDataProfile */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    java.util.ArrayList<android.hardware.radio.V1_0.DataProfileInfo> profiles = android.hardware.radio.V1_0.DataProfileInfo.readVectorFromParcel(_hidl_request);
                    boolean isRoaming = _hidl_request.readBool();
                    setDataProfile(serial, profiles, isRoaming);
                    break;
                }

                case 118 /* requestShutdown */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    requestShutdown(serial);
                    break;
                }

                case 119 /* getRadioCapability */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getRadioCapability(serial);
                    break;
                }

                case 120 /* setRadioCapability */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    android.hardware.radio.V1_0.RadioCapability rc = new android.hardware.radio.V1_0.RadioCapability();
                    ((android.hardware.radio.V1_0.RadioCapability) rc).readFromParcel(_hidl_request);
                    setRadioCapability(serial, rc);
                    break;
                }

                case 121 /* startLceService */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int reportInterval = _hidl_request.readInt32();
                    boolean pullMode = _hidl_request.readBool();
                    startLceService(serial, reportInterval, pullMode);
                    break;
                }

                case 122 /* stopLceService */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    stopLceService(serial);
                    break;
                }

                case 123 /* pullLceData */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    pullLceData(serial);
                    break;
                }

                case 124 /* getModemActivityInfo */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getModemActivityInfo(serial);
                    break;
                }

                case 125 /* setAllowedCarriers */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean allAllowed = _hidl_request.readBool();
                    android.hardware.radio.V1_0.CarrierRestrictions carriers = new android.hardware.radio.V1_0.CarrierRestrictions();
                    ((android.hardware.radio.V1_0.CarrierRestrictions) carriers).readFromParcel(_hidl_request);
                    setAllowedCarriers(serial, allAllowed, carriers);
                    break;
                }

                case 126 /* getAllowedCarriers */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    getAllowedCarriers(serial);
                    break;
                }

                case 127 /* sendDeviceState */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int deviceStateType = _hidl_request.readInt32();
                    boolean state = _hidl_request.readBool();
                    sendDeviceState(serial, deviceStateType, state);
                    break;
                }

                case 128 /* setIndicationFilter */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    int indicationFilter = _hidl_request.readInt32();
                    setIndicationFilter(serial, indicationFilter);
                    break;
                }

                case 129 /* setSimCardPower */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    boolean powerUp = _hidl_request.readBool();
                    setSimCardPower(serial, powerUp);
                    break;
                }

                case 130 /* responseAcknowledgement */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadio.kInterfaceName);

                    responseAcknowledgement();
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
