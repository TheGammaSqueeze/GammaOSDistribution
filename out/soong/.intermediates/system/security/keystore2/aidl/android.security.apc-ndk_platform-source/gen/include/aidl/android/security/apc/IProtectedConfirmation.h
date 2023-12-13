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
#include <aidl/android/security/apc/IConfirmationCallback.h>

namespace aidl {
namespace android {
namespace security {
namespace apc {
class IProtectedConfirmation : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IProtectedConfirmation();
  virtual ~IProtectedConfirmation();

  enum : int32_t { FLAG_UI_OPTION_INVERTED = 1 };
  enum : int32_t { FLAG_UI_OPTION_MAGNIFIED = 2 };
  static constexpr uint32_t TRANSACTION_presentPrompt = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_cancelPrompt = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_isSupported = FIRST_CALL_TRANSACTION + 2;

  static std::shared_ptr<IProtectedConfirmation> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IProtectedConfirmation>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IProtectedConfirmation>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IProtectedConfirmation>& impl);
  static const std::shared_ptr<IProtectedConfirmation>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus presentPrompt(const std::shared_ptr<::aidl::android::security::apc::IConfirmationCallback>& in_listener, const std::string& in_promptText, const std::vector<uint8_t>& in_extraData, const std::string& in_locale, int32_t in_uiOptionFlags) = 0;
  virtual ::ndk::ScopedAStatus cancelPrompt(const std::shared_ptr<::aidl::android::security::apc::IConfirmationCallback>& in_listener) = 0;
  virtual ::ndk::ScopedAStatus isSupported(bool* _aidl_return) = 0;
private:
  static std::shared_ptr<IProtectedConfirmation> default_impl;
};
class IProtectedConfirmationDefault : public IProtectedConfirmation {
public:
  ::ndk::ScopedAStatus presentPrompt(const std::shared_ptr<::aidl::android::security::apc::IConfirmationCallback>& in_listener, const std::string& in_promptText, const std::vector<uint8_t>& in_extraData, const std::string& in_locale, int32_t in_uiOptionFlags) override;
  ::ndk::ScopedAStatus cancelPrompt(const std::shared_ptr<::aidl::android::security::apc::IConfirmationCallback>& in_listener) override;
  ::ndk::ScopedAStatus isSupported(bool* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace apc
}  // namespace security
}  // namespace android
}  // namespace aidl
