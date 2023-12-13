#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

class ICameraServiceListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(CameraServiceListener)
  enum  : int32_t {
    STATUS_NOT_PRESENT = 0,
    STATUS_PRESENT = 1,
    STATUS_ENUMERATING = 2,
    STATUS_NOT_AVAILABLE = -2,
    STATUS_UNKNOWN = -1,
    TORCH_STATUS_NOT_AVAILABLE = 0,
    TORCH_STATUS_AVAILABLE_OFF = 1,
    TORCH_STATUS_AVAILABLE_ON = 2,
    TORCH_STATUS_UNKNOWN = -1,
  };
  virtual ::android::binder::Status onStatusChanged(int32_t status, const ::android::String16& cameraId) = 0;
  virtual ::android::binder::Status onPhysicalCameraStatusChanged(int32_t status, const ::android::String16& cameraId, const ::android::String16& physicalCameraId) = 0;
  virtual ::android::binder::Status onTorchStatusChanged(int32_t status, const ::android::String16& cameraId) = 0;
  virtual ::android::binder::Status onCameraAccessPrioritiesChanged() = 0;
  virtual ::android::binder::Status onCameraOpened(const ::android::String16& cameraId, const ::android::String16& clientPackageId) = 0;
  virtual ::android::binder::Status onCameraClosed(const ::android::String16& cameraId) = 0;
};  // class ICameraServiceListener

class ICameraServiceListenerDefault : public ICameraServiceListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onStatusChanged(int32_t, const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onPhysicalCameraStatusChanged(int32_t, const ::android::String16&, const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onTorchStatusChanged(int32_t, const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onCameraAccessPrioritiesChanged() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onCameraOpened(const ::android::String16&, const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onCameraClosed(const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICameraServiceListenerDefault

}  // namespace hardware

}  // namespace android
