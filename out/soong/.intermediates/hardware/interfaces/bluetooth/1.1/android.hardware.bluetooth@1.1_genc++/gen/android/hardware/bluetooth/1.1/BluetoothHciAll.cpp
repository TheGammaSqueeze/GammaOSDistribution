#define LOG_TAG "android.hardware.bluetooth@1.1::BluetoothHci"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/bluetooth/1.1/BpHwBluetoothHci.h>
#include <android/hardware/bluetooth/1.1/BnHwBluetoothHci.h>
#include <android/hardware/bluetooth/1.1/BsBluetoothHci.h>
#include <android/hardware/bluetooth/1.0/BpHwBluetoothHci.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace bluetooth {
namespace V1_1 {

const char* IBluetoothHci::descriptor("android.hardware.bluetooth@1.1::IBluetoothHci");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IBluetoothHci::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwBluetoothHci(static_cast<IBluetoothHci *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IBluetoothHci::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsBluetoothHci(static_cast<IBluetoothHci *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IBluetoothHci::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IBluetoothHci::descriptor);
}

// Methods from ::android::hardware::bluetooth::V1_0::IBluetoothHci follow.
// no default implementation for: ::android::hardware::Return<void> IBluetoothHci::initialize(const ::android::sp<::android::hardware::bluetooth::V1_0::IBluetoothHciCallbacks>& callback)
// no default implementation for: ::android::hardware::Return<void> IBluetoothHci::sendHciCommand(const ::android::hardware::hidl_vec<uint8_t>& command)
// no default implementation for: ::android::hardware::Return<void> IBluetoothHci::sendAclData(const ::android::hardware::hidl_vec<uint8_t>& data)
// no default implementation for: ::android::hardware::Return<void> IBluetoothHci::sendScoData(const ::android::hardware::hidl_vec<uint8_t>& data)
// no default implementation for: ::android::hardware::Return<void> IBluetoothHci::close()

// Methods from ::android::hardware::bluetooth::V1_1::IBluetoothHci follow.
// no default implementation for: ::android::hardware::Return<void> IBluetoothHci::initialize_1_1(const ::android::sp<::android::hardware::bluetooth::V1_1::IBluetoothHciCallbacks>& callback)
// no default implementation for: ::android::hardware::Return<void> IBluetoothHci::sendIsoData(const ::android::hardware::hidl_vec<uint8_t>& data)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IBluetoothHci::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::bluetooth::V1_1::IBluetoothHci::descriptor,
        ::android::hardware::bluetooth::V1_0::IBluetoothHci::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothHci::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothHci::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::bluetooth::V1_1::IBluetoothHci::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothHci::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){54,47,209,194,22,65,194,34,79,59,128,195,13,151,151,185,136,250,63,52,66,67,213,49,186,115,197,83,119,154,87,99} /* 362fd1c21641c2224f3b80c30d9797b988fa3f344243d531ba73c553779a5763 */,
        (uint8_t[32]){52,124,231,70,129,86,7,86,127,95,59,83,228,128,9,152,202,90,185,53,81,65,240,136,15,192,207,12,31,197,195,85} /* 347ce746815607567f5f3b53e4800998ca5ab9355141f0880fc0cf0c1fc5c355 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothHci::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IBluetoothHci::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IBluetoothHci::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothHci::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IBluetoothHci::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IBluetoothHci::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::bluetooth::V1_1::IBluetoothHci>> IBluetoothHci::castFrom(const ::android::sp<::android::hardware::bluetooth::V1_1::IBluetoothHci>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::bluetooth::V1_1::IBluetoothHci>> IBluetoothHci::castFrom(const ::android::sp<::android::hardware::bluetooth::V1_0::IBluetoothHci>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IBluetoothHci, ::android::hardware::bluetooth::V1_0::IBluetoothHci, BpHwBluetoothHci>(
            parent, "android.hardware.bluetooth@1.1::IBluetoothHci", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::bluetooth::V1_1::IBluetoothHci>> IBluetoothHci::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IBluetoothHci, ::android::hidl::base::V1_0::IBase, BpHwBluetoothHci>(
            parent, "android.hardware.bluetooth@1.1::IBluetoothHci", emitError);
}

BpHwBluetoothHci::BpHwBluetoothHci(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IBluetoothHci>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.bluetooth@1.1", "IBluetoothHci") {
}

void BpHwBluetoothHci::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IBluetoothHci>::onLastStrongRef(id);
}
// Methods from ::android::hardware::bluetooth::V1_1::IBluetoothHci follow.
::android::hardware::Return<void> BpHwBluetoothHci::_hidl_initialize_1_1(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::bluetooth::V1_1::IBluetoothHciCallbacks>& callback) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBluetoothHci::initialize_1_1::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.bluetooth", "1.1", "IBluetoothHci", "initialize_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBluetoothHci::descriptor);
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
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* initialize_1_1 */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.bluetooth", "1.1", "IBluetoothHci", "initialize_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBluetoothHci::_hidl_sendIsoData(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& data) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBluetoothHci::sendIsoData::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.bluetooth", "1.1", "IBluetoothHci", "sendIsoData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBluetoothHci::descriptor);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* sendIsoData */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.bluetooth", "1.1", "IBluetoothHci", "sendIsoData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::bluetooth::V1_0::IBluetoothHci follow.
::android::hardware::Return<void> BpHwBluetoothHci::initialize(const ::android::sp<::android::hardware::bluetooth::V1_0::IBluetoothHciCallbacks>& callback){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::V1_0::BpHwBluetoothHci::_hidl_initialize(this, this, callback);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothHci::sendHciCommand(const ::android::hardware::hidl_vec<uint8_t>& command){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::V1_0::BpHwBluetoothHci::_hidl_sendHciCommand(this, this, command);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothHci::sendAclData(const ::android::hardware::hidl_vec<uint8_t>& data){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::V1_0::BpHwBluetoothHci::_hidl_sendAclData(this, this, data);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothHci::sendScoData(const ::android::hardware::hidl_vec<uint8_t>& data){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::V1_0::BpHwBluetoothHci::_hidl_sendScoData(this, this, data);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothHci::close(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::V1_0::BpHwBluetoothHci::_hidl_close(this, this);

    return _hidl_out;
}


// Methods from ::android::hardware::bluetooth::V1_1::IBluetoothHci follow.
::android::hardware::Return<void> BpHwBluetoothHci::initialize_1_1(const ::android::sp<::android::hardware::bluetooth::V1_1::IBluetoothHciCallbacks>& callback){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::V1_1::BpHwBluetoothHci::_hidl_initialize_1_1(this, this, callback);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothHci::sendIsoData(const ::android::hardware::hidl_vec<uint8_t>& data){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::V1_1::BpHwBluetoothHci::_hidl_sendIsoData(this, this, data);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwBluetoothHci::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothHci::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothHci::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothHci::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothHci::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwBluetoothHci::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwBluetoothHci::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothHci::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothHci::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwBluetoothHci::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwBluetoothHci::BnHwBluetoothHci(const ::android::sp<IBluetoothHci> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.bluetooth@1.1", "IBluetoothHci") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwBluetoothHci::~BnHwBluetoothHci() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::bluetooth::V1_1::IBluetoothHci follow.
::android::status_t BnHwBluetoothHci::_hidl_initialize_1_1(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBluetoothHci::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::sp<::android::hardware::bluetooth::V1_1::IBluetoothHciCallbacks> callback;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<::android::hardware::bluetooth::V1_1::IBluetoothHciCallbacks,::android::hardware::bluetooth::V1_1::BpHwBluetoothHciCallbacks,::android::hardware::bluetooth::V1_1::BnHwBluetoothHciCallbacks>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBluetoothHci::initialize_1_1::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.bluetooth", "1.1", "IBluetoothHci", "initialize_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBluetoothHci*>(_hidl_this->getImpl().get())->initialize_1_1(callback);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.bluetooth", "1.1", "IBluetoothHci", "initialize_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBluetoothHci::_hidl_sendIsoData(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBluetoothHci::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* data;

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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBluetoothHci::sendIsoData::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.bluetooth", "1.1", "IBluetoothHci", "sendIsoData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBluetoothHci*>(_hidl_this->getImpl().get())->sendIsoData(*data);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.bluetooth", "1.1", "IBluetoothHci", "sendIsoData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::bluetooth::V1_0::IBluetoothHci follow.

// Methods from ::android::hardware::bluetooth::V1_1::IBluetoothHci follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwBluetoothHci::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwBluetoothHci::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwBluetoothHci::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* initialize */:
        {
            _hidl_err = ::android::hardware::bluetooth::V1_0::BnHwBluetoothHci::_hidl_initialize(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* sendHciCommand */:
        {
            _hidl_err = ::android::hardware::bluetooth::V1_0::BnHwBluetoothHci::_hidl_sendHciCommand(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* sendAclData */:
        {
            _hidl_err = ::android::hardware::bluetooth::V1_0::BnHwBluetoothHci::_hidl_sendAclData(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* sendScoData */:
        {
            _hidl_err = ::android::hardware::bluetooth::V1_0::BnHwBluetoothHci::_hidl_sendScoData(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* close */:
        {
            _hidl_err = ::android::hardware::bluetooth::V1_0::BnHwBluetoothHci::_hidl_close(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* initialize_1_1 */:
        {
            _hidl_err = ::android::hardware::bluetooth::V1_1::BnHwBluetoothHci::_hidl_initialize_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* sendIsoData */:
        {
            _hidl_err = ::android::hardware::bluetooth::V1_1::BnHwBluetoothHci::_hidl_sendIsoData(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsBluetoothHci::BsBluetoothHci(const ::android::sp<::android::hardware::bluetooth::V1_1::IBluetoothHci> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.bluetooth@1.1", "IBluetoothHci"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsBluetoothHci::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IBluetoothHci> IBluetoothHci::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwBluetoothHci>(serviceName, false, getStub);
}

::android::sp<IBluetoothHci> IBluetoothHci::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwBluetoothHci>(serviceName, true, getStub);
}

::android::status_t IBluetoothHci::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IBluetoothHci::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.bluetooth@1.1::IBluetoothHci",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_1
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
