#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/camera2/ICameraInjectionSession.h>

namespace android {

namespace hardware {

namespace camera2 {

class BpCameraInjectionSession : public ::android::BpInterface<ICameraInjectionSession> {
public:
  explicit BpCameraInjectionSession(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCameraInjectionSession() = default;
  ::android::binder::Status stopInjection() override;
};  // class BpCameraInjectionSession

}  // namespace camera2

}  // namespace hardware

}  // namespace android
