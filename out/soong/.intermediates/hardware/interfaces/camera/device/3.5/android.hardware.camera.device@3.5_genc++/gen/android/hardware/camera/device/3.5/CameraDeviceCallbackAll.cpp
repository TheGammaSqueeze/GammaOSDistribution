#define LOG_TAG "android.hardware.camera.device@3.5::CameraDeviceCallback"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/camera/device/3.5/BpHwCameraDeviceCallback.h>
#include <android/hardware/camera/device/3.5/BnHwCameraDeviceCallback.h>
#include <android/hardware/camera/device/3.5/BsCameraDeviceCallback.h>
#include <android/hardware/camera/device/3.4/BpHwCameraDeviceCallback.h>
#include <android/hardware/camera/device/3.2/BpHwCameraDeviceCallback.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace camera {
namespace device {
namespace V3_5 {

const char* ICameraDeviceCallback::descriptor("android.hardware.camera.device@3.5::ICameraDeviceCallback");

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

// Methods from ::android::hardware::camera::device::V3_2::ICameraDeviceCallback follow.
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::processCaptureResult(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::CaptureResult>& results)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::notify(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::NotifyMsg>& msgs)

// Methods from ::android::hardware::camera::device::V3_4::ICameraDeviceCallback follow.
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::processCaptureResult_3_4(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_4::CaptureResult>& results)

// Methods from ::android::hardware::camera::device::V3_5::ICameraDeviceCallback follow.
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::requestStreamBuffers(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_5::BufferRequest>& bufReqs, requestStreamBuffers_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceCallback::returnStreamBuffers(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer>& buffers)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ICameraDeviceCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::camera::device::V3_5::ICameraDeviceCallback::descriptor,
        ::android::hardware::camera::device::V3_4::ICameraDeviceCallback::descriptor,
        ::android::hardware::camera::device::V3_2::ICameraDeviceCallback::descriptor,
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
    _hidl_cb(::android::hardware::camera::device::V3_5::ICameraDeviceCallback::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceCallback::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){6,35,125,229,60,66,137,0,41,227,248,254,125,20,128,208,120,70,156,13,7,96,142,81,195,123,77,72,93,52,41,146} /* 06237de53c42890029e3f8fe7d1480d078469c0d07608e51c37b4d485d342992 */,
        (uint8_t[32]){79,176,114,92,54,237,79,119,164,43,66,227,241,141,139,95,121,25,203,98,185,0,152,178,49,67,165,85,170,125,217,109} /* 4fb0725c36ed4f77a42b42e3f18d8b5f7919cb62b90098b23143a555aa7dd96d */,
        (uint8_t[32]){41,36,195,228,56,88,25,14,227,226,218,76,47,185,59,186,138,224,101,254,49,68,81,240,53,167,236,82,203,128,201,74} /* 2924c3e43858190ee3e2da4c2fb93bba8ae065fe314451f035a7ec52cb80c94a */,
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


::android::hardware::Return<::android::sp<::android::hardware::camera::device::V3_5::ICameraDeviceCallback>> ICameraDeviceCallback::castFrom(const ::android::sp<::android::hardware::camera::device::V3_5::ICameraDeviceCallback>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::camera::device::V3_5::ICameraDeviceCallback>> ICameraDeviceCallback::castFrom(const ::android::sp<::android::hardware::camera::device::V3_4::ICameraDeviceCallback>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraDeviceCallback, ::android::hardware::camera::device::V3_4::ICameraDeviceCallback, BpHwCameraDeviceCallback>(
            parent, "android.hardware.camera.device@3.5::ICameraDeviceCallback", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::camera::device::V3_5::ICameraDeviceCallback>> ICameraDeviceCallback::castFrom(const ::android::sp<::android::hardware::camera::device::V3_2::ICameraDeviceCallback>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraDeviceCallback, ::android::hardware::camera::device::V3_2::ICameraDeviceCallback, BpHwCameraDeviceCallback>(
            parent, "android.hardware.camera.device@3.5::ICameraDeviceCallback", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::camera::device::V3_5::ICameraDeviceCallback>> ICameraDeviceCallback::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraDeviceCallback, ::android::hidl::base::V1_0::IBase, BpHwCameraDeviceCallback>(
            parent, "android.hardware.camera.device@3.5::ICameraDeviceCallback", emitError);
}

BpHwCameraDeviceCallback::BpHwCameraDeviceCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ICameraDeviceCallback>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.camera.device@3.5", "ICameraDeviceCallback") {
}

void BpHwCameraDeviceCallback::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ICameraDeviceCallback>::onLastStrongRef(id);
}
// Methods from ::android::hardware::camera::device::V3_5::ICameraDeviceCallback follow.
::android::hardware::Return<void> BpHwCameraDeviceCallback::_hidl_requestStreamBuffers(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_5::BufferRequest>& bufReqs, requestStreamBuffers_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::requestStreamBuffers::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&bufReqs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.device", "3.5", "ICameraDeviceCallback", "requestStreamBuffers", &_hidl_args);
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

    size_t _hidl_bufReqs_parent;

    _hidl_err = _hidl_data.writeBuffer(&bufReqs, sizeof(bufReqs), &_hidl_bufReqs_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_bufReqs_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            bufReqs,
            &_hidl_data,
            _hidl_bufReqs_parent,
            0 /* parentOffset */, &_hidl_bufReqs_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* requestStreamBuffers */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::camera::device::V3_5::BufferRequestStatus _hidl_out_st;
        const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_5::StreamBufferRet>* _hidl_out_buffers;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_st);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_buffers_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_buffers), &_hidl__hidl_out_buffers_parent,  reinterpret_cast<const void **>(&_hidl_out_buffers));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_buffers_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_5::StreamBufferRet> &>(*_hidl_out_buffers),
                _hidl_reply,
                _hidl__hidl_out_buffers_parent,
                0 /* parentOffset */, &_hidl__hidl_out_buffers_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_buffers->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::camera::device::V3_5::StreamBufferRet &>((*_hidl_out_buffers)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_buffers_child,
                    _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_5::StreamBufferRet));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_cb(_hidl_out_st, *_hidl_out_buffers);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_st);
            _hidl_args.push_back((void *)_hidl_out_buffers);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.device", "3.5", "ICameraDeviceCallback", "requestStreamBuffers", &_hidl_args);
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

::android::hardware::Return<void> BpHwCameraDeviceCallback::_hidl_returnStreamBuffers(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer>& buffers) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::returnStreamBuffers::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffers);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.device", "3.5", "ICameraDeviceCallback", "returnStreamBuffers", &_hidl_args);
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

    size_t _hidl_buffers_parent;

    _hidl_err = _hidl_data.writeBuffer(&buffers, sizeof(buffers), &_hidl_buffers_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_buffers_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            buffers,
            &_hidl_data,
            _hidl_buffers_parent,
            0 /* parentOffset */, &_hidl_buffers_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < buffers.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                buffers[_hidl_index_0],
                &_hidl_data,
                _hidl_buffers_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_2::StreamBuffer));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* returnStreamBuffers */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.device", "3.5", "ICameraDeviceCallback", "returnStreamBuffers", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::camera::device::V3_2::ICameraDeviceCallback follow.
::android::hardware::Return<void> BpHwCameraDeviceCallback::processCaptureResult(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::CaptureResult>& results){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_2::BpHwCameraDeviceCallback::_hidl_processCaptureResult(this, this, results);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::notify(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::NotifyMsg>& msgs){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_2::BpHwCameraDeviceCallback::_hidl_notify(this, this, msgs);

    return _hidl_out;
}


// Methods from ::android::hardware::camera::device::V3_4::ICameraDeviceCallback follow.
::android::hardware::Return<void> BpHwCameraDeviceCallback::processCaptureResult_3_4(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_4::CaptureResult>& results){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_4::BpHwCameraDeviceCallback::_hidl_processCaptureResult_3_4(this, this, results);

    return _hidl_out;
}


// Methods from ::android::hardware::camera::device::V3_5::ICameraDeviceCallback follow.
::android::hardware::Return<void> BpHwCameraDeviceCallback::requestStreamBuffers(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_5::BufferRequest>& bufReqs, requestStreamBuffers_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_5::BpHwCameraDeviceCallback::_hidl_requestStreamBuffers(this, this, bufReqs, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceCallback::returnStreamBuffers(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer>& buffers){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_5::BpHwCameraDeviceCallback::_hidl_returnStreamBuffers(this, this, buffers);

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
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.camera.device@3.5", "ICameraDeviceCallback") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwCameraDeviceCallback::~BnHwCameraDeviceCallback() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::camera::device::V3_5::ICameraDeviceCallback follow.
::android::status_t BnHwCameraDeviceCallback::_hidl_requestStreamBuffers(
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

    const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_5::BufferRequest>* bufReqs;

    size_t _hidl_bufReqs_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*bufReqs), &_hidl_bufReqs_parent,  reinterpret_cast<const void **>(&bufReqs));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_bufReqs_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_5::BufferRequest> &>(*bufReqs),
            _hidl_data,
            _hidl_bufReqs_parent,
            0 /* parentOffset */, &_hidl_bufReqs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::requestStreamBuffers::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)bufReqs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.device", "3.5", "ICameraDeviceCallback", "requestStreamBuffers", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceCallback*>(_hidl_this->getImpl().get())->requestStreamBuffers(*bufReqs, [&](const auto &_hidl_out_st, const auto &_hidl_out_buffers) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("requestStreamBuffers: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_st);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_buffers_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_buffers, sizeof(_hidl_out_buffers), &_hidl__hidl_out_buffers_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_buffers_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_buffers,
                _hidl_reply,
                _hidl__hidl_out_buffers_parent,
                0 /* parentOffset */, &_hidl__hidl_out_buffers_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_buffers.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_buffers[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_buffers_child,
                    _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_5::StreamBufferRet));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_st);
            _hidl_args.push_back((void *)&_hidl_out_buffers);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.device", "3.5", "ICameraDeviceCallback", "requestStreamBuffers", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("requestStreamBuffers: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwCameraDeviceCallback::_hidl_returnStreamBuffers(
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

    const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer>* buffers;

    size_t _hidl_buffers_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*buffers), &_hidl_buffers_parent,  reinterpret_cast<const void **>(&buffers));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_buffers_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer> &>(*buffers),
            _hidl_data,
            _hidl_buffers_parent,
            0 /* parentOffset */, &_hidl_buffers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < buffers->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::camera::device::V3_2::StreamBuffer &>((*buffers)[_hidl_index_0]),
                _hidl_data,
                _hidl_buffers_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_2::StreamBuffer));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceCallback::returnStreamBuffers::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)buffers);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.device", "3.5", "ICameraDeviceCallback", "returnStreamBuffers", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceCallback*>(_hidl_this->getImpl().get())->returnStreamBuffers(*buffers);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.device", "3.5", "ICameraDeviceCallback", "returnStreamBuffers", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::camera::device::V3_2::ICameraDeviceCallback follow.

// Methods from ::android::hardware::camera::device::V3_4::ICameraDeviceCallback follow.

// Methods from ::android::hardware::camera::device::V3_5::ICameraDeviceCallback follow.

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
        case 1 /* processCaptureResult */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_2::BnHwCameraDeviceCallback::_hidl_processCaptureResult(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* notify */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_2::BnHwCameraDeviceCallback::_hidl_notify(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* processCaptureResult_3_4 */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_4::BnHwCameraDeviceCallback::_hidl_processCaptureResult_3_4(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* requestStreamBuffers */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_5::BnHwCameraDeviceCallback::_hidl_requestStreamBuffers(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* returnStreamBuffers */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_5::BnHwCameraDeviceCallback::_hidl_returnStreamBuffers(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsCameraDeviceCallback::BsCameraDeviceCallback(const ::android::sp<::android::hardware::camera::device::V3_5::ICameraDeviceCallback> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.camera.device@3.5", "ICameraDeviceCallback"), mImpl(impl) {
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
            sm->registerForNotifications("android.hardware.camera.device@3.5::ICameraDeviceCallback",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V3_5
}  // namespace device
}  // namespace camera
}  // namespace hardware
}  // namespace android
