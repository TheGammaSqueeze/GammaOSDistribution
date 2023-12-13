#pragma once

#include <android/binder_to_string.h>
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

class State : public ::android::Parcelable {
public:
  inline bool operator!=(const State& rhs) const {
    return std::tie(id, name) != std::tie(rhs.id, rhs.name);
  }
  inline bool operator<(const State& rhs) const {
    return std::tie(id, name) < std::tie(rhs.id, rhs.name);
  }
  inline bool operator<=(const State& rhs) const {
    return std::tie(id, name) <= std::tie(rhs.id, rhs.name);
  }
  inline bool operator==(const State& rhs) const {
    return std::tie(id, name) == std::tie(rhs.id, rhs.name);
  }
  inline bool operator>(const State& rhs) const {
    return std::tie(id, name) > std::tie(rhs.id, rhs.name);
  }
  inline bool operator>=(const State& rhs) const {
    return std::tie(id, name) >= std::tie(rhs.id, rhs.name);
  }

  int32_t id = int32_t(0);
  ::std::string name;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.power.stats.State");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "State{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", name: " << ::android::internal::ToString(name);
    os << "}";
    return os.str();
  }
};  // class State

}  // namespace stats

}  // namespace power

}  // namespace hardware

}  // namespace android
