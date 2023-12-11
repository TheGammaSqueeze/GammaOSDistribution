#ifndef HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_3_BPHWRADIO_H
#define HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_3_BPHWRADIO_H

#include <hidl/HidlTransportSupport.h>

#include <vendor/mediatek/hardware/radio/2.3/IHwRadio.h>

namespace vendor {
namespace mediatek {
namespace hardware {
namespace radio {
namespace V2_3 {

struct BpHwRadio : public ::android::hardware::BpInterface<IRadio>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwRadio(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IRadio Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::vendor::mediatek::hardware::radio::V2_3::IRadio follow.
    static ::android::hardware::Return<void>  _hidl_setWifiFlightModeEnabled(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_setLocationInfoWlanMac(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);

    // Methods from ::android::hardware::radio::V1_0::IRadio follow.
    ::android::hardware::Return<void> setResponseFunctions(const ::android::sp<::android::hardware::radio::V1_0::IRadioResponse>& radioResponse, const ::android::sp<::android::hardware::radio::V1_0::IRadioIndication>& radioIndication) override;
    ::android::hardware::Return<void> getIccCardStatus(int32_t serial) override;
    ::android::hardware::Return<void> supplyIccPinForApp(int32_t serial, const ::android::hardware::hidl_string& pin, const ::android::hardware::hidl_string& aid) override;
    ::android::hardware::Return<void> supplyIccPukForApp(int32_t serial, const ::android::hardware::hidl_string& puk, const ::android::hardware::hidl_string& pin, const ::android::hardware::hidl_string& aid) override;
    ::android::hardware::Return<void> supplyIccPin2ForApp(int32_t serial, const ::android::hardware::hidl_string& pin2, const ::android::hardware::hidl_string& aid) override;
    ::android::hardware::Return<void> supplyIccPuk2ForApp(int32_t serial, const ::android::hardware::hidl_string& puk2, const ::android::hardware::hidl_string& pin2, const ::android::hardware::hidl_string& aid) override;
    ::android::hardware::Return<void> changeIccPinForApp(int32_t serial, const ::android::hardware::hidl_string& oldPin, const ::android::hardware::hidl_string& newPin, const ::android::hardware::hidl_string& aid) override;
    ::android::hardware::Return<void> changeIccPin2ForApp(int32_t serial, const ::android::hardware::hidl_string& oldPin2, const ::android::hardware::hidl_string& newPin2, const ::android::hardware::hidl_string& aid) override;
    ::android::hardware::Return<void> supplyNetworkDepersonalization(int32_t serial, const ::android::hardware::hidl_string& netPin) override;
    ::android::hardware::Return<void> getCurrentCalls(int32_t serial) override;
    ::android::hardware::Return<void> dial(int32_t serial, const ::android::hardware::radio::V1_0::Dial& dialInfo) override;
    ::android::hardware::Return<void> getImsiForApp(int32_t serial, const ::android::hardware::hidl_string& aid) override;
    ::android::hardware::Return<void> hangup(int32_t serial, int32_t gsmIndex) override;
    ::android::hardware::Return<void> hangupWaitingOrBackground(int32_t serial) override;
    ::android::hardware::Return<void> hangupForegroundResumeBackground(int32_t serial) override;
    ::android::hardware::Return<void> switchWaitingOrHoldingAndActive(int32_t serial) override;
    ::android::hardware::Return<void> conference(int32_t serial) override;
    ::android::hardware::Return<void> rejectCall(int32_t serial) override;
    ::android::hardware::Return<void> getLastCallFailCause(int32_t serial) override;
    ::android::hardware::Return<void> getSignalStrength(int32_t serial) override;
    ::android::hardware::Return<void> getVoiceRegistrationState(int32_t serial) override;
    ::android::hardware::Return<void> getDataRegistrationState(int32_t serial) override;
    ::android::hardware::Return<void> getOperator(int32_t serial) override;
    ::android::hardware::Return<void> setRadioPower(int32_t serial, bool on) override;
    ::android::hardware::Return<void> sendDtmf(int32_t serial, const ::android::hardware::hidl_string& s) override;
    ::android::hardware::Return<void> sendSms(int32_t serial, const ::android::hardware::radio::V1_0::GsmSmsMessage& message) override;
    ::android::hardware::Return<void> sendSMSExpectMore(int32_t serial, const ::android::hardware::radio::V1_0::GsmSmsMessage& message) override;
    ::android::hardware::Return<void> setupDataCall(int32_t serial, ::android::hardware::radio::V1_0::RadioTechnology radioTechnology, const ::android::hardware::radio::V1_0::DataProfileInfo& dataProfileInfo, bool modemCognitive, bool roamingAllowed, bool isRoaming) override;
    ::android::hardware::Return<void> iccIOForApp(int32_t serial, const ::android::hardware::radio::V1_0::IccIo& iccIo) override;
    ::android::hardware::Return<void> sendUssd(int32_t serial, const ::android::hardware::hidl_string& ussd) override;
    ::android::hardware::Return<void> cancelPendingUssd(int32_t serial) override;
    ::android::hardware::Return<void> getClir(int32_t serial) override;
    ::android::hardware::Return<void> setClir(int32_t serial, int32_t status) override;
    ::android::hardware::Return<void> getCallForwardStatus(int32_t serial, const ::android::hardware::radio::V1_0::CallForwardInfo& callInfo) override;
    ::android::hardware::Return<void> setCallForward(int32_t serial, const ::android::hardware::radio::V1_0::CallForwardInfo& callInfo) override;
    ::android::hardware::Return<void> getCallWaiting(int32_t serial, int32_t serviceClass) override;
    ::android::hardware::Return<void> setCallWaiting(int32_t serial, bool enable, int32_t serviceClass) override;
    ::android::hardware::Return<void> acknowledgeLastIncomingGsmSms(int32_t serial, bool success, ::android::hardware::radio::V1_0::SmsAcknowledgeFailCause cause) override;
    ::android::hardware::Return<void> acceptCall(int32_t serial) override;
    ::android::hardware::Return<void> deactivateDataCall(int32_t serial, int32_t cid, bool reasonRadioShutDown) override;
    ::android::hardware::Return<void> getFacilityLockForApp(int32_t serial, const ::android::hardware::hidl_string& facility, const ::android::hardware::hidl_string& password, int32_t serviceClass, const ::android::hardware::hidl_string& appId) override;
    ::android::hardware::Return<void> setFacilityLockForApp(int32_t serial, const ::android::hardware::hidl_string& facility, bool lockState, const ::android::hardware::hidl_string& password, int32_t serviceClass, const ::android::hardware::hidl_string& appId) override;
    ::android::hardware::Return<void> setBarringPassword(int32_t serial, const ::android::hardware::hidl_string& facility, const ::android::hardware::hidl_string& oldPassword, const ::android::hardware::hidl_string& newPassword) override;
    ::android::hardware::Return<void> getNetworkSelectionMode(int32_t serial) override;
    ::android::hardware::Return<void> setNetworkSelectionModeAutomatic(int32_t serial) override;
    ::android::hardware::Return<void> setNetworkSelectionModeManual(int32_t serial, const ::android::hardware::hidl_string& operatorNumeric) override;
    ::android::hardware::Return<void> getAvailableNetworks(int32_t serial) override;
    ::android::hardware::Return<void> startDtmf(int32_t serial, const ::android::hardware::hidl_string& s) override;
    ::android::hardware::Return<void> stopDtmf(int32_t serial) override;
    ::android::hardware::Return<void> getBasebandVersion(int32_t serial) override;
    ::android::hardware::Return<void> separateConnection(int32_t serial, int32_t gsmIndex) override;
    ::android::hardware::Return<void> setMute(int32_t serial, bool enable) override;
    ::android::hardware::Return<void> getMute(int32_t serial) override;
    ::android::hardware::Return<void> getClip(int32_t serial) override;
    ::android::hardware::Return<void> getDataCallList(int32_t serial) override;
    ::android::hardware::Return<void> setSuppServiceNotifications(int32_t serial, bool enable) override;
    ::android::hardware::Return<void> writeSmsToSim(int32_t serial, const ::android::hardware::radio::V1_0::SmsWriteArgs& smsWriteArgs) override;
    ::android::hardware::Return<void> deleteSmsOnSim(int32_t serial, int32_t index) override;
    ::android::hardware::Return<void> setBandMode(int32_t serial, ::android::hardware::radio::V1_0::RadioBandMode mode) override;
    ::android::hardware::Return<void> getAvailableBandModes(int32_t serial) override;
    ::android::hardware::Return<void> sendEnvelope(int32_t serial, const ::android::hardware::hidl_string& command) override;
    ::android::hardware::Return<void> sendTerminalResponseToSim(int32_t serial, const ::android::hardware::hidl_string& commandResponse) override;
    ::android::hardware::Return<void> handleStkCallSetupRequestFromSim(int32_t serial, bool accept) override;
    ::android::hardware::Return<void> explicitCallTransfer(int32_t serial) override;
    ::android::hardware::Return<void> setPreferredNetworkType(int32_t serial, ::android::hardware::radio::V1_0::PreferredNetworkType nwType) override;
    ::android::hardware::Return<void> getPreferredNetworkType(int32_t serial) override;
    ::android::hardware::Return<void> getNeighboringCids(int32_t serial) override;
    ::android::hardware::Return<void> setLocationUpdates(int32_t serial, bool enable) override;
    ::android::hardware::Return<void> setCdmaSubscriptionSource(int32_t serial, ::android::hardware::radio::V1_0::CdmaSubscriptionSource cdmaSub) override;
    ::android::hardware::Return<void> setCdmaRoamingPreference(int32_t serial, ::android::hardware::radio::V1_0::CdmaRoamingType type) override;
    ::android::hardware::Return<void> getCdmaRoamingPreference(int32_t serial) override;
    ::android::hardware::Return<void> setTTYMode(int32_t serial, ::android::hardware::radio::V1_0::TtyMode mode) override;
    ::android::hardware::Return<void> getTTYMode(int32_t serial) override;
    ::android::hardware::Return<void> setPreferredVoicePrivacy(int32_t serial, bool enable) override;
    ::android::hardware::Return<void> getPreferredVoicePrivacy(int32_t serial) override;
    ::android::hardware::Return<void> sendCDMAFeatureCode(int32_t serial, const ::android::hardware::hidl_string& featureCode) override;
    ::android::hardware::Return<void> sendBurstDtmf(int32_t serial, const ::android::hardware::hidl_string& dtmf, int32_t on, int32_t off) override;
    ::android::hardware::Return<void> sendCdmaSms(int32_t serial, const ::android::hardware::radio::V1_0::CdmaSmsMessage& sms) override;
    ::android::hardware::Return<void> acknowledgeLastIncomingCdmaSms(int32_t serial, const ::android::hardware::radio::V1_0::CdmaSmsAck& smsAck) override;
    ::android::hardware::Return<void> getGsmBroadcastConfig(int32_t serial) override;
    ::android::hardware::Return<void> setGsmBroadcastConfig(int32_t serial, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::GsmBroadcastSmsConfigInfo>& configInfo) override;
    ::android::hardware::Return<void> setGsmBroadcastActivation(int32_t serial, bool activate) override;
    ::android::hardware::Return<void> getCdmaBroadcastConfig(int32_t serial) override;
    ::android::hardware::Return<void> setCdmaBroadcastConfig(int32_t serial, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaBroadcastSmsConfigInfo>& configInfo) override;
    ::android::hardware::Return<void> setCdmaBroadcastActivation(int32_t serial, bool activate) override;
    ::android::hardware::Return<void> getCDMASubscription(int32_t serial) override;
    ::android::hardware::Return<void> writeSmsToRuim(int32_t serial, const ::android::hardware::radio::V1_0::CdmaSmsWriteArgs& cdmaSms) override;
    ::android::hardware::Return<void> deleteSmsOnRuim(int32_t serial, int32_t index) override;
    ::android::hardware::Return<void> getDeviceIdentity(int32_t serial) override;
    ::android::hardware::Return<void> exitEmergencyCallbackMode(int32_t serial) override;
    ::android::hardware::Return<void> getSmscAddress(int32_t serial) override;
    ::android::hardware::Return<void> setSmscAddress(int32_t serial, const ::android::hardware::hidl_string& smsc) override;
    ::android::hardware::Return<void> reportSmsMemoryStatus(int32_t serial, bool available) override;
    ::android::hardware::Return<void> reportStkServiceIsRunning(int32_t serial) override;
    ::android::hardware::Return<void> getCdmaSubscriptionSource(int32_t serial) override;
    ::android::hardware::Return<void> requestIsimAuthentication(int32_t serial, const ::android::hardware::hidl_string& challenge) override;
    ::android::hardware::Return<void> acknowledgeIncomingGsmSmsWithPdu(int32_t serial, bool success, const ::android::hardware::hidl_string& ackPdu) override;
    ::android::hardware::Return<void> sendEnvelopeWithStatus(int32_t serial, const ::android::hardware::hidl_string& contents) override;
    ::android::hardware::Return<void> getVoiceRadioTechnology(int32_t serial) override;
    ::android::hardware::Return<void> getCellInfoList(int32_t serial) override;
    ::android::hardware::Return<void> setCellInfoListRate(int32_t serial, int32_t rate) override;
    ::android::hardware::Return<void> setInitialAttachApn(int32_t serial, const ::android::hardware::radio::V1_0::DataProfileInfo& dataProfileInfo, bool modemCognitive, bool isRoaming) override;
    ::android::hardware::Return<void> getImsRegistrationState(int32_t serial) override;
    ::android::hardware::Return<void> sendImsSms(int32_t serial, const ::android::hardware::radio::V1_0::ImsSmsMessage& message) override;
    ::android::hardware::Return<void> iccTransmitApduBasicChannel(int32_t serial, const ::android::hardware::radio::V1_0::SimApdu& message) override;
    ::android::hardware::Return<void> iccOpenLogicalChannel(int32_t serial, const ::android::hardware::hidl_string& aid, int32_t p2) override;
    ::android::hardware::Return<void> iccCloseLogicalChannel(int32_t serial, int32_t channelId) override;
    ::android::hardware::Return<void> iccTransmitApduLogicalChannel(int32_t serial, const ::android::hardware::radio::V1_0::SimApdu& message) override;
    ::android::hardware::Return<void> nvReadItem(int32_t serial, ::android::hardware::radio::V1_0::NvItem itemId) override;
    ::android::hardware::Return<void> nvWriteItem(int32_t serial, const ::android::hardware::radio::V1_0::NvWriteItem& item) override;
    ::android::hardware::Return<void> nvWriteCdmaPrl(int32_t serial, const ::android::hardware::hidl_vec<uint8_t>& prl) override;
    ::android::hardware::Return<void> nvResetConfig(int32_t serial, ::android::hardware::radio::V1_0::ResetNvType resetType) override;
    ::android::hardware::Return<void> setUiccSubscription(int32_t serial, const ::android::hardware::radio::V1_0::SelectUiccSub& uiccSub) override;
    ::android::hardware::Return<void> setDataAllowed(int32_t serial, bool allow) override;
    ::android::hardware::Return<void> getHardwareConfig(int32_t serial) override;
    ::android::hardware::Return<void> requestIccSimAuthentication(int32_t serial, int32_t authContext, const ::android::hardware::hidl_string& authData, const ::android::hardware::hidl_string& aid) override;
    ::android::hardware::Return<void> setDataProfile(int32_t serial, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::DataProfileInfo>& profiles, bool isRoaming) override;
    ::android::hardware::Return<void> requestShutdown(int32_t serial) override;
    ::android::hardware::Return<void> getRadioCapability(int32_t serial) override;
    ::android::hardware::Return<void> setRadioCapability(int32_t serial, const ::android::hardware::radio::V1_0::RadioCapability& rc) override;
    ::android::hardware::Return<void> startLceService(int32_t serial, int32_t reportInterval, bool pullMode) override;
    ::android::hardware::Return<void> stopLceService(int32_t serial) override;
    ::android::hardware::Return<void> pullLceData(int32_t serial) override;
    ::android::hardware::Return<void> getModemActivityInfo(int32_t serial) override;
    ::android::hardware::Return<void> setAllowedCarriers(int32_t serial, bool allAllowed, const ::android::hardware::radio::V1_0::CarrierRestrictions& carriers) override;
    ::android::hardware::Return<void> getAllowedCarriers(int32_t serial) override;
    ::android::hardware::Return<void> sendDeviceState(int32_t serial, ::android::hardware::radio::V1_0::DeviceStateType deviceStateType, bool state) override;
    ::android::hardware::Return<void> setIndicationFilter(int32_t serial, ::android::hardware::hidl_bitfield<::android::hardware::radio::V1_0::IndicationFilter> indicationFilter) override;
    ::android::hardware::Return<void> setSimCardPower(int32_t serial, bool powerUp) override;
    ::android::hardware::Return<void> responseAcknowledgement() override;

    // Methods from ::android::hardware::radio::V1_1::IRadio follow.
    ::android::hardware::Return<void> setCarrierInfoForImsiEncryption(int32_t serial, const ::android::hardware::radio::V1_1::ImsiEncryptionInfo& imsiEncryptionInfo) override;
    ::android::hardware::Return<void> setSimCardPower_1_1(int32_t serial, ::android::hardware::radio::V1_1::CardPowerState powerUp) override;
    ::android::hardware::Return<void> startNetworkScan(int32_t serial, const ::android::hardware::radio::V1_1::NetworkScanRequest& request) override;
    ::android::hardware::Return<void> stopNetworkScan(int32_t serial) override;
    ::android::hardware::Return<void> startKeepalive(int32_t serial, const ::android::hardware::radio::V1_1::KeepaliveRequest& keepalive) override;
    ::android::hardware::Return<void> stopKeepalive(int32_t serial, int32_t sessionHandle) override;

    // Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadio follow.
    ::android::hardware::Return<void> setResponseFunctionsMtk(const ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioResponse>& responseCb, const ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioIndication>& indicationCb) override;
    ::android::hardware::Return<void> setResponseFunctionsIms() override;
    ::android::hardware::Return<void> setTrm() override;
    ::android::hardware::Return<void> getATR() override;
    ::android::hardware::Return<void> setSimPower() override;
    ::android::hardware::Return<void> hangupAll() override;
    ::android::hardware::Return<void> setCallIndication(int32_t serial, int32_t mode, int32_t callId, int32_t seqNo) override;
    ::android::hardware::Return<void> emergencyDial() override;
    ::android::hardware::Return<void> setEccServiceCategory() override;
    ::android::hardware::Return<void> setEccList() override;
    ::android::hardware::Return<void> vtDial() override;
    ::android::hardware::Return<void> voiceAccept() override;
    ::android::hardware::Return<void> replaceVtCall() override;
    ::android::hardware::Return<void> currentStatus() override;
    ::android::hardware::Return<void> eccPreferredRat() override;
    ::android::hardware::Return<void> videoCallAccept() override;
    ::android::hardware::Return<void> imsEctCommand() override;
    ::android::hardware::Return<void> holdCall() override;
    ::android::hardware::Return<void> resumeCall() override;
    ::android::hardware::Return<void> imsDeregNotification() override;
    ::android::hardware::Return<void> setImsEnable() override;
    ::android::hardware::Return<void> setVolteEnable() override;
    ::android::hardware::Return<void> setWfcEnable() override;
    ::android::hardware::Return<void> setVilteEnable() override;
    ::android::hardware::Return<void> setViWifiEnable() override;
    ::android::hardware::Return<void> setImsVoiceEnable() override;
    ::android::hardware::Return<void> setImsVideoEnable() override;
    ::android::hardware::Return<void> setImsCfg() override;
    ::android::hardware::Return<void> getProvisionValue() override;
    ::android::hardware::Return<void> setProvisionValue() override;
    ::android::hardware::Return<void> addImsConferenceCallNumber() override;
    ::android::hardware::Return<void> removeImsConferenceCallNumber() override;
    ::android::hardware::Return<void> setWfcProfile() override;
    ::android::hardware::Return<void> conferenceDial() override;
    ::android::hardware::Return<void> vtDialWithSipUri() override;
    ::android::hardware::Return<void> dialWithSipUri() override;
    ::android::hardware::Return<void> sendUssi() override;
    ::android::hardware::Return<void> cancelUssi() override;
    ::android::hardware::Return<void> forceReleaseCall() override;
    ::android::hardware::Return<void> imsBearerActivationDone() override;
    ::android::hardware::Return<void> imsBearerDeactivationDone() override;
    ::android::hardware::Return<void> setImsRtpReport() override;
    ::android::hardware::Return<void> pullCall() override;
    ::android::hardware::Return<void> setImsRegistrationReport() override;
    ::android::hardware::Return<void> setResponseFunctionsForAtci() override;
    ::android::hardware::Return<void> sendAtciRequest() override;
    ::android::hardware::Return<void> setModemPower() override;
    ::android::hardware::Return<void> setNetworkSelectionModeManualWithAct() override;
    ::android::hardware::Return<void> getAvailableNetworksWithAct() override;
    ::android::hardware::Return<void> cancelAvailableNetworks() override;
    ::android::hardware::Return<void> getSmsParameters() override;
    ::android::hardware::Return<void> setSmsParameters() override;
    ::android::hardware::Return<void> getSmsMemStatus() override;
    ::android::hardware::Return<void> setEtws() override;
    ::android::hardware::Return<void> removeCbMsg() override;
    ::android::hardware::Return<void> setGsmBroadcastLangs() override;
    ::android::hardware::Return<void> getGsmBroadcastLangs() override;
    ::android::hardware::Return<void> getGsmBroadcastActivation() override;
    ::android::hardware::Return<void> sendEmbmsAtCommand() override;
    ::android::hardware::Return<void> setApcMode() override;
    ::android::hardware::Return<void> getApcInfo() override;
    ::android::hardware::Return<void> triggerModeSwitchByEcc() override;
    ::android::hardware::Return<void> getSmsRuimMemoryStatus() override;
    ::android::hardware::Return<void> setFdMode() override;
    ::android::hardware::Return<void> setResumeRegistration() override;
    ::android::hardware::Return<void> storeModemType() override;
    ::android::hardware::Return<void> reloadModemType() override;
    ::android::hardware::Return<void> setInitialAttachApnEx() override;
    ::android::hardware::Return<void> handleStkCallSetupRequestFromSimWithResCode() override;
    ::android::hardware::Return<void> getFemtocellList() override;
    ::android::hardware::Return<void> abortFemtocellList() override;
    ::android::hardware::Return<void> selectFemtocell() override;
    ::android::hardware::Return<void> queryFemtoCellSystemSelectionMode() override;
    ::android::hardware::Return<void> setFemtoCellSystemSelectionMode() override;
    ::android::hardware::Return<void> setBarringPasswordCheckedByNW() override;
    ::android::hardware::Return<void> setClip() override;
    ::android::hardware::Return<void> getColp() override;
    ::android::hardware::Return<void> getColr() override;
    ::android::hardware::Return<void> sendCnap() override;
    ::android::hardware::Return<void> setColp() override;
    ::android::hardware::Return<void> setColr() override;
    ::android::hardware::Return<void> queryCallForwardInTimeSlotStatus() override;
    ::android::hardware::Return<void> setCallForwardInTimeSlot() override;
    ::android::hardware::Return<void> runGbaAuthentication() override;
    ::android::hardware::Return<void> queryPhbStorageInfo() override;
    ::android::hardware::Return<void> writePhbEntry() override;
    ::android::hardware::Return<void> readPhbEntry() override;
    ::android::hardware::Return<void> queryUPBCapability() override;
    ::android::hardware::Return<void> editUPBEntry() override;
    ::android::hardware::Return<void> deleteUPBEntry() override;
    ::android::hardware::Return<void> readUPBGasList() override;
    ::android::hardware::Return<void> readUPBGrpEntry() override;
    ::android::hardware::Return<void> writeUPBGrpEntry() override;
    ::android::hardware::Return<void> getPhoneBookStringsLength() override;
    ::android::hardware::Return<void> getPhoneBookMemStorage() override;
    ::android::hardware::Return<void> setPhoneBookMemStorage() override;
    ::android::hardware::Return<void> readPhoneBookEntryExt() override;
    ::android::hardware::Return<void> writePhoneBookEntryExt() override;
    ::android::hardware::Return<void> queryUPBAvailable() override;
    ::android::hardware::Return<void> readUPBEmailEntry() override;
    ::android::hardware::Return<void> readUPBSneEntry() override;
    ::android::hardware::Return<void> readUPBAnrEntry() override;
    ::android::hardware::Return<void> readUPBAasList() override;
    ::android::hardware::Return<void> doGeneralSimAuthentication() override;
    ::android::hardware::Return<void> queryNetworkLock() override;
    ::android::hardware::Return<void> setNetworkLock() override;
    ::android::hardware::Return<void> resetRadio() override;
    ::android::hardware::Return<void> syncDataSettingsToMd(int32_t serial, const ::android::hardware::hidl_vec<int32_t>& dataSettings) override;
    ::android::hardware::Return<void> resetMdDataRetryCount(int32_t serial, const ::android::hardware::hidl_string& apn) override;
    ::android::hardware::Return<void> setRemoveRestrictEutranMode() override;
    ::android::hardware::Return<void> setLteAccessStratumReport() override;
    ::android::hardware::Return<void> setLteUplinkDataTransfer() override;
    ::android::hardware::Return<void> setRxTestConfig() override;
    ::android::hardware::Return<void> getRxTestResult() override;
    ::android::hardware::Return<void> getPOLCapability() override;
    ::android::hardware::Return<void> getCurrentPOLList() override;
    ::android::hardware::Return<void> setPOLEntry() override;
    ::android::hardware::Return<void> setRoamingEnable() override;
    ::android::hardware::Return<void> getRoamingEnable() override;
    ::android::hardware::Return<void> setDataProfileEx() override;
    ::android::hardware::Return<void> sendVsimNotification() override;
    ::android::hardware::Return<void> sendVsimOperation() override;
    ::android::hardware::Return<void> setVoiceDomainPreference() override;
    ::android::hardware::Return<void> setModemImsCfg() override;
    ::android::hardware::Return<void> setWifiEnable() override;
    ::android::hardware::Return<void> setWifiAssociated() override;
    ::android::hardware::Return<void> setWifiSignalLevel() override;
    ::android::hardware::Return<void> setWifiIpAddress() override;
    ::android::hardware::Return<void> setLocationInfo() override;
    ::android::hardware::Return<void> setEmergencyAddressId() override;
    ::android::hardware::Return<void> setE911State() override;
    ::android::hardware::Return<void> setServiceStateToModem(int32_t serial, int32_t voiceRegState, int32_t dataRegState, int32_t voiceRoamingType, int32_t dataRoamingType, int32_t rilVoiceRegState, int32_t rilDataRegState) override;
    ::android::hardware::Return<void> sendRequestRaw() override;
    ::android::hardware::Return<void> sendRequestStrings() override;
    ::android::hardware::Return<void> setNattKeepAliveStatus() override;

    // Methods from ::vendor::mediatek::hardware::radio::V2_3::IRadio follow.
    ::android::hardware::Return<void> setWifiFlightModeEnabled() override;
    ::android::hardware::Return<void> setLocationInfoWlanMac() override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;
    ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;
    ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> setHALInstrumentation() override;
    ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;
    ::android::hardware::Return<void> ping() override;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;
    ::android::hardware::Return<void> notifySyspropsChanged() override;
    ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

private:
    std::mutex _hidl_mMutex;
    std::vector<::android::sp<::android::hardware::hidl_binder_death_recipient>> _hidl_mDeathRecipients;
};

}  // namespace V2_3
}  // namespace radio
}  // namespace hardware
}  // namespace mediatek
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_3_BPHWRADIO_H
