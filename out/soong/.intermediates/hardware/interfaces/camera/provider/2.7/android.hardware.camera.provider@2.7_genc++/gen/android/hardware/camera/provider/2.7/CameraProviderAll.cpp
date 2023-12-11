#define LOG_TAG "android.hardware.camera.provider@2.7::CameraProvider"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/camera/provider/2.7/BpHwCameraProvider.h>
#include <android/hardware/camera/provider/2.7/BnHwCameraProvider.h>
#include <android/hardware/camera/provider/2.7/BsCameraProvider.h>
#include <android/hardware/camera/provider/2.6/BpHwCameraProvider.h>
#include <android/hardware/camera/provider/2.5/BpHwCameraProvider.h>
#include <android/hardware/camera/provider/2.4/BpHwCameraProvider.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace camera {
namespace provider {
namespace V2_7 {

const char* ICameraProvider::descriptor("android.hardware.camera.provider@2.7::ICameraProvider");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ICameraProvider::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwCameraProvider(static_cast<ICameraProvider *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ICameraProvider::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsCameraProvider(static_cast<ICameraProvider *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ICameraProvider::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ICameraProvider::descriptor);
}

// Methods from ::android::hardware::camera::provider::V2_4::ICameraProvider follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::camera::common::V1_0::Status> ICameraProvider::setCallback(const ::android::sp<::android::hardware::camera::provider::V2_4::ICameraProviderCallback>& callback)
// no default implementation for: ::android::hardware::Return<void> ICameraProvider::getVendorTags(getVendorTags_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraProvider::getCameraIdList(getCameraIdList_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraProvider::isSetTorchModeSupported(isSetTorchModeSupported_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraProvider::getCameraDeviceInterface_V1_x(const ::android::hardware::hidl_string& cameraDeviceName, getCameraDeviceInterface_V1_x_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraProvider::getCameraDeviceInterface_V3_x(const ::android::hardware::hidl_string& cameraDeviceName, getCameraDeviceInterface_V3_x_cb _hidl_cb)

// Methods from ::android::hardware::camera::provider::V2_5::ICameraProvider follow.
// no default implementation for: ::android::hardware::Return<void> ICameraProvider::notifyDeviceStateChange(::android::hardware::hidl_bitfield<::android::hardware::camera::provider::V2_5::DeviceState> newState)

// Methods from ::android::hardware::camera::provider::V2_6::ICameraProvider follow.
// no default implementation for: ::android::hardware::Return<void> ICameraProvider::getConcurrentStreamingCameraIds(getConcurrentStreamingCameraIds_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraProvider::isConcurrentStreamCombinationSupported(const ::android::hardware::hidl_vec<::android::hardware::camera::provider::V2_6::CameraIdAndStreamCombination>& configs, isConcurrentStreamCombinationSupported_cb _hidl_cb)

// Methods from ::android::hardware::camera::provider::V2_7::ICameraProvider follow.
// no default implementation for: ::android::hardware::Return<void> ICameraProvider::isConcurrentStreamCombinationSupported_2_7(const ::android::hardware::hidl_vec<::android::hardware::camera::provider::V2_7::CameraIdAndStreamCombination>& configs, isConcurrentStreamCombinationSupported_2_7_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ICameraProvider::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::camera::provider::V2_7::ICameraProvider::descriptor,
        ::android::hardware::camera::provider::V2_6::ICameraProvider::descriptor,
        ::android::hardware::camera::provider::V2_5::ICameraProvider::descriptor,
        ::android::hardware::camera::provider::V2_4::ICameraProvider::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraProvider::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraProvider::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::camera::provider::V2_7::ICameraProvider::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraProvider::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){152,255,130,90,125,55,229,171,152,53,2,209,60,236,31,46,90,156,172,155,103,75,111,241,165,43,207,84,15,78,49,94} /* 98ff825a7d37e5ab983502d13cec1f2e5a9cac9b674b6ff1a52bcf540f4e315e */,
        (uint8_t[32]){147,205,148,228,123,34,0,123,191,67,108,47,92,39,3,187,123,40,89,209,183,20,214,174,21,82,13,181,86,103,186,108} /* 93cd94e47b22007bbf436c2f5c2703bb7b2859d1b714d6ae15520db55667ba6c */,
        (uint8_t[32]){15,179,154,120,9,173,28,82,179,239,187,237,94,244,116,155,6,194,164,241,241,156,220,62,250,46,61,155,40,241,32,92} /* 0fb39a7809ad1c52b3efbbed5ef4749b06c2a4f1f19cdc3efa2e3d9b28f1205c */,
        (uint8_t[32]){188,238,232,30,193,181,147,36,171,208,89,50,181,98,15,218,90,101,137,89,124,156,179,149,59,167,243,234,2,204,205,62} /* bceee81ec1b59324abd05932b5620fda5a6589597c9cb3953ba7f3ea02cccd3e */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraProvider::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraProvider::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ICameraProvider::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraProvider::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ICameraProvider::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraProvider::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::camera::provider::V2_7::ICameraProvider>> ICameraProvider::castFrom(const ::android::sp<::android::hardware::camera::provider::V2_7::ICameraProvider>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::camera::provider::V2_7::ICameraProvider>> ICameraProvider::castFrom(const ::android::sp<::android::hardware::camera::provider::V2_6::ICameraProvider>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraProvider, ::android::hardware::camera::provider::V2_6::ICameraProvider, BpHwCameraProvider>(
            parent, "android.hardware.camera.provider@2.7::ICameraProvider", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::camera::provider::V2_7::ICameraProvider>> ICameraProvider::castFrom(const ::android::sp<::android::hardware::camera::provider::V2_5::ICameraProvider>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraProvider, ::android::hardware::camera::provider::V2_5::ICameraProvider, BpHwCameraProvider>(
            parent, "android.hardware.camera.provider@2.7::ICameraProvider", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::camera::provider::V2_7::ICameraProvider>> ICameraProvider::castFrom(const ::android::sp<::android::hardware::camera::provider::V2_4::ICameraProvider>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraProvider, ::android::hardware::camera::provider::V2_4::ICameraProvider, BpHwCameraProvider>(
            parent, "android.hardware.camera.provider@2.7::ICameraProvider", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::camera::provider::V2_7::ICameraProvider>> ICameraProvider::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraProvider, ::android::hidl::base::V1_0::IBase, BpHwCameraProvider>(
            parent, "android.hardware.camera.provider@2.7::ICameraProvider", emitError);
}

BpHwCameraProvider::BpHwCameraProvider(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ICameraProvider>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.camera.provider@2.7", "ICameraProvider") {
}

void BpHwCameraProvider::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ICameraProvider>::onLastStrongRef(id);
}
// Methods from ::android::hardware::camera::provider::V2_7::ICameraProvider follow.
::android::hardware::Return<void> BpHwCameraProvider::_hidl_isConcurrentStreamCombinationSupported_2_7(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::camera::provider::V2_7::CameraIdAndStreamCombination>& configs, isConcurrentStreamCombinationSupported_2_7_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraProvider::isConcurrentStreamCombinationSupported_2_7::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&configs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.provider", "2.7", "ICameraProvider", "isConcurrentStreamCombinationSupported_2_7", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraProvider::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_configs_parent;

    _hidl_err = _hidl_data.writeBuffer(&configs, sizeof(configs), &_hidl_configs_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_configs_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            configs,
            &_hidl_data,
            _hidl_configs_parent,
            0 /* parentOffset */, &_hidl_configs_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < configs.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                configs[_hidl_index_0],
                &_hidl_data,
                _hidl_configs_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::provider::V2_7::CameraIdAndStreamCombination));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* isConcurrentStreamCombinationSupported_2_7 */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
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
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.provider", "2.7", "ICameraProvider", "isConcurrentStreamCombinationSupported_2_7", &_hidl_args);
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


// Methods from ::android::hardware::camera::provider::V2_4::ICameraProvider follow.
::android::hardware::Return<::android::hardware::camera::common::V1_0::Status> BpHwCameraProvider::setCallback(const ::android::sp<::android::hardware::camera::provider::V2_4::ICameraProviderCallback>& callback){
    ::android::hardware::Return<::android::hardware::camera::common::V1_0::Status>  _hidl_out = ::android::hardware::camera::provider::V2_4::BpHwCameraProvider::_hidl_setCallback(this, this, callback);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProvider::getVendorTags(getVendorTags_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::provider::V2_4::BpHwCameraProvider::_hidl_getVendorTags(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProvider::getCameraIdList(getCameraIdList_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::provider::V2_4::BpHwCameraProvider::_hidl_getCameraIdList(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProvider::isSetTorchModeSupported(isSetTorchModeSupported_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::provider::V2_4::BpHwCameraProvider::_hidl_isSetTorchModeSupported(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProvider::getCameraDeviceInterface_V1_x(const ::android::hardware::hidl_string& cameraDeviceName, getCameraDeviceInterface_V1_x_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::provider::V2_4::BpHwCameraProvider::_hidl_getCameraDeviceInterface_V1_x(this, this, cameraDeviceName, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProvider::getCameraDeviceInterface_V3_x(const ::android::hardware::hidl_string& cameraDeviceName, getCameraDeviceInterface_V3_x_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::provider::V2_4::BpHwCameraProvider::_hidl_getCameraDeviceInterface_V3_x(this, this, cameraDeviceName, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hardware::camera::provider::V2_5::ICameraProvider follow.
::android::hardware::Return<void> BpHwCameraProvider::notifyDeviceStateChange(::android::hardware::hidl_bitfield<::android::hardware::camera::provider::V2_5::DeviceState> newState){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::provider::V2_5::BpHwCameraProvider::_hidl_notifyDeviceStateChange(this, this, newState);

    return _hidl_out;
}


// Methods from ::android::hardware::camera::provider::V2_6::ICameraProvider follow.
::android::hardware::Return<void> BpHwCameraProvider::getConcurrentStreamingCameraIds(getConcurrentStreamingCameraIds_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::provider::V2_6::BpHwCameraProvider::_hidl_getConcurrentStreamingCameraIds(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProvider::isConcurrentStreamCombinationSupported(const ::android::hardware::hidl_vec<::android::hardware::camera::provider::V2_6::CameraIdAndStreamCombination>& configs, isConcurrentStreamCombinationSupported_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::provider::V2_6::BpHwCameraProvider::_hidl_isConcurrentStreamCombinationSupported(this, this, configs, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hardware::camera::provider::V2_7::ICameraProvider follow.
::android::hardware::Return<void> BpHwCameraProvider::isConcurrentStreamCombinationSupported_2_7(const ::android::hardware::hidl_vec<::android::hardware::camera::provider::V2_7::CameraIdAndStreamCombination>& configs, isConcurrentStreamCombinationSupported_2_7_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::camera::provider::V2_7::BpHwCameraProvider::_hidl_isConcurrentStreamCombinationSupported_2_7(this, this, configs, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwCameraProvider::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProvider::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProvider::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProvider::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProvider::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraProvider::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwCameraProvider::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProvider::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraProvider::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraProvider::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwCameraProvider::BnHwCameraProvider(const ::android::sp<ICameraProvider> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.camera.provider@2.7", "ICameraProvider") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwCameraProvider::~BnHwCameraProvider() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::camera::provider::V2_7::ICameraProvider follow.
::android::status_t BnHwCameraProvider::_hidl_isConcurrentStreamCombinationSupported_2_7(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraProvider::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<::android::hardware::camera::provider::V2_7::CameraIdAndStreamCombination>* configs;

    size_t _hidl_configs_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*configs), &_hidl_configs_parent,  reinterpret_cast<const void **>(&configs));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_configs_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::provider::V2_7::CameraIdAndStreamCombination> &>(*configs),
            _hidl_data,
            _hidl_configs_parent,
            0 /* parentOffset */, &_hidl_configs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < configs->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::camera::provider::V2_7::CameraIdAndStreamCombination &>((*configs)[_hidl_index_0]),
                _hidl_data,
                _hidl_configs_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::provider::V2_7::CameraIdAndStreamCombination));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraProvider::isConcurrentStreamCombinationSupported_2_7::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)configs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.provider", "2.7", "ICameraProvider", "isConcurrentStreamCombinationSupported_2_7", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraProvider*>(_hidl_this->getImpl().get())->isConcurrentStreamCombinationSupported_2_7(*configs, [&](const auto &_hidl_out_status, const auto &_hidl_out_queryStatus) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("isConcurrentStreamCombinationSupported_2_7: _hidl_cb called a second time, but must be called once.");
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
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.provider", "2.7", "ICameraProvider", "isConcurrentStreamCombinationSupported_2_7", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("isConcurrentStreamCombinationSupported_2_7: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::camera::provider::V2_4::ICameraProvider follow.

// Methods from ::android::hardware::camera::provider::V2_5::ICameraProvider follow.

// Methods from ::android::hardware::camera::provider::V2_6::ICameraProvider follow.

// Methods from ::android::hardware::camera::provider::V2_7::ICameraProvider follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwCameraProvider::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwCameraProvider::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwCameraProvider::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* setCallback */:
        {
            _hidl_err = ::android::hardware::camera::provider::V2_4::BnHwCameraProvider::_hidl_setCallback(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getVendorTags */:
        {
            _hidl_err = ::android::hardware::camera::provider::V2_4::BnHwCameraProvider::_hidl_getVendorTags(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* getCameraIdList */:
        {
            _hidl_err = ::android::hardware::camera::provider::V2_4::BnHwCameraProvider::_hidl_getCameraIdList(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* isSetTorchModeSupported */:
        {
            _hidl_err = ::android::hardware::camera::provider::V2_4::BnHwCameraProvider::_hidl_isSetTorchModeSupported(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* getCameraDeviceInterface_V1_x */:
        {
            _hidl_err = ::android::hardware::camera::provider::V2_4::BnHwCameraProvider::_hidl_getCameraDeviceInterface_V1_x(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* getCameraDeviceInterface_V3_x */:
        {
            _hidl_err = ::android::hardware::camera::provider::V2_4::BnHwCameraProvider::_hidl_getCameraDeviceInterface_V3_x(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* notifyDeviceStateChange */:
        {
            _hidl_err = ::android::hardware::camera::provider::V2_5::BnHwCameraProvider::_hidl_notifyDeviceStateChange(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* getConcurrentStreamingCameraIds */:
        {
            _hidl_err = ::android::hardware::camera::provider::V2_6::BnHwCameraProvider::_hidl_getConcurrentStreamingCameraIds(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* isConcurrentStreamCombinationSupported */:
        {
            _hidl_err = ::android::hardware::camera::provider::V2_6::BnHwCameraProvider::_hidl_isConcurrentStreamCombinationSupported(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* isConcurrentStreamCombinationSupported_2_7 */:
        {
            _hidl_err = ::android::hardware::camera::provider::V2_7::BnHwCameraProvider::_hidl_isConcurrentStreamCombinationSupported_2_7(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsCameraProvider::BsCameraProvider(const ::android::sp<::android::hardware::camera::provider::V2_7::ICameraProvider> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.camera.provider@2.7", "ICameraProvider"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsCameraProvider::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ICameraProvider> ICameraProvider::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraProvider>(serviceName, false, getStub);
}

::android::sp<ICameraProvider> ICameraProvider::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraProvider>(serviceName, true, getStub);
}

::android::status_t ICameraProvider::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ICameraProvider::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.camera.provider@2.7::ICameraProvider",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_7
}  // namespace provider
}  // namespace camera
}  // namespace hardware
}  // namespace android
