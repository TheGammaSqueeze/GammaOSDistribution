#define LOG_TAG "android.hardware.drm@1.4::CryptoPlugin"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/drm/1.4/BpHwCryptoPlugin.h>
#include <android/hardware/drm/1.4/BnHwCryptoPlugin.h>
#include <android/hardware/drm/1.4/BsCryptoPlugin.h>
#include <android/hardware/drm/1.2/BpHwCryptoPlugin.h>
#include <android/hardware/drm/1.0/BpHwCryptoPlugin.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace drm {
namespace V1_4 {

const char* ICryptoPlugin::descriptor("android.hardware.drm@1.4::ICryptoPlugin");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ICryptoPlugin::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwCryptoPlugin(static_cast<ICryptoPlugin *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ICryptoPlugin::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsCryptoPlugin(static_cast<ICryptoPlugin *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ICryptoPlugin::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ICryptoPlugin::descriptor);
}

// Methods from ::android::hardware::drm::V1_0::ICryptoPlugin follow.
// no default implementation for: ::android::hardware::Return<bool> ICryptoPlugin::requiresSecureDecoderComponent(const ::android::hardware::hidl_string& mime)
// no default implementation for: ::android::hardware::Return<void> ICryptoPlugin::notifyResolution(uint32_t width, uint32_t height)
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> ICryptoPlugin::setMediaDrmSession(const ::android::hardware::hidl_vec<uint8_t>& sessionId)
// no default implementation for: ::android::hardware::Return<void> ICryptoPlugin::setSharedBufferBase(const ::android::hardware::hidl_memory& base, uint32_t bufferId)
// no default implementation for: ::android::hardware::Return<void> ICryptoPlugin::decrypt(bool secure, const ::android::hardware::hidl_array<uint8_t, 16>& keyId, const ::android::hardware::hidl_array<uint8_t, 16>& iv, ::android::hardware::drm::V1_0::Mode mode, const ::android::hardware::drm::V1_0::Pattern& pattern, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::SubSample>& subSamples, const ::android::hardware::drm::V1_0::SharedBuffer& source, uint64_t offset, const ::android::hardware::drm::V1_0::DestinationBuffer& destination, decrypt_cb _hidl_cb)

// Methods from ::android::hardware::drm::V1_2::ICryptoPlugin follow.
// no default implementation for: ::android::hardware::Return<void> ICryptoPlugin::decrypt_1_2(bool secure, const ::android::hardware::hidl_array<uint8_t, 16>& keyId, const ::android::hardware::hidl_array<uint8_t, 16>& iv, ::android::hardware::drm::V1_0::Mode mode, const ::android::hardware::drm::V1_0::Pattern& pattern, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::SubSample>& subSamples, const ::android::hardware::drm::V1_0::SharedBuffer& source, uint64_t offset, const ::android::hardware::drm::V1_0::DestinationBuffer& destination, decrypt_1_2_cb _hidl_cb)

// Methods from ::android::hardware::drm::V1_4::ICryptoPlugin follow.
// no default implementation for: ::android::hardware::Return<void> ICryptoPlugin::getLogMessages(getLogMessages_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ICryptoPlugin::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::drm::V1_4::ICryptoPlugin::descriptor,
        ::android::hardware::drm::V1_2::ICryptoPlugin::descriptor,
        ::android::hardware::drm::V1_0::ICryptoPlugin::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICryptoPlugin::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICryptoPlugin::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::drm::V1_4::ICryptoPlugin::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICryptoPlugin::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){14,150,231,105,158,231,77,101,67,42,135,18,230,178,71,75,66,90,58,7,156,85,244,227,18,42,166,95,242,183,120,164} /* 0e96e7699ee74d65432a8712e6b2474b425a3a079c55f4e3122aa65ff2b778a4 */,
        (uint8_t[32]){72,149,249,142,158,242,16,233,172,176,25,130,245,208,123,101,69,56,55,126,20,4,184,219,94,25,231,133,136,53,233,216} /* 4895f98e9ef210e9acb01982f5d07b654538377e1404b8db5e19e7858835e9d8 */,
        (uint8_t[32]){131,99,158,144,202,235,153,107,2,116,228,32,222,60,213,86,119,157,225,202,72,70,75,104,238,231,153,190,243,43,52,205} /* 83639e90caeb996b0274e420de3cd556779de1ca48464b68eee799bef32b34cd */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICryptoPlugin::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICryptoPlugin::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ICryptoPlugin::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICryptoPlugin::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ICryptoPlugin::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICryptoPlugin::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::drm::V1_4::ICryptoPlugin>> ICryptoPlugin::castFrom(const ::android::sp<::android::hardware::drm::V1_4::ICryptoPlugin>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::drm::V1_4::ICryptoPlugin>> ICryptoPlugin::castFrom(const ::android::sp<::android::hardware::drm::V1_2::ICryptoPlugin>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICryptoPlugin, ::android::hardware::drm::V1_2::ICryptoPlugin, BpHwCryptoPlugin>(
            parent, "android.hardware.drm@1.4::ICryptoPlugin", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::drm::V1_4::ICryptoPlugin>> ICryptoPlugin::castFrom(const ::android::sp<::android::hardware::drm::V1_0::ICryptoPlugin>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICryptoPlugin, ::android::hardware::drm::V1_0::ICryptoPlugin, BpHwCryptoPlugin>(
            parent, "android.hardware.drm@1.4::ICryptoPlugin", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::drm::V1_4::ICryptoPlugin>> ICryptoPlugin::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICryptoPlugin, ::android::hidl::base::V1_0::IBase, BpHwCryptoPlugin>(
            parent, "android.hardware.drm@1.4::ICryptoPlugin", emitError);
}

BpHwCryptoPlugin::BpHwCryptoPlugin(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ICryptoPlugin>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.drm@1.4", "ICryptoPlugin") {
}

void BpHwCryptoPlugin::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ICryptoPlugin>::onLastStrongRef(id);
}
// Methods from ::android::hardware::drm::V1_4::ICryptoPlugin follow.
::android::hardware::Return<void> BpHwCryptoPlugin::_hidl_getLogMessages(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getLogMessages_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICryptoPlugin::getLogMessages::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.4", "ICryptoPlugin", "getLogMessages", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCryptoPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* getLogMessages */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_4::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<::android::hardware::drm::V1_4::LogMessage>* _hidl_out_logMessages;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_logMessages_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_logMessages), &_hidl__hidl_out_logMessages_parent,  reinterpret_cast<const void **>(&_hidl_out_logMessages));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_logMessages_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::drm::V1_4::LogMessage> &>(*_hidl_out_logMessages),
                _hidl_reply,
                _hidl__hidl_out_logMessages_parent,
                0 /* parentOffset */, &_hidl__hidl_out_logMessages_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_logMessages->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::drm::V1_4::LogMessage &>((*_hidl_out_logMessages)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_logMessages_child,
                    _hidl_index_0 * sizeof(::android::hardware::drm::V1_4::LogMessage));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_cb(_hidl_out_status, *_hidl_out_logMessages);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_logMessages);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.4", "ICryptoPlugin", "getLogMessages", &_hidl_args);
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


// Methods from ::android::hardware::drm::V1_0::ICryptoPlugin follow.
::android::hardware::Return<bool> BpHwCryptoPlugin::requiresSecureDecoderComponent(const ::android::hardware::hidl_string& mime){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::drm::V1_0::BpHwCryptoPlugin::_hidl_requiresSecureDecoderComponent(this, this, mime);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoPlugin::notifyResolution(uint32_t width, uint32_t height){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwCryptoPlugin::_hidl_notifyResolution(this, this, width, height);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwCryptoPlugin::setMediaDrmSession(const ::android::hardware::hidl_vec<uint8_t>& sessionId){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_0::BpHwCryptoPlugin::_hidl_setMediaDrmSession(this, this, sessionId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoPlugin::setSharedBufferBase(const ::android::hardware::hidl_memory& base, uint32_t bufferId){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwCryptoPlugin::_hidl_setSharedBufferBase(this, this, base, bufferId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoPlugin::decrypt(bool secure, const ::android::hardware::hidl_array<uint8_t, 16>& keyId, const ::android::hardware::hidl_array<uint8_t, 16>& iv, ::android::hardware::drm::V1_0::Mode mode, const ::android::hardware::drm::V1_0::Pattern& pattern, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::SubSample>& subSamples, const ::android::hardware::drm::V1_0::SharedBuffer& source, uint64_t offset, const ::android::hardware::drm::V1_0::DestinationBuffer& destination, decrypt_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwCryptoPlugin::_hidl_decrypt(this, this, secure, keyId, iv, mode, pattern, subSamples, source, offset, destination, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hardware::drm::V1_2::ICryptoPlugin follow.
::android::hardware::Return<void> BpHwCryptoPlugin::decrypt_1_2(bool secure, const ::android::hardware::hidl_array<uint8_t, 16>& keyId, const ::android::hardware::hidl_array<uint8_t, 16>& iv, ::android::hardware::drm::V1_0::Mode mode, const ::android::hardware::drm::V1_0::Pattern& pattern, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::SubSample>& subSamples, const ::android::hardware::drm::V1_0::SharedBuffer& source, uint64_t offset, const ::android::hardware::drm::V1_0::DestinationBuffer& destination, decrypt_1_2_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_2::BpHwCryptoPlugin::_hidl_decrypt_1_2(this, this, secure, keyId, iv, mode, pattern, subSamples, source, offset, destination, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hardware::drm::V1_4::ICryptoPlugin follow.
::android::hardware::Return<void> BpHwCryptoPlugin::getLogMessages(getLogMessages_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_4::BpHwCryptoPlugin::_hidl_getLogMessages(this, this, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwCryptoPlugin::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoPlugin::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoPlugin::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoPlugin::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoPlugin::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCryptoPlugin::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwCryptoPlugin::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoPlugin::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoPlugin::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCryptoPlugin::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwCryptoPlugin::BnHwCryptoPlugin(const ::android::sp<ICryptoPlugin> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.drm@1.4", "ICryptoPlugin") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwCryptoPlugin::~BnHwCryptoPlugin() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::drm::V1_4::ICryptoPlugin follow.
::android::status_t BnHwCryptoPlugin::_hidl_getLogMessages(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCryptoPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICryptoPlugin::getLogMessages::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.4", "ICryptoPlugin", "getLogMessages", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICryptoPlugin*>(_hidl_this->getImpl().get())->getLogMessages([&](const auto &_hidl_out_status, const auto &_hidl_out_logMessages) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getLogMessages: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_logMessages_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_logMessages, sizeof(_hidl_out_logMessages), &_hidl__hidl_out_logMessages_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_logMessages_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_logMessages,
                _hidl_reply,
                _hidl__hidl_out_logMessages_parent,
                0 /* parentOffset */, &_hidl__hidl_out_logMessages_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_logMessages.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_logMessages[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_logMessages_child,
                    _hidl_index_0 * sizeof(::android::hardware::drm::V1_4::LogMessage));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_logMessages);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.4", "ICryptoPlugin", "getLogMessages", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getLogMessages: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::drm::V1_0::ICryptoPlugin follow.

// Methods from ::android::hardware::drm::V1_2::ICryptoPlugin follow.

// Methods from ::android::hardware::drm::V1_4::ICryptoPlugin follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwCryptoPlugin::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwCryptoPlugin::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwCryptoPlugin::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* requiresSecureDecoderComponent */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwCryptoPlugin::_hidl_requiresSecureDecoderComponent(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* notifyResolution */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwCryptoPlugin::_hidl_notifyResolution(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* setMediaDrmSession */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwCryptoPlugin::_hidl_setMediaDrmSession(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* setSharedBufferBase */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwCryptoPlugin::_hidl_setSharedBufferBase(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* decrypt */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwCryptoPlugin::_hidl_decrypt(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* decrypt_1_2 */:
        {
            _hidl_err = ::android::hardware::drm::V1_2::BnHwCryptoPlugin::_hidl_decrypt_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* getLogMessages */:
        {
            _hidl_err = ::android::hardware::drm::V1_4::BnHwCryptoPlugin::_hidl_getLogMessages(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsCryptoPlugin::BsCryptoPlugin(const ::android::sp<::android::hardware::drm::V1_4::ICryptoPlugin> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.drm@1.4", "ICryptoPlugin"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsCryptoPlugin::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ICryptoPlugin> ICryptoPlugin::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCryptoPlugin>(serviceName, false, getStub);
}

::android::sp<ICryptoPlugin> ICryptoPlugin::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCryptoPlugin>(serviceName, true, getStub);
}

::android::status_t ICryptoPlugin::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ICryptoPlugin::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.drm@1.4::ICryptoPlugin",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_4
}  // namespace drm
}  // namespace hardware
}  // namespace android
