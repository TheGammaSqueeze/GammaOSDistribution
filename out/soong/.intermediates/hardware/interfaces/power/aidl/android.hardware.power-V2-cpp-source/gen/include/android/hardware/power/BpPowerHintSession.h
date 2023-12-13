#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/power/IPowerHintSession.h>

namespace android {

namespace hardware {

namespace power {

class BpPowerHintSession : public ::android::BpInterface<IPowerHintSession> {
public:
  explicit BpPowerHintSession(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpPowerHintSession() = default;
  ::android::binder::Status updateTargetWorkDuration(int64_t targetDurationNanos) override;
  ::android::binder::Status reportActualWorkDuration(const ::std::vector<::android::hardware::power::WorkDuration>& durations) override;
  ::android::binder::Status pause() override;
  ::android::binder::Status resume() override;
  ::android::binder::Status close() override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpPowerHintSession

}  // namespace power

}  // namespace hardware

}  // namespace android
