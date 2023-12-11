#define LOG_TAG "android.hardware.gnss@2.0::Gnss"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/gnss/2.0/BpHwGnss.h>
#include <android/hardware/gnss/2.0/BnHwGnss.h>
#include <android/hardware/gnss/2.0/BsGnss.h>
#include <android/hardware/gnss/1.1/BpHwGnss.h>
#include <android/hardware/gnss/1.0/BpHwGnss.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace gnss {
namespace V2_0 {

const char* IGnss::descriptor("android.hardware.gnss@2.0::IGnss");

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

// Methods from ::android::hardware::gnss::V1_1::IGnss follow.
// no default implementation for: ::android::hardware::Return<bool> IGnss::setCallback_1_1(const ::android::sp<::android::hardware::gnss::V1_1::IGnssCallback>& callback)
// no default implementation for: ::android::hardware::Return<bool> IGnss::setPositionMode_1_1(::android::hardware::gnss::V1_0::IGnss::GnssPositionMode mode, ::android::hardware::gnss::V1_0::IGnss::GnssPositionRecurrence recurrence, uint32_t minIntervalMs, uint32_t preferredAccuracyMeters, uint32_t preferredTimeMs, bool lowPowerMode)
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_1::IGnssConfiguration>> IGnss::getExtensionGnssConfiguration_1_1()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_1::IGnssMeasurement>> IGnss::getExtensionGnssMeasurement_1_1()
// no default implementation for: ::android::hardware::Return<bool> IGnss::injectBestLocation(const ::android::hardware::gnss::V1_0::GnssLocation& location)

// Methods from ::android::hardware::gnss::V2_0::IGnss follow.
// no default implementation for: ::android::hardware::Return<bool> IGnss::setCallback_2_0(const ::android::sp<::android::hardware::gnss::V2_0::IGnssCallback>& callback)
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssConfiguration>> IGnss::getExtensionGnssConfiguration_2_0()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>> IGnss::getExtensionGnssDebug_2_0()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnss>> IGnss::getExtensionAGnss_2_0()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnssRil>> IGnss::getExtensionAGnssRil_2_0()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurement>> IGnss::getExtensionGnssMeasurement_2_0()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::measurement_corrections::V1_0::IMeasurementCorrections>> IGnss::getExtensionMeasurementCorrections()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControl>> IGnss::getExtensionVisibilityControl()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssBatching>> IGnss::getExtensionGnssBatching_2_0()
// no default implementation for: ::android::hardware::Return<bool> IGnss::injectBestLocation_2_0(const ::android::hardware::gnss::V2_0::GnssLocation& location)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IGnss::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::gnss::V2_0::IGnss::descriptor,
        ::android::hardware::gnss::V1_1::IGnss::descriptor,
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
    _hidl_cb(::android::hardware::gnss::V2_0::IGnss::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnss::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){245,96,95,72,194,251,159,35,22,21,221,147,43,247,48,174,149,64,244,249,139,91,122,226,178,105,151,95,69,47,109,115} /* f5605f48c2fb9f231615dd932bf730ae9540f4f98b5b7ae2b269975f452f6d73 */,
        (uint8_t[32]){181,241,244,193,189,109,231,26,142,113,215,15,87,205,171,144,74,192,36,161,47,61,238,62,33,115,119,10,69,131,188,194} /* b5f1f4c1bd6de71a8e71d70f57cdab904ac024a12f3dee3e2173770a4583bcc2 */,
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


::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnss>> IGnss::castFrom(const ::android::sp<::android::hardware::gnss::V2_0::IGnss>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnss>> IGnss::castFrom(const ::android::sp<::android::hardware::gnss::V1_1::IGnss>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnss, ::android::hardware::gnss::V1_1::IGnss, BpHwGnss>(
            parent, "android.hardware.gnss@2.0::IGnss", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnss>> IGnss::castFrom(const ::android::sp<::android::hardware::gnss::V1_0::IGnss>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnss, ::android::hardware::gnss::V1_0::IGnss, BpHwGnss>(
            parent, "android.hardware.gnss@2.0::IGnss", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnss>> IGnss::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnss, ::android::hidl::base::V1_0::IBase, BpHwGnss>(
            parent, "android.hardware.gnss@2.0::IGnss", emitError);
}

BpHwGnss::BpHwGnss(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IGnss>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.gnss@2.0", "IGnss") {
}

void BpHwGnss::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IGnss>::onLastStrongRef(id);
}
// Methods from ::android::hardware::gnss::V2_0::IGnss follow.
::android::hardware::Return<bool> BpHwGnss::_hidl_setCallback_2_0(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::gnss::V2_0::IGnssCallback>& callback) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::setCallback_2_0::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "setCallback_2_0", &_hidl_args);
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
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(24 /* setCallback_2_0 */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "setCallback_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<bool>(_hidl_out_success);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<bool>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssConfiguration>> BpHwGnss::_hidl_getExtensionGnssConfiguration_2_0(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssConfiguration_2_0::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssConfiguration_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V2_0::IGnssConfiguration> _hidl_out_gnssConfigurationIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(25 /* getExtensionGnssConfiguration_2_0 */, _hidl_data, &_hidl_reply, 0 /* flags */);
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

        _hidl_out_gnssConfigurationIface = ::android::hardware::fromBinder<::android::hardware::gnss::V2_0::IGnssConfiguration,::android::hardware::gnss::V2_0::BpHwGnssConfiguration,::android::hardware::gnss::V2_0::BnHwGnssConfiguration>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_gnssConfigurationIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssConfiguration_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssConfiguration>>(_hidl_out_gnssConfigurationIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssConfiguration>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>> BpHwGnss::_hidl_getExtensionGnssDebug_2_0(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssDebug_2_0::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssDebug_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V2_0::IGnssDebug> _hidl_out_gnssDebugIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(26 /* getExtensionGnssDebug_2_0 */, _hidl_data, &_hidl_reply, 0 /* flags */);
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

        _hidl_out_gnssDebugIface = ::android::hardware::fromBinder<::android::hardware::gnss::V2_0::IGnssDebug,::android::hardware::gnss::V2_0::BpHwGnssDebug,::android::hardware::gnss::V2_0::BnHwGnssDebug>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_gnssDebugIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssDebug_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>>(_hidl_out_gnssDebugIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnss>> BpHwGnss::_hidl_getExtensionAGnss_2_0(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionAGnss_2_0::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionAGnss_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V2_0::IAGnss> _hidl_out_aGnssIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(27 /* getExtensionAGnss_2_0 */, _hidl_data, &_hidl_reply, 0 /* flags */);
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

        _hidl_out_aGnssIface = ::android::hardware::fromBinder<::android::hardware::gnss::V2_0::IAGnss,::android::hardware::gnss::V2_0::BpHwAGnss,::android::hardware::gnss::V2_0::BnHwAGnss>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_aGnssIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionAGnss_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnss>>(_hidl_out_aGnssIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnss>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnssRil>> BpHwGnss::_hidl_getExtensionAGnssRil_2_0(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionAGnssRil_2_0::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionAGnssRil_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V2_0::IAGnssRil> _hidl_out_aGnssRilIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(28 /* getExtensionAGnssRil_2_0 */, _hidl_data, &_hidl_reply, 0 /* flags */);
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

        _hidl_out_aGnssRilIface = ::android::hardware::fromBinder<::android::hardware::gnss::V2_0::IAGnssRil,::android::hardware::gnss::V2_0::BpHwAGnssRil,::android::hardware::gnss::V2_0::BnHwAGnssRil>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_aGnssRilIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionAGnssRil_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnssRil>>(_hidl_out_aGnssRilIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnssRil>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurement>> BpHwGnss::_hidl_getExtensionGnssMeasurement_2_0(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssMeasurement_2_0::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssMeasurement_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurement> _hidl_out_gnssMeasurementIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(29 /* getExtensionGnssMeasurement_2_0 */, _hidl_data, &_hidl_reply, 0 /* flags */);
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

        _hidl_out_gnssMeasurementIface = ::android::hardware::fromBinder<::android::hardware::gnss::V2_0::IGnssMeasurement,::android::hardware::gnss::V2_0::BpHwGnssMeasurement,::android::hardware::gnss::V2_0::BnHwGnssMeasurement>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_gnssMeasurementIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssMeasurement_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurement>>(_hidl_out_gnssMeasurementIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurement>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::measurement_corrections::V1_0::IMeasurementCorrections>> BpHwGnss::_hidl_getExtensionMeasurementCorrections(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionMeasurementCorrections::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionMeasurementCorrections", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::measurement_corrections::V1_0::IMeasurementCorrections> _hidl_out_measurementCorrectionsIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(30 /* getExtensionMeasurementCorrections */, _hidl_data, &_hidl_reply, 0 /* flags */);
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

        _hidl_out_measurementCorrectionsIface = ::android::hardware::fromBinder<::android::hardware::gnss::measurement_corrections::V1_0::IMeasurementCorrections,::android::hardware::gnss::measurement_corrections::V1_0::BpHwMeasurementCorrections,::android::hardware::gnss::measurement_corrections::V1_0::BnHwMeasurementCorrections>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_measurementCorrectionsIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionMeasurementCorrections", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::measurement_corrections::V1_0::IMeasurementCorrections>>(_hidl_out_measurementCorrectionsIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::measurement_corrections::V1_0::IMeasurementCorrections>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControl>> BpHwGnss::_hidl_getExtensionVisibilityControl(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionVisibilityControl::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionVisibilityControl", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControl> _hidl_out_visibilityControlIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(31 /* getExtensionVisibilityControl */, _hidl_data, &_hidl_reply, 0 /* flags */);
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

        _hidl_out_visibilityControlIface = ::android::hardware::fromBinder<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControl,::android::hardware::gnss::visibility_control::V1_0::BpHwGnssVisibilityControl,::android::hardware::gnss::visibility_control::V1_0::BnHwGnssVisibilityControl>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_visibilityControlIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionVisibilityControl", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControl>>(_hidl_out_visibilityControlIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControl>>(_hidl_status);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssBatching>> BpHwGnss::_hidl_getExtensionGnssBatching_2_0(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssBatching_2_0::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssBatching_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<::android::hardware::gnss::V2_0::IGnssBatching> _hidl_out_batchingIface;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnss::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(32 /* getExtensionGnssBatching_2_0 */, _hidl_data, &_hidl_reply, 0 /* flags */);
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

        _hidl_out_batchingIface = ::android::hardware::fromBinder<::android::hardware::gnss::V2_0::IGnssBatching,::android::hardware::gnss::V2_0::BpHwGnssBatching,::android::hardware::gnss::V2_0::BnHwGnssBatching>(_hidl_binder);
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_batchingIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssBatching_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssBatching>>(_hidl_out_batchingIface);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssBatching>>(_hidl_status);
}

::android::hardware::Return<bool> BpHwGnss::_hidl_injectBestLocation_2_0(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::gnss::V2_0::GnssLocation& location) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnss::injectBestLocation_2_0::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&location);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "injectBestLocation_2_0", &_hidl_args);
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

    size_t _hidl_location_parent;

    _hidl_err = _hidl_data.writeBuffer(&location, sizeof(location), &_hidl_location_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(33 /* injectBestLocation_2_0 */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "injectBestLocation_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<bool>(_hidl_out_success);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<bool>(_hidl_status);
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


// Methods from ::android::hardware::gnss::V1_1::IGnss follow.
::android::hardware::Return<bool> BpHwGnss::setCallback_1_1(const ::android::sp<::android::hardware::gnss::V1_1::IGnssCallback>& callback){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_1::BpHwGnss::_hidl_setCallback_1_1(this, this, callback);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnss::setPositionMode_1_1(::android::hardware::gnss::V1_0::IGnss::GnssPositionMode mode, ::android::hardware::gnss::V1_0::IGnss::GnssPositionRecurrence recurrence, uint32_t minIntervalMs, uint32_t preferredAccuracyMeters, uint32_t preferredTimeMs, bool lowPowerMode){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_1::BpHwGnss::_hidl_setPositionMode_1_1(this, this, mode, recurrence, minIntervalMs, preferredAccuracyMeters, preferredTimeMs, lowPowerMode);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_1::IGnssConfiguration>> BpHwGnss::getExtensionGnssConfiguration_1_1(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_1::IGnssConfiguration>>  _hidl_out = ::android::hardware::gnss::V1_1::BpHwGnss::_hidl_getExtensionGnssConfiguration_1_1(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_1::IGnssMeasurement>> BpHwGnss::getExtensionGnssMeasurement_1_1(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_1::IGnssMeasurement>>  _hidl_out = ::android::hardware::gnss::V1_1::BpHwGnss::_hidl_getExtensionGnssMeasurement_1_1(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnss::injectBestLocation(const ::android::hardware::gnss::V1_0::GnssLocation& location){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_1::BpHwGnss::_hidl_injectBestLocation(this, this, location);

    return _hidl_out;
}


// Methods from ::android::hardware::gnss::V2_0::IGnss follow.
::android::hardware::Return<bool> BpHwGnss::setCallback_2_0(const ::android::sp<::android::hardware::gnss::V2_0::IGnssCallback>& callback){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnss::_hidl_setCallback_2_0(this, this, callback);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssConfiguration>> BpHwGnss::getExtensionGnssConfiguration_2_0(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssConfiguration>>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnss::_hidl_getExtensionGnssConfiguration_2_0(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>> BpHwGnss::getExtensionGnssDebug_2_0(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnss::_hidl_getExtensionGnssDebug_2_0(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnss>> BpHwGnss::getExtensionAGnss_2_0(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnss>>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnss::_hidl_getExtensionAGnss_2_0(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnssRil>> BpHwGnss::getExtensionAGnssRil_2_0(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnssRil>>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnss::_hidl_getExtensionAGnssRil_2_0(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurement>> BpHwGnss::getExtensionGnssMeasurement_2_0(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurement>>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnss::_hidl_getExtensionGnssMeasurement_2_0(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::measurement_corrections::V1_0::IMeasurementCorrections>> BpHwGnss::getExtensionMeasurementCorrections(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::measurement_corrections::V1_0::IMeasurementCorrections>>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnss::_hidl_getExtensionMeasurementCorrections(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControl>> BpHwGnss::getExtensionVisibilityControl(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControl>>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnss::_hidl_getExtensionVisibilityControl(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssBatching>> BpHwGnss::getExtensionGnssBatching_2_0(){
    ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssBatching>>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnss::_hidl_getExtensionGnssBatching_2_0(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnss::injectBestLocation_2_0(const ::android::hardware::gnss::V2_0::GnssLocation& location){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnss::_hidl_injectBestLocation_2_0(this, this, location);

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
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.gnss@2.0", "IGnss") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwGnss::~BnHwGnss() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::gnss::V2_0::IGnss follow.
::android::status_t BnHwGnss::_hidl_setCallback_2_0(
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

    ::android::sp<::android::hardware::gnss::V2_0::IGnssCallback> callback;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<::android::hardware::gnss::V2_0::IGnssCallback,::android::hardware::gnss::V2_0::BpHwGnssCallback,::android::hardware::gnss::V2_0::BnHwGnssCallback>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::setCallback_2_0::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "setCallback_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_out_success = static_cast<IGnss*>(_hidl_this->getImpl().get())->setCallback_2_0(callback);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "setCallback_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionGnssConfiguration_2_0(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssConfiguration_2_0::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssConfiguration_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V2_0::IGnssConfiguration> _hidl_out_gnssConfigurationIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionGnssConfiguration_2_0();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_gnssConfigurationIface == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_gnssConfigurationIface.get());
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
        _hidl_args.push_back((void *)&_hidl_out_gnssConfigurationIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssConfiguration_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionGnssDebug_2_0(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssDebug_2_0::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssDebug_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V2_0::IGnssDebug> _hidl_out_gnssDebugIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionGnssDebug_2_0();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_gnssDebugIface == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_gnssDebugIface.get());
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
        _hidl_args.push_back((void *)&_hidl_out_gnssDebugIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssDebug_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionAGnss_2_0(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionAGnss_2_0::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionAGnss_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V2_0::IAGnss> _hidl_out_aGnssIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionAGnss_2_0();

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionAGnss_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionAGnssRil_2_0(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionAGnssRil_2_0::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionAGnssRil_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V2_0::IAGnssRil> _hidl_out_aGnssRilIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionAGnssRil_2_0();

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionAGnssRil_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionGnssMeasurement_2_0(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssMeasurement_2_0::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssMeasurement_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurement> _hidl_out_gnssMeasurementIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionGnssMeasurement_2_0();

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssMeasurement_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionMeasurementCorrections(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionMeasurementCorrections::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionMeasurementCorrections", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::measurement_corrections::V1_0::IMeasurementCorrections> _hidl_out_measurementCorrectionsIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionMeasurementCorrections();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_measurementCorrectionsIface == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_measurementCorrectionsIface.get());
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
        _hidl_args.push_back((void *)&_hidl_out_measurementCorrectionsIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionMeasurementCorrections", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionVisibilityControl(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionVisibilityControl::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionVisibilityControl", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControl> _hidl_out_visibilityControlIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionVisibilityControl();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_visibilityControlIface == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_visibilityControlIface.get());
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
        _hidl_args.push_back((void *)&_hidl_out_visibilityControlIface);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionVisibilityControl", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_getExtensionGnssBatching_2_0(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::getExtensionGnssBatching_2_0::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssBatching_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<::android::hardware::gnss::V2_0::IGnssBatching> _hidl_out_batchingIface = static_cast<IGnss*>(_hidl_this->getImpl().get())->getExtensionGnssBatching_2_0();

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "getExtensionGnssBatching_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGnss::_hidl_injectBestLocation_2_0(
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

    ::android::hardware::gnss::V2_0::GnssLocation* location;

    size_t _hidl_location_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*location), &_hidl_location_parent,  const_cast<const void**>(reinterpret_cast<void **>(&location)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnss::injectBestLocation_2_0::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)location);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.0", "IGnss", "injectBestLocation_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_out_success = static_cast<IGnss*>(_hidl_this->getImpl().get())->injectBestLocation_2_0(*location);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.0", "IGnss", "injectBestLocation_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::gnss::V1_0::IGnss follow.

// Methods from ::android::hardware::gnss::V1_1::IGnss follow.

// Methods from ::android::hardware::gnss::V2_0::IGnss follow.

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

        case 19 /* setCallback_1_1 */:
        {
            _hidl_err = ::android::hardware::gnss::V1_1::BnHwGnss::_hidl_setCallback_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 20 /* setPositionMode_1_1 */:
        {
            _hidl_err = ::android::hardware::gnss::V1_1::BnHwGnss::_hidl_setPositionMode_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 21 /* getExtensionGnssConfiguration_1_1 */:
        {
            _hidl_err = ::android::hardware::gnss::V1_1::BnHwGnss::_hidl_getExtensionGnssConfiguration_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 22 /* getExtensionGnssMeasurement_1_1 */:
        {
            _hidl_err = ::android::hardware::gnss::V1_1::BnHwGnss::_hidl_getExtensionGnssMeasurement_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 23 /* injectBestLocation */:
        {
            _hidl_err = ::android::hardware::gnss::V1_1::BnHwGnss::_hidl_injectBestLocation(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 24 /* setCallback_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnss::_hidl_setCallback_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 25 /* getExtensionGnssConfiguration_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnss::_hidl_getExtensionGnssConfiguration_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 26 /* getExtensionGnssDebug_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnss::_hidl_getExtensionGnssDebug_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 27 /* getExtensionAGnss_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnss::_hidl_getExtensionAGnss_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 28 /* getExtensionAGnssRil_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnss::_hidl_getExtensionAGnssRil_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 29 /* getExtensionGnssMeasurement_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnss::_hidl_getExtensionGnssMeasurement_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 30 /* getExtensionMeasurementCorrections */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnss::_hidl_getExtensionMeasurementCorrections(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 31 /* getExtensionVisibilityControl */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnss::_hidl_getExtensionVisibilityControl(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 32 /* getExtensionGnssBatching_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnss::_hidl_getExtensionGnssBatching_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 33 /* injectBestLocation_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnss::_hidl_injectBestLocation_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsGnss::BsGnss(const ::android::sp<::android::hardware::gnss::V2_0::IGnss> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.gnss@2.0", "IGnss"), mImpl(impl) {
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
            sm->registerForNotifications("android.hardware.gnss@2.0::IGnss",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_0
}  // namespace gnss
}  // namespace hardware
}  // namespace android
