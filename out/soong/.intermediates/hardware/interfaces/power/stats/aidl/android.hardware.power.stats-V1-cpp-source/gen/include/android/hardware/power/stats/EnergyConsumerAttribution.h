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

class EnergyConsumerAttribution : public ::android::Parcelable {
public:
  inline bool operator!=(const EnergyConsumerAttribution& rhs) const {
    return std::tie(uid, energyUWs) != std::tie(rhs.uid, rhs.energyUWs);
  }
  inline bool operator<(const EnergyConsumerAttribution& rhs) const {
    return std::tie(uid, energyUWs) < std::tie(rhs.uid, rhs.energyUWs);
  }
  inline bool operator<=(const EnergyConsumerAttribution& rhs) const {
    return std::tie(uid, energyUWs) <= std::tie(rhs.uid, rhs.energyUWs);
  }
  inline bool operator==(const EnergyConsumerAttribution& rhs) const {
    return std::tie(uid, energyUWs) == std::tie(rhs.uid, rhs.energyUWs);
  }
  inline bool operator>(const EnergyConsumerAttribution& rhs) const {
    return std::tie(uid, energyUWs) > std::tie(rhs.uid, rhs.energyUWs);
  }
  inline bool operator>=(const EnergyConsumerAttribution& rhs) const {
    return std::tie(uid, energyUWs) >= std::tie(rhs.uid, rhs.energyUWs);
  }

  int32_t uid = int32_t(0);
  int64_t energyUWs = int64_t(0L);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.power.stats.EnergyConsumerAttribution");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "EnergyConsumerAttribution{";
    os << "uid: " << ::android::internal::ToString(uid);
    os << ", energyUWs: " << ::android::internal::ToString(energyUWs);
    os << "}";
    return os.str();
  }
};  // class EnergyConsumerAttribution

}  // namespace stats

}  // namespace power

}  // namespace hardware

}  // namespace android
