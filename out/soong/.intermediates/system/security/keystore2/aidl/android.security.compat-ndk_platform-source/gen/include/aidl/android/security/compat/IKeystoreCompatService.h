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
#include <aidl/android/hardware/security/keymint/IKeyMintDevice.h>
#include <aidl/android/hardware/security/keymint/SecurityLevel.h>
#include <aidl/android/hardware/security/secureclock/ISecureClock.h>
#include <aidl/android/hardware/security/sharedsecret/ISharedSecret.h>

namespace aidl {
namespace android {
namespace security {
namespace compat {
class IKeystoreCompatService : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IKeystoreCompatService();
  virtual ~IKeystoreCompatService();

  static constexpr uint32_t TRANSACTION_getKeyMintDevice = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getSecureClock = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getSharedSecret = FIRST_CALL_TRANSACTION + 2;

  static std::shared_ptr<IKeystoreCompatService> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IKeystoreCompatService>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IKeystoreCompatService>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IKeystoreCompatService>& impl);
  static const std::shared_ptr<IKeystoreCompatService>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus getKeyMintDevice(::aidl::android::hardware::security::keymint::SecurityLevel in_securityLevel, std::shared_ptr<::aidl::android::hardware::security::keymint::IKeyMintDevice>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getSecureClock(std::shared_ptr<::aidl::android::hardware::security::secureclock::ISecureClock>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getSharedSecret(::aidl::android::hardware::security::keymint::SecurityLevel in_securityLevel, std::shared_ptr<::aidl::android::hardware::security::sharedsecret::ISharedSecret>* _aidl_return) = 0;
private:
  static std::shared_ptr<IKeystoreCompatService> default_impl;
};
class IKeystoreCompatServiceDefault : public IKeystoreCompatService {
public:
  ::ndk::ScopedAStatus getKeyMintDevice(::aidl::android::hardware::security::keymint::SecurityLevel in_securityLevel, std::shared_ptr<::aidl::android::hardware::security::keymint::IKeyMintDevice>* _aidl_return) override;
  ::ndk::ScopedAStatus getSecureClock(std::shared_ptr<::aidl::android::hardware::security::secureclock::ISecureClock>* _aidl_return) override;
  ::ndk::ScopedAStatus getSharedSecret(::aidl::android::hardware::security::keymint::SecurityLevel in_securityLevel, std::shared_ptr<::aidl::android::hardware::security::sharedsecret::ISharedSecret>* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace compat
}  // namespace security
}  // namespace android
}  // namespace aidl
