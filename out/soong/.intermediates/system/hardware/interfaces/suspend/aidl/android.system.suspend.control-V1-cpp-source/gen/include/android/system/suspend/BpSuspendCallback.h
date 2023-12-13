#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/system/suspend/ISuspendCallback.h>

namespace android {

namespace system {

namespace suspend {

class BpSuspendCallback : public ::android::BpInterface<ISuspendCallback> {
public:
  explicit BpSuspendCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpSuspendCallback() = default;
  ::android::binder::Status notifyWakeup(bool success, const ::std::vector<::std::string>& wakeupReasons) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpSuspendCallback

}  // namespace suspend

}  // namespace system

}  // namespace android
