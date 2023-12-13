#pragma once

#include <android/media/SpatializerHeadTrackingMode.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace media {

class ISpatializerHeadTrackingCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(SpatializerHeadTrackingCallback)
  virtual ::android::binder::Status onHeadTrackingModeChanged(::android::media::SpatializerHeadTrackingMode mode) = 0;
  virtual ::android::binder::Status onHeadToSoundStagePoseUpdated(const ::std::vector<float>& headToStage) = 0;
};  // class ISpatializerHeadTrackingCallback

class ISpatializerHeadTrackingCallbackDefault : public ISpatializerHeadTrackingCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onHeadTrackingModeChanged(::android::media::SpatializerHeadTrackingMode) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onHeadToSoundStagePoseUpdated(const ::std::vector<float>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ISpatializerHeadTrackingCallbackDefault

}  // namespace media

}  // namespace android
