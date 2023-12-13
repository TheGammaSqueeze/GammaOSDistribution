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

namespace aidl {
namespace android {
namespace os {
class IStatsCompanionService : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IStatsCompanionService();
  virtual ~IStatsCompanionService();

  static constexpr uint32_t TRANSACTION_statsdReady = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_setAnomalyAlarm = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_cancelAnomalyAlarm = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_setPullingAlarm = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_cancelPullingAlarm = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_setAlarmForSubscriberTriggering = FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_cancelAlarmForSubscriberTriggering = FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_checkPermission = FIRST_CALL_TRANSACTION + 7;

  static std::shared_ptr<IStatsCompanionService> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IStatsCompanionService>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IStatsCompanionService>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IStatsCompanionService>& impl);
  static const std::shared_ptr<IStatsCompanionService>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus statsdReady() = 0;
  virtual ::ndk::ScopedAStatus setAnomalyAlarm(int64_t in_timestampMs) = 0;
  virtual ::ndk::ScopedAStatus cancelAnomalyAlarm() = 0;
  virtual ::ndk::ScopedAStatus setPullingAlarm(int64_t in_nextPullTimeMs) = 0;
  virtual ::ndk::ScopedAStatus cancelPullingAlarm() = 0;
  virtual ::ndk::ScopedAStatus setAlarmForSubscriberTriggering(int64_t in_timestampMs) = 0;
  virtual ::ndk::ScopedAStatus cancelAlarmForSubscriberTriggering() = 0;
  virtual ::ndk::ScopedAStatus checkPermission(const std::string& in_permission, int32_t in_pid, int32_t in_uid, bool* _aidl_return) = 0;
private:
  static std::shared_ptr<IStatsCompanionService> default_impl;
};
class IStatsCompanionServiceDefault : public IStatsCompanionService {
public:
  ::ndk::ScopedAStatus statsdReady() override;
  ::ndk::ScopedAStatus setAnomalyAlarm(int64_t in_timestampMs) override;
  ::ndk::ScopedAStatus cancelAnomalyAlarm() override;
  ::ndk::ScopedAStatus setPullingAlarm(int64_t in_nextPullTimeMs) override;
  ::ndk::ScopedAStatus cancelPullingAlarm() override;
  ::ndk::ScopedAStatus setAlarmForSubscriberTriggering(int64_t in_timestampMs) override;
  ::ndk::ScopedAStatus cancelAlarmForSubscriberTriggering() override;
  ::ndk::ScopedAStatus checkPermission(const std::string& in_permission, int32_t in_pid, int32_t in_uid, bool* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
