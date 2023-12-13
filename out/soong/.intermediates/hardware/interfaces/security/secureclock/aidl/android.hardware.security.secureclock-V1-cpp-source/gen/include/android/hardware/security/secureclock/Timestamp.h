#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace security {

namespace secureclock {

class Timestamp : public ::android::Parcelable {
public:
  inline bool operator!=(const Timestamp& rhs) const {
    return std::tie(milliSeconds) != std::tie(rhs.milliSeconds);
  }
  inline bool operator<(const Timestamp& rhs) const {
    return std::tie(milliSeconds) < std::tie(rhs.milliSeconds);
  }
  inline bool operator<=(const Timestamp& rhs) const {
    return std::tie(milliSeconds) <= std::tie(rhs.milliSeconds);
  }
  inline bool operator==(const Timestamp& rhs) const {
    return std::tie(milliSeconds) == std::tie(rhs.milliSeconds);
  }
  inline bool operator>(const Timestamp& rhs) const {
    return std::tie(milliSeconds) > std::tie(rhs.milliSeconds);
  }
  inline bool operator>=(const Timestamp& rhs) const {
    return std::tie(milliSeconds) >= std::tie(rhs.milliSeconds);
  }

  int64_t milliSeconds = int64_t(0L);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.security.secureclock.Timestamp");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "Timestamp{";
    os << "milliSeconds: " << ::android::internal::ToString(milliSeconds);
    os << "}";
    return os.str();
  }
};  // class Timestamp

}  // namespace secureclock

}  // namespace security

}  // namespace hardware

}  // namespace android
