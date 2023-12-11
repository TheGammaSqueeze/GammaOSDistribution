#define LOG_TAG "android.hardware.drm@1.0::DrmPlugin"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/drm/1.0/BpHwDrmPlugin.h>
#include <android/hardware/drm/1.0/BnHwDrmPlugin.h>
#include <android/hardware/drm/1.0/BsDrmPlugin.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace drm {
namespace V1_0 {

const char* IDrmPlugin::descriptor("android.hardware.drm@1.0::IDrmPlugin");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IDrmPlugin::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwDrmPlugin(static_cast<IDrmPlugin *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IDrmPlugin::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsDrmPlugin(static_cast<IDrmPlugin *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IDrmPlugin::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IDrmPlugin::descriptor);
}

// Methods from ::android::hardware::drm::V1_0::IDrmPlugin follow.
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::openSession(openSession_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> IDrmPlugin::closeSession(const ::android::hardware::hidl_vec<uint8_t>& sessionId)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getKeyRequest(const ::android::hardware::hidl_vec<uint8_t>& scope, const ::android::hardware::hidl_vec<uint8_t>& initData, const ::android::hardware::hidl_string& mimeType, ::android::hardware::drm::V1_0::KeyType keyType, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyValue>& optionalParameters, getKeyRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::provideKeyResponse(const ::android::hardware::hidl_vec<uint8_t>& scope, const ::android::hardware::hidl_vec<uint8_t>& response, provideKeyResponse_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> IDrmPlugin::removeKeys(const ::android::hardware::hidl_vec<uint8_t>& sessionId)
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> IDrmPlugin::restoreKeys(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keySetId)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::queryKeyStatus(const ::android::hardware::hidl_vec<uint8_t>& sessionId, queryKeyStatus_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getProvisionRequest(const ::android::hardware::hidl_string& certificateType, const ::android::hardware::hidl_string& certificateAuthority, getProvisionRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::provideProvisionResponse(const ::android::hardware::hidl_vec<uint8_t>& response, provideProvisionResponse_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getSecureStops(getSecureStops_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getSecureStop(const ::android::hardware::hidl_vec<uint8_t>& secureStopId, getSecureStop_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> IDrmPlugin::releaseAllSecureStops()
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> IDrmPlugin::releaseSecureStop(const ::android::hardware::hidl_vec<uint8_t>& secureStopId)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getPropertyString(const ::android::hardware::hidl_string& propertyName, getPropertyString_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getPropertyByteArray(const ::android::hardware::hidl_string& propertyName, getPropertyByteArray_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> IDrmPlugin::setPropertyString(const ::android::hardware::hidl_string& propertyName, const ::android::hardware::hidl_string& value)
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> IDrmPlugin::setPropertyByteArray(const ::android::hardware::hidl_string& propertyName, const ::android::hardware::hidl_vec<uint8_t>& value)
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> IDrmPlugin::setCipherAlgorithm(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_string& algorithm)
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> IDrmPlugin::setMacAlgorithm(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_string& algorithm)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::encrypt(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keyId, const ::android::hardware::hidl_vec<uint8_t>& input, const ::android::hardware::hidl_vec<uint8_t>& iv, encrypt_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::decrypt(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keyId, const ::android::hardware::hidl_vec<uint8_t>& input, const ::android::hardware::hidl_vec<uint8_t>& iv, decrypt_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::sign(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keyId, const ::android::hardware::hidl_vec<uint8_t>& message, sign_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::verify(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keyId, const ::android::hardware::hidl_vec<uint8_t>& message, const ::android::hardware::hidl_vec<uint8_t>& signature, verify_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::signRSA(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_string& algorithm, const ::android::hardware::hidl_vec<uint8_t>& message, const ::android::hardware::hidl_vec<uint8_t>& wrappedkey, signRSA_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::setListener(const ::android::sp<::android::hardware::drm::V1_0::IDrmPluginListener>& listener)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::sendEvent(::android::hardware::drm::V1_0::EventType eventType, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& data)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::sendExpirationUpdate(const ::android::hardware::hidl_vec<uint8_t>& sessionId, int64_t expiryTimeInMS)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::sendKeysChange(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyStatus>& keyStatusList, bool hasNewUsableKey)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IDrmPlugin::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::drm::V1_0::IDrmPlugin::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDrmPlugin::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDrmPlugin::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::drm::V1_0::IDrmPlugin::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDrmPlugin::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){120,186,51,177,8,246,32,230,160,238,192,30,246,84,84,126,105,168,87,84,87,142,164,201,239,3,236,32,95,22,18,28} /* 78ba33b108f620e6a0eec01ef654547e69a85754578ea4c9ef03ec205f16121c */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDrmPlugin::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IDrmPlugin::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IDrmPlugin::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDrmPlugin::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IDrmPlugin::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IDrmPlugin::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::drm::V1_0::IDrmPlugin>> IDrmPlugin::castFrom(const ::android::sp<::android::hardware::drm::V1_0::IDrmPlugin>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::drm::V1_0::IDrmPlugin>> IDrmPlugin::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDrmPlugin, ::android::hidl::base::V1_0::IBase, BpHwDrmPlugin>(
            parent, "android.hardware.drm@1.0::IDrmPlugin", emitError);
}

BpHwDrmPlugin::BpHwDrmPlugin(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IDrmPlugin>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.drm@1.0", "IDrmPlugin") {
}

void BpHwDrmPlugin::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IDrmPlugin>::onLastStrongRef(id);
}
// Methods from ::android::hardware::drm::V1_0::IDrmPlugin follow.
::android::hardware::Return<void> BpHwDrmPlugin::_hidl_openSession(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, openSession_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::openSession::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "openSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* openSession */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_sessionId;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_sessionId_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_sessionId), &_hidl__hidl_out_sessionId_parent,  reinterpret_cast<const void **>(&_hidl_out_sessionId));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_sessionId_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_sessionId),
                _hidl_reply,
                _hidl__hidl_out_sessionId_parent,
                0 /* parentOffset */, &_hidl__hidl_out_sessionId_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_sessionId);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_sessionId);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "openSession", &_hidl_args);
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

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::_hidl_closeSession(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::closeSession::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "closeSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::drm::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* closeSession */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "closeSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_getKeyRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& scope, const ::android::hardware::hidl_vec<uint8_t>& initData, const ::android::hardware::hidl_string& mimeType, ::android::hardware::drm::V1_0::KeyType keyType, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyValue>& optionalParameters, getKeyRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getKeyRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&scope);
        _hidl_args.push_back((void *)&initData);
        _hidl_args.push_back((void *)&mimeType);
        _hidl_args.push_back((void *)&keyType);
        _hidl_args.push_back((void *)&optionalParameters);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "getKeyRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_scope_parent;

    _hidl_err = _hidl_data.writeBuffer(&scope, sizeof(scope), &_hidl_scope_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_scope_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            scope,
            &_hidl_data,
            _hidl_scope_parent,
            0 /* parentOffset */, &_hidl_scope_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_initData_parent;

    _hidl_err = _hidl_data.writeBuffer(&initData, sizeof(initData), &_hidl_initData_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_initData_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            initData,
            &_hidl_data,
            _hidl_initData_parent,
            0 /* parentOffset */, &_hidl_initData_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_mimeType_parent;

    _hidl_err = _hidl_data.writeBuffer(&mimeType, sizeof(mimeType), &_hidl_mimeType_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            mimeType,
            &_hidl_data,
            _hidl_mimeType_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32((uint32_t)keyType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_optionalParameters_parent;

    _hidl_err = _hidl_data.writeBuffer(&optionalParameters, sizeof(optionalParameters), &_hidl_optionalParameters_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_optionalParameters_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            optionalParameters,
            &_hidl_data,
            _hidl_optionalParameters_parent,
            0 /* parentOffset */, &_hidl_optionalParameters_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < optionalParameters.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                optionalParameters[_hidl_index_0],
                &_hidl_data,
                _hidl_optionalParameters_child,
                _hidl_index_0 * sizeof(::android::hardware::drm::V1_0::KeyValue));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* getKeyRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_request;
        ::android::hardware::drm::V1_0::KeyRequestType _hidl_out_requestType;
        const ::android::hardware::hidl_string* _hidl_out_defaultUrl;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_request_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_request), &_hidl__hidl_out_request_parent,  reinterpret_cast<const void **>(&_hidl_out_request));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_request_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_request),
                _hidl_reply,
                _hidl__hidl_out_request_parent,
                0 /* parentOffset */, &_hidl__hidl_out_request_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_requestType);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_defaultUrl_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_defaultUrl), &_hidl__hidl_out_defaultUrl_parent,  reinterpret_cast<const void **>(&_hidl_out_defaultUrl));

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(*_hidl_out_defaultUrl),
                _hidl_reply,
                _hidl__hidl_out_defaultUrl_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_request, _hidl_out_requestType, *_hidl_out_defaultUrl);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_request);
            _hidl_args.push_back((void *)&_hidl_out_requestType);
            _hidl_args.push_back((void *)_hidl_out_defaultUrl);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "getKeyRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_provideKeyResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& scope, const ::android::hardware::hidl_vec<uint8_t>& response, provideKeyResponse_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::provideKeyResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&scope);
        _hidl_args.push_back((void *)&response);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "provideKeyResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_scope_parent;

    _hidl_err = _hidl_data.writeBuffer(&scope, sizeof(scope), &_hidl_scope_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_scope_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            scope,
            &_hidl_data,
            _hidl_scope_parent,
            0 /* parentOffset */, &_hidl_scope_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_response_parent;

    _hidl_err = _hidl_data.writeBuffer(&response, sizeof(response), &_hidl_response_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_response_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            response,
            &_hidl_data,
            _hidl_response_parent,
            0 /* parentOffset */, &_hidl_response_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* provideKeyResponse */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_keySetId;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keySetId_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_keySetId), &_hidl__hidl_out_keySetId_parent,  reinterpret_cast<const void **>(&_hidl_out_keySetId));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keySetId_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_keySetId),
                _hidl_reply,
                _hidl__hidl_out_keySetId_parent,
                0 /* parentOffset */, &_hidl__hidl_out_keySetId_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_keySetId);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_keySetId);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "provideKeyResponse", &_hidl_args);
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

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::_hidl_removeKeys(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::removeKeys::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "removeKeys", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::drm::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* removeKeys */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "removeKeys", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::_hidl_restoreKeys(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keySetId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::restoreKeys::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&keySetId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "restoreKeys", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::drm::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keySetId_parent;

    _hidl_err = _hidl_data.writeBuffer(&keySetId, sizeof(keySetId), &_hidl_keySetId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keySetId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keySetId,
            &_hidl_data,
            _hidl_keySetId_parent,
            0 /* parentOffset */, &_hidl_keySetId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* restoreKeys */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "restoreKeys", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_queryKeyStatus(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, queryKeyStatus_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::queryKeyStatus::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "queryKeyStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* queryKeyStatus */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyValue>* _hidl_out_infoList;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_infoList_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_infoList), &_hidl__hidl_out_infoList_parent,  reinterpret_cast<const void **>(&_hidl_out_infoList));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_infoList_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyValue> &>(*_hidl_out_infoList),
                _hidl_reply,
                _hidl__hidl_out_infoList_parent,
                0 /* parentOffset */, &_hidl__hidl_out_infoList_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_infoList->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::drm::V1_0::KeyValue &>((*_hidl_out_infoList)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_infoList_child,
                    _hidl_index_0 * sizeof(::android::hardware::drm::V1_0::KeyValue));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_cb(_hidl_out_status, *_hidl_out_infoList);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_infoList);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "queryKeyStatus", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_getProvisionRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& certificateType, const ::android::hardware::hidl_string& certificateAuthority, getProvisionRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getProvisionRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&certificateType);
        _hidl_args.push_back((void *)&certificateAuthority);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "getProvisionRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_certificateType_parent;

    _hidl_err = _hidl_data.writeBuffer(&certificateType, sizeof(certificateType), &_hidl_certificateType_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            certificateType,
            &_hidl_data,
            _hidl_certificateType_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_certificateAuthority_parent;

    _hidl_err = _hidl_data.writeBuffer(&certificateAuthority, sizeof(certificateAuthority), &_hidl_certificateAuthority_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            certificateAuthority,
            &_hidl_data,
            _hidl_certificateAuthority_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* getProvisionRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_request;
        const ::android::hardware::hidl_string* _hidl_out_defaultUrl;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_request_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_request), &_hidl__hidl_out_request_parent,  reinterpret_cast<const void **>(&_hidl_out_request));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_request_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_request),
                _hidl_reply,
                _hidl__hidl_out_request_parent,
                0 /* parentOffset */, &_hidl__hidl_out_request_child);

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_defaultUrl_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_defaultUrl), &_hidl__hidl_out_defaultUrl_parent,  reinterpret_cast<const void **>(&_hidl_out_defaultUrl));

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(*_hidl_out_defaultUrl),
                _hidl_reply,
                _hidl__hidl_out_defaultUrl_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_request, *_hidl_out_defaultUrl);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_request);
            _hidl_args.push_back((void *)_hidl_out_defaultUrl);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "getProvisionRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_provideProvisionResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& response, provideProvisionResponse_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::provideProvisionResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&response);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "provideProvisionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_response_parent;

    _hidl_err = _hidl_data.writeBuffer(&response, sizeof(response), &_hidl_response_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_response_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            response,
            &_hidl_data,
            _hidl_response_parent,
            0 /* parentOffset */, &_hidl_response_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* provideProvisionResponse */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_certificate;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_wrappedKey;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_certificate_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_certificate), &_hidl__hidl_out_certificate_parent,  reinterpret_cast<const void **>(&_hidl_out_certificate));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_certificate_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_certificate),
                _hidl_reply,
                _hidl__hidl_out_certificate_parent,
                0 /* parentOffset */, &_hidl__hidl_out_certificate_child);

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_wrappedKey_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_wrappedKey), &_hidl__hidl_out_wrappedKey_parent,  reinterpret_cast<const void **>(&_hidl_out_wrappedKey));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_wrappedKey_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_wrappedKey),
                _hidl_reply,
                _hidl__hidl_out_wrappedKey_parent,
                0 /* parentOffset */, &_hidl__hidl_out_wrappedKey_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_certificate, *_hidl_out_wrappedKey);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_certificate);
            _hidl_args.push_back((void *)_hidl_out_wrappedKey);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "provideProvisionResponse", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_getSecureStops(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getSecureStops_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getSecureStops::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "getSecureStops", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* getSecureStops */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::SecureStop>* _hidl_out_secureStops;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_secureStops_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_secureStops), &_hidl__hidl_out_secureStops_parent,  reinterpret_cast<const void **>(&_hidl_out_secureStops));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_secureStops_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::drm::V1_0::SecureStop> &>(*_hidl_out_secureStops),
                _hidl_reply,
                _hidl__hidl_out_secureStops_parent,
                0 /* parentOffset */, &_hidl__hidl_out_secureStops_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_secureStops->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::drm::V1_0::SecureStop &>((*_hidl_out_secureStops)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_secureStops_child,
                    _hidl_index_0 * sizeof(::android::hardware::drm::V1_0::SecureStop));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_cb(_hidl_out_status, *_hidl_out_secureStops);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_secureStops);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "getSecureStops", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_getSecureStop(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& secureStopId, getSecureStop_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getSecureStop::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&secureStopId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "getSecureStop", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_secureStopId_parent;

    _hidl_err = _hidl_data.writeBuffer(&secureStopId, sizeof(secureStopId), &_hidl_secureStopId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_secureStopId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            secureStopId,
            &_hidl_data,
            _hidl_secureStopId_parent,
            0 /* parentOffset */, &_hidl_secureStopId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* getSecureStop */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        ::android::hardware::drm::V1_0::SecureStop* _hidl_out_secureStop;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_secureStop_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_secureStop), &_hidl__hidl_out_secureStop_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_secureStop)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::drm::V1_0::SecureStop &>(*_hidl_out_secureStop),
                _hidl_reply,
                _hidl__hidl_out_secureStop_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_secureStop);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_secureStop);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "getSecureStop", &_hidl_args);
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

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::_hidl_releaseAllSecureStops(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::releaseAllSecureStops::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "releaseAllSecureStops", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::drm::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* releaseAllSecureStops */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "releaseAllSecureStops", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::_hidl_releaseSecureStop(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& secureStopId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::releaseSecureStop::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&secureStopId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "releaseSecureStop", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::drm::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_secureStopId_parent;

    _hidl_err = _hidl_data.writeBuffer(&secureStopId, sizeof(secureStopId), &_hidl_secureStopId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_secureStopId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            secureStopId,
            &_hidl_data,
            _hidl_secureStopId_parent,
            0 /* parentOffset */, &_hidl_secureStopId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* releaseSecureStop */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "releaseSecureStop", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_getPropertyString(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& propertyName, getPropertyString_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getPropertyString::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&propertyName);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "getPropertyString", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_propertyName_parent;

    _hidl_err = _hidl_data.writeBuffer(&propertyName, sizeof(propertyName), &_hidl_propertyName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            propertyName,
            &_hidl_data,
            _hidl_propertyName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(14 /* getPropertyString */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_string* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  reinterpret_cast<const void **>(&_hidl_out_value));

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(*_hidl_out_value),
                _hidl_reply,
                _hidl__hidl_out_value_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "getPropertyString", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_getPropertyByteArray(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& propertyName, getPropertyByteArray_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getPropertyByteArray::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&propertyName);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "getPropertyByteArray", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_propertyName_parent;

    _hidl_err = _hidl_data.writeBuffer(&propertyName, sizeof(propertyName), &_hidl_propertyName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            propertyName,
            &_hidl_data,
            _hidl_propertyName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(15 /* getPropertyByteArray */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  reinterpret_cast<const void **>(&_hidl_out_value));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_value_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_value),
                _hidl_reply,
                _hidl__hidl_out_value_parent,
                0 /* parentOffset */, &_hidl__hidl_out_value_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "getPropertyByteArray", &_hidl_args);
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

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::_hidl_setPropertyString(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& propertyName, const ::android::hardware::hidl_string& value) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::setPropertyString::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&propertyName);
        _hidl_args.push_back((void *)&value);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "setPropertyString", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::drm::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_propertyName_parent;

    _hidl_err = _hidl_data.writeBuffer(&propertyName, sizeof(propertyName), &_hidl_propertyName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            propertyName,
            &_hidl_data,
            _hidl_propertyName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_value_parent;

    _hidl_err = _hidl_data.writeBuffer(&value, sizeof(value), &_hidl_value_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            value,
            &_hidl_data,
            _hidl_value_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(16 /* setPropertyString */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "setPropertyString", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::_hidl_setPropertyByteArray(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& propertyName, const ::android::hardware::hidl_vec<uint8_t>& value) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::setPropertyByteArray::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&propertyName);
        _hidl_args.push_back((void *)&value);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "setPropertyByteArray", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::drm::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_propertyName_parent;

    _hidl_err = _hidl_data.writeBuffer(&propertyName, sizeof(propertyName), &_hidl_propertyName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            propertyName,
            &_hidl_data,
            _hidl_propertyName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_value_parent;

    _hidl_err = _hidl_data.writeBuffer(&value, sizeof(value), &_hidl_value_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_value_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            value,
            &_hidl_data,
            _hidl_value_parent,
            0 /* parentOffset */, &_hidl_value_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(17 /* setPropertyByteArray */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "setPropertyByteArray", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::_hidl_setCipherAlgorithm(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_string& algorithm) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::setCipherAlgorithm::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&algorithm);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "setCipherAlgorithm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::drm::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_algorithm_parent;

    _hidl_err = _hidl_data.writeBuffer(&algorithm, sizeof(algorithm), &_hidl_algorithm_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            algorithm,
            &_hidl_data,
            _hidl_algorithm_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(18 /* setCipherAlgorithm */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "setCipherAlgorithm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::_hidl_setMacAlgorithm(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_string& algorithm) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::setMacAlgorithm::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&algorithm);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "setMacAlgorithm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::drm::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_algorithm_parent;

    _hidl_err = _hidl_data.writeBuffer(&algorithm, sizeof(algorithm), &_hidl_algorithm_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            algorithm,
            &_hidl_data,
            _hidl_algorithm_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(19 /* setMacAlgorithm */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "setMacAlgorithm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_encrypt(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keyId, const ::android::hardware::hidl_vec<uint8_t>& input, const ::android::hardware::hidl_vec<uint8_t>& iv, encrypt_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::encrypt::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&keyId);
        _hidl_args.push_back((void *)&input);
        _hidl_args.push_back((void *)&iv);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "encrypt", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyId_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyId, sizeof(keyId), &_hidl_keyId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyId,
            &_hidl_data,
            _hidl_keyId_parent,
            0 /* parentOffset */, &_hidl_keyId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_input_parent;

    _hidl_err = _hidl_data.writeBuffer(&input, sizeof(input), &_hidl_input_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_input_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            input,
            &_hidl_data,
            _hidl_input_parent,
            0 /* parentOffset */, &_hidl_input_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_iv_parent;

    _hidl_err = _hidl_data.writeBuffer(&iv, sizeof(iv), &_hidl_iv_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_iv_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            iv,
            &_hidl_data,
            _hidl_iv_parent,
            0 /* parentOffset */, &_hidl_iv_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(20 /* encrypt */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_output;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_output_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_output), &_hidl__hidl_out_output_parent,  reinterpret_cast<const void **>(&_hidl_out_output));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_output_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_output),
                _hidl_reply,
                _hidl__hidl_out_output_parent,
                0 /* parentOffset */, &_hidl__hidl_out_output_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_output);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_output);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "encrypt", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_decrypt(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keyId, const ::android::hardware::hidl_vec<uint8_t>& input, const ::android::hardware::hidl_vec<uint8_t>& iv, decrypt_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::decrypt::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&keyId);
        _hidl_args.push_back((void *)&input);
        _hidl_args.push_back((void *)&iv);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "decrypt", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyId_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyId, sizeof(keyId), &_hidl_keyId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyId,
            &_hidl_data,
            _hidl_keyId_parent,
            0 /* parentOffset */, &_hidl_keyId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_input_parent;

    _hidl_err = _hidl_data.writeBuffer(&input, sizeof(input), &_hidl_input_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_input_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            input,
            &_hidl_data,
            _hidl_input_parent,
            0 /* parentOffset */, &_hidl_input_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_iv_parent;

    _hidl_err = _hidl_data.writeBuffer(&iv, sizeof(iv), &_hidl_iv_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_iv_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            iv,
            &_hidl_data,
            _hidl_iv_parent,
            0 /* parentOffset */, &_hidl_iv_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(21 /* decrypt */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_output;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_output_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_output), &_hidl__hidl_out_output_parent,  reinterpret_cast<const void **>(&_hidl_out_output));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_output_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_output),
                _hidl_reply,
                _hidl__hidl_out_output_parent,
                0 /* parentOffset */, &_hidl__hidl_out_output_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_output);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_output);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "decrypt", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_sign(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keyId, const ::android::hardware::hidl_vec<uint8_t>& message, sign_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::sign::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&keyId);
        _hidl_args.push_back((void *)&message);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "sign", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyId_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyId, sizeof(keyId), &_hidl_keyId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyId,
            &_hidl_data,
            _hidl_keyId_parent,
            0 /* parentOffset */, &_hidl_keyId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_message_parent;

    _hidl_err = _hidl_data.writeBuffer(&message, sizeof(message), &_hidl_message_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_message_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            message,
            &_hidl_data,
            _hidl_message_parent,
            0 /* parentOffset */, &_hidl_message_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(22 /* sign */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_signature;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_signature_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_signature), &_hidl__hidl_out_signature_parent,  reinterpret_cast<const void **>(&_hidl_out_signature));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_signature_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_signature),
                _hidl_reply,
                _hidl__hidl_out_signature_parent,
                0 /* parentOffset */, &_hidl__hidl_out_signature_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_signature);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_signature);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "sign", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_verify(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keyId, const ::android::hardware::hidl_vec<uint8_t>& message, const ::android::hardware::hidl_vec<uint8_t>& signature, verify_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::verify::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&keyId);
        _hidl_args.push_back((void *)&message);
        _hidl_args.push_back((void *)&signature);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "verify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyId_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyId, sizeof(keyId), &_hidl_keyId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyId,
            &_hidl_data,
            _hidl_keyId_parent,
            0 /* parentOffset */, &_hidl_keyId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_message_parent;

    _hidl_err = _hidl_data.writeBuffer(&message, sizeof(message), &_hidl_message_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_message_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            message,
            &_hidl_data,
            _hidl_message_parent,
            0 /* parentOffset */, &_hidl_message_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_signature_parent;

    _hidl_err = _hidl_data.writeBuffer(&signature, sizeof(signature), &_hidl_signature_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_signature_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            signature,
            &_hidl_data,
            _hidl_signature_parent,
            0 /* parentOffset */, &_hidl_signature_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(23 /* verify */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        bool _hidl_out_match;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readBool(&_hidl_out_match);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_match);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_match);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "verify", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_signRSA(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_string& algorithm, const ::android::hardware::hidl_vec<uint8_t>& message, const ::android::hardware::hidl_vec<uint8_t>& wrappedkey, signRSA_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::signRSA::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&algorithm);
        _hidl_args.push_back((void *)&message);
        _hidl_args.push_back((void *)&wrappedkey);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "signRSA", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_algorithm_parent;

    _hidl_err = _hidl_data.writeBuffer(&algorithm, sizeof(algorithm), &_hidl_algorithm_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            algorithm,
            &_hidl_data,
            _hidl_algorithm_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_message_parent;

    _hidl_err = _hidl_data.writeBuffer(&message, sizeof(message), &_hidl_message_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_message_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            message,
            &_hidl_data,
            _hidl_message_parent,
            0 /* parentOffset */, &_hidl_message_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_wrappedkey_parent;

    _hidl_err = _hidl_data.writeBuffer(&wrappedkey, sizeof(wrappedkey), &_hidl_wrappedkey_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_wrappedkey_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            wrappedkey,
            &_hidl_data,
            _hidl_wrappedkey_parent,
            0 /* parentOffset */, &_hidl_wrappedkey_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(24 /* signRSA */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_signature;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_signature_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_signature), &_hidl__hidl_out_signature_parent,  reinterpret_cast<const void **>(&_hidl_out_signature));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_signature_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_signature),
                _hidl_reply,
                _hidl__hidl_out_signature_parent,
                0 /* parentOffset */, &_hidl__hidl_out_signature_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_signature);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_signature);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "signRSA", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_setListener(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::drm::V1_0::IDrmPluginListener>& listener) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::setListener::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&listener);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "setListener", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
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

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(25 /* setListener */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "setListener", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_sendEvent(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::drm::V1_0::EventType eventType, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& data) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::sendEvent::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&eventType);
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "sendEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32((uint32_t)eventType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(26 /* sendEvent */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "sendEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_sendExpirationUpdate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, int64_t expiryTimeInMS) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::sendExpirationUpdate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&expiryTimeInMS);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "sendExpirationUpdate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt64(expiryTimeInMS);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(27 /* sendExpirationUpdate */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "sendExpirationUpdate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_sendKeysChange(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyStatus>& keyStatusList, bool hasNewUsableKey) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::sendKeysChange::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&keyStatusList);
        _hidl_args.push_back((void *)&hasNewUsableKey);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "sendKeysChange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyStatusList_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyStatusList, sizeof(keyStatusList), &_hidl_keyStatusList_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyStatusList_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyStatusList,
            &_hidl_data,
            _hidl_keyStatusList_parent,
            0 /* parentOffset */, &_hidl_keyStatusList_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < keyStatusList.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                keyStatusList[_hidl_index_0],
                &_hidl_data,
                _hidl_keyStatusList_child,
                _hidl_index_0 * sizeof(::android::hardware::drm::V1_0::KeyStatus));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_err = _hidl_data.writeBool(hasNewUsableKey);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(28 /* sendKeysChange */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "sendKeysChange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::drm::V1_0::IDrmPlugin follow.
::android::hardware::Return<void> BpHwDrmPlugin::openSession(openSession_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_openSession(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::closeSession(const ::android::hardware::hidl_vec<uint8_t>& sessionId){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_closeSession(this, this, sessionId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getKeyRequest(const ::android::hardware::hidl_vec<uint8_t>& scope, const ::android::hardware::hidl_vec<uint8_t>& initData, const ::android::hardware::hidl_string& mimeType, ::android::hardware::drm::V1_0::KeyType keyType, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyValue>& optionalParameters, getKeyRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_getKeyRequest(this, this, scope, initData, mimeType, keyType, optionalParameters, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::provideKeyResponse(const ::android::hardware::hidl_vec<uint8_t>& scope, const ::android::hardware::hidl_vec<uint8_t>& response, provideKeyResponse_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_provideKeyResponse(this, this, scope, response, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::removeKeys(const ::android::hardware::hidl_vec<uint8_t>& sessionId){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_removeKeys(this, this, sessionId);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::restoreKeys(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keySetId){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_restoreKeys(this, this, sessionId, keySetId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::queryKeyStatus(const ::android::hardware::hidl_vec<uint8_t>& sessionId, queryKeyStatus_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_queryKeyStatus(this, this, sessionId, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getProvisionRequest(const ::android::hardware::hidl_string& certificateType, const ::android::hardware::hidl_string& certificateAuthority, getProvisionRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_getProvisionRequest(this, this, certificateType, certificateAuthority, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::provideProvisionResponse(const ::android::hardware::hidl_vec<uint8_t>& response, provideProvisionResponse_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_provideProvisionResponse(this, this, response, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getSecureStops(getSecureStops_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_getSecureStops(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getSecureStop(const ::android::hardware::hidl_vec<uint8_t>& secureStopId, getSecureStop_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_getSecureStop(this, this, secureStopId, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::releaseAllSecureStops(){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_releaseAllSecureStops(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::releaseSecureStop(const ::android::hardware::hidl_vec<uint8_t>& secureStopId){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_releaseSecureStop(this, this, secureStopId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getPropertyString(const ::android::hardware::hidl_string& propertyName, getPropertyString_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_getPropertyString(this, this, propertyName, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getPropertyByteArray(const ::android::hardware::hidl_string& propertyName, getPropertyByteArray_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_getPropertyByteArray(this, this, propertyName, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::setPropertyString(const ::android::hardware::hidl_string& propertyName, const ::android::hardware::hidl_string& value){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_setPropertyString(this, this, propertyName, value);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::setPropertyByteArray(const ::android::hardware::hidl_string& propertyName, const ::android::hardware::hidl_vec<uint8_t>& value){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_setPropertyByteArray(this, this, propertyName, value);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::setCipherAlgorithm(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_string& algorithm){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_setCipherAlgorithm(this, this, sessionId, algorithm);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::setMacAlgorithm(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_string& algorithm){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_setMacAlgorithm(this, this, sessionId, algorithm);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::encrypt(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keyId, const ::android::hardware::hidl_vec<uint8_t>& input, const ::android::hardware::hidl_vec<uint8_t>& iv, encrypt_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_encrypt(this, this, sessionId, keyId, input, iv, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::decrypt(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keyId, const ::android::hardware::hidl_vec<uint8_t>& input, const ::android::hardware::hidl_vec<uint8_t>& iv, decrypt_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_decrypt(this, this, sessionId, keyId, input, iv, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::sign(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keyId, const ::android::hardware::hidl_vec<uint8_t>& message, sign_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_sign(this, this, sessionId, keyId, message, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::verify(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& keyId, const ::android::hardware::hidl_vec<uint8_t>& message, const ::android::hardware::hidl_vec<uint8_t>& signature, verify_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_verify(this, this, sessionId, keyId, message, signature, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::signRSA(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_string& algorithm, const ::android::hardware::hidl_vec<uint8_t>& message, const ::android::hardware::hidl_vec<uint8_t>& wrappedkey, signRSA_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_signRSA(this, this, sessionId, algorithm, message, wrappedkey, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::setListener(const ::android::sp<::android::hardware::drm::V1_0::IDrmPluginListener>& listener){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_setListener(this, this, listener);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::sendEvent(::android::hardware::drm::V1_0::EventType eventType, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& data){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_sendEvent(this, this, eventType, sessionId, data);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::sendExpirationUpdate(const ::android::hardware::hidl_vec<uint8_t>& sessionId, int64_t expiryTimeInMS){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_sendExpirationUpdate(this, this, sessionId, expiryTimeInMS);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::sendKeysChange(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyStatus>& keyStatusList, bool hasNewUsableKey){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmPlugin::_hidl_sendKeysChange(this, this, sessionId, keyStatusList, hasNewUsableKey);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwDrmPlugin::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwDrmPlugin::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwDrmPlugin::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwDrmPlugin::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwDrmPlugin::BnHwDrmPlugin(const ::android::sp<IDrmPlugin> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.drm@1.0", "IDrmPlugin") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwDrmPlugin::~BnHwDrmPlugin() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::drm::V1_0::IDrmPlugin follow.
::android::status_t BnHwDrmPlugin::_hidl_openSession(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::openSession::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "openSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->openSession([&](const auto &_hidl_out_status, const auto &_hidl_out_sessionId) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("openSession: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_sessionId_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_sessionId, sizeof(_hidl_out_sessionId), &_hidl__hidl_out_sessionId_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_sessionId_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_sessionId,
                _hidl_reply,
                _hidl__hidl_out_sessionId_parent,
                0 /* parentOffset */, &_hidl__hidl_out_sessionId_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_sessionId);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "openSession", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("openSession: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_closeSession(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::closeSession::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "closeSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::drm::V1_0::Status _hidl_out_status = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->closeSession(*sessionId);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "closeSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_getKeyRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* scope;
    const ::android::hardware::hidl_vec<uint8_t>* initData;
    const ::android::hardware::hidl_string* mimeType;
    ::android::hardware::drm::V1_0::KeyType keyType;
    const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyValue>* optionalParameters;

    size_t _hidl_scope_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*scope), &_hidl_scope_parent,  reinterpret_cast<const void **>(&scope));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_scope_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*scope),
            _hidl_data,
            _hidl_scope_parent,
            0 /* parentOffset */, &_hidl_scope_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_initData_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*initData), &_hidl_initData_parent,  reinterpret_cast<const void **>(&initData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_initData_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*initData),
            _hidl_data,
            _hidl_initData_parent,
            0 /* parentOffset */, &_hidl_initData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_mimeType_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*mimeType), &_hidl_mimeType_parent,  reinterpret_cast<const void **>(&mimeType));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*mimeType),
            _hidl_data,
            _hidl_mimeType_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32((uint32_t *)&keyType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_optionalParameters_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*optionalParameters), &_hidl_optionalParameters_parent,  reinterpret_cast<const void **>(&optionalParameters));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_optionalParameters_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyValue> &>(*optionalParameters),
            _hidl_data,
            _hidl_optionalParameters_parent,
            0 /* parentOffset */, &_hidl_optionalParameters_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < optionalParameters->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::drm::V1_0::KeyValue &>((*optionalParameters)[_hidl_index_0]),
                _hidl_data,
                _hidl_optionalParameters_child,
                _hidl_index_0 * sizeof(::android::hardware::drm::V1_0::KeyValue));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getKeyRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)scope);
        _hidl_args.push_back((void *)initData);
        _hidl_args.push_back((void *)mimeType);
        _hidl_args.push_back((void *)&keyType);
        _hidl_args.push_back((void *)optionalParameters);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "getKeyRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->getKeyRequest(*scope, *initData, *mimeType, keyType, *optionalParameters, [&](const auto &_hidl_out_status, const auto &_hidl_out_request, const auto &_hidl_out_requestType, const auto &_hidl_out_defaultUrl) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getKeyRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_request_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_request, sizeof(_hidl_out_request), &_hidl__hidl_out_request_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_request_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_request,
                _hidl_reply,
                _hidl__hidl_out_request_parent,
                0 /* parentOffset */, &_hidl__hidl_out_request_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_requestType);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_defaultUrl_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_defaultUrl, sizeof(_hidl_out_defaultUrl), &_hidl__hidl_out_defaultUrl_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_defaultUrl,
                _hidl_reply,
                _hidl__hidl_out_defaultUrl_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_request);
            _hidl_args.push_back((void *)&_hidl_out_requestType);
            _hidl_args.push_back((void *)&_hidl_out_defaultUrl);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "getKeyRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getKeyRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_provideKeyResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* scope;
    const ::android::hardware::hidl_vec<uint8_t>* response;

    size_t _hidl_scope_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*scope), &_hidl_scope_parent,  reinterpret_cast<const void **>(&scope));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_scope_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*scope),
            _hidl_data,
            _hidl_scope_parent,
            0 /* parentOffset */, &_hidl_scope_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_response_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*response), &_hidl_response_parent,  reinterpret_cast<const void **>(&response));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_response_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*response),
            _hidl_data,
            _hidl_response_parent,
            0 /* parentOffset */, &_hidl_response_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::provideKeyResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)scope);
        _hidl_args.push_back((void *)response);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "provideKeyResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->provideKeyResponse(*scope, *response, [&](const auto &_hidl_out_status, const auto &_hidl_out_keySetId) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("provideKeyResponse: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keySetId_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_keySetId, sizeof(_hidl_out_keySetId), &_hidl__hidl_out_keySetId_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keySetId_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_keySetId,
                _hidl_reply,
                _hidl__hidl_out_keySetId_parent,
                0 /* parentOffset */, &_hidl__hidl_out_keySetId_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_keySetId);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "provideKeyResponse", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("provideKeyResponse: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_removeKeys(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::removeKeys::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "removeKeys", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::drm::V1_0::Status _hidl_out_status = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->removeKeys(*sessionId);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "removeKeys", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_restoreKeys(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;
    const ::android::hardware::hidl_vec<uint8_t>* keySetId;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keySetId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keySetId), &_hidl_keySetId_parent,  reinterpret_cast<const void **>(&keySetId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keySetId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*keySetId),
            _hidl_data,
            _hidl_keySetId_parent,
            0 /* parentOffset */, &_hidl_keySetId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::restoreKeys::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        _hidl_args.push_back((void *)keySetId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "restoreKeys", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::drm::V1_0::Status _hidl_out_status = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->restoreKeys(*sessionId, *keySetId);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "restoreKeys", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_queryKeyStatus(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::queryKeyStatus::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "queryKeyStatus", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->queryKeyStatus(*sessionId, [&](const auto &_hidl_out_status, const auto &_hidl_out_infoList) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("queryKeyStatus: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_infoList_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_infoList, sizeof(_hidl_out_infoList), &_hidl__hidl_out_infoList_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_infoList_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_infoList,
                _hidl_reply,
                _hidl__hidl_out_infoList_parent,
                0 /* parentOffset */, &_hidl__hidl_out_infoList_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_infoList.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_infoList[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_infoList_child,
                    _hidl_index_0 * sizeof(::android::hardware::drm::V1_0::KeyValue));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_infoList);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "queryKeyStatus", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("queryKeyStatus: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_getProvisionRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* certificateType;
    const ::android::hardware::hidl_string* certificateAuthority;

    size_t _hidl_certificateType_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*certificateType), &_hidl_certificateType_parent,  reinterpret_cast<const void **>(&certificateType));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*certificateType),
            _hidl_data,
            _hidl_certificateType_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_certificateAuthority_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*certificateAuthority), &_hidl_certificateAuthority_parent,  reinterpret_cast<const void **>(&certificateAuthority));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*certificateAuthority),
            _hidl_data,
            _hidl_certificateAuthority_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getProvisionRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)certificateType);
        _hidl_args.push_back((void *)certificateAuthority);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "getProvisionRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->getProvisionRequest(*certificateType, *certificateAuthority, [&](const auto &_hidl_out_status, const auto &_hidl_out_request, const auto &_hidl_out_defaultUrl) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getProvisionRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_request_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_request, sizeof(_hidl_out_request), &_hidl__hidl_out_request_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_request_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_request,
                _hidl_reply,
                _hidl__hidl_out_request_parent,
                0 /* parentOffset */, &_hidl__hidl_out_request_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_defaultUrl_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_defaultUrl, sizeof(_hidl_out_defaultUrl), &_hidl__hidl_out_defaultUrl_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_defaultUrl,
                _hidl_reply,
                _hidl__hidl_out_defaultUrl_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_request);
            _hidl_args.push_back((void *)&_hidl_out_defaultUrl);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "getProvisionRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getProvisionRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_provideProvisionResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* response;

    size_t _hidl_response_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*response), &_hidl_response_parent,  reinterpret_cast<const void **>(&response));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_response_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*response),
            _hidl_data,
            _hidl_response_parent,
            0 /* parentOffset */, &_hidl_response_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::provideProvisionResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)response);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "provideProvisionResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->provideProvisionResponse(*response, [&](const auto &_hidl_out_status, const auto &_hidl_out_certificate, const auto &_hidl_out_wrappedKey) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("provideProvisionResponse: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_certificate_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_certificate, sizeof(_hidl_out_certificate), &_hidl__hidl_out_certificate_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_certificate_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_certificate,
                _hidl_reply,
                _hidl__hidl_out_certificate_parent,
                0 /* parentOffset */, &_hidl__hidl_out_certificate_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_wrappedKey_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_wrappedKey, sizeof(_hidl_out_wrappedKey), &_hidl__hidl_out_wrappedKey_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_wrappedKey_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_wrappedKey,
                _hidl_reply,
                _hidl__hidl_out_wrappedKey_parent,
                0 /* parentOffset */, &_hidl__hidl_out_wrappedKey_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_certificate);
            _hidl_args.push_back((void *)&_hidl_out_wrappedKey);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "provideProvisionResponse", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("provideProvisionResponse: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_getSecureStops(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getSecureStops::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "getSecureStops", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->getSecureStops([&](const auto &_hidl_out_status, const auto &_hidl_out_secureStops) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getSecureStops: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_secureStops_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_secureStops, sizeof(_hidl_out_secureStops), &_hidl__hidl_out_secureStops_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_secureStops_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_secureStops,
                _hidl_reply,
                _hidl__hidl_out_secureStops_parent,
                0 /* parentOffset */, &_hidl__hidl_out_secureStops_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_secureStops.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_secureStops[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_secureStops_child,
                    _hidl_index_0 * sizeof(::android::hardware::drm::V1_0::SecureStop));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_secureStops);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "getSecureStops", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getSecureStops: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_getSecureStop(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* secureStopId;

    size_t _hidl_secureStopId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*secureStopId), &_hidl_secureStopId_parent,  reinterpret_cast<const void **>(&secureStopId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_secureStopId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*secureStopId),
            _hidl_data,
            _hidl_secureStopId_parent,
            0 /* parentOffset */, &_hidl_secureStopId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getSecureStop::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)secureStopId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "getSecureStop", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->getSecureStop(*secureStopId, [&](const auto &_hidl_out_status, const auto &_hidl_out_secureStop) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getSecureStop: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_secureStop_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_secureStop, sizeof(_hidl_out_secureStop), &_hidl__hidl_out_secureStop_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_secureStop,
                _hidl_reply,
                _hidl__hidl_out_secureStop_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_secureStop);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "getSecureStop", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getSecureStop: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_releaseAllSecureStops(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::releaseAllSecureStops::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "releaseAllSecureStops", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::drm::V1_0::Status _hidl_out_status = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->releaseAllSecureStops();

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "releaseAllSecureStops", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_releaseSecureStop(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* secureStopId;

    size_t _hidl_secureStopId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*secureStopId), &_hidl_secureStopId_parent,  reinterpret_cast<const void **>(&secureStopId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_secureStopId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*secureStopId),
            _hidl_data,
            _hidl_secureStopId_parent,
            0 /* parentOffset */, &_hidl_secureStopId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::releaseSecureStop::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)secureStopId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "releaseSecureStop", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::drm::V1_0::Status _hidl_out_status = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->releaseSecureStop(*secureStopId);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "releaseSecureStop", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_getPropertyString(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* propertyName;

    size_t _hidl_propertyName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*propertyName), &_hidl_propertyName_parent,  reinterpret_cast<const void **>(&propertyName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*propertyName),
            _hidl_data,
            _hidl_propertyName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getPropertyString::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)propertyName);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "getPropertyString", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->getPropertyString(*propertyName, [&](const auto &_hidl_out_status, const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getPropertyString: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_value,
                _hidl_reply,
                _hidl__hidl_out_value_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "getPropertyString", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getPropertyString: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_getPropertyByteArray(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* propertyName;

    size_t _hidl_propertyName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*propertyName), &_hidl_propertyName_parent,  reinterpret_cast<const void **>(&propertyName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*propertyName),
            _hidl_data,
            _hidl_propertyName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getPropertyByteArray::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)propertyName);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "getPropertyByteArray", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->getPropertyByteArray(*propertyName, [&](const auto &_hidl_out_status, const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getPropertyByteArray: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_value_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_value,
                _hidl_reply,
                _hidl__hidl_out_value_parent,
                0 /* parentOffset */, &_hidl__hidl_out_value_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "getPropertyByteArray", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getPropertyByteArray: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_setPropertyString(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* propertyName;
    const ::android::hardware::hidl_string* value;

    size_t _hidl_propertyName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*propertyName), &_hidl_propertyName_parent,  reinterpret_cast<const void **>(&propertyName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*propertyName),
            _hidl_data,
            _hidl_propertyName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_value_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*value), &_hidl_value_parent,  reinterpret_cast<const void **>(&value));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*value),
            _hidl_data,
            _hidl_value_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::setPropertyString::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)propertyName);
        _hidl_args.push_back((void *)value);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "setPropertyString", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::drm::V1_0::Status _hidl_out_status = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->setPropertyString(*propertyName, *value);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "setPropertyString", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_setPropertyByteArray(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* propertyName;
    const ::android::hardware::hidl_vec<uint8_t>* value;

    size_t _hidl_propertyName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*propertyName), &_hidl_propertyName_parent,  reinterpret_cast<const void **>(&propertyName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*propertyName),
            _hidl_data,
            _hidl_propertyName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_value_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*value), &_hidl_value_parent,  reinterpret_cast<const void **>(&value));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_value_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*value),
            _hidl_data,
            _hidl_value_parent,
            0 /* parentOffset */, &_hidl_value_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::setPropertyByteArray::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)propertyName);
        _hidl_args.push_back((void *)value);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "setPropertyByteArray", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::drm::V1_0::Status _hidl_out_status = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->setPropertyByteArray(*propertyName, *value);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "setPropertyByteArray", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_setCipherAlgorithm(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;
    const ::android::hardware::hidl_string* algorithm;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_algorithm_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*algorithm), &_hidl_algorithm_parent,  reinterpret_cast<const void **>(&algorithm));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*algorithm),
            _hidl_data,
            _hidl_algorithm_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::setCipherAlgorithm::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        _hidl_args.push_back((void *)algorithm);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "setCipherAlgorithm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::drm::V1_0::Status _hidl_out_status = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->setCipherAlgorithm(*sessionId, *algorithm);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "setCipherAlgorithm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_setMacAlgorithm(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;
    const ::android::hardware::hidl_string* algorithm;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_algorithm_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*algorithm), &_hidl_algorithm_parent,  reinterpret_cast<const void **>(&algorithm));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*algorithm),
            _hidl_data,
            _hidl_algorithm_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::setMacAlgorithm::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        _hidl_args.push_back((void *)algorithm);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "setMacAlgorithm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::drm::V1_0::Status _hidl_out_status = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->setMacAlgorithm(*sessionId, *algorithm);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "setMacAlgorithm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_encrypt(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;
    const ::android::hardware::hidl_vec<uint8_t>* keyId;
    const ::android::hardware::hidl_vec<uint8_t>* input;
    const ::android::hardware::hidl_vec<uint8_t>* iv;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyId), &_hidl_keyId_parent,  reinterpret_cast<const void **>(&keyId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*keyId),
            _hidl_data,
            _hidl_keyId_parent,
            0 /* parentOffset */, &_hidl_keyId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_input_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*input), &_hidl_input_parent,  reinterpret_cast<const void **>(&input));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_input_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*input),
            _hidl_data,
            _hidl_input_parent,
            0 /* parentOffset */, &_hidl_input_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_iv_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*iv), &_hidl_iv_parent,  reinterpret_cast<const void **>(&iv));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_iv_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*iv),
            _hidl_data,
            _hidl_iv_parent,
            0 /* parentOffset */, &_hidl_iv_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::encrypt::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        _hidl_args.push_back((void *)keyId);
        _hidl_args.push_back((void *)input);
        _hidl_args.push_back((void *)iv);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "encrypt", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->encrypt(*sessionId, *keyId, *input, *iv, [&](const auto &_hidl_out_status, const auto &_hidl_out_output) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("encrypt: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_output_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_output, sizeof(_hidl_out_output), &_hidl__hidl_out_output_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_output_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_output,
                _hidl_reply,
                _hidl__hidl_out_output_parent,
                0 /* parentOffset */, &_hidl__hidl_out_output_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_output);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "encrypt", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("encrypt: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_decrypt(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;
    const ::android::hardware::hidl_vec<uint8_t>* keyId;
    const ::android::hardware::hidl_vec<uint8_t>* input;
    const ::android::hardware::hidl_vec<uint8_t>* iv;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyId), &_hidl_keyId_parent,  reinterpret_cast<const void **>(&keyId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*keyId),
            _hidl_data,
            _hidl_keyId_parent,
            0 /* parentOffset */, &_hidl_keyId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_input_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*input), &_hidl_input_parent,  reinterpret_cast<const void **>(&input));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_input_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*input),
            _hidl_data,
            _hidl_input_parent,
            0 /* parentOffset */, &_hidl_input_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_iv_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*iv), &_hidl_iv_parent,  reinterpret_cast<const void **>(&iv));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_iv_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*iv),
            _hidl_data,
            _hidl_iv_parent,
            0 /* parentOffset */, &_hidl_iv_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::decrypt::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        _hidl_args.push_back((void *)keyId);
        _hidl_args.push_back((void *)input);
        _hidl_args.push_back((void *)iv);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "decrypt", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->decrypt(*sessionId, *keyId, *input, *iv, [&](const auto &_hidl_out_status, const auto &_hidl_out_output) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("decrypt: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_output_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_output, sizeof(_hidl_out_output), &_hidl__hidl_out_output_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_output_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_output,
                _hidl_reply,
                _hidl__hidl_out_output_parent,
                0 /* parentOffset */, &_hidl__hidl_out_output_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_output);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "decrypt", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("decrypt: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_sign(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;
    const ::android::hardware::hidl_vec<uint8_t>* keyId;
    const ::android::hardware::hidl_vec<uint8_t>* message;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyId), &_hidl_keyId_parent,  reinterpret_cast<const void **>(&keyId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*keyId),
            _hidl_data,
            _hidl_keyId_parent,
            0 /* parentOffset */, &_hidl_keyId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_message_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*message), &_hidl_message_parent,  reinterpret_cast<const void **>(&message));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_message_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*message),
            _hidl_data,
            _hidl_message_parent,
            0 /* parentOffset */, &_hidl_message_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::sign::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        _hidl_args.push_back((void *)keyId);
        _hidl_args.push_back((void *)message);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "sign", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->sign(*sessionId, *keyId, *message, [&](const auto &_hidl_out_status, const auto &_hidl_out_signature) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("sign: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_signature_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_signature, sizeof(_hidl_out_signature), &_hidl__hidl_out_signature_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_signature_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_signature,
                _hidl_reply,
                _hidl__hidl_out_signature_parent,
                0 /* parentOffset */, &_hidl__hidl_out_signature_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_signature);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "sign", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("sign: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_verify(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;
    const ::android::hardware::hidl_vec<uint8_t>* keyId;
    const ::android::hardware::hidl_vec<uint8_t>* message;
    const ::android::hardware::hidl_vec<uint8_t>* signature;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyId), &_hidl_keyId_parent,  reinterpret_cast<const void **>(&keyId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*keyId),
            _hidl_data,
            _hidl_keyId_parent,
            0 /* parentOffset */, &_hidl_keyId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_message_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*message), &_hidl_message_parent,  reinterpret_cast<const void **>(&message));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_message_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*message),
            _hidl_data,
            _hidl_message_parent,
            0 /* parentOffset */, &_hidl_message_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_signature_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*signature), &_hidl_signature_parent,  reinterpret_cast<const void **>(&signature));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_signature_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*signature),
            _hidl_data,
            _hidl_signature_parent,
            0 /* parentOffset */, &_hidl_signature_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::verify::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        _hidl_args.push_back((void *)keyId);
        _hidl_args.push_back((void *)message);
        _hidl_args.push_back((void *)signature);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "verify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->verify(*sessionId, *keyId, *message, *signature, [&](const auto &_hidl_out_status, const auto &_hidl_out_match) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("verify: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeBool(_hidl_out_match);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_match);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "verify", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("verify: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_signRSA(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;
    const ::android::hardware::hidl_string* algorithm;
    const ::android::hardware::hidl_vec<uint8_t>* message;
    const ::android::hardware::hidl_vec<uint8_t>* wrappedkey;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_algorithm_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*algorithm), &_hidl_algorithm_parent,  reinterpret_cast<const void **>(&algorithm));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*algorithm),
            _hidl_data,
            _hidl_algorithm_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_message_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*message), &_hidl_message_parent,  reinterpret_cast<const void **>(&message));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_message_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*message),
            _hidl_data,
            _hidl_message_parent,
            0 /* parentOffset */, &_hidl_message_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_wrappedkey_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*wrappedkey), &_hidl_wrappedkey_parent,  reinterpret_cast<const void **>(&wrappedkey));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_wrappedkey_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*wrappedkey),
            _hidl_data,
            _hidl_wrappedkey_parent,
            0 /* parentOffset */, &_hidl_wrappedkey_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::signRSA::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        _hidl_args.push_back((void *)algorithm);
        _hidl_args.push_back((void *)message);
        _hidl_args.push_back((void *)wrappedkey);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "signRSA", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->signRSA(*sessionId, *algorithm, *message, *wrappedkey, [&](const auto &_hidl_out_status, const auto &_hidl_out_signature) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("signRSA: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_signature_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_signature, sizeof(_hidl_out_signature), &_hidl__hidl_out_signature_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_signature_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_signature,
                _hidl_reply,
                _hidl__hidl_out_signature_parent,
                0 /* parentOffset */, &_hidl__hidl_out_signature_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_signature);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "signRSA", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("signRSA: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_setListener(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::sp<::android::hardware::drm::V1_0::IDrmPluginListener> listener;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        listener = ::android::hardware::fromBinder<::android::hardware::drm::V1_0::IDrmPluginListener,::android::hardware::drm::V1_0::BpHwDrmPluginListener,::android::hardware::drm::V1_0::BnHwDrmPluginListener>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::setListener::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&listener);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "setListener", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->setListener(listener);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "setListener", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_sendEvent(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::drm::V1_0::EventType eventType;
    const ::android::hardware::hidl_vec<uint8_t>* sessionId;
    const ::android::hardware::hidl_vec<uint8_t>* data;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&eventType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::sendEvent::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&eventType);
        _hidl_args.push_back((void *)sessionId);
        _hidl_args.push_back((void *)data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "sendEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->sendEvent(eventType, *sessionId, *data);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "sendEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_sendExpirationUpdate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;
    int64_t expiryTimeInMS;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt64(&expiryTimeInMS);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::sendExpirationUpdate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        _hidl_args.push_back((void *)&expiryTimeInMS);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "sendExpirationUpdate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->sendExpirationUpdate(*sessionId, expiryTimeInMS);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "sendExpirationUpdate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_sendKeysChange(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDrmPlugin::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;
    const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyStatus>* keyStatusList;
    bool hasNewUsableKey;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyStatusList_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyStatusList), &_hidl_keyStatusList_parent,  reinterpret_cast<const void **>(&keyStatusList));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyStatusList_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyStatus> &>(*keyStatusList),
            _hidl_data,
            _hidl_keyStatusList_parent,
            0 /* parentOffset */, &_hidl_keyStatusList_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < keyStatusList->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::drm::V1_0::KeyStatus &>((*keyStatusList)[_hidl_index_0]),
                _hidl_data,
                _hidl_keyStatusList_child,
                _hidl_index_0 * sizeof(::android::hardware::drm::V1_0::KeyStatus));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = _hidl_data.readBool(&hasNewUsableKey);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::sendKeysChange::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        _hidl_args.push_back((void *)keyStatusList);
        _hidl_args.push_back((void *)&hasNewUsableKey);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.0", "IDrmPlugin", "sendKeysChange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->sendKeysChange(*sessionId, *keyStatusList, hasNewUsableKey);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.0", "IDrmPlugin", "sendKeysChange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::drm::V1_0::IDrmPlugin follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwDrmPlugin::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwDrmPlugin::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwDrmPlugin::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* openSession */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_openSession(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* closeSession */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_closeSession(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* getKeyRequest */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_getKeyRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* provideKeyResponse */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_provideKeyResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* removeKeys */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_removeKeys(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* restoreKeys */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_restoreKeys(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* queryKeyStatus */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_queryKeyStatus(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* getProvisionRequest */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_getProvisionRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* provideProvisionResponse */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_provideProvisionResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* getSecureStops */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_getSecureStops(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* getSecureStop */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_getSecureStop(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* releaseAllSecureStops */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_releaseAllSecureStops(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* releaseSecureStop */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_releaseSecureStop(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* getPropertyString */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_getPropertyString(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* getPropertyByteArray */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_getPropertyByteArray(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* setPropertyString */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_setPropertyString(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* setPropertyByteArray */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_setPropertyByteArray(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* setCipherAlgorithm */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_setCipherAlgorithm(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 19 /* setMacAlgorithm */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_setMacAlgorithm(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 20 /* encrypt */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_encrypt(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 21 /* decrypt */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_decrypt(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 22 /* sign */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_sign(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 23 /* verify */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_verify(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 24 /* signRSA */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_signRSA(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 25 /* setListener */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_setListener(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 26 /* sendEvent */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_sendEvent(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 27 /* sendExpirationUpdate */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_sendExpirationUpdate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 28 /* sendKeysChange */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmPlugin::_hidl_sendKeysChange(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsDrmPlugin::BsDrmPlugin(const ::android::sp<::android::hardware::drm::V1_0::IDrmPlugin> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.drm@1.0", "IDrmPlugin"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsDrmPlugin::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IDrmPlugin> IDrmPlugin::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwDrmPlugin>(serviceName, false, getStub);
}

::android::sp<IDrmPlugin> IDrmPlugin::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwDrmPlugin>(serviceName, true, getStub);
}

::android::status_t IDrmPlugin::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IDrmPlugin::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.drm@1.0::IDrmPlugin",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace drm
}  // namespace hardware
}  // namespace android
