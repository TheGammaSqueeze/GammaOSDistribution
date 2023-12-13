#pragma once

#include <android/hardware/security/keymint/HardwareAuthToken.h>
#include <android/hardware/security/secureclock/TimeStampToken.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

class IKeyMintOperation : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(KeyMintOperation)
  const int32_t VERSION = 1;
  const std::string HASH = "976674616001f714f4a4df49ee45f548de828524";
  virtual ::android::binder::Status updateAad(const ::std::vector<uint8_t>& input, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>& authToken, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>& timeStampToken) = 0;
  virtual ::android::binder::Status update(const ::std::vector<uint8_t>& input, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>& authToken, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>& timeStampToken, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status finish(const ::std::optional<::std::vector<uint8_t>>& input, const ::std::optional<::std::vector<uint8_t>>& signature, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>& authToken, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>& timestampToken, const ::std::optional<::std::vector<uint8_t>>& confirmationToken, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status abort() = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IKeyMintOperation

class IKeyMintOperationDefault : public IKeyMintOperation {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status updateAad(const ::std::vector<uint8_t>&, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>&, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status update(const ::std::vector<uint8_t>&, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>&, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>&, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status finish(const ::std::optional<::std::vector<uint8_t>>&, const ::std::optional<::std::vector<uint8_t>>&, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>&, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>&, const ::std::optional<::std::vector<uint8_t>>&, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status abort() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IKeyMintOperationDefault

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
