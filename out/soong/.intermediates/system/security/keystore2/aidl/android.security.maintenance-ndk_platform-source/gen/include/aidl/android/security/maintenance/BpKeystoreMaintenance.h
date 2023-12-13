#pragma once

#include "aidl/android/security/maintenance/IKeystoreMaintenance.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace security {
namespace maintenance {
class BpKeystoreMaintenance : public ::ndk::BpCInterface<IKeystoreMaintenance> {
public:
  explicit BpKeystoreMaintenance(const ::ndk::SpAIBinder& binder);
  virtual ~BpKeystoreMaintenance();

  ::ndk::ScopedAStatus onUserAdded(int32_t in_userId) override;
  ::ndk::ScopedAStatus onUserRemoved(int32_t in_userId) override;
  ::ndk::ScopedAStatus onUserPasswordChanged(int32_t in_userId, const std::optional<std::vector<uint8_t>>& in_password) override;
  ::ndk::ScopedAStatus clearNamespace(::aidl::android::system::keystore2::Domain in_domain, int64_t in_nspace) override;
  ::ndk::ScopedAStatus getState(int32_t in_userId, ::aidl::android::security::maintenance::UserState* _aidl_return) override;
  ::ndk::ScopedAStatus earlyBootEnded() override;
  ::ndk::ScopedAStatus onDeviceOffBody() override;
  ::ndk::ScopedAStatus migrateKeyNamespace(const ::aidl::android::system::keystore2::KeyDescriptor& in_source, const ::aidl::android::system::keystore2::KeyDescriptor& in_destination) override;
  ::ndk::ScopedAStatus deleteAllKeys() override;
};
}  // namespace maintenance
}  // namespace security
}  // namespace android
}  // namespace aidl
