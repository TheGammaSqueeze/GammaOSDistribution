#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/ISpatializerHeadTrackingCallback.h>

namespace android {

namespace media {

class BpSpatializerHeadTrackingCallback : public ::android::BpInterface<ISpatializerHeadTrackingCallback> {
public:
  explicit BpSpatializerHeadTrackingCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpSpatializerHeadTrackingCallback() = default;
  ::android::binder::Status onHeadTrackingModeChanged(::android::media::SpatializerHeadTrackingMode mode) override;
  ::android::binder::Status onHeadToSoundStagePoseUpdated(const ::std::vector<float>& headToStage) override;
};  // class BpSpatializerHeadTrackingCallback

}  // namespace media

}  // namespace android
