#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/gnss/IGnss.h>

namespace android {

namespace hardware {

namespace gnss {

class BpGnss : public ::android::BpInterface<IGnss> {
public:
  explicit BpGnss(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpGnss() = default;
  ::android::binder::Status setCallback(const ::android::sp<::android::hardware::gnss::IGnssCallback>& callback) override;
  ::android::binder::Status close() override;
  ::android::binder::Status getExtensionPsds(::android::sp<::android::hardware::gnss::IGnssPsds>* _aidl_return) override;
  ::android::binder::Status getExtensionGnssConfiguration(::android::sp<::android::hardware::gnss::IGnssConfiguration>* _aidl_return) override;
  ::android::binder::Status getExtensionGnssMeasurement(::android::sp<::android::hardware::gnss::IGnssMeasurementInterface>* _aidl_return) override;
  ::android::binder::Status getExtensionGnssPowerIndication(::android::sp<::android::hardware::gnss::IGnssPowerIndication>* _aidl_return) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpGnss

}  // namespace gnss

}  // namespace hardware

}  // namespace android
