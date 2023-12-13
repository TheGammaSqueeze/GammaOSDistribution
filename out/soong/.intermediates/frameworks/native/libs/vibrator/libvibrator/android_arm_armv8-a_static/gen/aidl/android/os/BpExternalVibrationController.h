#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IExternalVibrationController.h>

namespace android {

namespace os {

class BpExternalVibrationController : public ::android::BpInterface<IExternalVibrationController> {
public:
  explicit BpExternalVibrationController(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpExternalVibrationController() = default;
  ::android::binder::Status mute(bool* _aidl_return) override;
  ::android::binder::Status unmute(bool* _aidl_return) override;
};  // class BpExternalVibrationController

}  // namespace os

}  // namespace android
