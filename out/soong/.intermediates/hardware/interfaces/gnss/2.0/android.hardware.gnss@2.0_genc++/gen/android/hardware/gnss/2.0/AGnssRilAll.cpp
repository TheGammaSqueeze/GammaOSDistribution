#define LOG_TAG "android.hardware.gnss@2.0::AGnssRil"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/gnss/2.0/BpHwAGnssRil.h>
#include <android/hardware/gnss/2.0/BnHwAGnssRil.h>
#include <android/hardware/gnss/2.0/BsAGnssRil.h>
#include <android/hardware/gnss/1.0/BpHwAGnssRil.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace gnss {
namespace V2_0 {

::android::status_t readEmbeddedFromParcel(
        const IAGnssRil::IAGnssRil::NetworkAttributes &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.apn),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::gnss::V2_0::IAGnssRil::NetworkAttributes, apn));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const IAGnssRil::IAGnssRil::NetworkAttributes &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.apn,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::gnss::V2_0::IAGnssRil::NetworkAttributes, apn));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

const char* IAGnssRil::descriptor("android.hardware.gnss@2.0::IAGnssRil");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IAGnssRil::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwAGnssRil(static_cast<IAGnssRil *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IAGnssRil::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsAGnssRil(static_cast<IAGnssRil *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IAGnssRil::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IAGnssRil::descriptor);
}

// Methods from ::android::hardware::gnss::V1_0::IAGnssRil follow.
// no default implementation for: ::android::hardware::Return<void> IAGnssRil::setCallback(const ::android::sp<::android::hardware::gnss::V1_0::IAGnssRilCallback>& callback)
// no default implementation for: ::android::hardware::Return<void> IAGnssRil::setRefLocation(const ::android::hardware::gnss::V1_0::IAGnssRil::AGnssRefLocation& agnssReflocation)
// no default implementation for: ::android::hardware::Return<bool> IAGnssRil::setSetId(::android::hardware::gnss::V1_0::IAGnssRil::SetIDType type, const ::android::hardware::hidl_string& setid)
// no default implementation for: ::android::hardware::Return<bool> IAGnssRil::updateNetworkState(bool connected, ::android::hardware::gnss::V1_0::IAGnssRil::NetworkType type, bool roaming)
// no default implementation for: ::android::hardware::Return<bool> IAGnssRil::updateNetworkAvailability(bool available, const ::android::hardware::hidl_string& apn)

// Methods from ::android::hardware::gnss::V2_0::IAGnssRil follow.
// no default implementation for: ::android::hardware::Return<bool> IAGnssRil::updateNetworkState_2_0(const ::android::hardware::gnss::V2_0::IAGnssRil::NetworkAttributes& attributes)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IAGnssRil::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::gnss::V2_0::IAGnssRil::descriptor,
        ::android::hardware::gnss::V1_0::IAGnssRil::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IAGnssRil::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IAGnssRil::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::gnss::V2_0::IAGnssRil::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IAGnssRil::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){31,74,192,104,168,138,114,54,2,128,217,74,127,111,215,198,56,19,193,238,164,137,26,14,176,19,148,211,231,231,117,242} /* 1f4ac068a88a72360280d94a7f6fd7c63813c1eea4891a0eb01394d3e7e775f2 */,
        (uint8_t[32]){209,110,106,53,155,230,150,62,167,83,215,19,142,132,236,242,185,48,82,9,121,56,147,140,77,54,215,164,126,162,226,174} /* d16e6a359be6963ea753d7138e84ecf2b93052097938938c4d36d7a47ea2e2ae */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IAGnssRil::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IAGnssRil::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IAGnssRil::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IAGnssRil::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IAGnssRil::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IAGnssRil::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnssRil>> IAGnssRil::castFrom(const ::android::sp<::android::hardware::gnss::V2_0::IAGnssRil>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnssRil>> IAGnssRil::castFrom(const ::android::sp<::android::hardware::gnss::V1_0::IAGnssRil>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IAGnssRil, ::android::hardware::gnss::V1_0::IAGnssRil, BpHwAGnssRil>(
            parent, "android.hardware.gnss@2.0::IAGnssRil", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnssRil>> IAGnssRil::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IAGnssRil, ::android::hidl::base::V1_0::IBase, BpHwAGnssRil>(
            parent, "android.hardware.gnss@2.0::IAGnssRil", emitError);
}

BpHwAGnssRil::BpHwAGnssRil(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IAGnssRil>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.gnss@2.0", "IAGnssRil") {
}

void BpHwAGnssRil::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IAGnssRil>::onLastStrongRef(id);
}
// Methods from ::android::hardware::gnss::V2_0::IAGnssRil follow.
::android::hardware::Return<bool> BpHwAGnssRil::_hidl_updateNetworkState_2_0(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::gnss::V2_0::IAGnssRil::NetworkAttributes& attributes) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IAGnssRil::updateNetworkState_2_0::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&attributes);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.0", "IAGnssRil", "updateNetworkState_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    bool _hidl_out_success;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwAGnssRil::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_attributes_parent;

    _hidl_err = _hidl_data.writeBuffer(&attributes, sizeof(attributes), &_hidl_attributes_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            attributes,
            &_hidl_data,
            _hidl_attributes_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* updateNetworkState_2_0 */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readBool(&_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.0", "IAGnssRil", "updateNetworkState_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<bool>(_hidl_out_success);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<bool>(_hidl_status);
}


// Methods from ::android::hardware::gnss::V1_0::IAGnssRil follow.
::android::hardware::Return<void> BpHwAGnssRil::setCallback(const ::android::sp<::android::hardware::gnss::V1_0::IAGnssRilCallback>& callback){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwAGnssRil::_hidl_setCallback(this, this, callback);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwAGnssRil::setRefLocation(const ::android::hardware::gnss::V1_0::IAGnssRil::AGnssRefLocation& agnssReflocation){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwAGnssRil::_hidl_setRefLocation(this, this, agnssReflocation);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwAGnssRil::setSetId(::android::hardware::gnss::V1_0::IAGnssRil::SetIDType type, const ::android::hardware::hidl_string& setid){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwAGnssRil::_hidl_setSetId(this, this, type, setid);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwAGnssRil::updateNetworkState(bool connected, ::android::hardware::gnss::V1_0::IAGnssRil::NetworkType type, bool roaming){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwAGnssRil::_hidl_updateNetworkState(this, this, connected, type, roaming);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwAGnssRil::updateNetworkAvailability(bool available, const ::android::hardware::hidl_string& apn){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwAGnssRil::_hidl_updateNetworkAvailability(this, this, available, apn);

    return _hidl_out;
}


// Methods from ::android::hardware::gnss::V2_0::IAGnssRil follow.
::android::hardware::Return<bool> BpHwAGnssRil::updateNetworkState_2_0(const ::android::hardware::gnss::V2_0::IAGnssRil::NetworkAttributes& attributes){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwAGnssRil::_hidl_updateNetworkState_2_0(this, this, attributes);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwAGnssRil::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwAGnssRil::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwAGnssRil::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwAGnssRil::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwAGnssRil::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwAGnssRil::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwAGnssRil::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwAGnssRil::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwAGnssRil::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwAGnssRil::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwAGnssRil::BnHwAGnssRil(const ::android::sp<IAGnssRil> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.gnss@2.0", "IAGnssRil") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwAGnssRil::~BnHwAGnssRil() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::gnss::V2_0::IAGnssRil follow.
::android::status_t BnHwAGnssRil::_hidl_updateNetworkState_2_0(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwAGnssRil::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::gnss::V2_0::IAGnssRil::NetworkAttributes* attributes;

    size_t _hidl_attributes_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*attributes), &_hidl_attributes_parent,  const_cast<const void**>(reinterpret_cast<void **>(&attributes)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::gnss::V2_0::IAGnssRil::NetworkAttributes &>(*attributes),
            _hidl_data,
            _hidl_attributes_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IAGnssRil::updateNetworkState_2_0::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)attributes);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.0", "IAGnssRil", "updateNetworkState_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_out_success = static_cast<IAGnssRil*>(_hidl_this->getImpl().get())->updateNetworkState_2_0(*attributes);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeBool(_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.0", "IAGnssRil", "updateNetworkState_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::gnss::V1_0::IAGnssRil follow.

// Methods from ::android::hardware::gnss::V2_0::IAGnssRil follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwAGnssRil::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwAGnssRil::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwAGnssRil::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* setCallback */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwAGnssRil::_hidl_setCallback(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* setRefLocation */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwAGnssRil::_hidl_setRefLocation(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* setSetId */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwAGnssRil::_hidl_setSetId(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* updateNetworkState */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwAGnssRil::_hidl_updateNetworkState(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* updateNetworkAvailability */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwAGnssRil::_hidl_updateNetworkAvailability(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* updateNetworkState_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwAGnssRil::_hidl_updateNetworkState_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsAGnssRil::BsAGnssRil(const ::android::sp<::android::hardware::gnss::V2_0::IAGnssRil> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.gnss@2.0", "IAGnssRil"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsAGnssRil::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IAGnssRil> IAGnssRil::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwAGnssRil>(serviceName, false, getStub);
}

::android::sp<IAGnssRil> IAGnssRil::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwAGnssRil>(serviceName, true, getStub);
}

::android::status_t IAGnssRil::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IAGnssRil::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.gnss@2.0::IAGnssRil",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_0
}  // namespace gnss
}  // namespace hardware
}  // namespace android
