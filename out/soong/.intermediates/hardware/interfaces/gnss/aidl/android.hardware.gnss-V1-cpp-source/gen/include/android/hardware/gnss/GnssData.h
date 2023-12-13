#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/gnss/ElapsedRealtime.h>
#include <android/hardware/gnss/GnssClock.h>
#include <android/hardware/gnss/GnssMeasurement.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace gnss {

class GnssData : public ::android::Parcelable {
public:
  inline bool operator!=(const GnssData& rhs) const {
    return std::tie(measurements, clock, elapsedRealtime) != std::tie(rhs.measurements, rhs.clock, rhs.elapsedRealtime);
  }
  inline bool operator<(const GnssData& rhs) const {
    return std::tie(measurements, clock, elapsedRealtime) < std::tie(rhs.measurements, rhs.clock, rhs.elapsedRealtime);
  }
  inline bool operator<=(const GnssData& rhs) const {
    return std::tie(measurements, clock, elapsedRealtime) <= std::tie(rhs.measurements, rhs.clock, rhs.elapsedRealtime);
  }
  inline bool operator==(const GnssData& rhs) const {
    return std::tie(measurements, clock, elapsedRealtime) == std::tie(rhs.measurements, rhs.clock, rhs.elapsedRealtime);
  }
  inline bool operator>(const GnssData& rhs) const {
    return std::tie(measurements, clock, elapsedRealtime) > std::tie(rhs.measurements, rhs.clock, rhs.elapsedRealtime);
  }
  inline bool operator>=(const GnssData& rhs) const {
    return std::tie(measurements, clock, elapsedRealtime) >= std::tie(rhs.measurements, rhs.clock, rhs.elapsedRealtime);
  }

  ::std::vector<::android::hardware::gnss::GnssMeasurement> measurements;
  ::android::hardware::gnss::GnssClock clock;
  ::android::hardware::gnss::ElapsedRealtime elapsedRealtime;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.gnss.GnssData");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "GnssData{";
    os << "measurements: " << ::android::internal::ToString(measurements);
    os << ", clock: " << ::android::internal::ToString(clock);
    os << ", elapsedRealtime: " << ::android::internal::ToString(elapsedRealtime);
    os << "}";
    return os.str();
  }
};  // class GnssData

}  // namespace gnss

}  // namespace hardware

}  // namespace android
