#define LOG_TAG "android.hardware.soundtrigger@2.0::SoundTriggerHw"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/soundtrigger/2.0/BpHwSoundTriggerHw.h>
#include <android/hardware/soundtrigger/2.0/BnHwSoundTriggerHw.h>
#include <android/hardware/soundtrigger/2.0/BsSoundTriggerHw.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace soundtrigger {
namespace V2_0 {

::android::status_t readEmbeddedFromParcel(
        const ISoundTriggerHw::ISoundTriggerHw::Properties &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.implementor),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Properties, implementor));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.description),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Properties, description));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ISoundTriggerHw::ISoundTriggerHw::Properties &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.implementor,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Properties, implementor));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.description,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Properties, description));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const ISoundTriggerHw::ISoundTriggerHw::SoundModel &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.data),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::SoundModel, data), &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ISoundTriggerHw::ISoundTriggerHw::SoundModel &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.data,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::SoundModel, data), &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const ISoundTriggerHw::ISoundTriggerHw::Phrase &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_users_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.users),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Phrase, users), &_hidl_users_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.locale),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Phrase, locale));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.text),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Phrase, text));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ISoundTriggerHw::ISoundTriggerHw::Phrase &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_users_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.users,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Phrase, users), &_hidl_users_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.locale,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Phrase, locale));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.text,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Phrase, text));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const ISoundTriggerHw::ISoundTriggerHw::PhraseSoundModel &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::SoundModel &>(obj.common),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::PhraseSoundModel, common));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_phrases_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Phrase> &>(obj.phrases),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::PhraseSoundModel, phrases), &_hidl_phrases_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.phrases.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Phrase &>(obj.phrases[_hidl_index_0]),
                parcel,
                _hidl_phrases_child,
                _hidl_index_0 * sizeof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Phrase));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ISoundTriggerHw::ISoundTriggerHw::PhraseSoundModel &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.common,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::PhraseSoundModel, common));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_phrases_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.phrases,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::PhraseSoundModel, phrases), &_hidl_phrases_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.phrases.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.phrases[_hidl_index_0],
                parcel,
                _hidl_phrases_child,
                _hidl_index_0 * sizeof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Phrase));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const ISoundTriggerHw::ISoundTriggerHw::RecognitionConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_phrases_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::soundtrigger::V2_0::PhraseRecognitionExtra> &>(obj.phrases),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::RecognitionConfig, phrases), &_hidl_phrases_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.phrases.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::soundtrigger::V2_0::PhraseRecognitionExtra &>(obj.phrases[_hidl_index_0]),
                parcel,
                _hidl_phrases_child,
                _hidl_index_0 * sizeof(::android::hardware::soundtrigger::V2_0::PhraseRecognitionExtra));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.data),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::RecognitionConfig, data), &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ISoundTriggerHw::ISoundTriggerHw::RecognitionConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_phrases_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.phrases,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::RecognitionConfig, phrases), &_hidl_phrases_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.phrases.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.phrases[_hidl_index_0],
                parcel,
                _hidl_phrases_child,
                _hidl_index_0 * sizeof(::android::hardware::soundtrigger::V2_0::PhraseRecognitionExtra));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.data,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::RecognitionConfig, data), &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

const char* ISoundTriggerHw::descriptor("android.hardware.soundtrigger@2.0::ISoundTriggerHw");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ISoundTriggerHw::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwSoundTriggerHw(static_cast<ISoundTriggerHw *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ISoundTriggerHw::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsSoundTriggerHw(static_cast<ISoundTriggerHw *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ISoundTriggerHw::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ISoundTriggerHw::descriptor);
}

// Methods from ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw follow.
// no default implementation for: ::android::hardware::Return<void> ISoundTriggerHw::getProperties(getProperties_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISoundTriggerHw::loadSoundModel(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::SoundModel& soundModel, const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>& callback, int32_t cookie, loadSoundModel_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISoundTriggerHw::loadPhraseSoundModel(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::PhraseSoundModel& soundModel, const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>& callback, int32_t cookie, loadPhraseSoundModel_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<int32_t> ISoundTriggerHw::unloadSoundModel(int32_t modelHandle)
// no default implementation for: ::android::hardware::Return<int32_t> ISoundTriggerHw::startRecognition(int32_t modelHandle, const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::RecognitionConfig& config, const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>& callback, int32_t cookie)
// no default implementation for: ::android::hardware::Return<int32_t> ISoundTriggerHw::stopRecognition(int32_t modelHandle)
// no default implementation for: ::android::hardware::Return<int32_t> ISoundTriggerHw::stopAllRecognitions()

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ISoundTriggerHw::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISoundTriggerHw::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISoundTriggerHw::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISoundTriggerHw::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){91,239,192,25,203,233,73,83,102,30,44,219,149,227,207,100,245,229,101,194,148,3,225,194,218,236,194,190,68,224,165,92} /* 5befc019cbe94953661e2cdb95e3cf64f5e565c29403e1c2daecc2be44e0a55c */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISoundTriggerHw::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ISoundTriggerHw::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ISoundTriggerHw::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISoundTriggerHw::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ISoundTriggerHw::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ISoundTriggerHw::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHw>> ISoundTriggerHw::castFrom(const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHw>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHw>> ISoundTriggerHw::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ISoundTriggerHw, ::android::hidl::base::V1_0::IBase, BpHwSoundTriggerHw>(
            parent, "android.hardware.soundtrigger@2.0::ISoundTriggerHw", emitError);
}

BpHwSoundTriggerHw::BpHwSoundTriggerHw(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ISoundTriggerHw>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.soundtrigger@2.0", "ISoundTriggerHw") {
}

void BpHwSoundTriggerHw::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ISoundTriggerHw>::onLastStrongRef(id);
}
// Methods from ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw follow.
::android::hardware::Return<void> BpHwSoundTriggerHw::_hidl_getProperties(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getProperties_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISoundTriggerHw::getProperties::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "getProperties", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSoundTriggerHw::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* getProperties */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        int32_t _hidl_out_retval;
        ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Properties* _hidl_out_properties;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_properties_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_properties), &_hidl__hidl_out_properties_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_properties)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Properties &>(*_hidl_out_properties),
                _hidl_reply,
                _hidl__hidl_out_properties_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, *_hidl_out_properties);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)_hidl_out_properties);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "getProperties", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwSoundTriggerHw::_hidl_loadSoundModel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::SoundModel& soundModel, const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>& callback, int32_t cookie, loadSoundModel_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISoundTriggerHw::loadSoundModel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&soundModel);
        _hidl_args.push_back((void *)&callback);
        _hidl_args.push_back((void *)&cookie);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "loadSoundModel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSoundTriggerHw::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_soundModel_parent;

    _hidl_err = _hidl_data.writeBuffer(&soundModel, sizeof(soundModel), &_hidl_soundModel_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            soundModel,
            &_hidl_data,
            _hidl_soundModel_parent,
            0 /* parentOffset */);

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

    _hidl_err = _hidl_data.writeInt32(cookie);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* loadSoundModel */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        int32_t _hidl_out_retval;
        int32_t _hidl_out_modelHandle;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_modelHandle);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_modelHandle);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_modelHandle);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "loadSoundModel", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwSoundTriggerHw::_hidl_loadPhraseSoundModel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::PhraseSoundModel& soundModel, const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>& callback, int32_t cookie, loadPhraseSoundModel_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISoundTriggerHw::loadPhraseSoundModel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&soundModel);
        _hidl_args.push_back((void *)&callback);
        _hidl_args.push_back((void *)&cookie);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "loadPhraseSoundModel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSoundTriggerHw::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_soundModel_parent;

    _hidl_err = _hidl_data.writeBuffer(&soundModel, sizeof(soundModel), &_hidl_soundModel_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            soundModel,
            &_hidl_data,
            _hidl_soundModel_parent,
            0 /* parentOffset */);

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

    _hidl_err = _hidl_data.writeInt32(cookie);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* loadPhraseSoundModel */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        int32_t _hidl_out_retval;
        int32_t _hidl_out_modelHandle;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt32(&_hidl_out_modelHandle);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_modelHandle);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_modelHandle);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "loadPhraseSoundModel", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<int32_t> BpHwSoundTriggerHw::_hidl_unloadSoundModel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t modelHandle) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISoundTriggerHw::unloadSoundModel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&modelHandle);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "unloadSoundModel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSoundTriggerHw::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(modelHandle);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* unloadSoundModel */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_retval);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_retval);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "unloadSoundModel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}

::android::hardware::Return<int32_t> BpHwSoundTriggerHw::_hidl_startRecognition(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t modelHandle, const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::RecognitionConfig& config, const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>& callback, int32_t cookie) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISoundTriggerHw::startRecognition::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&modelHandle);
        _hidl_args.push_back((void *)&config);
        _hidl_args.push_back((void *)&callback);
        _hidl_args.push_back((void *)&cookie);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "startRecognition", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSoundTriggerHw::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(modelHandle);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_config_parent;

    _hidl_err = _hidl_data.writeBuffer(&config, sizeof(config), &_hidl_config_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            config,
            &_hidl_data,
            _hidl_config_parent,
            0 /* parentOffset */);

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

    _hidl_err = _hidl_data.writeInt32(cookie);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* startRecognition */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_retval);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_retval);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "startRecognition", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}

::android::hardware::Return<int32_t> BpHwSoundTriggerHw::_hidl_stopRecognition(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t modelHandle) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISoundTriggerHw::stopRecognition::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&modelHandle);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "stopRecognition", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSoundTriggerHw::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(modelHandle);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* stopRecognition */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_retval);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_retval);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "stopRecognition", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}

::android::hardware::Return<int32_t> BpHwSoundTriggerHw::_hidl_stopAllRecognitions(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISoundTriggerHw::stopAllRecognitions::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "stopAllRecognitions", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    int32_t _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSoundTriggerHw::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* stopAllRecognitions */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_retval);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_retval);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "stopAllRecognitions", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<int32_t>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<int32_t>(_hidl_status);
}


// Methods from ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw follow.
::android::hardware::Return<void> BpHwSoundTriggerHw::getProperties(getProperties_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::soundtrigger::V2_0::BpHwSoundTriggerHw::_hidl_getProperties(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHw::loadSoundModel(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::SoundModel& soundModel, const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>& callback, int32_t cookie, loadSoundModel_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::soundtrigger::V2_0::BpHwSoundTriggerHw::_hidl_loadSoundModel(this, this, soundModel, callback, cookie, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHw::loadPhraseSoundModel(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::PhraseSoundModel& soundModel, const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>& callback, int32_t cookie, loadPhraseSoundModel_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::soundtrigger::V2_0::BpHwSoundTriggerHw::_hidl_loadPhraseSoundModel(this, this, soundModel, callback, cookie, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwSoundTriggerHw::unloadSoundModel(int32_t modelHandle){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::soundtrigger::V2_0::BpHwSoundTriggerHw::_hidl_unloadSoundModel(this, this, modelHandle);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwSoundTriggerHw::startRecognition(int32_t modelHandle, const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::RecognitionConfig& config, const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>& callback, int32_t cookie){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::soundtrigger::V2_0::BpHwSoundTriggerHw::_hidl_startRecognition(this, this, modelHandle, config, callback, cookie);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwSoundTriggerHw::stopRecognition(int32_t modelHandle){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::soundtrigger::V2_0::BpHwSoundTriggerHw::_hidl_stopRecognition(this, this, modelHandle);

    return _hidl_out;
}

::android::hardware::Return<int32_t> BpHwSoundTriggerHw::stopAllRecognitions(){
    ::android::hardware::Return<int32_t>  _hidl_out = ::android::hardware::soundtrigger::V2_0::BpHwSoundTriggerHw::_hidl_stopAllRecognitions(this, this);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwSoundTriggerHw::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHw::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHw::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHw::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHw::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwSoundTriggerHw::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwSoundTriggerHw::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHw::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSoundTriggerHw::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwSoundTriggerHw::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwSoundTriggerHw::BnHwSoundTriggerHw(const ::android::sp<ISoundTriggerHw> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.soundtrigger@2.0", "ISoundTriggerHw") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwSoundTriggerHw::~BnHwSoundTriggerHw() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw follow.
::android::status_t BnHwSoundTriggerHw::_hidl_getProperties(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSoundTriggerHw::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISoundTriggerHw::getProperties::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "getProperties", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISoundTriggerHw*>(_hidl_this->getImpl().get())->getProperties([&](const auto &_hidl_out_retval, const auto &_hidl_out_properties) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getProperties: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_properties_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_properties, sizeof(_hidl_out_properties), &_hidl__hidl_out_properties_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_properties,
                _hidl_reply,
                _hidl__hidl_out_properties_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_properties);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "getProperties", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getProperties: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSoundTriggerHw::_hidl_loadSoundModel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSoundTriggerHw::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::SoundModel* soundModel;
    ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback> callback;
    int32_t cookie;

    size_t _hidl_soundModel_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*soundModel), &_hidl_soundModel_parent,  const_cast<const void**>(reinterpret_cast<void **>(&soundModel)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::SoundModel &>(*soundModel),
            _hidl_data,
            _hidl_soundModel_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback,::android::hardware::soundtrigger::V2_0::BpHwSoundTriggerHwCallback,::android::hardware::soundtrigger::V2_0::BnHwSoundTriggerHwCallback>(_hidl_binder);
    }

    _hidl_err = _hidl_data.readInt32(&cookie);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISoundTriggerHw::loadSoundModel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)soundModel);
        _hidl_args.push_back((void *)&callback);
        _hidl_args.push_back((void *)&cookie);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "loadSoundModel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISoundTriggerHw*>(_hidl_this->getImpl().get())->loadSoundModel(*soundModel, callback, cookie, [&](const auto &_hidl_out_retval, const auto &_hidl_out_modelHandle) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("loadSoundModel: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_modelHandle);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_modelHandle);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "loadSoundModel", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("loadSoundModel: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSoundTriggerHw::_hidl_loadPhraseSoundModel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSoundTriggerHw::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::PhraseSoundModel* soundModel;
    ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback> callback;
    int32_t cookie;

    size_t _hidl_soundModel_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*soundModel), &_hidl_soundModel_parent,  const_cast<const void**>(reinterpret_cast<void **>(&soundModel)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::PhraseSoundModel &>(*soundModel),
            _hidl_data,
            _hidl_soundModel_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback,::android::hardware::soundtrigger::V2_0::BpHwSoundTriggerHwCallback,::android::hardware::soundtrigger::V2_0::BnHwSoundTriggerHwCallback>(_hidl_binder);
    }

    _hidl_err = _hidl_data.readInt32(&cookie);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISoundTriggerHw::loadPhraseSoundModel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)soundModel);
        _hidl_args.push_back((void *)&callback);
        _hidl_args.push_back((void *)&cookie);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "loadPhraseSoundModel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISoundTriggerHw*>(_hidl_this->getImpl().get())->loadPhraseSoundModel(*soundModel, callback, cookie, [&](const auto &_hidl_out_retval, const auto &_hidl_out_modelHandle) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("loadPhraseSoundModel: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_modelHandle);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_modelHandle);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "loadPhraseSoundModel", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("loadPhraseSoundModel: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSoundTriggerHw::_hidl_unloadSoundModel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSoundTriggerHw::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t modelHandle;

    _hidl_err = _hidl_data.readInt32(&modelHandle);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISoundTriggerHw::unloadSoundModel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&modelHandle);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "unloadSoundModel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_retval = static_cast<ISoundTriggerHw*>(_hidl_this->getImpl().get())->unloadSoundModel(modelHandle);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_retval);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_retval);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "unloadSoundModel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwSoundTriggerHw::_hidl_startRecognition(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSoundTriggerHw::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t modelHandle;
    ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::RecognitionConfig* config;
    ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback> callback;
    int32_t cookie;

    _hidl_err = _hidl_data.readInt32(&modelHandle);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_config_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*config), &_hidl_config_parent,  const_cast<const void**>(reinterpret_cast<void **>(&config)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::RecognitionConfig &>(*config),
            _hidl_data,
            _hidl_config_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback,::android::hardware::soundtrigger::V2_0::BpHwSoundTriggerHwCallback,::android::hardware::soundtrigger::V2_0::BnHwSoundTriggerHwCallback>(_hidl_binder);
    }

    _hidl_err = _hidl_data.readInt32(&cookie);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISoundTriggerHw::startRecognition::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&modelHandle);
        _hidl_args.push_back((void *)config);
        _hidl_args.push_back((void *)&callback);
        _hidl_args.push_back((void *)&cookie);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "startRecognition", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_retval = static_cast<ISoundTriggerHw*>(_hidl_this->getImpl().get())->startRecognition(modelHandle, *config, callback, cookie);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_retval);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_retval);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "startRecognition", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwSoundTriggerHw::_hidl_stopRecognition(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSoundTriggerHw::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t modelHandle;

    _hidl_err = _hidl_data.readInt32(&modelHandle);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISoundTriggerHw::stopRecognition::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&modelHandle);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "stopRecognition", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_retval = static_cast<ISoundTriggerHw*>(_hidl_this->getImpl().get())->stopRecognition(modelHandle);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_retval);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_retval);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "stopRecognition", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwSoundTriggerHw::_hidl_stopAllRecognitions(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSoundTriggerHw::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISoundTriggerHw::stopAllRecognitions::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "stopAllRecognitions", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    int32_t _hidl_out_retval = static_cast<ISoundTriggerHw*>(_hidl_this->getImpl().get())->stopAllRecognitions();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32(_hidl_out_retval);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_retval);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.soundtrigger", "2.0", "ISoundTriggerHw", "stopAllRecognitions", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwSoundTriggerHw::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwSoundTriggerHw::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwSoundTriggerHw::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* getProperties */:
        {
            _hidl_err = ::android::hardware::soundtrigger::V2_0::BnHwSoundTriggerHw::_hidl_getProperties(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* loadSoundModel */:
        {
            _hidl_err = ::android::hardware::soundtrigger::V2_0::BnHwSoundTriggerHw::_hidl_loadSoundModel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* loadPhraseSoundModel */:
        {
            _hidl_err = ::android::hardware::soundtrigger::V2_0::BnHwSoundTriggerHw::_hidl_loadPhraseSoundModel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* unloadSoundModel */:
        {
            _hidl_err = ::android::hardware::soundtrigger::V2_0::BnHwSoundTriggerHw::_hidl_unloadSoundModel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* startRecognition */:
        {
            _hidl_err = ::android::hardware::soundtrigger::V2_0::BnHwSoundTriggerHw::_hidl_startRecognition(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* stopRecognition */:
        {
            _hidl_err = ::android::hardware::soundtrigger::V2_0::BnHwSoundTriggerHw::_hidl_stopRecognition(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* stopAllRecognitions */:
        {
            _hidl_err = ::android::hardware::soundtrigger::V2_0::BnHwSoundTriggerHw::_hidl_stopAllRecognitions(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsSoundTriggerHw::BsSoundTriggerHw(const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHw> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.soundtrigger@2.0", "ISoundTriggerHw"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsSoundTriggerHw::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ISoundTriggerHw> ISoundTriggerHw::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwSoundTriggerHw>(serviceName, false, getStub);
}

::android::sp<ISoundTriggerHw> ISoundTriggerHw::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwSoundTriggerHw>(serviceName, true, getStub);
}

::android::status_t ISoundTriggerHw::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ISoundTriggerHw::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.soundtrigger@2.0::ISoundTriggerHw",
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
