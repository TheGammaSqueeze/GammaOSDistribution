#pragma once

#include "aidl/android/os/IStatsd.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BpStatsd : public ::ndk::BpCInterface<IStatsd> {
public:
  explicit BpStatsd(const ::ndk::SpAIBinder& binder);
  virtual ~BpStatsd();

  ::ndk::ScopedAStatus systemRunning() override;
  ::ndk::ScopedAStatus bootCompleted() override;
  ::ndk::ScopedAStatus statsCompanionReady() override;
  ::ndk::ScopedAStatus informAnomalyAlarmFired() override;
  ::ndk::ScopedAStatus informPollAlarmFired() override;
  ::ndk::ScopedAStatus informAlarmForSubscriberTriggeringFired() override;
  ::ndk::ScopedAStatus informDeviceShutdown() override;
  ::ndk::ScopedAStatus informAllUidData(const ::ndk::ScopedFileDescriptor& in_fd) override;
  ::ndk::ScopedAStatus informOnePackage(const std::string& in_app, int32_t in_uid, int64_t in_version, const std::string& in_version_string, const std::string& in_installer) override;
  ::ndk::ScopedAStatus informOnePackageRemoved(const std::string& in_app, int32_t in_uid) override;
  ::ndk::ScopedAStatus getData(int64_t in_key, int32_t in_callingUid, std::vector<uint8_t>* _aidl_return) override;
  ::ndk::ScopedAStatus getMetadata(std::vector<uint8_t>* _aidl_return) override;
  ::ndk::ScopedAStatus addConfiguration(int64_t in_configId, const std::vector<uint8_t>& in_config, int32_t in_callingUid) override;
  ::ndk::ScopedAStatus setDataFetchOperation(int64_t in_configId, const std::shared_ptr<::aidl::android::os::IPendingIntentRef>& in_pendingIntentRef, int32_t in_callingUid) override;
  ::ndk::ScopedAStatus removeDataFetchOperation(int64_t in_configId, int32_t in_callingUid) override;
  ::ndk::ScopedAStatus setActiveConfigsChangedOperation(const std::shared_ptr<::aidl::android::os::IPendingIntentRef>& in_pendingIntentRef, int32_t in_callingUid, std::vector<int64_t>* _aidl_return) override;
  ::ndk::ScopedAStatus removeActiveConfigsChangedOperation(int32_t in_callingUid) override;
  ::ndk::ScopedAStatus removeConfiguration(int64_t in_configId, int32_t in_callingUid) override;
  ::ndk::ScopedAStatus setBroadcastSubscriber(int64_t in_configId, int64_t in_subscriberId, const std::shared_ptr<::aidl::android::os::IPendingIntentRef>& in_pir, int32_t in_callingUid) override;
  ::ndk::ScopedAStatus unsetBroadcastSubscriber(int64_t in_configId, int64_t in_subscriberId, int32_t in_callingUid) override;
  ::ndk::ScopedAStatus allPullersFromBootRegistered() override;
  ::ndk::ScopedAStatus registerPullAtomCallback(int32_t in_uid, int32_t in_atomTag, int64_t in_coolDownMillis, int64_t in_timeoutMillis, const std::vector<int32_t>& in_additiveFields, const std::shared_ptr<::aidl::android::os::IPullAtomCallback>& in_pullerCallback) override;
  ::ndk::ScopedAStatus registerNativePullAtomCallback(int32_t in_atomTag, int64_t in_coolDownMillis, int64_t in_timeoutMillis, const std::vector<int32_t>& in_additiveFields, const std::shared_ptr<::aidl::android::os::IPullAtomCallback>& in_pullerCallback) override;
  ::ndk::ScopedAStatus unregisterPullAtomCallback(int32_t in_uid, int32_t in_atomTag) override;
  ::ndk::ScopedAStatus unregisterNativePullAtomCallback(int32_t in_atomTag) override;
  ::ndk::ScopedAStatus getRegisteredExperimentIds(std::vector<int64_t>* _aidl_return) override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
