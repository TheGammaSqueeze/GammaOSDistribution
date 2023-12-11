#define LOG_TAG "android.hardware.radio@1.2::RadioResponse"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/radio/1.2/BpHwRadioResponse.h>
#include <android/hardware/radio/1.2/BnHwRadioResponse.h>
#include <android/hardware/radio/1.2/BsRadioResponse.h>
#include <android/hardware/radio/1.1/BpHwRadioResponse.h>
#include <android/hardware/radio/1.0/BpHwRadioResponse.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace radio {
namespace V1_2 {

const char* IRadioResponse::descriptor("android.hardware.radio@1.2::IRadioResponse");

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

// Methods from ::android::hardware::radio::V1_1::IRadioResponse follow.
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setCarrierInfoForImsiEncryptionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setSimCardPowerResponse_1_1(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::startNetworkScanResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::stopNetworkScanResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::startKeepaliveResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_1::KeepaliveStatus& status)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::stopKeepaliveResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)

// Methods from ::android::hardware::radio::V1_2::IRadioResponse follow.
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getCellInfoListResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellInfo>& cellInfo)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getIccCardStatusResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::CardStatus& cardStatus)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setSignalStrengthReportingCriteriaResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setLinkCapacityReportingCriteriaResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getCurrentCallsResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_2::Call>& calls)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getSignalStrengthResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::SignalStrength& signalStrength)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getVoiceRegistrationStateResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::VoiceRegStateResult& voiceRegResponse)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getDataRegistrationStateResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::DataRegStateResult& dataRegResponse)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IRadioResponse::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::radio::V1_2::IRadioResponse::descriptor,
        ::android::hardware::radio::V1_1::IRadioResponse::descriptor,
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
    _hidl_cb(::android::hardware::radio::V1_2::IRadioResponse::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioResponse::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){218,140,106,233,145,198,164,178,132,204,110,68,83,50,224,100,226,142,232,160,148,130,237,90,255,249,209,89,236,102,148,183} /* da8c6ae991c6a4b284cc6e445332e064e28ee8a09482ed5afff9d159ec6694b7 */,
        (uint8_t[32]){0,54,107,47,136,249,236,36,88,1,73,114,147,130,112,200,65,61,74,179,3,33,142,55,191,58,221,43,142,107,130,154} /* 00366b2f88f9ec2458014972938270c8413d4ab303218e37bf3add2b8e6b829a */,
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


::android::hardware::Return<::android::sp<::android::hardware::radio::V1_2::IRadioResponse>> IRadioResponse::castFrom(const ::android::sp<::android::hardware::radio::V1_2::IRadioResponse>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::radio::V1_2::IRadioResponse>> IRadioResponse::castFrom(const ::android::sp<::android::hardware::radio::V1_1::IRadioResponse>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioResponse, ::android::hardware::radio::V1_1::IRadioResponse, BpHwRadioResponse>(
            parent, "android.hardware.radio@1.2::IRadioResponse", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::radio::V1_2::IRadioResponse>> IRadioResponse::castFrom(const ::android::sp<::android::hardware::radio::V1_0::IRadioResponse>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioResponse, ::android::hardware::radio::V1_0::IRadioResponse, BpHwRadioResponse>(
            parent, "android.hardware.radio@1.2::IRadioResponse", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::radio::V1_2::IRadioResponse>> IRadioResponse::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioResponse, ::android::hidl::base::V1_0::IBase, BpHwRadioResponse>(
            parent, "android.hardware.radio@1.2::IRadioResponse", emitError);
}

BpHwRadioResponse::BpHwRadioResponse(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IRadioResponse>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.radio@1.2", "IRadioResponse") {
}

void BpHwRadioResponse::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IRadioResponse>::onLastStrongRef(id);
}
// Methods from ::android::hardware::radio::V1_2::IRadioResponse follow.
::android::hardware::Return<void> BpHwRadioResponse::_hidl_getCellInfoListResponse_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellInfo>& cellInfo) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCellInfoListResponse_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&cellInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "getCellInfoListResponse_1_2", &_hidl_args);
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
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellInfo));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(136 /* getCellInfoListResponse_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "getCellInfoListResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getIccCardStatusResponse_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::CardStatus& cardStatus) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getIccCardStatusResponse_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&cardStatus);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "getIccCardStatusResponse_1_2", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(137 /* getIccCardStatusResponse_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "getIccCardStatusResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setSignalStrengthReportingCriteriaResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setSignalStrengthReportingCriteriaResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "setSignalStrengthReportingCriteriaResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(138 /* setSignalStrengthReportingCriteriaResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "setSignalStrengthReportingCriteriaResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setLinkCapacityReportingCriteriaResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setLinkCapacityReportingCriteriaResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "setLinkCapacityReportingCriteriaResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(139 /* setLinkCapacityReportingCriteriaResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "setLinkCapacityReportingCriteriaResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getCurrentCallsResponse_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_2::Call>& calls) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCurrentCallsResponse_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&calls);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "getCurrentCallsResponse_1_2", &_hidl_args);
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
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::Call));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(140 /* getCurrentCallsResponse_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "getCurrentCallsResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getSignalStrengthResponse_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::SignalStrength& signalStrength) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getSignalStrengthResponse_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&signalStrength);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "getSignalStrengthResponse_1_2", &_hidl_args);
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

    size_t _hidl_signalStrength_parent;

    _hidl_err = _hidl_data.writeBuffer(&signalStrength, sizeof(signalStrength), &_hidl_signalStrength_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(141 /* getSignalStrengthResponse_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "getSignalStrengthResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getVoiceRegistrationStateResponse_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::VoiceRegStateResult& voiceRegResponse) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getVoiceRegistrationStateResponse_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&voiceRegResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "getVoiceRegistrationStateResponse_1_2", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(142 /* getVoiceRegistrationStateResponse_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "getVoiceRegistrationStateResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getDataRegistrationStateResponse_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::DataRegStateResult& dataRegResponse) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getDataRegistrationStateResponse_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&dataRegResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "getDataRegistrationStateResponse_1_2", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(143 /* getDataRegistrationStateResponse_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "getDataRegistrationStateResponse_1_2", &_hidl_args);
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


// Methods from ::android::hardware::radio::V1_1::IRadioResponse follow.
::android::hardware::Return<void> BpHwRadioResponse::setCarrierInfoForImsiEncryptionResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadioResponse::_hidl_setCarrierInfoForImsiEncryptionResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setSimCardPowerResponse_1_1(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadioResponse::_hidl_setSimCardPowerResponse_1_1(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::startNetworkScanResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadioResponse::_hidl_startNetworkScanResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::stopNetworkScanResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadioResponse::_hidl_stopNetworkScanResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::startKeepaliveResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_1::KeepaliveStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadioResponse::_hidl_startKeepaliveResponse(this, this, info, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::stopKeepaliveResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadioResponse::_hidl_stopKeepaliveResponse(this, this, info);

    return _hidl_out;
}


// Methods from ::android::hardware::radio::V1_2::IRadioResponse follow.
::android::hardware::Return<void> BpHwRadioResponse::getCellInfoListResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellInfo>& cellInfo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadioResponse::_hidl_getCellInfoListResponse_1_2(this, this, info, cellInfo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getIccCardStatusResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::CardStatus& cardStatus){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadioResponse::_hidl_getIccCardStatusResponse_1_2(this, this, info, cardStatus);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setSignalStrengthReportingCriteriaResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadioResponse::_hidl_setSignalStrengthReportingCriteriaResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setLinkCapacityReportingCriteriaResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadioResponse::_hidl_setLinkCapacityReportingCriteriaResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getCurrentCallsResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_2::Call>& calls){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadioResponse::_hidl_getCurrentCallsResponse_1_2(this, this, info, calls);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getSignalStrengthResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::SignalStrength& signalStrength){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadioResponse::_hidl_getSignalStrengthResponse_1_2(this, this, info, signalStrength);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getVoiceRegistrationStateResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::VoiceRegStateResult& voiceRegResponse){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadioResponse::_hidl_getVoiceRegistrationStateResponse_1_2(this, this, info, voiceRegResponse);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getDataRegistrationStateResponse_1_2(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::radio::V1_2::DataRegStateResult& dataRegResponse){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadioResponse::_hidl_getDataRegistrationStateResponse_1_2(this, this, info, dataRegResponse);

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
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.radio@1.2", "IRadioResponse") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwRadioResponse::~BnHwRadioResponse() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::radio::V1_2::IRadioResponse follow.
::android::status_t BnHwRadioResponse::_hidl_getCellInfoListResponse_1_2(
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
    const ::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellInfo>* cellInfo;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_cellInfo_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*cellInfo), &_hidl_cellInfo_parent,  reinterpret_cast<const void **>(&cellInfo));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_cellInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellInfo> &>(*cellInfo),
            _hidl_data,
            _hidl_cellInfo_parent,
            0 /* parentOffset */, &_hidl_cellInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < cellInfo->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_2::CellInfo &>((*cellInfo)[_hidl_index_0]),
                _hidl_data,
                _hidl_cellInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCellInfoListResponse_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)cellInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "getCellInfoListResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getCellInfoListResponse_1_2(*info, *cellInfo);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "getCellInfoListResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getIccCardStatusResponse_1_2(
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
    ::android::hardware::radio::V1_2::CardStatus* cardStatus;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_cardStatus_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*cardStatus), &_hidl_cardStatus_parent,  const_cast<const void**>(reinterpret_cast<void **>(&cardStatus)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CardStatus &>(*cardStatus),
            _hidl_data,
            _hidl_cardStatus_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getIccCardStatusResponse_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)cardStatus);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "getIccCardStatusResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getIccCardStatusResponse_1_2(*info, *cardStatus);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "getIccCardStatusResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setSignalStrengthReportingCriteriaResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setSignalStrengthReportingCriteriaResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "setSignalStrengthReportingCriteriaResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setSignalStrengthReportingCriteriaResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "setSignalStrengthReportingCriteriaResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setLinkCapacityReportingCriteriaResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setLinkCapacityReportingCriteriaResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "setLinkCapacityReportingCriteriaResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setLinkCapacityReportingCriteriaResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "setLinkCapacityReportingCriteriaResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getCurrentCallsResponse_1_2(
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
    const ::android::hardware::hidl_vec<::android::hardware::radio::V1_2::Call>* calls;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_calls_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*calls), &_hidl_calls_parent,  reinterpret_cast<const void **>(&calls));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_calls_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_2::Call> &>(*calls),
            _hidl_data,
            _hidl_calls_parent,
            0 /* parentOffset */, &_hidl_calls_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < calls->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_2::Call &>((*calls)[_hidl_index_0]),
                _hidl_data,
                _hidl_calls_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::Call));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCurrentCallsResponse_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)calls);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "getCurrentCallsResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getCurrentCallsResponse_1_2(*info, *calls);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "getCurrentCallsResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getSignalStrengthResponse_1_2(
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
    ::android::hardware::radio::V1_2::SignalStrength* signalStrength;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_signalStrength_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*signalStrength), &_hidl_signalStrength_parent,  const_cast<const void**>(reinterpret_cast<void **>(&signalStrength)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getSignalStrengthResponse_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)signalStrength);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "getSignalStrengthResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getSignalStrengthResponse_1_2(*info, *signalStrength);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "getSignalStrengthResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getVoiceRegistrationStateResponse_1_2(
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
    ::android::hardware::radio::V1_2::VoiceRegStateResult* voiceRegResponse;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_voiceRegResponse_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*voiceRegResponse), &_hidl_voiceRegResponse_parent,  const_cast<const void**>(reinterpret_cast<void **>(&voiceRegResponse)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::VoiceRegStateResult &>(*voiceRegResponse),
            _hidl_data,
            _hidl_voiceRegResponse_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getVoiceRegistrationStateResponse_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)voiceRegResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "getVoiceRegistrationStateResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getVoiceRegistrationStateResponse_1_2(*info, *voiceRegResponse);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "getVoiceRegistrationStateResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getDataRegistrationStateResponse_1_2(
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
    ::android::hardware::radio::V1_2::DataRegStateResult* dataRegResponse;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dataRegResponse_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dataRegResponse), &_hidl_dataRegResponse_parent,  const_cast<const void**>(reinterpret_cast<void **>(&dataRegResponse)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::DataRegStateResult &>(*dataRegResponse),
            _hidl_data,
            _hidl_dataRegResponse_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getDataRegistrationStateResponse_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)dataRegResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.2", "IRadioResponse", "getDataRegistrationStateResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getDataRegistrationStateResponse_1_2(*info, *dataRegResponse);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.2", "IRadioResponse", "getDataRegistrationStateResponse_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::radio::V1_0::IRadioResponse follow.

// Methods from ::android::hardware::radio::V1_1::IRadioResponse follow.

// Methods from ::android::hardware::radio::V1_2::IRadioResponse follow.

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

        case 130 /* setCarrierInfoForImsiEncryptionResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadioResponse::_hidl_setCarrierInfoForImsiEncryptionResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 131 /* setSimCardPowerResponse_1_1 */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadioResponse::_hidl_setSimCardPowerResponse_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 132 /* startNetworkScanResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadioResponse::_hidl_startNetworkScanResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 133 /* stopNetworkScanResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadioResponse::_hidl_stopNetworkScanResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 134 /* startKeepaliveResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadioResponse::_hidl_startKeepaliveResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 135 /* stopKeepaliveResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadioResponse::_hidl_stopKeepaliveResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 136 /* getCellInfoListResponse_1_2 */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadioResponse::_hidl_getCellInfoListResponse_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 137 /* getIccCardStatusResponse_1_2 */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadioResponse::_hidl_getIccCardStatusResponse_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 138 /* setSignalStrengthReportingCriteriaResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadioResponse::_hidl_setSignalStrengthReportingCriteriaResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 139 /* setLinkCapacityReportingCriteriaResponse */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadioResponse::_hidl_setLinkCapacityReportingCriteriaResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 140 /* getCurrentCallsResponse_1_2 */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadioResponse::_hidl_getCurrentCallsResponse_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 141 /* getSignalStrengthResponse_1_2 */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadioResponse::_hidl_getSignalStrengthResponse_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 142 /* getVoiceRegistrationStateResponse_1_2 */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadioResponse::_hidl_getVoiceRegistrationStateResponse_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 143 /* getDataRegistrationStateResponse_1_2 */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadioResponse::_hidl_getDataRegistrationStateResponse_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsRadioResponse::BsRadioResponse(const ::android::sp<::android::hardware::radio::V1_2::IRadioResponse> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.radio@1.2", "IRadioResponse"), mImpl(impl) {
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
            sm->registerForNotifications("android.hardware.radio@1.2::IRadioResponse",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_2
}  // namespace radio
}  // namespace hardware
}  // namespace android
