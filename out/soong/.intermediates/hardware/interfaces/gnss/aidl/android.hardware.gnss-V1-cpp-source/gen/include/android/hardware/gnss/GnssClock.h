#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/gnss/GnssSignalType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace gnss {

class GnssClock : public ::android::Parcelable {
public:
  inline bool operator!=(const GnssClock& rhs) const {
    return std::tie(gnssClockFlags, leapSecond, timeNs, timeUncertaintyNs, fullBiasNs, biasNs, biasUncertaintyNs, driftNsps, driftUncertaintyNsps, hwClockDiscontinuityCount, referenceSignalTypeForIsb) != std::tie(rhs.gnssClockFlags, rhs.leapSecond, rhs.timeNs, rhs.timeUncertaintyNs, rhs.fullBiasNs, rhs.biasNs, rhs.biasUncertaintyNs, rhs.driftNsps, rhs.driftUncertaintyNsps, rhs.hwClockDiscontinuityCount, rhs.referenceSignalTypeForIsb);
  }
  inline bool operator<(const GnssClock& rhs) const {
    return std::tie(gnssClockFlags, leapSecond, timeNs, timeUncertaintyNs, fullBiasNs, biasNs, biasUncertaintyNs, driftNsps, driftUncertaintyNsps, hwClockDiscontinuityCount, referenceSignalTypeForIsb) < std::tie(rhs.gnssClockFlags, rhs.leapSecond, rhs.timeNs, rhs.timeUncertaintyNs, rhs.fullBiasNs, rhs.biasNs, rhs.biasUncertaintyNs, rhs.driftNsps, rhs.driftUncertaintyNsps, rhs.hwClockDiscontinuityCount, rhs.referenceSignalTypeForIsb);
  }
  inline bool operator<=(const GnssClock& rhs) const {
    return std::tie(gnssClockFlags, leapSecond, timeNs, timeUncertaintyNs, fullBiasNs, biasNs, biasUncertaintyNs, driftNsps, driftUncertaintyNsps, hwClockDiscontinuityCount, referenceSignalTypeForIsb) <= std::tie(rhs.gnssClockFlags, rhs.leapSecond, rhs.timeNs, rhs.timeUncertaintyNs, rhs.fullBiasNs, rhs.biasNs, rhs.biasUncertaintyNs, rhs.driftNsps, rhs.driftUncertaintyNsps, rhs.hwClockDiscontinuityCount, rhs.referenceSignalTypeForIsb);
  }
  inline bool operator==(const GnssClock& rhs) const {
    return std::tie(gnssClockFlags, leapSecond, timeNs, timeUncertaintyNs, fullBiasNs, biasNs, biasUncertaintyNs, driftNsps, driftUncertaintyNsps, hwClockDiscontinuityCount, referenceSignalTypeForIsb) == std::tie(rhs.gnssClockFlags, rhs.leapSecond, rhs.timeNs, rhs.timeUncertaintyNs, rhs.fullBiasNs, rhs.biasNs, rhs.biasUncertaintyNs, rhs.driftNsps, rhs.driftUncertaintyNsps, rhs.hwClockDiscontinuityCount, rhs.referenceSignalTypeForIsb);
  }
  inline bool operator>(const GnssClock& rhs) const {
    return std::tie(gnssClockFlags, leapSecond, timeNs, timeUncertaintyNs, fullBiasNs, biasNs, biasUncertaintyNs, driftNsps, driftUncertaintyNsps, hwClockDiscontinuityCount, referenceSignalTypeForIsb) > std::tie(rhs.gnssClockFlags, rhs.leapSecond, rhs.timeNs, rhs.timeUncertaintyNs, rhs.fullBiasNs, rhs.biasNs, rhs.biasUncertaintyNs, rhs.driftNsps, rhs.driftUncertaintyNsps, rhs.hwClockDiscontinuityCount, rhs.referenceSignalTypeForIsb);
  }
  inline bool operator>=(const GnssClock& rhs) const {
    return std::tie(gnssClockFlags, leapSecond, timeNs, timeUncertaintyNs, fullBiasNs, biasNs, biasUncertaintyNs, driftNsps, driftUncertaintyNsps, hwClockDiscontinuityCount, referenceSignalTypeForIsb) >= std::tie(rhs.gnssClockFlags, rhs.leapSecond, rhs.timeNs, rhs.timeUncertaintyNs, rhs.fullBiasNs, rhs.biasNs, rhs.biasUncertaintyNs, rhs.driftNsps, rhs.driftUncertaintyNsps, rhs.hwClockDiscontinuityCount, rhs.referenceSignalTypeForIsb);
  }

  int32_t gnssClockFlags = int32_t(0);
  int32_t leapSecond = int32_t(0);
  int64_t timeNs = int64_t(0L);
  double timeUncertaintyNs = double(0.000000);
  int64_t fullBiasNs = int64_t(0L);
  double biasNs = double(0.000000);
  double biasUncertaintyNs = double(0.000000);
  double driftNsps = double(0.000000);
  double driftUncertaintyNsps = double(0.000000);
  int32_t hwClockDiscontinuityCount = int32_t(0);
  ::android::hardware::gnss::GnssSignalType referenceSignalTypeForIsb;
  enum  : int32_t {
    HAS_LEAP_SECOND = 1,
    HAS_TIME_UNCERTAINTY = 2,
    HAS_FULL_BIAS = 4,
    HAS_BIAS = 8,
    HAS_BIAS_UNCERTAINTY = 16,
    HAS_DRIFT = 32,
    HAS_DRIFT_UNCERTAINTY = 64,
  };
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.gnss.GnssClock");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "GnssClock{";
    os << "gnssClockFlags: " << ::android::internal::ToString(gnssClockFlags);
    os << ", leapSecond: " << ::android::internal::ToString(leapSecond);
    os << ", timeNs: " << ::android::internal::ToString(timeNs);
    os << ", timeUncertaintyNs: " << ::android::internal::ToString(timeUncertaintyNs);
    os << ", fullBiasNs: " << ::android::internal::ToString(fullBiasNs);
    os << ", biasNs: " << ::android::internal::ToString(biasNs);
    os << ", biasUncertaintyNs: " << ::android::internal::ToString(biasUncertaintyNs);
    os << ", driftNsps: " << ::android::internal::ToString(driftNsps);
    os << ", driftUncertaintyNsps: " << ::android::internal::ToString(driftUncertaintyNsps);
    os << ", hwClockDiscontinuityCount: " << ::android::internal::ToString(hwClockDiscontinuityCount);
    os << ", referenceSignalTypeForIsb: " << ::android::internal::ToString(referenceSignalTypeForIsb);
    os << "}";
    return os.str();
  }
};  // class GnssClock

}  // namespace gnss

}  // namespace hardware

}  // namespace android
