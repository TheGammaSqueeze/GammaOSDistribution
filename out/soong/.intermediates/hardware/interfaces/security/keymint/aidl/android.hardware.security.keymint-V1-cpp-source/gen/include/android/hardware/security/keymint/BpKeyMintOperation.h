#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/security/keymint/IKeyMintOperation.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

class BpKeyMintOperation : public ::android::BpInterface<IKeyMintOperation> {
public:
  explicit BpKeyMintOperation(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpKeyMintOperation() = default;
  ::android::binder::Status updateAad(const ::std::vector<uint8_t>& input, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>& authToken, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>& timeStampToken) override;
  ::android::binder::Status update(const ::std::vector<uint8_t>& input, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>& authToken, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>& timeStampToken, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status finish(const ::std::optional<::std::vector<uint8_t>>& input, const ::std::optional<::std::vector<uint8_t>>& signature, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>& authToken, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>& timestampToken, const ::std::optional<::std::vector<uint8_t>>& confirmationToken, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status abort() override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpKeyMintOperation

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
