#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/power/stats/State.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace power {

namespace stats {

class PowerEntity : public ::android::Parcelable {
public:
  inline bool operator!=(const PowerEntity& rhs) const {
    return std::tie(id, name, states) != std::tie(rhs.id, rhs.name, rhs.states);
  }
  inline bool operator<(const PowerEntity& rhs) const {
    return std::tie(id, name, states) < std::tie(rhs.id, rhs.name, rhs.states);
  }
  inline bool operator<=(const PowerEntity& rhs) const {
    return std::tie(id, name, states) <= std::tie(rhs.id, rhs.name, rhs.states);
  }
  inline bool operator==(const PowerEntity& rhs) const {
    return std::tie(id, name, states) == std::tie(rhs.id, rhs.name, rhs.states);
  }
  inline bool operator>(const PowerEntity& rhs) const {
    return std::tie(id, name, states) > std::tie(rhs.id, rhs.name, rhs.states);
  }
  inline bool operator>=(const PowerEntity& rhs) const {
    return std::tie(id, name, states) >= std::tie(rhs.id, rhs.name, rhs.states);
  }

  int32_t id = int32_t(0);
  ::std::string name;
  ::std::vector<::android::hardware::power::stats::State> states;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.power.stats.PowerEntity");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "PowerEntity{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", name: " << ::android::internal::ToString(name);
    os << ", states: " << ::android::internal::ToString(states);
    os << "}";
    return os.str();
  }
};  // class PowerEntity

}  // namespace stats

}  // namespace power

}  // namespace hardware

}  // namespace android
