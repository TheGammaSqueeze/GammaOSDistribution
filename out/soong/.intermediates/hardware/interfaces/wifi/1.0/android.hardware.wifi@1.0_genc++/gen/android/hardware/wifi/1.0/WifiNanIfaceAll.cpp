#define LOG_TAG "android.hardware.wifi@1.0::WifiNanIface"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/wifi/1.0/BpHwWifiNanIface.h>
#include <android/hardware/wifi/1.0/BnHwWifiNanIface.h>
#include <android/hardware/wifi/1.0/BsWifiNanIface.h>
#include <android/hardware/wifi/1.0/BpHwWifiIface.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace wifi {
namespace V1_0 {

const char* IWifiNanIface::descriptor("android.hardware.wifi@1.0::IWifiNanIface");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IWifiNanIface::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwWifiNanIface(static_cast<IWifiNanIface *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IWifiNanIface::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsWifiNanIface(static_cast<IWifiNanIface *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IWifiNanIface::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IWifiNanIface::descriptor);
}

// Methods from ::android::hardware::wifi::V1_0::IWifiIface follow.
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::getType(getType_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::getName(getName_cb _hidl_cb)

// Methods from ::android::hardware::wifi::V1_0::IWifiNanIface follow.
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::registerEventCallback(const ::android::sp<::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback>& callback, registerEventCallback_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::getCapabilitiesRequest(uint16_t cmdId, getCapabilitiesRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::enableRequest(uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanEnableRequest& msg, enableRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::configRequest(uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanConfigRequest& msg, configRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::disableRequest(uint16_t cmdId, disableRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::startPublishRequest(uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanPublishRequest& msg, startPublishRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::stopPublishRequest(uint16_t cmdId, uint8_t sessionId, stopPublishRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::startSubscribeRequest(uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanSubscribeRequest& msg, startSubscribeRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::stopSubscribeRequest(uint16_t cmdId, uint8_t sessionId, stopSubscribeRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::transmitFollowupRequest(uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanTransmitFollowupRequest& msg, transmitFollowupRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::createDataInterfaceRequest(uint16_t cmdId, const ::android::hardware::hidl_string& ifaceName, createDataInterfaceRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::deleteDataInterfaceRequest(uint16_t cmdId, const ::android::hardware::hidl_string& ifaceName, deleteDataInterfaceRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::initiateDataPathRequest(uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanInitiateDataPathRequest& msg, initiateDataPathRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::respondToDataPathIndicationRequest(uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanRespondToDataPathIndicationRequest& msg, respondToDataPathIndicationRequest_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IWifiNanIface::terminateDataPathRequest(uint16_t cmdId, uint32_t ndpInstanceId, terminateDataPathRequest_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IWifiNanIface::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::wifi::V1_0::IWifiNanIface::descriptor,
        ::android::hardware::wifi::V1_0::IWifiIface::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiNanIface::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiNanIface::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::wifi::V1_0::IWifiNanIface::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiNanIface::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){186,90,167,79,27,167,20,240,9,56,100,34,121,35,73,40,8,121,91,218,97,153,196,234,8,145,50,45,39,248,201,49} /* ba5aa74f1ba714f0093864227923492808795bda6199c4ea0891322d27f8c931 */,
        (uint8_t[32]){107,154,212,58,94,251,230,202,33,79,117,30,34,206,67,207,92,212,213,213,242,203,168,15,36,204,211,117,90,114,64,28} /* 6b9ad43a5efbe6ca214f751e22ce43cf5cd4d5d5f2cba80f24ccd3755a72401c */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiNanIface::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IWifiNanIface::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IWifiNanIface::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiNanIface::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IWifiNanIface::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IWifiNanIface::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::wifi::V1_0::IWifiNanIface>> IWifiNanIface::castFrom(const ::android::sp<::android::hardware::wifi::V1_0::IWifiNanIface>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::wifi::V1_0::IWifiNanIface>> IWifiNanIface::castFrom(const ::android::sp<::android::hardware::wifi::V1_0::IWifiIface>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IWifiNanIface, ::android::hardware::wifi::V1_0::IWifiIface, BpHwWifiNanIface>(
            parent, "android.hardware.wifi@1.0::IWifiNanIface", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::wifi::V1_0::IWifiNanIface>> IWifiNanIface::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IWifiNanIface, ::android::hidl::base::V1_0::IBase, BpHwWifiNanIface>(
            parent, "android.hardware.wifi@1.0::IWifiNanIface", emitError);
}

BpHwWifiNanIface::BpHwWifiNanIface(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IWifiNanIface>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.wifi@1.0", "IWifiNanIface") {
}

void BpHwWifiNanIface::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IWifiNanIface>::onLastStrongRef(id);
}
// Methods from ::android::hardware::wifi::V1_0::IWifiNanIface follow.
::android::hardware::Return<void> BpHwWifiNanIface::_hidl_registerEventCallback(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback>& callback, registerEventCallback_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::registerEventCallback::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "registerEventCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (callback == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(callback.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* registerEventCallback */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "registerEventCallback", &_hidl_args);
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

::android::hardware::Return<void> BpHwWifiNanIface::_hidl_getCapabilitiesRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t cmdId, getCapabilitiesRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::getCapabilitiesRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "getCapabilitiesRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* getCapabilitiesRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "getCapabilitiesRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwWifiNanIface::_hidl_enableRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanEnableRequest& msg, enableRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::enableRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "enableRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.writeBuffer(&msg, sizeof(msg), &_hidl_msg_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* enableRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "enableRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwWifiNanIface::_hidl_configRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanConfigRequest& msg, configRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::configRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "configRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.writeBuffer(&msg, sizeof(msg), &_hidl_msg_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* configRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "configRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwWifiNanIface::_hidl_disableRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t cmdId, disableRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::disableRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "disableRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* disableRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "disableRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwWifiNanIface::_hidl_startPublishRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanPublishRequest& msg, startPublishRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::startPublishRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "startPublishRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.writeBuffer(&msg, sizeof(msg), &_hidl_msg_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            msg,
            &_hidl_data,
            _hidl_msg_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* startPublishRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "startPublishRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwWifiNanIface::_hidl_stopPublishRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t cmdId, uint8_t sessionId, stopPublishRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::stopPublishRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "stopPublishRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint8(sessionId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* stopPublishRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "stopPublishRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwWifiNanIface::_hidl_startSubscribeRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanSubscribeRequest& msg, startSubscribeRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::startSubscribeRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "startSubscribeRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.writeBuffer(&msg, sizeof(msg), &_hidl_msg_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            msg,
            &_hidl_data,
            _hidl_msg_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* startSubscribeRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "startSubscribeRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwWifiNanIface::_hidl_stopSubscribeRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t cmdId, uint8_t sessionId, stopSubscribeRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::stopSubscribeRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "stopSubscribeRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint8(sessionId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* stopSubscribeRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "stopSubscribeRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwWifiNanIface::_hidl_transmitFollowupRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanTransmitFollowupRequest& msg, transmitFollowupRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::transmitFollowupRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "transmitFollowupRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.writeBuffer(&msg, sizeof(msg), &_hidl_msg_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            msg,
            &_hidl_data,
            _hidl_msg_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* transmitFollowupRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "transmitFollowupRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwWifiNanIface::_hidl_createDataInterfaceRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t cmdId, const ::android::hardware::hidl_string& ifaceName, createDataInterfaceRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::createDataInterfaceRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&ifaceName);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "createDataInterfaceRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_ifaceName_parent;

    _hidl_err = _hidl_data.writeBuffer(&ifaceName, sizeof(ifaceName), &_hidl_ifaceName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            ifaceName,
            &_hidl_data,
            _hidl_ifaceName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* createDataInterfaceRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "createDataInterfaceRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwWifiNanIface::_hidl_deleteDataInterfaceRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t cmdId, const ::android::hardware::hidl_string& ifaceName, deleteDataInterfaceRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::deleteDataInterfaceRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&ifaceName);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "deleteDataInterfaceRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_ifaceName_parent;

    _hidl_err = _hidl_data.writeBuffer(&ifaceName, sizeof(ifaceName), &_hidl_ifaceName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            ifaceName,
            &_hidl_data,
            _hidl_ifaceName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(14 /* deleteDataInterfaceRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "deleteDataInterfaceRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwWifiNanIface::_hidl_initiateDataPathRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanInitiateDataPathRequest& msg, initiateDataPathRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::initiateDataPathRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "initiateDataPathRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.writeBuffer(&msg, sizeof(msg), &_hidl_msg_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            msg,
            &_hidl_data,
            _hidl_msg_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(15 /* initiateDataPathRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "initiateDataPathRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwWifiNanIface::_hidl_respondToDataPathIndicationRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanRespondToDataPathIndicationRequest& msg, respondToDataPathIndicationRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::respondToDataPathIndicationRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "respondToDataPathIndicationRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.writeBuffer(&msg, sizeof(msg), &_hidl_msg_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            msg,
            &_hidl_data,
            _hidl_msg_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(16 /* respondToDataPathIndicationRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "respondToDataPathIndicationRequest", &_hidl_args);
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

::android::hardware::Return<void> BpHwWifiNanIface::_hidl_terminateDataPathRequest(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t cmdId, uint32_t ndpInstanceId, terminateDataPathRequest_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiNanIface::terminateDataPathRequest::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&ndpInstanceId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "terminateDataPathRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiNanIface::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(ndpInstanceId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(17 /* terminateDataPathRequest */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::wifi::V1_0::WifiStatus* _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_status), &_hidl__hidl_out_status_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_status)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiStatus &>(*_hidl_out_status),
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "terminateDataPathRequest", &_hidl_args);
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


// Methods from ::android::hardware::wifi::V1_0::IWifiIface follow.
::android::hardware::Return<void> BpHwWifiNanIface::getType(getType_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiIface::_hidl_getType(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::getName(getName_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiIface::_hidl_getName(this, this, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hardware::wifi::V1_0::IWifiNanIface follow.
::android::hardware::Return<void> BpHwWifiNanIface::registerEventCallback(const ::android::sp<::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback>& callback, registerEventCallback_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_registerEventCallback(this, this, callback, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::getCapabilitiesRequest(uint16_t cmdId, getCapabilitiesRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_getCapabilitiesRequest(this, this, cmdId, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::enableRequest(uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanEnableRequest& msg, enableRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_enableRequest(this, this, cmdId, msg, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::configRequest(uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanConfigRequest& msg, configRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_configRequest(this, this, cmdId, msg, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::disableRequest(uint16_t cmdId, disableRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_disableRequest(this, this, cmdId, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::startPublishRequest(uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanPublishRequest& msg, startPublishRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_startPublishRequest(this, this, cmdId, msg, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::stopPublishRequest(uint16_t cmdId, uint8_t sessionId, stopPublishRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_stopPublishRequest(this, this, cmdId, sessionId, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::startSubscribeRequest(uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanSubscribeRequest& msg, startSubscribeRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_startSubscribeRequest(this, this, cmdId, msg, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::stopSubscribeRequest(uint16_t cmdId, uint8_t sessionId, stopSubscribeRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_stopSubscribeRequest(this, this, cmdId, sessionId, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::transmitFollowupRequest(uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanTransmitFollowupRequest& msg, transmitFollowupRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_transmitFollowupRequest(this, this, cmdId, msg, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::createDataInterfaceRequest(uint16_t cmdId, const ::android::hardware::hidl_string& ifaceName, createDataInterfaceRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_createDataInterfaceRequest(this, this, cmdId, ifaceName, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::deleteDataInterfaceRequest(uint16_t cmdId, const ::android::hardware::hidl_string& ifaceName, deleteDataInterfaceRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_deleteDataInterfaceRequest(this, this, cmdId, ifaceName, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::initiateDataPathRequest(uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanInitiateDataPathRequest& msg, initiateDataPathRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_initiateDataPathRequest(this, this, cmdId, msg, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::respondToDataPathIndicationRequest(uint16_t cmdId, const ::android::hardware::wifi::V1_0::NanRespondToDataPathIndicationRequest& msg, respondToDataPathIndicationRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_respondToDataPathIndicationRequest(this, this, cmdId, msg, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::terminateDataPathRequest(uint16_t cmdId, uint32_t ndpInstanceId, terminateDataPathRequest_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiNanIface::_hidl_terminateDataPathRequest(this, this, cmdId, ndpInstanceId, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwWifiNanIface::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwWifiNanIface::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwWifiNanIface::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiNanIface::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwWifiNanIface::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwWifiNanIface::BnHwWifiNanIface(const ::android::sp<IWifiNanIface> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.wifi@1.0", "IWifiNanIface") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwWifiNanIface::~BnHwWifiNanIface() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::wifi::V1_0::IWifiNanIface follow.
::android::status_t BnHwWifiNanIface::_hidl_registerEventCallback(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::sp<::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback> callback;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<::android::hardware::wifi::V1_0::IWifiNanIfaceEventCallback,::android::hardware::wifi::V1_0::BpHwWifiNanIfaceEventCallback,::android::hardware::wifi::V1_0::BnHwWifiNanIfaceEventCallback>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::registerEventCallback::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "registerEventCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->registerEventCallback(callback, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("registerEventCallback: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "registerEventCallback", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("registerEventCallback: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwWifiNanIface::_hidl_getCapabilitiesRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t cmdId;

    _hidl_err = _hidl_data.readUint16(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::getCapabilitiesRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "getCapabilitiesRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->getCapabilitiesRequest(cmdId, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getCapabilitiesRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "getCapabilitiesRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getCapabilitiesRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwWifiNanIface::_hidl_enableRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t cmdId;
    ::android::hardware::wifi::V1_0::NanEnableRequest* msg;

    _hidl_err = _hidl_data.readUint16(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*msg), &_hidl_msg_parent,  const_cast<const void**>(reinterpret_cast<void **>(&msg)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::enableRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "enableRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->enableRequest(cmdId, *msg, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("enableRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "enableRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("enableRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwWifiNanIface::_hidl_configRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t cmdId;
    ::android::hardware::wifi::V1_0::NanConfigRequest* msg;

    _hidl_err = _hidl_data.readUint16(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*msg), &_hidl_msg_parent,  const_cast<const void**>(reinterpret_cast<void **>(&msg)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::configRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "configRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->configRequest(cmdId, *msg, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("configRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "configRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("configRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwWifiNanIface::_hidl_disableRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t cmdId;

    _hidl_err = _hidl_data.readUint16(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::disableRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "disableRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->disableRequest(cmdId, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("disableRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "disableRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("disableRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwWifiNanIface::_hidl_startPublishRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t cmdId;
    ::android::hardware::wifi::V1_0::NanPublishRequest* msg;

    _hidl_err = _hidl_data.readUint16(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*msg), &_hidl_msg_parent,  const_cast<const void**>(reinterpret_cast<void **>(&msg)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::NanPublishRequest &>(*msg),
            _hidl_data,
            _hidl_msg_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::startPublishRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "startPublishRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->startPublishRequest(cmdId, *msg, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("startPublishRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "startPublishRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("startPublishRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwWifiNanIface::_hidl_stopPublishRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t cmdId;
    uint8_t sessionId;

    _hidl_err = _hidl_data.readUint16(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint8(&sessionId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::stopPublishRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "stopPublishRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->stopPublishRequest(cmdId, sessionId, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("stopPublishRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "stopPublishRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("stopPublishRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwWifiNanIface::_hidl_startSubscribeRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t cmdId;
    ::android::hardware::wifi::V1_0::NanSubscribeRequest* msg;

    _hidl_err = _hidl_data.readUint16(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*msg), &_hidl_msg_parent,  const_cast<const void**>(reinterpret_cast<void **>(&msg)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::NanSubscribeRequest &>(*msg),
            _hidl_data,
            _hidl_msg_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::startSubscribeRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "startSubscribeRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->startSubscribeRequest(cmdId, *msg, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("startSubscribeRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "startSubscribeRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("startSubscribeRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwWifiNanIface::_hidl_stopSubscribeRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t cmdId;
    uint8_t sessionId;

    _hidl_err = _hidl_data.readUint16(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint8(&sessionId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::stopSubscribeRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "stopSubscribeRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->stopSubscribeRequest(cmdId, sessionId, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("stopSubscribeRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "stopSubscribeRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("stopSubscribeRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwWifiNanIface::_hidl_transmitFollowupRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t cmdId;
    ::android::hardware::wifi::V1_0::NanTransmitFollowupRequest* msg;

    _hidl_err = _hidl_data.readUint16(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*msg), &_hidl_msg_parent,  const_cast<const void**>(reinterpret_cast<void **>(&msg)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::NanTransmitFollowupRequest &>(*msg),
            _hidl_data,
            _hidl_msg_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::transmitFollowupRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "transmitFollowupRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->transmitFollowupRequest(cmdId, *msg, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("transmitFollowupRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "transmitFollowupRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("transmitFollowupRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwWifiNanIface::_hidl_createDataInterfaceRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t cmdId;
    const ::android::hardware::hidl_string* ifaceName;

    _hidl_err = _hidl_data.readUint16(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_ifaceName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*ifaceName), &_hidl_ifaceName_parent,  reinterpret_cast<const void **>(&ifaceName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*ifaceName),
            _hidl_data,
            _hidl_ifaceName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::createDataInterfaceRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)ifaceName);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "createDataInterfaceRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->createDataInterfaceRequest(cmdId, *ifaceName, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("createDataInterfaceRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "createDataInterfaceRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("createDataInterfaceRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwWifiNanIface::_hidl_deleteDataInterfaceRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t cmdId;
    const ::android::hardware::hidl_string* ifaceName;

    _hidl_err = _hidl_data.readUint16(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_ifaceName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*ifaceName), &_hidl_ifaceName_parent,  reinterpret_cast<const void **>(&ifaceName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*ifaceName),
            _hidl_data,
            _hidl_ifaceName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::deleteDataInterfaceRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)ifaceName);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "deleteDataInterfaceRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->deleteDataInterfaceRequest(cmdId, *ifaceName, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("deleteDataInterfaceRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "deleteDataInterfaceRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("deleteDataInterfaceRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwWifiNanIface::_hidl_initiateDataPathRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t cmdId;
    ::android::hardware::wifi::V1_0::NanInitiateDataPathRequest* msg;

    _hidl_err = _hidl_data.readUint16(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*msg), &_hidl_msg_parent,  const_cast<const void**>(reinterpret_cast<void **>(&msg)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::NanInitiateDataPathRequest &>(*msg),
            _hidl_data,
            _hidl_msg_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::initiateDataPathRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "initiateDataPathRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->initiateDataPathRequest(cmdId, *msg, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("initiateDataPathRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "initiateDataPathRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("initiateDataPathRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwWifiNanIface::_hidl_respondToDataPathIndicationRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t cmdId;
    ::android::hardware::wifi::V1_0::NanRespondToDataPathIndicationRequest* msg;

    _hidl_err = _hidl_data.readUint16(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*msg), &_hidl_msg_parent,  const_cast<const void**>(reinterpret_cast<void **>(&msg)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::NanRespondToDataPathIndicationRequest &>(*msg),
            _hidl_data,
            _hidl_msg_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::respondToDataPathIndicationRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "respondToDataPathIndicationRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->respondToDataPathIndicationRequest(cmdId, *msg, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("respondToDataPathIndicationRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "respondToDataPathIndicationRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("respondToDataPathIndicationRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwWifiNanIface::_hidl_terminateDataPathRequest(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiNanIface::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t cmdId;
    uint32_t ndpInstanceId;

    _hidl_err = _hidl_data.readUint16(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&ndpInstanceId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiNanIface::terminateDataPathRequest::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&ndpInstanceId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiNanIface", "terminateDataPathRequest", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiNanIface*>(_hidl_this->getImpl().get())->terminateDataPathRequest(cmdId, ndpInstanceId, [&](const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("terminateDataPathRequest: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_status_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_status, sizeof(_hidl_out_status), &_hidl__hidl_out_status_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_status,
                _hidl_reply,
                _hidl__hidl_out_status_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiNanIface", "terminateDataPathRequest", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("terminateDataPathRequest: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::wifi::V1_0::IWifiIface follow.

// Methods from ::android::hardware::wifi::V1_0::IWifiNanIface follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwWifiNanIface::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwWifiNanIface::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwWifiNanIface::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* getType */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiIface::_hidl_getType(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getName */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiIface::_hidl_getName(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* registerEventCallback */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_registerEventCallback(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* getCapabilitiesRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_getCapabilitiesRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* enableRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_enableRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* configRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_configRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* disableRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_disableRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* startPublishRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_startPublishRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* stopPublishRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_stopPublishRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* startSubscribeRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_startSubscribeRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* stopSubscribeRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_stopSubscribeRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* transmitFollowupRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_transmitFollowupRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* createDataInterfaceRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_createDataInterfaceRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* deleteDataInterfaceRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_deleteDataInterfaceRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* initiateDataPathRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_initiateDataPathRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* respondToDataPathIndicationRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_respondToDataPathIndicationRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* terminateDataPathRequest */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiNanIface::_hidl_terminateDataPathRequest(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsWifiNanIface::BsWifiNanIface(const ::android::sp<::android::hardware::wifi::V1_0::IWifiNanIface> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.wifi@1.0", "IWifiNanIface"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsWifiNanIface::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IWifiNanIface> IWifiNanIface::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwWifiNanIface>(serviceName, false, getStub);
}

::android::sp<IWifiNanIface> IWifiNanIface::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwWifiNanIface>(serviceName, true, getStub);
}

::android::status_t IWifiNanIface::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IWifiNanIface::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.wifi@1.0::IWifiNanIface",
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
