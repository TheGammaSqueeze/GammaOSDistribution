#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/vibrator/IVibratorManager.h>

namespace android {

namespace hardware {

namespace vibrator {

class BpVibratorManager : public ::android::BpInterface<IVibratorManager> {
public:
  explicit BpVibratorManager(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpVibratorManager() = default;
  ::android::binder::Status getCapabilities(int32_t* _aidl_return) override;
  ::android::binder::Status getVibratorIds(::std::vector<int32_t>* _aidl_return) override;
  ::android::binder::Status getVibrator(int32_t vibratorId, ::android::sp<::android::hardware::vibrator::IVibrator>* _aidl_return) override;
  ::android::binder::Status prepareSynced(const ::std::vector<int32_t>& vibratorIds) override;
  ::android::binder::Status triggerSynced(const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback) override;
  ::android::binder::Status cancelSynced() override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpVibratorManager

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
