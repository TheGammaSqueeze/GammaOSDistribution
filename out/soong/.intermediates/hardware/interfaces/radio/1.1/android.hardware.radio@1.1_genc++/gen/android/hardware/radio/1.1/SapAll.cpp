#define LOG_TAG "android.hardware.radio@1.1::Sap"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/radio/1.1/BpHwSap.h>
#include <android/hardware/radio/1.1/BnHwSap.h>
#include <android/hardware/radio/1.1/BsSap.h>
#include <android/hardware/radio/1.0/BpHwSap.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace radio {
namespace V1_1 {

const char* ISap::descriptor("android.hardware.radio@1.1::ISap");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ISap::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwSap(static_cast<ISap *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ISap::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsSap(static_cast<ISap *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ISap::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ISap::descriptor);
}

// Methods from ::android::hardware::radio::V1_0::ISap follow.
// no default implementation for: ::android::hardware::Return<void> ISap::setCallback(const ::android::sp<::android::hardware::radio::V1_0::ISapCallback>& sapCallback)
// no default implementation for: ::android::hardware::Return<void> ISap::connectReq(int32_t token, int32_t maxMsgSize)
// no default implementation for: ::android::hardware::Return<void> ISap::disconnectReq(int32_t token)
// no default implementation for: ::android::hardware::Return<void> ISap::apduReq(int32_t token, ::android::hardware::radio::V1_0::SapApduType type, const ::android::hardware::hidl_vec<uint8_t>& command)
// no default implementation for: ::android::hardware::Return<void> ISap::transferAtrReq(int32_t token)
// no default implementation for: ::android::hardware::Return<void> ISap::powerReq(int32_t token, bool state)
// no default implementation for: ::android::hardware::Return<void> ISap::resetSimReq(int32_t token)
// no default implementation for: ::android::hardware::Return<void> ISap::transferCardReaderStatusReq(int32_t token)
// no default implementation for: ::android::hardware::Return<void> ISap::setTransferProtocolReq(int32_t token, ::android::hardware::radio::V1_0::SapTransferProtocol transferProtocol)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ISap::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::radio::V1_1::ISap::descriptor,
        ::android::hardware::radio::V1_0::ISap::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISap::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISap::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::radio::V1_1::ISap::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISap::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){249,108,188,89,223,225,108,141,12,42,126,6,219,36,216,115,138,99,40,182,233,15,123,142,22,64,234,43,70,0,222,189} /* f96cbc59dfe16c8d0c2a7e06db24d8738a6328b6e90f7b8e1640ea2b4600debd */,
        (uint8_t[32]){222,58,185,247,59,16,115,205,103,123,25,216,134,251,146,126,147,129,179,1,97,167,4,113,45,43,48,248,117,135,63,92} /* de3ab9f73b1073cd677b19d886fb927e9381b30161a704712d2b30f875873f5c */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISap::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ISap::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ISap::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISap::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ISap::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ISap::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::radio::V1_1::ISap>> ISap::castFrom(const ::android::sp<::android::hardware::radio::V1_1::ISap>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::radio::V1_1::ISap>> ISap::castFrom(const ::android::sp<::android::hardware::radio::V1_0::ISap>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ISap, ::android::hardware::radio::V1_0::ISap, BpHwSap>(
            parent, "android.hardware.radio@1.1::ISap", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::radio::V1_1::ISap>> ISap::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ISap, ::android::hidl::base::V1_0::IBase, BpHwSap>(
            parent, "android.hardware.radio@1.1::ISap", emitError);
}

BpHwSap::BpHwSap(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ISap>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.radio@1.1", "ISap") {
}

void BpHwSap::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ISap>::onLastStrongRef(id);
}

// Methods from ::android::hardware::radio::V1_0::ISap follow.
::android::hardware::Return<void> BpHwSap::setCallback(const ::android::sp<::android::hardware::radio::V1_0::ISapCallback>& sapCallback){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwSap::_hidl_setCallback(this, this, sapCallback);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSap::connectReq(int32_t token, int32_t maxMsgSize){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwSap::_hidl_connectReq(this, this, token, maxMsgSize);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSap::disconnectReq(int32_t token){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwSap::_hidl_disconnectReq(this, this, token);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSap::apduReq(int32_t token, ::android::hardware::radio::V1_0::SapApduType type, const ::android::hardware::hidl_vec<uint8_t>& command){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwSap::_hidl_apduReq(this, this, token, type, command);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSap::transferAtrReq(int32_t token){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwSap::_hidl_transferAtrReq(this, this, token);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSap::powerReq(int32_t token, bool state){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwSap::_hidl_powerReq(this, this, token, state);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSap::resetSimReq(int32_t token){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwSap::_hidl_resetSimReq(this, this, token);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSap::transferCardReaderStatusReq(int32_t token){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwSap::_hidl_transferCardReaderStatusReq(this, this, token);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSap::setTransferProtocolReq(int32_t token, ::android::hardware::radio::V1_0::SapTransferProtocol transferProtocol){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::V1_0::BpHwSap::_hidl_setTransferProtocolReq(this, this, token, transferProtocol);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwSap::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSap::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSap::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSap::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSap::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwSap::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwSap::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSap::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSap::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwSap::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwSap::BnHwSap(const ::android::sp<ISap> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.radio@1.1", "ISap") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwSap::~BnHwSap() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}


// Methods from ::android::hardware::radio::V1_0::ISap follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwSap::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwSap::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwSap::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* setCallback */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwSap::_hidl_setCallback(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* connectReq */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwSap::_hidl_connectReq(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* disconnectReq */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwSap::_hidl_disconnectReq(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* apduReq */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwSap::_hidl_apduReq(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* transferAtrReq */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwSap::_hidl_transferAtrReq(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* powerReq */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwSap::_hidl_powerReq(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* resetSimReq */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwSap::_hidl_resetSimReq(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* transferCardReaderStatusReq */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwSap::_hidl_transferCardReaderStatusReq(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* setTransferProtocolReq */:
        {
            _hidl_err = ::android::hardware::radio::V1_0::BnHwSap::_hidl_setTransferProtocolReq(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsSap::BsSap(const ::android::sp<::android::hardware::radio::V1_1::ISap> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.radio@1.1", "ISap"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsSap::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ISap> ISap::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwSap>(serviceName, false, getStub);
}

::android::sp<ISap> ISap::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwSap>(serviceName, true, getStub);
}

::android::status_t ISap::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ISap::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.radio@1.1::ISap",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_1
}  // namespace radio
}  // namespace hardware
}  // namespace android
