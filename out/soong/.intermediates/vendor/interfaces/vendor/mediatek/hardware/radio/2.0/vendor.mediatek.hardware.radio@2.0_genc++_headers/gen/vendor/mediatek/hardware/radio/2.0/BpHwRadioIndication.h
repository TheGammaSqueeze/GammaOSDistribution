#ifndef HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_0_BPHWRADIOINDICATION_H
#define HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_0_BPHWRADIOINDICATION_H

#include <hidl/HidlTransportSupport.h>

#include <vendor/mediatek/hardware/radio/2.0/IHwRadioIndication.h>

namespace vendor {
namespace mediatek {
namespace hardware {
namespace radio {
namespace V2_0 {

struct BpHwRadioIndication : public ::android::hardware::BpInterface<IRadioIndication>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwRadioIndication(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IRadioIndication Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadioIndication follow.
    static ::android::hardware::Return<void>  _hidl_incomingCallIndication(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::radio::V1_0::RadioIndicationType type, const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& notification);
    static ::android::hardware::Return<void>  _hidl_cipherIndication(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_crssIndication(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_vtStatusInfoIndication(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_speechCodecInfoIndication(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_cdmaCallAccepted(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onVirtualSimOn(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onVirtualSimOff(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onImeiLock(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onImsiRefreshDone(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_newEtwsInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_meSmsStorageFullInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_smsReadyInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_dataCallListChangedEx(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult>& dcResponse);
    static ::android::hardware::Return<void>  _hidl_responseCsNetworkStateChangeInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_eMBMSAtInfoIndication(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_eMBMSSessionStatusIndication(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_responsePsNetworkStateChangeInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_responseInvalidSimInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_responseNetworkEventInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_responseModulationInfoInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_dataAllowedNotification(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onPseudoCellInfoInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_plmnChangedIndication(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_registrationSuspendedIndication(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_gmssRatChangedIndication(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_worldModeChangedIndication(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_resetAttachApnInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_mdChangedApnInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_esnMeidChangeInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_responseFemtocellInfo(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_phbReadyNotification(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_bipProactiveCommand(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_triggerOtaSP(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onStkMenuReset(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onMdDataRetryCountReset(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onRemoveRestrictEutran(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onPcoStatus(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onLteAccessStratumStateChanged(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onSimPlugIn(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onSimPlugOut(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onSimMissing(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onSimRecovery(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onSimTrayPlugIn(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onSimCommonSlotNoChanged(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onSimMeLockEvent(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_networkInfoInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_cfuStatusNotify(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_pcoDataAfterAttached(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_confSRVCC(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onVsimEventIndication(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_volteLteConnectionStatus(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_dedicatedBearerActivationInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_dedicatedBearerModificationInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_dedicatedBearerDeactivationInd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onWifiMonitoringThreshouldChanged(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onWifiPdnActivate(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onWfcPdnError(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onPdnHandover(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onWifiRoveout(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onLocationRequest(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onWfcPdnStateChanged(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_onNattKeepAliveChanged(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_oemHookRaw(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);

    // Methods from ::android::hardware::radio::V1_0::IRadioIndication follow.
    ::android::hardware::Return<void> radioStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::RadioState radioState) override;
    ::android::hardware::Return<void> callStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type) override;
    ::android::hardware::Return<void> networkStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type) override;
    ::android::hardware::Return<void> newSms(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<uint8_t>& pdu) override;
    ::android::hardware::Return<void> newSmsStatusReport(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<uint8_t>& pdu) override;
    ::android::hardware::Return<void> newSmsOnSim(::android::hardware::radio::V1_0::RadioIndicationType type, int32_t recordNumber) override;
    ::android::hardware::Return<void> onUssd(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::UssdModeType modeType, const ::android::hardware::hidl_string& msg) override;
    ::android::hardware::Return<void> nitzTimeReceived(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& nitzTime, uint64_t receivedTime) override;
    ::android::hardware::Return<void> currentSignalStrength(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::SignalStrength& signalStrength) override;
    ::android::hardware::Return<void> dataCallListChanged(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::SetupDataCallResult>& dcList) override;
    ::android::hardware::Return<void> suppSvcNotify(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::SuppSvcNotification& suppSvc) override;
    ::android::hardware::Return<void> stkSessionEnd(::android::hardware::radio::V1_0::RadioIndicationType type) override;
    ::android::hardware::Return<void> stkProactiveCommand(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& cmd) override;
    ::android::hardware::Return<void> stkEventNotify(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& cmd) override;
    ::android::hardware::Return<void> stkCallSetup(::android::hardware::radio::V1_0::RadioIndicationType type, int64_t timeout) override;
    ::android::hardware::Return<void> simSmsStorageFull(::android::hardware::radio::V1_0::RadioIndicationType type) override;
    ::android::hardware::Return<void> simRefresh(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::SimRefreshResult& refreshResult) override;
    ::android::hardware::Return<void> callRing(::android::hardware::radio::V1_0::RadioIndicationType type, bool isGsm, const ::android::hardware::radio::V1_0::CdmaSignalInfoRecord& record) override;
    ::android::hardware::Return<void> simStatusChanged(::android::hardware::radio::V1_0::RadioIndicationType type) override;
    ::android::hardware::Return<void> cdmaNewSms(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::CdmaSmsMessage& msg) override;
    ::android::hardware::Return<void> newBroadcastSms(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<uint8_t>& data) override;
    ::android::hardware::Return<void> cdmaRuimSmsStorageFull(::android::hardware::radio::V1_0::RadioIndicationType type) override;
    ::android::hardware::Return<void> restrictedStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::PhoneRestrictedState state) override;
    ::android::hardware::Return<void> enterEmergencyCallbackMode(::android::hardware::radio::V1_0::RadioIndicationType type) override;
    ::android::hardware::Return<void> cdmaCallWaiting(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::CdmaCallWaiting& callWaitingRecord) override;
    ::android::hardware::Return<void> cdmaOtaProvisionStatus(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::CdmaOtaProvisionStatus status) override;
    ::android::hardware::Return<void> cdmaInfoRec(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::CdmaInformationRecords& records) override;
    ::android::hardware::Return<void> indicateRingbackTone(::android::hardware::radio::V1_0::RadioIndicationType type, bool start) override;
    ::android::hardware::Return<void> resendIncallMute(::android::hardware::radio::V1_0::RadioIndicationType type) override;
    ::android::hardware::Return<void> cdmaSubscriptionSourceChanged(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::CdmaSubscriptionSource cdmaSource) override;
    ::android::hardware::Return<void> cdmaPrlChanged(::android::hardware::radio::V1_0::RadioIndicationType type, int32_t version) override;
    ::android::hardware::Return<void> exitEmergencyCallbackMode(::android::hardware::radio::V1_0::RadioIndicationType type) override;
    ::android::hardware::Return<void> rilConnected(::android::hardware::radio::V1_0::RadioIndicationType type) override;
    ::android::hardware::Return<void> voiceRadioTechChanged(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::RadioTechnology rat) override;
    ::android::hardware::Return<void> cellInfoList(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfo>& records) override;
    ::android::hardware::Return<void> imsNetworkStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type) override;
    ::android::hardware::Return<void> subscriptionStatusChanged(::android::hardware::radio::V1_0::RadioIndicationType type, bool activate) override;
    ::android::hardware::Return<void> srvccStateNotify(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::SrvccState state) override;
    ::android::hardware::Return<void> hardwareConfigChanged(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::HardwareConfig>& configs) override;
    ::android::hardware::Return<void> radioCapabilityIndication(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::RadioCapability& rc) override;
    ::android::hardware::Return<void> onSupplementaryServiceIndication(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::StkCcUnsolSsResult& ss) override;
    ::android::hardware::Return<void> stkCallControlAlphaNotify(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& alpha) override;
    ::android::hardware::Return<void> lceData(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::LceDataInfo& lce) override;
    ::android::hardware::Return<void> pcoData(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::PcoDataInfo& pco) override;
    ::android::hardware::Return<void> modemReset(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& reason) override;

    // Methods from ::android::hardware::radio::V1_1::IRadioIndication follow.
    ::android::hardware::Return<void> carrierInfoForImsiEncryption(::android::hardware::radio::V1_0::RadioIndicationType info) override;
    ::android::hardware::Return<void> networkScanResult(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_1::NetworkScanResult& result) override;
    ::android::hardware::Return<void> keepaliveStatus(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_1::KeepaliveStatus& status) override;

    // Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadioIndication follow.
    ::android::hardware::Return<void> incomingCallIndication(::android::hardware::radio::V1_0::RadioIndicationType type, const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& notification) override;
    ::android::hardware::Return<void> cipherIndication() override;
    ::android::hardware::Return<void> crssIndication() override;
    ::android::hardware::Return<void> vtStatusInfoIndication() override;
    ::android::hardware::Return<void> speechCodecInfoIndication() override;
    ::android::hardware::Return<void> cdmaCallAccepted() override;
    ::android::hardware::Return<void> onVirtualSimOn() override;
    ::android::hardware::Return<void> onVirtualSimOff() override;
    ::android::hardware::Return<void> onImeiLock() override;
    ::android::hardware::Return<void> onImsiRefreshDone() override;
    ::android::hardware::Return<void> newEtwsInd() override;
    ::android::hardware::Return<void> meSmsStorageFullInd() override;
    ::android::hardware::Return<void> smsReadyInd() override;
    ::android::hardware::Return<void> dataCallListChangedEx(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult>& dcResponse) override;
    ::android::hardware::Return<void> responseCsNetworkStateChangeInd() override;
    ::android::hardware::Return<void> eMBMSAtInfoIndication() override;
    ::android::hardware::Return<void> eMBMSSessionStatusIndication() override;
    ::android::hardware::Return<void> responsePsNetworkStateChangeInd() override;
    ::android::hardware::Return<void> responseInvalidSimInd() override;
    ::android::hardware::Return<void> responseNetworkEventInd() override;
    ::android::hardware::Return<void> responseModulationInfoInd() override;
    ::android::hardware::Return<void> dataAllowedNotification() override;
    ::android::hardware::Return<void> onPseudoCellInfoInd() override;
    ::android::hardware::Return<void> plmnChangedIndication() override;
    ::android::hardware::Return<void> registrationSuspendedIndication() override;
    ::android::hardware::Return<void> gmssRatChangedIndication() override;
    ::android::hardware::Return<void> worldModeChangedIndication() override;
    ::android::hardware::Return<void> resetAttachApnInd() override;
    ::android::hardware::Return<void> mdChangedApnInd() override;
    ::android::hardware::Return<void> esnMeidChangeInd() override;
    ::android::hardware::Return<void> responseFemtocellInfo() override;
    ::android::hardware::Return<void> phbReadyNotification() override;
    ::android::hardware::Return<void> bipProactiveCommand() override;
    ::android::hardware::Return<void> triggerOtaSP() override;
    ::android::hardware::Return<void> onStkMenuReset() override;
    ::android::hardware::Return<void> onMdDataRetryCountReset() override;
    ::android::hardware::Return<void> onRemoveRestrictEutran() override;
    ::android::hardware::Return<void> onPcoStatus() override;
    ::android::hardware::Return<void> onLteAccessStratumStateChanged() override;
    ::android::hardware::Return<void> onSimPlugIn() override;
    ::android::hardware::Return<void> onSimPlugOut() override;
    ::android::hardware::Return<void> onSimMissing() override;
    ::android::hardware::Return<void> onSimRecovery() override;
    ::android::hardware::Return<void> onSimTrayPlugIn() override;
    ::android::hardware::Return<void> onSimCommonSlotNoChanged() override;
    ::android::hardware::Return<void> onSimMeLockEvent() override;
    ::android::hardware::Return<void> networkInfoInd() override;
    ::android::hardware::Return<void> cfuStatusNotify() override;
    ::android::hardware::Return<void> pcoDataAfterAttached() override;
    ::android::hardware::Return<void> confSRVCC() override;
    ::android::hardware::Return<void> onVsimEventIndication() override;
    ::android::hardware::Return<void> volteLteConnectionStatus() override;
    ::android::hardware::Return<void> dedicatedBearerActivationInd() override;
    ::android::hardware::Return<void> dedicatedBearerModificationInd() override;
    ::android::hardware::Return<void> dedicatedBearerDeactivationInd() override;
    ::android::hardware::Return<void> onWifiMonitoringThreshouldChanged() override;
    ::android::hardware::Return<void> onWifiPdnActivate() override;
    ::android::hardware::Return<void> onWfcPdnError() override;
    ::android::hardware::Return<void> onPdnHandover() override;
    ::android::hardware::Return<void> onWifiRoveout() override;
    ::android::hardware::Return<void> onLocationRequest() override;
    ::android::hardware::Return<void> onWfcPdnStateChanged() override;
    ::android::hardware::Return<void> onNattKeepAliveChanged() override;
    ::android::hardware::Return<void> oemHookRaw() override;

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

}  // namespace V2_0
}  // namespace radio
}  // namespace hardware
}  // namespace mediatek
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_0_BPHWRADIOINDICATION_H
