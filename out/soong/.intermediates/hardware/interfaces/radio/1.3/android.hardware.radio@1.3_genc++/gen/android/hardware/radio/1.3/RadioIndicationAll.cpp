#define LOG_TAG "android.hardware.radio@1.3::RadioIndication"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/radio/1.3/BpHwRadioIndication.h>
#include <android/hardware/radio/1.3/BnHwRadioIndication.h>
#include <android/hardware/radio/1.3/BsRadioIndication.h>
#include <android/hardware/radio/1.2/BpHwRadioIndication.h>
#include <android/hardware/radio/1.1/BpHwRadioIndication.h>
#include <android/hardware/radio/1.0/BpHwRadioIndication.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace radio {
namespace V1_3 {

const char* IRadioIndication::descriptor("android.hardware.radio@1.3::IRadioIndication");

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

// Methods from ::android::hardware::radio::V1_2::IRadioIndication follow.
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::networkScanResult_1_2(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_2::NetworkScanResult& result)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::cellInfoList_1_2(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellInfo>& records)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::currentLinkCapacityEstimate(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_2::LinkCapacityEstimate& lce)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::currentPhysicalChannelConfigs(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_2::PhysicalChannelConfig>& configs)
// no default implementation for: ::android::hardware::Return<void> IRadioIndication::currentSignalStrength_1_2(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_2::SignalStrength& signalStrength)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IRadioIndication::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::radio::V1_3::IRadioIndication::descriptor,
        ::android::hardware::radio::V1_2::IRadioIndication::descriptor,
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
    _hidl_cb(::android::hardware::radio::V1_3::IRadioIndication::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioIndication::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){233,208,241,26,82,113,95,90,41,216,158,45,142,46,33,219,30,22,164,49,116,175,107,157,81,166,45,112,92,218,20,85} /* e9d0f11a52715f5a29d89e2d8e2e21db1e16a43174af6b9d51a62d705cda1455 */,
        (uint8_t[32]){205,167,82,174,171,170,188,32,72,106,130,172,87,163,221,16,119,133,192,6,9,74,52,155,197,226,36,232,170,34,161,124} /* cda752aeabaabc20486a82ac57a3dd107785c006094a349bc5e224e8aa22a17c */,
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


::android::hardware::Return<::android::sp<::android::hardware::radio::V1_3::IRadioIndication>> IRadioIndication::castFrom(const ::android::sp<::android::hardware::radio::V1_3::IRadioIndication>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::radio::V1_3::IRadioIndication>> IRadioIndication::castFrom(const ::android::sp<::android::hardware::radio::V1_2::IRadioIndication>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioIndication, ::android::hardware::radio::V1_2::IRadioIndication, BpHwRadioIndication>(
            parent, "android.hardware.radio@1.3::IRadioIndication", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::radio::V1_3::IRadioIndication>> IRadioIndication::castFrom(const ::android::sp<::android::hardware::radio::V1_1::IRadioIndication>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioIndication, ::android::hardware::radio::V1_1::IRadioIndication, BpHwRadioIndication>(
            parent, "android.hardware.radio@1.3::IRadioIndication", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::radio::V1_3::IRadioIndication>> IRadioIndication::castFrom(const ::android::sp<::android::hardware::radio::V1_0::IRadioIndication>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioIndication, ::android::hardware::radio::V1_0::IRadioIndication, BpHwRadioIndication>(
            parent, "android.hardware.radio@1.3::IRadioIndication", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::radio::V1_3::IRadioIndication>> IRadioIndication::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioIndication, ::android::hidl::base::V1_0::IBase, BpHwRadioIndication>(
            parent, "android.hardware.radio@1.3::IRadioIndication", emitError);
}

BpHwRadioIndication::BpHwRadioIndication(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IRadioIndication>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.radio@1.3", "IRadioIndication") {
}

void BpHwRadioIndication::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IRadioIndication>::onLastStrongRef(id);
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


// Methods from ::android::hardware::radio::V1_2::IRadioIndication follow.
::android::hardware::Return<void> BpHwRadioIndication::networkScanResult_1_2(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_2::NetworkScanResult& result){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadioIndication::_hidl_networkScanResult_1_2(this, this, type, result);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::cellInfoList_1_2(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellInfo>& records){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadioIndication::_hidl_cellInfoList_1_2(this, this, type, records);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::currentLinkCapacityEstimate(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_2::LinkCapacityEstimate& lce){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadioIndication::_hidl_currentLinkCapacityEstimate(this, this, type, lce);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::currentPhysicalChannelConfigs(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::hidl_vec<::android::hardware::radio::V1_2::PhysicalChannelConfig>& configs){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadioIndication::_hidl_currentPhysicalChannelConfigs(this, this, type, configs);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioIndication::currentSignalStrength_1_2(::android::hardware::radio::V1_0::RadioIndicationType type, const ::android::hardware::radio::V1_2::SignalStrength& signalStrength){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_2::BpHwRadioIndication::_hidl_currentSignalStrength_1_2(this, this, type, signalStrength);

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
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.radio@1.3", "IRadioIndication") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwRadioIndication::~BnHwRadioIndication() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}


// Methods from ::android::hardware::radio::V1_0::IRadioIndication follow.

// Methods from ::android::hardware::radio::V1_1::IRadioIndication follow.

// Methods from ::android::hardware::radio::V1_2::IRadioIndication follow.

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

        case 49 /* networkScanResult_1_2 */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadioIndication::_hidl_networkScanResult_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 50 /* cellInfoList_1_2 */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadioIndication::_hidl_cellInfoList_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 51 /* currentLinkCapacityEstimate */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadioIndication::_hidl_currentLinkCapacityEstimate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 52 /* currentPhysicalChannelConfigs */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadioIndication::_hidl_currentPhysicalChannelConfigs(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 53 /* currentSignalStrength_1_2 */:
        {
            _hidl_err = ::android::hardware::radio::V1_2::BnHwRadioIndication::_hidl_currentSignalStrength_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsRadioIndication::BsRadioIndication(const ::android::sp<::android::hardware::radio::V1_3::IRadioIndication> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.radio@1.3", "IRadioIndication"), mImpl(impl) {
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
            sm->registerForNotifications("android.hardware.radio@1.3::IRadioIndication",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_3
}  // namespace radio
}  // namespace hardware
}  // namespace android
