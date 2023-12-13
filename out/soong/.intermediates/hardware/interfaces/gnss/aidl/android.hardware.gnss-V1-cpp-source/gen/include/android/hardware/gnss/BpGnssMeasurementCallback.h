#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/gnss/IGnssMeasurementCallback.h>

namespace android {

namespace hardware {

namespace gnss {

class BpGnssMeasurementCallback : public ::android::BpInterface<IGnssMeasurementCallback> {
public:
  explicit BpGnssMeasurementCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpGnssMeasurementCallback() = default;
  ::android::binder::Status gnssMeasurementCb(const ::android::hardware::gnss::GnssData& data) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpGnssMeasurementCallback

}  // namespace gnss

}  // namespace hardware

}  // namespace android
