#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/gnss/IGnssMeasurementInterface.h>

namespace android {

namespace hardware {

namespace gnss {

class BpGnssMeasurementInterface : public ::android::BpInterface<IGnssMeasurementInterface> {
public:
  explicit BpGnssMeasurementInterface(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpGnssMeasurementInterface() = default;
  ::android::binder::Status setCallback(const ::android::sp<::android::hardware::gnss::IGnssMeasurementCallback>& callback, bool enableFullTracking, bool enableCorrVecOutputs) override;
  ::android::binder::Status close() override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpGnssMeasurementInterface

}  // namespace gnss

}  // namespace hardware

}  // namespace android
