#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/system/suspend/IWakelockCallback.h>

namespace android {

namespace system {

namespace suspend {

class BpWakelockCallback : public ::android::BpInterface<IWakelockCallback> {
public:
  explicit BpWakelockCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpWakelockCallback() = default;
  ::android::binder::Status notifyAcquired() override;
  ::android::binder::Status notifyReleased() override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpWakelockCallback

}  // namespace suspend

}  // namespace system

}  // namespace android
