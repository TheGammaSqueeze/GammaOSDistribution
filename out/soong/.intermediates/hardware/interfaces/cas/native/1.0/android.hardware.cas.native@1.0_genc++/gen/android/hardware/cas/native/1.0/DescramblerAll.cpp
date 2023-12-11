#define LOG_TAG "android.hardware.cas.native@1.0::Descrambler"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/cas/native/1.0/BpHwDescrambler.h>
#include <android/hardware/cas/native/1.0/BnHwDescrambler.h>
#include <android/hardware/cas/native/1.0/BsDescrambler.h>
#include <android/hardware/cas/1.0/BpHwDescramblerBase.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace cas {
namespace native {
namespace V1_0 {

const char* IDescrambler::descriptor("android.hardware.cas.native@1.0::IDescrambler");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IDescrambler::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwDescrambler(static_cast<IDescrambler *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IDescrambler::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsDescrambler(static_cast<IDescrambler *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IDescrambler::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IDescrambler::descriptor);
}

// Methods from ::android::hardware::cas::V1_0::IDescramblerBase follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::cas::V1_0::Status> IDescrambler::setMediaCasSession(const ::android::hardware::hidl_vec<uint8_t>& sessionId)
// no default implementation for: ::android::hardware::Return<bool> IDescrambler::requiresSecureDecoderComponent(const ::android::hardware::hidl_string& mime)
// no default implementation for: ::android::hardware::Return<::android::hardware::cas::V1_0::Status> IDescrambler::release()

// Methods from ::android::hardware::cas::native::V1_0::IDescrambler follow.
// no default implementation for: ::android::hardware::Return<void> IDescrambler::descramble(::android::hardware::cas::native::V1_0::ScramblingControl scramblingControl, const ::android::hardware::hidl_vec<::android::hardware::cas::native::V1_0::SubSample>& subSamples, const ::android::hardware::cas::native::V1_0::SharedBuffer& srcBuffer, uint64_t srcOffset, const ::android::hardware::cas::native::V1_0::DestinationBuffer& dstBuffer, uint64_t dstOffset, descramble_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IDescrambler::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::cas::native::V1_0::IDescrambler::descriptor,
        ::android::hardware::cas::V1_0::IDescramblerBase::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDescrambler::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDescrambler::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::cas::native::V1_0::IDescrambler::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDescrambler::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){97,150,0,16,146,50,237,100,184,39,200,161,27,238,216,7,11,24,39,174,70,69,71,215,170,20,108,240,71,59,75,202} /* 619600109232ed64b827c8a11beed8070b1827ae464547d7aa146cf0473b4bca */,
        (uint8_t[32]){164,50,214,217,32,2,72,220,33,38,130,123,205,108,222,163,29,214,94,255,57,185,57,246,69,133,210,125,145,90,88,87} /* a432d6d9200248dc2126827bcd6cdea31dd65eff39b939f64585d27d915a5857 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDescrambler::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IDescrambler::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IDescrambler::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDescrambler::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IDescrambler::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IDescrambler::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::cas::native::V1_0::IDescrambler>> IDescrambler::castFrom(const ::android::sp<::android::hardware::cas::native::V1_0::IDescrambler>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::cas::native::V1_0::IDescrambler>> IDescrambler::castFrom(const ::android::sp<::android::hardware::cas::V1_0::IDescramblerBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDescrambler, ::android::hardware::cas::V1_0::IDescramblerBase, BpHwDescrambler>(
            parent, "android.hardware.cas.native@1.0::IDescrambler", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::cas::native::V1_0::IDescrambler>> IDescrambler::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDescrambler, ::android::hidl::base::V1_0::IBase, BpHwDescrambler>(
            parent, "android.hardware.cas.native@1.0::IDescrambler", emitError);
}

BpHwDescrambler::BpHwDescrambler(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IDescrambler>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.cas.native@1.0", "IDescrambler") {
}

void BpHwDescrambler::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IDescrambler>::onLastStrongRef(id);
}
// Methods from ::android::hardware::cas::native::V1_0::IDescrambler follow.
::android::hardware::Return<void> BpHwDescrambler::_hidl_descramble(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::cas::native::V1_0::ScramblingControl scramblingControl, const ::android::hardware::hidl_vec<::android::hardware::cas::native::V1_0::SubSample>& subSamples, const ::android::hardware::cas::native::V1_0::SharedBuffer& srcBuffer, uint64_t srcOffset, const ::android::hardware::cas::native::V1_0::DestinationBuffer& dstBuffer, uint64_t dstOffset, descramble_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDescrambler::descramble::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&scramblingControl);
        _hidl_args.push_back((void *)&subSamples);
        _hidl_args.push_back((void *)&srcBuffer);
        _hidl_args.push_back((void *)&srcOffset);
        _hidl_args.push_back((void *)&dstBuffer);
        _hidl_args.push_back((void *)&dstOffset);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.cas.native", "1.0", "IDescrambler", "descramble", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDescrambler::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32((uint32_t)scramblingControl);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_subSamples_parent;

    _hidl_err = _hidl_data.writeBuffer(&subSamples, sizeof(subSamples), &_hidl_subSamples_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_subSamples_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            subSamples,
            &_hidl_data,
            _hidl_subSamples_parent,
            0 /* parentOffset */, &_hidl_subSamples_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_srcBuffer_parent;

    _hidl_err = _hidl_data.writeBuffer(&srcBuffer, sizeof(srcBuffer), &_hidl_srcBuffer_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            srcBuffer,
            &_hidl_data,
            _hidl_srcBuffer_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(srcOffset);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dstBuffer_parent;

    _hidl_err = _hidl_data.writeBuffer(&dstBuffer, sizeof(dstBuffer), &_hidl_dstBuffer_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            dstBuffer,
            &_hidl_data,
            _hidl_dstBuffer_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(dstOffset);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* descramble */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::cas::V1_0::Status _hidl_out_status;
        uint32_t _hidl_out_bytesWritten;
        const ::android::hardware::hidl_string* _hidl_out_detailedError;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_bytesWritten);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_detailedError_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_detailedError), &_hidl__hidl_out_detailedError_parent,  reinterpret_cast<const void **>(&_hidl_out_detailedError));

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(*_hidl_out_detailedError),
                _hidl_reply,
                _hidl__hidl_out_detailedError_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_bytesWritten, *_hidl_out_detailedError);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_bytesWritten);
            _hidl_args.push_back((void *)_hidl_out_detailedError);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.cas.native", "1.0", "IDescrambler", "descramble", &_hidl_args);
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


// Methods from ::android::hardware::cas::V1_0::IDescramblerBase follow.
::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwDescrambler::setMediaCasSession(const ::android::hardware::hidl_vec<uint8_t>& sessionId){
    ::android::hardware::Return<::android::hardware::cas::V1_0::Status>  _hidl_out = ::android::hardware::cas::V1_0::BpHwDescramblerBase::_hidl_setMediaCasSession(this, this, sessionId);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwDescrambler::requiresSecureDecoderComponent(const ::android::hardware::hidl_string& mime){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::cas::V1_0::BpHwDescramblerBase::_hidl_requiresSecureDecoderComponent(this, this, mime);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwDescrambler::release(){
    ::android::hardware::Return<::android::hardware::cas::V1_0::Status>  _hidl_out = ::android::hardware::cas::V1_0::BpHwDescramblerBase::_hidl_release(this, this);

    return _hidl_out;
}


// Methods from ::android::hardware::cas::native::V1_0::IDescrambler follow.
::android::hardware::Return<void> BpHwDescrambler::descramble(::android::hardware::cas::native::V1_0::ScramblingControl scramblingControl, const ::android::hardware::hidl_vec<::android::hardware::cas::native::V1_0::SubSample>& subSamples, const ::android::hardware::cas::native::V1_0::SharedBuffer& srcBuffer, uint64_t srcOffset, const ::android::hardware::cas::native::V1_0::DestinationBuffer& dstBuffer, uint64_t dstOffset, descramble_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::cas::native::V1_0::BpHwDescrambler::_hidl_descramble(this, this, scramblingControl, subSamples, srcBuffer, srcOffset, dstBuffer, dstOffset, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwDescrambler::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDescrambler::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDescrambler::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDescrambler::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDescrambler::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwDescrambler::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwDescrambler::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDescrambler::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDescrambler::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwDescrambler::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwDescrambler::BnHwDescrambler(const ::android::sp<IDescrambler> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.cas.native@1.0", "IDescrambler") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwDescrambler::~BnHwDescrambler() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::cas::native::V1_0::IDescrambler follow.
::android::status_t BnHwDescrambler::_hidl_descramble(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDescrambler::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::cas::native::V1_0::ScramblingControl scramblingControl;
    const ::android::hardware::hidl_vec<::android::hardware::cas::native::V1_0::SubSample>* subSamples;
    ::android::hardware::cas::native::V1_0::SharedBuffer* srcBuffer;
    uint64_t srcOffset;
    ::android::hardware::cas::native::V1_0::DestinationBuffer* dstBuffer;
    uint64_t dstOffset;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&scramblingControl);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_subSamples_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*subSamples), &_hidl_subSamples_parent,  reinterpret_cast<const void **>(&subSamples));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_subSamples_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::cas::native::V1_0::SubSample> &>(*subSamples),
            _hidl_data,
            _hidl_subSamples_parent,
            0 /* parentOffset */, &_hidl_subSamples_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_srcBuffer_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*srcBuffer), &_hidl_srcBuffer_parent,  const_cast<const void**>(reinterpret_cast<void **>(&srcBuffer)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::cas::native::V1_0::SharedBuffer &>(*srcBuffer),
            _hidl_data,
            _hidl_srcBuffer_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&srcOffset);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dstBuffer_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dstBuffer), &_hidl_dstBuffer_parent,  const_cast<const void**>(reinterpret_cast<void **>(&dstBuffer)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::cas::native::V1_0::DestinationBuffer &>(*dstBuffer),
            _hidl_data,
            _hidl_dstBuffer_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&dstOffset);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDescrambler::descramble::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&scramblingControl);
        _hidl_args.push_back((void *)subSamples);
        _hidl_args.push_back((void *)srcBuffer);
        _hidl_args.push_back((void *)&srcOffset);
        _hidl_args.push_back((void *)dstBuffer);
        _hidl_args.push_back((void *)&dstOffset);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.cas.native", "1.0", "IDescrambler", "descramble", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDescrambler*>(_hidl_this->getImpl().get())->descramble(scramblingControl, *subSamples, *srcBuffer, srcOffset, *dstBuffer, dstOffset, [&](const auto &_hidl_out_status, const auto &_hidl_out_bytesWritten, const auto &_hidl_out_detailedError) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("descramble: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_bytesWritten);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_detailedError_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_detailedError, sizeof(_hidl_out_detailedError), &_hidl__hidl_out_detailedError_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_detailedError,
                _hidl_reply,
                _hidl__hidl_out_detailedError_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_bytesWritten);
            _hidl_args.push_back((void *)&_hidl_out_detailedError);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.cas.native", "1.0", "IDescrambler", "descramble", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("descramble: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::cas::V1_0::IDescramblerBase follow.

// Methods from ::android::hardware::cas::native::V1_0::IDescrambler follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwDescrambler::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwDescrambler::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwDescrambler::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* setMediaCasSession */:
        {
            _hidl_err = ::android::hardware::cas::V1_0::BnHwDescramblerBase::_hidl_setMediaCasSession(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* requiresSecureDecoderComponent */:
        {
            _hidl_err = ::android::hardware::cas::V1_0::BnHwDescramblerBase::_hidl_requiresSecureDecoderComponent(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* release */:
        {
            _hidl_err = ::android::hardware::cas::V1_0::BnHwDescramblerBase::_hidl_release(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* descramble */:
        {
            _hidl_err = ::android::hardware::cas::native::V1_0::BnHwDescrambler::_hidl_descramble(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsDescrambler::BsDescrambler(const ::android::sp<::android::hardware::cas::native::V1_0::IDescrambler> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.cas.native@1.0", "IDescrambler"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsDescrambler::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IDescrambler> IDescrambler::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwDescrambler>(serviceName, false, getStub);
}

::android::sp<IDescrambler> IDescrambler::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwDescrambler>(serviceName, true, getStub);
}

::android::status_t IDescrambler::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IDescrambler::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.cas.native@1.0::IDescrambler",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace native
}  // namespace cas
}  // namespace hardware
}  // namespace android
