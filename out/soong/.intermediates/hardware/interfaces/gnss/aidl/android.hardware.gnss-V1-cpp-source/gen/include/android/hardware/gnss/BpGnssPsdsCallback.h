#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/gnss/IGnssPsdsCallback.h>

namespace android {

namespace hardware {

namespace gnss {

class BpGnssPsdsCallback : public ::android::BpInterface<IGnssPsdsCallback> {
public:
  explicit BpGnssPsdsCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpGnssPsdsCallback() = default;
  ::android::binder::Status downloadRequestCb(::android::hardware::gnss::PsdsType psdsType) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpGnssPsdsCallback

}  // namespace gnss

}  // namespace hardware

}  // namespace android
