#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/power/stats/EnergyConsumerType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace power {

namespace stats {

class EnergyConsumer : public ::android::Parcelable {
public:
  inline bool operator!=(const EnergyConsumer& rhs) const {
    return std::tie(id, ordinal, type, name) != std::tie(rhs.id, rhs.ordinal, rhs.type, rhs.name);
  }
  inline bool operator<(const EnergyConsumer& rhs) const {
    return std::tie(id, ordinal, type, name) < std::tie(rhs.id, rhs.ordinal, rhs.type, rhs.name);
  }
  inline bool operator<=(const EnergyConsumer& rhs) const {
    return std::tie(id, ordinal, type, name) <= std::tie(rhs.id, rhs.ordinal, rhs.type, rhs.name);
  }
  inline bool operator==(const EnergyConsumer& rhs) const {
    return std::tie(id, ordinal, type, name) == std::tie(rhs.id, rhs.ordinal, rhs.type, rhs.name);
  }
  inline bool operator>(const EnergyConsumer& rhs) const {
    return std::tie(id, ordinal, type, name) > std::tie(rhs.id, rhs.ordinal, rhs.type, rhs.name);
  }
  inline bool operator>=(const EnergyConsumer& rhs) const {
    return std::tie(id, ordinal, type, name) >= std::tie(rhs.id, rhs.ordinal, rhs.type, rhs.name);
  }

  int32_t id = int32_t(0);
  int32_t ordinal = int32_t(0);
  ::android::hardware::power::stats::EnergyConsumerType type = ::android::hardware::power::stats::EnergyConsumerType(::android::hardware::power::stats::EnergyConsumerType::OTHER);
  ::std::string name;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.power.stats.EnergyConsumer");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "EnergyConsumer{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", ordinal: " << ::android::internal::ToString(ordinal);
    os << ", type: " << ::android::internal::ToString(type);
    os << ", name: " << ::android::internal::ToString(name);
    os << "}";
    return os.str();
  }
};  // class EnergyConsumer

}  // namespace stats

}  // namespace power

}  // namespace hardware

}  // namespace android
