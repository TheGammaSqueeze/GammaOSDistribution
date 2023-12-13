#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/system/suspend/ISuspendControlService.h>

namespace android {

namespace system {

namespace suspend {

class BpSuspendControlService : public ::android::BpInterface<ISuspendControlService> {
public:
  explicit BpSuspendControlService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpSuspendControlService() = default;
  ::android::binder::Status registerCallback(const ::android::sp<::android::system::suspend::ISuspendCallback>& callback, bool* _aidl_return) override;
  ::android::binder::Status registerWakelockCallback(const ::android::sp<::android::system::suspend::IWakelockCallback>& callback, const ::std::string& name, bool* _aidl_return) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpSuspendControlService

}  // namespace suspend

}  // namespace system

}  // namespace android
