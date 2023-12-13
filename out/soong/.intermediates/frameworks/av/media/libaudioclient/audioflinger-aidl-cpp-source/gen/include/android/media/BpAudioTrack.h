#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/IAudioTrack.h>

namespace android {

namespace media {

class BpAudioTrack : public ::android::BpInterface<IAudioTrack> {
public:
  explicit BpAudioTrack(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpAudioTrack() = default;
  ::android::binder::Status getCblk(::std::optional<::android::media::SharedFileRegion>* _aidl_return) override;
  ::android::binder::Status start(int32_t* _aidl_return) override;
  ::android::binder::Status stop() override;
  ::android::binder::Status flush() override;
  ::android::binder::Status pause() override;
  ::android::binder::Status attachAuxEffect(int32_t effectId, int32_t* _aidl_return) override;
  ::android::binder::Status setParameters(const ::std::string& keyValuePairs, int32_t* _aidl_return) override;
  ::android::binder::Status selectPresentation(int32_t presentationId, int32_t programId, int32_t* _aidl_return) override;
  ::android::binder::Status getTimestamp(::android::media::AudioTimestampInternal* timestamp, int32_t* _aidl_return) override;
  ::android::binder::Status signal() override;
  ::android::binder::Status applyVolumeShaper(const ::android::media::VolumeShaperConfiguration& configuration, const ::android::media::VolumeShaperOperation& operation, int32_t* _aidl_return) override;
  ::android::binder::Status getVolumeShaperState(int32_t id, ::std::optional<::android::media::VolumeShaperState>* _aidl_return) override;
  ::android::binder::Status getDualMonoMode(::android::media::AudioDualMonoMode* _aidl_return) override;
  ::android::binder::Status setDualMonoMode(::android::media::AudioDualMonoMode mode) override;
  ::android::binder::Status getAudioDescriptionMixLevel(float* _aidl_return) override;
  ::android::binder::Status setAudioDescriptionMixLevel(float leveldB) override;
  ::android::binder::Status getPlaybackRateParameters(::android::media::AudioPlaybackRate* _aidl_return) override;
  ::android::binder::Status setPlaybackRateParameters(const ::android::media::AudioPlaybackRate& playbackRate) override;
};  // class BpAudioTrack

}  // namespace media

}  // namespace android
