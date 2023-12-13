#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/IPlayer.h>

namespace android {

namespace media {

class BpPlayer : public ::android::BpInterface<IPlayer> {
public:
  explicit BpPlayer(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpPlayer() = default;
  ::android::binder::Status start() override;
  ::android::binder::Status pause() override;
  ::android::binder::Status stop() override;
  ::android::binder::Status setVolume(float vol) override;
  ::android::binder::Status setPan(float pan) override;
  ::android::binder::Status setStartDelayMs(int32_t delayMs) override;
  ::android::binder::Status applyVolumeShaper(const ::android::media::VolumeShaperConfiguration& configuration, const ::android::media::VolumeShaperOperation& operation) override;
};  // class BpPlayer

}  // namespace media

}  // namespace android
