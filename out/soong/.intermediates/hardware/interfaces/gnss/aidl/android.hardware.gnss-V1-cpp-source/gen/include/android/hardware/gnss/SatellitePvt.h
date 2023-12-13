#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/gnss/SatelliteClockInfo.h>
#include <android/hardware/gnss/SatellitePositionEcef.h>
#include <android/hardware/gnss/SatelliteVelocityEcef.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace gnss {

class SatellitePvt : public ::android::Parcelable {
public:
  inline bool operator!=(const SatellitePvt& rhs) const {
    return std::tie(flags, satPosEcef, satVelEcef, satClockInfo, ionoDelayMeters, tropoDelayMeters) != std::tie(rhs.flags, rhs.satPosEcef, rhs.satVelEcef, rhs.satClockInfo, rhs.ionoDelayMeters, rhs.tropoDelayMeters);
  }
  inline bool operator<(const SatellitePvt& rhs) const {
    return std::tie(flags, satPosEcef, satVelEcef, satClockInfo, ionoDelayMeters, tropoDelayMeters) < std::tie(rhs.flags, rhs.satPosEcef, rhs.satVelEcef, rhs.satClockInfo, rhs.ionoDelayMeters, rhs.tropoDelayMeters);
  }
  inline bool operator<=(const SatellitePvt& rhs) const {
    return std::tie(flags, satPosEcef, satVelEcef, satClockInfo, ionoDelayMeters, tropoDelayMeters) <= std::tie(rhs.flags, rhs.satPosEcef, rhs.satVelEcef, rhs.satClockInfo, rhs.ionoDelayMeters, rhs.tropoDelayMeters);
  }
  inline bool operator==(const SatellitePvt& rhs) const {
    return std::tie(flags, satPosEcef, satVelEcef, satClockInfo, ionoDelayMeters, tropoDelayMeters) == std::tie(rhs.flags, rhs.satPosEcef, rhs.satVelEcef, rhs.satClockInfo, rhs.ionoDelayMeters, rhs.tropoDelayMeters);
  }
  inline bool operator>(const SatellitePvt& rhs) const {
    return std::tie(flags, satPosEcef, satVelEcef, satClockInfo, ionoDelayMeters, tropoDelayMeters) > std::tie(rhs.flags, rhs.satPosEcef, rhs.satVelEcef, rhs.satClockInfo, rhs.ionoDelayMeters, rhs.tropoDelayMeters);
  }
  inline bool operator>=(const SatellitePvt& rhs) const {
    return std::tie(flags, satPosEcef, satVelEcef, satClockInfo, ionoDelayMeters, tropoDelayMeters) >= std::tie(rhs.flags, rhs.satPosEcef, rhs.satVelEcef, rhs.satClockInfo, rhs.ionoDelayMeters, rhs.tropoDelayMeters);
  }

  int32_t flags = int32_t(0);
  ::android::hardware::gnss::SatellitePositionEcef satPosEcef;
  ::android::hardware::gnss::SatelliteVelocityEcef satVelEcef;
  ::android::hardware::gnss::SatelliteClockInfo satClockInfo;
  double ionoDelayMeters = double(0.000000);
  double tropoDelayMeters = double(0.000000);
  enum  : int32_t {
    HAS_POSITION_VELOCITY_CLOCK_INFO = 1,
    HAS_IONO = 2,
    HAS_TROPO = 4,
  };
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.gnss.SatellitePvt");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "SatellitePvt{";
    os << "flags: " << ::android::internal::ToString(flags);
    os << ", satPosEcef: " << ::android::internal::ToString(satPosEcef);
    os << ", satVelEcef: " << ::android::internal::ToString(satVelEcef);
    os << ", satClockInfo: " << ::android::internal::ToString(satClockInfo);
    os << ", ionoDelayMeters: " << ::android::internal::ToString(ionoDelayMeters);
    os << ", tropoDelayMeters: " << ::android::internal::ToString(tropoDelayMeters);
    os << "}";
    return os.str();
  }
};  // class SatellitePvt

}  // namespace gnss

}  // namespace hardware

}  // namespace android
