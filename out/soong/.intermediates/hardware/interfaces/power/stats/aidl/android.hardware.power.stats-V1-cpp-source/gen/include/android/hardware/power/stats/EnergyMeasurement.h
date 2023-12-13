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

class EnergyMeasurement : public ::android::Parcelable {
public:
  inline bool operator!=(const EnergyMeasurement& rhs) const {
    return std::tie(id, timestampMs, durationMs, energyUWs) != std::tie(rhs.id, rhs.timestampMs, rhs.durationMs, rhs.energyUWs);
  }
  inline bool operator<(const EnergyMeasurement& rhs) const {
    return std::tie(id, timestampMs, durationMs, energyUWs) < std::tie(rhs.id, rhs.timestampMs, rhs.durationMs, rhs.energyUWs);
  }
  inline bool operator<=(const EnergyMeasurement& rhs) const {
    return std::tie(id, timestampMs, durationMs, energyUWs) <= std::tie(rhs.id, rhs.timestampMs, rhs.durationMs, rhs.energyUWs);
  }
  inline bool operator==(const EnergyMeasurement& rhs) const {
    return std::tie(id, timestampMs, durationMs, energyUWs) == std::tie(rhs.id, rhs.timestampMs, rhs.durationMs, rhs.energyUWs);
  }
  inline bool operator>(const EnergyMeasurement& rhs) const {
    return std::tie(id, timestampMs, durationMs, energyUWs) > std::tie(rhs.id, rhs.timestampMs, rhs.durationMs, rhs.energyUWs);
  }
  inline bool operator>=(const EnergyMeasurement& rhs) const {
    return std::tie(id, timestampMs, durationMs, energyUWs) >= std::tie(rhs.id, rhs.timestampMs, rhs.durationMs, rhs.energyUWs);
  }

  int32_t id = int32_t(0);
  int64_t timestampMs = int64_t(0L);
  int64_t durationMs = int64_t(0L);
  int64_t energyUWs = int64_t(0L);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.power.stats.EnergyMeasurement");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "EnergyMeasurement{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", timestampMs: " << ::android::internal::ToString(timestampMs);
    os << ", durationMs: " << ::android::internal::ToString(durationMs);
    os << ", energyUWs: " << ::android::internal::ToString(energyUWs);
    os << "}";
    return os.str();
  }
};  // class EnergyMeasurement

}  // namespace stats

}  // namespace power

}  // namespace hardware

}  // namespace android
