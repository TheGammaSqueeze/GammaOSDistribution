#define LOG_TAG "android.hardware.broadcastradio@1.1::BroadcastRadioFactory"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/broadcastradio/1.1/BpHwBroadcastRadioFactory.h>
#include <android/hardware/broadcastradio/1.1/BnHwBroadcastRadioFactory.h>
#include <android/hardware/broadcastradio/1.1/BsBroadcastRadioFactory.h>
#include <android/hardware/broadcastradio/1.0/BpHwBroadcastRadioFactory.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace broadcastradio {
namespace V1_1 {

const char* IBroadcastRadioFactory::descriptor("android.hardware.broadcastradio@1.1::IBroadcastRadioFactory");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IBroadcastRadioFactory::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwBroadcastRadioFactory(static_cast<IBroadcastRadioFactory *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IBroadcastRadioFactory::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsBroadcastRadioFactory(static_cast<IBroadcastRadioFactory *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IBroadcastRadioFactory::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IBroadcastRadioFactory::descriptor);
}

// Methods from ::android::hardware::broadcastradio::V1_0::IBroadcastRadioFactory follow.
// no default implementation for: ::android::hardware::Return<void> IBroadcastRadioFactory::connectModule(::android::hardware::broadcastradio::V1_0::Class classId, connectModule_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IBroadcastRadioFactory::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::broadcastradio::V1_1::IBroadcastRadioFactory::descriptor,
        ::android::hardware::broadcastradio::V1_0::IBroadcastRadioFactory::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBroadcastRadioFactory::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBroadcastRadioFactory::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::broadcastradio::V1_1::IBroadcastRadioFactory::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBroadcastRadioFactory::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){181,214,45,205,102,63,196,252,201,119,178,82,175,89,179,51,4,59,223,231,61,226,241,31,230,214,168,191,67,138,15,146} /* b5d62dcd663fc4fcc977b252af59b333043bdfe73de2f11fe6d6a8bf438a0f92 */,
        (uint8_t[32]){237,130,87,156,12,22,95,234,161,45,14,51,192,107,51,66,171,65,236,10,67,146,71,242,2,119,94,131,105,228,110,246} /* ed82579c0c165feaa12d0e33c06b3342ab41ec0a439247f202775e8369e46ef6 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBroadcastRadioFactory::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IBroadcastRadioFactory::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IBroadcastRadioFactory::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBroadcastRadioFactory::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IBroadcastRadioFactory::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IBroadcastRadioFactory::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::broadcastradio::V1_1::IBroadcastRadioFactory>> IBroadcastRadioFactory::castFrom(const ::android::sp<::android::hardware::broadcastradio::V1_1::IBroadcastRadioFactory>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::broadcastradio::V1_1::IBroadcastRadioFactory>> IBroadcastRadioFactory::castFrom(const ::android::sp<::android::hardware::broadcastradio::V1_0::IBroadcastRadioFactory>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IBroadcastRadioFactory, ::android::hardware::broadcastradio::V1_0::IBroadcastRadioFactory, BpHwBroadcastRadioFactory>(
            parent, "android.hardware.broadcastradio@1.1::IBroadcastRadioFactory", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::broadcastradio::V1_1::IBroadcastRadioFactory>> IBroadcastRadioFactory::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IBroadcastRadioFactory, ::android::hidl::base::V1_0::IBase, BpHwBroadcastRadioFactory>(
            parent, "android.hardware.broadcastradio@1.1::IBroadcastRadioFactory", emitError);
}

BpHwBroadcastRadioFactory::BpHwBroadcastRadioFactory(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IBroadcastRadioFactory>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.broadcastradio@1.1", "IBroadcastRadioFactory") {
}

void BpHwBroadcastRadioFactory::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IBroadcastRadioFactory>::onLastStrongRef(id);
}

// Methods from ::android::hardware::broadcastradio::V1_0::IBroadcastRadioFactory follow.
::android::hardware::Return<void> BpHwBroadcastRadioFactory::connectModule(::android::hardware::broadcastradio::V1_0::Class classId, connectModule_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_0::BpHwBroadcastRadioFactory::_hidl_connectModule(this, this, classId, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwBroadcastRadioFactory::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBroadcastRadioFactory::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBroadcastRadioFactory::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBroadcastRadioFactory::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBroadcastRadioFactory::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwBroadcastRadioFactory::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwBroadcastRadioFactory::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBroadcastRadioFactory::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBroadcastRadioFactory::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwBroadcastRadioFactory::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwBroadcastRadioFactory::BnHwBroadcastRadioFactory(const ::android::sp<IBroadcastRadioFactory> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.broadcastradio@1.1", "IBroadcastRadioFactory") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwBroadcastRadioFactory::~BnHwBroadcastRadioFactory() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}


// Methods from ::android::hardware::broadcastradio::V1_0::IBroadcastRadioFactory follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwBroadcastRadioFactory::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwBroadcastRadioFactory::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwBroadcastRadioFactory::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* connectModule */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_0::BnHwBroadcastRadioFactory::_hidl_connectModule(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsBroadcastRadioFactory::BsBroadcastRadioFactory(const ::android::sp<::android::hardware::broadcastradio::V1_1::IBroadcastRadioFactory> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.broadcastradio@1.1", "IBroadcastRadioFactory"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsBroadcastRadioFactory::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IBroadcastRadioFactory> IBroadcastRadioFactory::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwBroadcastRadioFactory>(serviceName, false, getStub);
}

::android::sp<IBroadcastRadioFactory> IBroadcastRadioFactory::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwBroadcastRadioFactory>(serviceName, true, getStub);
}

::android::status_t IBroadcastRadioFactory::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IBroadcastRadioFactory::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.broadcastradio@1.1::IBroadcastRadioFactory",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_1
}  // namespace broadcastradio
}  // namespace hardware
}  // namespace android
