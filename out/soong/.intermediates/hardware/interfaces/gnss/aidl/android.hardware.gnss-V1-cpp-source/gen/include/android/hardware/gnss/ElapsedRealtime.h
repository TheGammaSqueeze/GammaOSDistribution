#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace gnss {

class ElapsedRealtime : public ::android::Parcelable {
public:
  inline bool operator!=(const ElapsedRealtime& rhs) const {
    return std::tie(flags, timestampNs, timeUncertaintyNs) != std::tie(rhs.flags, rhs.timestampNs, rhs.timeUncertaintyNs);
  }
  inline bool operator<(const ElapsedRealtime& rhs) const {
    return std::tie(flags, timestampNs, timeUncertaintyNs) < std::tie(rhs.flags, rhs.timestampNs, rhs.timeUncertaintyNs);
  }
  inline bool operator<=(const ElapsedRealtime& rhs) const {
    return std::tie(flags, timestampNs, timeUncertaintyNs) <= std::tie(rhs.flags, rhs.timestampNs, rhs.timeUncertaintyNs);
  }
  inline bool operator==(const ElapsedRealtime& rhs) const {
    return std::tie(flags, timestampNs, timeUncertaintyNs) == std::tie(rhs.flags, rhs.timestampNs, rhs.timeUncertaintyNs);
  }
  inline bool operator>(const ElapsedRealtime& rhs) const {
    return std::tie(flags, timestampNs, timeUncertaintyNs) > std::tie(rhs.flags, rhs.timestampNs, rhs.timeUncertaintyNs);
  }
  inline bool operator>=(const ElapsedRealtime& rhs) const {
    return std::tie(flags, timestampNs, timeUncertaintyNs) >= std::tie(rhs.flags, rhs.timestampNs, rhs.timeUncertaintyNs);
  }

  int32_t flags = int32_t(0);
  int64_t timestampNs = int64_t(0L);
  double timeUncertaintyNs = double(0.000000);
  enum  : int32_t {
    HAS_TIMESTAMP_NS = 1,
    HAS_TIME_UNCERTAINTY_NS = 2,
  };
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.gnss.ElapsedRealtime");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "ElapsedRealtime{";
    os << "flags: " << ::android::internal::ToString(flags);
    os << ", timestampNs: " << ::android::internal::ToString(timestampNs);
    os << ", timeUncertaintyNs: " << ::android::internal::ToString(timeUncertaintyNs);
    os << "}";
    return os.str();
  }
};  // class ElapsedRealtime

}  // namespace gnss

}  // namespace hardware

}  // namespace android
