#define LOG_TAG "android.hardware.graphics.bufferqueue@1.0::GraphicBufferProducer"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/graphics/bufferqueue/1.0/BpHwGraphicBufferProducer.h>
#include <android/hardware/graphics/bufferqueue/1.0/BnHwGraphicBufferProducer.h>
#include <android/hardware/graphics/bufferqueue/1.0/BsGraphicBufferProducer.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace graphics {
namespace bufferqueue {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const IGraphicBufferProducer::IGraphicBufferProducer::FenceTimeSnapshot &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_handle &>(obj.fence),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FenceTimeSnapshot, fence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const IGraphicBufferProducer::IGraphicBufferProducer::FenceTimeSnapshot &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.fence,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FenceTimeSnapshot, fence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const IGraphicBufferProducer::IGraphicBufferProducer::FrameEventsDelta &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FenceTimeSnapshot &>(obj.gpuCompositionDoneFence),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventsDelta, gpuCompositionDoneFence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FenceTimeSnapshot &>(obj.displayPresentFence),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventsDelta, displayPresentFence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FenceTimeSnapshot &>(obj.displayRetireFence),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventsDelta, displayRetireFence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FenceTimeSnapshot &>(obj.releaseFence),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventsDelta, releaseFence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const IGraphicBufferProducer::IGraphicBufferProducer::FrameEventsDelta &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.gpuCompositionDoneFence,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventsDelta, gpuCompositionDoneFence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.displayPresentFence,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventsDelta, displayPresentFence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.displayRetireFence,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventsDelta, displayRetireFence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.releaseFence,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventsDelta, releaseFence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const IGraphicBufferProducer::IGraphicBufferProducer::FrameEventHistoryDelta &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_deltas_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventsDelta> &>(obj.deltas),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventHistoryDelta, deltas), &_hidl_deltas_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.deltas.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventsDelta &>(obj.deltas[_hidl_index_0]),
                parcel,
                _hidl_deltas_child,
                _hidl_index_0 * sizeof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventsDelta));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const IGraphicBufferProducer::IGraphicBufferProducer::FrameEventHistoryDelta &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_deltas_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.deltas,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventHistoryDelta, deltas), &_hidl_deltas_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.deltas.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.deltas[_hidl_index_0],
                parcel,
                _hidl_deltas_child,
                _hidl_index_0 * sizeof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventsDelta));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const IGraphicBufferProducer::IGraphicBufferProducer::QueueBufferInput &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_handle &>(obj.fence),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferInput, fence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_surfaceDamage_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::media::V1_0::Rect> &>(obj.surfaceDamage),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferInput, surfaceDamage), &_hidl_surfaceDamage_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const IGraphicBufferProducer::IGraphicBufferProducer::QueueBufferInput &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.fence,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferInput, fence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_surfaceDamage_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.surfaceDamage,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferInput, surfaceDamage), &_hidl_surfaceDamage_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const IGraphicBufferProducer::IGraphicBufferProducer::QueueBufferOutput &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventHistoryDelta &>(obj.frameTimestamps),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferOutput, frameTimestamps));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const IGraphicBufferProducer::IGraphicBufferProducer::QueueBufferOutput &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.frameTimestamps,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferOutput, frameTimestamps));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

const char* IGraphicBufferProducer::descriptor("android.hardware.graphics.bufferqueue@1.0::IGraphicBufferProducer");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IGraphicBufferProducer::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwGraphicBufferProducer(static_cast<IGraphicBufferProducer *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IGraphicBufferProducer::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsGraphicBufferProducer(static_cast<IGraphicBufferProducer *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IGraphicBufferProducer::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IGraphicBufferProducer::descriptor);
}

// Methods from ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer follow.
// no default implementation for: ::android::hardware::Return<void> IGraphicBufferProducer::requestBuffer(int32_t slot, requestBuffer_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<int32_t> IGraphicBufferProducer::setMaxDequeuedBufferCount(int32_t maxDequeuedBuffers)
// no default implementation for: ::android::hardware::Return<int32_t> IGraphicBufferProducer::setAsyncMode(bool async)
// no default implementation for: ::android::hardware::Return<void> IGraphicBufferProducer::dequeueBuffer(uint32_t width, uint32_t height, ::android::hardware::graphics::common::V1_0::PixelFormat format, uint32_t usage, bool getFrameTimestamps, dequeueBuffer_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<int32_t> IGraphicBufferProducer::detachBuffer(int32_t slot)
// no default implementation for: ::android::hardware::Return<void> IGraphicBufferProducer::detachNextBuffer(detachNextBuffer_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IGraphicBufferProducer::attachBuffer(const ::android::hardware::media::V1_0::AnwBuffer& buffer, attachBuffer_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IGraphicBufferProducer::queueBuffer(int32_t slot, const ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferInput& input, queueBuffer_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<int32_t> IGraphicBufferProducer::cancelBuffer(int32_t slot, const ::android::hardware::hidl_handle& fence)
// no default implementation for: ::android::hardware::Return<void> IGraphicBufferProducer::query(int32_t what, query_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IGraphicBufferProducer::connect(const ::android::sp<::android::hardware::graphics::bufferqueue::V1_0::IProducerListener>& listener, int32_t api, bool producerControlledByApp, connect_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<int32_t> IGraphicBufferProducer::disconnect(int32_t api, ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::DisconnectMode mode)
// no default implementation for: ::android::hardware::Return<int32_t> IGraphicBufferProducer::setSidebandStream(const ::android::hardware::hidl_handle& stream)
// no default implementation for: ::android::hardware::Return<void> IGraphicBufferProducer::allocateBuffers(uint32_t width, uint32_t height, ::android::hardware::graphics::common::V1_0::PixelFormat format, uint32_t usage)
// no default implementation for: ::android::hardware::Return<int32_t> IGraphicBufferProducer::allowAllocation(bool allow)
// no default implementation for: ::android::hardware::Return<int32_t> IGraphicBufferProducer::setGenerationNumber(uint32_t generationNumber)
// no default implementation for: ::android::hardware::Return<void> IGraphicBufferProducer::getConsumerName(getConsumerName_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<int32_t> IGraphicBufferProducer::setSharedBufferMode(bool sharedBufferMode)
// no default implementation for: ::android::hardware::Return<int32_t> IGraphicBufferProducer::setAutoRefresh(bool autoRefresh)
// no default implementation for: ::android::hardware::Return<int32_t> IGraphicBufferProducer::setDequeueTimeout(int64_t timeoutNs)
// no default implementation for: ::android::hardware::Return<void> IGraphicBufferProducer::getLastQueuedBuffer(getLastQueuedBuffer_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IGraphicBufferProducer::getFrameTimestamps(getFrameTimestamps_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IGraphicBufferProducer::getUniqueId(getUniqueId_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IGraphicBufferProducer::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGraphicBufferProducer::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGraphicBufferProducer::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGraphicBufferProducer::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){124,119,33,192,247,115,252,244,34,183,26,79,85,133,69,233,227,106,204,151,62,88,202,81,229,189,83,144,92,244,107,192} /* 7c7721c0f773fcf422b71a4f558545e9e36acc973e58ca51e5bd53905cf46bc0 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGraphicBufferProducer::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IGraphicBufferProducer::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IGraphicBufferProducer::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGraphicBufferProducer::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IGraphicBufferProducer::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IGraphicBufferProducer::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer>> IGraphicBufferProducer::castFrom(const ::android::sp<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer>> IGraphicBufferProducer::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGraphicBufferProducer, ::android::hidl::base::V1_0::IBase, BpHwGraphicBufferProducer>(
            parent, "android.hardware.graphics.bufferqueue@1.0::IGraphicBufferProducer", emitError);
}

BpHwGraphicBufferProducer::BpHwGraphicBufferProducer(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IGraphicBufferProducer>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.graphics.bufferqueue@1.0", "IGraphicBufferProducer") {
}

void BpHwGraphicBufferProducer::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IGraphicBufferProducer>::onLastStrongRef(id);
}
// Methods from ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer follow.
::android::hardware::Return<void> BpHwGraphicBufferProducer::_hidl_requestBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t slot, requestBuffer_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::requestBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&slot);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "requestBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* requestBuffer */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        int32_t _hidl_out_status;
        ::android::hardware::media::V1_0::AnwBuffer* _hidl_out_buffer;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_buffer_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_buffer), &_hidl__hidl_out_buffer_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_buffer)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::media::V1_0::AnwBuffer &>(*_hidl_out_buffer),
                _hidl_reply,
                _hidl__hidl_out_buffer_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_buffer);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_buffer);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "requestBuffer", &_hidl_args);
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

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::_hidl_setMaxDequeuedBufferCount(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t maxDequeuedBuffers) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::setMaxDequeuedBufferCount::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&maxDequeuedBuffers);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setMaxDequeuedBufferCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(maxDequeuedBuffers);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* setMaxDequeuedBufferCount */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setMaxDequeuedBufferCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::_hidl_setAsyncMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool async) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::setAsyncMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&async);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setAsyncMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(async);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* setAsyncMode */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setAsyncMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::_hidl_dequeueBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t width, uint32_t height, ::android::hardware::graphics::common::V1_0::PixelFormat format, uint32_t usage, bool getFrameTimestamps, dequeueBuffer_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::dequeueBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&width);
        _hidl_args.push_back((void *)&height);
        _hidl_args.push_back((void *)&format);
        _hidl_args.push_back((void *)&usage);
        _hidl_args.push_back((void *)&getFrameTimestamps);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "dequeueBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(width);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(height);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)format);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(usage);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(getFrameTimestamps);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* dequeueBuffer */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        int32_t _hidl_out_status;
        int32_t _hidl_out_slot;
        ::android::hardware::hidl_handle _hidl_out_fence;
        ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventHistoryDelta* _hidl_out_outTimestamps;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_slot);
        if (_hidl_err != ::android::OK) { return; }

        const native_handle_t *_hidl_out_fence_ptr;

        _hidl_err = _hidl_reply.readNullableNativeHandleNoDup(&_hidl_out_fence_ptr);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_out_fence = _hidl_out_fence_ptr;
        size_t _hidl__hidl_out_outTimestamps_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_outTimestamps), &_hidl__hidl_out_outTimestamps_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_outTimestamps)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventHistoryDelta &>(*_hidl_out_outTimestamps),
                _hidl_reply,
                _hidl__hidl_out_outTimestamps_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_slot, _hidl_out_fence, *_hidl_out_outTimestamps);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_slot);
            _hidl_args.push_back((void *)&_hidl_out_fence);
            _hidl_args.push_back((void *)_hidl_out_outTimestamps);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "dequeueBuffer", &_hidl_args);
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

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::_hidl_detachBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t slot) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::detachBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&slot);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "detachBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* detachBuffer */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "detachBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::_hidl_detachNextBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, detachNextBuffer_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::detachNextBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "detachNextBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* detachNextBuffer */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        int32_t _hidl_out_status;
        ::android::hardware::media::V1_0::AnwBuffer* _hidl_out_buffer;
        ::android::hardware::hidl_handle _hidl_out_fence;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_buffer_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_buffer), &_hidl__hidl_out_buffer_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_buffer)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::media::V1_0::AnwBuffer &>(*_hidl_out_buffer),
                _hidl_reply,
                _hidl__hidl_out_buffer_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        const native_handle_t *_hidl_out_fence_ptr;

        _hidl_err = _hidl_reply.readNullableNativeHandleNoDup(&_hidl_out_fence_ptr);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_out_fence = _hidl_out_fence_ptr;
        _hidl_cb(_hidl_out_status, *_hidl_out_buffer, _hidl_out_fence);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_buffer);
            _hidl_args.push_back((void *)&_hidl_out_fence);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "detachNextBuffer", &_hidl_args);
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

::android::hardware::Return<void> BpHwGraphicBufferProducer::_hidl_attachBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::media::V1_0::AnwBuffer& buffer, attachBuffer_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::attachBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "attachBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_buffer_parent;

    _hidl_err = _hidl_data.writeBuffer(&buffer, sizeof(buffer), &_hidl_buffer_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            buffer,
            &_hidl_data,
            _hidl_buffer_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* attachBuffer */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        int32_t _hidl_out_status;
        int32_t _hidl_out_slot;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_slot);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_slot);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_slot);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "attachBuffer", &_hidl_args);
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

::android::hardware::Return<void> BpHwGraphicBufferProducer::_hidl_queueBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t slot, const ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferInput& input, queueBuffer_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::queueBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&input);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "queueBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_input_parent;

    _hidl_err = _hidl_data.writeBuffer(&input, sizeof(input), &_hidl_input_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            input,
            &_hidl_data,
            _hidl_input_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* queueBuffer */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        int32_t _hidl_out_status;
        ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferOutput* _hidl_out_output;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_output_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_output), &_hidl__hidl_out_output_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_output)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferOutput &>(*_hidl_out_output),
                _hidl_reply,
                _hidl__hidl_out_output_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_output);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_output);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "queueBuffer", &_hidl_args);
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

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::_hidl_cancelBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t slot, const ::android::hardware::hidl_handle& fence) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::cancelBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&fence);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "cancelBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeNativeHandleNoDup(fence);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* cancelBuffer */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "cancelBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::_hidl_query(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t what, query_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::query::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&what);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "query", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(what);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* query */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        int32_t _hidl_out_result;
        int32_t _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_result);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_value);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_result, _hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_result);
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "query", &_hidl_args);
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

::android::hardware::Return<void> BpHwGraphicBufferProducer::_hidl_connect(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::graphics::bufferqueue::V1_0::IProducerListener>& listener, int32_t api, bool producerControlledByApp, connect_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::connect::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&listener);
        _hidl_args.push_back((void *)&api);
        _hidl_args.push_back((void *)&producerControlledByApp);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "connect", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (listener == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(listener.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(api);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(producerControlledByApp);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* connect */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        int32_t _hidl_out_status;
        ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferOutput* _hidl_out_output;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_output_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_output), &_hidl__hidl_out_output_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_output)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferOutput &>(*_hidl_out_output),
                _hidl_reply,
                _hidl__hidl_out_output_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_output);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_output);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "connect", &_hidl_args);
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

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::_hidl_disconnect(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t api, ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::DisconnectMode mode) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::disconnect::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&api);
        _hidl_args.push_back((void *)&mode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "disconnect", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(api);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)mode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* disconnect */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "disconnect", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::_hidl_setSidebandStream(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_handle& stream) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::setSidebandStream::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&stream);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setSidebandStream", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeNativeHandleNoDup(stream);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* setSidebandStream */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setSidebandStream", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::_hidl_allocateBuffers(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t width, uint32_t height, ::android::hardware::graphics::common::V1_0::PixelFormat format, uint32_t usage) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::allocateBuffers::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&width);
        _hidl_args.push_back((void *)&height);
        _hidl_args.push_back((void *)&format);
        _hidl_args.push_back((void *)&usage);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "allocateBuffers", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(width);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(height);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)format);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(usage);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(14 /* allocateBuffers */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "allocateBuffers", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::_hidl_allowAllocation(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool allow) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::allowAllocation::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allow);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "allowAllocation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(allow);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(15 /* allowAllocation */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "allowAllocation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::_hidl_setGenerationNumber(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t generationNumber) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::setGenerationNumber::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&generationNumber);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setGenerationNumber", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(generationNumber);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(16 /* setGenerationNumber */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setGenerationNumber", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::_hidl_getConsumerName(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getConsumerName_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::getConsumerName::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getConsumerName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(17 /* getConsumerName */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
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
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getConsumerName", &_hidl_args);
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

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::_hidl_setSharedBufferMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool sharedBufferMode) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::setSharedBufferMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sharedBufferMode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setSharedBufferMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(sharedBufferMode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(18 /* setSharedBufferMode */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setSharedBufferMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::_hidl_setAutoRefresh(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool autoRefresh) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::setAutoRefresh::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&autoRefresh);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setAutoRefresh", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(autoRefresh);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(19 /* setAutoRefresh */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setAutoRefresh", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::_hidl_setDequeueTimeout(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int64_t timeoutNs) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::setDequeueTimeout::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&timeoutNs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setDequeueTimeout", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt64(timeoutNs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(20 /* setDequeueTimeout */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setDequeueTimeout", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::_hidl_getLastQueuedBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getLastQueuedBuffer_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::getLastQueuedBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getLastQueuedBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(21 /* getLastQueuedBuffer */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        int32_t _hidl_out_status;
        ::android::hardware::media::V1_0::AnwBuffer* _hidl_out_buffer;
        ::android::hardware::hidl_handle _hidl_out_fence;
        const ::android::hardware::hidl_array<float, 16>* _hidl_out_transformMatrix;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_buffer_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_buffer), &_hidl__hidl_out_buffer_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_buffer)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::media::V1_0::AnwBuffer &>(*_hidl_out_buffer),
                _hidl_reply,
                _hidl__hidl_out_buffer_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        const native_handle_t *_hidl_out_fence_ptr;

        _hidl_err = _hidl_reply.readNullableNativeHandleNoDup(&_hidl_out_fence_ptr);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_out_fence = _hidl_out_fence_ptr;
        size_t _hidl__hidl_out_transformMatrix_parent;

        _hidl_err = _hidl_reply.readBuffer(16 * sizeof(float), &_hidl__hidl_out_transformMatrix_parent,  reinterpret_cast<const void **>(&_hidl_out_transformMatrix));

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_buffer, _hidl_out_fence, *_hidl_out_transformMatrix);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_buffer);
            _hidl_args.push_back((void *)&_hidl_out_fence);
            _hidl_args.push_back((void *)_hidl_out_transformMatrix);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getLastQueuedBuffer", &_hidl_args);
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

::android::hardware::Return<void> BpHwGraphicBufferProducer::_hidl_getFrameTimestamps(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getFrameTimestamps_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::getFrameTimestamps::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getFrameTimestamps", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(22 /* getFrameTimestamps */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventHistoryDelta* _hidl_out_timeStamps;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_timeStamps_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_timeStamps), &_hidl__hidl_out_timeStamps_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_timeStamps)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::FrameEventHistoryDelta &>(*_hidl_out_timeStamps),
                _hidl_reply,
                _hidl__hidl_out_timeStamps_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_timeStamps);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_timeStamps);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getFrameTimestamps", &_hidl_args);
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

::android::hardware::Return<void> BpHwGraphicBufferProducer::_hidl_getUniqueId(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getUniqueId_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::getUniqueId::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getUniqueId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGraphicBufferProducer::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(23 /* getUniqueId */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        int32_t _hidl_out_status;
        uint64_t _hidl_out_outId;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint64(&_hidl_out_outId);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_outId);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_outId);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getUniqueId", &_hidl_args);
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


// Methods from ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer follow.
::android::hardware::Return<void> BpHwGraphicBufferProducer::requestBuffer(int32_t slot, requestBuffer_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_requestBuffer(this, this, slot, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::setMaxDequeuedBufferCount(int32_t maxDequeuedBuffers){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_setMaxDequeuedBufferCount(this, this, maxDequeuedBuffers);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::setAsyncMode(bool async){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_setAsyncMode(this, this, async);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::dequeueBuffer(uint32_t width, uint32_t height, ::android::hardware::graphics::common::V1_0::PixelFormat format, uint32_t usage, bool getFrameTimestamps, dequeueBuffer_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_dequeueBuffer(this, this, width, height, format, usage, getFrameTimestamps, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::detachBuffer(int32_t slot){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_detachBuffer(this, this, slot);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::detachNextBuffer(detachNextBuffer_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_detachNextBuffer(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::attachBuffer(const ::android::hardware::media::V1_0::AnwBuffer& buffer, attachBuffer_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_attachBuffer(this, this, buffer, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::queueBuffer(int32_t slot, const ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferInput& input, queueBuffer_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_queueBuffer(this, this, slot, input, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::cancelBuffer(int32_t slot, const ::android::hardware::hidl_handle& fence){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_cancelBuffer(this, this, slot, fence);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::query(int32_t what, query_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_query(this, this, what, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::connect(const ::android::sp<::android::hardware::graphics::bufferqueue::V1_0::IProducerListener>& listener, int32_t api, bool producerControlledByApp, connect_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_connect(this, this, listener, api, producerControlledByApp, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::disconnect(int32_t api, ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::DisconnectMode mode){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_disconnect(this, this, api, mode);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::setSidebandStream(const ::android::hardware::hidl_handle& stream){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_setSidebandStream(this, this, stream);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::allocateBuffers(uint32_t width, uint32_t height, ::android::hardware::graphics::common::V1_0::PixelFormat format, uint32_t usage){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_allocateBuffers(this, this, width, height, format, usage);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::allowAllocation(bool allow){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_allowAllocation(this, this, allow);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::setGenerationNumber(uint32_t generationNumber){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_setGenerationNumber(this, this, generationNumber);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::getConsumerName(getConsumerName_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_getConsumerName(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::setSharedBufferMode(bool sharedBufferMode){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_setSharedBufferMode(this, this, sharedBufferMode);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::setAutoRefresh(bool autoRefresh){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_setAutoRefresh(this, this, autoRefresh);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwGraphicBufferProducer::setDequeueTimeout(int64_t timeoutNs){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_setDequeueTimeout(this, this, timeoutNs);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::getLastQueuedBuffer(getLastQueuedBuffer_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_getLastQueuedBuffer(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::getFrameTimestamps(getFrameTimestamps_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_getFrameTimestamps(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::getUniqueId(getUniqueId_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::bufferqueue::V1_0::BpHwGraphicBufferProducer::_hidl_getUniqueId(this, this, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwGraphicBufferProducer::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGraphicBufferProducer::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGraphicBufferProducer::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGraphicBufferProducer::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwGraphicBufferProducer::BnHwGraphicBufferProducer(const ::android::sp<IGraphicBufferProducer> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.graphics.bufferqueue@1.0", "IGraphicBufferProducer") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwGraphicBufferProducer::~BnHwGraphicBufferProducer() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer follow.
::android::status_t BnHwGraphicBufferProducer::_hidl_requestBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t slot;

    _hidl_err = _hidl_data.readInt32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::requestBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&slot);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "requestBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->requestBuffer(slot, [&](const auto &_hidl_out_status, const auto &_hidl_out_buffer) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("requestBuffer: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_buffer_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_buffer, sizeof(_hidl_out_buffer), &_hidl__hidl_out_buffer_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_buffer,
                _hidl_reply,
                _hidl__hidl_out_buffer_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_buffer);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "requestBuffer", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("requestBuffer: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_setMaxDequeuedBufferCount(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t maxDequeuedBuffers;

    _hidl_err = _hidl_data.readInt32(&maxDequeuedBuffers);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::setMaxDequeuedBufferCount::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&maxDequeuedBuffers);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setMaxDequeuedBufferCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_status = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->setMaxDequeuedBufferCount(maxDequeuedBuffers);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setMaxDequeuedBufferCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_setAsyncMode(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    bool async;

    _hidl_err = _hidl_data.readBool(&async);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::setAsyncMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&async);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setAsyncMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_status = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->setAsyncMode(async);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setAsyncMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_dequeueBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t width;
    uint32_t height;
    ::android::hardware::graphics::common::V1_0::PixelFormat format;
    uint32_t usage;
    bool getFrameTimestamps;

    _hidl_err = _hidl_data.readUint32(&width);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&height);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&format);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&usage);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&getFrameTimestamps);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::dequeueBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&width);
        _hidl_args.push_back((void *)&height);
        _hidl_args.push_back((void *)&format);
        _hidl_args.push_back((void *)&usage);
        _hidl_args.push_back((void *)&getFrameTimestamps);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "dequeueBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->dequeueBuffer(width, height, format, usage, getFrameTimestamps, [&](const auto &_hidl_out_status, const auto &_hidl_out_slot, const auto &_hidl_out_fence, const auto &_hidl_out_outTimestamps) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("dequeueBuffer: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_slot);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeNativeHandleNoDup(_hidl_out_fence);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_outTimestamps_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_outTimestamps, sizeof(_hidl_out_outTimestamps), &_hidl__hidl_out_outTimestamps_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_outTimestamps,
                _hidl_reply,
                _hidl__hidl_out_outTimestamps_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_slot);
            _hidl_args.push_back((void *)&_hidl_out_fence);
            _hidl_args.push_back((void *)&_hidl_out_outTimestamps);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "dequeueBuffer", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("dequeueBuffer: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_detachBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t slot;

    _hidl_err = _hidl_data.readInt32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::detachBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&slot);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "detachBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_status = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->detachBuffer(slot);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "detachBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_detachNextBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::detachNextBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "detachNextBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->detachNextBuffer([&](const auto &_hidl_out_status, const auto &_hidl_out_buffer, const auto &_hidl_out_fence) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("detachNextBuffer: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_buffer_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_buffer, sizeof(_hidl_out_buffer), &_hidl__hidl_out_buffer_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_buffer,
                _hidl_reply,
                _hidl__hidl_out_buffer_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeNativeHandleNoDup(_hidl_out_fence);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_buffer);
            _hidl_args.push_back((void *)&_hidl_out_fence);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "detachNextBuffer", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("detachNextBuffer: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_attachBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::media::V1_0::AnwBuffer* buffer;

    size_t _hidl_buffer_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*buffer), &_hidl_buffer_parent,  const_cast<const void**>(reinterpret_cast<void **>(&buffer)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::media::V1_0::AnwBuffer &>(*buffer),
            _hidl_data,
            _hidl_buffer_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::attachBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)buffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "attachBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->attachBuffer(*buffer, [&](const auto &_hidl_out_status, const auto &_hidl_out_slot) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("attachBuffer: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_slot);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_slot);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "attachBuffer", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("attachBuffer: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_queueBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t slot;
    ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferInput* input;

    _hidl_err = _hidl_data.readInt32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_input_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*input), &_hidl_input_parent,  const_cast<const void**>(reinterpret_cast<void **>(&input)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::QueueBufferInput &>(*input),
            _hidl_data,
            _hidl_input_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::queueBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)input);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "queueBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->queueBuffer(slot, *input, [&](const auto &_hidl_out_status, const auto &_hidl_out_output) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("queueBuffer: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_output_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_output, sizeof(_hidl_out_output), &_hidl__hidl_out_output_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_output,
                _hidl_reply,
                _hidl__hidl_out_output_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_output);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "queueBuffer", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("queueBuffer: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_cancelBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t slot;
    ::android::hardware::hidl_handle fence;

    _hidl_err = _hidl_data.readInt32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    const native_handle_t *fence_ptr;

    _hidl_err = _hidl_data.readNullableNativeHandleNoDup(&fence_ptr);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    fence = fence_ptr;
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::cancelBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&fence);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "cancelBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_status = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->cancelBuffer(slot, fence);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "cancelBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_query(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t what;

    _hidl_err = _hidl_data.readInt32(&what);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::query::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&what);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "query", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->query(what, [&](const auto &_hidl_out_result, const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("query: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_result);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_value);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_result);
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "query", &_hidl_args);
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

::android::status_t BnHwGraphicBufferProducer::_hidl_connect(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::sp<::android::hardware::graphics::bufferqueue::V1_0::IProducerListener> listener;
    int32_t api;
    bool producerControlledByApp;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        listener = ::android::hardware::fromBinder<::android::hardware::graphics::bufferqueue::V1_0::IProducerListener,::android::hardware::graphics::bufferqueue::V1_0::BpHwProducerListener,::android::hardware::graphics::bufferqueue::V1_0::BnHwProducerListener>(_hidl_binder);
    }

    _hidl_err = _hidl_data.readInt32(&api);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&producerControlledByApp);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::connect::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&listener);
        _hidl_args.push_back((void *)&api);
        _hidl_args.push_back((void *)&producerControlledByApp);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "connect", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->connect(listener, api, producerControlledByApp, [&](const auto &_hidl_out_status, const auto &_hidl_out_output) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("connect: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_output_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_output, sizeof(_hidl_out_output), &_hidl__hidl_out_output_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_output,
                _hidl_reply,
                _hidl__hidl_out_output_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_output);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "connect", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("connect: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_disconnect(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t api;
    ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer::DisconnectMode mode;

    _hidl_err = _hidl_data.readInt32(&api);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&mode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::disconnect::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&api);
        _hidl_args.push_back((void *)&mode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "disconnect", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_status = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->disconnect(api, mode);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "disconnect", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_setSidebandStream(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::hidl_handle stream;

    const native_handle_t *stream_ptr;

    _hidl_err = _hidl_data.readNullableNativeHandleNoDup(&stream_ptr);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    stream = stream_ptr;
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::setSidebandStream::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&stream);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setSidebandStream", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_status = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->setSidebandStream(stream);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setSidebandStream", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_allocateBuffers(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t width;
    uint32_t height;
    ::android::hardware::graphics::common::V1_0::PixelFormat format;
    uint32_t usage;

    _hidl_err = _hidl_data.readUint32(&width);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&height);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&format);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&usage);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::allocateBuffers::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&width);
        _hidl_args.push_back((void *)&height);
        _hidl_args.push_back((void *)&format);
        _hidl_args.push_back((void *)&usage);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "allocateBuffers", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->allocateBuffers(width, height, format, usage);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "allocateBuffers", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_allowAllocation(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    bool allow;

    _hidl_err = _hidl_data.readBool(&allow);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::allowAllocation::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allow);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "allowAllocation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_status = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->allowAllocation(allow);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "allowAllocation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_setGenerationNumber(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t generationNumber;

    _hidl_err = _hidl_data.readUint32(&generationNumber);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::setGenerationNumber::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&generationNumber);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setGenerationNumber", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_status = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->setGenerationNumber(generationNumber);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setGenerationNumber", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_getConsumerName(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::getConsumerName::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getConsumerName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->getConsumerName([&](const auto &_hidl_out_name) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getConsumerName: _hidl_cb called a second time, but must be called once.");
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
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getConsumerName", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getConsumerName: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_setSharedBufferMode(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    bool sharedBufferMode;

    _hidl_err = _hidl_data.readBool(&sharedBufferMode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::setSharedBufferMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sharedBufferMode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setSharedBufferMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_status = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->setSharedBufferMode(sharedBufferMode);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setSharedBufferMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_setAutoRefresh(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    bool autoRefresh;

    _hidl_err = _hidl_data.readBool(&autoRefresh);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::setAutoRefresh::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&autoRefresh);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setAutoRefresh", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_status = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->setAutoRefresh(autoRefresh);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setAutoRefresh", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_setDequeueTimeout(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int64_t timeoutNs;

    _hidl_err = _hidl_data.readInt64(&timeoutNs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::setDequeueTimeout::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&timeoutNs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setDequeueTimeout", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_status = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->setDequeueTimeout(timeoutNs);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "setDequeueTimeout", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_getLastQueuedBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::getLastQueuedBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getLastQueuedBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->getLastQueuedBuffer([&](const auto &_hidl_out_status, const auto &_hidl_out_buffer, const auto &_hidl_out_fence, const auto &_hidl_out_transformMatrix) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getLastQueuedBuffer: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_buffer_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_buffer, sizeof(_hidl_out_buffer), &_hidl__hidl_out_buffer_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_buffer,
                _hidl_reply,
                _hidl__hidl_out_buffer_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeNativeHandleNoDup(_hidl_out_fence);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_transformMatrix_parent;

        _hidl_err = _hidl_reply->writeBuffer(_hidl_out_transformMatrix.data(), 16 * sizeof(float), &_hidl__hidl_out_transformMatrix_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_buffer);
            _hidl_args.push_back((void *)&_hidl_out_fence);
            _hidl_args.push_back((void *)&_hidl_out_transformMatrix);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getLastQueuedBuffer", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getLastQueuedBuffer: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_getFrameTimestamps(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::getFrameTimestamps::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getFrameTimestamps", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->getFrameTimestamps([&](const auto &_hidl_out_timeStamps) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getFrameTimestamps: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_timeStamps_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_timeStamps, sizeof(_hidl_out_timeStamps), &_hidl__hidl_out_timeStamps_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_timeStamps,
                _hidl_reply,
                _hidl__hidl_out_timeStamps_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_timeStamps);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getFrameTimestamps", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getFrameTimestamps: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwGraphicBufferProducer::_hidl_getUniqueId(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGraphicBufferProducer::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGraphicBufferProducer::getUniqueId::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getUniqueId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGraphicBufferProducer*>(_hidl_this->getImpl().get())->getUniqueId([&](const auto &_hidl_out_status, const auto &_hidl_out_outId) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getUniqueId: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint64(_hidl_out_outId);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_outId);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.bufferqueue", "1.0", "IGraphicBufferProducer", "getUniqueId", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getUniqueId: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwGraphicBufferProducer::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwGraphicBufferProducer::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwGraphicBufferProducer::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* requestBuffer */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_requestBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* setMaxDequeuedBufferCount */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_setMaxDequeuedBufferCount(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* setAsyncMode */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_setAsyncMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* dequeueBuffer */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_dequeueBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* detachBuffer */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_detachBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* detachNextBuffer */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_detachNextBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* attachBuffer */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_attachBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* queueBuffer */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_queueBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* cancelBuffer */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_cancelBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* query */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_query(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* connect */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_connect(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* disconnect */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_disconnect(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* setSidebandStream */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_setSidebandStream(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* allocateBuffers */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_allocateBuffers(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* allowAllocation */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_allowAllocation(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* setGenerationNumber */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_setGenerationNumber(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* getConsumerName */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_getConsumerName(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* setSharedBufferMode */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_setSharedBufferMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 19 /* setAutoRefresh */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_setAutoRefresh(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 20 /* setDequeueTimeout */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_setDequeueTimeout(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 21 /* getLastQueuedBuffer */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_getLastQueuedBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 22 /* getFrameTimestamps */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_getFrameTimestamps(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 23 /* getUniqueId */:
        {
            _hidl_err = ::android::hardware::graphics::bufferqueue::V1_0::BnHwGraphicBufferProducer::_hidl_getUniqueId(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsGraphicBufferProducer::BsGraphicBufferProducer(const ::android::sp<::android::hardware::graphics::bufferqueue::V1_0::IGraphicBufferProducer> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.graphics.bufferqueue@1.0", "IGraphicBufferProducer"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsGraphicBufferProducer::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IGraphicBufferProducer> IGraphicBufferProducer::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwGraphicBufferProducer>(serviceName, false, getStub);
}

::android::sp<IGraphicBufferProducer> IGraphicBufferProducer::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwGraphicBufferProducer>(serviceName, true, getStub);
}

::android::status_t IGraphicBufferProducer::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IGraphicBufferProducer::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.graphics.bufferqueue@1.0::IGraphicBufferProducer",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace bufferqueue
}  // namespace graphics
}  // namespace hardware
}  // namespace android
