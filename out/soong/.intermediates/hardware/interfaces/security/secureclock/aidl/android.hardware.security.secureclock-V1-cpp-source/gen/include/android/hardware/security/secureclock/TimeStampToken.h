#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/security/secureclock/Timestamp.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace security {

namespace secureclock {

class TimeStampToken : public ::android::Parcelable {
public:
  inline bool operator!=(const TimeStampToken& rhs) const {
    return std::tie(challenge, timestamp, mac) != std::tie(rhs.challenge, rhs.timestamp, rhs.mac);
  }
  inline bool operator<(const TimeStampToken& rhs) const {
    return std::tie(challenge, timestamp, mac) < std::tie(rhs.challenge, rhs.timestamp, rhs.mac);
  }
  inline bool operator<=(const TimeStampToken& rhs) const {
    return std::tie(challenge, timestamp, mac) <= std::tie(rhs.challenge, rhs.timestamp, rhs.mac);
  }
  inline bool operator==(const TimeStampToken& rhs) const {
    return std::tie(challenge, timestamp, mac) == std::tie(rhs.challenge, rhs.timestamp, rhs.mac);
  }
  inline bool operator>(const TimeStampToken& rhs) const {
    return std::tie(challenge, timestamp, mac) > std::tie(rhs.challenge, rhs.timestamp, rhs.mac);
  }
  inline bool operator>=(const TimeStampToken& rhs) const {
    return std::tie(challenge, timestamp, mac) >= std::tie(rhs.challenge, rhs.timestamp, rhs.mac);
  }

  int64_t challenge = int64_t(0L);
  ::android::hardware::security::secureclock::Timestamp timestamp;
  ::std::vector<uint8_t> mac;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.security.secureclock.TimeStampToken");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "TimeStampToken{";
    os << "challenge: " << ::android::internal::ToString(challenge);
    os << ", timestamp: " << ::android::internal::ToString(timestamp);
    os << ", mac: " << ::android::internal::ToString(mac);
    os << "}";
    return os.str();
  }
};  // class TimeStampToken

}  // namespace secureclock

}  // namespace security

}  // namespace hardware

}  // namespace android
