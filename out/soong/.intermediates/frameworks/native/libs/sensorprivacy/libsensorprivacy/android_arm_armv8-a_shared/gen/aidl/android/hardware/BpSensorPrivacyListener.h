#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/ISensorPrivacyListener.h>

namespace android {

namespace hardware {

class BpSensorPrivacyListener : public ::android::BpInterface<ISensorPrivacyListener> {
public:
  explicit BpSensorPrivacyListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpSensorPrivacyListener() = default;
  ::android::binder::Status onSensorPrivacyChanged(bool enabled) override;
};  // class BpSensorPrivacyListener

}  // namespace hardware

}  // namespace android
