#define LOG_TAG "vendor.mediatek.hardware.radio@2.0::Radio"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <vendor/mediatek/hardware/radio/2.0/BpHwRadio.h>
#include <vendor/mediatek/hardware/radio/2.0/BnHwRadio.h>
#include <vendor/mediatek/hardware/radio/2.0/BsRadio.h>
#include <android/hardware/radio/1.1/BpHwRadio.h>
#include <android/hardware/radio/1.0/BpHwRadio.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace vendor {
namespace mediatek {
namespace hardware {
namespace radio {
namespace V2_0 {

const char* IRadio::descriptor("vendor.mediatek.hardware.radio@2.0::IRadio");

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

// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadio follow.
// no default implementation for: ::android::hardware::Return<void> IRadio::setResponseFunctionsMtk(const ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioResponse>& responseCb, const ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioIndication>& indicationCb)
// no default implementation for: ::android::hardware::Return<void> IRadio::setResponseFunctionsIms()
// no default implementation for: ::android::hardware::Return<void> IRadio::setTrm()
// no default implementation for: ::android::hardware::Return<void> IRadio::getATR()
// no default implementation for: ::android::hardware::Return<void> IRadio::setSimPower()
// no default implementation for: ::android::hardware::Return<void> IRadio::hangupAll()
// no default implementation for: ::android::hardware::Return<void> IRadio::setCallIndication(int32_t serial, int32_t mode, int32_t callId, int32_t seqNo)
// no default implementation for: ::android::hardware::Return<void> IRadio::emergencyDial()
// no default implementation for: ::android::hardware::Return<void> IRadio::setEccServiceCategory()
// no default implementation for: ::android::hardware::Return<void> IRadio::setEccList()
// no default implementation for: ::android::hardware::Return<void> IRadio::vtDial()
// no default implementation for: ::android::hardware::Return<void> IRadio::voiceAccept()
// no default implementation for: ::android::hardware::Return<void> IRadio::replaceVtCall()
// no default implementation for: ::android::hardware::Return<void> IRadio::currentStatus()
// no default implementation for: ::android::hardware::Return<void> IRadio::eccPreferredRat()
// no default implementation for: ::android::hardware::Return<void> IRadio::videoCallAccept()
// no default implementation for: ::android::hardware::Return<void> IRadio::imsEctCommand()
// no default implementation for: ::android::hardware::Return<void> IRadio::holdCall()
// no default implementation for: ::android::hardware::Return<void> IRadio::resumeCall()
// no default implementation for: ::android::hardware::Return<void> IRadio::imsDeregNotification()
// no default implementation for: ::android::hardware::Return<void> IRadio::setImsEnable()
// no default implementation for: ::android::hardware::Return<void> IRadio::setVolteEnable()
// no default implementation for: ::android::hardware::Return<void> IRadio::setWfcEnable()
// no default implementation for: ::android::hardware::Return<void> IRadio::setVilteEnable()
// no default implementation for: ::android::hardware::Return<void> IRadio::setViWifiEnable()
// no default implementation for: ::android::hardware::Return<void> IRadio::setImsVoiceEnable()
// no default implementation for: ::android::hardware::Return<void> IRadio::setImsVideoEnable()
// no default implementation for: ::android::hardware::Return<void> IRadio::setImsCfg()
// no default implementation for: ::android::hardware::Return<void> IRadio::getProvisionValue()
// no default implementation for: ::android::hardware::Return<void> IRadio::setProvisionValue()
// no default implementation for: ::android::hardware::Return<void> IRadio::addImsConferenceCallNumber()
// no default implementation for: ::android::hardware::Return<void> IRadio::removeImsConferenceCallNumber()
// no default implementation for: ::android::hardware::Return<void> IRadio::setWfcProfile()
// no default implementation for: ::android::hardware::Return<void> IRadio::conferenceDial()
// no default implementation for: ::android::hardware::Return<void> IRadio::vtDialWithSipUri()
// no default implementation for: ::android::hardware::Return<void> IRadio::dialWithSipUri()
// no default implementation for: ::android::hardware::Return<void> IRadio::sendUssi()
// no default implementation for: ::android::hardware::Return<void> IRadio::cancelUssi()
// no default implementation for: ::android::hardware::Return<void> IRadio::forceReleaseCall()
// no default implementation for: ::android::hardware::Return<void> IRadio::imsBearerActivationDone()
// no default implementation for: ::android::hardware::Return<void> IRadio::imsBearerDeactivationDone()
// no default implementation for: ::android::hardware::Return<void> IRadio::setImsRtpReport()
// no default implementation for: ::android::hardware::Return<void> IRadio::pullCall()
// no default implementation for: ::android::hardware::Return<void> IRadio::setImsRegistrationReport()
// no default implementation for: ::android::hardware::Return<void> IRadio::setResponseFunctionsForAtci()
// no default implementation for: ::android::hardware::Return<void> IRadio::sendAtciRequest()
// no default implementation for: ::android::hardware::Return<void> IRadio::setModemPower()
// no default implementation for: ::android::hardware::Return<void> IRadio::setNetworkSelectionModeManualWithAct()
// no default implementation for: ::android::hardware::Return<void> IRadio::getAvailableNetworksWithAct()
// no default implementation for: ::android::hardware::Return<void> IRadio::cancelAvailableNetworks()
// no default implementation for: ::android::hardware::Return<void> IRadio::getSmsParameters()
// no default implementation for: ::android::hardware::Return<void> IRadio::setSmsParameters()
// no default implementation for: ::android::hardware::Return<void> IRadio::getSmsMemStatus()
// no default implementation for: ::android::hardware::Return<void> IRadio::setEtws()
// no default implementation for: ::android::hardware::Return<void> IRadio::removeCbMsg()
// no default implementation for: ::android::hardware::Return<void> IRadio::setGsmBroadcastLangs()
// no default implementation for: ::android::hardware::Return<void> IRadio::getGsmBroadcastLangs()
// no default implementation for: ::android::hardware::Return<void> IRadio::getGsmBroadcastActivation()
// no default implementation for: ::android::hardware::Return<void> IRadio::sendEmbmsAtCommand()
// no default implementation for: ::android::hardware::Return<void> IRadio::setApcMode()
// no default implementation for: ::android::hardware::Return<void> IRadio::getApcInfo()
// no default implementation for: ::android::hardware::Return<void> IRadio::triggerModeSwitchByEcc()
// no default implementation for: ::android::hardware::Return<void> IRadio::getSmsRuimMemoryStatus()
// no default implementation for: ::android::hardware::Return<void> IRadio::setFdMode()
// no default implementation for: ::android::hardware::Return<void> IRadio::setResumeRegistration()
// no default implementation for: ::android::hardware::Return<void> IRadio::storeModemType()
// no default implementation for: ::android::hardware::Return<void> IRadio::reloadModemType()
// no default implementation for: ::android::hardware::Return<void> IRadio::setInitialAttachApnEx()
// no default implementation for: ::android::hardware::Return<void> IRadio::handleStkCallSetupRequestFromSimWithResCode()
// no default implementation for: ::android::hardware::Return<void> IRadio::getFemtocellList()
// no default implementation for: ::android::hardware::Return<void> IRadio::abortFemtocellList()
// no default implementation for: ::android::hardware::Return<void> IRadio::selectFemtocell()
// no default implementation for: ::android::hardware::Return<void> IRadio::queryFemtoCellSystemSelectionMode()
// no default implementation for: ::android::hardware::Return<void> IRadio::setFemtoCellSystemSelectionMode()
// no default implementation for: ::android::hardware::Return<void> IRadio::setBarringPasswordCheckedByNW()
// no default implementation for: ::android::hardware::Return<void> IRadio::setClip()
// no default implementation for: ::android::hardware::Return<void> IRadio::getColp()
// no default implementation for: ::android::hardware::Return<void> IRadio::getColr()
// no default implementation for: ::android::hardware::Return<void> IRadio::sendCnap()
// no default implementation for: ::android::hardware::Return<void> IRadio::setColp()
// no default implementation for: ::android::hardware::Return<void> IRadio::setColr()
// no default implementation for: ::android::hardware::Return<void> IRadio::queryCallForwardInTimeSlotStatus()
// no default implementation for: ::android::hardware::Return<void> IRadio::setCallForwardInTimeSlot()
// no default implementation for: ::android::hardware::Return<void> IRadio::runGbaAuthentication()
// no default implementation for: ::android::hardware::Return<void> IRadio::queryPhbStorageInfo()
// no default implementation for: ::android::hardware::Return<void> IRadio::writePhbEntry()
// no default implementation for: ::android::hardware::Return<void> IRadio::readPhbEntry()
// no default implementation for: ::android::hardware::Return<void> IRadio::queryUPBCapability()
// no default implementation for: ::android::hardware::Return<void> IRadio::editUPBEntry()
// no default implementation for: ::android::hardware::Return<void> IRadio::deleteUPBEntry()
// no default implementation for: ::android::hardware::Return<void> IRadio::readUPBGasList()
// no default implementation for: ::android::hardware::Return<void> IRadio::readUPBGrpEntry()
// no default implementation for: ::android::hardware::Return<void> IRadio::writeUPBGrpEntry()
// no default implementation for: ::android::hardware::Return<void> IRadio::getPhoneBookStringsLength()
// no default implementation for: ::android::hardware::Return<void> IRadio::getPhoneBookMemStorage()
// no default implementation for: ::android::hardware::Return<void> IRadio::setPhoneBookMemStorage()
// no default implementation for: ::android::hardware::Return<void> IRadio::readPhoneBookEntryExt()
// no default implementation for: ::android::hardware::Return<void> IRadio::writePhoneBookEntryExt()
// no default implementation for: ::android::hardware::Return<void> IRadio::queryUPBAvailable()
// no default implementation for: ::android::hardware::Return<void> IRadio::readUPBEmailEntry()
// no default implementation for: ::android::hardware::Return<void> IRadio::readUPBSneEntry()
// no default implementation for: ::android::hardware::Return<void> IRadio::readUPBAnrEntry()
// no default implementation for: ::android::hardware::Return<void> IRadio::readUPBAasList()
// no default implementation for: ::android::hardware::Return<void> IRadio::doGeneralSimAuthentication()
// no default implementation for: ::android::hardware::Return<void> IRadio::queryNetworkLock()
// no default implementation for: ::android::hardware::Return<void> IRadio::setNetworkLock()
// no default implementation for: ::android::hardware::Return<void> IRadio::resetRadio()
// no default implementation for: ::android::hardware::Return<void> IRadio::syncDataSettingsToMd(int32_t serial, const ::android::hardware::hidl_vec<int32_t>& dataSettings)
// no default implementation for: ::android::hardware::Return<void> IRadio::resetMdDataRetryCount(int32_t serial, const ::android::hardware::hidl_string& apn)
// no default implementation for: ::android::hardware::Return<void> IRadio::setRemoveRestrictEutranMode()
// no default implementation for: ::android::hardware::Return<void> IRadio::setLteAccessStratumReport()
// no default implementation for: ::android::hardware::Return<void> IRadio::setLteUplinkDataTransfer()
// no default implementation for: ::android::hardware::Return<void> IRadio::setRxTestConfig()
// no default implementation for: ::android::hardware::Return<void> IRadio::getRxTestResult()
// no default implementation for: ::android::hardware::Return<void> IRadio::getPOLCapability()
// no default implementation for: ::android::hardware::Return<void> IRadio::getCurrentPOLList()
// no default implementation for: ::android::hardware::Return<void> IRadio::setPOLEntry()
// no default implementation for: ::android::hardware::Return<void> IRadio::setRoamingEnable()
// no default implementation for: ::android::hardware::Return<void> IRadio::getRoamingEnable()
// no default implementation for: ::android::hardware::Return<void> IRadio::setDataProfileEx()
// no default implementation for: ::android::hardware::Return<void> IRadio::sendVsimNotification()
// no default implementation for: ::android::hardware::Return<void> IRadio::sendVsimOperation()
// no default implementation for: ::android::hardware::Return<void> IRadio::setVoiceDomainPreference()
// no default implementation for: ::android::hardware::Return<void> IRadio::setModemImsCfg()
// no default implementation for: ::android::hardware::Return<void> IRadio::setWifiEnable()
// no default implementation for: ::android::hardware::Return<void> IRadio::setWifiAssociated()
// no default implementation for: ::android::hardware::Return<void> IRadio::setWifiSignalLevel()
// no default implementation for: ::android::hardware::Return<void> IRadio::setWifiIpAddress()
// no default implementation for: ::android::hardware::Return<void> IRadio::setLocationInfo()
// no default implementation for: ::android::hardware::Return<void> IRadio::setEmergencyAddressId()
// no default implementation for: ::android::hardware::Return<void> IRadio::setE911State()
// no default implementation for: ::android::hardware::Return<void> IRadio::setServiceStateToModem(int32_t serial, int32_t voiceRegState, int32_t dataRegState, int32_t voiceRoamingType, int32_t dataRoamingType, int32_t rilVoiceRegState, int32_t rilDataRegState)
// no default implementation for: ::android::hardware::Return<void> IRadio::sendRequestRaw()
// no default implementation for: ::android::hardware::Return<void> IRadio::sendRequestStrings()
// no default implementation for: ::android::hardware::Return<void> IRadio::setNattKeepAliveStatus()

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IRadio::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::vendor::mediatek::hardware::radio::V2_0::IRadio::descriptor,
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
    _hidl_cb(::vendor::mediatek::hardware::radio::V2_0::IRadio::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadio::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} /* 0000000000000000000000000000000000000000000000000000000000000000 */,
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


::android::hardware::Return<::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadio>> IRadio::castFrom(const ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadio>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadio>> IRadio::castFrom(const ::android::sp<::android::hardware::radio::V1_1::IRadio>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadio, ::android::hardware::radio::V1_1::IRadio, BpHwRadio>(
            parent, "vendor.mediatek.hardware.radio@2.0::IRadio", emitError);
}

::android::hardware::Return<::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadio>> IRadio::castFrom(const ::android::sp<::android::hardware::radio::V1_0::IRadio>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadio, ::android::hardware::radio::V1_0::IRadio, BpHwRadio>(
            parent, "vendor.mediatek.hardware.radio@2.0::IRadio", emitError);
}

::android::hardware::Return<::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadio>> IRadio::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadio, ::android::hidl::base::V1_0::IBase, BpHwRadio>(
            parent, "vendor.mediatek.hardware.radio@2.0::IRadio", emitError);
}

BpHwRadio::BpHwRadio(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IRadio>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("vendor.mediatek.hardware.radio@2.0", "IRadio") {
}

void BpHwRadio::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IRadio>::onLastStrongRef(id);
}
// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadio follow.
::android::hardware::Return<void> BpHwRadio::_hidl_setResponseFunctionsMtk(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioResponse>& responseCb, const ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioIndication>& indicationCb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setResponseFunctionsMtk::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&responseCb);
        _hidl_args.push_back((void *)&indicationCb);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResponseFunctionsMtk", &_hidl_args);
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

    if (responseCb == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(responseCb.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (indicationCb == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(indicationCb.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(137 /* setResponseFunctionsMtk */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResponseFunctionsMtk", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setResponseFunctionsIms(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setResponseFunctionsIms::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResponseFunctionsIms", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(138 /* setResponseFunctionsIms */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResponseFunctionsIms", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setTrm(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setTrm::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setTrm", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(139 /* setTrm */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setTrm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getATR(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getATR::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getATR", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(140 /* getATR */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getATR", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setSimPower(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setSimPower::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setSimPower", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(141 /* setSimPower */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setSimPower", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_hangupAll(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::hangupAll::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "hangupAll", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(142 /* hangupAll */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "hangupAll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setCallIndication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t serial, int32_t mode, int32_t callId, int32_t seqNo) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setCallIndication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&mode);
        _hidl_args.push_back((void *)&callId);
        _hidl_args.push_back((void *)&seqNo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setCallIndication", &_hidl_args);
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

    _hidl_err = _hidl_data.writeInt32(mode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(callId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(seqNo);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(143 /* setCallIndication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setCallIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_emergencyDial(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::emergencyDial::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "emergencyDial", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(144 /* emergencyDial */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "emergencyDial", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setEccServiceCategory(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setEccServiceCategory::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEccServiceCategory", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(145 /* setEccServiceCategory */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEccServiceCategory", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setEccList(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setEccList::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEccList", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(146 /* setEccList */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEccList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_vtDial(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::vtDial::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "vtDial", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(147 /* vtDial */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "vtDial", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_voiceAccept(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::voiceAccept::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "voiceAccept", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(148 /* voiceAccept */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "voiceAccept", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_replaceVtCall(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::replaceVtCall::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "replaceVtCall", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(149 /* replaceVtCall */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "replaceVtCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_currentStatus(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::currentStatus::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "currentStatus", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(150 /* currentStatus */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "currentStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_eccPreferredRat(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::eccPreferredRat::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "eccPreferredRat", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(151 /* eccPreferredRat */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "eccPreferredRat", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_videoCallAccept(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::videoCallAccept::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "videoCallAccept", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(152 /* videoCallAccept */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "videoCallAccept", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_imsEctCommand(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::imsEctCommand::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsEctCommand", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(153 /* imsEctCommand */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsEctCommand", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_holdCall(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::holdCall::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "holdCall", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(154 /* holdCall */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "holdCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_resumeCall(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::resumeCall::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "resumeCall", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(155 /* resumeCall */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "resumeCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_imsDeregNotification(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::imsDeregNotification::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsDeregNotification", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(156 /* imsDeregNotification */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsDeregNotification", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setImsEnable(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setImsEnable::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsEnable", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(157 /* setImsEnable */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setVolteEnable(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setVolteEnable::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setVolteEnable", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(158 /* setVolteEnable */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setVolteEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setWfcEnable(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setWfcEnable::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWfcEnable", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(159 /* setWfcEnable */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWfcEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setVilteEnable(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setVilteEnable::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setVilteEnable", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(160 /* setVilteEnable */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setVilteEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setViWifiEnable(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setViWifiEnable::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setViWifiEnable", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(161 /* setViWifiEnable */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setViWifiEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setImsVoiceEnable(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setImsVoiceEnable::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsVoiceEnable", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(162 /* setImsVoiceEnable */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsVoiceEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setImsVideoEnable(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setImsVideoEnable::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsVideoEnable", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(163 /* setImsVideoEnable */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsVideoEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setImsCfg(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setImsCfg::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsCfg", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(164 /* setImsCfg */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsCfg", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getProvisionValue(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getProvisionValue::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getProvisionValue", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(165 /* getProvisionValue */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getProvisionValue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setProvisionValue(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setProvisionValue::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setProvisionValue", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(166 /* setProvisionValue */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setProvisionValue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_addImsConferenceCallNumber(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::addImsConferenceCallNumber::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "addImsConferenceCallNumber", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(167 /* addImsConferenceCallNumber */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "addImsConferenceCallNumber", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_removeImsConferenceCallNumber(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::removeImsConferenceCallNumber::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "removeImsConferenceCallNumber", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(168 /* removeImsConferenceCallNumber */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "removeImsConferenceCallNumber", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setWfcProfile(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setWfcProfile::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWfcProfile", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(169 /* setWfcProfile */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWfcProfile", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_conferenceDial(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::conferenceDial::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "conferenceDial", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(170 /* conferenceDial */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "conferenceDial", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_vtDialWithSipUri(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::vtDialWithSipUri::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "vtDialWithSipUri", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(171 /* vtDialWithSipUri */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "vtDialWithSipUri", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_dialWithSipUri(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::dialWithSipUri::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "dialWithSipUri", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(172 /* dialWithSipUri */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "dialWithSipUri", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_sendUssi(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::sendUssi::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendUssi", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(173 /* sendUssi */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendUssi", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_cancelUssi(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::cancelUssi::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "cancelUssi", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(174 /* cancelUssi */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "cancelUssi", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_forceReleaseCall(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::forceReleaseCall::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "forceReleaseCall", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(175 /* forceReleaseCall */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "forceReleaseCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_imsBearerActivationDone(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::imsBearerActivationDone::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsBearerActivationDone", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(176 /* imsBearerActivationDone */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsBearerActivationDone", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_imsBearerDeactivationDone(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::imsBearerDeactivationDone::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsBearerDeactivationDone", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(177 /* imsBearerDeactivationDone */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsBearerDeactivationDone", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setImsRtpReport(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setImsRtpReport::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsRtpReport", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(178 /* setImsRtpReport */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsRtpReport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_pullCall(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::pullCall::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "pullCall", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(179 /* pullCall */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "pullCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setImsRegistrationReport(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setImsRegistrationReport::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsRegistrationReport", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(180 /* setImsRegistrationReport */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsRegistrationReport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setResponseFunctionsForAtci(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setResponseFunctionsForAtci::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResponseFunctionsForAtci", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(181 /* setResponseFunctionsForAtci */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResponseFunctionsForAtci", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_sendAtciRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::sendAtciRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendAtciRequest", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(182 /* sendAtciRequest */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendAtciRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setModemPower(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setModemPower::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setModemPower", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(183 /* setModemPower */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setModemPower", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setNetworkSelectionModeManualWithAct(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setNetworkSelectionModeManualWithAct::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setNetworkSelectionModeManualWithAct", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(184 /* setNetworkSelectionModeManualWithAct */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setNetworkSelectionModeManualWithAct", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getAvailableNetworksWithAct(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getAvailableNetworksWithAct::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getAvailableNetworksWithAct", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(185 /* getAvailableNetworksWithAct */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getAvailableNetworksWithAct", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_cancelAvailableNetworks(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::cancelAvailableNetworks::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "cancelAvailableNetworks", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(186 /* cancelAvailableNetworks */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "cancelAvailableNetworks", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getSmsParameters(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getSmsParameters::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getSmsParameters", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(187 /* getSmsParameters */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getSmsParameters", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setSmsParameters(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setSmsParameters::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setSmsParameters", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(188 /* setSmsParameters */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setSmsParameters", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getSmsMemStatus(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getSmsMemStatus::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getSmsMemStatus", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(189 /* getSmsMemStatus */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getSmsMemStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setEtws(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setEtws::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEtws", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(190 /* setEtws */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEtws", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_removeCbMsg(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::removeCbMsg::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "removeCbMsg", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(191 /* removeCbMsg */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "removeCbMsg", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setGsmBroadcastLangs(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setGsmBroadcastLangs::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setGsmBroadcastLangs", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(192 /* setGsmBroadcastLangs */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setGsmBroadcastLangs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getGsmBroadcastLangs(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getGsmBroadcastLangs::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getGsmBroadcastLangs", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(193 /* getGsmBroadcastLangs */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getGsmBroadcastLangs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getGsmBroadcastActivation(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getGsmBroadcastActivation::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getGsmBroadcastActivation", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(194 /* getGsmBroadcastActivation */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getGsmBroadcastActivation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_sendEmbmsAtCommand(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::sendEmbmsAtCommand::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendEmbmsAtCommand", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(195 /* sendEmbmsAtCommand */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendEmbmsAtCommand", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setApcMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setApcMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setApcMode", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(196 /* setApcMode */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setApcMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getApcInfo(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getApcInfo::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getApcInfo", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(197 /* getApcInfo */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getApcInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_triggerModeSwitchByEcc(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::triggerModeSwitchByEcc::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "triggerModeSwitchByEcc", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(198 /* triggerModeSwitchByEcc */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "triggerModeSwitchByEcc", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getSmsRuimMemoryStatus(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getSmsRuimMemoryStatus::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getSmsRuimMemoryStatus", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(199 /* getSmsRuimMemoryStatus */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getSmsRuimMemoryStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setFdMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setFdMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setFdMode", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(200 /* setFdMode */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setFdMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setResumeRegistration(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setResumeRegistration::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResumeRegistration", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(201 /* setResumeRegistration */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResumeRegistration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_storeModemType(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::storeModemType::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "storeModemType", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(202 /* storeModemType */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "storeModemType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_reloadModemType(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::reloadModemType::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "reloadModemType", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(203 /* reloadModemType */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "reloadModemType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setInitialAttachApnEx(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setInitialAttachApnEx::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setInitialAttachApnEx", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(204 /* setInitialAttachApnEx */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setInitialAttachApnEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_handleStkCallSetupRequestFromSimWithResCode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::handleStkCallSetupRequestFromSimWithResCode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "handleStkCallSetupRequestFromSimWithResCode", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(205 /* handleStkCallSetupRequestFromSimWithResCode */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "handleStkCallSetupRequestFromSimWithResCode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getFemtocellList(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getFemtocellList::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getFemtocellList", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(206 /* getFemtocellList */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getFemtocellList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_abortFemtocellList(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::abortFemtocellList::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "abortFemtocellList", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(207 /* abortFemtocellList */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "abortFemtocellList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_selectFemtocell(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::selectFemtocell::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "selectFemtocell", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(208 /* selectFemtocell */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "selectFemtocell", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_queryFemtoCellSystemSelectionMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::queryFemtoCellSystemSelectionMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryFemtoCellSystemSelectionMode", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(209 /* queryFemtoCellSystemSelectionMode */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryFemtoCellSystemSelectionMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setFemtoCellSystemSelectionMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setFemtoCellSystemSelectionMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setFemtoCellSystemSelectionMode", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(210 /* setFemtoCellSystemSelectionMode */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setFemtoCellSystemSelectionMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setBarringPasswordCheckedByNW(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setBarringPasswordCheckedByNW::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setBarringPasswordCheckedByNW", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(211 /* setBarringPasswordCheckedByNW */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setBarringPasswordCheckedByNW", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setClip(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setClip::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setClip", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(212 /* setClip */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setClip", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getColp(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getColp::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getColp", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(213 /* getColp */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getColp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getColr(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getColr::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getColr", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(214 /* getColr */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getColr", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_sendCnap(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::sendCnap::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendCnap", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(215 /* sendCnap */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendCnap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setColp(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setColp::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setColp", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(216 /* setColp */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setColp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setColr(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setColr::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setColr", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(217 /* setColr */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setColr", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_queryCallForwardInTimeSlotStatus(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::queryCallForwardInTimeSlotStatus::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryCallForwardInTimeSlotStatus", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(218 /* queryCallForwardInTimeSlotStatus */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryCallForwardInTimeSlotStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setCallForwardInTimeSlot(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setCallForwardInTimeSlot::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setCallForwardInTimeSlot", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(219 /* setCallForwardInTimeSlot */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setCallForwardInTimeSlot", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_runGbaAuthentication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::runGbaAuthentication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "runGbaAuthentication", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(220 /* runGbaAuthentication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "runGbaAuthentication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_queryPhbStorageInfo(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::queryPhbStorageInfo::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryPhbStorageInfo", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(221 /* queryPhbStorageInfo */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryPhbStorageInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_writePhbEntry(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::writePhbEntry::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "writePhbEntry", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(222 /* writePhbEntry */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "writePhbEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_readPhbEntry(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::readPhbEntry::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readPhbEntry", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(223 /* readPhbEntry */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readPhbEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_queryUPBCapability(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::queryUPBCapability::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryUPBCapability", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(224 /* queryUPBCapability */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryUPBCapability", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_editUPBEntry(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::editUPBEntry::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "editUPBEntry", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(225 /* editUPBEntry */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "editUPBEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_deleteUPBEntry(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::deleteUPBEntry::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "deleteUPBEntry", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(226 /* deleteUPBEntry */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "deleteUPBEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_readUPBGasList(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::readUPBGasList::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBGasList", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(227 /* readUPBGasList */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBGasList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_readUPBGrpEntry(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::readUPBGrpEntry::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBGrpEntry", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(228 /* readUPBGrpEntry */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBGrpEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_writeUPBGrpEntry(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::writeUPBGrpEntry::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "writeUPBGrpEntry", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(229 /* writeUPBGrpEntry */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "writeUPBGrpEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getPhoneBookStringsLength(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getPhoneBookStringsLength::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getPhoneBookStringsLength", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(230 /* getPhoneBookStringsLength */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getPhoneBookStringsLength", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getPhoneBookMemStorage(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getPhoneBookMemStorage::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getPhoneBookMemStorage", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(231 /* getPhoneBookMemStorage */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getPhoneBookMemStorage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setPhoneBookMemStorage(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setPhoneBookMemStorage::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setPhoneBookMemStorage", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(232 /* setPhoneBookMemStorage */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setPhoneBookMemStorage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_readPhoneBookEntryExt(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::readPhoneBookEntryExt::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readPhoneBookEntryExt", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(233 /* readPhoneBookEntryExt */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readPhoneBookEntryExt", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_writePhoneBookEntryExt(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::writePhoneBookEntryExt::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "writePhoneBookEntryExt", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(234 /* writePhoneBookEntryExt */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "writePhoneBookEntryExt", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_queryUPBAvailable(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::queryUPBAvailable::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryUPBAvailable", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(235 /* queryUPBAvailable */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryUPBAvailable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_readUPBEmailEntry(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::readUPBEmailEntry::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBEmailEntry", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(236 /* readUPBEmailEntry */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBEmailEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_readUPBSneEntry(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::readUPBSneEntry::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBSneEntry", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(237 /* readUPBSneEntry */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBSneEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_readUPBAnrEntry(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::readUPBAnrEntry::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBAnrEntry", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(238 /* readUPBAnrEntry */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBAnrEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_readUPBAasList(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::readUPBAasList::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBAasList", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(239 /* readUPBAasList */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBAasList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_doGeneralSimAuthentication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::doGeneralSimAuthentication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "doGeneralSimAuthentication", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(240 /* doGeneralSimAuthentication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "doGeneralSimAuthentication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_queryNetworkLock(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::queryNetworkLock::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryNetworkLock", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(241 /* queryNetworkLock */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryNetworkLock", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setNetworkLock(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setNetworkLock::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setNetworkLock", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(242 /* setNetworkLock */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setNetworkLock", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_resetRadio(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::resetRadio::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "resetRadio", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(243 /* resetRadio */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "resetRadio", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_syncDataSettingsToMd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t serial, const ::android::hardware::hidl_vec<int32_t>& dataSettings) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::syncDataSettingsToMd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&dataSettings);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "syncDataSettingsToMd", &_hidl_args);
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

    size_t _hidl_dataSettings_parent;

    _hidl_err = _hidl_data.writeBuffer(&dataSettings, sizeof(dataSettings), &_hidl_dataSettings_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dataSettings_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            dataSettings,
            &_hidl_data,
            _hidl_dataSettings_parent,
            0 /* parentOffset */, &_hidl_dataSettings_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(244 /* syncDataSettingsToMd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "syncDataSettingsToMd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_resetMdDataRetryCount(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t serial, const ::android::hardware::hidl_string& apn) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::resetMdDataRetryCount::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&apn);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "resetMdDataRetryCount", &_hidl_args);
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

    size_t _hidl_apn_parent;

    _hidl_err = _hidl_data.writeBuffer(&apn, sizeof(apn), &_hidl_apn_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            apn,
            &_hidl_data,
            _hidl_apn_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(245 /* resetMdDataRetryCount */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "resetMdDataRetryCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setRemoveRestrictEutranMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setRemoveRestrictEutranMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setRemoveRestrictEutranMode", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(246 /* setRemoveRestrictEutranMode */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setRemoveRestrictEutranMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setLteAccessStratumReport(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setLteAccessStratumReport::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setLteAccessStratumReport", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(247 /* setLteAccessStratumReport */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setLteAccessStratumReport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setLteUplinkDataTransfer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setLteUplinkDataTransfer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setLteUplinkDataTransfer", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(248 /* setLteUplinkDataTransfer */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setLteUplinkDataTransfer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setRxTestConfig(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setRxTestConfig::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setRxTestConfig", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(249 /* setRxTestConfig */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setRxTestConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getRxTestResult(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getRxTestResult::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getRxTestResult", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(250 /* getRxTestResult */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getRxTestResult", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getPOLCapability(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getPOLCapability::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getPOLCapability", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(251 /* getPOLCapability */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getPOLCapability", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getCurrentPOLList(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getCurrentPOLList::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getCurrentPOLList", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(252 /* getCurrentPOLList */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getCurrentPOLList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setPOLEntry(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setPOLEntry::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setPOLEntry", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(253 /* setPOLEntry */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setPOLEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setRoamingEnable(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setRoamingEnable::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setRoamingEnable", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(254 /* setRoamingEnable */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setRoamingEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_getRoamingEnable(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::getRoamingEnable::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getRoamingEnable", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(255 /* getRoamingEnable */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getRoamingEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setDataProfileEx(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setDataProfileEx::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setDataProfileEx", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(256 /* setDataProfileEx */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setDataProfileEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_sendVsimNotification(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::sendVsimNotification::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendVsimNotification", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(257 /* sendVsimNotification */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendVsimNotification", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_sendVsimOperation(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::sendVsimOperation::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendVsimOperation", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(258 /* sendVsimOperation */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendVsimOperation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setVoiceDomainPreference(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setVoiceDomainPreference::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setVoiceDomainPreference", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(259 /* setVoiceDomainPreference */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setVoiceDomainPreference", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setModemImsCfg(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setModemImsCfg::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setModemImsCfg", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(260 /* setModemImsCfg */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setModemImsCfg", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setWifiEnable(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setWifiEnable::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiEnable", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(261 /* setWifiEnable */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setWifiAssociated(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setWifiAssociated::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiAssociated", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(262 /* setWifiAssociated */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiAssociated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setWifiSignalLevel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setWifiSignalLevel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiSignalLevel", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(263 /* setWifiSignalLevel */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiSignalLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setWifiIpAddress(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setWifiIpAddress::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiIpAddress", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(264 /* setWifiIpAddress */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiIpAddress", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setLocationInfo(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setLocationInfo::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setLocationInfo", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(265 /* setLocationInfo */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setLocationInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setEmergencyAddressId(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setEmergencyAddressId::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEmergencyAddressId", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(266 /* setEmergencyAddressId */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEmergencyAddressId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setE911State(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setE911State::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setE911State", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(267 /* setE911State */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setE911State", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setServiceStateToModem(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t serial, int32_t voiceRegState, int32_t dataRegState, int32_t voiceRoamingType, int32_t dataRoamingType, int32_t rilVoiceRegState, int32_t rilDataRegState) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setServiceStateToModem::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&voiceRegState);
        _hidl_args.push_back((void *)&dataRegState);
        _hidl_args.push_back((void *)&voiceRoamingType);
        _hidl_args.push_back((void *)&dataRoamingType);
        _hidl_args.push_back((void *)&rilVoiceRegState);
        _hidl_args.push_back((void *)&rilDataRegState);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setServiceStateToModem", &_hidl_args);
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

    _hidl_err = _hidl_data.writeInt32(voiceRegState);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(dataRegState);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(voiceRoamingType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(dataRoamingType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(rilVoiceRegState);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(rilDataRegState);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(268 /* setServiceStateToModem */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setServiceStateToModem", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_sendRequestRaw(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::sendRequestRaw::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendRequestRaw", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(269 /* sendRequestRaw */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendRequestRaw", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_sendRequestStrings(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::sendRequestStrings::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendRequestStrings", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(270 /* sendRequestStrings */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendRequestStrings", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadio::_hidl_setNattKeepAliveStatus(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadio::setNattKeepAliveStatus::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setNattKeepAliveStatus", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(271 /* setNattKeepAliveStatus */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setNattKeepAliveStatus", &_hidl_args);
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


// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadio follow.
::android::hardware::Return<void> BpHwRadio::setResponseFunctionsMtk(const ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioResponse>& responseCb, const ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioIndication>& indicationCb){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setResponseFunctionsMtk(this, this, responseCb, indicationCb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setResponseFunctionsIms(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setResponseFunctionsIms(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setTrm(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setTrm(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getATR(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getATR(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setSimPower(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setSimPower(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::hangupAll(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_hangupAll(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setCallIndication(int32_t serial, int32_t mode, int32_t callId, int32_t seqNo){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setCallIndication(this, this, serial, mode, callId, seqNo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::emergencyDial(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_emergencyDial(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setEccServiceCategory(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setEccServiceCategory(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setEccList(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setEccList(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::vtDial(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_vtDial(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::voiceAccept(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_voiceAccept(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::replaceVtCall(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_replaceVtCall(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::currentStatus(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_currentStatus(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::eccPreferredRat(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_eccPreferredRat(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::videoCallAccept(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_videoCallAccept(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::imsEctCommand(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_imsEctCommand(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::holdCall(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_holdCall(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::resumeCall(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_resumeCall(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::imsDeregNotification(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_imsDeregNotification(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setImsEnable(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setImsEnable(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setVolteEnable(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setVolteEnable(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setWfcEnable(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setWfcEnable(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setVilteEnable(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setVilteEnable(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setViWifiEnable(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setViWifiEnable(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setImsVoiceEnable(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setImsVoiceEnable(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setImsVideoEnable(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setImsVideoEnable(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setImsCfg(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setImsCfg(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getProvisionValue(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getProvisionValue(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setProvisionValue(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setProvisionValue(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::addImsConferenceCallNumber(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_addImsConferenceCallNumber(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::removeImsConferenceCallNumber(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_removeImsConferenceCallNumber(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setWfcProfile(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setWfcProfile(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::conferenceDial(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_conferenceDial(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::vtDialWithSipUri(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_vtDialWithSipUri(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::dialWithSipUri(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_dialWithSipUri(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendUssi(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_sendUssi(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::cancelUssi(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_cancelUssi(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::forceReleaseCall(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_forceReleaseCall(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::imsBearerActivationDone(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_imsBearerActivationDone(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::imsBearerDeactivationDone(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_imsBearerDeactivationDone(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setImsRtpReport(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setImsRtpReport(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::pullCall(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_pullCall(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setImsRegistrationReport(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setImsRegistrationReport(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setResponseFunctionsForAtci(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setResponseFunctionsForAtci(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendAtciRequest(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_sendAtciRequest(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setModemPower(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setModemPower(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setNetworkSelectionModeManualWithAct(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setNetworkSelectionModeManualWithAct(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getAvailableNetworksWithAct(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getAvailableNetworksWithAct(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::cancelAvailableNetworks(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_cancelAvailableNetworks(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getSmsParameters(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getSmsParameters(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setSmsParameters(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setSmsParameters(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getSmsMemStatus(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getSmsMemStatus(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setEtws(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setEtws(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::removeCbMsg(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_removeCbMsg(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setGsmBroadcastLangs(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setGsmBroadcastLangs(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getGsmBroadcastLangs(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getGsmBroadcastLangs(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getGsmBroadcastActivation(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getGsmBroadcastActivation(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendEmbmsAtCommand(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_sendEmbmsAtCommand(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setApcMode(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setApcMode(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getApcInfo(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getApcInfo(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::triggerModeSwitchByEcc(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_triggerModeSwitchByEcc(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getSmsRuimMemoryStatus(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getSmsRuimMemoryStatus(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setFdMode(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setFdMode(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setResumeRegistration(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setResumeRegistration(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::storeModemType(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_storeModemType(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::reloadModemType(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_reloadModemType(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setInitialAttachApnEx(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setInitialAttachApnEx(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::handleStkCallSetupRequestFromSimWithResCode(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_handleStkCallSetupRequestFromSimWithResCode(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getFemtocellList(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getFemtocellList(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::abortFemtocellList(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_abortFemtocellList(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::selectFemtocell(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_selectFemtocell(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::queryFemtoCellSystemSelectionMode(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_queryFemtoCellSystemSelectionMode(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setFemtoCellSystemSelectionMode(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setFemtoCellSystemSelectionMode(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setBarringPasswordCheckedByNW(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setBarringPasswordCheckedByNW(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setClip(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setClip(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getColp(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getColp(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getColr(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getColr(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendCnap(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_sendCnap(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setColp(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setColp(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setColr(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setColr(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::queryCallForwardInTimeSlotStatus(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_queryCallForwardInTimeSlotStatus(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setCallForwardInTimeSlot(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setCallForwardInTimeSlot(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::runGbaAuthentication(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_runGbaAuthentication(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::queryPhbStorageInfo(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_queryPhbStorageInfo(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::writePhbEntry(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_writePhbEntry(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::readPhbEntry(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_readPhbEntry(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::queryUPBCapability(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_queryUPBCapability(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::editUPBEntry(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_editUPBEntry(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::deleteUPBEntry(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_deleteUPBEntry(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::readUPBGasList(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_readUPBGasList(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::readUPBGrpEntry(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_readUPBGrpEntry(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::writeUPBGrpEntry(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_writeUPBGrpEntry(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getPhoneBookStringsLength(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getPhoneBookStringsLength(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getPhoneBookMemStorage(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getPhoneBookMemStorage(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setPhoneBookMemStorage(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setPhoneBookMemStorage(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::readPhoneBookEntryExt(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_readPhoneBookEntryExt(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::writePhoneBookEntryExt(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_writePhoneBookEntryExt(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::queryUPBAvailable(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_queryUPBAvailable(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::readUPBEmailEntry(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_readUPBEmailEntry(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::readUPBSneEntry(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_readUPBSneEntry(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::readUPBAnrEntry(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_readUPBAnrEntry(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::readUPBAasList(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_readUPBAasList(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::doGeneralSimAuthentication(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_doGeneralSimAuthentication(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::queryNetworkLock(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_queryNetworkLock(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setNetworkLock(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setNetworkLock(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::resetRadio(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_resetRadio(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::syncDataSettingsToMd(int32_t serial, const ::android::hardware::hidl_vec<int32_t>& dataSettings){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_syncDataSettingsToMd(this, this, serial, dataSettings);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::resetMdDataRetryCount(int32_t serial, const ::android::hardware::hidl_string& apn){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_resetMdDataRetryCount(this, this, serial, apn);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setRemoveRestrictEutranMode(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setRemoveRestrictEutranMode(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setLteAccessStratumReport(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setLteAccessStratumReport(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setLteUplinkDataTransfer(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setLteUplinkDataTransfer(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setRxTestConfig(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setRxTestConfig(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getRxTestResult(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getRxTestResult(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getPOLCapability(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getPOLCapability(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getCurrentPOLList(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getCurrentPOLList(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setPOLEntry(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setPOLEntry(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setRoamingEnable(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setRoamingEnable(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::getRoamingEnable(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_getRoamingEnable(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setDataProfileEx(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setDataProfileEx(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendVsimNotification(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_sendVsimNotification(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendVsimOperation(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_sendVsimOperation(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setVoiceDomainPreference(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setVoiceDomainPreference(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setModemImsCfg(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setModemImsCfg(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setWifiEnable(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setWifiEnable(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setWifiAssociated(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setWifiAssociated(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setWifiSignalLevel(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setWifiSignalLevel(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setWifiIpAddress(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setWifiIpAddress(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setLocationInfo(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setLocationInfo(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setEmergencyAddressId(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setEmergencyAddressId(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setE911State(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setE911State(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setServiceStateToModem(int32_t serial, int32_t voiceRegState, int32_t dataRegState, int32_t voiceRoamingType, int32_t dataRoamingType, int32_t rilVoiceRegState, int32_t rilDataRegState){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setServiceStateToModem(this, this, serial, voiceRegState, dataRegState, voiceRoamingType, dataRoamingType, rilVoiceRegState, rilDataRegState);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendRequestRaw(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_sendRequestRaw(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::sendRequestStrings(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_sendRequestStrings(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadio::setNattKeepAliveStatus(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadio::_hidl_setNattKeepAliveStatus(this, this);

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
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "vendor.mediatek.hardware.radio@2.0", "IRadio") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwRadio::~BnHwRadio() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadio follow.
::android::status_t BnHwRadio::_hidl_setResponseFunctionsMtk(
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

    ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioResponse> responseCb;
    ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioIndication> indicationCb;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        responseCb = ::android::hardware::fromBinder<::vendor::mediatek::hardware::radio::V2_0::IRadioResponse,::vendor::mediatek::hardware::radio::V2_0::BpHwRadioResponse,::vendor::mediatek::hardware::radio::V2_0::BnHwRadioResponse>(_hidl_binder);
    }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        indicationCb = ::android::hardware::fromBinder<::vendor::mediatek::hardware::radio::V2_0::IRadioIndication,::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication,::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setResponseFunctionsMtk::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&responseCb);
        _hidl_args.push_back((void *)&indicationCb);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResponseFunctionsMtk", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setResponseFunctionsMtk(responseCb, indicationCb);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResponseFunctionsMtk", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setResponseFunctionsIms(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setResponseFunctionsIms::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResponseFunctionsIms", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setResponseFunctionsIms();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResponseFunctionsIms", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setTrm(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setTrm::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setTrm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setTrm();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setTrm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getATR(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getATR::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getATR", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getATR();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getATR", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setSimPower(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setSimPower::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setSimPower", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setSimPower();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setSimPower", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_hangupAll(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::hangupAll::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "hangupAll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->hangupAll();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "hangupAll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setCallIndication(
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
    int32_t mode;
    int32_t callId;
    int32_t seqNo;

    _hidl_err = _hidl_data.readInt32(&serial);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&mode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&callId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&seqNo);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setCallIndication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&mode);
        _hidl_args.push_back((void *)&callId);
        _hidl_args.push_back((void *)&seqNo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setCallIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setCallIndication(serial, mode, callId, seqNo);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setCallIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_emergencyDial(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::emergencyDial::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "emergencyDial", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->emergencyDial();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "emergencyDial", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setEccServiceCategory(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setEccServiceCategory::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEccServiceCategory", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setEccServiceCategory();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEccServiceCategory", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setEccList(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setEccList::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEccList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setEccList();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEccList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_vtDial(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::vtDial::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "vtDial", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->vtDial();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "vtDial", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_voiceAccept(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::voiceAccept::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "voiceAccept", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->voiceAccept();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "voiceAccept", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_replaceVtCall(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::replaceVtCall::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "replaceVtCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->replaceVtCall();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "replaceVtCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_currentStatus(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::currentStatus::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "currentStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->currentStatus();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "currentStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_eccPreferredRat(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::eccPreferredRat::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "eccPreferredRat", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->eccPreferredRat();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "eccPreferredRat", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_videoCallAccept(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::videoCallAccept::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "videoCallAccept", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->videoCallAccept();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "videoCallAccept", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_imsEctCommand(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::imsEctCommand::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsEctCommand", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->imsEctCommand();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsEctCommand", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_holdCall(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::holdCall::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "holdCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->holdCall();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "holdCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_resumeCall(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::resumeCall::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "resumeCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->resumeCall();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "resumeCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_imsDeregNotification(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::imsDeregNotification::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsDeregNotification", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->imsDeregNotification();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsDeregNotification", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setImsEnable(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setImsEnable::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setImsEnable();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setVolteEnable(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setVolteEnable::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setVolteEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setVolteEnable();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setVolteEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setWfcEnable(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setWfcEnable::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWfcEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setWfcEnable();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWfcEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setVilteEnable(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setVilteEnable::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setVilteEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setVilteEnable();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setVilteEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setViWifiEnable(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setViWifiEnable::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setViWifiEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setViWifiEnable();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setViWifiEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setImsVoiceEnable(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setImsVoiceEnable::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsVoiceEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setImsVoiceEnable();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsVoiceEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setImsVideoEnable(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setImsVideoEnable::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsVideoEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setImsVideoEnable();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsVideoEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setImsCfg(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setImsCfg::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsCfg", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setImsCfg();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsCfg", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getProvisionValue(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getProvisionValue::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getProvisionValue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getProvisionValue();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getProvisionValue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setProvisionValue(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setProvisionValue::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setProvisionValue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setProvisionValue();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setProvisionValue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_addImsConferenceCallNumber(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::addImsConferenceCallNumber::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "addImsConferenceCallNumber", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->addImsConferenceCallNumber();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "addImsConferenceCallNumber", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_removeImsConferenceCallNumber(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::removeImsConferenceCallNumber::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "removeImsConferenceCallNumber", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->removeImsConferenceCallNumber();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "removeImsConferenceCallNumber", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setWfcProfile(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setWfcProfile::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWfcProfile", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setWfcProfile();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWfcProfile", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_conferenceDial(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::conferenceDial::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "conferenceDial", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->conferenceDial();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "conferenceDial", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_vtDialWithSipUri(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::vtDialWithSipUri::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "vtDialWithSipUri", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->vtDialWithSipUri();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "vtDialWithSipUri", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_dialWithSipUri(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::dialWithSipUri::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "dialWithSipUri", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->dialWithSipUri();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "dialWithSipUri", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_sendUssi(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::sendUssi::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendUssi", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->sendUssi();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendUssi", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_cancelUssi(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::cancelUssi::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "cancelUssi", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->cancelUssi();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "cancelUssi", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_forceReleaseCall(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::forceReleaseCall::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "forceReleaseCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->forceReleaseCall();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "forceReleaseCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_imsBearerActivationDone(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::imsBearerActivationDone::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsBearerActivationDone", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->imsBearerActivationDone();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsBearerActivationDone", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_imsBearerDeactivationDone(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::imsBearerDeactivationDone::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsBearerDeactivationDone", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->imsBearerDeactivationDone();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "imsBearerDeactivationDone", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setImsRtpReport(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setImsRtpReport::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsRtpReport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setImsRtpReport();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsRtpReport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_pullCall(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::pullCall::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "pullCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->pullCall();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "pullCall", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setImsRegistrationReport(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setImsRegistrationReport::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsRegistrationReport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setImsRegistrationReport();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setImsRegistrationReport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setResponseFunctionsForAtci(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setResponseFunctionsForAtci::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResponseFunctionsForAtci", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setResponseFunctionsForAtci();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResponseFunctionsForAtci", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_sendAtciRequest(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::sendAtciRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendAtciRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->sendAtciRequest();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendAtciRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setModemPower(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setModemPower::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setModemPower", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setModemPower();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setModemPower", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setNetworkSelectionModeManualWithAct(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setNetworkSelectionModeManualWithAct::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setNetworkSelectionModeManualWithAct", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setNetworkSelectionModeManualWithAct();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setNetworkSelectionModeManualWithAct", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getAvailableNetworksWithAct(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getAvailableNetworksWithAct::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getAvailableNetworksWithAct", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getAvailableNetworksWithAct();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getAvailableNetworksWithAct", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_cancelAvailableNetworks(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::cancelAvailableNetworks::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "cancelAvailableNetworks", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->cancelAvailableNetworks();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "cancelAvailableNetworks", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getSmsParameters(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getSmsParameters::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getSmsParameters", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getSmsParameters();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getSmsParameters", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setSmsParameters(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setSmsParameters::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setSmsParameters", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setSmsParameters();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setSmsParameters", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getSmsMemStatus(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getSmsMemStatus::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getSmsMemStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getSmsMemStatus();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getSmsMemStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setEtws(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setEtws::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEtws", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setEtws();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEtws", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_removeCbMsg(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::removeCbMsg::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "removeCbMsg", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->removeCbMsg();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "removeCbMsg", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setGsmBroadcastLangs(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setGsmBroadcastLangs::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setGsmBroadcastLangs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setGsmBroadcastLangs();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setGsmBroadcastLangs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getGsmBroadcastLangs(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getGsmBroadcastLangs::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getGsmBroadcastLangs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getGsmBroadcastLangs();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getGsmBroadcastLangs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getGsmBroadcastActivation(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getGsmBroadcastActivation::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getGsmBroadcastActivation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getGsmBroadcastActivation();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getGsmBroadcastActivation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_sendEmbmsAtCommand(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::sendEmbmsAtCommand::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendEmbmsAtCommand", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->sendEmbmsAtCommand();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendEmbmsAtCommand", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setApcMode(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setApcMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setApcMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setApcMode();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setApcMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getApcInfo(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getApcInfo::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getApcInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getApcInfo();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getApcInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_triggerModeSwitchByEcc(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::triggerModeSwitchByEcc::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "triggerModeSwitchByEcc", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->triggerModeSwitchByEcc();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "triggerModeSwitchByEcc", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getSmsRuimMemoryStatus(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getSmsRuimMemoryStatus::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getSmsRuimMemoryStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getSmsRuimMemoryStatus();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getSmsRuimMemoryStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setFdMode(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setFdMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setFdMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setFdMode();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setFdMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setResumeRegistration(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setResumeRegistration::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResumeRegistration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setResumeRegistration();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setResumeRegistration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_storeModemType(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::storeModemType::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "storeModemType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->storeModemType();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "storeModemType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_reloadModemType(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::reloadModemType::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "reloadModemType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->reloadModemType();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "reloadModemType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setInitialAttachApnEx(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setInitialAttachApnEx::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setInitialAttachApnEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setInitialAttachApnEx();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setInitialAttachApnEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_handleStkCallSetupRequestFromSimWithResCode(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::handleStkCallSetupRequestFromSimWithResCode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "handleStkCallSetupRequestFromSimWithResCode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->handleStkCallSetupRequestFromSimWithResCode();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "handleStkCallSetupRequestFromSimWithResCode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getFemtocellList(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getFemtocellList::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getFemtocellList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getFemtocellList();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getFemtocellList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_abortFemtocellList(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::abortFemtocellList::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "abortFemtocellList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->abortFemtocellList();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "abortFemtocellList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_selectFemtocell(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::selectFemtocell::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "selectFemtocell", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->selectFemtocell();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "selectFemtocell", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_queryFemtoCellSystemSelectionMode(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::queryFemtoCellSystemSelectionMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryFemtoCellSystemSelectionMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->queryFemtoCellSystemSelectionMode();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryFemtoCellSystemSelectionMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setFemtoCellSystemSelectionMode(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setFemtoCellSystemSelectionMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setFemtoCellSystemSelectionMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setFemtoCellSystemSelectionMode();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setFemtoCellSystemSelectionMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setBarringPasswordCheckedByNW(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setBarringPasswordCheckedByNW::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setBarringPasswordCheckedByNW", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setBarringPasswordCheckedByNW();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setBarringPasswordCheckedByNW", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setClip(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setClip::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setClip", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setClip();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setClip", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getColp(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getColp::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getColp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getColp();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getColp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getColr(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getColr::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getColr", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getColr();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getColr", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_sendCnap(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::sendCnap::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendCnap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->sendCnap();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendCnap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setColp(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setColp::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setColp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setColp();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setColp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setColr(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setColr::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setColr", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setColr();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setColr", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_queryCallForwardInTimeSlotStatus(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::queryCallForwardInTimeSlotStatus::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryCallForwardInTimeSlotStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->queryCallForwardInTimeSlotStatus();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryCallForwardInTimeSlotStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setCallForwardInTimeSlot(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setCallForwardInTimeSlot::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setCallForwardInTimeSlot", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setCallForwardInTimeSlot();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setCallForwardInTimeSlot", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_runGbaAuthentication(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::runGbaAuthentication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "runGbaAuthentication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->runGbaAuthentication();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "runGbaAuthentication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_queryPhbStorageInfo(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::queryPhbStorageInfo::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryPhbStorageInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->queryPhbStorageInfo();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryPhbStorageInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_writePhbEntry(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::writePhbEntry::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "writePhbEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->writePhbEntry();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "writePhbEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_readPhbEntry(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::readPhbEntry::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readPhbEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->readPhbEntry();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readPhbEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_queryUPBCapability(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::queryUPBCapability::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryUPBCapability", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->queryUPBCapability();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryUPBCapability", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_editUPBEntry(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::editUPBEntry::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "editUPBEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->editUPBEntry();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "editUPBEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_deleteUPBEntry(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::deleteUPBEntry::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "deleteUPBEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->deleteUPBEntry();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "deleteUPBEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_readUPBGasList(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::readUPBGasList::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBGasList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->readUPBGasList();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBGasList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_readUPBGrpEntry(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::readUPBGrpEntry::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBGrpEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->readUPBGrpEntry();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBGrpEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_writeUPBGrpEntry(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::writeUPBGrpEntry::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "writeUPBGrpEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->writeUPBGrpEntry();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "writeUPBGrpEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getPhoneBookStringsLength(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getPhoneBookStringsLength::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getPhoneBookStringsLength", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getPhoneBookStringsLength();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getPhoneBookStringsLength", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getPhoneBookMemStorage(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getPhoneBookMemStorage::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getPhoneBookMemStorage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getPhoneBookMemStorage();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getPhoneBookMemStorage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setPhoneBookMemStorage(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setPhoneBookMemStorage::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setPhoneBookMemStorage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setPhoneBookMemStorage();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setPhoneBookMemStorage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_readPhoneBookEntryExt(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::readPhoneBookEntryExt::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readPhoneBookEntryExt", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->readPhoneBookEntryExt();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readPhoneBookEntryExt", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_writePhoneBookEntryExt(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::writePhoneBookEntryExt::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "writePhoneBookEntryExt", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->writePhoneBookEntryExt();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "writePhoneBookEntryExt", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_queryUPBAvailable(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::queryUPBAvailable::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryUPBAvailable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->queryUPBAvailable();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryUPBAvailable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_readUPBEmailEntry(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::readUPBEmailEntry::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBEmailEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->readUPBEmailEntry();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBEmailEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_readUPBSneEntry(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::readUPBSneEntry::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBSneEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->readUPBSneEntry();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBSneEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_readUPBAnrEntry(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::readUPBAnrEntry::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBAnrEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->readUPBAnrEntry();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBAnrEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_readUPBAasList(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::readUPBAasList::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBAasList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->readUPBAasList();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "readUPBAasList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_doGeneralSimAuthentication(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::doGeneralSimAuthentication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "doGeneralSimAuthentication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->doGeneralSimAuthentication();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "doGeneralSimAuthentication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_queryNetworkLock(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::queryNetworkLock::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryNetworkLock", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->queryNetworkLock();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "queryNetworkLock", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setNetworkLock(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setNetworkLock::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setNetworkLock", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setNetworkLock();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setNetworkLock", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_resetRadio(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::resetRadio::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "resetRadio", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->resetRadio();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "resetRadio", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_syncDataSettingsToMd(
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
    const ::android::hardware::hidl_vec<int32_t>* dataSettings;

    _hidl_err = _hidl_data.readInt32(&serial);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dataSettings_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dataSettings), &_hidl_dataSettings_parent,  reinterpret_cast<const void **>(&dataSettings));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dataSettings_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int32_t> &>(*dataSettings),
            _hidl_data,
            _hidl_dataSettings_parent,
            0 /* parentOffset */, &_hidl_dataSettings_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::syncDataSettingsToMd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)dataSettings);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "syncDataSettingsToMd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->syncDataSettingsToMd(serial, *dataSettings);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "syncDataSettingsToMd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_resetMdDataRetryCount(
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
    const ::android::hardware::hidl_string* apn;

    _hidl_err = _hidl_data.readInt32(&serial);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_apn_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*apn), &_hidl_apn_parent,  reinterpret_cast<const void **>(&apn));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*apn),
            _hidl_data,
            _hidl_apn_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::resetMdDataRetryCount::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)apn);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "resetMdDataRetryCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->resetMdDataRetryCount(serial, *apn);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "resetMdDataRetryCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setRemoveRestrictEutranMode(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setRemoveRestrictEutranMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setRemoveRestrictEutranMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setRemoveRestrictEutranMode();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setRemoveRestrictEutranMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setLteAccessStratumReport(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setLteAccessStratumReport::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setLteAccessStratumReport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setLteAccessStratumReport();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setLteAccessStratumReport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setLteUplinkDataTransfer(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setLteUplinkDataTransfer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setLteUplinkDataTransfer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setLteUplinkDataTransfer();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setLteUplinkDataTransfer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setRxTestConfig(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setRxTestConfig::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setRxTestConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setRxTestConfig();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setRxTestConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getRxTestResult(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getRxTestResult::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getRxTestResult", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getRxTestResult();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getRxTestResult", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getPOLCapability(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getPOLCapability::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getPOLCapability", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getPOLCapability();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getPOLCapability", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getCurrentPOLList(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getCurrentPOLList::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getCurrentPOLList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getCurrentPOLList();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getCurrentPOLList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setPOLEntry(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setPOLEntry::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setPOLEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setPOLEntry();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setPOLEntry", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setRoamingEnable(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setRoamingEnable::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setRoamingEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setRoamingEnable();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setRoamingEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_getRoamingEnable(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::getRoamingEnable::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getRoamingEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->getRoamingEnable();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "getRoamingEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setDataProfileEx(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setDataProfileEx::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setDataProfileEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setDataProfileEx();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setDataProfileEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_sendVsimNotification(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::sendVsimNotification::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendVsimNotification", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->sendVsimNotification();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendVsimNotification", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_sendVsimOperation(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::sendVsimOperation::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendVsimOperation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->sendVsimOperation();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendVsimOperation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setVoiceDomainPreference(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setVoiceDomainPreference::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setVoiceDomainPreference", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setVoiceDomainPreference();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setVoiceDomainPreference", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setModemImsCfg(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setModemImsCfg::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setModemImsCfg", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setModemImsCfg();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setModemImsCfg", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setWifiEnable(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setWifiEnable::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setWifiEnable();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setWifiAssociated(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setWifiAssociated::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiAssociated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setWifiAssociated();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiAssociated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setWifiSignalLevel(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setWifiSignalLevel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiSignalLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setWifiSignalLevel();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiSignalLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setWifiIpAddress(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setWifiIpAddress::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiIpAddress", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setWifiIpAddress();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setWifiIpAddress", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setLocationInfo(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setLocationInfo::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setLocationInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setLocationInfo();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setLocationInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setEmergencyAddressId(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setEmergencyAddressId::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEmergencyAddressId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setEmergencyAddressId();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setEmergencyAddressId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setE911State(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setE911State::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setE911State", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setE911State();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setE911State", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setServiceStateToModem(
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
    int32_t voiceRegState;
    int32_t dataRegState;
    int32_t voiceRoamingType;
    int32_t dataRoamingType;
    int32_t rilVoiceRegState;
    int32_t rilDataRegState;

    _hidl_err = _hidl_data.readInt32(&serial);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&voiceRegState);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&dataRegState);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&voiceRoamingType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&dataRoamingType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&rilVoiceRegState);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&rilDataRegState);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setServiceStateToModem::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&serial);
        _hidl_args.push_back((void *)&voiceRegState);
        _hidl_args.push_back((void *)&dataRegState);
        _hidl_args.push_back((void *)&voiceRoamingType);
        _hidl_args.push_back((void *)&dataRoamingType);
        _hidl_args.push_back((void *)&rilVoiceRegState);
        _hidl_args.push_back((void *)&rilDataRegState);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setServiceStateToModem", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setServiceStateToModem(serial, voiceRegState, dataRegState, voiceRoamingType, dataRoamingType, rilVoiceRegState, rilDataRegState);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setServiceStateToModem", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_sendRequestRaw(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::sendRequestRaw::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendRequestRaw", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->sendRequestRaw();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendRequestRaw", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_sendRequestStrings(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::sendRequestStrings::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendRequestStrings", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->sendRequestStrings();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "sendRequestStrings", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadio::_hidl_setNattKeepAliveStatus(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadio::setNattKeepAliveStatus::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setNattKeepAliveStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadio*>(_hidl_this->getImpl().get())->setNattKeepAliveStatus();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadio", "setNattKeepAliveStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::radio::V1_0::IRadio follow.

// Methods from ::android::hardware::radio::V1_1::IRadio follow.

// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadio follow.

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

        case 137 /* setResponseFunctionsMtk */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setResponseFunctionsMtk(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 138 /* setResponseFunctionsIms */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setResponseFunctionsIms(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 139 /* setTrm */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setTrm(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 140 /* getATR */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getATR(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 141 /* setSimPower */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setSimPower(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 142 /* hangupAll */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_hangupAll(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 143 /* setCallIndication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setCallIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 144 /* emergencyDial */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_emergencyDial(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 145 /* setEccServiceCategory */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setEccServiceCategory(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 146 /* setEccList */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setEccList(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 147 /* vtDial */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_vtDial(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 148 /* voiceAccept */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_voiceAccept(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 149 /* replaceVtCall */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_replaceVtCall(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 150 /* currentStatus */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_currentStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 151 /* eccPreferredRat */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_eccPreferredRat(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 152 /* videoCallAccept */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_videoCallAccept(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 153 /* imsEctCommand */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_imsEctCommand(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 154 /* holdCall */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_holdCall(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 155 /* resumeCall */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_resumeCall(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 156 /* imsDeregNotification */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_imsDeregNotification(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 157 /* setImsEnable */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setImsEnable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 158 /* setVolteEnable */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setVolteEnable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 159 /* setWfcEnable */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setWfcEnable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 160 /* setVilteEnable */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setVilteEnable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 161 /* setViWifiEnable */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setViWifiEnable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 162 /* setImsVoiceEnable */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setImsVoiceEnable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 163 /* setImsVideoEnable */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setImsVideoEnable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 164 /* setImsCfg */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setImsCfg(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 165 /* getProvisionValue */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getProvisionValue(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 166 /* setProvisionValue */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setProvisionValue(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 167 /* addImsConferenceCallNumber */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_addImsConferenceCallNumber(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 168 /* removeImsConferenceCallNumber */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_removeImsConferenceCallNumber(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 169 /* setWfcProfile */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setWfcProfile(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 170 /* conferenceDial */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_conferenceDial(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 171 /* vtDialWithSipUri */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_vtDialWithSipUri(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 172 /* dialWithSipUri */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_dialWithSipUri(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 173 /* sendUssi */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_sendUssi(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 174 /* cancelUssi */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_cancelUssi(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 175 /* forceReleaseCall */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_forceReleaseCall(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 176 /* imsBearerActivationDone */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_imsBearerActivationDone(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 177 /* imsBearerDeactivationDone */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_imsBearerDeactivationDone(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 178 /* setImsRtpReport */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setImsRtpReport(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 179 /* pullCall */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_pullCall(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 180 /* setImsRegistrationReport */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setImsRegistrationReport(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 181 /* setResponseFunctionsForAtci */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setResponseFunctionsForAtci(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 182 /* sendAtciRequest */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_sendAtciRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 183 /* setModemPower */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setModemPower(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 184 /* setNetworkSelectionModeManualWithAct */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setNetworkSelectionModeManualWithAct(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 185 /* getAvailableNetworksWithAct */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getAvailableNetworksWithAct(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 186 /* cancelAvailableNetworks */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_cancelAvailableNetworks(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 187 /* getSmsParameters */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getSmsParameters(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 188 /* setSmsParameters */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setSmsParameters(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 189 /* getSmsMemStatus */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getSmsMemStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 190 /* setEtws */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setEtws(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 191 /* removeCbMsg */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_removeCbMsg(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 192 /* setGsmBroadcastLangs */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setGsmBroadcastLangs(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 193 /* getGsmBroadcastLangs */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getGsmBroadcastLangs(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 194 /* getGsmBroadcastActivation */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getGsmBroadcastActivation(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 195 /* sendEmbmsAtCommand */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_sendEmbmsAtCommand(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 196 /* setApcMode */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setApcMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 197 /* getApcInfo */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getApcInfo(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 198 /* triggerModeSwitchByEcc */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_triggerModeSwitchByEcc(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 199 /* getSmsRuimMemoryStatus */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getSmsRuimMemoryStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 200 /* setFdMode */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setFdMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 201 /* setResumeRegistration */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setResumeRegistration(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 202 /* storeModemType */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_storeModemType(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 203 /* reloadModemType */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_reloadModemType(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 204 /* setInitialAttachApnEx */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setInitialAttachApnEx(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 205 /* handleStkCallSetupRequestFromSimWithResCode */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_handleStkCallSetupRequestFromSimWithResCode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 206 /* getFemtocellList */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getFemtocellList(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 207 /* abortFemtocellList */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_abortFemtocellList(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 208 /* selectFemtocell */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_selectFemtocell(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 209 /* queryFemtoCellSystemSelectionMode */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_queryFemtoCellSystemSelectionMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 210 /* setFemtoCellSystemSelectionMode */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setFemtoCellSystemSelectionMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 211 /* setBarringPasswordCheckedByNW */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setBarringPasswordCheckedByNW(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 212 /* setClip */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setClip(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 213 /* getColp */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getColp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 214 /* getColr */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getColr(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 215 /* sendCnap */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_sendCnap(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 216 /* setColp */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setColp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 217 /* setColr */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setColr(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 218 /* queryCallForwardInTimeSlotStatus */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_queryCallForwardInTimeSlotStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 219 /* setCallForwardInTimeSlot */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setCallForwardInTimeSlot(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 220 /* runGbaAuthentication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_runGbaAuthentication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 221 /* queryPhbStorageInfo */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_queryPhbStorageInfo(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 222 /* writePhbEntry */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_writePhbEntry(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 223 /* readPhbEntry */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_readPhbEntry(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 224 /* queryUPBCapability */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_queryUPBCapability(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 225 /* editUPBEntry */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_editUPBEntry(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 226 /* deleteUPBEntry */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_deleteUPBEntry(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 227 /* readUPBGasList */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_readUPBGasList(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 228 /* readUPBGrpEntry */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_readUPBGrpEntry(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 229 /* writeUPBGrpEntry */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_writeUPBGrpEntry(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 230 /* getPhoneBookStringsLength */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getPhoneBookStringsLength(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 231 /* getPhoneBookMemStorage */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getPhoneBookMemStorage(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 232 /* setPhoneBookMemStorage */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setPhoneBookMemStorage(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 233 /* readPhoneBookEntryExt */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_readPhoneBookEntryExt(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 234 /* writePhoneBookEntryExt */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_writePhoneBookEntryExt(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 235 /* queryUPBAvailable */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_queryUPBAvailable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 236 /* readUPBEmailEntry */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_readUPBEmailEntry(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 237 /* readUPBSneEntry */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_readUPBSneEntry(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 238 /* readUPBAnrEntry */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_readUPBAnrEntry(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 239 /* readUPBAasList */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_readUPBAasList(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 240 /* doGeneralSimAuthentication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_doGeneralSimAuthentication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 241 /* queryNetworkLock */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_queryNetworkLock(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 242 /* setNetworkLock */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setNetworkLock(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 243 /* resetRadio */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_resetRadio(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 244 /* syncDataSettingsToMd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_syncDataSettingsToMd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 245 /* resetMdDataRetryCount */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_resetMdDataRetryCount(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 246 /* setRemoveRestrictEutranMode */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setRemoveRestrictEutranMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 247 /* setLteAccessStratumReport */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setLteAccessStratumReport(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 248 /* setLteUplinkDataTransfer */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setLteUplinkDataTransfer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 249 /* setRxTestConfig */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setRxTestConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 250 /* getRxTestResult */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getRxTestResult(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 251 /* getPOLCapability */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getPOLCapability(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 252 /* getCurrentPOLList */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getCurrentPOLList(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 253 /* setPOLEntry */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setPOLEntry(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 254 /* setRoamingEnable */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setRoamingEnable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 255 /* getRoamingEnable */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_getRoamingEnable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 256 /* setDataProfileEx */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setDataProfileEx(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 257 /* sendVsimNotification */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_sendVsimNotification(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 258 /* sendVsimOperation */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_sendVsimOperation(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 259 /* setVoiceDomainPreference */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setVoiceDomainPreference(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 260 /* setModemImsCfg */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setModemImsCfg(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 261 /* setWifiEnable */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setWifiEnable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 262 /* setWifiAssociated */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setWifiAssociated(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 263 /* setWifiSignalLevel */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setWifiSignalLevel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 264 /* setWifiIpAddress */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setWifiIpAddress(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 265 /* setLocationInfo */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setLocationInfo(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 266 /* setEmergencyAddressId */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setEmergencyAddressId(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 267 /* setE911State */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setE911State(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 268 /* setServiceStateToModem */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setServiceStateToModem(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 269 /* sendRequestRaw */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_sendRequestRaw(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 270 /* sendRequestStrings */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_sendRequestStrings(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 271 /* setNattKeepAliveStatus */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadio::_hidl_setNattKeepAliveStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsRadio::BsRadio(const ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadio> impl) : ::android::hardware::details::HidlInstrumentor("vendor.mediatek.hardware.radio@2.0", "IRadio"), mImpl(impl) {
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
            sm->registerForNotifications("vendor.mediatek.hardware.radio@2.0::IRadio",
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
