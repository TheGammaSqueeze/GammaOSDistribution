#define LOG_TAG "android.hardware.renderscript@1.0::Context"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/renderscript/1.0/BpHwContext.h>
#include <android/hardware/renderscript/1.0/BnHwContext.h>
#include <android/hardware/renderscript/1.0/BsContext.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace renderscript {
namespace V1_0 {

const char* IContext::descriptor("android.hardware.renderscript@1.0::IContext");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IContext::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwContext(static_cast<IContext *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IContext::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsContext(static_cast<IContext *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IContext::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IContext::descriptor);
}

// Methods from ::android::hardware::renderscript::V1_0::IContext follow.
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::allocationAdapterCreate(uint64_t type, uint64_t baseAlloc)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationAdapterOffset(uint64_t alloc, const ::android::hardware::hidl_vec<uint32_t>& offsets)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::allocationGetType(uint64_t allocation)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::allocationCreateTyped(uint64_t type, ::android::hardware::renderscript::V1_0::AllocationMipmapControl mips, ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::AllocationUsageType> usage, void* ptr)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::allocationCreateFromBitmap(uint64_t type, ::android::hardware::renderscript::V1_0::AllocationMipmapControl mips, const ::android::hardware::hidl_vec<uint8_t>& bitmap, ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::AllocationUsageType> usage)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::allocationCubeCreateFromBitmap(uint64_t type, ::android::hardware::renderscript::V1_0::AllocationMipmapControl mips, const ::android::hardware::hidl_vec<uint8_t>& bitmap, ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::AllocationUsageType> usage)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::allocationGetNativeWindow(uint64_t allocation)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationSetNativeWindow(uint64_t allocation, uint64_t nativewindow)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationSetupBufferQueue(uint64_t alloc, uint32_t numBuffer)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationShareBufferQueue(uint64_t baseAlloc, uint64_t subAlloc)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationCopyToBitmap(uint64_t allocation, void* data, uint64_t sizeBytes)
// no default implementation for: ::android::hardware::Return<void> IContext::allocation1DWrite(uint64_t allocation, uint32_t offset, uint32_t lod, uint32_t count, const ::android::hardware::hidl_vec<uint8_t>& data)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationElementWrite(uint64_t allocation, uint32_t x, uint32_t y, uint32_t z, uint32_t lod, const ::android::hardware::hidl_vec<uint8_t>& data, uint64_t compIdx)
// no default implementation for: ::android::hardware::Return<void> IContext::allocation2DWrite(uint64_t allocation, uint32_t xoff, uint32_t yoff, uint32_t lod, ::android::hardware::renderscript::V1_0::AllocationCubemapFace face, uint32_t w, uint32_t h, const ::android::hardware::hidl_vec<uint8_t>& data, uint64_t stride)
// no default implementation for: ::android::hardware::Return<void> IContext::allocation3DWrite(uint64_t allocation, uint32_t xoff, uint32_t yoff, uint32_t zoff, uint32_t lod, uint32_t w, uint32_t h, uint32_t d, const ::android::hardware::hidl_vec<uint8_t>& data, uint64_t stride)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationGenerateMipmaps(uint64_t allocation)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationRead(uint64_t allocation, void* data, uint64_t sizeBytes)
// no default implementation for: ::android::hardware::Return<void> IContext::allocation1DRead(uint64_t allocation, uint32_t xoff, uint32_t lod, uint32_t count, void* data, uint64_t sizeBytes)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationElementRead(uint64_t allocation, uint32_t x, uint32_t y, uint32_t z, uint32_t lod, void* data, uint64_t sizeBytes, uint64_t compIdx)
// no default implementation for: ::android::hardware::Return<void> IContext::allocation2DRead(uint64_t allocation, uint32_t xoff, uint32_t yoff, uint32_t lod, ::android::hardware::renderscript::V1_0::AllocationCubemapFace face, uint32_t w, uint32_t h, void* data, uint64_t sizeBytes, uint64_t stride)
// no default implementation for: ::android::hardware::Return<void> IContext::allocation3DRead(uint64_t allocation, uint32_t xoff, uint32_t yoff, uint32_t zoff, uint32_t lod, uint32_t w, uint32_t h, uint32_t d, void* data, uint64_t sizeBytes, uint64_t stride)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationSyncAll(uint64_t allocation, ::android::hardware::renderscript::V1_0::AllocationUsageType usageType)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationResize1D(uint64_t allocation, uint32_t dimX)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationCopy2DRange(uint64_t dstAlloc, uint32_t dstXoff, uint32_t dstYoff, uint32_t dstMip, ::android::hardware::renderscript::V1_0::AllocationCubemapFace dstFace, uint32_t width, uint32_t height, uint64_t srcAlloc, uint32_t srcXoff, uint32_t srcYoff, uint32_t srcMip, ::android::hardware::renderscript::V1_0::AllocationCubemapFace srcFace)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationCopy3DRange(uint64_t dstAlloc, uint32_t dstXoff, uint32_t dstYoff, uint32_t dstZoff, uint32_t dstMip, uint32_t width, uint32_t height, uint32_t depth, uint64_t srcAlloc, uint32_t srcXoff, uint32_t srcYoff, uint32_t srcZoff, uint32_t srcMip)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationIoSend(uint64_t allocation)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationIoReceive(uint64_t allocation)
// no default implementation for: ::android::hardware::Return<void> IContext::allocationGetPointer(uint64_t allocation, uint32_t lod, ::android::hardware::renderscript::V1_0::AllocationCubemapFace face, uint32_t z, allocationGetPointer_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IContext::elementGetNativeMetadata(uint64_t element, elementGetNativeMetadata_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IContext::elementGetSubElements(uint64_t element, uint64_t numSubElem, elementGetSubElements_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::elementCreate(::android::hardware::renderscript::V1_0::DataType dt, ::android::hardware::renderscript::V1_0::DataKind dk, bool norm, uint32_t size)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::elementComplexCreate(const ::android::hardware::hidl_vec<uint64_t>& einsPtr, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& names, const ::android::hardware::hidl_vec<uint64_t>& arraySizesPtr)
// no default implementation for: ::android::hardware::Return<void> IContext::typeGetNativeMetadata(uint64_t type, typeGetNativeMetadata_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::typeCreate(uint64_t element, uint32_t dimX, uint32_t dimY, uint32_t dimZ, bool mipmaps, bool faces, ::android::hardware::renderscript::V1_0::YuvFormat yuv)
// no default implementation for: ::android::hardware::Return<void> IContext::contextDestroy()
// no default implementation for: ::android::hardware::Return<void> IContext::contextGetMessage(void* data, uint64_t size, contextGetMessage_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IContext::contextPeekMessage(contextPeekMessage_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IContext::contextSendMessage(uint32_t id, const ::android::hardware::hidl_vec<uint8_t>& data)
// no default implementation for: ::android::hardware::Return<void> IContext::contextInitToClient()
// no default implementation for: ::android::hardware::Return<void> IContext::contextDeinitToClient()
// no default implementation for: ::android::hardware::Return<void> IContext::contextFinish()
// no default implementation for: ::android::hardware::Return<void> IContext::contextLog()
// no default implementation for: ::android::hardware::Return<void> IContext::contextSetCacheDir(const ::android::hardware::hidl_string& cacheDir)
// no default implementation for: ::android::hardware::Return<void> IContext::contextSetPriority(::android::hardware::renderscript::V1_0::ThreadPriorities priority)
// no default implementation for: ::android::hardware::Return<void> IContext::assignName(uint64_t obj, const ::android::hardware::hidl_string& name)
// no default implementation for: ::android::hardware::Return<void> IContext::getName(uint64_t obj, getName_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::closureCreate(uint64_t kernelID, uint64_t returnValue, const ::android::hardware::hidl_vec<uint64_t>& fieldIDS, const ::android::hardware::hidl_vec<int64_t>& values, const ::android::hardware::hidl_vec<int32_t>& sizes, const ::android::hardware::hidl_vec<uint64_t>& depClosures, const ::android::hardware::hidl_vec<uint64_t>& depFieldIDS)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::invokeClosureCreate(uint64_t invokeID, const ::android::hardware::hidl_vec<uint8_t>& params, const ::android::hardware::hidl_vec<uint64_t>& fieldIDS, const ::android::hardware::hidl_vec<int64_t>& values, const ::android::hardware::hidl_vec<int32_t>& sizes)
// no default implementation for: ::android::hardware::Return<void> IContext::closureSetArg(uint64_t closure, uint32_t index, void* value, int32_t size)
// no default implementation for: ::android::hardware::Return<void> IContext::closureSetGlobal(uint64_t closure, uint64_t fieldID, int64_t value, int32_t size)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::scriptKernelIDCreate(uint64_t script, int32_t slot, ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::MetadataSignatureBitval> sig)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::scriptInvokeIDCreate(uint64_t script, int32_t slot)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::scriptFieldIDCreate(uint64_t script, int32_t slot)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::scriptGroupCreate(const ::android::hardware::hidl_vec<uint64_t>& kernels, const ::android::hardware::hidl_vec<uint64_t>& srcK, const ::android::hardware::hidl_vec<uint64_t>& dstK, const ::android::hardware::hidl_vec<uint64_t>& dstF, const ::android::hardware::hidl_vec<uint64_t>& types)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::scriptGroup2Create(const ::android::hardware::hidl_string& name, const ::android::hardware::hidl_string& cacheDir, const ::android::hardware::hidl_vec<uint64_t>& closures)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptGroupSetOutput(uint64_t sg, uint64_t kid, uint64_t alloc)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptGroupSetInput(uint64_t sg, uint64_t kid, uint64_t alloc)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptGroupExecute(uint64_t sg)
// no default implementation for: ::android::hardware::Return<void> IContext::objDestroy(uint64_t obj)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::samplerCreate(::android::hardware::renderscript::V1_0::SamplerValue magFilter, ::android::hardware::renderscript::V1_0::SamplerValue minFilter, ::android::hardware::renderscript::V1_0::SamplerValue wrapS, ::android::hardware::renderscript::V1_0::SamplerValue wrapT, ::android::hardware::renderscript::V1_0::SamplerValue wrapR, float aniso)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptBindAllocation(uint64_t script, uint64_t allocation, uint32_t slot)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptSetTimeZone(uint64_t script, const ::android::hardware::hidl_string& timeZone)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptInvoke(uint64_t vs, uint32_t slot)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptInvokeV(uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint8_t>& data)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptForEach(uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint64_t>& vains, uint64_t vaout, const ::android::hardware::hidl_vec<uint8_t>& params, void* sc)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptReduce(uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint64_t>& vains, uint64_t vaout, void* sc)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptSetVarI(uint64_t vs, uint32_t slot, int32_t value)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptSetVarObj(uint64_t vs, uint32_t slot, uint64_t obj)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptSetVarJ(uint64_t vs, uint32_t slot, int64_t value)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptSetVarF(uint64_t vs, uint32_t slot, float value)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptSetVarD(uint64_t vs, uint32_t slot, double value)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptSetVarV(uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint8_t>& data)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptGetVarV(uint64_t vs, uint32_t slot, uint64_t len, scriptGetVarV_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IContext::scriptSetVarVE(uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint8_t>& data, uint64_t ve, const ::android::hardware::hidl_vec<uint32_t>& dims)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::scriptCCreate(const ::android::hardware::hidl_string& resName, const ::android::hardware::hidl_string& cacheDir, const ::android::hardware::hidl_vec<uint8_t>& text)
// no default implementation for: ::android::hardware::Return<uint64_t> IContext::scriptIntrinsicCreate(::android::hardware::renderscript::V1_0::ScriptIntrinsicID id, uint64_t elem)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IContext::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::renderscript::V1_0::IContext::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IContext::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IContext::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::renderscript::V1_0::IContext::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IContext::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){105,131,162,202,254,57,213,197,125,253,193,116,48,85,251,15,117,122,13,248,199,142,0,66,61,94,24,16,131,105,39,225} /* 6983a2cafe39d5c57dfdc1743055fb0f757a0df8c78e00423d5e1810836927e1 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IContext::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IContext::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IContext::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IContext::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IContext::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IContext::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::renderscript::V1_0::IContext>> IContext::castFrom(const ::android::sp<::android::hardware::renderscript::V1_0::IContext>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::renderscript::V1_0::IContext>> IContext::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IContext, ::android::hidl::base::V1_0::IBase, BpHwContext>(
            parent, "android.hardware.renderscript@1.0::IContext", emitError);
}

BpHwContext::BpHwContext(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IContext>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.renderscript@1.0", "IContext") {
}

void BpHwContext::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IContext>::onLastStrongRef(id);
}
// Methods from ::android::hardware::renderscript::V1_0::IContext follow.
::android::hardware::Return<uint64_t> BpHwContext::_hidl_allocationAdapterCreate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t type, uint64_t baseAlloc) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationAdapterCreate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&baseAlloc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationAdapterCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_subAlloc;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(baseAlloc);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* allocationAdapterCreate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_subAlloc);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_subAlloc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationAdapterCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_subAlloc);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationAdapterOffset(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t alloc, const ::android::hardware::hidl_vec<uint32_t>& offsets) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationAdapterOffset::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&alloc);
        _hidl_args.push_back((void *)&offsets);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationAdapterOffset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(alloc);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_offsets_parent;

    _hidl_err = _hidl_data.writeBuffer(&offsets, sizeof(offsets), &_hidl_offsets_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_offsets_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            offsets,
            &_hidl_data,
            _hidl_offsets_parent,
            0 /* parentOffset */, &_hidl_offsets_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* allocationAdapterOffset */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationAdapterOffset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_allocationGetType(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationGetType::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationGetType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_type;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* allocationGetType */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_type);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationGetType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_type);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_allocationCreateTyped(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t type, ::android::hardware::renderscript::V1_0::AllocationMipmapControl mips, ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::AllocationUsageType> usage, void* ptr) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationCreateTyped::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&mips);
        _hidl_args.push_back((void *)&usage);
        _hidl_args.push_back((void *)&ptr);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationCreateTyped", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_allocation;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)mips);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)usage);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)ptr;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* allocationCreateTyped */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationCreateTyped", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_allocation);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_allocationCreateFromBitmap(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t type, ::android::hardware::renderscript::V1_0::AllocationMipmapControl mips, const ::android::hardware::hidl_vec<uint8_t>& bitmap, ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::AllocationUsageType> usage) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationCreateFromBitmap::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&mips);
        _hidl_args.push_back((void *)&bitmap);
        _hidl_args.push_back((void *)&usage);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationCreateFromBitmap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_allocation;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)mips);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_bitmap_parent;

    _hidl_err = _hidl_data.writeBuffer(&bitmap, sizeof(bitmap), &_hidl_bitmap_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_bitmap_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            bitmap,
            &_hidl_data,
            _hidl_bitmap_parent,
            0 /* parentOffset */, &_hidl_bitmap_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)usage);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* allocationCreateFromBitmap */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationCreateFromBitmap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_allocation);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_allocationCubeCreateFromBitmap(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t type, ::android::hardware::renderscript::V1_0::AllocationMipmapControl mips, const ::android::hardware::hidl_vec<uint8_t>& bitmap, ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::AllocationUsageType> usage) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationCubeCreateFromBitmap::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&mips);
        _hidl_args.push_back((void *)&bitmap);
        _hidl_args.push_back((void *)&usage);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationCubeCreateFromBitmap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_allocation;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)mips);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_bitmap_parent;

    _hidl_err = _hidl_data.writeBuffer(&bitmap, sizeof(bitmap), &_hidl_bitmap_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_bitmap_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            bitmap,
            &_hidl_data,
            _hidl_bitmap_parent,
            0 /* parentOffset */, &_hidl_bitmap_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)usage);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* allocationCubeCreateFromBitmap */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationCubeCreateFromBitmap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_allocation);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_allocationGetNativeWindow(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationGetNativeWindow::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationGetNativeWindow", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_nativeWindow;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* allocationGetNativeWindow */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_nativeWindow);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_nativeWindow);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationGetNativeWindow", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_nativeWindow);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationSetNativeWindow(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation, uint64_t nativewindow) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationSetNativeWindow::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&nativewindow);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationSetNativeWindow", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(nativewindow);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* allocationSetNativeWindow */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationSetNativeWindow", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationSetupBufferQueue(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t alloc, uint32_t numBuffer) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationSetupBufferQueue::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&alloc);
        _hidl_args.push_back((void *)&numBuffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationSetupBufferQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(alloc);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(numBuffer);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* allocationSetupBufferQueue */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationSetupBufferQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationShareBufferQueue(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t baseAlloc, uint64_t subAlloc) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationShareBufferQueue::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&baseAlloc);
        _hidl_args.push_back((void *)&subAlloc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationShareBufferQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(baseAlloc);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(subAlloc);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* allocationShareBufferQueue */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationShareBufferQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationCopyToBitmap(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation, void* data, uint64_t sizeBytes) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationCopyToBitmap::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&sizeBytes);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationCopyToBitmap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)data;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(sizeBytes);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* allocationCopyToBitmap */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationCopyToBitmap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocation1DWrite(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation, uint32_t offset, uint32_t lod, uint32_t count, const ::android::hardware::hidl_vec<uint8_t>& data) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocation1DWrite::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&offset);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&count);
        _hidl_args.push_back((void *)&data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocation1DWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(offset);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(lod);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(count);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.writeBuffer(&data, sizeof(data), &_hidl_data_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            data,
            &_hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* allocation1DWrite */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocation1DWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationElementWrite(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation, uint32_t x, uint32_t y, uint32_t z, uint32_t lod, const ::android::hardware::hidl_vec<uint8_t>& data, uint64_t compIdx) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationElementWrite::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&x);
        _hidl_args.push_back((void *)&y);
        _hidl_args.push_back((void *)&z);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&compIdx);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationElementWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(x);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(y);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(z);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(lod);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.writeBuffer(&data, sizeof(data), &_hidl_data_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            data,
            &_hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(compIdx);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* allocationElementWrite */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationElementWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocation2DWrite(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation, uint32_t xoff, uint32_t yoff, uint32_t lod, ::android::hardware::renderscript::V1_0::AllocationCubemapFace face, uint32_t w, uint32_t h, const ::android::hardware::hidl_vec<uint8_t>& data, uint64_t stride) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocation2DWrite::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&xoff);
        _hidl_args.push_back((void *)&yoff);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&face);
        _hidl_args.push_back((void *)&w);
        _hidl_args.push_back((void *)&h);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&stride);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocation2DWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(xoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(yoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(lod);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)face);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(w);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(h);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.writeBuffer(&data, sizeof(data), &_hidl_data_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            data,
            &_hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(stride);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(14 /* allocation2DWrite */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocation2DWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocation3DWrite(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation, uint32_t xoff, uint32_t yoff, uint32_t zoff, uint32_t lod, uint32_t w, uint32_t h, uint32_t d, const ::android::hardware::hidl_vec<uint8_t>& data, uint64_t stride) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocation3DWrite::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&xoff);
        _hidl_args.push_back((void *)&yoff);
        _hidl_args.push_back((void *)&zoff);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&w);
        _hidl_args.push_back((void *)&h);
        _hidl_args.push_back((void *)&d);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&stride);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocation3DWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(xoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(yoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(zoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(lod);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(w);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(h);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(d);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.writeBuffer(&data, sizeof(data), &_hidl_data_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            data,
            &_hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(stride);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(15 /* allocation3DWrite */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocation3DWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationGenerateMipmaps(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationGenerateMipmaps::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationGenerateMipmaps", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(16 /* allocationGenerateMipmaps */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationGenerateMipmaps", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationRead(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation, void* data, uint64_t sizeBytes) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationRead::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&sizeBytes);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)data;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(sizeBytes);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(17 /* allocationRead */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocation1DRead(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation, uint32_t xoff, uint32_t lod, uint32_t count, void* data, uint64_t sizeBytes) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocation1DRead::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&xoff);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&count);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&sizeBytes);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocation1DRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(xoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(lod);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(count);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)data;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(sizeBytes);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(18 /* allocation1DRead */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocation1DRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationElementRead(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation, uint32_t x, uint32_t y, uint32_t z, uint32_t lod, void* data, uint64_t sizeBytes, uint64_t compIdx) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationElementRead::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&x);
        _hidl_args.push_back((void *)&y);
        _hidl_args.push_back((void *)&z);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&sizeBytes);
        _hidl_args.push_back((void *)&compIdx);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationElementRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(x);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(y);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(z);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(lod);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)data;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(sizeBytes);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(compIdx);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(19 /* allocationElementRead */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationElementRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocation2DRead(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation, uint32_t xoff, uint32_t yoff, uint32_t lod, ::android::hardware::renderscript::V1_0::AllocationCubemapFace face, uint32_t w, uint32_t h, void* data, uint64_t sizeBytes, uint64_t stride) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocation2DRead::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&xoff);
        _hidl_args.push_back((void *)&yoff);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&face);
        _hidl_args.push_back((void *)&w);
        _hidl_args.push_back((void *)&h);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&sizeBytes);
        _hidl_args.push_back((void *)&stride);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocation2DRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(xoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(yoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(lod);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)face);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(w);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(h);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)data;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(sizeBytes);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(stride);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(20 /* allocation2DRead */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocation2DRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocation3DRead(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation, uint32_t xoff, uint32_t yoff, uint32_t zoff, uint32_t lod, uint32_t w, uint32_t h, uint32_t d, void* data, uint64_t sizeBytes, uint64_t stride) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocation3DRead::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&xoff);
        _hidl_args.push_back((void *)&yoff);
        _hidl_args.push_back((void *)&zoff);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&w);
        _hidl_args.push_back((void *)&h);
        _hidl_args.push_back((void *)&d);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&sizeBytes);
        _hidl_args.push_back((void *)&stride);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocation3DRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(xoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(yoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(zoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(lod);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(w);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(h);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(d);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)data;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(sizeBytes);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(stride);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(21 /* allocation3DRead */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocation3DRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationSyncAll(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation, ::android::hardware::renderscript::V1_0::AllocationUsageType usageType) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationSyncAll::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&usageType);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationSyncAll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)usageType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(22 /* allocationSyncAll */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationSyncAll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationResize1D(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation, uint32_t dimX) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationResize1D::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&dimX);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationResize1D", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(dimX);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(23 /* allocationResize1D */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationResize1D", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationCopy2DRange(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t dstAlloc, uint32_t dstXoff, uint32_t dstYoff, uint32_t dstMip, ::android::hardware::renderscript::V1_0::AllocationCubemapFace dstFace, uint32_t width, uint32_t height, uint64_t srcAlloc, uint32_t srcXoff, uint32_t srcYoff, uint32_t srcMip, ::android::hardware::renderscript::V1_0::AllocationCubemapFace srcFace) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationCopy2DRange::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&dstAlloc);
        _hidl_args.push_back((void *)&dstXoff);
        _hidl_args.push_back((void *)&dstYoff);
        _hidl_args.push_back((void *)&dstMip);
        _hidl_args.push_back((void *)&dstFace);
        _hidl_args.push_back((void *)&width);
        _hidl_args.push_back((void *)&height);
        _hidl_args.push_back((void *)&srcAlloc);
        _hidl_args.push_back((void *)&srcXoff);
        _hidl_args.push_back((void *)&srcYoff);
        _hidl_args.push_back((void *)&srcMip);
        _hidl_args.push_back((void *)&srcFace);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationCopy2DRange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(dstAlloc);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(dstXoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(dstYoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(dstMip);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)dstFace);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(width);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(height);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(srcAlloc);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(srcXoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(srcYoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(srcMip);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)srcFace);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(24 /* allocationCopy2DRange */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationCopy2DRange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationCopy3DRange(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t dstAlloc, uint32_t dstXoff, uint32_t dstYoff, uint32_t dstZoff, uint32_t dstMip, uint32_t width, uint32_t height, uint32_t depth, uint64_t srcAlloc, uint32_t srcXoff, uint32_t srcYoff, uint32_t srcZoff, uint32_t srcMip) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationCopy3DRange::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&dstAlloc);
        _hidl_args.push_back((void *)&dstXoff);
        _hidl_args.push_back((void *)&dstYoff);
        _hidl_args.push_back((void *)&dstZoff);
        _hidl_args.push_back((void *)&dstMip);
        _hidl_args.push_back((void *)&width);
        _hidl_args.push_back((void *)&height);
        _hidl_args.push_back((void *)&depth);
        _hidl_args.push_back((void *)&srcAlloc);
        _hidl_args.push_back((void *)&srcXoff);
        _hidl_args.push_back((void *)&srcYoff);
        _hidl_args.push_back((void *)&srcZoff);
        _hidl_args.push_back((void *)&srcMip);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationCopy3DRange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(dstAlloc);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(dstXoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(dstYoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(dstZoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(dstMip);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(width);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(height);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(depth);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(srcAlloc);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(srcXoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(srcYoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(srcZoff);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(srcMip);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(25 /* allocationCopy3DRange */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationCopy3DRange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationIoSend(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationIoSend::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationIoSend", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(26 /* allocationIoSend */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationIoSend", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationIoReceive(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationIoReceive::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationIoReceive", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(27 /* allocationIoReceive */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationIoReceive", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_allocationGetPointer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t allocation, uint32_t lod, ::android::hardware::renderscript::V1_0::AllocationCubemapFace face, uint32_t z, allocationGetPointer_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::allocationGetPointer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&face);
        _hidl_args.push_back((void *)&z);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationGetPointer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(lod);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)face);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(z);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(28 /* allocationGetPointer */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        void* _hidl_out_dataPtr;
        uint64_t _hidl_out_stride;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        (void)_hidl_out_dataPtr;
        LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint64(&_hidl_out_stride);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_dataPtr, _hidl_out_stride);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_dataPtr);
            _hidl_args.push_back((void *)&_hidl_out_stride);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationGetPointer", &_hidl_args);
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

::android::hardware::Return<void> BpHwContext::_hidl_elementGetNativeMetadata(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t element, elementGetNativeMetadata_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::elementGetNativeMetadata::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&element);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "elementGetNativeMetadata", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(element);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(29 /* elementGetNativeMetadata */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::hidl_vec<uint32_t>* _hidl_out_elemData;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_elemData_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_elemData), &_hidl__hidl_out_elemData_parent,  reinterpret_cast<const void **>(&_hidl_out_elemData));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_elemData_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint32_t> &>(*_hidl_out_elemData),
                _hidl_reply,
                _hidl__hidl_out_elemData_parent,
                0 /* parentOffset */, &_hidl__hidl_out_elemData_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_elemData);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_elemData);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "elementGetNativeMetadata", &_hidl_args);
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

::android::hardware::Return<void> BpHwContext::_hidl_elementGetSubElements(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t element, uint64_t numSubElem, elementGetSubElements_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::elementGetSubElements::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&element);
        _hidl_args.push_back((void *)&numSubElem);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "elementGetSubElements", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(element);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(numSubElem);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(30 /* elementGetSubElements */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::hidl_vec<uint64_t>* _hidl_out_ids;
        const ::android::hardware::hidl_vec<::android::hardware::hidl_string>* _hidl_out_names;
        const ::android::hardware::hidl_vec<uint64_t>* _hidl_out_arraySizes;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_ids_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_ids), &_hidl__hidl_out_ids_parent,  reinterpret_cast<const void **>(&_hidl_out_ids));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_ids_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint64_t> &>(*_hidl_out_ids),
                _hidl_reply,
                _hidl__hidl_out_ids_parent,
                0 /* parentOffset */, &_hidl__hidl_out_ids_child);

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_names_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_names), &_hidl__hidl_out_names_parent,  reinterpret_cast<const void **>(&_hidl_out_names));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_names_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(*_hidl_out_names),
                _hidl_reply,
                _hidl__hidl_out_names_parent,
                0 /* parentOffset */, &_hidl__hidl_out_names_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_names->size(); ++_hidl_index_0) {
            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_string &>((*_hidl_out_names)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_names_child,
                    _hidl_index_0 * sizeof(::android::hardware::hidl_string));

            if (_hidl_err != ::android::OK) { return; }

        }

        size_t _hidl__hidl_out_arraySizes_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_arraySizes), &_hidl__hidl_out_arraySizes_parent,  reinterpret_cast<const void **>(&_hidl_out_arraySizes));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_arraySizes_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint64_t> &>(*_hidl_out_arraySizes),
                _hidl_reply,
                _hidl__hidl_out_arraySizes_parent,
                0 /* parentOffset */, &_hidl__hidl_out_arraySizes_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_ids, *_hidl_out_names, *_hidl_out_arraySizes);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_ids);
            _hidl_args.push_back((void *)_hidl_out_names);
            _hidl_args.push_back((void *)_hidl_out_arraySizes);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "elementGetSubElements", &_hidl_args);
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

::android::hardware::Return<uint64_t> BpHwContext::_hidl_elementCreate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::renderscript::V1_0::DataType dt, ::android::hardware::renderscript::V1_0::DataKind dk, bool norm, uint32_t size) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::elementCreate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&dt);
        _hidl_args.push_back((void *)&dk);
        _hidl_args.push_back((void *)&norm);
        _hidl_args.push_back((void *)&size);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "elementCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_element;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)dt);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)dk);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(norm);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(size);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(31 /* elementCreate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_element);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_element);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "elementCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_element);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_elementComplexCreate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint64_t>& einsPtr, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& names, const ::android::hardware::hidl_vec<uint64_t>& arraySizesPtr) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::elementComplexCreate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&einsPtr);
        _hidl_args.push_back((void *)&names);
        _hidl_args.push_back((void *)&arraySizesPtr);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "elementComplexCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_element;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_einsPtr_parent;

    _hidl_err = _hidl_data.writeBuffer(&einsPtr, sizeof(einsPtr), &_hidl_einsPtr_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_einsPtr_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            einsPtr,
            &_hidl_data,
            _hidl_einsPtr_parent,
            0 /* parentOffset */, &_hidl_einsPtr_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_names_parent;

    _hidl_err = _hidl_data.writeBuffer(&names, sizeof(names), &_hidl_names_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_names_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            names,
            &_hidl_data,
            _hidl_names_parent,
            0 /* parentOffset */, &_hidl_names_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < names.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                names[_hidl_index_0],
                &_hidl_data,
                _hidl_names_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    size_t _hidl_arraySizesPtr_parent;

    _hidl_err = _hidl_data.writeBuffer(&arraySizesPtr, sizeof(arraySizesPtr), &_hidl_arraySizesPtr_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_arraySizesPtr_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            arraySizesPtr,
            &_hidl_data,
            _hidl_arraySizesPtr_parent,
            0 /* parentOffset */, &_hidl_arraySizesPtr_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(32 /* elementComplexCreate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_element);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_element);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "elementComplexCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_element);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_typeGetNativeMetadata(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t type, typeGetNativeMetadata_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::typeGetNativeMetadata::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "typeGetNativeMetadata", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(33 /* typeGetNativeMetadata */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::hidl_vec<uint64_t>* _hidl_out_metadata;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_metadata_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_metadata), &_hidl__hidl_out_metadata_parent,  reinterpret_cast<const void **>(&_hidl_out_metadata));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_metadata_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint64_t> &>(*_hidl_out_metadata),
                _hidl_reply,
                _hidl__hidl_out_metadata_parent,
                0 /* parentOffset */, &_hidl__hidl_out_metadata_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_metadata);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_metadata);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "typeGetNativeMetadata", &_hidl_args);
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

::android::hardware::Return<uint64_t> BpHwContext::_hidl_typeCreate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t element, uint32_t dimX, uint32_t dimY, uint32_t dimZ, bool mipmaps, bool faces, ::android::hardware::renderscript::V1_0::YuvFormat yuv) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::typeCreate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&element);
        _hidl_args.push_back((void *)&dimX);
        _hidl_args.push_back((void *)&dimY);
        _hidl_args.push_back((void *)&dimZ);
        _hidl_args.push_back((void *)&mipmaps);
        _hidl_args.push_back((void *)&faces);
        _hidl_args.push_back((void *)&yuv);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "typeCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_type;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(element);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(dimX);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(dimY);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(dimZ);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(mipmaps);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(faces);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)yuv);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(34 /* typeCreate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_type);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "typeCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_type);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_contextDestroy(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::contextDestroy::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextDestroy", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(35 /* contextDestroy */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextDestroy", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_contextGetMessage(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* data, uint64_t size, contextGetMessage_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::contextGetMessage::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&size);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextGetMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)data;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(size);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(36 /* contextGetMessage */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::renderscript::V1_0::MessageToClientType _hidl_out_messageType;
        uint64_t _hidl_out_receiveLen;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_messageType);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint64(&_hidl_out_receiveLen);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_messageType, _hidl_out_receiveLen);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_messageType);
            _hidl_args.push_back((void *)&_hidl_out_receiveLen);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextGetMessage", &_hidl_args);
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

::android::hardware::Return<void> BpHwContext::_hidl_contextPeekMessage(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, contextPeekMessage_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::contextPeekMessage::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextPeekMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(37 /* contextPeekMessage */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::renderscript::V1_0::MessageToClientType _hidl_out_messageType;
        uint64_t _hidl_out_receiveLen;
        uint32_t _hidl_out_subID;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_messageType);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint64(&_hidl_out_receiveLen);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_subID);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_messageType, _hidl_out_receiveLen, _hidl_out_subID);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_messageType);
            _hidl_args.push_back((void *)&_hidl_out_receiveLen);
            _hidl_args.push_back((void *)&_hidl_out_subID);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextPeekMessage", &_hidl_args);
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

::android::hardware::Return<void> BpHwContext::_hidl_contextSendMessage(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t id, const ::android::hardware::hidl_vec<uint8_t>& data) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::contextSendMessage::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextSendMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.writeBuffer(&data, sizeof(data), &_hidl_data_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            data,
            &_hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(38 /* contextSendMessage */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextSendMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_contextInitToClient(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::contextInitToClient::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextInitToClient", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(39 /* contextInitToClient */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextInitToClient", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_contextDeinitToClient(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::contextDeinitToClient::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextDeinitToClient", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(40 /* contextDeinitToClient */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextDeinitToClient", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_contextFinish(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::contextFinish::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextFinish", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(41 /* contextFinish */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextFinish", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_contextLog(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::contextLog::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextLog", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(42 /* contextLog */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextLog", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_contextSetCacheDir(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& cacheDir) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::contextSetCacheDir::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cacheDir);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextSetCacheDir", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_cacheDir_parent;

    _hidl_err = _hidl_data.writeBuffer(&cacheDir, sizeof(cacheDir), &_hidl_cacheDir_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            cacheDir,
            &_hidl_data,
            _hidl_cacheDir_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(43 /* contextSetCacheDir */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextSetCacheDir", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_contextSetPriority(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::renderscript::V1_0::ThreadPriorities priority) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::contextSetPriority::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&priority);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextSetPriority", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)priority);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(44 /* contextSetPriority */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextSetPriority", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_assignName(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t obj, const ::android::hardware::hidl_string& name) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::assignName::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&obj);
        _hidl_args.push_back((void *)&name);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "assignName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(obj);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_name_parent;

    _hidl_err = _hidl_data.writeBuffer(&name, sizeof(name), &_hidl_name_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            name,
            &_hidl_data,
            _hidl_name_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(45 /* assignName */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "assignName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_getName(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t obj, getName_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::getName::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&obj);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "getName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(obj);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(46 /* getName */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
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
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "getName", &_hidl_args);
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

::android::hardware::Return<uint64_t> BpHwContext::_hidl_closureCreate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t kernelID, uint64_t returnValue, const ::android::hardware::hidl_vec<uint64_t>& fieldIDS, const ::android::hardware::hidl_vec<int64_t>& values, const ::android::hardware::hidl_vec<int32_t>& sizes, const ::android::hardware::hidl_vec<uint64_t>& depClosures, const ::android::hardware::hidl_vec<uint64_t>& depFieldIDS) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::closureCreate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&kernelID);
        _hidl_args.push_back((void *)&returnValue);
        _hidl_args.push_back((void *)&fieldIDS);
        _hidl_args.push_back((void *)&values);
        _hidl_args.push_back((void *)&sizes);
        _hidl_args.push_back((void *)&depClosures);
        _hidl_args.push_back((void *)&depFieldIDS);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "closureCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_closure;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(kernelID);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(returnValue);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_fieldIDS_parent;

    _hidl_err = _hidl_data.writeBuffer(&fieldIDS, sizeof(fieldIDS), &_hidl_fieldIDS_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_fieldIDS_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            fieldIDS,
            &_hidl_data,
            _hidl_fieldIDS_parent,
            0 /* parentOffset */, &_hidl_fieldIDS_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_values_parent;

    _hidl_err = _hidl_data.writeBuffer(&values, sizeof(values), &_hidl_values_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            values,
            &_hidl_data,
            _hidl_values_parent,
            0 /* parentOffset */, &_hidl_values_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sizes_parent;

    _hidl_err = _hidl_data.writeBuffer(&sizes, sizeof(sizes), &_hidl_sizes_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sizes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sizes,
            &_hidl_data,
            _hidl_sizes_parent,
            0 /* parentOffset */, &_hidl_sizes_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_depClosures_parent;

    _hidl_err = _hidl_data.writeBuffer(&depClosures, sizeof(depClosures), &_hidl_depClosures_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_depClosures_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            depClosures,
            &_hidl_data,
            _hidl_depClosures_parent,
            0 /* parentOffset */, &_hidl_depClosures_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_depFieldIDS_parent;

    _hidl_err = _hidl_data.writeBuffer(&depFieldIDS, sizeof(depFieldIDS), &_hidl_depFieldIDS_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_depFieldIDS_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            depFieldIDS,
            &_hidl_data,
            _hidl_depFieldIDS_parent,
            0 /* parentOffset */, &_hidl_depFieldIDS_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(47 /* closureCreate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_closure);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_closure);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "closureCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_closure);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_invokeClosureCreate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t invokeID, const ::android::hardware::hidl_vec<uint8_t>& params, const ::android::hardware::hidl_vec<uint64_t>& fieldIDS, const ::android::hardware::hidl_vec<int64_t>& values, const ::android::hardware::hidl_vec<int32_t>& sizes) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::invokeClosureCreate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&invokeID);
        _hidl_args.push_back((void *)&params);
        _hidl_args.push_back((void *)&fieldIDS);
        _hidl_args.push_back((void *)&values);
        _hidl_args.push_back((void *)&sizes);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "invokeClosureCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_closure;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(invokeID);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_params_parent;

    _hidl_err = _hidl_data.writeBuffer(&params, sizeof(params), &_hidl_params_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_params_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            params,
            &_hidl_data,
            _hidl_params_parent,
            0 /* parentOffset */, &_hidl_params_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_fieldIDS_parent;

    _hidl_err = _hidl_data.writeBuffer(&fieldIDS, sizeof(fieldIDS), &_hidl_fieldIDS_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_fieldIDS_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            fieldIDS,
            &_hidl_data,
            _hidl_fieldIDS_parent,
            0 /* parentOffset */, &_hidl_fieldIDS_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_values_parent;

    _hidl_err = _hidl_data.writeBuffer(&values, sizeof(values), &_hidl_values_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            values,
            &_hidl_data,
            _hidl_values_parent,
            0 /* parentOffset */, &_hidl_values_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sizes_parent;

    _hidl_err = _hidl_data.writeBuffer(&sizes, sizeof(sizes), &_hidl_sizes_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sizes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sizes,
            &_hidl_data,
            _hidl_sizes_parent,
            0 /* parentOffset */, &_hidl_sizes_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(48 /* invokeClosureCreate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_closure);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_closure);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "invokeClosureCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_closure);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_closureSetArg(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t closure, uint32_t index, void* value, int32_t size) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::closureSetArg::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&closure);
        _hidl_args.push_back((void *)&index);
        _hidl_args.push_back((void *)&value);
        _hidl_args.push_back((void *)&size);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "closureSetArg", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(closure);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(index);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)value;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(size);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(49 /* closureSetArg */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "closureSetArg", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_closureSetGlobal(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t closure, uint64_t fieldID, int64_t value, int32_t size) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::closureSetGlobal::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&closure);
        _hidl_args.push_back((void *)&fieldID);
        _hidl_args.push_back((void *)&value);
        _hidl_args.push_back((void *)&size);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "closureSetGlobal", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(closure);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(fieldID);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt64(value);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(size);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(50 /* closureSetGlobal */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "closureSetGlobal", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_scriptKernelIDCreate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t script, int32_t slot, ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::MetadataSignatureBitval> sig) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptKernelIDCreate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&script);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&sig);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptKernelIDCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_scriptKernelID;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(script);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)sig);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(51 /* scriptKernelIDCreate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_scriptKernelID);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_scriptKernelID);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptKernelIDCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_scriptKernelID);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_scriptInvokeIDCreate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t script, int32_t slot) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptInvokeIDCreate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&script);
        _hidl_args.push_back((void *)&slot);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptInvokeIDCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_scriptInvokeID;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(script);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(52 /* scriptInvokeIDCreate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_scriptInvokeID);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_scriptInvokeID);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptInvokeIDCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_scriptInvokeID);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_scriptFieldIDCreate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t script, int32_t slot) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptFieldIDCreate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&script);
        _hidl_args.push_back((void *)&slot);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptFieldIDCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_scriptFieldID;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(script);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(53 /* scriptFieldIDCreate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_scriptFieldID);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_scriptFieldID);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptFieldIDCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_scriptFieldID);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_scriptGroupCreate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint64_t>& kernels, const ::android::hardware::hidl_vec<uint64_t>& srcK, const ::android::hardware::hidl_vec<uint64_t>& dstK, const ::android::hardware::hidl_vec<uint64_t>& dstF, const ::android::hardware::hidl_vec<uint64_t>& types) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptGroupCreate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&kernels);
        _hidl_args.push_back((void *)&srcK);
        _hidl_args.push_back((void *)&dstK);
        _hidl_args.push_back((void *)&dstF);
        _hidl_args.push_back((void *)&types);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_scriptGroup;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_kernels_parent;

    _hidl_err = _hidl_data.writeBuffer(&kernels, sizeof(kernels), &_hidl_kernels_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_kernels_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            kernels,
            &_hidl_data,
            _hidl_kernels_parent,
            0 /* parentOffset */, &_hidl_kernels_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_srcK_parent;

    _hidl_err = _hidl_data.writeBuffer(&srcK, sizeof(srcK), &_hidl_srcK_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_srcK_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            srcK,
            &_hidl_data,
            _hidl_srcK_parent,
            0 /* parentOffset */, &_hidl_srcK_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dstK_parent;

    _hidl_err = _hidl_data.writeBuffer(&dstK, sizeof(dstK), &_hidl_dstK_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dstK_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            dstK,
            &_hidl_data,
            _hidl_dstK_parent,
            0 /* parentOffset */, &_hidl_dstK_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dstF_parent;

    _hidl_err = _hidl_data.writeBuffer(&dstF, sizeof(dstF), &_hidl_dstF_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dstF_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            dstF,
            &_hidl_data,
            _hidl_dstF_parent,
            0 /* parentOffset */, &_hidl_dstF_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_types_parent;

    _hidl_err = _hidl_data.writeBuffer(&types, sizeof(types), &_hidl_types_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_types_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            types,
            &_hidl_data,
            _hidl_types_parent,
            0 /* parentOffset */, &_hidl_types_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(54 /* scriptGroupCreate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_scriptGroup);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_scriptGroup);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_scriptGroup);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_scriptGroup2Create(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& name, const ::android::hardware::hidl_string& cacheDir, const ::android::hardware::hidl_vec<uint64_t>& closures) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptGroup2Create::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&name);
        _hidl_args.push_back((void *)&cacheDir);
        _hidl_args.push_back((void *)&closures);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptGroup2Create", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_scriptGroup2;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_name_parent;

    _hidl_err = _hidl_data.writeBuffer(&name, sizeof(name), &_hidl_name_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            name,
            &_hidl_data,
            _hidl_name_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_cacheDir_parent;

    _hidl_err = _hidl_data.writeBuffer(&cacheDir, sizeof(cacheDir), &_hidl_cacheDir_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            cacheDir,
            &_hidl_data,
            _hidl_cacheDir_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_closures_parent;

    _hidl_err = _hidl_data.writeBuffer(&closures, sizeof(closures), &_hidl_closures_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_closures_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            closures,
            &_hidl_data,
            _hidl_closures_parent,
            0 /* parentOffset */, &_hidl_closures_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(55 /* scriptGroup2Create */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_scriptGroup2);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_scriptGroup2);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptGroup2Create", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_scriptGroup2);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptGroupSetOutput(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t sg, uint64_t kid, uint64_t alloc) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptGroupSetOutput::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sg);
        _hidl_args.push_back((void *)&kid);
        _hidl_args.push_back((void *)&alloc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupSetOutput", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(sg);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(kid);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(alloc);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(56 /* scriptGroupSetOutput */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupSetOutput", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptGroupSetInput(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t sg, uint64_t kid, uint64_t alloc) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptGroupSetInput::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sg);
        _hidl_args.push_back((void *)&kid);
        _hidl_args.push_back((void *)&alloc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupSetInput", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(sg);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(kid);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(alloc);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(57 /* scriptGroupSetInput */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupSetInput", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptGroupExecute(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t sg) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptGroupExecute::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupExecute", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(sg);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(58 /* scriptGroupExecute */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupExecute", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_objDestroy(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t obj) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::objDestroy::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&obj);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "objDestroy", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(obj);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(59 /* objDestroy */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "objDestroy", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_samplerCreate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::renderscript::V1_0::SamplerValue magFilter, ::android::hardware::renderscript::V1_0::SamplerValue minFilter, ::android::hardware::renderscript::V1_0::SamplerValue wrapS, ::android::hardware::renderscript::V1_0::SamplerValue wrapT, ::android::hardware::renderscript::V1_0::SamplerValue wrapR, float aniso) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::samplerCreate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&magFilter);
        _hidl_args.push_back((void *)&minFilter);
        _hidl_args.push_back((void *)&wrapS);
        _hidl_args.push_back((void *)&wrapT);
        _hidl_args.push_back((void *)&wrapR);
        _hidl_args.push_back((void *)&aniso);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "samplerCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_sampler;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)magFilter);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)minFilter);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)wrapS);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)wrapT);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)wrapR);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeFloat(aniso);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(60 /* samplerCreate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_sampler);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_sampler);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "samplerCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_sampler);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptBindAllocation(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t script, uint64_t allocation, uint32_t slot) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptBindAllocation::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&script);
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&slot);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptBindAllocation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(script);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(61 /* scriptBindAllocation */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptBindAllocation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptSetTimeZone(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t script, const ::android::hardware::hidl_string& timeZone) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptSetTimeZone::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&script);
        _hidl_args.push_back((void *)&timeZone);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetTimeZone", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(script);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_timeZone_parent;

    _hidl_err = _hidl_data.writeBuffer(&timeZone, sizeof(timeZone), &_hidl_timeZone_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            timeZone,
            &_hidl_data,
            _hidl_timeZone_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(62 /* scriptSetTimeZone */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetTimeZone", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptInvoke(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t vs, uint32_t slot) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptInvoke::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptInvoke", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(vs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(63 /* scriptInvoke */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptInvoke", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptInvokeV(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint8_t>& data) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptInvokeV::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptInvokeV", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(vs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.writeBuffer(&data, sizeof(data), &_hidl_data_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            data,
            &_hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(64 /* scriptInvokeV */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptInvokeV", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptForEach(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint64_t>& vains, uint64_t vaout, const ::android::hardware::hidl_vec<uint8_t>& params, void* sc) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptForEach::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&vains);
        _hidl_args.push_back((void *)&vaout);
        _hidl_args.push_back((void *)&params);
        _hidl_args.push_back((void *)&sc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptForEach", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(vs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_vains_parent;

    _hidl_err = _hidl_data.writeBuffer(&vains, sizeof(vains), &_hidl_vains_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_vains_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            vains,
            &_hidl_data,
            _hidl_vains_parent,
            0 /* parentOffset */, &_hidl_vains_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(vaout);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_params_parent;

    _hidl_err = _hidl_data.writeBuffer(&params, sizeof(params), &_hidl_params_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_params_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            params,
            &_hidl_data,
            _hidl_params_parent,
            0 /* parentOffset */, &_hidl_params_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)sc;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(65 /* scriptForEach */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptForEach", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptReduce(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint64_t>& vains, uint64_t vaout, void* sc) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptReduce::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&vains);
        _hidl_args.push_back((void *)&vaout);
        _hidl_args.push_back((void *)&sc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptReduce", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(vs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_vains_parent;

    _hidl_err = _hidl_data.writeBuffer(&vains, sizeof(vains), &_hidl_vains_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_vains_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            vains,
            &_hidl_data,
            _hidl_vains_parent,
            0 /* parentOffset */, &_hidl_vains_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(vaout);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    (void)sc;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(66 /* scriptReduce */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptReduce", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptSetVarI(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t vs, uint32_t slot, int32_t value) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptSetVarI::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&value);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarI", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(vs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(value);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(67 /* scriptSetVarI */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarI", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptSetVarObj(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t vs, uint32_t slot, uint64_t obj) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptSetVarObj::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&obj);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarObj", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(vs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(obj);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(68 /* scriptSetVarObj */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarObj", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptSetVarJ(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t vs, uint32_t slot, int64_t value) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptSetVarJ::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&value);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarJ", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(vs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt64(value);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(69 /* scriptSetVarJ */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarJ", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptSetVarF(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t vs, uint32_t slot, float value) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptSetVarF::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&value);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarF", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(vs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeFloat(value);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(70 /* scriptSetVarF */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarF", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptSetVarD(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t vs, uint32_t slot, double value) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptSetVarD::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&value);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarD", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(vs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeDouble(value);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(71 /* scriptSetVarD */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarD", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptSetVarV(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint8_t>& data) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptSetVarV::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarV", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(vs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.writeBuffer(&data, sizeof(data), &_hidl_data_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            data,
            &_hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(72 /* scriptSetVarV */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarV", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwContext::_hidl_scriptGetVarV(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t vs, uint32_t slot, uint64_t len, scriptGetVarV_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptGetVarV::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&len);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptGetVarV", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(vs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(len);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(73 /* scriptGetVarV */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_data;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_data_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_data), &_hidl__hidl_out_data_parent,  reinterpret_cast<const void **>(&_hidl_out_data));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_data_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_data),
                _hidl_reply,
                _hidl__hidl_out_data_parent,
                0 /* parentOffset */, &_hidl__hidl_out_data_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_data);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_data);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptGetVarV", &_hidl_args);
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

::android::hardware::Return<void> BpHwContext::_hidl_scriptSetVarVE(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint8_t>& data, uint64_t ve, const ::android::hardware::hidl_vec<uint32_t>& dims) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptSetVarVE::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&ve);
        _hidl_args.push_back((void *)&dims);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarVE", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(vs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(slot);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.writeBuffer(&data, sizeof(data), &_hidl_data_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            data,
            &_hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(ve);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dims_parent;

    _hidl_err = _hidl_data.writeBuffer(&dims, sizeof(dims), &_hidl_dims_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dims_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            dims,
            &_hidl_data,
            _hidl_dims_parent,
            0 /* parentOffset */, &_hidl_dims_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(74 /* scriptSetVarVE */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarVE", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_scriptCCreate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& resName, const ::android::hardware::hidl_string& cacheDir, const ::android::hardware::hidl_vec<uint8_t>& text) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptCCreate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&resName);
        _hidl_args.push_back((void *)&cacheDir);
        _hidl_args.push_back((void *)&text);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptCCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_script;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_resName_parent;

    _hidl_err = _hidl_data.writeBuffer(&resName, sizeof(resName), &_hidl_resName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            resName,
            &_hidl_data,
            _hidl_resName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_cacheDir_parent;

    _hidl_err = _hidl_data.writeBuffer(&cacheDir, sizeof(cacheDir), &_hidl_cacheDir_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            cacheDir,
            &_hidl_data,
            _hidl_cacheDir_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_text_parent;

    _hidl_err = _hidl_data.writeBuffer(&text, sizeof(text), &_hidl_text_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_text_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            text,
            &_hidl_data,
            _hidl_text_parent,
            0 /* parentOffset */, &_hidl_text_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(75 /* scriptCCreate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_script);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_script);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptCCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_script);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}

::android::hardware::Return<uint64_t> BpHwContext::_hidl_scriptIntrinsicCreate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::renderscript::V1_0::ScriptIntrinsicID id, uint64_t elem) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IContext::scriptIntrinsicCreate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&elem);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptIntrinsicCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    uint64_t _hidl_out_script;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwContext::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(elem);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(76 /* scriptIntrinsicCreate */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_script);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_script);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptIntrinsicCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<uint64_t>(_hidl_out_script);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint64_t>(_hidl_status);
}


// Methods from ::android::hardware::renderscript::V1_0::IContext follow.
::android::hardware::Return<uint64_t> BpHwContext::allocationAdapterCreate(uint64_t type, uint64_t baseAlloc){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationAdapterCreate(this, this, type, baseAlloc);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationAdapterOffset(uint64_t alloc, const ::android::hardware::hidl_vec<uint32_t>& offsets){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationAdapterOffset(this, this, alloc, offsets);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::allocationGetType(uint64_t allocation){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationGetType(this, this, allocation);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::allocationCreateTyped(uint64_t type, ::android::hardware::renderscript::V1_0::AllocationMipmapControl mips, ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::AllocationUsageType> usage, void* ptr){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationCreateTyped(this, this, type, mips, usage, ptr);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::allocationCreateFromBitmap(uint64_t type, ::android::hardware::renderscript::V1_0::AllocationMipmapControl mips, const ::android::hardware::hidl_vec<uint8_t>& bitmap, ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::AllocationUsageType> usage){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationCreateFromBitmap(this, this, type, mips, bitmap, usage);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::allocationCubeCreateFromBitmap(uint64_t type, ::android::hardware::renderscript::V1_0::AllocationMipmapControl mips, const ::android::hardware::hidl_vec<uint8_t>& bitmap, ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::AllocationUsageType> usage){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationCubeCreateFromBitmap(this, this, type, mips, bitmap, usage);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::allocationGetNativeWindow(uint64_t allocation){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationGetNativeWindow(this, this, allocation);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationSetNativeWindow(uint64_t allocation, uint64_t nativewindow){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationSetNativeWindow(this, this, allocation, nativewindow);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationSetupBufferQueue(uint64_t alloc, uint32_t numBuffer){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationSetupBufferQueue(this, this, alloc, numBuffer);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationShareBufferQueue(uint64_t baseAlloc, uint64_t subAlloc){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationShareBufferQueue(this, this, baseAlloc, subAlloc);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationCopyToBitmap(uint64_t allocation, void* data, uint64_t sizeBytes){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationCopyToBitmap(this, this, allocation, data, sizeBytes);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocation1DWrite(uint64_t allocation, uint32_t offset, uint32_t lod, uint32_t count, const ::android::hardware::hidl_vec<uint8_t>& data){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocation1DWrite(this, this, allocation, offset, lod, count, data);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationElementWrite(uint64_t allocation, uint32_t x, uint32_t y, uint32_t z, uint32_t lod, const ::android::hardware::hidl_vec<uint8_t>& data, uint64_t compIdx){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationElementWrite(this, this, allocation, x, y, z, lod, data, compIdx);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocation2DWrite(uint64_t allocation, uint32_t xoff, uint32_t yoff, uint32_t lod, ::android::hardware::renderscript::V1_0::AllocationCubemapFace face, uint32_t w, uint32_t h, const ::android::hardware::hidl_vec<uint8_t>& data, uint64_t stride){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocation2DWrite(this, this, allocation, xoff, yoff, lod, face, w, h, data, stride);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocation3DWrite(uint64_t allocation, uint32_t xoff, uint32_t yoff, uint32_t zoff, uint32_t lod, uint32_t w, uint32_t h, uint32_t d, const ::android::hardware::hidl_vec<uint8_t>& data, uint64_t stride){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocation3DWrite(this, this, allocation, xoff, yoff, zoff, lod, w, h, d, data, stride);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationGenerateMipmaps(uint64_t allocation){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationGenerateMipmaps(this, this, allocation);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationRead(uint64_t allocation, void* data, uint64_t sizeBytes){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationRead(this, this, allocation, data, sizeBytes);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocation1DRead(uint64_t allocation, uint32_t xoff, uint32_t lod, uint32_t count, void* data, uint64_t sizeBytes){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocation1DRead(this, this, allocation, xoff, lod, count, data, sizeBytes);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationElementRead(uint64_t allocation, uint32_t x, uint32_t y, uint32_t z, uint32_t lod, void* data, uint64_t sizeBytes, uint64_t compIdx){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationElementRead(this, this, allocation, x, y, z, lod, data, sizeBytes, compIdx);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocation2DRead(uint64_t allocation, uint32_t xoff, uint32_t yoff, uint32_t lod, ::android::hardware::renderscript::V1_0::AllocationCubemapFace face, uint32_t w, uint32_t h, void* data, uint64_t sizeBytes, uint64_t stride){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocation2DRead(this, this, allocation, xoff, yoff, lod, face, w, h, data, sizeBytes, stride);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocation3DRead(uint64_t allocation, uint32_t xoff, uint32_t yoff, uint32_t zoff, uint32_t lod, uint32_t w, uint32_t h, uint32_t d, void* data, uint64_t sizeBytes, uint64_t stride){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocation3DRead(this, this, allocation, xoff, yoff, zoff, lod, w, h, d, data, sizeBytes, stride);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationSyncAll(uint64_t allocation, ::android::hardware::renderscript::V1_0::AllocationUsageType usageType){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationSyncAll(this, this, allocation, usageType);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationResize1D(uint64_t allocation, uint32_t dimX){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationResize1D(this, this, allocation, dimX);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationCopy2DRange(uint64_t dstAlloc, uint32_t dstXoff, uint32_t dstYoff, uint32_t dstMip, ::android::hardware::renderscript::V1_0::AllocationCubemapFace dstFace, uint32_t width, uint32_t height, uint64_t srcAlloc, uint32_t srcXoff, uint32_t srcYoff, uint32_t srcMip, ::android::hardware::renderscript::V1_0::AllocationCubemapFace srcFace){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationCopy2DRange(this, this, dstAlloc, dstXoff, dstYoff, dstMip, dstFace, width, height, srcAlloc, srcXoff, srcYoff, srcMip, srcFace);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationCopy3DRange(uint64_t dstAlloc, uint32_t dstXoff, uint32_t dstYoff, uint32_t dstZoff, uint32_t dstMip, uint32_t width, uint32_t height, uint32_t depth, uint64_t srcAlloc, uint32_t srcXoff, uint32_t srcYoff, uint32_t srcZoff, uint32_t srcMip){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationCopy3DRange(this, this, dstAlloc, dstXoff, dstYoff, dstZoff, dstMip, width, height, depth, srcAlloc, srcXoff, srcYoff, srcZoff, srcMip);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationIoSend(uint64_t allocation){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationIoSend(this, this, allocation);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationIoReceive(uint64_t allocation){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationIoReceive(this, this, allocation);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::allocationGetPointer(uint64_t allocation, uint32_t lod, ::android::hardware::renderscript::V1_0::AllocationCubemapFace face, uint32_t z, allocationGetPointer_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_allocationGetPointer(this, this, allocation, lod, face, z, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::elementGetNativeMetadata(uint64_t element, elementGetNativeMetadata_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_elementGetNativeMetadata(this, this, element, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::elementGetSubElements(uint64_t element, uint64_t numSubElem, elementGetSubElements_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_elementGetSubElements(this, this, element, numSubElem, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::elementCreate(::android::hardware::renderscript::V1_0::DataType dt, ::android::hardware::renderscript::V1_0::DataKind dk, bool norm, uint32_t size){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_elementCreate(this, this, dt, dk, norm, size);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::elementComplexCreate(const ::android::hardware::hidl_vec<uint64_t>& einsPtr, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& names, const ::android::hardware::hidl_vec<uint64_t>& arraySizesPtr){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_elementComplexCreate(this, this, einsPtr, names, arraySizesPtr);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::typeGetNativeMetadata(uint64_t type, typeGetNativeMetadata_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_typeGetNativeMetadata(this, this, type, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::typeCreate(uint64_t element, uint32_t dimX, uint32_t dimY, uint32_t dimZ, bool mipmaps, bool faces, ::android::hardware::renderscript::V1_0::YuvFormat yuv){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_typeCreate(this, this, element, dimX, dimY, dimZ, mipmaps, faces, yuv);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::contextDestroy(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_contextDestroy(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::contextGetMessage(void* data, uint64_t size, contextGetMessage_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_contextGetMessage(this, this, data, size, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::contextPeekMessage(contextPeekMessage_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_contextPeekMessage(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::contextSendMessage(uint32_t id, const ::android::hardware::hidl_vec<uint8_t>& data){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_contextSendMessage(this, this, id, data);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::contextInitToClient(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_contextInitToClient(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::contextDeinitToClient(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_contextDeinitToClient(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::contextFinish(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_contextFinish(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::contextLog(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_contextLog(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::contextSetCacheDir(const ::android::hardware::hidl_string& cacheDir){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_contextSetCacheDir(this, this, cacheDir);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::contextSetPriority(::android::hardware::renderscript::V1_0::ThreadPriorities priority){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_contextSetPriority(this, this, priority);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::assignName(uint64_t obj, const ::android::hardware::hidl_string& name){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_assignName(this, this, obj, name);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::getName(uint64_t obj, getName_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_getName(this, this, obj, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::closureCreate(uint64_t kernelID, uint64_t returnValue, const ::android::hardware::hidl_vec<uint64_t>& fieldIDS, const ::android::hardware::hidl_vec<int64_t>& values, const ::android::hardware::hidl_vec<int32_t>& sizes, const ::android::hardware::hidl_vec<uint64_t>& depClosures, const ::android::hardware::hidl_vec<uint64_t>& depFieldIDS){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_closureCreate(this, this, kernelID, returnValue, fieldIDS, values, sizes, depClosures, depFieldIDS);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::invokeClosureCreate(uint64_t invokeID, const ::android::hardware::hidl_vec<uint8_t>& params, const ::android::hardware::hidl_vec<uint64_t>& fieldIDS, const ::android::hardware::hidl_vec<int64_t>& values, const ::android::hardware::hidl_vec<int32_t>& sizes){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_invokeClosureCreate(this, this, invokeID, params, fieldIDS, values, sizes);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::closureSetArg(uint64_t closure, uint32_t index, void* value, int32_t size){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_closureSetArg(this, this, closure, index, value, size);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::closureSetGlobal(uint64_t closure, uint64_t fieldID, int64_t value, int32_t size){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_closureSetGlobal(this, this, closure, fieldID, value, size);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::scriptKernelIDCreate(uint64_t script, int32_t slot, ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::MetadataSignatureBitval> sig){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptKernelIDCreate(this, this, script, slot, sig);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::scriptInvokeIDCreate(uint64_t script, int32_t slot){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptInvokeIDCreate(this, this, script, slot);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::scriptFieldIDCreate(uint64_t script, int32_t slot){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptFieldIDCreate(this, this, script, slot);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::scriptGroupCreate(const ::android::hardware::hidl_vec<uint64_t>& kernels, const ::android::hardware::hidl_vec<uint64_t>& srcK, const ::android::hardware::hidl_vec<uint64_t>& dstK, const ::android::hardware::hidl_vec<uint64_t>& dstF, const ::android::hardware::hidl_vec<uint64_t>& types){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptGroupCreate(this, this, kernels, srcK, dstK, dstF, types);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::scriptGroup2Create(const ::android::hardware::hidl_string& name, const ::android::hardware::hidl_string& cacheDir, const ::android::hardware::hidl_vec<uint64_t>& closures){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptGroup2Create(this, this, name, cacheDir, closures);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptGroupSetOutput(uint64_t sg, uint64_t kid, uint64_t alloc){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptGroupSetOutput(this, this, sg, kid, alloc);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptGroupSetInput(uint64_t sg, uint64_t kid, uint64_t alloc){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptGroupSetInput(this, this, sg, kid, alloc);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptGroupExecute(uint64_t sg){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptGroupExecute(this, this, sg);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::objDestroy(uint64_t obj){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_objDestroy(this, this, obj);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::samplerCreate(::android::hardware::renderscript::V1_0::SamplerValue magFilter, ::android::hardware::renderscript::V1_0::SamplerValue minFilter, ::android::hardware::renderscript::V1_0::SamplerValue wrapS, ::android::hardware::renderscript::V1_0::SamplerValue wrapT, ::android::hardware::renderscript::V1_0::SamplerValue wrapR, float aniso){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_samplerCreate(this, this, magFilter, minFilter, wrapS, wrapT, wrapR, aniso);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptBindAllocation(uint64_t script, uint64_t allocation, uint32_t slot){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptBindAllocation(this, this, script, allocation, slot);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptSetTimeZone(uint64_t script, const ::android::hardware::hidl_string& timeZone){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptSetTimeZone(this, this, script, timeZone);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptInvoke(uint64_t vs, uint32_t slot){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptInvoke(this, this, vs, slot);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptInvokeV(uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint8_t>& data){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptInvokeV(this, this, vs, slot, data);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptForEach(uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint64_t>& vains, uint64_t vaout, const ::android::hardware::hidl_vec<uint8_t>& params, void* sc){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptForEach(this, this, vs, slot, vains, vaout, params, sc);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptReduce(uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint64_t>& vains, uint64_t vaout, void* sc){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptReduce(this, this, vs, slot, vains, vaout, sc);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptSetVarI(uint64_t vs, uint32_t slot, int32_t value){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptSetVarI(this, this, vs, slot, value);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptSetVarObj(uint64_t vs, uint32_t slot, uint64_t obj){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptSetVarObj(this, this, vs, slot, obj);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptSetVarJ(uint64_t vs, uint32_t slot, int64_t value){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptSetVarJ(this, this, vs, slot, value);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptSetVarF(uint64_t vs, uint32_t slot, float value){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptSetVarF(this, this, vs, slot, value);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptSetVarD(uint64_t vs, uint32_t slot, double value){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptSetVarD(this, this, vs, slot, value);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptSetVarV(uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint8_t>& data){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptSetVarV(this, this, vs, slot, data);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptGetVarV(uint64_t vs, uint32_t slot, uint64_t len, scriptGetVarV_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptGetVarV(this, this, vs, slot, len, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::scriptSetVarVE(uint64_t vs, uint32_t slot, const ::android::hardware::hidl_vec<uint8_t>& data, uint64_t ve, const ::android::hardware::hidl_vec<uint32_t>& dims){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptSetVarVE(this, this, vs, slot, data, ve, dims);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::scriptCCreate(const ::android::hardware::hidl_string& resName, const ::android::hardware::hidl_string& cacheDir, const ::android::hardware::hidl_vec<uint8_t>& text){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptCCreate(this, this, resName, cacheDir, text);

    return _hidl_out;
}

::android::hardware::Return<uint64_t> BpHwContext::scriptIntrinsicCreate(::android::hardware::renderscript::V1_0::ScriptIntrinsicID id, uint64_t elem){
    ::android::hardware::Return<uint64_t>  _hidl_out = ::android::hardware::renderscript::V1_0::BpHwContext::_hidl_scriptIntrinsicCreate(this, this, id, elem);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwContext::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwContext::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwContext::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwContext::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwContext::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwContext::BnHwContext(const ::android::sp<IContext> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.renderscript@1.0", "IContext") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwContext::~BnHwContext() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::renderscript::V1_0::IContext follow.
::android::status_t BnHwContext::_hidl_allocationAdapterCreate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t type;
    uint64_t baseAlloc;

    _hidl_err = _hidl_data.readUint64(&type);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&baseAlloc);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationAdapterCreate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&baseAlloc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationAdapterCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_subAlloc = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationAdapterCreate(type, baseAlloc);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_subAlloc);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_subAlloc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationAdapterCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationAdapterOffset(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t alloc;
    const ::android::hardware::hidl_vec<uint32_t>* offsets;

    _hidl_err = _hidl_data.readUint64(&alloc);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_offsets_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*offsets), &_hidl_offsets_parent,  reinterpret_cast<const void **>(&offsets));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_offsets_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(*offsets),
            _hidl_data,
            _hidl_offsets_parent,
            0 /* parentOffset */, &_hidl_offsets_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationAdapterOffset::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&alloc);
        _hidl_args.push_back((void *)offsets);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationAdapterOffset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationAdapterOffset(alloc, *offsets);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationAdapterOffset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationGetType(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationGetType::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationGetType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_type = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationGetType(allocation);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_type);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationGetType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationCreateTyped(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t type;
    ::android::hardware::renderscript::V1_0::AllocationMipmapControl mips;
    ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::AllocationUsageType> usage;
    void* ptr;

    _hidl_err = _hidl_data.readUint64(&type);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&mips);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&usage);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    (void)ptr;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationCreateTyped::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&mips);
        _hidl_args.push_back((void *)&usage);
        _hidl_args.push_back((void *)&ptr);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationCreateTyped", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_allocation = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationCreateTyped(type, mips, usage, ptr);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationCreateTyped", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationCreateFromBitmap(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t type;
    ::android::hardware::renderscript::V1_0::AllocationMipmapControl mips;
    const ::android::hardware::hidl_vec<uint8_t>* bitmap;
    ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::AllocationUsageType> usage;

    _hidl_err = _hidl_data.readUint64(&type);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&mips);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_bitmap_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*bitmap), &_hidl_bitmap_parent,  reinterpret_cast<const void **>(&bitmap));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_bitmap_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*bitmap),
            _hidl_data,
            _hidl_bitmap_parent,
            0 /* parentOffset */, &_hidl_bitmap_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&usage);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationCreateFromBitmap::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&mips);
        _hidl_args.push_back((void *)bitmap);
        _hidl_args.push_back((void *)&usage);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationCreateFromBitmap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_allocation = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationCreateFromBitmap(type, mips, *bitmap, usage);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationCreateFromBitmap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationCubeCreateFromBitmap(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t type;
    ::android::hardware::renderscript::V1_0::AllocationMipmapControl mips;
    const ::android::hardware::hidl_vec<uint8_t>* bitmap;
    ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::AllocationUsageType> usage;

    _hidl_err = _hidl_data.readUint64(&type);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&mips);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_bitmap_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*bitmap), &_hidl_bitmap_parent,  reinterpret_cast<const void **>(&bitmap));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_bitmap_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*bitmap),
            _hidl_data,
            _hidl_bitmap_parent,
            0 /* parentOffset */, &_hidl_bitmap_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&usage);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationCubeCreateFromBitmap::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        _hidl_args.push_back((void *)&mips);
        _hidl_args.push_back((void *)bitmap);
        _hidl_args.push_back((void *)&usage);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationCubeCreateFromBitmap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_allocation = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationCubeCreateFromBitmap(type, mips, *bitmap, usage);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_allocation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationCubeCreateFromBitmap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationGetNativeWindow(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationGetNativeWindow::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationGetNativeWindow", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_nativeWindow = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationGetNativeWindow(allocation);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_nativeWindow);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_nativeWindow);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationGetNativeWindow", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationSetNativeWindow(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;
    uint64_t nativewindow;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&nativewindow);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationSetNativeWindow::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&nativewindow);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationSetNativeWindow", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationSetNativeWindow(allocation, nativewindow);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationSetNativeWindow", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationSetupBufferQueue(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t alloc;
    uint32_t numBuffer;

    _hidl_err = _hidl_data.readUint64(&alloc);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&numBuffer);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationSetupBufferQueue::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&alloc);
        _hidl_args.push_back((void *)&numBuffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationSetupBufferQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationSetupBufferQueue(alloc, numBuffer);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationSetupBufferQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationShareBufferQueue(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t baseAlloc;
    uint64_t subAlloc;

    _hidl_err = _hidl_data.readUint64(&baseAlloc);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&subAlloc);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationShareBufferQueue::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&baseAlloc);
        _hidl_args.push_back((void *)&subAlloc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationShareBufferQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationShareBufferQueue(baseAlloc, subAlloc);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationShareBufferQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationCopyToBitmap(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;
    void* data;
    uint64_t sizeBytes;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    (void)data;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&sizeBytes);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationCopyToBitmap::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&sizeBytes);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationCopyToBitmap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationCopyToBitmap(allocation, data, sizeBytes);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationCopyToBitmap", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocation1DWrite(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;
    uint32_t offset;
    uint32_t lod;
    uint32_t count;
    const ::android::hardware::hidl_vec<uint8_t>* data;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&offset);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&lod);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&count);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*data), &_hidl_data_parent,  reinterpret_cast<const void **>(&data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*data),
            _hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocation1DWrite::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&offset);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&count);
        _hidl_args.push_back((void *)data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocation1DWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocation1DWrite(allocation, offset, lod, count, *data);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocation1DWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationElementWrite(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t lod;
    const ::android::hardware::hidl_vec<uint8_t>* data;
    uint64_t compIdx;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&x);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&y);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&z);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&lod);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*data), &_hidl_data_parent,  reinterpret_cast<const void **>(&data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*data),
            _hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&compIdx);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationElementWrite::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&x);
        _hidl_args.push_back((void *)&y);
        _hidl_args.push_back((void *)&z);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)data);
        _hidl_args.push_back((void *)&compIdx);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationElementWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationElementWrite(allocation, x, y, z, lod, *data, compIdx);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationElementWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocation2DWrite(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;
    uint32_t xoff;
    uint32_t yoff;
    uint32_t lod;
    ::android::hardware::renderscript::V1_0::AllocationCubemapFace face;
    uint32_t w;
    uint32_t h;
    const ::android::hardware::hidl_vec<uint8_t>* data;
    uint64_t stride;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&xoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&yoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&lod);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&face);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&w);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&h);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*data), &_hidl_data_parent,  reinterpret_cast<const void **>(&data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*data),
            _hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&stride);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocation2DWrite::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&xoff);
        _hidl_args.push_back((void *)&yoff);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&face);
        _hidl_args.push_back((void *)&w);
        _hidl_args.push_back((void *)&h);
        _hidl_args.push_back((void *)data);
        _hidl_args.push_back((void *)&stride);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocation2DWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocation2DWrite(allocation, xoff, yoff, lod, face, w, h, *data, stride);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocation2DWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocation3DWrite(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;
    uint32_t xoff;
    uint32_t yoff;
    uint32_t zoff;
    uint32_t lod;
    uint32_t w;
    uint32_t h;
    uint32_t d;
    const ::android::hardware::hidl_vec<uint8_t>* data;
    uint64_t stride;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&xoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&yoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&zoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&lod);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&w);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&h);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&d);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*data), &_hidl_data_parent,  reinterpret_cast<const void **>(&data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*data),
            _hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&stride);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocation3DWrite::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&xoff);
        _hidl_args.push_back((void *)&yoff);
        _hidl_args.push_back((void *)&zoff);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&w);
        _hidl_args.push_back((void *)&h);
        _hidl_args.push_back((void *)&d);
        _hidl_args.push_back((void *)data);
        _hidl_args.push_back((void *)&stride);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocation3DWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocation3DWrite(allocation, xoff, yoff, zoff, lod, w, h, d, *data, stride);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocation3DWrite", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationGenerateMipmaps(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationGenerateMipmaps::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationGenerateMipmaps", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationGenerateMipmaps(allocation);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationGenerateMipmaps", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationRead(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;
    void* data;
    uint64_t sizeBytes;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    (void)data;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&sizeBytes);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationRead::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&sizeBytes);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationRead(allocation, data, sizeBytes);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocation1DRead(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;
    uint32_t xoff;
    uint32_t lod;
    uint32_t count;
    void* data;
    uint64_t sizeBytes;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&xoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&lod);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&count);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    (void)data;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&sizeBytes);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocation1DRead::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&xoff);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&count);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&sizeBytes);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocation1DRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocation1DRead(allocation, xoff, lod, count, data, sizeBytes);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocation1DRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationElementRead(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t lod;
    void* data;
    uint64_t sizeBytes;
    uint64_t compIdx;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&x);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&y);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&z);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&lod);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    (void)data;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&sizeBytes);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&compIdx);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationElementRead::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&x);
        _hidl_args.push_back((void *)&y);
        _hidl_args.push_back((void *)&z);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&sizeBytes);
        _hidl_args.push_back((void *)&compIdx);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationElementRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationElementRead(allocation, x, y, z, lod, data, sizeBytes, compIdx);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationElementRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocation2DRead(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;
    uint32_t xoff;
    uint32_t yoff;
    uint32_t lod;
    ::android::hardware::renderscript::V1_0::AllocationCubemapFace face;
    uint32_t w;
    uint32_t h;
    void* data;
    uint64_t sizeBytes;
    uint64_t stride;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&xoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&yoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&lod);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&face);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&w);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&h);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    (void)data;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&sizeBytes);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&stride);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocation2DRead::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&xoff);
        _hidl_args.push_back((void *)&yoff);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&face);
        _hidl_args.push_back((void *)&w);
        _hidl_args.push_back((void *)&h);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&sizeBytes);
        _hidl_args.push_back((void *)&stride);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocation2DRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocation2DRead(allocation, xoff, yoff, lod, face, w, h, data, sizeBytes, stride);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocation2DRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocation3DRead(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;
    uint32_t xoff;
    uint32_t yoff;
    uint32_t zoff;
    uint32_t lod;
    uint32_t w;
    uint32_t h;
    uint32_t d;
    void* data;
    uint64_t sizeBytes;
    uint64_t stride;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&xoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&yoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&zoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&lod);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&w);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&h);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&d);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    (void)data;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&sizeBytes);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&stride);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocation3DRead::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&xoff);
        _hidl_args.push_back((void *)&yoff);
        _hidl_args.push_back((void *)&zoff);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&w);
        _hidl_args.push_back((void *)&h);
        _hidl_args.push_back((void *)&d);
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&sizeBytes);
        _hidl_args.push_back((void *)&stride);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocation3DRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocation3DRead(allocation, xoff, yoff, zoff, lod, w, h, d, data, sizeBytes, stride);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocation3DRead", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationSyncAll(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;
    ::android::hardware::renderscript::V1_0::AllocationUsageType usageType;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&usageType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationSyncAll::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&usageType);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationSyncAll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationSyncAll(allocation, usageType);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationSyncAll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationResize1D(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;
    uint32_t dimX;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&dimX);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationResize1D::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&dimX);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationResize1D", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationResize1D(allocation, dimX);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationResize1D", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationCopy2DRange(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t dstAlloc;
    uint32_t dstXoff;
    uint32_t dstYoff;
    uint32_t dstMip;
    ::android::hardware::renderscript::V1_0::AllocationCubemapFace dstFace;
    uint32_t width;
    uint32_t height;
    uint64_t srcAlloc;
    uint32_t srcXoff;
    uint32_t srcYoff;
    uint32_t srcMip;
    ::android::hardware::renderscript::V1_0::AllocationCubemapFace srcFace;

    _hidl_err = _hidl_data.readUint64(&dstAlloc);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&dstXoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&dstYoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&dstMip);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&dstFace);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&width);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&height);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&srcAlloc);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&srcXoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&srcYoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&srcMip);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&srcFace);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationCopy2DRange::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&dstAlloc);
        _hidl_args.push_back((void *)&dstXoff);
        _hidl_args.push_back((void *)&dstYoff);
        _hidl_args.push_back((void *)&dstMip);
        _hidl_args.push_back((void *)&dstFace);
        _hidl_args.push_back((void *)&width);
        _hidl_args.push_back((void *)&height);
        _hidl_args.push_back((void *)&srcAlloc);
        _hidl_args.push_back((void *)&srcXoff);
        _hidl_args.push_back((void *)&srcYoff);
        _hidl_args.push_back((void *)&srcMip);
        _hidl_args.push_back((void *)&srcFace);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationCopy2DRange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationCopy2DRange(dstAlloc, dstXoff, dstYoff, dstMip, dstFace, width, height, srcAlloc, srcXoff, srcYoff, srcMip, srcFace);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationCopy2DRange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationCopy3DRange(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t dstAlloc;
    uint32_t dstXoff;
    uint32_t dstYoff;
    uint32_t dstZoff;
    uint32_t dstMip;
    uint32_t width;
    uint32_t height;
    uint32_t depth;
    uint64_t srcAlloc;
    uint32_t srcXoff;
    uint32_t srcYoff;
    uint32_t srcZoff;
    uint32_t srcMip;

    _hidl_err = _hidl_data.readUint64(&dstAlloc);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&dstXoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&dstYoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&dstZoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&dstMip);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&width);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&height);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&depth);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&srcAlloc);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&srcXoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&srcYoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&srcZoff);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&srcMip);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationCopy3DRange::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&dstAlloc);
        _hidl_args.push_back((void *)&dstXoff);
        _hidl_args.push_back((void *)&dstYoff);
        _hidl_args.push_back((void *)&dstZoff);
        _hidl_args.push_back((void *)&dstMip);
        _hidl_args.push_back((void *)&width);
        _hidl_args.push_back((void *)&height);
        _hidl_args.push_back((void *)&depth);
        _hidl_args.push_back((void *)&srcAlloc);
        _hidl_args.push_back((void *)&srcXoff);
        _hidl_args.push_back((void *)&srcYoff);
        _hidl_args.push_back((void *)&srcZoff);
        _hidl_args.push_back((void *)&srcMip);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationCopy3DRange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationCopy3DRange(dstAlloc, dstXoff, dstYoff, dstZoff, dstMip, width, height, depth, srcAlloc, srcXoff, srcYoff, srcZoff, srcMip);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationCopy3DRange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationIoSend(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationIoSend::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationIoSend", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationIoSend(allocation);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationIoSend", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationIoReceive(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationIoReceive::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationIoReceive", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationIoReceive(allocation);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationIoReceive", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_allocationGetPointer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t allocation;
    uint32_t lod;
    ::android::hardware::renderscript::V1_0::AllocationCubemapFace face;
    uint32_t z;

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&lod);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&face);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&z);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::allocationGetPointer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&lod);
        _hidl_args.push_back((void *)&face);
        _hidl_args.push_back((void *)&z);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "allocationGetPointer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->allocationGetPointer(allocation, lod, face, z, [&](const auto &_hidl_out_dataPtr, const auto &_hidl_out_stride) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("allocationGetPointer: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        (void)_hidl_out_dataPtr;
        LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint64(_hidl_out_stride);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_dataPtr);
            _hidl_args.push_back((void *)&_hidl_out_stride);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "allocationGetPointer", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("allocationGetPointer: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_elementGetNativeMetadata(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t element;

    _hidl_err = _hidl_data.readUint64(&element);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::elementGetNativeMetadata::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&element);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "elementGetNativeMetadata", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->elementGetNativeMetadata(element, [&](const auto &_hidl_out_elemData) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("elementGetNativeMetadata: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_elemData_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_elemData, sizeof(_hidl_out_elemData), &_hidl__hidl_out_elemData_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_elemData_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_elemData,
                _hidl_reply,
                _hidl__hidl_out_elemData_parent,
                0 /* parentOffset */, &_hidl__hidl_out_elemData_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_elemData);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "elementGetNativeMetadata", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("elementGetNativeMetadata: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_elementGetSubElements(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t element;
    uint64_t numSubElem;

    _hidl_err = _hidl_data.readUint64(&element);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&numSubElem);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::elementGetSubElements::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&element);
        _hidl_args.push_back((void *)&numSubElem);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "elementGetSubElements", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->elementGetSubElements(element, numSubElem, [&](const auto &_hidl_out_ids, const auto &_hidl_out_names, const auto &_hidl_out_arraySizes) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("elementGetSubElements: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_ids_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_ids, sizeof(_hidl_out_ids), &_hidl__hidl_out_ids_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_ids_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_ids,
                _hidl_reply,
                _hidl__hidl_out_ids_parent,
                0 /* parentOffset */, &_hidl__hidl_out_ids_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_names_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_names, sizeof(_hidl_out_names), &_hidl__hidl_out_names_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_names_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_names,
                _hidl_reply,
                _hidl__hidl_out_names_parent,
                0 /* parentOffset */, &_hidl__hidl_out_names_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_names.size(); ++_hidl_index_0) {
            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    _hidl_out_names[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_names_child,
                    _hidl_index_0 * sizeof(::android::hardware::hidl_string));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

        size_t _hidl__hidl_out_arraySizes_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_arraySizes, sizeof(_hidl_out_arraySizes), &_hidl__hidl_out_arraySizes_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_arraySizes_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_arraySizes,
                _hidl_reply,
                _hidl__hidl_out_arraySizes_parent,
                0 /* parentOffset */, &_hidl__hidl_out_arraySizes_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_ids);
            _hidl_args.push_back((void *)&_hidl_out_names);
            _hidl_args.push_back((void *)&_hidl_out_arraySizes);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "elementGetSubElements", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("elementGetSubElements: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_elementCreate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::renderscript::V1_0::DataType dt;
    ::android::hardware::renderscript::V1_0::DataKind dk;
    bool norm;
    uint32_t size;

    _hidl_err = _hidl_data.readInt32((int32_t *)&dt);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&dk);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&norm);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&size);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::elementCreate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&dt);
        _hidl_args.push_back((void *)&dk);
        _hidl_args.push_back((void *)&norm);
        _hidl_args.push_back((void *)&size);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "elementCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_element = static_cast<IContext*>(_hidl_this->getImpl().get())->elementCreate(dt, dk, norm, size);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_element);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_element);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "elementCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_elementComplexCreate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint64_t>* einsPtr;
    const ::android::hardware::hidl_vec<::android::hardware::hidl_string>* names;
    const ::android::hardware::hidl_vec<uint64_t>* arraySizesPtr;

    size_t _hidl_einsPtr_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*einsPtr), &_hidl_einsPtr_parent,  reinterpret_cast<const void **>(&einsPtr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_einsPtr_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(*einsPtr),
            _hidl_data,
            _hidl_einsPtr_parent,
            0 /* parentOffset */, &_hidl_einsPtr_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_names_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*names), &_hidl_names_parent,  reinterpret_cast<const void **>(&names));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_names_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(*names),
            _hidl_data,
            _hidl_names_parent,
            0 /* parentOffset */, &_hidl_names_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < names->size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>((*names)[_hidl_index_0]),
                _hidl_data,
                _hidl_names_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_arraySizesPtr_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*arraySizesPtr), &_hidl_arraySizesPtr_parent,  reinterpret_cast<const void **>(&arraySizesPtr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_arraySizesPtr_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(*arraySizesPtr),
            _hidl_data,
            _hidl_arraySizesPtr_parent,
            0 /* parentOffset */, &_hidl_arraySizesPtr_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::elementComplexCreate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)einsPtr);
        _hidl_args.push_back((void *)names);
        _hidl_args.push_back((void *)arraySizesPtr);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "elementComplexCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_element = static_cast<IContext*>(_hidl_this->getImpl().get())->elementComplexCreate(*einsPtr, *names, *arraySizesPtr);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_element);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_element);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "elementComplexCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_typeGetNativeMetadata(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t type;

    _hidl_err = _hidl_data.readUint64(&type);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::typeGetNativeMetadata::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "typeGetNativeMetadata", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->typeGetNativeMetadata(type, [&](const auto &_hidl_out_metadata) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("typeGetNativeMetadata: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_metadata_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_metadata, sizeof(_hidl_out_metadata), &_hidl__hidl_out_metadata_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_metadata_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_metadata,
                _hidl_reply,
                _hidl__hidl_out_metadata_parent,
                0 /* parentOffset */, &_hidl__hidl_out_metadata_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_metadata);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "typeGetNativeMetadata", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("typeGetNativeMetadata: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_typeCreate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t element;
    uint32_t dimX;
    uint32_t dimY;
    uint32_t dimZ;
    bool mipmaps;
    bool faces;
    ::android::hardware::renderscript::V1_0::YuvFormat yuv;

    _hidl_err = _hidl_data.readUint64(&element);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&dimX);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&dimY);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&dimZ);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&mipmaps);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&faces);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&yuv);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::typeCreate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&element);
        _hidl_args.push_back((void *)&dimX);
        _hidl_args.push_back((void *)&dimY);
        _hidl_args.push_back((void *)&dimZ);
        _hidl_args.push_back((void *)&mipmaps);
        _hidl_args.push_back((void *)&faces);
        _hidl_args.push_back((void *)&yuv);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "typeCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_type = static_cast<IContext*>(_hidl_this->getImpl().get())->typeCreate(element, dimX, dimY, dimZ, mipmaps, faces, yuv);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_type);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "typeCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_contextDestroy(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::contextDestroy::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextDestroy", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->contextDestroy();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextDestroy", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_contextGetMessage(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    void* data;
    uint64_t size;

    (void)data;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&size);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::contextGetMessage::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&data);
        _hidl_args.push_back((void *)&size);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextGetMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->contextGetMessage(data, size, [&](const auto &_hidl_out_messageType, const auto &_hidl_out_receiveLen) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("contextGetMessage: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_messageType);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint64(_hidl_out_receiveLen);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_messageType);
            _hidl_args.push_back((void *)&_hidl_out_receiveLen);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextGetMessage", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("contextGetMessage: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_contextPeekMessage(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::contextPeekMessage::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextPeekMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->contextPeekMessage([&](const auto &_hidl_out_messageType, const auto &_hidl_out_receiveLen, const auto &_hidl_out_subID) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("contextPeekMessage: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_messageType);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint64(_hidl_out_receiveLen);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_subID);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_messageType);
            _hidl_args.push_back((void *)&_hidl_out_receiveLen);
            _hidl_args.push_back((void *)&_hidl_out_subID);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextPeekMessage", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("contextPeekMessage: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_contextSendMessage(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t id;
    const ::android::hardware::hidl_vec<uint8_t>* data;

    _hidl_err = _hidl_data.readUint32(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*data), &_hidl_data_parent,  reinterpret_cast<const void **>(&data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*data),
            _hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::contextSendMessage::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextSendMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->contextSendMessage(id, *data);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextSendMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_contextInitToClient(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::contextInitToClient::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextInitToClient", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->contextInitToClient();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextInitToClient", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_contextDeinitToClient(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::contextDeinitToClient::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextDeinitToClient", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->contextDeinitToClient();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextDeinitToClient", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_contextFinish(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::contextFinish::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextFinish", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->contextFinish();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextFinish", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_contextLog(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::contextLog::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextLog", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->contextLog();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextLog", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_contextSetCacheDir(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* cacheDir;

    size_t _hidl_cacheDir_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*cacheDir), &_hidl_cacheDir_parent,  reinterpret_cast<const void **>(&cacheDir));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*cacheDir),
            _hidl_data,
            _hidl_cacheDir_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::contextSetCacheDir::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)cacheDir);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextSetCacheDir", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->contextSetCacheDir(*cacheDir);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextSetCacheDir", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_contextSetPriority(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::renderscript::V1_0::ThreadPriorities priority;

    _hidl_err = _hidl_data.readInt32((int32_t *)&priority);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::contextSetPriority::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&priority);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "contextSetPriority", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->contextSetPriority(priority);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "contextSetPriority", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_assignName(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t obj;
    const ::android::hardware::hidl_string* name;

    _hidl_err = _hidl_data.readUint64(&obj);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_name_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*name), &_hidl_name_parent,  reinterpret_cast<const void **>(&name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*name),
            _hidl_data,
            _hidl_name_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::assignName::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&obj);
        _hidl_args.push_back((void *)name);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "assignName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->assignName(obj, *name);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "assignName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_getName(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t obj;

    _hidl_err = _hidl_data.readUint64(&obj);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::getName::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&obj);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "getName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->getName(obj, [&](const auto &_hidl_out_name) {
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
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "getName", &_hidl_args);
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

::android::status_t BnHwContext::_hidl_closureCreate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t kernelID;
    uint64_t returnValue;
    const ::android::hardware::hidl_vec<uint64_t>* fieldIDS;
    const ::android::hardware::hidl_vec<int64_t>* values;
    const ::android::hardware::hidl_vec<int32_t>* sizes;
    const ::android::hardware::hidl_vec<uint64_t>* depClosures;
    const ::android::hardware::hidl_vec<uint64_t>* depFieldIDS;

    _hidl_err = _hidl_data.readUint64(&kernelID);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&returnValue);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_fieldIDS_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*fieldIDS), &_hidl_fieldIDS_parent,  reinterpret_cast<const void **>(&fieldIDS));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_fieldIDS_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(*fieldIDS),
            _hidl_data,
            _hidl_fieldIDS_parent,
            0 /* parentOffset */, &_hidl_fieldIDS_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_values_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*values), &_hidl_values_parent,  reinterpret_cast<const void **>(&values));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int64_t> &>(*values),
            _hidl_data,
            _hidl_values_parent,
            0 /* parentOffset */, &_hidl_values_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sizes_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sizes), &_hidl_sizes_parent,  reinterpret_cast<const void **>(&sizes));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sizes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int32_t> &>(*sizes),
            _hidl_data,
            _hidl_sizes_parent,
            0 /* parentOffset */, &_hidl_sizes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_depClosures_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*depClosures), &_hidl_depClosures_parent,  reinterpret_cast<const void **>(&depClosures));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_depClosures_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(*depClosures),
            _hidl_data,
            _hidl_depClosures_parent,
            0 /* parentOffset */, &_hidl_depClosures_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_depFieldIDS_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*depFieldIDS), &_hidl_depFieldIDS_parent,  reinterpret_cast<const void **>(&depFieldIDS));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_depFieldIDS_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(*depFieldIDS),
            _hidl_data,
            _hidl_depFieldIDS_parent,
            0 /* parentOffset */, &_hidl_depFieldIDS_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::closureCreate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&kernelID);
        _hidl_args.push_back((void *)&returnValue);
        _hidl_args.push_back((void *)fieldIDS);
        _hidl_args.push_back((void *)values);
        _hidl_args.push_back((void *)sizes);
        _hidl_args.push_back((void *)depClosures);
        _hidl_args.push_back((void *)depFieldIDS);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "closureCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_closure = static_cast<IContext*>(_hidl_this->getImpl().get())->closureCreate(kernelID, returnValue, *fieldIDS, *values, *sizes, *depClosures, *depFieldIDS);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_closure);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_closure);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "closureCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_invokeClosureCreate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t invokeID;
    const ::android::hardware::hidl_vec<uint8_t>* params;
    const ::android::hardware::hidl_vec<uint64_t>* fieldIDS;
    const ::android::hardware::hidl_vec<int64_t>* values;
    const ::android::hardware::hidl_vec<int32_t>* sizes;

    _hidl_err = _hidl_data.readUint64(&invokeID);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_params_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*params), &_hidl_params_parent,  reinterpret_cast<const void **>(&params));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_params_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*params),
            _hidl_data,
            _hidl_params_parent,
            0 /* parentOffset */, &_hidl_params_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_fieldIDS_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*fieldIDS), &_hidl_fieldIDS_parent,  reinterpret_cast<const void **>(&fieldIDS));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_fieldIDS_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(*fieldIDS),
            _hidl_data,
            _hidl_fieldIDS_parent,
            0 /* parentOffset */, &_hidl_fieldIDS_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_values_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*values), &_hidl_values_parent,  reinterpret_cast<const void **>(&values));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int64_t> &>(*values),
            _hidl_data,
            _hidl_values_parent,
            0 /* parentOffset */, &_hidl_values_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sizes_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sizes), &_hidl_sizes_parent,  reinterpret_cast<const void **>(&sizes));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sizes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int32_t> &>(*sizes),
            _hidl_data,
            _hidl_sizes_parent,
            0 /* parentOffset */, &_hidl_sizes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::invokeClosureCreate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&invokeID);
        _hidl_args.push_back((void *)params);
        _hidl_args.push_back((void *)fieldIDS);
        _hidl_args.push_back((void *)values);
        _hidl_args.push_back((void *)sizes);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "invokeClosureCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_closure = static_cast<IContext*>(_hidl_this->getImpl().get())->invokeClosureCreate(invokeID, *params, *fieldIDS, *values, *sizes);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_closure);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_closure);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "invokeClosureCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_closureSetArg(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t closure;
    uint32_t index;
    void* value;
    int32_t size;

    _hidl_err = _hidl_data.readUint64(&closure);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&index);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    (void)value;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&size);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::closureSetArg::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&closure);
        _hidl_args.push_back((void *)&index);
        _hidl_args.push_back((void *)&value);
        _hidl_args.push_back((void *)&size);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "closureSetArg", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->closureSetArg(closure, index, value, size);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "closureSetArg", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_closureSetGlobal(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t closure;
    uint64_t fieldID;
    int64_t value;
    int32_t size;

    _hidl_err = _hidl_data.readUint64(&closure);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&fieldID);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt64(&value);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&size);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::closureSetGlobal::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&closure);
        _hidl_args.push_back((void *)&fieldID);
        _hidl_args.push_back((void *)&value);
        _hidl_args.push_back((void *)&size);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "closureSetGlobal", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->closureSetGlobal(closure, fieldID, value, size);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "closureSetGlobal", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptKernelIDCreate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t script;
    int32_t slot;
    ::android::hardware::hidl_bitfield<::android::hardware::renderscript::V1_0::MetadataSignatureBitval> sig;

    _hidl_err = _hidl_data.readUint64(&script);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&sig);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptKernelIDCreate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&script);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&sig);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptKernelIDCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_scriptKernelID = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptKernelIDCreate(script, slot, sig);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_scriptKernelID);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_scriptKernelID);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptKernelIDCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptInvokeIDCreate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t script;
    int32_t slot;

    _hidl_err = _hidl_data.readUint64(&script);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptInvokeIDCreate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&script);
        _hidl_args.push_back((void *)&slot);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptInvokeIDCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_scriptInvokeID = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptInvokeIDCreate(script, slot);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_scriptInvokeID);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_scriptInvokeID);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptInvokeIDCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptFieldIDCreate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t script;
    int32_t slot;

    _hidl_err = _hidl_data.readUint64(&script);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptFieldIDCreate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&script);
        _hidl_args.push_back((void *)&slot);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptFieldIDCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_scriptFieldID = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptFieldIDCreate(script, slot);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_scriptFieldID);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_scriptFieldID);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptFieldIDCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptGroupCreate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint64_t>* kernels;
    const ::android::hardware::hidl_vec<uint64_t>* srcK;
    const ::android::hardware::hidl_vec<uint64_t>* dstK;
    const ::android::hardware::hidl_vec<uint64_t>* dstF;
    const ::android::hardware::hidl_vec<uint64_t>* types;

    size_t _hidl_kernels_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*kernels), &_hidl_kernels_parent,  reinterpret_cast<const void **>(&kernels));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_kernels_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(*kernels),
            _hidl_data,
            _hidl_kernels_parent,
            0 /* parentOffset */, &_hidl_kernels_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_srcK_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*srcK), &_hidl_srcK_parent,  reinterpret_cast<const void **>(&srcK));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_srcK_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(*srcK),
            _hidl_data,
            _hidl_srcK_parent,
            0 /* parentOffset */, &_hidl_srcK_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dstK_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dstK), &_hidl_dstK_parent,  reinterpret_cast<const void **>(&dstK));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dstK_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(*dstK),
            _hidl_data,
            _hidl_dstK_parent,
            0 /* parentOffset */, &_hidl_dstK_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dstF_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dstF), &_hidl_dstF_parent,  reinterpret_cast<const void **>(&dstF));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dstF_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(*dstF),
            _hidl_data,
            _hidl_dstF_parent,
            0 /* parentOffset */, &_hidl_dstF_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_types_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*types), &_hidl_types_parent,  reinterpret_cast<const void **>(&types));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_types_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(*types),
            _hidl_data,
            _hidl_types_parent,
            0 /* parentOffset */, &_hidl_types_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptGroupCreate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)kernels);
        _hidl_args.push_back((void *)srcK);
        _hidl_args.push_back((void *)dstK);
        _hidl_args.push_back((void *)dstF);
        _hidl_args.push_back((void *)types);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_scriptGroup = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptGroupCreate(*kernels, *srcK, *dstK, *dstF, *types);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_scriptGroup);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_scriptGroup);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptGroup2Create(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* name;
    const ::android::hardware::hidl_string* cacheDir;
    const ::android::hardware::hidl_vec<uint64_t>* closures;

    size_t _hidl_name_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*name), &_hidl_name_parent,  reinterpret_cast<const void **>(&name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*name),
            _hidl_data,
            _hidl_name_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_cacheDir_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*cacheDir), &_hidl_cacheDir_parent,  reinterpret_cast<const void **>(&cacheDir));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*cacheDir),
            _hidl_data,
            _hidl_cacheDir_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_closures_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*closures), &_hidl_closures_parent,  reinterpret_cast<const void **>(&closures));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_closures_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(*closures),
            _hidl_data,
            _hidl_closures_parent,
            0 /* parentOffset */, &_hidl_closures_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptGroup2Create::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)name);
        _hidl_args.push_back((void *)cacheDir);
        _hidl_args.push_back((void *)closures);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptGroup2Create", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_scriptGroup2 = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptGroup2Create(*name, *cacheDir, *closures);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_scriptGroup2);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_scriptGroup2);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptGroup2Create", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptGroupSetOutput(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t sg;
    uint64_t kid;
    uint64_t alloc;

    _hidl_err = _hidl_data.readUint64(&sg);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&kid);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&alloc);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptGroupSetOutput::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sg);
        _hidl_args.push_back((void *)&kid);
        _hidl_args.push_back((void *)&alloc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupSetOutput", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptGroupSetOutput(sg, kid, alloc);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupSetOutput", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptGroupSetInput(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t sg;
    uint64_t kid;
    uint64_t alloc;

    _hidl_err = _hidl_data.readUint64(&sg);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&kid);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&alloc);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptGroupSetInput::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sg);
        _hidl_args.push_back((void *)&kid);
        _hidl_args.push_back((void *)&alloc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupSetInput", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptGroupSetInput(sg, kid, alloc);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupSetInput", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptGroupExecute(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t sg;

    _hidl_err = _hidl_data.readUint64(&sg);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptGroupExecute::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupExecute", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptGroupExecute(sg);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptGroupExecute", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_objDestroy(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t obj;

    _hidl_err = _hidl_data.readUint64(&obj);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::objDestroy::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&obj);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "objDestroy", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->objDestroy(obj);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "objDestroy", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_samplerCreate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::renderscript::V1_0::SamplerValue magFilter;
    ::android::hardware::renderscript::V1_0::SamplerValue minFilter;
    ::android::hardware::renderscript::V1_0::SamplerValue wrapS;
    ::android::hardware::renderscript::V1_0::SamplerValue wrapT;
    ::android::hardware::renderscript::V1_0::SamplerValue wrapR;
    float aniso;

    _hidl_err = _hidl_data.readInt32((int32_t *)&magFilter);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&minFilter);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&wrapS);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&wrapT);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&wrapR);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readFloat(&aniso);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::samplerCreate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&magFilter);
        _hidl_args.push_back((void *)&minFilter);
        _hidl_args.push_back((void *)&wrapS);
        _hidl_args.push_back((void *)&wrapT);
        _hidl_args.push_back((void *)&wrapR);
        _hidl_args.push_back((void *)&aniso);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "samplerCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_sampler = static_cast<IContext*>(_hidl_this->getImpl().get())->samplerCreate(magFilter, minFilter, wrapS, wrapT, wrapR, aniso);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_sampler);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_sampler);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "samplerCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptBindAllocation(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t script;
    uint64_t allocation;
    uint32_t slot;

    _hidl_err = _hidl_data.readUint64(&script);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&allocation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptBindAllocation::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&script);
        _hidl_args.push_back((void *)&allocation);
        _hidl_args.push_back((void *)&slot);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptBindAllocation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptBindAllocation(script, allocation, slot);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptBindAllocation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptSetTimeZone(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t script;
    const ::android::hardware::hidl_string* timeZone;

    _hidl_err = _hidl_data.readUint64(&script);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_timeZone_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*timeZone), &_hidl_timeZone_parent,  reinterpret_cast<const void **>(&timeZone));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*timeZone),
            _hidl_data,
            _hidl_timeZone_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptSetTimeZone::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&script);
        _hidl_args.push_back((void *)timeZone);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetTimeZone", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptSetTimeZone(script, *timeZone);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetTimeZone", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptInvoke(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t vs;
    uint32_t slot;

    _hidl_err = _hidl_data.readUint64(&vs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptInvoke::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptInvoke", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptInvoke(vs, slot);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptInvoke", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptInvokeV(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t vs;
    uint32_t slot;
    const ::android::hardware::hidl_vec<uint8_t>* data;

    _hidl_err = _hidl_data.readUint64(&vs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*data), &_hidl_data_parent,  reinterpret_cast<const void **>(&data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*data),
            _hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptInvokeV::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptInvokeV", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptInvokeV(vs, slot, *data);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptInvokeV", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptForEach(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t vs;
    uint32_t slot;
    const ::android::hardware::hidl_vec<uint64_t>* vains;
    uint64_t vaout;
    const ::android::hardware::hidl_vec<uint8_t>* params;
    void* sc;

    _hidl_err = _hidl_data.readUint64(&vs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_vains_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*vains), &_hidl_vains_parent,  reinterpret_cast<const void **>(&vains));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_vains_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(*vains),
            _hidl_data,
            _hidl_vains_parent,
            0 /* parentOffset */, &_hidl_vains_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&vaout);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_params_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*params), &_hidl_params_parent,  reinterpret_cast<const void **>(&params));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_params_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*params),
            _hidl_data,
            _hidl_params_parent,
            0 /* parentOffset */, &_hidl_params_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    (void)sc;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptForEach::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)vains);
        _hidl_args.push_back((void *)&vaout);
        _hidl_args.push_back((void *)params);
        _hidl_args.push_back((void *)&sc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptForEach", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptForEach(vs, slot, *vains, vaout, *params, sc);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptForEach", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptReduce(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t vs;
    uint32_t slot;
    const ::android::hardware::hidl_vec<uint64_t>* vains;
    uint64_t vaout;
    void* sc;

    _hidl_err = _hidl_data.readUint64(&vs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_vains_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*vains), &_hidl_vains_parent,  reinterpret_cast<const void **>(&vains));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_vains_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(*vains),
            _hidl_data,
            _hidl_vains_parent,
            0 /* parentOffset */, &_hidl_vains_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&vaout);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    (void)sc;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptReduce::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)vains);
        _hidl_args.push_back((void *)&vaout);
        _hidl_args.push_back((void *)&sc);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptReduce", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptReduce(vs, slot, *vains, vaout, sc);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptReduce", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptSetVarI(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t vs;
    uint32_t slot;
    int32_t value;

    _hidl_err = _hidl_data.readUint64(&vs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&value);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptSetVarI::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&value);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarI", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptSetVarI(vs, slot, value);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarI", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptSetVarObj(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t vs;
    uint32_t slot;
    uint64_t obj;

    _hidl_err = _hidl_data.readUint64(&vs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&obj);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptSetVarObj::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&obj);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarObj", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptSetVarObj(vs, slot, obj);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarObj", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptSetVarJ(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t vs;
    uint32_t slot;
    int64_t value;

    _hidl_err = _hidl_data.readUint64(&vs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt64(&value);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptSetVarJ::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&value);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarJ", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptSetVarJ(vs, slot, value);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarJ", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptSetVarF(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t vs;
    uint32_t slot;
    float value;

    _hidl_err = _hidl_data.readUint64(&vs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readFloat(&value);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptSetVarF::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&value);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarF", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptSetVarF(vs, slot, value);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarF", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptSetVarD(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t vs;
    uint32_t slot;
    double value;

    _hidl_err = _hidl_data.readUint64(&vs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readDouble(&value);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptSetVarD::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&value);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarD", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptSetVarD(vs, slot, value);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarD", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptSetVarV(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t vs;
    uint32_t slot;
    const ::android::hardware::hidl_vec<uint8_t>* data;

    _hidl_err = _hidl_data.readUint64(&vs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*data), &_hidl_data_parent,  reinterpret_cast<const void **>(&data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*data),
            _hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptSetVarV::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarV", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptSetVarV(vs, slot, *data);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarV", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptGetVarV(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t vs;
    uint32_t slot;
    uint64_t len;

    _hidl_err = _hidl_data.readUint64(&vs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&len);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptGetVarV::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)&len);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptGetVarV", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptGetVarV(vs, slot, len, [&](const auto &_hidl_out_data) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("scriptGetVarV: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_data_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_data, sizeof(_hidl_out_data), &_hidl__hidl_out_data_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_data_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_data,
                _hidl_reply,
                _hidl__hidl_out_data_parent,
                0 /* parentOffset */, &_hidl__hidl_out_data_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_data);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptGetVarV", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("scriptGetVarV: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptSetVarVE(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t vs;
    uint32_t slot;
    const ::android::hardware::hidl_vec<uint8_t>* data;
    uint64_t ve;
    const ::android::hardware::hidl_vec<uint32_t>* dims;

    _hidl_err = _hidl_data.readUint64(&vs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&slot);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*data), &_hidl_data_parent,  reinterpret_cast<const void **>(&data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*data),
            _hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&ve);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dims_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dims), &_hidl_dims_parent,  reinterpret_cast<const void **>(&dims));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dims_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(*dims),
            _hidl_data,
            _hidl_dims_parent,
            0 /* parentOffset */, &_hidl_dims_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptSetVarVE::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&vs);
        _hidl_args.push_back((void *)&slot);
        _hidl_args.push_back((void *)data);
        _hidl_args.push_back((void *)&ve);
        _hidl_args.push_back((void *)dims);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarVE", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptSetVarVE(vs, slot, *data, ve, *dims);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptSetVarVE", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptCCreate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* resName;
    const ::android::hardware::hidl_string* cacheDir;
    const ::android::hardware::hidl_vec<uint8_t>* text;

    size_t _hidl_resName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*resName), &_hidl_resName_parent,  reinterpret_cast<const void **>(&resName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*resName),
            _hidl_data,
            _hidl_resName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_cacheDir_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*cacheDir), &_hidl_cacheDir_parent,  reinterpret_cast<const void **>(&cacheDir));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*cacheDir),
            _hidl_data,
            _hidl_cacheDir_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_text_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*text), &_hidl_text_parent,  reinterpret_cast<const void **>(&text));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_text_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*text),
            _hidl_data,
            _hidl_text_parent,
            0 /* parentOffset */, &_hidl_text_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptCCreate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)resName);
        _hidl_args.push_back((void *)cacheDir);
        _hidl_args.push_back((void *)text);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptCCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_script = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptCCreate(*resName, *cacheDir, *text);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_script);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_script);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptCCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwContext::_hidl_scriptIntrinsicCreate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwContext::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::renderscript::V1_0::ScriptIntrinsicID id;
    uint64_t elem;

    _hidl_err = _hidl_data.readInt32((int32_t *)&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&elem);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IContext::scriptIntrinsicCreate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&elem);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.renderscript", "1.0", "IContext", "scriptIntrinsicCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint64_t _hidl_out_script = static_cast<IContext*>(_hidl_this->getImpl().get())->scriptIntrinsicCreate(id, elem);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint64(_hidl_out_script);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_script);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.renderscript", "1.0", "IContext", "scriptIntrinsicCreate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::renderscript::V1_0::IContext follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwContext::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwContext::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwContext::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* allocationAdapterCreate */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationAdapterCreate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* allocationAdapterOffset */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationAdapterOffset(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* allocationGetType */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationGetType(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* allocationCreateTyped */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationCreateTyped(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* allocationCreateFromBitmap */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationCreateFromBitmap(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* allocationCubeCreateFromBitmap */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationCubeCreateFromBitmap(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* allocationGetNativeWindow */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationGetNativeWindow(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* allocationSetNativeWindow */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationSetNativeWindow(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* allocationSetupBufferQueue */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationSetupBufferQueue(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* allocationShareBufferQueue */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationShareBufferQueue(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* allocationCopyToBitmap */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationCopyToBitmap(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* allocation1DWrite */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocation1DWrite(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* allocationElementWrite */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationElementWrite(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* allocation2DWrite */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocation2DWrite(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* allocation3DWrite */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocation3DWrite(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* allocationGenerateMipmaps */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationGenerateMipmaps(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* allocationRead */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationRead(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* allocation1DRead */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocation1DRead(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 19 /* allocationElementRead */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationElementRead(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 20 /* allocation2DRead */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocation2DRead(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 21 /* allocation3DRead */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocation3DRead(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 22 /* allocationSyncAll */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationSyncAll(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 23 /* allocationResize1D */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationResize1D(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 24 /* allocationCopy2DRange */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationCopy2DRange(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 25 /* allocationCopy3DRange */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationCopy3DRange(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 26 /* allocationIoSend */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationIoSend(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 27 /* allocationIoReceive */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationIoReceive(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 28 /* allocationGetPointer */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_allocationGetPointer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 29 /* elementGetNativeMetadata */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_elementGetNativeMetadata(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 30 /* elementGetSubElements */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_elementGetSubElements(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 31 /* elementCreate */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_elementCreate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 32 /* elementComplexCreate */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_elementComplexCreate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 33 /* typeGetNativeMetadata */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_typeGetNativeMetadata(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 34 /* typeCreate */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_typeCreate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 35 /* contextDestroy */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_contextDestroy(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 36 /* contextGetMessage */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_contextGetMessage(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 37 /* contextPeekMessage */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_contextPeekMessage(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 38 /* contextSendMessage */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_contextSendMessage(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 39 /* contextInitToClient */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_contextInitToClient(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 40 /* contextDeinitToClient */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_contextDeinitToClient(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 41 /* contextFinish */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_contextFinish(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 42 /* contextLog */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_contextLog(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 43 /* contextSetCacheDir */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_contextSetCacheDir(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 44 /* contextSetPriority */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_contextSetPriority(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 45 /* assignName */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_assignName(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 46 /* getName */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_getName(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 47 /* closureCreate */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_closureCreate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 48 /* invokeClosureCreate */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_invokeClosureCreate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 49 /* closureSetArg */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_closureSetArg(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 50 /* closureSetGlobal */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_closureSetGlobal(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 51 /* scriptKernelIDCreate */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptKernelIDCreate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 52 /* scriptInvokeIDCreate */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptInvokeIDCreate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 53 /* scriptFieldIDCreate */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptFieldIDCreate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 54 /* scriptGroupCreate */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptGroupCreate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 55 /* scriptGroup2Create */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptGroup2Create(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 56 /* scriptGroupSetOutput */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptGroupSetOutput(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 57 /* scriptGroupSetInput */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptGroupSetInput(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 58 /* scriptGroupExecute */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptGroupExecute(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 59 /* objDestroy */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_objDestroy(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 60 /* samplerCreate */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_samplerCreate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 61 /* scriptBindAllocation */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptBindAllocation(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 62 /* scriptSetTimeZone */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptSetTimeZone(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 63 /* scriptInvoke */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptInvoke(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 64 /* scriptInvokeV */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptInvokeV(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 65 /* scriptForEach */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptForEach(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 66 /* scriptReduce */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptReduce(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 67 /* scriptSetVarI */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptSetVarI(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 68 /* scriptSetVarObj */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptSetVarObj(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 69 /* scriptSetVarJ */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptSetVarJ(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 70 /* scriptSetVarF */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptSetVarF(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 71 /* scriptSetVarD */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptSetVarD(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 72 /* scriptSetVarV */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptSetVarV(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 73 /* scriptGetVarV */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptGetVarV(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 74 /* scriptSetVarVE */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptSetVarVE(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 75 /* scriptCCreate */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptCCreate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 76 /* scriptIntrinsicCreate */:
        {
            _hidl_err = ::android::hardware::renderscript::V1_0::BnHwContext::_hidl_scriptIntrinsicCreate(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsContext::BsContext(const ::android::sp<::android::hardware::renderscript::V1_0::IContext> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.renderscript@1.0", "IContext"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsContext::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IContext> IContext::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwContext>(serviceName, false, getStub);
}

::android::sp<IContext> IContext::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwContext>(serviceName, true, getStub);
}

::android::status_t IContext::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IContext::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.renderscript@1.0::IContext",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace renderscript
}  // namespace hardware
}  // namespace android
