#define LOG_TAG "android.hardware.wifi@1.0::WifiRttControllerEventCallback"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/wifi/1.0/BpHwWifiRttControllerEventCallback.h>
#include <android/hardware/wifi/1.0/BnHwWifiRttControllerEventCallback.h>
#include <android/hardware/wifi/1.0/BsWifiRttControllerEventCallback.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace wifi {
namespace V1_0 {

const char* IWifiRttControllerEventCallback::descriptor("android.hardware.wifi@1.0::IWifiRttControllerEventCallback");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IWifiRttControllerEventCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwWifiRttControllerEventCallback(static_cast<IWifiRttControllerEventCallback *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IWifiRttControllerEventCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsWifiRttControllerEventCallback(static_cast<IWifiRttControllerEventCallback *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IWifiRttControllerEventCallback::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IWifiRttControllerEventCallback::descriptor);
}

// Methods from ::android::hardware::wifi::V1_0::IWifiRttControllerEventCallback follow.
// no default implementation for: ::android::hardware::Return<void> IWifiRttControllerEventCallback::onResults(uint32_t cmdId, const ::android::hardware::hidl_vec<::android::hardware::wifi::V1_0::RttResult>& results)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IWifiRttControllerEventCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::wifi::V1_0::IWifiRttControllerEventCallback::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiRttControllerEventCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiRttControllerEventCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::wifi::V1_0::IWifiRttControllerEventCallback::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiRttControllerEventCallback::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){114,171,111,62,18,12,191,7,170,111,142,135,202,137,17,43,222,179,107,127,187,150,188,229,175,55,18,50,58,184,184,230} /* 72ab6f3e120cbf07aa6f8e87ca89112bdeb36b7fbb96bce5af3712323ab8b8e6 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiRttControllerEventCallback::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IWifiRttControllerEventCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IWifiRttControllerEventCallback::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IWifiRttControllerEventCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IWifiRttControllerEventCallback::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IWifiRttControllerEventCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::wifi::V1_0::IWifiRttControllerEventCallback>> IWifiRttControllerEventCallback::castFrom(const ::android::sp<::android::hardware::wifi::V1_0::IWifiRttControllerEventCallback>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::wifi::V1_0::IWifiRttControllerEventCallback>> IWifiRttControllerEventCallback::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IWifiRttControllerEventCallback, ::android::hidl::base::V1_0::IBase, BpHwWifiRttControllerEventCallback>(
            parent, "android.hardware.wifi@1.0::IWifiRttControllerEventCallback", emitError);
}

BpHwWifiRttControllerEventCallback::BpHwWifiRttControllerEventCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IWifiRttControllerEventCallback>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.wifi@1.0", "IWifiRttControllerEventCallback") {
}

void BpHwWifiRttControllerEventCallback::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IWifiRttControllerEventCallback>::onLastStrongRef(id);
}
// Methods from ::android::hardware::wifi::V1_0::IWifiRttControllerEventCallback follow.
::android::hardware::Return<void> BpHwWifiRttControllerEventCallback::_hidl_onResults(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t cmdId, const ::android::hardware::hidl_vec<::android::hardware::wifi::V1_0::RttResult>& results) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IWifiRttControllerEventCallback::onResults::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)&results);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiRttControllerEventCallback", "onResults", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwWifiRttControllerEventCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(cmdId);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_results_parent;

    _hidl_err = _hidl_data.writeBuffer(&results, sizeof(results), &_hidl_results_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_results_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            results,
            &_hidl_data,
            _hidl_results_parent,
            0 /* parentOffset */, &_hidl_results_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < results.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                results[_hidl_index_0],
                &_hidl_data,
                _hidl_results_child,
                _hidl_index_0 * sizeof(::android::hardware::wifi::V1_0::RttResult));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* onResults */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.wifi", "1.0", "IWifiRttControllerEventCallback", "onResults", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::wifi::V1_0::IWifiRttControllerEventCallback follow.
::android::hardware::Return<void> BpHwWifiRttControllerEventCallback::onResults(uint32_t cmdId, const ::android::hardware::hidl_vec<::android::hardware::wifi::V1_0::RttResult>& results){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::wifi::V1_0::BpHwWifiRttControllerEventCallback::_hidl_onResults(this, this, cmdId, results);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwWifiRttControllerEventCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiRttControllerEventCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiRttControllerEventCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiRttControllerEventCallback::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiRttControllerEventCallback::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwWifiRttControllerEventCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwWifiRttControllerEventCallback::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiRttControllerEventCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwWifiRttControllerEventCallback::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwWifiRttControllerEventCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwWifiRttControllerEventCallback::BnHwWifiRttControllerEventCallback(const ::android::sp<IWifiRttControllerEventCallback> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.wifi@1.0", "IWifiRttControllerEventCallback") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwWifiRttControllerEventCallback::~BnHwWifiRttControllerEventCallback() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::wifi::V1_0::IWifiRttControllerEventCallback follow.
::android::status_t BnHwWifiRttControllerEventCallback::_hidl_onResults(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwWifiRttControllerEventCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t cmdId;
    const ::android::hardware::hidl_vec<::android::hardware::wifi::V1_0::RttResult>* results;

    _hidl_err = _hidl_data.readUint32(&cmdId);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_results_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*results), &_hidl_results_parent,  reinterpret_cast<const void **>(&results));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_results_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::wifi::V1_0::RttResult> &>(*results),
            _hidl_data,
            _hidl_results_parent,
            0 /* parentOffset */, &_hidl_results_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < results->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::RttResult &>((*results)[_hidl_index_0]),
                _hidl_data,
                _hidl_results_child,
                _hidl_index_0 * sizeof(::android::hardware::wifi::V1_0::RttResult));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IWifiRttControllerEventCallback::onResults::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmdId);
        _hidl_args.push_back((void *)results);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.wifi", "1.0", "IWifiRttControllerEventCallback", "onResults", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IWifiRttControllerEventCallback*>(_hidl_this->getImpl().get())->onResults(cmdId, *results);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.wifi", "1.0", "IWifiRttControllerEventCallback", "onResults", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::wifi::V1_0::IWifiRttControllerEventCallback follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwWifiRttControllerEventCallback::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwWifiRttControllerEventCallback::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwWifiRttControllerEventCallback::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* onResults */:
        {
            _hidl_err = ::android::hardware::wifi::V1_0::BnHwWifiRttControllerEventCallback::_hidl_onResults(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsWifiRttControllerEventCallback::BsWifiRttControllerEventCallback(const ::android::sp<::android::hardware::wifi::V1_0::IWifiRttControllerEventCallback> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.wifi@1.0", "IWifiRttControllerEventCallback"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsWifiRttControllerEventCallback::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IWifiRttControllerEventCallback> IWifiRttControllerEventCallback::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwWifiRttControllerEventCallback>(serviceName, false, getStub);
}

::android::sp<IWifiRttControllerEventCallback> IWifiRttControllerEventCallback::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwWifiRttControllerEventCallback>(serviceName, true, getStub);
}

::android::status_t IWifiRttControllerEventCallback::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IWifiRttControllerEventCallback::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.wifi@1.0::IWifiRttControllerEventCallback",
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
