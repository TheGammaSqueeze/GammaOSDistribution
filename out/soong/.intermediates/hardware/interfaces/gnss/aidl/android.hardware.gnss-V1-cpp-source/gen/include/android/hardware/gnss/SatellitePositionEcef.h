#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace gnss {

class SatellitePositionEcef : public ::android::Parcelable {
public:
  inline bool operator!=(const SatellitePositionEcef& rhs) const {
    return std::tie(posXMeters, posYMeters, posZMeters, ureMeters) != std::tie(rhs.posXMeters, rhs.posYMeters, rhs.posZMeters, rhs.ureMeters);
  }
  inline bool operator<(const SatellitePositionEcef& rhs) const {
    return std::tie(posXMeters, posYMeters, posZMeters, ureMeters) < std::tie(rhs.posXMeters, rhs.posYMeters, rhs.posZMeters, rhs.ureMeters);
  }
  inline bool operator<=(const SatellitePositionEcef& rhs) const {
    return std::tie(posXMeters, posYMeters, posZMeters, ureMeters) <= std::tie(rhs.posXMeters, rhs.posYMeters, rhs.posZMeters, rhs.ureMeters);
  }
  inline bool operator==(const SatellitePositionEcef& rhs) const {
    return std::tie(posXMeters, posYMeters, posZMeters, ureMeters) == std::tie(rhs.posXMeters, rhs.posYMeters, rhs.posZMeters, rhs.ureMeters);
  }
  inline bool operator>(const SatellitePositionEcef& rhs) const {
    return std::tie(posXMeters, posYMeters, posZMeters, ureMeters) > std::tie(rhs.posXMeters, rhs.posYMeters, rhs.posZMeters, rhs.ureMeters);
  }
  inline bool operator>=(const SatellitePositionEcef& rhs) const {
    return std::tie(posXMeters, posYMeters, posZMeters, ureMeters) >= std::tie(rhs.posXMeters, rhs.posYMeters, rhs.posZMeters, rhs.ureMeters);
  }

  double posXMeters = double(0.000000);
  double posYMeters = double(0.000000);
  double posZMeters = double(0.000000);
  double ureMeters = double(0.000000);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.gnss.SatellitePositionEcef");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "SatellitePositionEcef{";
    os << "posXMeters: " << ::android::internal::ToString(posXMeters);
    os << ", posYMeters: " << ::android::internal::ToString(posYMeters);
    os << ", posZMeters: " << ::android::internal::ToString(posZMeters);
    os << ", ureMeters: " << ::android::internal::ToString(ureMeters);
    os << "}";
    return os.str();
  }
};  // class SatellitePositionEcef

}  // namespace gnss

}  // namespace hardware

}  // namespace android
