#define LOG_TAG "android.hardware.camera.device@1.0::CameraDeviceCallback"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/camera/device/1.0/BpHwCameraDeviceCallback.h>
#include <android/hardware/camera/device/1.0/BnHwCameraDeviceCallback.h>
#include <android/hardware/camera/device/1.0/BsCameraDeviceCallback.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace camera {
namespace device {
namespace V1_0 {

const char* ICameraDeviceCallback::descriptor("android.hardware.camera.device@1.0::ICameraDeviceCallback");

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

// Methods from ::android::hardware::camera::device::V1_0::ICameraDeviceCallback follow.
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::notifyCallback(::android::hardware::camera::device::V1_0::NotifyCallbackMsg msgType, int32_t ext1, int32_t ext2)
// no default implementation for: ::android::hardware::Return<uint32_t> ICameraDeviceCallback::registerMemory(const ::android::hardware::hidl_handle& descriptor, uint32_t bufferSize, uint32_t bufferCount)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::unregisterMemory(uint32_t memId)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::dataCallback(::android::hardware::camera::device::V1_0::DataCallbackMsg msgType, uint32_t data, uint32_t bufferIndex, const ::android::hardware::camera::device::V1_0::CameraFrameMetadata& metadata)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::dataCallbackTimestamp(::android::hardware::camera::device::V1_0::DataCallbackMsg msgType, uint32_t data, uint32_t bufferIndex, int64_t timestamp)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::handleCallbackTimestamp(::android::hardware::camera::device::V1_0::DataCallbackMsg msgType, const ::android::hardware::hidl_handle& frameData, uint32_t data, uint32_t bufferIndex, int64_t timestamp)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::handleCallbackTimestampBatch(::android::hardware::camera::device::V1_0::DataCallbackMsg msgType, const ::android::hardware::hidl_vec<::android::hardware::camera::device::V1_0::HandleTimestampMessage>& batch)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ICameraDeviceCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::camera::device::V1_0::ICameraDeviceCallback::descriptor,
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
    _hidl_cb(::android::hardware::camera::device::V1_0::ICameraDeviceCallback::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceCallback::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){120,233,180,76,248,102,11,220,30,152,220,160,116,81,128,65,83,130,78,252,210,141,178,8,166,47,90,215,40,244,64,118} /* 78e9b44cf8660bdc1e98dca07451804153824efcd28db208a62f5ad728f44076 */,
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


::android::hardware::Return<::android::sp<::android::hardware::camera::device::V1_0::ICameraDeviceCallback>> ICameraDeviceCallback::castFrom(const ::android::sp<::android::hardware::camera::device::V1_0::ICameraDeviceCallback>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::camera::device::V1_0::ICameraDeviceCallback>> ICameraDeviceCallback::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraDeviceCallback, ::android::hidl::base::V1_0::IBase, BpHwCameraDeviceCallback>(
            parent, "android.hardware.camera.device@1.0::ICameraDeviceCallback", emitError);
}

BpHwCameraDeviceCallback::BpHwCameraDeviceCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ICameraDeviceCallback>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.camera.device@1.0", "ICameraDeviceCallback") {
}

void BpHwCameraDeviceCallback::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ICameraDeviceCallback>::onLastStrongRef(id);
}
// Methods from ::android::hardware::camera::device::V1_0::ICameraDeviceCallback follow.
::android::hardware::Return<void> BpHwCameraDeviceCallback::_hidl_notifyCallback(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::camera::device::V1_0::NotifyCallbackMsg msgType, int32_t ext1, int32_t ext2) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::notifyCallback::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&msgType);
        _hidl_args.push_back((void *)&ext1);
        _hidl_args.push_back((void *)&ext2);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "notifyCallback", &_hidl_args);
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

    _hidl_err = _hidl_data.writeUint32((uint32_t)msgType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(ext1);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(ext2);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* notifyCallback */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "notifyCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<uint32_t> BpHwCameraDeviceCallback::_hidl_registerMemory(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_handle& descriptor, uint32_t bufferSize, uint32_t bufferCount) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::registerMemory::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&descriptor);
        _hidl_args.push_back((void *)&bufferSize);
        _hidl_args.push_back((void *)&bufferCount);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "registerMemory", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint32_t _hidl_out_memId;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeNativeHandleNoDup(descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(bufferSize);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(bufferCount);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* registerMemory */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32(&_hidl_out_memId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_memId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "registerMemory", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint32_t>(_hidl_out_memId);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint32_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::_hidl_unregisterMemory(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t memId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::unregisterMemory::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&memId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "unregisterMemory", &_hidl_args);
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

    _hidl_err = _hidl_data.writeUint32(memId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* unregisterMemory */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "unregisterMemory", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::_hidl_dataCallback(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::camera::device::V1_0::DataCallbackMsg msgType, uint32_t data, uint32_t bufferIndex, const ::android::hardware::camera::device::V1_0::CameraFrameMetadata& metadata) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::dataCallback::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&msgType);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&bufferIndex);
        _hidl_args.push_back((void *)&metadata);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "dataCallback", &_hidl_args);
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

    _hidl_err = _hidl_data.writeUint32((uint32_t)msgType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(data);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(bufferIndex);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_metadata_parent;

    _hidl_err = _hidl_data.writeBuffer(&metadata, sizeof(metadata), &_hidl_metadata_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            metadata,
            &_hidl_data,
            _hidl_metadata_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* dataCallback */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "dataCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::_hidl_dataCallbackTimestamp(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::camera::device::V1_0::DataCallbackMsg msgType, uint32_t data, uint32_t bufferIndex, int64_t timestamp) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::dataCallbackTimestamp::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&msgType);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&bufferIndex);
        _hidl_args.push_back((void *)&timestamp);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "dataCallbackTimestamp", &_hidl_args);
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

    _hidl_err = _hidl_data.writeUint32((uint32_t)msgType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(data);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(bufferIndex);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt64(timestamp);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* dataCallbackTimestamp */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "dataCallbackTimestamp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::_hidl_handleCallbackTimestamp(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::camera::device::V1_0::DataCallbackMsg msgType, const ::android::hardware::hidl_handle& frameData, uint32_t data, uint32_t bufferIndex, int64_t timestamp) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::handleCallbackTimestamp::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&msgType);
        _hidl_args.push_back((void *)&frameData);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&bufferIndex);
        _hidl_args.push_back((void *)&timestamp);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "handleCallbackTimestamp", &_hidl_args);
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

    _hidl_err = _hidl_data.writeUint32((uint32_t)msgType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeNativeHandleNoDup(frameData);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(data);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(bufferIndex);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt64(timestamp);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* handleCallbackTimestamp */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "handleCallbackTimestamp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::_hidl_handleCallbackTimestampBatch(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::camera::device::V1_0::DataCallbackMsg msgType, const ::android::hardware::hidl_vec<::android::hardware::camera::device::V1_0::HandleTimestampMessage>& batch) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::handleCallbackTimestampBatch::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&msgType);
        _hidl_args.push_back((void *)&batch);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "handleCallbackTimestampBatch", &_hidl_args);
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

    _hidl_err = _hidl_data.writeUint32((uint32_t)msgType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_batch_parent;

    _hidl_err = _hidl_data.writeBuffer(&batch, sizeof(batch), &_hidl_batch_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_batch_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            batch,
            &_hidl_data,
            _hidl_batch_parent,
            0 /* parentOffset */, &_hidl_batch_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < batch.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                batch[_hidl_index_0],
                &_hidl_data,
                _hidl_batch_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V1_0::HandleTimestampMessage));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* handleCallbackTimestampBatch */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "handleCallbackTimestampBatch", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::camera::device::V1_0::ICameraDeviceCallback follow.
::android::hardware::Return<void> BpHwCameraDeviceCallback::notifyCallback(::android::hardware::camera::device::V1_0::NotifyCallbackMsg msgType, int32_t ext1, int32_t ext2){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V1_0::BpHwCameraDeviceCallback::_hidl_notifyCallback(this, this, msgType, ext1, ext2);

    return _hidl_out;
}

::android::hardware::Return<uint32_t> BpHwCameraDeviceCallback::registerMemory(const ::android::hardware::hidl_handle& descriptor, uint32_t bufferSize, uint32_t bufferCount){
    ::android::hardware::Return<uint32_t>  _hidl_out = ::android::hardware::camera::device::V1_0::BpHwCameraDeviceCallback::_hidl_registerMemory(this, this, descriptor, bufferSize, bufferCount);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::unregisterMemory(uint32_t memId){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V1_0::BpHwCameraDeviceCallback::_hidl_unregisterMemory(this, this, memId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::dataCallback(::android::hardware::camera::device::V1_0::DataCallbackMsg msgType, uint32_t data, uint32_t bufferIndex, const ::android::hardware::camera::device::V1_0::CameraFrameMetadata& metadata){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V1_0::BpHwCameraDeviceCallback::_hidl_dataCallback(this, this, msgType, data, bufferIndex, metadata);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::dataCallbackTimestamp(::android::hardware::camera::device::V1_0::DataCallbackMsg msgType, uint32_t data, uint32_t bufferIndex, int64_t timestamp){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V1_0::BpHwCameraDeviceCallback::_hidl_dataCallbackTimestamp(this, this, msgType, data, bufferIndex, timestamp);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::handleCallbackTimestamp(::android::hardware::camera::device::V1_0::DataCallbackMsg msgType, const ::android::hardware::hidl_handle& frameData, uint32_t data, uint32_t bufferIndex, int64_t timestamp){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V1_0::BpHwCameraDeviceCallback::_hidl_handleCallbackTimestamp(this, this, msgType, frameData, data, bufferIndex, timestamp);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::handleCallbackTimestampBatch(::android::hardware::camera::device::V1_0::DataCallbackMsg msgType, const ::android::hardware::hidl_vec<::android::hardware::camera::device::V1_0::HandleTimestampMessage>& batch){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V1_0::BpHwCameraDeviceCallback::_hidl_handleCallbackTimestampBatch(this, this, msgType, batch);

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
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.camera.device@1.0", "ICameraDeviceCallback") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwCameraDeviceCallback::~BnHwCameraDeviceCallback() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::camera::device::V1_0::ICameraDeviceCallback follow.
::android::status_t BnHwCameraDeviceCallback::_hidl_notifyCallback(
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

    ::android::hardware::camera::device::V1_0::NotifyCallbackMsg msgType;
    int32_t ext1;
    int32_t ext2;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&msgType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&ext1);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&ext2);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::notifyCallback::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&msgType);
        _hidl_args.push_back((void *)&ext1);
        _hidl_args.push_back((void *)&ext2);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "notifyCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceCallback*>(_hidl_this->getImpl().get())->notifyCallback(msgType, ext1, ext2);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "notifyCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceCallback::_hidl_registerMemory(
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

    ::android::hardware::hidl_handle descriptor;
    uint32_t bufferSize;
    uint32_t bufferCount;

    const native_handle_t *descriptor_ptr;

    _hidl_err = _hidl_data.readNullableNativeHandleNoDup(&descriptor_ptr);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    descriptor = descriptor_ptr;
    _hidl_err = _hidl_data.readUint32(&bufferSize);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&bufferCount);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::registerMemory::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&descriptor);
        _hidl_args.push_back((void *)&bufferSize);
        _hidl_args.push_back((void *)&bufferCount);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "registerMemory", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint32_t _hidl_out_memId = static_cast<ICameraDeviceCallback*>(_hidl_this->getImpl().get())->registerMemory(descriptor, bufferSize, bufferCount);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32(_hidl_out_memId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_memId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "registerMemory", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCameraDeviceCallback::_hidl_unregisterMemory(
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

    uint32_t memId;

    _hidl_err = _hidl_data.readUint32(&memId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::unregisterMemory::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&memId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "unregisterMemory", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceCallback*>(_hidl_this->getImpl().get())->unregisterMemory(memId);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "unregisterMemory", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceCallback::_hidl_dataCallback(
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

    ::android::hardware::camera::device::V1_0::DataCallbackMsg msgType;
    uint32_t data;
    uint32_t bufferIndex;
    ::android::hardware::camera::device::V1_0::CameraFrameMetadata* metadata;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&msgType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&data);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&bufferIndex);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_metadata_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*metadata), &_hidl_metadata_parent,  const_cast<const void**>(reinterpret_cast<void **>(&metadata)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::camera::device::V1_0::CameraFrameMetadata &>(*metadata),
            _hidl_data,
            _hidl_metadata_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::dataCallback::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&msgType);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&bufferIndex);
        _hidl_args.push_back((void *)metadata);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "dataCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceCallback*>(_hidl_this->getImpl().get())->dataCallback(msgType, data, bufferIndex, *metadata);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "dataCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceCallback::_hidl_dataCallbackTimestamp(
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

    ::android::hardware::camera::device::V1_0::DataCallbackMsg msgType;
    uint32_t data;
    uint32_t bufferIndex;
    int64_t timestamp;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&msgType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&data);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&bufferIndex);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt64(&timestamp);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::dataCallbackTimestamp::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&msgType);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&bufferIndex);
        _hidl_args.push_back((void *)&timestamp);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "dataCallbackTimestamp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceCallback*>(_hidl_this->getImpl().get())->dataCallbackTimestamp(msgType, data, bufferIndex, timestamp);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "dataCallbackTimestamp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceCallback::_hidl_handleCallbackTimestamp(
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

    ::android::hardware::camera::device::V1_0::DataCallbackMsg msgType;
    ::android::hardware::hidl_handle frameData;
    uint32_t data;
    uint32_t bufferIndex;
    int64_t timestamp;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&msgType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    const native_handle_t *frameData_ptr;

    _hidl_err = _hidl_data.readNullableNativeHandleNoDup(&frameData_ptr);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    frameData = frameData_ptr;
    _hidl_err = _hidl_data.readUint32(&data);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&bufferIndex);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt64(&timestamp);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::handleCallbackTimestamp::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&msgType);
        _hidl_args.push_back((void *)&frameData);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&bufferIndex);
        _hidl_args.push_back((void *)&timestamp);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "handleCallbackTimestamp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceCallback*>(_hidl_this->getImpl().get())->handleCallbackTimestamp(msgType, frameData, data, bufferIndex, timestamp);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "handleCallbackTimestamp", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceCallback::_hidl_handleCallbackTimestampBatch(
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

    ::android::hardware::camera::device::V1_0::DataCallbackMsg msgType;
    const ::android::hardware::hidl_vec<::android::hardware::camera::device::V1_0::HandleTimestampMessage>* batch;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&msgType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_batch_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*batch), &_hidl_batch_parent,  reinterpret_cast<const void **>(&batch));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_batch_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V1_0::HandleTimestampMessage> &>(*batch),
            _hidl_data,
            _hidl_batch_parent,
            0 /* parentOffset */, &_hidl_batch_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < batch->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::camera::device::V1_0::HandleTimestampMessage &>((*batch)[_hidl_index_0]),
                _hidl_data,
                _hidl_batch_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V1_0::HandleTimestampMessage));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::handleCallbackTimestampBatch::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&msgType);
        _hidl_args.push_back((void *)batch);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "handleCallbackTimestampBatch", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceCallback*>(_hidl_this->getImpl().get())->handleCallbackTimestampBatch(msgType, *batch);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.device", "1.0", "ICameraDeviceCallback", "handleCallbackTimestampBatch", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::camera::device::V1_0::ICameraDeviceCallback follow.

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
        case 1 /* notifyCallback */:
        {
            _hidl_err = ::android::hardware::camera::device::V1_0::BnHwCameraDeviceCallback::_hidl_notifyCallback(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* registerMemory */:
        {
            _hidl_err = ::android::hardware::camera::device::V1_0::BnHwCameraDeviceCallback::_hidl_registerMemory(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* unregisterMemory */:
        {
            _hidl_err = ::android::hardware::camera::device::V1_0::BnHwCameraDeviceCallback::_hidl_unregisterMemory(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* dataCallback */:
        {
            _hidl_err = ::android::hardware::camera::device::V1_0::BnHwCameraDeviceCallback::_hidl_dataCallback(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* dataCallbackTimestamp */:
        {
            _hidl_err = ::android::hardware::camera::device::V1_0::BnHwCameraDeviceCallback::_hidl_dataCallbackTimestamp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* handleCallbackTimestamp */:
        {
            _hidl_err = ::android::hardware::camera::device::V1_0::BnHwCameraDeviceCallback::_hidl_handleCallbackTimestamp(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* handleCallbackTimestampBatch */:
        {
            _hidl_err = ::android::hardware::camera::device::V1_0::BnHwCameraDeviceCallback::_hidl_handleCallbackTimestampBatch(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsCameraDeviceCallback::BsCameraDeviceCallback(const ::android::sp<::android::hardware::camera::device::V1_0::ICameraDeviceCallback> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.camera.device@1.0", "ICameraDeviceCallback"), mImpl(impl) {
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
            sm->registerForNotifications("android.hardware.camera.device@1.0::ICameraDeviceCallback",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace device
}  // namespace camera
}  // namespace hardware
}  // namespace android
