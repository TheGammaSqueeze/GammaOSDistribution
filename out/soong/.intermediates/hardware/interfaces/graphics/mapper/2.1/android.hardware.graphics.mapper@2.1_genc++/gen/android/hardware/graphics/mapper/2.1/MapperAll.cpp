#define LOG_TAG "android.hardware.graphics.mapper@2.1::Mapper"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/graphics/mapper/2.1/BpHwMapper.h>
#include <android/hardware/graphics/mapper/2.1/BnHwMapper.h>
#include <android/hardware/graphics/mapper/2.1/BsMapper.h>
#include <android/hardware/graphics/mapper/2.0/BpHwMapper.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace graphics {
namespace mapper {
namespace V2_1 {

const char* IMapper::descriptor("android.hardware.graphics.mapper@2.1::IMapper");

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

// Methods from ::android::hardware::graphics::mapper::V2_0::IMapper follow.
// no default implementation for: ::android::hardware::Return<void> IMapper::createDescriptor(const ::android::hardware::graphics::mapper::V2_0::IMapper::BufferDescriptorInfo& descriptorInfo, createDescriptor_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IMapper::importBuffer(const ::android::hardware::hidl_handle& rawHandle, importBuffer_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::graphics::mapper::V2_0::Error> IMapper::freeBuffer(void* buffer)
// no default implementation for: ::android::hardware::Return<void> IMapper::lock(void* buffer, ::android::hardware::hidl_bitfield<::android::hardware::graphics::common::V1_0::BufferUsage> cpuUsage, const ::android::hardware::graphics::mapper::V2_0::IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lock_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IMapper::lockYCbCr(void* buffer, ::android::hardware::hidl_bitfield<::android::hardware::graphics::common::V1_0::BufferUsage> cpuUsage, const ::android::hardware::graphics::mapper::V2_0::IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lockYCbCr_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IMapper::unlock(void* buffer, unlock_cb _hidl_cb)

// Methods from ::android::hardware::graphics::mapper::V2_1::IMapper follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::graphics::mapper::V2_0::Error> IMapper::validateBufferSize(void* buffer, const ::android::hardware::graphics::mapper::V2_1::IMapper::BufferDescriptorInfo& descriptorInfo, uint32_t stride)
// no default implementation for: ::android::hardware::Return<void> IMapper::getTransportSize(void* buffer, getTransportSize_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IMapper::createDescriptor_2_1(const ::android::hardware::graphics::mapper::V2_1::IMapper::BufferDescriptorInfo& descriptorInfo, createDescriptor_2_1_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IMapper::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::graphics::mapper::V2_1::IMapper::descriptor,
        ::android::hardware::graphics::mapper::V2_0::IMapper::descriptor,
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
    _hidl_cb(::android::hardware::graphics::mapper::V2_1::IMapper::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IMapper::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){221,131,190,7,107,107,63,16,237,98,171,52,216,200,185,95,36,21,150,31,183,133,32,14,184,66,231,191,178,176,238,146} /* dd83be076b6b3f10ed62ab34d8c8b95f2415961fb785200eb842e7bfb2b0ee92 */,
        (uint8_t[32]){247,215,203,116,125,192,26,159,219,45,57,168,0,3,180,216,223,155,231,51,214,95,88,66,25,136,2,235,98,9,219,105} /* f7d7cb747dc01a9fdb2d39a80003b4d8df9be733d65f5842198802eb6209db69 */,
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


::android::hardware::Return<::android::sp<::android::hardware::graphics::mapper::V2_1::IMapper>> IMapper::castFrom(const ::android::sp<::android::hardware::graphics::mapper::V2_1::IMapper>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::graphics::mapper::V2_1::IMapper>> IMapper::castFrom(const ::android::sp<::android::hardware::graphics::mapper::V2_0::IMapper>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IMapper, ::android::hardware::graphics::mapper::V2_0::IMapper, BpHwMapper>(
            parent, "android.hardware.graphics.mapper@2.1::IMapper", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::graphics::mapper::V2_1::IMapper>> IMapper::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IMapper, ::android::hidl::base::V1_0::IBase, BpHwMapper>(
            parent, "android.hardware.graphics.mapper@2.1::IMapper", emitError);
}

BpHwMapper::BpHwMapper(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IMapper>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.graphics.mapper@2.1", "IMapper") {
}

void BpHwMapper::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IMapper>::onLastStrongRef(id);
}
// Methods from ::android::hardware::graphics::mapper::V2_1::IMapper follow.
::android::hardware::Return<::android::hardware::graphics::mapper::V2_0::Error> BpHwMapper::_hidl_validateBufferSize(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer, const ::android::hardware::graphics::mapper::V2_1::IMapper::BufferDescriptorInfo& descriptorInfo, uint32_t stride) {
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
        _hidl_args.push_back((void *)&descriptorInfo);
        _hidl_args.push_back((void *)&stride);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.mapper", "2.1", "IMapper", "validateBufferSize", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::graphics::mapper::V2_0::Error _hidl_out_error;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwMapper::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)buffer;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_descriptorInfo_parent;

    _hidl_err = _hidl_data.writeBuffer(&descriptorInfo, sizeof(descriptorInfo), &_hidl_descriptorInfo_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(stride);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* validateBufferSize */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.mapper", "2.1", "IMapper", "validateBufferSize", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::graphics::mapper::V2_0::Error>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::graphics::mapper::V2_0::Error>(_hidl_status);
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
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.mapper", "2.1", "IMapper", "getTransportSize", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* getTransportSize */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::graphics::mapper::V2_0::Error _hidl_out_error;
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
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.mapper", "2.1", "IMapper", "getTransportSize", &_hidl_args);
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

::android::hardware::Return<void> BpHwMapper::_hidl_createDescriptor_2_1(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::graphics::mapper::V2_1::IMapper::BufferDescriptorInfo& descriptorInfo, createDescriptor_2_1_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IMapper::createDescriptor_2_1::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&descriptorInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.mapper", "2.1", "IMapper", "createDescriptor_2_1", &_hidl_args);
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

    size_t _hidl_descriptorInfo_parent;

    _hidl_err = _hidl_data.writeBuffer(&descriptorInfo, sizeof(descriptorInfo), &_hidl_descriptorInfo_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* createDescriptor_2_1 */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::graphics::mapper::V2_0::Error _hidl_out_error;
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
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.mapper", "2.1", "IMapper", "createDescriptor_2_1", &_hidl_args);
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


// Methods from ::android::hardware::graphics::mapper::V2_0::IMapper follow.
::android::hardware::Return<void> BpHwMapper::createDescriptor(const ::android::hardware::graphics::mapper::V2_0::IMapper::BufferDescriptorInfo& descriptorInfo, createDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::mapper::V2_0::BpHwMapper::_hidl_createDescriptor(this, this, descriptorInfo, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::importBuffer(const ::android::hardware::hidl_handle& rawHandle, importBuffer_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::mapper::V2_0::BpHwMapper::_hidl_importBuffer(this, this, rawHandle, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::graphics::mapper::V2_0::Error> BpHwMapper::freeBuffer(void* buffer){
    ::android::hardware::Return<::android::hardware::graphics::mapper::V2_0::Error>  _hidl_out = ::android::hardware::graphics::mapper::V2_0::BpHwMapper::_hidl_freeBuffer(this, this, buffer);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::lock(void* buffer, ::android::hardware::hidl_bitfield<::android::hardware::graphics::common::V1_0::BufferUsage> cpuUsage, const ::android::hardware::graphics::mapper::V2_0::IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lock_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::mapper::V2_0::BpHwMapper::_hidl_lock(this, this, buffer, cpuUsage, accessRegion, acquireFence, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::lockYCbCr(void* buffer, ::android::hardware::hidl_bitfield<::android::hardware::graphics::common::V1_0::BufferUsage> cpuUsage, const ::android::hardware::graphics::mapper::V2_0::IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lockYCbCr_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::mapper::V2_0::BpHwMapper::_hidl_lockYCbCr(this, this, buffer, cpuUsage, accessRegion, acquireFence, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::unlock(void* buffer, unlock_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::mapper::V2_0::BpHwMapper::_hidl_unlock(this, this, buffer, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hardware::graphics::mapper::V2_1::IMapper follow.
::android::hardware::Return<::android::hardware::graphics::mapper::V2_0::Error> BpHwMapper::validateBufferSize(void* buffer, const ::android::hardware::graphics::mapper::V2_1::IMapper::BufferDescriptorInfo& descriptorInfo, uint32_t stride){
    ::android::hardware::Return<::android::hardware::graphics::mapper::V2_0::Error>  _hidl_out = ::android::hardware::graphics::mapper::V2_1::BpHwMapper::_hidl_validateBufferSize(this, this, buffer, descriptorInfo, stride);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::getTransportSize(void* buffer, getTransportSize_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::mapper::V2_1::BpHwMapper::_hidl_getTransportSize(this, this, buffer, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwMapper::createDescriptor_2_1(const ::android::hardware::graphics::mapper::V2_1::IMapper::BufferDescriptorInfo& descriptorInfo, createDescriptor_2_1_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::mapper::V2_1::BpHwMapper::_hidl_createDescriptor_2_1(this, this, descriptorInfo, _hidl_cb);

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
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.graphics.mapper@2.1", "IMapper") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwMapper::~BnHwMapper() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::graphics::mapper::V2_1::IMapper follow.
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
    ::android::hardware::graphics::mapper::V2_1::IMapper::BufferDescriptorInfo* descriptorInfo;
    uint32_t stride;

    (void)buffer;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_descriptorInfo_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*descriptorInfo), &_hidl_descriptorInfo_parent,  const_cast<const void**>(reinterpret_cast<void **>(&descriptorInfo)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&stride);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IMapper::validateBufferSize::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        _hidl_args.push_back((void *)descriptorInfo);
        _hidl_args.push_back((void *)&stride);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.mapper", "2.1", "IMapper", "validateBufferSize", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::graphics::mapper::V2_0::Error _hidl_out_error = static_cast<IMapper*>(_hidl_this->getImpl().get())->validateBufferSize(buffer, *descriptorInfo, stride);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.mapper", "2.1", "IMapper", "validateBufferSize", &_hidl_args);
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
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.mapper", "2.1", "IMapper", "getTransportSize", &_hidl_args);
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
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.mapper", "2.1", "IMapper", "getTransportSize", &_hidl_args);
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

::android::status_t BnHwMapper::_hidl_createDescriptor_2_1(
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

    ::android::hardware::graphics::mapper::V2_1::IMapper::BufferDescriptorInfo* descriptorInfo;

    size_t _hidl_descriptorInfo_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*descriptorInfo), &_hidl_descriptorInfo_parent,  const_cast<const void**>(reinterpret_cast<void **>(&descriptorInfo)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IMapper::createDescriptor_2_1::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)descriptorInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.mapper", "2.1", "IMapper", "createDescriptor_2_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IMapper*>(_hidl_this->getImpl().get())->createDescriptor_2_1(*descriptorInfo, [&](const auto &_hidl_out_error, const auto &_hidl_out_descriptor) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("createDescriptor_2_1: _hidl_cb called a second time, but must be called once.");
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
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.mapper", "2.1", "IMapper", "createDescriptor_2_1", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("createDescriptor_2_1: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::graphics::mapper::V2_0::IMapper follow.

// Methods from ::android::hardware::graphics::mapper::V2_1::IMapper follow.

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
            _hidl_err = ::android::hardware::graphics::mapper::V2_0::BnHwMapper::_hidl_createDescriptor(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* importBuffer */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V2_0::BnHwMapper::_hidl_importBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* freeBuffer */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V2_0::BnHwMapper::_hidl_freeBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* lock */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V2_0::BnHwMapper::_hidl_lock(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* lockYCbCr */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V2_0::BnHwMapper::_hidl_lockYCbCr(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* unlock */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V2_0::BnHwMapper::_hidl_unlock(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* validateBufferSize */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V2_1::BnHwMapper::_hidl_validateBufferSize(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* getTransportSize */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V2_1::BnHwMapper::_hidl_getTransportSize(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* createDescriptor_2_1 */:
        {
            _hidl_err = ::android::hardware::graphics::mapper::V2_1::BnHwMapper::_hidl_createDescriptor_2_1(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsMapper::BsMapper(const ::android::sp<::android::hardware::graphics::mapper::V2_1::IMapper> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.graphics.mapper@2.1", "IMapper"), mImpl(impl) {
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
            sm->registerForNotifications("android.hardware.graphics.mapper@2.1::IMapper",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_1
}  // namespace mapper
}  // namespace graphics
}  // namespace hardware
}  // namespace android
