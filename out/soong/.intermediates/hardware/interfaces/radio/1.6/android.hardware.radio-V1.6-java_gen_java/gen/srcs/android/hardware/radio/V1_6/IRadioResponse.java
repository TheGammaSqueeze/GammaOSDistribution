package android.hardware.radio.V1_6;

/**
 * Interface declaring response functions to solicited radio requests.
 */
public interface IRadioResponse extends android.hardware.radio.V1_5.IRadioResponse {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.radio@1.6::IRadioResponse";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IRadioResponse asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IRadioResponse)) {
            return (IRadioResponse)iface;
        }

        IRadioResponse proxy = new IRadioResponse.Proxy(binder);

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
    public static IRadioResponse castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IRadioResponse.asInterface(iface.asBinder());
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
    public static IRadioResponse getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IRadioResponse.asInterface(android.os.HwBinder.getService("android.hardware.radio@1.6::IRadioResponse", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IRadioResponse getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IRadioResponse getService(String serviceName) throws android.os.RemoteException {
        return IRadioResponse.asInterface(android.os.HwBinder.getService("android.hardware.radio@1.6::IRadioResponse", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IRadioResponse getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:RF_HARDWARE_ISSUE
     *   RadioError:NO_RF_CALIBRATION_INFO
     */
    void setRadioPowerResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param dcResponse SetupDataCallResult defined in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE must be returned on both success and failure of setup with the
     *              DataCallResponse.status containing the actual status
     *              For all other errors the DataCallResponse is ignored.
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:OP_NOT_ALLOWED_BEFORE_REG_TO_NW
     *   RadioError:OP_NOT_ALLOWED_DURING_VOICE_CALL
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_RESOURCES if the vendor is unable handle due to resources
     *              are full.
     *   RadioError:SIM_ABSENT
     */
    void setupDataCallResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_6.SetupDataCallResult dcResponse)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param dcResponse List of SetupDataCallResult as defined in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:SIM_ABSENT
     */
    void getDataCallListResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_6.SetupDataCallResult> dcResponse)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param sms Response to sms sent as defined by SendSmsResult in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SMS_SEND_FAIL_RETRY
     *   RadioError:NETWORK_REJECT
     *   RadioError:INVALID_STATE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:INVALID_SMS_FORMAT
     *   RadioError:SYSTEM_ERR
     *   RadioError:ENCODING_ERR
     *   RadioError:INVALID_SMSC_ADDRESS
     *   RadioError:MODEM_ERR
     *   RadioError:NETWORK_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NETWORK_NOT_READY
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     *   RadioError:ACCESS_BARRED
     *   RadioError:BLOCKED_DUE_TO_CALL
     */
    void sendSmsResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_0.SendSmsResult sms)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param sms Response to sms sent as defined by SendSmsResult in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SMS_SEND_FAIL_RETRY
     *   RadioError:NETWORK_REJECT
     *   RadioError:INVALID_STATE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:INVALID_SMS_FORMAT
     *   RadioError:SYSTEM_ERR
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:ENCODING_ERR
     *   RadioError:INVALID_SMSC_ADDRESS
     *   RadioError:MODEM_ERR
     *   RadioError:NETWORK_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NETWORK_NOT_READY
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     *   RadioError:ACCESS_BARRED
     *   RadioError:BLOCKED_DUE_TO_CALL
     */
    void sendSmsExpectMoreResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_0.SendSmsResult sms)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param sms Sms result struct as defined by SendSmsResult in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:SMS_SEND_FAIL_RETRY
     *   RadioError:NETWORK_REJECT
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:INVALID_SMS_FORMAT
     *   RadioError:SYSTEM_ERR
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:MODEM_ERR
     *   RadioError:NETWORK_ERR
     *   RadioError:ENCODING_ERR
     *   RadioError:INVALID_SMSC_ADDRESS
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:ENCODING_ERR
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     *   RadioError:SIMULTANEOUS_SMS_AND_CALL_NOT_ALLOWED
     *   RadioError:ACCESS_BARRED
     *   RadioError:BLOCKED_DUE_TO_CALL
     */
    void sendCdmaSmsResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_0.SendSmsResult sms)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param sms Response to sms sent as defined by SendSmsResult in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SMS_SEND_FAIL_RETRY
     *   RadioError:NETWORK_REJECT
     *   RadioError:INVALID_STATE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:INVALID_SMS_FORMAT
     *   RadioError:SYSTEM_ERR
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:ENCODING_ERR
     *   RadioError:INVALID_SMSC_ADDRESS
     *   RadioError:MODEM_ERR
     *   RadioError:NETWORK_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NETWORK_NOT_READY
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     *   RadioError:SIMULTANEOUS_SMS_AND_CALL_NOT_ALLOWED
     *   RadioError:ACCESS_BARRED
     *   RadioError:BLOCKED_DUE_TO_CALL
     */
    void sendCdmaSmsExpectMoreResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_0.SendSmsResult sms)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:SIM_ERR (indicates a timeout or other issue making the SIM unresponsive)
     *
     * Note that this differs from setSimCardPowerResponse_1_1 in that the response
     * should only be sent once the request from setSimCardPower_1_6 is complete
     * (the SIM has finished powering on or off).
     */
    void setSimCardPowerResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_STATE
     */
    void setNrDualConnectivityStateResponse(android.hardware.radio.V1_6.RadioResponseInfo info)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * @param isEnabled Indicates whether NR dual connectivity is enabled or not, True if enabled
     *        else false.
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    void isNrDualConnectivityEnabledResponse(android.hardware.radio.V1_6.RadioResponseInfo info, boolean isEnabled)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param id The allocated id. On an error, this is set to 0.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_RESOURCES- Indicates that no pdu session ids are available
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    void allocatePduSessionIdResponse(android.hardware.radio.V1_6.RadioResponseInfo info, int id)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_RESOURCES
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    void releasePduSessionIdResponse(android.hardware.radio.V1_6.RadioResponseInfo info)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_RESOURCES
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_CALL_ID
     */
    void startHandoverResponse(android.hardware.radio.V1_6.RadioResponseInfo info)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param dcResponse Attributes of data call
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_RESOURCES
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_CALL_ID
     */
    void cancelHandoverResponse(android.hardware.radio.V1_6.RadioResponseInfo info)
        throws android.os.RemoteException;
    /**
     * Callback of IRadio.setAllowedNetworkTypesBitmap(int, bitfield<RadioAccessFamily>)
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:MODE_NOT_SUPPORTED
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     */
    void setAllowedNetworkTypesBitmapResponse(android.hardware.radio.V1_6.RadioResponseInfo info)
        throws android.os.RemoteException;
    /**
     * Callback of IRadio.getAllowedNetworkTypesBitmap(int, bitfield<RadioAccessFamily>)
     * @param info Response info struct containing response type, serial no. and error
     * @param networkTypeBitmap a 32-bit bitmap of RadioAccessFamily.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:MODE_NOT_SUPPORTED
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     */
    void getAllowedNetworkTypesBitmapResponse(android.hardware.radio.V1_6.RadioResponseInfo info, int networkTypeBitmap)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     *  Valid errors returned:
     *  RadioError:NONE
     *  RadioError:RADIO_NOT_AVAILABLE
     *  RadioError:MODEM_ERR
     *  RadioError:INVALID_ARGUMENTS
     *  RadioError:REQUEST_NOT_SUPPORTED
     */
    void setDataThrottlingResponse(android.hardware.radio.V1_6.RadioResponseInfo info)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param specifiers List of RadioAccessSpecifiers that are scanned.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_ARGUMENTS
     */
    void getSystemSelectionChannelsResponse(android.hardware.radio.V1_6.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_5.RadioAccessSpecifier> specifiers)
        throws android.os.RemoteException;
    /**
     * This is identical to getCellInfoListResponse_1_5 but uses an updated version of CellInfo.
     *
     * @param info Response info struct containing response type, serial no. and error
     * @param cellInfo List of current cell information known to radio
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     */
    void getCellInfoListResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_6.CellInfo> cellInfo)
        throws android.os.RemoteException;
    /**
     * This is identical to getSignalStrengthResponse_1_4 but uses an updated version of
     * SignalStrength.
     *
     * @param signalStrength Current signal strength
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     */
    void getSignalStrengthResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_6.SignalStrength signalStrength)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param voiceRegResponse Current Voice registration response as defined by RegStateResult
     *        in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     */
    void getVoiceRegistrationStateResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_6.RegStateResult voiceRegResponse)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param dataRegResponse Current Data registration response as defined by RegStateResult in
     *        types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NOT_PROVISIONED
     */
    void getDataRegistrationStateResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_6.RegStateResult dataRegResponse)
        throws android.os.RemoteException;
    /**
     * @param calls Current call list
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    void getCurrentCallsResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_6.Call> calls)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param slicingConfig Current slicing configuration
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    void getSlicingConfigResponse(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_6.SlicingConfig slicingConfig)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_SIM_STATE
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     * REQUEST_NOT_SUPPORTED may only be returned on devices that don't support this API,
     * indicated by the HAL capability CAPABILITY_SIM_PHONEBOOK_IN_MODEM.
     */
    void getSimPhonebookRecordsResponse(android.hardware.radio.V1_6.RadioResponseInfo info)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param capacity Response capacity enum indicating response processing status
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_SIM_STATE
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     * REQUEST_NOT_SUPPORTED may only be returned on devices that don't support this API,
     * indicated by the HAL capability CAPABILITY_SIM_PHONEBOOK_IN_MODEM.
     */
    void getSimPhonebookCapacityResponse(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_6.PhonebookCapacity capacity)
        throws android.os.RemoteException;
    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param updatedRecordIndex The index of the updated or inserted record in the phonebook and
     *                           the minimum value is 1
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_SIM_STATE
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:SIM_ERR
     *   RadioError:NO_SUCH_ENTRY
     *   RadioError:NO_RESOURCES
     * REQUEST_NOT_SUPPORTED may only be returned on devices that don't support this API,
     * indicated by the HAL capability CAPABILITY_SIM_PHONEBOOK_IN_MODEM.
     */
    void updateSimPhonebookRecordsResponse(android.hardware.radio.V1_6.RadioResponseInfo info, int updatedRecordIndex)
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

    public static final class Proxy implements IRadioResponse {
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
            return "[class or subclass of " + IRadioResponse.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::radio::V1_0::IRadioResponse follow.
        @Override
        public void getIccCardStatusResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.CardStatus cardStatus)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.CardStatus) cardStatus).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* getIccCardStatusResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void supplyIccPinForAppResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int remainingRetries)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(remainingRetries);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* supplyIccPinForAppResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void supplyIccPukForAppResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int remainingRetries)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(remainingRetries);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* supplyIccPukForAppResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void supplyIccPin2ForAppResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int remainingRetries)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(remainingRetries);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* supplyIccPin2ForAppResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void supplyIccPuk2ForAppResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int remainingRetries)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(remainingRetries);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* supplyIccPuk2ForAppResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void changeIccPinForAppResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int remainingRetries)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(remainingRetries);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* changeIccPinForAppResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void changeIccPin2ForAppResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int remainingRetries)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(remainingRetries);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* changeIccPin2ForAppResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void supplyNetworkDepersonalizationResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int remainingRetries)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(remainingRetries);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* supplyNetworkDepersonalizationResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCurrentCallsResponse(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_0.Call> calls)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_0.Call.writeVectorToParcel(_hidl_request, calls);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* getCurrentCallsResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void dialResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* dialResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getIMSIForAppResponse(android.hardware.radio.V1_0.RadioResponseInfo info, String imsi)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeString(imsi);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* getIMSIForAppResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void hangupConnectionResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* hangupConnectionResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void hangupWaitingOrBackgroundResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* hangupWaitingOrBackgroundResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void hangupForegroundResumeBackgroundResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* hangupForegroundResumeBackgroundResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void switchWaitingOrHoldingAndActiveResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* switchWaitingOrHoldingAndActiveResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void conferenceResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* conferenceResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void rejectCallResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* rejectCallResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getLastCallFailCauseResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.LastCallFailCauseInfo failCauseinfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.LastCallFailCauseInfo) failCauseinfo).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(18 /* getLastCallFailCauseResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSignalStrengthResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.SignalStrength sigStrength)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.SignalStrength) sigStrength).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(19 /* getSignalStrengthResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getVoiceRegistrationStateResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.VoiceRegStateResult voiceRegResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.VoiceRegStateResult) voiceRegResponse).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(20 /* getVoiceRegistrationStateResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDataRegistrationStateResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.DataRegStateResult dataRegResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.DataRegStateResult) dataRegResponse).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(21 /* getDataRegistrationStateResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getOperatorResponse(android.hardware.radio.V1_0.RadioResponseInfo info, String longName, String shortName, String numeric)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeString(longName);
            _hidl_request.writeString(shortName);
            _hidl_request.writeString(numeric);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(22 /* getOperatorResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setRadioPowerResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(23 /* setRadioPowerResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendDtmfResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(24 /* sendDtmfResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendSmsResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.SendSmsResult sms)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.SendSmsResult) sms).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(25 /* sendSmsResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendSMSExpectMoreResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.SendSmsResult sms)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.SendSmsResult) sms).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(26 /* sendSMSExpectMoreResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setupDataCallResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.SetupDataCallResult dcResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.SetupDataCallResult) dcResponse).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(27 /* setupDataCallResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void iccIOForAppResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.IccIoResult iccIo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.IccIoResult) iccIo).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(28 /* iccIOForAppResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendUssdResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(29 /* sendUssdResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cancelPendingUssdResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(30 /* cancelPendingUssdResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getClirResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int n, int m)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(n);
            _hidl_request.writeInt32(m);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(31 /* getClirResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setClirResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(32 /* setClirResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCallForwardStatusResponse(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_0.CallForwardInfo> callForwardInfos)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_0.CallForwardInfo.writeVectorToParcel(_hidl_request, callForwardInfos);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(33 /* getCallForwardStatusResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setCallForwardResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(34 /* setCallForwardResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCallWaitingResponse(android.hardware.radio.V1_0.RadioResponseInfo info, boolean enable, int serviceClass)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeBool(enable);
            _hidl_request.writeInt32(serviceClass);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(35 /* getCallWaitingResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setCallWaitingResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(36 /* setCallWaitingResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void acknowledgeLastIncomingGsmSmsResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(37 /* acknowledgeLastIncomingGsmSmsResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void acceptCallResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(38 /* acceptCallResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void deactivateDataCallResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(39 /* deactivateDataCallResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getFacilityLockForAppResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int response)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(response);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(40 /* getFacilityLockForAppResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setFacilityLockForAppResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int retry)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(retry);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(41 /* setFacilityLockForAppResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setBarringPasswordResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(42 /* setBarringPasswordResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getNetworkSelectionModeResponse(android.hardware.radio.V1_0.RadioResponseInfo info, boolean manual)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeBool(manual);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(43 /* getNetworkSelectionModeResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setNetworkSelectionModeAutomaticResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(44 /* setNetworkSelectionModeAutomaticResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setNetworkSelectionModeManualResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(45 /* setNetworkSelectionModeManualResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getAvailableNetworksResponse(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_0.OperatorInfo> networkInfos)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_0.OperatorInfo.writeVectorToParcel(_hidl_request, networkInfos);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(46 /* getAvailableNetworksResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void startDtmfResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(47 /* startDtmfResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void stopDtmfResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(48 /* stopDtmfResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getBasebandVersionResponse(android.hardware.radio.V1_0.RadioResponseInfo info, String version)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeString(version);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(49 /* getBasebandVersionResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void separateConnectionResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(50 /* separateConnectionResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setMuteResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(51 /* setMuteResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getMuteResponse(android.hardware.radio.V1_0.RadioResponseInfo info, boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(52 /* getMuteResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getClipResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(status);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(53 /* getClipResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDataCallListResponse(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_0.SetupDataCallResult> dcResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_0.SetupDataCallResult.writeVectorToParcel(_hidl_request, dcResponse);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(54 /* getDataCallListResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setSuppServiceNotificationsResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(55 /* setSuppServiceNotificationsResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void writeSmsToSimResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int index)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(index);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(56 /* writeSmsToSimResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void deleteSmsOnSimResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(57 /* deleteSmsOnSimResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setBandModeResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(58 /* setBandModeResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getAvailableBandModesResponse(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<Integer> bandModes)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32Vector(bandModes);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(59 /* getAvailableBandModesResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendEnvelopeResponse(android.hardware.radio.V1_0.RadioResponseInfo info, String commandResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeString(commandResponse);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(60 /* sendEnvelopeResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendTerminalResponseToSimResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(61 /* sendTerminalResponseToSimResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void handleStkCallSetupRequestFromSimResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(62 /* handleStkCallSetupRequestFromSimResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void explicitCallTransferResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(63 /* explicitCallTransferResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setPreferredNetworkTypeResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(64 /* setPreferredNetworkTypeResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getPreferredNetworkTypeResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int nwType)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(nwType);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(65 /* getPreferredNetworkTypeResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getNeighboringCidsResponse(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_0.NeighboringCell> cells)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_0.NeighboringCell.writeVectorToParcel(_hidl_request, cells);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(66 /* getNeighboringCidsResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setLocationUpdatesResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(67 /* setLocationUpdatesResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setCdmaSubscriptionSourceResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(68 /* setCdmaSubscriptionSourceResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setCdmaRoamingPreferenceResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(69 /* setCdmaRoamingPreferenceResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCdmaRoamingPreferenceResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(type);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(70 /* getCdmaRoamingPreferenceResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setTTYModeResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(71 /* setTTYModeResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getTTYModeResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int mode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(mode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(72 /* getTTYModeResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setPreferredVoicePrivacyResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(73 /* setPreferredVoicePrivacyResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getPreferredVoicePrivacyResponse(android.hardware.radio.V1_0.RadioResponseInfo info, boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(74 /* getPreferredVoicePrivacyResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendCDMAFeatureCodeResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(75 /* sendCDMAFeatureCodeResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendBurstDtmfResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(76 /* sendBurstDtmfResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendCdmaSmsResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.SendSmsResult sms)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.SendSmsResult) sms).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(77 /* sendCdmaSmsResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void acknowledgeLastIncomingCdmaSmsResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(78 /* acknowledgeLastIncomingCdmaSmsResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getGsmBroadcastConfigResponse(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_0.GsmBroadcastSmsConfigInfo> configs)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_0.GsmBroadcastSmsConfigInfo.writeVectorToParcel(_hidl_request, configs);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(79 /* getGsmBroadcastConfigResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setGsmBroadcastConfigResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(80 /* setGsmBroadcastConfigResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setGsmBroadcastActivationResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(81 /* setGsmBroadcastActivationResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCdmaBroadcastConfigResponse(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_0.CdmaBroadcastSmsConfigInfo> configs)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_0.CdmaBroadcastSmsConfigInfo.writeVectorToParcel(_hidl_request, configs);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(82 /* getCdmaBroadcastConfigResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setCdmaBroadcastConfigResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(83 /* setCdmaBroadcastConfigResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setCdmaBroadcastActivationResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(84 /* setCdmaBroadcastActivationResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCDMASubscriptionResponse(android.hardware.radio.V1_0.RadioResponseInfo info, String mdn, String hSid, String hNid, String min, String prl)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeString(mdn);
            _hidl_request.writeString(hSid);
            _hidl_request.writeString(hNid);
            _hidl_request.writeString(min);
            _hidl_request.writeString(prl);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(85 /* getCDMASubscriptionResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void writeSmsToRuimResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int index)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(index);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(86 /* writeSmsToRuimResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void deleteSmsOnRuimResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(87 /* deleteSmsOnRuimResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDeviceIdentityResponse(android.hardware.radio.V1_0.RadioResponseInfo info, String imei, String imeisv, String esn, String meid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeString(imei);
            _hidl_request.writeString(imeisv);
            _hidl_request.writeString(esn);
            _hidl_request.writeString(meid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(88 /* getDeviceIdentityResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void exitEmergencyCallbackModeResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(89 /* exitEmergencyCallbackModeResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSmscAddressResponse(android.hardware.radio.V1_0.RadioResponseInfo info, String smsc)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeString(smsc);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(90 /* getSmscAddressResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setSmscAddressResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(91 /* setSmscAddressResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void reportSmsMemoryStatusResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(92 /* reportSmsMemoryStatusResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void reportStkServiceIsRunningResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(93 /* reportStkServiceIsRunningResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCdmaSubscriptionSourceResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int source)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(source);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(94 /* getCdmaSubscriptionSourceResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void requestIsimAuthenticationResponse(android.hardware.radio.V1_0.RadioResponseInfo info, String response)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeString(response);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(95 /* requestIsimAuthenticationResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void acknowledgeIncomingGsmSmsWithPduResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(96 /* acknowledgeIncomingGsmSmsWithPduResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendEnvelopeWithStatusResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.IccIoResult iccIo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.IccIoResult) iccIo).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(97 /* sendEnvelopeWithStatusResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getVoiceRadioTechnologyResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int rat)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(rat);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(98 /* getVoiceRadioTechnologyResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCellInfoListResponse(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_0.CellInfo> cellInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_0.CellInfo.writeVectorToParcel(_hidl_request, cellInfo);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(99 /* getCellInfoListResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setCellInfoListRateResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(100 /* setCellInfoListRateResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setInitialAttachApnResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(101 /* setInitialAttachApnResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getImsRegistrationStateResponse(android.hardware.radio.V1_0.RadioResponseInfo info, boolean isRegistered, int ratFamily)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeBool(isRegistered);
            _hidl_request.writeInt32(ratFamily);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(102 /* getImsRegistrationStateResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendImsSmsResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.SendSmsResult sms)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.SendSmsResult) sms).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(103 /* sendImsSmsResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void iccTransmitApduBasicChannelResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.IccIoResult result)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.IccIoResult) result).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(104 /* iccTransmitApduBasicChannelResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void iccOpenLogicalChannelResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int channelId, java.util.ArrayList<Byte> selectResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(channelId);
            _hidl_request.writeInt8Vector(selectResponse);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(105 /* iccOpenLogicalChannelResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void iccCloseLogicalChannelResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(106 /* iccCloseLogicalChannelResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void iccTransmitApduLogicalChannelResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.IccIoResult result)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.IccIoResult) result).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(107 /* iccTransmitApduLogicalChannelResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void nvReadItemResponse(android.hardware.radio.V1_0.RadioResponseInfo info, String result)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeString(result);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(108 /* nvReadItemResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void nvWriteItemResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(109 /* nvWriteItemResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void nvWriteCdmaPrlResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(110 /* nvWriteCdmaPrlResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void nvResetConfigResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(111 /* nvResetConfigResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setUiccSubscriptionResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(112 /* setUiccSubscriptionResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setDataAllowedResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(113 /* setDataAllowedResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getHardwareConfigResponse(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_0.HardwareConfig> config)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_0.HardwareConfig.writeVectorToParcel(_hidl_request, config);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(114 /* getHardwareConfigResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void requestIccSimAuthenticationResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.IccIoResult result)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.IccIoResult) result).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(115 /* requestIccSimAuthenticationResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setDataProfileResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(116 /* setDataProfileResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void requestShutdownResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(117 /* requestShutdownResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getRadioCapabilityResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.RadioCapability rc)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.RadioCapability) rc).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(118 /* getRadioCapabilityResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setRadioCapabilityResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.RadioCapability rc)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.RadioCapability) rc).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(119 /* setRadioCapabilityResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void startLceServiceResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.LceStatusInfo statusInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.LceStatusInfo) statusInfo).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(120 /* startLceServiceResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void stopLceServiceResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.LceStatusInfo statusInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.LceStatusInfo) statusInfo).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(121 /* stopLceServiceResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void pullLceDataResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.LceDataInfo lceInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.LceDataInfo) lceInfo).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(122 /* pullLceDataResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getModemActivityInfoResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.ActivityStatsInfo activityInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.ActivityStatsInfo) activityInfo).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(123 /* getModemActivityInfoResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setAllowedCarriersResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int numAllowed)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(numAllowed);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(124 /* setAllowedCarriersResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getAllowedCarriersResponse(android.hardware.radio.V1_0.RadioResponseInfo info, boolean allAllowed, android.hardware.radio.V1_0.CarrierRestrictions carriers)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeBool(allAllowed);
            ((android.hardware.radio.V1_0.CarrierRestrictions) carriers).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(125 /* getAllowedCarriersResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendDeviceStateResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(126 /* sendDeviceStateResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setIndicationFilterResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(127 /* setIndicationFilterResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setSimCardPowerResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(128 /* setSimCardPowerResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void acknowledgeRequest(int serial)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);
            _hidl_request.writeInt32(serial);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(129 /* acknowledgeRequest */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::radio::V1_1::IRadioResponse follow.
        @Override
        public void setCarrierInfoForImsiEncryptionResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_1.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(130 /* setCarrierInfoForImsiEncryptionResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setSimCardPowerResponse_1_1(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_1.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(131 /* setSimCardPowerResponse_1_1 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void startNetworkScanResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_1.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(132 /* startNetworkScanResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void stopNetworkScanResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_1.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(133 /* stopNetworkScanResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void startKeepaliveResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_1.KeepaliveStatus status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_1.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_1.KeepaliveStatus) status).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(134 /* startKeepaliveResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void stopKeepaliveResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_1.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(135 /* stopKeepaliveResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::radio::V1_2::IRadioResponse follow.
        @Override
        public void getCellInfoListResponse_1_2(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_2.CellInfo> cellInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_2.CellInfo.writeVectorToParcel(_hidl_request, cellInfo);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(136 /* getCellInfoListResponse_1_2 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getIccCardStatusResponse_1_2(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_2.CardStatus cardStatus)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_2.CardStatus) cardStatus).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(137 /* getIccCardStatusResponse_1_2 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setSignalStrengthReportingCriteriaResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(138 /* setSignalStrengthReportingCriteriaResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setLinkCapacityReportingCriteriaResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(139 /* setLinkCapacityReportingCriteriaResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCurrentCallsResponse_1_2(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_2.Call> calls)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_2.Call.writeVectorToParcel(_hidl_request, calls);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(140 /* getCurrentCallsResponse_1_2 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSignalStrengthResponse_1_2(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_2.SignalStrength signalStrength)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_2.SignalStrength) signalStrength).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(141 /* getSignalStrengthResponse_1_2 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getVoiceRegistrationStateResponse_1_2(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_2.VoiceRegStateResult voiceRegResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_2.VoiceRegStateResult) voiceRegResponse).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(142 /* getVoiceRegistrationStateResponse_1_2 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDataRegistrationStateResponse_1_2(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_2.DataRegStateResult dataRegResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_2.DataRegStateResult) dataRegResponse).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(143 /* getDataRegistrationStateResponse_1_2 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::radio::V1_3::IRadioResponse follow.
        @Override
        public void setSystemSelectionChannelsResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_3.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(144 /* setSystemSelectionChannelsResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void enableModemResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_3.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(145 /* enableModemResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getModemStackStatusResponse(android.hardware.radio.V1_0.RadioResponseInfo info, boolean isEnabled)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_3.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeBool(isEnabled);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(146 /* getModemStackStatusResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::radio::V1_4::IRadioResponse follow.
        @Override
        public void emergencyDialResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(147 /* emergencyDialResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void startNetworkScanResponse_1_4(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(148 /* startNetworkScanResponse_1_4 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCellInfoListResponse_1_4(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_4.CellInfo> cellInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_4.CellInfo.writeVectorToParcel(_hidl_request, cellInfo);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(149 /* getCellInfoListResponse_1_4 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDataRegistrationStateResponse_1_4(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_4.DataRegStateResult dataRegResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_4.DataRegStateResult) dataRegResponse).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(150 /* getDataRegistrationStateResponse_1_4 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getIccCardStatusResponse_1_4(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_4.CardStatus cardStatus)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_4.CardStatus) cardStatus).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(151 /* getIccCardStatusResponse_1_4 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getPreferredNetworkTypeBitmapResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int networkTypeBitmap)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(networkTypeBitmap);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(152 /* getPreferredNetworkTypeBitmapResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setPreferredNetworkTypeBitmapResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(153 /* setPreferredNetworkTypeBitmapResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDataCallListResponse_1_4(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_4.SetupDataCallResult> dcResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_4.SetupDataCallResult.writeVectorToParcel(_hidl_request, dcResponse);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(154 /* getDataCallListResponse_1_4 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setupDataCallResponse_1_4(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_4.SetupDataCallResult dcResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_4.SetupDataCallResult) dcResponse).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(155 /* setupDataCallResponse_1_4 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setAllowedCarriersResponse_1_4(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(156 /* setAllowedCarriersResponse_1_4 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getAllowedCarriersResponse_1_4(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_4.CarrierRestrictionsWithPriority carriers, int multiSimPolicy)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_4.CarrierRestrictionsWithPriority) carriers).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(multiSimPolicy);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(157 /* getAllowedCarriersResponse_1_4 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSignalStrengthResponse_1_4(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_4.SignalStrength signalStrength)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_4.SignalStrength) signalStrength).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(158 /* getSignalStrengthResponse_1_4 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::radio::V1_5::IRadioResponse follow.
        @Override
        public void setSignalStrengthReportingCriteriaResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(159 /* setSignalStrengthReportingCriteriaResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setLinkCapacityReportingCriteriaResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(160 /* setLinkCapacityReportingCriteriaResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void enableUiccApplicationsResponse(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(161 /* enableUiccApplicationsResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void areUiccApplicationsEnabledResponse(android.hardware.radio.V1_0.RadioResponseInfo info, boolean enabled)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeBool(enabled);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(162 /* areUiccApplicationsEnabledResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setSystemSelectionChannelsResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(163 /* setSystemSelectionChannelsResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void startNetworkScanResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(164 /* startNetworkScanResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setupDataCallResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_5.SetupDataCallResult dcResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_5.SetupDataCallResult) dcResponse).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(165 /* setupDataCallResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDataCallListResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_5.SetupDataCallResult> dcResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_5.SetupDataCallResult.writeVectorToParcel(_hidl_request, dcResponse);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(166 /* getDataCallListResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setInitialAttachApnResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(167 /* setInitialAttachApnResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setDataProfileResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(168 /* setDataProfileResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setRadioPowerResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(169 /* setRadioPowerResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setIndicationFilterResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(170 /* setIndicationFilterResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getBarringInfoResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_5.CellIdentity cellIdentity, java.util.ArrayList<android.hardware.radio.V1_5.BarringInfo> barringInfos)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_5.CellIdentity) cellIdentity).writeToParcel(_hidl_request);
            android.hardware.radio.V1_5.BarringInfo.writeVectorToParcel(_hidl_request, barringInfos);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(171 /* getBarringInfoResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getVoiceRegistrationStateResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_5.RegStateResult voiceRegResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_5.RegStateResult) voiceRegResponse).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(172 /* getVoiceRegistrationStateResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDataRegistrationStateResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_5.RegStateResult dataRegResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_5.RegStateResult) dataRegResponse).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(173 /* getDataRegistrationStateResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCellInfoListResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_5.CellInfo> cellInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_5.CellInfo.writeVectorToParcel(_hidl_request, cellInfo);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(174 /* getCellInfoListResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setNetworkSelectionModeManualResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(175 /* setNetworkSelectionModeManualResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendCdmaSmsExpectMoreResponse(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_0.SendSmsResult sms)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.SendSmsResult) sms).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(176 /* sendCdmaSmsExpectMoreResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void supplySimDepersonalizationResponse(android.hardware.radio.V1_0.RadioResponseInfo info, int persoType, int remainingRetries)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(persoType);
            _hidl_request.writeInt32(remainingRetries);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(177 /* supplySimDepersonalizationResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getIccCardStatusResponse_1_5(android.hardware.radio.V1_0.RadioResponseInfo info, android.hardware.radio.V1_5.CardStatus cardStatus)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_0.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_5.CardStatus) cardStatus).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(178 /* getIccCardStatusResponse_1_5 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::radio::V1_6::IRadioResponse follow.
        @Override
        public void setRadioPowerResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(179 /* setRadioPowerResponse_1_6 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setupDataCallResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_6.SetupDataCallResult dcResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_6.SetupDataCallResult) dcResponse).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(180 /* setupDataCallResponse_1_6 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDataCallListResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_6.SetupDataCallResult> dcResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_6.SetupDataCallResult.writeVectorToParcel(_hidl_request, dcResponse);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(181 /* getDataCallListResponse_1_6 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendSmsResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_0.SendSmsResult sms)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.SendSmsResult) sms).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(182 /* sendSmsResponse_1_6 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendSmsExpectMoreResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_0.SendSmsResult sms)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.SendSmsResult) sms).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(183 /* sendSmsExpectMoreResponse_1_6 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendCdmaSmsResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_0.SendSmsResult sms)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.SendSmsResult) sms).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(184 /* sendCdmaSmsResponse_1_6 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void sendCdmaSmsExpectMoreResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_0.SendSmsResult sms)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_0.SendSmsResult) sms).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(185 /* sendCdmaSmsExpectMoreResponse_1_6 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setSimCardPowerResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(186 /* setSimCardPowerResponse_1_6 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setNrDualConnectivityStateResponse(android.hardware.radio.V1_6.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(187 /* setNrDualConnectivityStateResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void isNrDualConnectivityEnabledResponse(android.hardware.radio.V1_6.RadioResponseInfo info, boolean isEnabled)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeBool(isEnabled);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(188 /* isNrDualConnectivityEnabledResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void allocatePduSessionIdResponse(android.hardware.radio.V1_6.RadioResponseInfo info, int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(189 /* allocatePduSessionIdResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void releasePduSessionIdResponse(android.hardware.radio.V1_6.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(190 /* releasePduSessionIdResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void startHandoverResponse(android.hardware.radio.V1_6.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(191 /* startHandoverResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void cancelHandoverResponse(android.hardware.radio.V1_6.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(192 /* cancelHandoverResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setAllowedNetworkTypesBitmapResponse(android.hardware.radio.V1_6.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(193 /* setAllowedNetworkTypesBitmapResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getAllowedNetworkTypesBitmapResponse(android.hardware.radio.V1_6.RadioResponseInfo info, int networkTypeBitmap)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(networkTypeBitmap);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(194 /* getAllowedNetworkTypesBitmapResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setDataThrottlingResponse(android.hardware.radio.V1_6.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(195 /* setDataThrottlingResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSystemSelectionChannelsResponse(android.hardware.radio.V1_6.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_5.RadioAccessSpecifier> specifiers)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_5.RadioAccessSpecifier.writeVectorToParcel(_hidl_request, specifiers);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(196 /* getSystemSelectionChannelsResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCellInfoListResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_6.CellInfo> cellInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_6.CellInfo.writeVectorToParcel(_hidl_request, cellInfo);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(197 /* getCellInfoListResponse_1_6 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSignalStrengthResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_6.SignalStrength signalStrength)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_6.SignalStrength) signalStrength).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(198 /* getSignalStrengthResponse_1_6 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getVoiceRegistrationStateResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_6.RegStateResult voiceRegResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_6.RegStateResult) voiceRegResponse).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(199 /* getVoiceRegistrationStateResponse_1_6 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDataRegistrationStateResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_6.RegStateResult dataRegResponse)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_6.RegStateResult) dataRegResponse).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(200 /* getDataRegistrationStateResponse_1_6 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCurrentCallsResponse_1_6(android.hardware.radio.V1_6.RadioResponseInfo info, java.util.ArrayList<android.hardware.radio.V1_6.Call> calls)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            android.hardware.radio.V1_6.Call.writeVectorToParcel(_hidl_request, calls);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(201 /* getCurrentCallsResponse_1_6 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSlicingConfigResponse(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_6.SlicingConfig slicingConfig)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_6.SlicingConfig) slicingConfig).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(202 /* getSlicingConfigResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSimPhonebookRecordsResponse(android.hardware.radio.V1_6.RadioResponseInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(203 /* getSimPhonebookRecordsResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSimPhonebookCapacityResponse(android.hardware.radio.V1_6.RadioResponseInfo info, android.hardware.radio.V1_6.PhonebookCapacity capacity)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            ((android.hardware.radio.V1_6.PhonebookCapacity) capacity).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(204 /* getSimPhonebookCapacityResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void updateSimPhonebookRecordsResponse(android.hardware.radio.V1_6.RadioResponseInfo info, int updatedRecordIndex)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);
            ((android.hardware.radio.V1_6.RadioResponseInfo) info).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(updatedRecordIndex);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(205 /* updateSimPhonebookRecordsResponse */, _hidl_request, _hidl_reply, 1 /* oneway */);
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

    public static abstract class Stub extends android.os.HwBinder implements IRadioResponse {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.radio.V1_6.IRadioResponse.kInterfaceName,
                    android.hardware.radio.V1_5.IRadioResponse.kInterfaceName,
                    android.hardware.radio.V1_4.IRadioResponse.kInterfaceName,
                    android.hardware.radio.V1_3.IRadioResponse.kInterfaceName,
                    android.hardware.radio.V1_2.IRadioResponse.kInterfaceName,
                    android.hardware.radio.V1_1.IRadioResponse.kInterfaceName,
                    android.hardware.radio.V1_0.IRadioResponse.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.radio.V1_6.IRadioResponse.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{68,67,-11,-59,-9,-119,-41,122,-76,-111,-86,-44,-49,70,115,-47,49,-69,-92,80,20,-42,-69,72,22,-120,-116,-70,-61,122,-88,-63} /* 4443f5c5f789d77ab491aad4cf4673d131bba45014d6bb4816888cbac37aa8c1 */,
                    new byte[/* 32 */]{-72,9,25,57,112,-87,28,-90,55,-92,-80,24,71,103,49,86,1,-45,46,62,-13,-43,-103,47,-5,-57,-88,-47,74,20,-16,21} /* b809193970a91ca637a4b0184767315601d32e3ef3d5992ffbc7a8d14a14f015 */,
                    new byte[/* 32 */]{12,-64,-35,-121,-58,52,-86,-45,109,125,-14,43,40,50,-125,-98,-9,-34,-41,25,9,-37,-51,-31,28,-3,-42,-99,-64,-36,82,-72} /* 0cc0dd87c634aad36d7df22b2832839ef7ded71909dbcde11cfdd69dc0dc52b8 */,
                    new byte[/* 32 */]{-11,-5,-28,-14,-118,-98,52,107,-29,96,99,-20,-92,-26,-56,100,17,74,26,111,-74,72,-124,-37,3,-3,-40,37,121,26,-39,-72} /* f5fbe4f28a9e346be36063eca4e6c864114a1a6fb64884db03fdd825791ad9b8 */,
                    new byte[/* 32 */]{-38,-116,106,-23,-111,-58,-92,-78,-124,-52,110,68,83,50,-32,100,-30,-114,-24,-96,-108,-126,-19,90,-1,-7,-47,89,-20,102,-108,-73} /* da8c6ae991c6a4b284cc6e445332e064e28ee8a09482ed5afff9d159ec6694b7 */,
                    new byte[/* 32 */]{0,54,107,47,-120,-7,-20,36,88,1,73,114,-109,-126,112,-56,65,61,74,-77,3,33,-114,55,-65,58,-35,43,-114,107,-126,-102} /* 00366b2f88f9ec2458014972938270c8413d4ab303218e37bf3add2b8e6b829a */,
                    new byte[/* 32 */]{-68,60,-116,35,48,-123,-4,-93,-121,-99,-57,75,73,11,-98,91,-63,6,50,88,71,13,59,76,18,-9,-89,75,-14,21,-53,-67} /* bc3c8c233085fca3879dc74b490b9e5bc1063258470d3b4c12f7a74bf215cbbd */,
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
                case 1 /* getIccCardStatusResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.CardStatus cardStatus = new android.hardware.radio.V1_0.CardStatus();
                    ((android.hardware.radio.V1_0.CardStatus) cardStatus).readFromParcel(_hidl_request);
                    getIccCardStatusResponse(info, cardStatus);
                    break;
                }

                case 2 /* supplyIccPinForAppResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int remainingRetries = _hidl_request.readInt32();
                    supplyIccPinForAppResponse(info, remainingRetries);
                    break;
                }

                case 3 /* supplyIccPukForAppResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int remainingRetries = _hidl_request.readInt32();
                    supplyIccPukForAppResponse(info, remainingRetries);
                    break;
                }

                case 4 /* supplyIccPin2ForAppResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int remainingRetries = _hidl_request.readInt32();
                    supplyIccPin2ForAppResponse(info, remainingRetries);
                    break;
                }

                case 5 /* supplyIccPuk2ForAppResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int remainingRetries = _hidl_request.readInt32();
                    supplyIccPuk2ForAppResponse(info, remainingRetries);
                    break;
                }

                case 6 /* changeIccPinForAppResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int remainingRetries = _hidl_request.readInt32();
                    changeIccPinForAppResponse(info, remainingRetries);
                    break;
                }

                case 7 /* changeIccPin2ForAppResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int remainingRetries = _hidl_request.readInt32();
                    changeIccPin2ForAppResponse(info, remainingRetries);
                    break;
                }

                case 8 /* supplyNetworkDepersonalizationResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int remainingRetries = _hidl_request.readInt32();
                    supplyNetworkDepersonalizationResponse(info, remainingRetries);
                    break;
                }

                case 9 /* getCurrentCallsResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_0.Call> calls = android.hardware.radio.V1_0.Call.readVectorFromParcel(_hidl_request);
                    getCurrentCallsResponse(info, calls);
                    break;
                }

                case 10 /* dialResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    dialResponse(info);
                    break;
                }

                case 11 /* getIMSIForAppResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    String imsi = _hidl_request.readString();
                    getIMSIForAppResponse(info, imsi);
                    break;
                }

                case 12 /* hangupConnectionResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    hangupConnectionResponse(info);
                    break;
                }

                case 13 /* hangupWaitingOrBackgroundResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    hangupWaitingOrBackgroundResponse(info);
                    break;
                }

                case 14 /* hangupForegroundResumeBackgroundResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    hangupForegroundResumeBackgroundResponse(info);
                    break;
                }

                case 15 /* switchWaitingOrHoldingAndActiveResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    switchWaitingOrHoldingAndActiveResponse(info);
                    break;
                }

                case 16 /* conferenceResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    conferenceResponse(info);
                    break;
                }

                case 17 /* rejectCallResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    rejectCallResponse(info);
                    break;
                }

                case 18 /* getLastCallFailCauseResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.LastCallFailCauseInfo failCauseinfo = new android.hardware.radio.V1_0.LastCallFailCauseInfo();
                    ((android.hardware.radio.V1_0.LastCallFailCauseInfo) failCauseinfo).readFromParcel(_hidl_request);
                    getLastCallFailCauseResponse(info, failCauseinfo);
                    break;
                }

                case 19 /* getSignalStrengthResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.SignalStrength sigStrength = new android.hardware.radio.V1_0.SignalStrength();
                    ((android.hardware.radio.V1_0.SignalStrength) sigStrength).readFromParcel(_hidl_request);
                    getSignalStrengthResponse(info, sigStrength);
                    break;
                }

                case 20 /* getVoiceRegistrationStateResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.VoiceRegStateResult voiceRegResponse = new android.hardware.radio.V1_0.VoiceRegStateResult();
                    ((android.hardware.radio.V1_0.VoiceRegStateResult) voiceRegResponse).readFromParcel(_hidl_request);
                    getVoiceRegistrationStateResponse(info, voiceRegResponse);
                    break;
                }

                case 21 /* getDataRegistrationStateResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.DataRegStateResult dataRegResponse = new android.hardware.radio.V1_0.DataRegStateResult();
                    ((android.hardware.radio.V1_0.DataRegStateResult) dataRegResponse).readFromParcel(_hidl_request);
                    getDataRegistrationStateResponse(info, dataRegResponse);
                    break;
                }

                case 22 /* getOperatorResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    String longName = _hidl_request.readString();
                    String shortName = _hidl_request.readString();
                    String numeric = _hidl_request.readString();
                    getOperatorResponse(info, longName, shortName, numeric);
                    break;
                }

                case 23 /* setRadioPowerResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setRadioPowerResponse(info);
                    break;
                }

                case 24 /* sendDtmfResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    sendDtmfResponse(info);
                    break;
                }

                case 25 /* sendSmsResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.SendSmsResult sms = new android.hardware.radio.V1_0.SendSmsResult();
                    ((android.hardware.radio.V1_0.SendSmsResult) sms).readFromParcel(_hidl_request);
                    sendSmsResponse(info, sms);
                    break;
                }

                case 26 /* sendSMSExpectMoreResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.SendSmsResult sms = new android.hardware.radio.V1_0.SendSmsResult();
                    ((android.hardware.radio.V1_0.SendSmsResult) sms).readFromParcel(_hidl_request);
                    sendSMSExpectMoreResponse(info, sms);
                    break;
                }

                case 27 /* setupDataCallResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.SetupDataCallResult dcResponse = new android.hardware.radio.V1_0.SetupDataCallResult();
                    ((android.hardware.radio.V1_0.SetupDataCallResult) dcResponse).readFromParcel(_hidl_request);
                    setupDataCallResponse(info, dcResponse);
                    break;
                }

                case 28 /* iccIOForAppResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.IccIoResult iccIo = new android.hardware.radio.V1_0.IccIoResult();
                    ((android.hardware.radio.V1_0.IccIoResult) iccIo).readFromParcel(_hidl_request);
                    iccIOForAppResponse(info, iccIo);
                    break;
                }

                case 29 /* sendUssdResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    sendUssdResponse(info);
                    break;
                }

                case 30 /* cancelPendingUssdResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    cancelPendingUssdResponse(info);
                    break;
                }

                case 31 /* getClirResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int n = _hidl_request.readInt32();
                    int m = _hidl_request.readInt32();
                    getClirResponse(info, n, m);
                    break;
                }

                case 32 /* setClirResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setClirResponse(info);
                    break;
                }

                case 33 /* getCallForwardStatusResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_0.CallForwardInfo> callForwardInfos = android.hardware.radio.V1_0.CallForwardInfo.readVectorFromParcel(_hidl_request);
                    getCallForwardStatusResponse(info, callForwardInfos);
                    break;
                }

                case 34 /* setCallForwardResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setCallForwardResponse(info);
                    break;
                }

                case 35 /* getCallWaitingResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    boolean enable = _hidl_request.readBool();
                    int serviceClass = _hidl_request.readInt32();
                    getCallWaitingResponse(info, enable, serviceClass);
                    break;
                }

                case 36 /* setCallWaitingResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setCallWaitingResponse(info);
                    break;
                }

                case 37 /* acknowledgeLastIncomingGsmSmsResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    acknowledgeLastIncomingGsmSmsResponse(info);
                    break;
                }

                case 38 /* acceptCallResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    acceptCallResponse(info);
                    break;
                }

                case 39 /* deactivateDataCallResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    deactivateDataCallResponse(info);
                    break;
                }

                case 40 /* getFacilityLockForAppResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int response = _hidl_request.readInt32();
                    getFacilityLockForAppResponse(info, response);
                    break;
                }

                case 41 /* setFacilityLockForAppResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int retry = _hidl_request.readInt32();
                    setFacilityLockForAppResponse(info, retry);
                    break;
                }

                case 42 /* setBarringPasswordResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setBarringPasswordResponse(info);
                    break;
                }

                case 43 /* getNetworkSelectionModeResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    boolean manual = _hidl_request.readBool();
                    getNetworkSelectionModeResponse(info, manual);
                    break;
                }

                case 44 /* setNetworkSelectionModeAutomaticResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setNetworkSelectionModeAutomaticResponse(info);
                    break;
                }

                case 45 /* setNetworkSelectionModeManualResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setNetworkSelectionModeManualResponse(info);
                    break;
                }

                case 46 /* getAvailableNetworksResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_0.OperatorInfo> networkInfos = android.hardware.radio.V1_0.OperatorInfo.readVectorFromParcel(_hidl_request);
                    getAvailableNetworksResponse(info, networkInfos);
                    break;
                }

                case 47 /* startDtmfResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    startDtmfResponse(info);
                    break;
                }

                case 48 /* stopDtmfResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    stopDtmfResponse(info);
                    break;
                }

                case 49 /* getBasebandVersionResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    String version = _hidl_request.readString();
                    getBasebandVersionResponse(info, version);
                    break;
                }

                case 50 /* separateConnectionResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    separateConnectionResponse(info);
                    break;
                }

                case 51 /* setMuteResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setMuteResponse(info);
                    break;
                }

                case 52 /* getMuteResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    boolean enable = _hidl_request.readBool();
                    getMuteResponse(info, enable);
                    break;
                }

                case 53 /* getClipResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int status = _hidl_request.readInt32();
                    getClipResponse(info, status);
                    break;
                }

                case 54 /* getDataCallListResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_0.SetupDataCallResult> dcResponse = android.hardware.radio.V1_0.SetupDataCallResult.readVectorFromParcel(_hidl_request);
                    getDataCallListResponse(info, dcResponse);
                    break;
                }

                case 55 /* setSuppServiceNotificationsResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setSuppServiceNotificationsResponse(info);
                    break;
                }

                case 56 /* writeSmsToSimResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int index = _hidl_request.readInt32();
                    writeSmsToSimResponse(info, index);
                    break;
                }

                case 57 /* deleteSmsOnSimResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    deleteSmsOnSimResponse(info);
                    break;
                }

                case 58 /* setBandModeResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setBandModeResponse(info);
                    break;
                }

                case 59 /* getAvailableBandModesResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<Integer> bandModes = _hidl_request.readInt32Vector();
                    getAvailableBandModesResponse(info, bandModes);
                    break;
                }

                case 60 /* sendEnvelopeResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    String commandResponse = _hidl_request.readString();
                    sendEnvelopeResponse(info, commandResponse);
                    break;
                }

                case 61 /* sendTerminalResponseToSimResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    sendTerminalResponseToSimResponse(info);
                    break;
                }

                case 62 /* handleStkCallSetupRequestFromSimResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    handleStkCallSetupRequestFromSimResponse(info);
                    break;
                }

                case 63 /* explicitCallTransferResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    explicitCallTransferResponse(info);
                    break;
                }

                case 64 /* setPreferredNetworkTypeResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setPreferredNetworkTypeResponse(info);
                    break;
                }

                case 65 /* getPreferredNetworkTypeResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int nwType = _hidl_request.readInt32();
                    getPreferredNetworkTypeResponse(info, nwType);
                    break;
                }

                case 66 /* getNeighboringCidsResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_0.NeighboringCell> cells = android.hardware.radio.V1_0.NeighboringCell.readVectorFromParcel(_hidl_request);
                    getNeighboringCidsResponse(info, cells);
                    break;
                }

                case 67 /* setLocationUpdatesResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setLocationUpdatesResponse(info);
                    break;
                }

                case 68 /* setCdmaSubscriptionSourceResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setCdmaSubscriptionSourceResponse(info);
                    break;
                }

                case 69 /* setCdmaRoamingPreferenceResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setCdmaRoamingPreferenceResponse(info);
                    break;
                }

                case 70 /* getCdmaRoamingPreferenceResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int type = _hidl_request.readInt32();
                    getCdmaRoamingPreferenceResponse(info, type);
                    break;
                }

                case 71 /* setTTYModeResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setTTYModeResponse(info);
                    break;
                }

                case 72 /* getTTYModeResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int mode = _hidl_request.readInt32();
                    getTTYModeResponse(info, mode);
                    break;
                }

                case 73 /* setPreferredVoicePrivacyResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setPreferredVoicePrivacyResponse(info);
                    break;
                }

                case 74 /* getPreferredVoicePrivacyResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    boolean enable = _hidl_request.readBool();
                    getPreferredVoicePrivacyResponse(info, enable);
                    break;
                }

                case 75 /* sendCDMAFeatureCodeResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    sendCDMAFeatureCodeResponse(info);
                    break;
                }

                case 76 /* sendBurstDtmfResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    sendBurstDtmfResponse(info);
                    break;
                }

                case 77 /* sendCdmaSmsResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.SendSmsResult sms = new android.hardware.radio.V1_0.SendSmsResult();
                    ((android.hardware.radio.V1_0.SendSmsResult) sms).readFromParcel(_hidl_request);
                    sendCdmaSmsResponse(info, sms);
                    break;
                }

                case 78 /* acknowledgeLastIncomingCdmaSmsResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    acknowledgeLastIncomingCdmaSmsResponse(info);
                    break;
                }

                case 79 /* getGsmBroadcastConfigResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_0.GsmBroadcastSmsConfigInfo> configs = android.hardware.radio.V1_0.GsmBroadcastSmsConfigInfo.readVectorFromParcel(_hidl_request);
                    getGsmBroadcastConfigResponse(info, configs);
                    break;
                }

                case 80 /* setGsmBroadcastConfigResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setGsmBroadcastConfigResponse(info);
                    break;
                }

                case 81 /* setGsmBroadcastActivationResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setGsmBroadcastActivationResponse(info);
                    break;
                }

                case 82 /* getCdmaBroadcastConfigResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_0.CdmaBroadcastSmsConfigInfo> configs = android.hardware.radio.V1_0.CdmaBroadcastSmsConfigInfo.readVectorFromParcel(_hidl_request);
                    getCdmaBroadcastConfigResponse(info, configs);
                    break;
                }

                case 83 /* setCdmaBroadcastConfigResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setCdmaBroadcastConfigResponse(info);
                    break;
                }

                case 84 /* setCdmaBroadcastActivationResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setCdmaBroadcastActivationResponse(info);
                    break;
                }

                case 85 /* getCDMASubscriptionResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    String mdn = _hidl_request.readString();
                    String hSid = _hidl_request.readString();
                    String hNid = _hidl_request.readString();
                    String min = _hidl_request.readString();
                    String prl = _hidl_request.readString();
                    getCDMASubscriptionResponse(info, mdn, hSid, hNid, min, prl);
                    break;
                }

                case 86 /* writeSmsToRuimResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int index = _hidl_request.readInt32();
                    writeSmsToRuimResponse(info, index);
                    break;
                }

                case 87 /* deleteSmsOnRuimResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    deleteSmsOnRuimResponse(info);
                    break;
                }

                case 88 /* getDeviceIdentityResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    String imei = _hidl_request.readString();
                    String imeisv = _hidl_request.readString();
                    String esn = _hidl_request.readString();
                    String meid = _hidl_request.readString();
                    getDeviceIdentityResponse(info, imei, imeisv, esn, meid);
                    break;
                }

                case 89 /* exitEmergencyCallbackModeResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    exitEmergencyCallbackModeResponse(info);
                    break;
                }

                case 90 /* getSmscAddressResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    String smsc = _hidl_request.readString();
                    getSmscAddressResponse(info, smsc);
                    break;
                }

                case 91 /* setSmscAddressResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setSmscAddressResponse(info);
                    break;
                }

                case 92 /* reportSmsMemoryStatusResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    reportSmsMemoryStatusResponse(info);
                    break;
                }

                case 93 /* reportStkServiceIsRunningResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    reportStkServiceIsRunningResponse(info);
                    break;
                }

                case 94 /* getCdmaSubscriptionSourceResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int source = _hidl_request.readInt32();
                    getCdmaSubscriptionSourceResponse(info, source);
                    break;
                }

                case 95 /* requestIsimAuthenticationResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    String response = _hidl_request.readString();
                    requestIsimAuthenticationResponse(info, response);
                    break;
                }

                case 96 /* acknowledgeIncomingGsmSmsWithPduResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    acknowledgeIncomingGsmSmsWithPduResponse(info);
                    break;
                }

                case 97 /* sendEnvelopeWithStatusResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.IccIoResult iccIo = new android.hardware.radio.V1_0.IccIoResult();
                    ((android.hardware.radio.V1_0.IccIoResult) iccIo).readFromParcel(_hidl_request);
                    sendEnvelopeWithStatusResponse(info, iccIo);
                    break;
                }

                case 98 /* getVoiceRadioTechnologyResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int rat = _hidl_request.readInt32();
                    getVoiceRadioTechnologyResponse(info, rat);
                    break;
                }

                case 99 /* getCellInfoListResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_0.CellInfo> cellInfo = android.hardware.radio.V1_0.CellInfo.readVectorFromParcel(_hidl_request);
                    getCellInfoListResponse(info, cellInfo);
                    break;
                }

                case 100 /* setCellInfoListRateResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setCellInfoListRateResponse(info);
                    break;
                }

                case 101 /* setInitialAttachApnResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setInitialAttachApnResponse(info);
                    break;
                }

                case 102 /* getImsRegistrationStateResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    boolean isRegistered = _hidl_request.readBool();
                    int ratFamily = _hidl_request.readInt32();
                    getImsRegistrationStateResponse(info, isRegistered, ratFamily);
                    break;
                }

                case 103 /* sendImsSmsResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.SendSmsResult sms = new android.hardware.radio.V1_0.SendSmsResult();
                    ((android.hardware.radio.V1_0.SendSmsResult) sms).readFromParcel(_hidl_request);
                    sendImsSmsResponse(info, sms);
                    break;
                }

                case 104 /* iccTransmitApduBasicChannelResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.IccIoResult result = new android.hardware.radio.V1_0.IccIoResult();
                    ((android.hardware.radio.V1_0.IccIoResult) result).readFromParcel(_hidl_request);
                    iccTransmitApduBasicChannelResponse(info, result);
                    break;
                }

                case 105 /* iccOpenLogicalChannelResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int channelId = _hidl_request.readInt32();
                    java.util.ArrayList<Byte> selectResponse = _hidl_request.readInt8Vector();
                    iccOpenLogicalChannelResponse(info, channelId, selectResponse);
                    break;
                }

                case 106 /* iccCloseLogicalChannelResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    iccCloseLogicalChannelResponse(info);
                    break;
                }

                case 107 /* iccTransmitApduLogicalChannelResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.IccIoResult result = new android.hardware.radio.V1_0.IccIoResult();
                    ((android.hardware.radio.V1_0.IccIoResult) result).readFromParcel(_hidl_request);
                    iccTransmitApduLogicalChannelResponse(info, result);
                    break;
                }

                case 108 /* nvReadItemResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    String result = _hidl_request.readString();
                    nvReadItemResponse(info, result);
                    break;
                }

                case 109 /* nvWriteItemResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    nvWriteItemResponse(info);
                    break;
                }

                case 110 /* nvWriteCdmaPrlResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    nvWriteCdmaPrlResponse(info);
                    break;
                }

                case 111 /* nvResetConfigResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    nvResetConfigResponse(info);
                    break;
                }

                case 112 /* setUiccSubscriptionResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setUiccSubscriptionResponse(info);
                    break;
                }

                case 113 /* setDataAllowedResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setDataAllowedResponse(info);
                    break;
                }

                case 114 /* getHardwareConfigResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_0.HardwareConfig> config = android.hardware.radio.V1_0.HardwareConfig.readVectorFromParcel(_hidl_request);
                    getHardwareConfigResponse(info, config);
                    break;
                }

                case 115 /* requestIccSimAuthenticationResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.IccIoResult result = new android.hardware.radio.V1_0.IccIoResult();
                    ((android.hardware.radio.V1_0.IccIoResult) result).readFromParcel(_hidl_request);
                    requestIccSimAuthenticationResponse(info, result);
                    break;
                }

                case 116 /* setDataProfileResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setDataProfileResponse(info);
                    break;
                }

                case 117 /* requestShutdownResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    requestShutdownResponse(info);
                    break;
                }

                case 118 /* getRadioCapabilityResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.RadioCapability rc = new android.hardware.radio.V1_0.RadioCapability();
                    ((android.hardware.radio.V1_0.RadioCapability) rc).readFromParcel(_hidl_request);
                    getRadioCapabilityResponse(info, rc);
                    break;
                }

                case 119 /* setRadioCapabilityResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.RadioCapability rc = new android.hardware.radio.V1_0.RadioCapability();
                    ((android.hardware.radio.V1_0.RadioCapability) rc).readFromParcel(_hidl_request);
                    setRadioCapabilityResponse(info, rc);
                    break;
                }

                case 120 /* startLceServiceResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.LceStatusInfo statusInfo = new android.hardware.radio.V1_0.LceStatusInfo();
                    ((android.hardware.radio.V1_0.LceStatusInfo) statusInfo).readFromParcel(_hidl_request);
                    startLceServiceResponse(info, statusInfo);
                    break;
                }

                case 121 /* stopLceServiceResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.LceStatusInfo statusInfo = new android.hardware.radio.V1_0.LceStatusInfo();
                    ((android.hardware.radio.V1_0.LceStatusInfo) statusInfo).readFromParcel(_hidl_request);
                    stopLceServiceResponse(info, statusInfo);
                    break;
                }

                case 122 /* pullLceDataResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.LceDataInfo lceInfo = new android.hardware.radio.V1_0.LceDataInfo();
                    ((android.hardware.radio.V1_0.LceDataInfo) lceInfo).readFromParcel(_hidl_request);
                    pullLceDataResponse(info, lceInfo);
                    break;
                }

                case 123 /* getModemActivityInfoResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.ActivityStatsInfo activityInfo = new android.hardware.radio.V1_0.ActivityStatsInfo();
                    ((android.hardware.radio.V1_0.ActivityStatsInfo) activityInfo).readFromParcel(_hidl_request);
                    getModemActivityInfoResponse(info, activityInfo);
                    break;
                }

                case 124 /* setAllowedCarriersResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int numAllowed = _hidl_request.readInt32();
                    setAllowedCarriersResponse(info, numAllowed);
                    break;
                }

                case 125 /* getAllowedCarriersResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    boolean allAllowed = _hidl_request.readBool();
                    android.hardware.radio.V1_0.CarrierRestrictions carriers = new android.hardware.radio.V1_0.CarrierRestrictions();
                    ((android.hardware.radio.V1_0.CarrierRestrictions) carriers).readFromParcel(_hidl_request);
                    getAllowedCarriersResponse(info, allAllowed, carriers);
                    break;
                }

                case 126 /* sendDeviceStateResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    sendDeviceStateResponse(info);
                    break;
                }

                case 127 /* setIndicationFilterResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setIndicationFilterResponse(info);
                    break;
                }

                case 128 /* setSimCardPowerResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setSimCardPowerResponse(info);
                    break;
                }

                case 129 /* acknowledgeRequest */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_0.IRadioResponse.kInterfaceName);

                    int serial = _hidl_request.readInt32();
                    acknowledgeRequest(serial);
                    break;
                }

                case 130 /* setCarrierInfoForImsiEncryptionResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_1.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setCarrierInfoForImsiEncryptionResponse(info);
                    break;
                }

                case 131 /* setSimCardPowerResponse_1_1 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_1.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setSimCardPowerResponse_1_1(info);
                    break;
                }

                case 132 /* startNetworkScanResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_1.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    startNetworkScanResponse(info);
                    break;
                }

                case 133 /* stopNetworkScanResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_1.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    stopNetworkScanResponse(info);
                    break;
                }

                case 134 /* startKeepaliveResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_1.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_1.KeepaliveStatus status = new android.hardware.radio.V1_1.KeepaliveStatus();
                    ((android.hardware.radio.V1_1.KeepaliveStatus) status).readFromParcel(_hidl_request);
                    startKeepaliveResponse(info, status);
                    break;
                }

                case 135 /* stopKeepaliveResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_1.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    stopKeepaliveResponse(info);
                    break;
                }

                case 136 /* getCellInfoListResponse_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_2.CellInfo> cellInfo = android.hardware.radio.V1_2.CellInfo.readVectorFromParcel(_hidl_request);
                    getCellInfoListResponse_1_2(info, cellInfo);
                    break;
                }

                case 137 /* getIccCardStatusResponse_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_2.CardStatus cardStatus = new android.hardware.radio.V1_2.CardStatus();
                    ((android.hardware.radio.V1_2.CardStatus) cardStatus).readFromParcel(_hidl_request);
                    getIccCardStatusResponse_1_2(info, cardStatus);
                    break;
                }

                case 138 /* setSignalStrengthReportingCriteriaResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setSignalStrengthReportingCriteriaResponse(info);
                    break;
                }

                case 139 /* setLinkCapacityReportingCriteriaResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setLinkCapacityReportingCriteriaResponse(info);
                    break;
                }

                case 140 /* getCurrentCallsResponse_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_2.Call> calls = android.hardware.radio.V1_2.Call.readVectorFromParcel(_hidl_request);
                    getCurrentCallsResponse_1_2(info, calls);
                    break;
                }

                case 141 /* getSignalStrengthResponse_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_2.SignalStrength signalStrength = new android.hardware.radio.V1_2.SignalStrength();
                    ((android.hardware.radio.V1_2.SignalStrength) signalStrength).readFromParcel(_hidl_request);
                    getSignalStrengthResponse_1_2(info, signalStrength);
                    break;
                }

                case 142 /* getVoiceRegistrationStateResponse_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_2.VoiceRegStateResult voiceRegResponse = new android.hardware.radio.V1_2.VoiceRegStateResult();
                    ((android.hardware.radio.V1_2.VoiceRegStateResult) voiceRegResponse).readFromParcel(_hidl_request);
                    getVoiceRegistrationStateResponse_1_2(info, voiceRegResponse);
                    break;
                }

                case 143 /* getDataRegistrationStateResponse_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_2.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_2.DataRegStateResult dataRegResponse = new android.hardware.radio.V1_2.DataRegStateResult();
                    ((android.hardware.radio.V1_2.DataRegStateResult) dataRegResponse).readFromParcel(_hidl_request);
                    getDataRegistrationStateResponse_1_2(info, dataRegResponse);
                    break;
                }

                case 144 /* setSystemSelectionChannelsResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_3.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setSystemSelectionChannelsResponse(info);
                    break;
                }

                case 145 /* enableModemResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_3.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    enableModemResponse(info);
                    break;
                }

                case 146 /* getModemStackStatusResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_3.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    boolean isEnabled = _hidl_request.readBool();
                    getModemStackStatusResponse(info, isEnabled);
                    break;
                }

                case 147 /* emergencyDialResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    emergencyDialResponse(info);
                    break;
                }

                case 148 /* startNetworkScanResponse_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    startNetworkScanResponse_1_4(info);
                    break;
                }

                case 149 /* getCellInfoListResponse_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_4.CellInfo> cellInfo = android.hardware.radio.V1_4.CellInfo.readVectorFromParcel(_hidl_request);
                    getCellInfoListResponse_1_4(info, cellInfo);
                    break;
                }

                case 150 /* getDataRegistrationStateResponse_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_4.DataRegStateResult dataRegResponse = new android.hardware.radio.V1_4.DataRegStateResult();
                    ((android.hardware.radio.V1_4.DataRegStateResult) dataRegResponse).readFromParcel(_hidl_request);
                    getDataRegistrationStateResponse_1_4(info, dataRegResponse);
                    break;
                }

                case 151 /* getIccCardStatusResponse_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_4.CardStatus cardStatus = new android.hardware.radio.V1_4.CardStatus();
                    ((android.hardware.radio.V1_4.CardStatus) cardStatus).readFromParcel(_hidl_request);
                    getIccCardStatusResponse_1_4(info, cardStatus);
                    break;
                }

                case 152 /* getPreferredNetworkTypeBitmapResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int networkTypeBitmap = _hidl_request.readInt32();
                    getPreferredNetworkTypeBitmapResponse(info, networkTypeBitmap);
                    break;
                }

                case 153 /* setPreferredNetworkTypeBitmapResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setPreferredNetworkTypeBitmapResponse(info);
                    break;
                }

                case 154 /* getDataCallListResponse_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_4.SetupDataCallResult> dcResponse = android.hardware.radio.V1_4.SetupDataCallResult.readVectorFromParcel(_hidl_request);
                    getDataCallListResponse_1_4(info, dcResponse);
                    break;
                }

                case 155 /* setupDataCallResponse_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_4.SetupDataCallResult dcResponse = new android.hardware.radio.V1_4.SetupDataCallResult();
                    ((android.hardware.radio.V1_4.SetupDataCallResult) dcResponse).readFromParcel(_hidl_request);
                    setupDataCallResponse_1_4(info, dcResponse);
                    break;
                }

                case 156 /* setAllowedCarriersResponse_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setAllowedCarriersResponse_1_4(info);
                    break;
                }

                case 157 /* getAllowedCarriersResponse_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_4.CarrierRestrictionsWithPriority carriers = new android.hardware.radio.V1_4.CarrierRestrictionsWithPriority();
                    ((android.hardware.radio.V1_4.CarrierRestrictionsWithPriority) carriers).readFromParcel(_hidl_request);
                    int multiSimPolicy = _hidl_request.readInt32();
                    getAllowedCarriersResponse_1_4(info, carriers, multiSimPolicy);
                    break;
                }

                case 158 /* getSignalStrengthResponse_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_4.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_4.SignalStrength signalStrength = new android.hardware.radio.V1_4.SignalStrength();
                    ((android.hardware.radio.V1_4.SignalStrength) signalStrength).readFromParcel(_hidl_request);
                    getSignalStrengthResponse_1_4(info, signalStrength);
                    break;
                }

                case 159 /* setSignalStrengthReportingCriteriaResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setSignalStrengthReportingCriteriaResponse_1_5(info);
                    break;
                }

                case 160 /* setLinkCapacityReportingCriteriaResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setLinkCapacityReportingCriteriaResponse_1_5(info);
                    break;
                }

                case 161 /* enableUiccApplicationsResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    enableUiccApplicationsResponse(info);
                    break;
                }

                case 162 /* areUiccApplicationsEnabledResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    boolean enabled = _hidl_request.readBool();
                    areUiccApplicationsEnabledResponse(info, enabled);
                    break;
                }

                case 163 /* setSystemSelectionChannelsResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setSystemSelectionChannelsResponse_1_5(info);
                    break;
                }

                case 164 /* startNetworkScanResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    startNetworkScanResponse_1_5(info);
                    break;
                }

                case 165 /* setupDataCallResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_5.SetupDataCallResult dcResponse = new android.hardware.radio.V1_5.SetupDataCallResult();
                    ((android.hardware.radio.V1_5.SetupDataCallResult) dcResponse).readFromParcel(_hidl_request);
                    setupDataCallResponse_1_5(info, dcResponse);
                    break;
                }

                case 166 /* getDataCallListResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_5.SetupDataCallResult> dcResponse = android.hardware.radio.V1_5.SetupDataCallResult.readVectorFromParcel(_hidl_request);
                    getDataCallListResponse_1_5(info, dcResponse);
                    break;
                }

                case 167 /* setInitialAttachApnResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setInitialAttachApnResponse_1_5(info);
                    break;
                }

                case 168 /* setDataProfileResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setDataProfileResponse_1_5(info);
                    break;
                }

                case 169 /* setRadioPowerResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setRadioPowerResponse_1_5(info);
                    break;
                }

                case 170 /* setIndicationFilterResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setIndicationFilterResponse_1_5(info);
                    break;
                }

                case 171 /* getBarringInfoResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_5.CellIdentity cellIdentity = new android.hardware.radio.V1_5.CellIdentity();
                    ((android.hardware.radio.V1_5.CellIdentity) cellIdentity).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_5.BarringInfo> barringInfos = android.hardware.radio.V1_5.BarringInfo.readVectorFromParcel(_hidl_request);
                    getBarringInfoResponse(info, cellIdentity, barringInfos);
                    break;
                }

                case 172 /* getVoiceRegistrationStateResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_5.RegStateResult voiceRegResponse = new android.hardware.radio.V1_5.RegStateResult();
                    ((android.hardware.radio.V1_5.RegStateResult) voiceRegResponse).readFromParcel(_hidl_request);
                    getVoiceRegistrationStateResponse_1_5(info, voiceRegResponse);
                    break;
                }

                case 173 /* getDataRegistrationStateResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_5.RegStateResult dataRegResponse = new android.hardware.radio.V1_5.RegStateResult();
                    ((android.hardware.radio.V1_5.RegStateResult) dataRegResponse).readFromParcel(_hidl_request);
                    getDataRegistrationStateResponse_1_5(info, dataRegResponse);
                    break;
                }

                case 174 /* getCellInfoListResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_5.CellInfo> cellInfo = android.hardware.radio.V1_5.CellInfo.readVectorFromParcel(_hidl_request);
                    getCellInfoListResponse_1_5(info, cellInfo);
                    break;
                }

                case 175 /* setNetworkSelectionModeManualResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setNetworkSelectionModeManualResponse_1_5(info);
                    break;
                }

                case 176 /* sendCdmaSmsExpectMoreResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.SendSmsResult sms = new android.hardware.radio.V1_0.SendSmsResult();
                    ((android.hardware.radio.V1_0.SendSmsResult) sms).readFromParcel(_hidl_request);
                    sendCdmaSmsExpectMoreResponse(info, sms);
                    break;
                }

                case 177 /* supplySimDepersonalizationResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int persoType = _hidl_request.readInt32();
                    int remainingRetries = _hidl_request.readInt32();
                    supplySimDepersonalizationResponse(info, persoType, remainingRetries);
                    break;
                }

                case 178 /* getIccCardStatusResponse_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_5.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_0.RadioResponseInfo info = new android.hardware.radio.V1_0.RadioResponseInfo();
                    ((android.hardware.radio.V1_0.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_5.CardStatus cardStatus = new android.hardware.radio.V1_5.CardStatus();
                    ((android.hardware.radio.V1_5.CardStatus) cardStatus).readFromParcel(_hidl_request);
                    getIccCardStatusResponse_1_5(info, cardStatus);
                    break;
                }

                case 179 /* setRadioPowerResponse_1_6 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setRadioPowerResponse_1_6(info);
                    break;
                }

                case 180 /* setupDataCallResponse_1_6 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_6.SetupDataCallResult dcResponse = new android.hardware.radio.V1_6.SetupDataCallResult();
                    ((android.hardware.radio.V1_6.SetupDataCallResult) dcResponse).readFromParcel(_hidl_request);
                    setupDataCallResponse_1_6(info, dcResponse);
                    break;
                }

                case 181 /* getDataCallListResponse_1_6 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_6.SetupDataCallResult> dcResponse = android.hardware.radio.V1_6.SetupDataCallResult.readVectorFromParcel(_hidl_request);
                    getDataCallListResponse_1_6(info, dcResponse);
                    break;
                }

                case 182 /* sendSmsResponse_1_6 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.SendSmsResult sms = new android.hardware.radio.V1_0.SendSmsResult();
                    ((android.hardware.radio.V1_0.SendSmsResult) sms).readFromParcel(_hidl_request);
                    sendSmsResponse_1_6(info, sms);
                    break;
                }

                case 183 /* sendSmsExpectMoreResponse_1_6 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.SendSmsResult sms = new android.hardware.radio.V1_0.SendSmsResult();
                    ((android.hardware.radio.V1_0.SendSmsResult) sms).readFromParcel(_hidl_request);
                    sendSmsExpectMoreResponse_1_6(info, sms);
                    break;
                }

                case 184 /* sendCdmaSmsResponse_1_6 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.SendSmsResult sms = new android.hardware.radio.V1_0.SendSmsResult();
                    ((android.hardware.radio.V1_0.SendSmsResult) sms).readFromParcel(_hidl_request);
                    sendCdmaSmsResponse_1_6(info, sms);
                    break;
                }

                case 185 /* sendCdmaSmsExpectMoreResponse_1_6 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_0.SendSmsResult sms = new android.hardware.radio.V1_0.SendSmsResult();
                    ((android.hardware.radio.V1_0.SendSmsResult) sms).readFromParcel(_hidl_request);
                    sendCdmaSmsExpectMoreResponse_1_6(info, sms);
                    break;
                }

                case 186 /* setSimCardPowerResponse_1_6 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setSimCardPowerResponse_1_6(info);
                    break;
                }

                case 187 /* setNrDualConnectivityStateResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setNrDualConnectivityStateResponse(info);
                    break;
                }

                case 188 /* isNrDualConnectivityEnabledResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    boolean isEnabled = _hidl_request.readBool();
                    isNrDualConnectivityEnabledResponse(info, isEnabled);
                    break;
                }

                case 189 /* allocatePduSessionIdResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int id = _hidl_request.readInt32();
                    allocatePduSessionIdResponse(info, id);
                    break;
                }

                case 190 /* releasePduSessionIdResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    releasePduSessionIdResponse(info);
                    break;
                }

                case 191 /* startHandoverResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    startHandoverResponse(info);
                    break;
                }

                case 192 /* cancelHandoverResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    cancelHandoverResponse(info);
                    break;
                }

                case 193 /* setAllowedNetworkTypesBitmapResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setAllowedNetworkTypesBitmapResponse(info);
                    break;
                }

                case 194 /* getAllowedNetworkTypesBitmapResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int networkTypeBitmap = _hidl_request.readInt32();
                    getAllowedNetworkTypesBitmapResponse(info, networkTypeBitmap);
                    break;
                }

                case 195 /* setDataThrottlingResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    setDataThrottlingResponse(info);
                    break;
                }

                case 196 /* getSystemSelectionChannelsResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_5.RadioAccessSpecifier> specifiers = android.hardware.radio.V1_5.RadioAccessSpecifier.readVectorFromParcel(_hidl_request);
                    getSystemSelectionChannelsResponse(info, specifiers);
                    break;
                }

                case 197 /* getCellInfoListResponse_1_6 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_6.CellInfo> cellInfo = android.hardware.radio.V1_6.CellInfo.readVectorFromParcel(_hidl_request);
                    getCellInfoListResponse_1_6(info, cellInfo);
                    break;
                }

                case 198 /* getSignalStrengthResponse_1_6 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_6.SignalStrength signalStrength = new android.hardware.radio.V1_6.SignalStrength();
                    ((android.hardware.radio.V1_6.SignalStrength) signalStrength).readFromParcel(_hidl_request);
                    getSignalStrengthResponse_1_6(info, signalStrength);
                    break;
                }

                case 199 /* getVoiceRegistrationStateResponse_1_6 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_6.RegStateResult voiceRegResponse = new android.hardware.radio.V1_6.RegStateResult();
                    ((android.hardware.radio.V1_6.RegStateResult) voiceRegResponse).readFromParcel(_hidl_request);
                    getVoiceRegistrationStateResponse_1_6(info, voiceRegResponse);
                    break;
                }

                case 200 /* getDataRegistrationStateResponse_1_6 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_6.RegStateResult dataRegResponse = new android.hardware.radio.V1_6.RegStateResult();
                    ((android.hardware.radio.V1_6.RegStateResult) dataRegResponse).readFromParcel(_hidl_request);
                    getDataRegistrationStateResponse_1_6(info, dataRegResponse);
                    break;
                }

                case 201 /* getCurrentCallsResponse_1_6 */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    java.util.ArrayList<android.hardware.radio.V1_6.Call> calls = android.hardware.radio.V1_6.Call.readVectorFromParcel(_hidl_request);
                    getCurrentCallsResponse_1_6(info, calls);
                    break;
                }

                case 202 /* getSlicingConfigResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_6.SlicingConfig slicingConfig = new android.hardware.radio.V1_6.SlicingConfig();
                    ((android.hardware.radio.V1_6.SlicingConfig) slicingConfig).readFromParcel(_hidl_request);
                    getSlicingConfigResponse(info, slicingConfig);
                    break;
                }

                case 203 /* getSimPhonebookRecordsResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    getSimPhonebookRecordsResponse(info);
                    break;
                }

                case 204 /* getSimPhonebookCapacityResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    android.hardware.radio.V1_6.PhonebookCapacity capacity = new android.hardware.radio.V1_6.PhonebookCapacity();
                    ((android.hardware.radio.V1_6.PhonebookCapacity) capacity).readFromParcel(_hidl_request);
                    getSimPhonebookCapacityResponse(info, capacity);
                    break;
                }

                case 205 /* updateSimPhonebookRecordsResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.radio.V1_6.IRadioResponse.kInterfaceName);

                    android.hardware.radio.V1_6.RadioResponseInfo info = new android.hardware.radio.V1_6.RadioResponseInfo();
                    ((android.hardware.radio.V1_6.RadioResponseInfo) info).readFromParcel(_hidl_request);
                    int updatedRecordIndex = _hidl_request.readInt32();
                    updateSimPhonebookRecordsResponse(info, updatedRecordIndex);
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
