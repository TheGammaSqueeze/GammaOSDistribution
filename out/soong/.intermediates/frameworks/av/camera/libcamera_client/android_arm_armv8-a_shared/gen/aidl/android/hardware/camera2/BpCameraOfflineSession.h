#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/camera2/ICameraOfflineSession.h>

namespace android {

namespace hardware {

namespace camera2 {

class BpCameraOfflineSession : public ::android::BpInterface<ICameraOfflineSession> {
public:
  explicit BpCameraOfflineSession(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCameraOfflineSession() = default;
  ::android::binder::Status disconnect() override;
};  // class BpCameraOfflineSession

}  // namespace camera2

}  // namespace hardware

}  // namespace android
