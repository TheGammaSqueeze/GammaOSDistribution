#define LOG_TAG "android.hardware.configstore@1.0::SurfaceFlingerConfigs"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/configstore/1.0/BpHwSurfaceFlingerConfigs.h>
#include <android/hardware/configstore/1.0/BnHwSurfaceFlingerConfigs.h>
#include <android/hardware/configstore/1.0/BsSurfaceFlingerConfigs.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace configstore {
namespace V1_0 {

const char* ISurfaceFlingerConfigs::descriptor("android.hardware.configstore@1.0::ISurfaceFlingerConfigs");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ISurfaceFlingerConfigs::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwSurfaceFlingerConfigs(static_cast<ISurfaceFlingerConfigs *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ISurfaceFlingerConfigs::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsSurfaceFlingerConfigs(static_cast<ISurfaceFlingerConfigs *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ISurfaceFlingerConfigs::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ISurfaceFlingerConfigs::descriptor);
}

// Methods from ::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs follow.
// no default implementation for: ::android::hardware::Return<void> ISurfaceFlingerConfigs::vsyncEventPhaseOffsetNs(vsyncEventPhaseOffsetNs_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISurfaceFlingerConfigs::vsyncSfEventPhaseOffsetNs(vsyncSfEventPhaseOffsetNs_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISurfaceFlingerConfigs::useContextPriority(useContextPriority_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISurfaceFlingerConfigs::hasWideColorDisplay(hasWideColorDisplay_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISurfaceFlingerConfigs::hasHDRDisplay(hasHDRDisplay_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISurfaceFlingerConfigs::presentTimeOffsetFromVSyncNs(presentTimeOffsetFromVSyncNs_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISurfaceFlingerConfigs::useHwcForRGBtoYUV(useHwcForRGBtoYUV_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISurfaceFlingerConfigs::maxVirtualDisplaySize(maxVirtualDisplaySize_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISurfaceFlingerConfigs::hasSyncFramework(hasSyncFramework_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISurfaceFlingerConfigs::useVrFlinger(useVrFlinger_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISurfaceFlingerConfigs::maxFrameBufferAcquiredBuffers(maxFrameBufferAcquiredBuffers_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISurfaceFlingerConfigs::startGraphicsAllocatorService(startGraphicsAllocatorService_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ISurfaceFlingerConfigs::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISurfaceFlingerConfigs::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISurfaceFlingerConfigs::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISurfaceFlingerConfigs::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){218,51,35,68,3,255,93,96,243,71,55,17,145,123,153,72,230,72,74,66,96,181,36,122,205,175,177,17,25,58,157,226} /* da33234403ff5d60f3473711917b9948e6484a4260b5247acdafb111193a9de2 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISurfaceFlingerConfigs::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ISurfaceFlingerConfigs::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ISurfaceFlingerConfigs::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISurfaceFlingerConfigs::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ISurfaceFlingerConfigs::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ISurfaceFlingerConfigs::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs>> ISurfaceFlingerConfigs::castFrom(const ::android::sp<::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs>> ISurfaceFlingerConfigs::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ISurfaceFlingerConfigs, ::android::hidl::base::V1_0::IBase, BpHwSurfaceFlingerConfigs>(
            parent, "android.hardware.configstore@1.0::ISurfaceFlingerConfigs", emitError);
}

BpHwSurfaceFlingerConfigs::BpHwSurfaceFlingerConfigs(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ISurfaceFlingerConfigs>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.configstore@1.0", "ISurfaceFlingerConfigs") {
}

void BpHwSurfaceFlingerConfigs::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ISurfaceFlingerConfigs>::onLastStrongRef(id);
}
// Methods from ::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs follow.
::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::_hidl_vsyncEventPhaseOffsetNs(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, vsyncEventPhaseOffsetNs_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::vsyncEventPhaseOffsetNs::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "vsyncEventPhaseOffsetNs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSurfaceFlingerConfigs::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* vsyncEventPhaseOffsetNs */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::configstore::V1_0::OptionalInt64* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_value)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "vsyncEventPhaseOffsetNs", &_hidl_args);
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

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::_hidl_vsyncSfEventPhaseOffsetNs(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, vsyncSfEventPhaseOffsetNs_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::vsyncSfEventPhaseOffsetNs::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "vsyncSfEventPhaseOffsetNs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSurfaceFlingerConfigs::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* vsyncSfEventPhaseOffsetNs */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::configstore::V1_0::OptionalInt64* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_value)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "vsyncSfEventPhaseOffsetNs", &_hidl_args);
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

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::_hidl_useContextPriority(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, useContextPriority_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::useContextPriority::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "useContextPriority", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSurfaceFlingerConfigs::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* useContextPriority */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::configstore::V1_0::OptionalBool* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_value)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "useContextPriority", &_hidl_args);
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

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::_hidl_hasWideColorDisplay(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, hasWideColorDisplay_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::hasWideColorDisplay::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "hasWideColorDisplay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSurfaceFlingerConfigs::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* hasWideColorDisplay */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::configstore::V1_0::OptionalBool* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_value)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "hasWideColorDisplay", &_hidl_args);
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

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::_hidl_hasHDRDisplay(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, hasHDRDisplay_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::hasHDRDisplay::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "hasHDRDisplay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSurfaceFlingerConfigs::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* hasHDRDisplay */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::configstore::V1_0::OptionalBool* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_value)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "hasHDRDisplay", &_hidl_args);
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

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::_hidl_presentTimeOffsetFromVSyncNs(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, presentTimeOffsetFromVSyncNs_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::presentTimeOffsetFromVSyncNs::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "presentTimeOffsetFromVSyncNs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSurfaceFlingerConfigs::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* presentTimeOffsetFromVSyncNs */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::configstore::V1_0::OptionalInt64* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_value)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "presentTimeOffsetFromVSyncNs", &_hidl_args);
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

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::_hidl_useHwcForRGBtoYUV(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, useHwcForRGBtoYUV_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::useHwcForRGBtoYUV::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "useHwcForRGBtoYUV", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSurfaceFlingerConfigs::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* useHwcForRGBtoYUV */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::configstore::V1_0::OptionalBool* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_value)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "useHwcForRGBtoYUV", &_hidl_args);
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

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::_hidl_maxVirtualDisplaySize(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, maxVirtualDisplaySize_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::maxVirtualDisplaySize::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "maxVirtualDisplaySize", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSurfaceFlingerConfigs::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* maxVirtualDisplaySize */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::configstore::V1_0::OptionalUInt64* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_value)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "maxVirtualDisplaySize", &_hidl_args);
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

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::_hidl_hasSyncFramework(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, hasSyncFramework_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::hasSyncFramework::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "hasSyncFramework", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSurfaceFlingerConfigs::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* hasSyncFramework */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::configstore::V1_0::OptionalBool* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_value)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "hasSyncFramework", &_hidl_args);
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

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::_hidl_useVrFlinger(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, useVrFlinger_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::useVrFlinger::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "useVrFlinger", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSurfaceFlingerConfigs::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* useVrFlinger */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::configstore::V1_0::OptionalBool* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_value)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "useVrFlinger", &_hidl_args);
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

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::_hidl_maxFrameBufferAcquiredBuffers(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, maxFrameBufferAcquiredBuffers_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::maxFrameBufferAcquiredBuffers::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "maxFrameBufferAcquiredBuffers", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSurfaceFlingerConfigs::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* maxFrameBufferAcquiredBuffers */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::configstore::V1_0::OptionalInt64* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_value)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "maxFrameBufferAcquiredBuffers", &_hidl_args);
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

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::_hidl_startGraphicsAllocatorService(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, startGraphicsAllocatorService_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::startGraphicsAllocatorService::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "startGraphicsAllocatorService", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSurfaceFlingerConfigs::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* startGraphicsAllocatorService */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::configstore::V1_0::OptionalBool* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_value)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "startGraphicsAllocatorService", &_hidl_args);
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


// Methods from ::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs follow.
::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::vsyncEventPhaseOffsetNs(vsyncEventPhaseOffsetNs_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::configstore::V1_0::BpHwSurfaceFlingerConfigs::_hidl_vsyncEventPhaseOffsetNs(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::vsyncSfEventPhaseOffsetNs(vsyncSfEventPhaseOffsetNs_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::configstore::V1_0::BpHwSurfaceFlingerConfigs::_hidl_vsyncSfEventPhaseOffsetNs(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::useContextPriority(useContextPriority_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::configstore::V1_0::BpHwSurfaceFlingerConfigs::_hidl_useContextPriority(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::hasWideColorDisplay(hasWideColorDisplay_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::configstore::V1_0::BpHwSurfaceFlingerConfigs::_hidl_hasWideColorDisplay(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::hasHDRDisplay(hasHDRDisplay_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::configstore::V1_0::BpHwSurfaceFlingerConfigs::_hidl_hasHDRDisplay(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::presentTimeOffsetFromVSyncNs(presentTimeOffsetFromVSyncNs_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::configstore::V1_0::BpHwSurfaceFlingerConfigs::_hidl_presentTimeOffsetFromVSyncNs(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::useHwcForRGBtoYUV(useHwcForRGBtoYUV_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::configstore::V1_0::BpHwSurfaceFlingerConfigs::_hidl_useHwcForRGBtoYUV(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::maxVirtualDisplaySize(maxVirtualDisplaySize_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::configstore::V1_0::BpHwSurfaceFlingerConfigs::_hidl_maxVirtualDisplaySize(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::hasSyncFramework(hasSyncFramework_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::configstore::V1_0::BpHwSurfaceFlingerConfigs::_hidl_hasSyncFramework(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::useVrFlinger(useVrFlinger_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::configstore::V1_0::BpHwSurfaceFlingerConfigs::_hidl_useVrFlinger(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::maxFrameBufferAcquiredBuffers(maxFrameBufferAcquiredBuffers_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::configstore::V1_0::BpHwSurfaceFlingerConfigs::_hidl_maxFrameBufferAcquiredBuffers(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::startGraphicsAllocatorService(startGraphicsAllocatorService_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::configstore::V1_0::BpHwSurfaceFlingerConfigs::_hidl_startGraphicsAllocatorService(this, this, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwSurfaceFlingerConfigs::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSurfaceFlingerConfigs::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwSurfaceFlingerConfigs::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwSurfaceFlingerConfigs::BnHwSurfaceFlingerConfigs(const ::android::sp<ISurfaceFlingerConfigs> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.configstore@1.0", "ISurfaceFlingerConfigs") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwSurfaceFlingerConfigs::~BnHwSurfaceFlingerConfigs() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs follow.
::android::status_t BnHwSurfaceFlingerConfigs::_hidl_vsyncEventPhaseOffsetNs(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSurfaceFlingerConfigs::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::vsyncEventPhaseOffsetNs::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "vsyncEventPhaseOffsetNs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISurfaceFlingerConfigs*>(_hidl_this->getImpl().get())->vsyncEventPhaseOffsetNs([&](const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("vsyncEventPhaseOffsetNs: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "vsyncEventPhaseOffsetNs", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("vsyncEventPhaseOffsetNs: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSurfaceFlingerConfigs::_hidl_vsyncSfEventPhaseOffsetNs(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSurfaceFlingerConfigs::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::vsyncSfEventPhaseOffsetNs::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "vsyncSfEventPhaseOffsetNs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISurfaceFlingerConfigs*>(_hidl_this->getImpl().get())->vsyncSfEventPhaseOffsetNs([&](const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("vsyncSfEventPhaseOffsetNs: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "vsyncSfEventPhaseOffsetNs", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("vsyncSfEventPhaseOffsetNs: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSurfaceFlingerConfigs::_hidl_useContextPriority(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSurfaceFlingerConfigs::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::useContextPriority::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "useContextPriority", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISurfaceFlingerConfigs*>(_hidl_this->getImpl().get())->useContextPriority([&](const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("useContextPriority: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "useContextPriority", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("useContextPriority: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSurfaceFlingerConfigs::_hidl_hasWideColorDisplay(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSurfaceFlingerConfigs::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::hasWideColorDisplay::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "hasWideColorDisplay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISurfaceFlingerConfigs*>(_hidl_this->getImpl().get())->hasWideColorDisplay([&](const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("hasWideColorDisplay: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "hasWideColorDisplay", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("hasWideColorDisplay: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSurfaceFlingerConfigs::_hidl_hasHDRDisplay(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSurfaceFlingerConfigs::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::hasHDRDisplay::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "hasHDRDisplay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISurfaceFlingerConfigs*>(_hidl_this->getImpl().get())->hasHDRDisplay([&](const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("hasHDRDisplay: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "hasHDRDisplay", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("hasHDRDisplay: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSurfaceFlingerConfigs::_hidl_presentTimeOffsetFromVSyncNs(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSurfaceFlingerConfigs::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::presentTimeOffsetFromVSyncNs::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "presentTimeOffsetFromVSyncNs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISurfaceFlingerConfigs*>(_hidl_this->getImpl().get())->presentTimeOffsetFromVSyncNs([&](const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("presentTimeOffsetFromVSyncNs: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "presentTimeOffsetFromVSyncNs", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("presentTimeOffsetFromVSyncNs: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSurfaceFlingerConfigs::_hidl_useHwcForRGBtoYUV(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSurfaceFlingerConfigs::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::useHwcForRGBtoYUV::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "useHwcForRGBtoYUV", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISurfaceFlingerConfigs*>(_hidl_this->getImpl().get())->useHwcForRGBtoYUV([&](const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("useHwcForRGBtoYUV: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "useHwcForRGBtoYUV", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("useHwcForRGBtoYUV: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSurfaceFlingerConfigs::_hidl_maxVirtualDisplaySize(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSurfaceFlingerConfigs::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::maxVirtualDisplaySize::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "maxVirtualDisplaySize", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISurfaceFlingerConfigs*>(_hidl_this->getImpl().get())->maxVirtualDisplaySize([&](const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("maxVirtualDisplaySize: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "maxVirtualDisplaySize", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("maxVirtualDisplaySize: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSurfaceFlingerConfigs::_hidl_hasSyncFramework(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSurfaceFlingerConfigs::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::hasSyncFramework::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "hasSyncFramework", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISurfaceFlingerConfigs*>(_hidl_this->getImpl().get())->hasSyncFramework([&](const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("hasSyncFramework: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "hasSyncFramework", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("hasSyncFramework: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSurfaceFlingerConfigs::_hidl_useVrFlinger(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSurfaceFlingerConfigs::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::useVrFlinger::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "useVrFlinger", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISurfaceFlingerConfigs*>(_hidl_this->getImpl().get())->useVrFlinger([&](const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("useVrFlinger: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "useVrFlinger", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("useVrFlinger: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSurfaceFlingerConfigs::_hidl_maxFrameBufferAcquiredBuffers(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSurfaceFlingerConfigs::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::maxFrameBufferAcquiredBuffers::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "maxFrameBufferAcquiredBuffers", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISurfaceFlingerConfigs*>(_hidl_this->getImpl().get())->maxFrameBufferAcquiredBuffers([&](const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("maxFrameBufferAcquiredBuffers: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "maxFrameBufferAcquiredBuffers", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("maxFrameBufferAcquiredBuffers: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSurfaceFlingerConfigs::_hidl_startGraphicsAllocatorService(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSurfaceFlingerConfigs::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISurfaceFlingerConfigs::startGraphicsAllocatorService::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "startGraphicsAllocatorService", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISurfaceFlingerConfigs*>(_hidl_this->getImpl().get())->startGraphicsAllocatorService([&](const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("startGraphicsAllocatorService: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.configstore", "1.0", "ISurfaceFlingerConfigs", "startGraphicsAllocatorService", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("startGraphicsAllocatorService: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwSurfaceFlingerConfigs::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwSurfaceFlingerConfigs::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwSurfaceFlingerConfigs::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* vsyncEventPhaseOffsetNs */:
        {
            _hidl_err = ::android::hardware::configstore::V1_0::BnHwSurfaceFlingerConfigs::_hidl_vsyncEventPhaseOffsetNs(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* vsyncSfEventPhaseOffsetNs */:
        {
            _hidl_err = ::android::hardware::configstore::V1_0::BnHwSurfaceFlingerConfigs::_hidl_vsyncSfEventPhaseOffsetNs(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* useContextPriority */:
        {
            _hidl_err = ::android::hardware::configstore::V1_0::BnHwSurfaceFlingerConfigs::_hidl_useContextPriority(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* hasWideColorDisplay */:
        {
            _hidl_err = ::android::hardware::configstore::V1_0::BnHwSurfaceFlingerConfigs::_hidl_hasWideColorDisplay(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* hasHDRDisplay */:
        {
            _hidl_err = ::android::hardware::configstore::V1_0::BnHwSurfaceFlingerConfigs::_hidl_hasHDRDisplay(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* presentTimeOffsetFromVSyncNs */:
        {
            _hidl_err = ::android::hardware::configstore::V1_0::BnHwSurfaceFlingerConfigs::_hidl_presentTimeOffsetFromVSyncNs(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* useHwcForRGBtoYUV */:
        {
            _hidl_err = ::android::hardware::configstore::V1_0::BnHwSurfaceFlingerConfigs::_hidl_useHwcForRGBtoYUV(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* maxVirtualDisplaySize */:
        {
            _hidl_err = ::android::hardware::configstore::V1_0::BnHwSurfaceFlingerConfigs::_hidl_maxVirtualDisplaySize(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* hasSyncFramework */:
        {
            _hidl_err = ::android::hardware::configstore::V1_0::BnHwSurfaceFlingerConfigs::_hidl_hasSyncFramework(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* useVrFlinger */:
        {
            _hidl_err = ::android::hardware::configstore::V1_0::BnHwSurfaceFlingerConfigs::_hidl_useVrFlinger(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* maxFrameBufferAcquiredBuffers */:
        {
            _hidl_err = ::android::hardware::configstore::V1_0::BnHwSurfaceFlingerConfigs::_hidl_maxFrameBufferAcquiredBuffers(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* startGraphicsAllocatorService */:
        {
            _hidl_err = ::android::hardware::configstore::V1_0::BnHwSurfaceFlingerConfigs::_hidl_startGraphicsAllocatorService(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsSurfaceFlingerConfigs::BsSurfaceFlingerConfigs(const ::android::sp<::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.configstore@1.0", "ISurfaceFlingerConfigs"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsSurfaceFlingerConfigs::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ISurfaceFlingerConfigs> ISurfaceFlingerConfigs::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwSurfaceFlingerConfigs>(serviceName, false, getStub);
}

::android::sp<ISurfaceFlingerConfigs> ISurfaceFlingerConfigs::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwSurfaceFlingerConfigs>(serviceName, true, getStub);
}

::android::status_t ISurfaceFlingerConfigs::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ISurfaceFlingerConfigs::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.configstore@1.0::ISurfaceFlingerConfigs",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace configstore
}  // namespace hardware
}  // namespace android
