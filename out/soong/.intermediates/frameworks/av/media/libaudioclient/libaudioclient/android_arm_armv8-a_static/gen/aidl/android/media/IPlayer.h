#pragma once

#include <android/media/VolumeShaperConfiguration.h>
#include <android/media/VolumeShaperOperation.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace media {

class IPlayer : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Player)
  virtual ::android::binder::Status start() = 0;
  virtual ::android::binder::Status pause() = 0;
  virtual ::android::binder::Status stop() = 0;
  virtual ::android::binder::Status setVolume(float vol) = 0;
  virtual ::android::binder::Status setPan(float pan) = 0;
  virtual ::android::binder::Status setStartDelayMs(int32_t delayMs) = 0;
  virtual ::android::binder::Status applyVolumeShaper(const ::android::media::VolumeShaperConfiguration& configuration, const ::android::media::VolumeShaperOperation& operation) = 0;
};  // class IPlayer

class IPlayerDefault : public IPlayer {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status start() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status pause() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stop() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setVolume(float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPan(float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setStartDelayMs(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status applyVolumeShaper(const ::android::media::VolumeShaperConfiguration&, const ::android::media::VolumeShaperOperation&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IPlayerDefault

}  // namespace media

}  // namespace android
