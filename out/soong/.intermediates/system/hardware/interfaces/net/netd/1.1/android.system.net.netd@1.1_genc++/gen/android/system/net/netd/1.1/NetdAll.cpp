#define LOG_TAG "android.system.net.netd@1.1::Netd"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/system/net/netd/1.1/BpHwNetd.h>
#include <android/system/net/netd/1.1/BnHwNetd.h>
#include <android/system/net/netd/1.1/BsNetd.h>
#include <android/system/net/netd/1.0/BpHwNetd.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace system {
namespace net {
namespace netd {
namespace V1_1 {

const char* INetd::descriptor("android.system.net.netd@1.1::INetd");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(INetd::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwNetd(static_cast<INetd *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(INetd::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsNetd(static_cast<INetd *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(INetd::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(INetd::descriptor);
}

// Methods from ::android::system::net::netd::V1_0::INetd follow.
// no default implementation for: ::android::hardware::Return<void> INetd::createOemNetwork(createOemNetwork_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> INetd::destroyOemNetwork(uint64_t networkHandle)

// Methods from ::android::system::net::netd::V1_1::INetd follow.
// no default implementation for: ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> INetd::addRouteToOemNetwork(uint64_t networkHandle, const ::android::hardware::hidl_string& ifname, const ::android::hardware::hidl_string& destination, const ::android::hardware::hidl_string& nexthop)
// no default implementation for: ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> INetd::removeRouteFromOemNetwork(uint64_t networkHandle, const ::android::hardware::hidl_string& ifname, const ::android::hardware::hidl_string& destination, const ::android::hardware::hidl_string& nexthop)
// no default implementation for: ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> INetd::addInterfaceToOemNetwork(uint64_t networkHandle, const ::android::hardware::hidl_string& ifname)
// no default implementation for: ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> INetd::removeInterfaceFromOemNetwork(uint64_t networkHandle, const ::android::hardware::hidl_string& ifname)
// no default implementation for: ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> INetd::setIpForwardEnable(bool enable)
// no default implementation for: ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> INetd::setForwardingBetweenInterfaces(const ::android::hardware::hidl_string& inputIfName, const ::android::hardware::hidl_string& outputIfName, bool enable)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> INetd::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::system::net::netd::V1_1::INetd::descriptor,
        ::android::system::net::netd::V1_0::INetd::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> INetd::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> INetd::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::system::net::netd::V1_1::INetd::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> INetd::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){66,26,172,9,244,146,141,174,187,191,254,51,2,241,92,111,104,210,181,228,185,198,113,229,40,218,138,89,145,51,144,108} /* 421aac09f4928daebbbffe3302f15c6f68d2b5e4b9c671e528da8a599133906c */,
        (uint8_t[32]){44,253,121,24,172,240,148,98,254,143,227,245,96,139,226,149,108,159,115,124,120,211,187,63,23,108,197,83,28,9,245,214} /* 2cfd7918acf09462fe8fe3f5608be2956c9f737c78d3bb3f176cc5531c09f5d6 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> INetd::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> INetd::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> INetd::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> INetd::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> INetd::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> INetd::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::system::net::netd::V1_1::INetd>> INetd::castFrom(const ::android::sp<::android::system::net::netd::V1_1::INetd>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::system::net::netd::V1_1::INetd>> INetd::castFrom(const ::android::sp<::android::system::net::netd::V1_0::INetd>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<INetd, ::android::system::net::netd::V1_0::INetd, BpHwNetd>(
            parent, "android.system.net.netd@1.1::INetd", emitError);
}

::android::hardware::Return<::android::sp<::android::system::net::netd::V1_1::INetd>> INetd::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<INetd, ::android::hidl::base::V1_0::IBase, BpHwNetd>(
            parent, "android.system.net.netd@1.1::INetd", emitError);
}

BpHwNetd::BpHwNetd(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<INetd>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.system.net.netd@1.1", "INetd") {
}

void BpHwNetd::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<INetd>::onLastStrongRef(id);
}
// Methods from ::android::system::net::netd::V1_1::INetd follow.
::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> BpHwNetd::_hidl_addRouteToOemNetwork(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t networkHandle, const ::android::hardware::hidl_string& ifname, const ::android::hardware::hidl_string& destination, const ::android::hardware::hidl_string& nexthop) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::INetd::addRouteToOemNetwork::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&networkHandle);
        _hidl_args.push_back((void *)&ifname);
        _hidl_args.push_back((void *)&destination);
        _hidl_args.push_back((void *)&nexthop);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.system.net.netd", "1.1", "INetd", "addRouteToOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::system::net::netd::V1_0::INetd::StatusCode _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwNetd::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(networkHandle);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_ifname_parent;

    _hidl_err = _hidl_data.writeBuffer(&ifname, sizeof(ifname), &_hidl_ifname_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            ifname,
            &_hidl_data,
            _hidl_ifname_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_destination_parent;

    _hidl_err = _hidl_data.writeBuffer(&destination, sizeof(destination), &_hidl_destination_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            destination,
            &_hidl_data,
            _hidl_destination_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_nexthop_parent;

    _hidl_err = _hidl_data.writeBuffer(&nexthop, sizeof(nexthop), &_hidl_nexthop_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            nexthop,
            &_hidl_data,
            _hidl_nexthop_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* addRouteToOemNetwork */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.system.net.netd", "1.1", "INetd", "addRouteToOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>(_hidl_status);
}

::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> BpHwNetd::_hidl_removeRouteFromOemNetwork(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t networkHandle, const ::android::hardware::hidl_string& ifname, const ::android::hardware::hidl_string& destination, const ::android::hardware::hidl_string& nexthop) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::INetd::removeRouteFromOemNetwork::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&networkHandle);
        _hidl_args.push_back((void *)&ifname);
        _hidl_args.push_back((void *)&destination);
        _hidl_args.push_back((void *)&nexthop);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.system.net.netd", "1.1", "INetd", "removeRouteFromOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::system::net::netd::V1_0::INetd::StatusCode _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwNetd::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(networkHandle);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_ifname_parent;

    _hidl_err = _hidl_data.writeBuffer(&ifname, sizeof(ifname), &_hidl_ifname_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            ifname,
            &_hidl_data,
            _hidl_ifname_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_destination_parent;

    _hidl_err = _hidl_data.writeBuffer(&destination, sizeof(destination), &_hidl_destination_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            destination,
            &_hidl_data,
            _hidl_destination_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_nexthop_parent;

    _hidl_err = _hidl_data.writeBuffer(&nexthop, sizeof(nexthop), &_hidl_nexthop_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            nexthop,
            &_hidl_data,
            _hidl_nexthop_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* removeRouteFromOemNetwork */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.system.net.netd", "1.1", "INetd", "removeRouteFromOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>(_hidl_status);
}

::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> BpHwNetd::_hidl_addInterfaceToOemNetwork(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t networkHandle, const ::android::hardware::hidl_string& ifname) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::INetd::addInterfaceToOemNetwork::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&networkHandle);
        _hidl_args.push_back((void *)&ifname);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.system.net.netd", "1.1", "INetd", "addInterfaceToOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::system::net::netd::V1_0::INetd::StatusCode _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwNetd::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(networkHandle);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_ifname_parent;

    _hidl_err = _hidl_data.writeBuffer(&ifname, sizeof(ifname), &_hidl_ifname_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            ifname,
            &_hidl_data,
            _hidl_ifname_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* addInterfaceToOemNetwork */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.system.net.netd", "1.1", "INetd", "addInterfaceToOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>(_hidl_status);
}

::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> BpHwNetd::_hidl_removeInterfaceFromOemNetwork(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t networkHandle, const ::android::hardware::hidl_string& ifname) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::INetd::removeInterfaceFromOemNetwork::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&networkHandle);
        _hidl_args.push_back((void *)&ifname);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.system.net.netd", "1.1", "INetd", "removeInterfaceFromOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::system::net::netd::V1_0::INetd::StatusCode _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwNetd::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(networkHandle);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_ifname_parent;

    _hidl_err = _hidl_data.writeBuffer(&ifname, sizeof(ifname), &_hidl_ifname_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            ifname,
            &_hidl_data,
            _hidl_ifname_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* removeInterfaceFromOemNetwork */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.system.net.netd", "1.1", "INetd", "removeInterfaceFromOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>(_hidl_status);
}

::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> BpHwNetd::_hidl_setIpForwardEnable(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool enable) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::INetd::setIpForwardEnable::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&enable);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.system.net.netd", "1.1", "INetd", "setIpForwardEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::system::net::netd::V1_0::INetd::StatusCode _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwNetd::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(enable);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* setIpForwardEnable */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.system.net.netd", "1.1", "INetd", "setIpForwardEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>(_hidl_status);
}

::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> BpHwNetd::_hidl_setForwardingBetweenInterfaces(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& inputIfName, const ::android::hardware::hidl_string& outputIfName, bool enable) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::INetd::setForwardingBetweenInterfaces::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&inputIfName);
        _hidl_args.push_back((void *)&outputIfName);
        _hidl_args.push_back((void *)&enable);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.system.net.netd", "1.1", "INetd", "setForwardingBetweenInterfaces", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::system::net::netd::V1_0::INetd::StatusCode _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwNetd::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inputIfName_parent;

    _hidl_err = _hidl_data.writeBuffer(&inputIfName, sizeof(inputIfName), &_hidl_inputIfName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            inputIfName,
            &_hidl_data,
            _hidl_inputIfName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_outputIfName_parent;

    _hidl_err = _hidl_data.writeBuffer(&outputIfName, sizeof(outputIfName), &_hidl_outputIfName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            outputIfName,
            &_hidl_data,
            _hidl_outputIfName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(enable);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* setForwardingBetweenInterfaces */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.system.net.netd", "1.1", "INetd", "setForwardingBetweenInterfaces", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>(_hidl_status);
}


// Methods from ::android::system::net::netd::V1_0::INetd follow.
::android::hardware::Return<void> BpHwNetd::createOemNetwork(createOemNetwork_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::system::net::netd::V1_0::BpHwNetd::_hidl_createOemNetwork(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> BpHwNetd::destroyOemNetwork(uint64_t networkHandle){
    ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>  _hidl_out = ::android::system::net::netd::V1_0::BpHwNetd::_hidl_destroyOemNetwork(this, this, networkHandle);

    return _hidl_out;
}


// Methods from ::android::system::net::netd::V1_1::INetd follow.
::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> BpHwNetd::addRouteToOemNetwork(uint64_t networkHandle, const ::android::hardware::hidl_string& ifname, const ::android::hardware::hidl_string& destination, const ::android::hardware::hidl_string& nexthop){
    ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>  _hidl_out = ::android::system::net::netd::V1_1::BpHwNetd::_hidl_addRouteToOemNetwork(this, this, networkHandle, ifname, destination, nexthop);

    return _hidl_out;
}

::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> BpHwNetd::removeRouteFromOemNetwork(uint64_t networkHandle, const ::android::hardware::hidl_string& ifname, const ::android::hardware::hidl_string& destination, const ::android::hardware::hidl_string& nexthop){
    ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>  _hidl_out = ::android::system::net::netd::V1_1::BpHwNetd::_hidl_removeRouteFromOemNetwork(this, this, networkHandle, ifname, destination, nexthop);

    return _hidl_out;
}

::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> BpHwNetd::addInterfaceToOemNetwork(uint64_t networkHandle, const ::android::hardware::hidl_string& ifname){
    ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>  _hidl_out = ::android::system::net::netd::V1_1::BpHwNetd::_hidl_addInterfaceToOemNetwork(this, this, networkHandle, ifname);

    return _hidl_out;
}

::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> BpHwNetd::removeInterfaceFromOemNetwork(uint64_t networkHandle, const ::android::hardware::hidl_string& ifname){
    ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>  _hidl_out = ::android::system::net::netd::V1_1::BpHwNetd::_hidl_removeInterfaceFromOemNetwork(this, this, networkHandle, ifname);

    return _hidl_out;
}

::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> BpHwNetd::setIpForwardEnable(bool enable){
    ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>  _hidl_out = ::android::system::net::netd::V1_1::BpHwNetd::_hidl_setIpForwardEnable(this, this, enable);

    return _hidl_out;
}

::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode> BpHwNetd::setForwardingBetweenInterfaces(const ::android::hardware::hidl_string& inputIfName, const ::android::hardware::hidl_string& outputIfName, bool enable){
    ::android::hardware::Return<::android::system::net::netd::V1_0::INetd::StatusCode>  _hidl_out = ::android::system::net::netd::V1_1::BpHwNetd::_hidl_setForwardingBetweenInterfaces(this, this, inputIfName, outputIfName, enable);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwNetd::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwNetd::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwNetd::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwNetd::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwNetd::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwNetd::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwNetd::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwNetd::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwNetd::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwNetd::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwNetd::BnHwNetd(const ::android::sp<INetd> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.system.net.netd@1.1", "INetd") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwNetd::~BnHwNetd() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::system::net::netd::V1_1::INetd follow.
::android::status_t BnHwNetd::_hidl_addRouteToOemNetwork(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwNetd::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t networkHandle;
    const ::android::hardware::hidl_string* ifname;
    const ::android::hardware::hidl_string* destination;
    const ::android::hardware::hidl_string* nexthop;

    _hidl_err = _hidl_data.readUint64(&networkHandle);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_ifname_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*ifname), &_hidl_ifname_parent,  reinterpret_cast<const void **>(&ifname));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*ifname),
            _hidl_data,
            _hidl_ifname_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_destination_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*destination), &_hidl_destination_parent,  reinterpret_cast<const void **>(&destination));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*destination),
            _hidl_data,
            _hidl_destination_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_nexthop_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*nexthop), &_hidl_nexthop_parent,  reinterpret_cast<const void **>(&nexthop));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*nexthop),
            _hidl_data,
            _hidl_nexthop_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::INetd::addRouteToOemNetwork::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&networkHandle);
        _hidl_args.push_back((void *)ifname);
        _hidl_args.push_back((void *)destination);
        _hidl_args.push_back((void *)nexthop);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.system.net.netd", "1.1", "INetd", "addRouteToOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::system::net::netd::V1_0::INetd::StatusCode _hidl_out_status = static_cast<INetd*>(_hidl_this->getImpl().get())->addRouteToOemNetwork(networkHandle, *ifname, *destination, *nexthop);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.system.net.netd", "1.1", "INetd", "addRouteToOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwNetd::_hidl_removeRouteFromOemNetwork(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwNetd::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t networkHandle;
    const ::android::hardware::hidl_string* ifname;
    const ::android::hardware::hidl_string* destination;
    const ::android::hardware::hidl_string* nexthop;

    _hidl_err = _hidl_data.readUint64(&networkHandle);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_ifname_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*ifname), &_hidl_ifname_parent,  reinterpret_cast<const void **>(&ifname));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*ifname),
            _hidl_data,
            _hidl_ifname_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_destination_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*destination), &_hidl_destination_parent,  reinterpret_cast<const void **>(&destination));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*destination),
            _hidl_data,
            _hidl_destination_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_nexthop_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*nexthop), &_hidl_nexthop_parent,  reinterpret_cast<const void **>(&nexthop));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*nexthop),
            _hidl_data,
            _hidl_nexthop_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::INetd::removeRouteFromOemNetwork::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&networkHandle);
        _hidl_args.push_back((void *)ifname);
        _hidl_args.push_back((void *)destination);
        _hidl_args.push_back((void *)nexthop);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.system.net.netd", "1.1", "INetd", "removeRouteFromOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::system::net::netd::V1_0::INetd::StatusCode _hidl_out_status = static_cast<INetd*>(_hidl_this->getImpl().get())->removeRouteFromOemNetwork(networkHandle, *ifname, *destination, *nexthop);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.system.net.netd", "1.1", "INetd", "removeRouteFromOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwNetd::_hidl_addInterfaceToOemNetwork(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwNetd::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t networkHandle;
    const ::android::hardware::hidl_string* ifname;

    _hidl_err = _hidl_data.readUint64(&networkHandle);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_ifname_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*ifname), &_hidl_ifname_parent,  reinterpret_cast<const void **>(&ifname));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*ifname),
            _hidl_data,
            _hidl_ifname_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::INetd::addInterfaceToOemNetwork::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&networkHandle);
        _hidl_args.push_back((void *)ifname);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.system.net.netd", "1.1", "INetd", "addInterfaceToOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::system::net::netd::V1_0::INetd::StatusCode _hidl_out_status = static_cast<INetd*>(_hidl_this->getImpl().get())->addInterfaceToOemNetwork(networkHandle, *ifname);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.system.net.netd", "1.1", "INetd", "addInterfaceToOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwNetd::_hidl_removeInterfaceFromOemNetwork(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwNetd::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t networkHandle;
    const ::android::hardware::hidl_string* ifname;

    _hidl_err = _hidl_data.readUint64(&networkHandle);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_ifname_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*ifname), &_hidl_ifname_parent,  reinterpret_cast<const void **>(&ifname));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*ifname),
            _hidl_data,
            _hidl_ifname_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::INetd::removeInterfaceFromOemNetwork::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&networkHandle);
        _hidl_args.push_back((void *)ifname);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.system.net.netd", "1.1", "INetd", "removeInterfaceFromOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::system::net::netd::V1_0::INetd::StatusCode _hidl_out_status = static_cast<INetd*>(_hidl_this->getImpl().get())->removeInterfaceFromOemNetwork(networkHandle, *ifname);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.system.net.netd", "1.1", "INetd", "removeInterfaceFromOemNetwork", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwNetd::_hidl_setIpForwardEnable(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwNetd::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    bool enable;

    _hidl_err = _hidl_data.readBool(&enable);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::INetd::setIpForwardEnable::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&enable);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.system.net.netd", "1.1", "INetd", "setIpForwardEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::system::net::netd::V1_0::INetd::StatusCode _hidl_out_status = static_cast<INetd*>(_hidl_this->getImpl().get())->setIpForwardEnable(enable);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.system.net.netd", "1.1", "INetd", "setIpForwardEnable", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwNetd::_hidl_setForwardingBetweenInterfaces(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwNetd::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* inputIfName;
    const ::android::hardware::hidl_string* outputIfName;
    bool enable;

    size_t _hidl_inputIfName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*inputIfName), &_hidl_inputIfName_parent,  reinterpret_cast<const void **>(&inputIfName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*inputIfName),
            _hidl_data,
            _hidl_inputIfName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputIfName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*outputIfName), &_hidl_outputIfName_parent,  reinterpret_cast<const void **>(&outputIfName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*outputIfName),
            _hidl_data,
            _hidl_outputIfName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&enable);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::INetd::setForwardingBetweenInterfaces::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)inputIfName);
        _hidl_args.push_back((void *)outputIfName);
        _hidl_args.push_back((void *)&enable);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.system.net.netd", "1.1", "INetd", "setForwardingBetweenInterfaces", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::system::net::netd::V1_0::INetd::StatusCode _hidl_out_status = static_cast<INetd*>(_hidl_this->getImpl().get())->setForwardingBetweenInterfaces(*inputIfName, *outputIfName, enable);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.system.net.netd", "1.1", "INetd", "setForwardingBetweenInterfaces", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::system::net::netd::V1_0::INetd follow.

// Methods from ::android::system::net::netd::V1_1::INetd follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwNetd::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwNetd::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwNetd::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* createOemNetwork */:
        {
            _hidl_err = ::android::system::net::netd::V1_0::BnHwNetd::_hidl_createOemNetwork(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* destroyOemNetwork */:
        {
            _hidl_err = ::android::system::net::netd::V1_0::BnHwNetd::_hidl_destroyOemNetwork(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* addRouteToOemNetwork */:
        {
            _hidl_err = ::android::system::net::netd::V1_1::BnHwNetd::_hidl_addRouteToOemNetwork(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* removeRouteFromOemNetwork */:
        {
            _hidl_err = ::android::system::net::netd::V1_1::BnHwNetd::_hidl_removeRouteFromOemNetwork(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* addInterfaceToOemNetwork */:
        {
            _hidl_err = ::android::system::net::netd::V1_1::BnHwNetd::_hidl_addInterfaceToOemNetwork(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* removeInterfaceFromOemNetwork */:
        {
            _hidl_err = ::android::system::net::netd::V1_1::BnHwNetd::_hidl_removeInterfaceFromOemNetwork(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* setIpForwardEnable */:
        {
            _hidl_err = ::android::system::net::netd::V1_1::BnHwNetd::_hidl_setIpForwardEnable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* setForwardingBetweenInterfaces */:
        {
            _hidl_err = ::android::system::net::netd::V1_1::BnHwNetd::_hidl_setForwardingBetweenInterfaces(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsNetd::BsNetd(const ::android::sp<::android::system::net::netd::V1_1::INetd> impl) : ::android::hardware::details::HidlInstrumentor("android.system.net.netd@1.1", "INetd"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsNetd::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<INetd> INetd::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwNetd>(serviceName, false, getStub);
}

::android::sp<INetd> INetd::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwNetd>(serviceName, true, getStub);
}

::android::status_t INetd::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool INetd::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.system.net.netd@1.1::INetd",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_1
}  // namespace netd
}  // namespace net
}  // namespace system
}  // namespace android
