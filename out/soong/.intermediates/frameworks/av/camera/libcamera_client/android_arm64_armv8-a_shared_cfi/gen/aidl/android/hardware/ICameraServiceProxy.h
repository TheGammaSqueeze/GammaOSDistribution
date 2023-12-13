#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <camera/CameraSessionStats.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

class ICameraServiceProxy : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(CameraServiceProxy)
  virtual ::android::binder::Status pingForUserUpdate() = 0;
  virtual ::android::binder::Status notifyCameraState(const ::android::hardware::CameraSessionStats& cameraSessionStats) = 0;
  virtual ::android::binder::Status getRotateAndCropOverride(const ::android::String16& packageName, int32_t lensFacing, int32_t userId, int32_t* _aidl_return) = 0;
};  // class ICameraServiceProxy

class ICameraServiceProxyDefault : public ICameraServiceProxy {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status pingForUserUpdate() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status notifyCameraState(const ::android::hardware::CameraSessionStats&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getRotateAndCropOverride(const ::android::String16&, int32_t, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICameraServiceProxyDefault

}  // namespace hardware

}  // namespace android
