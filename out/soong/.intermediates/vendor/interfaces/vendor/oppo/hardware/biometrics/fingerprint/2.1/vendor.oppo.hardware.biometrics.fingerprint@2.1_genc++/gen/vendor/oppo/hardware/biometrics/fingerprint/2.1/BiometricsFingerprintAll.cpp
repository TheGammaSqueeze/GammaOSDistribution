#define LOG_TAG "vendor.oppo.hardware.biometrics.fingerprint@2.1::BiometricsFingerprint"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <vendor/oppo/hardware/biometrics/fingerprint/2.1/BpHwBiometricsFingerprint.h>
#include <vendor/oppo/hardware/biometrics/fingerprint/2.1/BnHwBiometricsFingerprint.h>
#include <vendor/oppo/hardware/biometrics/fingerprint/2.1/BsBiometricsFingerprint.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace vendor {
namespace oppo {
namespace hardware {
namespace biometrics {
namespace fingerprint {
namespace V2_1 {

const char* IBiometricsFingerprint::descriptor("vendor.oppo.hardware.biometrics.fingerprint@2.1::IBiometricsFingerprint");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IBiometricsFingerprint::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwBiometricsFingerprint(static_cast<IBiometricsFingerprint *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IBiometricsFingerprint::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsBiometricsFingerprint(static_cast<IBiometricsFingerprint *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IBiometricsFingerprint::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IBiometricsFingerprint::descriptor);
}

// Methods from ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint follow.
// no default implementation for: ::android::hardware::Return<uint64_t> IBiometricsFingerprint::setNotify(const ::android::sp<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback>& clientCallback)
// no default implementation for: ::android::hardware::Return<uint64_t> IBiometricsFingerprint::preEnroll()
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::enroll(const ::android::hardware::hidl_array<uint8_t, 69>& hat, uint32_t gid, uint32_t timeoutSec)
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::postEnroll()
// no default implementation for: ::android::hardware::Return<uint64_t> IBiometricsFingerprint::getAuthenticatorId()
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::cancel()
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::enumerate()
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::remove(uint32_t gid, uint32_t fid)
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::setActiveGroup(uint32_t gid, const ::android::hardware::hidl_string& storePath)
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::authenticate(uint64_t operationId, uint32_t gid)
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::authenticateAsType(uint64_t auth, uint32_t type, ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintAuthType AuthType)
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::cleanUp()
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::pauseEnroll()
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::continueEnroll()
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::setTouchEventListener()
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::dynamicallyConfigLog(uint32_t log)
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::pauseIdentify()
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::continueIdentify()
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::getAlikeyStatus()
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::getEnrollmentTotalTimes()
// no default implementation for: ::android::hardware::Return<void> IBiometricsFingerprint::setScreenState(::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintScreenState ScreenState)
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::getEngineeringInfo(uint32_t info)
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::touchDown()
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::touchUp()
// no default implementation for: ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> IBiometricsFingerprint::sendFingerprintCmd(int32_t cmd, const ::android::hardware::hidl_vec<int8_t>& CmdId)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IBiometricsFingerprint::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBiometricsFingerprint::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBiometricsFingerprint::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBiometricsFingerprint::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} /* 0000000000000000000000000000000000000000000000000000000000000000 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBiometricsFingerprint::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IBiometricsFingerprint::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IBiometricsFingerprint::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBiometricsFingerprint::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IBiometricsFingerprint::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IBiometricsFingerprint::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint>> IBiometricsFingerprint::castFrom(const ::android::sp<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint>> IBiometricsFingerprint::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IBiometricsFingerprint, ::android::hidl::base::V1_0::IBase, BpHwBiometricsFingerprint>(
            parent, "vendor.oppo.hardware.biometrics.fingerprint@2.1::IBiometricsFingerprint", emitError);
}

BpHwBiometricsFingerprint::BpHwBiometricsFingerprint(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IBiometricsFingerprint>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("vendor.oppo.hardware.biometrics.fingerprint@2.1", "IBiometricsFingerprint") {
}

void BpHwBiometricsFingerprint::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IBiometricsFingerprint>::onLastStrongRef(id);
}
// Methods from ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint follow.
::android::hardware::Return<uint64_t> BpHwBiometricsFingerprint::_hidl_setNotify(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback>& clientCallback) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::setNotify::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&clientCallback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setNotify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_deviceId;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (clientCallback == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(clientCallback.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* setNotify */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_deviceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_deviceId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setNotify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_deviceId);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwBiometricsFingerprint::_hidl_preEnroll(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::preEnroll::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "preEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_authChallenge;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* preEnroll */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_authChallenge);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_authChallenge);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "preEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_authChallenge);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_enroll(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_array<uint8_t, 69>& hat, uint32_t gid, uint32_t timeoutSec) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::enroll::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&hat);
        _hidl_args.push_back((void *)&gid);
        _hidl_args.push_back((void *)&timeoutSec);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "enroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_hat_parent;

    _hidl_err = _hidl_data.writeBuffer(hat.data(), 69 * sizeof(uint8_t), &_hidl_hat_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(gid);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(timeoutSec);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* enroll */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "enroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_postEnroll(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::postEnroll::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "postEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* postEnroll */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "postEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwBiometricsFingerprint::_hidl_getAuthenticatorId(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::getAuthenticatorId::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getAuthenticatorId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_AuthenticatorId;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* getAuthenticatorId */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_AuthenticatorId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_AuthenticatorId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getAuthenticatorId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_AuthenticatorId);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_cancel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::cancel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "cancel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* cancel */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "cancel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_enumerate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::enumerate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "enumerate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* enumerate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "enumerate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_remove(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t gid, uint32_t fid) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::remove::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&gid);
        _hidl_args.push_back((void *)&fid);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "remove", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(gid);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(fid);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* remove */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "remove", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_setActiveGroup(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t gid, const ::android::hardware::hidl_string& storePath) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::setActiveGroup::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&gid);
        _hidl_args.push_back((void *)&storePath);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setActiveGroup", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(gid);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_storePath_parent;

    _hidl_err = _hidl_data.writeBuffer(&storePath, sizeof(storePath), &_hidl_storePath_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            storePath,
            &_hidl_data,
            _hidl_storePath_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* setActiveGroup */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setActiveGroup", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_authenticate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t operationId, uint32_t gid) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::authenticate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&operationId);
        _hidl_args.push_back((void *)&gid);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "authenticate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(operationId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(gid);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* authenticate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "authenticate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_authenticateAsType(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t auth, uint32_t type, ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintAuthType AuthType) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::authenticateAsType::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&auth);
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&AuthType);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "authenticateAsType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(auth);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)AuthType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* authenticateAsType */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "authenticateAsType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_cleanUp(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::cleanUp::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "cleanUp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* cleanUp */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "cleanUp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_pauseEnroll(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::pauseEnroll::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "pauseEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* pauseEnroll */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "pauseEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_continueEnroll(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::continueEnroll::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "continueEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(14 /* continueEnroll */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "continueEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_setTouchEventListener(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::setTouchEventListener::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setTouchEventListener", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(15 /* setTouchEventListener */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setTouchEventListener", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_dynamicallyConfigLog(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t log) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::dynamicallyConfigLog::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&log);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "dynamicallyConfigLog", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(log);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(16 /* dynamicallyConfigLog */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "dynamicallyConfigLog", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_pauseIdentify(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::pauseIdentify::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "pauseIdentify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(17 /* pauseIdentify */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "pauseIdentify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_continueIdentify(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::continueIdentify::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "continueIdentify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(18 /* continueIdentify */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "continueIdentify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_getAlikeyStatus(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::getAlikeyStatus::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getAlikeyStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(19 /* getAlikeyStatus */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getAlikeyStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_getEnrollmentTotalTimes(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::getEnrollmentTotalTimes::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getEnrollmentTotalTimes", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(20 /* getEnrollmentTotalTimes */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getEnrollmentTotalTimes", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<void> BpHwBiometricsFingerprint::_hidl_setScreenState(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintScreenState ScreenState) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::setScreenState::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&ScreenState);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setScreenState", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)ScreenState);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(21 /* setScreenState */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setScreenState", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_getEngineeringInfo(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::getEngineeringInfo::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getEngineeringInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(info);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(22 /* getEngineeringInfo */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getEngineeringInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_touchDown(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::touchDown::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "touchDown", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(23 /* touchDown */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "touchDown", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_touchUp(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::touchUp::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "touchUp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(24 /* touchUp */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "touchUp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::_hidl_sendFingerprintCmd(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t cmd, const ::android::hardware::hidl_vec<int8_t>& CmdId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::sendFingerprintCmd::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmd);
        _hidl_args.push_back((void *)&CmdId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "sendFingerprintCmd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBiometricsFingerprint::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(cmd);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_CmdId_parent;

    _hidl_err = _hidl_data.writeBuffer(&CmdId, sizeof(CmdId), &_hidl_CmdId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_CmdId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            CmdId,
            &_hidl_data,
            _hidl_CmdId_parent,
            0 /* parentOffset */, &_hidl_CmdId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(25 /* sendFingerprintCmd */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "sendFingerprintCmd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_out_debugErrno);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>(_hidl_status);
}


// Methods from ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint follow.
::android::hardware::Return<uint64_t> BpHwBiometricsFingerprint::setNotify(const ::android::sp<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback>& clientCallback){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_setNotify(this, this, clientCallback);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwBiometricsFingerprint::preEnroll(){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_preEnroll(this, this);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::enroll(const ::android::hardware::hidl_array<uint8_t, 69>& hat, uint32_t gid, uint32_t timeoutSec){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_enroll(this, this, hat, gid, timeoutSec);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::postEnroll(){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_postEnroll(this, this);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwBiometricsFingerprint::getAuthenticatorId(){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_getAuthenticatorId(this, this);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::cancel(){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_cancel(this, this);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::enumerate(){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_enumerate(this, this);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::remove(uint32_t gid, uint32_t fid){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_remove(this, this, gid, fid);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::setActiveGroup(uint32_t gid, const ::android::hardware::hidl_string& storePath){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_setActiveGroup(this, this, gid, storePath);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::authenticate(uint64_t operationId, uint32_t gid){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_authenticate(this, this, operationId, gid);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::authenticateAsType(uint64_t auth, uint32_t type, ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintAuthType AuthType){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_authenticateAsType(this, this, auth, type, AuthType);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::cleanUp(){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_cleanUp(this, this);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::pauseEnroll(){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_pauseEnroll(this, this);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::continueEnroll(){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_continueEnroll(this, this);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::setTouchEventListener(){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_setTouchEventListener(this, this);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::dynamicallyConfigLog(uint32_t log){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_dynamicallyConfigLog(this, this, log);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::pauseIdentify(){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_pauseIdentify(this, this);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::continueIdentify(){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_continueIdentify(this, this);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::getAlikeyStatus(){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_getAlikeyStatus(this, this);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::getEnrollmentTotalTimes(){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_getEnrollmentTotalTimes(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprint::setScreenState(::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintScreenState ScreenState){
    ::android::hardware::Return<void>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_setScreenState(this, this, ScreenState);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::getEngineeringInfo(uint32_t info){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_getEngineeringInfo(this, this, info);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::touchDown(){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_touchDown(this, this);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::touchUp(){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_touchUp(this, this);

    return _hidl_out;
}

::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus> BpHwBiometricsFingerprint::sendFingerprintCmd(int32_t cmd, const ::android::hardware::hidl_vec<int8_t>& CmdId){
    ::android::hardware::Return<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_out = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprint::_hidl_sendFingerprintCmd(this, this, cmd, CmdId);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwBiometricsFingerprint::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprint::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprint::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprint::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprint::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwBiometricsFingerprint::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwBiometricsFingerprint::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprint::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBiometricsFingerprint::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwBiometricsFingerprint::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwBiometricsFingerprint::BnHwBiometricsFingerprint(const ::android::sp<IBiometricsFingerprint> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "vendor.oppo.hardware.biometrics.fingerprint@2.1", "IBiometricsFingerprint") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwBiometricsFingerprint::~BnHwBiometricsFingerprint() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint follow.
::android::status_t BnHwBiometricsFingerprint::_hidl_setNotify(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::sp<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback> clientCallback;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        clientCallback = ::android::hardware::fromBinder<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback,::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BpHwBiometricsFingerprintClientCallback,::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprintClientCallback>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::setNotify::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&clientCallback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setNotify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_deviceId = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->setNotify(clientCallback);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_deviceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_deviceId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setNotify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_preEnroll(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::preEnroll::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "preEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_authChallenge = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->preEnroll();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_authChallenge);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_authChallenge);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "preEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_enroll(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_array<uint8_t, 69>* hat;
    uint32_t gid;
    uint32_t timeoutSec;

    size_t _hidl_hat_parent;

    _hidl_err = _hidl_data.readBuffer(69 * sizeof(uint8_t), &_hidl_hat_parent,  reinterpret_cast<const void **>(&hat));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&gid);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&timeoutSec);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::enroll::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)hat);
        _hidl_args.push_back((void *)&gid);
        _hidl_args.push_back((void *)&timeoutSec);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "enroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->enroll(*hat, gid, timeoutSec);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "enroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_postEnroll(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::postEnroll::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "postEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->postEnroll();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "postEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_getAuthenticatorId(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::getAuthenticatorId::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getAuthenticatorId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_AuthenticatorId = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->getAuthenticatorId();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_AuthenticatorId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_AuthenticatorId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getAuthenticatorId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_cancel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::cancel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "cancel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->cancel();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "cancel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_enumerate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::enumerate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "enumerate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->enumerate();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "enumerate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_remove(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t gid;
    uint32_t fid;

    _hidl_err = _hidl_data.readUint32(&gid);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&fid);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::remove::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&gid);
        _hidl_args.push_back((void *)&fid);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "remove", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->remove(gid, fid);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "remove", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_setActiveGroup(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t gid;
    const ::android::hardware::hidl_string* storePath;

    _hidl_err = _hidl_data.readUint32(&gid);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_storePath_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*storePath), &_hidl_storePath_parent,  reinterpret_cast<const void **>(&storePath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*storePath),
            _hidl_data,
            _hidl_storePath_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::setActiveGroup::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&gid);
        _hidl_args.push_back((void *)storePath);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setActiveGroup", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->setActiveGroup(gid, *storePath);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setActiveGroup", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_authenticate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t operationId;
    uint32_t gid;

    _hidl_err = _hidl_data.readUint64(&operationId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&gid);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::authenticate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&operationId);
        _hidl_args.push_back((void *)&gid);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "authenticate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->authenticate(operationId, gid);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "authenticate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_authenticateAsType(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t auth;
    uint32_t type;
    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintAuthType AuthType;

    _hidl_err = _hidl_data.readUint64(&auth);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&type);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&AuthType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::authenticateAsType::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&auth);
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&AuthType);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "authenticateAsType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->authenticateAsType(auth, type, AuthType);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "authenticateAsType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_cleanUp(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::cleanUp::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "cleanUp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->cleanUp();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "cleanUp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_pauseEnroll(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::pauseEnroll::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "pauseEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->pauseEnroll();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "pauseEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_continueEnroll(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::continueEnroll::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "continueEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->continueEnroll();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "continueEnroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_setTouchEventListener(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::setTouchEventListener::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setTouchEventListener", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->setTouchEventListener();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setTouchEventListener", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_dynamicallyConfigLog(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t log;

    _hidl_err = _hidl_data.readUint32(&log);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::dynamicallyConfigLog::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&log);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "dynamicallyConfigLog", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->dynamicallyConfigLog(log);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "dynamicallyConfigLog", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_pauseIdentify(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::pauseIdentify::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "pauseIdentify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->pauseIdentify();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "pauseIdentify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_continueIdentify(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::continueIdentify::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "continueIdentify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->continueIdentify();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "continueIdentify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_getAlikeyStatus(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::getAlikeyStatus::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getAlikeyStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->getAlikeyStatus();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getAlikeyStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_getEnrollmentTotalTimes(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::getEnrollmentTotalTimes::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getEnrollmentTotalTimes", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->getEnrollmentTotalTimes();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getEnrollmentTotalTimes", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_setScreenState(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::FingerprintScreenState ScreenState;

    _hidl_err = _hidl_data.readInt32((int32_t *)&ScreenState);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::setScreenState::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&ScreenState);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setScreenState", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->setScreenState(ScreenState);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "setScreenState", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_getEngineeringInfo(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t info;

    _hidl_err = _hidl_data.readUint32(&info);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::getEngineeringInfo::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getEngineeringInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->getEngineeringInfo(info);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "getEngineeringInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_touchDown(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::touchDown::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "touchDown", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->touchDown();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "touchDown", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_touchUp(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::touchUp::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "touchUp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->touchUp();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "touchUp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwBiometricsFingerprint::_hidl_sendFingerprintCmd(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBiometricsFingerprint::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t cmd;
    const ::android::hardware::hidl_vec<int8_t>* CmdId;

    _hidl_err = _hidl_data.readInt32(&cmd);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_CmdId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*CmdId), &_hidl_CmdId_parent,  reinterpret_cast<const void **>(&CmdId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_CmdId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int8_t> &>(*CmdId),
            _hidl_data,
            _hidl_CmdId_parent,
            0 /* parentOffset */, &_hidl_CmdId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBiometricsFingerprint::sendFingerprintCmd::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmd);
        _hidl_args.push_back((void *)CmdId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "sendFingerprintCmd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::RequestStatus _hidl_out_debugErrno = static_cast<IBiometricsFingerprint*>(_hidl_this->getImpl().get())->sendFingerprintCmd(cmd, *CmdId);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_debugErrno);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_debugErrno);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.oppo.hardware.biometrics.fingerprint", "2.1", "IBiometricsFingerprint", "sendFingerprintCmd", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwBiometricsFingerprint::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwBiometricsFingerprint::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwBiometricsFingerprint::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* setNotify */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_setNotify(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* preEnroll */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_preEnroll(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* enroll */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_enroll(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* postEnroll */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_postEnroll(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* getAuthenticatorId */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_getAuthenticatorId(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* cancel */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_cancel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* enumerate */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_enumerate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* remove */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_remove(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* setActiveGroup */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_setActiveGroup(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* authenticate */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_authenticate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* authenticateAsType */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_authenticateAsType(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* cleanUp */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_cleanUp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* pauseEnroll */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_pauseEnroll(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* continueEnroll */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_continueEnroll(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* setTouchEventListener */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_setTouchEventListener(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* dynamicallyConfigLog */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_dynamicallyConfigLog(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* pauseIdentify */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_pauseIdentify(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* continueIdentify */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_continueIdentify(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 19 /* getAlikeyStatus */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_getAlikeyStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 20 /* getEnrollmentTotalTimes */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_getEnrollmentTotalTimes(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 21 /* setScreenState */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_setScreenState(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 22 /* getEngineeringInfo */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_getEngineeringInfo(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 23 /* touchDown */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_touchDown(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 24 /* touchUp */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_touchUp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 25 /* sendFingerprintCmd */:
        {
            _hidl_err = ::vendor::oppo::hardware::biometrics::fingerprint::V2_1::BnHwBiometricsFingerprint::_hidl_sendFingerprintCmd(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsBiometricsFingerprint::BsBiometricsFingerprint(const ::android::sp<::vendor::oppo::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint> impl) : ::android::hardware::details::HidlInstrumentor("vendor.oppo.hardware.biometrics.fingerprint@2.1", "IBiometricsFingerprint"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsBiometricsFingerprint::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IBiometricsFingerprint> IBiometricsFingerprint::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwBiometricsFingerprint>(serviceName, false, getStub);
}

::android::sp<IBiometricsFingerprint> IBiometricsFingerprint::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwBiometricsFingerprint>(serviceName, true, getStub);
}

::android::status_t IBiometricsFingerprint::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IBiometricsFingerprint::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("vendor.oppo.hardware.biometrics.fingerprint@2.1::IBiometricsFingerprint",
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
