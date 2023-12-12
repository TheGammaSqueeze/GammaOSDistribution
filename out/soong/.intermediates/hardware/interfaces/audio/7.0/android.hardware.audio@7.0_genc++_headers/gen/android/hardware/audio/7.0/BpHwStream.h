#ifndef HIDL_GENERATED_ANDROID_HARDWARE_AUDIO_V7_0_BPHWSTREAM_H
#define HIDL_GENERATED_ANDROID_HARDWARE_AUDIO_V7_0_BPHWSTREAM_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/audio/7.0/IHwStream.h>

namespace android {
namespace hardware {
namespace audio {
namespace V7_0 {

struct BpHwStream : public ::android::hardware::BpInterface<IStream>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwStream(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IStream Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::android::hardware::audio::V7_0::IStream follow.
    static ::android::hardware::Return<uint64_t>  _hidl_getFrameSize(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<uint64_t>  _hidl_getFrameCount(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<uint64_t>  _hidl_getBufferSize(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_getSupportedProfiles(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getSupportedProfiles_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_getAudioProperties(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getAudioProperties_cb _hidl_cb);
    static ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_setAudioProperties(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional& config);
    static ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_addEffect(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t effectId);
    static ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_removeEffect(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t effectId);
    static ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_standby(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_getDevices(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getDevices_cb _hidl_cb);
    static ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_setDevices(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::DeviceAddress>& devices);
    static ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_setHwAvSync(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t hwAvSync);
    static ::android::hardware::Return<void>  _hidl_getParameters(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::audio::V7_0::ParameterValue>& context, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& keys, getParameters_cb _hidl_cb);
    static ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_setParameters(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::audio::V7_0::ParameterValue>& context, const ::android::hardware::hidl_vec<::android::hardware::audio::V7_0::ParameterValue>& parameters);
    static ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_start(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_stop(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_createMmapBuffer(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t minSizeFrames, createMmapBuffer_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_getMmapPosition(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getMmapPosition_cb _hidl_cb);
    static ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_close(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);

    // Methods from ::android::hardware::audio::V7_0::IStream follow.
    ::android::hardware::Return<uint64_t> getFrameSize() override;
    ::android::hardware::Return<uint64_t> getFrameCount() override;
    ::android::hardware::Return<uint64_t> getBufferSize() override;
    ::android::hardware::Return<void> getSupportedProfiles(getSupportedProfiles_cb _hidl_cb) override;
    ::android::hardware::Return<void> getAudioProperties(getAudioProperties_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result> setAudioProperties(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional& config) override;
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result> addEffect(uint64_t effectId) override;
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result> removeEffect(uint64_t effectId) override;
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result> standby() override;
    ::android::hardware::Return<void> getDevices(getDevices_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result> setDevices(const ::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::DeviceAddress>& devices) override;
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result> setHwAvSync(uint32_t hwAvSync) override;
    ::android::hardware::Return<void> getParameters(const ::android::hardware::hidl_vec<::android::hardware::audio::V7_0::ParameterValue>& context, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& keys, getParameters_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result> setParameters(const ::android::hardware::hidl_vec<::android::hardware::audio::V7_0::ParameterValue>& context, const ::android::hardware::hidl_vec<::android::hardware::audio::V7_0::ParameterValue>& parameters) override;
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result> start() override;
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result> stop() override;
    ::android::hardware::Return<void> createMmapBuffer(int32_t minSizeFrames, createMmapBuffer_cb _hidl_cb) override;
    ::android::hardware::Return<void> getMmapPosition(getMmapPosition_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result> close() override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;
    ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;
    ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> setHALInstrumentation() override;
    ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;
    ::android::hardware::Return<void> ping() override;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;
    ::android::hardware::Return<void> notifySyspropsChanged() override;
    ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

private:
    std::mutex _hidl_mMutex;
    std::vector<::android::sp<::android::hardware::hidl_binder_death_recipient>> _hidl_mDeathRecipients;
};

}  // namespace V7_0
}  // namespace audio
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_AUDIO_V7_0_BPHWSTREAM_H
