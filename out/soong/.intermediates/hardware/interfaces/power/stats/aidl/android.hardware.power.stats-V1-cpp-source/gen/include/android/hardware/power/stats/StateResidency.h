#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace power {

namespace stats {

class StateResidency : public ::android::Parcelable {
public:
  inline bool operator!=(const StateResidency& rhs) const {
    return std::tie(id, totalTimeInStateMs, totalStateEntryCount, lastEntryTimestampMs) != std::tie(rhs.id, rhs.totalTimeInStateMs, rhs.totalStateEntryCount, rhs.lastEntryTimestampMs);
  }
  inline bool operator<(const StateResidency& rhs) const {
    return std::tie(id, totalTimeInStateMs, totalStateEntryCount, lastEntryTimestampMs) < std::tie(rhs.id, rhs.totalTimeInStateMs, rhs.totalStateEntryCount, rhs.lastEntryTimestampMs);
  }
  inline bool operator<=(const StateResidency& rhs) const {
    return std::tie(id, totalTimeInStateMs, totalStateEntryCount, lastEntryTimestampMs) <= std::tie(rhs.id, rhs.totalTimeInStateMs, rhs.totalStateEntryCount, rhs.lastEntryTimestampMs);
  }
  inline bool operator==(const StateResidency& rhs) const {
    return std::tie(id, totalTimeInStateMs, totalStateEntryCount, lastEntryTimestampMs) == std::tie(rhs.id, rhs.totalTimeInStateMs, rhs.totalStateEntryCount, rhs.lastEntryTimestampMs);
  }
  inline bool operator>(const StateResidency& rhs) const {
    return std::tie(id, totalTimeInStateMs, totalStateEntryCount, lastEntryTimestampMs) > std::tie(rhs.id, rhs.totalTimeInStateMs, rhs.totalStateEntryCount, rhs.lastEntryTimestampMs);
  }
  inline bool operator>=(const StateResidency& rhs) const {
    return std::tie(id, totalTimeInStateMs, totalStateEntryCount, lastEntryTimestampMs) >= std::tie(rhs.id, rhs.totalTimeInStateMs, rhs.totalStateEntryCount, rhs.lastEntryTimestampMs);
  }

  int32_t id = int32_t(0);
  int64_t totalTimeInStateMs = int64_t(0L);
  int64_t totalStateEntryCount = int64_t(0L);
  int64_t lastEntryTimestampMs = int64_t(0L);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.power.stats.StateResidency");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "StateResidency{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", totalTimeInStateMs: " << ::android::internal::ToString(totalTimeInStateMs);
    os << ", totalStateEntryCount: " << ::android::internal::ToString(totalStateEntryCount);
    os << ", lastEntryTimestampMs: " << ::android::internal::ToString(lastEntryTimestampMs);
    os << "}";
    return os.str();
  }
};  // class StateResidency

}  // namespace stats

}  // namespace power

}  // namespace hardware

}  // namespace android
