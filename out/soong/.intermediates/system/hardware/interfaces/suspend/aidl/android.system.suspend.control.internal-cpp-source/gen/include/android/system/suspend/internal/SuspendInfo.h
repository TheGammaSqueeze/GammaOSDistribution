#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace system {

namespace suspend {

namespace internal {

class SuspendInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const SuspendInfo& rhs) const {
    return std::tie(suspendAttemptCount, failedSuspendCount, shortSuspendCount, suspendTimeMillis, shortSuspendTimeMillis, suspendOverheadTimeMillis, failedSuspendOverheadTimeMillis, newBackoffCount, backoffContinueCount, sleepTimeMillis) != std::tie(rhs.suspendAttemptCount, rhs.failedSuspendCount, rhs.shortSuspendCount, rhs.suspendTimeMillis, rhs.shortSuspendTimeMillis, rhs.suspendOverheadTimeMillis, rhs.failedSuspendOverheadTimeMillis, rhs.newBackoffCount, rhs.backoffContinueCount, rhs.sleepTimeMillis);
  }
  inline bool operator<(const SuspendInfo& rhs) const {
    return std::tie(suspendAttemptCount, failedSuspendCount, shortSuspendCount, suspendTimeMillis, shortSuspendTimeMillis, suspendOverheadTimeMillis, failedSuspendOverheadTimeMillis, newBackoffCount, backoffContinueCount, sleepTimeMillis) < std::tie(rhs.suspendAttemptCount, rhs.failedSuspendCount, rhs.shortSuspendCount, rhs.suspendTimeMillis, rhs.shortSuspendTimeMillis, rhs.suspendOverheadTimeMillis, rhs.failedSuspendOverheadTimeMillis, rhs.newBackoffCount, rhs.backoffContinueCount, rhs.sleepTimeMillis);
  }
  inline bool operator<=(const SuspendInfo& rhs) const {
    return std::tie(suspendAttemptCount, failedSuspendCount, shortSuspendCount, suspendTimeMillis, shortSuspendTimeMillis, suspendOverheadTimeMillis, failedSuspendOverheadTimeMillis, newBackoffCount, backoffContinueCount, sleepTimeMillis) <= std::tie(rhs.suspendAttemptCount, rhs.failedSuspendCount, rhs.shortSuspendCount, rhs.suspendTimeMillis, rhs.shortSuspendTimeMillis, rhs.suspendOverheadTimeMillis, rhs.failedSuspendOverheadTimeMillis, rhs.newBackoffCount, rhs.backoffContinueCount, rhs.sleepTimeMillis);
  }
  inline bool operator==(const SuspendInfo& rhs) const {
    return std::tie(suspendAttemptCount, failedSuspendCount, shortSuspendCount, suspendTimeMillis, shortSuspendTimeMillis, suspendOverheadTimeMillis, failedSuspendOverheadTimeMillis, newBackoffCount, backoffContinueCount, sleepTimeMillis) == std::tie(rhs.suspendAttemptCount, rhs.failedSuspendCount, rhs.shortSuspendCount, rhs.suspendTimeMillis, rhs.shortSuspendTimeMillis, rhs.suspendOverheadTimeMillis, rhs.failedSuspendOverheadTimeMillis, rhs.newBackoffCount, rhs.backoffContinueCount, rhs.sleepTimeMillis);
  }
  inline bool operator>(const SuspendInfo& rhs) const {
    return std::tie(suspendAttemptCount, failedSuspendCount, shortSuspendCount, suspendTimeMillis, shortSuspendTimeMillis, suspendOverheadTimeMillis, failedSuspendOverheadTimeMillis, newBackoffCount, backoffContinueCount, sleepTimeMillis) > std::tie(rhs.suspendAttemptCount, rhs.failedSuspendCount, rhs.shortSuspendCount, rhs.suspendTimeMillis, rhs.shortSuspendTimeMillis, rhs.suspendOverheadTimeMillis, rhs.failedSuspendOverheadTimeMillis, rhs.newBackoffCount, rhs.backoffContinueCount, rhs.sleepTimeMillis);
  }
  inline bool operator>=(const SuspendInfo& rhs) const {
    return std::tie(suspendAttemptCount, failedSuspendCount, shortSuspendCount, suspendTimeMillis, shortSuspendTimeMillis, suspendOverheadTimeMillis, failedSuspendOverheadTimeMillis, newBackoffCount, backoffContinueCount, sleepTimeMillis) >= std::tie(rhs.suspendAttemptCount, rhs.failedSuspendCount, rhs.shortSuspendCount, rhs.suspendTimeMillis, rhs.shortSuspendTimeMillis, rhs.suspendOverheadTimeMillis, rhs.failedSuspendOverheadTimeMillis, rhs.newBackoffCount, rhs.backoffContinueCount, rhs.sleepTimeMillis);
  }

  int64_t suspendAttemptCount = int64_t(0L);
  int64_t failedSuspendCount = int64_t(0L);
  int64_t shortSuspendCount = int64_t(0L);
  int64_t suspendTimeMillis = int64_t(0L);
  int64_t shortSuspendTimeMillis = int64_t(0L);
  int64_t suspendOverheadTimeMillis = int64_t(0L);
  int64_t failedSuspendOverheadTimeMillis = int64_t(0L);
  int64_t newBackoffCount = int64_t(0L);
  int64_t backoffContinueCount = int64_t(0L);
  int64_t sleepTimeMillis = int64_t(0L);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.system.suspend.internal.SuspendInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "SuspendInfo{";
    os << "suspendAttemptCount: " << ::android::internal::ToString(suspendAttemptCount);
    os << ", failedSuspendCount: " << ::android::internal::ToString(failedSuspendCount);
    os << ", shortSuspendCount: " << ::android::internal::ToString(shortSuspendCount);
    os << ", suspendTimeMillis: " << ::android::internal::ToString(suspendTimeMillis);
    os << ", shortSuspendTimeMillis: " << ::android::internal::ToString(shortSuspendTimeMillis);
    os << ", suspendOverheadTimeMillis: " << ::android::internal::ToString(suspendOverheadTimeMillis);
    os << ", failedSuspendOverheadTimeMillis: " << ::android::internal::ToString(failedSuspendOverheadTimeMillis);
    os << ", newBackoffCount: " << ::android::internal::ToString(newBackoffCount);
    os << ", backoffContinueCount: " << ::android::internal::ToString(backoffContinueCount);
    os << ", sleepTimeMillis: " << ::android::internal::ToString(sleepTimeMillis);
    os << "}";
    return os.str();
  }
};  // class SuspendInfo

}  // namespace internal

}  // namespace suspend

}  // namespace system

}  // namespace android
