#pragma once

#include "aidl/android/os/IStatsCompanionService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BpStatsCompanionService : public ::ndk::BpCInterface<IStatsCompanionService> {
public:
  explicit BpStatsCompanionService(const ::ndk::SpAIBinder& binder);
  virtual ~BpStatsCompanionService();

  ::ndk::ScopedAStatus statsdReady() override;
  ::ndk::ScopedAStatus setAnomalyAlarm(int64_t in_timestampMs) override;
  ::ndk::ScopedAStatus cancelAnomalyAlarm() override;
  ::ndk::ScopedAStatus setPullingAlarm(int64_t in_nextPullTimeMs) override;
  ::ndk::ScopedAStatus cancelPullingAlarm() override;
  ::ndk::ScopedAStatus setAlarmForSubscriberTriggering(int64_t in_timestampMs) override;
  ::ndk::ScopedAStatus cancelAlarmForSubscriberTriggering() override;
  ::ndk::ScopedAStatus checkPermission(const std::string& in_permission, int32_t in_pid, int32_t in_uid, bool* _aidl_return) override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
