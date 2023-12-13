#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace gnss {

class SatelliteVelocityEcef : public ::android::Parcelable {
public:
  inline bool operator!=(const SatelliteVelocityEcef& rhs) const {
    return std::tie(velXMps, velYMps, velZMps, ureRateMps) != std::tie(rhs.velXMps, rhs.velYMps, rhs.velZMps, rhs.ureRateMps);
  }
  inline bool operator<(const SatelliteVelocityEcef& rhs) const {
    return std::tie(velXMps, velYMps, velZMps, ureRateMps) < std::tie(rhs.velXMps, rhs.velYMps, rhs.velZMps, rhs.ureRateMps);
  }
  inline bool operator<=(const SatelliteVelocityEcef& rhs) const {
    return std::tie(velXMps, velYMps, velZMps, ureRateMps) <= std::tie(rhs.velXMps, rhs.velYMps, rhs.velZMps, rhs.ureRateMps);
  }
  inline bool operator==(const SatelliteVelocityEcef& rhs) const {
    return std::tie(velXMps, velYMps, velZMps, ureRateMps) == std::tie(rhs.velXMps, rhs.velYMps, rhs.velZMps, rhs.ureRateMps);
  }
  inline bool operator>(const SatelliteVelocityEcef& rhs) const {
    return std::tie(velXMps, velYMps, velZMps, ureRateMps) > std::tie(rhs.velXMps, rhs.velYMps, rhs.velZMps, rhs.ureRateMps);
  }
  inline bool operator>=(const SatelliteVelocityEcef& rhs) const {
    return std::tie(velXMps, velYMps, velZMps, ureRateMps) >= std::tie(rhs.velXMps, rhs.velYMps, rhs.velZMps, rhs.ureRateMps);
  }

  double velXMps = double(0.000000);
  double velYMps = double(0.000000);
  double velZMps = double(0.000000);
  double ureRateMps = double(0.000000);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.gnss.SatelliteVelocityEcef");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "SatelliteVelocityEcef{";
    os << "velXMps: " << ::android::internal::ToString(velXMps);
    os << ", velYMps: " << ::android::internal::ToString(velYMps);
    os << ", velZMps: " << ::android::internal::ToString(velZMps);
    os << ", ureRateMps: " << ::android::internal::ToString(ureRateMps);
    os << "}";
    return os.str();
  }
};  // class SatelliteVelocityEcef

}  // namespace gnss

}  // namespace hardware

}  // namespace android
