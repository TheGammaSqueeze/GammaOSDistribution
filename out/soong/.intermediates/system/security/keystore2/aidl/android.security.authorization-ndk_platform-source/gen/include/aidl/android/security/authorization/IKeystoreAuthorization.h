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
#include <android/binder_parcel_platform.h>
#include <android/binder_ibinder_platform.h>
#include <aidl/android/hardware/security/keymint/HardwareAuthToken.h>
#include <aidl/android/security/authorization/AuthorizationTokens.h>
#include <aidl/android/security/authorization/LockScreenEvent.h>

namespace aidl {
namespace android {
namespace security {
namespace authorization {
class IKeystoreAuthorization : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IKeystoreAuthorization();
  virtual ~IKeystoreAuthorization();

  static constexpr uint32_t TRANSACTION_addAuthToken = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onLockScreenEvent = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getAuthTokensForCredStore = FIRST_CALL_TRANSACTION + 2;

  static std::shared_ptr<IKeystoreAuthorization> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IKeystoreAuthorization>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IKeystoreAuthorization>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IKeystoreAuthorization>& impl);
  static const std::shared_ptr<IKeystoreAuthorization>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus addAuthToken(const ::aidl::android::hardware::security::keymint::HardwareAuthToken& in_authToken) = 0;
  virtual ::ndk::ScopedAStatus onLockScreenEvent(::aidl::android::security::authorization::LockScreenEvent in_lockScreenEvent, int32_t in_userId, const std::optional<std::vector<uint8_t>>& in_password, const std::optional<std::vector<int64_t>>& in_unlockingSids) = 0;
  virtual ::ndk::ScopedAStatus getAuthTokensForCredStore(int64_t in_challenge, int64_t in_secureUserId, int64_t in_authTokenMaxAgeMillis, ::aidl::android::security::authorization::AuthorizationTokens* _aidl_return) = 0;
private:
  static std::shared_ptr<IKeystoreAuthorization> default_impl;
};
class IKeystoreAuthorizationDefault : public IKeystoreAuthorization {
public:
  ::ndk::ScopedAStatus addAuthToken(const ::aidl::android::hardware::security::keymint::HardwareAuthToken& in_authToken) override;
  ::ndk::ScopedAStatus onLockScreenEvent(::aidl::android::security::authorization::LockScreenEvent in_lockScreenEvent, int32_t in_userId, const std::optional<std::vector<uint8_t>>& in_password, const std::optional<std::vector<int64_t>>& in_unlockingSids) override;
  ::ndk::ScopedAStatus getAuthTokensForCredStore(int64_t in_challenge, int64_t in_secureUserId, int64_t in_authTokenMaxAgeMillis, ::aidl::android::security::authorization::AuthorizationTokens* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace authorization
}  // namespace security
}  // namespace android
}  // namespace aidl
