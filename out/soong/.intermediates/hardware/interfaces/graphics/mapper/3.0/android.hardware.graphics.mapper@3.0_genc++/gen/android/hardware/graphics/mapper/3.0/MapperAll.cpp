#define LOG_TAG "android.hardware.graphics.mapper@3.0::Mapper"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/graphics/mapper/3.0/BpHwMapper.h>
#include <android/hardware/graphics/mapper/3.0/BnHwMapper.h>
#include <android/hardware/graphics/mapper/3.0/BsMapper.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace graphics {
namespace mapper {
namespace V3_0 {

const char* IMapper::descriptor("android.hardware.graphics.mapper@3.0::IMapper");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IMapper::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwMapper(static_cast<IMapper *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IMapper::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsMapper(static_cast<IMapper *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IMapper::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IMapper::descriptor);
}

// Methods from ::android::hardware::graphics::mapper::V3_0::IMapper follow.
// no default implementation for: ::android::hardware::Return<void> IMapper::createDescriptor(const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, createDescriptor_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IMapper::importBuffer(const ::android::hardware::hidl_handle& rawHandle, importBuffer_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error> IMapper::freeBuffer(void* buffer)
// no default implementation for: ::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error> IMapper::validateBufferSize(void* buffer, const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, uint32_t stride)
// no default implementation for: ::android::hardware::Return<void> IMapper::getTransportSize(void* buffer, getTransportSize_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IMapper::lock(void* buffer, uint64_t cpuUsage, const ::android::hardware::graphics::mapper::V3_0::IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lock_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IMapper::lockYCbCr(void* buffer, uint64_t cpuUsage, const ::android::hardware::graphics::mapper::V3_0::IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lockYCbCr_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IMapper::unlock(void* buffer, unlock_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IMapper::isSupported(const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, isSupported_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IMapper::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::graphics::mapper::V3_0::IMapper::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IMapper::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IMapper::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::graphics::mapper::V3_0::IMapper::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IMapper::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){3,62,9,108,182,94,80,147,238,29,14,71,56,146,185,164,135,145,29,70,17,219,182,94,190,203,92,239,24,51,137,35} /* 033e096cb65e5093ee1d0e473892b9a487911d4611dbb65ebecb5cef18338923 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IMapper::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IMapper::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IMapper::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IMapper::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IMapper::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IMapper::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::graphics::mapper::V3_0::IMapper>> IMapper::castFrom(const ::android::sp<::android::hardware::graphics::mapper::V3_0::IMapper>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::graphics::mapper::V3_0::IMapper>> IMapper::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IMapper, ::android::hidl::base::V1_0::IBase, BpHwMapper>(
            parent, "android.hardware.graphics.mapper@3.0::IMapper", emitError);
}

BpHwMapper::BpHwMapper(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IMapper>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.graphics.mapper@3.0", "IMapper") {
}

void BpHwMapper::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IMapper>::onLastStrongRef(id);
}
// Methods from ::android::hardware::graphics::mapper::V3_0::IMapper follow.
::android::hardware::Return<void> BpHwMapper::_hidl_createDescriptor(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, createDescriptor_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IMapper::createDescriptor::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&description);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "createDescriptor", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwMapper::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_description_parent;

    _hidl_err = _hidl_data.writeBuffer(&description, sizeof(description), &_hidl_description_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* createDescriptor */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::graphics::mapper::V3_0::Error _hidl_out_error;
        const ::android::hardware::hidl_vec<uint32_t>* _hidl_out_descriptor;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_descriptor_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_descriptor), &_hidl__hidl_out_descriptor_parent,  reinterpret_cast<const void **>(&_hidl_out_descriptor));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_descriptor_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint32_t> &>(*_hidl_out_descriptor),
                _hidl_reply,
                _hidl__hidl_out_descriptor_parent,
                0 /* parentOffset */, &_hidl__hidl_out_descriptor_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, *_hidl_out_descriptor);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)_hidl_out_descriptor);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "createDescriptor", &_hidl_args);
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

::android::hardware::Return<void> BpHwMapper::_hidl_importBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_handle& rawHandle, importBuffer_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IMapper::importBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&rawHandle);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "importBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwMapper::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeNativeHandleNoDup(rawHandle);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* importBuffer */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::graphics::mapper::V3_0::Error _hidl_out_error;
        void* _hidl_out_buffer;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        (void)_hidl_out_buffer;
        LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, _hidl_out_buffer);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_buffer);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "importBuffer", &_hidl_args);
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

::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error> BpHwMapper::_hidl_freeBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IMapper::freeBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "freeBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::graphics::mapper::V3_0::Error _hidl_out_error;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwMapper::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)buffer;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* freeBuffer */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "freeBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error>(_hidl_status);
}

::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error> BpHwMapper::_hidl_validateBufferSize(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer, const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, uint32_t stride) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IMapper::validateBufferSize::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        _hidl_args.push_back((void *)&description);
        _hidl_args.push_back((void *)&stride);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "validateBufferSize", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::graphics::mapper::V3_0::Error _hidl_out_error;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwMapper::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)buffer;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_description_parent;

    _hidl_err = _hidl_data.writeBuffer(&description, sizeof(description), &_hidl_description_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(stride);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* validateBufferSize */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "validateBufferSize", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error>(_hidl_status);
}

::android::hardware::Return<void> BpHwMapper::_hidl_getTransportSize(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer, getTransportSize_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IMapper::getTransportSize::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "getTransportSize", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwMapper::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)buffer;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* getTransportSize */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::graphics::mapper::V3_0::Error _hidl_out_error;
        uint32_t _hidl_out_numFds;
        uint32_t _hidl_out_numInts;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_numFds);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_numInts);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, _hidl_out_numFds, _hidl_out_numInts);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_numFds);
            _hidl_args.push_back((void *)&_hidl_out_numInts);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "getTransportSize", &_hidl_args);
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

::android::hardware::Return<void> BpHwMapper::_hidl_lock(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer, uint64_t cpuUsage, const ::android::hardware::graphics::mapper::V3_0::IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lock_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IMapper::lock::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        _hidl_args.push_back((void *)&cpuUsage);
        _hidl_args.push_back((void *)&accessRegion);
        _hidl_args.push_back((void *)&acquireFence);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "lock", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwMapper::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)buffer;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(cpuUsage);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_accessRegion_parent;

    _hidl_err = _hidl_data.writeBuffer(&accessRegion, sizeof(accessRegion), &_hidl_accessRegion_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeNativeHandleNoDup(acquireFence);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* lock */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::graphics::mapper::V3_0::Error _hidl_out_error;
        void* _hidl_out_data;
        int32_t _hidl_out_bytesPerPixel;
        int32_t _hidl_out_bytesPerStride;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        (void)_hidl_out_data;
        LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_bytesPerPixel);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_bytesPerStride);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, _hidl_out_data, _hidl_out_bytesPerPixel, _hidl_out_bytesPerStride);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_data);
            _hidl_args.push_back((void *)&_hidl_out_bytesPerPixel);
            _hidl_args.push_back((void *)&_hidl_out_bytesPerStride);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "lock", &_hidl_args);
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

::android::hardware::Return<void> BpHwMapper::_hidl_lockYCbCr(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer, uint64_t cpuUsage, const ::android::hardware::graphics::mapper::V3_0::IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lockYCbCr_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IMapper::lockYCbCr::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        _hidl_args.push_back((void *)&cpuUsage);
        _hidl_args.push_back((void *)&accessRegion);
        _hidl_args.push_back((void *)&acquireFence);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "lockYCbCr", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwMapper::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)buffer;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(cpuUsage);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_accessRegion_parent;

    _hidl_err = _hidl_data.writeBuffer(&accessRegion, sizeof(accessRegion), &_hidl_accessRegion_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeNativeHandleNoDup(acquireFence);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* lockYCbCr */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::graphics::mapper::V3_0::Error _hidl_out_error;
        ::android::hardware::graphics::mapper::V3_0::YCbCrLayout* _hidl_out_layout;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_layout_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_layout), &_hidl__hidl_out_layout_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_layout)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::graphics::mapper::V3_0::YCbCrLayout &>(*_hidl_out_layout),
                _hidl_reply,
                _hidl__hidl_out_layout_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, *_hidl_out_layout);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)_hidl_out_layout);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "lockYCbCr", &_hidl_args);
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

::android::hardware::Return<void> BpHwMapper::_hidl_unlock(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer, unlock_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IMapper::unlock::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "unlock", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwMapper::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)buffer;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* unlock */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::graphics::mapper::V3_0::Error _hidl_out_error;
        ::android::hardware::hidl_handle _hidl_out_releaseFence;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        const native_handle_t *_hidl_out_releaseFence_ptr;

        _hidl_err = _hidl_reply.readNullableNativeHandleNoDup(&_hidl_out_releaseFence_ptr);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_out_releaseFence = _hidl_out_releaseFence_ptr;
        _hidl_cb(_hidl_out_error, _hidl_out_releaseFence);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_releaseFence);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "unlock", &_hidl_args);
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

::android::hardware::Return<void> BpHwMapper::_hidl_isSupported(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, isSupported_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IMapper::isSupported::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&description);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "isSupported", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwMapper::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_description_parent;

    _hidl_err = _hidl_data.writeBuffer(&description, sizeof(description), &_hidl_description_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* isSupported */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::graphics::mapper::V3_0::Error _hidl_out_error;
        bool _hidl_out_supported;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readBool(&_hidl_out_supported);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, _hidl_out_supported);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_supported);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "isSupported", &_hidl_args);
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


// Methods from ::android::hardware::graphics::mapper::V3_0::IMapper follow.
::android::hardware::Return<void> BpHwMapper::createDescriptor(const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, createDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::mapper::V3_0::BpHwMapper::_hidl_createDescriptor(this, this, description, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::importBuffer(const ::android::hardware::hidl_handle& rawHandle, importBuffer_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::mapper::V3_0::BpHwMapper::_hidl_importBuffer(this, this, rawHandle, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error> BpHwMapper::freeBuffer(void* buffer){
    ::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error>  _hidl_out = ::android::hardware::graphics::mapper::V3_0::BpHwMapper::_hidl_freeBuffer(this, this, buffer);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error> BpHwMapper::validateBufferSize(void* buffer, const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, uint32_t stride){
    ::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error>  _hidl_out = ::android::hardware::graphics::mapper::V3_0::BpHwMapper::_hidl_validateBufferSize(this, this, buffer, description, stride);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::getTransportSize(void* buffer, getTransportSize_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::mapper::V3_0::BpHwMapper::_hidl_getTransportSize(this, this, buffer, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::lock(void* buffer, uint64_t cpuUsage, const ::android::hardware::graphics::mapper::V3_0::IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lock_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::mapper::V3_0::BpHwMapper::_hidl_lock(this, this, buffer, cpuUsage, accessRegion, acquireFence, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::lockYCbCr(void* buffer, uint64_t cpuUsage, const ::android::hardware::graphics::mapper::V3_0::IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lockYCbCr_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::mapper::V3_0::BpHwMapper::_hidl_lockYCbCr(this, this, buffer, cpuUsage, accessRegion, acquireFence, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::unlock(void* buffer, unlock_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::mapper::V3_0::BpHwMapper::_hidl_unlock(this, this, buffer, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::isSupported(const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, isSupported_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::mapper::V3_0::BpHwMapper::_hidl_isSupported(this, this, description, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwMapper::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwMapper::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwMapper::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwMapper::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwMapper::BnHwMapper(const ::android::sp<IMapper> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.graphics.mapper@3.0", "IMapper") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwMapper::~BnHwMapper() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::graphics::mapper::V3_0::IMapper follow.
::android::status_t BnHwMapper::_hidl_createDescriptor(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwMapper::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo* description;

    size_t _hidl_description_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*description), &_hidl_description_parent,  const_cast<const void**>(reinterpret_cast<void **>(&description)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IMapper::createDescriptor::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)description);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "createDescriptor", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IMapper*>(_hidl_this->getImpl().get())->createDescriptor(*description, [&](const auto &_hidl_out_error, const auto &_hidl_out_descriptor) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("createDescriptor: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_descriptor_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_descriptor, sizeof(_hidl_out_descriptor), &_hidl__hidl_out_descriptor_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_descriptor_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_descriptor,
                _hidl_reply,
                _hidl__hidl_out_descriptor_parent,
                0 /* parentOffset */, &_hidl__hidl_out_descriptor_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_descriptor);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "createDescriptor", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("createDescriptor: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwMapper::_hidl_importBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwMapper::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::hidl_handle rawHandle;

    const native_handle_t *rawHandle_ptr;

    _hidl_err = _hidl_data.readNullableNativeHandleNoDup(&rawHandle_ptr);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    rawHandle = rawHandle_ptr;
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IMapper::importBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&rawHandle);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "importBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IMapper*>(_hidl_this->getImpl().get())->importBuffer(rawHandle, [&](const auto &_hidl_out_error, const auto &_hidl_out_buffer) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("importBuffer: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        (void)_hidl_out_buffer;
        LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_buffer);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "importBuffer", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("importBuffer: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwMapper::_hidl_freeBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwMapper::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    void* buffer;

    (void)buffer;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IMapper::freeBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "freeBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::graphics::mapper::V3_0::Error _hidl_out_error = static_cast<IMapper*>(_hidl_this->getImpl().get())->freeBuffer(buffer);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "freeBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwMapper::_hidl_validateBufferSize(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwMapper::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    void* buffer;
    ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo* description;
    uint32_t stride;

    (void)buffer;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_description_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*description), &_hidl_description_parent,  const_cast<const void**>(reinterpret_cast<void **>(&description)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&stride);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IMapper::validateBufferSize::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        _hidl_args.push_back((void *)description);
        _hidl_args.push_back((void *)&stride);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "validateBufferSize", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::graphics::mapper::V3_0::Error _hidl_out_error = static_cast<IMapper*>(_hidl_this->getImpl().get())->validateBufferSize(buffer, *description, stride);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "validateBufferSize", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwMapper::_hidl_getTransportSize(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwMapper::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    void* buffer;

    (void)buffer;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IMapper::getTransportSize::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "getTransportSize", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IMapper*>(_hidl_this->getImpl().get())->getTransportSize(buffer, [&](const auto &_hidl_out_error, const auto &_hidl_out_numFds, const auto &_hidl_out_numInts) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getTransportSize: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_numFds);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_numInts);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_numFds);
            _hidl_args.push_back((void *)&_hidl_out_numInts);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "getTransportSize", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getTransportSize: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwMapper::_hidl_lock(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwMapper::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    void* buffer;
    uint64_t cpuUsage;
    ::android::hardware::graphics::mapper::V3_0::IMapper::Rect* accessRegion;
    ::android::hardware::hidl_handle acquireFence;

    (void)buffer;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&cpuUsage);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_accessRegion_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*accessRegion), &_hidl_accessRegion_parent,  const_cast<const void**>(reinterpret_cast<void **>(&accessRegion)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    const native_handle_t *acquireFence_ptr;

    _hidl_err = _hidl_data.readNullableNativeHandleNoDup(&acquireFence_ptr);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    acquireFence = acquireFence_ptr;
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IMapper::lock::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        _hidl_args.push_back((void *)&cpuUsage);
        _hidl_args.push_back((void *)accessRegion);
        _hidl_args.push_back((void *)&acquireFence);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "lock", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IMapper*>(_hidl_this->getImpl().get())->lock(buffer, cpuUsage, *accessRegion, acquireFence, [&](const auto &_hidl_out_error, const auto &_hidl_out_data, const auto &_hidl_out_bytesPerPixel, const auto &_hidl_out_bytesPerStride) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("lock: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        (void)_hidl_out_data;
        LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_bytesPerPixel);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_bytesPerStride);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_data);
            _hidl_args.push_back((void *)&_hidl_out_bytesPerPixel);
            _hidl_args.push_back((void *)&_hidl_out_bytesPerStride);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "lock", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("lock: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwMapper::_hidl_lockYCbCr(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwMapper::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    void* buffer;
    uint64_t cpuUsage;
    ::android::hardware::graphics::mapper::V3_0::IMapper::Rect* accessRegion;
    ::android::hardware::hidl_handle acquireFence;

    (void)buffer;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&cpuUsage);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_accessRegion_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*accessRegion), &_hidl_accessRegion_parent,  const_cast<const void**>(reinterpret_cast<void **>(&accessRegion)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    const native_handle_t *acquireFence_ptr;

    _hidl_err = _hidl_data.readNullableNativeHandleNoDup(&acquireFence_ptr);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    acquireFence = acquireFence_ptr;
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IMapper::lockYCbCr::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        _hidl_args.push_back((void *)&cpuUsage);
        _hidl_args.push_back((void *)accessRegion);
        _hidl_args.push_back((void *)&acquireFence);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "lockYCbCr", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IMapper*>(_hidl_this->getImpl().get())->lockYCbCr(buffer, cpuUsage, *accessRegion, acquireFence, [&](const auto &_hidl_out_error, const auto &_hidl_out_layout) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("lockYCbCr: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_layout_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_layout, sizeof(_hidl_out_layout), &_hidl__hidl_out_layout_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_layout,
                _hidl_reply,
                _hidl__hidl_out_layout_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_layout);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "lockYCbCr", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("lockYCbCr: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwMapper::_hidl_unlock(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwMapper::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    void* buffer;

    (void)buffer;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IMapper::unlock::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "unlock", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IMapper*>(_hidl_this->getImpl().get())->unlock(buffer, [&](const auto &_hidl_out_error, const auto &_hidl_out_releaseFence) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("unlock: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeNativeHandleNoDup(_hidl_out_releaseFence);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_releaseFence);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "unlock", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("unlock: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwMapper::_hidl_isSupported(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwMapper::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo* description;

    size_t _hidl_description_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*description), &_hidl_description_parent,  const_cast<const void**>(reinterpret_cast<void **>(&description)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IMapper::isSupported::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)description);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.mapper", "3.0", "IMapper", "isSupported", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IMapper*>(_hidl_this->getImpl().get())->isSupported(*description, [&](const auto &_hidl_out_error, const auto &_hidl_out_supported) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("isSupported: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeBool(_hidl_out_supported);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_supported);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.mapper", "3.0", "IMapper", "isSupported", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("isSupported: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::graphics::mapper::V3_0::IMapper follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwMapper::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwMapper::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwMapper::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* createDescriptor */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V3_0::BnHwMapper::_hidl_createDescriptor(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* importBuffer */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V3_0::BnHwMapper::_hidl_importBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* freeBuffer */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V3_0::BnHwMapper::_hidl_freeBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* validateBufferSize */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V3_0::BnHwMapper::_hidl_validateBufferSize(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* getTransportSize */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V3_0::BnHwMapper::_hidl_getTransportSize(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* lock */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V3_0::BnHwMapper::_hidl_lock(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* lockYCbCr */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V3_0::BnHwMapper::_hidl_lockYCbCr(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* unlock */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V3_0::BnHwMapper::_hidl_unlock(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* isSupported */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V3_0::BnHwMapper::_hidl_isSupported(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsMapper::BsMapper(const ::android::sp<::android::hardware::graphics::mapper::V3_0::IMapper> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.graphics.mapper@3.0", "IMapper"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsMapper::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IMapper> IMapper::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwMapper>(serviceName, false, getStub);
}

::android::sp<IMapper> IMapper::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwMapper>(serviceName, true, getStub);
}

::android::status_t IMapper::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IMapper::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.graphics.mapper@3.0::IMapper",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V3_0
}  // namespace mapper
}  // namespace graphics
}  // namespace hardware
}  // namespace android
