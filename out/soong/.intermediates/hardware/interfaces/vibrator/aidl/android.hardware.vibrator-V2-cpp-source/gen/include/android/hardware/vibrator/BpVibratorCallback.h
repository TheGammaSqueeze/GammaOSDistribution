#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/vibrator/IVibratorCallback.h>

namespace android {

namespace hardware {

namespace vibrator {

class BpVibratorCallback : public ::android::BpInterface<IVibratorCallback> {
public:
  explicit BpVibratorCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpVibratorCallback() = default;
  ::android::binder::Status onComplete() override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpVibratorCallback

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
