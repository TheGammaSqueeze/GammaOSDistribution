#define LOG_TAG "android.hardware.gnss@2.1::GnssCallback"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/gnss/2.1/BpHwGnssCallback.h>
#include <android/hardware/gnss/2.1/BnHwGnssCallback.h>
#include <android/hardware/gnss/2.1/BsGnssCallback.h>
#include <android/hardware/gnss/2.0/BpHwGnssCallback.h>
#include <android/hardware/gnss/1.1/BpHwGnssCallback.h>
#include <android/hardware/gnss/1.0/BpHwGnssCallback.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace gnss {
namespace V2_1 {

const char* IGnssCallback::descriptor("android.hardware.gnss@2.1::IGnssCallback");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IGnssCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwGnssCallback(static_cast<IGnssCallback *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IGnssCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsGnssCallback(static_cast<IGnssCallback *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IGnssCallback::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IGnssCallback::descriptor);
}

// Methods from ::android::hardware::gnss::V1_0::IGnssCallback follow.
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssLocationCb(const ::android::hardware::gnss::V1_0::GnssLocation& location)
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssStatusCb(::android::hardware::gnss::V1_0::IGnssCallback::GnssStatusValue status)
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssSvStatusCb(const ::android::hardware::gnss::V1_0::IGnssCallback::GnssSvStatus& svInfo)
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssNmeaCb(int64_t timestamp, const ::android::hardware::hidl_string& nmea)
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssSetCapabilitesCb(::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssCallback::Capabilities> capabilities)
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssAcquireWakelockCb()
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssReleaseWakelockCb()
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssRequestTimeCb()
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssSetSystemInfoCb(const ::android::hardware::gnss::V1_0::IGnssCallback::GnssSystemInfo& info)

// Methods from ::android::hardware::gnss::V1_1::IGnssCallback follow.
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssNameCb(const ::android::hardware::hidl_string& name)
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssRequestLocationCb(bool independentFromGnss)

// Methods from ::android::hardware::gnss::V2_0::IGnssCallback follow.
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssSetCapabilitiesCb_2_0(::android::hardware::hidl_bitfield<::android::hardware::gnss::V2_0::IGnssCallback::Capabilities> capabilities)
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssLocationCb_2_0(const ::android::hardware::gnss::V2_0::GnssLocation& location)
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssRequestLocationCb_2_0(bool independentFromGnss, bool isUserEmergency)
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssSvStatusCb_2_0(const ::android::hardware::hidl_vec<::android::hardware::gnss::V2_0::IGnssCallback::GnssSvInfo>& svInfoList)

// Methods from ::android::hardware::gnss::V2_1::IGnssCallback follow.
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssSetCapabilitiesCb_2_1(::android::hardware::hidl_bitfield<::android::hardware::gnss::V2_1::IGnssCallback::Capabilities> capabilities)
// no default implementation for: ::android::hardware::Return<void> IGnssCallback::gnssSvStatusCb_2_1(const ::android::hardware::hidl_vec<::android::hardware::gnss::V2_1::IGnssCallback::GnssSvInfo>& svInfoList)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IGnssCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::gnss::V2_1::IGnssCallback::descriptor,
        ::android::hardware::gnss::V2_0::IGnssCallback::descriptor,
        ::android::hardware::gnss::V1_1::IGnssCallback::descriptor,
        ::android::hardware::gnss::V1_0::IGnssCallback::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::gnss::V2_1::IGnssCallback::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssCallback::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){53,65,216,58,223,234,193,110,227,228,93,24,58,88,223,254,6,1,44,203,90,165,188,210,228,246,238,174,38,159,105,205} /* 3541d83adfeac16ee3e45d183a58dffe06012ccb5aa5bcd2e4f6eeae269f69cd */,
        (uint8_t[32]){100,35,32,55,16,154,94,95,83,171,3,119,231,85,236,73,74,233,63,203,82,121,230,238,167,29,236,46,122,198,251,252} /* 64232037109a5e5f53ab0377e755ec494ae93fcb5279e6eea71dec2e7ac6fbfc */,
        (uint8_t[32]){138,213,91,195,91,179,168,62,101,192,24,189,253,231,174,94,188,116,159,242,191,107,121,65,45,237,11,198,200,155,151,216} /* 8ad55bc35bb3a83e65c018bdfde7ae5ebc749ff2bf6b79412ded0bc6c89b97d8 */,
        (uint8_t[32]){156,179,223,43,222,44,108,213,253,150,183,196,21,85,66,12,172,215,226,118,165,86,198,132,175,145,183,70,28,134,70,15} /* 9cb3df2bde2c6cd5fd96b7c41555420cacd7e276a556c684af91b7461c86460f */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssCallback::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IGnssCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IGnssCallback::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IGnssCallback::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IGnssCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssCallback>> IGnssCallback::castFrom(const ::android::sp<::android::hardware::gnss::V2_1::IGnssCallback>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssCallback>> IGnssCallback::castFrom(const ::android::sp<::android::hardware::gnss::V2_0::IGnssCallback>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnssCallback, ::android::hardware::gnss::V2_0::IGnssCallback, BpHwGnssCallback>(
            parent, "android.hardware.gnss@2.1::IGnssCallback", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssCallback>> IGnssCallback::castFrom(const ::android::sp<::android::hardware::gnss::V1_1::IGnssCallback>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnssCallback, ::android::hardware::gnss::V1_1::IGnssCallback, BpHwGnssCallback>(
            parent, "android.hardware.gnss@2.1::IGnssCallback", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssCallback>> IGnssCallback::castFrom(const ::android::sp<::android::hardware::gnss::V1_0::IGnssCallback>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnssCallback, ::android::hardware::gnss::V1_0::IGnssCallback, BpHwGnssCallback>(
            parent, "android.hardware.gnss@2.1::IGnssCallback", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssCallback>> IGnssCallback::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnssCallback, ::android::hidl::base::V1_0::IBase, BpHwGnssCallback>(
            parent, "android.hardware.gnss@2.1::IGnssCallback", emitError);
}

BpHwGnssCallback::BpHwGnssCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IGnssCallback>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.gnss@2.1", "IGnssCallback") {
}

void BpHwGnssCallback::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IGnssCallback>::onLastStrongRef(id);
}
// Methods from ::android::hardware::gnss::V2_1::IGnssCallback follow.
::android::hardware::Return<void> BpHwGnssCallback::_hidl_gnssSetCapabilitiesCb_2_1(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::hidl_bitfield<::android::hardware::gnss::V2_1::IGnssCallback::Capabilities> capabilities) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnssCallback::gnssSetCapabilitiesCb_2_1::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&capabilities);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.1", "IGnssCallback", "gnssSetCapabilitiesCb_2_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnssCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32((uint32_t)capabilities);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(16 /* gnssSetCapabilitiesCb_2_1 */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.1", "IGnssCallback", "gnssSetCapabilitiesCb_2_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwGnssCallback::_hidl_gnssSvStatusCb_2_1(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::gnss::V2_1::IGnssCallback::GnssSvInfo>& svInfoList) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnssCallback::gnssSvStatusCb_2_1::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&svInfoList);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.1", "IGnssCallback", "gnssSvStatusCb_2_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnssCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_svInfoList_parent;

    _hidl_err = _hidl_data.writeBuffer(&svInfoList, sizeof(svInfoList), &_hidl_svInfoList_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_svInfoList_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            svInfoList,
            &_hidl_data,
            _hidl_svInfoList_parent,
            0 /* parentOffset */, &_hidl_svInfoList_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(17 /* gnssSvStatusCb_2_1 */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.1", "IGnssCallback", "gnssSvStatusCb_2_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::gnss::V1_0::IGnssCallback follow.
::android::hardware::Return<void> BpHwGnssCallback::gnssLocationCb(const ::android::hardware::gnss::V1_0::GnssLocation& location){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssCallback::_hidl_gnssLocationCb(this, this, location);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::gnssStatusCb(::android::hardware::gnss::V1_0::IGnssCallback::GnssStatusValue status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssCallback::_hidl_gnssStatusCb(this, this, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::gnssSvStatusCb(const ::android::hardware::gnss::V1_0::IGnssCallback::GnssSvStatus& svInfo){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssCallback::_hidl_gnssSvStatusCb(this, this, svInfo);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::gnssNmeaCb(int64_t timestamp, const ::android::hardware::hidl_string& nmea){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssCallback::_hidl_gnssNmeaCb(this, this, timestamp, nmea);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::gnssSetCapabilitesCb(::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssCallback::Capabilities> capabilities){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssCallback::_hidl_gnssSetCapabilitesCb(this, this, capabilities);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::gnssAcquireWakelockCb(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssCallback::_hidl_gnssAcquireWakelockCb(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::gnssReleaseWakelockCb(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssCallback::_hidl_gnssReleaseWakelockCb(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::gnssRequestTimeCb(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssCallback::_hidl_gnssRequestTimeCb(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::gnssSetSystemInfoCb(const ::android::hardware::gnss::V1_0::IGnssCallback::GnssSystemInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssCallback::_hidl_gnssSetSystemInfoCb(this, this, info);

    return _hidl_out;
}


// Methods from ::android::hardware::gnss::V1_1::IGnssCallback follow.
::android::hardware::Return<void> BpHwGnssCallback::gnssNameCb(const ::android::hardware::hidl_string& name){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_1::BpHwGnssCallback::_hidl_gnssNameCb(this, this, name);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::gnssRequestLocationCb(bool independentFromGnss){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_1::BpHwGnssCallback::_hidl_gnssRequestLocationCb(this, this, independentFromGnss);

    return _hidl_out;
}


// Methods from ::android::hardware::gnss::V2_0::IGnssCallback follow.
::android::hardware::Return<void> BpHwGnssCallback::gnssSetCapabilitiesCb_2_0(::android::hardware::hidl_bitfield<::android::hardware::gnss::V2_0::IGnssCallback::Capabilities> capabilities){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnssCallback::_hidl_gnssSetCapabilitiesCb_2_0(this, this, capabilities);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::gnssLocationCb_2_0(const ::android::hardware::gnss::V2_0::GnssLocation& location){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnssCallback::_hidl_gnssLocationCb_2_0(this, this, location);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::gnssRequestLocationCb_2_0(bool independentFromGnss, bool isUserEmergency){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnssCallback::_hidl_gnssRequestLocationCb_2_0(this, this, independentFromGnss, isUserEmergency);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::gnssSvStatusCb_2_0(const ::android::hardware::hidl_vec<::android::hardware::gnss::V2_0::IGnssCallback::GnssSvInfo>& svInfoList){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnssCallback::_hidl_gnssSvStatusCb_2_0(this, this, svInfoList);

    return _hidl_out;
}


// Methods from ::android::hardware::gnss::V2_1::IGnssCallback follow.
::android::hardware::Return<void> BpHwGnssCallback::gnssSetCapabilitiesCb_2_1(::android::hardware::hidl_bitfield<::android::hardware::gnss::V2_1::IGnssCallback::Capabilities> capabilities){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V2_1::BpHwGnssCallback::_hidl_gnssSetCapabilitiesCb_2_1(this, this, capabilities);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::gnssSvStatusCb_2_1(const ::android::hardware::hidl_vec<::android::hardware::gnss::V2_1::IGnssCallback::GnssSvInfo>& svInfoList){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V2_1::BpHwGnssCallback::_hidl_gnssSvStatusCb_2_1(this, this, svInfoList);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwGnssCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnssCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwGnssCallback::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssCallback::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnssCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwGnssCallback::BnHwGnssCallback(const ::android::sp<IGnssCallback> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.gnss@2.1", "IGnssCallback") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwGnssCallback::~BnHwGnssCallback() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::gnss::V2_1::IGnssCallback follow.
::android::status_t BnHwGnssCallback::_hidl_gnssSetCapabilitiesCb_2_1(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnssCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::hidl_bitfield<::android::hardware::gnss::V2_1::IGnssCallback::Capabilities> capabilities;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&capabilities);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnssCallback::gnssSetCapabilitiesCb_2_1::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&capabilities);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.1", "IGnssCallback", "gnssSetCapabilitiesCb_2_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGnssCallback*>(_hidl_this->getImpl().get())->gnssSetCapabilitiesCb_2_1(capabilities);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.1", "IGnssCallback", "gnssSetCapabilitiesCb_2_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwGnssCallback::_hidl_gnssSvStatusCb_2_1(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnssCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<::android::hardware::gnss::V2_1::IGnssCallback::GnssSvInfo>* svInfoList;

    size_t _hidl_svInfoList_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*svInfoList), &_hidl_svInfoList_parent,  reinterpret_cast<const void **>(&svInfoList));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_svInfoList_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::gnss::V2_1::IGnssCallback::GnssSvInfo> &>(*svInfoList),
            _hidl_data,
            _hidl_svInfoList_parent,
            0 /* parentOffset */, &_hidl_svInfoList_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnssCallback::gnssSvStatusCb_2_1::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)svInfoList);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.1", "IGnssCallback", "gnssSvStatusCb_2_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGnssCallback*>(_hidl_this->getImpl().get())->gnssSvStatusCb_2_1(*svInfoList);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.1", "IGnssCallback", "gnssSvStatusCb_2_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::gnss::V1_0::IGnssCallback follow.

// Methods from ::android::hardware::gnss::V1_1::IGnssCallback follow.

// Methods from ::android::hardware::gnss::V2_0::IGnssCallback follow.

// Methods from ::android::hardware::gnss::V2_1::IGnssCallback follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwGnssCallback::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwGnssCallback::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwGnssCallback::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* gnssLocationCb */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssCallback::_hidl_gnssLocationCb(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* gnssStatusCb */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssCallback::_hidl_gnssStatusCb(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* gnssSvStatusCb */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssCallback::_hidl_gnssSvStatusCb(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* gnssNmeaCb */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssCallback::_hidl_gnssNmeaCb(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* gnssSetCapabilitesCb */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssCallback::_hidl_gnssSetCapabilitesCb(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* gnssAcquireWakelockCb */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssCallback::_hidl_gnssAcquireWakelockCb(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* gnssReleaseWakelockCb */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssCallback::_hidl_gnssReleaseWakelockCb(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* gnssRequestTimeCb */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssCallback::_hidl_gnssRequestTimeCb(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* gnssSetSystemInfoCb */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssCallback::_hidl_gnssSetSystemInfoCb(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* gnssNameCb */:
        {
            _hidl_err = ::android::hardware::gnss::V1_1::BnHwGnssCallback::_hidl_gnssNameCb(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* gnssRequestLocationCb */:
        {
            _hidl_err = ::android::hardware::gnss::V1_1::BnHwGnssCallback::_hidl_gnssRequestLocationCb(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* gnssSetCapabilitiesCb_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnssCallback::_hidl_gnssSetCapabilitiesCb_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* gnssLocationCb_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnssCallback::_hidl_gnssLocationCb_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* gnssRequestLocationCb_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnssCallback::_hidl_gnssRequestLocationCb_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* gnssSvStatusCb_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnssCallback::_hidl_gnssSvStatusCb_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* gnssSetCapabilitiesCb_2_1 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_1::BnHwGnssCallback::_hidl_gnssSetCapabilitiesCb_2_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* gnssSvStatusCb_2_1 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_1::BnHwGnssCallback::_hidl_gnssSvStatusCb_2_1(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsGnssCallback::BsGnssCallback(const ::android::sp<::android::hardware::gnss::V2_1::IGnssCallback> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.gnss@2.1", "IGnssCallback"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsGnssCallback::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IGnssCallback> IGnssCallback::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwGnssCallback>(serviceName, false, getStub);
}

::android::sp<IGnssCallback> IGnssCallback::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwGnssCallback>(serviceName, true, getStub);
}

::android::status_t IGnssCallback::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IGnssCallback::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.gnss@2.1::IGnssCallback",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_1
}  // namespace gnss
}  // namespace hardware
}  // namespace android
