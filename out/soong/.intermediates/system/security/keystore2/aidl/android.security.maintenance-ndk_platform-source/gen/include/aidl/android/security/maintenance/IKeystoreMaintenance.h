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
#include <aidl/android/security/maintenance/UserState.h>
#include <aidl/android/system/keystore2/Domain.h>
#include <aidl/android/system/keystore2/KeyDescriptor.h>

namespace aidl {
namespace android {
namespace security {
namespace maintenance {
class IKeystoreMaintenance : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IKeystoreMaintenance();
  virtual ~IKeystoreMaintenance();

  static constexpr uint32_t TRANSACTION_onUserAdded = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onUserRemoved = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onUserPasswordChanged = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_clearNamespace = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getState = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_earlyBootEnded = FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_onDeviceOffBody = FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_migrateKeyNamespace = FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_deleteAllKeys = FIRST_CALL_TRANSACTION + 8;

  static std::shared_ptr<IKeystoreMaintenance> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IKeystoreMaintenance>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IKeystoreMaintenance>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IKeystoreMaintenance>& impl);
  static const std::shared_ptr<IKeystoreMaintenance>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onUserAdded(int32_t in_userId) = 0;
  virtual ::ndk::ScopedAStatus onUserRemoved(int32_t in_userId) = 0;
  virtual ::ndk::ScopedAStatus onUserPasswordChanged(int32_t in_userId, const std::optional<std::vector<uint8_t>>& in_password) = 0;
  virtual ::ndk::ScopedAStatus clearNamespace(::aidl::android::system::keystore2::Domain in_domain, int64_t in_nspace) = 0;
  virtual ::ndk::ScopedAStatus getState(int32_t in_userId, ::aidl::android::security::maintenance::UserState* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus earlyBootEnded() = 0;
  virtual ::ndk::ScopedAStatus onDeviceOffBody() = 0;
  virtual ::ndk::ScopedAStatus migrateKeyNamespace(const ::aidl::android::system::keystore2::KeyDescriptor& in_source, const ::aidl::android::system::keystore2::KeyDescriptor& in_destination) = 0;
  virtual ::ndk::ScopedAStatus deleteAllKeys() = 0;
private:
  static std::shared_ptr<IKeystoreMaintenance> default_impl;
};
class IKeystoreMaintenanceDefault : public IKeystoreMaintenance {
public:
  ::ndk::ScopedAStatus onUserAdded(int32_t in_userId) override;
  ::ndk::ScopedAStatus onUserRemoved(int32_t in_userId) override;
  ::ndk::ScopedAStatus onUserPasswordChanged(int32_t in_userId, const std::optional<std::vector<uint8_t>>& in_password) override;
  ::ndk::ScopedAStatus clearNamespace(::aidl::android::system::keystore2::Domain in_domain, int64_t in_nspace) override;
  ::ndk::ScopedAStatus getState(int32_t in_userId, ::aidl::android::security::maintenance::UserState* _aidl_return) override;
  ::ndk::ScopedAStatus earlyBootEnded() override;
  ::ndk::ScopedAStatus onDeviceOffBody() override;
  ::ndk::ScopedAStatus migrateKeyNamespace(const ::aidl::android::system::keystore2::KeyDescriptor& in_source, const ::aidl::android::system::keystore2::KeyDescriptor& in_destination) override;
  ::ndk::ScopedAStatus deleteAllKeys() override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace maintenance
}  // namespace security
}  // namespace android
}  // namespace aidl
