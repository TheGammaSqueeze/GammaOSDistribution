#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/gnss/IGnssCallback.h>

namespace android {

namespace hardware {

namespace gnss {

class BpGnssCallback : public ::android::BpInterface<IGnssCallback> {
public:
  explicit BpGnssCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpGnssCallback() = default;
  ::android::binder::Status gnssSetCapabilitiesCb(int32_t capabilities) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpGnssCallback

}  // namespace gnss

}  // namespace hardware

}  // namespace android
