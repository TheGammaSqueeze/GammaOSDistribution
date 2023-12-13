#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/gnss/IGnssPowerIndication.h>

namespace android {

namespace hardware {

namespace gnss {

class BpGnssPowerIndication : public ::android::BpInterface<IGnssPowerIndication> {
public:
  explicit BpGnssPowerIndication(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpGnssPowerIndication() = default;
  ::android::binder::Status setCallback(const ::android::sp<::android::hardware::gnss::IGnssPowerIndicationCallback>& callback) override;
  ::android::binder::Status requestGnssPowerStats() override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpGnssPowerIndication

}  // namespace gnss

}  // namespace hardware

}  // namespace android
