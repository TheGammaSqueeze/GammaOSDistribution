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

class Channel : public ::android::Parcelable {
public:
  inline bool operator!=(const Channel& rhs) const {
    return std::tie(id, name, subsystem) != std::tie(rhs.id, rhs.name, rhs.subsystem);
  }
  inline bool operator<(const Channel& rhs) const {
    return std::tie(id, name, subsystem) < std::tie(rhs.id, rhs.name, rhs.subsystem);
  }
  inline bool operator<=(const Channel& rhs) const {
    return std::tie(id, name, subsystem) <= std::tie(rhs.id, rhs.name, rhs.subsystem);
  }
  inline bool operator==(const Channel& rhs) const {
    return std::tie(id, name, subsystem) == std::tie(rhs.id, rhs.name, rhs.subsystem);
  }
  inline bool operator>(const Channel& rhs) const {
    return std::tie(id, name, subsystem) > std::tie(rhs.id, rhs.name, rhs.subsystem);
  }
  inline bool operator>=(const Channel& rhs) const {
    return std::tie(id, name, subsystem) >= std::tie(rhs.id, rhs.name, rhs.subsystem);
  }

  int32_t id = int32_t(0);
  ::std::string name;
  ::std::string subsystem;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.power.stats.Channel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "Channel{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", name: " << ::android::internal::ToString(name);
    os << ", subsystem: " << ::android::internal::ToString(subsystem);
    os << "}";
    return os.str();
  }
};  // class Channel

}  // namespace stats

}  // namespace power

}  // namespace hardware

}  // namespace android
