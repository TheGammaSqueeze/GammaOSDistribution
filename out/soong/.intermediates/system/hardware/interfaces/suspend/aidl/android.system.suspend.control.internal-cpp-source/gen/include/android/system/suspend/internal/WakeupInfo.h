#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace system {

namespace suspend {

namespace internal {

class WakeupInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const WakeupInfo& rhs) const {
    return std::tie(name, count) != std::tie(rhs.name, rhs.count);
  }
  inline bool operator<(const WakeupInfo& rhs) const {
    return std::tie(name, count) < std::tie(rhs.name, rhs.count);
  }
  inline bool operator<=(const WakeupInfo& rhs) const {
    return std::tie(name, count) <= std::tie(rhs.name, rhs.count);
  }
  inline bool operator==(const WakeupInfo& rhs) const {
    return std::tie(name, count) == std::tie(rhs.name, rhs.count);
  }
  inline bool operator>(const WakeupInfo& rhs) const {
    return std::tie(name, count) > std::tie(rhs.name, rhs.count);
  }
  inline bool operator>=(const WakeupInfo& rhs) const {
    return std::tie(name, count) >= std::tie(rhs.name, rhs.count);
  }

  ::std::string name;
  int64_t count = int64_t(0L);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.system.suspend.internal.WakeupInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "WakeupInfo{";
    os << "name: " << ::android::internal::ToString(name);
    os << ", count: " << ::android::internal::ToString(count);
    os << "}";
    return os.str();
  }
};  // class WakeupInfo

}  // namespace internal

}  // namespace suspend

}  // namespace system

}  // namespace android
