#pragma once

#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
#include <aidl/android/security/apc/ResponseCode.h>

namespace aidl {
namespace android {
namespace security {
namespace apc {
class IConfirmationCallback : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IConfirmationCallback();
  virtual ~IConfirmationCallback();

  static constexpr uint32_t TRANSACTION_onCompleted = FIRST_CALL_TRANSACTION + 0;

  static std::shared_ptr<IConfirmationCallback> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IConfirmationCallback>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IConfirmationCallback>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IConfirmationCallback>& impl);
  static const std::shared_ptr<IConfirmationCallback>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onCompleted(::aidl::android::security::apc::ResponseCode in_result, const std::optional<std::vector<uint8_t>>& in_dataConfirmed) = 0;
private:
  static std::shared_ptr<IConfirmationCallback> default_impl;
};
class IConfirmationCallbackDefault : public IConfirmationCallback {
public:
  ::ndk::ScopedAStatus onCompleted(::aidl::android::security::apc::ResponseCode in_result, const std::optional<std::vector<uint8_t>>& in_dataConfirmed) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace apc
}  // namespace security
}  // namespace android
}  // namespace aidl
