#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace system {

namespace keystore2 {

class IKeystoreOperation : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(KeystoreOperation)
  const int32_t VERSION = 1;
  const std::string HASH = "19e8b65277839bad0ab335c781e3c652324920ce";
  virtual ::android::binder::Status updateAad(const ::std::vector<uint8_t>& aadInput) = 0;
  virtual ::android::binder::Status update(const ::std::vector<uint8_t>& input, ::std::optional<::std::vector<uint8_t>>* _aidl_return) = 0;
  virtual ::android::binder::Status finish(const ::std::optional<::std::vector<uint8_t>>& input, const ::std::optional<::std::vector<uint8_t>>& signature, ::std::optional<::std::vector<uint8_t>>* _aidl_return) = 0;
  virtual ::android::binder::Status abort() = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IKeystoreOperation

class IKeystoreOperationDefault : public IKeystoreOperation {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status updateAad(const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status update(const ::std::vector<uint8_t>&, ::std::optional<::std::vector<uint8_t>>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status finish(const ::std::optional<::std::vector<uint8_t>>&, const ::std::optional<::std::vector<uint8_t>>&, ::std::optional<::std::vector<uint8_t>>*) override {
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
};  // class IKeystoreOperationDefault

}  // namespace keystore2

}  // namespace system

}  // namespace android
