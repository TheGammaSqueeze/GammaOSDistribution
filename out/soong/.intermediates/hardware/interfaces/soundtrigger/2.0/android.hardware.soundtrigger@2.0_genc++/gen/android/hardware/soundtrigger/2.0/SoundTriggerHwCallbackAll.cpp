#define LOG_TAG "android.hardware.soundtrigger@2.0::SoundTriggerHwCallback"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/soundtrigger/2.0/BpHwSoundTriggerHwCallback.h>
#include <android/hardware/soundtrigger/2.0/BnHwSoundTriggerHwCallback.h>
#include <android/hardware/soundtrigger/2.0/BsSoundTriggerHwCallback.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace soundtrigger {
namespace V2_0 {

::android::status_t readEmbeddedFromParcel(
        const ISoundTriggerHwCallback::ISoundTriggerHwCallback::RecognitionEvent &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.data),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::RecognitionEvent, data), &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ISoundTriggerHwCallback::ISoundTriggerHwCallback::RecognitionEvent &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.data,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::RecognitionEvent, data), &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const ISoundTriggerHwCallback::ISoundTriggerHwCallback::PhraseRecognitionEvent &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::RecognitionEvent &>(obj.common),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::PhraseRecognitionEvent, common));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_phraseExtras_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::soundtrigger::V2_0::PhraseRecognitionExtra> &>(obj.phraseExtras),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::PhraseRecognitionEvent, phraseExtras), &_hidl_phraseExtras_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.phraseExtras.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::soundtrigger::V2_0::PhraseRecognitionExtra &>(obj.phraseExtras[_hidl_index_0]),
                parcel,
                _hidl_phraseExtras_child,
                _hidl_index_0 * sizeof(::android::hardware::soundtrigger::V2_0::PhraseRecognitionExtra));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ISoundTriggerHwCallback::ISoundTriggerHwCallback::PhraseRecognitionEvent &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.common,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::PhraseRecognitionEvent, common));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_phraseExtras_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.phraseExtras,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::PhraseRecognitionEvent, phraseExtras), &_hidl_phraseExtras_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.phraseExtras.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.phraseExtras[_hidl_index_0],
                parcel,
                _hidl_phraseExtras_child,
                _hidl_index_0 * sizeof(::android::hardware::soundtrigger::V2_0::PhraseRecognitionExtra));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const ISoundTriggerHwCallback::ISoundTriggerHwCallback::ModelEvent &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.data),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::ModelEvent, data), &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ISoundTriggerHwCallback::ISoundTriggerHwCallback::ModelEvent &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.data,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::ModelEvent, data), &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

const char* ISoundTriggerHwCallback::descriptor("android.hardware.soundtrigger@2.0::ISoundTriggerHwCallback");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ISoundTriggerHwCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwSoundTriggerHwCallback(static_cast<ISoundTriggerHwCallback *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ISoundTriggerHwCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsSoundTriggerHwCallback(static_cast<ISoundTriggerHwCallback *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ISoundTriggerHwCallback::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ISoundTriggerHwCallback::descriptor);
}

// Methods from ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback follow.
// no default implementation for: ::android::hardware::Return<void> ISoundTriggerHwCallback::recognitionCallback(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::RecognitionEvent& event, int32_t cookie)
// no default implementation for: ::android::hardware::Return<void> ISoundTriggerHwCallback::phraseRecognitionCallback(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::PhraseRecognitionEvent& event, int32_t cookie)
// no default implementation for: ::android::hardware::Return<void> ISoundTriggerHwCallback::soundModelCallback(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::ModelEvent& event, int32_t cookie)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ISoundTriggerHwCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISoundTriggerHwCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISoundTriggerHwCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISoundTriggerHwCallback::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){26,110,43,210,137,242,41,49,197,38,178,25,22,145,15,29,76,67,107,122,203,149,86,228,36,61,228,206,142,108,194,228} /* 1a6e2bd289f22931c526b21916910f1d4c436b7acb9556e4243de4ce8e6cc2e4 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISoundTriggerHwCallback::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ISoundTriggerHwCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ISoundTriggerHwCallback::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISoundTriggerHwCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ISoundTriggerHwCallback::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ISoundTriggerHwCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>> ISoundTriggerHwCallback::castFrom(const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>> ISoundTriggerHwCallback::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ISoundTriggerHwCallback, ::android::hidl::base::V1_0::IBase, BpHwSoundTriggerHwCallback>(
            parent, "android.hardware.soundtrigger@2.0::ISoundTriggerHwCallback", emitError);
}

BpHwSoundTriggerHwCallback::BpHwSoundTriggerHwCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ISoundTriggerHwCallback>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.soundtrigger@2.0", "ISoundTriggerHwCallback") {
}

void BpHwSoundTriggerHwCallback::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ISoundTriggerHwCallback>::onLastStrongRef(id);
}
// Methods from ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback follow.
::android::hardware::Return<void> BpHwSoundTriggerHwCallback::_hidl_recognitionCallback(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::RecognitionEvent& event, int32_t cookie) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISoundTriggerHwCallback::recognitionCallback::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&event);
        _hidl_args.push_back((void *)&cookie);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHwCallback", "recognitionCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSoundTriggerHwCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.writeBuffer(&event, sizeof(event), &_hidl_event_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            event,
            &_hidl_data,
            _hidl_event_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(cookie);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* recognitionCallback */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHwCallback", "recognitionCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwSoundTriggerHwCallback::_hidl_phraseRecognitionCallback(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::PhraseRecognitionEvent& event, int32_t cookie) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISoundTriggerHwCallback::phraseRecognitionCallback::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&event);
        _hidl_args.push_back((void *)&cookie);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHwCallback", "phraseRecognitionCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSoundTriggerHwCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.writeBuffer(&event, sizeof(event), &_hidl_event_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            event,
            &_hidl_data,
            _hidl_event_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(cookie);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* phraseRecognitionCallback */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHwCallback", "phraseRecognitionCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwSoundTriggerHwCallback::_hidl_soundModelCallback(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::ModelEvent& event, int32_t cookie) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISoundTriggerHwCallback::soundModelCallback::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&event);
        _hidl_args.push_back((void *)&cookie);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHwCallback", "soundModelCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSoundTriggerHwCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.writeBuffer(&event, sizeof(event), &_hidl_event_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            event,
            &_hidl_data,
            _hidl_event_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(cookie);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* soundModelCallback */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHwCallback", "soundModelCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback follow.
::android::hardware::Return<void> BpHwSoundTriggerHwCallback::recognitionCallback(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::RecognitionEvent& event, int32_t cookie){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::soundtrigger::V2_0::BpHwSoundTriggerHwCallback::_hidl_recognitionCallback(this, this, event, cookie);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHwCallback::phraseRecognitionCallback(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::PhraseRecognitionEvent& event, int32_t cookie){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::soundtrigger::V2_0::BpHwSoundTriggerHwCallback::_hidl_phraseRecognitionCallback(this, this, event, cookie);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHwCallback::soundModelCallback(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::ModelEvent& event, int32_t cookie){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::soundtrigger::V2_0::BpHwSoundTriggerHwCallback::_hidl_soundModelCallback(this, this, event, cookie);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwSoundTriggerHwCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHwCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHwCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHwCallback::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHwCallback::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwSoundTriggerHwCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwSoundTriggerHwCallback::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHwCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHwCallback::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwSoundTriggerHwCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwSoundTriggerHwCallback::BnHwSoundTriggerHwCallback(const ::android::sp<ISoundTriggerHwCallback> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.soundtrigger@2.0", "ISoundTriggerHwCallback") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwSoundTriggerHwCallback::~BnHwSoundTriggerHwCallback() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback follow.
::android::status_t BnHwSoundTriggerHwCallback::_hidl_recognitionCallback(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSoundTriggerHwCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::RecognitionEvent* event;
    int32_t cookie;

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*event), &_hidl_event_parent,  const_cast<const void**>(reinterpret_cast<void **>(&event)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::RecognitionEvent &>(*event),
            _hidl_data,
            _hidl_event_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&cookie);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISoundTriggerHwCallback::recognitionCallback::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)event);
        _hidl_args.push_back((void *)&cookie);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHwCallback", "recognitionCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISoundTriggerHwCallback*>(_hidl_this->getImpl().get())->recognitionCallback(*event, cookie);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHwCallback", "recognitionCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwSoundTriggerHwCallback::_hidl_phraseRecognitionCallback(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSoundTriggerHwCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::PhraseRecognitionEvent* event;
    int32_t cookie;

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*event), &_hidl_event_parent,  const_cast<const void**>(reinterpret_cast<void **>(&event)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::PhraseRecognitionEvent &>(*event),
            _hidl_data,
            _hidl_event_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&cookie);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISoundTriggerHwCallback::phraseRecognitionCallback::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)event);
        _hidl_args.push_back((void *)&cookie);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHwCallback", "phraseRecognitionCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISoundTriggerHwCallback*>(_hidl_this->getImpl().get())->phraseRecognitionCallback(*event, cookie);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHwCallback", "phraseRecognitionCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwSoundTriggerHwCallback::_hidl_soundModelCallback(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSoundTriggerHwCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::ModelEvent* event;
    int32_t cookie;

    size_t _hidl_event_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*event), &_hidl_event_parent,  const_cast<const void**>(reinterpret_cast<void **>(&event)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::ModelEvent &>(*event),
            _hidl_data,
            _hidl_event_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&cookie);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISoundTriggerHwCallback::soundModelCallback::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)event);
        _hidl_args.push_back((void *)&cookie);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHwCallback", "soundModelCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISoundTriggerHwCallback*>(_hidl_this->getImpl().get())->soundModelCallback(*event, cookie);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHwCallback", "soundModelCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwSoundTriggerHwCallback::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwSoundTriggerHwCallback::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwSoundTriggerHwCallback::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* recognitionCallback */:
        {
            _hidl_err = ::android::hardware::soundtrigger::V2_0::BnHwSoundTriggerHwCallback::_hidl_recognitionCallback(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* phraseRecognitionCallback */:
        {
            _hidl_err = ::android::hardware::soundtrigger::V2_0::BnHwSoundTriggerHwCallback::_hidl_phraseRecognitionCallback(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* soundModelCallback */:
        {
            _hidl_err = ::android::hardware::soundtrigger::V2_0::BnHwSoundTriggerHwCallback::_hidl_soundModelCallback(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsSoundTriggerHwCallback::BsSoundTriggerHwCallback(const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.soundtrigger@2.0", "ISoundTriggerHwCallback"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsSoundTriggerHwCallback::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ISoundTriggerHwCallback> ISoundTriggerHwCallback::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwSoundTriggerHwCallback>(serviceName, false, getStub);
}

::android::sp<ISoundTriggerHwCallback> ISoundTriggerHwCallback::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwSoundTriggerHwCallback>(serviceName, true, getStub);
}

::android::status_t ISoundTriggerHwCallback::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ISoundTriggerHwCallback::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.soundtrigger@2.0::ISoundTriggerHwCallback",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_0
}  // namespace soundtrigger
}  // namespace hardware
}  // namespace android
