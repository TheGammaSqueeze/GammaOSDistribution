#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace gnss {

class SatelliteClockInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const SatelliteClockInfo& rhs) const {
    return std::tie(satHardwareCodeBiasMeters, satTimeCorrectionMeters, satClkDriftMps) != std::tie(rhs.satHardwareCodeBiasMeters, rhs.satTimeCorrectionMeters, rhs.satClkDriftMps);
  }
  inline bool operator<(const SatelliteClockInfo& rhs) const {
    return std::tie(satHardwareCodeBiasMeters, satTimeCorrectionMeters, satClkDriftMps) < std::tie(rhs.satHardwareCodeBiasMeters, rhs.satTimeCorrectionMeters, rhs.satClkDriftMps);
  }
  inline bool operator<=(const SatelliteClockInfo& rhs) const {
    return std::tie(satHardwareCodeBiasMeters, satTimeCorrectionMeters, satClkDriftMps) <= std::tie(rhs.satHardwareCodeBiasMeters, rhs.satTimeCorrectionMeters, rhs.satClkDriftMps);
  }
  inline bool operator==(const SatelliteClockInfo& rhs) const {
    return std::tie(satHardwareCodeBiasMeters, satTimeCorrectionMeters, satClkDriftMps) == std::tie(rhs.satHardwareCodeBiasMeters, rhs.satTimeCorrectionMeters, rhs.satClkDriftMps);
  }
  inline bool operator>(const SatelliteClockInfo& rhs) const {
    return std::tie(satHardwareCodeBiasMeters, satTimeCorrectionMeters, satClkDriftMps) > std::tie(rhs.satHardwareCodeBiasMeters, rhs.satTimeCorrectionMeters, rhs.satClkDriftMps);
  }
  inline bool operator>=(const SatelliteClockInfo& rhs) const {
    return std::tie(satHardwareCodeBiasMeters, satTimeCorrectionMeters, satClkDriftMps) >= std::tie(rhs.satHardwareCodeBiasMeters, rhs.satTimeCorrectionMeters, rhs.satClkDriftMps);
  }

  double satHardwareCodeBiasMeters = double(0.000000);
  double satTimeCorrectionMeters = double(0.000000);
  double satClkDriftMps = double(0.000000);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.gnss.SatelliteClockInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "SatelliteClockInfo{";
    os << "satHardwareCodeBiasMeters: " << ::android::internal::ToString(satHardwareCodeBiasMeters);
    os << ", satTimeCorrectionMeters: " << ::android::internal::ToString(satTimeCorrectionMeters);
    os << ", satClkDriftMps: " << ::android::internal::ToString(satClkDriftMps);
    os << "}";
    return os.str();
  }
};  // class SatelliteClockInfo

}  // namespace gnss

}  // namespace hardware

}  // namespace android
