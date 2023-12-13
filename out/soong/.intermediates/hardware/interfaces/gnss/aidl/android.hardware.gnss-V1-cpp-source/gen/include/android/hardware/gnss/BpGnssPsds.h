#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/gnss/IGnssPsds.h>

namespace android {

namespace hardware {

namespace gnss {

class BpGnssPsds : public ::android::BpInterface<IGnssPsds> {
public:
  explicit BpGnssPsds(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpGnssPsds() = default;
  ::android::binder::Status injectPsdsData(::android::hardware::gnss::PsdsType psdsType, const ::std::vector<uint8_t>& psdsData) override;
  ::android::binder::Status setCallback(const ::android::sp<::android::hardware::gnss::IGnssPsdsCallback>& callback) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpGnssPsds

}  // namespace gnss

}  // namespace hardware

}  // namespace android
