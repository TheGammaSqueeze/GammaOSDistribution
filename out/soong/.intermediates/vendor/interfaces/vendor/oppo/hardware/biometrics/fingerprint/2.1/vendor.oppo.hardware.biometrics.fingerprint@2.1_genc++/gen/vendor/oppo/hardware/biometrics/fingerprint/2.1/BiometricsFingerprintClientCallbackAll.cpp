#define LOG_TAG "vendor.oppo.hardware.biometrics.fingerprint@2.1::BiometricsFingerprintClientCallback"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <vendor/oppo/hardware/biometrics/fingerprint/2.1/BpHwBiometricsFingerprintClientCallback.h>
#include <vendor/oppo/hardware/biometrics/fingerprint/2.1/BnHwBiometricsFingerprintClientCallback.h>
#include <vendor/oppo/hardware/biometrics/fingerprint/2.1/BsBiometricsFingerprintClientCallback.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace vendor {
namespace oppo {
namespace hardware {
namespace biometrics {
namespace fingerprint {
namespace V2_1 {

const char* IBiometricsFingerprintClientCallback::descriptor("vendor.oppo.hardware.biometrics.fingerprint@2.1::IBiometricsFingerprintClientCallback");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IBiometricsFingerprintClientCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwBiometricsFingerprintClientCallback(static_cast<IBiometricsFingerprintClientCallback *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IBiometricsFingerprintClientCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsBiometricsFingerprintClientCallback(static_cast<IBiometricsFingerprintClientCallback *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IBiometricsFingerprintClientCallback::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IBiometricsFingerprintClientCallback::descriptor);
}

// Methods from ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback follow.
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprintClientCallback::onEnrollResult(uint64_t deviceId, uint32_t fingerId, uint32_t groupId, uint32_t remaining)
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprintClientCallback::onAcquired(uint64_t deviceId, ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintAcquiredInfo acquiredInfo, int32_t vendorCode)
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprintClientCallback::onAuthenticated(uint64_t deviceId, uint32_t fingerId, uint32_t groupId, const ::android::hardware::hidl_vec<uint8_t>& token)
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprintClientCallback::onError(uint64_t deviceId, ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintError error, int32_t vendorCode)
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprintClientCallback::onRemoved(uint64_t deviceId, uint32_t fingerId, uint32_t groupId, uint32_t remaining)
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprintClientCallback::onEnumerate(uint64_t deviceId, uint32_t fingerId, uint32_t groupId, uint32_t remaining)
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprintClientCallback::onTouchDown(uint64_t deviceId)
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprintClientCallback::onTouchUp(uint64_t deviceId)
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprintClientCallback::onMonitorEventTriggered(uint32_t type, const ::android::hardware::hidl_string& data)
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprintClientCallback::onImageInfoAcquired(uint32_t type, uint32_t quality, uint32_t match_score)
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprintClientCallback::onSyncTemplates(uint64_t deviceId, const ::android::hardware::hidl_vec<uint32_t>& fingerId, uint32_t remaining)
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprintClientCallback::onEngineeringInfoUpdated(uint32_t length, const ::android::hardware::hidl_vec<uint32_t>& keys, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& values)
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprintClientCallback::onFingerprintCmd(int32_t deviceId, const ::android::hardware::hidl_vec<uint32_t>& groupId, uint32_t remaining)
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprintClientCallback::onUIReady(int64_t deviceId)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IBiometricsFingerprintClientCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBiometricsFingerprintClientCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBiometricsFingerprintClientCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBiometricsFingerprintClientCallback::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} /* 0000000000000000000000000000000000000000000000000000000000000000 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBiometricsFingerprintClientCallback::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IBiometricsFingerprintClientCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IBiometricsFingerprintClientCallback::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBiometricsFingerprintClientCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IBiometricsFingerprintClientCallback::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IBiometricsFingerprintClientCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback>> IBiometricsFingerprintClientCallback::castFrom(const ::android::sp<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback>> IBiometricsFingerprintClientCallback::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IBiometricsFingerprintClientCallback, ::android::hidl::base::V1_0::IBase, BpHwBiometricsFingerprintClientCallback>(
            parent, "vendor.oppo.hardware.biometrics.fingerprint@2.1::IBiometricsFingerprintClientCallback", emitError);
}

BpHwBiometricsFingerprintClientCallback::BpHwBiometricsFingerprintClientCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IBiometricsFingerprintClientCallback>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("vendor.oppo.hardware.biometrics.fingerprint@2.1", "IBiometricsFingerprintClientCallback") {
}

void BpHwBiometricsFingerprintClientCallback::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IBiometricsFingerprintClientCallback>::onLastStrongRef(id);
}
// Methods from ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback follow.
::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::_hidl_onEnrollResult(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t deviceId, uint32_t fingerId, uint32_t groupId, uint32_t remaining) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onEnrollResult::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)&fingerId);
        _hidl_args.push_back((void *)&groupId);
        _hidl_args.push_back((void *)&remaining);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onEnrollResult", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprintClientCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(deviceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(fingerId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(groupId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(remaining);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* onEnrollResult */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onEnrollResult", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::_hidl_onAcquired(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t deviceId, ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintAcquiredInfo acquiredInfo, int32_t vendorCode) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onAcquired::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)&acquiredInfo);
        _hidl_args.push_back((void *)&vendorCode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onAcquired", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprintClientCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(deviceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)acquiredInfo);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(vendorCode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* onAcquired */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onAcquired", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::_hidl_onAuthenticated(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t deviceId, uint32_t fingerId, uint32_t groupId, const ::android::hardware::hidl_vec<uint8_t>& token) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onAuthenticated::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)&fingerId);
        _hidl_args.push_back((void *)&groupId);
        _hidl_args.push_back((void *)&token);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onAuthenticated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprintClientCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(deviceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(fingerId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(groupId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_token_parent;

    _hidl_err = _hidl_data.writeBuffer(&token, sizeof(token), &_hidl_token_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_token_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            token,
            &_hidl_data,
            _hidl_token_parent,
            0 /* parentOffset */, &_hidl_token_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* onAuthenticated */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onAuthenticated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::_hidl_onError(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t deviceId, ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintError error, int32_t vendorCode) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onError::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)&error);
        _hidl_args.push_back((void *)&vendorCode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprintClientCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(deviceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(vendorCode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* onError */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::_hidl_onRemoved(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t deviceId, uint32_t fingerId, uint32_t groupId, uint32_t remaining) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onRemoved::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)&fingerId);
        _hidl_args.push_back((void *)&groupId);
        _hidl_args.push_back((void *)&remaining);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onRemoved", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprintClientCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(deviceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(fingerId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(groupId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(remaining);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* onRemoved */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onRemoved", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::_hidl_onEnumerate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t deviceId, uint32_t fingerId, uint32_t groupId, uint32_t remaining) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onEnumerate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)&fingerId);
        _hidl_args.push_back((void *)&groupId);
        _hidl_args.push_back((void *)&remaining);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onEnumerate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprintClientCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(deviceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(fingerId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(groupId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(remaining);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* onEnumerate */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onEnumerate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::_hidl_onTouchDown(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t deviceId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onTouchDown::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onTouchDown", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprintClientCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(deviceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* onTouchDown */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onTouchDown", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::_hidl_onTouchUp(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t deviceId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onTouchUp::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onTouchUp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprintClientCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(deviceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* onTouchUp */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onTouchUp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::_hidl_onMonitorEventTriggered(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t type, const ::android::hardware::hidl_string& data) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onMonitorEventTriggered::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onMonitorEventTriggered", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprintClientCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.writeBuffer(&data, sizeof(data), &_hidl_data_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            data,
            &_hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* onMonitorEventTriggered */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onMonitorEventTriggered", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::_hidl_onImageInfoAcquired(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t type, uint32_t quality, uint32_t match_score) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onImageInfoAcquired::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&quality);
        _hidl_args.push_back((void *)&match_score);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onImageInfoAcquired", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprintClientCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(quality);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(match_score);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* onImageInfoAcquired */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onImageInfoAcquired", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::_hidl_onSyncTemplates(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t deviceId, const ::android::hardware::hidl_vec<uint32_t>& fingerId, uint32_t remaining) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onSyncTemplates::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)&fingerId);
        _hidl_args.push_back((void *)&remaining);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onSyncTemplates", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprintClientCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(deviceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_fingerId_parent;

    _hidl_err = _hidl_data.writeBuffer(&fingerId, sizeof(fingerId), &_hidl_fingerId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_fingerId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            fingerId,
            &_hidl_data,
            _hidl_fingerId_parent,
            0 /* parentOffset */, &_hidl_fingerId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(remaining);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* onSyncTemplates */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onSyncTemplates", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::_hidl_onEngineeringInfoUpdated(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t length, const ::android::hardware::hidl_vec<uint32_t>& keys, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& values) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onEngineeringInfoUpdated::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&length);
        _hidl_args.push_back((void *)&keys);
        _hidl_args.push_back((void *)&values);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onEngineeringInfoUpdated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprintClientCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(length);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keys_parent;

    _hidl_err = _hidl_data.writeBuffer(&keys, sizeof(keys), &_hidl_keys_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keys_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keys,
            &_hidl_data,
            _hidl_keys_parent,
            0 /* parentOffset */, &_hidl_keys_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_values_parent;

    _hidl_err = _hidl_data.writeBuffer(&values, sizeof(values), &_hidl_values_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            values,
            &_hidl_data,
            _hidl_values_parent,
            0 /* parentOffset */, &_hidl_values_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < values.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                values[_hidl_index_0],
                &_hidl_data,
                _hidl_values_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* onEngineeringInfoUpdated */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onEngineeringInfoUpdated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::_hidl_onFingerprintCmd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t deviceId, const ::android::hardware::hidl_vec<uint32_t>& groupId, uint32_t remaining) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onFingerprintCmd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)&groupId);
        _hidl_args.push_back((void *)&remaining);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onFingerprintCmd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprintClientCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(deviceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_groupId_parent;

    _hidl_err = _hidl_data.writeBuffer(&groupId, sizeof(groupId), &_hidl_groupId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_groupId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            groupId,
            &_hidl_data,
            _hidl_groupId_parent,
            0 /* parentOffset */, &_hidl_groupId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(remaining);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* onFingerprintCmd */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onFingerprintCmd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::_hidl_onUIReady(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int64_t deviceId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onUIReady::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onUIReady", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprintClientCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt64(deviceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(14 /* onUIReady */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onUIReady", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback follow.
::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::onEnrollResult(uint64_t deviceId, uint32_t fingerId, uint32_t groupId, uint32_t remaining){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback::_hidl_onEnrollResult(this, this, deviceId, fingerId, groupId, remaining);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::onAcquired(uint64_t deviceId, ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintAcquiredInfo acquiredInfo, int32_t vendorCode){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback::_hidl_onAcquired(this, this, deviceId, acquiredInfo, vendorCode);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::onAuthenticated(uint64_t deviceId, uint32_t fingerId, uint32_t groupId, const ::android::hardware::hidl_vec<uint8_t>& token){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback::_hidl_onAuthenticated(this, this, deviceId, fingerId, groupId, token);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::onError(uint64_t deviceId, ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintError error, int32_t vendorCode){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback::_hidl_onError(this, this, deviceId, error, vendorCode);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::onRemoved(uint64_t deviceId, uint32_t fingerId, uint32_t groupId, uint32_t remaining){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback::_hidl_onRemoved(this, this, deviceId, fingerId, groupId, remaining);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::onEnumerate(uint64_t deviceId, uint32_t fingerId, uint32_t groupId, uint32_t remaining){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback::_hidl_onEnumerate(this, this, deviceId, fingerId, groupId, remaining);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::onTouchDown(uint64_t deviceId){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback::_hidl_onTouchDown(this, this, deviceId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::onTouchUp(uint64_t deviceId){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback::_hidl_onTouchUp(this, this, deviceId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::onMonitorEventTriggered(uint32_t type, const ::android::hardware::hidl_string& data){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback::_hidl_onMonitorEventTriggered(this, this, type, data);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::onImageInfoAcquired(uint32_t type, uint32_t quality, uint32_t match_score){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback::_hidl_onImageInfoAcquired(this, this, type, quality, match_score);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::onSyncTemplates(uint64_t deviceId, const ::android::hardware::hidl_vec<uint32_t>& fingerId, uint32_t remaining){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback::_hidl_onSyncTemplates(this, this, deviceId, fingerId, remaining);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::onEngineeringInfoUpdated(uint32_t length, const ::android::hardware::hidl_vec<uint32_t>& keys, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& values){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback::_hidl_onEngineeringInfoUpdated(this, this, length, keys, values);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::onFingerprintCmd(int32_t deviceId, const ::android::hardware::hidl_vec<uint32_t>& groupId, uint32_t remaining){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback::_hidl_onFingerprintCmd(this, this, deviceId, groupId, remaining);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::onUIReady(int64_t deviceId){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback::_hidl_onUIReady(this, this, deviceId);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwBiometricsFingerprintClientCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprintClientCallback::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwBiometricsFingerprintClientCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwBiometricsFingerprintClientCallback::BnHwBiometricsFingerprintClientCallback(const ::android::sp<IBiometricsFingerprintClientCallback> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "vendor.oppo.hardware.biometrics.fingerprint@2.1", "IBiometricsFingerprintClientCallback") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwBiometricsFingerprintClientCallback::~BnHwBiometricsFingerprintClientCallback() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback follow.
::android::status_t BnHwBiometricsFingerprintClientCallback::_hidl_onEnrollResult(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprintClientCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t deviceId;
    uint32_t fingerId;
    uint32_t groupId;
    uint32_t remaining;

    _hidl_err = _hidl_data.readUint64(&deviceId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&fingerId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&groupId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&remaining);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onEnrollResult::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)&fingerId);
        _hidl_args.push_back((void *)&groupId);
        _hidl_args.push_back((void *)&remaining);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onEnrollResult", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprintClientCallback*>(_hidl_this->getImpl().get())->onEnrollResult(deviceId, fingerId, groupId, remaining);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onEnrollResult", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprintClientCallback::_hidl_onAcquired(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprintClientCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t deviceId;
    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintAcquiredInfo acquiredInfo;
    int32_t vendorCode;

    _hidl_err = _hidl_data.readUint64(&deviceId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&acquiredInfo);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&vendorCode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onAcquired::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)&acquiredInfo);
        _hidl_args.push_back((void *)&vendorCode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onAcquired", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprintClientCallback*>(_hidl_this->getImpl().get())->onAcquired(deviceId, acquiredInfo, vendorCode);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onAcquired", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprintClientCallback::_hidl_onAuthenticated(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprintClientCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t deviceId;
    uint32_t fingerId;
    uint32_t groupId;
    const ::android::hardware::hidl_vec<uint8_t>* token;

    _hidl_err = _hidl_data.readUint64(&deviceId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&fingerId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&groupId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_token_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*token), &_hidl_token_parent,  reinterpret_cast<const void **>(&token));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_token_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*token),
            _hidl_data,
            _hidl_token_parent,
            0 /* parentOffset */, &_hidl_token_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onAuthenticated::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)&fingerId);
        _hidl_args.push_back((void *)&groupId);
        _hidl_args.push_back((void *)token);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onAuthenticated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprintClientCallback*>(_hidl_this->getImpl().get())->onAuthenticated(deviceId, fingerId, groupId, *token);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onAuthenticated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprintClientCallback::_hidl_onError(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprintClientCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t deviceId;
    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintError error;
    int32_t vendorCode;

    _hidl_err = _hidl_data.readUint64(&deviceId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&error);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&vendorCode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onError::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)&error);
        _hidl_args.push_back((void *)&vendorCode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprintClientCallback*>(_hidl_this->getImpl().get())->onError(deviceId, error, vendorCode);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprintClientCallback::_hidl_onRemoved(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprintClientCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t deviceId;
    uint32_t fingerId;
    uint32_t groupId;
    uint32_t remaining;

    _hidl_err = _hidl_data.readUint64(&deviceId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&fingerId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&groupId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&remaining);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onRemoved::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)&fingerId);
        _hidl_args.push_back((void *)&groupId);
        _hidl_args.push_back((void *)&remaining);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onRemoved", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprintClientCallback*>(_hidl_this->getImpl().get())->onRemoved(deviceId, fingerId, groupId, remaining);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onRemoved", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprintClientCallback::_hidl_onEnumerate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprintClientCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t deviceId;
    uint32_t fingerId;
    uint32_t groupId;
    uint32_t remaining;

    _hidl_err = _hidl_data.readUint64(&deviceId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&fingerId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&groupId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&remaining);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onEnumerate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)&fingerId);
        _hidl_args.push_back((void *)&groupId);
        _hidl_args.push_back((void *)&remaining);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onEnumerate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprintClientCallback*>(_hidl_this->getImpl().get())->onEnumerate(deviceId, fingerId, groupId, remaining);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onEnumerate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprintClientCallback::_hidl_onTouchDown(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprintClientCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t deviceId;

    _hidl_err = _hidl_data.readUint64(&deviceId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onTouchDown::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onTouchDown", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprintClientCallback*>(_hidl_this->getImpl().get())->onTouchDown(deviceId);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onTouchDown", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprintClientCallback::_hidl_onTouchUp(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprintClientCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t deviceId;

    _hidl_err = _hidl_data.readUint64(&deviceId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onTouchUp::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onTouchUp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprintClientCallback*>(_hidl_this->getImpl().get())->onTouchUp(deviceId);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onTouchUp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprintClientCallback::_hidl_onMonitorEventTriggered(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprintClientCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t type;
    const ::android::hardware::hidl_string* data;

    _hidl_err = _hidl_data.readUint32(&type);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*data), &_hidl_data_parent,  reinterpret_cast<const void **>(&data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*data),
            _hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onMonitorEventTriggered::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onMonitorEventTriggered", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprintClientCallback*>(_hidl_this->getImpl().get())->onMonitorEventTriggered(type, *data);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onMonitorEventTriggered", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprintClientCallback::_hidl_onImageInfoAcquired(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprintClientCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t type;
    uint32_t quality;
    uint32_t match_score;

    _hidl_err = _hidl_data.readUint32(&type);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&quality);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&match_score);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onImageInfoAcquired::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&quality);
        _hidl_args.push_back((void *)&match_score);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onImageInfoAcquired", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprintClientCallback*>(_hidl_this->getImpl().get())->onImageInfoAcquired(type, quality, match_score);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onImageInfoAcquired", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprintClientCallback::_hidl_onSyncTemplates(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprintClientCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t deviceId;
    const ::android::hardware::hidl_vec<uint32_t>* fingerId;
    uint32_t remaining;

    _hidl_err = _hidl_data.readUint64(&deviceId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_fingerId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*fingerId), &_hidl_fingerId_parent,  reinterpret_cast<const void **>(&fingerId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_fingerId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(*fingerId),
            _hidl_data,
            _hidl_fingerId_parent,
            0 /* parentOffset */, &_hidl_fingerId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&remaining);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onSyncTemplates::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)fingerId);
        _hidl_args.push_back((void *)&remaining);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onSyncTemplates", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprintClientCallback*>(_hidl_this->getImpl().get())->onSyncTemplates(deviceId, *fingerId, remaining);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onSyncTemplates", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprintClientCallback::_hidl_onEngineeringInfoUpdated(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprintClientCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t length;
    const ::android::hardware::hidl_vec<uint32_t>* keys;
    const ::android::hardware::hidl_vec<::android::hardware::hidl_string>* values;

    _hidl_err = _hidl_data.readUint32(&length);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keys_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keys), &_hidl_keys_parent,  reinterpret_cast<const void **>(&keys));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keys_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(*keys),
            _hidl_data,
            _hidl_keys_parent,
            0 /* parentOffset */, &_hidl_keys_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_values_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*values), &_hidl_values_parent,  reinterpret_cast<const void **>(&values));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(*values),
            _hidl_data,
            _hidl_values_parent,
            0 /* parentOffset */, &_hidl_values_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < values->size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>((*values)[_hidl_index_0]),
                _hidl_data,
                _hidl_values_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onEngineeringInfoUpdated::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&length);
        _hidl_args.push_back((void *)keys);
        _hidl_args.push_back((void *)values);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onEngineeringInfoUpdated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprintClientCallback*>(_hidl_this->getImpl().get())->onEngineeringInfoUpdated(length, *keys, *values);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onEngineeringInfoUpdated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprintClientCallback::_hidl_onFingerprintCmd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprintClientCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t deviceId;
    const ::android::hardware::hidl_vec<uint32_t>* groupId;
    uint32_t remaining;

    _hidl_err = _hidl_data.readInt32(&deviceId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_groupId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*groupId), &_hidl_groupId_parent,  reinterpret_cast<const void **>(&groupId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_groupId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(*groupId),
            _hidl_data,
            _hidl_groupId_parent,
            0 /* parentOffset */, &_hidl_groupId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&remaining);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onFingerprintCmd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        _hidl_args.push_back((void *)groupId);
        _hidl_args.push_back((void *)&remaining);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onFingerprintCmd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprintClientCallback*>(_hidl_this->getImpl().get())->onFingerprintCmd(deviceId, *groupId, remaining);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onFingerprintCmd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprintClientCallback::_hidl_onUIReady(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprintClientCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int64_t deviceId;

    _hidl_err = _hidl_data.readInt64(&deviceId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprintClientCallback::onUIReady::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&deviceId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onUIReady", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprintClientCallback*>(_hidl_this->getImpl().get())->onUIReady(deviceId);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprintClientCallback", "onUIReady", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwBiometricsFingerprintClientCallback::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwBiometricsFingerprintClientCallback::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwBiometricsFingerprintClientCallback::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* onEnrollResult */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback::_hidl_onEnrollResult(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* onAcquired */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback::_hidl_onAcquired(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* onAuthenticated */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback::_hidl_onAuthenticated(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* onError */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback::_hidl_onError(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* onRemoved */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback::_hidl_onRemoved(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* onEnumerate */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback::_hidl_onEnumerate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* onTouchDown */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback::_hidl_onTouchDown(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* onTouchUp */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback::_hidl_onTouchUp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* onMonitorEventTriggered */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback::_hidl_onMonitorEventTriggered(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* onImageInfoAcquired */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback::_hidl_onImageInfoAcquired(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* onSyncTemplates */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback::_hidl_onSyncTemplates(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* onEngineeringInfoUpdated */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback::_hidl_onEngineeringInfoUpdated(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* onFingerprintCmd */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback::_hidl_onFingerprintCmd(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* onUIReady */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback::_hidl_onUIReady(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsBiometricsFingerprintClientCallback::BsBiometricsFingerprintClientCallback(const ::android::sp<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback> impl) : ::android::hardware::details::HidlInstrumentor("vendor.oppo.hardware.biometrics.fingerprint@2.1", "IBiometricsFingerprintClientCallback"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsBiometricsFingerprintClientCallback::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IBiometricsFingerprintClientCallback> IBiometricsFingerprintClientCallback::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwBiometricsFingerprintClientCallback>(serviceName, false, getStub);
}

::android::sp<IBiometricsFingerprintClientCallback> IBiometricsFingerprintClientCallback::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwBiometricsFingerprintClientCallback>(serviceName, true, getStub);
}

::android::status_t IBiometricsFingerprintClientCallback::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IBiometricsFingerprintClientCallback::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("vendor.oppo.hardware.biometrics.fingerprint@2.1::IBiometricsFingerprintClientCallback",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_1
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace hardware
}  // namespace oppo
}  // namespace vendor
