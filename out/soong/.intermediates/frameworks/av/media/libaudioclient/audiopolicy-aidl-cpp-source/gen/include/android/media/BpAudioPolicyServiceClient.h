#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/IAudioPolicyServiceClient.h>

namespace android {

namespace media {

class BpAudioPolicyServiceClient : public ::android::BpInterface<IAudioPolicyServiceClient> {
public:
  explicit BpAudioPolicyServiceClient(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpAudioPolicyServiceClient() = default;
  ::android::binder::Status onAudioVolumeGroupChanged(int32_t group, int32_t flags) override;
  ::android::binder::Status onAudioPortListUpdate() override;
  ::android::binder::Status onAudioPatchListUpdate() override;
  ::android::binder::Status onDynamicPolicyMixStateUpdate(const ::std::string& regId, int32_t state) override;
  ::android::binder::Status onRecordingConfigurationUpdate(int32_t event, const ::android::media::RecordClientInfo& clientInfo, const ::android::media::AudioConfigBase& clientConfig, const ::std::vector<::android::media::EffectDescriptor>& clientEffects, const ::android::media::AudioConfigBase& deviceConfig, const ::std::vector<::android::media::EffectDescriptor>& effects, int32_t patchHandle, ::android::media::AudioSourceType source) override;
  ::android::binder::Status onRoutingUpdated() override;
};  // class BpAudioPolicyServiceClient

}  // namespace media

}  // namespace android
