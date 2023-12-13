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
#include <aidl/android/os/StatsDimensionsValueParcel.h>

namespace aidl {
namespace android {
namespace os {
class IPendingIntentRef : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IPendingIntentRef();
  virtual ~IPendingIntentRef();

  static constexpr uint32_t TRANSACTION_sendDataBroadcast = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_sendActiveConfigsChangedBroadcast = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_sendSubscriberBroadcast = FIRST_CALL_TRANSACTION + 2;

  static std::shared_ptr<IPendingIntentRef> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IPendingIntentRef>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IPendingIntentRef>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IPendingIntentRef>& impl);
  static const std::shared_ptr<IPendingIntentRef>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus sendDataBroadcast(int64_t in_lastReportTimeNs) = 0;
  virtual ::ndk::ScopedAStatus sendActiveConfigsChangedBroadcast(const std::vector<int64_t>& in_configIds) = 0;
  virtual ::ndk::ScopedAStatus sendSubscriberBroadcast(int64_t in_configUid, int64_t in_configId, int64_t in_subscriptionId, int64_t in_subscriptionRuleId, const std::vector<std::string>& in_cookies, const ::aidl::android::os::StatsDimensionsValueParcel& in_dimensionsValueParcel) = 0;
private:
  static std::shared_ptr<IPendingIntentRef> default_impl;
};
class IPendingIntentRefDefault : public IPendingIntentRef {
public:
  ::ndk::ScopedAStatus sendDataBroadcast(int64_t in_lastReportTimeNs) override;
  ::ndk::ScopedAStatus sendActiveConfigsChangedBroadcast(const std::vector<int64_t>& in_configIds) override;
  ::ndk::ScopedAStatus sendSubscriberBroadcast(int64_t in_configUid, int64_t in_configId, int64_t in_subscriptionId, int64_t in_subscriptionRuleId, const std::vector<std::string>& in_cookies, const ::aidl::android::os::StatsDimensionsValueParcel& in_dimensionsValueParcel) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
