#ifndef HIDL_GENERATED_ANDROID_HARDWARE_RADIO_V1_4_IRADIORESPONSE_H
#define HIDL_GENERATED_ANDROID_HARDWARE_RADIO_V1_4_IRADIORESPONSE_H

#include <android/hardware/radio/1.0/types.h>
#include <android/hardware/radio/1.3/IRadioResponse.h>
#include <android/hardware/radio/1.4/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace radio {
namespace V1_4 {

/**
 * Interface declaring response functions to solicited radio requests.
 */
struct IRadioResponse : public ::android::hardware::radio::V1_3::IRadioResponse {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef ::android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.radio@1.4::IRadioResponse"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param cardStatus ICC card status as defined by CardStatus in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> getIccCardStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::CardStatus& cardStatus) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param remainingRetries Number of retries remaining, must be equal to -1 if unknown.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:PASSWORD_INCORRECT
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_SIM_STATE
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> supplyIccPinForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param remainingRetries Number of retries remaining, must be equal to -1 if unknown.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:PASSWORD_INCORRECT (PUK is invalid)
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_SIM_STATE
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> supplyIccPukForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param remainingRetries Number of retries remaining, must be equal to -1 if unknown.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:PASSWORD_INCORRECT
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_SIM_STATE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SIM_PUK2
     */
    virtual ::android::hardware::Return<void> supplyIccPin2ForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param remainingRetries Number of retries remaining, must be equal to -1 if unknown.
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:PASSWORD_INCORRECT (PUK is invalid)
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_SIM_STATE
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> supplyIccPuk2ForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param remainingRetries Number of retries remaining, must be equal to -1 if unknown.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:PASSWORD_INCORRECT
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_SIM_STATE
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> changeIccPinForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param remainingRetries Number of retries remaining, must be equal to -1 if unknown.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:PASSWORD_INCORRECT (old PIN2 is invalid)
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_SIM_STATE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SIM_PUK2
     */
    virtual ::android::hardware::Return<void> changeIccPin2ForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param remainingRetries Number of retries remaining, must be equal to -1 if unknown.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:PASSWORD_INCORRECT (code is invalid)
     *   RadioError:NO_MEMORY
     *   RadioError:INVALID_SIM_STATE
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> supplyNetworkDepersonalizationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param calls Current call list
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getCurrentCallsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::Call>& calls) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:DIAL_MODIFIED_TO_USSD
     *   RadioError:DIAL_MODIFIED_TO_SS
     *   RadioError:DIAL_MODIFIED_TO_DIAL
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:INVALID_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:INTERNAL_ERR
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:MODEM_ERR
     *   RadioError:NO_SUBSCRIPTION
     *   RadioError:NO_NETWORK_FOUND
     *   RadioError:INVALID_CALL_ID
     *   RadioError:DEVICE_IN_USE
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:ABORTED
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> dialResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param imsi String containing the IMSI
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_SIM_STATE
     *   RadioError:SIM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> getIMSIForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& imsi) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:INVALID_STATE
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_CALL_ID
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> hangupConnectionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_CALL_ID
     *   RadioError:NO_RESOURCES
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> hangupWaitingOrBackgroundResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_CALL_ID
     *   RadioError:NO_RESOURCES
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> hangupForegroundResumeBackgroundResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_STATE
     *   RadioError:INVALID_CALL_ID
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> switchWaitingOrHoldingAndActiveResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_STATE
     *   RadioError:INVALID_CALL_ID
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> conferenceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:INVALID_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_CALL_ID
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> rejectCallResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param failCauseInfo Contains LastCallFailCause and vendor cause code.
     *
     *   The vendor cause code must be used for debugging purpose only.
     *   The implementation must return one of the values of LastCallFailCause
     *   as mentioned below
     *
     *   GSM failure reasons codes for the cause codes defined in TS 24.008 Annex H
     *   where possible.
     *   CDMA failure reasons codes for the possible call failure scenarios
     *   described in the "CDMA IS-2000 Release A (C.S0005-A v6.0)" standard.
     *   Any of the following reason codes if the call is failed or dropped due to reason
     *   mentioned with in the braces.
     *      LastCallFailCause:RADIO_OFF (Radio is OFF)
     *      LastCallFailCause:OUT_OF_SERVICE (No cell coverage)
     *      LastCallFailCause:NO_VALID_SIM (No valid SIM)
     *      LastCallFailCause:RADIO_INTERNAL_ERROR (Modem hit unexpected error scenario)
     *      LastCallFailCause:NETWORK_RESP_TIMEOUT (No response from network)
     *      LastCallFailCause:NETWORK_REJECT (Explicit network reject)
     *      LastCallFailCause:RADIO_ACCESS_FAILURE (RRC connection failure. Eg.RACH)
     *      LastCallFailCause:RADIO_LINK_FAILURE (Radio Link Failure)
     *      LastCallFailCause:RADIO_LINK_LOST (Radio link lost due to poor coverage)
     *      LastCallFailCause:RADIO_UPLINK_FAILURE (Radio uplink failure)
     *      LastCallFailCause:RADIO_SETUP_FAILURE (RRC connection setup failure)
     *      LastCallFailCause:RADIO_RELEASE_NORMAL (RRC connection release, normal)
     *      LastCallFailCause:RADIO_RELEASE_ABNORMAL (RRC connection release, abnormal)
     *      LastCallFailCause:ACCESS_CLASS_BLOCKED (Access class barring)
     *      LastCallFailCause:NETWORK_DETACH (Explicit network detach)
     *   OEM causes (LastCallFailCause:OEM_CAUSE_XX) must be used for debug purpose only
     *
     * If the implementation does not have access to the exact cause codes,
     * then it must return one of the values listed in LastCallFailCause,
     * as the UI layer needs to distinguish these cases for tone generation or
     * error notification.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:NO_MEMORY
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INTERNAL_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getLastCallFailCauseResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LastCallFailCauseInfo& failCauseinfo) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param sigStrength Current signal strength
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:NOT_PROVISIONED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getSignalStrengthResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SignalStrength& sigStrength) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param voiceRegResponse Current Voice registration response as defined by VoiceRegStateResult
     *        in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> getVoiceRegistrationStateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::VoiceRegStateResult& voiceRegResponse) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param dataRegResponse Current Data registration response as defined by DataRegStateResult in
     *        types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:NOT_PROVISIONED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getDataRegistrationStateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::DataRegStateResult& dataRegResponse) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param longName is long alpha ONS or EONS or empty string if unregistered
     * @param shortName is short alpha ONS or EONS or empty string if unregistered
     * @param numeric is 5 or 6 digit numeric code (MCC + MNC) or empty string if unregistered
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getOperatorResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& longName, const ::android::hardware::hidl_string& shortName, const ::android::hardware::hidl_string& numeric) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:DEVICE_IN_USE
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setRadioPowerResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_RESOURCES
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:INVALID_CALL_ID
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     */
    virtual ::android::hardware::Return<void> sendDtmfResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

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
     */
    virtual ::android::hardware::Return<void> sendSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms) = 0;

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
     */
    virtual ::android::hardware::Return<void> sendSMSExpectMoreResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms) = 0;

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
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> setupDataCallResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SetupDataCallResult& dcResponse) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param iccIo ICC io operation response as defined by IccIoResult in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SIM_PIN2
     *   RadioError:SIM_PUK2
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_SIM_STATE
     *   RadioError:SIM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> iccIOForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& iccIo) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:USSD_MODIFIED_TO_DIAL
     *   RadioError:USSD_MODIFIED_TO_SS
     *   RadioError:USSD_MODIFIED_TO_USSD
     *   RadioError:SIM_BUSY
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:ABORTED
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_STATE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> sendUssdResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SIM_BUSY
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:INVALID_STATE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> cancelPendingUssdResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param n is "n" parameter from TS 27.007 7.7
     * @param m is "m" parameter from TS 27.007 7.7
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SS_MODIFIED_TO_DIAL
     *   RadioError:SS_MODIFIED_TO_USSD
     *   RadioError:SS_MODIFIED_TO_SS
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getClirResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t n, int32_t m) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SS_MODIFIED_TO_DIAL
     *   RadioError:SS_MODIFIED_TO_USSD
     *   RadioError:SS_MODIFIED_TO_SS
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setClirResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param callForwardInfos points to a vector of CallForwardInfo, one for
     *        each distinct registered phone number.
     *
     * For example, if data is forwarded to +18005551212 and voice is forwarded
     * to +18005559999, then two separate CallForwardInfo's must be returned
     *
     * If, however, both data and voice are forwarded to +18005551212, then
     * a single CallForwardInfo must be returned with the service class
     * set to "data + voice = 3")
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SS_MODIFIED_TO_DIAL
     *   RadioError:SS_MODIFIED_TO_USSD
     *   RadioError:SS_MODIFIED_TO_SS
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SYSTEM_ERR
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getCallForwardStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CallForwardInfo>& callForwardInfos) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SS_MODIFIED_TO_DIAL
     *   RadioError:SS_MODIFIED_TO_USSD
     *   RadioError:SS_MODIFIED_TO_SS
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_STATE
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setCallForwardResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param enable If current call waiting state is disabled, enable = false else true
     * @param serviceClass If enable, then callWaitingResp[1]
     *        must follow, with the TS 27.007 service class bit vector of services
     *        for which call waiting is enabled.
     *        For example, if callWaitingResp[0] is 1 and
     *        callWaitingResp[1] is 3, then call waiting is enabled for data
     *        and voice and disabled for everything else.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SS_MODIFIED_TO_DIAL
     *   RadioError:SS_MODIFIED_TO_USSD
     *   RadioError:SS_MODIFIED_TO_SS
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getCallWaitingResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool enable, int32_t serviceClass) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SS_MODIFIED_TO_DIAL
     *   RadioError:SS_MODIFIED_TO_USSD
     *   RadioError:SS_MODIFIED_TO_SS
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_STATE
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setCallWaitingResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> acknowledgeLastIncomingGsmSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_CALL_ID
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> acceptCallResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_CALL_ID
     *   RadioError:INVALID_STATE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> deactivateDataCallResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param response 0 is the TS 27.007 service class bit vector of
     *        services for which the specified barring facility
     *        is active. "0" means "disabled for all"
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SS_MODIFIED_TO_DIAL
     *   RadioError:SS_MODIFIED_TO_USSD
     *   RadioError:SS_MODIFIED_TO_SS
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getFacilityLockForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t response) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param retry 0 is the number of retries remaining, or -1 if unknown
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SS_MODIFIED_TO_DIAL
     *   RadioError:SS_MODIFIED_TO_USSD
     *   RadioError:SS_MODIFIED_TO_SS
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_STATE
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setFacilityLockForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t retry) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SS_MODIFIED_TO_DIAL
     *   RadioError:SS_MODIFIED_TO_USSD
     *   RadioError:SS_MODIFIED_TO_SS
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setBarringPasswordResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param selection false for automatic selection, true for manual selection
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getNetworkSelectionModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool manual) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:ILLEGAL_SIM_OR_ME
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *
     * Returns RadioError:ILLEGAL_SIM_OR_ME when the failure is permanent and
     * no retries needed, such as illegal SIM or ME.
     */
    virtual ::android::hardware::Return<void> setNetworkSelectionModeAutomaticResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:ILLEGAL_SIM_OR_ME
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *
     * Returns RadioError:ILLEGAL_SIM_OR_ME when the failure is permanent and
     * no retries needed, such as illegal SIM or ME.
     */
    virtual ::android::hardware::Return<void> setNetworkSelectionModeManualResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param networkInfos List of network operator information as OperatorInfos defined in
     *         types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:ABORTED
     *   RadioError:DEVICE_IN_USE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:CANCELLED
     *   RadioError:NO_RESOURCES
     *   RadioError:INTERNAL_ERR
     */
    virtual ::android::hardware::Return<void> getAvailableNetworksResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::OperatorInfo>& networkInfos) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_RESOURCES
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_CALL_ID
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     */
    virtual ::android::hardware::Return<void> startDtmfResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_RESOURCES
     *   RadioError:NO_MEMORY
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_CALL_ID
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     */
    virtual ::android::hardware::Return<void> stopDtmfResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param version string containing version string for log reporting
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:EMPTY_RECORD
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:NOT_PROVISIONED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getBasebandVersionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& version) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_CALL_ID
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> separateConnectionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setMuteResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param enable true for "mute enabled" and false for "mute disabled"
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SS_MODIFIED_TO_DIAL
     *   RadioError:SS_MODIFIED_TO_USSD
     *   RadioError:SS_MODIFIED_TO_SS
     *   RadioError:NO_MEMORY
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getMuteResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool enable) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param status indicates CLIP status
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getClipResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::ClipStatus status) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param dcResponse List of DataCallResult as defined in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> getDataCallListResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::SetupDataCallResult>& dcResponse) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:SIM_BUSY
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> setSuppServiceNotificationsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param index record index where the message is stored
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SIM_FULL
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_SMS_FORMAT
     *   RadioError:INTERNAL_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:ENCODING_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INVALID_SMSC_ADDRESS
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> writeSmsToSimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t index) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SIM_FULL
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:NO_SUCH_ENTRY
     *   RadioError:INTERNAL_ERR
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> deleteSmsOnSimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setBandModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param bandModes List of RadioBandMode listing supported modes
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getAvailableBandModesResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::RadioBandMode>& bandModes) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param commandResponse SAT/USAT response in hexadecimal format
     *        string starting with first byte of response
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SIM_BUSY
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> sendEnvelopeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& commandResponse) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> sendTerminalResponseToSimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> handleStkCallSetupRequestFromSimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_CALL_ID
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> explicitCallTransferResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:MODE_NOT_SUPPORTED
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setPreferredNetworkTypeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param nwType RadioPreferredNetworkType defined in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getPreferredNetworkTypeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::PreferredNetworkType nwType) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param cells Vector of neighboring radio cell
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:NO_NETWORK_FOUND
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getNeighboringCidsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::NeighboringCell>& cells) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> setLocationUpdatesResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SIM_ABSENT
     *   RadioError:SUBSCRIPTION_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> setCdmaSubscriptionSourceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> setCdmaRoamingPreferenceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param type CdmaRoamingType defined in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> getCdmaRoamingPreferenceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::CdmaRoamingType type) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setTTYModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param mode TtyMode
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getTTYModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::TtyMode mode) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_CALL_ID
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setPreferredVoicePrivacyResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param enable false for Standard Privacy Mode (Public Long Code Mask)
     *        true for Enhanced Privacy Mode (Private Long Code Mask)
     *
     * Valid errors:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getPreferredVoicePrivacyResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool enable) = 0;

    /**
     * Response callback for IRadio.sendCDMAFeatureCode()
     *
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INVALID_CALL_ID
     *   RadioError:INVALID_STATE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:OPERATION_NOT_ALLOWED
     */
    virtual ::android::hardware::Return<void> sendCDMAFeatureCodeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INVALID_CALL_ID
     *   RadioError:INVALID_STATE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:OPERATION_NOT_ALLOWED
     */
    virtual ::android::hardware::Return<void> sendBurstDtmfResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

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
     */
    virtual ::android::hardware::Return<void> sendCdmaSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_SMS_TO_ACK
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:NETWORK_NOT_READY
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> acknowledgeLastIncomingCdmaSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param configs Vector of GSM/WCDMA Cell broadcast configs
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:NO_RESOURCES
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     */
    virtual ::android::hardware::Return<void> getGsmBroadcastConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::GsmBroadcastSmsConfigInfo>& configs) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     */
    virtual ::android::hardware::Return<void> setGsmBroadcastConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     */
    virtual ::android::hardware::Return<void> setGsmBroadcastActivationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param configs Vector of CDMA Broadcast SMS configs.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:NO_RESOURCES
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     */
    virtual ::android::hardware::Return<void> getCdmaBroadcastConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaBroadcastSmsConfigInfo>& configs) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     */
    virtual ::android::hardware::Return<void> setCdmaBroadcastConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     */
    virtual ::android::hardware::Return<void> setCdmaBroadcastActivationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param mdn MDN if CDMA subscription is available
     * @param hSid is a comma separated list of H_SID (Home SID) if
     *        CDMA subscription is available, in decimal format
     * @param hNid is a comma separated list of H_NID (Home NID) if
     *        CDMA subscription is available, in decimal format
     * @param min MIN (10 digits, MIN2+MIN1) if CDMA subscription is available
     * @param prl PRL version if CDMA subscription is available
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SUBSCRIPTION_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:NOT_PROVISIONED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> getCDMASubscriptionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& mdn, const ::android::hardware::hidl_string& hSid, const ::android::hardware::hidl_string& hNid, const ::android::hardware::hidl_string& min, const ::android::hardware::hidl_string& prl) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param index record index where the cmda sms message is stored
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_SMS_FORMAT
     *   RadioError:SIM_FULL
     *   RadioError:INTERNAL_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:ENCODING_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:INVALID_SMSC_ADDRESS
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> writeSmsToRuimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, uint32_t index) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:NO_SUCH_ENTRY
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> deleteSmsOnRuimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param imei IMEI if GSM subscription is available
     * @param imeisv IMEISV if GSM subscription is available
     * @param esn ESN if CDMA subscription is available
     * @param meid MEID if CDMA subscription is available
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:NOT_PROVISIONED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *
     * If a empty string value is returned for any of the device id, it means that there was error
     * accessing the device.
     *
     */
    virtual ::android::hardware::Return<void> getDeviceIdentityResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& imei, const ::android::hardware::hidl_string& imeisv, const ::android::hardware::hidl_string& esn, const ::android::hardware::hidl_string& meid) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:OPERATION_NO_ALLOWED
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> exitEmergencyCallbackModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param smsc Short Message Service Center address on the device
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:MODEM_ERR
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NOT_PROVISIONED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> getSmscAddressResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& smsc) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_SMS_FORMAT
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:MODEM_ERR
     *   RadioError:NO_RESOURCES
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> setSmscAddressResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_MEMORY
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:MODEM_ERR
     *   RadioError:INVALID_STATE
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> reportSmsMemoryStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> reportStkServiceIsRunningResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param source CDMA subscription source
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SUBSCRIPTION_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> getCdmaSubscriptionSourceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::CdmaSubscriptionSource source) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param response response string of the challenge/response algo for ISIM auth in base64 format
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> requestIsimAuthenticationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& response) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> acknowledgeIncomingGsmSmsWithPduResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param iccIo IccIoResult as defined in types.hal corresponding to ICC IO response
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SIM_BUSY
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> sendEnvelopeWithStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& iccIo) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param rat Current voice RAT
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> getVoiceRadioTechnologyResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::RadioTechnology rat) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param cellInfo List of current cell information known to radio
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:NO_NETWORK_FOUND
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getCellInfoListResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfo>& cellInfo) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> setCellInfoListRateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SUBSCRIPTION_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NOT_PROVISIONED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setInitialAttachApnResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param isRegistered false = not registered, true = registered
     * @param ratFamily RadioTechnologyFamily as defined in types.hal. This value is valid only if
     *        isRegistered is true.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> getImsRegistrationStateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool isRegistered, ::android::hardware::radio::V1_0::RadioTechnologyFamily ratFamily) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param sms Response to sms sent as defined by SendSmsResult in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SMS_SEND_FAIL_RETRY
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:NETWORK_REJECT
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INVALID_STATE
     *   RadioError:NO_MEMORY
     *   RadioError:INVALID_SMS_FORMAT
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_RATE_LIMITED
     *   RadioError:MODEM_ERR
     *   RadioError:NETWORK_ERR
     *   RadioError:ENCODING_ERR
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NETWORK_NOT_READY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> sendImsSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param result IccIoResult as defined in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> iccTransmitApduBasicChannelResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& result) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param channelId session id of the logical channel.
     * @param selectResponse Contains the select response for the open channel command with one
     *        byte per integer
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:MISSING_RESOURCE
     *   RadioError:NO_SUCH_ELEMENT
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:SIM_ERR
     *   RadioError:INVALID_SIM_STATE
     *   RadioError:MISSING_RESOURCE
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> iccOpenLogicalChannelResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t channelId, const ::android::hardware::hidl_vec<int8_t>& selectResponse) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> iccCloseLogicalChannelResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param result IccIoResult as defined in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> iccTransmitApduLogicalChannelResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& result) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param result string containing the contents of the NV item
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> nvReadItemResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& result) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> nvWriteItemResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> nvWriteCdmaPrlResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> nvResetConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SUBSCRIPTION_NOT_SUPPORTED
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setUiccSubscriptionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:DEVICE_IN_USE
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> setDataAllowedResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param config Array of HardwareConfig of the radio.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> getHardwareConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::HardwareConfig>& config) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param result IccIoResult as defined in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:INVALID_MODEM_STATE
     *   RadioError:SIM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> requestIccSimAuthenticationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& result) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:SUBSCRIPTION_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> setDataProfileResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> requestShutdownResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param rc Radio capability as defined by RadioCapability in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:INVALID_STATE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getRadioCapabilityResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::RadioCapability& rc) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param rc Radio capability as defined by RadioCapability in types.hal used to
     *        feedback return status
     *
     * Valid errors returned:
     *   RadioError:NONE means a unsol radioCapability() will be sent within 30 seconds.
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:INVALID_STATE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setRadioCapabilityResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::RadioCapability& rc) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param statusInfo LceStatusInfo indicating LCE status
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:LCE_NOT_SUPPORTED
     *   RadioError:INTERNAL_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> startLceServiceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LceStatusInfo& statusInfo) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param statusInfo LceStatusInfo indicating LCE status
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:LCE_NOT_SUPPORTED
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> stopLceServiceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LceStatusInfo& statusInfo) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param lceInfo LceDataInfo indicating LCE data as defined in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:LCE_NOT_SUPPORTED
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> pullLceDataResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LceDataInfo& lceInfo) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param activityInfo modem activity information
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:NOT_PROVISIONED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> getModemActivityInfoResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::ActivityStatsInfo& activityInfo) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param numAllowed number of allowed carriers which have been set correctly.
     *        On success, it must match the length of list Carriers->allowedCarriers.
     *        if Length of allowed carriers list is 0, numAllowed = 0.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> setAllowedCarriersResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t numAllowed) = 0;

    /**
     * Expected modem behavior:
     *  Return list of allowed carriers, and if all carriers are allowed.
     *
     * @param info Response info struct containing response type, serial no. and error
     * @param allAllowed true only when all carriers are allowed. Ignore "carriers" struct.
     *        If false, consider "carriers" struct
     * @param carriers Carrier restriction information.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> getAllowedCarriersResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool allAllowed, const ::android::hardware::radio::V1_0::CarrierRestrictions& carriers) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> sendDeviceStateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setIndicationFilterResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> setSimCardPowerResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * Acknowledge the receipt of radio request sent to the vendor. This must be sent only for
     * radio request which take long time to respond.
     * For more details, refer https://source.android.com/devices/tech/connect/ril.html
     *
     * @param serial Serial no. of the request whose acknowledgement is sent.
     */
    virtual ::android::hardware::Return<void> acknowledgeRequest(int32_t serial) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:RIL_E_SUCCESS
     *   RadioError:RIL_E_RADIO_NOT_AVAILABLE
     *   RadioError:SIM_ABSENT
     *   RadioError:RIL_E_REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_INTERNAL_FAILURE
     */
    virtual ::android::hardware::Return<void> setCarrierInfoForImsiEncryptionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_ARGUMENTS
     */
    virtual ::android::hardware::Return<void> setSimCardPowerResponse_1_1(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:OPERATION_NOT_ALLOWED
     *   RadioError:DEVICE_IN_USE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_MEMORY
     *   RadioError:MODEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> startNetworkScanResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:INTERNAL_ERR
     *   RadioError:MODEM_ERR
     */
    virtual ::android::hardware::Return<void> stopNetworkScanResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param status Status object containing a new handle and a current status. The
     * status returned here may be PENDING to indicate that the radio has not yet
     * processed the keepalive request.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:NO_RESOURCES
     *   RadioError:INVALID_ARGUMENTS
     */
    virtual ::android::hardware::Return<void> startKeepaliveResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_1::KeepaliveStatus& status) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:INVALID_ARGUMENTS
     */
    virtual ::android::hardware::Return<void> stopKeepaliveResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param cellInfo List of current cell information known to radio
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:NO_NETWORK_FOUND
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getCellInfoListResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellInfo>& cellInfo) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param cardStatus ICC card status as defined by CardStatus in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     */
    virtual ::android::hardware::Return<void> getIccCardStatusResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::CardStatus& cardStatus) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     */
    virtual ::android::hardware::Return<void> setSignalStrengthReportingCriteriaResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     */
    virtual ::android::hardware::Return<void> setLinkCapacityReportingCriteriaResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param calls Current call list
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:NO_MEMORY
     *   RadioError:INTERNAL_ERR
     *   RadioError:SYSTEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     *   RadioError:CANCELLED
     */
    virtual ::android::hardware::Return<void> getCurrentCallsResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_2::Call>& calls) = 0;

    /**
     * @param signalStrength Current signal strength
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     */
    virtual ::android::hardware::Return<void> getSignalStrengthResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::SignalStrength& signalStrength) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param voiceRegResponse Current Voice registration response as defined by VoiceRegStateResult
     *        in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     */
    virtual ::android::hardware::Return<void> getVoiceRegistrationStateResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::VoiceRegStateResult& voiceRegResponse) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param dataRegResponse Current Data registration response as defined by DataRegStateResult in
     *        types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NOT_PROVISIONED
     */
    virtual ::android::hardware::Return<void> getDataRegistrationStateResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::DataRegStateResult& dataRegResponse) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_ARGUMENTS
     */
    virtual ::android::hardware::Return<void> setSystemSelectionChannelsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:MODEM_ERR
     *   RadioError:INVALID_STATE: this is for the case that the API is called in a single-sim
     *              mode, or when there is only one modem available, as this API should only
     *              be called in multi sim status.
     */
    virtual ::android::hardware::Return<void> enableModemResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:MODEM_ERR
     */
    virtual ::android::hardware::Return<void> getModemStackStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool isEnabled) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE (radio resetting)
     *   RadioError:DIAL_MODIFIED_TO_USSD
     *   RadioError:DIAL_MODIFIED_TO_SS
     *   RadioError:DIAL_MODIFIED_TO_DIAL
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:NO_RESOURCES
     *   RadioError:INTERNAL_ERR
     *   RadioError:FDN_CHECK_FAILURE
     *   RadioError:MODEM_ERR
     *   RadioError:NO_SUBSCRIPTION
     *   RadioError:NO_NETWORK_FOUND
     *   RadioError:INVALID_CALL_ID
     *   RadioError:DEVICE_IN_USE
     *   RadioError:ABORTED
     *   RadioError:INVALID_MODEM_STATE
     */
    virtual ::android::hardware::Return<void> emergencyDialResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Same API as @1.1::IRadioResponse.startNetworkScanResponse, except disallowing error codes
     * OPERATION_NOT_ALLOWED and REQUEST_NOT_SUPPORTED.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:DEVICE_IN_USE
     *   RadioError:INTERNAL_ERR
     *   RadioError:MODEM_ERR
     *   RadioError:INVALID_ARGUMENTS
     */
    virtual ::android::hardware::Return<void> startNetworkScanResponse_1_4(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param cellInfo List of current cell information known to radio
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     */
    virtual ::android::hardware::Return<void> getCellInfoListResponse_1_4(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_4::CellInfo>& cellInfo) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param dataRegResponse Current Data registration response as defined by DataRegStateResult in
     *        types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NOT_PROVISIONED
     */
    virtual ::android::hardware::Return<void> getDataRegistrationStateResponse_1_4(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_4::DataRegStateResult& dataRegResponse) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param cardStatus ICC card status as defined by CardStatus in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_RESOURCES
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> getIccCardStatusResponse_1_4(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_4::CardStatus& cardStatus) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param networkTypeBitmap a 32-bit bitmap of RadioAccessFamily.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:MODEM_ERR
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:NO_RESOURCES
     */
    virtual ::android::hardware::Return<void> getPreferredNetworkTypeBitmapResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::hidl_bitfield<::android::hardware::radio::V1_4::RadioAccessFamily> networkTypeBitmap) = 0;

    /**
     * Callback of IRadio.setPreferredNetworkTypeBitmap(int, bitfield<RadioAccessFamily>)
     *
     * @param info Response info struct containing response type, serial no. and error
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
    virtual ::android::hardware::Return<void> setPreferredNetworkTypeBitmapResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     * @param dcResponse List of DataCallResult as defined in types.hal
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_RESOURCES
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> getDataCallListResponse_1_4(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_4::SetupDataCallResult>& dcResponse) = 0;

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
     *   RadioError:REQUEST_NOT_SUPPORTED
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:INTERNAL_ERR
     *   RadioError:NO_RESOURCES
     *   RadioError:SIM_ABSENT
     */
    virtual ::android::hardware::Return<void> setupDataCallResponse_1_4(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_4::SetupDataCallResult& dcResponse) = 0;

    /**
     * @param info Response info struct containing response type, serial no. and error
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INVALID_ARGUMENTS
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> setAllowedCarriersResponse_1_4(const ::android::hardware::radio::V1_0::RadioResponseInfo& info) = 0;

    /**
     * Expected modem behavior:
     *  Return list of allowed carriers, and if all carriers are allowed.
     *
     * @param info Response info struct containing response type, serial no. and error
     * @param carriers Carrier restriction information.
     * @param multiSimPolicy Policy used for devices with multiple SIM cards.
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:REQUEST_NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> getAllowedCarriersResponse_1_4(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_4::CarrierRestrictionsWithPriority& carriers, ::android::hardware::radio::V1_4::SimLockMultiSimPolicy multiSimPolicy) = 0;

    /**
     * @param signalStrength Current signal strength
     *
     * Valid errors returned:
     *   RadioError:NONE
     *   RadioError:RADIO_NOT_AVAILABLE
     *   RadioError:INTERNAL_ERR
     */
    virtual ::android::hardware::Return<void> getSignalStrengthResponse_1_4(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_4::SignalStrength& signalStrength) = 0;

    /**
     * Return callback for interfaceChain
     */
    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;
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
    virtual ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;

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
    virtual ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;

    /**
     * Return callback for interfaceDescriptor
     */
    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;
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
    virtual ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;

    /**
     * Return callback for getHashChain
     */
    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;
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
    virtual ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;

    /*
     * This method trigger the interface to enable/disable instrumentation based
     * on system property hal.instrumentation.enable.
     */
    virtual ::android::hardware::Return<void> setHALInstrumentation() override;

    /*
     * Registers a death recipient, to be called when the process hosting this
     * interface dies.
     *
     * @param recipient a hidl_death_recipient callback object
     * @param cookie a cookie that must be returned with the callback
     * @return success whether the death recipient was registered successfully.
     */
    virtual ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;

    /*
     * Provides way to determine if interface is running without requesting
     * any functionality.
     */
    virtual ::android::hardware::Return<void> ping() override;

    /**
     * Return callback for getDebugInfo
     */
    using getDebugInfo_cb = std::function<void(const ::android::hidl::base::V1_0::DebugInfo& info)>;
    /*
     * Get debug information on references on this interface.
     * @return info debugging information. See comments of DebugInfo.
     */
    virtual ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;

    /*
     * This method notifies the interface that one or more system properties
     * have changed. The default implementation calls
     * (C++)  report_sysprop_change() in libcutils or
     * (Java) android.os.SystemProperties.reportSyspropChanged,
     * which in turn calls a set of registered callbacks (eg to update trace
     * tags).
     */
    virtual ::android::hardware::Return<void> notifySyspropsChanged() override;

    /*
     * Unregisters the registered death recipient. If this service was registered
     * multiple times with the same exact death recipient, this unlinks the most
     * recently registered one.
     *
     * @param recipient a previously registered hidl_death_recipient callback
     * @return success whether the death recipient was unregistered successfully.
     */
    virtual ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

    // cast static functions
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::radio::V1_4::IRadioResponse>> castFrom(const ::android::sp<::android::hardware::radio::V1_4::IRadioResponse>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::radio::V1_4::IRadioResponse>> castFrom(const ::android::sp<::android::hardware::radio::V1_3::IRadioResponse>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::radio::V1_4::IRadioResponse>> castFrom(const ::android::sp<::android::hardware::radio::V1_2::IRadioResponse>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::radio::V1_4::IRadioResponse>> castFrom(const ::android::sp<::android::hardware::radio::V1_1::IRadioResponse>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::radio::V1_4::IRadioResponse>> castFrom(const ::android::sp<::android::hardware::radio::V1_0::IRadioResponse>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::radio::V1_4::IRadioResponse>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    // helper methods for interactions with the hwservicemanager
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is currently not available or not in the VINTF manifest on a Trebilized
     * device, this will return nullptr. This is useful when you don't want to block
     * during device boot. If getStub is true, this will try to return an unwrapped
     * passthrough implementation in the same process. This is useful when getting an
     * implementation from the same partition/compilation group.
     *
     * In general, prefer getService(std::string,bool)
     */
    static ::android::sp<IRadioResponse> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IRadioResponse> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IRadioResponse> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IRadioResponse> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IRadioResponse> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IRadioResponse> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IRadioResponse> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IRadioResponse> getService(bool getStub) { return getService("default", getStub); }
    /**
     * Registers a service with the service manager. For Trebilized devices, the service
     * must also be in the VINTF manifest.
     */
    __attribute__ ((warn_unused_result))::android::status_t registerAsService(const std::string &serviceName="default");
    /**
     * Registers for notifications for when a service is registered.
     */
    static bool registerForNotifications(
            const std::string &serviceName,
            const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification);
};

//
// type declarations for package
//

static inline std::string toString(const ::android::sp<::android::hardware::radio::V1_4::IRadioResponse>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::radio::V1_4::IRadioResponse>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::radio::V1_4::IRadioResponse::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_4
}  // namespace radio
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_RADIO_V1_4_IRADIORESPONSE_H
