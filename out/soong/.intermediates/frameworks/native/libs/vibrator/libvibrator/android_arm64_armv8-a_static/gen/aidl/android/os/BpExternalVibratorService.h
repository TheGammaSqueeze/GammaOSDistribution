#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IExternalVibratorService.h>

namespace android {

namespace os {

class BpExternalVibratorService : public ::android::BpInterface<IExternalVibratorService> {
public:
  explicit BpExternalVibratorService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpExternalVibratorService() = default;
  ::android::binder::Status onExternalVibrationStart(const ::android::os::ExternalVibration& vib, int32_t* _aidl_return) override;
  ::android::binder::Status onExternalVibrationStop(const ::android::os::ExternalVibration& vib) override;
};  // class BpExternalVibratorService

}  // namespace os

}  // namespace android
