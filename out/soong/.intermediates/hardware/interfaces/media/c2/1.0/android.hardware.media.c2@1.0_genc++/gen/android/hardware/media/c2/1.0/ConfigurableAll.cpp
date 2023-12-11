#define LOG_TAG "android.hardware.media.c2@1.0::Configurable"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/media/c2/1.0/BpHwConfigurable.h>
#include <android/hardware/media/c2/1.0/BnHwConfigurable.h>
#include <android/hardware/media/c2/1.0/BsConfigurable.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace media {
namespace c2 {
namespace V1_0 {

const char* IConfigurable::descriptor("android.hardware.media.c2@1.0::IConfigurable");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IConfigurable::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwConfigurable(static_cast<IConfigurable *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IConfigurable::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsConfigurable(static_cast<IConfigurable *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IConfigurable::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IConfigurable::descriptor);
}

// Methods from ::android::hardware::media::c2::V1_0::IConfigurable follow.
// no default implementation for: ::android::hardware::Return<uint32_t> IConfigurable::getId()
// no default implementation for: ::android::hardware::Return<void> IConfigurable::getName(getName_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IConfigurable::query(const ::android::hardware::hidl_vec<uint32_t>& indices, bool mayBlock, query_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IConfigurable::config(const ::android::hardware::hidl_vec<uint8_t>& inParams, bool mayBlock, config_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IConfigurable::querySupportedParams(uint32_t start, uint32_t count, querySupportedParams_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IConfigurable::querySupportedValues(const ::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::FieldSupportedValuesQuery>& inFields, bool mayBlock, querySupportedValues_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IConfigurable::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::media::c2::V1_0::IConfigurable::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfigurable::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfigurable::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::media::c2::V1_0::IConfigurable::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfigurable::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){211,111,116,127,156,154,143,47,33,219,47,131,35,194,215,85,221,8,179,76,232,19,147,45,115,57,151,159,125,73,13,171} /* d36f747f9c9a8f2f21db2f8323c2d755dd08b34ce813932d7339979f7d490dab */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfigurable::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IConfigurable::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IConfigurable::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfigurable::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IConfigurable::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IConfigurable::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::media::c2::V1_0::IConfigurable>> IConfigurable::castFrom(const ::android::sp<::android::hardware::media::c2::V1_0::IConfigurable>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::media::c2::V1_0::IConfigurable>> IConfigurable::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IConfigurable, ::android::hidl::base::V1_0::IBase, BpHwConfigurable>(
            parent, "android.hardware.media.c2@1.0::IConfigurable", emitError);
}

BpHwConfigurable::BpHwConfigurable(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IConfigurable>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.media.c2@1.0", "IConfigurable") {
}

void BpHwConfigurable::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IConfigurable>::onLastStrongRef(id);
}
// Methods from ::android::hardware::media::c2::V1_0::IConfigurable follow.
::android::hardware::Return<uint32_t> BpHwConfigurable::_hidl_getId(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IConfigurable::getId::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.c2", "1.0", "IConfigurable", "getId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint32_t _hidl_out_id;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwConfigurable::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* getId */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32(&_hidl_out_id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_id);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.c2", "1.0", "IConfigurable", "getId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint32_t>(_hidl_out_id);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint32_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwConfigurable::_hidl_getName(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getName_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IConfigurable::getName::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.c2", "1.0", "IConfigurable", "getName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwConfigurable::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* getName */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::hidl_string* _hidl_out_name;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_name_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_name), &_hidl__hidl_out_name_parent,  reinterpret_cast<const void **>(&_hidl_out_name));

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(*_hidl_out_name),
                _hidl_reply,
                _hidl__hidl_out_name_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_name);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_name);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.c2", "1.0", "IConfigurable", "getName", &_hidl_args);
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

::android::hardware::Return<void> BpHwConfigurable::_hidl_query(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint32_t>& indices, bool mayBlock, query_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IConfigurable::query::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&indices);
        _hidl_args.push_back((void *)&mayBlock);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.c2", "1.0", "IConfigurable", "query", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwConfigurable::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_indices_parent;

    _hidl_err = _hidl_data.writeBuffer(&indices, sizeof(indices), &_hidl_indices_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_indices_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            indices,
            &_hidl_data,
            _hidl_indices_parent,
            0 /* parentOffset */, &_hidl_indices_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(mayBlock);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* query */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::media::c2::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_params;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_params_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_params), &_hidl__hidl_out_params_parent,  reinterpret_cast<const void **>(&_hidl_out_params));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_params_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_params),
                _hidl_reply,
                _hidl__hidl_out_params_parent,
                0 /* parentOffset */, &_hidl__hidl_out_params_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_params);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_params);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.c2", "1.0", "IConfigurable", "query", &_hidl_args);
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

::android::hardware::Return<void> BpHwConfigurable::_hidl_config(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& inParams, bool mayBlock, config_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IConfigurable::config::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&inParams);
        _hidl_args.push_back((void *)&mayBlock);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.c2", "1.0", "IConfigurable", "config", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwConfigurable::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inParams_parent;

    _hidl_err = _hidl_data.writeBuffer(&inParams, sizeof(inParams), &_hidl_inParams_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inParams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            inParams,
            &_hidl_data,
            _hidl_inParams_parent,
            0 /* parentOffset */, &_hidl_inParams_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(mayBlock);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* config */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::media::c2::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::SettingResult>* _hidl_out_failures;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_outParams;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_failures_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_failures), &_hidl__hidl_out_failures_parent,  reinterpret_cast<const void **>(&_hidl_out_failures));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_failures_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::SettingResult> &>(*_hidl_out_failures),
                _hidl_reply,
                _hidl__hidl_out_failures_parent,
                0 /* parentOffset */, &_hidl__hidl_out_failures_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_failures->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::media::c2::V1_0::SettingResult &>((*_hidl_out_failures)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_failures_child,
                    _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::SettingResult));

            if (_hidl_err != ::android::OK) { return; }

        }

        size_t _hidl__hidl_out_outParams_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_outParams), &_hidl__hidl_out_outParams_parent,  reinterpret_cast<const void **>(&_hidl_out_outParams));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_outParams_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_outParams),
                _hidl_reply,
                _hidl__hidl_out_outParams_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outParams_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_failures, *_hidl_out_outParams);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_failures);
            _hidl_args.push_back((void *)_hidl_out_outParams);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.c2", "1.0", "IConfigurable", "config", &_hidl_args);
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

::android::hardware::Return<void> BpHwConfigurable::_hidl_querySupportedParams(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t start, uint32_t count, querySupportedParams_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IConfigurable::querySupportedParams::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&start);
        _hidl_args.push_back((void *)&count);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.c2", "1.0", "IConfigurable", "querySupportedParams", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwConfigurable::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(start);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(count);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* querySupportedParams */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::media::c2::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::ParamDescriptor>* _hidl_out_params;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_params_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_params), &_hidl__hidl_out_params_parent,  reinterpret_cast<const void **>(&_hidl_out_params));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_params_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::ParamDescriptor> &>(*_hidl_out_params),
                _hidl_reply,
                _hidl__hidl_out_params_parent,
                0 /* parentOffset */, &_hidl__hidl_out_params_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_params->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::media::c2::V1_0::ParamDescriptor &>((*_hidl_out_params)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_params_child,
                    _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::ParamDescriptor));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_cb(_hidl_out_status, *_hidl_out_params);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_params);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.c2", "1.0", "IConfigurable", "querySupportedParams", &_hidl_args);
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

::android::hardware::Return<void> BpHwConfigurable::_hidl_querySupportedValues(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::FieldSupportedValuesQuery>& inFields, bool mayBlock, querySupportedValues_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IConfigurable::querySupportedValues::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&inFields);
        _hidl_args.push_back((void *)&mayBlock);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.c2", "1.0", "IConfigurable", "querySupportedValues", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwConfigurable::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inFields_parent;

    _hidl_err = _hidl_data.writeBuffer(&inFields, sizeof(inFields), &_hidl_inFields_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inFields_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            inFields,
            &_hidl_data,
            _hidl_inFields_parent,
            0 /* parentOffset */, &_hidl_inFields_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(mayBlock);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* querySupportedValues */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::media::c2::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::FieldSupportedValuesQueryResult>* _hidl_out_outFields;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_outFields_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_outFields), &_hidl__hidl_out_outFields_parent,  reinterpret_cast<const void **>(&_hidl_out_outFields));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_outFields_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::FieldSupportedValuesQueryResult> &>(*_hidl_out_outFields),
                _hidl_reply,
                _hidl__hidl_out_outFields_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outFields_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_outFields->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::media::c2::V1_0::FieldSupportedValuesQueryResult &>((*_hidl_out_outFields)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_outFields_child,
                    _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::FieldSupportedValuesQueryResult));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_cb(_hidl_out_status, *_hidl_out_outFields);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_outFields);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.c2", "1.0", "IConfigurable", "querySupportedValues", &_hidl_args);
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


// Methods from ::android::hardware::media::c2::V1_0::IConfigurable follow.
::android::hardware::Return<uint32_t> BpHwConfigurable::getId(){
    ::android::hardware::Return<uint32_t>  _hidl_out = ::android::hardware::media::c2::V1_0::BpHwConfigurable::_hidl_getId(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfigurable::getName(getName_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::c2::V1_0::BpHwConfigurable::_hidl_getName(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfigurable::query(const ::android::hardware::hidl_vec<uint32_t>& indices, bool mayBlock, query_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::c2::V1_0::BpHwConfigurable::_hidl_query(this, this, indices, mayBlock, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfigurable::config(const ::android::hardware::hidl_vec<uint8_t>& inParams, bool mayBlock, config_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::c2::V1_0::BpHwConfigurable::_hidl_config(this, this, inParams, mayBlock, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfigurable::querySupportedParams(uint32_t start, uint32_t count, querySupportedParams_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::c2::V1_0::BpHwConfigurable::_hidl_querySupportedParams(this, this, start, count, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfigurable::querySupportedValues(const ::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::FieldSupportedValuesQuery>& inFields, bool mayBlock, querySupportedValues_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::c2::V1_0::BpHwConfigurable::_hidl_querySupportedValues(this, this, inFields, mayBlock, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwConfigurable::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfigurable::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfigurable::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfigurable::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfigurable::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwConfigurable::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwConfigurable::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfigurable::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfigurable::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwConfigurable::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwConfigurable::BnHwConfigurable(const ::android::sp<IConfigurable> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.media.c2@1.0", "IConfigurable") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwConfigurable::~BnHwConfigurable() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::media::c2::V1_0::IConfigurable follow.
::android::status_t BnHwConfigurable::_hidl_getId(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwConfigurable::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IConfigurable::getId::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.c2", "1.0", "IConfigurable", "getId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint32_t _hidl_out_id = static_cast<IConfigurable*>(_hidl_this->getImpl().get())->getId();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32(_hidl_out_id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_id);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.c2", "1.0", "IConfigurable", "getId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwConfigurable::_hidl_getName(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwConfigurable::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IConfigurable::getName::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.c2", "1.0", "IConfigurable", "getName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IConfigurable*>(_hidl_this->getImpl().get())->getName([&](const auto &_hidl_out_name) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getName: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_name_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_name, sizeof(_hidl_out_name), &_hidl__hidl_out_name_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_name,
                _hidl_reply,
                _hidl__hidl_out_name_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_name);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.c2", "1.0", "IConfigurable", "getName", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getName: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwConfigurable::_hidl_query(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwConfigurable::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint32_t>* indices;
    bool mayBlock;

    size_t _hidl_indices_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*indices), &_hidl_indices_parent,  reinterpret_cast<const void **>(&indices));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_indices_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(*indices),
            _hidl_data,
            _hidl_indices_parent,
            0 /* parentOffset */, &_hidl_indices_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&mayBlock);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IConfigurable::query::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)indices);
        _hidl_args.push_back((void *)&mayBlock);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.c2", "1.0", "IConfigurable", "query", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IConfigurable*>(_hidl_this->getImpl().get())->query(*indices, mayBlock, [&](const auto &_hidl_out_status, const auto &_hidl_out_params) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("query: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_params_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_params, sizeof(_hidl_out_params), &_hidl__hidl_out_params_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_params_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_params,
                _hidl_reply,
                _hidl__hidl_out_params_parent,
                0 /* parentOffset */, &_hidl__hidl_out_params_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_params);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.c2", "1.0", "IConfigurable", "query", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("query: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwConfigurable::_hidl_config(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwConfigurable::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* inParams;
    bool mayBlock;

    size_t _hidl_inParams_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*inParams), &_hidl_inParams_parent,  reinterpret_cast<const void **>(&inParams));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_inParams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*inParams),
            _hidl_data,
            _hidl_inParams_parent,
            0 /* parentOffset */, &_hidl_inParams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&mayBlock);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IConfigurable::config::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)inParams);
        _hidl_args.push_back((void *)&mayBlock);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.c2", "1.0", "IConfigurable", "config", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IConfigurable*>(_hidl_this->getImpl().get())->config(*inParams, mayBlock, [&](const auto &_hidl_out_status, const auto &_hidl_out_failures, const auto &_hidl_out_outParams) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("config: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_failures_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_failures, sizeof(_hidl_out_failures), &_hidl__hidl_out_failures_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_failures_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_failures,
                _hidl_reply,
                _hidl__hidl_out_failures_parent,
                0 /* parentOffset */, &_hidl__hidl_out_failures_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_failures.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_failures[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_failures_child,
                    _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::SettingResult));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

        size_t _hidl__hidl_out_outParams_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_outParams, sizeof(_hidl_out_outParams), &_hidl__hidl_out_outParams_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_outParams_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_outParams,
                _hidl_reply,
                _hidl__hidl_out_outParams_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outParams_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_failures);
            _hidl_args.push_back((void *)&_hidl_out_outParams);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.c2", "1.0", "IConfigurable", "config", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("config: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwConfigurable::_hidl_querySupportedParams(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwConfigurable::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t start;
    uint32_t count;

    _hidl_err = _hidl_data.readUint32(&start);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&count);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IConfigurable::querySupportedParams::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&start);
        _hidl_args.push_back((void *)&count);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.c2", "1.0", "IConfigurable", "querySupportedParams", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IConfigurable*>(_hidl_this->getImpl().get())->querySupportedParams(start, count, [&](const auto &_hidl_out_status, const auto &_hidl_out_params) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("querySupportedParams: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_params_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_params, sizeof(_hidl_out_params), &_hidl__hidl_out_params_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_params_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_params,
                _hidl_reply,
                _hidl__hidl_out_params_parent,
                0 /* parentOffset */, &_hidl__hidl_out_params_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_params.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_params[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_params_child,
                    _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::ParamDescriptor));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_params);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.c2", "1.0", "IConfigurable", "querySupportedParams", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("querySupportedParams: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwConfigurable::_hidl_querySupportedValues(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwConfigurable::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::FieldSupportedValuesQuery>* inFields;
    bool mayBlock;

    size_t _hidl_inFields_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*inFields), &_hidl_inFields_parent,  reinterpret_cast<const void **>(&inFields));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_inFields_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::FieldSupportedValuesQuery> &>(*inFields),
            _hidl_data,
            _hidl_inFields_parent,
            0 /* parentOffset */, &_hidl_inFields_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&mayBlock);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IConfigurable::querySupportedValues::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)inFields);
        _hidl_args.push_back((void *)&mayBlock);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.c2", "1.0", "IConfigurable", "querySupportedValues", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IConfigurable*>(_hidl_this->getImpl().get())->querySupportedValues(*inFields, mayBlock, [&](const auto &_hidl_out_status, const auto &_hidl_out_outFields) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("querySupportedValues: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_outFields_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_outFields, sizeof(_hidl_out_outFields), &_hidl__hidl_out_outFields_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_outFields_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_outFields,
                _hidl_reply,
                _hidl__hidl_out_outFields_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outFields_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_outFields.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_outFields[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_outFields_child,
                    _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::FieldSupportedValuesQueryResult));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_outFields);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.c2", "1.0", "IConfigurable", "querySupportedValues", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("querySupportedValues: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::media::c2::V1_0::IConfigurable follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwConfigurable::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwConfigurable::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwConfigurable::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* getId */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_0::BnHwConfigurable::_hidl_getId(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getName */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_0::BnHwConfigurable::_hidl_getName(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* query */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_0::BnHwConfigurable::_hidl_query(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* config */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_0::BnHwConfigurable::_hidl_config(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* querySupportedParams */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_0::BnHwConfigurable::_hidl_querySupportedParams(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* querySupportedValues */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_0::BnHwConfigurable::_hidl_querySupportedValues(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsConfigurable::BsConfigurable(const ::android::sp<::android::hardware::media::c2::V1_0::IConfigurable> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.media.c2@1.0", "IConfigurable"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsConfigurable::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IConfigurable> IConfigurable::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwConfigurable>(serviceName, false, getStub);
}

::android::sp<IConfigurable> IConfigurable::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwConfigurable>(serviceName, true, getStub);
}

::android::status_t IConfigurable::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IConfigurable::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.media.c2@1.0::IConfigurable",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace c2
}  // namespace media
}  // namespace hardware
}  // namespace android
