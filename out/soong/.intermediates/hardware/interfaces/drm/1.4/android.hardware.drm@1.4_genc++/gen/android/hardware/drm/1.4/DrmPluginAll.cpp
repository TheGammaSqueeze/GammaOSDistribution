#define LOG_TAG "android.hardware.drm@1.4::DrmPlugin"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/drm/1.4/BpHwDrmPlugin.h>
#include <android/hardware/drm/1.4/BnHwDrmPlugin.h>
#include <android/hardware/drm/1.4/BsDrmPlugin.h>
#include <android/hardware/drm/1.2/BpHwDrmPlugin.h>
#include <android/hardware/drm/1.1/BpHwDrmPlugin.h>
#include <android/hardware/drm/1.0/BpHwDrmPlugin.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace drm {
namespace V1_4 {

const char* IDrmPlugin::descriptor("android.hardware.drm@1.4::IDrmPlugin");

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

// Methods from ::android::hardware::drm::V1_2::IDrmPlugin follow.
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getOfflineLicenseKeySetIds(getOfflineLicenseKeySetIds_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> IDrmPlugin::removeOfflineLicense(const ::android::hardware::hidl_vec<uint8_t>& keySetId)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getOfflineLicenseState(const ::android::hardware::hidl_vec<uint8_t>& keySetId, getOfflineLicenseState_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getKeyRequest_1_2(const ::android::hardware::hidl_vec<uint8_t>& scope, const ::android::hardware::hidl_vec<uint8_t>& initData, const ::android::hardware::hidl_string& mimeType, ::android::hardware::drm::V1_0::KeyType keyType, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyValue>& optionalParameters, getKeyRequest_1_2_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getProvisionRequest_1_2(const ::android::hardware::hidl_string& certificateType, const ::android::hardware::hidl_string& certificateAuthority, getProvisionRequest_1_2_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getHdcpLevels_1_2(getHdcpLevels_1_2_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::sendSessionLostState(const ::android::hardware::hidl_vec<uint8_t>& sessionId)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::sendKeysChange_1_2(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_2::KeyStatus>& keyStatusList, bool hasNewUsableKey)

// Methods from ::android::hardware::drm::V1_4::IDrmPlugin follow.
// no default implementation for: ::android::hardware::Return<bool> IDrmPlugin::requiresSecureDecoder(const ::android::hardware::hidl_string& mime, ::android::hardware::drm::V1_1::SecurityLevel level)
// no default implementation for: ::android::hardware::Return<bool> IDrmPlugin::requiresSecureDecoderDefault(const ::android::hardware::hidl_string& mime)
// no default implementation for: ::android::hardware::Return<::android::hardware::drm::V1_0::Status> IDrmPlugin::setPlaybackId(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_string& playbackId)
// no default implementation for: ::android::hardware::Return<void> IDrmPlugin::getLogMessages(getLogMessages_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IDrmPlugin::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::drm::V1_4::IDrmPlugin::descriptor,
        ::android::hardware::drm::V1_2::IDrmPlugin::descriptor,
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
    _hidl_cb(::android::hardware::drm::V1_4::IDrmPlugin::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDrmPlugin::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){167,31,162,72,65,241,57,134,32,249,186,247,56,134,61,186,242,155,222,98,205,23,26,199,180,96,135,151,202,85,227,93} /* a71fa24841f1398620f9baf738863dbaf29bde62cd171ac7b4608797ca55e35d */,
        (uint8_t[32]){142,241,202,249,33,195,232,58,0,24,15,119,14,59,142,143,246,93,138,92,128,100,130,229,26,164,94,109,85,241,174,193} /* 8ef1caf921c3e83a00180f770e3b8e8ff65d8a5c806482e51aa45e6d55f1aec1 */,
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


::android::hardware::Return<::android::sp<::android::hardware::drm::V1_4::IDrmPlugin>> IDrmPlugin::castFrom(const ::android::sp<::android::hardware::drm::V1_4::IDrmPlugin>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::drm::V1_4::IDrmPlugin>> IDrmPlugin::castFrom(const ::android::sp<::android::hardware::drm::V1_2::IDrmPlugin>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDrmPlugin, ::android::hardware::drm::V1_2::IDrmPlugin, BpHwDrmPlugin>(
            parent, "android.hardware.drm@1.4::IDrmPlugin", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::drm::V1_4::IDrmPlugin>> IDrmPlugin::castFrom(const ::android::sp<::android::hardware::drm::V1_1::IDrmPlugin>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDrmPlugin, ::android::hardware::drm::V1_1::IDrmPlugin, BpHwDrmPlugin>(
            parent, "android.hardware.drm@1.4::IDrmPlugin", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::drm::V1_4::IDrmPlugin>> IDrmPlugin::castFrom(const ::android::sp<::android::hardware::drm::V1_0::IDrmPlugin>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDrmPlugin, ::android::hardware::drm::V1_0::IDrmPlugin, BpHwDrmPlugin>(
            parent, "android.hardware.drm@1.4::IDrmPlugin", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::drm::V1_4::IDrmPlugin>> IDrmPlugin::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDrmPlugin, ::android::hidl::base::V1_0::IBase, BpHwDrmPlugin>(
            parent, "android.hardware.drm@1.4::IDrmPlugin", emitError);
}

BpHwDrmPlugin::BpHwDrmPlugin(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IDrmPlugin>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.drm@1.4", "IDrmPlugin") {
}

void BpHwDrmPlugin::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IDrmPlugin>::onLastStrongRef(id);
}
// Methods from ::android::hardware::drm::V1_4::IDrmPlugin follow.
::android::hardware::Return<bool> BpHwDrmPlugin::_hidl_requiresSecureDecoder(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& mime, ::android::hardware::drm::V1_1::SecurityLevel level) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::requiresSecureDecoder::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&mime);
        _hidl_args.push_back((void *)&level);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.4", "IDrmPlugin", "requiresSecureDecoder", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    bool _hidl_out_secureRequired;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_mime_parent;

    _hidl_err = _hidl_data.writeBuffer(&mime, sizeof(mime), &_hidl_mime_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            mime,
            &_hidl_data,
            _hidl_mime_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32((uint32_t)level);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(47 /* requiresSecureDecoder */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readBool(&_hidl_out_secureRequired);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_secureRequired);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.4", "IDrmPlugin", "requiresSecureDecoder", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<bool>(_hidl_out_secureRequired);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<bool>(_hidl_status);
}

::android::hardware::Return<bool> BpHwDrmPlugin::_hidl_requiresSecureDecoderDefault(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& mime) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::requiresSecureDecoderDefault::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&mime);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.4", "IDrmPlugin", "requiresSecureDecoderDefault", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    bool _hidl_out_secureRequired;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDrmPlugin::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_mime_parent;

    _hidl_err = _hidl_data.writeBuffer(&mime, sizeof(mime), &_hidl_mime_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            mime,
            &_hidl_data,
            _hidl_mime_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(48 /* requiresSecureDecoderDefault */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readBool(&_hidl_out_secureRequired);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_secureRequired);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.4", "IDrmPlugin", "requiresSecureDecoderDefault", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<bool>(_hidl_out_secureRequired);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<bool>(_hidl_status);
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::_hidl_setPlaybackId(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_string& playbackId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::setPlaybackId::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&playbackId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.4", "IDrmPlugin", "setPlaybackId", &_hidl_args);
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

    size_t _hidl_playbackId_parent;

    _hidl_err = _hidl_data.writeBuffer(&playbackId, sizeof(playbackId), &_hidl_playbackId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            playbackId,
            &_hidl_data,
            _hidl_playbackId_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(49 /* setPlaybackId */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.4", "IDrmPlugin", "setPlaybackId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::drm::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwDrmPlugin::_hidl_getLogMessages(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getLogMessages_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getLogMessages::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.drm", "1.4", "IDrmPlugin", "getLogMessages", &_hidl_args);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(50 /* getLogMessages */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
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
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.drm", "1.4", "IDrmPlugin", "getLogMessages", &_hidl_args);
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


// Methods from ::android::hardware::drm::V1_2::IDrmPlugin follow.
::android::hardware::Return<void> BpHwDrmPlugin::getOfflineLicenseKeySetIds(getOfflineLicenseKeySetIds_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_2::BpHwDrmPlugin::_hidl_getOfflineLicenseKeySetIds(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::removeOfflineLicense(const ::android::hardware::hidl_vec<uint8_t>& keySetId){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_2::BpHwDrmPlugin::_hidl_removeOfflineLicense(this, this, keySetId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getOfflineLicenseState(const ::android::hardware::hidl_vec<uint8_t>& keySetId, getOfflineLicenseState_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_2::BpHwDrmPlugin::_hidl_getOfflineLicenseState(this, this, keySetId, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getKeyRequest_1_2(const ::android::hardware::hidl_vec<uint8_t>& scope, const ::android::hardware::hidl_vec<uint8_t>& initData, const ::android::hardware::hidl_string& mimeType, ::android::hardware::drm::V1_0::KeyType keyType, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyValue>& optionalParameters, getKeyRequest_1_2_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_2::BpHwDrmPlugin::_hidl_getKeyRequest_1_2(this, this, scope, initData, mimeType, keyType, optionalParameters, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getProvisionRequest_1_2(const ::android::hardware::hidl_string& certificateType, const ::android::hardware::hidl_string& certificateAuthority, getProvisionRequest_1_2_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_2::BpHwDrmPlugin::_hidl_getProvisionRequest_1_2(this, this, certificateType, certificateAuthority, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getHdcpLevels_1_2(getHdcpLevels_1_2_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_2::BpHwDrmPlugin::_hidl_getHdcpLevels_1_2(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::sendSessionLostState(const ::android::hardware::hidl_vec<uint8_t>& sessionId){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_2::BpHwDrmPlugin::_hidl_sendSessionLostState(this, this, sessionId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::sendKeysChange_1_2(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_2::KeyStatus>& keyStatusList, bool hasNewUsableKey){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_2::BpHwDrmPlugin::_hidl_sendKeysChange_1_2(this, this, sessionId, keyStatusList, hasNewUsableKey);

    return _hidl_out;
}


// Methods from ::android::hardware::drm::V1_4::IDrmPlugin follow.
::android::hardware::Return<bool> BpHwDrmPlugin::requiresSecureDecoder(const ::android::hardware::hidl_string& mime, ::android::hardware::drm::V1_1::SecurityLevel level){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::drm::V1_4::BpHwDrmPlugin::_hidl_requiresSecureDecoder(this, this, mime, level);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwDrmPlugin::requiresSecureDecoderDefault(const ::android::hardware::hidl_string& mime){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::drm::V1_4::BpHwDrmPlugin::_hidl_requiresSecureDecoderDefault(this, this, mime);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::drm::V1_0::Status> BpHwDrmPlugin::setPlaybackId(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_string& playbackId){
    ::android::hardware::Return<::android::hardware::drm::V1_0::Status>  _hidl_out = ::android::hardware::drm::V1_4::BpHwDrmPlugin::_hidl_setPlaybackId(this, this, sessionId, playbackId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmPlugin::getLogMessages(getLogMessages_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_4::BpHwDrmPlugin::_hidl_getLogMessages(this, this, _hidl_cb);

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
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.drm@1.4", "IDrmPlugin") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwDrmPlugin::~BnHwDrmPlugin() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::drm::V1_4::IDrmPlugin follow.
::android::status_t BnHwDrmPlugin::_hidl_requiresSecureDecoder(
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

    const ::android::hardware::hidl_string* mime;
    ::android::hardware::drm::V1_1::SecurityLevel level;

    size_t _hidl_mime_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*mime), &_hidl_mime_parent,  reinterpret_cast<const void **>(&mime));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*mime),
            _hidl_data,
            _hidl_mime_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32((uint32_t *)&level);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::requiresSecureDecoder::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)mime);
        _hidl_args.push_back((void *)&level);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.4", "IDrmPlugin", "requiresSecureDecoder", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_out_secureRequired = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->requiresSecureDecoder(*mime, level);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeBool(_hidl_out_secureRequired);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_secureRequired);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.4", "IDrmPlugin", "requiresSecureDecoder", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_requiresSecureDecoderDefault(
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

    const ::android::hardware::hidl_string* mime;

    size_t _hidl_mime_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*mime), &_hidl_mime_parent,  reinterpret_cast<const void **>(&mime));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*mime),
            _hidl_data,
            _hidl_mime_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::requiresSecureDecoderDefault::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)mime);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.4", "IDrmPlugin", "requiresSecureDecoderDefault", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_out_secureRequired = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->requiresSecureDecoderDefault(*mime);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeBool(_hidl_out_secureRequired);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_secureRequired);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.4", "IDrmPlugin", "requiresSecureDecoderDefault", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_setPlaybackId(
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
    const ::android::hardware::hidl_string* playbackId;

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

    size_t _hidl_playbackId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*playbackId), &_hidl_playbackId_parent,  reinterpret_cast<const void **>(&playbackId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*playbackId),
            _hidl_data,
            _hidl_playbackId_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::setPlaybackId::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        _hidl_args.push_back((void *)playbackId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.4", "IDrmPlugin", "setPlaybackId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::drm::V1_0::Status _hidl_out_status = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->setPlaybackId(*sessionId, *playbackId);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.4", "IDrmPlugin", "setPlaybackId", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDrmPlugin::_hidl_getLogMessages(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDrmPlugin::getLogMessages::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.drm", "1.4", "IDrmPlugin", "getLogMessages", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDrmPlugin*>(_hidl_this->getImpl().get())->getLogMessages([&](const auto &_hidl_out_status, const auto &_hidl_out_logMessages) {
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
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.drm", "1.4", "IDrmPlugin", "getLogMessages", &_hidl_args);
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


// Methods from ::android::hardware::drm::V1_0::IDrmPlugin follow.

// Methods from ::android::hardware::drm::V1_1::IDrmPlugin follow.

// Methods from ::android::hardware::drm::V1_2::IDrmPlugin follow.

// Methods from ::android::hardware::drm::V1_4::IDrmPlugin follow.

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

        case 39 /* getOfflineLicenseKeySetIds */:
        {
            _hidl_err = ::android::hardware::drm::V1_2::BnHwDrmPlugin::_hidl_getOfflineLicenseKeySetIds(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 40 /* removeOfflineLicense */:
        {
            _hidl_err = ::android::hardware::drm::V1_2::BnHwDrmPlugin::_hidl_removeOfflineLicense(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 41 /* getOfflineLicenseState */:
        {
            _hidl_err = ::android::hardware::drm::V1_2::BnHwDrmPlugin::_hidl_getOfflineLicenseState(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 42 /* getKeyRequest_1_2 */:
        {
            _hidl_err = ::android::hardware::drm::V1_2::BnHwDrmPlugin::_hidl_getKeyRequest_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 43 /* getProvisionRequest_1_2 */:
        {
            _hidl_err = ::android::hardware::drm::V1_2::BnHwDrmPlugin::_hidl_getProvisionRequest_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 44 /* getHdcpLevels_1_2 */:
        {
            _hidl_err = ::android::hardware::drm::V1_2::BnHwDrmPlugin::_hidl_getHdcpLevels_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 45 /* sendSessionLostState */:
        {
            _hidl_err = ::android::hardware::drm::V1_2::BnHwDrmPlugin::_hidl_sendSessionLostState(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 46 /* sendKeysChange_1_2 */:
        {
            _hidl_err = ::android::hardware::drm::V1_2::BnHwDrmPlugin::_hidl_sendKeysChange_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 47 /* requiresSecureDecoder */:
        {
            _hidl_err = ::android::hardware::drm::V1_4::BnHwDrmPlugin::_hidl_requiresSecureDecoder(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 48 /* requiresSecureDecoderDefault */:
        {
            _hidl_err = ::android::hardware::drm::V1_4::BnHwDrmPlugin::_hidl_requiresSecureDecoderDefault(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 49 /* setPlaybackId */:
        {
            _hidl_err = ::android::hardware::drm::V1_4::BnHwDrmPlugin::_hidl_setPlaybackId(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 50 /* getLogMessages */:
        {
            _hidl_err = ::android::hardware::drm::V1_4::BnHwDrmPlugin::_hidl_getLogMessages(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsDrmPlugin::BsDrmPlugin(const ::android::sp<::android::hardware::drm::V1_4::IDrmPlugin> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.drm@1.4", "IDrmPlugin"), mImpl(impl) {
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
            sm->registerForNotifications("android.hardware.drm@1.4::IDrmPlugin",
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
