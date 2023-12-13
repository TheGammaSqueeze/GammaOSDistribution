#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/ICameraServiceListener.h>

namespace android {

namespace hardware {

class BpCameraServiceListener : public ::android::BpInterface<ICameraServiceListener> {
public:
  explicit BpCameraServiceListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCameraServiceListener() = default;
  ::android::binder::Status onStatusChanged(int32_t status, const ::android::String16& cameraId) override;
  ::android::binder::Status onPhysicalCameraStatusChanged(int32_t status, const ::android::String16& cameraId, const ::android::String16& physicalCameraId) override;
  ::android::binder::Status onTorchStatusChanged(int32_t status, const ::android::String16& cameraId) override;
  ::android::binder::Status onCameraAccessPrioritiesChanged() override;
  ::android::binder::Status onCameraOpened(const ::android::String16& cameraId, const ::android::String16& clientPackageId) override;
  ::android::binder::Status onCameraClosed(const ::android::String16& cameraId) override;
};  // class BpCameraServiceListener

}  // namespace hardware

}  // namespace android
