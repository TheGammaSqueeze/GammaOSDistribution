#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace system {

namespace suspend {

namespace internal {

class WakeLockInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const WakeLockInfo& rhs) const {
    return std::tie(name, activeCount, lastChange, maxTime, totalTime, isActive, activeTime, isKernelWakelock, pid, eventCount, expireCount, preventSuspendTime, wakeupCount) != std::tie(rhs.name, rhs.activeCount, rhs.lastChange, rhs.maxTime, rhs.totalTime, rhs.isActive, rhs.activeTime, rhs.isKernelWakelock, rhs.pid, rhs.eventCount, rhs.expireCount, rhs.preventSuspendTime, rhs.wakeupCount);
  }
  inline bool operator<(const WakeLockInfo& rhs) const {
    return std::tie(name, activeCount, lastChange, maxTime, totalTime, isActive, activeTime, isKernelWakelock, pid, eventCount, expireCount, preventSuspendTime, wakeupCount) < std::tie(rhs.name, rhs.activeCount, rhs.lastChange, rhs.maxTime, rhs.totalTime, rhs.isActive, rhs.activeTime, rhs.isKernelWakelock, rhs.pid, rhs.eventCount, rhs.expireCount, rhs.preventSuspendTime, rhs.wakeupCount);
  }
  inline bool operator<=(const WakeLockInfo& rhs) const {
    return std::tie(name, activeCount, lastChange, maxTime, totalTime, isActive, activeTime, isKernelWakelock, pid, eventCount, expireCount, preventSuspendTime, wakeupCount) <= std::tie(rhs.name, rhs.activeCount, rhs.lastChange, rhs.maxTime, rhs.totalTime, rhs.isActive, rhs.activeTime, rhs.isKernelWakelock, rhs.pid, rhs.eventCount, rhs.expireCount, rhs.preventSuspendTime, rhs.wakeupCount);
  }
  inline bool operator==(const WakeLockInfo& rhs) const {
    return std::tie(name, activeCount, lastChange, maxTime, totalTime, isActive, activeTime, isKernelWakelock, pid, eventCount, expireCount, preventSuspendTime, wakeupCount) == std::tie(rhs.name, rhs.activeCount, rhs.lastChange, rhs.maxTime, rhs.totalTime, rhs.isActive, rhs.activeTime, rhs.isKernelWakelock, rhs.pid, rhs.eventCount, rhs.expireCount, rhs.preventSuspendTime, rhs.wakeupCount);
  }
  inline bool operator>(const WakeLockInfo& rhs) const {
    return std::tie(name, activeCount, lastChange, maxTime, totalTime, isActive, activeTime, isKernelWakelock, pid, eventCount, expireCount, preventSuspendTime, wakeupCount) > std::tie(rhs.name, rhs.activeCount, rhs.lastChange, rhs.maxTime, rhs.totalTime, rhs.isActive, rhs.activeTime, rhs.isKernelWakelock, rhs.pid, rhs.eventCount, rhs.expireCount, rhs.preventSuspendTime, rhs.wakeupCount);
  }
  inline bool operator>=(const WakeLockInfo& rhs) const {
    return std::tie(name, activeCount, lastChange, maxTime, totalTime, isActive, activeTime, isKernelWakelock, pid, eventCount, expireCount, preventSuspendTime, wakeupCount) >= std::tie(rhs.name, rhs.activeCount, rhs.lastChange, rhs.maxTime, rhs.totalTime, rhs.isActive, rhs.activeTime, rhs.isKernelWakelock, rhs.pid, rhs.eventCount, rhs.expireCount, rhs.preventSuspendTime, rhs.wakeupCount);
  }

  ::std::string name;
  int64_t activeCount = int64_t(0L);
  int64_t lastChange = int64_t(0L);
  int64_t maxTime = int64_t(0L);
  int64_t totalTime = int64_t(0L);
  bool isActive = bool(false);
  int64_t activeTime = int64_t(0L);
  bool isKernelWakelock = bool(false);
  int32_t pid = int32_t(0);
  int64_t eventCount = int64_t(0L);
  int64_t expireCount = int64_t(0L);
  int64_t preventSuspendTime = int64_t(0L);
  int64_t wakeupCount = int64_t(0L);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.system.suspend.internal.WakeLockInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "WakeLockInfo{";
    os << "name: " << ::android::internal::ToString(name);
    os << ", activeCount: " << ::android::internal::ToString(activeCount);
    os << ", lastChange: " << ::android::internal::ToString(lastChange);
    os << ", maxTime: " << ::android::internal::ToString(maxTime);
    os << ", totalTime: " << ::android::internal::ToString(totalTime);
    os << ", isActive: " << ::android::internal::ToString(isActive);
    os << ", activeTime: " << ::android::internal::ToString(activeTime);
    os << ", isKernelWakelock: " << ::android::internal::ToString(isKernelWakelock);
    os << ", pid: " << ::android::internal::ToString(pid);
    os << ", eventCount: " << ::android::internal::ToString(eventCount);
    os << ", expireCount: " << ::android::internal::ToString(expireCount);
    os << ", preventSuspendTime: " << ::android::internal::ToString(preventSuspendTime);
    os << ", wakeupCount: " << ::android::internal::ToString(wakeupCount);
    os << "}";
    return os.str();
  }
};  // class WakeLockInfo

}  // namespace internal

}  // namespace suspend

}  // namespace system

}  // namespace android
