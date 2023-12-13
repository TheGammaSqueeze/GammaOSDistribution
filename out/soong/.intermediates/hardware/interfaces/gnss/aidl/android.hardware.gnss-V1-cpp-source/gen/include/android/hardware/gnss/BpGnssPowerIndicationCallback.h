#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/gnss/IGnssPowerIndicationCallback.h>

namespace android {

namespace hardware {

namespace gnss {

class BpGnssPowerIndicationCallback : public ::android::BpInterface<IGnssPowerIndicationCallback> {
public:
  explicit BpGnssPowerIndicationCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpGnssPowerIndicationCallback() = default;
  ::android::binder::Status setCapabilitiesCb(int32_t capabilities) override;
  ::android::binder::Status gnssPowerStatsCb(const ::android::hardware::gnss::GnssPowerStats& gnssPowerStats) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpGnssPowerIndicationCallback

}  // namespace gnss

}  // namespace hardware

}  // namespace android
