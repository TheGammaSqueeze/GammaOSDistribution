#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/power/stats/EnergyConsumerAttribution.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace power {

namespace stats {

class EnergyConsumerResult : public ::android::Parcelable {
public:
  inline bool operator!=(const EnergyConsumerResult& rhs) const {
    return std::tie(id, timestampMs, energyUWs, attribution) != std::tie(rhs.id, rhs.timestampMs, rhs.energyUWs, rhs.attribution);
  }
  inline bool operator<(const EnergyConsumerResult& rhs) const {
    return std::tie(id, timestampMs, energyUWs, attribution) < std::tie(rhs.id, rhs.timestampMs, rhs.energyUWs, rhs.attribution);
  }
  inline bool operator<=(const EnergyConsumerResult& rhs) const {
    return std::tie(id, timestampMs, energyUWs, attribution) <= std::tie(rhs.id, rhs.timestampMs, rhs.energyUWs, rhs.attribution);
  }
  inline bool operator==(const EnergyConsumerResult& rhs) const {
    return std::tie(id, timestampMs, energyUWs, attribution) == std::tie(rhs.id, rhs.timestampMs, rhs.energyUWs, rhs.attribution);
  }
  inline bool operator>(const EnergyConsumerResult& rhs) const {
    return std::tie(id, timestampMs, energyUWs, attribution) > std::tie(rhs.id, rhs.timestampMs, rhs.energyUWs, rhs.attribution);
  }
  inline bool operator>=(const EnergyConsumerResult& rhs) const {
    return std::tie(id, timestampMs, energyUWs, attribution) >= std::tie(rhs.id, rhs.timestampMs, rhs.energyUWs, rhs.attribution);
  }

  int32_t id = int32_t(0);
  int64_t timestampMs = int64_t(0L);
  int64_t energyUWs = int64_t(0L);
  ::std::vector<::android::hardware::power::stats::EnergyConsumerAttribution> attribution;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.power.stats.EnergyConsumerResult");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "EnergyConsumerResult{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", timestampMs: " << ::android::internal::ToString(timestampMs);
    os << ", energyUWs: " << ::android::internal::ToString(energyUWs);
    os << ", attribution: " << ::android::internal::ToString(attribution);
    os << "}";
    return os.str();
  }
};  // class EnergyConsumerResult

}  // namespace stats

}  // namespace power

}  // namespace hardware

}  // namespace android
