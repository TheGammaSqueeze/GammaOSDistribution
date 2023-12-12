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
#include <aidl/android/os/IPendingIntentRef.h>
#include <aidl/android/os/IPullAtomCallback.h>

namespace aidl {
namespace android {
namespace os {
class IStatsd : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IStatsd();
  virtual ~IStatsd();

  enum : int32_t { FLAG_REQUIRE_STAGING = 1 };
  enum : int32_t { FLAG_ROLLBACK_ENABLED = 2 };
  enum : int32_t { FLAG_REQUIRE_LOW_LATENCY_MONITOR = 4 };
  static constexpr uint32_t TRANSACTION_systemRunning = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_bootCompleted = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_statsCompanionReady = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_informAnomalyAlarmFired = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_informPollAlarmFired = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_informAlarmForSubscriberTriggeringFired = FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_informDeviceShutdown = FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_informAllUidData = FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_informOnePackage = FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_informOnePackageRemoved = FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_getData = FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_getMetadata = FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_addConfiguration = FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_setDataFetchOperation = FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_removeDataFetchOperation = FIRST_CALL_TRANSACTION + 14;
  static constexpr uint32_t TRANSACTION_setActiveConfigsChangedOperation = FIRST_CALL_TRANSACTION + 15;
  static constexpr uint32_t TRANSACTION_removeActiveConfigsChangedOperation = FIRST_CALL_TRANSACTION + 16;
  static constexpr uint32_t TRANSACTION_removeConfiguration = FIRST_CALL_TRANSACTION + 17;
  static constexpr uint32_t TRANSACTION_setBroadcastSubscriber = FIRST_CALL_TRANSACTION + 18;
  static constexpr uint32_t TRANSACTION_unsetBroadcastSubscriber = FIRST_CALL_TRANSACTION + 19;
  static constexpr uint32_t TRANSACTION_allPullersFromBootRegistered = FIRST_CALL_TRANSACTION + 20;
  static constexpr uint32_t TRANSACTION_registerPullAtomCallback = FIRST_CALL_TRANSACTION + 21;
  static constexpr uint32_t TRANSACTION_registerNativePullAtomCallback = FIRST_CALL_TRANSACTION + 22;
  static constexpr uint32_t TRANSACTION_unregisterPullAtomCallback = FIRST_CALL_TRANSACTION + 23;
  static constexpr uint32_t TRANSACTION_unregisterNativePullAtomCallback = FIRST_CALL_TRANSACTION + 24;
  static constexpr uint32_t TRANSACTION_getRegisteredExperimentIds = FIRST_CALL_TRANSACTION + 25;

  static std::shared_ptr<IStatsd> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IStatsd>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IStatsd>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IStatsd>& impl);
  static const std::shared_ptr<IStatsd>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus systemRunning() = 0;
  virtual ::ndk::ScopedAStatus bootCompleted() = 0;
  virtual ::ndk::ScopedAStatus statsCompanionReady() = 0;
  virtual ::ndk::ScopedAStatus informAnomalyAlarmFired() = 0;
  virtual ::ndk::ScopedAStatus informPollAlarmFired() = 0;
  virtual ::ndk::ScopedAStatus informAlarmForSubscriberTriggeringFired() = 0;
  virtual ::ndk::ScopedAStatus informDeviceShutdown() = 0;
  virtual ::ndk::ScopedAStatus informAllUidData(const ::ndk::ScopedFileDescriptor& in_fd) = 0;
  virtual ::ndk::ScopedAStatus informOnePackage(const std::string& in_app, int32_t in_uid, int64_t in_version, const std::string& in_version_string, const std::string& in_installer) = 0;
  virtual ::ndk::ScopedAStatus informOnePackageRemoved(const std::string& in_app, int32_t in_uid) = 0;
  virtual ::ndk::ScopedAStatus getData(int64_t in_key, int32_t in_callingUid, std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getMetadata(std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus addConfiguration(int64_t in_configId, const std::vector<uint8_t>& in_config, int32_t in_callingUid) = 0;
  virtual ::ndk::ScopedAStatus setDataFetchOperation(int64_t in_configId, const std::shared_ptr<::aidl::android::os::IPendingIntentRef>& in_pendingIntentRef, int32_t in_callingUid) = 0;
  virtual ::ndk::ScopedAStatus removeDataFetchOperation(int64_t in_configId, int32_t in_callingUid) = 0;
  virtual ::ndk::ScopedAStatus setActiveConfigsChangedOperation(const std::shared_ptr<::aidl::android::os::IPendingIntentRef>& in_pendingIntentRef, int32_t in_callingUid, std::vector<int64_t>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus removeActiveConfigsChangedOperation(int32_t in_callingUid) = 0;
  virtual ::ndk::ScopedAStatus removeConfiguration(int64_t in_configId, int32_t in_callingUid) = 0;
  virtual ::ndk::ScopedAStatus setBroadcastSubscriber(int64_t in_configId, int64_t in_subscriberId, const std::shared_ptr<::aidl::android::os::IPendingIntentRef>& in_pir, int32_t in_callingUid) = 0;
  virtual ::ndk::ScopedAStatus unsetBroadcastSubscriber(int64_t in_configId, int64_t in_subscriberId, int32_t in_callingUid) = 0;
  virtual ::ndk::ScopedAStatus allPullersFromBootRegistered() = 0;
  virtual ::ndk::ScopedAStatus registerPullAtomCallback(int32_t in_uid, int32_t in_atomTag, int64_t in_coolDownMillis, int64_t in_timeoutMillis, const std::vector<int32_t>& in_additiveFields, const std::shared_ptr<::aidl::android::os::IPullAtomCallback>& in_pullerCallback) = 0;
  virtual ::ndk::ScopedAStatus registerNativePullAtomCallback(int32_t in_atomTag, int64_t in_coolDownMillis, int64_t in_timeoutMillis, const std::vector<int32_t>& in_additiveFields, const std::shared_ptr<::aidl::android::os::IPullAtomCallback>& in_pullerCallback) = 0;
  virtual ::ndk::ScopedAStatus unregisterPullAtomCallback(int32_t in_uid, int32_t in_atomTag) = 0;
  virtual ::ndk::ScopedAStatus unregisterNativePullAtomCallback(int32_t in_atomTag) = 0;
  virtual ::ndk::ScopedAStatus getRegisteredExperimentIds(std::vector<int64_t>* _aidl_return) = 0;
private:
  static std::shared_ptr<IStatsd> default_impl;
};
class IStatsdDefault : public IStatsd {
public:
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
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
