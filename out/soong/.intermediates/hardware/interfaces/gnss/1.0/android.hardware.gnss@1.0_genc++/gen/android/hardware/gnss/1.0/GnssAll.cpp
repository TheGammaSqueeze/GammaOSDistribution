#define LOG_TAG "android.hardware.gnss@1.0::Gnss"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/gnss/1.0/BpHwGnss.h>
#include <android/hardware/gnss/1.0/BnHwGnss.h>
#include <android/hardware/gnss/1.0/BsGnss.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace gnss {
namespace V1_0 {

const char* IGnss::descriptor("android.hardware.gnss@1.0::IGnss");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IGnss::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwGnss(static_cast<IGnss *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IGnss::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsGnss(static_cast<IGnss *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IGnss::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IGnss::descriptor);
}

// Methods from ::android::hardware::gnss::V1_0::IGnss follow.
// no default implementation for: ::android::hardware::Return<bool> IGnss::setCallback(const ::android::sp<::android::hardware::gnss::V1_0::IGnssCallback>& callback)
// no default implementation for: ::android::hardware::Return<bool> IGnss::start()
// no default implementation for: ::android::hardware::Return<bool> IGnss::stop()
// no default implementation for: ::android::hardware::Return<void> IGnss::cleanup()
// no default implementation for: ::android::hardware::Return<bool> IGnss::injectTime(int64_t timeMs, int64_t timeReferenceMs, int32_t uncertaintyMs)
// no default implementation for: ::android::hardware::Return<bool> IGnss::injectLocation(double latitudeDegrees, double longitudeDegrees, float accuracyMeters)
// no default implementation for: ::android::hardware::Return<void> IGnss::deleteAidingData(::android::hardware::gnss::V1_0::IGnss::GnssAidingData aidingDataFlags)
// no default implementation for: ::android::hardware::Return<bool> IGnss::setPositionMode(::android::hardware::gnss::V1_0::IGnss::GnssPositionMode mode, ::android::hardware::gnss::V1_0::IGnss::GnssPositionRecurrence recurrence, uint32_t minIntervalMs, uint32_t preferredAccuracyMeters, uint32_t preferredTimeMs)
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IAGnssRil>> IGnss::getExtensionAGnssRil()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssGeofencing>> IGnss::getExtensionGnssGeofencing()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IAGnss>> IGnss::getExtensionAGnss()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssNi>> IGnss::getExtensionGnssNi()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurement>> IGnss::getExtensionGnssMeasurement()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssNavigationMessage>> IGnss::getExtensionGnssNavigationMessage()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssXtra>> IGnss::getExtensionXtra()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssConfiguration>> IGnss::getExtensionGnssConfiguration()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssDebug>> IGnss::getExtensionGnssDebug()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssBatching>> IGnss::getExtensionGnssBatching()

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IGnss::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::gnss::V1_0::IGnss::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnss::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnss::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::gnss::V1_0::IGnss::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnss::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){237,230,151,16,195,169,92,44,190,129,142,108,139,183,44,120,22,130,63,172,229,252,33,193,119,49,178,111,65,217,77,101} /* ede69710c3a95c2cbe818e6c8bb72c7816823face5fc21c17731b26f41d94d65 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnss::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IGnss::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IGnss::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnss::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IGnss::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IGnss::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnss>> IGnss::castFrom(const ::android::sp<::android::hardware::gnss::V1_0::IGnss>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnss>> IGnss::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnss, ::android::hidl::base::V1_0::IBase, BpHwGnss>(
            parent, "android.hardware.gnss@1.0::IGnss", emitError);
}

BpHwGnss::BpHwGnss(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IGnss>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.gnss@1.0", "IGnss") {
}

void BpHwGnss::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IGnss>::onLastStrongRef(id);
}
// Methods from ::android::hardware::gnss::V1_0::IGnss follow.
::android::hardware::Return<bool> BpHwGnss::_hidl_setCallback(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::gnss::V1_0::IGnssCallback>& callback) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::setCallback::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "setCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    bool _hidl_out_success;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (callback == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(callback.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* setCallback */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readBool(&_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "setCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<bool>(_hidl_out_success);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<bool>(_hidl_status);
}

::android::hardware::Return<bool> BpHwGnss::_hidl_start(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::start::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "start", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    bool _hidl_out_success;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* start */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readBool(&_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "start", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<bool>(_hidl_out_success);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<bool>(_hidl_status);
}

::android::hardware::Return<bool> BpHwGnss::_hidl_stop(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::stop::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "stop", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    bool _hidl_out_success;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* stop */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readBool(&_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "stop", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<bool>(_hidl_out_success);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<bool>(_hidl_status);
}

::android::hardware::Return<void> BpHwGnss::_hidl_cleanup(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::cleanup::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "cleanup", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* cleanup */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "cleanup", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<bool> BpHwGnss::_hidl_injectTime(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int64_t timeMs, int64_t timeReferenceMs, int32_t uncertaintyMs) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::injectTime::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&timeMs);
        _hidl_args.push_back((void *)&timeReferenceMs);
        _hidl_args.push_back((void *)&uncertaintyMs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "injectTime", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    bool _hidl_out_success;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt64(timeMs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt64(timeReferenceMs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(uncertaintyMs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* injectTime */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readBool(&_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "injectTime", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<bool>(_hidl_out_success);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<bool>(_hidl_status);
}

::android::hardware::Return<bool> BpHwGnss::_hidl_injectLocation(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, double latitudeDegrees, double longitudeDegrees, float accuracyMeters) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::injectLocation::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&latitudeDegrees);
        _hidl_args.push_back((void *)&longitudeDegrees);
        _hidl_args.push_back((void *)&accuracyMeters);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "injectLocation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    bool _hidl_out_success;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeDouble(latitudeDegrees);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeDouble(longitudeDegrees);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeFloat(accuracyMeters);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* injectLocation */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readBool(&_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "injectLocation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<bool>(_hidl_out_success);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<bool>(_hidl_status);
}

::android::hardware::Return<void> BpHwGnss::_hidl_deleteAidingData(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::gnss::V1_0::IGnss::GnssAidingData aidingDataFlags) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::deleteAidingData::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&aidingDataFlags);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "deleteAidingData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16((uint16_t)aidingDataFlags);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* deleteAidingData */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "deleteAidingData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<bool> BpHwGnss::_hidl_setPositionMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::gnss::V1_0::IGnss::GnssPositionMode mode, ::android::hardware::gnss::V1_0::IGnss::GnssPositionRecurrence recurrence, uint32_t minIntervalMs, uint32_t preferredAccuracyMeters, uint32_t preferredTimeMs) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::setPositionMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&mode);
        _hidl_args.push_back((void *)&recurrence);
        _hidl_args.push_back((void *)&minIntervalMs);
        _hidl_args.push_back((void *)&preferredAccuracyMeters);
        _hidl_args.push_back((void *)&preferredTimeMs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "setPositionMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    bool _hidl_out_success;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint8((uint8_t)mode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32((uint32_t)recurrence);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(minIntervalMs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(preferredAccuracyMeters);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(preferredTimeMs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* setPositionMode */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readBool(&_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "setPositionMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<bool>(_hidl_out_success);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<bool>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IAGnssRil>> BpHwGnss::_hidl_getExtensionAGnssRil(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionAGnssRil::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionAGnssRil", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V1_0::IAGnssRil> _hidl_out_aGnssRilIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* getExtensionAGnssRil */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_out_aGnssRilIface = ::android::hardware::fromBinder<::android::hardware::gnss::V1_0::IAGnssRil,::android::hardware::gnss::V1_0::BpHwAGnssRil,::android::hardware::gnss::V1_0::BnHwAGnssRil>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_aGnssRilIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionAGnssRil", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IAGnssRil>>(_hidl_out_aGnssRilIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IAGnssRil>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssGeofencing>> BpHwGnss::_hidl_getExtensionGnssGeofencing(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssGeofencing::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssGeofencing", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V1_0::IGnssGeofencing> _hidl_out_gnssGeofencingIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* getExtensionGnssGeofencing */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_out_gnssGeofencingIface = ::android::hardware::fromBinder<::android::hardware::gnss::V1_0::IGnssGeofencing,::android::hardware::gnss::V1_0::BpHwGnssGeofencing,::android::hardware::gnss::V1_0::BnHwGnssGeofencing>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_gnssGeofencingIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssGeofencing", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssGeofencing>>(_hidl_out_gnssGeofencingIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssGeofencing>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IAGnss>> BpHwGnss::_hidl_getExtensionAGnss(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionAGnss::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionAGnss", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V1_0::IAGnss> _hidl_out_aGnssIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* getExtensionAGnss */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_out_aGnssIface = ::android::hardware::fromBinder<::android::hardware::gnss::V1_0::IAGnss,::android::hardware::gnss::V1_0::BpHwAGnss,::android::hardware::gnss::V1_0::BnHwAGnss>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_aGnssIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionAGnss", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IAGnss>>(_hidl_out_aGnssIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IAGnss>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssNi>> BpHwGnss::_hidl_getExtensionGnssNi(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssNi::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssNi", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V1_0::IGnssNi> _hidl_out_gnssNiIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* getExtensionGnssNi */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_out_gnssNiIface = ::android::hardware::fromBinder<::android::hardware::gnss::V1_0::IGnssNi,::android::hardware::gnss::V1_0::BpHwGnssNi,::android::hardware::gnss::V1_0::BnHwGnssNi>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_gnssNiIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssNi", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssNi>>(_hidl_out_gnssNiIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssNi>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurement>> BpHwGnss::_hidl_getExtensionGnssMeasurement(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssMeasurement::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssMeasurement", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurement> _hidl_out_gnssMeasurementIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* getExtensionGnssMeasurement */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_out_gnssMeasurementIface = ::android::hardware::fromBinder<::android::hardware::gnss::V1_0::IGnssMeasurement,::android::hardware::gnss::V1_0::BpHwGnssMeasurement,::android::hardware::gnss::V1_0::BnHwGnssMeasurement>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_gnssMeasurementIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssMeasurement", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurement>>(_hidl_out_gnssMeasurementIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurement>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssNavigationMessage>> BpHwGnss::_hidl_getExtensionGnssNavigationMessage(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssNavigationMessage::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssNavigationMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V1_0::IGnssNavigationMessage> _hidl_out_gnssNavigationIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(14 /* getExtensionGnssNavigationMessage */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_out_gnssNavigationIface = ::android::hardware::fromBinder<::android::hardware::gnss::V1_0::IGnssNavigationMessage,::android::hardware::gnss::V1_0::BpHwGnssNavigationMessage,::android::hardware::gnss::V1_0::BnHwGnssNavigationMessage>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_gnssNavigationIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssNavigationMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssNavigationMessage>>(_hidl_out_gnssNavigationIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssNavigationMessage>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssXtra>> BpHwGnss::_hidl_getExtensionXtra(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionXtra::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionXtra", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V1_0::IGnssXtra> _hidl_out_xtraIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(15 /* getExtensionXtra */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_out_xtraIface = ::android::hardware::fromBinder<::android::hardware::gnss::V1_0::IGnssXtra,::android::hardware::gnss::V1_0::BpHwGnssXtra,::android::hardware::gnss::V1_0::BnHwGnssXtra>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_xtraIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionXtra", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssXtra>>(_hidl_out_xtraIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssXtra>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssConfiguration>> BpHwGnss::_hidl_getExtensionGnssConfiguration(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssConfiguration::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssConfiguration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V1_0::IGnssConfiguration> _hidl_out_gnssConfigIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(16 /* getExtensionGnssConfiguration */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_out_gnssConfigIface = ::android::hardware::fromBinder<::android::hardware::gnss::V1_0::IGnssConfiguration,::android::hardware::gnss::V1_0::BpHwGnssConfiguration,::android::hardware::gnss::V1_0::BnHwGnssConfiguration>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_gnssConfigIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssConfiguration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssConfiguration>>(_hidl_out_gnssConfigIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssConfiguration>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssDebug>> BpHwGnss::_hidl_getExtensionGnssDebug(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssDebug::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssDebug", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V1_0::IGnssDebug> _hidl_out_debugIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(17 /* getExtensionGnssDebug */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_out_debugIface = ::android::hardware::fromBinder<::android::hardware::gnss::V1_0::IGnssDebug,::android::hardware::gnss::V1_0::BpHwGnssDebug,::android::hardware::gnss::V1_0::BnHwGnssDebug>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssDebug", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssDebug>>(_hidl_out_debugIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssDebug>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssBatching>> BpHwGnss::_hidl_getExtensionGnssBatching(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssBatching::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssBatching", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V1_0::IGnssBatching> _hidl_out_batchingIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(18 /* getExtensionGnssBatching */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_out_batchingIface = ::android::hardware::fromBinder<::android::hardware::gnss::V1_0::IGnssBatching,::android::hardware::gnss::V1_0::BpHwGnssBatching,::android::hardware::gnss::V1_0::BnHwGnssBatching>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_batchingIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssBatching", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssBatching>>(_hidl_out_batchingIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssBatching>>(_hidl_status);
}


// Methods from ::android::hardware::gnss::V1_0::IGnss follow.
::android::hardware::Return<bool> BpHwGnss::setCallback(const ::android::sp<::android::hardware::gnss::V1_0::IGnssCallback>& callback){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_setCallback(this, this, callback);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnss::start(){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_start(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnss::stop(){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_stop(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnss::cleanup(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_cleanup(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnss::injectTime(int64_t timeMs, int64_t timeReferenceMs, int32_t uncertaintyMs){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_injectTime(this, this, timeMs, timeReferenceMs, uncertaintyMs);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnss::injectLocation(double latitudeDegrees, double longitudeDegrees, float accuracyMeters){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_injectLocation(this, this, latitudeDegrees, longitudeDegrees, accuracyMeters);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnss::deleteAidingData(::android::hardware::gnss::V1_0::IGnss::GnssAidingData aidingDataFlags){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_deleteAidingData(this, this, aidingDataFlags);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnss::setPositionMode(::android::hardware::gnss::V1_0::IGnss::GnssPositionMode mode, ::android::hardware::gnss::V1_0::IGnss::GnssPositionRecurrence recurrence, uint32_t minIntervalMs, uint32_t preferredAccuracyMeters, uint32_t preferredTimeMs){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_setPositionMode(this, this, mode, recurrence, minIntervalMs, preferredAccuracyMeters, preferredTimeMs);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IAGnssRil>> BpHwGnss::getExtensionAGnssRil(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IAGnssRil>>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_getExtensionAGnssRil(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssGeofencing>> BpHwGnss::getExtensionGnssGeofencing(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssGeofencing>>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_getExtensionGnssGeofencing(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IAGnss>> BpHwGnss::getExtensionAGnss(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IAGnss>>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_getExtensionAGnss(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssNi>> BpHwGnss::getExtensionGnssNi(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssNi>>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_getExtensionGnssNi(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurement>> BpHwGnss::getExtensionGnssMeasurement(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurement>>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_getExtensionGnssMeasurement(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssNavigationMessage>> BpHwGnss::getExtensionGnssNavigationMessage(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssNavigationMessage>>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_getExtensionGnssNavigationMessage(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssXtra>> BpHwGnss::getExtensionXtra(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssXtra>>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_getExtensionXtra(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssConfiguration>> BpHwGnss::getExtensionGnssConfiguration(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssConfiguration>>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_getExtensionGnssConfiguration(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssDebug>> BpHwGnss::getExtensionGnssDebug(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssDebug>>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_getExtensionGnssDebug(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssBatching>> BpHwGnss::getExtensionGnssBatching(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssBatching>>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnss::_hidl_getExtensionGnssBatching(this, this);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwGnss::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnss::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnss::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnss::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnss::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnss::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwGnss::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnss::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnss::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnss::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwGnss::BnHwGnss(const ::android::sp<IGnss> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.gnss@1.0", "IGnss") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwGnss::~BnHwGnss() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::gnss::V1_0::IGnss follow.
::android::status_t BnHwGnss::_hidl_setCallback(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::sp<::android::hardware::gnss::V1_0::IGnssCallback> callback;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<::android::hardware::gnss::V1_0::IGnssCallback,::android::hardware::gnss::V1_0::BpHwGnssCallback,::android::hardware::gnss::V1_0::BnHwGnssCallback>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::setCallback::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "setCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_out_success = static_cast<IGnss*>(_hidl_this->getImpl().get())->setCallback(callback);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeBool(_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "setCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_start(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::start::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "start", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_out_success = static_cast<IGnss*>(_hidl_this->getImpl().get())->start();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeBool(_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "start", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_stop(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::stop::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "stop", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_out_success = static_cast<IGnss*>(_hidl_this->getImpl().get())->stop();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeBool(_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "stop", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_cleanup(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::cleanup::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "cleanup", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGnss*>(_hidl_this->getImpl().get())->cleanup();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "cleanup", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_injectTime(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int64_t timeMs;
    int64_t timeReferenceMs;
    int32_t uncertaintyMs;

    _hidl_err = _hidl_data.readInt64(&timeMs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt64(&timeReferenceMs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&uncertaintyMs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::injectTime::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&timeMs);
        _hidl_args.push_back((void *)&timeReferenceMs);
        _hidl_args.push_back((void *)&uncertaintyMs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "injectTime", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_out_success = static_cast<IGnss*>(_hidl_this->getImpl().get())->injectTime(timeMs, timeReferenceMs, uncertaintyMs);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeBool(_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "injectTime", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_injectLocation(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    double latitudeDegrees;
    double longitudeDegrees;
    float accuracyMeters;

    _hidl_err = _hidl_data.readDouble(&latitudeDegrees);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readDouble(&longitudeDegrees);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readFloat(&accuracyMeters);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::injectLocation::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&latitudeDegrees);
        _hidl_args.push_back((void *)&longitudeDegrees);
        _hidl_args.push_back((void *)&accuracyMeters);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "injectLocation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_out_success = static_cast<IGnss*>(_hidl_this->getImpl().get())->injectLocation(latitudeDegrees, longitudeDegrees, accuracyMeters);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeBool(_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "injectLocation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_deleteAidingData(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::gnss::V1_0::IGnss::GnssAidingData aidingDataFlags;

    _hidl_err = _hidl_data.readUint16((uint16_t *)&aidingDataFlags);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::deleteAidingData::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&aidingDataFlags);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "deleteAidingData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGnss*>(_hidl_this->getImpl().get())->deleteAidingData(aidingDataFlags);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "deleteAidingData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_setPositionMode(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::gnss::V1_0::IGnss::GnssPositionMode mode;
    ::android::hardware::gnss::V1_0::IGnss::GnssPositionRecurrence recurrence;
    uint32_t minIntervalMs;
    uint32_t preferredAccuracyMeters;
    uint32_t preferredTimeMs;

    _hidl_err = _hidl_data.readUint8((uint8_t *)&mode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32((uint32_t *)&recurrence);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&minIntervalMs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&preferredAccuracyMeters);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&preferredTimeMs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::setPositionMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&mode);
        _hidl_args.push_back((void *)&recurrence);
        _hidl_args.push_back((void *)&minIntervalMs);
        _hidl_args.push_back((void *)&preferredAccuracyMeters);
        _hidl_args.push_back((void *)&preferredTimeMs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "setPositionMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_out_success = static_cast<IGnss*>(_hidl_this->getImpl().get())->setPositionMode(mode, recurrence, minIntervalMs, preferredAccuracyMeters, preferredTimeMs);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeBool(_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "setPositionMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionAGnssRil(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionAGnssRil::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionAGnssRil", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V1_0::IAGnssRil> _hidl_out_aGnssRilIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionAGnssRil();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_aGnssRilIface == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_aGnssRilIface.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_aGnssRilIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionAGnssRil", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionGnssGeofencing(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssGeofencing::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssGeofencing", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V1_0::IGnssGeofencing> _hidl_out_gnssGeofencingIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionGnssGeofencing();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_gnssGeofencingIface == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_gnssGeofencingIface.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_gnssGeofencingIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssGeofencing", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionAGnss(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionAGnss::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionAGnss", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V1_0::IAGnss> _hidl_out_aGnssIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionAGnss();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_aGnssIface == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_aGnssIface.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_aGnssIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionAGnss", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionGnssNi(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssNi::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssNi", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V1_0::IGnssNi> _hidl_out_gnssNiIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionGnssNi();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_gnssNiIface == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_gnssNiIface.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_gnssNiIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssNi", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionGnssMeasurement(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssMeasurement::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssMeasurement", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurement> _hidl_out_gnssMeasurementIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionGnssMeasurement();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_gnssMeasurementIface == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_gnssMeasurementIface.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_gnssMeasurementIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssMeasurement", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionGnssNavigationMessage(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssNavigationMessage::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssNavigationMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V1_0::IGnssNavigationMessage> _hidl_out_gnssNavigationIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionGnssNavigationMessage();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_gnssNavigationIface == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_gnssNavigationIface.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_gnssNavigationIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssNavigationMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionXtra(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionXtra::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionXtra", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V1_0::IGnssXtra> _hidl_out_xtraIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionXtra();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_xtraIface == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_xtraIface.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_xtraIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionXtra", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionGnssConfiguration(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssConfiguration::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssConfiguration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V1_0::IGnssConfiguration> _hidl_out_gnssConfigIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionGnssConfiguration();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_gnssConfigIface == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_gnssConfigIface.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_gnssConfigIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssConfiguration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionGnssDebug(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssDebug::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssDebug", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V1_0::IGnssDebug> _hidl_out_debugIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionGnssDebug();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_debugIface == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_debugIface.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssDebug", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionGnssBatching(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnss::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssBatching::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssBatching", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V1_0::IGnssBatching> _hidl_out_batchingIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionGnssBatching();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_batchingIface == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_batchingIface.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_batchingIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "1.0", "IGnss", "getExtensionGnssBatching", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::gnss::V1_0::IGnss follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwGnss::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwGnss::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwGnss::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* setCallback */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_setCallback(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* start */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_start(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* stop */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_stop(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* cleanup */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_cleanup(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* injectTime */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_injectTime(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* injectLocation */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_injectLocation(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* deleteAidingData */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_deleteAidingData(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* setPositionMode */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_setPositionMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* getExtensionAGnssRil */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_getExtensionAGnssRil(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* getExtensionGnssGeofencing */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_getExtensionGnssGeofencing(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* getExtensionAGnss */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_getExtensionAGnss(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* getExtensionGnssNi */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_getExtensionGnssNi(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* getExtensionGnssMeasurement */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_getExtensionGnssMeasurement(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* getExtensionGnssNavigationMessage */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_getExtensionGnssNavigationMessage(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* getExtensionXtra */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_getExtensionXtra(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* getExtensionGnssConfiguration */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_getExtensionGnssConfiguration(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* getExtensionGnssDebug */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_getExtensionGnssDebug(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* getExtensionGnssBatching */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnss::_hidl_getExtensionGnssBatching(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsGnss::BsGnss(const ::android::sp<::android::hardware::gnss::V1_0::IGnss> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.gnss@1.0", "IGnss"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsGnss::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IGnss> IGnss::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwGnss>(serviceName, false, getStub);
}

::android::sp<IGnss> IGnss::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwGnss>(serviceName, true, getStub);
}

::android::status_t IGnss::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IGnss::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.gnss@1.0::IGnss",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace gnss
}  // namespace hardware
}  // namespace android
