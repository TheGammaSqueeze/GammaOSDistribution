#define LOG_TAG "android.hardware.drm@1.1::CryptoFactory"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/drm/1.1/BpHwCryptoFactory.h>
#include <android/hardware/drm/1.1/BnHwCryptoFactory.h>
#include <android/hardware/drm/1.1/BsCryptoFactory.h>
#include <android/hardware/drm/1.0/BpHwCryptoFactory.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace drm {
namespace V1_1 {

const char* ICryptoFactory::descriptor("android.hardware.drm@1.1::ICryptoFactory");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ICryptoFactory::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwCryptoFactory(static_cast<ICryptoFactory *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ICryptoFactory::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsCryptoFactory(static_cast<ICryptoFactory *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ICryptoFactory::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ICryptoFactory::descriptor);
}

// Methods from ::android::hardware::drm::V1_0::ICryptoFactory follow.
// no default implementation for: ::android::hardware::Return<bool> ICryptoFactory::isCryptoSchemeSupported(const ::android::hardware::hidl_array<uint8_t, 16>& uuid)
// no default implementation for: ::android::hardware::Return<void> ICryptoFactory::createPlugin(const ::android::hardware::hidl_array<uint8_t, 16>& uuid, const ::android::hardware::hidl_vec<uint8_t>& initData, createPlugin_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ICryptoFactory::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::drm::V1_1::ICryptoFactory::descriptor,
        ::android::hardware::drm::V1_0::ICryptoFactory::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICryptoFactory::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICryptoFactory::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::drm::V1_1::ICryptoFactory::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICryptoFactory::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){31,191,45,126,56,54,50,33,106,170,161,217,114,162,26,97,143,85,101,146,99,210,230,240,179,9,227,203,50,59,75,99} /* 1fbf2d7e383632216aaaa1d972a21a618f55659263d2e6f0b309e3cb323b4b63 */,
        (uint8_t[32]){223,23,76,24,113,200,100,180,199,156,169,246,74,174,121,54,210,74,39,46,202,49,145,163,4,88,202,43,112,109,236,121} /* df174c1871c864b4c79ca9f64aae7936d24a272eca3191a30458ca2b706dec79 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICryptoFactory::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICryptoFactory::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ICryptoFactory::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICryptoFactory::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ICryptoFactory::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICryptoFactory::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::drm::V1_1::ICryptoFactory>> ICryptoFactory::castFrom(const ::android::sp<::android::hardware::drm::V1_1::ICryptoFactory>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::drm::V1_1::ICryptoFactory>> ICryptoFactory::castFrom(const ::android::sp<::android::hardware::drm::V1_0::ICryptoFactory>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICryptoFactory, ::android::hardware::drm::V1_0::ICryptoFactory, BpHwCryptoFactory>(
            parent, "android.hardware.drm@1.1::ICryptoFactory", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::drm::V1_1::ICryptoFactory>> ICryptoFactory::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICryptoFactory, ::android::hidl::base::V1_0::IBase, BpHwCryptoFactory>(
            parent, "android.hardware.drm@1.1::ICryptoFactory", emitError);
}

BpHwCryptoFactory::BpHwCryptoFactory(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ICryptoFactory>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.drm@1.1", "ICryptoFactory") {
}

void BpHwCryptoFactory::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ICryptoFactory>::onLastStrongRef(id);
}

// Methods from ::android::hardware::drm::V1_0::ICryptoFactory follow.
::android::hardware::Return<bool> BpHwCryptoFactory::isCryptoSchemeSupported(const ::android::hardware::hidl_array<uint8_t, 16>& uuid){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::drm::V1_0::BpHwCryptoFactory::_hidl_isCryptoSchemeSupported(this, this, uuid);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoFactory::createPlugin(const ::android::hardware::hidl_array<uint8_t, 16>& uuid, const ::android::hardware::hidl_vec<uint8_t>& initData, createPlugin_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwCryptoFactory::_hidl_createPlugin(this, this, uuid, initData, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwCryptoFactory::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoFactory::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoFactory::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoFactory::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoFactory::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCryptoFactory::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwCryptoFactory::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoFactory::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCryptoFactory::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCryptoFactory::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwCryptoFactory::BnHwCryptoFactory(const ::android::sp<ICryptoFactory> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.drm@1.1", "ICryptoFactory") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwCryptoFactory::~BnHwCryptoFactory() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}


// Methods from ::android::hardware::drm::V1_0::ICryptoFactory follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwCryptoFactory::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwCryptoFactory::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwCryptoFactory::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* isCryptoSchemeSupported */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwCryptoFactory::_hidl_isCryptoSchemeSupported(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* createPlugin */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwCryptoFactory::_hidl_createPlugin(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsCryptoFactory::BsCryptoFactory(const ::android::sp<::android::hardware::drm::V1_1::ICryptoFactory> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.drm@1.1", "ICryptoFactory"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsCryptoFactory::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ICryptoFactory> ICryptoFactory::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCryptoFactory>(serviceName, false, getStub);
}

::android::sp<ICryptoFactory> ICryptoFactory::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCryptoFactory>(serviceName, true, getStub);
}

::android::status_t ICryptoFactory::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ICryptoFactory::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.drm@1.1::ICryptoFactory",
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
