#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/system/keystore2/IKeystoreOperation.h>

namespace android {

namespace system {

namespace keystore2 {

class BpKeystoreOperation : public ::android::BpInterface<IKeystoreOperation> {
public:
  explicit BpKeystoreOperation(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpKeystoreOperation() = default;
  ::android::binder::Status updateAad(const ::std::vector<uint8_t>& aadInput) override;
  ::android::binder::Status update(const ::std::vector<uint8_t>& input, ::std::optional<::std::vector<uint8_t>>* _aidl_return) override;
  ::android::binder::Status finish(const ::std::optional<::std::vector<uint8_t>>& input, const ::std::optional<::std::vector<uint8_t>>& signature, ::std::optional<::std::vector<uint8_t>>* _aidl_return) override;
  ::android::binder::Status abort() override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpKeystoreOperation

}  // namespace keystore2

}  // namespace system

}  // namespace android
