#pragma once

#include "aidl/android/security/authorization/IKeystoreAuthorization.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace security {
namespace authorization {
class BpKeystoreAuthorization : public ::ndk::BpCInterface<IKeystoreAuthorization> {
public:
  explicit BpKeystoreAuthorization(const ::ndk::SpAIBinder& binder);
  virtual ~BpKeystoreAuthorization();

  ::ndk::ScopedAStatus addAuthToken(const ::aidl::android::hardware::security::keymint::HardwareAuthToken& in_authToken) override;
  ::ndk::ScopedAStatus onLockScreenEvent(::aidl::android::security::authorization::LockScreenEvent in_lockScreenEvent, int32_t in_userId, const std::optional<std::vector<uint8_t>>& in_password, const std::optional<std::vector<int64_t>>& in_unlockingSids) override;
  ::ndk::ScopedAStatus getAuthTokensForCredStore(int64_t in_challenge, int64_t in_secureUserId, int64_t in_authTokenMaxAgeMillis, ::aidl::android::security::authorization::AuthorizationTokens* _aidl_return) override;
};
}  // namespace authorization
}  // namespace security
}  // namespace android
}  // namespace aidl
