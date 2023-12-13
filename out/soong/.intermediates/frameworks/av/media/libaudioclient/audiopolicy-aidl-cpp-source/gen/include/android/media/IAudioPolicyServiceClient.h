#pragma once

#include <android/media/AudioConfigBase.h>
#include <android/media/AudioSourceType.h>
#include <android/media/EffectDescriptor.h>
#include <android/media/RecordClientInfo.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace media {

class IAudioPolicyServiceClient : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(AudioPolicyServiceClient)
  virtual ::android::binder::Status onAudioVolumeGroupChanged(int32_t group, int32_t flags) = 0;
  virtual ::android::binder::Status onAudioPortListUpdate() = 0;
  virtual ::android::binder::Status onAudioPatchListUpdate() = 0;
  virtual ::android::binder::Status onDynamicPolicyMixStateUpdate(const ::std::string& regId, int32_t state) = 0;
  virtual ::android::binder::Status onRecordingConfigurationUpdate(int32_t event, const ::android::media::RecordClientInfo& clientInfo, const ::android::media::AudioConfigBase& clientConfig, const ::std::vector<::android::media::EffectDescriptor>& clientEffects, const ::android::media::AudioConfigBase& deviceConfig, const ::std::vector<::android::media::EffectDescriptor>& effects, int32_t patchHandle, ::android::media::AudioSourceType source) = 0;
  virtual ::android::binder::Status onRoutingUpdated() = 0;
};  // class IAudioPolicyServiceClient

class IAudioPolicyServiceClientDefault : public IAudioPolicyServiceClient {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onAudioVolumeGroupChanged(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onAudioPortListUpdate() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onAudioPatchListUpdate() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onDynamicPolicyMixStateUpdate(const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onRecordingConfigurationUpdate(int32_t, const ::android::media::RecordClientInfo&, const ::android::media::AudioConfigBase&, const ::std::vector<::android::media::EffectDescriptor>&, const ::android::media::AudioConfigBase&, const ::std::vector<::android::media::EffectDescriptor>&, int32_t, ::android::media::AudioSourceType) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onRoutingUpdated() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IAudioPolicyServiceClientDefault

}  // namespace media

}  // namespace android
