#pragma once

#include "aidl/android/os/IPendingIntentRef.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BpPendingIntentRef : public ::ndk::BpCInterface<IPendingIntentRef> {
public:
  explicit BpPendingIntentRef(const ::ndk::SpAIBinder& binder);
  virtual ~BpPendingIntentRef();

  ::ndk::ScopedAStatus sendDataBroadcast(int64_t in_lastReportTimeNs) override;
  ::ndk::ScopedAStatus sendActiveConfigsChangedBroadcast(const std::vector<int64_t>& in_configIds) override;
  ::ndk::ScopedAStatus sendSubscriberBroadcast(int64_t in_configUid, int64_t in_configId, int64_t in_subscriptionId, int64_t in_subscriptionRuleId, const std::vector<std::string>& in_cookies, const ::aidl::android::os::StatsDimensionsValueParcel& in_dimensionsValueParcel) override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
