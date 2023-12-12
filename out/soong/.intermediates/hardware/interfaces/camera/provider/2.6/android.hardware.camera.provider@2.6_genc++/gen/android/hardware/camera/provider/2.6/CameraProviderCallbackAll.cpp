#define LOG_TAG "android.hardware.camera.provider@2.6::CameraProviderCallback"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/camera/provider/2.6/BpHwCameraProviderCallback.h>
#include <android/hardware/camera/provider/2.6/BnHwCameraProviderCallback.h>
#include <android/hardware/camera/provider/2.6/BsCameraProviderCallback.h>
#include <android/hardware/camera/provider/2.4/BpHwCameraProviderCallback.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace camera {
namespace provider {
namespace V2_6 {

const char* ICameraProviderCallback::descriptor("android.hardware.camera.provider@2.6::ICameraProviderCallback");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ICameraProviderCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwCameraProviderCallback(static_cast<ICameraProviderCallback *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ICameraProviderCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsCameraProviderCallback(static_cast<ICameraProviderCallback *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ICameraProviderCallback::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ICameraProviderCallback::descriptor);
}

// Methods from ::android::hardware::camera::provider::V2_4::ICameraProviderCallback follow.
// no default implementation for: ::android::hardware::Return<void> ICameraProviderCallback::cameraDeviceStatusChange(const ::android::hardware::hidl_string& cameraDeviceName, ::android::hardware::camera::common::V1_0::CameraDeviceStatus newStatus)
// no default implementation for: ::android::hardware::Return<void> ICameraProviderCallback::torchModeStatusChange(const ::android::hardware::hidl_string& cameraDeviceName, ::android::hardware::camera::common::V1_0::TorchModeStatus newStatus)

// Methods from ::android::hardware::camera::provider::V2_6::ICameraProviderCallback follow.
// no default implementation for: ::android::hardware::Return<void> ICameraProviderCallback::physicalCameraDeviceStatusChange(const ::android::hardware::hidl_string& cameraDeviceName, const ::android::hardware::hidl_string& physicalCameraDeviceName, ::android::hardware::camera::common::V1_0::CameraDeviceStatus newStatus)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ICameraProviderCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::camera::provider::V2_6::ICameraProviderCallback::descriptor,
        ::android::hardware::camera::provider::V2_4::ICameraProviderCallback::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraProviderCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraProviderCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::camera::provider::V2_6::ICameraProviderCallback::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraProviderCallback::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){143,141,148,99,80,143,249,202,232,142,179,92,66,159,208,226,219,202,12,168,245,222,127,223,131,108,192,196,55,11,236,182} /* 8f8d9463508ff9cae88eb35c429fd0e2dbca0ca8f5de7fdf836cc0c4370becb6 */,
        (uint8_t[32]){44,232,32,220,79,60,109,133,114,27,101,21,14,210,21,124,110,46,32,85,248,102,251,108,107,164,121,15,20,64,141,102} /* 2ce820dc4f3c6d85721b65150ed2157c6e2e2055f866fb6c6ba4790f14408d66 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraProviderCallback::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraProviderCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ICameraProviderCallback::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraProviderCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ICameraProviderCallback::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraProviderCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::camera::provider::V2_6::ICameraProviderCallback>> ICameraProviderCallback::castFrom(const ::android::sp<::android::hardware::camera::provider::V2_6::ICameraProviderCallback>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::camera::provider::V2_6::ICameraProviderCallback>> ICameraProviderCallback::castFrom(const ::android::sp<::android::hardware::camera::provider::V2_4::ICameraProviderCallback>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraProviderCallback, ::android::hardware::camera::provider::V2_4::ICameraProviderCallback, BpHwCameraProviderCallback>(
            parent, "android.hardware.camera.provider@2.6::ICameraProviderCallback", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::camera::provider::V2_6::ICameraProviderCallback>> ICameraProviderCallback::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraProviderCallback, ::android::hidl::base::V1_0::IBase, BpHwCameraProviderCallback>(
            parent, "android.hardware.camera.provider@2.6::ICameraProviderCallback", emitError);
}

BpHwCameraProviderCallback::BpHwCameraProviderCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ICameraProviderCallback>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.camera.provider@2.6", "ICameraProviderCallback") {
}

void BpHwCameraProviderCallback::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ICameraProviderCallback>::onLastStrongRef(id);
}
// Methods from ::android::hardware::camera::provider::V2_6::ICameraProviderCallback follow.
::android::hardware::Return<void> BpHwCameraProviderCallback::_hidl_physicalCameraDeviceStatusChange(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& cameraDeviceName, const ::android::hardware::hidl_string& physicalCameraDeviceName, ::android::hardware::camera::common::V1_0::CameraDeviceStatus newStatus) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraProviderCallback::physicalCameraDeviceStatusChange::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cameraDeviceName);
        _hidl_args.push_back((void *)&physicalCameraDeviceName);
        _hidl_args.push_back((void *)&newStatus);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.provider", "2.6", "ICameraProviderCallback", "physicalCameraDeviceStatusChange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraProviderCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_cameraDeviceName_parent;

    _hidl_err = _hidl_data.writeBuffer(&cameraDeviceName, sizeof(cameraDeviceName), &_hidl_cameraDeviceName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            cameraDeviceName,
            &_hidl_data,
            _hidl_cameraDeviceName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_physicalCameraDeviceName_parent;

    _hidl_err = _hidl_data.writeBuffer(&physicalCameraDeviceName, sizeof(physicalCameraDeviceName), &_hidl_physicalCameraDeviceName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            physicalCameraDeviceName,
            &_hidl_data,
            _hidl_physicalCameraDeviceName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32((uint32_t)newStatus);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* physicalCameraDeviceStatusChange */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.provider", "2.6", "ICameraProviderCallback", "physicalCameraDeviceStatusChange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::camera::provider::V2_4::ICameraProviderCallback follow.
::android::hardware::Return<void> BpHwCameraProviderCallback::cameraDeviceStatusChange(const ::android::hardware::hidl_string& cameraDeviceName, ::android::hardware::camera::common::V1_0::CameraDeviceStatus newStatus){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::provider::V2_4::BpHwCameraProviderCallback::_hidl_cameraDeviceStatusChange(this, this, cameraDeviceName, newStatus);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProviderCallback::torchModeStatusChange(const ::android::hardware::hidl_string& cameraDeviceName, ::android::hardware::camera::common::V1_0::TorchModeStatus newStatus){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::provider::V2_4::BpHwCameraProviderCallback::_hidl_torchModeStatusChange(this, this, cameraDeviceName, newStatus);

    return _hidl_out;
}


// Methods from ::android::hardware::camera::provider::V2_6::ICameraProviderCallback follow.
::android::hardware::Return<void> BpHwCameraProviderCallback::physicalCameraDeviceStatusChange(const ::android::hardware::hidl_string& cameraDeviceName, const ::android::hardware::hidl_string& physicalCameraDeviceName, ::android::hardware::camera::common::V1_0::CameraDeviceStatus newStatus){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::provider::V2_6::BpHwCameraProviderCallback::_hidl_physicalCameraDeviceStatusChange(this, this, cameraDeviceName, physicalCameraDeviceName, newStatus);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwCameraProviderCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProviderCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProviderCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProviderCallback::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProviderCallback::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraProviderCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwCameraProviderCallback::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProviderCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProviderCallback::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraProviderCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwCameraProviderCallback::BnHwCameraProviderCallback(const ::android::sp<ICameraProviderCallback> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.camera.provider@2.6", "ICameraProviderCallback") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwCameraProviderCallback::~BnHwCameraProviderCallback() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::camera::provider::V2_6::ICameraProviderCallback follow.
::android::status_t BnHwCameraProviderCallback::_hidl_physicalCameraDeviceStatusChange(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraProviderCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* cameraDeviceName;
    const ::android::hardware::hidl_string* physicalCameraDeviceName;
    ::android::hardware::camera::common::V1_0::CameraDeviceStatus newStatus;

    size_t _hidl_cameraDeviceName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*cameraDeviceName), &_hidl_cameraDeviceName_parent,  reinterpret_cast<const void **>(&cameraDeviceName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*cameraDeviceName),
            _hidl_data,
            _hidl_cameraDeviceName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_physicalCameraDeviceName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*physicalCameraDeviceName), &_hidl_physicalCameraDeviceName_parent,  reinterpret_cast<const void **>(&physicalCameraDeviceName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*physicalCameraDeviceName),
            _hidl_data,
            _hidl_physicalCameraDeviceName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32((uint32_t *)&newStatus);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraProviderCallback::physicalCameraDeviceStatusChange::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)cameraDeviceName);
        _hidl_args.push_back((void *)physicalCameraDeviceName);
        _hidl_args.push_back((void *)&newStatus);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.provider", "2.6", "ICameraProviderCallback", "physicalCameraDeviceStatusChange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraProviderCallback*>(_hidl_this->getImpl().get())->physicalCameraDeviceStatusChange(*cameraDeviceName, *physicalCameraDeviceName, newStatus);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.provider", "2.6", "ICameraProviderCallback", "physicalCameraDeviceStatusChange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::camera::provider::V2_4::ICameraProviderCallback follow.

// Methods from ::android::hardware::camera::provider::V2_6::ICameraProviderCallback follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwCameraProviderCallback::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwCameraProviderCallback::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwCameraProviderCallback::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* cameraDeviceStatusChange */:
        {
            _hidl_err = ::android::hardware::camera::provider::V2_4::BnHwCameraProviderCallback::_hidl_cameraDeviceStatusChange(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* torchModeStatusChange */:
        {
            _hidl_err = ::android::hardware::camera::provider::V2_4::BnHwCameraProviderCallback::_hidl_torchModeStatusChange(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* physicalCameraDeviceStatusChange */:
        {
            _hidl_err = ::android::hardware::camera::provider::V2_6::BnHwCameraProviderCallback::_hidl_physicalCameraDeviceStatusChange(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsCameraProviderCallback::BsCameraProviderCallback(const ::android::sp<::android::hardware::camera::provider::V2_6::ICameraProviderCallback> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.camera.provider@2.6", "ICameraProviderCallback"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsCameraProviderCallback::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ICameraProviderCallback> ICameraProviderCallback::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraProviderCallback>(serviceName, false, getStub);
}

::android::sp<ICameraProviderCallback> ICameraProviderCallback::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraProviderCallback>(serviceName, true, getStub);
}

::android::status_t ICameraProviderCallback::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ICameraProviderCallback::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.camera.provider@2.6::ICameraProviderCallback",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_6
}  // namespace provider
}  // namespace camera
}  // namespace hardware
}  // namespace android
