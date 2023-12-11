#define LOG_TAG "android.hardware.camera.device@3.5::CameraDevice"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/camera/device/3.5/BpHwCameraDevice.h>
#include <android/hardware/camera/device/3.5/BnHwCameraDevice.h>
#include <android/hardware/camera/device/3.5/BsCameraDevice.h>
#include <android/hardware/camera/device/3.2/BpHwCameraDevice.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace camera {
namespace device {
namespace V3_5 {

const char* ICameraDevice::descriptor("android.hardware.camera.device@3.5::ICameraDevice");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ICameraDevice::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwCameraDevice(static_cast<ICameraDevice *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ICameraDevice::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsCameraDevice(static_cast<ICameraDevice *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ICameraDevice::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ICameraDevice::descriptor);
}

// Methods from ::android::hardware::camera::device::V3_2::ICameraDevice follow.
// no default implementation for: ::android::hardware::Return<void> ICameraDevice::getResourceCost(getResourceCost_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraDevice::getCameraCharacteristics(getCameraCharacteristics_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::camera::common::V1_0::Status> ICameraDevice::setTorchMode(::android::hardware::camera::common::V1_0::TorchMode mode)
// no default implementation for: ::android::hardware::Return<void> ICameraDevice::open(const ::android::sp<::android::hardware::camera::device::V3_2::ICameraDeviceCallback>& callback, open_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraDevice::dumpState(const ::android::hardware::hidl_handle& fd)

// Methods from ::android::hardware::camera::device::V3_5::ICameraDevice follow.
// no default implementation for: ::android::hardware::Return<void> ICameraDevice::getPhysicalCameraCharacteristics(const ::android::hardware::hidl_string& physicalCameraId, getPhysicalCameraCharacteristics_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraDevice::isStreamCombinationSupported(const ::android::hardware::camera::device::V3_4::StreamConfiguration& streams, isStreamCombinationSupported_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ICameraDevice::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::camera::device::V3_5::ICameraDevice::descriptor,
        ::android::hardware::camera::device::V3_2::ICameraDevice::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDevice::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDevice::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::camera::device::V3_5::ICameraDevice::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDevice::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){9,171,155,36,153,68,41,217,187,50,163,251,66,11,111,107,227,228,126,182,85,19,154,44,8,196,232,13,63,51,255,149} /* 09ab9b24994429d9bb32a3fb420b6f6be3e47eb655139a2c08c4e80d3f33ff95 */,
        (uint8_t[32]){42,85,226,36,170,155,198,44,3,135,205,133,173,60,151,227,63,12,51,164,225,72,156,186,232,107,37,35,230,249,223,53} /* 2a55e224aa9bc62c0387cd85ad3c97e33f0c33a4e1489cbae86b2523e6f9df35 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDevice::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraDevice::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ICameraDevice::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraDevice::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ICameraDevice::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraDevice::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::camera::device::V3_5::ICameraDevice>> ICameraDevice::castFrom(const ::android::sp<::android::hardware::camera::device::V3_5::ICameraDevice>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::camera::device::V3_5::ICameraDevice>> ICameraDevice::castFrom(const ::android::sp<::android::hardware::camera::device::V3_2::ICameraDevice>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraDevice, ::android::hardware::camera::device::V3_2::ICameraDevice, BpHwCameraDevice>(
            parent, "android.hardware.camera.device@3.5::ICameraDevice", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::camera::device::V3_5::ICameraDevice>> ICameraDevice::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraDevice, ::android::hidl::base::V1_0::IBase, BpHwCameraDevice>(
            parent, "android.hardware.camera.device@3.5::ICameraDevice", emitError);
}

BpHwCameraDevice::BpHwCameraDevice(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ICameraDevice>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.camera.device@3.5", "ICameraDevice") {
}

void BpHwCameraDevice::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ICameraDevice>::onLastStrongRef(id);
}
// Methods from ::android::hardware::camera::device::V3_5::ICameraDevice follow.
::android::hardware::Return<void> BpHwCameraDevice::_hidl_getPhysicalCameraCharacteristics(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& physicalCameraId, getPhysicalCameraCharacteristics_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDevice::getPhysicalCameraCharacteristics::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&physicalCameraId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.device", "3.5", "ICameraDevice", "getPhysicalCameraCharacteristics", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_physicalCameraId_parent;

    _hidl_err = _hidl_data.writeBuffer(&physicalCameraId, sizeof(physicalCameraId), &_hidl_physicalCameraId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            physicalCameraId,
            &_hidl_data,
            _hidl_physicalCameraId_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* getPhysicalCameraCharacteristics */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::camera::common::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_cameraCharacteristics;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_cameraCharacteristics_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_cameraCharacteristics), &_hidl__hidl_out_cameraCharacteristics_parent,  reinterpret_cast<const void **>(&_hidl_out_cameraCharacteristics));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_cameraCharacteristics_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_cameraCharacteristics),
                _hidl_reply,
                _hidl__hidl_out_cameraCharacteristics_parent,
                0 /* parentOffset */, &_hidl__hidl_out_cameraCharacteristics_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_cameraCharacteristics);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_cameraCharacteristics);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.device", "3.5", "ICameraDevice", "getPhysicalCameraCharacteristics", &_hidl_args);
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

::android::hardware::Return<void> BpHwCameraDevice::_hidl_isStreamCombinationSupported(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::camera::device::V3_4::StreamConfiguration& streams, isStreamCombinationSupported_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraDevice::isStreamCombinationSupported::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&streams);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.device", "3.5", "ICameraDevice", "isStreamCombinationSupported", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_streams_parent;

    _hidl_err = _hidl_data.writeBuffer(&streams, sizeof(streams), &_hidl_streams_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            streams,
            &_hidl_data,
            _hidl_streams_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* isStreamCombinationSupported */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::camera::common::V1_0::Status _hidl_out_status;
        bool _hidl_out_queryStatus;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readBool(&_hidl_out_queryStatus);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_queryStatus);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_queryStatus);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.device", "3.5", "ICameraDevice", "isStreamCombinationSupported", &_hidl_args);
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


// Methods from ::android::hardware::camera::device::V3_2::ICameraDevice follow.
::android::hardware::Return<void> BpHwCameraDevice::getResourceCost(getResourceCost_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_2::BpHwCameraDevice::_hidl_getResourceCost(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDevice::getCameraCharacteristics(getCameraCharacteristics_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_2::BpHwCameraDevice::_hidl_getCameraCharacteristics(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::camera::common::V1_0::Status> BpHwCameraDevice::setTorchMode(::android::hardware::camera::common::V1_0::TorchMode mode){
    ::android::hardware::Return<::android::hardware::camera::common::V1_0::Status>  _hidl_out = ::android::hardware::camera::device::V3_2::BpHwCameraDevice::_hidl_setTorchMode(this, this, mode);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDevice::open(const ::android::sp<::android::hardware::camera::device::V3_2::ICameraDeviceCallback>& callback, open_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_2::BpHwCameraDevice::_hidl_open(this, this, callback, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDevice::dumpState(const ::android::hardware::hidl_handle& fd){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_2::BpHwCameraDevice::_hidl_dumpState(this, this, fd);

    return _hidl_out;
}


// Methods from ::android::hardware::camera::device::V3_5::ICameraDevice follow.
::android::hardware::Return<void> BpHwCameraDevice::getPhysicalCameraCharacteristics(const ::android::hardware::hidl_string& physicalCameraId, getPhysicalCameraCharacteristics_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_5::BpHwCameraDevice::_hidl_getPhysicalCameraCharacteristics(this, this, physicalCameraId, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDevice::isStreamCombinationSupported(const ::android::hardware::camera::device::V3_4::StreamConfiguration& streams, isStreamCombinationSupported_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::device::V3_5::BpHwCameraDevice::_hidl_isStreamCombinationSupported(this, this, streams, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwCameraDevice::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDevice::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDevice::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDevice::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDevice::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraDevice::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwCameraDevice::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDevice::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraDevice::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraDevice::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwCameraDevice::BnHwCameraDevice(const ::android::sp<ICameraDevice> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.camera.device@3.5", "ICameraDevice") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwCameraDevice::~BnHwCameraDevice() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::camera::device::V3_5::ICameraDevice follow.
::android::status_t BnHwCameraDevice::_hidl_getPhysicalCameraCharacteristics(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* physicalCameraId;

    size_t _hidl_physicalCameraId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*physicalCameraId), &_hidl_physicalCameraId_parent,  reinterpret_cast<const void **>(&physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*physicalCameraId),
            _hidl_data,
            _hidl_physicalCameraId_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDevice::getPhysicalCameraCharacteristics::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)physicalCameraId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.device", "3.5", "ICameraDevice", "getPhysicalCameraCharacteristics", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDevice*>(_hidl_this->getImpl().get())->getPhysicalCameraCharacteristics(*physicalCameraId, [&](const auto &_hidl_out_status, const auto &_hidl_out_cameraCharacteristics) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getPhysicalCameraCharacteristics: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_cameraCharacteristics_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_cameraCharacteristics, sizeof(_hidl_out_cameraCharacteristics), &_hidl__hidl_out_cameraCharacteristics_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_cameraCharacteristics_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_cameraCharacteristics,
                _hidl_reply,
                _hidl__hidl_out_cameraCharacteristics_parent,
                0 /* parentOffset */, &_hidl__hidl_out_cameraCharacteristics_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_cameraCharacteristics);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.device", "3.5", "ICameraDevice", "getPhysicalCameraCharacteristics", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getPhysicalCameraCharacteristics: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwCameraDevice::_hidl_isStreamCombinationSupported(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::camera::device::V3_4::StreamConfiguration* streams;

    size_t _hidl_streams_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*streams), &_hidl_streams_parent,  const_cast<const void**>(reinterpret_cast<void **>(&streams)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::camera::device::V3_4::StreamConfiguration &>(*streams),
            _hidl_data,
            _hidl_streams_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraDevice::isStreamCombinationSupported::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)streams);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.device", "3.5", "ICameraDevice", "isStreamCombinationSupported", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraDevice*>(_hidl_this->getImpl().get())->isStreamCombinationSupported(*streams, [&](const auto &_hidl_out_status, const auto &_hidl_out_queryStatus) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("isStreamCombinationSupported: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeBool(_hidl_out_queryStatus);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_queryStatus);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.device", "3.5", "ICameraDevice", "isStreamCombinationSupported", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("isStreamCombinationSupported: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::camera::device::V3_2::ICameraDevice follow.

// Methods from ::android::hardware::camera::device::V3_5::ICameraDevice follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwCameraDevice::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwCameraDevice::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwCameraDevice::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* getResourceCost */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_2::BnHwCameraDevice::_hidl_getResourceCost(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getCameraCharacteristics */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_2::BnHwCameraDevice::_hidl_getCameraCharacteristics(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* setTorchMode */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_2::BnHwCameraDevice::_hidl_setTorchMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* open */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_2::BnHwCameraDevice::_hidl_open(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* dumpState */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_2::BnHwCameraDevice::_hidl_dumpState(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* getPhysicalCameraCharacteristics */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_5::BnHwCameraDevice::_hidl_getPhysicalCameraCharacteristics(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* isStreamCombinationSupported */:
        {
            _hidl_err = ::android::hardware::camera::device::V3_5::BnHwCameraDevice::_hidl_isStreamCombinationSupported(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsCameraDevice::BsCameraDevice(const ::android::sp<::android::hardware::camera::device::V3_5::ICameraDevice> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.camera.device@3.5", "ICameraDevice"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsCameraDevice::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ICameraDevice> ICameraDevice::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraDevice>(serviceName, false, getStub);
}

::android::sp<ICameraDevice> ICameraDevice::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraDevice>(serviceName, true, getStub);
}

::android::status_t ICameraDevice::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ICameraDevice::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.camera.device@3.5::ICameraDevice",
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
