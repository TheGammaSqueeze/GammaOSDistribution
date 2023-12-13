#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/camera2/ICameraInjectionCallback.h>

namespace android {

namespace hardware {

namespace camera2 {

class BpCameraInjectionCallback : public ::android::BpInterface<ICameraInjectionCallback> {
public:
  explicit BpCameraInjectionCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCameraInjectionCallback() = default;
  ::android::binder::Status onInjectionError(int32_t errorCode) override;
};  // class BpCameraInjectionCallback

}  // namespace camera2

}  // namespace hardware

}  // namespace android
