#define LOG_TAG "android.hardware.confirmationui@1.0::ConfirmationUI"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/confirmationui/1.0/BpHwConfirmationUI.h>
#include <android/hardware/confirmationui/1.0/BnHwConfirmationUI.h>
#include <android/hardware/confirmationui/1.0/BsConfirmationUI.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace confirmationui {
namespace V1_0 {

const char* IConfirmationUI::descriptor("android.hardware.confirmationui@1.0::IConfirmationUI");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IConfirmationUI::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwConfirmationUI(static_cast<IConfirmationUI *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IConfirmationUI::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsConfirmationUI(static_cast<IConfirmationUI *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IConfirmationUI::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IConfirmationUI::descriptor);
}

// Methods from ::android::hardware::confirmationui::V1_0::IConfirmationUI follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::confirmationui::V1_0::ResponseCode> IConfirmationUI::promptUserConfirmation(const ::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationResultCallback>& resultCB, const ::android::hardware::hidl_string& promptText, const ::android::hardware::hidl_vec<uint8_t>& extraData, const ::android::hardware::hidl_string& locale, const ::android::hardware::hidl_vec<::android::hardware::confirmationui::V1_0::UIOption>& uiOptions)
// no default implementation for: ::android::hardware::Return<::android::hardware::confirmationui::V1_0::ResponseCode> IConfirmationUI::deliverSecureInputEvent(const ::android::hardware::keymaster::V4_0::HardwareAuthToken& secureInputToken)
// no default implementation for: ::android::hardware::Return<void> IConfirmationUI::abort()

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IConfirmationUI::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::confirmationui::V1_0::IConfirmationUI::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfirmationUI::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfirmationUI::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::confirmationui::V1_0::IConfirmationUI::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfirmationUI::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){109,131,71,255,60,215,222,71,16,101,172,62,142,104,56,80,115,99,12,222,235,233,248,250,88,203,145,207,68,67,108,149} /* 6d8347ff3cd7de471065ac3e8e68385073630cdeebe9f8fa58cb91cf44436c95 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfirmationUI::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IConfirmationUI::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IConfirmationUI::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IConfirmationUI::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IConfirmationUI::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IConfirmationUI::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationUI>> IConfirmationUI::castFrom(const ::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationUI>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationUI>> IConfirmationUI::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IConfirmationUI, ::android::hidl::base::V1_0::IBase, BpHwConfirmationUI>(
            parent, "android.hardware.confirmationui@1.0::IConfirmationUI", emitError);
}

BpHwConfirmationUI::BpHwConfirmationUI(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IConfirmationUI>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.confirmationui@1.0", "IConfirmationUI") {
}

void BpHwConfirmationUI::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IConfirmationUI>::onLastStrongRef(id);
}
// Methods from ::android::hardware::confirmationui::V1_0::IConfirmationUI follow.
::android::hardware::Return<::android::hardware::confirmationui::V1_0::ResponseCode> BpHwConfirmationUI::_hidl_promptUserConfirmation(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationResultCallback>& resultCB, const ::android::hardware::hidl_string& promptText, const ::android::hardware::hidl_vec<uint8_t>& extraData, const ::android::hardware::hidl_string& locale, const ::android::hardware::hidl_vec<::android::hardware::confirmationui::V1_0::UIOption>& uiOptions) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IConfirmationUI::promptUserConfirmation::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&resultCB);
        _hidl_args.push_back((void *)&promptText);
        _hidl_args.push_back((void *)&extraData);
        _hidl_args.push_back((void *)&locale);
        _hidl_args.push_back((void *)&uiOptions);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.confirmationui", "1.0", "IConfirmationUI", "promptUserConfirmation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::confirmationui::V1_0::ResponseCode _hidl_out_error;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwConfirmationUI::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (resultCB == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(resultCB.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_promptText_parent;

    _hidl_err = _hidl_data.writeBuffer(&promptText, sizeof(promptText), &_hidl_promptText_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            promptText,
            &_hidl_data,
            _hidl_promptText_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_extraData_parent;

    _hidl_err = _hidl_data.writeBuffer(&extraData, sizeof(extraData), &_hidl_extraData_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_extraData_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            extraData,
            &_hidl_data,
            _hidl_extraData_parent,
            0 /* parentOffset */, &_hidl_extraData_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_locale_parent;

    _hidl_err = _hidl_data.writeBuffer(&locale, sizeof(locale), &_hidl_locale_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            locale,
            &_hidl_data,
            _hidl_locale_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_uiOptions_parent;

    _hidl_err = _hidl_data.writeBuffer(&uiOptions, sizeof(uiOptions), &_hidl_uiOptions_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_uiOptions_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            uiOptions,
            &_hidl_data,
            _hidl_uiOptions_parent,
            0 /* parentOffset */, &_hidl_uiOptions_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* promptUserConfirmation */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.confirmationui", "1.0", "IConfirmationUI", "promptUserConfirmation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::confirmationui::V1_0::ResponseCode>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::confirmationui::V1_0::ResponseCode>(_hidl_status);
}

::android::hardware::Return<::android::hardware::confirmationui::V1_0::ResponseCode> BpHwConfirmationUI::_hidl_deliverSecureInputEvent(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::keymaster::V4_0::HardwareAuthToken& secureInputToken) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IConfirmationUI::deliverSecureInputEvent::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&secureInputToken);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.confirmationui", "1.0", "IConfirmationUI", "deliverSecureInputEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::confirmationui::V1_0::ResponseCode _hidl_out_error;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwConfirmationUI::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_secureInputToken_parent;

    _hidl_err = _hidl_data.writeBuffer(&secureInputToken, sizeof(secureInputToken), &_hidl_secureInputToken_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            secureInputToken,
            &_hidl_data,
            _hidl_secureInputToken_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* deliverSecureInputEvent */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.confirmationui", "1.0", "IConfirmationUI", "deliverSecureInputEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::confirmationui::V1_0::ResponseCode>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::confirmationui::V1_0::ResponseCode>(_hidl_status);
}

::android::hardware::Return<void> BpHwConfirmationUI::_hidl_abort(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IConfirmationUI::abort::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.confirmationui", "1.0", "IConfirmationUI", "abort", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwConfirmationUI::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* abort */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.confirmationui", "1.0", "IConfirmationUI", "abort", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::confirmationui::V1_0::IConfirmationUI follow.
::android::hardware::Return<::android::hardware::confirmationui::V1_0::ResponseCode> BpHwConfirmationUI::promptUserConfirmation(const ::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationResultCallback>& resultCB, const ::android::hardware::hidl_string& promptText, const ::android::hardware::hidl_vec<uint8_t>& extraData, const ::android::hardware::hidl_string& locale, const ::android::hardware::hidl_vec<::android::hardware::confirmationui::V1_0::UIOption>& uiOptions){
    ::android::hardware::Return<::android::hardware::confirmationui::V1_0::ResponseCode>  _hidl_out = ::android::hardware::confirmationui::V1_0::BpHwConfirmationUI::_hidl_promptUserConfirmation(this, this, resultCB, promptText, extraData, locale, uiOptions);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::confirmationui::V1_0::ResponseCode> BpHwConfirmationUI::deliverSecureInputEvent(const ::android::hardware::keymaster::V4_0::HardwareAuthToken& secureInputToken){
    ::android::hardware::Return<::android::hardware::confirmationui::V1_0::ResponseCode>  _hidl_out = ::android::hardware::confirmationui::V1_0::BpHwConfirmationUI::_hidl_deliverSecureInputEvent(this, this, secureInputToken);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfirmationUI::abort(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::confirmationui::V1_0::BpHwConfirmationUI::_hidl_abort(this, this);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwConfirmationUI::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfirmationUI::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfirmationUI::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfirmationUI::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfirmationUI::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwConfirmationUI::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwConfirmationUI::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfirmationUI::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwConfirmationUI::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwConfirmationUI::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwConfirmationUI::BnHwConfirmationUI(const ::android::sp<IConfirmationUI> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.confirmationui@1.0", "IConfirmationUI") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwConfirmationUI::~BnHwConfirmationUI() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::confirmationui::V1_0::IConfirmationUI follow.
::android::status_t BnHwConfirmationUI::_hidl_promptUserConfirmation(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwConfirmationUI::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationResultCallback> resultCB;
    const ::android::hardware::hidl_string* promptText;
    const ::android::hardware::hidl_vec<uint8_t>* extraData;
    const ::android::hardware::hidl_string* locale;
    const ::android::hardware::hidl_vec<::android::hardware::confirmationui::V1_0::UIOption>* uiOptions;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        resultCB = ::android::hardware::fromBinder<::android::hardware::confirmationui::V1_0::IConfirmationResultCallback,::android::hardware::confirmationui::V1_0::BpHwConfirmationResultCallback,::android::hardware::confirmationui::V1_0::BnHwConfirmationResultCallback>(_hidl_binder);
    }

    size_t _hidl_promptText_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*promptText), &_hidl_promptText_parent,  reinterpret_cast<const void **>(&promptText));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*promptText),
            _hidl_data,
            _hidl_promptText_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_extraData_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*extraData), &_hidl_extraData_parent,  reinterpret_cast<const void **>(&extraData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_extraData_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*extraData),
            _hidl_data,
            _hidl_extraData_parent,
            0 /* parentOffset */, &_hidl_extraData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_locale_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*locale), &_hidl_locale_parent,  reinterpret_cast<const void **>(&locale));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*locale),
            _hidl_data,
            _hidl_locale_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_uiOptions_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*uiOptions), &_hidl_uiOptions_parent,  reinterpret_cast<const void **>(&uiOptions));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_uiOptions_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::confirmationui::V1_0::UIOption> &>(*uiOptions),
            _hidl_data,
            _hidl_uiOptions_parent,
            0 /* parentOffset */, &_hidl_uiOptions_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IConfirmationUI::promptUserConfirmation::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&resultCB);
        _hidl_args.push_back((void *)promptText);
        _hidl_args.push_back((void *)extraData);
        _hidl_args.push_back((void *)locale);
        _hidl_args.push_back((void *)uiOptions);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.confirmationui", "1.0", "IConfirmationUI", "promptUserConfirmation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::confirmationui::V1_0::ResponseCode _hidl_out_error = static_cast<IConfirmationUI*>(_hidl_this->getImpl().get())->promptUserConfirmation(resultCB, *promptText, *extraData, *locale, *uiOptions);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.confirmationui", "1.0", "IConfirmationUI", "promptUserConfirmation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwConfirmationUI::_hidl_deliverSecureInputEvent(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwConfirmationUI::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::keymaster::V4_0::HardwareAuthToken* secureInputToken;

    size_t _hidl_secureInputToken_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*secureInputToken), &_hidl_secureInputToken_parent,  const_cast<const void**>(reinterpret_cast<void **>(&secureInputToken)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::keymaster::V4_0::HardwareAuthToken &>(*secureInputToken),
            _hidl_data,
            _hidl_secureInputToken_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IConfirmationUI::deliverSecureInputEvent::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)secureInputToken);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.confirmationui", "1.0", "IConfirmationUI", "deliverSecureInputEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::confirmationui::V1_0::ResponseCode _hidl_out_error = static_cast<IConfirmationUI*>(_hidl_this->getImpl().get())->deliverSecureInputEvent(*secureInputToken);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.confirmationui", "1.0", "IConfirmationUI", "deliverSecureInputEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwConfirmationUI::_hidl_abort(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwConfirmationUI::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IConfirmationUI::abort::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.confirmationui", "1.0", "IConfirmationUI", "abort", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IConfirmationUI*>(_hidl_this->getImpl().get())->abort();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.confirmationui", "1.0", "IConfirmationUI", "abort", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::confirmationui::V1_0::IConfirmationUI follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwConfirmationUI::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwConfirmationUI::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwConfirmationUI::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* promptUserConfirmation */:
        {
            _hidl_err = ::android::hardware::confirmationui::V1_0::BnHwConfirmationUI::_hidl_promptUserConfirmation(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* deliverSecureInputEvent */:
        {
            _hidl_err = ::android::hardware::confirmationui::V1_0::BnHwConfirmationUI::_hidl_deliverSecureInputEvent(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* abort */:
        {
            _hidl_err = ::android::hardware::confirmationui::V1_0::BnHwConfirmationUI::_hidl_abort(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsConfirmationUI::BsConfirmationUI(const ::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationUI> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.confirmationui@1.0", "IConfirmationUI"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsConfirmationUI::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IConfirmationUI> IConfirmationUI::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwConfirmationUI>(serviceName, false, getStub);
}

::android::sp<IConfirmationUI> IConfirmationUI::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwConfirmationUI>(serviceName, true, getStub);
}

::android::status_t IConfirmationUI::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IConfirmationUI::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.confirmationui@1.0::IConfirmationUI",
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
