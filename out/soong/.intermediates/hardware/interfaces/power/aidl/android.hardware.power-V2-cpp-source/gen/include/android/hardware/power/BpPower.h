#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/power/IPower.h>

namespace android {

namespace hardware {

namespace power {

class BpPower : public ::android::BpInterface<IPower> {
public:
  explicit BpPower(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpPower() = default;
  ::android::binder::Status setMode(::android::hardware::power::Mode type, bool enabled) override;
  ::android::binder::Status isModeSupported(::android::hardware::power::Mode type, bool* _aidl_return) override;
  ::android::binder::Status setBoost(::android::hardware::power::Boost type, int32_t durationMs) override;
  ::android::binder::Status isBoostSupported(::android::hardware::power::Boost type, bool* _aidl_return) override;
  ::android::binder::Status createHintSession(int32_t tgid, int32_t uid, const ::std::vector<int32_t>& threadIds, int64_t durationNanos, ::android::sp<::android::hardware::power::IPowerHintSession>* _aidl_return) override;
  ::android::binder::Status getHintSessionPreferredRate(int64_t* _aidl_return) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpPower

}  // namespace power

}  // namespace hardware

}  // namespace android
