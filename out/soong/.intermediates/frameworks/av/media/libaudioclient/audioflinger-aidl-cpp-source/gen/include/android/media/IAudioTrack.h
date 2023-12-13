#pragma once

#include <android/media/AudioDualMonoMode.h>
#include <android/media/AudioPlaybackRate.h>
#include <android/media/AudioTimestampInternal.h>
#include <android/media/SharedFileRegion.h>
#include <android/media/VolumeShaperConfiguration.h>
#include <android/media/VolumeShaperOperation.h>
#include <android/media/VolumeShaperState.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <string>
#include <utils/StrongPointer.h>

namespace android {

namespace media {

class IAudioTrack : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(AudioTrack)
  virtual ::android::binder::Status getCblk(::std::optional<::android::media::SharedFileRegion>* _aidl_return) = 0;
  virtual ::android::binder::Status start(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status stop() = 0;
  virtual ::android::binder::Status flush() = 0;
  virtual ::android::binder::Status pause() = 0;
  virtual ::android::binder::Status attachAuxEffect(int32_t effectId, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status setParameters(const ::std::string& keyValuePairs, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status selectPresentation(int32_t presentationId, int32_t programId, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getTimestamp(::android::media::AudioTimestampInternal* timestamp, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status signal() = 0;
  virtual ::android::binder::Status applyVolumeShaper(const ::android::media::VolumeShaperConfiguration& configuration, const ::android::media::VolumeShaperOperation& operation, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getVolumeShaperState(int32_t id, ::std::optional<::android::media::VolumeShaperState>* _aidl_return) = 0;
  virtual ::android::binder::Status getDualMonoMode(::android::media::AudioDualMonoMode* _aidl_return) = 0;
  virtual ::android::binder::Status setDualMonoMode(::android::media::AudioDualMonoMode mode) = 0;
  virtual ::android::binder::Status getAudioDescriptionMixLevel(float* _aidl_return) = 0;
  virtual ::android::binder::Status setAudioDescriptionMixLevel(float leveldB) = 0;
  virtual ::android::binder::Status getPlaybackRateParameters(::android::media::AudioPlaybackRate* _aidl_return) = 0;
  virtual ::android::binder::Status setPlaybackRateParameters(const ::android::media::AudioPlaybackRate& playbackRate) = 0;
};  // class IAudioTrack

class IAudioTrackDefault : public IAudioTrack {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getCblk(::std::optional<::android::media::SharedFileRegion>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status start(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stop() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status flush() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status pause() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status attachAuxEffect(int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setParameters(const ::std::string&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status selectPresentation(int32_t, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getTimestamp(::android::media::AudioTimestampInternal*, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status signal() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status applyVolumeShaper(const ::android::media::VolumeShaperConfiguration&, const ::android::media::VolumeShaperOperation&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getVolumeShaperState(int32_t, ::std::optional<::android::media::VolumeShaperState>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getDualMonoMode(::android::media::AudioDualMonoMode*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setDualMonoMode(::android::media::AudioDualMonoMode) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAudioDescriptionMixLevel(float*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAudioDescriptionMixLevel(float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPlaybackRateParameters(::android::media::AudioPlaybackRate*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPlaybackRateParameters(const ::android::media::AudioPlaybackRate&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IAudioTrackDefault

}  // namespace media

}  // namespace android
