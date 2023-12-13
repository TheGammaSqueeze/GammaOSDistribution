#pragma once

#include "aidl/android/security/compat/IKeystoreCompatService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace security {
namespace compat {
class BpKeystoreCompatService : public ::ndk::BpCInterface<IKeystoreCompatService> {
public:
  explicit BpKeystoreCompatService(const ::ndk::SpAIBinder& binder);
  virtual ~BpKeystoreCompatService();

  ::ndk::ScopedAStatus getKeyMintDevice(::aidl::android::hardware::security::keymint::SecurityLevel in_securityLevel, std::shared_ptr<::aidl::android::hardware::security::keymint::IKeyMintDevice>* _aidl_return) override;
  ::ndk::ScopedAStatus getSecureClock(std::shared_ptr<::aidl::android::hardware::security::secureclock::ISecureClock>* _aidl_return) override;
  ::ndk::ScopedAStatus getSharedSecret(::aidl::android::hardware::security::keymint::SecurityLevel in_securityLevel, std::shared_ptr<::aidl::android::hardware::security::sharedsecret::ISharedSecret>* _aidl_return) override;
};
}  // namespace compat
}  // namespace security
}  // namespace android
}  // namespace aidl
