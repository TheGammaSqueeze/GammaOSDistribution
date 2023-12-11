#define LOG_TAG "android.hardware.radio@1.2::Radio"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/radio/1.2/BpHwRadio.h>
#include <android/hardware/radio/1.2/BnHwRadio.h>
#include <android/hardware/radio/1.2/BsRadio.h>
#include <android/hardware/radio/1.1/BpHwRadio.h>
#include <android/hardware/radio/1.0/BpHwRadio.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace radio {
namespace V1_2 {

const char* IRadio::descriptor("android.hardware.radio@1.2::IRadio");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IRadio::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwRadio(static_cast<IRadio *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IRadio::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsRadio(static_cast<IRadio *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IRadio::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IRadio::descriptor);
}

// Methods from ::android::hardware::radio::V1_0::IRadio follow.
// no default implementation for: ::android::hardware::Return<void> IRadio::setResponseFunctions(const ::android::sp<::android::hardware::radio::V1_0::IRadioResponse>& radioResponse, const ::android::sp<::android::hardware::radio::V1_0::IRadioIndication>& radioIndication)
// no default implementation for: ::android::hardware::Return<void> IRadio::getIccCardStatus(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::supplyIccPinForApp(int32_t serial, const ::android::hardware::hidl_string& pin, const ::android::hardware::hidl_string& aid)
// no default implementation for: ::android::hardware::Return<void> IRadio::supplyIccPukForApp(int32_t serial, const ::android::hardware::hidl_string& puk, const ::android::hardware::hidl_string& pin, const ::android::hardware::hidl_string& aid)
// no default implementation for: ::android::hardware::Return<void> IRadio::supplyIccPin2ForApp(int32_t serial, const ::android::hardware::hidl_string& pin2, const ::android::hardware::hidl_string& aid)
// no default implementation for: ::android::hardware::Return<void> IRadio::supplyIccPuk2ForApp(int32_t serial, const ::android::hardware::hidl_string& puk2, const ::android::hardware::hidl_string& pin2, const ::android::hardware::hidl_string& aid)
// no default implementation for: ::android::hardware::Return<void> IRadio::changeIccPinForApp(int32_t serial, const ::android::hardware::hidl_string& oldPin, const ::android::hardware::hidl_string& newPin, const ::android::hardware::hidl_string& aid)
// no default implementation for: ::android::hardware::Return<void> IRadio::changeIccPin2ForApp(int32_t serial, const ::android::hardware::hidl_string& oldPin2, const ::android::hardware::hidl_string& newPin2, const ::android::hardware::hidl_string& aid)
// no default implementation for: ::android::hardware::Return<void> IRadio::supplyNetworkDepersonalization(int32_t serial, const ::android::hardware::hidl_string& netPin)
// no default implementation for: ::android::hardware::Return<void> IRadio::getCurrentCalls(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::dial(int32_t serial, const ::android::hardware::radio::V1_0::Dial& dialInfo)
// no default implementation for: ::android::hardware::Return<void> IRadio::getImsiForApp(int32_t serial, const ::android::hardware::hidl_string& aid)
// no default implementation for: ::android::hardware::Return<void> IRadio::hangup(int32_t serial, int32_t gsmIndex)
// no default implementation for: ::android::hardware::Return<void> IRadio::hangupWaitingOrBackground(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::hangupForegroundResumeBackground(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::switchWaitingOrHoldingAndActive(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::conference(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::rejectCall(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getLastCallFailCause(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getSignalStrength(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getVoiceRegistrationState(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getDataRegistrationState(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getOperator(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setRadioPower(int32_t serial, bool on)
// no default implementation for: ::android::hardware::Return<void> IRadio::sendDtmf(int32_t serial, const ::android::hardware::hidl_string& s)
// no default implementation for: ::android::hardware::Return<void> IRadio::sendSms(int32_t serial, const ::android::hardware::radio::V1_0::GsmSmsMessage& message)
// no default implementation for: ::android::hardware::Return<void> IRadio::sendSMSExpectMore(int32_t serial, const ::android::hardware::radio::V1_0::GsmSmsMessage& message)
// no default implementation for: ::android::hardware::Return<void> IRadio::setupDataCall(int32_t serial, ::android::hardware::radio::V1_0::RadioTechnology radioTechnology, const ::android::hardware::radio::V1_0::DataProfileInfo& dataProfileInfo, bool modemCognitive, bool roamingAllowed, bool isRoaming)
// no default implementation for: ::android::hardware::Return<void> IRadio::iccIOForApp(int32_t serial, const ::android::hardware::radio::V1_0::IccIo& iccIo)
// no default implementation for: ::android::hardware::Return<void> IRadio::sendUssd(int32_t serial, const ::android::hardware::hidl_string& ussd)
// no default implementation for: ::android::hardware::Return<void> IRadio::cancelPendingUssd(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getClir(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setClir(int32_t serial, int32_t status)
// no default implementation for: ::android::hardware::Return<void> IRadio::getCallForwardStatus(int32_t serial, const ::android::hardware::radio::V1_0::CallForwardInfo& callInfo)
// no default implementation for: ::android::hardware::Return<void> IRadio::setCallForward(int32_t serial, const ::android::hardware::radio::V1_0::CallForwardInfo& callInfo)
// no default implementation for: ::android::hardware::Return<void> IRadio::getCallWaiting(int32_t serial, int32_t serviceClass)
// no default implementation for: ::android::hardware::Return<void> IRadio::setCallWaiting(int32_t serial, bool enable, int32_t serviceClass)
// no default implementation for: ::android::hardware::Return<void> IRadio::acknowledgeLastIncomingGsmSms(int32_t serial, bool success, ::android::hardware::radio::V1_0::SmsAcknowledgeFailCause cause)
// no default implementation for: ::android::hardware::Return<void> IRadio::acceptCall(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::deactivateDataCall(int32_t serial, int32_t cid, bool reasonRadioShutDown)
// no default implementation for: ::android::hardware::Return<void> IRadio::getFacilityLockForApp(int32_t serial, const ::android::hardware::hidl_string& facility, const ::android::hardware::hidl_string& password, int32_t serviceClass, const ::android::hardware::hidl_string& appId)
// no default implementation for: ::android::hardware::Return<void> IRadio::setFacilityLockForApp(int32_t serial, const ::android::hardware::hidl_string& facility, bool lockState, const ::android::hardware::hidl_string& password, int32_t serviceClass, const ::android::hardware::hidl_string& appId)
// no default implementation for: ::android::hardware::Return<void> IRadio::setBarringPassword(int32_t serial, const ::android::hardware::hidl_string& facility, const ::android::hardware::hidl_string& oldPassword, const ::android::hardware::hidl_string& newPassword)
// no default implementation for: ::android::hardware::Return<void> IRadio::getNetworkSelectionMode(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setNetworkSelectionModeAutomatic(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setNetworkSelectionModeManual(int32_t serial, const ::android::hardware::hidl_string& operatorNumeric)
// no default implementation for: ::android::hardware::Return<void> IRadio::getAvailableNetworks(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::startDtmf(int32_t serial, const ::android::hardware::hidl_string& s)
// no default implementation for: ::android::hardware::Return<void> IRadio::stopDtmf(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getBasebandVersion(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::separateConnection(int32_t serial, int32_t gsmIndex)
// no default implementation for: ::android::hardware::Return<void> IRadio::setMute(int32_t serial, bool enable)
// no default implementation for: ::android::hardware::Return<void> IRadio::getMute(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getClip(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getDataCallList(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setSuppServiceNotifications(int32_t serial, bool enable)
// no default implementation for: ::android::hardware::Return<void> IRadio::writeSmsToSim(int32_t serial, const ::android::hardware::radio::V1_0::SmsWriteArgs& smsWriteArgs)
// no default implementation for: ::android::hardware::Return<void> IRadio::deleteSmsOnSim(int32_t serial, int32_t index)
// no default implementation for: ::android::hardware::Return<void> IRadio::setBandMode(int32_t serial, ::android::hardware::radio::V1_0::RadioBandMode mode)
// no default implementation for: ::android::hardware::Return<void> IRadio::getAvailableBandModes(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::sendEnvelope(int32_t serial, const ::android::hardware::hidl_string& command)
// no default implementation for: ::android::hardware::Return<void> IRadio::sendTerminalResponseToSim(int32_t serial, const ::android::hardware::hidl_string& commandResponse)
// no default implementation for: ::android::hardware::Return<void> IRadio::handleStkCallSetupRequestFromSim(int32_t serial, bool accept)
// no default implementation for: ::android::hardware::Return<void> IRadio::explicitCallTransfer(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setPreferredNetworkType(int32_t serial, ::android::hardware::radio::V1_0::PreferredNetworkType nwType)
// no default implementation for: ::android::hardware::Return<void> IRadio::getPreferredNetworkType(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getNeighboringCids(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setLocationUpdates(int32_t serial, bool enable)
// no default implementation for: ::android::hardware::Return<void> IRadio::setCdmaSubscriptionSource(int32_t serial, ::android::hardware::radio::V1_0::CdmaSubscriptionSource cdmaSub)
// no default implementation for: ::android::hardware::Return<void> IRadio::setCdmaRoamingPreference(int32_t serial, ::android::hardware::radio::V1_0::CdmaRoamingType type)
// no default implementation for: ::android::hardware::Return<void> IRadio::getCdmaRoamingPreference(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setTTYMode(int32_t serial, ::android::hardware::radio::V1_0::TtyMode mode)
// no default implementation for: ::android::hardware::Return<void> IRadio::getTTYMode(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setPreferredVoicePrivacy(int32_t serial, bool enable)
// no default implementation for: ::android::hardware::Return<void> IRadio::getPreferredVoicePrivacy(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::sendCDMAFeatureCode(int32_t serial, const ::android::hardware::hidl_string& featureCode)
// no default implementation for: ::android::hardware::Return<void> IRadio::sendBurstDtmf(int32_t serial, const ::android::hardware::hidl_string& dtmf, int32_t on, int32_t off)
// no default implementation for: ::android::hardware::Return<void> IRadio::sendCdmaSms(int32_t serial, const ::android::hardware::radio::V1_0::CdmaSmsMessage& sms)
// no default implementation for: ::android::hardware::Return<void> IRadio::acknowledgeLastIncomingCdmaSms(int32_t serial, const ::android::hardware::radio::V1_0::CdmaSmsAck& smsAck)
// no default implementation for: ::android::hardware::Return<void> IRadio::getGsmBroadcastConfig(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setGsmBroadcastConfig(int32_t serial, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::GsmBroadcastSmsConfigInfo>& configInfo)
// no default implementation for: ::android::hardware::Return<void> IRadio::setGsmBroadcastActivation(int32_t serial, bool activate)
// no default implementation for: ::android::hardware::Return<void> IRadio::getCdmaBroadcastConfig(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setCdmaBroadcastConfig(int32_t serial, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaBroadcastSmsConfigInfo>& configInfo)
// no default implementation for: ::android::hardware::Return<void> IRadio::setCdmaBroadcastActivation(int32_t serial, bool activate)
// no default implementation for: ::android::hardware::Return<void> IRadio::getCDMASubscription(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::writeSmsToRuim(int32_t serial, const ::android::hardware::radio::V1_0::CdmaSmsWriteArgs& cdmaSms)
// no default implementation for: ::android::hardware::Return<void> IRadio::deleteSmsOnRuim(int32_t serial, int32_t index)
// no default implementation for: ::android::hardware::Return<void> IRadio::getDeviceIdentity(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::exitEmergencyCallbackMode(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getSmscAddress(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setSmscAddress(int32_t serial, const ::android::hardware::hidl_string& smsc)
// no default implementation for: ::android::hardware::Return<void> IRadio::reportSmsMemoryStatus(int32_t serial, bool available)
// no default implementation for: ::android::hardware::Return<void> IRadio::reportStkServiceIsRunning(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getCdmaSubscriptionSource(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::requestIsimAuthentication(int32_t serial, const ::android::hardware::hidl_string& challenge)
// no default implementation for: ::android::hardware::Return<void> IRadio::acknowledgeIncomingGsmSmsWithPdu(int32_t serial, bool success, const ::android::hardware::hidl_string& ackPdu)
// no default implementation for: ::android::hardware::Return<void> IRadio::sendEnvelopeWithStatus(int32_t serial, const ::android::hardware::hidl_string& contents)
// no default implementation for: ::android::hardware::Return<void> IRadio::getVoiceRadioTechnology(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getCellInfoList(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setCellInfoListRate(int32_t serial, int32_t rate)
// no default implementation for: ::android::hardware::Return<void> IRadio::setInitialAttachApn(int32_t serial, const ::android::hardware::radio::V1_0::DataProfileInfo& dataProfileInfo, bool modemCognitive, bool isRoaming)
// no default implementation for: ::android::hardware::Return<void> IRadio::getImsRegistrationState(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::sendImsSms(int32_t serial, const ::android::hardware::radio::V1_0::ImsSmsMessage& message)
// no default implementation for: ::android::hardware::Return<void> IRadio::iccTransmitApduBasicChannel(int32_t serial, const ::android::hardware::radio::V1_0::SimApdu& message)
// no default implementation for: ::android::hardware::Return<void> IRadio::iccOpenLogicalChannel(int32_t serial, const ::android::hardware::hidl_string& aid, int32_t p2)
// no default implementation for: ::android::hardware::Return<void> IRadio::iccCloseLogicalChannel(int32_t serial, int32_t channelId)
// no default implementation for: ::android::hardware::Return<void> IRadio::iccTransmitApduLogicalChannel(int32_t serial, const ::android::hardware::radio::V1_0::SimApdu& message)
// no default implementation for: ::android::hardware::Return<void> IRadio::nvReadItem(int32_t serial, ::android::hardware::radio::V1_0::NvItem itemId)
// no default implementation for: ::android::hardware::Return<void> IRadio::nvWriteItem(int32_t serial, const ::android::hardware::radio::V1_0::NvWriteItem& item)
// no default implementation for: ::android::hardware::Return<void> IRadio::nvWriteCdmaPrl(int32_t serial, const ::android::hardware::hidl_vec<uint8_t>& prl)
// no default implementation for: ::android::hardware::Return<void> IRadio::nvResetConfig(int32_t serial, ::android::hardware::radio::V1_0::ResetNvType resetType)
// no default implementation for: ::android::hardware::Return<void> IRadio::setUiccSubscription(int32_t serial, const ::android::hardware::radio::V1_0::SelectUiccSub& uiccSub)
// no default implementation for: ::android::hardware::Return<void> IRadio::setDataAllowed(int32_t serial, bool allow)
// no default implementation for: ::android::hardware::Return<void> IRadio::getHardwareConfig(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::requestIccSimAuthentication(int32_t serial, int32_t authContext, const ::android::hardware::hidl_string& authData, const ::android::hardware::hidl_string& aid)
// no default implementation for: ::android::hardware::Return<void> IRadio::setDataProfile(int32_t serial, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::DataProfileInfo>& profiles, bool isRoaming)
// no default implementation for: ::android::hardware::Return<void> IRadio::requestShutdown(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getRadioCapability(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setRadioCapability(int32_t serial, const ::android::hardware::radio::V1_0::RadioCapability& rc)
// no default implementation for: ::android::hardware::Return<void> IRadio::startLceService(int32_t serial, int32_t reportInterval, bool pullMode)
// no default implementation for: ::android::hardware::Return<void> IRadio::stopLceService(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::pullLceData(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::getModemActivityInfo(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::setAllowedCarriers(int32_t serial, bool allAllowed, const ::android::hardware::radio::V1_0::CarrierRestrictions& carriers)
// no default implementation for: ::android::hardware::Return<void> IRadio::getAllowedCarriers(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::sendDeviceState(int32_t serial, ::android::hardware::radio::V1_0::DeviceStateType deviceStateType, bool state)
// no default implementation for: ::android::hardware::Return<void> IRadio::setIndicationFilter(int32_t serial, ::android::hardware::hidl_bitfield<::android::hardware::radio::V1_0::IndicationFilter> indicationFilter)
// no default implementation for: ::android::hardware::Return<void> IRadio::setSimCardPower(int32_t serial, bool powerUp)
// no default implementation for: ::android::hardware::Return<void> IRadio::responseAcknowledgement()

// Methods from ::android::hardware::radio::V1_1::IRadio follow.
// no default implementation for: ::android::hardware::Return<void> IRadio::setCarrierInfoForImsiEncryption(int32_t serial, const ::android::hardware::radio::V1_1::ImsiEncryptionInfo& imsiEncryptionInfo)
// no default implementation for: ::android::hardware::Return<void> IRadio::setSimCardPower_1_1(int32_t serial, ::android::hardware::radio::V1_1::CardPowerState powerUp)
// no default implementation for: ::android::hardware::Return<void> IRadio::startNetworkScan(int32_t serial, const ::android::hardware::radio::V1_1::NetworkScanRequest& request)
// no default implementation for: ::android::hardware::Return<void> IRadio::stopNetworkScan(int32_t serial)
// no default implementation for: ::android::hardware::Return<void> IRadio::startKeepalive(int32_t serial, const ::android::hardware::radio::V1_1::KeepaliveRequest& keepalive)
// no default implementation for: ::android::hardware::Return<void> IRadio::stopKeepalive(int32_t serial, int32_t sessionHandle)

// Methods from ::android::hardware::radio::V1_2::IRadio follow.
// no default implementation for: ::android::hardware::Return<void> IRadio::startNetworkScan_1_2(int32_t serial, const ::android::hardware::radio::V1_2::NetworkScanRequest& request)
// no default implementation for: ::android::hardware::Return<void> IRadio::setIndicationFilter_1_2(int32_t serial, ::android::hardware::hidl_bitfield<::android::hardware::radio::V1_2::IndicationFilter> indicationFilter)
// no default implementation for: ::android::hardware::Return<void> IRadio::setSignalStrengthReportingCriteria(int32_t serial, int32_t hysteresisMs, int32_t hysteresisDb, const ::android::hardware::hidl_vec<int32_t>& thresholdsDbm, ::android::hardware::radio::V1_2::AccessNetwork accessNetwork)
// no default implementation for: ::android::hardware::Return<void> IRadio::setLinkCapacityReportingCriteria(int32_t serial, int32_t hysteresisMs, int32_t hysteresisDlKbps, int32_t hysteresisUlKbps, const ::android::hardware::hidl_vec<int32_t>& thresholdsDownlinkKbps, const ::android::hardware::hidl_vec<int32_t>& thresholdsUplinkKbps, ::android::hardware::radio::V1_2::AccessNetwork accessNetwork)
// no default implementation for: ::android::hardware::Return<void> IRadio::setupDataCall_1_2(int32_t serial, ::android::hardware::radio::V1_2::AccessNetwork accessNetwork, const ::android::hardware::radio::V1_0::DataProfileInfo& dataProfileInfo, bool modemCognitive, bool roamingAllowed, bool isRoaming, ::android::hardware::radio::V1_2::DataRequestReason reason, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& addresses, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& dnses)
// no default implementation for: ::android::hardware::Return<void> IRadio::deactivateDataCall_1_2(int32_t serial, int32_t cid, ::android::hardware::radio::V1_2::DataRequestReason reason)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IRadio::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::radio::V1_2::IRadio::descriptor,
        ::android::hardware::radio::V1_1::IRadio::descriptor,
        ::android::hardware::radio::V1_0::IRadio::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadio::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadio::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::radio::V1_2::IRadio::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadio::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){43,90,254,246,142,62,47,241,218,182,62,79,46,229,115,55,239,38,53,236,129,47,73,8,12,173,252,233,102,211,59,82} /* 2b5afef68e3e2ff1dab63e4f2ee57337ef2635ec812f49080cadfce966d33b52 */,
        (uint8_t[32]){134,251,7,154,96,11,35,1,167,82,36,157,251,252,83,152,58,121,93,117,47,17,170,188,182,131,21,161,137,246,201,162} /* 86fb079a600b2301a752249dfbfc53983a795d752f11aabcb68315a189f6c9a2 */,
        (uint8_t[32]){207,170,176,228,92,93,123,53,149,3,45,100,157,162,158,215,18,233,32,249,86,193,54,113,239,211,86,2,250,129,201,35} /* cfaab0e45c5d7b3595032d649da29ed712e920f956c13671efd35602fa81c923 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadio::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IRadio::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IRadio::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadio::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IRadio::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IRadio::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::radio::V1_2::IRadio>> IRadio::castFrom(const ::android::sp<::android::hardware::radio::V1_2::IRadio>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::radio::V1_2::IRadio>> IRadio::castFrom(const ::android::sp<::android::hardware::radio::V1_1::IRadio>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadio, ::android::hardware::radio::V1_1::IRadio, BpHwRadio>(
            parent, "android.hardware.radio@1.2::IRadio", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::radio::V1_2::IRadio>> IRadio::castFrom(const ::android::sp<::android::hardware::radio::V1_0::IRadio>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadio, ::android::hardware::radio::V1_0::IRadio, BpHwRadio>(
            parent, "android.hardware.radio@1.2::IRadio", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::radio::V1_2::IRadio>> IRadio::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadio, ::android::hidl::base::V1_0::IBase, BpHwRadio>(
            parent, "android.hardware.radio@1.2::IRadio", emitError);
}

BpHwRadio::BpHwRadio(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IRadio>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.radio@1.2", "IRadio") {
}

void BpHwRadio::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IRadio>::onLastStrongRef(id);
}
// Methods from ::android::hardware::radio::V1_2::IRadio follow.
::android::hardware::Return<void> BpHwRadio::_hidl_startNetworkScan_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t serial, const ::android::hardware::radio::V1_2::NetworkScanRequest& request) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::startNetworkScan_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&request);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.2", "IRadio", "startNetworkScan_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadio::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(serial);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_request_parent;

    _hidl_err = _hidl_data.writeBuffer(&request, sizeof(request), &_hidl_request_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            request,
            &_hidl_data,
            _hidl_request_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(137 /* startNetworkScan_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.2", "IRadio", "startNetworkScan_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setIndicationFilter_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t serial, ::android::hardware::hidl_bitfield<::android::hardware::radio::V1_2::IndicationFilter> indicationFilter) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setIndicationFilter_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&indicationFilter);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.2", "IRadio", "setIndicationFilter_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadio::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(serial);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)indicationFilter);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(138 /* setIndicationFilter_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.2", "IRadio", "setIndicationFilter_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setSignalStrengthReportingCriteria(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t serial, int32_t hysteresisMs, int32_t hysteresisDb, const ::android::hardware::hidl_vec<int32_t>& thresholdsDbm, ::android::hardware::radio::V1_2::AccessNetwork accessNetwork) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setSignalStrengthReportingCriteria::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&hysteresisMs);
        _hidl_args.push_back((void *)&hysteresisDb);
        _hidl_args.push_back((void *)&thresholdsDbm);
        _hidl_args.push_back((void *)&accessNetwork);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.2", "IRadio", "setSignalStrengthReportingCriteria", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadio::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(serial);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(hysteresisMs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(hysteresisDb);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_thresholdsDbm_parent;

    _hidl_err = _hidl_data.writeBuffer(&thresholdsDbm, sizeof(thresholdsDbm), &_hidl_thresholdsDbm_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_thresholdsDbm_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            thresholdsDbm,
            &_hidl_data,
            _hidl_thresholdsDbm_parent,
            0 /* parentOffset */, &_hidl_thresholdsDbm_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)accessNetwork);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(139 /* setSignalStrengthReportingCriteria */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.2", "IRadio", "setSignalStrengthReportingCriteria", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setLinkCapacityReportingCriteria(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t serial, int32_t hysteresisMs, int32_t hysteresisDlKbps, int32_t hysteresisUlKbps, const ::android::hardware::hidl_vec<int32_t>& thresholdsDownlinkKbps, const ::android::hardware::hidl_vec<int32_t>& thresholdsUplinkKbps, ::android::hardware::radio::V1_2::AccessNetwork accessNetwork) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setLinkCapacityReportingCriteria::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&hysteresisMs);
        _hidl_args.push_back((void *)&hysteresisDlKbps);
        _hidl_args.push_back((void *)&hysteresisUlKbps);
        _hidl_args.push_back((void *)&thresholdsDownlinkKbps);
        _hidl_args.push_back((void *)&thresholdsUplinkKbps);
        _hidl_args.push_back((void *)&accessNetwork);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.2", "IRadio", "setLinkCapacityReportingCriteria", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadio::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(serial);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(hysteresisMs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(hysteresisDlKbps);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(hysteresisUlKbps);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_thresholdsDownlinkKbps_parent;

    _hidl_err = _hidl_data.writeBuffer(&thresholdsDownlinkKbps, sizeof(thresholdsDownlinkKbps), &_hidl_thresholdsDownlinkKbps_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_thresholdsDownlinkKbps_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            thresholdsDownlinkKbps,
            &_hidl_data,
            _hidl_thresholdsDownlinkKbps_parent,
            0 /* parentOffset */, &_hidl_thresholdsDownlinkKbps_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_thresholdsUplinkKbps_parent;

    _hidl_err = _hidl_data.writeBuffer(&thresholdsUplinkKbps, sizeof(thresholdsUplinkKbps), &_hidl_thresholdsUplinkKbps_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_thresholdsUplinkKbps_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            thresholdsUplinkKbps,
            &_hidl_data,
            _hidl_thresholdsUplinkKbps_parent,
            0 /* parentOffset */, &_hidl_thresholdsUplinkKbps_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)accessNetwork);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(140 /* setLinkCapacityReportingCriteria */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.2", "IRadio", "setLinkCapacityReportingCriteria", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setupDataCall_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t serial, ::android::hardware::radio::V1_2::AccessNetwork accessNetwork, const ::android::hardware::radio::V1_0::DataProfileInfo& dataProfileInfo, bool modemCognitive, bool roamingAllowed, bool isRoaming, ::android::hardware::radio::V1_2::DataRequestReason reason, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& addresses, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& dnses) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setupDataCall_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&accessNetwork);
        _hidl_args.push_back((void *)&dataProfileInfo);
        _hidl_args.push_back((void *)&modemCognitive);
        _hidl_args.push_back((void *)&roamingAllowed);
        _hidl_args.push_back((void *)&isRoaming);
        _hidl_args.push_back((void *)&reason);
        _hidl_args.push_back((void *)&addresses);
        _hidl_args.push_back((void *)&dnses);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.2", "IRadio", "setupDataCall_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadio::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(serial);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)accessNetwork);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dataProfileInfo_parent;

    _hidl_err = _hidl_data.writeBuffer(&dataProfileInfo, sizeof(dataProfileInfo), &_hidl_dataProfileInfo_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            dataProfileInfo,
            &_hidl_data,
            _hidl_dataProfileInfo_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(modemCognitive);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(roamingAllowed);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(isRoaming);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)reason);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_addresses_parent;

    _hidl_err = _hidl_data.writeBuffer(&addresses, sizeof(addresses), &_hidl_addresses_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_addresses_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            addresses,
            &_hidl_data,
            _hidl_addresses_parent,
            0 /* parentOffset */, &_hidl_addresses_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < addresses.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                addresses[_hidl_index_0],
                &_hidl_data,
                _hidl_addresses_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    size_t _hidl_dnses_parent;

    _hidl_err = _hidl_data.writeBuffer(&dnses, sizeof(dnses), &_hidl_dnses_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dnses_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            dnses,
            &_hidl_data,
            _hidl_dnses_parent,
            0 /* parentOffset */, &_hidl_dnses_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < dnses.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                dnses[_hidl_index_0],
                &_hidl_data,
                _hidl_dnses_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(141 /* setupDataCall_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.2", "IRadio", "setupDataCall_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_deactivateDataCall_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t serial, int32_t cid, ::android::hardware::radio::V1_2::DataRequestReason reason) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::deactivateDataCall_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&cid);
        _hidl_args.push_back((void *)&reason);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio", "1.2", "IRadio", "deactivateDataCall_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadio::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(serial);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(cid);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)reason);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(142 /* deactivateDataCall_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio", "1.2", "IRadio", "deactivateDataCall_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::radio::V1_0::IRadio follow.
::android::hardware::Return<void> BpHwRadio::setResponseFunctions(const ::android::sp<::android::hardware::radio::V1_0::IRadioResponse>& radioResponse, const ::android::sp<::android::hardware::radio::V1_0::IRadioIndication>& radioIndication){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setResponseFunctions(this, this, radioResponse, radioIndication);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getIccCardStatus(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getIccCardStatus(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::supplyIccPinForApp(int32_t serial, const ::android::hardware::hidl_string& pin, const ::android::hardware::hidl_string& aid){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_supplyIccPinForApp(this, this, serial, pin, aid);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::supplyIccPukForApp(int32_t serial, const ::android::hardware::hidl_string& puk, const ::android::hardware::hidl_string& pin, const ::android::hardware::hidl_string& aid){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_supplyIccPukForApp(this, this, serial, puk, pin, aid);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::supplyIccPin2ForApp(int32_t serial, const ::android::hardware::hidl_string& pin2, const ::android::hardware::hidl_string& aid){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_supplyIccPin2ForApp(this, this, serial, pin2, aid);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::supplyIccPuk2ForApp(int32_t serial, const ::android::hardware::hidl_string& puk2, const ::android::hardware::hidl_string& pin2, const ::android::hardware::hidl_string& aid){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_supplyIccPuk2ForApp(this, this, serial, puk2, pin2, aid);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::changeIccPinForApp(int32_t serial, const ::android::hardware::hidl_string& oldPin, const ::android::hardware::hidl_string& newPin, const ::android::hardware::hidl_string& aid){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_changeIccPinForApp(this, this, serial, oldPin, newPin, aid);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::changeIccPin2ForApp(int32_t serial, const ::android::hardware::hidl_string& oldPin2, const ::android::hardware::hidl_string& newPin2, const ::android::hardware::hidl_string& aid){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_changeIccPin2ForApp(this, this, serial, oldPin2, newPin2, aid);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::supplyNetworkDepersonalization(int32_t serial, const ::android::hardware::hidl_string& netPin){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_supplyNetworkDepersonalization(this, this, serial, netPin);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getCurrentCalls(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getCurrentCalls(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::dial(int32_t serial, const ::android::hardware::radio::V1_0::Dial& dialInfo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_dial(this, this, serial, dialInfo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getImsiForApp(int32_t serial, const ::android::hardware::hidl_string& aid){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getImsiForApp(this, this, serial, aid);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::hangup(int32_t serial, int32_t gsmIndex){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_hangup(this, this, serial, gsmIndex);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::hangupWaitingOrBackground(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_hangupWaitingOrBackground(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::hangupForegroundResumeBackground(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_hangupForegroundResumeBackground(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::switchWaitingOrHoldingAndActive(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_switchWaitingOrHoldingAndActive(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::conference(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_conference(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::rejectCall(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_rejectCall(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getLastCallFailCause(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getLastCallFailCause(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getSignalStrength(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getSignalStrength(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getVoiceRegistrationState(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getVoiceRegistrationState(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getDataRegistrationState(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getDataRegistrationState(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getOperator(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getOperator(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setRadioPower(int32_t serial, bool on){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setRadioPower(this, this, serial, on);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendDtmf(int32_t serial, const ::android::hardware::hidl_string& s){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_sendDtmf(this, this, serial, s);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendSms(int32_t serial, const ::android::hardware::radio::V1_0::GsmSmsMessage& message){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_sendSms(this, this, serial, message);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendSMSExpectMore(int32_t serial, const ::android::hardware::radio::V1_0::GsmSmsMessage& message){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_sendSMSExpectMore(this, this, serial, message);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setupDataCall(int32_t serial, ::android::hardware::radio::V1_0::RadioTechnology radioTechnology, const ::android::hardware::radio::V1_0::DataProfileInfo& dataProfileInfo, bool modemCognitive, bool roamingAllowed, bool isRoaming){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setupDataCall(this, this, serial, radioTechnology, dataProfileInfo, modemCognitive, roamingAllowed, isRoaming);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::iccIOForApp(int32_t serial, const ::android::hardware::radio::V1_0::IccIo& iccIo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_iccIOForApp(this, this, serial, iccIo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendUssd(int32_t serial, const ::android::hardware::hidl_string& ussd){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_sendUssd(this, this, serial, ussd);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::cancelPendingUssd(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_cancelPendingUssd(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getClir(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getClir(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setClir(int32_t serial, int32_t status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setClir(this, this, serial, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getCallForwardStatus(int32_t serial, const ::android::hardware::radio::V1_0::CallForwardInfo& callInfo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getCallForwardStatus(this, this, serial, callInfo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setCallForward(int32_t serial, const ::android::hardware::radio::V1_0::CallForwardInfo& callInfo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setCallForward(this, this, serial, callInfo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getCallWaiting(int32_t serial, int32_t serviceClass){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getCallWaiting(this, this, serial, serviceClass);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setCallWaiting(int32_t serial, bool enable, int32_t serviceClass){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setCallWaiting(this, this, serial, enable, serviceClass);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::acknowledgeLastIncomingGsmSms(int32_t serial, bool success, ::android::hardware::radio::V1_0::SmsAcknowledgeFailCause cause){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_acknowledgeLastIncomingGsmSms(this, this, serial, success, cause);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::acceptCall(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_acceptCall(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::deactivateDataCall(int32_t serial, int32_t cid, bool reasonRadioShutDown){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_deactivateDataCall(this, this, serial, cid, reasonRadioShutDown);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getFacilityLockForApp(int32_t serial, const ::android::hardware::hidl_string& facility, const ::android::hardware::hidl_string& password, int32_t serviceClass, const ::android::hardware::hidl_string& appId){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getFacilityLockForApp(this, this, serial, facility, password, serviceClass, appId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setFacilityLockForApp(int32_t serial, const ::android::hardware::hidl_string& facility, bool lockState, const ::android::hardware::hidl_string& password, int32_t serviceClass, const ::android::hardware::hidl_string& appId){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setFacilityLockForApp(this, this, serial, facility, lockState, password, serviceClass, appId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setBarringPassword(int32_t serial, const ::android::hardware::hidl_string& facility, const ::android::hardware::hidl_string& oldPassword, const ::android::hardware::hidl_string& newPassword){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setBarringPassword(this, this, serial, facility, oldPassword, newPassword);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getNetworkSelectionMode(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getNetworkSelectionMode(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setNetworkSelectionModeAutomatic(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setNetworkSelectionModeAutomatic(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setNetworkSelectionModeManual(int32_t serial, const ::android::hardware::hidl_string& operatorNumeric){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setNetworkSelectionModeManual(this, this, serial, operatorNumeric);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getAvailableNetworks(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getAvailableNetworks(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::startDtmf(int32_t serial, const ::android::hardware::hidl_string& s){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_startDtmf(this, this, serial, s);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::stopDtmf(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_stopDtmf(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getBasebandVersion(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getBasebandVersion(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::separateConnection(int32_t serial, int32_t gsmIndex){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_separateConnection(this, this, serial, gsmIndex);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setMute(int32_t serial, bool enable){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setMute(this, this, serial, enable);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getMute(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getMute(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getClip(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getClip(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getDataCallList(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getDataCallList(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setSuppServiceNotifications(int32_t serial, bool enable){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setSuppServiceNotifications(this, this, serial, enable);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::writeSmsToSim(int32_t serial, const ::android::hardware::radio::V1_0::SmsWriteArgs& smsWriteArgs){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_writeSmsToSim(this, this, serial, smsWriteArgs);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::deleteSmsOnSim(int32_t serial, int32_t index){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_deleteSmsOnSim(this, this, serial, index);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setBandMode(int32_t serial, ::android::hardware::radio::V1_0::RadioBandMode mode){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setBandMode(this, this, serial, mode);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getAvailableBandModes(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getAvailableBandModes(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendEnvelope(int32_t serial, const ::android::hardware::hidl_string& command){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_sendEnvelope(this, this, serial, command);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendTerminalResponseToSim(int32_t serial, const ::android::hardware::hidl_string& commandResponse){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_sendTerminalResponseToSim(this, this, serial, commandResponse);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::handleStkCallSetupRequestFromSim(int32_t serial, bool accept){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_handleStkCallSetupRequestFromSim(this, this, serial, accept);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::explicitCallTransfer(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_explicitCallTransfer(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setPreferredNetworkType(int32_t serial, ::android::hardware::radio::V1_0::PreferredNetworkType nwType){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setPreferredNetworkType(this, this, serial, nwType);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getPreferredNetworkType(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getPreferredNetworkType(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getNeighboringCids(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getNeighboringCids(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setLocationUpdates(int32_t serial, bool enable){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setLocationUpdates(this, this, serial, enable);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setCdmaSubscriptionSource(int32_t serial, ::android::hardware::radio::V1_0::CdmaSubscriptionSource cdmaSub){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setCdmaSubscriptionSource(this, this, serial, cdmaSub);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setCdmaRoamingPreference(int32_t serial, ::android::hardware::radio::V1_0::CdmaRoamingType type){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setCdmaRoamingPreference(this, this, serial, type);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getCdmaRoamingPreference(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getCdmaRoamingPreference(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setTTYMode(int32_t serial, ::android::hardware::radio::V1_0::TtyMode mode){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setTTYMode(this, this, serial, mode);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getTTYMode(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getTTYMode(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setPreferredVoicePrivacy(int32_t serial, bool enable){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setPreferredVoicePrivacy(this, this, serial, enable);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getPreferredVoicePrivacy(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getPreferredVoicePrivacy(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendCDMAFeatureCode(int32_t serial, const ::android::hardware::hidl_string& featureCode){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_sendCDMAFeatureCode(this, this, serial, featureCode);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendBurstDtmf(int32_t serial, const ::android::hardware::hidl_string& dtmf, int32_t on, int32_t off){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_sendBurstDtmf(this, this, serial, dtmf, on, off);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendCdmaSms(int32_t serial, const ::android::hardware::radio::V1_0::CdmaSmsMessage& sms){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_sendCdmaSms(this, this, serial, sms);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::acknowledgeLastIncomingCdmaSms(int32_t serial, const ::android::hardware::radio::V1_0::CdmaSmsAck& smsAck){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_acknowledgeLastIncomingCdmaSms(this, this, serial, smsAck);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getGsmBroadcastConfig(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getGsmBroadcastConfig(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setGsmBroadcastConfig(int32_t serial, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::GsmBroadcastSmsConfigInfo>& configInfo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setGsmBroadcastConfig(this, this, serial, configInfo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setGsmBroadcastActivation(int32_t serial, bool activate){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setGsmBroadcastActivation(this, this, serial, activate);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getCdmaBroadcastConfig(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getCdmaBroadcastConfig(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setCdmaBroadcastConfig(int32_t serial, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaBroadcastSmsConfigInfo>& configInfo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setCdmaBroadcastConfig(this, this, serial, configInfo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setCdmaBroadcastActivation(int32_t serial, bool activate){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setCdmaBroadcastActivation(this, this, serial, activate);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getCDMASubscription(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getCDMASubscription(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::writeSmsToRuim(int32_t serial, const ::android::hardware::radio::V1_0::CdmaSmsWriteArgs& cdmaSms){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_writeSmsToRuim(this, this, serial, cdmaSms);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::deleteSmsOnRuim(int32_t serial, int32_t index){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_deleteSmsOnRuim(this, this, serial, index);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getDeviceIdentity(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getDeviceIdentity(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::exitEmergencyCallbackMode(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_exitEmergencyCallbackMode(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getSmscAddress(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getSmscAddress(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setSmscAddress(int32_t serial, const ::android::hardware::hidl_string& smsc){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setSmscAddress(this, this, serial, smsc);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::reportSmsMemoryStatus(int32_t serial, bool available){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_reportSmsMemoryStatus(this, this, serial, available);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::reportStkServiceIsRunning(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_reportStkServiceIsRunning(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getCdmaSubscriptionSource(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getCdmaSubscriptionSource(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::requestIsimAuthentication(int32_t serial, const ::android::hardware::hidl_string& challenge){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_requestIsimAuthentication(this, this, serial, challenge);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::acknowledgeIncomingGsmSmsWithPdu(int32_t serial, bool success, const ::android::hardware::hidl_string& ackPdu){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_acknowledgeIncomingGsmSmsWithPdu(this, this, serial, success, ackPdu);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendEnvelopeWithStatus(int32_t serial, const ::android::hardware::hidl_string& contents){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_sendEnvelopeWithStatus(this, this, serial, contents);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getVoiceRadioTechnology(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getVoiceRadioTechnology(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getCellInfoList(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getCellInfoList(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setCellInfoListRate(int32_t serial, int32_t rate){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setCellInfoListRate(this, this, serial, rate);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setInitialAttachApn(int32_t serial, const ::android::hardware::radio::V1_0::DataProfileInfo& dataProfileInfo, bool modemCognitive, bool isRoaming){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setInitialAttachApn(this, this, serial, dataProfileInfo, modemCognitive, isRoaming);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getImsRegistrationState(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getImsRegistrationState(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendImsSms(int32_t serial, const ::android::hardware::radio::V1_0::ImsSmsMessage& message){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_sendImsSms(this, this, serial, message);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::iccTransmitApduBasicChannel(int32_t serial, const ::android::hardware::radio::V1_0::SimApdu& message){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_iccTransmitApduBasicChannel(this, this, serial, message);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::iccOpenLogicalChannel(int32_t serial, const ::android::hardware::hidl_string& aid, int32_t p2){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_iccOpenLogicalChannel(this, this, serial, aid, p2);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::iccCloseLogicalChannel(int32_t serial, int32_t channelId){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_iccCloseLogicalChannel(this, this, serial, channelId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::iccTransmitApduLogicalChannel(int32_t serial, const ::android::hardware::radio::V1_0::SimApdu& message){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_iccTransmitApduLogicalChannel(this, this, serial, message);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::nvReadItem(int32_t serial, ::android::hardware::radio::V1_0::NvItem itemId){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_nvReadItem(this, this, serial, itemId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::nvWriteItem(int32_t serial, const ::android::hardware::radio::V1_0::NvWriteItem& item){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_nvWriteItem(this, this, serial, item);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::nvWriteCdmaPrl(int32_t serial, const ::android::hardware::hidl_vec<uint8_t>& prl){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_nvWriteCdmaPrl(this, this, serial, prl);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::nvResetConfig(int32_t serial, ::android::hardware::radio::V1_0::ResetNvType resetType){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_nvResetConfig(this, this, serial, resetType);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setUiccSubscription(int32_t serial, const ::android::hardware::radio::V1_0::SelectUiccSub& uiccSub){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setUiccSubscription(this, this, serial, uiccSub);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setDataAllowed(int32_t serial, bool allow){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setDataAllowed(this, this, serial, allow);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getHardwareConfig(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getHardwareConfig(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::requestIccSimAuthentication(int32_t serial, int32_t authContext, const ::android::hardware::hidl_string& authData, const ::android::hardware::hidl_string& aid){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_requestIccSimAuthentication(this, this, serial, authContext, authData, aid);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setDataProfile(int32_t serial, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::DataProfileInfo>& profiles, bool isRoaming){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setDataProfile(this, this, serial, profiles, isRoaming);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::requestShutdown(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_requestShutdown(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getRadioCapability(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getRadioCapability(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setRadioCapability(int32_t serial, const ::android::hardware::radio::V1_0::RadioCapability& rc){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setRadioCapability(this, this, serial, rc);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::startLceService(int32_t serial, int32_t reportInterval, bool pullMode){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_startLceService(this, this, serial, reportInterval, pullMode);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::stopLceService(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_stopLceService(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::pullLceData(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_pullLceData(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getModemActivityInfo(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getModemActivityInfo(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setAllowedCarriers(int32_t serial, bool allAllowed, const ::android::hardware::radio::V1_0::CarrierRestrictions& carriers){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setAllowedCarriers(this, this, serial, allAllowed, carriers);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getAllowedCarriers(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_getAllowedCarriers(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendDeviceState(int32_t serial, ::android::hardware::radio::V1_0::DeviceStateType deviceStateType, bool state){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_sendDeviceState(this, this, serial, deviceStateType, state);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setIndicationFilter(int32_t serial, ::android::hardware::hidl_bitfield<::android::hardware::radio::V1_0::IndicationFilter> indicationFilter){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setIndicationFilter(this, this, serial, indicationFilter);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setSimCardPower(int32_t serial, bool powerUp){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_setSimCardPower(this, this, serial, powerUp);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::responseAcknowledgement(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadio::_hidl_responseAcknowledgement(this, this);

    return _hidl_out;
}


// Methods from ::android::hardware::radio::V1_1::IRadio follow.
::android::hardware::Return<void> BpHwRadio::setCarrierInfoForImsiEncryption(int32_t serial, const ::android::hardware::radio::V1_1::ImsiEncryptionInfo& imsiEncryptionInfo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadio::_hidl_setCarrierInfoForImsiEncryption(this, this, serial, imsiEncryptionInfo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setSimCardPower_1_1(int32_t serial, ::android::hardware::radio::V1_1::CardPowerState powerUp){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadio::_hidl_setSimCardPower_1_1(this, this, serial, powerUp);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::startNetworkScan(int32_t serial, const ::android::hardware::radio::V1_1::NetworkScanRequest& request){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadio::_hidl_startNetworkScan(this, this, serial, request);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::stopNetworkScan(int32_t serial){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadio::_hidl_stopNetworkScan(this, this, serial);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::startKeepalive(int32_t serial, const ::android::hardware::radio::V1_1::KeepaliveRequest& keepalive){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadio::_hidl_startKeepalive(this, this, serial, keepalive);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::stopKeepalive(int32_t serial, int32_t sessionHandle){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadio::_hidl_stopKeepalive(this, this, serial, sessionHandle);

    return _hidl_out;
}


// Methods from ::android::hardware::radio::V1_2::IRadio follow.
::android::hardware::Return<void> BpHwRadio::startNetworkScan_1_2(int32_t serial, const ::android::hardware::radio::V1_2::NetworkScanRequest& request){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadio::_hidl_startNetworkScan_1_2(this, this, serial, request);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setIndicationFilter_1_2(int32_t serial, ::android::hardware::hidl_bitfield<::android::hardware::radio::V1_2::IndicationFilter> indicationFilter){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadio::_hidl_setIndicationFilter_1_2(this, this, serial, indicationFilter);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setSignalStrengthReportingCriteria(int32_t serial, int32_t hysteresisMs, int32_t hysteresisDb, const ::android::hardware::hidl_vec<int32_t>& thresholdsDbm, ::android::hardware::radio::V1_2::AccessNetwork accessNetwork){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadio::_hidl_setSignalStrengthReportingCriteria(this, this, serial, hysteresisMs, hysteresisDb, thresholdsDbm, accessNetwork);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setLinkCapacityReportingCriteria(int32_t serial, int32_t hysteresisMs, int32_t hysteresisDlKbps, int32_t hysteresisUlKbps, const ::android::hardware::hidl_vec<int32_t>& thresholdsDownlinkKbps, const ::android::hardware::hidl_vec<int32_t>& thresholdsUplinkKbps, ::android::hardware::radio::V1_2::AccessNetwork accessNetwork){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadio::_hidl_setLinkCapacityReportingCriteria(this, this, serial, hysteresisMs, hysteresisDlKbps, hysteresisUlKbps, thresholdsDownlinkKbps, thresholdsUplinkKbps, accessNetwork);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setupDataCall_1_2(int32_t serial, ::android::hardware::radio::V1_2::AccessNetwork accessNetwork, const ::android::hardware::radio::V1_0::DataProfileInfo& dataProfileInfo, bool modemCognitive, bool roamingAllowed, bool isRoaming, ::android::hardware::radio::V1_2::DataRequestReason reason, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& addresses, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& dnses){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadio::_hidl_setupDataCall_1_2(this, this, serial, accessNetwork, dataProfileInfo, modemCognitive, roamingAllowed, isRoaming, reason, addresses, dnses);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::deactivateDataCall_1_2(int32_t serial, int32_t cid, ::android::hardware::radio::V1_2::DataRequestReason reason){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadio::_hidl_deactivateDataCall_1_2(this, this, serial, cid, reason);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwRadio::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwRadio::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwRadio::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwRadio::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwRadio::BnHwRadio(const ::android::sp<IRadio> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.radio@1.2", "IRadio") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwRadio::~BnHwRadio() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::radio::V1_2::IRadio follow.
::android::status_t BnHwRadio::_hidl_startNetworkScan_1_2(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadio::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t serial;
    ::android::hardware::radio::V1_2::NetworkScanRequest* request;

    _hidl_err = _hidl_data.readInt32(&serial);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_request_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*request), &_hidl_request_parent,  const_cast<const void**>(reinterpret_cast<void **>(&request)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::NetworkScanRequest &>(*request),
            _hidl_data,
            _hidl_request_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::startNetworkScan_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)request);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.2", "IRadio", "startNetworkScan_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->startNetworkScan_1_2(serial, *request);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.2", "IRadio", "startNetworkScan_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setIndicationFilter_1_2(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadio::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t serial;
    ::android::hardware::hidl_bitfield<::android::hardware::radio::V1_2::IndicationFilter> indicationFilter;

    _hidl_err = _hidl_data.readInt32(&serial);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&indicationFilter);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setIndicationFilter_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&indicationFilter);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.2", "IRadio", "setIndicationFilter_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setIndicationFilter_1_2(serial, indicationFilter);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.2", "IRadio", "setIndicationFilter_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setSignalStrengthReportingCriteria(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadio::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t serial;
    int32_t hysteresisMs;
    int32_t hysteresisDb;
    const ::android::hardware::hidl_vec<int32_t>* thresholdsDbm;
    ::android::hardware::radio::V1_2::AccessNetwork accessNetwork;

    _hidl_err = _hidl_data.readInt32(&serial);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&hysteresisMs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&hysteresisDb);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_thresholdsDbm_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*thresholdsDbm), &_hidl_thresholdsDbm_parent,  reinterpret_cast<const void **>(&thresholdsDbm));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_thresholdsDbm_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int32_t> &>(*thresholdsDbm),
            _hidl_data,
            _hidl_thresholdsDbm_parent,
            0 /* parentOffset */, &_hidl_thresholdsDbm_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&accessNetwork);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setSignalStrengthReportingCriteria::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&hysteresisMs);
        _hidl_args.push_back((void *)&hysteresisDb);
        _hidl_args.push_back((void *)thresholdsDbm);
        _hidl_args.push_back((void *)&accessNetwork);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.2", "IRadio", "setSignalStrengthReportingCriteria", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setSignalStrengthReportingCriteria(serial, hysteresisMs, hysteresisDb, *thresholdsDbm, accessNetwork);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.2", "IRadio", "setSignalStrengthReportingCriteria", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setLinkCapacityReportingCriteria(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadio::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t serial;
    int32_t hysteresisMs;
    int32_t hysteresisDlKbps;
    int32_t hysteresisUlKbps;
    const ::android::hardware::hidl_vec<int32_t>* thresholdsDownlinkKbps;
    const ::android::hardware::hidl_vec<int32_t>* thresholdsUplinkKbps;
    ::android::hardware::radio::V1_2::AccessNetwork accessNetwork;

    _hidl_err = _hidl_data.readInt32(&serial);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&hysteresisMs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&hysteresisDlKbps);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&hysteresisUlKbps);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_thresholdsDownlinkKbps_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*thresholdsDownlinkKbps), &_hidl_thresholdsDownlinkKbps_parent,  reinterpret_cast<const void **>(&thresholdsDownlinkKbps));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_thresholdsDownlinkKbps_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int32_t> &>(*thresholdsDownlinkKbps),
            _hidl_data,
            _hidl_thresholdsDownlinkKbps_parent,
            0 /* parentOffset */, &_hidl_thresholdsDownlinkKbps_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_thresholdsUplinkKbps_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*thresholdsUplinkKbps), &_hidl_thresholdsUplinkKbps_parent,  reinterpret_cast<const void **>(&thresholdsUplinkKbps));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_thresholdsUplinkKbps_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int32_t> &>(*thresholdsUplinkKbps),
            _hidl_data,
            _hidl_thresholdsUplinkKbps_parent,
            0 /* parentOffset */, &_hidl_thresholdsUplinkKbps_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&accessNetwork);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setLinkCapacityReportingCriteria::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&hysteresisMs);
        _hidl_args.push_back((void *)&hysteresisDlKbps);
        _hidl_args.push_back((void *)&hysteresisUlKbps);
        _hidl_args.push_back((void *)thresholdsDownlinkKbps);
        _hidl_args.push_back((void *)thresholdsUplinkKbps);
        _hidl_args.push_back((void *)&accessNetwork);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.2", "IRadio", "setLinkCapacityReportingCriteria", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setLinkCapacityReportingCriteria(serial, hysteresisMs, hysteresisDlKbps, hysteresisUlKbps, *thresholdsDownlinkKbps, *thresholdsUplinkKbps, accessNetwork);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.2", "IRadio", "setLinkCapacityReportingCriteria", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setupDataCall_1_2(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadio::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t serial;
    ::android::hardware::radio::V1_2::AccessNetwork accessNetwork;
    ::android::hardware::radio::V1_0::DataProfileInfo* dataProfileInfo;
    bool modemCognitive;
    bool roamingAllowed;
    bool isRoaming;
    ::android::hardware::radio::V1_2::DataRequestReason reason;
    const ::android::hardware::hidl_vec<::android::hardware::hidl_string>* addresses;
    const ::android::hardware::hidl_vec<::android::hardware::hidl_string>* dnses;

    _hidl_err = _hidl_data.readInt32(&serial);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&accessNetwork);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dataProfileInfo_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dataProfileInfo), &_hidl_dataProfileInfo_parent,  const_cast<const void**>(reinterpret_cast<void **>(&dataProfileInfo)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::DataProfileInfo &>(*dataProfileInfo),
            _hidl_data,
            _hidl_dataProfileInfo_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&modemCognitive);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&roamingAllowed);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&isRoaming);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&reason);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_addresses_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*addresses), &_hidl_addresses_parent,  reinterpret_cast<const void **>(&addresses));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_addresses_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(*addresses),
            _hidl_data,
            _hidl_addresses_parent,
            0 /* parentOffset */, &_hidl_addresses_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < addresses->size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>((*addresses)[_hidl_index_0]),
                _hidl_data,
                _hidl_addresses_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_dnses_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dnses), &_hidl_dnses_parent,  reinterpret_cast<const void **>(&dnses));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dnses_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(*dnses),
            _hidl_data,
            _hidl_dnses_parent,
            0 /* parentOffset */, &_hidl_dnses_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < dnses->size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>((*dnses)[_hidl_index_0]),
                _hidl_data,
                _hidl_dnses_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setupDataCall_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&accessNetwork);
        _hidl_args.push_back((void *)dataProfileInfo);
        _hidl_args.push_back((void *)&modemCognitive);
        _hidl_args.push_back((void *)&roamingAllowed);
        _hidl_args.push_back((void *)&isRoaming);
        _hidl_args.push_back((void *)&reason);
        _hidl_args.push_back((void *)addresses);
        _hidl_args.push_back((void *)dnses);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.2", "IRadio", "setupDataCall_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setupDataCall_1_2(serial, accessNetwork, *dataProfileInfo, modemCognitive, roamingAllowed, isRoaming, reason, *addresses, *dnses);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.2", "IRadio", "setupDataCall_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_deactivateDataCall_1_2(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadio::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t serial;
    int32_t cid;
    ::android::hardware::radio::V1_2::DataRequestReason reason;

    _hidl_err = _hidl_data.readInt32(&serial);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&cid);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&reason);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::deactivateDataCall_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&cid);
        _hidl_args.push_back((void *)&reason);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio", "1.2", "IRadio", "deactivateDataCall_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->deactivateDataCall_1_2(serial, cid, reason);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio", "1.2", "IRadio", "deactivateDataCall_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::radio::V1_0::IRadio follow.

// Methods from ::android::hardware::radio::V1_1::IRadio follow.

// Methods from ::android::hardware::radio::V1_2::IRadio follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwRadio::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwRadio::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwRadio::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* setResponseFunctions */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setResponseFunctions(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getIccCardStatus */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getIccCardStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* supplyIccPinForApp */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_supplyIccPinForApp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* supplyIccPukForApp */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_supplyIccPukForApp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* supplyIccPin2ForApp */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_supplyIccPin2ForApp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* supplyIccPuk2ForApp */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_supplyIccPuk2ForApp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* changeIccPinForApp */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_changeIccPinForApp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* changeIccPin2ForApp */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_changeIccPin2ForApp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* supplyNetworkDepersonalization */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_supplyNetworkDepersonalization(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* getCurrentCalls */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getCurrentCalls(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* dial */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_dial(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* getImsiForApp */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getImsiForApp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* hangup */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_hangup(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* hangupWaitingOrBackground */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_hangupWaitingOrBackground(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* hangupForegroundResumeBackground */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_hangupForegroundResumeBackground(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* switchWaitingOrHoldingAndActive */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_switchWaitingOrHoldingAndActive(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* conference */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_conference(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* rejectCall */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_rejectCall(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 19 /* getLastCallFailCause */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getLastCallFailCause(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 20 /* getSignalStrength */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getSignalStrength(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 21 /* getVoiceRegistrationState */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getVoiceRegistrationState(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 22 /* getDataRegistrationState */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getDataRegistrationState(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 23 /* getOperator */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getOperator(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 24 /* setRadioPower */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setRadioPower(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 25 /* sendDtmf */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_sendDtmf(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 26 /* sendSms */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_sendSms(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 27 /* sendSMSExpectMore */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_sendSMSExpectMore(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 28 /* setupDataCall */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setupDataCall(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 29 /* iccIOForApp */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_iccIOForApp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 30 /* sendUssd */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_sendUssd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 31 /* cancelPendingUssd */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_cancelPendingUssd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 32 /* getClir */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getClir(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 33 /* setClir */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setClir(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 34 /* getCallForwardStatus */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getCallForwardStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 35 /* setCallForward */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setCallForward(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 36 /* getCallWaiting */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getCallWaiting(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 37 /* setCallWaiting */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setCallWaiting(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 38 /* acknowledgeLastIncomingGsmSms */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_acknowledgeLastIncomingGsmSms(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 39 /* acceptCall */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_acceptCall(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 40 /* deactivateDataCall */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_deactivateDataCall(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 41 /* getFacilityLockForApp */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getFacilityLockForApp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 42 /* setFacilityLockForApp */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setFacilityLockForApp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 43 /* setBarringPassword */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setBarringPassword(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 44 /* getNetworkSelectionMode */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getNetworkSelectionMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 45 /* setNetworkSelectionModeAutomatic */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setNetworkSelectionModeAutomatic(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 46 /* setNetworkSelectionModeManual */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setNetworkSelectionModeManual(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 47 /* getAvailableNetworks */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getAvailableNetworks(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 48 /* startDtmf */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_startDtmf(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 49 /* stopDtmf */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_stopDtmf(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 50 /* getBasebandVersion */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getBasebandVersion(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 51 /* separateConnection */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_separateConnection(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 52 /* setMute */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setMute(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 53 /* getMute */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getMute(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 54 /* getClip */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getClip(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 55 /* getDataCallList */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getDataCallList(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 56 /* setSuppServiceNotifications */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setSuppServiceNotifications(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 57 /* writeSmsToSim */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_writeSmsToSim(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 58 /* deleteSmsOnSim */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_deleteSmsOnSim(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 59 /* setBandMode */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setBandMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 60 /* getAvailableBandModes */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getAvailableBandModes(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 61 /* sendEnvelope */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_sendEnvelope(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 62 /* sendTerminalResponseToSim */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_sendTerminalResponseToSim(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 63 /* handleStkCallSetupRequestFromSim */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_handleStkCallSetupRequestFromSim(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 64 /* explicitCallTransfer */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_explicitCallTransfer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 65 /* setPreferredNetworkType */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setPreferredNetworkType(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 66 /* getPreferredNetworkType */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getPreferredNetworkType(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 67 /* getNeighboringCids */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getNeighboringCids(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 68 /* setLocationUpdates */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setLocationUpdates(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 69 /* setCdmaSubscriptionSource */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setCdmaSubscriptionSource(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 70 /* setCdmaRoamingPreference */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setCdmaRoamingPreference(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 71 /* getCdmaRoamingPreference */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getCdmaRoamingPreference(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 72 /* setTTYMode */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setTTYMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 73 /* getTTYMode */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getTTYMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 74 /* setPreferredVoicePrivacy */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setPreferredVoicePrivacy(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 75 /* getPreferredVoicePrivacy */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getPreferredVoicePrivacy(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 76 /* sendCDMAFeatureCode */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_sendCDMAFeatureCode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 77 /* sendBurstDtmf */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_sendBurstDtmf(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 78 /* sendCdmaSms */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_sendCdmaSms(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 79 /* acknowledgeLastIncomingCdmaSms */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_acknowledgeLastIncomingCdmaSms(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 80 /* getGsmBroadcastConfig */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getGsmBroadcastConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 81 /* setGsmBroadcastConfig */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setGsmBroadcastConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 82 /* setGsmBroadcastActivation */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setGsmBroadcastActivation(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 83 /* getCdmaBroadcastConfig */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getCdmaBroadcastConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 84 /* setCdmaBroadcastConfig */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setCdmaBroadcastConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 85 /* setCdmaBroadcastActivation */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setCdmaBroadcastActivation(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 86 /* getCDMASubscription */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getCDMASubscription(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 87 /* writeSmsToRuim */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_writeSmsToRuim(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 88 /* deleteSmsOnRuim */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_deleteSmsOnRuim(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 89 /* getDeviceIdentity */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getDeviceIdentity(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 90 /* exitEmergencyCallbackMode */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_exitEmergencyCallbackMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 91 /* getSmscAddress */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getSmscAddress(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 92 /* setSmscAddress */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setSmscAddress(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 93 /* reportSmsMemoryStatus */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_reportSmsMemoryStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 94 /* reportStkServiceIsRunning */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_reportStkServiceIsRunning(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 95 /* getCdmaSubscriptionSource */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getCdmaSubscriptionSource(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 96 /* requestIsimAuthentication */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_requestIsimAuthentication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 97 /* acknowledgeIncomingGsmSmsWithPdu */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_acknowledgeIncomingGsmSmsWithPdu(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 98 /* sendEnvelopeWithStatus */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_sendEnvelopeWithStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 99 /* getVoiceRadioTechnology */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getVoiceRadioTechnology(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 100 /* getCellInfoList */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getCellInfoList(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 101 /* setCellInfoListRate */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setCellInfoListRate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 102 /* setInitialAttachApn */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setInitialAttachApn(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 103 /* getImsRegistrationState */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getImsRegistrationState(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 104 /* sendImsSms */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_sendImsSms(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 105 /* iccTransmitApduBasicChannel */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_iccTransmitApduBasicChannel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 106 /* iccOpenLogicalChannel */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_iccOpenLogicalChannel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 107 /* iccCloseLogicalChannel */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_iccCloseLogicalChannel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 108 /* iccTransmitApduLogicalChannel */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_iccTransmitApduLogicalChannel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 109 /* nvReadItem */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_nvReadItem(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 110 /* nvWriteItem */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_nvWriteItem(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 111 /* nvWriteCdmaPrl */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_nvWriteCdmaPrl(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 112 /* nvResetConfig */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_nvResetConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 113 /* setUiccSubscription */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setUiccSubscription(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 114 /* setDataAllowed */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setDataAllowed(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 115 /* getHardwareConfig */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getHardwareConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 116 /* requestIccSimAuthentication */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_requestIccSimAuthentication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 117 /* setDataProfile */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setDataProfile(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 118 /* requestShutdown */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_requestShutdown(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 119 /* getRadioCapability */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getRadioCapability(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 120 /* setRadioCapability */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setRadioCapability(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 121 /* startLceService */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_startLceService(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 122 /* stopLceService */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_stopLceService(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 123 /* pullLceData */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_pullLceData(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 124 /* getModemActivityInfo */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getModemActivityInfo(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 125 /* setAllowedCarriers */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setAllowedCarriers(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 126 /* getAllowedCarriers */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_getAllowedCarriers(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 127 /* sendDeviceState */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_sendDeviceState(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 128 /* setIndicationFilter */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setIndicationFilter(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 129 /* setSimCardPower */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_setSimCardPower(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 130 /* responseAcknowledgement */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadio::_hidl_responseAcknowledgement(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 131 /* setCarrierInfoForImsiEncryption */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadio::_hidl_setCarrierInfoForImsiEncryption(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 132 /* setSimCardPower_1_1 */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadio::_hidl_setSimCardPower_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 133 /* startNetworkScan */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadio::_hidl_startNetworkScan(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 134 /* stopNetworkScan */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadio::_hidl_stopNetworkScan(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 135 /* startKeepalive */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadio::_hidl_startKeepalive(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 136 /* stopKeepalive */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadio::_hidl_stopKeepalive(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 137 /* startNetworkScan_1_2 */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadio::_hidl_startNetworkScan_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 138 /* setIndicationFilter_1_2 */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadio::_hidl_setIndicationFilter_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 139 /* setSignalStrengthReportingCriteria */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadio::_hidl_setSignalStrengthReportingCriteria(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 140 /* setLinkCapacityReportingCriteria */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadio::_hidl_setLinkCapacityReportingCriteria(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 141 /* setupDataCall_1_2 */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadio::_hidl_setupDataCall_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 142 /* deactivateDataCall_1_2 */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadio::_hidl_deactivateDataCall_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsRadio::BsRadio(const ::android::sp<::android::hardware::radio::V1_2::IRadio> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.radio@1.2", "IRadio"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsRadio::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IRadio> IRadio::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwRadio>(serviceName, false, getStub);
}

::android::sp<IRadio> IRadio::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwRadio>(serviceName, true, getStub);
}

::android::status_t IRadio::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IRadio::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.radio@1.2::IRadio",
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
