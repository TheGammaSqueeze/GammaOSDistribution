#define LOG_TAG "android.hardware.camera.provider@2.4::CameraProvider"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/camera/provider/2.4/BpHwCameraProvider.h>
#include <android/hardware/camera/provider/2.4/BnHwCameraProvider.h>
#include <android/hardware/camera/provider/2.4/BsCameraProvider.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace camera {
namespace provider {
namespace V2_4 {

const char* ICameraProvider::descriptor("android.hardware.camera.provider@2.4::ICameraProvider");

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

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ICameraProvider::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
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
    _hidl_cb(::android::hardware::camera::provider::V2_4::ICameraProvider::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraProvider::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
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


::android::hardware::Return<::android::sp<::android::hardware::camera::provider::V2_4::ICameraProvider>> ICameraProvider::castFrom(const ::android::sp<::android::hardware::camera::provider::V2_4::ICameraProvider>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::camera::provider::V2_4::ICameraProvider>> ICameraProvider::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraProvider, ::android::hidl::base::V1_0::IBase, BpHwCameraProvider>(
            parent, "android.hardware.camera.provider@2.4::ICameraProvider", emitError);
}

BpHwCameraProvider::BpHwCameraProvider(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ICameraProvider>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.camera.provider@2.4", "ICameraProvider") {
}

void BpHwCameraProvider::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ICameraProvider>::onLastStrongRef(id);
}
// Methods from ::android::hardware::camera::provider::V2_4::ICameraProvider follow.
::android::hardware::Return<::android::hardware::camera::common::V1_0::Status> BpHwCameraProvider::_hidl_setCallback(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::camera::provider::V2_4::ICameraProviderCallback>& callback) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraProvider::setCallback::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.provider", "2.4", "ICameraProvider", "setCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::camera::common::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraProvider::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (callback == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(callback.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* setCallback */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.provider", "2.4", "ICameraProvider", "setCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::camera::common::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::camera::common::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwCameraProvider::_hidl_getVendorTags(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getVendorTags_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraProvider::getVendorTags::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getVendorTags", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* getVendorTags */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::camera::common::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<::android::hardware::camera::common::V1_0::VendorTagSection>* _hidl_out_sections;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_sections_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_sections), &_hidl__hidl_out_sections_parent,  reinterpret_cast<const void **>(&_hidl_out_sections));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_sections_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::camera::common::V1_0::VendorTagSection> &>(*_hidl_out_sections),
                _hidl_reply,
                _hidl__hidl_out_sections_parent,
                0 /* parentOffset */, &_hidl__hidl_out_sections_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_sections->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::camera::common::V1_0::VendorTagSection &>((*_hidl_out_sections)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_sections_child,
                    _hidl_index_0 * sizeof(::android::hardware::camera::common::V1_0::VendorTagSection));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_cb(_hidl_out_status, *_hidl_out_sections);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_sections);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getVendorTags", &_hidl_args);
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

::android::hardware::Return<void> BpHwCameraProvider::_hidl_getCameraIdList(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getCameraIdList_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraProvider::getCameraIdList::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getCameraIdList", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* getCameraIdList */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::camera::common::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<::android::hardware::hidl_string>* _hidl_out_cameraDeviceNames;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_cameraDeviceNames_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_cameraDeviceNames), &_hidl__hidl_out_cameraDeviceNames_parent,  reinterpret_cast<const void **>(&_hidl_out_cameraDeviceNames));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_cameraDeviceNames_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(*_hidl_out_cameraDeviceNames),
                _hidl_reply,
                _hidl__hidl_out_cameraDeviceNames_parent,
                0 /* parentOffset */, &_hidl__hidl_out_cameraDeviceNames_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_cameraDeviceNames->size(); ++_hidl_index_0) {
            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_string &>((*_hidl_out_cameraDeviceNames)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_cameraDeviceNames_child,
                    _hidl_index_0 * sizeof(::android::hardware::hidl_string));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_cb(_hidl_out_status, *_hidl_out_cameraDeviceNames);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_cameraDeviceNames);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getCameraIdList", &_hidl_args);
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

::android::hardware::Return<void> BpHwCameraProvider::_hidl_isSetTorchModeSupported(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, isSetTorchModeSupported_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraProvider::isSetTorchModeSupported::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.provider", "2.4", "ICameraProvider", "isSetTorchModeSupported", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* isSetTorchModeSupported */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::camera::common::V1_0::Status _hidl_out_status;
        bool _hidl_out_support;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readBool(&_hidl_out_support);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_support);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_support);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.provider", "2.4", "ICameraProvider", "isSetTorchModeSupported", &_hidl_args);
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

::android::hardware::Return<void> BpHwCameraProvider::_hidl_getCameraDeviceInterface_V1_x(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& cameraDeviceName, getCameraDeviceInterface_V1_x_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraProvider::getCameraDeviceInterface_V1_x::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cameraDeviceName);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getCameraDeviceInterface_V1_x", &_hidl_args);
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

    size_t _hidl_cameraDeviceName_parent;

    _hidl_err = _hidl_data.writeBuffer(&cameraDeviceName, sizeof(cameraDeviceName), &_hidl_cameraDeviceName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            cameraDeviceName,
            &_hidl_data,
            _hidl_cameraDeviceName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* getCameraDeviceInterface_V1_x */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::camera::common::V1_0::Status _hidl_out_status;
        ::android::sp<::android::hardware::camera::device::V1_0::ICameraDevice> _hidl_out_device;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        {
            ::android::sp<::android::hardware::IBinder> _hidl_binder;
            _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
            if (_hidl_err != ::android::OK) { return; }

            _hidl_out_device = ::android::hardware::fromBinder<::android::hardware::camera::device::V1_0::ICameraDevice,::android::hardware::camera::device::V1_0::BpHwCameraDevice,::android::hardware::camera::device::V1_0::BnHwCameraDevice>(_hidl_binder);
        }

        _hidl_cb(_hidl_out_status, _hidl_out_device);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_device);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getCameraDeviceInterface_V1_x", &_hidl_args);
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

::android::hardware::Return<void> BpHwCameraProvider::_hidl_getCameraDeviceInterface_V3_x(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& cameraDeviceName, getCameraDeviceInterface_V3_x_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraProvider::getCameraDeviceInterface_V3_x::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cameraDeviceName);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getCameraDeviceInterface_V3_x", &_hidl_args);
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

    size_t _hidl_cameraDeviceName_parent;

    _hidl_err = _hidl_data.writeBuffer(&cameraDeviceName, sizeof(cameraDeviceName), &_hidl_cameraDeviceName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            cameraDeviceName,
            &_hidl_data,
            _hidl_cameraDeviceName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* getCameraDeviceInterface_V3_x */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::camera::common::V1_0::Status _hidl_out_status;
        ::android::sp<::android::hardware::camera::device::V3_2::ICameraDevice> _hidl_out_device;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        {
            ::android::sp<::android::hardware::IBinder> _hidl_binder;
            _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
            if (_hidl_err != ::android::OK) { return; }

            _hidl_out_device = ::android::hardware::fromBinder<::android::hardware::camera::device::V3_2::ICameraDevice,::android::hardware::camera::device::V3_2::BpHwCameraDevice,::android::hardware::camera::device::V3_2::BnHwCameraDevice>(_hidl_binder);
        }

        _hidl_cb(_hidl_out_status, _hidl_out_device);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_device);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getCameraDeviceInterface_V3_x", &_hidl_args);
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
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.camera.provider@2.4", "ICameraProvider") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwCameraProvider::~BnHwCameraProvider() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::camera::provider::V2_4::ICameraProvider follow.
::android::status_t BnHwCameraProvider::_hidl_setCallback(
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

    ::android::sp<::android::hardware::camera::provider::V2_4::ICameraProviderCallback> callback;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<::android::hardware::camera::provider::V2_4::ICameraProviderCallback,::android::hardware::camera::provider::V2_4::BpHwCameraProviderCallback,::android::hardware::camera::provider::V2_4::BnHwCameraProviderCallback>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraProvider::setCallback::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.provider", "2.4", "ICameraProvider", "setCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::camera::common::V1_0::Status _hidl_out_status = static_cast<ICameraProvider*>(_hidl_this->getImpl().get())->setCallback(callback);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.provider", "2.4", "ICameraProvider", "setCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCameraProvider::_hidl_getVendorTags(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraProvider::getVendorTags::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getVendorTags", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraProvider*>(_hidl_this->getImpl().get())->getVendorTags([&](const auto &_hidl_out_status, const auto &_hidl_out_sections) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getVendorTags: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_sections_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_sections, sizeof(_hidl_out_sections), &_hidl__hidl_out_sections_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_sections_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_sections,
                _hidl_reply,
                _hidl__hidl_out_sections_parent,
                0 /* parentOffset */, &_hidl__hidl_out_sections_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_sections.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_sections[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_sections_child,
                    _hidl_index_0 * sizeof(::android::hardware::camera::common::V1_0::VendorTagSection));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_sections);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getVendorTags", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getVendorTags: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwCameraProvider::_hidl_getCameraIdList(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraProvider::getCameraIdList::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getCameraIdList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraProvider*>(_hidl_this->getImpl().get())->getCameraIdList([&](const auto &_hidl_out_status, const auto &_hidl_out_cameraDeviceNames) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getCameraIdList: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_cameraDeviceNames_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_cameraDeviceNames, sizeof(_hidl_out_cameraDeviceNames), &_hidl__hidl_out_cameraDeviceNames_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_cameraDeviceNames_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_cameraDeviceNames,
                _hidl_reply,
                _hidl__hidl_out_cameraDeviceNames_parent,
                0 /* parentOffset */, &_hidl__hidl_out_cameraDeviceNames_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_cameraDeviceNames.size(); ++_hidl_index_0) {
            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    _hidl_out_cameraDeviceNames[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_cameraDeviceNames_child,
                    _hidl_index_0 * sizeof(::android::hardware::hidl_string));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_cameraDeviceNames);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getCameraIdList", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getCameraIdList: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwCameraProvider::_hidl_isSetTorchModeSupported(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraProvider::isSetTorchModeSupported::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.provider", "2.4", "ICameraProvider", "isSetTorchModeSupported", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraProvider*>(_hidl_this->getImpl().get())->isSetTorchModeSupported([&](const auto &_hidl_out_status, const auto &_hidl_out_support) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("isSetTorchModeSupported: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeBool(_hidl_out_support);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_support);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.provider", "2.4", "ICameraProvider", "isSetTorchModeSupported", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("isSetTorchModeSupported: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwCameraProvider::_hidl_getCameraDeviceInterface_V1_x(
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

    const ::android::hardware::hidl_string* cameraDeviceName;

    size_t _hidl_cameraDeviceName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*cameraDeviceName), &_hidl_cameraDeviceName_parent,  reinterpret_cast<const void **>(&cameraDeviceName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*cameraDeviceName),
            _hidl_data,
            _hidl_cameraDeviceName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraProvider::getCameraDeviceInterface_V1_x::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)cameraDeviceName);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getCameraDeviceInterface_V1_x", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraProvider*>(_hidl_this->getImpl().get())->getCameraDeviceInterface_V1_x(*cameraDeviceName, [&](const auto &_hidl_out_status, const auto &_hidl_out_device) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getCameraDeviceInterface_V1_x: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        if (_hidl_out_device == nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
        } else {
            ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_device.get());
            if (_hidl_binder.get() != nullptr) {
                _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
            } else {
                _hidl_err = ::android::UNKNOWN_ERROR;
            }
        }
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_device);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getCameraDeviceInterface_V1_x", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getCameraDeviceInterface_V1_x: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwCameraProvider::_hidl_getCameraDeviceInterface_V3_x(
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

    const ::android::hardware::hidl_string* cameraDeviceName;

    size_t _hidl_cameraDeviceName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*cameraDeviceName), &_hidl_cameraDeviceName_parent,  reinterpret_cast<const void **>(&cameraDeviceName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*cameraDeviceName),
            _hidl_data,
            _hidl_cameraDeviceName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraProvider::getCameraDeviceInterface_V3_x::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)cameraDeviceName);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getCameraDeviceInterface_V3_x", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraProvider*>(_hidl_this->getImpl().get())->getCameraDeviceInterface_V3_x(*cameraDeviceName, [&](const auto &_hidl_out_status, const auto &_hidl_out_device) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getCameraDeviceInterface_V3_x: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        if (_hidl_out_device == nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
        } else {
            ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_device.get());
            if (_hidl_binder.get() != nullptr) {
                _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
            } else {
                _hidl_err = ::android::UNKNOWN_ERROR;
            }
        }
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_device);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.camera.provider", "2.4", "ICameraProvider", "getCameraDeviceInterface_V3_x", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getCameraDeviceInterface_V3_x: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::camera::provider::V2_4::ICameraProvider follow.

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

BsCameraProvider::BsCameraProvider(const ::android::sp<::android::hardware::camera::provider::V2_4::ICameraProvider> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.camera.provider@2.4", "ICameraProvider"), mImpl(impl) {
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
            sm->registerForNotifications("android.hardware.camera.provider@2.4::ICameraProvider",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_4
}  // namespace provider
}  // namespace camera
}  // namespace hardware
}  // namespace android
