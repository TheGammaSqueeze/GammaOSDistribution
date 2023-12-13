#pragma once

#include "aidl/android/security/apc/IProtectedConfirmation.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace security {
namespace apc {
class BpProtectedConfirmation : public ::ndk::BpCInterface<IProtectedConfirmation> {
public:
  explicit BpProtectedConfirmation(const ::ndk::SpAIBinder& binder);
  virtual ~BpProtectedConfirmation();

  ::ndk::ScopedAStatus presentPrompt(const std::shared_ptr<::aidl::android::security::apc::IConfirmationCallback>& in_listener, const std::string& in_promptText, const std::vector<uint8_t>& in_extraData, const std::string& in_locale, int32_t in_uiOptionFlags) override;
  ::ndk::ScopedAStatus cancelPrompt(const std::shared_ptr<::aidl::android::security::apc::IConfirmationCallback>& in_listener) override;
  ::ndk::ScopedAStatus isSupported(bool* _aidl_return) override;
};
}  // namespace apc
}  // namespace security
}  // namespace android
}  // namespace aidl
