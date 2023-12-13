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
#include <aidl/android/media/IResourceManagerClient.h>
#include <aidl/android/media/MediaResourceParcel.h>
#include <aidl/android/media/MediaResourcePolicyParcel.h>

namespace aidl {
namespace android {
namespace media {
class IResourceManagerService : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IResourceManagerService();
  virtual ~IResourceManagerService();

  static const char* kPolicySupportsMultipleSecureCodecs;
  static const char* kPolicySupportsSecureWithNonSecureCodec;
  static constexpr uint32_t TRANSACTION_config = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_addResource = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_removeResource = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_removeClient = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_reclaimResource = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_overridePid = FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_overrideProcessInfo = FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_markClientForPendingRemoval = FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_reclaimResourcesFromClientsPendingRemoval = FIRST_CALL_TRANSACTION + 8;

  static std::shared_ptr<IResourceManagerService> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IResourceManagerService>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IResourceManagerService>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IResourceManagerService>& impl);
  static const std::shared_ptr<IResourceManagerService>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus config(const std::vector<::aidl::android::media::MediaResourcePolicyParcel>& in_policies) = 0;
  virtual ::ndk::ScopedAStatus addResource(int32_t in_pid, int32_t in_uid, int64_t in_clientId, const std::shared_ptr<::aidl::android::media::IResourceManagerClient>& in_client, const std::vector<::aidl::android::media::MediaResourceParcel>& in_resources) = 0;
  virtual ::ndk::ScopedAStatus removeResource(int32_t in_pid, int64_t in_clientId, const std::vector<::aidl::android::media::MediaResourceParcel>& in_resources) = 0;
  virtual ::ndk::ScopedAStatus removeClient(int32_t in_pid, int64_t in_clientId) = 0;
  virtual ::ndk::ScopedAStatus reclaimResource(int32_t in_callingPid, const std::vector<::aidl::android::media::MediaResourceParcel>& in_resources, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus overridePid(int32_t in_originalPid, int32_t in_newPid) = 0;
  virtual ::ndk::ScopedAStatus overrideProcessInfo(const std::shared_ptr<::aidl::android::media::IResourceManagerClient>& in_client, int32_t in_pid, int32_t in_procState, int32_t in_oomScore) = 0;
  virtual ::ndk::ScopedAStatus markClientForPendingRemoval(int32_t in_pid, int64_t in_clientId) = 0;
  virtual ::ndk::ScopedAStatus reclaimResourcesFromClientsPendingRemoval(int32_t in_pid) = 0;
private:
  static std::shared_ptr<IResourceManagerService> default_impl;
};
class IResourceManagerServiceDefault : public IResourceManagerService {
public:
  ::ndk::ScopedAStatus config(const std::vector<::aidl::android::media::MediaResourcePolicyParcel>& in_policies) override;
  ::ndk::ScopedAStatus addResource(int32_t in_pid, int32_t in_uid, int64_t in_clientId, const std::shared_ptr<::aidl::android::media::IResourceManagerClient>& in_client, const std::vector<::aidl::android::media::MediaResourceParcel>& in_resources) override;
  ::ndk::ScopedAStatus removeResource(int32_t in_pid, int64_t in_clientId, const std::vector<::aidl::android::media::MediaResourceParcel>& in_resources) override;
  ::ndk::ScopedAStatus removeClient(int32_t in_pid, int64_t in_clientId) override;
  ::ndk::ScopedAStatus reclaimResource(int32_t in_callingPid, const std::vector<::aidl::android::media::MediaResourceParcel>& in_resources, bool* _aidl_return) override;
  ::ndk::ScopedAStatus overridePid(int32_t in_originalPid, int32_t in_newPid) override;
  ::ndk::ScopedAStatus overrideProcessInfo(const std::shared_ptr<::aidl::android::media::IResourceManagerClient>& in_client, int32_t in_pid, int32_t in_procState, int32_t in_oomScore) override;
  ::ndk::ScopedAStatus markClientForPendingRemoval(int32_t in_pid, int64_t in_clientId) override;
  ::ndk::ScopedAStatus reclaimResourcesFromClientsPendingRemoval(int32_t in_pid) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
