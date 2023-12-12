#define LOG_TAG "android.hardware.confirmationui@1.0::ConfirmationResultCallback"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/confirmationui/1.0/BpHwConfirmationResultCallback.h>
#include <android/hardware/confirmationui/1.0/BnHwConfirmationResultCallback.h>
#include <android/hardware/confirmationui/1.0/BsConfirmationResultCallback.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace confirmationui {
namespace V1_0 {

const char* IConfirmationResultCallback::descriptor("android.hardware.confirmationui@1.0::IConfirmationResultCallback");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IConfirmationResultCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwConfirmationResultCallback(static_cast<IConfirmationResultCallback *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IConfirmationResultCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsConfirmationResultCallback(static_cast<IConfirmationResultCallback *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IConfirmationResultCallback::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IConfirmationResultCallback::descriptor);
}

// Methods from ::android::hardware::confirmationui::V1_0::IConfirmationResultCallback follow.
// no default implementation for: ::android::hardware::Return<void> IConfirmationResultCallback::result(::android::hardware::confirmationui::V1_0::ResponseCode error, const ::android::hardware::hidl_vec<uint8_t>& formattedMessage, const ::android::hardware::hidl_vec<uint8_t>& confirmationToken)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IConfirmationResultCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::confirmationui::V1_0::IConfirmationResultCallback::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfirmationResultCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfirmationResultCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::confirmationui::V1_0::IConfirmationResultCallback::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfirmationResultCallback::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){26,70,174,174,69,183,160,228,127,121,183,32,115,0,83,41,134,249,217,205,112,96,119,154,252,122,82,159,84,215,18,171} /* 1a46aeae45b7a0e47f79b7207300532986f9d9cd7060779afc7a529f54d712ab */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfirmationResultCallback::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IConfirmationResultCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IConfirmationResultCallback::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfirmationResultCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IConfirmationResultCallback::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IConfirmationResultCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationResultCallback>> IConfirmationResultCallback::castFrom(const ::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationResultCallback>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationResultCallback>> IConfirmationResultCallback::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IConfirmationResultCallback, ::android::hidl::base::V1_0::IBase, BpHwConfirmationResultCallback>(
            parent, "android.hardware.confirmationui@1.0::IConfirmationResultCallback", emitError);
}

BpHwConfirmationResultCallback::BpHwConfirmationResultCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IConfirmationResultCallback>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.confirmationui@1.0", "IConfirmationResultCallback") {
}

void BpHwConfirmationResultCallback::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IConfirmationResultCallback>::onLastStrongRef(id);
}
// Methods from ::android::hardware::confirmationui::V1_0::IConfirmationResultCallback follow.
::android::hardware::Return<void> BpHwConfirmationResultCallback::_hidl_result(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::confirmationui::V1_0::ResponseCode error, const ::android::hardware::hidl_vec<uint8_t>& formattedMessage, const ::android::hardware::hidl_vec<uint8_t>& confirmationToken) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IConfirmationResultCallback::result::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&error);
        _hidl_args.push_back((void *)&formattedMessage);
        _hidl_args.push_back((void *)&confirmationToken);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.confirmationui", "1.0", "IConfirmationResultCallback", "result", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwConfirmationResultCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32((uint32_t)error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_formattedMessage_parent;

    _hidl_err = _hidl_data.writeBuffer(&formattedMessage, sizeof(formattedMessage), &_hidl_formattedMessage_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_formattedMessage_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            formattedMessage,
            &_hidl_data,
            _hidl_formattedMessage_parent,
            0 /* parentOffset */, &_hidl_formattedMessage_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_confirmationToken_parent;

    _hidl_err = _hidl_data.writeBuffer(&confirmationToken, sizeof(confirmationToken), &_hidl_confirmationToken_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_confirmationToken_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            confirmationToken,
            &_hidl_data,
            _hidl_confirmationToken_parent,
            0 /* parentOffset */, &_hidl_confirmationToken_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* result */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.confirmationui", "1.0", "IConfirmationResultCallback", "result", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::confirmationui::V1_0::IConfirmationResultCallback follow.
::android::hardware::Return<void> BpHwConfirmationResultCallback::result(::android::hardware::confirmationui::V1_0::ResponseCode error, const ::android::hardware::hidl_vec<uint8_t>& formattedMessage, const ::android::hardware::hidl_vec<uint8_t>& confirmationToken){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::confirmationui::V1_0::BpHwConfirmationResultCallback::_hidl_result(this, this, error, formattedMessage, confirmationToken);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwConfirmationResultCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfirmationResultCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfirmationResultCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfirmationResultCallback::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfirmationResultCallback::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwConfirmationResultCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwConfirmationResultCallback::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfirmationResultCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfirmationResultCallback::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwConfirmationResultCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwConfirmationResultCallback::BnHwConfirmationResultCallback(const ::android::sp<IConfirmationResultCallback> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.confirmationui@1.0", "IConfirmationResultCallback") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwConfirmationResultCallback::~BnHwConfirmationResultCallback() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::confirmationui::V1_0::IConfirmationResultCallback follow.
::android::status_t BnHwConfirmationResultCallback::_hidl_result(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwConfirmationResultCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::confirmationui::V1_0::ResponseCode error;
    const ::android::hardware::hidl_vec<uint8_t>* formattedMessage;
    const ::android::hardware::hidl_vec<uint8_t>* confirmationToken;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&error);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_formattedMessage_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*formattedMessage), &_hidl_formattedMessage_parent,  reinterpret_cast<const void **>(&formattedMessage));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_formattedMessage_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*formattedMessage),
            _hidl_data,
            _hidl_formattedMessage_parent,
            0 /* parentOffset */, &_hidl_formattedMessage_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_confirmationToken_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*confirmationToken), &_hidl_confirmationToken_parent,  reinterpret_cast<const void **>(&confirmationToken));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_confirmationToken_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*confirmationToken),
            _hidl_data,
            _hidl_confirmationToken_parent,
            0 /* parentOffset */, &_hidl_confirmationToken_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IConfirmationResultCallback::result::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&error);
        _hidl_args.push_back((void *)formattedMessage);
        _hidl_args.push_back((void *)confirmationToken);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.confirmationui", "1.0", "IConfirmationResultCallback", "result", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IConfirmationResultCallback*>(_hidl_this->getImpl().get())->result(error, *formattedMessage, *confirmationToken);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.confirmationui", "1.0", "IConfirmationResultCallback", "result", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::confirmationui::V1_0::IConfirmationResultCallback follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwConfirmationResultCallback::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwConfirmationResultCallback::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwConfirmationResultCallback::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* result */:
        {
            _hidl_err = ::android::hardware::confirmationui::V1_0::BnHwConfirmationResultCallback::_hidl_result(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsConfirmationResultCallback::BsConfirmationResultCallback(const ::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationResultCallback> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.confirmationui@1.0", "IConfirmationResultCallback"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsConfirmationResultCallback::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IConfirmationResultCallback> IConfirmationResultCallback::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwConfirmationResultCallback>(serviceName, false, getStub);
}

::android::sp<IConfirmationResultCallback> IConfirmationResultCallback::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwConfirmationResultCallback>(serviceName, true, getStub);
}

::android::status_t IConfirmationResultCallback::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IConfirmationResultCallback::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.confirmationui@1.0::IConfirmationResultCallback",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace confirmationui
}  // namespace hardware
}  // namespace android
