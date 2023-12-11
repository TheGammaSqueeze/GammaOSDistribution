#define LOG_TAG "android.frameworks.cameraservice.device@2.0::CameraDeviceCallback"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/frameworks/cameraservice/device/2.0/BpHwCameraDeviceCallback.h>
#include <android/frameworks/cameraservice/device/2.0/BnHwCameraDeviceCallback.h>
#include <android/frameworks/cameraservice/device/2.0/BsCameraDeviceCallback.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace frameworks {
namespace cameraservice {
namespace device {
namespace V2_0 {

const char* ICameraDeviceCallback::descriptor("android.frameworks.cameraservice.device@2.0::ICameraDeviceCallback");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ICameraDeviceCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwCameraDeviceCallback(static_cast<ICameraDeviceCallback *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ICameraDeviceCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsCameraDeviceCallback(static_cast<ICameraDeviceCallback *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ICameraDeviceCallback::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ICameraDeviceCallback::descriptor);
}

// Methods from ::android::frameworks::cameraservice::device::V2_0::ICameraDeviceCallback follow.
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::onDeviceError(::android::frameworks::cameraservice::device::V2_0::ErrorCode errorCode, const ::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras& resultExtras)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::onDeviceIdle()
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::onCaptureStarted(const ::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras& resultExtras, uint64_t timestamp)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::onResultReceived(const ::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata& result, const ::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras& resultExtras, const ::android::hardware::hidl_vec<::android::frameworks::cameraservice::device::V2_0::PhysicalCaptureResultInfo>& physicalCaptureResultInfos)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::onRepeatingRequestError(uint64_t lastFrameNumber, int32_t repeatingRequestId)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ICameraDeviceCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::frameworks::cameraservice::device::V2_0::ICameraDeviceCallback::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::frameworks::cameraservice::device::V2_0::ICameraDeviceCallback::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceCallback::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){69,26,6,70,148,248,124,219,126,36,64,12,36,111,167,151,78,204,176,90,91,246,189,218,209,117,82,31,209,138,145,133} /* 451a064694f87cdb7e24400c246fa7974eccb05a5bf6bddad175521fd18a9185 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceCallback::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraDeviceCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ICameraDeviceCallback::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ICameraDeviceCallback::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraDeviceCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::frameworks::cameraservice::device::V2_0::ICameraDeviceCallback>> ICameraDeviceCallback::castFrom(const ::android::sp<::android::frameworks::cameraservice::device::V2_0::ICameraDeviceCallback>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::frameworks::cameraservice::device::V2_0::ICameraDeviceCallback>> ICameraDeviceCallback::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraDeviceCallback, ::android::hidl::base::V1_0::IBase, BpHwCameraDeviceCallback>(
            parent, "android.frameworks.cameraservice.device@2.0::ICameraDeviceCallback", emitError);
}

BpHwCameraDeviceCallback::BpHwCameraDeviceCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ICameraDeviceCallback>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.frameworks.cameraservice.device@2.0", "ICameraDeviceCallback") {
}

void BpHwCameraDeviceCallback::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ICameraDeviceCallback>::onLastStrongRef(id);
}
// Methods from ::android::frameworks::cameraservice::device::V2_0::ICameraDeviceCallback follow.
::android::hardware::Return<void> BpHwCameraDeviceCallback::_hidl_onDeviceError(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::frameworks::cameraservice::device::V2_0::ErrorCode errorCode, const ::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras& resultExtras) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::onDeviceError::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&errorCode);
        _hidl_args.push_back((void *)&resultExtras);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onDeviceError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)errorCode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_resultExtras_parent;

    _hidl_err = _hidl_data.writeBuffer(&resultExtras, sizeof(resultExtras), &_hidl_resultExtras_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            resultExtras,
            &_hidl_data,
            _hidl_resultExtras_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* onDeviceError */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onDeviceError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::_hidl_onDeviceIdle(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::onDeviceIdle::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onDeviceIdle", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* onDeviceIdle */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onDeviceIdle", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::_hidl_onCaptureStarted(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras& resultExtras, uint64_t timestamp) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::onCaptureStarted::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&resultExtras);
        _hidl_args.push_back((void *)&timestamp);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onCaptureStarted", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_resultExtras_parent;

    _hidl_err = _hidl_data.writeBuffer(&resultExtras, sizeof(resultExtras), &_hidl_resultExtras_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            resultExtras,
            &_hidl_data,
            _hidl_resultExtras_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(timestamp);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* onCaptureStarted */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onCaptureStarted", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::_hidl_onResultReceived(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata& result, const ::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras& resultExtras, const ::android::hardware::hidl_vec<::android::frameworks::cameraservice::device::V2_0::PhysicalCaptureResultInfo>& physicalCaptureResultInfos) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::onResultReceived::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&result);
        _hidl_args.push_back((void *)&resultExtras);
        _hidl_args.push_back((void *)&physicalCaptureResultInfos);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onResultReceived", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_result_parent;

    _hidl_err = _hidl_data.writeBuffer(&result, sizeof(result), &_hidl_result_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            result,
            &_hidl_data,
            _hidl_result_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_resultExtras_parent;

    _hidl_err = _hidl_data.writeBuffer(&resultExtras, sizeof(resultExtras), &_hidl_resultExtras_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            resultExtras,
            &_hidl_data,
            _hidl_resultExtras_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_physicalCaptureResultInfos_parent;

    _hidl_err = _hidl_data.writeBuffer(&physicalCaptureResultInfos, sizeof(physicalCaptureResultInfos), &_hidl_physicalCaptureResultInfos_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_physicalCaptureResultInfos_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            physicalCaptureResultInfos,
            &_hidl_data,
            _hidl_physicalCaptureResultInfos_parent,
            0 /* parentOffset */, &_hidl_physicalCaptureResultInfos_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < physicalCaptureResultInfos.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                physicalCaptureResultInfos[_hidl_index_0],
                &_hidl_data,
                _hidl_physicalCaptureResultInfos_child,
                _hidl_index_0 * sizeof(::android::frameworks::cameraservice::device::V2_0::PhysicalCaptureResultInfo));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* onResultReceived */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onResultReceived", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::_hidl_onRepeatingRequestError(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t lastFrameNumber, int32_t repeatingRequestId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::onRepeatingRequestError::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&lastFrameNumber);
        _hidl_args.push_back((void *)&repeatingRequestId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onRepeatingRequestError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(lastFrameNumber);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(repeatingRequestId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* onRepeatingRequestError */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onRepeatingRequestError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::frameworks::cameraservice::device::V2_0::ICameraDeviceCallback follow.
::android::hardware::Return<void> BpHwCameraDeviceCallback::onDeviceError(::android::frameworks::cameraservice::device::V2_0::ErrorCode errorCode, const ::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras& resultExtras){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceCallback::_hidl_onDeviceError(this, this, errorCode, resultExtras);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::onDeviceIdle(){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceCallback::_hidl_onDeviceIdle(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::onCaptureStarted(const ::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras& resultExtras, uint64_t timestamp){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceCallback::_hidl_onCaptureStarted(this, this, resultExtras, timestamp);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::onResultReceived(const ::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata& result, const ::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras& resultExtras, const ::android::hardware::hidl_vec<::android::frameworks::cameraservice::device::V2_0::PhysicalCaptureResultInfo>& physicalCaptureResultInfos){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceCallback::_hidl_onResultReceived(this, this, result, resultExtras, physicalCaptureResultInfos);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::onRepeatingRequestError(uint64_t lastFrameNumber, int32_t repeatingRequestId){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceCallback::_hidl_onRepeatingRequestError(this, this, lastFrameNumber, repeatingRequestId);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwCameraDeviceCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraDeviceCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraDeviceCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwCameraDeviceCallback::BnHwCameraDeviceCallback(const ::android::sp<ICameraDeviceCallback> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.frameworks.cameraservice.device@2.0", "ICameraDeviceCallback") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwCameraDeviceCallback::~BnHwCameraDeviceCallback() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::frameworks::cameraservice::device::V2_0::ICameraDeviceCallback follow.
::android::status_t BnHwCameraDeviceCallback::_hidl_onDeviceError(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::frameworks::cameraservice::device::V2_0::ErrorCode errorCode;
    ::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras* resultExtras;

    _hidl_err = _hidl_data.readInt32((int32_t *)&errorCode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_resultExtras_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*resultExtras), &_hidl_resultExtras_parent,  const_cast<const void**>(reinterpret_cast<void **>(&resultExtras)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras &>(*resultExtras),
            _hidl_data,
            _hidl_resultExtras_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::onDeviceError::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&errorCode);
        _hidl_args.push_back((void *)resultExtras);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onDeviceError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceCallback*>(_hidl_this->getImpl().get())->onDeviceError(errorCode, *resultExtras);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onDeviceError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceCallback::_hidl_onDeviceIdle(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::onDeviceIdle::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onDeviceIdle", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceCallback*>(_hidl_this->getImpl().get())->onDeviceIdle();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onDeviceIdle", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceCallback::_hidl_onCaptureStarted(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras* resultExtras;
    uint64_t timestamp;

    size_t _hidl_resultExtras_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*resultExtras), &_hidl_resultExtras_parent,  const_cast<const void**>(reinterpret_cast<void **>(&resultExtras)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras &>(*resultExtras),
            _hidl_data,
            _hidl_resultExtras_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&timestamp);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::onCaptureStarted::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)resultExtras);
        _hidl_args.push_back((void *)&timestamp);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onCaptureStarted", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceCallback*>(_hidl_this->getImpl().get())->onCaptureStarted(*resultExtras, timestamp);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onCaptureStarted", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceCallback::_hidl_onResultReceived(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata* result;
    ::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras* resultExtras;
    const ::android::hardware::hidl_vec<::android::frameworks::cameraservice::device::V2_0::PhysicalCaptureResultInfo>* physicalCaptureResultInfos;

    size_t _hidl_result_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*result), &_hidl_result_parent,  const_cast<const void**>(reinterpret_cast<void **>(&result)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata &>(*result),
            _hidl_data,
            _hidl_result_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_resultExtras_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*resultExtras), &_hidl_resultExtras_parent,  const_cast<const void**>(reinterpret_cast<void **>(&resultExtras)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras &>(*resultExtras),
            _hidl_data,
            _hidl_resultExtras_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_physicalCaptureResultInfos_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*physicalCaptureResultInfos), &_hidl_physicalCaptureResultInfos_parent,  reinterpret_cast<const void **>(&physicalCaptureResultInfos));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_physicalCaptureResultInfos_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::frameworks::cameraservice::device::V2_0::PhysicalCaptureResultInfo> &>(*physicalCaptureResultInfos),
            _hidl_data,
            _hidl_physicalCaptureResultInfos_parent,
            0 /* parentOffset */, &_hidl_physicalCaptureResultInfos_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < physicalCaptureResultInfos->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::frameworks::cameraservice::device::V2_0::PhysicalCaptureResultInfo &>((*physicalCaptureResultInfos)[_hidl_index_0]),
                _hidl_data,
                _hidl_physicalCaptureResultInfos_child,
                _hidl_index_0 * sizeof(::android::frameworks::cameraservice::device::V2_0::PhysicalCaptureResultInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::onResultReceived::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)result);
        _hidl_args.push_back((void *)resultExtras);
        _hidl_args.push_back((void *)physicalCaptureResultInfos);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onResultReceived", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceCallback*>(_hidl_this->getImpl().get())->onResultReceived(*result, *resultExtras, *physicalCaptureResultInfos);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onResultReceived", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceCallback::_hidl_onRepeatingRequestError(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t lastFrameNumber;
    int32_t repeatingRequestId;

    _hidl_err = _hidl_data.readUint64(&lastFrameNumber);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&repeatingRequestId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::onRepeatingRequestError::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&lastFrameNumber);
        _hidl_args.push_back((void *)&repeatingRequestId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onRepeatingRequestError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceCallback*>(_hidl_this->getImpl().get())->onRepeatingRequestError(lastFrameNumber, repeatingRequestId);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceCallback", "onRepeatingRequestError", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::frameworks::cameraservice::device::V2_0::ICameraDeviceCallback follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwCameraDeviceCallback::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwCameraDeviceCallback::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwCameraDeviceCallback::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* onDeviceError */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceCallback::_hidl_onDeviceError(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* onDeviceIdle */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceCallback::_hidl_onDeviceIdle(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* onCaptureStarted */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceCallback::_hidl_onCaptureStarted(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* onResultReceived */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceCallback::_hidl_onResultReceived(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* onRepeatingRequestError */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceCallback::_hidl_onRepeatingRequestError(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsCameraDeviceCallback::BsCameraDeviceCallback(const ::android::sp<::android::frameworks::cameraservice::device::V2_0::ICameraDeviceCallback> impl) : ::android::hardware::details::HidlInstrumentor("android.frameworks.cameraservice.device@2.0", "ICameraDeviceCallback"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsCameraDeviceCallback::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ICameraDeviceCallback> ICameraDeviceCallback::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraDeviceCallback>(serviceName, false, getStub);
}

::android::sp<ICameraDeviceCallback> ICameraDeviceCallback::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraDeviceCallback>(serviceName, true, getStub);
}

::android::status_t ICameraDeviceCallback::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ICameraDeviceCallback::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.frameworks.cameraservice.device@2.0::ICameraDeviceCallback",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_0
}  // namespace device
}  // namespace cameraservice
}  // namespace frameworks
}  // namespace android
