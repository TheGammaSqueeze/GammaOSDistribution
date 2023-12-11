#define LOG_TAG "vendor.mediatek.hardware.radio@2.0::RadioResponse"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <vendor/mediatek/hardware/radio/2.0/BpHwRadioResponse.h>
#include <vendor/mediatek/hardware/radio/2.0/BnHwRadioResponse.h>
#include <vendor/mediatek/hardware/radio/2.0/BsRadioResponse.h>
#include <android/hardware/radio/1.1/BpHwRadioResponse.h>
#include <android/hardware/radio/1.0/BpHwRadioResponse.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace vendor {
namespace mediatek {
namespace hardware {
namespace radio {
namespace V2_0 {

const char* IRadioResponse::descriptor("vendor.mediatek.hardware.radio@2.0::IRadioResponse");

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

// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadioResponse follow.
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setTrmResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getATRResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setSimPowerResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setModemPowerResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::hangupAllResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setCallIndicationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::emergencyDialResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setEccServiceCategoryResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setEccListResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::vtDialResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::voiceAcceptResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::replaceVtCallResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setNetworkSelectionModeManualWithActResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getAvailableNetworksWithActResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::cancelAvailableNetworksResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::currentStatusResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::eccPreferredRatResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getSmsParametersResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setSmsParametersResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getSmsMemStatusResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setEtwsResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::removeCbMsgResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setGsmBroadcastLangsResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getGsmBroadcastLangsResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getGsmBroadcastActivationRsp()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendEmbmsAtCommandResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setupDataCallResponseEx(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& setupDataCallResult)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getDataCallListResponseEx(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult>& dcResponse)
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setApcModeResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getApcInfoResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::triggerModeSwitchByEccResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getSmsRuimMemoryStatusResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setFdModeResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setResumeRegistrationResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::storeModemTypeResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::reloadModemTypeResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::handleStkCallSetupRequestFromSimWithResCodeResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getFemtocellListResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::abortFemtocellListResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::selectFemtocellResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::queryFemtoCellSystemSelectionModeResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setFemtoCellSystemSelectionModeResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setClipResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getColpResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getColrResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendCnapResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setColpResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setColrResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::queryCallForwardInTimeSlotStatusResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setCallForwardInTimeSlotResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::runGbaAuthenticationResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::queryPhbStorageInfoResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::writePhbEntryResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::readPhbEntryResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::queryUPBCapabilityResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::editUPBEntryResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::deleteUPBEntryResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::readUPBGasListResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::readUPBGrpEntryResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::writeUPBGrpEntryResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getPhoneBookStringsLengthResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getPhoneBookMemStorageResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setPhoneBookMemStorageResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::readPhoneBookEntryExtResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::writePhoneBookEntryExtResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::queryUPBAvailableResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::readUPBEmailEntryResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::readUPBSneEntryResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::readUPBAnrEntryResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::readUPBAasListResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::queryNetworkLockResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setNetworkLockResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::resetRadioResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::syncDataSettingsToMdResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::resetMdDataRetryCountResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setRemoveRestrictEutranModeResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setLteAccessStratumReportResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setLteUplinkDataTransferResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setRxTestConfigResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getRxTestResultResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getPOLCapabilityResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getCurrentPOLListResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setPOLEntryResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setRoamingEnableResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::getRoamingEnableResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::vsimNotificationResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::vsimOperationResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setWifiEnabledResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setWifiAssociatedResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setWifiSignalLevelResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setWifiIpAddressResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setLocationInfoResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setEmergencyAddressIdResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setNattKeepAliveStatusResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setE911StateResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::setServiceStateToModemResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendRequestRawResponse()
// no default implementation for: ::android::hardware::Return<void> IRadioResponse::sendRequestStringsResponse()

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IRadioResponse::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::vendor::mediatek::hardware::radio::V2_0::IRadioResponse::descriptor,
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
    _hidl_cb(::vendor::mediatek::hardware::radio::V2_0::IRadioResponse::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioResponse::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} /* 0000000000000000000000000000000000000000000000000000000000000000 */,
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


::android::hardware::Return<::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioResponse>> IRadioResponse::castFrom(const ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioResponse>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioResponse>> IRadioResponse::castFrom(const ::android::sp<::android::hardware::radio::V1_1::IRadioResponse>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioResponse, ::android::hardware::radio::V1_1::IRadioResponse, BpHwRadioResponse>(
            parent, "vendor.mediatek.hardware.radio@2.0::IRadioResponse", emitError);
}

::android::hardware::Return<::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioResponse>> IRadioResponse::castFrom(const ::android::sp<::android::hardware::radio::V1_0::IRadioResponse>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioResponse, ::android::hardware::radio::V1_0::IRadioResponse, BpHwRadioResponse>(
            parent, "vendor.mediatek.hardware.radio@2.0::IRadioResponse", emitError);
}

::android::hardware::Return<::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioResponse>> IRadioResponse::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioResponse, ::android::hidl::base::V1_0::IBase, BpHwRadioResponse>(
            parent, "vendor.mediatek.hardware.radio@2.0::IRadioResponse", emitError);
}

BpHwRadioResponse::BpHwRadioResponse(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IRadioResponse>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("vendor.mediatek.hardware.radio@2.0", "IRadioResponse") {
}

void BpHwRadioResponse::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IRadioResponse>::onLastStrongRef(id);
}
// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadioResponse follow.
::android::hardware::Return<void> BpHwRadioResponse::_hidl_setTrmResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setTrmResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setTrmResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(136 /* setTrmResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setTrmResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getATRResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getATRResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getATRResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(137 /* getATRResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getATRResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setSimPowerResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setSimPowerResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setSimPowerResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(138 /* setSimPowerResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setSimPowerResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setModemPowerResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setModemPowerResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setModemPowerResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(139 /* setModemPowerResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setModemPowerResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_hangupAllResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::hangupAllResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "hangupAllResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(140 /* hangupAllResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "hangupAllResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setCallIndicationResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCallIndicationResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setCallIndicationResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(141 /* setCallIndicationResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setCallIndicationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_emergencyDialResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::emergencyDialResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "emergencyDialResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(142 /* emergencyDialResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "emergencyDialResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setEccServiceCategoryResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setEccServiceCategoryResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEccServiceCategoryResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(143 /* setEccServiceCategoryResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEccServiceCategoryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setEccListResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setEccListResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEccListResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(144 /* setEccListResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEccListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_vtDialResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::vtDialResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "vtDialResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(145 /* vtDialResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "vtDialResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_voiceAcceptResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::voiceAcceptResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "voiceAcceptResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(146 /* voiceAcceptResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "voiceAcceptResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_replaceVtCallResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::replaceVtCallResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "replaceVtCallResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(147 /* replaceVtCallResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "replaceVtCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setNetworkSelectionModeManualWithActResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setNetworkSelectionModeManualWithActResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setNetworkSelectionModeManualWithActResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(148 /* setNetworkSelectionModeManualWithActResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setNetworkSelectionModeManualWithActResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getAvailableNetworksWithActResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getAvailableNetworksWithActResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getAvailableNetworksWithActResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(149 /* getAvailableNetworksWithActResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getAvailableNetworksWithActResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_cancelAvailableNetworksResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::cancelAvailableNetworksResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "cancelAvailableNetworksResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(150 /* cancelAvailableNetworksResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "cancelAvailableNetworksResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_currentStatusResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::currentStatusResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "currentStatusResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(151 /* currentStatusResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "currentStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_eccPreferredRatResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::eccPreferredRatResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "eccPreferredRatResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(152 /* eccPreferredRatResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "eccPreferredRatResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getSmsParametersResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getSmsParametersResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getSmsParametersResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(153 /* getSmsParametersResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getSmsParametersResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setSmsParametersResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setSmsParametersResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setSmsParametersResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(154 /* setSmsParametersResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setSmsParametersResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getSmsMemStatusResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getSmsMemStatusResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getSmsMemStatusResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(155 /* getSmsMemStatusResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getSmsMemStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setEtwsResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setEtwsResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEtwsResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(156 /* setEtwsResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEtwsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_removeCbMsgResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::removeCbMsgResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "removeCbMsgResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(157 /* removeCbMsgResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "removeCbMsgResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setGsmBroadcastLangsResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setGsmBroadcastLangsResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setGsmBroadcastLangsResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(158 /* setGsmBroadcastLangsResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setGsmBroadcastLangsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getGsmBroadcastLangsResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getGsmBroadcastLangsResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getGsmBroadcastLangsResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(159 /* getGsmBroadcastLangsResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getGsmBroadcastLangsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getGsmBroadcastActivationRsp(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getGsmBroadcastActivationRsp::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getGsmBroadcastActivationRsp", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(160 /* getGsmBroadcastActivationRsp */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getGsmBroadcastActivationRsp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendEmbmsAtCommandResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendEmbmsAtCommandResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendEmbmsAtCommandResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(161 /* sendEmbmsAtCommandResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendEmbmsAtCommandResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setupDataCallResponseEx(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& setupDataCallResult) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setupDataCallResponseEx::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&setupDataCallResult);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setupDataCallResponseEx", &_hidl_args);
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

    size_t _hidl_setupDataCallResult_parent;

    _hidl_err = _hidl_data.writeBuffer(&setupDataCallResult, sizeof(setupDataCallResult), &_hidl_setupDataCallResult_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            setupDataCallResult,
            &_hidl_data,
            _hidl_setupDataCallResult_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(162 /* setupDataCallResponseEx */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setupDataCallResponseEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getDataCallListResponseEx(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult>& dcResponse) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getDataCallListResponseEx::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&dcResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getDataCallListResponseEx", &_hidl_args);
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
                _hidl_index_0 * sizeof(::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(163 /* getDataCallListResponseEx */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getDataCallListResponseEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setApcModeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setApcModeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setApcModeResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(164 /* setApcModeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setApcModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getApcInfoResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getApcInfoResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getApcInfoResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(165 /* getApcInfoResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getApcInfoResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_triggerModeSwitchByEccResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::triggerModeSwitchByEccResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "triggerModeSwitchByEccResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(166 /* triggerModeSwitchByEccResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "triggerModeSwitchByEccResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getSmsRuimMemoryStatusResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getSmsRuimMemoryStatusResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getSmsRuimMemoryStatusResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(167 /* getSmsRuimMemoryStatusResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getSmsRuimMemoryStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setFdModeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setFdModeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setFdModeResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(168 /* setFdModeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setFdModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setResumeRegistrationResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setResumeRegistrationResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setResumeRegistrationResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(169 /* setResumeRegistrationResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setResumeRegistrationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_storeModemTypeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::storeModemTypeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "storeModemTypeResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(170 /* storeModemTypeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "storeModemTypeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_reloadModemTypeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::reloadModemTypeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "reloadModemTypeResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(171 /* reloadModemTypeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "reloadModemTypeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_handleStkCallSetupRequestFromSimWithResCodeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::handleStkCallSetupRequestFromSimWithResCodeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "handleStkCallSetupRequestFromSimWithResCodeResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(172 /* handleStkCallSetupRequestFromSimWithResCodeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "handleStkCallSetupRequestFromSimWithResCodeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getFemtocellListResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getFemtocellListResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getFemtocellListResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(173 /* getFemtocellListResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getFemtocellListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_abortFemtocellListResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::abortFemtocellListResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "abortFemtocellListResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(174 /* abortFemtocellListResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "abortFemtocellListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_selectFemtocellResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::selectFemtocellResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "selectFemtocellResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(175 /* selectFemtocellResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "selectFemtocellResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_queryFemtoCellSystemSelectionModeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::queryFemtoCellSystemSelectionModeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryFemtoCellSystemSelectionModeResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(176 /* queryFemtoCellSystemSelectionModeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryFemtoCellSystemSelectionModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setFemtoCellSystemSelectionModeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setFemtoCellSystemSelectionModeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setFemtoCellSystemSelectionModeResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(177 /* setFemtoCellSystemSelectionModeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setFemtoCellSystemSelectionModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setClipResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setClipResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setClipResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(178 /* setClipResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setClipResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getColpResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getColpResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getColpResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(179 /* getColpResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getColpResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getColrResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getColrResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getColrResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(180 /* getColrResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getColrResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendCnapResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendCnapResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendCnapResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(181 /* sendCnapResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendCnapResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setColpResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setColpResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setColpResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(182 /* setColpResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setColpResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setColrResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setColrResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setColrResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(183 /* setColrResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setColrResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_queryCallForwardInTimeSlotStatusResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::queryCallForwardInTimeSlotStatusResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryCallForwardInTimeSlotStatusResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(184 /* queryCallForwardInTimeSlotStatusResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryCallForwardInTimeSlotStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setCallForwardInTimeSlotResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCallForwardInTimeSlotResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setCallForwardInTimeSlotResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(185 /* setCallForwardInTimeSlotResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setCallForwardInTimeSlotResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_runGbaAuthenticationResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::runGbaAuthenticationResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "runGbaAuthenticationResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(186 /* runGbaAuthenticationResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "runGbaAuthenticationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_queryPhbStorageInfoResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::queryPhbStorageInfoResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryPhbStorageInfoResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(187 /* queryPhbStorageInfoResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryPhbStorageInfoResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_writePhbEntryResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::writePhbEntryResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "writePhbEntryResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(188 /* writePhbEntryResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "writePhbEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_readPhbEntryResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::readPhbEntryResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readPhbEntryResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(189 /* readPhbEntryResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readPhbEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_queryUPBCapabilityResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::queryUPBCapabilityResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryUPBCapabilityResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(190 /* queryUPBCapabilityResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryUPBCapabilityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_editUPBEntryResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::editUPBEntryResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "editUPBEntryResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(191 /* editUPBEntryResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "editUPBEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_deleteUPBEntryResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::deleteUPBEntryResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "deleteUPBEntryResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(192 /* deleteUPBEntryResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "deleteUPBEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_readUPBGasListResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::readUPBGasListResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBGasListResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(193 /* readUPBGasListResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBGasListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_readUPBGrpEntryResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::readUPBGrpEntryResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBGrpEntryResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(194 /* readUPBGrpEntryResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBGrpEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_writeUPBGrpEntryResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::writeUPBGrpEntryResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "writeUPBGrpEntryResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(195 /* writeUPBGrpEntryResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "writeUPBGrpEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getPhoneBookStringsLengthResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getPhoneBookStringsLengthResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getPhoneBookStringsLengthResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(196 /* getPhoneBookStringsLengthResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getPhoneBookStringsLengthResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getPhoneBookMemStorageResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getPhoneBookMemStorageResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getPhoneBookMemStorageResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(197 /* getPhoneBookMemStorageResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getPhoneBookMemStorageResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setPhoneBookMemStorageResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setPhoneBookMemStorageResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setPhoneBookMemStorageResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(198 /* setPhoneBookMemStorageResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setPhoneBookMemStorageResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_readPhoneBookEntryExtResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::readPhoneBookEntryExtResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readPhoneBookEntryExtResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(199 /* readPhoneBookEntryExtResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readPhoneBookEntryExtResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_writePhoneBookEntryExtResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::writePhoneBookEntryExtResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "writePhoneBookEntryExtResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(200 /* writePhoneBookEntryExtResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "writePhoneBookEntryExtResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_queryUPBAvailableResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::queryUPBAvailableResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryUPBAvailableResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(201 /* queryUPBAvailableResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryUPBAvailableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_readUPBEmailEntryResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::readUPBEmailEntryResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBEmailEntryResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(202 /* readUPBEmailEntryResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBEmailEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_readUPBSneEntryResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::readUPBSneEntryResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBSneEntryResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(203 /* readUPBSneEntryResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBSneEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_readUPBAnrEntryResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::readUPBAnrEntryResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBAnrEntryResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(204 /* readUPBAnrEntryResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBAnrEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_readUPBAasListResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::readUPBAasListResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBAasListResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(205 /* readUPBAasListResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBAasListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_queryNetworkLockResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::queryNetworkLockResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryNetworkLockResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(206 /* queryNetworkLockResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryNetworkLockResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setNetworkLockResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setNetworkLockResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setNetworkLockResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(207 /* setNetworkLockResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setNetworkLockResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_resetRadioResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::resetRadioResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "resetRadioResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(208 /* resetRadioResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "resetRadioResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_syncDataSettingsToMdResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::syncDataSettingsToMdResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "syncDataSettingsToMdResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(209 /* syncDataSettingsToMdResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "syncDataSettingsToMdResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_resetMdDataRetryCountResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::resetMdDataRetryCountResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "resetMdDataRetryCountResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(210 /* resetMdDataRetryCountResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "resetMdDataRetryCountResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setRemoveRestrictEutranModeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setRemoveRestrictEutranModeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setRemoveRestrictEutranModeResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(211 /* setRemoveRestrictEutranModeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setRemoveRestrictEutranModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setLteAccessStratumReportResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setLteAccessStratumReportResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setLteAccessStratumReportResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(212 /* setLteAccessStratumReportResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setLteAccessStratumReportResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setLteUplinkDataTransferResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setLteUplinkDataTransferResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setLteUplinkDataTransferResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(213 /* setLteUplinkDataTransferResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setLteUplinkDataTransferResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setRxTestConfigResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setRxTestConfigResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setRxTestConfigResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(214 /* setRxTestConfigResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setRxTestConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getRxTestResultResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getRxTestResultResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getRxTestResultResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(215 /* getRxTestResultResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getRxTestResultResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getPOLCapabilityResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getPOLCapabilityResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getPOLCapabilityResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(216 /* getPOLCapabilityResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getPOLCapabilityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getCurrentPOLListResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCurrentPOLListResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getCurrentPOLListResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(217 /* getCurrentPOLListResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getCurrentPOLListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setPOLEntryResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setPOLEntryResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setPOLEntryResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(218 /* setPOLEntryResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setPOLEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setRoamingEnableResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setRoamingEnableResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setRoamingEnableResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(219 /* setRoamingEnableResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setRoamingEnableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_getRoamingEnableResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::getRoamingEnableResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getRoamingEnableResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(220 /* getRoamingEnableResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getRoamingEnableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_vsimNotificationResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::vsimNotificationResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "vsimNotificationResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(221 /* vsimNotificationResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "vsimNotificationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_vsimOperationResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::vsimOperationResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "vsimOperationResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(222 /* vsimOperationResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "vsimOperationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setWifiEnabledResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setWifiEnabledResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiEnabledResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(223 /* setWifiEnabledResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiEnabledResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setWifiAssociatedResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setWifiAssociatedResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiAssociatedResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(224 /* setWifiAssociatedResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiAssociatedResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setWifiSignalLevelResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setWifiSignalLevelResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiSignalLevelResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(225 /* setWifiSignalLevelResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiSignalLevelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setWifiIpAddressResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setWifiIpAddressResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiIpAddressResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(226 /* setWifiIpAddressResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiIpAddressResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setLocationInfoResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setLocationInfoResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setLocationInfoResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(227 /* setLocationInfoResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setLocationInfoResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setEmergencyAddressIdResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setEmergencyAddressIdResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEmergencyAddressIdResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(228 /* setEmergencyAddressIdResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEmergencyAddressIdResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setNattKeepAliveStatusResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setNattKeepAliveStatusResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setNattKeepAliveStatusResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(229 /* setNattKeepAliveStatusResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setNattKeepAliveStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setE911StateResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setE911StateResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setE911StateResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(230 /* setE911StateResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setE911StateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_setServiceStateToModemResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::setServiceStateToModemResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setServiceStateToModemResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(231 /* setServiceStateToModemResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setServiceStateToModemResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendRequestRawResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendRequestRawResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendRequestRawResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(232 /* sendRequestRawResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendRequestRawResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioResponse::_hidl_sendRequestStringsResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendRequestStringsResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendRequestStringsResponse", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(233 /* sendRequestStringsResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendRequestStringsResponse", &_hidl_args);
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


// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadioResponse follow.
::android::hardware::Return<void> BpHwRadioResponse::setTrmResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setTrmResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getATRResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getATRResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setSimPowerResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setSimPowerResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setModemPowerResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setModemPowerResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::hangupAllResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_hangupAllResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setCallIndicationResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setCallIndicationResponse(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::emergencyDialResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_emergencyDialResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setEccServiceCategoryResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setEccServiceCategoryResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setEccListResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setEccListResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::vtDialResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_vtDialResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::voiceAcceptResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_voiceAcceptResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::replaceVtCallResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_replaceVtCallResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setNetworkSelectionModeManualWithActResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setNetworkSelectionModeManualWithActResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getAvailableNetworksWithActResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getAvailableNetworksWithActResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::cancelAvailableNetworksResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_cancelAvailableNetworksResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::currentStatusResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_currentStatusResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::eccPreferredRatResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_eccPreferredRatResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getSmsParametersResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getSmsParametersResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setSmsParametersResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setSmsParametersResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getSmsMemStatusResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getSmsMemStatusResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setEtwsResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setEtwsResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::removeCbMsgResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_removeCbMsgResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setGsmBroadcastLangsResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setGsmBroadcastLangsResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getGsmBroadcastLangsResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getGsmBroadcastLangsResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getGsmBroadcastActivationRsp(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getGsmBroadcastActivationRsp(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendEmbmsAtCommandResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_sendEmbmsAtCommandResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setupDataCallResponseEx(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& setupDataCallResult){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setupDataCallResponseEx(this, this, info, setupDataCallResult);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getDataCallListResponseEx(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult>& dcResponse){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getDataCallListResponseEx(this, this, info, dcResponse);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setApcModeResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setApcModeResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getApcInfoResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getApcInfoResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::triggerModeSwitchByEccResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_triggerModeSwitchByEccResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getSmsRuimMemoryStatusResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getSmsRuimMemoryStatusResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setFdModeResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setFdModeResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setResumeRegistrationResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setResumeRegistrationResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::storeModemTypeResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_storeModemTypeResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::reloadModemTypeResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_reloadModemTypeResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::handleStkCallSetupRequestFromSimWithResCodeResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_handleStkCallSetupRequestFromSimWithResCodeResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getFemtocellListResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getFemtocellListResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::abortFemtocellListResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_abortFemtocellListResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::selectFemtocellResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_selectFemtocellResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::queryFemtoCellSystemSelectionModeResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_queryFemtoCellSystemSelectionModeResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setFemtoCellSystemSelectionModeResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setFemtoCellSystemSelectionModeResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setClipResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setClipResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getColpResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getColpResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getColrResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getColrResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendCnapResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_sendCnapResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setColpResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setColpResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setColrResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setColrResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::queryCallForwardInTimeSlotStatusResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_queryCallForwardInTimeSlotStatusResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setCallForwardInTimeSlotResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setCallForwardInTimeSlotResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::runGbaAuthenticationResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_runGbaAuthenticationResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::queryPhbStorageInfoResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_queryPhbStorageInfoResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::writePhbEntryResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_writePhbEntryResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::readPhbEntryResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_readPhbEntryResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::queryUPBCapabilityResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_queryUPBCapabilityResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::editUPBEntryResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_editUPBEntryResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::deleteUPBEntryResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_deleteUPBEntryResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::readUPBGasListResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_readUPBGasListResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::readUPBGrpEntryResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_readUPBGrpEntryResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::writeUPBGrpEntryResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_writeUPBGrpEntryResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getPhoneBookStringsLengthResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getPhoneBookStringsLengthResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getPhoneBookMemStorageResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getPhoneBookMemStorageResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setPhoneBookMemStorageResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setPhoneBookMemStorageResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::readPhoneBookEntryExtResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_readPhoneBookEntryExtResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::writePhoneBookEntryExtResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_writePhoneBookEntryExtResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::queryUPBAvailableResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_queryUPBAvailableResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::readUPBEmailEntryResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_readUPBEmailEntryResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::readUPBSneEntryResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_readUPBSneEntryResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::readUPBAnrEntryResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_readUPBAnrEntryResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::readUPBAasListResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_readUPBAasListResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::queryNetworkLockResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_queryNetworkLockResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setNetworkLockResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setNetworkLockResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::resetRadioResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_resetRadioResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::syncDataSettingsToMdResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_syncDataSettingsToMdResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::resetMdDataRetryCountResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_resetMdDataRetryCountResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setRemoveRestrictEutranModeResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setRemoveRestrictEutranModeResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setLteAccessStratumReportResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setLteAccessStratumReportResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setLteUplinkDataTransferResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setLteUplinkDataTransferResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setRxTestConfigResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setRxTestConfigResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getRxTestResultResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getRxTestResultResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getPOLCapabilityResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getPOLCapabilityResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getCurrentPOLListResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getCurrentPOLListResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setPOLEntryResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setPOLEntryResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setRoamingEnableResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setRoamingEnableResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::getRoamingEnableResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_getRoamingEnableResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::vsimNotificationResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_vsimNotificationResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::vsimOperationResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_vsimOperationResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setWifiEnabledResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setWifiEnabledResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setWifiAssociatedResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setWifiAssociatedResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setWifiSignalLevelResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setWifiSignalLevelResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setWifiIpAddressResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setWifiIpAddressResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setLocationInfoResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setLocationInfoResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setEmergencyAddressIdResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setEmergencyAddressIdResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setNattKeepAliveStatusResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setNattKeepAliveStatusResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setE911StateResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setE911StateResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::setServiceStateToModemResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_setServiceStateToModemResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendRequestRawResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_sendRequestRawResponse(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioResponse::sendRequestStringsResponse(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse::_hidl_sendRequestStringsResponse(this, this);

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
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "vendor.mediatek.hardware.radio@2.0", "IRadioResponse") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwRadioResponse::~BnHwRadioResponse() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadioResponse follow.
::android::status_t BnHwRadioResponse::_hidl_setTrmResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setTrmResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setTrmResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setTrmResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setTrmResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getATRResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getATRResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getATRResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getATRResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getATRResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setSimPowerResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setSimPowerResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setSimPowerResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setSimPowerResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setSimPowerResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setModemPowerResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setModemPowerResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setModemPowerResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setModemPowerResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setModemPowerResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_hangupAllResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::hangupAllResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "hangupAllResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->hangupAllResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "hangupAllResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setCallIndicationResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCallIndicationResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setCallIndicationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setCallIndicationResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setCallIndicationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_emergencyDialResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::emergencyDialResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "emergencyDialResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->emergencyDialResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "emergencyDialResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setEccServiceCategoryResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setEccServiceCategoryResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEccServiceCategoryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setEccServiceCategoryResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEccServiceCategoryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setEccListResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setEccListResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEccListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setEccListResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEccListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_vtDialResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::vtDialResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "vtDialResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->vtDialResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "vtDialResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_voiceAcceptResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::voiceAcceptResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "voiceAcceptResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->voiceAcceptResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "voiceAcceptResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_replaceVtCallResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::replaceVtCallResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "replaceVtCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->replaceVtCallResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "replaceVtCallResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setNetworkSelectionModeManualWithActResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setNetworkSelectionModeManualWithActResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setNetworkSelectionModeManualWithActResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setNetworkSelectionModeManualWithActResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setNetworkSelectionModeManualWithActResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getAvailableNetworksWithActResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getAvailableNetworksWithActResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getAvailableNetworksWithActResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getAvailableNetworksWithActResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getAvailableNetworksWithActResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_cancelAvailableNetworksResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::cancelAvailableNetworksResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "cancelAvailableNetworksResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->cancelAvailableNetworksResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "cancelAvailableNetworksResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_currentStatusResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::currentStatusResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "currentStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->currentStatusResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "currentStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_eccPreferredRatResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::eccPreferredRatResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "eccPreferredRatResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->eccPreferredRatResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "eccPreferredRatResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getSmsParametersResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getSmsParametersResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getSmsParametersResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getSmsParametersResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getSmsParametersResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setSmsParametersResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setSmsParametersResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setSmsParametersResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setSmsParametersResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setSmsParametersResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getSmsMemStatusResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getSmsMemStatusResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getSmsMemStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getSmsMemStatusResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getSmsMemStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setEtwsResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setEtwsResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEtwsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setEtwsResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEtwsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_removeCbMsgResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::removeCbMsgResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "removeCbMsgResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->removeCbMsgResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "removeCbMsgResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setGsmBroadcastLangsResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setGsmBroadcastLangsResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setGsmBroadcastLangsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setGsmBroadcastLangsResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setGsmBroadcastLangsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getGsmBroadcastLangsResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getGsmBroadcastLangsResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getGsmBroadcastLangsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getGsmBroadcastLangsResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getGsmBroadcastLangsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getGsmBroadcastActivationRsp(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getGsmBroadcastActivationRsp::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getGsmBroadcastActivationRsp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getGsmBroadcastActivationRsp();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getGsmBroadcastActivationRsp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendEmbmsAtCommandResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendEmbmsAtCommandResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendEmbmsAtCommandResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendEmbmsAtCommandResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendEmbmsAtCommandResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setupDataCallResponseEx(
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
    ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult* setupDataCallResult;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_setupDataCallResult_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*setupDataCallResult), &_hidl_setupDataCallResult_parent,  const_cast<const void**>(reinterpret_cast<void **>(&setupDataCallResult)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult &>(*setupDataCallResult),
            _hidl_data,
            _hidl_setupDataCallResult_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setupDataCallResponseEx::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)setupDataCallResult);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setupDataCallResponseEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setupDataCallResponseEx(*info, *setupDataCallResult);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setupDataCallResponseEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getDataCallListResponseEx(
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
    const ::android::hardware::hidl_vec<::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult>* dcResponse;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dcResponse_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dcResponse), &_hidl_dcResponse_parent,  reinterpret_cast<const void **>(&dcResponse));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dcResponse_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult> &>(*dcResponse),
            _hidl_data,
            _hidl_dcResponse_parent,
            0 /* parentOffset */, &_hidl_dcResponse_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < dcResponse->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult &>((*dcResponse)[_hidl_index_0]),
                _hidl_data,
                _hidl_dcResponse_child,
                _hidl_index_0 * sizeof(::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getDataCallListResponseEx::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)dcResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getDataCallListResponseEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getDataCallListResponseEx(*info, *dcResponse);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getDataCallListResponseEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setApcModeResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setApcModeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setApcModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setApcModeResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setApcModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getApcInfoResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getApcInfoResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getApcInfoResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getApcInfoResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getApcInfoResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_triggerModeSwitchByEccResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::triggerModeSwitchByEccResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "triggerModeSwitchByEccResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->triggerModeSwitchByEccResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "triggerModeSwitchByEccResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getSmsRuimMemoryStatusResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getSmsRuimMemoryStatusResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getSmsRuimMemoryStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getSmsRuimMemoryStatusResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getSmsRuimMemoryStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setFdModeResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setFdModeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setFdModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setFdModeResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setFdModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setResumeRegistrationResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setResumeRegistrationResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setResumeRegistrationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setResumeRegistrationResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setResumeRegistrationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_storeModemTypeResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::storeModemTypeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "storeModemTypeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->storeModemTypeResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "storeModemTypeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_reloadModemTypeResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::reloadModemTypeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "reloadModemTypeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->reloadModemTypeResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "reloadModemTypeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_handleStkCallSetupRequestFromSimWithResCodeResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::handleStkCallSetupRequestFromSimWithResCodeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "handleStkCallSetupRequestFromSimWithResCodeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->handleStkCallSetupRequestFromSimWithResCodeResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "handleStkCallSetupRequestFromSimWithResCodeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getFemtocellListResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getFemtocellListResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getFemtocellListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getFemtocellListResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getFemtocellListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_abortFemtocellListResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::abortFemtocellListResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "abortFemtocellListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->abortFemtocellListResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "abortFemtocellListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_selectFemtocellResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::selectFemtocellResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "selectFemtocellResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->selectFemtocellResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "selectFemtocellResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_queryFemtoCellSystemSelectionModeResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::queryFemtoCellSystemSelectionModeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryFemtoCellSystemSelectionModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->queryFemtoCellSystemSelectionModeResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryFemtoCellSystemSelectionModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setFemtoCellSystemSelectionModeResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setFemtoCellSystemSelectionModeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setFemtoCellSystemSelectionModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setFemtoCellSystemSelectionModeResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setFemtoCellSystemSelectionModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setClipResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setClipResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setClipResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setClipResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setClipResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getColpResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getColpResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getColpResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getColpResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getColpResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getColrResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getColrResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getColrResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getColrResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getColrResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendCnapResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendCnapResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendCnapResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendCnapResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendCnapResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setColpResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setColpResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setColpResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setColpResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setColpResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setColrResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setColrResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setColrResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setColrResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setColrResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_queryCallForwardInTimeSlotStatusResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::queryCallForwardInTimeSlotStatusResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryCallForwardInTimeSlotStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->queryCallForwardInTimeSlotStatusResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryCallForwardInTimeSlotStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setCallForwardInTimeSlotResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setCallForwardInTimeSlotResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setCallForwardInTimeSlotResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setCallForwardInTimeSlotResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setCallForwardInTimeSlotResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_runGbaAuthenticationResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::runGbaAuthenticationResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "runGbaAuthenticationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->runGbaAuthenticationResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "runGbaAuthenticationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_queryPhbStorageInfoResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::queryPhbStorageInfoResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryPhbStorageInfoResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->queryPhbStorageInfoResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryPhbStorageInfoResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_writePhbEntryResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::writePhbEntryResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "writePhbEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->writePhbEntryResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "writePhbEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_readPhbEntryResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::readPhbEntryResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readPhbEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->readPhbEntryResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readPhbEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_queryUPBCapabilityResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::queryUPBCapabilityResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryUPBCapabilityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->queryUPBCapabilityResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryUPBCapabilityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_editUPBEntryResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::editUPBEntryResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "editUPBEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->editUPBEntryResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "editUPBEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_deleteUPBEntryResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::deleteUPBEntryResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "deleteUPBEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->deleteUPBEntryResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "deleteUPBEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_readUPBGasListResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::readUPBGasListResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBGasListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->readUPBGasListResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBGasListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_readUPBGrpEntryResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::readUPBGrpEntryResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBGrpEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->readUPBGrpEntryResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBGrpEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_writeUPBGrpEntryResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::writeUPBGrpEntryResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "writeUPBGrpEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->writeUPBGrpEntryResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "writeUPBGrpEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getPhoneBookStringsLengthResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getPhoneBookStringsLengthResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getPhoneBookStringsLengthResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getPhoneBookStringsLengthResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getPhoneBookStringsLengthResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getPhoneBookMemStorageResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getPhoneBookMemStorageResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getPhoneBookMemStorageResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getPhoneBookMemStorageResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getPhoneBookMemStorageResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setPhoneBookMemStorageResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setPhoneBookMemStorageResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setPhoneBookMemStorageResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setPhoneBookMemStorageResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setPhoneBookMemStorageResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_readPhoneBookEntryExtResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::readPhoneBookEntryExtResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readPhoneBookEntryExtResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->readPhoneBookEntryExtResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readPhoneBookEntryExtResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_writePhoneBookEntryExtResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::writePhoneBookEntryExtResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "writePhoneBookEntryExtResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->writePhoneBookEntryExtResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "writePhoneBookEntryExtResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_queryUPBAvailableResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::queryUPBAvailableResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryUPBAvailableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->queryUPBAvailableResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryUPBAvailableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_readUPBEmailEntryResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::readUPBEmailEntryResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBEmailEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->readUPBEmailEntryResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBEmailEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_readUPBSneEntryResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::readUPBSneEntryResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBSneEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->readUPBSneEntryResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBSneEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_readUPBAnrEntryResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::readUPBAnrEntryResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBAnrEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->readUPBAnrEntryResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBAnrEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_readUPBAasListResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::readUPBAasListResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBAasListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->readUPBAasListResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "readUPBAasListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_queryNetworkLockResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::queryNetworkLockResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryNetworkLockResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->queryNetworkLockResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "queryNetworkLockResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setNetworkLockResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setNetworkLockResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setNetworkLockResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setNetworkLockResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setNetworkLockResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_resetRadioResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::resetRadioResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "resetRadioResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->resetRadioResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "resetRadioResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_syncDataSettingsToMdResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::syncDataSettingsToMdResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "syncDataSettingsToMdResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->syncDataSettingsToMdResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "syncDataSettingsToMdResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_resetMdDataRetryCountResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::resetMdDataRetryCountResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "resetMdDataRetryCountResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->resetMdDataRetryCountResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "resetMdDataRetryCountResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setRemoveRestrictEutranModeResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setRemoveRestrictEutranModeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setRemoveRestrictEutranModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setRemoveRestrictEutranModeResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setRemoveRestrictEutranModeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setLteAccessStratumReportResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setLteAccessStratumReportResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setLteAccessStratumReportResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setLteAccessStratumReportResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setLteAccessStratumReportResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setLteUplinkDataTransferResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setLteUplinkDataTransferResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setLteUplinkDataTransferResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setLteUplinkDataTransferResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setLteUplinkDataTransferResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setRxTestConfigResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setRxTestConfigResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setRxTestConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setRxTestConfigResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setRxTestConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getRxTestResultResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getRxTestResultResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getRxTestResultResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getRxTestResultResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getRxTestResultResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getPOLCapabilityResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getPOLCapabilityResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getPOLCapabilityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getPOLCapabilityResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getPOLCapabilityResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getCurrentPOLListResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getCurrentPOLListResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getCurrentPOLListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getCurrentPOLListResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getCurrentPOLListResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setPOLEntryResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setPOLEntryResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setPOLEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setPOLEntryResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setPOLEntryResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setRoamingEnableResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setRoamingEnableResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setRoamingEnableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setRoamingEnableResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setRoamingEnableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_getRoamingEnableResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::getRoamingEnableResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getRoamingEnableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->getRoamingEnableResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "getRoamingEnableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_vsimNotificationResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::vsimNotificationResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "vsimNotificationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->vsimNotificationResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "vsimNotificationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_vsimOperationResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::vsimOperationResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "vsimOperationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->vsimOperationResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "vsimOperationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setWifiEnabledResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setWifiEnabledResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiEnabledResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setWifiEnabledResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiEnabledResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setWifiAssociatedResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setWifiAssociatedResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiAssociatedResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setWifiAssociatedResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiAssociatedResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setWifiSignalLevelResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setWifiSignalLevelResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiSignalLevelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setWifiSignalLevelResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiSignalLevelResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setWifiIpAddressResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setWifiIpAddressResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiIpAddressResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setWifiIpAddressResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setWifiIpAddressResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setLocationInfoResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setLocationInfoResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setLocationInfoResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setLocationInfoResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setLocationInfoResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setEmergencyAddressIdResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setEmergencyAddressIdResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEmergencyAddressIdResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setEmergencyAddressIdResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setEmergencyAddressIdResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setNattKeepAliveStatusResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setNattKeepAliveStatusResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setNattKeepAliveStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setNattKeepAliveStatusResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setNattKeepAliveStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setE911StateResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setE911StateResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setE911StateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setE911StateResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setE911StateResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_setServiceStateToModemResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::setServiceStateToModemResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setServiceStateToModemResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->setServiceStateToModemResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "setServiceStateToModemResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendRequestRawResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendRequestRawResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendRequestRawResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendRequestRawResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendRequestRawResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioResponse::_hidl_sendRequestStringsResponse(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioResponse::sendRequestStringsResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendRequestStringsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioResponse*>(_hidl_this->getImpl().get())->sendRequestStringsResponse();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioResponse", "sendRequestStringsResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::radio::V1_0::IRadioResponse follow.

// Methods from ::android::hardware::radio::V1_1::IRadioResponse follow.

// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadioResponse follow.

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

        case 136 /* setTrmResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setTrmResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 137 /* getATRResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getATRResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 138 /* setSimPowerResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setSimPowerResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 139 /* setModemPowerResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setModemPowerResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 140 /* hangupAllResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_hangupAllResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 141 /* setCallIndicationResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setCallIndicationResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 142 /* emergencyDialResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_emergencyDialResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 143 /* setEccServiceCategoryResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setEccServiceCategoryResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 144 /* setEccListResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setEccListResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 145 /* vtDialResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_vtDialResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 146 /* voiceAcceptResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_voiceAcceptResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 147 /* replaceVtCallResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_replaceVtCallResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 148 /* setNetworkSelectionModeManualWithActResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setNetworkSelectionModeManualWithActResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 149 /* getAvailableNetworksWithActResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getAvailableNetworksWithActResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 150 /* cancelAvailableNetworksResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_cancelAvailableNetworksResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 151 /* currentStatusResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_currentStatusResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 152 /* eccPreferredRatResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_eccPreferredRatResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 153 /* getSmsParametersResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getSmsParametersResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 154 /* setSmsParametersResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setSmsParametersResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 155 /* getSmsMemStatusResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getSmsMemStatusResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 156 /* setEtwsResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setEtwsResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 157 /* removeCbMsgResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_removeCbMsgResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 158 /* setGsmBroadcastLangsResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setGsmBroadcastLangsResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 159 /* getGsmBroadcastLangsResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getGsmBroadcastLangsResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 160 /* getGsmBroadcastActivationRsp */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getGsmBroadcastActivationRsp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 161 /* sendEmbmsAtCommandResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_sendEmbmsAtCommandResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 162 /* setupDataCallResponseEx */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setupDataCallResponseEx(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 163 /* getDataCallListResponseEx */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getDataCallListResponseEx(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 164 /* setApcModeResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setApcModeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 165 /* getApcInfoResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getApcInfoResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 166 /* triggerModeSwitchByEccResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_triggerModeSwitchByEccResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 167 /* getSmsRuimMemoryStatusResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getSmsRuimMemoryStatusResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 168 /* setFdModeResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setFdModeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 169 /* setResumeRegistrationResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setResumeRegistrationResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 170 /* storeModemTypeResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_storeModemTypeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 171 /* reloadModemTypeResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_reloadModemTypeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 172 /* handleStkCallSetupRequestFromSimWithResCodeResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_handleStkCallSetupRequestFromSimWithResCodeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 173 /* getFemtocellListResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getFemtocellListResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 174 /* abortFemtocellListResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_abortFemtocellListResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 175 /* selectFemtocellResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_selectFemtocellResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 176 /* queryFemtoCellSystemSelectionModeResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_queryFemtoCellSystemSelectionModeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 177 /* setFemtoCellSystemSelectionModeResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setFemtoCellSystemSelectionModeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 178 /* setClipResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setClipResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 179 /* getColpResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getColpResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 180 /* getColrResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getColrResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 181 /* sendCnapResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_sendCnapResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 182 /* setColpResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setColpResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 183 /* setColrResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setColrResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 184 /* queryCallForwardInTimeSlotStatusResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_queryCallForwardInTimeSlotStatusResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 185 /* setCallForwardInTimeSlotResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setCallForwardInTimeSlotResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 186 /* runGbaAuthenticationResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_runGbaAuthenticationResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 187 /* queryPhbStorageInfoResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_queryPhbStorageInfoResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 188 /* writePhbEntryResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_writePhbEntryResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 189 /* readPhbEntryResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_readPhbEntryResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 190 /* queryUPBCapabilityResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_queryUPBCapabilityResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 191 /* editUPBEntryResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_editUPBEntryResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 192 /* deleteUPBEntryResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_deleteUPBEntryResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 193 /* readUPBGasListResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_readUPBGasListResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 194 /* readUPBGrpEntryResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_readUPBGrpEntryResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 195 /* writeUPBGrpEntryResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_writeUPBGrpEntryResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 196 /* getPhoneBookStringsLengthResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getPhoneBookStringsLengthResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 197 /* getPhoneBookMemStorageResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getPhoneBookMemStorageResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 198 /* setPhoneBookMemStorageResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setPhoneBookMemStorageResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 199 /* readPhoneBookEntryExtResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_readPhoneBookEntryExtResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 200 /* writePhoneBookEntryExtResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_writePhoneBookEntryExtResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 201 /* queryUPBAvailableResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_queryUPBAvailableResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 202 /* readUPBEmailEntryResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_readUPBEmailEntryResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 203 /* readUPBSneEntryResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_readUPBSneEntryResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 204 /* readUPBAnrEntryResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_readUPBAnrEntryResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 205 /* readUPBAasListResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_readUPBAasListResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 206 /* queryNetworkLockResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_queryNetworkLockResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 207 /* setNetworkLockResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setNetworkLockResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 208 /* resetRadioResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_resetRadioResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 209 /* syncDataSettingsToMdResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_syncDataSettingsToMdResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 210 /* resetMdDataRetryCountResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_resetMdDataRetryCountResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 211 /* setRemoveRestrictEutranModeResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setRemoveRestrictEutranModeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 212 /* setLteAccessStratumReportResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setLteAccessStratumReportResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 213 /* setLteUplinkDataTransferResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setLteUplinkDataTransferResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 214 /* setRxTestConfigResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setRxTestConfigResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 215 /* getRxTestResultResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getRxTestResultResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 216 /* getPOLCapabilityResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getPOLCapabilityResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 217 /* getCurrentPOLListResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getCurrentPOLListResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 218 /* setPOLEntryResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setPOLEntryResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 219 /* setRoamingEnableResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setRoamingEnableResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 220 /* getRoamingEnableResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_getRoamingEnableResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 221 /* vsimNotificationResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_vsimNotificationResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 222 /* vsimOperationResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_vsimOperationResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 223 /* setWifiEnabledResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setWifiEnabledResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 224 /* setWifiAssociatedResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setWifiAssociatedResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 225 /* setWifiSignalLevelResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setWifiSignalLevelResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 226 /* setWifiIpAddressResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setWifiIpAddressResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 227 /* setLocationInfoResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setLocationInfoResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 228 /* setEmergencyAddressIdResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setEmergencyAddressIdResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 229 /* setNattKeepAliveStatusResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setNattKeepAliveStatusResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 230 /* setE911StateResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setE911StateResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 231 /* setServiceStateToModemResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_setServiceStateToModemResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 232 /* sendRequestRawResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_sendRequestRawResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 233 /* sendRequestStringsResponse */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse::_hidl_sendRequestStringsResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsRadioResponse::BsRadioResponse(const ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioResponse> impl) : ::android::hardware::details::HidlInstrumentor("vendor.mediatek.hardware.radio@2.0", "IRadioResponse"), mImpl(impl) {
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
            sm->registerForNotifications("vendor.mediatek.hardware.radio@2.0::IRadioResponse",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_0
}  // namespace radio
}  // namespace hardware
}  // namespace mediatek
}  // namespace vendor
