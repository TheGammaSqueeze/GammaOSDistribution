#define LOG_TAG "android.hardware.wifi@1.0::WifiNanIfaceEventCallback"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/wifi/1.0/BpHwWifiNanIfaceEventCallback.h>
#include <android/hardware/wifi/1.0/BnHwWifiNanIfaceEventCallback.h>
#include <android/hardware/wifi/1.0/BsWifiNanIfaceEventCallback.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace wifi {
namespace V1_0 {

const char* IWifiNanIfaceEventCallback::descriptor("android.hardware.wifi@1.0::IWifiNanIfaceEventCallback");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IWifiNanIfaceEventCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwWifiNanIfaceEventCallback(static_cast<IWifiNanIfaceEventCallback *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IWifiNanIfaceEventCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsWifiNanIfaceEventCallback(static_cast<IWifiNanIfaceEventCallback *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IWifiNanIfaceEventCallback::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IWifiNanIfaceEventCallback::descriptor);
}

// Methods from ::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback follow.
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifyCapabilitiesResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status, const ::android::hardware::wifi::V1_0::NanCapabilities& capabilities)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifyEnableResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifyConfigResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifyDisableResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifyStartPublishResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status, uint8_t sessionId)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifyStopPublishResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifyStartSubscribeResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status, uint8_t sessionId)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifyStopSubscribeResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifyTransmitFollowupResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifyCreateDataInterfaceResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifyDeleteDataInterfaceResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifyInitiateDataPathResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status, uint32_t ndpInstanceId)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifyRespondToDataPathIndicationResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifyTerminateDataPathResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::eventClusterEvent(const ::android::hardware::wifi::V1_0::NanClusterEventInd& event)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::eventDisabled(const ::android::hardware::wifi::V1_0::WifiNanStatus& status)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::eventPublishTerminated(uint8_t sessionId, const ::android::hardware::wifi::V1_0::WifiNanStatus& status)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::eventSubscribeTerminated(uint8_t sessionId, const ::android::hardware::wifi::V1_0::WifiNanStatus& status)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::eventMatch(const ::android::hardware::wifi::V1_0::NanMatchInd& event)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::eventMatchExpired(uint8_t discoverySessionId, uint32_t peerId)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::eventFollowupReceived(const ::android::hardware::wifi::V1_0::NanFollowupReceivedInd& event)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::eventTransmitFollowup(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::eventDataPathRequest(const ::android::hardware::wifi::V1_0::NanDataPathRequestInd& event)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::eventDataPathConfirm(const ::android::hardware::wifi::V1_0::NanDataPathConfirmInd& event)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIfaceEventCallback::eventDataPathTerminated(uint32_t ndpInstanceId)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IWifiNanIfaceEventCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiNanIfaceEventCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiNanIfaceEventCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiNanIfaceEventCallback::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){50,92,148,243,225,165,101,181,107,188,116,250,221,189,11,167,203,130,79,38,61,204,249,223,255,45,175,98,184,110,215,116} /* 325c94f3e1a565b56bbc74faddbd0ba7cb824f263dccf9dfff2daf62b86ed774 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiNanIfaceEventCallback::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IWifiNanIfaceEventCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IWifiNanIfaceEventCallback::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiNanIfaceEventCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IWifiNanIfaceEventCallback::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IWifiNanIfaceEventCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback>> IWifiNanIfaceEventCallback::castFrom(const ::android::sp<::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback>> IWifiNanIfaceEventCallback::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IWifiNanIfaceEventCallback, ::android::hidl::base::V1_0::IBase, BpHwWifiNanIfaceEventCallback>(
            parent, "android.hardware.wifi@1.0::IWifiNanIfaceEventCallback", emitError);
}

BpHwWifiNanIfaceEventCallback::BpHwWifiNanIfaceEventCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IWifiNanIfaceEventCallback>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.wifi@1.0", "IWifiNanIfaceEventCallback") {
}

void BpHwWifiNanIfaceEventCallback::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IWifiNanIfaceEventCallback>::onLastStrongRef(id);
}
// Methods from ::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback follow.
::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_notifyCapabilitiesResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status, const ::android::hardware::wifi::V1_0::NanCapabilities& capabilities) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyCapabilitiesResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        _hidl_args.push_back((void *)&capabilities);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyCapabilitiesResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_capabilities_parent;

    _hidl_err = _hidl_data.writeBuffer(&capabilities, sizeof(capabilities), &_hidl_capabilities_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* notifyCapabilitiesResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyCapabilitiesResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_notifyEnableResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyEnableResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyEnableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* notifyEnableResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyEnableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_notifyConfigResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyConfigResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* notifyConfigResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_notifyDisableResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyDisableResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyDisableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* notifyDisableResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyDisableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_notifyStartPublishResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status, uint8_t sessionId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyStartPublishResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        _hidl_args.push_back((void *)&sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStartPublishResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint8(sessionId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* notifyStartPublishResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStartPublishResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_notifyStopPublishResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyStopPublishResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStopPublishResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* notifyStopPublishResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStopPublishResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_notifyStartSubscribeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status, uint8_t sessionId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyStartSubscribeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        _hidl_args.push_back((void *)&sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStartSubscribeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint8(sessionId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* notifyStartSubscribeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStartSubscribeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_notifyStopSubscribeResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyStopSubscribeResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStopSubscribeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* notifyStopSubscribeResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStopSubscribeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_notifyTransmitFollowupResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyTransmitFollowupResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyTransmitFollowupResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* notifyTransmitFollowupResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyTransmitFollowupResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_notifyCreateDataInterfaceResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyCreateDataInterfaceResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyCreateDataInterfaceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* notifyCreateDataInterfaceResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyCreateDataInterfaceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_notifyDeleteDataInterfaceResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyDeleteDataInterfaceResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyDeleteDataInterfaceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* notifyDeleteDataInterfaceResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyDeleteDataInterfaceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_notifyInitiateDataPathResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status, uint32_t ndpInstanceId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyInitiateDataPathResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        _hidl_args.push_back((void *)&ndpInstanceId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyInitiateDataPathResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(ndpInstanceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* notifyInitiateDataPathResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyInitiateDataPathResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_notifyRespondToDataPathIndicationResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyRespondToDataPathIndicationResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyRespondToDataPathIndicationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* notifyRespondToDataPathIndicationResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyRespondToDataPathIndicationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_notifyTerminateDataPathResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyTerminateDataPathResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyTerminateDataPathResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(14 /* notifyTerminateDataPathResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyTerminateDataPathResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_eventClusterEvent(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::wifi::V1_0::NanClusterEventInd& event) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventClusterEvent::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&event);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventClusterEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.writeBuffer(&event, sizeof(event), &_hidl_event_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(15 /* eventClusterEvent */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventClusterEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_eventDisabled(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::wifi::V1_0::WifiNanStatus& status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventDisabled::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDisabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(16 /* eventDisabled */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDisabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_eventPublishTerminated(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint8_t sessionId, const ::android::hardware::wifi::V1_0::WifiNanStatus& status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventPublishTerminated::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventPublishTerminated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint8(sessionId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(17 /* eventPublishTerminated */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventPublishTerminated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_eventSubscribeTerminated(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint8_t sessionId, const ::android::hardware::wifi::V1_0::WifiNanStatus& status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventSubscribeTerminated::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventSubscribeTerminated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint8(sessionId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(18 /* eventSubscribeTerminated */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventSubscribeTerminated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_eventMatch(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::wifi::V1_0::NanMatchInd& event) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventMatch::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&event);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventMatch", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.writeBuffer(&event, sizeof(event), &_hidl_event_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            event,
            &_hidl_data,
            _hidl_event_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(19 /* eventMatch */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventMatch", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_eventMatchExpired(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint8_t discoverySessionId, uint32_t peerId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventMatchExpired::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&discoverySessionId);
        _hidl_args.push_back((void *)&peerId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventMatchExpired", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint8(discoverySessionId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(peerId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(20 /* eventMatchExpired */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventMatchExpired", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_eventFollowupReceived(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::wifi::V1_0::NanFollowupReceivedInd& event) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventFollowupReceived::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&event);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventFollowupReceived", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.writeBuffer(&event, sizeof(event), &_hidl_event_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            event,
            &_hidl_data,
            _hidl_event_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(21 /* eventFollowupReceived */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventFollowupReceived", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_eventTransmitFollowup(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventTransmitFollowup::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventTransmitFollowup", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.writeBuffer(&status, sizeof(status), &_hidl_status_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            status,
            &_hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(22 /* eventTransmitFollowup */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventTransmitFollowup", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_eventDataPathRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::wifi::V1_0::NanDataPathRequestInd& event) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventDataPathRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&event);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDataPathRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.writeBuffer(&event, sizeof(event), &_hidl_event_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            event,
            &_hidl_data,
            _hidl_event_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(23 /* eventDataPathRequest */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDataPathRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_eventDataPathConfirm(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::wifi::V1_0::NanDataPathConfirmInd& event) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventDataPathConfirm::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&event);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDataPathConfirm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.writeBuffer(&event, sizeof(event), &_hidl_event_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            event,
            &_hidl_data,
            _hidl_event_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(24 /* eventDataPathConfirm */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDataPathConfirm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::_hidl_eventDataPathTerminated(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t ndpInstanceId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventDataPathTerminated::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&ndpInstanceId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDataPathTerminated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIfaceEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(ndpInstanceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(25 /* eventDataPathTerminated */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDataPathTerminated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback follow.
::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifyCapabilitiesResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status, const ::android::hardware::wifi::V1_0::NanCapabilities& capabilities){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_notifyCapabilitiesResponse(this, this, id, status, capabilities);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifyEnableResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_notifyEnableResponse(this, this, id, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifyConfigResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_notifyConfigResponse(this, this, id, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifyDisableResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_notifyDisableResponse(this, this, id, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifyStartPublishResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status, uint8_t sessionId){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_notifyStartPublishResponse(this, this, id, status, sessionId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifyStopPublishResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_notifyStopPublishResponse(this, this, id, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifyStartSubscribeResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status, uint8_t sessionId){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_notifyStartSubscribeResponse(this, this, id, status, sessionId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifyStopSubscribeResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_notifyStopSubscribeResponse(this, this, id, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifyTransmitFollowupResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_notifyTransmitFollowupResponse(this, this, id, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifyCreateDataInterfaceResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_notifyCreateDataInterfaceResponse(this, this, id, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifyDeleteDataInterfaceResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_notifyDeleteDataInterfaceResponse(this, this, id, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifyInitiateDataPathResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status, uint32_t ndpInstanceId){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_notifyInitiateDataPathResponse(this, this, id, status, ndpInstanceId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifyRespondToDataPathIndicationResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_notifyRespondToDataPathIndicationResponse(this, this, id, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifyTerminateDataPathResponse(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_notifyTerminateDataPathResponse(this, this, id, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::eventClusterEvent(const ::android::hardware::wifi::V1_0::NanClusterEventInd& event){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_eventClusterEvent(this, this, event);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::eventDisabled(const ::android::hardware::wifi::V1_0::WifiNanStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_eventDisabled(this, this, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::eventPublishTerminated(uint8_t sessionId, const ::android::hardware::wifi::V1_0::WifiNanStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_eventPublishTerminated(this, this, sessionId, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::eventSubscribeTerminated(uint8_t sessionId, const ::android::hardware::wifi::V1_0::WifiNanStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_eventSubscribeTerminated(this, this, sessionId, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::eventMatch(const ::android::hardware::wifi::V1_0::NanMatchInd& event){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_eventMatch(this, this, event);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::eventMatchExpired(uint8_t discoverySessionId, uint32_t peerId){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_eventMatchExpired(this, this, discoverySessionId, peerId);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::eventFollowupReceived(const ::android::hardware::wifi::V1_0::NanFollowupReceivedInd& event){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_eventFollowupReceived(this, this, event);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::eventTransmitFollowup(uint16_t id, const ::android::hardware::wifi::V1_0::WifiNanStatus& status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_eventTransmitFollowup(this, this, id, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::eventDataPathRequest(const ::android::hardware::wifi::V1_0::NanDataPathRequestInd& event){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_eventDataPathRequest(this, this, event);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::eventDataPathConfirm(const ::android::hardware::wifi::V1_0::NanDataPathConfirmInd& event){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_eventDataPathConfirm(this, this, event);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::eventDataPathTerminated(uint32_t ndpInstanceId){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback::_hidl_eventDataPathTerminated(this, this, ndpInstanceId);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwWifiNanIfaceEventCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIfaceEventCallback::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwWifiNanIfaceEventCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwWifiNanIfaceEventCallback::BnHwWifiNanIfaceEventCallback(const ::android::sp<IWifiNanIfaceEventCallback> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.wifi@1.0", "IWifiNanIfaceEventCallback") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwWifiNanIfaceEventCallback::~BnHwWifiNanIfaceEventCallback() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback follow.
::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_notifyCapabilitiesResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;
    ::android::hardware::wifi::V1_0::NanCapabilities* capabilities;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_capabilities_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*capabilities), &_hidl_capabilities_parent,  const_cast<const void**>(reinterpret_cast<void **>(&capabilities)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyCapabilitiesResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        _hidl_args.push_back((void *)capabilities);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyCapabilitiesResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->notifyCapabilitiesResponse(id, *status, *capabilities);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyCapabilitiesResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_notifyEnableResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyEnableResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyEnableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->notifyEnableResponse(id, *status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyEnableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_notifyConfigResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyConfigResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->notifyConfigResponse(id, *status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyConfigResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_notifyDisableResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyDisableResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyDisableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->notifyDisableResponse(id, *status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyDisableResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_notifyStartPublishResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;
    uint8_t sessionId;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint8(&sessionId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyStartPublishResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        _hidl_args.push_back((void *)&sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStartPublishResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->notifyStartPublishResponse(id, *status, sessionId);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStartPublishResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_notifyStopPublishResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyStopPublishResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStopPublishResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->notifyStopPublishResponse(id, *status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStopPublishResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_notifyStartSubscribeResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;
    uint8_t sessionId;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint8(&sessionId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyStartSubscribeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        _hidl_args.push_back((void *)&sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStartSubscribeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->notifyStartSubscribeResponse(id, *status, sessionId);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStartSubscribeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_notifyStopSubscribeResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyStopSubscribeResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStopSubscribeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->notifyStopSubscribeResponse(id, *status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyStopSubscribeResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_notifyTransmitFollowupResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyTransmitFollowupResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyTransmitFollowupResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->notifyTransmitFollowupResponse(id, *status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyTransmitFollowupResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_notifyCreateDataInterfaceResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyCreateDataInterfaceResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyCreateDataInterfaceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->notifyCreateDataInterfaceResponse(id, *status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyCreateDataInterfaceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_notifyDeleteDataInterfaceResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyDeleteDataInterfaceResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyDeleteDataInterfaceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->notifyDeleteDataInterfaceResponse(id, *status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyDeleteDataInterfaceResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_notifyInitiateDataPathResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;
    uint32_t ndpInstanceId;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&ndpInstanceId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyInitiateDataPathResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        _hidl_args.push_back((void *)&ndpInstanceId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyInitiateDataPathResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->notifyInitiateDataPathResponse(id, *status, ndpInstanceId);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyInitiateDataPathResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_notifyRespondToDataPathIndicationResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyRespondToDataPathIndicationResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyRespondToDataPathIndicationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->notifyRespondToDataPathIndicationResponse(id, *status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyRespondToDataPathIndicationResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_notifyTerminateDataPathResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::notifyTerminateDataPathResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyTerminateDataPathResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->notifyTerminateDataPathResponse(id, *status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "notifyTerminateDataPathResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_eventClusterEvent(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::wifi::V1_0::NanClusterEventInd* event;

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*event), &_hidl_event_parent,  const_cast<const void**>(reinterpret_cast<void **>(&event)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventClusterEvent::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)event);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventClusterEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->eventClusterEvent(*event);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventClusterEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_eventDisabled(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::wifi::V1_0::WifiNanStatus* status;

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventDisabled::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDisabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->eventDisabled(*status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDisabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_eventPublishTerminated(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint8_t sessionId;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;

    _hidl_err = _hidl_data.readUint8(&sessionId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventPublishTerminated::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventPublishTerminated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->eventPublishTerminated(sessionId, *status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventPublishTerminated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_eventSubscribeTerminated(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint8_t sessionId;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;

    _hidl_err = _hidl_data.readUint8(&sessionId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventSubscribeTerminated::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventSubscribeTerminated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->eventSubscribeTerminated(sessionId, *status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventSubscribeTerminated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_eventMatch(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::wifi::V1_0::NanMatchInd* event;

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*event), &_hidl_event_parent,  const_cast<const void**>(reinterpret_cast<void **>(&event)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::NanMatchInd &>(*event),
            _hidl_data,
            _hidl_event_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventMatch::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)event);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventMatch", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->eventMatch(*event);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventMatch", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_eventMatchExpired(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint8_t discoverySessionId;
    uint32_t peerId;

    _hidl_err = _hidl_data.readUint8(&discoverySessionId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&peerId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventMatchExpired::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&discoverySessionId);
        _hidl_args.push_back((void *)&peerId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventMatchExpired", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->eventMatchExpired(discoverySessionId, peerId);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventMatchExpired", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_eventFollowupReceived(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::wifi::V1_0::NanFollowupReceivedInd* event;

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*event), &_hidl_event_parent,  const_cast<const void**>(reinterpret_cast<void **>(&event)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::NanFollowupReceivedInd &>(*event),
            _hidl_data,
            _hidl_event_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventFollowupReceived::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)event);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventFollowupReceived", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->eventFollowupReceived(*event);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventFollowupReceived", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_eventTransmitFollowup(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t id;
    ::android::hardware::wifi::V1_0::WifiNanStatus* status;

    _hidl_err = _hidl_data.readUint16(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_status_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*status), &_hidl_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&status)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(*status),
            _hidl_data,
            _hidl_status_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventTransmitFollowup::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        _hidl_args.push_back((void *)status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventTransmitFollowup", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->eventTransmitFollowup(id, *status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventTransmitFollowup", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_eventDataPathRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::wifi::V1_0::NanDataPathRequestInd* event;

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*event), &_hidl_event_parent,  const_cast<const void**>(reinterpret_cast<void **>(&event)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::NanDataPathRequestInd &>(*event),
            _hidl_data,
            _hidl_event_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventDataPathRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)event);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDataPathRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->eventDataPathRequest(*event);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDataPathRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_eventDataPathConfirm(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::wifi::V1_0::NanDataPathConfirmInd* event;

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*event), &_hidl_event_parent,  const_cast<const void**>(reinterpret_cast<void **>(&event)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::NanDataPathConfirmInd &>(*event),
            _hidl_data,
            _hidl_event_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventDataPathConfirm::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)event);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDataPathConfirm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->eventDataPathConfirm(*event);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDataPathConfirm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwWifiNanIfaceEventCallback::_hidl_eventDataPathTerminated(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIfaceEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t ndpInstanceId;

    _hidl_err = _hidl_data.readUint32(&ndpInstanceId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIfaceEventCallback::eventDataPathTerminated::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&ndpInstanceId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDataPathTerminated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIfaceEventCallback*>(_hidl_this->getImpl().get())->eventDataPathTerminated(ndpInstanceId);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIfaceEventCallback", "eventDataPathTerminated", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwWifiNanIfaceEventCallback::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwWifiNanIfaceEventCallback::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwWifiNanIfaceEventCallback::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* notifyCapabilitiesResponse */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_notifyCapabilitiesResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* notifyEnableResponse */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_notifyEnableResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* notifyConfigResponse */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_notifyConfigResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* notifyDisableResponse */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_notifyDisableResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* notifyStartPublishResponse */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_notifyStartPublishResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* notifyStopPublishResponse */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_notifyStopPublishResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* notifyStartSubscribeResponse */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_notifyStartSubscribeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* notifyStopSubscribeResponse */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_notifyStopSubscribeResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* notifyTransmitFollowupResponse */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_notifyTransmitFollowupResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* notifyCreateDataInterfaceResponse */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_notifyCreateDataInterfaceResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* notifyDeleteDataInterfaceResponse */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_notifyDeleteDataInterfaceResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* notifyInitiateDataPathResponse */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_notifyInitiateDataPathResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* notifyRespondToDataPathIndicationResponse */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_notifyRespondToDataPathIndicationResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* notifyTerminateDataPathResponse */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_notifyTerminateDataPathResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* eventClusterEvent */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_eventClusterEvent(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* eventDisabled */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_eventDisabled(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* eventPublishTerminated */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_eventPublishTerminated(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* eventSubscribeTerminated */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_eventSubscribeTerminated(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 19 /* eventMatch */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_eventMatch(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 20 /* eventMatchExpired */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_eventMatchExpired(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 21 /* eventFollowupReceived */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_eventFollowupReceived(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 22 /* eventTransmitFollowup */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_eventTransmitFollowup(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 23 /* eventDataPathRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_eventDataPathRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 24 /* eventDataPathConfirm */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_eventDataPathConfirm(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 25 /* eventDataPathTerminated */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback::_hidl_eventDataPathTerminated(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsWifiNanIfaceEventCallback::BsWifiNanIfaceEventCallback(const ::android::sp<::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.wifi@1.0", "IWifiNanIfaceEventCallback"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsWifiNanIfaceEventCallback::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IWifiNanIfaceEventCallback> IWifiNanIfaceEventCallback::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwWifiNanIfaceEventCallback>(serviceName, false, getStub);
}

::android::sp<IWifiNanIfaceEventCallback> IWifiNanIfaceEventCallback::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwWifiNanIfaceEventCallback>(serviceName, true, getStub);
}

::android::status_t IWifiNanIfaceEventCallback::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IWifiNanIfaceEventCallback::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.wifi@1.0::IWifiNanIfaceEventCallback",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace wifi
}  // namespace hardware
}  // namespace android
