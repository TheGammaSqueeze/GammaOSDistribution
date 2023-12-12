#define LOG_TAG "android.hardware.drm@1.1::DrmFactory"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/drm/1.1/BpHwDrmFactory.h>
#include <android/hardware/drm/1.1/BnHwDrmFactory.h>
#include <android/hardware/drm/1.1/BsDrmFactory.h>
#include <android/hardware/drm/1.0/BpHwDrmFactory.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace drm {
namespace V1_1 {

const char* IDrmFactory::descriptor("android.hardware.drm@1.1::IDrmFactory");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IDrmFactory::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwDrmFactory(static_cast<IDrmFactory *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IDrmFactory::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsDrmFactory(static_cast<IDrmFactory *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IDrmFactory::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IDrmFactory::descriptor);
}

// Methods from ::android::hardware::drm::V1_0::IDrmFactory follow.
// no default implementation for: ::android::hardware::Return<bool> IDrmFactory::isCryptoSchemeSupported(const ::android::hardware::hidl_array<uint8_t, 16>& uuid)
// no default implementation for: ::android::hardware::Return<bool> IDrmFactory::isContentTypeSupported(const ::android::hardware::hidl_string& mimeType)
// no default implementation for: ::android::hardware::Return<void> IDrmFactory::createPlugin(const ::android::hardware::hidl_array<uint8_t, 16>& uuid, const ::android::hardware::hidl_string& appPackageName, createPlugin_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IDrmFactory::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::drm::V1_1::IDrmFactory::descriptor,
        ::android::hardware::drm::V1_0::IDrmFactory::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDrmFactory::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDrmFactory::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::drm::V1_1::IDrmFactory::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDrmFactory::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){120,119,255,142,76,30,72,184,37,230,229,230,109,5,2,136,229,101,110,213,53,198,28,199,131,10,146,237,74,158,25,144} /* 7877ff8e4c1e48b825e6e5e66d050288e5656ed535c61cc7830a92ed4a9e1990 */,
        (uint8_t[32]){20,64,207,253,250,235,18,131,10,193,14,230,255,219,15,16,131,231,1,5,123,128,109,241,31,180,120,123,76,145,231,24} /* 1440cffdfaeb12830ac10ee6ffdb0f1083e701057b806df11fb4787b4c91e718 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDrmFactory::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IDrmFactory::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IDrmFactory::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDrmFactory::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IDrmFactory::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IDrmFactory::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::drm::V1_1::IDrmFactory>> IDrmFactory::castFrom(const ::android::sp<::android::hardware::drm::V1_1::IDrmFactory>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::drm::V1_1::IDrmFactory>> IDrmFactory::castFrom(const ::android::sp<::android::hardware::drm::V1_0::IDrmFactory>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDrmFactory, ::android::hardware::drm::V1_0::IDrmFactory, BpHwDrmFactory>(
            parent, "android.hardware.drm@1.1::IDrmFactory", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::drm::V1_1::IDrmFactory>> IDrmFactory::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDrmFactory, ::android::hidl::base::V1_0::IBase, BpHwDrmFactory>(
            parent, "android.hardware.drm@1.1::IDrmFactory", emitError);
}

BpHwDrmFactory::BpHwDrmFactory(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IDrmFactory>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.drm@1.1", "IDrmFactory") {
}

void BpHwDrmFactory::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IDrmFactory>::onLastStrongRef(id);
}

// Methods from ::android::hardware::drm::V1_0::IDrmFactory follow.
::android::hardware::Return<bool> BpHwDrmFactory::isCryptoSchemeSupported(const ::android::hardware::hidl_array<uint8_t, 16>& uuid){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmFactory::_hidl_isCryptoSchemeSupported(this, this, uuid);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwDrmFactory::isContentTypeSupported(const ::android::hardware::hidl_string& mimeType){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmFactory::_hidl_isContentTypeSupported(this, this, mimeType);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmFactory::createPlugin(const ::android::hardware::hidl_array<uint8_t, 16>& uuid, const ::android::hardware::hidl_string& appPackageName, createPlugin_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::drm::V1_0::BpHwDrmFactory::_hidl_createPlugin(this, this, uuid, appPackageName, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwDrmFactory::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmFactory::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmFactory::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmFactory::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmFactory::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwDrmFactory::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwDrmFactory::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmFactory::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDrmFactory::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwDrmFactory::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwDrmFactory::BnHwDrmFactory(const ::android::sp<IDrmFactory> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.drm@1.1", "IDrmFactory") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwDrmFactory::~BnHwDrmFactory() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}


// Methods from ::android::hardware::drm::V1_0::IDrmFactory follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwDrmFactory::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwDrmFactory::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwDrmFactory::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* isCryptoSchemeSupported */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmFactory::_hidl_isCryptoSchemeSupported(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* isContentTypeSupported */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmFactory::_hidl_isContentTypeSupported(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* createPlugin */:
        {
            _hidl_err = ::android::hardware::drm::V1_0::BnHwDrmFactory::_hidl_createPlugin(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsDrmFactory::BsDrmFactory(const ::android::sp<::android::hardware::drm::V1_1::IDrmFactory> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.drm@1.1", "IDrmFactory"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsDrmFactory::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IDrmFactory> IDrmFactory::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwDrmFactory>(serviceName, false, getStub);
}

::android::sp<IDrmFactory> IDrmFactory::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwDrmFactory>(serviceName, true, getStub);
}

::android::status_t IDrmFactory::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IDrmFactory::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.drm@1.1::IDrmFactory",
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
