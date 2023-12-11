#define LOG_TAG "android.frameworks.cameraservice.device@2.0::CameraDeviceUser"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/frameworks/cameraservice/device/2.0/BpHwCameraDeviceUser.h>
#include <android/frameworks/cameraservice/device/2.0/BnHwCameraDeviceUser.h>
#include <android/frameworks/cameraservice/device/2.0/BsCameraDeviceUser.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace frameworks {
namespace cameraservice {
namespace device {
namespace V2_0 {

const char* ICameraDeviceUser::descriptor("android.frameworks.cameraservice.device@2.0::ICameraDeviceUser");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ICameraDeviceUser::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwCameraDeviceUser(static_cast<ICameraDeviceUser *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ICameraDeviceUser::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsCameraDeviceUser(static_cast<ICameraDeviceUser *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ICameraDeviceUser::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ICameraDeviceUser::descriptor);
}

// Methods from ::android::frameworks::cameraservice::device::V2_0::ICameraDeviceUser follow.
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceUser::disconnect()
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceUser::getCaptureRequestMetadataQueue(getCaptureRequestMetadataQueue_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceUser::getCaptureResultMetadataQueue(getCaptureResultMetadataQueue_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceUser::submitRequestList(const ::android::hardware::hidl_vec<::android::frameworks::cameraservice::device::V2_0::CaptureRequest>& requestList, bool isRepeating, submitRequestList_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceUser::cancelRepeatingRequest(cancelRepeatingRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> ICameraDeviceUser::beginConfigure()
// no default implementation for: ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> ICameraDeviceUser::endConfigure(::android::frameworks::cameraservice::device::V2_0::StreamConfigurationMode operatingMode, const ::android::hardware::hidl_vec<uint8_t>& sessionParams)
// no default implementation for: ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> ICameraDeviceUser::deleteStream(int32_t streamId)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceUser::createStream(const ::android::frameworks::cameraservice::device::V2_0::OutputConfiguration& outputConfiguration, createStream_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceUser::createDefaultRequest(::android::frameworks::cameraservice::device::V2_0::TemplateId templateId, createDefaultRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> ICameraDeviceUser::waitUntilIdle()
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceUser::flush(flush_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> ICameraDeviceUser::updateOutputConfiguration(int32_t streamId, const ::android::frameworks::cameraservice::device::V2_0::OutputConfiguration& outputConfiguration)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceUser::isSessionConfigurationSupported(const ::android::frameworks::cameraservice::device::V2_0::SessionConfiguration& sessionConfiguration, isSessionConfigurationSupported_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ICameraDeviceUser::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::frameworks::cameraservice::device::V2_0::ICameraDeviceUser::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceUser::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceUser::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::frameworks::cameraservice::device::V2_0::ICameraDeviceUser::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceUser::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){14,185,167,81,73,27,239,194,7,168,245,169,68,150,72,154,253,18,31,152,86,6,48,119,23,65,175,88,216,143,173,255} /* 0eb9a751491befc207a8f5a94496489afd121f98560630771741af58d88fadff */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceUser::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraDeviceUser::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ICameraDeviceUser::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceUser::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ICameraDeviceUser::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraDeviceUser::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::frameworks::cameraservice::device::V2_0::ICameraDeviceUser>> ICameraDeviceUser::castFrom(const ::android::sp<::android::frameworks::cameraservice::device::V2_0::ICameraDeviceUser>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::frameworks::cameraservice::device::V2_0::ICameraDeviceUser>> ICameraDeviceUser::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraDeviceUser, ::android::hidl::base::V1_0::IBase, BpHwCameraDeviceUser>(
            parent, "android.frameworks.cameraservice.device@2.0::ICameraDeviceUser", emitError);
}

BpHwCameraDeviceUser::BpHwCameraDeviceUser(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ICameraDeviceUser>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.frameworks.cameraservice.device@2.0", "ICameraDeviceUser") {
}

void BpHwCameraDeviceUser::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ICameraDeviceUser>::onLastStrongRef(id);
}
// Methods from ::android::frameworks::cameraservice::device::V2_0::ICameraDeviceUser follow.
::android::hardware::Return<void> BpHwCameraDeviceUser::_hidl_disconnect(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::disconnect::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "disconnect", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceUser::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* disconnect */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "disconnect", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceUser::_hidl_getCaptureRequestMetadataQueue(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getCaptureRequestMetadataQueue_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::getCaptureRequestMetadataQueue::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "getCaptureRequestMetadataQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceUser::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* getCaptureRequestMetadataQueue */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::MQDescriptorSync<uint8_t>* _hidl_out_queue;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_queue_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_queue), &_hidl__hidl_out_queue_parent,  reinterpret_cast<const void **>(&_hidl_out_queue));

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::MQDescriptorSync<uint8_t> &>(*_hidl_out_queue),
                _hidl_reply,
                _hidl__hidl_out_queue_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_queue);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_queue);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "getCaptureRequestMetadataQueue", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceUser::_hidl_getCaptureResultMetadataQueue(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getCaptureResultMetadataQueue_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::getCaptureResultMetadataQueue::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "getCaptureResultMetadataQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceUser::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* getCaptureResultMetadataQueue */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::MQDescriptorSync<uint8_t>* _hidl_out_queue;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_queue_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_queue), &_hidl__hidl_out_queue_parent,  reinterpret_cast<const void **>(&_hidl_out_queue));

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::MQDescriptorSync<uint8_t> &>(*_hidl_out_queue),
                _hidl_reply,
                _hidl__hidl_out_queue_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_queue);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_queue);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "getCaptureResultMetadataQueue", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceUser::_hidl_submitRequestList(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::frameworks::cameraservice::device::V2_0::CaptureRequest>& requestList, bool isRepeating, submitRequestList_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::submitRequestList::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&requestList);
        _hidl_args.push_back((void *)&isRepeating);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "submitRequestList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceUser::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_requestList_parent;

    _hidl_err = _hidl_data.writeBuffer(&requestList, sizeof(requestList), &_hidl_requestList_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_requestList_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            requestList,
            &_hidl_data,
            _hidl_requestList_parent,
            0 /* parentOffset */, &_hidl_requestList_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < requestList.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                requestList[_hidl_index_0],
                &_hidl_data,
                _hidl_requestList_child,
                _hidl_index_0 * sizeof(::android::frameworks::cameraservice::device::V2_0::CaptureRequest));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_err = _hidl_data.writeBool(isRepeating);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* submitRequestList */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status;
        ::android::frameworks::cameraservice::device::V2_0::SubmitInfo* _hidl_out_submitInfo;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_submitInfo_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_submitInfo), &_hidl__hidl_out_submitInfo_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_submitInfo)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_submitInfo);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_submitInfo);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "submitRequestList", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceUser::_hidl_cancelRepeatingRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, cancelRepeatingRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::cancelRepeatingRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "cancelRepeatingRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceUser::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* cancelRepeatingRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status;
        int64_t _hidl_out_frameNumber;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt64(&_hidl_out_frameNumber);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_frameNumber);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_frameNumber);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "cancelRepeatingRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> BpHwCameraDeviceUser::_hidl_beginConfigure(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::beginConfigure::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "beginConfigure", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceUser::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* beginConfigure */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "beginConfigure", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> BpHwCameraDeviceUser::_hidl_endConfigure(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::frameworks::cameraservice::device::V2_0::StreamConfigurationMode operatingMode, const ::android::hardware::hidl_vec<uint8_t>& sessionParams) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::endConfigure::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&operatingMode);
        _hidl_args.push_back((void *)&sessionParams);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "endConfigure", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceUser::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32((uint32_t)operatingMode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionParams_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionParams, sizeof(sessionParams), &_hidl_sessionParams_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionParams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionParams,
            &_hidl_data,
            _hidl_sessionParams_parent,
            0 /* parentOffset */, &_hidl_sessionParams_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* endConfigure */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "endConfigure", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> BpHwCameraDeviceUser::_hidl_deleteStream(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t streamId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::deleteStream::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&streamId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "deleteStream", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceUser::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(streamId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* deleteStream */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "deleteStream", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceUser::_hidl_createStream(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::frameworks::cameraservice::device::V2_0::OutputConfiguration& outputConfiguration, createStream_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::createStream::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&outputConfiguration);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "createStream", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceUser::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_outputConfiguration_parent;

    _hidl_err = _hidl_data.writeBuffer(&outputConfiguration, sizeof(outputConfiguration), &_hidl_outputConfiguration_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            outputConfiguration,
            &_hidl_data,
            _hidl_outputConfiguration_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* createStream */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status;
        int32_t _hidl_out_streamID;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_streamID);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_streamID);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_streamID);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "createStream", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceUser::_hidl_createDefaultRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::frameworks::cameraservice::device::V2_0::TemplateId templateId, createDefaultRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::createDefaultRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&templateId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "createDefaultRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceUser::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)templateId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* createDefaultRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_metadata;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_metadata_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_metadata), &_hidl__hidl_out_metadata_parent,  reinterpret_cast<const void **>(&_hidl_out_metadata));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_metadata_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_metadata),
                _hidl_reply,
                _hidl__hidl_out_metadata_parent,
                0 /* parentOffset */, &_hidl__hidl_out_metadata_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_metadata);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_metadata);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "createDefaultRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> BpHwCameraDeviceUser::_hidl_waitUntilIdle(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::waitUntilIdle::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "waitUntilIdle", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceUser::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* waitUntilIdle */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "waitUntilIdle", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceUser::_hidl_flush(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, flush_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::flush::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "flush", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceUser::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* flush */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status;
        int64_t _hidl_out_lastFrameNumber;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt64(&_hidl_out_lastFrameNumber);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_lastFrameNumber);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_lastFrameNumber);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "flush", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> BpHwCameraDeviceUser::_hidl_updateOutputConfiguration(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t streamId, const ::android::frameworks::cameraservice::device::V2_0::OutputConfiguration& outputConfiguration) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::updateOutputConfiguration::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&streamId);
        _hidl_args.push_back((void *)&outputConfiguration);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "updateOutputConfiguration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceUser::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(streamId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_outputConfiguration_parent;

    _hidl_err = _hidl_data.writeBuffer(&outputConfiguration, sizeof(outputConfiguration), &_hidl_outputConfiguration_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            outputConfiguration,
            &_hidl_data,
            _hidl_outputConfiguration_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* updateOutputConfiguration */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "updateOutputConfiguration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraDeviceUser::_hidl_isSessionConfigurationSupported(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::frameworks::cameraservice::device::V2_0::SessionConfiguration& sessionConfiguration, isSessionConfigurationSupported_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::isSessionConfigurationSupported::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionConfiguration);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "isSessionConfigurationSupported", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceUser::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionConfiguration_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionConfiguration, sizeof(sessionConfiguration), &_hidl_sessionConfiguration_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            sessionConfiguration,
            &_hidl_data,
            _hidl_sessionConfiguration_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(14 /* isSessionConfigurationSupported */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status;
        bool _hidl_out_supported;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readBool(&_hidl_out_supported);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_supported);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_supported);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "isSessionConfigurationSupported", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::frameworks::cameraservice::device::V2_0::ICameraDeviceUser follow.
::android::hardware::Return<void> BpHwCameraDeviceUser::disconnect(){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceUser::_hidl_disconnect(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceUser::getCaptureRequestMetadataQueue(getCaptureRequestMetadataQueue_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceUser::_hidl_getCaptureRequestMetadataQueue(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceUser::getCaptureResultMetadataQueue(getCaptureResultMetadataQueue_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceUser::_hidl_getCaptureResultMetadataQueue(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceUser::submitRequestList(const ::android::hardware::hidl_vec<::android::frameworks::cameraservice::device::V2_0::CaptureRequest>& requestList, bool isRepeating, submitRequestList_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceUser::_hidl_submitRequestList(this, this, requestList, isRepeating, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceUser::cancelRepeatingRequest(cancelRepeatingRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceUser::_hidl_cancelRepeatingRequest(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> BpHwCameraDeviceUser::beginConfigure(){
    ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceUser::_hidl_beginConfigure(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> BpHwCameraDeviceUser::endConfigure(::android::frameworks::cameraservice::device::V2_0::StreamConfigurationMode operatingMode, const ::android::hardware::hidl_vec<uint8_t>& sessionParams){
    ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceUser::_hidl_endConfigure(this, this, operatingMode, sessionParams);

    return _hidl_out;
}

::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> BpHwCameraDeviceUser::deleteStream(int32_t streamId){
    ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceUser::_hidl_deleteStream(this, this, streamId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceUser::createStream(const ::android::frameworks::cameraservice::device::V2_0::OutputConfiguration& outputConfiguration, createStream_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceUser::_hidl_createStream(this, this, outputConfiguration, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceUser::createDefaultRequest(::android::frameworks::cameraservice::device::V2_0::TemplateId templateId, createDefaultRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceUser::_hidl_createDefaultRequest(this, this, templateId, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> BpHwCameraDeviceUser::waitUntilIdle(){
    ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceUser::_hidl_waitUntilIdle(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceUser::flush(flush_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceUser::_hidl_flush(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> BpHwCameraDeviceUser::updateOutputConfiguration(int32_t streamId, const ::android::frameworks::cameraservice::device::V2_0::OutputConfiguration& outputConfiguration){
    ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceUser::_hidl_updateOutputConfiguration(this, this, streamId, outputConfiguration);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceUser::isSessionConfigurationSupported(const ::android::frameworks::cameraservice::device::V2_0::SessionConfiguration& sessionConfiguration, isSessionConfigurationSupported_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::device::V2_0::BpHwCameraDeviceUser::_hidl_isSessionConfigurationSupported(this, this, sessionConfiguration, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwCameraDeviceUser::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceUser::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceUser::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceUser::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceUser::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraDeviceUser::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwCameraDeviceUser::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceUser::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceUser::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraDeviceUser::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwCameraDeviceUser::BnHwCameraDeviceUser(const ::android::sp<ICameraDeviceUser> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.frameworks.cameraservice.device@2.0", "ICameraDeviceUser") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwCameraDeviceUser::~BnHwCameraDeviceUser() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::frameworks::cameraservice::device::V2_0::ICameraDeviceUser follow.
::android::status_t BnHwCameraDeviceUser::_hidl_disconnect(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceUser::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::disconnect::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "disconnect", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceUser*>(_hidl_this->getImpl().get())->disconnect();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "disconnect", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceUser::_hidl_getCaptureRequestMetadataQueue(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceUser::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::getCaptureRequestMetadataQueue::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "getCaptureRequestMetadataQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceUser*>(_hidl_this->getImpl().get())->getCaptureRequestMetadataQueue([&](const auto &_hidl_out_queue) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getCaptureRequestMetadataQueue: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_queue_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_queue, sizeof(_hidl_out_queue), &_hidl__hidl_out_queue_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_queue,
                _hidl_reply,
                _hidl__hidl_out_queue_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_queue);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "getCaptureRequestMetadataQueue", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getCaptureRequestMetadataQueue: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceUser::_hidl_getCaptureResultMetadataQueue(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceUser::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::getCaptureResultMetadataQueue::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "getCaptureResultMetadataQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceUser*>(_hidl_this->getImpl().get())->getCaptureResultMetadataQueue([&](const auto &_hidl_out_queue) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getCaptureResultMetadataQueue: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_queue_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_queue, sizeof(_hidl_out_queue), &_hidl__hidl_out_queue_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_queue,
                _hidl_reply,
                _hidl__hidl_out_queue_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_queue);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "getCaptureResultMetadataQueue", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getCaptureResultMetadataQueue: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceUser::_hidl_submitRequestList(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceUser::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<::android::frameworks::cameraservice::device::V2_0::CaptureRequest>* requestList;
    bool isRepeating;

    size_t _hidl_requestList_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*requestList), &_hidl_requestList_parent,  reinterpret_cast<const void **>(&requestList));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_requestList_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::frameworks::cameraservice::device::V2_0::CaptureRequest> &>(*requestList),
            _hidl_data,
            _hidl_requestList_parent,
            0 /* parentOffset */, &_hidl_requestList_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < requestList->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::frameworks::cameraservice::device::V2_0::CaptureRequest &>((*requestList)[_hidl_index_0]),
                _hidl_data,
                _hidl_requestList_child,
                _hidl_index_0 * sizeof(::android::frameworks::cameraservice::device::V2_0::CaptureRequest));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = _hidl_data.readBool(&isRepeating);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::submitRequestList::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)requestList);
        _hidl_args.push_back((void *)&isRepeating);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "submitRequestList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceUser*>(_hidl_this->getImpl().get())->submitRequestList(*requestList, isRepeating, [&](const auto &_hidl_out_status, const auto &_hidl_out_submitInfo) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("submitRequestList: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_submitInfo_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_submitInfo, sizeof(_hidl_out_submitInfo), &_hidl__hidl_out_submitInfo_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_submitInfo);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "submitRequestList", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("submitRequestList: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceUser::_hidl_cancelRepeatingRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceUser::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::cancelRepeatingRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "cancelRepeatingRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceUser*>(_hidl_this->getImpl().get())->cancelRepeatingRequest([&](const auto &_hidl_out_status, const auto &_hidl_out_frameNumber) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("cancelRepeatingRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt64(_hidl_out_frameNumber);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_frameNumber);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "cancelRepeatingRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("cancelRepeatingRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceUser::_hidl_beginConfigure(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceUser::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::beginConfigure::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "beginConfigure", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status = static_cast<ICameraDeviceUser*>(_hidl_this->getImpl().get())->beginConfigure();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "beginConfigure", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCameraDeviceUser::_hidl_endConfigure(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceUser::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::frameworks::cameraservice::device::V2_0::StreamConfigurationMode operatingMode;
    const ::android::hardware::hidl_vec<uint8_t>* sessionParams;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&operatingMode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionParams_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionParams), &_hidl_sessionParams_parent,  reinterpret_cast<const void **>(&sessionParams));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionParams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionParams),
            _hidl_data,
            _hidl_sessionParams_parent,
            0 /* parentOffset */, &_hidl_sessionParams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::endConfigure::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&operatingMode);
        _hidl_args.push_back((void *)sessionParams);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "endConfigure", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status = static_cast<ICameraDeviceUser*>(_hidl_this->getImpl().get())->endConfigure(operatingMode, *sessionParams);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "endConfigure", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCameraDeviceUser::_hidl_deleteStream(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceUser::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t streamId;

    _hidl_err = _hidl_data.readInt32(&streamId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::deleteStream::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&streamId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "deleteStream", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status = static_cast<ICameraDeviceUser*>(_hidl_this->getImpl().get())->deleteStream(streamId);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "deleteStream", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCameraDeviceUser::_hidl_createStream(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceUser::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::frameworks::cameraservice::device::V2_0::OutputConfiguration* outputConfiguration;

    size_t _hidl_outputConfiguration_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*outputConfiguration), &_hidl_outputConfiguration_parent,  const_cast<const void**>(reinterpret_cast<void **>(&outputConfiguration)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::frameworks::cameraservice::device::V2_0::OutputConfiguration &>(*outputConfiguration),
            _hidl_data,
            _hidl_outputConfiguration_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::createStream::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)outputConfiguration);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "createStream", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceUser*>(_hidl_this->getImpl().get())->createStream(*outputConfiguration, [&](const auto &_hidl_out_status, const auto &_hidl_out_streamID) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("createStream: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_streamID);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_streamID);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "createStream", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("createStream: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceUser::_hidl_createDefaultRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceUser::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::frameworks::cameraservice::device::V2_0::TemplateId templateId;

    _hidl_err = _hidl_data.readInt32((int32_t *)&templateId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::createDefaultRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&templateId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "createDefaultRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceUser*>(_hidl_this->getImpl().get())->createDefaultRequest(templateId, [&](const auto &_hidl_out_status, const auto &_hidl_out_metadata) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("createDefaultRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_metadata_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_metadata, sizeof(_hidl_out_metadata), &_hidl__hidl_out_metadata_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_metadata_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_metadata,
                _hidl_reply,
                _hidl__hidl_out_metadata_parent,
                0 /* parentOffset */, &_hidl__hidl_out_metadata_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_metadata);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "createDefaultRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("createDefaultRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceUser::_hidl_waitUntilIdle(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceUser::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::waitUntilIdle::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "waitUntilIdle", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status = static_cast<ICameraDeviceUser*>(_hidl_this->getImpl().get())->waitUntilIdle();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "waitUntilIdle", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCameraDeviceUser::_hidl_flush(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceUser::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::flush::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "flush", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceUser*>(_hidl_this->getImpl().get())->flush([&](const auto &_hidl_out_status, const auto &_hidl_out_lastFrameNumber) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("flush: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt64(_hidl_out_lastFrameNumber);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_lastFrameNumber);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "flush", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("flush: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceUser::_hidl_updateOutputConfiguration(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceUser::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t streamId;
    ::android::frameworks::cameraservice::device::V2_0::OutputConfiguration* outputConfiguration;

    _hidl_err = _hidl_data.readInt32(&streamId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputConfiguration_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*outputConfiguration), &_hidl_outputConfiguration_parent,  const_cast<const void**>(reinterpret_cast<void **>(&outputConfiguration)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::frameworks::cameraservice::device::V2_0::OutputConfiguration &>(*outputConfiguration),
            _hidl_data,
            _hidl_outputConfiguration_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::updateOutputConfiguration::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&streamId);
        _hidl_args.push_back((void *)outputConfiguration);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "updateOutputConfiguration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::frameworks::cameraservice::common::V2_0::Status _hidl_out_status = static_cast<ICameraDeviceUser*>(_hidl_this->getImpl().get())->updateOutputConfiguration(streamId, *outputConfiguration);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "updateOutputConfiguration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCameraDeviceUser::_hidl_isSessionConfigurationSupported(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceUser::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::frameworks::cameraservice::device::V2_0::SessionConfiguration* sessionConfiguration;

    size_t _hidl_sessionConfiguration_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionConfiguration), &_hidl_sessionConfiguration_parent,  const_cast<const void**>(reinterpret_cast<void **>(&sessionConfiguration)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::frameworks::cameraservice::device::V2_0::SessionConfiguration &>(*sessionConfiguration),
            _hidl_data,
            _hidl_sessionConfiguration_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceUser::isSessionConfigurationSupported::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionConfiguration);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "isSessionConfigurationSupported", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceUser*>(_hidl_this->getImpl().get())->isSessionConfigurationSupported(*sessionConfiguration, [&](const auto &_hidl_out_status, const auto &_hidl_out_supported) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("isSessionConfigurationSupported: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeBool(_hidl_out_supported);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_supported);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.device", "2.0", "ICameraDeviceUser", "isSessionConfigurationSupported", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("isSessionConfigurationSupported: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::frameworks::cameraservice::device::V2_0::ICameraDeviceUser follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwCameraDeviceUser::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwCameraDeviceUser::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwCameraDeviceUser::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* disconnect */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceUser::_hidl_disconnect(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getCaptureRequestMetadataQueue */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceUser::_hidl_getCaptureRequestMetadataQueue(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* getCaptureResultMetadataQueue */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceUser::_hidl_getCaptureResultMetadataQueue(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* submitRequestList */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceUser::_hidl_submitRequestList(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* cancelRepeatingRequest */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceUser::_hidl_cancelRepeatingRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* beginConfigure */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceUser::_hidl_beginConfigure(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* endConfigure */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceUser::_hidl_endConfigure(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* deleteStream */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceUser::_hidl_deleteStream(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* createStream */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceUser::_hidl_createStream(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* createDefaultRequest */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceUser::_hidl_createDefaultRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* waitUntilIdle */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceUser::_hidl_waitUntilIdle(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* flush */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceUser::_hidl_flush(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* updateOutputConfiguration */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceUser::_hidl_updateOutputConfiguration(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* isSessionConfigurationSupported */:
        {
            _hidl_err = ::android::frameworks::cameraservice::device::V2_0::BnHwCameraDeviceUser::_hidl_isSessionConfigurationSupported(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsCameraDeviceUser::BsCameraDeviceUser(const ::android::sp<::android::frameworks::cameraservice::device::V2_0::ICameraDeviceUser> impl) : ::android::hardware::details::HidlInstrumentor("android.frameworks.cameraservice.device@2.0", "ICameraDeviceUser"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsCameraDeviceUser::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ICameraDeviceUser> ICameraDeviceUser::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraDeviceUser>(serviceName, false, getStub);
}

::android::sp<ICameraDeviceUser> ICameraDeviceUser::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraDeviceUser>(serviceName, true, getStub);
}

::android::status_t ICameraDeviceUser::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ICameraDeviceUser::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.frameworks.cameraservice.device@2.0::ICameraDeviceUser",
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
