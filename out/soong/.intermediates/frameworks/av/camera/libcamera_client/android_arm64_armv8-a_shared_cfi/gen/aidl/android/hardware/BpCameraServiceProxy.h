#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/ICameraServiceProxy.h>

namespace android {

namespace hardware {

class BpCameraServiceProxy : public ::android::BpInterface<ICameraServiceProxy> {
public:
  explicit BpCameraServiceProxy(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCameraServiceProxy() = default;
  ::android::binder::Status pingForUserUpdate() override;
  ::android::binder::Status notifyCameraState(const ::android::hardware::CameraSessionStats& cameraSessionStats) override;
  ::android::binder::Status getRotateAndCropOverride(const ::android::String16& packageName, int32_t lensFacing, int32_t userId, int32_t* _aidl_return) override;
};  // class BpCameraServiceProxy

}  // namespace hardware

}  // namespace android
