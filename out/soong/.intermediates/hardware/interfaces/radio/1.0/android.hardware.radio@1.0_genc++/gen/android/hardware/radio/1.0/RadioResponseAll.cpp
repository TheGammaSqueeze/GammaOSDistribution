#define LOG_TAG "android.hardware.radio@1.0::RadioResponse"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/radio/1.0/BpHwRadioResponse.h>
#include <android/hardware/radio/1.0/BnHwRadioResponse.h>
#include <android/hardware/radio/1.0/BsRadioResponse.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace radio {
namespace V1_0 {

const char* IRadioResponse::descriptor("android.hardware.radio@1.0::IRadioResponse");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IRadioResponse::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwRadioResponse(static_cast<IRadioResponse *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IRadioResponse::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsRadioResponse(static_cast<IRadioResponse *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IRadioResponse::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IRadioResponse::descriptor);
}

// Methods from ::android::hardware::radio::V1_0::IRadioResponse follow.
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getIccCardStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::CardStatus& cardStatus)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::supplyIccPinForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::supplyIccPukForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::supplyIccPin2ForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::supplyIccPuk2ForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::changeIccPinForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::changeIccPin2ForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::supplyNetworkDepersonalizationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getCurrentCallsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::Call>& calls)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::dialResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getIMSIForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& imsi)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::hangupConnectionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::hangupWaitingOrBackgroundResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::hangupForegroundResumeBackgroundResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::switchWaitingOrHoldingAndActiveResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::conferenceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::rejectCallResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getLastCallFailCauseResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LastCallFailCauseInfo& failCauseinfo)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getSignalStrengthResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SignalStrength& sigStrength)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getVoiceRegistrationStateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::VoiceRegStateResult& voiceRegResponse)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getDataRegistrationStateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::DataRegStateResult& dataRegResponse)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getOperatorResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& longName, const ::android::hardware::hidl_string& shortName, const ::android::hardware::hidl_string& numeric)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setRadioPowerResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendDtmfResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendSMSExpectMoreResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setupDataCallResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SetupDataCallResult& dcResponse)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::iccIOForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& iccIo)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendUssdResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::cancelPendingUssdResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getClirResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t n, int32_t m)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setClirResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getCallForwardStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CallForwardInfo>& callForwardInfos)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setCallForwardResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getCallWaitingResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool enable, int32_t serviceClass)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setCallWaitingResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::acknowledgeLastIncomingGsmSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::acceptCallResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::deactivateDataCallResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getFacilityLockForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t response)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setFacilityLockForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t retry)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setBarringPasswordResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getNetworkSelectionModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool manual)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setNetworkSelectionModeAutomaticResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setNetworkSelectionModeManualResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getAvailableNetworksResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::OperatorInfo>& networkInfos)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::startDtmfResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::stopDtmfResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getBasebandVersionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& version)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::separateConnectionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setMuteResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getMuteResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool enable)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getClipResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::ClipStatus status)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getDataCallListResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::SetupDataCallResult>& dcResponse)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setSuppServiceNotificationsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::writeSmsToSimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t index)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::deleteSmsOnSimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setBandModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getAvailableBandModesResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::RadioBandMode>& bandModes)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendEnvelopeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& commandResponse)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendTerminalResponseToSimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::handleStkCallSetupRequestFromSimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::explicitCallTransferResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setPreferredNetworkTypeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getPreferredNetworkTypeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::PreferredNetworkType nwType)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getNeighboringCidsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::NeighboringCell>& cells)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setLocationUpdatesResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setCdmaSubscriptionSourceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setCdmaRoamingPreferenceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getCdmaRoamingPreferenceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::CdmaRoamingType type)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setTTYModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getTTYModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::TtyMode mode)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setPreferredVoicePrivacyResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getPreferredVoicePrivacyResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool enable)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendCDMAFeatureCodeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendBurstDtmfResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendCdmaSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::acknowledgeLastIncomingCdmaSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getGsmBroadcastConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::GsmBroadcastSmsConfigInfo>& configs)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setGsmBroadcastConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setGsmBroadcastActivationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getCdmaBroadcastConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaBroadcastSmsConfigInfo>& configs)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setCdmaBroadcastConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setCdmaBroadcastActivationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getCDMASubscriptionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& mdn, const ::android::hardware::hidl_string& hSid, const ::android::hardware::hidl_string& hNid, const ::android::hardware::hidl_string& min, const ::android::hardware::hidl_string& prl)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::writeSmsToRuimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, uint32_t index)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::deleteSmsOnRuimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getDeviceIdentityResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& imei, const ::android::hardware::hidl_string& imeisv, const ::android::hardware::hidl_string& esn, const ::android::hardware::hidl_string& meid)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::exitEmergencyCallbackModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getSmscAddressResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& smsc)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setSmscAddressResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::reportSmsMemoryStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::reportStkServiceIsRunningResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getCdmaSubscriptionSourceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::CdmaSubscriptionSource source)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::requestIsimAuthenticationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& response)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::acknowledgeIncomingGsmSmsWithPduResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendEnvelopeWithStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& iccIo)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getVoiceRadioTechnologyResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::RadioTechnology rat)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getCellInfoListResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfo>& cellInfo)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setCellInfoListRateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setInitialAttachApnResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getImsRegistrationStateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool isRegistered, ::android::hardware::radio::V1_0::RadioTechnologyFamily ratFamily)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendImsSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::iccTransmitApduBasicChannelResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& result)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::iccOpenLogicalChannelResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t channelId, const ::android::hardware::hidl_vec<int8_t>& selectResponse)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::iccCloseLogicalChannelResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::iccTransmitApduLogicalChannelResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& result)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::nvReadItemResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& result)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::nvWriteItemResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::nvWriteCdmaPrlResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::nvResetConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setUiccSubscriptionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setDataAllowedResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getHardwareConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::HardwareConfig>& config)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::requestIccSimAuthenticationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& result)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setDataProfileResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::requestShutdownResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getRadioCapabilityResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::RadioCapability& rc)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setRadioCapabilityResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::RadioCapability& rc)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::startLceServiceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LceStatusInfo& statusInfo)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::stopLceServiceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LceStatusInfo& statusInfo)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::pullLceDataResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LceDataInfo& lceInfo)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getModemActivityInfoResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::ActivityStatsInfo& activityInfo)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setAllowedCarriersResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t numAllowed)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getAllowedCarriersResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool allAllowed, const ::android::hardware::radio::V1_0::CarrierRestrictions& carriers)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendDeviceStateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setIndicationFilterResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setSimCardPowerResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::acknowledgeRequest(int32_t serial)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IRadioResponse::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::radio::V1_0::IRadioResponse::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioResponse::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioResponse::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::radio::V1_0::IRadioResponse::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioResponse::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){188,60,140,35,48,133,252,163,135,157,199,75,73,11,158,91,193,6,50,88,71,13,59,76,18,247,167,75,242,21,203,189} /* bc3c8c233085fca3879dc74b490b9e5bc1063258470d3b4c12f7a74bf215cbbd */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioResponse::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IRadioResponse::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IRadioResponse::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioResponse::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hidl::base::V1_0::DebugInfo info = {};
    info.pid = -1;
    info.ptr = 0;
    info.arch = 
    #if defined(__LP64__)
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_64BIT
    #else
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_32BIT
    #endif
    ;
    _hidl_cb(info);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioResponse::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IRadioResponse::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::radio::V1_0::IRadioResponse>> IRadioResponse::castFrom(const ::android::sp<::android::hardware::radio::V1_0::IRadioResponse>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::radio::V1_0::IRadioResponse>> IRadioResponse::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioResponse, ::android::hidl::base::V1_0::IBase, BpHwRadioResponse>(
            parent, "android.hardware.radio@1.0::IRadioResponse", emitError);
}

BpHwRadioResponse::BpHwRadioResponse(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IRadioResponse>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.radio@1.0", "IRadioResponse") {
}

void BpHwRadioResponse::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IRadioResponse>::onLastStrongRef(id);
}
// Methods from ::android::hardware::radio::V1_0::IRadioResponse follow.
::android::hardware::Return<void> BpHwRadioResponse::_hidl_getIccCardStatusResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::CardStatus& cardStatus) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getIccCardStatusResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&cardStatus);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getIccCardStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_cardStatus_parent;

    _hidl_err = _hidl_data.writeBuffer(&cardStatus, sizeof(cardStatus), &_hidl_cardStatus_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            cardStatus,
            &_hidl_data,
            _hidl_cardStatus_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* getIccCardStatusResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getIccCardStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_supplyIccPinForAppResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::supplyIccPinForAppResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&remainingRetries);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPinForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(remainingRetries);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* supplyIccPinForAppResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPinForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_supplyIccPukForAppResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::supplyIccPukForAppResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&remainingRetries);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPukForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(remainingRetries);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* supplyIccPukForAppResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPukForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_supplyIccPin2ForAppResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::supplyIccPin2ForAppResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&remainingRetries);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPin2ForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(remainingRetries);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* supplyIccPin2ForAppResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPin2ForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_supplyIccPuk2ForAppResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::supplyIccPuk2ForAppResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&remainingRetries);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPuk2ForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(remainingRetries);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* supplyIccPuk2ForAppResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPuk2ForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_changeIccPinForAppResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::changeIccPinForAppResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&remainingRetries);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "changeIccPinForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(remainingRetries);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* changeIccPinForAppResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "changeIccPinForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_changeIccPin2ForAppResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::changeIccPin2ForAppResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&remainingRetries);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "changeIccPin2ForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(remainingRetries);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* changeIccPin2ForAppResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "changeIccPin2ForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_supplyNetworkDepersonalizationResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::supplyNetworkDepersonalizationResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&remainingRetries);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "supplyNetworkDepersonalizationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(remainingRetries);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* supplyNetworkDepersonalizationResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "supplyNetworkDepersonalizationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getCurrentCallsResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::Call>& calls) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCurrentCallsResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&calls);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCurrentCallsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_calls_parent;

    _hidl_err = _hidl_data.writeBuffer(&calls, sizeof(calls), &_hidl_calls_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_calls_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            calls,
            &_hidl_data,
            _hidl_calls_parent,
            0 /* parentOffset */, &_hidl_calls_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < calls.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                calls[_hidl_index_0],
                &_hidl_data,
                _hidl_calls_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::Call));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* getCurrentCallsResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCurrentCallsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_dialResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::dialResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "dialResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* dialResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "dialResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getIMSIForAppResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& imsi) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getIMSIForAppResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&imsi);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getIMSIForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_imsi_parent;

    _hidl_err = _hidl_data.writeBuffer(&imsi, sizeof(imsi), &_hidl_imsi_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            imsi,
            &_hidl_data,
            _hidl_imsi_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* getIMSIForAppResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getIMSIForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_hangupConnectionResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::hangupConnectionResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "hangupConnectionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* hangupConnectionResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "hangupConnectionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_hangupWaitingOrBackgroundResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::hangupWaitingOrBackgroundResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "hangupWaitingOrBackgroundResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* hangupWaitingOrBackgroundResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "hangupWaitingOrBackgroundResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_hangupForegroundResumeBackgroundResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::hangupForegroundResumeBackgroundResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "hangupForegroundResumeBackgroundResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(14 /* hangupForegroundResumeBackgroundResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "hangupForegroundResumeBackgroundResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_switchWaitingOrHoldingAndActiveResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::switchWaitingOrHoldingAndActiveResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "switchWaitingOrHoldingAndActiveResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(15 /* switchWaitingOrHoldingAndActiveResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "switchWaitingOrHoldingAndActiveResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_conferenceResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::conferenceResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "conferenceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(16 /* conferenceResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "conferenceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_rejectCallResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::rejectCallResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "rejectCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(17 /* rejectCallResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "rejectCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getLastCallFailCauseResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LastCallFailCauseInfo& failCauseinfo) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getLastCallFailCauseResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&failCauseinfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getLastCallFailCauseResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_failCauseinfo_parent;

    _hidl_err = _hidl_data.writeBuffer(&failCauseinfo, sizeof(failCauseinfo), &_hidl_failCauseinfo_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            failCauseinfo,
            &_hidl_data,
            _hidl_failCauseinfo_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(18 /* getLastCallFailCauseResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getLastCallFailCauseResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getSignalStrengthResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SignalStrength& sigStrength) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getSignalStrengthResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&sigStrength);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getSignalStrengthResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sigStrength_parent;

    _hidl_err = _hidl_data.writeBuffer(&sigStrength, sizeof(sigStrength), &_hidl_sigStrength_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(19 /* getSignalStrengthResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getSignalStrengthResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getVoiceRegistrationStateResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::VoiceRegStateResult& voiceRegResponse) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getVoiceRegistrationStateResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&voiceRegResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getVoiceRegistrationStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_voiceRegResponse_parent;

    _hidl_err = _hidl_data.writeBuffer(&voiceRegResponse, sizeof(voiceRegResponse), &_hidl_voiceRegResponse_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            voiceRegResponse,
            &_hidl_data,
            _hidl_voiceRegResponse_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(20 /* getVoiceRegistrationStateResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getVoiceRegistrationStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getDataRegistrationStateResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::DataRegStateResult& dataRegResponse) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getDataRegistrationStateResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&dataRegResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getDataRegistrationStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dataRegResponse_parent;

    _hidl_err = _hidl_data.writeBuffer(&dataRegResponse, sizeof(dataRegResponse), &_hidl_dataRegResponse_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            dataRegResponse,
            &_hidl_data,
            _hidl_dataRegResponse_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(21 /* getDataRegistrationStateResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getDataRegistrationStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getOperatorResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& longName, const ::android::hardware::hidl_string& shortName, const ::android::hardware::hidl_string& numeric) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getOperatorResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&longName);
        _hidl_args.push_back((void *)&shortName);
        _hidl_args.push_back((void *)&numeric);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getOperatorResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_longName_parent;

    _hidl_err = _hidl_data.writeBuffer(&longName, sizeof(longName), &_hidl_longName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            longName,
            &_hidl_data,
            _hidl_longName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_shortName_parent;

    _hidl_err = _hidl_data.writeBuffer(&shortName, sizeof(shortName), &_hidl_shortName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            shortName,
            &_hidl_data,
            _hidl_shortName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_numeric_parent;

    _hidl_err = _hidl_data.writeBuffer(&numeric, sizeof(numeric), &_hidl_numeric_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            numeric,
            &_hidl_data,
            _hidl_numeric_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(22 /* getOperatorResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getOperatorResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setRadioPowerResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setRadioPowerResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setRadioPowerResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(23 /* setRadioPowerResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setRadioPowerResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendDtmfResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendDtmfResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(24 /* sendDtmfResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendSmsResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendSmsResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&sms);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sms_parent;

    _hidl_err = _hidl_data.writeBuffer(&sms, sizeof(sms), &_hidl_sms_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            sms,
            &_hidl_data,
            _hidl_sms_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(25 /* sendSmsResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendSMSExpectMoreResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendSMSExpectMoreResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&sms);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendSMSExpectMoreResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sms_parent;

    _hidl_err = _hidl_data.writeBuffer(&sms, sizeof(sms), &_hidl_sms_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            sms,
            &_hidl_data,
            _hidl_sms_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(26 /* sendSMSExpectMoreResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendSMSExpectMoreResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setupDataCallResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SetupDataCallResult& dcResponse) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setupDataCallResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&dcResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setupDataCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dcResponse_parent;

    _hidl_err = _hidl_data.writeBuffer(&dcResponse, sizeof(dcResponse), &_hidl_dcResponse_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            dcResponse,
            &_hidl_data,
            _hidl_dcResponse_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(27 /* setupDataCallResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setupDataCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_iccIOForAppResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& iccIo) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::iccIOForAppResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&iccIo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "iccIOForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_iccIo_parent;

    _hidl_err = _hidl_data.writeBuffer(&iccIo, sizeof(iccIo), &_hidl_iccIo_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            iccIo,
            &_hidl_data,
            _hidl_iccIo_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(28 /* iccIOForAppResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "iccIOForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendUssdResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendUssdResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendUssdResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(29 /* sendUssdResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendUssdResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_cancelPendingUssdResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::cancelPendingUssdResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "cancelPendingUssdResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(30 /* cancelPendingUssdResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "cancelPendingUssdResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getClirResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t n, int32_t m) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getClirResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&n);
        _hidl_args.push_back((void *)&m);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getClirResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(n);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(m);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(31 /* getClirResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getClirResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setClirResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setClirResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setClirResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(32 /* setClirResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setClirResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getCallForwardStatusResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CallForwardInfo>& callForwardInfos) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCallForwardStatusResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&callForwardInfos);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCallForwardStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_callForwardInfos_parent;

    _hidl_err = _hidl_data.writeBuffer(&callForwardInfos, sizeof(callForwardInfos), &_hidl_callForwardInfos_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_callForwardInfos_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            callForwardInfos,
            &_hidl_data,
            _hidl_callForwardInfos_parent,
            0 /* parentOffset */, &_hidl_callForwardInfos_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < callForwardInfos.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                callForwardInfos[_hidl_index_0],
                &_hidl_data,
                _hidl_callForwardInfos_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CallForwardInfo));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(33 /* getCallForwardStatusResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCallForwardStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setCallForwardResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCallForwardResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setCallForwardResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(34 /* setCallForwardResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setCallForwardResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getCallWaitingResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool enable, int32_t serviceClass) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCallWaitingResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&enable);
        _hidl_args.push_back((void *)&serviceClass);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCallWaitingResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(enable);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(serviceClass);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(35 /* getCallWaitingResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCallWaitingResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setCallWaitingResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCallWaitingResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setCallWaitingResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(36 /* setCallWaitingResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setCallWaitingResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_acknowledgeLastIncomingGsmSmsResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::acknowledgeLastIncomingGsmSmsResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeLastIncomingGsmSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(37 /* acknowledgeLastIncomingGsmSmsResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeLastIncomingGsmSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_acceptCallResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::acceptCallResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "acceptCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(38 /* acceptCallResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "acceptCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_deactivateDataCallResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::deactivateDataCallResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "deactivateDataCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(39 /* deactivateDataCallResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "deactivateDataCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getFacilityLockForAppResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t response) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getFacilityLockForAppResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&response);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getFacilityLockForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(response);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(40 /* getFacilityLockForAppResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getFacilityLockForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setFacilityLockForAppResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t retry) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setFacilityLockForAppResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&retry);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setFacilityLockForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(retry);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(41 /* setFacilityLockForAppResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setFacilityLockForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setBarringPasswordResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setBarringPasswordResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setBarringPasswordResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(42 /* setBarringPasswordResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setBarringPasswordResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getNetworkSelectionModeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool manual) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getNetworkSelectionModeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&manual);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getNetworkSelectionModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(manual);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(43 /* getNetworkSelectionModeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getNetworkSelectionModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setNetworkSelectionModeAutomaticResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setNetworkSelectionModeAutomaticResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setNetworkSelectionModeAutomaticResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(44 /* setNetworkSelectionModeAutomaticResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setNetworkSelectionModeAutomaticResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setNetworkSelectionModeManualResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setNetworkSelectionModeManualResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setNetworkSelectionModeManualResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(45 /* setNetworkSelectionModeManualResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setNetworkSelectionModeManualResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getAvailableNetworksResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::OperatorInfo>& networkInfos) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getAvailableNetworksResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&networkInfos);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getAvailableNetworksResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_networkInfos_parent;

    _hidl_err = _hidl_data.writeBuffer(&networkInfos, sizeof(networkInfos), &_hidl_networkInfos_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_networkInfos_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            networkInfos,
            &_hidl_data,
            _hidl_networkInfos_parent,
            0 /* parentOffset */, &_hidl_networkInfos_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < networkInfos.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                networkInfos[_hidl_index_0],
                &_hidl_data,
                _hidl_networkInfos_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::OperatorInfo));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(46 /* getAvailableNetworksResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getAvailableNetworksResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_startDtmfResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::startDtmfResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "startDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(47 /* startDtmfResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "startDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_stopDtmfResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::stopDtmfResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "stopDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(48 /* stopDtmfResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "stopDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getBasebandVersionResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& version) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getBasebandVersionResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&version);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getBasebandVersionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_version_parent;

    _hidl_err = _hidl_data.writeBuffer(&version, sizeof(version), &_hidl_version_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            version,
            &_hidl_data,
            _hidl_version_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(49 /* getBasebandVersionResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getBasebandVersionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_separateConnectionResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::separateConnectionResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "separateConnectionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(50 /* separateConnectionResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "separateConnectionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setMuteResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setMuteResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setMuteResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(51 /* setMuteResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setMuteResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getMuteResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool enable) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getMuteResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&enable);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getMuteResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(enable);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(52 /* getMuteResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getMuteResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getClipResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::ClipStatus status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getClipResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getClipResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(53 /* getClipResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getClipResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getDataCallListResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::SetupDataCallResult>& dcResponse) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getDataCallListResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&dcResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getDataCallListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dcResponse_parent;

    _hidl_err = _hidl_data.writeBuffer(&dcResponse, sizeof(dcResponse), &_hidl_dcResponse_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dcResponse_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            dcResponse,
            &_hidl_data,
            _hidl_dcResponse_parent,
            0 /* parentOffset */, &_hidl_dcResponse_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < dcResponse.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                dcResponse[_hidl_index_0],
                &_hidl_data,
                _hidl_dcResponse_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::SetupDataCallResult));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(54 /* getDataCallListResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getDataCallListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setSuppServiceNotificationsResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setSuppServiceNotificationsResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setSuppServiceNotificationsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(55 /* setSuppServiceNotificationsResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setSuppServiceNotificationsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_writeSmsToSimResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t index) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::writeSmsToSimResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&index);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "writeSmsToSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(index);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(56 /* writeSmsToSimResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "writeSmsToSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_deleteSmsOnSimResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::deleteSmsOnSimResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "deleteSmsOnSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(57 /* deleteSmsOnSimResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "deleteSmsOnSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setBandModeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setBandModeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setBandModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(58 /* setBandModeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setBandModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getAvailableBandModesResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::RadioBandMode>& bandModes) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getAvailableBandModesResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&bandModes);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getAvailableBandModesResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_bandModes_parent;

    _hidl_err = _hidl_data.writeBuffer(&bandModes, sizeof(bandModes), &_hidl_bandModes_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_bandModes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            bandModes,
            &_hidl_data,
            _hidl_bandModes_parent,
            0 /* parentOffset */, &_hidl_bandModes_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(59 /* getAvailableBandModesResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getAvailableBandModesResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendEnvelopeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& commandResponse) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendEnvelopeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&commandResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendEnvelopeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_commandResponse_parent;

    _hidl_err = _hidl_data.writeBuffer(&commandResponse, sizeof(commandResponse), &_hidl_commandResponse_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            commandResponse,
            &_hidl_data,
            _hidl_commandResponse_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(60 /* sendEnvelopeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendEnvelopeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendTerminalResponseToSimResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendTerminalResponseToSimResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendTerminalResponseToSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(61 /* sendTerminalResponseToSimResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendTerminalResponseToSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_handleStkCallSetupRequestFromSimResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::handleStkCallSetupRequestFromSimResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "handleStkCallSetupRequestFromSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(62 /* handleStkCallSetupRequestFromSimResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "handleStkCallSetupRequestFromSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_explicitCallTransferResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::explicitCallTransferResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "explicitCallTransferResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(63 /* explicitCallTransferResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "explicitCallTransferResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setPreferredNetworkTypeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setPreferredNetworkTypeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setPreferredNetworkTypeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(64 /* setPreferredNetworkTypeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setPreferredNetworkTypeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getPreferredNetworkTypeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::PreferredNetworkType nwType) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getPreferredNetworkTypeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&nwType);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getPreferredNetworkTypeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)nwType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(65 /* getPreferredNetworkTypeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getPreferredNetworkTypeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getNeighboringCidsResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::NeighboringCell>& cells) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getNeighboringCidsResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&cells);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getNeighboringCidsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_cells_parent;

    _hidl_err = _hidl_data.writeBuffer(&cells, sizeof(cells), &_hidl_cells_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_cells_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            cells,
            &_hidl_data,
            _hidl_cells_parent,
            0 /* parentOffset */, &_hidl_cells_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < cells.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                cells[_hidl_index_0],
                &_hidl_data,
                _hidl_cells_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::NeighboringCell));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(66 /* getNeighboringCidsResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getNeighboringCidsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setLocationUpdatesResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setLocationUpdatesResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setLocationUpdatesResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(67 /* setLocationUpdatesResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setLocationUpdatesResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setCdmaSubscriptionSourceResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCdmaSubscriptionSourceResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaSubscriptionSourceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(68 /* setCdmaSubscriptionSourceResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaSubscriptionSourceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setCdmaRoamingPreferenceResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCdmaRoamingPreferenceResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaRoamingPreferenceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(69 /* setCdmaRoamingPreferenceResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaRoamingPreferenceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getCdmaRoamingPreferenceResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::CdmaRoamingType type) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCdmaRoamingPreferenceResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&type);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCdmaRoamingPreferenceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(70 /* getCdmaRoamingPreferenceResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCdmaRoamingPreferenceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setTTYModeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setTTYModeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setTTYModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(71 /* setTTYModeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setTTYModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getTTYModeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::TtyMode mode) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getTTYModeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&mode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getTTYModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)mode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(72 /* getTTYModeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getTTYModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setPreferredVoicePrivacyResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setPreferredVoicePrivacyResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setPreferredVoicePrivacyResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(73 /* setPreferredVoicePrivacyResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setPreferredVoicePrivacyResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getPreferredVoicePrivacyResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool enable) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getPreferredVoicePrivacyResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&enable);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getPreferredVoicePrivacyResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(enable);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(74 /* getPreferredVoicePrivacyResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getPreferredVoicePrivacyResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendCDMAFeatureCodeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendCDMAFeatureCodeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendCDMAFeatureCodeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(75 /* sendCDMAFeatureCodeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendCDMAFeatureCodeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendBurstDtmfResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendBurstDtmfResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendBurstDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(76 /* sendBurstDtmfResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendBurstDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendCdmaSmsResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendCdmaSmsResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&sms);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendCdmaSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sms_parent;

    _hidl_err = _hidl_data.writeBuffer(&sms, sizeof(sms), &_hidl_sms_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            sms,
            &_hidl_data,
            _hidl_sms_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(77 /* sendCdmaSmsResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendCdmaSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_acknowledgeLastIncomingCdmaSmsResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::acknowledgeLastIncomingCdmaSmsResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeLastIncomingCdmaSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(78 /* acknowledgeLastIncomingCdmaSmsResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeLastIncomingCdmaSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getGsmBroadcastConfigResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::GsmBroadcastSmsConfigInfo>& configs) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getGsmBroadcastConfigResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&configs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getGsmBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_configs_parent;

    _hidl_err = _hidl_data.writeBuffer(&configs, sizeof(configs), &_hidl_configs_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_configs_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            configs,
            &_hidl_data,
            _hidl_configs_parent,
            0 /* parentOffset */, &_hidl_configs_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(79 /* getGsmBroadcastConfigResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getGsmBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setGsmBroadcastConfigResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setGsmBroadcastConfigResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setGsmBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(80 /* setGsmBroadcastConfigResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setGsmBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setGsmBroadcastActivationResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setGsmBroadcastActivationResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setGsmBroadcastActivationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(81 /* setGsmBroadcastActivationResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setGsmBroadcastActivationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getCdmaBroadcastConfigResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaBroadcastSmsConfigInfo>& configs) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCdmaBroadcastConfigResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&configs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCdmaBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_configs_parent;

    _hidl_err = _hidl_data.writeBuffer(&configs, sizeof(configs), &_hidl_configs_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_configs_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            configs,
            &_hidl_data,
            _hidl_configs_parent,
            0 /* parentOffset */, &_hidl_configs_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(82 /* getCdmaBroadcastConfigResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCdmaBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setCdmaBroadcastConfigResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCdmaBroadcastConfigResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(83 /* setCdmaBroadcastConfigResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setCdmaBroadcastActivationResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCdmaBroadcastActivationResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaBroadcastActivationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(84 /* setCdmaBroadcastActivationResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaBroadcastActivationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getCDMASubscriptionResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& mdn, const ::android::hardware::hidl_string& hSid, const ::android::hardware::hidl_string& hNid, const ::android::hardware::hidl_string& min, const ::android::hardware::hidl_string& prl) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCDMASubscriptionResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&mdn);
        _hidl_args.push_back((void *)&hSid);
        _hidl_args.push_back((void *)&hNid);
        _hidl_args.push_back((void *)&min);
        _hidl_args.push_back((void *)&prl);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCDMASubscriptionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_mdn_parent;

    _hidl_err = _hidl_data.writeBuffer(&mdn, sizeof(mdn), &_hidl_mdn_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            mdn,
            &_hidl_data,
            _hidl_mdn_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_hSid_parent;

    _hidl_err = _hidl_data.writeBuffer(&hSid, sizeof(hSid), &_hidl_hSid_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            hSid,
            &_hidl_data,
            _hidl_hSid_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_hNid_parent;

    _hidl_err = _hidl_data.writeBuffer(&hNid, sizeof(hNid), &_hidl_hNid_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            hNid,
            &_hidl_data,
            _hidl_hNid_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_min_parent;

    _hidl_err = _hidl_data.writeBuffer(&min, sizeof(min), &_hidl_min_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            min,
            &_hidl_data,
            _hidl_min_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_prl_parent;

    _hidl_err = _hidl_data.writeBuffer(&prl, sizeof(prl), &_hidl_prl_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            prl,
            &_hidl_data,
            _hidl_prl_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(85 /* getCDMASubscriptionResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCDMASubscriptionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_writeSmsToRuimResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, uint32_t index) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::writeSmsToRuimResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&index);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "writeSmsToRuimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(index);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(86 /* writeSmsToRuimResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "writeSmsToRuimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_deleteSmsOnRuimResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::deleteSmsOnRuimResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "deleteSmsOnRuimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(87 /* deleteSmsOnRuimResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "deleteSmsOnRuimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getDeviceIdentityResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& imei, const ::android::hardware::hidl_string& imeisv, const ::android::hardware::hidl_string& esn, const ::android::hardware::hidl_string& meid) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getDeviceIdentityResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&imei);
        _hidl_args.push_back((void *)&imeisv);
        _hidl_args.push_back((void *)&esn);
        _hidl_args.push_back((void *)&meid);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getDeviceIdentityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_imei_parent;

    _hidl_err = _hidl_data.writeBuffer(&imei, sizeof(imei), &_hidl_imei_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            imei,
            &_hidl_data,
            _hidl_imei_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_imeisv_parent;

    _hidl_err = _hidl_data.writeBuffer(&imeisv, sizeof(imeisv), &_hidl_imeisv_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            imeisv,
            &_hidl_data,
            _hidl_imeisv_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_esn_parent;

    _hidl_err = _hidl_data.writeBuffer(&esn, sizeof(esn), &_hidl_esn_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            esn,
            &_hidl_data,
            _hidl_esn_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_meid_parent;

    _hidl_err = _hidl_data.writeBuffer(&meid, sizeof(meid), &_hidl_meid_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            meid,
            &_hidl_data,
            _hidl_meid_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(88 /* getDeviceIdentityResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getDeviceIdentityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_exitEmergencyCallbackModeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::exitEmergencyCallbackModeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "exitEmergencyCallbackModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(89 /* exitEmergencyCallbackModeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "exitEmergencyCallbackModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getSmscAddressResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& smsc) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getSmscAddressResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&smsc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getSmscAddressResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_smsc_parent;

    _hidl_err = _hidl_data.writeBuffer(&smsc, sizeof(smsc), &_hidl_smsc_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            smsc,
            &_hidl_data,
            _hidl_smsc_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(90 /* getSmscAddressResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getSmscAddressResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setSmscAddressResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setSmscAddressResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setSmscAddressResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(91 /* setSmscAddressResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setSmscAddressResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_reportSmsMemoryStatusResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::reportSmsMemoryStatusResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "reportSmsMemoryStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(92 /* reportSmsMemoryStatusResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "reportSmsMemoryStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_reportStkServiceIsRunningResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::reportStkServiceIsRunningResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "reportStkServiceIsRunningResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(93 /* reportStkServiceIsRunningResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "reportStkServiceIsRunningResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getCdmaSubscriptionSourceResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::CdmaSubscriptionSource source) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCdmaSubscriptionSourceResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&source);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCdmaSubscriptionSourceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)source);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(94 /* getCdmaSubscriptionSourceResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCdmaSubscriptionSourceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_requestIsimAuthenticationResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& response) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::requestIsimAuthenticationResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&response);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "requestIsimAuthenticationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_response_parent;

    _hidl_err = _hidl_data.writeBuffer(&response, sizeof(response), &_hidl_response_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            response,
            &_hidl_data,
            _hidl_response_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(95 /* requestIsimAuthenticationResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "requestIsimAuthenticationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_acknowledgeIncomingGsmSmsWithPduResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::acknowledgeIncomingGsmSmsWithPduResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeIncomingGsmSmsWithPduResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(96 /* acknowledgeIncomingGsmSmsWithPduResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeIncomingGsmSmsWithPduResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendEnvelopeWithStatusResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& iccIo) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendEnvelopeWithStatusResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&iccIo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendEnvelopeWithStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_iccIo_parent;

    _hidl_err = _hidl_data.writeBuffer(&iccIo, sizeof(iccIo), &_hidl_iccIo_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            iccIo,
            &_hidl_data,
            _hidl_iccIo_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(97 /* sendEnvelopeWithStatusResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendEnvelopeWithStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getVoiceRadioTechnologyResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::RadioTechnology rat) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getVoiceRadioTechnologyResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&rat);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getVoiceRadioTechnologyResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)rat);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(98 /* getVoiceRadioTechnologyResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getVoiceRadioTechnologyResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getCellInfoListResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfo>& cellInfo) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCellInfoListResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&cellInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCellInfoListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_cellInfo_parent;

    _hidl_err = _hidl_data.writeBuffer(&cellInfo, sizeof(cellInfo), &_hidl_cellInfo_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_cellInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            cellInfo,
            &_hidl_data,
            _hidl_cellInfo_parent,
            0 /* parentOffset */, &_hidl_cellInfo_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < cellInfo.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                cellInfo[_hidl_index_0],
                &_hidl_data,
                _hidl_cellInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellInfo));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(99 /* getCellInfoListResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCellInfoListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setCellInfoListRateResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCellInfoListRateResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setCellInfoListRateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(100 /* setCellInfoListRateResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setCellInfoListRateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setInitialAttachApnResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setInitialAttachApnResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setInitialAttachApnResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(101 /* setInitialAttachApnResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setInitialAttachApnResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getImsRegistrationStateResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool isRegistered, ::android::hardware::radio::V1_0::RadioTechnologyFamily ratFamily) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getImsRegistrationStateResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&isRegistered);
        _hidl_args.push_back((void *)&ratFamily);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getImsRegistrationStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(isRegistered);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)ratFamily);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(102 /* getImsRegistrationStateResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getImsRegistrationStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendImsSmsResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendImsSmsResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&sms);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendImsSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sms_parent;

    _hidl_err = _hidl_data.writeBuffer(&sms, sizeof(sms), &_hidl_sms_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            sms,
            &_hidl_data,
            _hidl_sms_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(103 /* sendImsSmsResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendImsSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_iccTransmitApduBasicChannelResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& result) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::iccTransmitApduBasicChannelResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&result);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "iccTransmitApduBasicChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_result_parent;

    _hidl_err = _hidl_data.writeBuffer(&result, sizeof(result), &_hidl_result_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            result,
            &_hidl_data,
            _hidl_result_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(104 /* iccTransmitApduBasicChannelResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "iccTransmitApduBasicChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_iccOpenLogicalChannelResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t channelId, const ::android::hardware::hidl_vec<int8_t>& selectResponse) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::iccOpenLogicalChannelResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&channelId);
        _hidl_args.push_back((void *)&selectResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "iccOpenLogicalChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(channelId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_selectResponse_parent;

    _hidl_err = _hidl_data.writeBuffer(&selectResponse, sizeof(selectResponse), &_hidl_selectResponse_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_selectResponse_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            selectResponse,
            &_hidl_data,
            _hidl_selectResponse_parent,
            0 /* parentOffset */, &_hidl_selectResponse_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(105 /* iccOpenLogicalChannelResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "iccOpenLogicalChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_iccCloseLogicalChannelResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::iccCloseLogicalChannelResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "iccCloseLogicalChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(106 /* iccCloseLogicalChannelResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "iccCloseLogicalChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_iccTransmitApduLogicalChannelResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& result) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::iccTransmitApduLogicalChannelResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&result);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "iccTransmitApduLogicalChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_result_parent;

    _hidl_err = _hidl_data.writeBuffer(&result, sizeof(result), &_hidl_result_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            result,
            &_hidl_data,
            _hidl_result_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(107 /* iccTransmitApduLogicalChannelResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "iccTransmitApduLogicalChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_nvReadItemResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& result) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::nvReadItemResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&result);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "nvReadItemResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_result_parent;

    _hidl_err = _hidl_data.writeBuffer(&result, sizeof(result), &_hidl_result_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            result,
            &_hidl_data,
            _hidl_result_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(108 /* nvReadItemResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "nvReadItemResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_nvWriteItemResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::nvWriteItemResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "nvWriteItemResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(109 /* nvWriteItemResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "nvWriteItemResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_nvWriteCdmaPrlResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::nvWriteCdmaPrlResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "nvWriteCdmaPrlResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(110 /* nvWriteCdmaPrlResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "nvWriteCdmaPrlResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_nvResetConfigResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::nvResetConfigResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "nvResetConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(111 /* nvResetConfigResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "nvResetConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setUiccSubscriptionResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setUiccSubscriptionResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setUiccSubscriptionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(112 /* setUiccSubscriptionResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setUiccSubscriptionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setDataAllowedResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setDataAllowedResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setDataAllowedResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(113 /* setDataAllowedResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setDataAllowedResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getHardwareConfigResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::HardwareConfig>& config) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getHardwareConfigResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&config);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getHardwareConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_config_parent;

    _hidl_err = _hidl_data.writeBuffer(&config, sizeof(config), &_hidl_config_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_config_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            config,
            &_hidl_data,
            _hidl_config_parent,
            0 /* parentOffset */, &_hidl_config_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < config.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                config[_hidl_index_0],
                &_hidl_data,
                _hidl_config_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::HardwareConfig));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(114 /* getHardwareConfigResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getHardwareConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_requestIccSimAuthenticationResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& result) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::requestIccSimAuthenticationResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&result);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "requestIccSimAuthenticationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_result_parent;

    _hidl_err = _hidl_data.writeBuffer(&result, sizeof(result), &_hidl_result_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            result,
            &_hidl_data,
            _hidl_result_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(115 /* requestIccSimAuthenticationResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "requestIccSimAuthenticationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setDataProfileResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setDataProfileResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setDataProfileResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(116 /* setDataProfileResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setDataProfileResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_requestShutdownResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::requestShutdownResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "requestShutdownResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(117 /* requestShutdownResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "requestShutdownResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getRadioCapabilityResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::RadioCapability& rc) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getRadioCapabilityResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&rc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getRadioCapabilityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_rc_parent;

    _hidl_err = _hidl_data.writeBuffer(&rc, sizeof(rc), &_hidl_rc_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            rc,
            &_hidl_data,
            _hidl_rc_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(118 /* getRadioCapabilityResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getRadioCapabilityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setRadioCapabilityResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::RadioCapability& rc) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setRadioCapabilityResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&rc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setRadioCapabilityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_rc_parent;

    _hidl_err = _hidl_data.writeBuffer(&rc, sizeof(rc), &_hidl_rc_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            rc,
            &_hidl_data,
            _hidl_rc_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(119 /* setRadioCapabilityResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setRadioCapabilityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_startLceServiceResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LceStatusInfo& statusInfo) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::startLceServiceResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&statusInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "startLceServiceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_statusInfo_parent;

    _hidl_err = _hidl_data.writeBuffer(&statusInfo, sizeof(statusInfo), &_hidl_statusInfo_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(120 /* startLceServiceResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "startLceServiceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_stopLceServiceResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LceStatusInfo& statusInfo) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::stopLceServiceResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&statusInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "stopLceServiceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_statusInfo_parent;

    _hidl_err = _hidl_data.writeBuffer(&statusInfo, sizeof(statusInfo), &_hidl_statusInfo_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(121 /* stopLceServiceResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "stopLceServiceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_pullLceDataResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LceDataInfo& lceInfo) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::pullLceDataResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&lceInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "pullLceDataResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_lceInfo_parent;

    _hidl_err = _hidl_data.writeBuffer(&lceInfo, sizeof(lceInfo), &_hidl_lceInfo_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(122 /* pullLceDataResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "pullLceDataResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getModemActivityInfoResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::ActivityStatsInfo& activityInfo) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getModemActivityInfoResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&activityInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getModemActivityInfoResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_activityInfo_parent;

    _hidl_err = _hidl_data.writeBuffer(&activityInfo, sizeof(activityInfo), &_hidl_activityInfo_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(123 /* getModemActivityInfoResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getModemActivityInfoResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setAllowedCarriersResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t numAllowed) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setAllowedCarriersResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&numAllowed);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setAllowedCarriersResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(numAllowed);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(124 /* setAllowedCarriersResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setAllowedCarriersResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getAllowedCarriersResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool allAllowed, const ::android::hardware::radio::V1_0::CarrierRestrictions& carriers) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getAllowedCarriersResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&allAllowed);
        _hidl_args.push_back((void *)&carriers);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getAllowedCarriersResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(allAllowed);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_carriers_parent;

    _hidl_err = _hidl_data.writeBuffer(&carriers, sizeof(carriers), &_hidl_carriers_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            carriers,
            &_hidl_data,
            _hidl_carriers_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(125 /* getAllowedCarriersResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getAllowedCarriersResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendDeviceStateResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendDeviceStateResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendDeviceStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(126 /* sendDeviceStateResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendDeviceStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setIndicationFilterResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setIndicationFilterResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setIndicationFilterResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(127 /* setIndicationFilterResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setIndicationFilterResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setSimCardPowerResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setSimCardPowerResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setSimCardPowerResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(128 /* setSimCardPowerResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setSimCardPowerResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_acknowledgeRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t serial) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::acknowledgeRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(serial);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(129 /* acknowledgeRequest */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::radio::V1_0::IRadioResponse follow.
::android::hardware::Return<void> BpHwRadioResponse::getIccCardStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::CardStatus& cardStatus){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getIccCardStatusResponse(this, this, info, cardStatus);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::supplyIccPinForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_supplyIccPinForAppResponse(this, this, info, remainingRetries);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::supplyIccPukForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_supplyIccPukForAppResponse(this, this, info, remainingRetries);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::supplyIccPin2ForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_supplyIccPin2ForAppResponse(this, this, info, remainingRetries);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::supplyIccPuk2ForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_supplyIccPuk2ForAppResponse(this, this, info, remainingRetries);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::changeIccPinForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_changeIccPinForAppResponse(this, this, info, remainingRetries);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::changeIccPin2ForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_changeIccPin2ForAppResponse(this, this, info, remainingRetries);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::supplyNetworkDepersonalizationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t remainingRetries){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_supplyNetworkDepersonalizationResponse(this, this, info, remainingRetries);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getCurrentCallsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::Call>& calls){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getCurrentCallsResponse(this, this, info, calls);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::dialResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_dialResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getIMSIForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& imsi){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getIMSIForAppResponse(this, this, info, imsi);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::hangupConnectionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_hangupConnectionResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::hangupWaitingOrBackgroundResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_hangupWaitingOrBackgroundResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::hangupForegroundResumeBackgroundResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_hangupForegroundResumeBackgroundResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::switchWaitingOrHoldingAndActiveResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_switchWaitingOrHoldingAndActiveResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::conferenceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_conferenceResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::rejectCallResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_rejectCallResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getLastCallFailCauseResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LastCallFailCauseInfo& failCauseinfo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getLastCallFailCauseResponse(this, this, info, failCauseinfo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getSignalStrengthResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SignalStrength& sigStrength){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getSignalStrengthResponse(this, this, info, sigStrength);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getVoiceRegistrationStateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::VoiceRegStateResult& voiceRegResponse){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getVoiceRegistrationStateResponse(this, this, info, voiceRegResponse);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getDataRegistrationStateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::DataRegStateResult& dataRegResponse){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getDataRegistrationStateResponse(this, this, info, dataRegResponse);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getOperatorResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& longName, const ::android::hardware::hidl_string& shortName, const ::android::hardware::hidl_string& numeric){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getOperatorResponse(this, this, info, longName, shortName, numeric);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setRadioPowerResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setRadioPowerResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendDtmfResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_sendDtmfResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_sendSmsResponse(this, this, info, sms);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendSMSExpectMoreResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_sendSMSExpectMoreResponse(this, this, info, sms);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setupDataCallResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SetupDataCallResult& dcResponse){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setupDataCallResponse(this, this, info, dcResponse);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::iccIOForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& iccIo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_iccIOForAppResponse(this, this, info, iccIo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendUssdResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_sendUssdResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::cancelPendingUssdResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_cancelPendingUssdResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getClirResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t n, int32_t m){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getClirResponse(this, this, info, n, m);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setClirResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setClirResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getCallForwardStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CallForwardInfo>& callForwardInfos){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getCallForwardStatusResponse(this, this, info, callForwardInfos);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setCallForwardResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setCallForwardResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getCallWaitingResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool enable, int32_t serviceClass){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getCallWaitingResponse(this, this, info, enable, serviceClass);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setCallWaitingResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setCallWaitingResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::acknowledgeLastIncomingGsmSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_acknowledgeLastIncomingGsmSmsResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::acceptCallResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_acceptCallResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::deactivateDataCallResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_deactivateDataCallResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getFacilityLockForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t response){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getFacilityLockForAppResponse(this, this, info, response);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setFacilityLockForAppResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t retry){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setFacilityLockForAppResponse(this, this, info, retry);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setBarringPasswordResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setBarringPasswordResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getNetworkSelectionModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool manual){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getNetworkSelectionModeResponse(this, this, info, manual);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setNetworkSelectionModeAutomaticResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setNetworkSelectionModeAutomaticResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setNetworkSelectionModeManualResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setNetworkSelectionModeManualResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getAvailableNetworksResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::OperatorInfo>& networkInfos){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getAvailableNetworksResponse(this, this, info, networkInfos);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::startDtmfResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_startDtmfResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::stopDtmfResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_stopDtmfResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getBasebandVersionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& version){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getBasebandVersionResponse(this, this, info, version);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::separateConnectionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_separateConnectionResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setMuteResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setMuteResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getMuteResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool enable){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getMuteResponse(this, this, info, enable);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getClipResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::ClipStatus status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getClipResponse(this, this, info, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getDataCallListResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::SetupDataCallResult>& dcResponse){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getDataCallListResponse(this, this, info, dcResponse);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setSuppServiceNotificationsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setSuppServiceNotificationsResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::writeSmsToSimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t index){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_writeSmsToSimResponse(this, this, info, index);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::deleteSmsOnSimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_deleteSmsOnSimResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setBandModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setBandModeResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getAvailableBandModesResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::RadioBandMode>& bandModes){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getAvailableBandModesResponse(this, this, info, bandModes);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendEnvelopeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& commandResponse){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_sendEnvelopeResponse(this, this, info, commandResponse);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendTerminalResponseToSimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_sendTerminalResponseToSimResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::handleStkCallSetupRequestFromSimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_handleStkCallSetupRequestFromSimResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::explicitCallTransferResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_explicitCallTransferResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setPreferredNetworkTypeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setPreferredNetworkTypeResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getPreferredNetworkTypeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::PreferredNetworkType nwType){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getPreferredNetworkTypeResponse(this, this, info, nwType);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getNeighboringCidsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::NeighboringCell>& cells){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getNeighboringCidsResponse(this, this, info, cells);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setLocationUpdatesResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setLocationUpdatesResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setCdmaSubscriptionSourceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setCdmaSubscriptionSourceResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setCdmaRoamingPreferenceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setCdmaRoamingPreferenceResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getCdmaRoamingPreferenceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::CdmaRoamingType type){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getCdmaRoamingPreferenceResponse(this, this, info, type);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setTTYModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setTTYModeResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getTTYModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::TtyMode mode){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getTTYModeResponse(this, this, info, mode);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setPreferredVoicePrivacyResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setPreferredVoicePrivacyResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getPreferredVoicePrivacyResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool enable){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getPreferredVoicePrivacyResponse(this, this, info, enable);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendCDMAFeatureCodeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_sendCDMAFeatureCodeResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendBurstDtmfResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_sendBurstDtmfResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendCdmaSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_sendCdmaSmsResponse(this, this, info, sms);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::acknowledgeLastIncomingCdmaSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_acknowledgeLastIncomingCdmaSmsResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getGsmBroadcastConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::GsmBroadcastSmsConfigInfo>& configs){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getGsmBroadcastConfigResponse(this, this, info, configs);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setGsmBroadcastConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setGsmBroadcastConfigResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setGsmBroadcastActivationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setGsmBroadcastActivationResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getCdmaBroadcastConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaBroadcastSmsConfigInfo>& configs){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getCdmaBroadcastConfigResponse(this, this, info, configs);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setCdmaBroadcastConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setCdmaBroadcastConfigResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setCdmaBroadcastActivationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setCdmaBroadcastActivationResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getCDMASubscriptionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& mdn, const ::android::hardware::hidl_string& hSid, const ::android::hardware::hidl_string& hNid, const ::android::hardware::hidl_string& min, const ::android::hardware::hidl_string& prl){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getCDMASubscriptionResponse(this, this, info, mdn, hSid, hNid, min, prl);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::writeSmsToRuimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, uint32_t index){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_writeSmsToRuimResponse(this, this, info, index);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::deleteSmsOnRuimResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_deleteSmsOnRuimResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getDeviceIdentityResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& imei, const ::android::hardware::hidl_string& imeisv, const ::android::hardware::hidl_string& esn, const ::android::hardware::hidl_string& meid){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getDeviceIdentityResponse(this, this, info, imei, imeisv, esn, meid);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::exitEmergencyCallbackModeResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_exitEmergencyCallbackModeResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getSmscAddressResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& smsc){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getSmscAddressResponse(this, this, info, smsc);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setSmscAddressResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setSmscAddressResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::reportSmsMemoryStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_reportSmsMemoryStatusResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::reportStkServiceIsRunningResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_reportStkServiceIsRunningResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getCdmaSubscriptionSourceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::CdmaSubscriptionSource source){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getCdmaSubscriptionSourceResponse(this, this, info, source);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::requestIsimAuthenticationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& response){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_requestIsimAuthenticationResponse(this, this, info, response);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::acknowledgeIncomingGsmSmsWithPduResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_acknowledgeIncomingGsmSmsWithPduResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendEnvelopeWithStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& iccIo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_sendEnvelopeWithStatusResponse(this, this, info, iccIo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getVoiceRadioTechnologyResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, ::android::hardware::radio::V1_0::RadioTechnology rat){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getVoiceRadioTechnologyResponse(this, this, info, rat);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getCellInfoListResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfo>& cellInfo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getCellInfoListResponse(this, this, info, cellInfo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setCellInfoListRateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setCellInfoListRateResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setInitialAttachApnResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setInitialAttachApnResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getImsRegistrationStateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool isRegistered, ::android::hardware::radio::V1_0::RadioTechnologyFamily ratFamily){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getImsRegistrationStateResponse(this, this, info, isRegistered, ratFamily);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendImsSmsResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::SendSmsResult& sms){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_sendImsSmsResponse(this, this, info, sms);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::iccTransmitApduBasicChannelResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& result){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_iccTransmitApduBasicChannelResponse(this, this, info, result);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::iccOpenLogicalChannelResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t channelId, const ::android::hardware::hidl_vec<int8_t>& selectResponse){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_iccOpenLogicalChannelResponse(this, this, info, channelId, selectResponse);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::iccCloseLogicalChannelResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_iccCloseLogicalChannelResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::iccTransmitApduLogicalChannelResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& result){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_iccTransmitApduLogicalChannelResponse(this, this, info, result);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::nvReadItemResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_string& result){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_nvReadItemResponse(this, this, info, result);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::nvWriteItemResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_nvWriteItemResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::nvWriteCdmaPrlResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_nvWriteCdmaPrlResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::nvResetConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_nvResetConfigResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setUiccSubscriptionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setUiccSubscriptionResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setDataAllowedResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setDataAllowedResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getHardwareConfigResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::HardwareConfig>& config){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getHardwareConfigResponse(this, this, info, config);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::requestIccSimAuthenticationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::IccIoResult& result){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_requestIccSimAuthenticationResponse(this, this, info, result);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setDataProfileResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setDataProfileResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::requestShutdownResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_requestShutdownResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getRadioCapabilityResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::RadioCapability& rc){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getRadioCapabilityResponse(this, this, info, rc);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setRadioCapabilityResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::RadioCapability& rc){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setRadioCapabilityResponse(this, this, info, rc);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::startLceServiceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LceStatusInfo& statusInfo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_startLceServiceResponse(this, this, info, statusInfo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::stopLceServiceResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LceStatusInfo& statusInfo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_stopLceServiceResponse(this, this, info, statusInfo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::pullLceDataResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::LceDataInfo& lceInfo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_pullLceDataResponse(this, this, info, lceInfo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getModemActivityInfoResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_0::ActivityStatsInfo& activityInfo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getModemActivityInfoResponse(this, this, info, activityInfo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setAllowedCarriersResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, int32_t numAllowed){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setAllowedCarriersResponse(this, this, info, numAllowed);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getAllowedCarriersResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, bool allAllowed, const ::android::hardware::radio::V1_0::CarrierRestrictions& carriers){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_getAllowedCarriersResponse(this, this, info, allAllowed, carriers);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendDeviceStateResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_sendDeviceStateResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setIndicationFilterResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setIndicationFilterResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setSimCardPowerResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_setSimCardPowerResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::acknowledgeRequest(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioResponse::_hidl_acknowledgeRequest(this, this, serial);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwRadioResponse::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwRadioResponse::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwRadioResponse::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwRadioResponse::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    for (auto it = _hidl_mDeathRecipients.rbegin();it != _hidl_mDeathRecipients.rend();++it) {
        if ((*it)->getRecipient() == recipient) {
            ::android::status_t status = remote()->unlinkToDeath(*it);
            _hidl_mDeathRecipients.erase(it.base()-1);
            return status == ::android::OK;
        }
    }
    return false;
}


BnHwRadioResponse::BnHwRadioResponse(const ::android::sp<IRadioResponse> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.radio@1.0", "IRadioResponse") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwRadioResponse::~BnHwRadioResponse() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::radio::V1_0::IRadioResponse follow.
::android::status_t BnHwRadioResponse::_hidl_getIccCardStatusResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::CardStatus* cardStatus;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_cardStatus_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*cardStatus), &_hidl_cardStatus_parent,  const_cast<const void**>(reinterpret_cast<void **>(&cardStatus)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::CardStatus &>(*cardStatus),
            _hidl_data,
            _hidl_cardStatus_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getIccCardStatusResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)cardStatus);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getIccCardStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getIccCardStatusResponse(*info, *cardStatus);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getIccCardStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_supplyIccPinForAppResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    int32_t remainingRetries;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&remainingRetries);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::supplyIccPinForAppResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&remainingRetries);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPinForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->supplyIccPinForAppResponse(*info, remainingRetries);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPinForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_supplyIccPukForAppResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    int32_t remainingRetries;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&remainingRetries);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::supplyIccPukForAppResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&remainingRetries);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPukForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->supplyIccPukForAppResponse(*info, remainingRetries);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPukForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_supplyIccPin2ForAppResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    int32_t remainingRetries;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&remainingRetries);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::supplyIccPin2ForAppResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&remainingRetries);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPin2ForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->supplyIccPin2ForAppResponse(*info, remainingRetries);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPin2ForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_supplyIccPuk2ForAppResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    int32_t remainingRetries;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&remainingRetries);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::supplyIccPuk2ForAppResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&remainingRetries);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPuk2ForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->supplyIccPuk2ForAppResponse(*info, remainingRetries);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "supplyIccPuk2ForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_changeIccPinForAppResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    int32_t remainingRetries;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&remainingRetries);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::changeIccPinForAppResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&remainingRetries);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "changeIccPinForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->changeIccPinForAppResponse(*info, remainingRetries);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "changeIccPinForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_changeIccPin2ForAppResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    int32_t remainingRetries;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&remainingRetries);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::changeIccPin2ForAppResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&remainingRetries);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "changeIccPin2ForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->changeIccPin2ForAppResponse(*info, remainingRetries);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "changeIccPin2ForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_supplyNetworkDepersonalizationResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    int32_t remainingRetries;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&remainingRetries);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::supplyNetworkDepersonalizationResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&remainingRetries);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "supplyNetworkDepersonalizationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->supplyNetworkDepersonalizationResponse(*info, remainingRetries);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "supplyNetworkDepersonalizationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getCurrentCallsResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::Call>* calls;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_calls_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*calls), &_hidl_calls_parent,  reinterpret_cast<const void **>(&calls));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_calls_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::Call> &>(*calls),
            _hidl_data,
            _hidl_calls_parent,
            0 /* parentOffset */, &_hidl_calls_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < calls->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::Call &>((*calls)[_hidl_index_0]),
                _hidl_data,
                _hidl_calls_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::Call));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCurrentCallsResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)calls);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCurrentCallsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getCurrentCallsResponse(*info, *calls);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCurrentCallsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_dialResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::dialResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "dialResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->dialResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "dialResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getIMSIForAppResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_string* imsi;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_imsi_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*imsi), &_hidl_imsi_parent,  reinterpret_cast<const void **>(&imsi));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*imsi),
            _hidl_data,
            _hidl_imsi_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getIMSIForAppResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)imsi);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getIMSIForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getIMSIForAppResponse(*info, *imsi);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getIMSIForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_hangupConnectionResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::hangupConnectionResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "hangupConnectionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->hangupConnectionResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "hangupConnectionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_hangupWaitingOrBackgroundResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::hangupWaitingOrBackgroundResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "hangupWaitingOrBackgroundResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->hangupWaitingOrBackgroundResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "hangupWaitingOrBackgroundResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_hangupForegroundResumeBackgroundResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::hangupForegroundResumeBackgroundResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "hangupForegroundResumeBackgroundResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->hangupForegroundResumeBackgroundResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "hangupForegroundResumeBackgroundResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_switchWaitingOrHoldingAndActiveResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::switchWaitingOrHoldingAndActiveResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "switchWaitingOrHoldingAndActiveResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->switchWaitingOrHoldingAndActiveResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "switchWaitingOrHoldingAndActiveResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_conferenceResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::conferenceResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "conferenceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->conferenceResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "conferenceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_rejectCallResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::rejectCallResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "rejectCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->rejectCallResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "rejectCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getLastCallFailCauseResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::LastCallFailCauseInfo* failCauseinfo;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_failCauseinfo_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*failCauseinfo), &_hidl_failCauseinfo_parent,  const_cast<const void**>(reinterpret_cast<void **>(&failCauseinfo)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::LastCallFailCauseInfo &>(*failCauseinfo),
            _hidl_data,
            _hidl_failCauseinfo_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getLastCallFailCauseResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)failCauseinfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getLastCallFailCauseResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getLastCallFailCauseResponse(*info, *failCauseinfo);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getLastCallFailCauseResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getSignalStrengthResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::SignalStrength* sigStrength;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sigStrength_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sigStrength), &_hidl_sigStrength_parent,  const_cast<const void**>(reinterpret_cast<void **>(&sigStrength)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getSignalStrengthResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)sigStrength);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getSignalStrengthResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getSignalStrengthResponse(*info, *sigStrength);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getSignalStrengthResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getVoiceRegistrationStateResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::VoiceRegStateResult* voiceRegResponse;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_voiceRegResponse_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*voiceRegResponse), &_hidl_voiceRegResponse_parent,  const_cast<const void**>(reinterpret_cast<void **>(&voiceRegResponse)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::VoiceRegStateResult &>(*voiceRegResponse),
            _hidl_data,
            _hidl_voiceRegResponse_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getVoiceRegistrationStateResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)voiceRegResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getVoiceRegistrationStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getVoiceRegistrationStateResponse(*info, *voiceRegResponse);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getVoiceRegistrationStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getDataRegistrationStateResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::DataRegStateResult* dataRegResponse;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dataRegResponse_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dataRegResponse), &_hidl_dataRegResponse_parent,  const_cast<const void**>(reinterpret_cast<void **>(&dataRegResponse)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::DataRegStateResult &>(*dataRegResponse),
            _hidl_data,
            _hidl_dataRegResponse_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getDataRegistrationStateResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)dataRegResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getDataRegistrationStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getDataRegistrationStateResponse(*info, *dataRegResponse);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getDataRegistrationStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getOperatorResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_string* longName;
    const ::android::hardware::hidl_string* shortName;
    const ::android::hardware::hidl_string* numeric;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_longName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*longName), &_hidl_longName_parent,  reinterpret_cast<const void **>(&longName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*longName),
            _hidl_data,
            _hidl_longName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_shortName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*shortName), &_hidl_shortName_parent,  reinterpret_cast<const void **>(&shortName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*shortName),
            _hidl_data,
            _hidl_shortName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_numeric_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*numeric), &_hidl_numeric_parent,  reinterpret_cast<const void **>(&numeric));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*numeric),
            _hidl_data,
            _hidl_numeric_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getOperatorResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)longName);
        _hidl_args.push_back((void *)shortName);
        _hidl_args.push_back((void *)numeric);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getOperatorResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getOperatorResponse(*info, *longName, *shortName, *numeric);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getOperatorResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setRadioPowerResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setRadioPowerResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setRadioPowerResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setRadioPowerResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setRadioPowerResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendDtmfResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendDtmfResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendDtmfResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendSmsResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::SendSmsResult* sms;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sms_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sms), &_hidl_sms_parent,  const_cast<const void**>(reinterpret_cast<void **>(&sms)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::SendSmsResult &>(*sms),
            _hidl_data,
            _hidl_sms_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendSmsResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)sms);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendSmsResponse(*info, *sms);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendSMSExpectMoreResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::SendSmsResult* sms;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sms_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sms), &_hidl_sms_parent,  const_cast<const void**>(reinterpret_cast<void **>(&sms)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::SendSmsResult &>(*sms),
            _hidl_data,
            _hidl_sms_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendSMSExpectMoreResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)sms);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendSMSExpectMoreResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendSMSExpectMoreResponse(*info, *sms);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendSMSExpectMoreResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setupDataCallResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::SetupDataCallResult* dcResponse;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dcResponse_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dcResponse), &_hidl_dcResponse_parent,  const_cast<const void**>(reinterpret_cast<void **>(&dcResponse)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::SetupDataCallResult &>(*dcResponse),
            _hidl_data,
            _hidl_dcResponse_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setupDataCallResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)dcResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setupDataCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setupDataCallResponse(*info, *dcResponse);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setupDataCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_iccIOForAppResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::IccIoResult* iccIo;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_iccIo_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*iccIo), &_hidl_iccIo_parent,  const_cast<const void**>(reinterpret_cast<void **>(&iccIo)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::IccIoResult &>(*iccIo),
            _hidl_data,
            _hidl_iccIo_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::iccIOForAppResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)iccIo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "iccIOForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->iccIOForAppResponse(*info, *iccIo);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "iccIOForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendUssdResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendUssdResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendUssdResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendUssdResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendUssdResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_cancelPendingUssdResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::cancelPendingUssdResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "cancelPendingUssdResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->cancelPendingUssdResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "cancelPendingUssdResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getClirResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    int32_t n;
    int32_t m;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&n);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&m);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getClirResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&n);
        _hidl_args.push_back((void *)&m);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getClirResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getClirResponse(*info, n, m);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getClirResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setClirResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setClirResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setClirResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setClirResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setClirResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getCallForwardStatusResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CallForwardInfo>* callForwardInfos;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_callForwardInfos_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*callForwardInfos), &_hidl_callForwardInfos_parent,  reinterpret_cast<const void **>(&callForwardInfos));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_callForwardInfos_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CallForwardInfo> &>(*callForwardInfos),
            _hidl_data,
            _hidl_callForwardInfos_parent,
            0 /* parentOffset */, &_hidl_callForwardInfos_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < callForwardInfos->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CallForwardInfo &>((*callForwardInfos)[_hidl_index_0]),
                _hidl_data,
                _hidl_callForwardInfos_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CallForwardInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCallForwardStatusResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)callForwardInfos);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCallForwardStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getCallForwardStatusResponse(*info, *callForwardInfos);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCallForwardStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setCallForwardResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCallForwardResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setCallForwardResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setCallForwardResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setCallForwardResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getCallWaitingResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    bool enable;
    int32_t serviceClass;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&enable);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&serviceClass);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCallWaitingResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&enable);
        _hidl_args.push_back((void *)&serviceClass);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCallWaitingResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getCallWaitingResponse(*info, enable, serviceClass);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCallWaitingResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setCallWaitingResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCallWaitingResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setCallWaitingResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setCallWaitingResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setCallWaitingResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_acknowledgeLastIncomingGsmSmsResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::acknowledgeLastIncomingGsmSmsResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeLastIncomingGsmSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->acknowledgeLastIncomingGsmSmsResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeLastIncomingGsmSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_acceptCallResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::acceptCallResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "acceptCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->acceptCallResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "acceptCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_deactivateDataCallResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::deactivateDataCallResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "deactivateDataCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->deactivateDataCallResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "deactivateDataCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getFacilityLockForAppResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    int32_t response;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&response);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getFacilityLockForAppResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&response);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getFacilityLockForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getFacilityLockForAppResponse(*info, response);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getFacilityLockForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setFacilityLockForAppResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    int32_t retry;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&retry);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setFacilityLockForAppResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&retry);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setFacilityLockForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setFacilityLockForAppResponse(*info, retry);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setFacilityLockForAppResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setBarringPasswordResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setBarringPasswordResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setBarringPasswordResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setBarringPasswordResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setBarringPasswordResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getNetworkSelectionModeResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    bool manual;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&manual);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getNetworkSelectionModeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&manual);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getNetworkSelectionModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getNetworkSelectionModeResponse(*info, manual);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getNetworkSelectionModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setNetworkSelectionModeAutomaticResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setNetworkSelectionModeAutomaticResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setNetworkSelectionModeAutomaticResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setNetworkSelectionModeAutomaticResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setNetworkSelectionModeAutomaticResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setNetworkSelectionModeManualResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setNetworkSelectionModeManualResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setNetworkSelectionModeManualResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setNetworkSelectionModeManualResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setNetworkSelectionModeManualResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getAvailableNetworksResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::OperatorInfo>* networkInfos;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_networkInfos_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*networkInfos), &_hidl_networkInfos_parent,  reinterpret_cast<const void **>(&networkInfos));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_networkInfos_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::OperatorInfo> &>(*networkInfos),
            _hidl_data,
            _hidl_networkInfos_parent,
            0 /* parentOffset */, &_hidl_networkInfos_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < networkInfos->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::OperatorInfo &>((*networkInfos)[_hidl_index_0]),
                _hidl_data,
                _hidl_networkInfos_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::OperatorInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getAvailableNetworksResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)networkInfos);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getAvailableNetworksResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getAvailableNetworksResponse(*info, *networkInfos);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getAvailableNetworksResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_startDtmfResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::startDtmfResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "startDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->startDtmfResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "startDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_stopDtmfResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::stopDtmfResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "stopDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->stopDtmfResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "stopDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getBasebandVersionResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_string* version;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_version_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*version), &_hidl_version_parent,  reinterpret_cast<const void **>(&version));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*version),
            _hidl_data,
            _hidl_version_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getBasebandVersionResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)version);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getBasebandVersionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getBasebandVersionResponse(*info, *version);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getBasebandVersionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_separateConnectionResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::separateConnectionResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "separateConnectionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->separateConnectionResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "separateConnectionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setMuteResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setMuteResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setMuteResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setMuteResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setMuteResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getMuteResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    bool enable;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&enable);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getMuteResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&enable);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getMuteResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getMuteResponse(*info, enable);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getMuteResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getClipResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::ClipStatus status;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&status);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getClipResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getClipResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getClipResponse(*info, status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getClipResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getDataCallListResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::SetupDataCallResult>* dcResponse;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dcResponse_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dcResponse), &_hidl_dcResponse_parent,  reinterpret_cast<const void **>(&dcResponse));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dcResponse_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::SetupDataCallResult> &>(*dcResponse),
            _hidl_data,
            _hidl_dcResponse_parent,
            0 /* parentOffset */, &_hidl_dcResponse_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < dcResponse->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::SetupDataCallResult &>((*dcResponse)[_hidl_index_0]),
                _hidl_data,
                _hidl_dcResponse_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::SetupDataCallResult));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getDataCallListResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)dcResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getDataCallListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getDataCallListResponse(*info, *dcResponse);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getDataCallListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setSuppServiceNotificationsResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setSuppServiceNotificationsResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setSuppServiceNotificationsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setSuppServiceNotificationsResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setSuppServiceNotificationsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_writeSmsToSimResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    int32_t index;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&index);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::writeSmsToSimResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&index);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "writeSmsToSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->writeSmsToSimResponse(*info, index);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "writeSmsToSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_deleteSmsOnSimResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::deleteSmsOnSimResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "deleteSmsOnSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->deleteSmsOnSimResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "deleteSmsOnSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setBandModeResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setBandModeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setBandModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setBandModeResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setBandModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getAvailableBandModesResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::RadioBandMode>* bandModes;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_bandModes_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*bandModes), &_hidl_bandModes_parent,  reinterpret_cast<const void **>(&bandModes));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_bandModes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::RadioBandMode> &>(*bandModes),
            _hidl_data,
            _hidl_bandModes_parent,
            0 /* parentOffset */, &_hidl_bandModes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getAvailableBandModesResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)bandModes);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getAvailableBandModesResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getAvailableBandModesResponse(*info, *bandModes);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getAvailableBandModesResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendEnvelopeResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_string* commandResponse;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_commandResponse_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*commandResponse), &_hidl_commandResponse_parent,  reinterpret_cast<const void **>(&commandResponse));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*commandResponse),
            _hidl_data,
            _hidl_commandResponse_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendEnvelopeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)commandResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendEnvelopeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendEnvelopeResponse(*info, *commandResponse);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendEnvelopeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendTerminalResponseToSimResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendTerminalResponseToSimResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendTerminalResponseToSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendTerminalResponseToSimResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendTerminalResponseToSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_handleStkCallSetupRequestFromSimResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::handleStkCallSetupRequestFromSimResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "handleStkCallSetupRequestFromSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->handleStkCallSetupRequestFromSimResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "handleStkCallSetupRequestFromSimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_explicitCallTransferResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::explicitCallTransferResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "explicitCallTransferResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->explicitCallTransferResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "explicitCallTransferResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setPreferredNetworkTypeResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setPreferredNetworkTypeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setPreferredNetworkTypeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setPreferredNetworkTypeResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setPreferredNetworkTypeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getPreferredNetworkTypeResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::PreferredNetworkType nwType;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&nwType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getPreferredNetworkTypeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&nwType);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getPreferredNetworkTypeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getPreferredNetworkTypeResponse(*info, nwType);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getPreferredNetworkTypeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getNeighboringCidsResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::NeighboringCell>* cells;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_cells_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*cells), &_hidl_cells_parent,  reinterpret_cast<const void **>(&cells));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_cells_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::NeighboringCell> &>(*cells),
            _hidl_data,
            _hidl_cells_parent,
            0 /* parentOffset */, &_hidl_cells_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < cells->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::NeighboringCell &>((*cells)[_hidl_index_0]),
                _hidl_data,
                _hidl_cells_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::NeighboringCell));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getNeighboringCidsResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)cells);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getNeighboringCidsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getNeighboringCidsResponse(*info, *cells);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getNeighboringCidsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setLocationUpdatesResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setLocationUpdatesResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setLocationUpdatesResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setLocationUpdatesResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setLocationUpdatesResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setCdmaSubscriptionSourceResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCdmaSubscriptionSourceResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaSubscriptionSourceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setCdmaSubscriptionSourceResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaSubscriptionSourceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setCdmaRoamingPreferenceResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCdmaRoamingPreferenceResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaRoamingPreferenceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setCdmaRoamingPreferenceResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaRoamingPreferenceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getCdmaRoamingPreferenceResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::CdmaRoamingType type;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&type);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCdmaRoamingPreferenceResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&type);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCdmaRoamingPreferenceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getCdmaRoamingPreferenceResponse(*info, type);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCdmaRoamingPreferenceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setTTYModeResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setTTYModeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setTTYModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setTTYModeResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setTTYModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getTTYModeResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::TtyMode mode;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&mode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getTTYModeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&mode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getTTYModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getTTYModeResponse(*info, mode);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getTTYModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setPreferredVoicePrivacyResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setPreferredVoicePrivacyResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setPreferredVoicePrivacyResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setPreferredVoicePrivacyResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setPreferredVoicePrivacyResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getPreferredVoicePrivacyResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    bool enable;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&enable);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getPreferredVoicePrivacyResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&enable);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getPreferredVoicePrivacyResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getPreferredVoicePrivacyResponse(*info, enable);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getPreferredVoicePrivacyResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendCDMAFeatureCodeResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendCDMAFeatureCodeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendCDMAFeatureCodeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendCDMAFeatureCodeResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendCDMAFeatureCodeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendBurstDtmfResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendBurstDtmfResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendBurstDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendBurstDtmfResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendBurstDtmfResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendCdmaSmsResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::SendSmsResult* sms;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sms_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sms), &_hidl_sms_parent,  const_cast<const void**>(reinterpret_cast<void **>(&sms)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::SendSmsResult &>(*sms),
            _hidl_data,
            _hidl_sms_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendCdmaSmsResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)sms);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendCdmaSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendCdmaSmsResponse(*info, *sms);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendCdmaSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_acknowledgeLastIncomingCdmaSmsResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::acknowledgeLastIncomingCdmaSmsResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeLastIncomingCdmaSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->acknowledgeLastIncomingCdmaSmsResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeLastIncomingCdmaSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getGsmBroadcastConfigResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::GsmBroadcastSmsConfigInfo>* configs;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_configs_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*configs), &_hidl_configs_parent,  reinterpret_cast<const void **>(&configs));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_configs_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::GsmBroadcastSmsConfigInfo> &>(*configs),
            _hidl_data,
            _hidl_configs_parent,
            0 /* parentOffset */, &_hidl_configs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getGsmBroadcastConfigResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)configs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getGsmBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getGsmBroadcastConfigResponse(*info, *configs);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getGsmBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setGsmBroadcastConfigResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setGsmBroadcastConfigResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setGsmBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setGsmBroadcastConfigResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setGsmBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setGsmBroadcastActivationResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setGsmBroadcastActivationResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setGsmBroadcastActivationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setGsmBroadcastActivationResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setGsmBroadcastActivationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getCdmaBroadcastConfigResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaBroadcastSmsConfigInfo>* configs;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_configs_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*configs), &_hidl_configs_parent,  reinterpret_cast<const void **>(&configs));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_configs_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaBroadcastSmsConfigInfo> &>(*configs),
            _hidl_data,
            _hidl_configs_parent,
            0 /* parentOffset */, &_hidl_configs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCdmaBroadcastConfigResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)configs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCdmaBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getCdmaBroadcastConfigResponse(*info, *configs);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCdmaBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setCdmaBroadcastConfigResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCdmaBroadcastConfigResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setCdmaBroadcastConfigResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaBroadcastConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setCdmaBroadcastActivationResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCdmaBroadcastActivationResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaBroadcastActivationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setCdmaBroadcastActivationResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setCdmaBroadcastActivationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getCDMASubscriptionResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_string* mdn;
    const ::android::hardware::hidl_string* hSid;
    const ::android::hardware::hidl_string* hNid;
    const ::android::hardware::hidl_string* min;
    const ::android::hardware::hidl_string* prl;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_mdn_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*mdn), &_hidl_mdn_parent,  reinterpret_cast<const void **>(&mdn));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*mdn),
            _hidl_data,
            _hidl_mdn_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_hSid_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*hSid), &_hidl_hSid_parent,  reinterpret_cast<const void **>(&hSid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*hSid),
            _hidl_data,
            _hidl_hSid_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_hNid_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*hNid), &_hidl_hNid_parent,  reinterpret_cast<const void **>(&hNid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*hNid),
            _hidl_data,
            _hidl_hNid_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_min_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*min), &_hidl_min_parent,  reinterpret_cast<const void **>(&min));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*min),
            _hidl_data,
            _hidl_min_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_prl_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*prl), &_hidl_prl_parent,  reinterpret_cast<const void **>(&prl));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*prl),
            _hidl_data,
            _hidl_prl_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCDMASubscriptionResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)mdn);
        _hidl_args.push_back((void *)hSid);
        _hidl_args.push_back((void *)hNid);
        _hidl_args.push_back((void *)min);
        _hidl_args.push_back((void *)prl);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCDMASubscriptionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getCDMASubscriptionResponse(*info, *mdn, *hSid, *hNid, *min, *prl);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCDMASubscriptionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_writeSmsToRuimResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    uint32_t index;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&index);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::writeSmsToRuimResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&index);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "writeSmsToRuimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->writeSmsToRuimResponse(*info, index);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "writeSmsToRuimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_deleteSmsOnRuimResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::deleteSmsOnRuimResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "deleteSmsOnRuimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->deleteSmsOnRuimResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "deleteSmsOnRuimResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getDeviceIdentityResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_string* imei;
    const ::android::hardware::hidl_string* imeisv;
    const ::android::hardware::hidl_string* esn;
    const ::android::hardware::hidl_string* meid;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_imei_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*imei), &_hidl_imei_parent,  reinterpret_cast<const void **>(&imei));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*imei),
            _hidl_data,
            _hidl_imei_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_imeisv_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*imeisv), &_hidl_imeisv_parent,  reinterpret_cast<const void **>(&imeisv));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*imeisv),
            _hidl_data,
            _hidl_imeisv_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_esn_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*esn), &_hidl_esn_parent,  reinterpret_cast<const void **>(&esn));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*esn),
            _hidl_data,
            _hidl_esn_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_meid_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*meid), &_hidl_meid_parent,  reinterpret_cast<const void **>(&meid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*meid),
            _hidl_data,
            _hidl_meid_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getDeviceIdentityResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)imei);
        _hidl_args.push_back((void *)imeisv);
        _hidl_args.push_back((void *)esn);
        _hidl_args.push_back((void *)meid);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getDeviceIdentityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getDeviceIdentityResponse(*info, *imei, *imeisv, *esn, *meid);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getDeviceIdentityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_exitEmergencyCallbackModeResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::exitEmergencyCallbackModeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "exitEmergencyCallbackModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->exitEmergencyCallbackModeResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "exitEmergencyCallbackModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getSmscAddressResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_string* smsc;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_smsc_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*smsc), &_hidl_smsc_parent,  reinterpret_cast<const void **>(&smsc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*smsc),
            _hidl_data,
            _hidl_smsc_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getSmscAddressResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)smsc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getSmscAddressResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getSmscAddressResponse(*info, *smsc);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getSmscAddressResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setSmscAddressResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setSmscAddressResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setSmscAddressResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setSmscAddressResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setSmscAddressResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_reportSmsMemoryStatusResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::reportSmsMemoryStatusResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "reportSmsMemoryStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->reportSmsMemoryStatusResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "reportSmsMemoryStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_reportStkServiceIsRunningResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::reportStkServiceIsRunningResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "reportStkServiceIsRunningResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->reportStkServiceIsRunningResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "reportStkServiceIsRunningResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getCdmaSubscriptionSourceResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::CdmaSubscriptionSource source;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&source);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCdmaSubscriptionSourceResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&source);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCdmaSubscriptionSourceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getCdmaSubscriptionSourceResponse(*info, source);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCdmaSubscriptionSourceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_requestIsimAuthenticationResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_string* response;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_response_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*response), &_hidl_response_parent,  reinterpret_cast<const void **>(&response));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*response),
            _hidl_data,
            _hidl_response_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::requestIsimAuthenticationResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)response);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "requestIsimAuthenticationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->requestIsimAuthenticationResponse(*info, *response);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "requestIsimAuthenticationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_acknowledgeIncomingGsmSmsWithPduResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::acknowledgeIncomingGsmSmsWithPduResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeIncomingGsmSmsWithPduResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->acknowledgeIncomingGsmSmsWithPduResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeIncomingGsmSmsWithPduResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendEnvelopeWithStatusResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::IccIoResult* iccIo;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_iccIo_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*iccIo), &_hidl_iccIo_parent,  const_cast<const void**>(reinterpret_cast<void **>(&iccIo)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::IccIoResult &>(*iccIo),
            _hidl_data,
            _hidl_iccIo_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendEnvelopeWithStatusResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)iccIo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendEnvelopeWithStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendEnvelopeWithStatusResponse(*info, *iccIo);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendEnvelopeWithStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getVoiceRadioTechnologyResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::RadioTechnology rat;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&rat);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getVoiceRadioTechnologyResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&rat);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getVoiceRadioTechnologyResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getVoiceRadioTechnologyResponse(*info, rat);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getVoiceRadioTechnologyResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getCellInfoListResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfo>* cellInfo;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_cellInfo_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*cellInfo), &_hidl_cellInfo_parent,  reinterpret_cast<const void **>(&cellInfo));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_cellInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfo> &>(*cellInfo),
            _hidl_data,
            _hidl_cellInfo_parent,
            0 /* parentOffset */, &_hidl_cellInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < cellInfo->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CellInfo &>((*cellInfo)[_hidl_index_0]),
                _hidl_data,
                _hidl_cellInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCellInfoListResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)cellInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getCellInfoListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getCellInfoListResponse(*info, *cellInfo);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getCellInfoListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setCellInfoListRateResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCellInfoListRateResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setCellInfoListRateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setCellInfoListRateResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setCellInfoListRateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setInitialAttachApnResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setInitialAttachApnResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setInitialAttachApnResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setInitialAttachApnResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setInitialAttachApnResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getImsRegistrationStateResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    bool isRegistered;
    ::android::hardware::radio::V1_0::RadioTechnologyFamily ratFamily;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&isRegistered);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&ratFamily);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getImsRegistrationStateResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&isRegistered);
        _hidl_args.push_back((void *)&ratFamily);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getImsRegistrationStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getImsRegistrationStateResponse(*info, isRegistered, ratFamily);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getImsRegistrationStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendImsSmsResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::SendSmsResult* sms;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sms_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sms), &_hidl_sms_parent,  const_cast<const void**>(reinterpret_cast<void **>(&sms)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::SendSmsResult &>(*sms),
            _hidl_data,
            _hidl_sms_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendImsSmsResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)sms);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendImsSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendImsSmsResponse(*info, *sms);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendImsSmsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_iccTransmitApduBasicChannelResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::IccIoResult* result;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_result_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*result), &_hidl_result_parent,  const_cast<const void**>(reinterpret_cast<void **>(&result)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::IccIoResult &>(*result),
            _hidl_data,
            _hidl_result_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::iccTransmitApduBasicChannelResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)result);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "iccTransmitApduBasicChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->iccTransmitApduBasicChannelResponse(*info, *result);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "iccTransmitApduBasicChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_iccOpenLogicalChannelResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    int32_t channelId;
    const ::android::hardware::hidl_vec<int8_t>* selectResponse;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&channelId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_selectResponse_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*selectResponse), &_hidl_selectResponse_parent,  reinterpret_cast<const void **>(&selectResponse));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_selectResponse_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int8_t> &>(*selectResponse),
            _hidl_data,
            _hidl_selectResponse_parent,
            0 /* parentOffset */, &_hidl_selectResponse_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::iccOpenLogicalChannelResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&channelId);
        _hidl_args.push_back((void *)selectResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "iccOpenLogicalChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->iccOpenLogicalChannelResponse(*info, channelId, *selectResponse);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "iccOpenLogicalChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_iccCloseLogicalChannelResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::iccCloseLogicalChannelResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "iccCloseLogicalChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->iccCloseLogicalChannelResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "iccCloseLogicalChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_iccTransmitApduLogicalChannelResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::IccIoResult* result;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_result_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*result), &_hidl_result_parent,  const_cast<const void**>(reinterpret_cast<void **>(&result)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::IccIoResult &>(*result),
            _hidl_data,
            _hidl_result_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::iccTransmitApduLogicalChannelResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)result);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "iccTransmitApduLogicalChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->iccTransmitApduLogicalChannelResponse(*info, *result);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "iccTransmitApduLogicalChannelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_nvReadItemResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_string* result;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_result_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*result), &_hidl_result_parent,  reinterpret_cast<const void **>(&result));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*result),
            _hidl_data,
            _hidl_result_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::nvReadItemResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)result);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "nvReadItemResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->nvReadItemResponse(*info, *result);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "nvReadItemResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_nvWriteItemResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::nvWriteItemResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "nvWriteItemResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->nvWriteItemResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "nvWriteItemResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_nvWriteCdmaPrlResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::nvWriteCdmaPrlResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "nvWriteCdmaPrlResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->nvWriteCdmaPrlResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "nvWriteCdmaPrlResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_nvResetConfigResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::nvResetConfigResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "nvResetConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->nvResetConfigResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "nvResetConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setUiccSubscriptionResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setUiccSubscriptionResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setUiccSubscriptionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setUiccSubscriptionResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setUiccSubscriptionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setDataAllowedResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setDataAllowedResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setDataAllowedResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setDataAllowedResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setDataAllowedResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getHardwareConfigResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::HardwareConfig>* config;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_config_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*config), &_hidl_config_parent,  reinterpret_cast<const void **>(&config));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_config_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::HardwareConfig> &>(*config),
            _hidl_data,
            _hidl_config_parent,
            0 /* parentOffset */, &_hidl_config_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < config->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::HardwareConfig &>((*config)[_hidl_index_0]),
                _hidl_data,
                _hidl_config_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::HardwareConfig));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getHardwareConfigResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)config);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getHardwareConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getHardwareConfigResponse(*info, *config);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getHardwareConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_requestIccSimAuthenticationResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::IccIoResult* result;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_result_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*result), &_hidl_result_parent,  const_cast<const void**>(reinterpret_cast<void **>(&result)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::IccIoResult &>(*result),
            _hidl_data,
            _hidl_result_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::requestIccSimAuthenticationResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)result);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "requestIccSimAuthenticationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->requestIccSimAuthenticationResponse(*info, *result);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "requestIccSimAuthenticationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setDataProfileResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setDataProfileResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setDataProfileResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setDataProfileResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setDataProfileResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_requestShutdownResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::requestShutdownResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "requestShutdownResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->requestShutdownResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "requestShutdownResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getRadioCapabilityResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::RadioCapability* rc;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_rc_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*rc), &_hidl_rc_parent,  const_cast<const void**>(reinterpret_cast<void **>(&rc)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::RadioCapability &>(*rc),
            _hidl_data,
            _hidl_rc_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getRadioCapabilityResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)rc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getRadioCapabilityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getRadioCapabilityResponse(*info, *rc);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getRadioCapabilityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setRadioCapabilityResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::RadioCapability* rc;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_rc_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*rc), &_hidl_rc_parent,  const_cast<const void**>(reinterpret_cast<void **>(&rc)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::RadioCapability &>(*rc),
            _hidl_data,
            _hidl_rc_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setRadioCapabilityResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)rc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setRadioCapabilityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setRadioCapabilityResponse(*info, *rc);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setRadioCapabilityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_startLceServiceResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::LceStatusInfo* statusInfo;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_statusInfo_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*statusInfo), &_hidl_statusInfo_parent,  const_cast<const void**>(reinterpret_cast<void **>(&statusInfo)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::startLceServiceResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)statusInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "startLceServiceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->startLceServiceResponse(*info, *statusInfo);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "startLceServiceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_stopLceServiceResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::LceStatusInfo* statusInfo;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_statusInfo_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*statusInfo), &_hidl_statusInfo_parent,  const_cast<const void**>(reinterpret_cast<void **>(&statusInfo)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::stopLceServiceResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)statusInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "stopLceServiceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->stopLceServiceResponse(*info, *statusInfo);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "stopLceServiceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_pullLceDataResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::LceDataInfo* lceInfo;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_lceInfo_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*lceInfo), &_hidl_lceInfo_parent,  const_cast<const void**>(reinterpret_cast<void **>(&lceInfo)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::pullLceDataResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)lceInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "pullLceDataResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->pullLceDataResponse(*info, *lceInfo);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "pullLceDataResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getModemActivityInfoResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    ::android::hardware::radio::V1_0::ActivityStatsInfo* activityInfo;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_activityInfo_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*activityInfo), &_hidl_activityInfo_parent,  const_cast<const void**>(reinterpret_cast<void **>(&activityInfo)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getModemActivityInfoResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)activityInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getModemActivityInfoResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getModemActivityInfoResponse(*info, *activityInfo);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getModemActivityInfoResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setAllowedCarriersResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    int32_t numAllowed;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&numAllowed);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setAllowedCarriersResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&numAllowed);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setAllowedCarriersResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setAllowedCarriersResponse(*info, numAllowed);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setAllowedCarriersResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getAllowedCarriersResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    bool allAllowed;
    ::android::hardware::radio::V1_0::CarrierRestrictions* carriers;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&allAllowed);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_carriers_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*carriers), &_hidl_carriers_parent,  const_cast<const void**>(reinterpret_cast<void **>(&carriers)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::CarrierRestrictions &>(*carriers),
            _hidl_data,
            _hidl_carriers_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getAllowedCarriersResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)&allAllowed);
        _hidl_args.push_back((void *)carriers);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "getAllowedCarriersResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getAllowedCarriersResponse(*info, allAllowed, *carriers);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "getAllowedCarriersResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendDeviceStateResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendDeviceStateResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "sendDeviceStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendDeviceStateResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "sendDeviceStateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setIndicationFilterResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setIndicationFilterResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setIndicationFilterResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setIndicationFilterResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setIndicationFilterResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setSimCardPowerResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setSimCardPowerResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "setSimCardPowerResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setSimCardPowerResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "setSimCardPowerResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_acknowledgeRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t serial;

    _hidl_err = _hidl_data.readInt32(&serial);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::acknowledgeRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->acknowledgeRequest(serial);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.0", "IRadioResponse", "acknowledgeRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::radio::V1_0::IRadioResponse follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwRadioResponse::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwRadioResponse::getDebugInfo(getDebugInfo_cb _hidl_cb) {
    ::android::hidl::base::V1_0::DebugInfo info = {};
    info.pid = ::android::hardware::details::getPidIfSharable();
    info.ptr = ::android::hardware::details::debuggable()? reinterpret_cast<uint64_t>(this) : 0;
    info.arch = 
    #if defined(__LP64__)
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_64BIT
    #else
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_32BIT
    #endif
    ;
    _hidl_cb(info);
    return ::android::hardware::Void();
}

::android::status_t BnHwRadioResponse::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* getIccCardStatusResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getIccCardStatusResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* supplyIccPinForAppResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_supplyIccPinForAppResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* supplyIccPukForAppResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_supplyIccPukForAppResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* supplyIccPin2ForAppResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_supplyIccPin2ForAppResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* supplyIccPuk2ForAppResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_supplyIccPuk2ForAppResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* changeIccPinForAppResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_changeIccPinForAppResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* changeIccPin2ForAppResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_changeIccPin2ForAppResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* supplyNetworkDepersonalizationResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_supplyNetworkDepersonalizationResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* getCurrentCallsResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getCurrentCallsResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* dialResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_dialResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* getIMSIForAppResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getIMSIForAppResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* hangupConnectionResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_hangupConnectionResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* hangupWaitingOrBackgroundResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_hangupWaitingOrBackgroundResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* hangupForegroundResumeBackgroundResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_hangupForegroundResumeBackgroundResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* switchWaitingOrHoldingAndActiveResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_switchWaitingOrHoldingAndActiveResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* conferenceResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_conferenceResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* rejectCallResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_rejectCallResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* getLastCallFailCauseResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getLastCallFailCauseResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 19 /* getSignalStrengthResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getSignalStrengthResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 20 /* getVoiceRegistrationStateResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getVoiceRegistrationStateResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 21 /* getDataRegistrationStateResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getDataRegistrationStateResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 22 /* getOperatorResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getOperatorResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 23 /* setRadioPowerResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setRadioPowerResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 24 /* sendDtmfResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_sendDtmfResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 25 /* sendSmsResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_sendSmsResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 26 /* sendSMSExpectMoreResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_sendSMSExpectMoreResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 27 /* setupDataCallResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setupDataCallResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 28 /* iccIOForAppResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_iccIOForAppResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 29 /* sendUssdResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_sendUssdResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 30 /* cancelPendingUssdResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_cancelPendingUssdResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 31 /* getClirResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getClirResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 32 /* setClirResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setClirResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 33 /* getCallForwardStatusResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getCallForwardStatusResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 34 /* setCallForwardResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setCallForwardResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 35 /* getCallWaitingResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getCallWaitingResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 36 /* setCallWaitingResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setCallWaitingResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 37 /* acknowledgeLastIncomingGsmSmsResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_acknowledgeLastIncomingGsmSmsResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 38 /* acceptCallResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_acceptCallResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 39 /* deactivateDataCallResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_deactivateDataCallResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 40 /* getFacilityLockForAppResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getFacilityLockForAppResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 41 /* setFacilityLockForAppResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setFacilityLockForAppResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 42 /* setBarringPasswordResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setBarringPasswordResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 43 /* getNetworkSelectionModeResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getNetworkSelectionModeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 44 /* setNetworkSelectionModeAutomaticResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setNetworkSelectionModeAutomaticResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 45 /* setNetworkSelectionModeManualResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setNetworkSelectionModeManualResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 46 /* getAvailableNetworksResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getAvailableNetworksResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 47 /* startDtmfResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_startDtmfResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 48 /* stopDtmfResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_stopDtmfResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 49 /* getBasebandVersionResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getBasebandVersionResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 50 /* separateConnectionResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_separateConnectionResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 51 /* setMuteResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setMuteResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 52 /* getMuteResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getMuteResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 53 /* getClipResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getClipResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 54 /* getDataCallListResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getDataCallListResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 55 /* setSuppServiceNotificationsResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setSuppServiceNotificationsResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 56 /* writeSmsToSimResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_writeSmsToSimResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 57 /* deleteSmsOnSimResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_deleteSmsOnSimResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 58 /* setBandModeResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setBandModeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 59 /* getAvailableBandModesResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getAvailableBandModesResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 60 /* sendEnvelopeResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_sendEnvelopeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 61 /* sendTerminalResponseToSimResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_sendTerminalResponseToSimResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 62 /* handleStkCallSetupRequestFromSimResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_handleStkCallSetupRequestFromSimResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 63 /* explicitCallTransferResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_explicitCallTransferResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 64 /* setPreferredNetworkTypeResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setPreferredNetworkTypeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 65 /* getPreferredNetworkTypeResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getPreferredNetworkTypeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 66 /* getNeighboringCidsResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getNeighboringCidsResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 67 /* setLocationUpdatesResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setLocationUpdatesResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 68 /* setCdmaSubscriptionSourceResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setCdmaSubscriptionSourceResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 69 /* setCdmaRoamingPreferenceResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setCdmaRoamingPreferenceResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 70 /* getCdmaRoamingPreferenceResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getCdmaRoamingPreferenceResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 71 /* setTTYModeResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setTTYModeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 72 /* getTTYModeResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getTTYModeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 73 /* setPreferredVoicePrivacyResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setPreferredVoicePrivacyResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 74 /* getPreferredVoicePrivacyResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getPreferredVoicePrivacyResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 75 /* sendCDMAFeatureCodeResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_sendCDMAFeatureCodeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 76 /* sendBurstDtmfResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_sendBurstDtmfResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 77 /* sendCdmaSmsResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_sendCdmaSmsResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 78 /* acknowledgeLastIncomingCdmaSmsResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_acknowledgeLastIncomingCdmaSmsResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 79 /* getGsmBroadcastConfigResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getGsmBroadcastConfigResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 80 /* setGsmBroadcastConfigResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setGsmBroadcastConfigResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 81 /* setGsmBroadcastActivationResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setGsmBroadcastActivationResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 82 /* getCdmaBroadcastConfigResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getCdmaBroadcastConfigResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 83 /* setCdmaBroadcastConfigResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setCdmaBroadcastConfigResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 84 /* setCdmaBroadcastActivationResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setCdmaBroadcastActivationResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 85 /* getCDMASubscriptionResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getCDMASubscriptionResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 86 /* writeSmsToRuimResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_writeSmsToRuimResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 87 /* deleteSmsOnRuimResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_deleteSmsOnRuimResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 88 /* getDeviceIdentityResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getDeviceIdentityResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 89 /* exitEmergencyCallbackModeResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_exitEmergencyCallbackModeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 90 /* getSmscAddressResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getSmscAddressResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 91 /* setSmscAddressResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setSmscAddressResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 92 /* reportSmsMemoryStatusResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_reportSmsMemoryStatusResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 93 /* reportStkServiceIsRunningResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_reportStkServiceIsRunningResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 94 /* getCdmaSubscriptionSourceResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getCdmaSubscriptionSourceResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 95 /* requestIsimAuthenticationResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_requestIsimAuthenticationResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 96 /* acknowledgeIncomingGsmSmsWithPduResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_acknowledgeIncomingGsmSmsWithPduResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 97 /* sendEnvelopeWithStatusResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_sendEnvelopeWithStatusResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 98 /* getVoiceRadioTechnologyResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getVoiceRadioTechnologyResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 99 /* getCellInfoListResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getCellInfoListResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 100 /* setCellInfoListRateResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setCellInfoListRateResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 101 /* setInitialAttachApnResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setInitialAttachApnResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 102 /* getImsRegistrationStateResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getImsRegistrationStateResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 103 /* sendImsSmsResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_sendImsSmsResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 104 /* iccTransmitApduBasicChannelResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_iccTransmitApduBasicChannelResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 105 /* iccOpenLogicalChannelResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_iccOpenLogicalChannelResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 106 /* iccCloseLogicalChannelResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_iccCloseLogicalChannelResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 107 /* iccTransmitApduLogicalChannelResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_iccTransmitApduLogicalChannelResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 108 /* nvReadItemResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_nvReadItemResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 109 /* nvWriteItemResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_nvWriteItemResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 110 /* nvWriteCdmaPrlResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_nvWriteCdmaPrlResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 111 /* nvResetConfigResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_nvResetConfigResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 112 /* setUiccSubscriptionResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setUiccSubscriptionResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 113 /* setDataAllowedResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setDataAllowedResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 114 /* getHardwareConfigResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getHardwareConfigResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 115 /* requestIccSimAuthenticationResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_requestIccSimAuthenticationResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 116 /* setDataProfileResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setDataProfileResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 117 /* requestShutdownResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_requestShutdownResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 118 /* getRadioCapabilityResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getRadioCapabilityResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 119 /* setRadioCapabilityResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setRadioCapabilityResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 120 /* startLceServiceResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_startLceServiceResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 121 /* stopLceServiceResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_stopLceServiceResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 122 /* pullLceDataResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_pullLceDataResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 123 /* getModemActivityInfoResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getModemActivityInfoResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 124 /* setAllowedCarriersResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setAllowedCarriersResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 125 /* getAllowedCarriersResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_getAllowedCarriersResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 126 /* sendDeviceStateResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_sendDeviceStateResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 127 /* setIndicationFilterResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setIndicationFilterResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 128 /* setSimCardPowerResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_setSimCardPowerResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 129 /* acknowledgeRequest */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioResponse::_hidl_acknowledgeRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        default:
        {
            return ::android::hidl::base::V1_0::BnHwBase::onTransact(
                    _hidl_code, _hidl_data, _hidl_reply, _hidl_flags, _hidl_cb);
        }
    }

    if (_hidl_err == ::android::UNEXPECTED_NULL) {
        _hidl_err = ::android::hardware::writeToParcel(
                ::android::hardware::Status::fromExceptionCode(::android::hardware::Status::EX_NULL_POINTER),
                _hidl_reply);
    }return _hidl_err;
}

BsRadioResponse::BsRadioResponse(const ::android::sp<::android::hardware::radio::V1_0::IRadioResponse> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.radio@1.0", "IRadioResponse"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsRadioResponse::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IRadioResponse> IRadioResponse::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwRadioResponse>(serviceName, false, getStub);
}

::android::sp<IRadioResponse> IRadioResponse::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwRadioResponse>(serviceName, true, getStub);
}

::android::status_t IRadioResponse::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IRadioResponse::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.radio@1.0::IRadioResponse",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace radio
}  // namespace hardware
}  // namespace android
