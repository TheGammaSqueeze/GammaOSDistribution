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

class WorkDuration : public ::android::Parcelable {
public:
  inline bool operator!=(const WorkDuration& rhs) const {
    return std::tie(timeStampNanos, durationNanos) != std::tie(rhs.timeStampNanos, rhs.durationNanos);
  }
  inline bool operator<(const WorkDuration& rhs) const {
    return std::tie(timeStampNanos, durationNanos) < std::tie(rhs.timeStampNanos, rhs.durationNanos);
  }
  inline bool operator<=(const WorkDuration& rhs) const {
    return std::tie(timeStampNanos, durationNanos) <= std::tie(rhs.timeStampNanos, rhs.durationNanos);
  }
  inline bool operator==(const WorkDuration& rhs) const {
    return std::tie(timeStampNanos, durationNanos) == std::tie(rhs.timeStampNanos, rhs.durationNanos);
  }
  inline bool operator>(const WorkDuration& rhs) const {
    return std::tie(timeStampNanos, durationNanos) > std::tie(rhs.timeStampNanos, rhs.durationNanos);
  }
  inline bool operator>=(const WorkDuration& rhs) const {
    return std::tie(timeStampNanos, durationNanos) >= std::tie(rhs.timeStampNanos, rhs.durationNanos);
  }

  int64_t timeStampNanos = int64_t(0L);
  int64_t durationNanos = int64_t(0L);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.power.WorkDuration");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "WorkDuration{";
    os << "timeStampNanos: " << ::android::internal::ToString(timeStampNanos);
    os << ", durationNanos: " << ::android::internal::ToString(durationNanos);
    os << "}";
    return os.str();
  }
};  // class WorkDuration

}  // namespace power

}  // namespace hardware

}  // namespace android
