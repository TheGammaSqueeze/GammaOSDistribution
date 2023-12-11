#define LOG_TAG "android.hardware.drm@1.1::DrmPlugin"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/drm/1.1/BpHwDrmPlugin.h>
#include <android/hardware/drm/1.1/BnHwDrmPlugin.h>
#include <android/hardware/drm/1.1/BsDrmPlugin.h>
#include <android/hardware/drm/1.0/BpHwDrmPlugin.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace drm {
namespace V1_1 {

const char* IDrmPlugin::descriptor("android.hardware.drm@1.1::IDrmPlugin");

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

// Methods from ::android::hardware::drm::V1_1::IDrmPlugin follow.
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::openSession_1_1(::android::hardware::drm::V1_1::SecurityLevel securityLevel, openSession_1_1_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getKeyRequest_1_1(const ::android::hardware::hidl_vec<uint8_t>& scope, const ::android::hardware::hidl_vec<uint8_t>& initData, const ::android::hardware::hidl_string& mimeType, ::android::hardware::drm::V1_0::KeyType keyType, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyValue>& optionalParameters, getKeyRequest_1_1_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getHdcpLevels(getHdcpLevels_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getNumberOfSessions(getNumberOfSessions_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getSecurityLevel(const ::android::hardware::hidl_vec<uint8_t>& sessionId, getSecurityLevel_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getMetrics(getMetrics_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getSecureStopIds(getSecureStopIds_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> IDrmPlugin::releaseSecureStops(const ::android::hardware::drm::V1_1::SecureStopRelease& ssRelease)
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> IDrmPlugin::removeSecureStop(const ::android::hardware::hidl_vec<uint8_t>& secureStopId)
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> IDrmPlugin::removeAllSecureStops()

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IDrmPlugin::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::drm::V1_1::IDrmPlugin::descriptor,
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
    _hidl_cb(::android::hardware::drm::V1_1::IDrmPlugin::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDrmPlugin::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){254,242,240,235,222,119,4,84,143,178,3,223,70,103,60,235,52,34,114,252,79,169,208,175,37,169,128,210,88,74,54,231} /* fef2f0ebde7704548fb203df46673ceb342272fc4fa9d0af25a980d2584a36e7 */,
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


::android::hardware::Return<::android::sp<::android::hardware::drm::V1_1::IDrmPlugin>> IDrmPlugin::castFrom(const ::android::sp<::android::hardware::drm::V1_1::IDrmPlugin>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::drm::V1_1::IDrmPlugin>> IDrmPlugin::castFrom(const ::android::sp<::android::hardware::drm::V1_0::IDrmPlugin>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDrmPlugin, ::android::hardware::drm::V1_0::IDrmPlugin, BpHwDrmPlugin>(
            parent, "android.hardware.drm@1.1::IDrmPlugin", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::drm::V1_1::IDrmPlugin>> IDrmPlugin::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDrmPlugin, ::android::hidl::base::V1_0::IBase, BpHwDrmPlugin>(
            parent, "android.hardware.drm@1.1::IDrmPlugin", emitError);
}

BpHwDrmPlugin::BpHwDrmPlugin(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IDrmPlugin>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.drm@1.1", "IDrmPlugin") {
}

void BpHwDrmPlugin::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IDrmPlugin>::onLastStrongRef(id);
}
// Methods from ::android::hardware::drm::V1_1::IDrmPlugin follow.
::android::hardware::Return<void> BpHwDrmPlugin::_hidl_openSession_1_1(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::drm::V1_1::SecurityLevel securityLevel, openSession_1_1_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::openSession_1_1::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&securityLevel);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "openSession_1_1", &_hidl_args);
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

    _hidl_err = _hidl_data.writeUint32((uint32_t)securityLevel);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(29 /* openSession_1_1 */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
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
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "openSession_1_1", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_getKeyRequest_1_1(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& scope, const ::android::hardware::hidl_vec<uint8_t>& initData, const ::android::hardware::hidl_string& mimeType, ::android::hardware::drm::V1_0::KeyType keyType, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyValue>& optionalParameters, getKeyRequest_1_1_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getKeyRequest_1_1::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&scope);
        _hidl_args.push_back((void *)&initData);
        _hidl_args.push_back((void *)&mimeType);
        _hidl_args.push_back((void *)&keyType);
        _hidl_args.push_back((void *)&optionalParameters);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "getKeyRequest_1_1", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(30 /* getKeyRequest_1_1 */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_request;
        ::android::hardware::drm::V1_1::KeyRequestType _hidl_out_requestType;
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
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "getKeyRequest_1_1", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_getHdcpLevels(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getHdcpLevels_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getHdcpLevels::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "getHdcpLevels", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(31 /* getHdcpLevels */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        ::android::hardware::drm::V1_1::HdcpLevel _hidl_out_connectedLevel;
        ::android::hardware::drm::V1_1::HdcpLevel _hidl_out_maxLevel;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_connectedLevel);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_maxLevel);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_connectedLevel, _hidl_out_maxLevel);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_connectedLevel);
            _hidl_args.push_back((void *)&_hidl_out_maxLevel);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "getHdcpLevels", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_getNumberOfSessions(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getNumberOfSessions_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getNumberOfSessions::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "getNumberOfSessions", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(32 /* getNumberOfSessions */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        uint32_t _hidl_out_currentSessions;
        uint32_t _hidl_out_maxSessions;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_currentSessions);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_maxSessions);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_currentSessions, _hidl_out_maxSessions);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_currentSessions);
            _hidl_args.push_back((void *)&_hidl_out_maxSessions);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "getNumberOfSessions", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_getSecurityLevel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, getSecurityLevel_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getSecurityLevel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "getSecurityLevel", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(33 /* getSecurityLevel */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        ::android::hardware::drm::V1_1::SecurityLevel _hidl_out_level;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_level);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, _hidl_out_level);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_level);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "getSecurityLevel", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_getMetrics(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getMetrics_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getMetrics::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "getMetrics", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(34 /* getMetrics */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<::android::hardware::drm::V1_1::DrmMetricGroup>* _hidl_out_metric_groups;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_metric_groups_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_metric_groups), &_hidl__hidl_out_metric_groups_parent,  reinterpret_cast<const void **>(&_hidl_out_metric_groups));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_metric_groups_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::drm::V1_1::DrmMetricGroup> &>(*_hidl_out_metric_groups),
                _hidl_reply,
                _hidl__hidl_out_metric_groups_parent,
                0 /* parentOffset */, &_hidl__hidl_out_metric_groups_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_metric_groups->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::drm::V1_1::DrmMetricGroup &>((*_hidl_out_metric_groups)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_metric_groups_child,
                    _hidl_index_0 * sizeof(::android::hardware::drm::V1_1::DrmMetricGroup));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_cb(_hidl_out_status, *_hidl_out_metric_groups);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_metric_groups);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "getMetrics", &_hidl_args);
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

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_getSecureStopIds(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getSecureStopIds_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getSecureStopIds::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "getSecureStopIds", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(35 /* getSecureStopIds */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::drm::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<::android::hardware::hidl_vec<uint8_t>>* _hidl_out_secureStopIds;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_secureStopIds_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_secureStopIds), &_hidl__hidl_out_secureStopIds_parent,  reinterpret_cast<const void **>(&_hidl_out_secureStopIds));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_secureStopIds_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_vec<uint8_t>> &>(*_hidl_out_secureStopIds),
                _hidl_reply,
                _hidl__hidl_out_secureStopIds_parent,
                0 /* parentOffset */, &_hidl__hidl_out_secureStopIds_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_secureStopIds->size(); ++_hidl_index_0) {
            size_t _hidl__hidl_out_secureStopIds_deref_indexed_child;

            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_vec<uint8_t> &>((*_hidl_out_secureStopIds)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_secureStopIds_child,
                    _hidl_index_0 * sizeof(::android::hardware::hidl_vec<uint8_t>), &_hidl__hidl_out_secureStopIds_deref_indexed_child);

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_cb(_hidl_out_status, *_hidl_out_secureStopIds);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_secureStopIds);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "getSecureStopIds", &_hidl_args);
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

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::_hidl_releaseSecureStops(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::drm::V1_1::SecureStopRelease& ssRelease) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::releaseSecureStops::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&ssRelease);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "releaseSecureStops", &_hidl_args);
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

    size_t _hidl_ssRelease_parent;

    _hidl_err = _hidl_data.writeBuffer(&ssRelease, sizeof(ssRelease), &_hidl_ssRelease_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            ssRelease,
            &_hidl_data,
            _hidl_ssRelease_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(36 /* releaseSecureStops */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "releaseSecureStops", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::_hidl_removeSecureStop(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& secureStopId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::removeSecureStop::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&secureStopId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "removeSecureStop", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(37 /* removeSecureStop */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "removeSecureStop", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::_hidl_removeAllSecureStops(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::removeAllSecureStops::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "removeAllSecureStops", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(38 /* removeAllSecureStops */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "removeAllSecureStops", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_status);
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


// Methods from ::android::hardware::drm::V1_1::IDrmPlugin follow.
::android::hardware::Return<void> BpHwDrmPlugin::openSession_1_1(::android::hardware::drm::V1_1::SecurityLevel securityLevel, openSession_1_1_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_1::BpHwDrmPlugin::_hidl_openSession_1_1(this, this, securityLevel, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getKeyRequest_1_1(const ::android::hardware::hidl_vec<uint8_t>& scope, const ::android::hardware::hidl_vec<uint8_t>& initData, const ::android::hardware::hidl_string& mimeType, ::android::hardware::drm::V1_0::KeyType keyType, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyValue>& optionalParameters, getKeyRequest_1_1_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_1::BpHwDrmPlugin::_hidl_getKeyRequest_1_1(this, this, scope, initData, mimeType, keyType, optionalParameters, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getHdcpLevels(getHdcpLevels_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_1::BpHwDrmPlugin::_hidl_getHdcpLevels(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getNumberOfSessions(getNumberOfSessions_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_1::BpHwDrmPlugin::_hidl_getNumberOfSessions(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getSecurityLevel(const ::android::hardware::hidl_vec<uint8_t>& sessionId, getSecurityLevel_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_1::BpHwDrmPlugin::_hidl_getSecurityLevel(this, this, sessionId, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getMetrics(getMetrics_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_1::BpHwDrmPlugin::_hidl_getMetrics(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getSecureStopIds(getSecureStopIds_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_1::BpHwDrmPlugin::_hidl_getSecureStopIds(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::releaseSecureStops(const ::android::hardware::drm::V1_1::SecureStopRelease& ssRelease){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_1::BpHwDrmPlugin::_hidl_releaseSecureStops(this, this, ssRelease);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::removeSecureStop(const ::android::hardware::hidl_vec<uint8_t>& secureStopId){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_1::BpHwDrmPlugin::_hidl_removeSecureStop(this, this, secureStopId);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::removeAllSecureStops(){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_1::BpHwDrmPlugin::_hidl_removeAllSecureStops(this, this);

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
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.drm@1.1", "IDrmPlugin") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwDrmPlugin::~BnHwDrmPlugin() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::drm::V1_1::IDrmPlugin follow.
::android::status_t BnHwDrmPlugin::_hidl_openSession_1_1(
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

    ::android::hardware::drm::V1_1::SecurityLevel securityLevel;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&securityLevel);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::openSession_1_1::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&securityLevel);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "openSession_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->openSession_1_1(securityLevel, [&](const auto &_hidl_out_status, const auto &_hidl_out_sessionId) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("openSession_1_1: _hidl_cb called a second time, but must be called once.");
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
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "openSession_1_1", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("openSession_1_1: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_getKeyRequest_1_1(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getKeyRequest_1_1::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)scope);
        _hidl_args.push_back((void *)initData);
        _hidl_args.push_back((void *)mimeType);
        _hidl_args.push_back((void *)&keyType);
        _hidl_args.push_back((void *)optionalParameters);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "getKeyRequest_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->getKeyRequest_1_1(*scope, *initData, *mimeType, keyType, *optionalParameters, [&](const auto &_hidl_out_status, const auto &_hidl_out_request, const auto &_hidl_out_requestType, const auto &_hidl_out_defaultUrl) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getKeyRequest_1_1: _hidl_cb called a second time, but must be called once.");
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
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "getKeyRequest_1_1", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getKeyRequest_1_1: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_getHdcpLevels(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getHdcpLevels::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "getHdcpLevels", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->getHdcpLevels([&](const auto &_hidl_out_status, const auto &_hidl_out_connectedLevel, const auto &_hidl_out_maxLevel) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getHdcpLevels: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_connectedLevel);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_maxLevel);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_connectedLevel);
            _hidl_args.push_back((void *)&_hidl_out_maxLevel);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "getHdcpLevels", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getHdcpLevels: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_getNumberOfSessions(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getNumberOfSessions::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "getNumberOfSessions", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->getNumberOfSessions([&](const auto &_hidl_out_status, const auto &_hidl_out_currentSessions, const auto &_hidl_out_maxSessions) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getNumberOfSessions: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_currentSessions);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_maxSessions);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_currentSessions);
            _hidl_args.push_back((void *)&_hidl_out_maxSessions);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "getNumberOfSessions", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getNumberOfSessions: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_getSecurityLevel(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getSecurityLevel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "getSecurityLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->getSecurityLevel(*sessionId, [&](const auto &_hidl_out_status, const auto &_hidl_out_level) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getSecurityLevel: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_level);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_level);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "getSecurityLevel", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getSecurityLevel: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_getMetrics(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getMetrics::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "getMetrics", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->getMetrics([&](const auto &_hidl_out_status, const auto &_hidl_out_metric_groups) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getMetrics: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_metric_groups_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_metric_groups, sizeof(_hidl_out_metric_groups), &_hidl__hidl_out_metric_groups_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_metric_groups_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_metric_groups,
                _hidl_reply,
                _hidl__hidl_out_metric_groups_parent,
                0 /* parentOffset */, &_hidl__hidl_out_metric_groups_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_metric_groups.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_metric_groups[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_metric_groups_child,
                    _hidl_index_0 * sizeof(::android::hardware::drm::V1_1::DrmMetricGroup));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_metric_groups);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "getMetrics", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getMetrics: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_getSecureStopIds(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getSecureStopIds::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "getSecureStopIds", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->getSecureStopIds([&](const auto &_hidl_out_status, const auto &_hidl_out_secureStopIds) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getSecureStopIds: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_secureStopIds_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_secureStopIds, sizeof(_hidl_out_secureStopIds), &_hidl__hidl_out_secureStopIds_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_secureStopIds_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_secureStopIds,
                _hidl_reply,
                _hidl__hidl_out_secureStopIds_parent,
                0 /* parentOffset */, &_hidl__hidl_out_secureStopIds_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_secureStopIds.size(); ++_hidl_index_0) {
            size_t _hidl__hidl_out_secureStopIds_indexed_child;

            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    _hidl_out_secureStopIds[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_secureStopIds_child,
                    _hidl_index_0 * sizeof(::android::hardware::hidl_vec<uint8_t>), &_hidl__hidl_out_secureStopIds_indexed_child);

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_secureStopIds);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "getSecureStopIds", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getSecureStopIds: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_releaseSecureStops(
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

    ::android::hardware::drm::V1_1::SecureStopRelease* ssRelease;

    size_t _hidl_ssRelease_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*ssRelease), &_hidl_ssRelease_parent,  const_cast<const void**>(reinterpret_cast<void **>(&ssRelease)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::drm::V1_1::SecureStopRelease &>(*ssRelease),
            _hidl_data,
            _hidl_ssRelease_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::releaseSecureStops::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)ssRelease);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "releaseSecureStops", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::drm::V1_0::Status _hidl_out_status = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->releaseSecureStops(*ssRelease);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "releaseSecureStops", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_removeSecureStop(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::removeSecureStop::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)secureStopId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "removeSecureStop", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::drm::V1_0::Status _hidl_out_status = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->removeSecureStop(*secureStopId);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "removeSecureStop", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_removeAllSecureStops(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::removeAllSecureStops::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.1", "IDrmPlugin", "removeAllSecureStops", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::drm::V1_0::Status _hidl_out_status = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->removeAllSecureStops();

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.1", "IDrmPlugin", "removeAllSecureStops", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::drm::V1_0::IDrmPlugin follow.

// Methods from ::android::hardware::drm::V1_1::IDrmPlugin follow.

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

        case 29 /* openSession_1_1 */:
        {
            _hidl_err = ::android::hardware::drm::V1_1::BnHwDrmPlugin::_hidl_openSession_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 30 /* getKeyRequest_1_1 */:
        {
            _hidl_err = ::android::hardware::drm::V1_1::BnHwDrmPlugin::_hidl_getKeyRequest_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 31 /* getHdcpLevels */:
        {
            _hidl_err = ::android::hardware::drm::V1_1::BnHwDrmPlugin::_hidl_getHdcpLevels(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 32 /* getNumberOfSessions */:
        {
            _hidl_err = ::android::hardware::drm::V1_1::BnHwDrmPlugin::_hidl_getNumberOfSessions(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 33 /* getSecurityLevel */:
        {
            _hidl_err = ::android::hardware::drm::V1_1::BnHwDrmPlugin::_hidl_getSecurityLevel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 34 /* getMetrics */:
        {
            _hidl_err = ::android::hardware::drm::V1_1::BnHwDrmPlugin::_hidl_getMetrics(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 35 /* getSecureStopIds */:
        {
            _hidl_err = ::android::hardware::drm::V1_1::BnHwDrmPlugin::_hidl_getSecureStopIds(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 36 /* releaseSecureStops */:
        {
            _hidl_err = ::android::hardware::drm::V1_1::BnHwDrmPlugin::_hidl_releaseSecureStops(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 37 /* removeSecureStop */:
        {
            _hidl_err = ::android::hardware::drm::V1_1::BnHwDrmPlugin::_hidl_removeSecureStop(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 38 /* removeAllSecureStops */:
        {
            _hidl_err = ::android::hardware::drm::V1_1::BnHwDrmPlugin::_hidl_removeAllSecureStops(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsDrmPlugin::BsDrmPlugin(const ::android::sp<::android::hardware::drm::V1_1::IDrmPlugin> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.drm@1.1", "IDrmPlugin"), mImpl(impl) {
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
            sm->registerForNotifications("android.hardware.drm@1.1::IDrmPlugin",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_1
}  // namespace drm
}  // namespace hardware
}  // namespace android
