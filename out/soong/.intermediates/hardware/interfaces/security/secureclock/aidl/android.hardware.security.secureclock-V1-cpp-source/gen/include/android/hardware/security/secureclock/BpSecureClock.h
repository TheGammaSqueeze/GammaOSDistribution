#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/security/secureclock/ISecureClock.h>

namespace android {

namespace hardware {

namespace security {

namespace secureclock {

class BpSecureClock : public ::android::BpInterface<ISecureClock> {
public:
  explicit BpSecureClock(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpSecureClock() = default;
  ::android::binder::Status generateTimeStamp(int64_t challenge, ::android::hardware::security::secureclock::TimeStampToken* _aidl_return) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpSecureClock

}  // namespace secureclock

}  // namespace security

}  // namespace hardware

}  // namespace android
