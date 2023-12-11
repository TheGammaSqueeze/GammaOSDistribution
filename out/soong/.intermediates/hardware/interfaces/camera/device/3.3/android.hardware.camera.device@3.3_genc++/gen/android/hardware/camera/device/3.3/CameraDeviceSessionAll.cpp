#define LOG_TAG "android.hardware.camera.device@3.3::CameraDeviceSession"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/camera/device/3.3/BpHwCameraDeviceSession.h>
#include <android/hardware/camera/device/3.3/BnHwCameraDeviceSession.h>
#include <android/hardware/camera/device/3.3/BsCameraDeviceSession.h>
#include <android/hardware/camera/device/3.2/BpHwCameraDeviceSession.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace camera {
namespace device {
namespace V3_3 {

const char* ICameraDeviceSession::descriptor("android.hardware.camera.device@3.3::ICameraDeviceSession");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ICameraDeviceSession::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwCameraDeviceSession(static_cast<ICameraDeviceSession *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ICameraDeviceSession::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsCameraDeviceSession(static_cast<ICameraDeviceSession *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ICameraDeviceSession::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ICameraDeviceSession::descriptor);
}

// Methods from ::android::hardware::camera::device::V3_2::ICameraDeviceSession follow.
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceSession::constructDefaultRequestSettings(::android::hardware::camera::device::V3_2::RequestTemplate type, constructDefaultRequestSettings_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceSession::configureStreams(const ::android::hardware::camera::device::V3_2::StreamConfiguration& requestedConfiguration, configureStreams_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceSession::processCaptureRequest(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::CaptureRequest>& requests, const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::BufferCache>& cachesToRemove, processCaptureRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceSession::getCaptureRequestMetadataQueue(getCaptureRequestMetadataQueue_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceSession::getCaptureResultMetadataQueue(getCaptureResultMetadataQueue_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::camera::common::V1_0::Status> ICameraDeviceSession::flush()
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceSession::close()

// Methods from ::android::hardware::camera::device::V3_3::ICameraDeviceSession follow.
// no default implementation for: ::android::hardware::Return<void> ICameraDeviceSession::configureStreams_3_3(const ::android::hardware::camera::device::V3_2::StreamConfiguration& requestedConfiguration, configureStreams_3_3_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ICameraDeviceSession::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::camera::device::V3_3::ICameraDeviceSession::descriptor,
        ::android::hardware::camera::device::V3_2::ICameraDeviceSession::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceSession::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceSession::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::camera::device::V3_3::ICameraDeviceSession::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceSession::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){187,207,195,247,72,176,120,246,166,108,78,34,128,132,166,121,211,11,214,27,253,232,187,122,145,239,213,7,185,28,27,253} /* bbcfc3f748b078f6a66c4e228084a679d30bd61bfde8bb7a91efd507b91c1bfd */,
        (uint8_t[32]){140,175,145,4,220,104,133,133,44,11,17,125,133,61,217,63,109,75,97,160,163,101,19,130,149,235,139,205,65,179,100,35} /* 8caf9104dc6885852c0b117d853dd93f6d4b61a0a365138295eb8bcd41b36423 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceSession::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraDeviceSession::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ICameraDeviceSession::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDeviceSession::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ICameraDeviceSession::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraDeviceSession::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::camera::device::V3_3::ICameraDeviceSession>> ICameraDeviceSession::castFrom(const ::android::sp<::android::hardware::camera::device::V3_3::ICameraDeviceSession>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::camera::device::V3_3::ICameraDeviceSession>> ICameraDeviceSession::castFrom(const ::android::sp<::android::hardware::camera::device::V3_2::ICameraDeviceSession>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraDeviceSession, ::android::hardware::camera::device::V3_2::ICameraDeviceSession, BpHwCameraDeviceSession>(
            parent, "android.hardware.camera.device@3.3::ICameraDeviceSession", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::camera::device::V3_3::ICameraDeviceSession>> ICameraDeviceSession::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraDeviceSession, ::android::hidl::base::V1_0::IBase, BpHwCameraDeviceSession>(
            parent, "android.hardware.camera.device@3.3::ICameraDeviceSession", emitError);
}

BpHwCameraDeviceSession::BpHwCameraDeviceSession(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ICameraDeviceSession>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.camera.device@3.3", "ICameraDeviceSession") {
}

void BpHwCameraDeviceSession::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ICameraDeviceSession>::onLastStrongRef(id);
}
// Methods from ::android::hardware::camera::device::V3_3::ICameraDeviceSession follow.
::android::hardware::Return<void> BpHwCameraDeviceSession::_hidl_configureStreams_3_3(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::camera::device::V3_2::StreamConfiguration& requestedConfiguration, configureStreams_3_3_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDeviceSession::configureStreams_3_3::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&requestedConfiguration);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.device", "3.3", "ICameraDeviceSession", "configureStreams_3_3", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDeviceSession::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_requestedConfiguration_parent;

    _hidl_err = _hidl_data.writeBuffer(&requestedConfiguration, sizeof(requestedConfiguration), &_hidl_requestedConfiguration_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            requestedConfiguration,
            &_hidl_data,
            _hidl_requestedConfiguration_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* configureStreams_3_3 */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::camera::common::V1_0::Status _hidl_out_status;
        ::android::hardware::camera::device::V3_3::HalStreamConfiguration* _hidl_out_halConfiguration;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_halConfiguration_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_halConfiguration), &_hidl__hidl_out_halConfiguration_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_halConfiguration)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::camera::device::V3_3::HalStreamConfiguration &>(*_hidl_out_halConfiguration),
                _hidl_reply,
                _hidl__hidl_out_halConfiguration_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_halConfiguration);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_halConfiguration);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.device", "3.3", "ICameraDeviceSession", "configureStreams_3_3", &_hidl_args);
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


// Methods from ::android::hardware::camera::device::V3_2::ICameraDeviceSession follow.
::android::hardware::Return<void> BpHwCameraDeviceSession::constructDefaultRequestSettings(::android::hardware::camera::device::V3_2::RequestTemplate type, constructDefaultRequestSettings_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_2::BpHwCameraDeviceSession::_hidl_constructDefaultRequestSettings(this, this, type, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceSession::configureStreams(const ::android::hardware::camera::device::V3_2::StreamConfiguration& requestedConfiguration, configureStreams_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_2::BpHwCameraDeviceSession::_hidl_configureStreams(this, this, requestedConfiguration, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceSession::processCaptureRequest(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::CaptureRequest>& requests, const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::BufferCache>& cachesToRemove, processCaptureRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_2::BpHwCameraDeviceSession::_hidl_processCaptureRequest(this, this, requests, cachesToRemove, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceSession::getCaptureRequestMetadataQueue(getCaptureRequestMetadataQueue_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_2::BpHwCameraDeviceSession::_hidl_getCaptureRequestMetadataQueue(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceSession::getCaptureResultMetadataQueue(getCaptureResultMetadataQueue_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_2::BpHwCameraDeviceSession::_hidl_getCaptureResultMetadataQueue(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::camera::common::V1_0::Status> BpHwCameraDeviceSession::flush(){
    ::android::hardware::Return<::android::hardware::camera::common::V1_0::Status>  _hidl_out = ::android::hardware::camera::device::V3_2::BpHwCameraDeviceSession::_hidl_flush(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceSession::close(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_2::BpHwCameraDeviceSession::_hidl_close(this, this);

    return _hidl_out;
}


// Methods from ::android::hardware::camera::device::V3_3::ICameraDeviceSession follow.
::android::hardware::Return<void> BpHwCameraDeviceSession::configureStreams_3_3(const ::android::hardware::camera::device::V3_2::StreamConfiguration& requestedConfiguration, configureStreams_3_3_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_3::BpHwCameraDeviceSession::_hidl_configureStreams_3_3(this, this, requestedConfiguration, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwCameraDeviceSession::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceSession::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceSession::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceSession::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceSession::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraDeviceSession::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwCameraDeviceSession::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceSession::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDeviceSession::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraDeviceSession::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwCameraDeviceSession::BnHwCameraDeviceSession(const ::android::sp<ICameraDeviceSession> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.camera.device@3.3", "ICameraDeviceSession") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwCameraDeviceSession::~BnHwCameraDeviceSession() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::camera::device::V3_3::ICameraDeviceSession follow.
::android::status_t BnHwCameraDeviceSession::_hidl_configureStreams_3_3(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDeviceSession::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::camera::device::V3_2::StreamConfiguration* requestedConfiguration;

    size_t _hidl_requestedConfiguration_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*requestedConfiguration), &_hidl_requestedConfiguration_parent,  const_cast<const void**>(reinterpret_cast<void **>(&requestedConfiguration)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::camera::device::V3_2::StreamConfiguration &>(*requestedConfiguration),
            _hidl_data,
            _hidl_requestedConfiguration_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDeviceSession::configureStreams_3_3::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)requestedConfiguration);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.device", "3.3", "ICameraDeviceSession", "configureStreams_3_3", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDeviceSession*>(_hidl_this->getImpl().get())->configureStreams_3_3(*requestedConfiguration, [&](const auto &_hidl_out_status, const auto &_hidl_out_halConfiguration) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("configureStreams_3_3: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_halConfiguration_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_halConfiguration, sizeof(_hidl_out_halConfiguration), &_hidl__hidl_out_halConfiguration_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_halConfiguration,
                _hidl_reply,
                _hidl__hidl_out_halConfiguration_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_halConfiguration);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.device", "3.3", "ICameraDeviceSession", "configureStreams_3_3", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("configureStreams_3_3: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::camera::device::V3_2::ICameraDeviceSession follow.

// Methods from ::android::hardware::camera::device::V3_3::ICameraDeviceSession follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwCameraDeviceSession::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwCameraDeviceSession::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwCameraDeviceSession::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* constructDefaultRequestSettings */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_2::BnHwCameraDeviceSession::_hidl_constructDefaultRequestSettings(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* configureStreams */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_2::BnHwCameraDeviceSession::_hidl_configureStreams(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* processCaptureRequest */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_2::BnHwCameraDeviceSession::_hidl_processCaptureRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* getCaptureRequestMetadataQueue */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_2::BnHwCameraDeviceSession::_hidl_getCaptureRequestMetadataQueue(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* getCaptureResultMetadataQueue */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_2::BnHwCameraDeviceSession::_hidl_getCaptureResultMetadataQueue(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* flush */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_2::BnHwCameraDeviceSession::_hidl_flush(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* close */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_2::BnHwCameraDeviceSession::_hidl_close(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* configureStreams_3_3 */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_3::BnHwCameraDeviceSession::_hidl_configureStreams_3_3(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsCameraDeviceSession::BsCameraDeviceSession(const ::android::sp<::android::hardware::camera::device::V3_3::ICameraDeviceSession> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.camera.device@3.3", "ICameraDeviceSession"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsCameraDeviceSession::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ICameraDeviceSession> ICameraDeviceSession::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraDeviceSession>(serviceName, false, getStub);
}

::android::sp<ICameraDeviceSession> ICameraDeviceSession::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraDeviceSession>(serviceName, true, getStub);
}

::android::status_t ICameraDeviceSession::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ICameraDeviceSession::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.camera.device@3.3::ICameraDeviceSession",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V3_3
}  // namespace device
}  // namespace camera
}  // namespace hardware
}  // namespace android
