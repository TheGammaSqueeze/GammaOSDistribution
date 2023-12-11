#define LOG_TAG "vendor.mediatek.hardware.radio@2.0::RadioIndication"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <vendor/mediatek/hardware/radio/2.0/BpHwRadioIndication.h>
#include <vendor/mediatek/hardware/radio/2.0/BnHwRadioIndication.h>
#include <vendor/mediatek/hardware/radio/2.0/BsRadioIndication.h>
#include <android/hardware/radio/1.1/BpHwRadioIndication.h>
#include <android/hardware/radio/1.0/BpHwRadioIndication.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace vendor {
namespace mediatek {
namespace hardware {
namespace radio {
namespace V2_0 {

const char* IRadioIndication::descriptor("vendor.mediatek.hardware.radio@2.0::IRadioIndication");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IRadioIndication::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwRadioIndication(static_cast<IRadioIndication *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IRadioIndication::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsRadioIndication(static_cast<IRadioIndication *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IRadioIndication::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IRadioIndication::descriptor);
}

// Methods from ::android::hardware::radio::V1_0::IRadioIndication follow.
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::radioStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::RadioState radioState)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::callStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::networkStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::newSms(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<uint8_t>& pdu)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::newSmsStatusReport(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<uint8_t>& pdu)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::newSmsOnSim(::android::hardware::radio::V1_0::RadioIndicationType type, int32_t recordNumber)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onUssd(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::UssdModeType modeType, const ::android::hardware::hidl_string& msg)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::nitzTimeReceived(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& nitzTime, uint64_t receivedTime)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::currentSignalStrength(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::SignalStrength& signalStrength)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::dataCallListChanged(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::SetupDataCallResult>& dcList)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::suppSvcNotify(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::SuppSvcNotification& suppSvc)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::stkSessionEnd(::android::hardware::radio::V1_0::RadioIndicationType type)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::stkProactiveCommand(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& cmd)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::stkEventNotify(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& cmd)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::stkCallSetup(::android::hardware::radio::V1_0::RadioIndicationType type, int64_t timeout)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::simSmsStorageFull(::android::hardware::radio::V1_0::RadioIndicationType type)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::simRefresh(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::SimRefreshResult& refreshResult)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::callRing(::android::hardware::radio::V1_0::RadioIndicationType type, bool isGsm, const ::android::hardware::radio::V1_0::CdmaSignalInfoRecord& record)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::simStatusChanged(::android::hardware::radio::V1_0::RadioIndicationType type)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::cdmaNewSms(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::CdmaSmsMessage& msg)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::newBroadcastSms(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<uint8_t>& data)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::cdmaRuimSmsStorageFull(::android::hardware::radio::V1_0::RadioIndicationType type)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::restrictedStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::PhoneRestrictedState state)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::enterEmergencyCallbackMode(::android::hardware::radio::V1_0::RadioIndicationType type)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::cdmaCallWaiting(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::CdmaCallWaiting& callWaitingRecord)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::cdmaOtaProvisionStatus(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::CdmaOtaProvisionStatus status)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::cdmaInfoRec(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::CdmaInformationRecords& records)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::indicateRingbackTone(::android::hardware::radio::V1_0::RadioIndicationType type, bool start)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::resendIncallMute(::android::hardware::radio::V1_0::RadioIndicationType type)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::cdmaSubscriptionSourceChanged(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::CdmaSubscriptionSource cdmaSource)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::cdmaPrlChanged(::android::hardware::radio::V1_0::RadioIndicationType type, int32_t version)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::exitEmergencyCallbackMode(::android::hardware::radio::V1_0::RadioIndicationType type)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::rilConnected(::android::hardware::radio::V1_0::RadioIndicationType type)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::voiceRadioTechChanged(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::RadioTechnology rat)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::cellInfoList(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfo>& records)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::imsNetworkStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::subscriptionStatusChanged(::android::hardware::radio::V1_0::RadioIndicationType type, bool activate)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::srvccStateNotify(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::SrvccState state)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::hardwareConfigChanged(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::HardwareConfig>& configs)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::radioCapabilityIndication(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::RadioCapability& rc)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onSupplementaryServiceIndication(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::StkCcUnsolSsResult& ss)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::stkCallControlAlphaNotify(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& alpha)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::lceData(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::LceDataInfo& lce)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::pcoData(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::PcoDataInfo& pco)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::modemReset(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& reason)

// Methods from ::android::hardware::radio::V1_1::IRadioIndication follow.
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::carrierInfoForImsiEncryption(::android::hardware::radio::V1_0::RadioIndicationType info)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::networkScanResult(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_1::NetworkScanResult& result)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::keepaliveStatus(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_1::KeepaliveStatus& status)

// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadioIndication follow.
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::incomingCallIndication(::android::hardware::radio::V1_0::RadioIndicationType type, const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& notification)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::cipherIndication()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::crssIndication()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::vtStatusInfoIndication()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::speechCodecInfoIndication()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::cdmaCallAccepted()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onVirtualSimOn()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onVirtualSimOff()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onImeiLock()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onImsiRefreshDone()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::newEtwsInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::meSmsStorageFullInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::smsReadyInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::dataCallListChangedEx(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult>& dcResponse)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::responseCsNetworkStateChangeInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::eMBMSAtInfoIndication()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::eMBMSSessionStatusIndication()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::responsePsNetworkStateChangeInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::responseInvalidSimInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::responseNetworkEventInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::responseModulationInfoInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::dataAllowedNotification()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onPseudoCellInfoInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::plmnChangedIndication()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::registrationSuspendedIndication()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::gmssRatChangedIndication()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::worldModeChangedIndication()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::resetAttachApnInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::mdChangedApnInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::esnMeidChangeInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::responseFemtocellInfo()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::phbReadyNotification()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::bipProactiveCommand()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::triggerOtaSP()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onStkMenuReset()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onMdDataRetryCountReset()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onRemoveRestrictEutran()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onPcoStatus()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onLteAccessStratumStateChanged()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onSimPlugIn()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onSimPlugOut()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onSimMissing()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onSimRecovery()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onSimTrayPlugIn()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onSimCommonSlotNoChanged()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onSimMeLockEvent()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::networkInfoInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::cfuStatusNotify()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::pcoDataAfterAttached()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::confSRVCC()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onVsimEventIndication()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::volteLteConnectionStatus()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::dedicatedBearerActivationInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::dedicatedBearerModificationInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::dedicatedBearerDeactivationInd()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onWifiMonitoringThreshouldChanged()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onWifiPdnActivate()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onWfcPdnError()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onPdnHandover()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onWifiRoveout()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onLocationRequest()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onWfcPdnStateChanged()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::onNattKeepAliveChanged()
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::oemHookRaw()

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IRadioIndication::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::vendor::mediatek::hardware::radio::V2_0::IRadioIndication::descriptor,
        ::android::hardware::radio::V1_1::IRadioIndication::descriptor,
        ::android::hardware::radio::V1_0::IRadioIndication::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioIndication::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioIndication::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::vendor::mediatek::hardware::radio::V2_0::IRadioIndication::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioIndication::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} /* 0000000000000000000000000000000000000000000000000000000000000000 */,
        (uint8_t[32]){252,197,200,200,139,133,169,246,63,186,103,217,230,116,218,70,108,114,169,140,162,135,243,67,251,87,33,208,152,113,63,134} /* fcc5c8c88b85a9f63fba67d9e674da466c72a98ca287f343fb5721d098713f86 */,
        (uint8_t[32]){137,215,143,164,155,9,226,243,24,18,187,99,225,191,172,43,243,24,169,86,20,115,198,176,237,105,4,206,24,55,125,84} /* 89d78fa49b09e2f31812bb63e1bfac2bf318a9561473c6b0ed6904ce18377d54 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioIndication::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IRadioIndication::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IRadioIndication::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioIndication::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IRadioIndication::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IRadioIndication::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioIndication>> IRadioIndication::castFrom(const ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioIndication>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioIndication>> IRadioIndication::castFrom(const ::android::sp<::android::hardware::radio::V1_1::IRadioIndication>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioIndication, ::android::hardware::radio::V1_1::IRadioIndication, BpHwRadioIndication>(
            parent, "vendor.mediatek.hardware.radio@2.0::IRadioIndication", emitError);
}

::android::hardware::Return<::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioIndication>> IRadioIndication::castFrom(const ::android::sp<::android::hardware::radio::V1_0::IRadioIndication>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioIndication, ::android::hardware::radio::V1_0::IRadioIndication, BpHwRadioIndication>(
            parent, "vendor.mediatek.hardware.radio@2.0::IRadioIndication", emitError);
}

::android::hardware::Return<::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioIndication>> IRadioIndication::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioIndication, ::android::hidl::base::V1_0::IBase, BpHwRadioIndication>(
            parent, "vendor.mediatek.hardware.radio@2.0::IRadioIndication", emitError);
}

BpHwRadioIndication::BpHwRadioIndication(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IRadioIndication>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("vendor.mediatek.hardware.radio@2.0", "IRadioIndication") {
}

void BpHwRadioIndication::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IRadioIndication>::onLastStrongRef(id);
}
// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadioIndication follow.
::android::hardware::Return<void> BpHwRadioIndication::_hidl_incomingCallIndication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::radio::V1_0::RadioIndicationType type, const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& notification) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::incomingCallIndication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&notification);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "incomingCallIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_notification_parent;

    _hidl_err = _hidl_data.writeBuffer(&notification, sizeof(notification), &_hidl_notification_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            notification,
            &_hidl_data,
            _hidl_notification_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(49 /* incomingCallIndication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "incomingCallIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_cipherIndication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::cipherIndication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "cipherIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(50 /* cipherIndication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "cipherIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_crssIndication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::crssIndication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "crssIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(51 /* crssIndication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "crssIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_vtStatusInfoIndication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::vtStatusInfoIndication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "vtStatusInfoIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(52 /* vtStatusInfoIndication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "vtStatusInfoIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_speechCodecInfoIndication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::speechCodecInfoIndication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "speechCodecInfoIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(53 /* speechCodecInfoIndication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "speechCodecInfoIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_cdmaCallAccepted(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::cdmaCallAccepted::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "cdmaCallAccepted", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(54 /* cdmaCallAccepted */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "cdmaCallAccepted", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onVirtualSimOn(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onVirtualSimOn::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onVirtualSimOn", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(55 /* onVirtualSimOn */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onVirtualSimOn", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onVirtualSimOff(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onVirtualSimOff::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onVirtualSimOff", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(56 /* onVirtualSimOff */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onVirtualSimOff", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onImeiLock(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onImeiLock::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onImeiLock", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(57 /* onImeiLock */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onImeiLock", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onImsiRefreshDone(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onImsiRefreshDone::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onImsiRefreshDone", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(58 /* onImsiRefreshDone */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onImsiRefreshDone", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_newEtwsInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::newEtwsInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "newEtwsInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(59 /* newEtwsInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "newEtwsInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_meSmsStorageFullInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::meSmsStorageFullInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "meSmsStorageFullInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(60 /* meSmsStorageFullInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "meSmsStorageFullInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_smsReadyInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::smsReadyInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "smsReadyInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(61 /* smsReadyInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "smsReadyInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_dataCallListChangedEx(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult>& dcResponse) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::dataCallListChangedEx::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&dcResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dataCallListChangedEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)type);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(62 /* dataCallListChangedEx */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dataCallListChangedEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_responseCsNetworkStateChangeInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::responseCsNetworkStateChangeInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseCsNetworkStateChangeInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(63 /* responseCsNetworkStateChangeInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseCsNetworkStateChangeInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_eMBMSAtInfoIndication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::eMBMSAtInfoIndication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "eMBMSAtInfoIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(64 /* eMBMSAtInfoIndication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "eMBMSAtInfoIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_eMBMSSessionStatusIndication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::eMBMSSessionStatusIndication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "eMBMSSessionStatusIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(65 /* eMBMSSessionStatusIndication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "eMBMSSessionStatusIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_responsePsNetworkStateChangeInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::responsePsNetworkStateChangeInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responsePsNetworkStateChangeInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(66 /* responsePsNetworkStateChangeInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responsePsNetworkStateChangeInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_responseInvalidSimInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::responseInvalidSimInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseInvalidSimInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(67 /* responseInvalidSimInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseInvalidSimInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_responseNetworkEventInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::responseNetworkEventInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseNetworkEventInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(68 /* responseNetworkEventInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseNetworkEventInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_responseModulationInfoInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::responseModulationInfoInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseModulationInfoInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(69 /* responseModulationInfoInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseModulationInfoInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_dataAllowedNotification(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::dataAllowedNotification::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dataAllowedNotification", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(70 /* dataAllowedNotification */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dataAllowedNotification", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onPseudoCellInfoInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onPseudoCellInfoInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onPseudoCellInfoInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(71 /* onPseudoCellInfoInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onPseudoCellInfoInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_plmnChangedIndication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::plmnChangedIndication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "plmnChangedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(72 /* plmnChangedIndication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "plmnChangedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_registrationSuspendedIndication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::registrationSuspendedIndication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "registrationSuspendedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(73 /* registrationSuspendedIndication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "registrationSuspendedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_gmssRatChangedIndication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::gmssRatChangedIndication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "gmssRatChangedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(74 /* gmssRatChangedIndication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "gmssRatChangedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_worldModeChangedIndication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::worldModeChangedIndication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "worldModeChangedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(75 /* worldModeChangedIndication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "worldModeChangedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_resetAttachApnInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::resetAttachApnInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "resetAttachApnInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(76 /* resetAttachApnInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "resetAttachApnInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_mdChangedApnInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::mdChangedApnInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "mdChangedApnInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(77 /* mdChangedApnInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "mdChangedApnInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_esnMeidChangeInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::esnMeidChangeInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "esnMeidChangeInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(78 /* esnMeidChangeInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "esnMeidChangeInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_responseFemtocellInfo(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::responseFemtocellInfo::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseFemtocellInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(79 /* responseFemtocellInfo */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseFemtocellInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_phbReadyNotification(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::phbReadyNotification::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "phbReadyNotification", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(80 /* phbReadyNotification */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "phbReadyNotification", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_bipProactiveCommand(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::bipProactiveCommand::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "bipProactiveCommand", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(81 /* bipProactiveCommand */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "bipProactiveCommand", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_triggerOtaSP(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::triggerOtaSP::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "triggerOtaSP", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(82 /* triggerOtaSP */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "triggerOtaSP", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onStkMenuReset(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onStkMenuReset::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onStkMenuReset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(83 /* onStkMenuReset */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onStkMenuReset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onMdDataRetryCountReset(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onMdDataRetryCountReset::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onMdDataRetryCountReset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(84 /* onMdDataRetryCountReset */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onMdDataRetryCountReset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onRemoveRestrictEutran(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onRemoveRestrictEutran::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onRemoveRestrictEutran", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(85 /* onRemoveRestrictEutran */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onRemoveRestrictEutran", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onPcoStatus(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onPcoStatus::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onPcoStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(86 /* onPcoStatus */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onPcoStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onLteAccessStratumStateChanged(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onLteAccessStratumStateChanged::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onLteAccessStratumStateChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(87 /* onLteAccessStratumStateChanged */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onLteAccessStratumStateChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onSimPlugIn(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onSimPlugIn::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimPlugIn", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(88 /* onSimPlugIn */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimPlugIn", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onSimPlugOut(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onSimPlugOut::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimPlugOut", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(89 /* onSimPlugOut */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimPlugOut", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onSimMissing(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onSimMissing::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimMissing", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(90 /* onSimMissing */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimMissing", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onSimRecovery(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onSimRecovery::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimRecovery", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(91 /* onSimRecovery */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimRecovery", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onSimTrayPlugIn(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onSimTrayPlugIn::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimTrayPlugIn", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(92 /* onSimTrayPlugIn */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimTrayPlugIn", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onSimCommonSlotNoChanged(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onSimCommonSlotNoChanged::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimCommonSlotNoChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(93 /* onSimCommonSlotNoChanged */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimCommonSlotNoChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onSimMeLockEvent(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onSimMeLockEvent::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimMeLockEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(94 /* onSimMeLockEvent */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimMeLockEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_networkInfoInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::networkInfoInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "networkInfoInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(95 /* networkInfoInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "networkInfoInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_cfuStatusNotify(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::cfuStatusNotify::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "cfuStatusNotify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(96 /* cfuStatusNotify */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "cfuStatusNotify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_pcoDataAfterAttached(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::pcoDataAfterAttached::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "pcoDataAfterAttached", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(97 /* pcoDataAfterAttached */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "pcoDataAfterAttached", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_confSRVCC(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::confSRVCC::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "confSRVCC", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(98 /* confSRVCC */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "confSRVCC", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onVsimEventIndication(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onVsimEventIndication::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onVsimEventIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(99 /* onVsimEventIndication */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onVsimEventIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_volteLteConnectionStatus(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::volteLteConnectionStatus::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "volteLteConnectionStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(100 /* volteLteConnectionStatus */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "volteLteConnectionStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_dedicatedBearerActivationInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::dedicatedBearerActivationInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dedicatedBearerActivationInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(101 /* dedicatedBearerActivationInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dedicatedBearerActivationInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_dedicatedBearerModificationInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::dedicatedBearerModificationInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dedicatedBearerModificationInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(102 /* dedicatedBearerModificationInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dedicatedBearerModificationInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_dedicatedBearerDeactivationInd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::dedicatedBearerDeactivationInd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dedicatedBearerDeactivationInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(103 /* dedicatedBearerDeactivationInd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dedicatedBearerDeactivationInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onWifiMonitoringThreshouldChanged(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onWifiMonitoringThreshouldChanged::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWifiMonitoringThreshouldChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(104 /* onWifiMonitoringThreshouldChanged */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWifiMonitoringThreshouldChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onWifiPdnActivate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onWifiPdnActivate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWifiPdnActivate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(105 /* onWifiPdnActivate */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWifiPdnActivate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onWfcPdnError(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onWfcPdnError::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWfcPdnError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(106 /* onWfcPdnError */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWfcPdnError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onPdnHandover(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onPdnHandover::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onPdnHandover", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(107 /* onPdnHandover */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onPdnHandover", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onWifiRoveout(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onWifiRoveout::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWifiRoveout", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(108 /* onWifiRoveout */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWifiRoveout", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onLocationRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onLocationRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onLocationRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(109 /* onLocationRequest */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onLocationRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onWfcPdnStateChanged(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onWfcPdnStateChanged::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWfcPdnStateChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(110 /* onWfcPdnStateChanged */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWfcPdnStateChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_onNattKeepAliveChanged(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::onNattKeepAliveChanged::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onNattKeepAliveChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(111 /* onNattKeepAliveChanged */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onNattKeepAliveChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioIndication::_hidl_oemHookRaw(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioIndication::oemHookRaw::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "oemHookRaw", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioIndication::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(112 /* oemHookRaw */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "oemHookRaw", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::radio::V1_0::IRadioIndication follow.
::android::hardware::Return<void> BpHwRadioIndication::radioStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::RadioState radioState){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_radioStateChanged(this, this, type, radioState);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::callStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_callStateChanged(this, this, type);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::networkStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_networkStateChanged(this, this, type);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::newSms(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<uint8_t>& pdu){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_newSms(this, this, type, pdu);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::newSmsStatusReport(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<uint8_t>& pdu){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_newSmsStatusReport(this, this, type, pdu);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::newSmsOnSim(::android::hardware::radio::V1_0::RadioIndicationType type, int32_t recordNumber){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_newSmsOnSim(this, this, type, recordNumber);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onUssd(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::UssdModeType modeType, const ::android::hardware::hidl_string& msg){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_onUssd(this, this, type, modeType, msg);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::nitzTimeReceived(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& nitzTime, uint64_t receivedTime){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_nitzTimeReceived(this, this, type, nitzTime, receivedTime);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::currentSignalStrength(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::SignalStrength& signalStrength){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_currentSignalStrength(this, this, type, signalStrength);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::dataCallListChanged(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::SetupDataCallResult>& dcList){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_dataCallListChanged(this, this, type, dcList);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::suppSvcNotify(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::SuppSvcNotification& suppSvc){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_suppSvcNotify(this, this, type, suppSvc);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::stkSessionEnd(::android::hardware::radio::V1_0::RadioIndicationType type){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_stkSessionEnd(this, this, type);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::stkProactiveCommand(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& cmd){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_stkProactiveCommand(this, this, type, cmd);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::stkEventNotify(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& cmd){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_stkEventNotify(this, this, type, cmd);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::stkCallSetup(::android::hardware::radio::V1_0::RadioIndicationType type, int64_t timeout){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_stkCallSetup(this, this, type, timeout);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::simSmsStorageFull(::android::hardware::radio::V1_0::RadioIndicationType type){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_simSmsStorageFull(this, this, type);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::simRefresh(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::SimRefreshResult& refreshResult){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_simRefresh(this, this, type, refreshResult);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::callRing(::android::hardware::radio::V1_0::RadioIndicationType type, bool isGsm, const ::android::hardware::radio::V1_0::CdmaSignalInfoRecord& record){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_callRing(this, this, type, isGsm, record);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::simStatusChanged(::android::hardware::radio::V1_0::RadioIndicationType type){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_simStatusChanged(this, this, type);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::cdmaNewSms(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::CdmaSmsMessage& msg){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_cdmaNewSms(this, this, type, msg);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::newBroadcastSms(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<uint8_t>& data){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_newBroadcastSms(this, this, type, data);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::cdmaRuimSmsStorageFull(::android::hardware::radio::V1_0::RadioIndicationType type){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_cdmaRuimSmsStorageFull(this, this, type);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::restrictedStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::PhoneRestrictedState state){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_restrictedStateChanged(this, this, type, state);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::enterEmergencyCallbackMode(::android::hardware::radio::V1_0::RadioIndicationType type){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_enterEmergencyCallbackMode(this, this, type);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::cdmaCallWaiting(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::CdmaCallWaiting& callWaitingRecord){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_cdmaCallWaiting(this, this, type, callWaitingRecord);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::cdmaOtaProvisionStatus(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::CdmaOtaProvisionStatus status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_cdmaOtaProvisionStatus(this, this, type, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::cdmaInfoRec(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::CdmaInformationRecords& records){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_cdmaInfoRec(this, this, type, records);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::indicateRingbackTone(::android::hardware::radio::V1_0::RadioIndicationType type, bool start){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_indicateRingbackTone(this, this, type, start);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::resendIncallMute(::android::hardware::radio::V1_0::RadioIndicationType type){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_resendIncallMute(this, this, type);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::cdmaSubscriptionSourceChanged(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::CdmaSubscriptionSource cdmaSource){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_cdmaSubscriptionSourceChanged(this, this, type, cdmaSource);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::cdmaPrlChanged(::android::hardware::radio::V1_0::RadioIndicationType type, int32_t version){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_cdmaPrlChanged(this, this, type, version);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::exitEmergencyCallbackMode(::android::hardware::radio::V1_0::RadioIndicationType type){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_exitEmergencyCallbackMode(this, this, type);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::rilConnected(::android::hardware::radio::V1_0::RadioIndicationType type){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_rilConnected(this, this, type);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::voiceRadioTechChanged(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::RadioTechnology rat){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_voiceRadioTechChanged(this, this, type, rat);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::cellInfoList(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfo>& records){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_cellInfoList(this, this, type, records);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::imsNetworkStateChanged(::android::hardware::radio::V1_0::RadioIndicationType type){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_imsNetworkStateChanged(this, this, type);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::subscriptionStatusChanged(::android::hardware::radio::V1_0::RadioIndicationType type, bool activate){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_subscriptionStatusChanged(this, this, type, activate);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::srvccStateNotify(::android::hardware::radio::V1_0::RadioIndicationType type, ::android::hardware::radio::V1_0::SrvccState state){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_srvccStateNotify(this, this, type, state);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::hardwareConfigChanged(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_0::HardwareConfig>& configs){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_hardwareConfigChanged(this, this, type, configs);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::radioCapabilityIndication(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::RadioCapability& rc){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_radioCapabilityIndication(this, this, type, rc);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onSupplementaryServiceIndication(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::StkCcUnsolSsResult& ss){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_onSupplementaryServiceIndication(this, this, type, ss);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::stkCallControlAlphaNotify(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& alpha){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_stkCallControlAlphaNotify(this, this, type, alpha);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::lceData(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::LceDataInfo& lce){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_lceData(this, this, type, lce);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::pcoData(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_0::PcoDataInfo& pco){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_pcoData(this, this, type, pco);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::modemReset(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_string& reason){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwRadioIndication::_hidl_modemReset(this, this, type, reason);

    return _hidl_out;
}


// Methods from ::android::hardware::radio::V1_1::IRadioIndication follow.
::android::hardware::Return<void> BpHwRadioIndication::carrierInfoForImsiEncryption(::android::hardware::radio::V1_0::RadioIndicationType info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadioIndication::_hidl_carrierInfoForImsiEncryption(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::networkScanResult(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_1::NetworkScanResult& result){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadioIndication::_hidl_networkScanResult(this, this, type, result);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::keepaliveStatus(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_1::KeepaliveStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_1::BpHwRadioIndication::_hidl_keepaliveStatus(this, this, type, status);

    return _hidl_out;
}


// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadioIndication follow.
::android::hardware::Return<void> BpHwRadioIndication::incomingCallIndication(::android::hardware::radio::V1_0::RadioIndicationType type, const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& notification){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_incomingCallIndication(this, this, type, notification);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::cipherIndication(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_cipherIndication(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::crssIndication(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_crssIndication(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::vtStatusInfoIndication(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_vtStatusInfoIndication(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::speechCodecInfoIndication(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_speechCodecInfoIndication(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::cdmaCallAccepted(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_cdmaCallAccepted(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onVirtualSimOn(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onVirtualSimOn(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onVirtualSimOff(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onVirtualSimOff(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onImeiLock(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onImeiLock(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onImsiRefreshDone(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onImsiRefreshDone(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::newEtwsInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_newEtwsInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::meSmsStorageFullInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_meSmsStorageFullInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::smsReadyInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_smsReadyInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::dataCallListChangedEx(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult>& dcResponse){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_dataCallListChangedEx(this, this, type, dcResponse);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::responseCsNetworkStateChangeInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_responseCsNetworkStateChangeInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::eMBMSAtInfoIndication(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_eMBMSAtInfoIndication(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::eMBMSSessionStatusIndication(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_eMBMSSessionStatusIndication(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::responsePsNetworkStateChangeInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_responsePsNetworkStateChangeInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::responseInvalidSimInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_responseInvalidSimInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::responseNetworkEventInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_responseNetworkEventInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::responseModulationInfoInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_responseModulationInfoInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::dataAllowedNotification(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_dataAllowedNotification(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onPseudoCellInfoInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onPseudoCellInfoInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::plmnChangedIndication(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_plmnChangedIndication(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::registrationSuspendedIndication(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_registrationSuspendedIndication(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::gmssRatChangedIndication(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_gmssRatChangedIndication(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::worldModeChangedIndication(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_worldModeChangedIndication(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::resetAttachApnInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_resetAttachApnInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::mdChangedApnInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_mdChangedApnInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::esnMeidChangeInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_esnMeidChangeInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::responseFemtocellInfo(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_responseFemtocellInfo(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::phbReadyNotification(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_phbReadyNotification(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::bipProactiveCommand(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_bipProactiveCommand(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::triggerOtaSP(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_triggerOtaSP(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onStkMenuReset(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onStkMenuReset(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onMdDataRetryCountReset(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onMdDataRetryCountReset(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onRemoveRestrictEutran(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onRemoveRestrictEutran(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onPcoStatus(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onPcoStatus(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onLteAccessStratumStateChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onLteAccessStratumStateChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onSimPlugIn(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onSimPlugIn(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onSimPlugOut(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onSimPlugOut(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onSimMissing(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onSimMissing(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onSimRecovery(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onSimRecovery(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onSimTrayPlugIn(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onSimTrayPlugIn(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onSimCommonSlotNoChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onSimCommonSlotNoChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onSimMeLockEvent(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onSimMeLockEvent(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::networkInfoInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_networkInfoInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::cfuStatusNotify(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_cfuStatusNotify(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::pcoDataAfterAttached(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_pcoDataAfterAttached(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::confSRVCC(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_confSRVCC(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onVsimEventIndication(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onVsimEventIndication(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::volteLteConnectionStatus(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_volteLteConnectionStatus(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::dedicatedBearerActivationInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_dedicatedBearerActivationInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::dedicatedBearerModificationInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_dedicatedBearerModificationInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::dedicatedBearerDeactivationInd(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_dedicatedBearerDeactivationInd(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onWifiMonitoringThreshouldChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onWifiMonitoringThreshouldChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onWifiPdnActivate(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onWifiPdnActivate(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onWfcPdnError(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onWfcPdnError(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onPdnHandover(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onPdnHandover(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onWifiRoveout(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onWifiRoveout(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onLocationRequest(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onLocationRequest(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onWfcPdnStateChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onWfcPdnStateChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::onNattKeepAliveChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_onNattKeepAliveChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::oemHookRaw(){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::mediatek::hardware::radio::V2_0::BpHwRadioIndication::_hidl_oemHookRaw(this, this);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwRadioIndication::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwRadioIndication::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwRadioIndication::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwRadioIndication::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwRadioIndication::BnHwRadioIndication(const ::android::sp<IRadioIndication> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "vendor.mediatek.hardware.radio@2.0", "IRadioIndication") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwRadioIndication::~BnHwRadioIndication() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadioIndication follow.
::android::status_t BnHwRadioIndication::_hidl_incomingCallIndication(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioIndicationType type;
    ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification* notification;

    _hidl_err = _hidl_data.readInt32((int32_t *)&type);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_notification_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*notification), &_hidl_notification_parent,  const_cast<const void**>(reinterpret_cast<void **>(&notification)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification &>(*notification),
            _hidl_data,
            _hidl_notification_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::incomingCallIndication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)notification);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "incomingCallIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->incomingCallIndication(type, *notification);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "incomingCallIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_cipherIndication(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::cipherIndication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "cipherIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->cipherIndication();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "cipherIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_crssIndication(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::crssIndication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "crssIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->crssIndication();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "crssIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_vtStatusInfoIndication(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::vtStatusInfoIndication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "vtStatusInfoIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->vtStatusInfoIndication();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "vtStatusInfoIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_speechCodecInfoIndication(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::speechCodecInfoIndication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "speechCodecInfoIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->speechCodecInfoIndication();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "speechCodecInfoIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_cdmaCallAccepted(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::cdmaCallAccepted::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "cdmaCallAccepted", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->cdmaCallAccepted();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "cdmaCallAccepted", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onVirtualSimOn(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onVirtualSimOn::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onVirtualSimOn", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onVirtualSimOn();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onVirtualSimOn", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onVirtualSimOff(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onVirtualSimOff::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onVirtualSimOff", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onVirtualSimOff();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onVirtualSimOff", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onImeiLock(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onImeiLock::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onImeiLock", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onImeiLock();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onImeiLock", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onImsiRefreshDone(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onImsiRefreshDone::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onImsiRefreshDone", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onImsiRefreshDone();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onImsiRefreshDone", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_newEtwsInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::newEtwsInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "newEtwsInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->newEtwsInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "newEtwsInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_meSmsStorageFullInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::meSmsStorageFullInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "meSmsStorageFullInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->meSmsStorageFullInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "meSmsStorageFullInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_smsReadyInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::smsReadyInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "smsReadyInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->smsReadyInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "smsReadyInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_dataCallListChangedEx(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioIndicationType type;
    const ::android::hardware::hidl_vec<::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult>* dcResponse;

    _hidl_err = _hidl_data.readInt32((int32_t *)&type);
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::dataCallListChangedEx::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)dcResponse);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dataCallListChangedEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->dataCallListChangedEx(type, *dcResponse);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dataCallListChangedEx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_responseCsNetworkStateChangeInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::responseCsNetworkStateChangeInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseCsNetworkStateChangeInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->responseCsNetworkStateChangeInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseCsNetworkStateChangeInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_eMBMSAtInfoIndication(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::eMBMSAtInfoIndication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "eMBMSAtInfoIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->eMBMSAtInfoIndication();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "eMBMSAtInfoIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_eMBMSSessionStatusIndication(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::eMBMSSessionStatusIndication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "eMBMSSessionStatusIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->eMBMSSessionStatusIndication();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "eMBMSSessionStatusIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_responsePsNetworkStateChangeInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::responsePsNetworkStateChangeInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responsePsNetworkStateChangeInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->responsePsNetworkStateChangeInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responsePsNetworkStateChangeInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_responseInvalidSimInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::responseInvalidSimInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseInvalidSimInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->responseInvalidSimInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseInvalidSimInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_responseNetworkEventInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::responseNetworkEventInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseNetworkEventInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->responseNetworkEventInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseNetworkEventInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_responseModulationInfoInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::responseModulationInfoInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseModulationInfoInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->responseModulationInfoInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseModulationInfoInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_dataAllowedNotification(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::dataAllowedNotification::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dataAllowedNotification", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->dataAllowedNotification();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dataAllowedNotification", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onPseudoCellInfoInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onPseudoCellInfoInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onPseudoCellInfoInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onPseudoCellInfoInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onPseudoCellInfoInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_plmnChangedIndication(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::plmnChangedIndication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "plmnChangedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->plmnChangedIndication();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "plmnChangedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_registrationSuspendedIndication(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::registrationSuspendedIndication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "registrationSuspendedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->registrationSuspendedIndication();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "registrationSuspendedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_gmssRatChangedIndication(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::gmssRatChangedIndication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "gmssRatChangedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->gmssRatChangedIndication();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "gmssRatChangedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_worldModeChangedIndication(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::worldModeChangedIndication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "worldModeChangedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->worldModeChangedIndication();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "worldModeChangedIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_resetAttachApnInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::resetAttachApnInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "resetAttachApnInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->resetAttachApnInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "resetAttachApnInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_mdChangedApnInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::mdChangedApnInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "mdChangedApnInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->mdChangedApnInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "mdChangedApnInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_esnMeidChangeInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::esnMeidChangeInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "esnMeidChangeInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->esnMeidChangeInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "esnMeidChangeInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_responseFemtocellInfo(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::responseFemtocellInfo::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseFemtocellInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->responseFemtocellInfo();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "responseFemtocellInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_phbReadyNotification(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::phbReadyNotification::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "phbReadyNotification", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->phbReadyNotification();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "phbReadyNotification", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_bipProactiveCommand(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::bipProactiveCommand::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "bipProactiveCommand", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->bipProactiveCommand();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "bipProactiveCommand", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_triggerOtaSP(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::triggerOtaSP::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "triggerOtaSP", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->triggerOtaSP();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "triggerOtaSP", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onStkMenuReset(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onStkMenuReset::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onStkMenuReset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onStkMenuReset();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onStkMenuReset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onMdDataRetryCountReset(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onMdDataRetryCountReset::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onMdDataRetryCountReset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onMdDataRetryCountReset();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onMdDataRetryCountReset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onRemoveRestrictEutran(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onRemoveRestrictEutran::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onRemoveRestrictEutran", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onRemoveRestrictEutran();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onRemoveRestrictEutran", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onPcoStatus(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onPcoStatus::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onPcoStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onPcoStatus();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onPcoStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onLteAccessStratumStateChanged(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onLteAccessStratumStateChanged::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onLteAccessStratumStateChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onLteAccessStratumStateChanged();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onLteAccessStratumStateChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onSimPlugIn(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onSimPlugIn::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimPlugIn", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onSimPlugIn();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimPlugIn", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onSimPlugOut(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onSimPlugOut::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimPlugOut", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onSimPlugOut();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimPlugOut", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onSimMissing(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onSimMissing::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimMissing", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onSimMissing();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimMissing", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onSimRecovery(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onSimRecovery::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimRecovery", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onSimRecovery();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimRecovery", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onSimTrayPlugIn(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onSimTrayPlugIn::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimTrayPlugIn", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onSimTrayPlugIn();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimTrayPlugIn", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onSimCommonSlotNoChanged(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onSimCommonSlotNoChanged::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimCommonSlotNoChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onSimCommonSlotNoChanged();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimCommonSlotNoChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onSimMeLockEvent(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onSimMeLockEvent::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimMeLockEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onSimMeLockEvent();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onSimMeLockEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_networkInfoInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::networkInfoInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "networkInfoInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->networkInfoInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "networkInfoInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_cfuStatusNotify(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::cfuStatusNotify::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "cfuStatusNotify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->cfuStatusNotify();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "cfuStatusNotify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_pcoDataAfterAttached(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::pcoDataAfterAttached::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "pcoDataAfterAttached", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->pcoDataAfterAttached();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "pcoDataAfterAttached", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_confSRVCC(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::confSRVCC::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "confSRVCC", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->confSRVCC();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "confSRVCC", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onVsimEventIndication(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onVsimEventIndication::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onVsimEventIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onVsimEventIndication();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onVsimEventIndication", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_volteLteConnectionStatus(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::volteLteConnectionStatus::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "volteLteConnectionStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->volteLteConnectionStatus();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "volteLteConnectionStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_dedicatedBearerActivationInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::dedicatedBearerActivationInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dedicatedBearerActivationInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->dedicatedBearerActivationInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dedicatedBearerActivationInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_dedicatedBearerModificationInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::dedicatedBearerModificationInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dedicatedBearerModificationInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->dedicatedBearerModificationInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dedicatedBearerModificationInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_dedicatedBearerDeactivationInd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::dedicatedBearerDeactivationInd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dedicatedBearerDeactivationInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->dedicatedBearerDeactivationInd();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "dedicatedBearerDeactivationInd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onWifiMonitoringThreshouldChanged(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onWifiMonitoringThreshouldChanged::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWifiMonitoringThreshouldChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onWifiMonitoringThreshouldChanged();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWifiMonitoringThreshouldChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onWifiPdnActivate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onWifiPdnActivate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWifiPdnActivate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onWifiPdnActivate();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWifiPdnActivate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onWfcPdnError(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onWfcPdnError::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWfcPdnError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onWfcPdnError();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWfcPdnError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onPdnHandover(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onPdnHandover::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onPdnHandover", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onPdnHandover();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onPdnHandover", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onWifiRoveout(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onWifiRoveout::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWifiRoveout", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onWifiRoveout();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWifiRoveout", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onLocationRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onLocationRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onLocationRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onLocationRequest();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onLocationRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onWfcPdnStateChanged(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onWfcPdnStateChanged::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWfcPdnStateChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onWfcPdnStateChanged();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onWfcPdnStateChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_onNattKeepAliveChanged(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::onNattKeepAliveChanged::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onNattKeepAliveChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->onNattKeepAliveChanged();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "onNattKeepAliveChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioIndication::_hidl_oemHookRaw(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioIndication::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioIndication::oemHookRaw::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "oemHookRaw", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioIndication*>(_hidl_this->getImpl().get())->oemHookRaw();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.mediatek.hardware.radio", "2.0", "IRadioIndication", "oemHookRaw", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::radio::V1_0::IRadioIndication follow.

// Methods from ::android::hardware::radio::V1_1::IRadioIndication follow.

// Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadioIndication follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwRadioIndication::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwRadioIndication::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwRadioIndication::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* radioStateChanged */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_radioStateChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* callStateChanged */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_callStateChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* networkStateChanged */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_networkStateChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* newSms */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_newSms(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* newSmsStatusReport */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_newSmsStatusReport(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* newSmsOnSim */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_newSmsOnSim(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* onUssd */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_onUssd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* nitzTimeReceived */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_nitzTimeReceived(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* currentSignalStrength */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_currentSignalStrength(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* dataCallListChanged */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_dataCallListChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* suppSvcNotify */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_suppSvcNotify(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* stkSessionEnd */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_stkSessionEnd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* stkProactiveCommand */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_stkProactiveCommand(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* stkEventNotify */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_stkEventNotify(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* stkCallSetup */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_stkCallSetup(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* simSmsStorageFull */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_simSmsStorageFull(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* simRefresh */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_simRefresh(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* callRing */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_callRing(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 19 /* simStatusChanged */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_simStatusChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 20 /* cdmaNewSms */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_cdmaNewSms(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 21 /* newBroadcastSms */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_newBroadcastSms(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 22 /* cdmaRuimSmsStorageFull */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_cdmaRuimSmsStorageFull(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 23 /* restrictedStateChanged */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_restrictedStateChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 24 /* enterEmergencyCallbackMode */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_enterEmergencyCallbackMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 25 /* cdmaCallWaiting */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_cdmaCallWaiting(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 26 /* cdmaOtaProvisionStatus */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_cdmaOtaProvisionStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 27 /* cdmaInfoRec */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_cdmaInfoRec(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 28 /* indicateRingbackTone */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_indicateRingbackTone(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 29 /* resendIncallMute */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_resendIncallMute(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 30 /* cdmaSubscriptionSourceChanged */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_cdmaSubscriptionSourceChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 31 /* cdmaPrlChanged */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_cdmaPrlChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 32 /* exitEmergencyCallbackMode */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_exitEmergencyCallbackMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 33 /* rilConnected */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_rilConnected(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 34 /* voiceRadioTechChanged */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_voiceRadioTechChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 35 /* cellInfoList */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_cellInfoList(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 36 /* imsNetworkStateChanged */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_imsNetworkStateChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 37 /* subscriptionStatusChanged */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_subscriptionStatusChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 38 /* srvccStateNotify */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_srvccStateNotify(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 39 /* hardwareConfigChanged */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_hardwareConfigChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 40 /* radioCapabilityIndication */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_radioCapabilityIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 41 /* onSupplementaryServiceIndication */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_onSupplementaryServiceIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 42 /* stkCallControlAlphaNotify */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_stkCallControlAlphaNotify(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 43 /* lceData */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_lceData(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 44 /* pcoData */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_pcoData(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 45 /* modemReset */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwRadioIndication::_hidl_modemReset(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 46 /* carrierInfoForImsiEncryption */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadioIndication::_hidl_carrierInfoForImsiEncryption(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 47 /* networkScanResult */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadioIndication::_hidl_networkScanResult(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 48 /* keepaliveStatus */:
        {
            _hidl_err = ::android::hardware::radio::V1_1::BnHwRadioIndication::_hidl_keepaliveStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 49 /* incomingCallIndication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_incomingCallIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 50 /* cipherIndication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_cipherIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 51 /* crssIndication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_crssIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 52 /* vtStatusInfoIndication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_vtStatusInfoIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 53 /* speechCodecInfoIndication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_speechCodecInfoIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 54 /* cdmaCallAccepted */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_cdmaCallAccepted(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 55 /* onVirtualSimOn */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onVirtualSimOn(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 56 /* onVirtualSimOff */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onVirtualSimOff(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 57 /* onImeiLock */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onImeiLock(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 58 /* onImsiRefreshDone */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onImsiRefreshDone(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 59 /* newEtwsInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_newEtwsInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 60 /* meSmsStorageFullInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_meSmsStorageFullInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 61 /* smsReadyInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_smsReadyInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 62 /* dataCallListChangedEx */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_dataCallListChangedEx(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 63 /* responseCsNetworkStateChangeInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_responseCsNetworkStateChangeInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 64 /* eMBMSAtInfoIndication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_eMBMSAtInfoIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 65 /* eMBMSSessionStatusIndication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_eMBMSSessionStatusIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 66 /* responsePsNetworkStateChangeInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_responsePsNetworkStateChangeInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 67 /* responseInvalidSimInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_responseInvalidSimInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 68 /* responseNetworkEventInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_responseNetworkEventInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 69 /* responseModulationInfoInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_responseModulationInfoInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 70 /* dataAllowedNotification */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_dataAllowedNotification(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 71 /* onPseudoCellInfoInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onPseudoCellInfoInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 72 /* plmnChangedIndication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_plmnChangedIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 73 /* registrationSuspendedIndication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_registrationSuspendedIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 74 /* gmssRatChangedIndication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_gmssRatChangedIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 75 /* worldModeChangedIndication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_worldModeChangedIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 76 /* resetAttachApnInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_resetAttachApnInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 77 /* mdChangedApnInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_mdChangedApnInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 78 /* esnMeidChangeInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_esnMeidChangeInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 79 /* responseFemtocellInfo */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_responseFemtocellInfo(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 80 /* phbReadyNotification */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_phbReadyNotification(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 81 /* bipProactiveCommand */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_bipProactiveCommand(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 82 /* triggerOtaSP */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_triggerOtaSP(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 83 /* onStkMenuReset */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onStkMenuReset(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 84 /* onMdDataRetryCountReset */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onMdDataRetryCountReset(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 85 /* onRemoveRestrictEutran */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onRemoveRestrictEutran(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 86 /* onPcoStatus */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onPcoStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 87 /* onLteAccessStratumStateChanged */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onLteAccessStratumStateChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 88 /* onSimPlugIn */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onSimPlugIn(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 89 /* onSimPlugOut */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onSimPlugOut(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 90 /* onSimMissing */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onSimMissing(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 91 /* onSimRecovery */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onSimRecovery(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 92 /* onSimTrayPlugIn */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onSimTrayPlugIn(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 93 /* onSimCommonSlotNoChanged */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onSimCommonSlotNoChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 94 /* onSimMeLockEvent */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onSimMeLockEvent(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 95 /* networkInfoInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_networkInfoInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 96 /* cfuStatusNotify */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_cfuStatusNotify(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 97 /* pcoDataAfterAttached */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_pcoDataAfterAttached(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 98 /* confSRVCC */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_confSRVCC(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 99 /* onVsimEventIndication */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onVsimEventIndication(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 100 /* volteLteConnectionStatus */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_volteLteConnectionStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 101 /* dedicatedBearerActivationInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_dedicatedBearerActivationInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 102 /* dedicatedBearerModificationInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_dedicatedBearerModificationInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 103 /* dedicatedBearerDeactivationInd */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_dedicatedBearerDeactivationInd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 104 /* onWifiMonitoringThreshouldChanged */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onWifiMonitoringThreshouldChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 105 /* onWifiPdnActivate */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onWifiPdnActivate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 106 /* onWfcPdnError */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onWfcPdnError(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 107 /* onPdnHandover */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onPdnHandover(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 108 /* onWifiRoveout */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onWifiRoveout(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 109 /* onLocationRequest */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onLocationRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 110 /* onWfcPdnStateChanged */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onWfcPdnStateChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 111 /* onNattKeepAliveChanged */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_onNattKeepAliveChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 112 /* oemHookRaw */:
        {
            _hidl_err = ::vendor::mediatek::hardware::radio::V2_0::BnHwRadioIndication::_hidl_oemHookRaw(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsRadioIndication::BsRadioIndication(const ::android::sp<::vendor::mediatek::hardware::radio::V2_0::IRadioIndication> impl) : ::android::hardware::details::HidlInstrumentor("vendor.mediatek.hardware.radio@2.0", "IRadioIndication"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsRadioIndication::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IRadioIndication> IRadioIndication::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwRadioIndication>(serviceName, false, getStub);
}

::android::sp<IRadioIndication> IRadioIndication::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwRadioIndication>(serviceName, true, getStub);
}

::android::status_t IRadioIndication::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IRadioIndication::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("vendor.mediatek.hardware.radio@2.0::IRadioIndication",
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
