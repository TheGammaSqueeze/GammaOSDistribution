#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/gnss/ElapsedRealtime.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace gnss {

class GnssPowerStats : public ::android::Parcelable {
public:
  inline bool operator!=(const GnssPowerStats& rhs) const {
    return std::tie(elapsedRealtime, totalEnergyMilliJoule, singlebandTrackingModeEnergyMilliJoule, multibandTrackingModeEnergyMilliJoule, singlebandAcquisitionModeEnergyMilliJoule, multibandAcquisitionModeEnergyMilliJoule, otherModesEnergyMilliJoule) != std::tie(rhs.elapsedRealtime, rhs.totalEnergyMilliJoule, rhs.singlebandTrackingModeEnergyMilliJoule, rhs.multibandTrackingModeEnergyMilliJoule, rhs.singlebandAcquisitionModeEnergyMilliJoule, rhs.multibandAcquisitionModeEnergyMilliJoule, rhs.otherModesEnergyMilliJoule);
  }
  inline bool operator<(const GnssPowerStats& rhs) const {
    return std::tie(elapsedRealtime, totalEnergyMilliJoule, singlebandTrackingModeEnergyMilliJoule, multibandTrackingModeEnergyMilliJoule, singlebandAcquisitionModeEnergyMilliJoule, multibandAcquisitionModeEnergyMilliJoule, otherModesEnergyMilliJoule) < std::tie(rhs.elapsedRealtime, rhs.totalEnergyMilliJoule, rhs.singlebandTrackingModeEnergyMilliJoule, rhs.multibandTrackingModeEnergyMilliJoule, rhs.singlebandAcquisitionModeEnergyMilliJoule, rhs.multibandAcquisitionModeEnergyMilliJoule, rhs.otherModesEnergyMilliJoule);
  }
  inline bool operator<=(const GnssPowerStats& rhs) const {
    return std::tie(elapsedRealtime, totalEnergyMilliJoule, singlebandTrackingModeEnergyMilliJoule, multibandTrackingModeEnergyMilliJoule, singlebandAcquisitionModeEnergyMilliJoule, multibandAcquisitionModeEnergyMilliJoule, otherModesEnergyMilliJoule) <= std::tie(rhs.elapsedRealtime, rhs.totalEnergyMilliJoule, rhs.singlebandTrackingModeEnergyMilliJoule, rhs.multibandTrackingModeEnergyMilliJoule, rhs.singlebandAcquisitionModeEnergyMilliJoule, rhs.multibandAcquisitionModeEnergyMilliJoule, rhs.otherModesEnergyMilliJoule);
  }
  inline bool operator==(const GnssPowerStats& rhs) const {
    return std::tie(elapsedRealtime, totalEnergyMilliJoule, singlebandTrackingModeEnergyMilliJoule, multibandTrackingModeEnergyMilliJoule, singlebandAcquisitionModeEnergyMilliJoule, multibandAcquisitionModeEnergyMilliJoule, otherModesEnergyMilliJoule) == std::tie(rhs.elapsedRealtime, rhs.totalEnergyMilliJoule, rhs.singlebandTrackingModeEnergyMilliJoule, rhs.multibandTrackingModeEnergyMilliJoule, rhs.singlebandAcquisitionModeEnergyMilliJoule, rhs.multibandAcquisitionModeEnergyMilliJoule, rhs.otherModesEnergyMilliJoule);
  }
  inline bool operator>(const GnssPowerStats& rhs) const {
    return std::tie(elapsedRealtime, totalEnergyMilliJoule, singlebandTrackingModeEnergyMilliJoule, multibandTrackingModeEnergyMilliJoule, singlebandAcquisitionModeEnergyMilliJoule, multibandAcquisitionModeEnergyMilliJoule, otherModesEnergyMilliJoule) > std::tie(rhs.elapsedRealtime, rhs.totalEnergyMilliJoule, rhs.singlebandTrackingModeEnergyMilliJoule, rhs.multibandTrackingModeEnergyMilliJoule, rhs.singlebandAcquisitionModeEnergyMilliJoule, rhs.multibandAcquisitionModeEnergyMilliJoule, rhs.otherModesEnergyMilliJoule);
  }
  inline bool operator>=(const GnssPowerStats& rhs) const {
    return std::tie(elapsedRealtime, totalEnergyMilliJoule, singlebandTrackingModeEnergyMilliJoule, multibandTrackingModeEnergyMilliJoule, singlebandAcquisitionModeEnergyMilliJoule, multibandAcquisitionModeEnergyMilliJoule, otherModesEnergyMilliJoule) >= std::tie(rhs.elapsedRealtime, rhs.totalEnergyMilliJoule, rhs.singlebandTrackingModeEnergyMilliJoule, rhs.multibandTrackingModeEnergyMilliJoule, rhs.singlebandAcquisitionModeEnergyMilliJoule, rhs.multibandAcquisitionModeEnergyMilliJoule, rhs.otherModesEnergyMilliJoule);
  }

  ::android::hardware::gnss::ElapsedRealtime elapsedRealtime;
  double totalEnergyMilliJoule = double(0.000000);
  double singlebandTrackingModeEnergyMilliJoule = double(0.000000);
  double multibandTrackingModeEnergyMilliJoule = double(0.000000);
  double singlebandAcquisitionModeEnergyMilliJoule = double(0.000000);
  double multibandAcquisitionModeEnergyMilliJoule = double(0.000000);
  ::std::vector<double> otherModesEnergyMilliJoule;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.gnss.GnssPowerStats");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "GnssPowerStats{";
    os << "elapsedRealtime: " << ::android::internal::ToString(elapsedRealtime);
    os << ", totalEnergyMilliJoule: " << ::android::internal::ToString(totalEnergyMilliJoule);
    os << ", singlebandTrackingModeEnergyMilliJoule: " << ::android::internal::ToString(singlebandTrackingModeEnergyMilliJoule);
    os << ", multibandTrackingModeEnergyMilliJoule: " << ::android::internal::ToString(multibandTrackingModeEnergyMilliJoule);
    os << ", singlebandAcquisitionModeEnergyMilliJoule: " << ::android::internal::ToString(singlebandAcquisitionModeEnergyMilliJoule);
    os << ", multibandAcquisitionModeEnergyMilliJoule: " << ::android::internal::ToString(multibandAcquisitionModeEnergyMilliJoule);
    os << ", otherModesEnergyMilliJoule: " << ::android::internal::ToString(otherModesEnergyMilliJoule);
    os << "}";
    return os.str();
  }
};  // class GnssPowerStats

}  // namespace gnss

}  // namespace hardware

}  // namespace android
