#define LOG_TAG "android.hardware.broadcastradio@1.1::TunerCallback"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/broadcastradio/1.1/BpHwTunerCallback.h>
#include <android/hardware/broadcastradio/1.1/BnHwTunerCallback.h>
#include <android/hardware/broadcastradio/1.1/BsTunerCallback.h>
#include <android/hardware/broadcastradio/1.0/BpHwTunerCallback.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace broadcastradio {
namespace V1_1 {

const char* ITunerCallback::descriptor("android.hardware.broadcastradio@1.1::ITunerCallback");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ITunerCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwTunerCallback(static_cast<ITunerCallback *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ITunerCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsTunerCallback(static_cast<ITunerCallback *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ITunerCallback::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ITunerCallback::descriptor);
}

// Methods from ::android::hardware::broadcastradio::V1_0::ITunerCallback follow.
// no default implementation for: ::android::hardware::Return<void> ITunerCallback::hardwareFailure()
// no default implementation for: ::android::hardware::Return<void> ITunerCallback::configChange(::android::hardware::broadcastradio::V1_0::Result result, const ::android::hardware::broadcastradio::V1_0::BandConfig& config)
// no default implementation for: ::android::hardware::Return<void> ITunerCallback::tuneComplete(::android::hardware::broadcastradio::V1_0::Result result, const ::android::hardware::broadcastradio::V1_0::ProgramInfo& info)
// no default implementation for: ::android::hardware::Return<void> ITunerCallback::afSwitch(const ::android::hardware::broadcastradio::V1_0::ProgramInfo& info)
// no default implementation for: ::android::hardware::Return<void> ITunerCallback::antennaStateChange(bool connected)
// no default implementation for: ::android::hardware::Return<void> ITunerCallback::trafficAnnouncement(bool active)
// no default implementation for: ::android::hardware::Return<void> ITunerCallback::emergencyAnnouncement(bool active)
// no default implementation for: ::android::hardware::Return<void> ITunerCallback::newMetadata(uint32_t channel, uint32_t subChannel, const ::android::hardware::hidl_vec<::android::hardware::broadcastradio::V1_0::MetaData>& metadata)

// Methods from ::android::hardware::broadcastradio::V1_1::ITunerCallback follow.
// no default implementation for: ::android::hardware::Return<void> ITunerCallback::tuneComplete_1_1(::android::hardware::broadcastradio::V1_0::Result result, const ::android::hardware::broadcastradio::V1_1::ProgramSelector& selector)
// no default implementation for: ::android::hardware::Return<void> ITunerCallback::backgroundScanAvailable(bool isAvailable)
// no default implementation for: ::android::hardware::Return<void> ITunerCallback::backgroundScanComplete(::android::hardware::broadcastradio::V1_1::ProgramListResult result)
// no default implementation for: ::android::hardware::Return<void> ITunerCallback::programListChanged()
// no default implementation for: ::android::hardware::Return<void> ITunerCallback::currentProgramInfoChanged(const ::android::hardware::broadcastradio::V1_1::ProgramInfo& info)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ITunerCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::broadcastradio::V1_1::ITunerCallback::descriptor,
        ::android::hardware::broadcastradio::V1_0::ITunerCallback::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ITunerCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ITunerCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::broadcastradio::V1_1::ITunerCallback::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ITunerCallback::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){233,19,159,199,85,190,87,134,147,241,124,140,209,226,124,117,244,18,207,199,34,21,123,171,91,240,62,230,136,150,227,29} /* e9139fc755be578693f17c8cd1e27c75f412cfc722157bab5bf03ee68896e31d */,
        (uint8_t[32]){4,211,202,2,46,37,195,8,217,239,210,231,235,119,179,167,162,6,144,124,220,27,158,169,50,99,64,179,119,134,129,114} /* 04d3ca022e25c308d9efd2e7eb77b3a7a206907cdc1b9ea9326340b377868172 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ITunerCallback::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ITunerCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ITunerCallback::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ITunerCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ITunerCallback::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ITunerCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::broadcastradio::V1_1::ITunerCallback>> ITunerCallback::castFrom(const ::android::sp<::android::hardware::broadcastradio::V1_1::ITunerCallback>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::broadcastradio::V1_1::ITunerCallback>> ITunerCallback::castFrom(const ::android::sp<::android::hardware::broadcastradio::V1_0::ITunerCallback>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ITunerCallback, ::android::hardware::broadcastradio::V1_0::ITunerCallback, BpHwTunerCallback>(
            parent, "android.hardware.broadcastradio@1.1::ITunerCallback", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::broadcastradio::V1_1::ITunerCallback>> ITunerCallback::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ITunerCallback, ::android::hidl::base::V1_0::IBase, BpHwTunerCallback>(
            parent, "android.hardware.broadcastradio@1.1::ITunerCallback", emitError);
}

BpHwTunerCallback::BpHwTunerCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ITunerCallback>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.broadcastradio@1.1", "ITunerCallback") {
}

void BpHwTunerCallback::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ITunerCallback>::onLastStrongRef(id);
}
// Methods from ::android::hardware::broadcastradio::V1_1::ITunerCallback follow.
::android::hardware::Return<void> BpHwTunerCallback::_hidl_tuneComplete_1_1(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::broadcastradio::V1_0::Result result, const ::android::hardware::broadcastradio::V1_1::ProgramSelector& selector) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ITunerCallback::tuneComplete_1_1::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&result);
        _hidl_args.push_back((void *)&selector);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "tuneComplete_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwTunerCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)result);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_selector_parent;

    _hidl_err = _hidl_data.writeBuffer(&selector, sizeof(selector), &_hidl_selector_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            selector,
            &_hidl_data,
            _hidl_selector_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* tuneComplete_1_1 */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "tuneComplete_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwTunerCallback::_hidl_backgroundScanAvailable(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool isAvailable) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ITunerCallback::backgroundScanAvailable::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&isAvailable);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "backgroundScanAvailable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwTunerCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(isAvailable);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* backgroundScanAvailable */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "backgroundScanAvailable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwTunerCallback::_hidl_backgroundScanComplete(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::broadcastradio::V1_1::ProgramListResult result) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ITunerCallback::backgroundScanComplete::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&result);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "backgroundScanComplete", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwTunerCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)result);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* backgroundScanComplete */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "backgroundScanComplete", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwTunerCallback::_hidl_programListChanged(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ITunerCallback::programListChanged::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "programListChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwTunerCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* programListChanged */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "programListChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwTunerCallback::_hidl_currentProgramInfoChanged(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::broadcastradio::V1_1::ProgramInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ITunerCallback::currentProgramInfoChanged::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "currentProgramInfoChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwTunerCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            info,
            &_hidl_data,
            _hidl_info_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* currentProgramInfoChanged */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "currentProgramInfoChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::broadcastradio::V1_0::ITunerCallback follow.
::android::hardware::Return<void> BpHwTunerCallback::hardwareFailure(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_0::BpHwTunerCallback::_hidl_hardwareFailure(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::configChange(::android::hardware::broadcastradio::V1_0::Result result, const ::android::hardware::broadcastradio::V1_0::BandConfig& config){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_0::BpHwTunerCallback::_hidl_configChange(this, this, result, config);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::tuneComplete(::android::hardware::broadcastradio::V1_0::Result result, const ::android::hardware::broadcastradio::V1_0::ProgramInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_0::BpHwTunerCallback::_hidl_tuneComplete(this, this, result, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::afSwitch(const ::android::hardware::broadcastradio::V1_0::ProgramInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_0::BpHwTunerCallback::_hidl_afSwitch(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::antennaStateChange(bool connected){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_0::BpHwTunerCallback::_hidl_antennaStateChange(this, this, connected);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::trafficAnnouncement(bool active){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_0::BpHwTunerCallback::_hidl_trafficAnnouncement(this, this, active);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::emergencyAnnouncement(bool active){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_0::BpHwTunerCallback::_hidl_emergencyAnnouncement(this, this, active);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::newMetadata(uint32_t channel, uint32_t subChannel, const ::android::hardware::hidl_vec<::android::hardware::broadcastradio::V1_0::MetaData>& metadata){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_0::BpHwTunerCallback::_hidl_newMetadata(this, this, channel, subChannel, metadata);

    return _hidl_out;
}


// Methods from ::android::hardware::broadcastradio::V1_1::ITunerCallback follow.
::android::hardware::Return<void> BpHwTunerCallback::tuneComplete_1_1(::android::hardware::broadcastradio::V1_0::Result result, const ::android::hardware::broadcastradio::V1_1::ProgramSelector& selector){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_1::BpHwTunerCallback::_hidl_tuneComplete_1_1(this, this, result, selector);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::backgroundScanAvailable(bool isAvailable){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_1::BpHwTunerCallback::_hidl_backgroundScanAvailable(this, this, isAvailable);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::backgroundScanComplete(::android::hardware::broadcastradio::V1_1::ProgramListResult result){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_1::BpHwTunerCallback::_hidl_backgroundScanComplete(this, this, result);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::programListChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_1::BpHwTunerCallback::_hidl_programListChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::currentProgramInfoChanged(const ::android::hardware::broadcastradio::V1_1::ProgramInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_1::BpHwTunerCallback::_hidl_currentProgramInfoChanged(this, this, info);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwTunerCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwTunerCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwTunerCallback::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwTunerCallback::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwTunerCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwTunerCallback::BnHwTunerCallback(const ::android::sp<ITunerCallback> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.broadcastradio@1.1", "ITunerCallback") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwTunerCallback::~BnHwTunerCallback() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::broadcastradio::V1_1::ITunerCallback follow.
::android::status_t BnHwTunerCallback::_hidl_tuneComplete_1_1(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwTunerCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::broadcastradio::V1_0::Result result;
    ::android::hardware::broadcastradio::V1_1::ProgramSelector* selector;

    _hidl_err = _hidl_data.readInt32((int32_t *)&result);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_selector_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*selector), &_hidl_selector_parent,  const_cast<const void**>(reinterpret_cast<void **>(&selector)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::broadcastradio::V1_1::ProgramSelector &>(*selector),
            _hidl_data,
            _hidl_selector_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ITunerCallback::tuneComplete_1_1::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&result);
        _hidl_args.push_back((void *)selector);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "tuneComplete_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ITunerCallback*>(_hidl_this->getImpl().get())->tuneComplete_1_1(result, *selector);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "tuneComplete_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwTunerCallback::_hidl_backgroundScanAvailable(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwTunerCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    bool isAvailable;

    _hidl_err = _hidl_data.readBool(&isAvailable);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ITunerCallback::backgroundScanAvailable::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&isAvailable);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "backgroundScanAvailable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ITunerCallback*>(_hidl_this->getImpl().get())->backgroundScanAvailable(isAvailable);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "backgroundScanAvailable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwTunerCallback::_hidl_backgroundScanComplete(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwTunerCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::broadcastradio::V1_1::ProgramListResult result;

    _hidl_err = _hidl_data.readInt32((int32_t *)&result);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ITunerCallback::backgroundScanComplete::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&result);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "backgroundScanComplete", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ITunerCallback*>(_hidl_this->getImpl().get())->backgroundScanComplete(result);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "backgroundScanComplete", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwTunerCallback::_hidl_programListChanged(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwTunerCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ITunerCallback::programListChanged::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "programListChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ITunerCallback*>(_hidl_this->getImpl().get())->programListChanged();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "programListChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwTunerCallback::_hidl_currentProgramInfoChanged(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwTunerCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::broadcastradio::V1_1::ProgramInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::broadcastradio::V1_1::ProgramInfo &>(*info),
            _hidl_data,
            _hidl_info_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ITunerCallback::currentProgramInfoChanged::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "currentProgramInfoChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ITunerCallback*>(_hidl_this->getImpl().get())->currentProgramInfoChanged(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.broadcastradio", "1.1", "ITunerCallback", "currentProgramInfoChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::broadcastradio::V1_0::ITunerCallback follow.

// Methods from ::android::hardware::broadcastradio::V1_1::ITunerCallback follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwTunerCallback::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwTunerCallback::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwTunerCallback::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* hardwareFailure */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_0::BnHwTunerCallback::_hidl_hardwareFailure(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* configChange */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_0::BnHwTunerCallback::_hidl_configChange(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* tuneComplete */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_0::BnHwTunerCallback::_hidl_tuneComplete(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* afSwitch */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_0::BnHwTunerCallback::_hidl_afSwitch(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* antennaStateChange */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_0::BnHwTunerCallback::_hidl_antennaStateChange(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* trafficAnnouncement */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_0::BnHwTunerCallback::_hidl_trafficAnnouncement(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* emergencyAnnouncement */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_0::BnHwTunerCallback::_hidl_emergencyAnnouncement(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* newMetadata */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_0::BnHwTunerCallback::_hidl_newMetadata(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* tuneComplete_1_1 */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_1::BnHwTunerCallback::_hidl_tuneComplete_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* backgroundScanAvailable */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_1::BnHwTunerCallback::_hidl_backgroundScanAvailable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* backgroundScanComplete */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_1::BnHwTunerCallback::_hidl_backgroundScanComplete(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* programListChanged */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_1::BnHwTunerCallback::_hidl_programListChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* currentProgramInfoChanged */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_1::BnHwTunerCallback::_hidl_currentProgramInfoChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsTunerCallback::BsTunerCallback(const ::android::sp<::android::hardware::broadcastradio::V1_1::ITunerCallback> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.broadcastradio@1.1", "ITunerCallback"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsTunerCallback::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ITunerCallback> ITunerCallback::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwTunerCallback>(serviceName, false, getStub);
}

::android::sp<ITunerCallback> ITunerCallback::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwTunerCallback>(serviceName, true, getStub);
}

::android::status_t ITunerCallback::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ITunerCallback::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.broadcastradio@1.1::ITunerCallback",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_1
}  // namespace broadcastradio
}  // namespace hardware
}  // namespace android
