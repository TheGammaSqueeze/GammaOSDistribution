#pragma once

#include "aidl/android/media/IResourceManagerService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BpResourceManagerService : public ::ndk::BpCInterface<IResourceManagerService> {
public:
  explicit BpResourceManagerService(const ::ndk::SpAIBinder& binder);
  virtual ~BpResourceManagerService();

  ::ndk::ScopedAStatus config(const std::vector<::aidl::android::media::MediaResourcePolicyParcel>& in_policies) override;
  ::ndk::ScopedAStatus addResource(int32_t in_pid, int32_t in_uid, int64_t in_clientId, const std::shared_ptr<::aidl::android::media::IResourceManagerClient>& in_client, const std::vector<::aidl::android::media::MediaResourceParcel>& in_resources) override;
  ::ndk::ScopedAStatus removeResource(int32_t in_pid, int64_t in_clientId, const std::vector<::aidl::android::media::MediaResourceParcel>& in_resources) override;
  ::ndk::ScopedAStatus removeClient(int32_t in_pid, int64_t in_clientId) override;
  ::ndk::ScopedAStatus reclaimResource(int32_t in_callingPid, const std::vector<::aidl::android::media::MediaResourceParcel>& in_resources, bool* _aidl_return) override;
  ::ndk::ScopedAStatus overridePid(int32_t in_originalPid, int32_t in_newPid) override;
  ::ndk::ScopedAStatus overrideProcessInfo(const std::shared_ptr<::aidl::android::media::IResourceManagerClient>& in_client, int32_t in_pid, int32_t in_procState, int32_t in_oomScore) override;
  ::ndk::ScopedAStatus markClientForPendingRemoval(int32_t in_pid, int64_t in_clientId) override;
  ::ndk::ScopedAStatus reclaimResourcesFromClientsPendingRemoval(int32_t in_pid) override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
