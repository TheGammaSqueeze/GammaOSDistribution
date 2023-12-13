#pragma once

#include <binder/IInterface.h>
#include <android/media/IAudioPolicyServiceClient.h>

namespace android {

namespace media {

class BnAudioPolicyServiceClient : public ::android::BnInterface<IAudioPolicyServiceClient> {
public:
  static constexpr uint32_t TRANSACTION_onAudioVolumeGroupChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onAudioPortListUpdate = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onAudioPatchListUpdate = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onDynamicPolicyMixStateUpdate = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onRecordingConfigurationUpdate = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_onRoutingUpdated = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  explicit BnAudioPolicyServiceClient();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnAudioPolicyServiceClient

}  // namespace media

}  // namespace android
