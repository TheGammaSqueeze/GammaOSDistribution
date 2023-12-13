#pragma once

#include <android/hardware/security/secureclock/TimeStampToken.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace security {

namespace secureclock {

class ISecureClock : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(SecureClock)
  const int32_t VERSION = 1;
  const std::string HASH = "cd55ca9963c6a57fa5f2f120a45c6e0c4fafb423";
  static const ::android::String16& TIME_STAMP_MAC_LABEL();
  virtual ::android::binder::Status generateTimeStamp(int64_t challenge, ::android::hardware::security::secureclock::TimeStampToken* _aidl_return) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class ISecureClock

class ISecureClockDefault : public ISecureClock {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status generateTimeStamp(int64_t, ::android::hardware::security::secureclock::TimeStampToken*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class ISecureClockDefault

}  // namespace secureclock

}  // namespace security

}  // namespace hardware

}  // namespace android
