#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/power/stats/StateResidency.h>
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

class StateResidencyResult : public ::android::Parcelable {
public:
  inline bool operator!=(const StateResidencyResult& rhs) const {
    return std::tie(id, stateResidencyData) != std::tie(rhs.id, rhs.stateResidencyData);
  }
  inline bool operator<(const StateResidencyResult& rhs) const {
    return std::tie(id, stateResidencyData) < std::tie(rhs.id, rhs.stateResidencyData);
  }
  inline bool operator<=(const StateResidencyResult& rhs) const {
    return std::tie(id, stateResidencyData) <= std::tie(rhs.id, rhs.stateResidencyData);
  }
  inline bool operator==(const StateResidencyResult& rhs) const {
    return std::tie(id, stateResidencyData) == std::tie(rhs.id, rhs.stateResidencyData);
  }
  inline bool operator>(const StateResidencyResult& rhs) const {
    return std::tie(id, stateResidencyData) > std::tie(rhs.id, rhs.stateResidencyData);
  }
  inline bool operator>=(const StateResidencyResult& rhs) const {
    return std::tie(id, stateResidencyData) >= std::tie(rhs.id, rhs.stateResidencyData);
  }

  int32_t id = int32_t(0);
  ::std::vector<::android::hardware::power::stats::StateResidency> stateResidencyData;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.power.stats.StateResidencyResult");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "StateResidencyResult{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", stateResidencyData: " << ::android::internal::ToString(stateResidencyData);
    os << "}";
    return os.str();
  }
};  // class StateResidencyResult

}  // namespace stats

}  // namespace power

}  // namespace hardware

}  // namespace android
