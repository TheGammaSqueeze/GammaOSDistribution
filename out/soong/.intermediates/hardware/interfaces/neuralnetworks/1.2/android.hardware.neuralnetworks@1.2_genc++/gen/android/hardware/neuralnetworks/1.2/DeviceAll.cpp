#define LOG_TAG "android.hardware.neuralnetworks@1.2::Device"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/neuralnetworks/1.2/BpHwDevice.h>
#include <android/hardware/neuralnetworks/1.2/BnHwDevice.h>
#include <android/hardware/neuralnetworks/1.2/BsDevice.h>
#include <android/hardware/neuralnetworks/1.1/BpHwDevice.h>
#include <android/hardware/neuralnetworks/1.0/BpHwDevice.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace neuralnetworks {
namespace V1_2 {

const char* IDevice::descriptor("android.hardware.neuralnetworks@1.2::IDevice");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IDevice::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwDevice(static_cast<IDevice *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IDevice::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsDevice(static_cast<IDevice *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IDevice::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IDevice::descriptor);
}

// Methods from ::android::hardware::neuralnetworks::V1_0::IDevice follow.
// no default implementation for: ::android::hardware::Return<void> IDevice::getCapabilities(getCapabilities_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDevice::getSupportedOperations(const ::android::hardware::neuralnetworks::V1_0::Model& model, getSupportedOperations_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> IDevice::prepareModel(const ::android::hardware::neuralnetworks::V1_0::Model& model, const ::android::sp<::android::hardware::neuralnetworks::V1_0::IPreparedModelCallback>& callback)
// no default implementation for: ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::DeviceStatus> IDevice::getStatus()

// Methods from ::android::hardware::neuralnetworks::V1_1::IDevice follow.
// no default implementation for: ::android::hardware::Return<void> IDevice::getCapabilities_1_1(getCapabilities_1_1_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDevice::getSupportedOperations_1_1(const ::android::hardware::neuralnetworks::V1_1::Model& model, getSupportedOperations_1_1_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> IDevice::prepareModel_1_1(const ::android::hardware::neuralnetworks::V1_1::Model& model, ::android::hardware::neuralnetworks::V1_1::ExecutionPreference preference, const ::android::sp<::android::hardware::neuralnetworks::V1_0::IPreparedModelCallback>& callback)

// Methods from ::android::hardware::neuralnetworks::V1_2::IDevice follow.
// no default implementation for: ::android::hardware::Return<void> IDevice::getVersionString(getVersionString_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDevice::getType(getType_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDevice::getCapabilities_1_2(getCapabilities_1_2_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDevice::getSupportedExtensions(getSupportedExtensions_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDevice::getSupportedOperations_1_2(const ::android::hardware::neuralnetworks::V1_2::Model& model, getSupportedOperations_1_2_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDevice::getNumberOfCacheFilesNeeded(getNumberOfCacheFilesNeeded_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> IDevice::prepareModel_1_2(const ::android::hardware::neuralnetworks::V1_2::Model& model, ::android::hardware::neuralnetworks::V1_1::ExecutionPreference preference, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& modelCache, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& dataCache, const ::android::hardware::hidl_array<uint8_t, 32 /* Constant:BYTE_SIZE_OF_CACHE_TOKEN */>& token, const ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback>& callback)
// no default implementation for: ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> IDevice::prepareModelFromCache(const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& modelCache, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& dataCache, const ::android::hardware::hidl_array<uint8_t, 32 /* Constant:BYTE_SIZE_OF_CACHE_TOKEN */>& token, const ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback>& callback)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IDevice::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::neuralnetworks::V1_2::IDevice::descriptor,
        ::android::hardware::neuralnetworks::V1_1::IDevice::descriptor,
        ::android::hardware::neuralnetworks::V1_0::IDevice::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDevice::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDevice::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::neuralnetworks::V1_2::IDevice::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDevice::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){205,132,171,25,197,144,224,231,61,210,48,123,89,26,48,147,238,24,20,126,249,94,109,84,24,100,68,99,166,98,0,118} /* cd84ab19c590e0e73dd2307b591a3093ee18147ef95e6d5418644463a6620076 */,
        (uint8_t[32]){118,152,220,35,130,162,238,180,53,65,132,14,62,230,36,243,65,8,239,223,185,118,178,191,167,193,62,241,95,184,196,196} /* 7698dc2382a2eeb43541840e3ee624f34108efdfb976b2bfa7c13ef15fb8c4c4 */,
        (uint8_t[32]){88,4,202,134,97,29,114,229,72,31,2,43,58,12,27,51,66,23,242,228,152,141,173,37,115,12,66,175,45,31,77,28} /* 5804ca86611d72e5481f022b3a0c1b334217f2e4988dad25730c42af2d1f4d1c */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDevice::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IDevice::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IDevice::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDevice::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IDevice::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IDevice::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_2::IDevice>> IDevice::castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IDevice>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_2::IDevice>> IDevice::castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_1::IDevice>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDevice, ::android::hardware::neuralnetworks::V1_1::IDevice, BpHwDevice>(
            parent, "android.hardware.neuralnetworks@1.2::IDevice", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_2::IDevice>> IDevice::castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_0::IDevice>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDevice, ::android::hardware::neuralnetworks::V1_0::IDevice, BpHwDevice>(
            parent, "android.hardware.neuralnetworks@1.2::IDevice", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_2::IDevice>> IDevice::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDevice, ::android::hidl::base::V1_0::IBase, BpHwDevice>(
            parent, "android.hardware.neuralnetworks@1.2::IDevice", emitError);
}

BpHwDevice::BpHwDevice(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IDevice>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.neuralnetworks@1.2", "IDevice") {
}

void BpHwDevice::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IDevice>::onLastStrongRef(id);
}
// Methods from ::android::hardware::neuralnetworks::V1_2::IDevice follow.
::android::hardware::Return<void> BpHwDevice::_hidl_getVersionString(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getVersionString_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDevice::getVersionString::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "getVersionString", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* getVersionString */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::neuralnetworks::V1_0::ErrorStatus _hidl_out_status;
        const ::android::hardware::hidl_string* _hidl_out_version;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_version_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_version), &_hidl__hidl_out_version_parent,  reinterpret_cast<const void **>(&_hidl_out_version));

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(*_hidl_out_version),
                _hidl_reply,
                _hidl__hidl_out_version_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_version);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_version);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "getVersionString", &_hidl_args);
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

::android::hardware::Return<void> BpHwDevice::_hidl_getType(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getType_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDevice::getType::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "getType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* getType */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::neuralnetworks::V1_0::ErrorStatus _hidl_out_status;
        ::android::hardware::neuralnetworks::V1_2::DeviceType _hidl_out_type;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_type);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_type);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_type);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "getType", &_hidl_args);
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

::android::hardware::Return<void> BpHwDevice::_hidl_getCapabilities_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getCapabilities_1_2_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDevice::getCapabilities_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "getCapabilities_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* getCapabilities_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::neuralnetworks::V1_0::ErrorStatus _hidl_out_status;
        ::android::hardware::neuralnetworks::V1_2::Capabilities* _hidl_out_capabilities;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_capabilities_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_capabilities), &_hidl__hidl_out_capabilities_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_capabilities)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::neuralnetworks::V1_2::Capabilities &>(*_hidl_out_capabilities),
                _hidl_reply,
                _hidl__hidl_out_capabilities_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_capabilities);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_capabilities);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "getCapabilities_1_2", &_hidl_args);
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

::android::hardware::Return<void> BpHwDevice::_hidl_getSupportedExtensions(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getSupportedExtensions_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDevice::getSupportedExtensions::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "getSupportedExtensions", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* getSupportedExtensions */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::neuralnetworks::V1_0::ErrorStatus _hidl_out_status;
        const ::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::Extension>* _hidl_out_extensions;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_extensions_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_extensions), &_hidl__hidl_out_extensions_parent,  reinterpret_cast<const void **>(&_hidl_out_extensions));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_extensions_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::Extension> &>(*_hidl_out_extensions),
                _hidl_reply,
                _hidl__hidl_out_extensions_parent,
                0 /* parentOffset */, &_hidl__hidl_out_extensions_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_extensions->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::neuralnetworks::V1_2::Extension &>((*_hidl_out_extensions)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_extensions_child,
                    _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_2::Extension));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_cb(_hidl_out_status, *_hidl_out_extensions);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_extensions);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "getSupportedExtensions", &_hidl_args);
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

::android::hardware::Return<void> BpHwDevice::_hidl_getSupportedOperations_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::neuralnetworks::V1_2::Model& model, getSupportedOperations_1_2_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDevice::getSupportedOperations_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&model);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "getSupportedOperations_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_model_parent;

    _hidl_err = _hidl_data.writeBuffer(&model, sizeof(model), &_hidl_model_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            model,
            &_hidl_data,
            _hidl_model_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* getSupportedOperations_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::neuralnetworks::V1_0::ErrorStatus _hidl_out_status;
        const ::android::hardware::hidl_vec<bool>* _hidl_out_supportedOperations;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_supportedOperations_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_supportedOperations), &_hidl__hidl_out_supportedOperations_parent,  reinterpret_cast<const void **>(&_hidl_out_supportedOperations));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_supportedOperations_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<bool> &>(*_hidl_out_supportedOperations),
                _hidl_reply,
                _hidl__hidl_out_supportedOperations_parent,
                0 /* parentOffset */, &_hidl__hidl_out_supportedOperations_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_supportedOperations);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_supportedOperations);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "getSupportedOperations_1_2", &_hidl_args);
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

::android::hardware::Return<void> BpHwDevice::_hidl_getNumberOfCacheFilesNeeded(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getNumberOfCacheFilesNeeded_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDevice::getNumberOfCacheFilesNeeded::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "getNumberOfCacheFilesNeeded", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* getNumberOfCacheFilesNeeded */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::neuralnetworks::V1_0::ErrorStatus _hidl_out_status;
        uint32_t _hidl_out_numModelCache;
        uint32_t _hidl_out_numDataCache;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_numModelCache);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_numDataCache);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_numModelCache, _hidl_out_numDataCache);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_numModelCache);
            _hidl_args.push_back((void *)&_hidl_out_numDataCache);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "getNumberOfCacheFilesNeeded", &_hidl_args);
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

::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> BpHwDevice::_hidl_prepareModel_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::neuralnetworks::V1_2::Model& model, ::android::hardware::neuralnetworks::V1_1::ExecutionPreference preference, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& modelCache, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& dataCache, const ::android::hardware::hidl_array<uint8_t, 32 /* Constant:BYTE_SIZE_OF_CACHE_TOKEN */>& token, const ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback>& callback) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDevice::prepareModel_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&model);
        _hidl_args.push_back((void *)&preference);
        _hidl_args.push_back((void *)&modelCache);
        _hidl_args.push_back((void *)&dataCache);
        _hidl_args.push_back((void *)&token);
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "prepareModel_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::neuralnetworks::V1_0::ErrorStatus _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_model_parent;

    _hidl_err = _hidl_data.writeBuffer(&model, sizeof(model), &_hidl_model_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            model,
            &_hidl_data,
            _hidl_model_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)preference);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_modelCache_parent;

    _hidl_err = _hidl_data.writeBuffer(&modelCache, sizeof(modelCache), &_hidl_modelCache_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_modelCache_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            modelCache,
            &_hidl_data,
            _hidl_modelCache_parent,
            0 /* parentOffset */, &_hidl_modelCache_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < modelCache.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                modelCache[_hidl_index_0],
                &_hidl_data,
                _hidl_modelCache_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    size_t _hidl_dataCache_parent;

    _hidl_err = _hidl_data.writeBuffer(&dataCache, sizeof(dataCache), &_hidl_dataCache_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dataCache_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            dataCache,
            &_hidl_data,
            _hidl_dataCache_parent,
            0 /* parentOffset */, &_hidl_dataCache_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < dataCache.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                dataCache[_hidl_index_0],
                &_hidl_data,
                _hidl_dataCache_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    size_t _hidl_token_parent;

    _hidl_err = _hidl_data.writeBuffer(token.data(), 32 * sizeof(uint8_t), &_hidl_token_parent);
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
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(14 /* prepareModel_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "prepareModel_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus>(_hidl_status);
}

::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> BpHwDevice::_hidl_prepareModelFromCache(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& modelCache, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& dataCache, const ::android::hardware::hidl_array<uint8_t, 32 /* Constant:BYTE_SIZE_OF_CACHE_TOKEN */>& token, const ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback>& callback) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDevice::prepareModelFromCache::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&modelCache);
        _hidl_args.push_back((void *)&dataCache);
        _hidl_args.push_back((void *)&token);
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "prepareModelFromCache", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::neuralnetworks::V1_0::ErrorStatus _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_modelCache_parent;

    _hidl_err = _hidl_data.writeBuffer(&modelCache, sizeof(modelCache), &_hidl_modelCache_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_modelCache_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            modelCache,
            &_hidl_data,
            _hidl_modelCache_parent,
            0 /* parentOffset */, &_hidl_modelCache_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < modelCache.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                modelCache[_hidl_index_0],
                &_hidl_data,
                _hidl_modelCache_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    size_t _hidl_dataCache_parent;

    _hidl_err = _hidl_data.writeBuffer(&dataCache, sizeof(dataCache), &_hidl_dataCache_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dataCache_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            dataCache,
            &_hidl_data,
            _hidl_dataCache_parent,
            0 /* parentOffset */, &_hidl_dataCache_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < dataCache.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                dataCache[_hidl_index_0],
                &_hidl_data,
                _hidl_dataCache_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    size_t _hidl_token_parent;

    _hidl_err = _hidl_data.writeBuffer(token.data(), 32 * sizeof(uint8_t), &_hidl_token_parent);
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
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(15 /* prepareModelFromCache */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "prepareModelFromCache", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus>(_hidl_status);
}


// Methods from ::android::hardware::neuralnetworks::V1_0::IDevice follow.
::android::hardware::Return<void> BpHwDevice::getCapabilities(getCapabilities_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_0::BpHwDevice::_hidl_getCapabilities(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDevice::getSupportedOperations(const ::android::hardware::neuralnetworks::V1_0::Model& model, getSupportedOperations_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_0::BpHwDevice::_hidl_getSupportedOperations(this, this, model, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> BpHwDevice::prepareModel(const ::android::hardware::neuralnetworks::V1_0::Model& model, const ::android::sp<::android::hardware::neuralnetworks::V1_0::IPreparedModelCallback>& callback){
    ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus>  _hidl_out = ::android::hardware::neuralnetworks::V1_0::BpHwDevice::_hidl_prepareModel(this, this, model, callback);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::DeviceStatus> BpHwDevice::getStatus(){
    ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::DeviceStatus>  _hidl_out = ::android::hardware::neuralnetworks::V1_0::BpHwDevice::_hidl_getStatus(this, this);

    return _hidl_out;
}


// Methods from ::android::hardware::neuralnetworks::V1_1::IDevice follow.
::android::hardware::Return<void> BpHwDevice::getCapabilities_1_1(getCapabilities_1_1_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_1::BpHwDevice::_hidl_getCapabilities_1_1(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDevice::getSupportedOperations_1_1(const ::android::hardware::neuralnetworks::V1_1::Model& model, getSupportedOperations_1_1_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_1::BpHwDevice::_hidl_getSupportedOperations_1_1(this, this, model, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> BpHwDevice::prepareModel_1_1(const ::android::hardware::neuralnetworks::V1_1::Model& model, ::android::hardware::neuralnetworks::V1_1::ExecutionPreference preference, const ::android::sp<::android::hardware::neuralnetworks::V1_0::IPreparedModelCallback>& callback){
    ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus>  _hidl_out = ::android::hardware::neuralnetworks::V1_1::BpHwDevice::_hidl_prepareModel_1_1(this, this, model, preference, callback);

    return _hidl_out;
}


// Methods from ::android::hardware::neuralnetworks::V1_2::IDevice follow.
::android::hardware::Return<void> BpHwDevice::getVersionString(getVersionString_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_2::BpHwDevice::_hidl_getVersionString(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDevice::getType(getType_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_2::BpHwDevice::_hidl_getType(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDevice::getCapabilities_1_2(getCapabilities_1_2_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_2::BpHwDevice::_hidl_getCapabilities_1_2(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDevice::getSupportedExtensions(getSupportedExtensions_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_2::BpHwDevice::_hidl_getSupportedExtensions(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDevice::getSupportedOperations_1_2(const ::android::hardware::neuralnetworks::V1_2::Model& model, getSupportedOperations_1_2_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_2::BpHwDevice::_hidl_getSupportedOperations_1_2(this, this, model, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDevice::getNumberOfCacheFilesNeeded(getNumberOfCacheFilesNeeded_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_2::BpHwDevice::_hidl_getNumberOfCacheFilesNeeded(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> BpHwDevice::prepareModel_1_2(const ::android::hardware::neuralnetworks::V1_2::Model& model, ::android::hardware::neuralnetworks::V1_1::ExecutionPreference preference, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& modelCache, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& dataCache, const ::android::hardware::hidl_array<uint8_t, 32 /* Constant:BYTE_SIZE_OF_CACHE_TOKEN */>& token, const ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback>& callback){
    ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus>  _hidl_out = ::android::hardware::neuralnetworks::V1_2::BpHwDevice::_hidl_prepareModel_1_2(this, this, model, preference, modelCache, dataCache, token, callback);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> BpHwDevice::prepareModelFromCache(const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& modelCache, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& dataCache, const ::android::hardware::hidl_array<uint8_t, 32 /* Constant:BYTE_SIZE_OF_CACHE_TOKEN */>& token, const ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback>& callback){
    ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus>  _hidl_out = ::android::hardware::neuralnetworks::V1_2::BpHwDevice::_hidl_prepareModelFromCache(this, this, modelCache, dataCache, token, callback);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwDevice::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDevice::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDevice::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDevice::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDevice::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwDevice::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwDevice::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDevice::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDevice::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwDevice::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwDevice::BnHwDevice(const ::android::sp<IDevice> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.neuralnetworks@1.2", "IDevice") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwDevice::~BnHwDevice() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::neuralnetworks::V1_2::IDevice follow.
::android::status_t BnHwDevice::_hidl_getVersionString(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDevice::getVersionString::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "getVersionString", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDevice*>(_hidl_this->getImpl().get())->getVersionString([&](const auto &_hidl_out_status, const auto &_hidl_out_version) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getVersionString: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_version_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_version, sizeof(_hidl_out_version), &_hidl__hidl_out_version_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_version,
                _hidl_reply,
                _hidl__hidl_out_version_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_version);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "getVersionString", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getVersionString: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDevice::_hidl_getType(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDevice::getType::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "getType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDevice*>(_hidl_this->getImpl().get())->getType([&](const auto &_hidl_out_status, const auto &_hidl_out_type) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getType: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_type);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_type);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "getType", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getType: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDevice::_hidl_getCapabilities_1_2(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDevice::getCapabilities_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "getCapabilities_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDevice*>(_hidl_this->getImpl().get())->getCapabilities_1_2([&](const auto &_hidl_out_status, const auto &_hidl_out_capabilities) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getCapabilities_1_2: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_capabilities_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_capabilities, sizeof(_hidl_out_capabilities), &_hidl__hidl_out_capabilities_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_capabilities,
                _hidl_reply,
                _hidl__hidl_out_capabilities_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_capabilities);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "getCapabilities_1_2", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getCapabilities_1_2: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDevice::_hidl_getSupportedExtensions(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDevice::getSupportedExtensions::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "getSupportedExtensions", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDevice*>(_hidl_this->getImpl().get())->getSupportedExtensions([&](const auto &_hidl_out_status, const auto &_hidl_out_extensions) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getSupportedExtensions: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_extensions_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_extensions, sizeof(_hidl_out_extensions), &_hidl__hidl_out_extensions_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_extensions_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_extensions,
                _hidl_reply,
                _hidl__hidl_out_extensions_parent,
                0 /* parentOffset */, &_hidl__hidl_out_extensions_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_extensions.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_extensions[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_extensions_child,
                    _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_2::Extension));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_extensions);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "getSupportedExtensions", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getSupportedExtensions: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDevice::_hidl_getSupportedOperations_1_2(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::neuralnetworks::V1_2::Model* model;

    size_t _hidl_model_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*model), &_hidl_model_parent,  const_cast<const void**>(reinterpret_cast<void **>(&model)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::neuralnetworks::V1_2::Model &>(*model),
            _hidl_data,
            _hidl_model_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDevice::getSupportedOperations_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)model);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "getSupportedOperations_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDevice*>(_hidl_this->getImpl().get())->getSupportedOperations_1_2(*model, [&](const auto &_hidl_out_status, const auto &_hidl_out_supportedOperations) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getSupportedOperations_1_2: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_supportedOperations_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_supportedOperations, sizeof(_hidl_out_supportedOperations), &_hidl__hidl_out_supportedOperations_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_supportedOperations_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_supportedOperations,
                _hidl_reply,
                _hidl__hidl_out_supportedOperations_parent,
                0 /* parentOffset */, &_hidl__hidl_out_supportedOperations_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_supportedOperations);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "getSupportedOperations_1_2", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getSupportedOperations_1_2: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDevice::_hidl_getNumberOfCacheFilesNeeded(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDevice::getNumberOfCacheFilesNeeded::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "getNumberOfCacheFilesNeeded", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDevice*>(_hidl_this->getImpl().get())->getNumberOfCacheFilesNeeded([&](const auto &_hidl_out_status, const auto &_hidl_out_numModelCache, const auto &_hidl_out_numDataCache) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getNumberOfCacheFilesNeeded: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_numModelCache);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_numDataCache);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_numModelCache);
            _hidl_args.push_back((void *)&_hidl_out_numDataCache);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "getNumberOfCacheFilesNeeded", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getNumberOfCacheFilesNeeded: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDevice::_hidl_prepareModel_1_2(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::neuralnetworks::V1_2::Model* model;
    ::android::hardware::neuralnetworks::V1_1::ExecutionPreference preference;
    const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>* modelCache;
    const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>* dataCache;
    const ::android::hardware::hidl_array<uint8_t, 32 /* Constant:BYTE_SIZE_OF_CACHE_TOKEN */>* token;
    ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback> callback;

    size_t _hidl_model_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*model), &_hidl_model_parent,  const_cast<const void**>(reinterpret_cast<void **>(&model)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::neuralnetworks::V1_2::Model &>(*model),
            _hidl_data,
            _hidl_model_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&preference);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_modelCache_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*modelCache), &_hidl_modelCache_parent,  reinterpret_cast<const void **>(&modelCache));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_modelCache_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_handle> &>(*modelCache),
            _hidl_data,
            _hidl_modelCache_parent,
            0 /* parentOffset */, &_hidl_modelCache_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < modelCache->size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_handle &>((*modelCache)[_hidl_index_0]),
                _hidl_data,
                _hidl_modelCache_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_dataCache_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dataCache), &_hidl_dataCache_parent,  reinterpret_cast<const void **>(&dataCache));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dataCache_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_handle> &>(*dataCache),
            _hidl_data,
            _hidl_dataCache_parent,
            0 /* parentOffset */, &_hidl_dataCache_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < dataCache->size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_handle &>((*dataCache)[_hidl_index_0]),
                _hidl_data,
                _hidl_dataCache_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_token_parent;

    _hidl_err = _hidl_data.readBuffer(32 * sizeof(uint8_t), &_hidl_token_parent,  reinterpret_cast<const void **>(&token));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback,::android::hardware::neuralnetworks::V1_2::BpHwPreparedModelCallback,::android::hardware::neuralnetworks::V1_2::BnHwPreparedModelCallback>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDevice::prepareModel_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)model);
        _hidl_args.push_back((void *)&preference);
        _hidl_args.push_back((void *)modelCache);
        _hidl_args.push_back((void *)dataCache);
        _hidl_args.push_back((void *)token);
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "prepareModel_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::neuralnetworks::V1_0::ErrorStatus _hidl_out_status = static_cast<IDevice*>(_hidl_this->getImpl().get())->prepareModel_1_2(*model, preference, *modelCache, *dataCache, *token, callback);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "prepareModel_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDevice::_hidl_prepareModelFromCache(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>* modelCache;
    const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>* dataCache;
    const ::android::hardware::hidl_array<uint8_t, 32 /* Constant:BYTE_SIZE_OF_CACHE_TOKEN */>* token;
    ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback> callback;

    size_t _hidl_modelCache_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*modelCache), &_hidl_modelCache_parent,  reinterpret_cast<const void **>(&modelCache));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_modelCache_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_handle> &>(*modelCache),
            _hidl_data,
            _hidl_modelCache_parent,
            0 /* parentOffset */, &_hidl_modelCache_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < modelCache->size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_handle &>((*modelCache)[_hidl_index_0]),
                _hidl_data,
                _hidl_modelCache_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_dataCache_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dataCache), &_hidl_dataCache_parent,  reinterpret_cast<const void **>(&dataCache));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dataCache_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_handle> &>(*dataCache),
            _hidl_data,
            _hidl_dataCache_parent,
            0 /* parentOffset */, &_hidl_dataCache_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < dataCache->size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_handle &>((*dataCache)[_hidl_index_0]),
                _hidl_data,
                _hidl_dataCache_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_token_parent;

    _hidl_err = _hidl_data.readBuffer(32 * sizeof(uint8_t), &_hidl_token_parent,  reinterpret_cast<const void **>(&token));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback,::android::hardware::neuralnetworks::V1_2::BpHwPreparedModelCallback,::android::hardware::neuralnetworks::V1_2::BnHwPreparedModelCallback>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDevice::prepareModelFromCache::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)modelCache);
        _hidl_args.push_back((void *)dataCache);
        _hidl_args.push_back((void *)token);
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IDevice", "prepareModelFromCache", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::neuralnetworks::V1_0::ErrorStatus _hidl_out_status = static_cast<IDevice*>(_hidl_this->getImpl().get())->prepareModelFromCache(*modelCache, *dataCache, *token, callback);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IDevice", "prepareModelFromCache", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::neuralnetworks::V1_0::IDevice follow.

// Methods from ::android::hardware::neuralnetworks::V1_1::IDevice follow.

// Methods from ::android::hardware::neuralnetworks::V1_2::IDevice follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwDevice::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwDevice::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwDevice::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* getCapabilities */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_0::BnHwDevice::_hidl_getCapabilities(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getSupportedOperations */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_0::BnHwDevice::_hidl_getSupportedOperations(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* prepareModel */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_0::BnHwDevice::_hidl_prepareModel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* getStatus */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_0::BnHwDevice::_hidl_getStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* getCapabilities_1_1 */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_1::BnHwDevice::_hidl_getCapabilities_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* getSupportedOperations_1_1 */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_1::BnHwDevice::_hidl_getSupportedOperations_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* prepareModel_1_1 */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_1::BnHwDevice::_hidl_prepareModel_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* getVersionString */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_2::BnHwDevice::_hidl_getVersionString(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* getType */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_2::BnHwDevice::_hidl_getType(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* getCapabilities_1_2 */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_2::BnHwDevice::_hidl_getCapabilities_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* getSupportedExtensions */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_2::BnHwDevice::_hidl_getSupportedExtensions(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* getSupportedOperations_1_2 */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_2::BnHwDevice::_hidl_getSupportedOperations_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* getNumberOfCacheFilesNeeded */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_2::BnHwDevice::_hidl_getNumberOfCacheFilesNeeded(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* prepareModel_1_2 */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_2::BnHwDevice::_hidl_prepareModel_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* prepareModelFromCache */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_2::BnHwDevice::_hidl_prepareModelFromCache(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsDevice::BsDevice(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IDevice> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.neuralnetworks@1.2", "IDevice"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsDevice::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IDevice> IDevice::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwDevice>(serviceName, false, getStub);
}

::android::sp<IDevice> IDevice::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwDevice>(serviceName, true, getStub);
}

::android::status_t IDevice::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IDevice::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.neuralnetworks@1.2::IDevice",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_2
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android
