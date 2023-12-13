#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/keymaster/SecurityLevel.h>
#include <android/hardware/keymaster/Timestamp.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace keymaster {

class VerificationToken : public ::android::Parcelable {
public:
  inline bool operator!=(const VerificationToken& rhs) const {
    return std::tie(challenge, timestamp, securityLevel, mac) != std::tie(rhs.challenge, rhs.timestamp, rhs.securityLevel, rhs.mac);
  }
  inline bool operator<(const VerificationToken& rhs) const {
    return std::tie(challenge, timestamp, securityLevel, mac) < std::tie(rhs.challenge, rhs.timestamp, rhs.securityLevel, rhs.mac);
  }
  inline bool operator<=(const VerificationToken& rhs) const {
    return std::tie(challenge, timestamp, securityLevel, mac) <= std::tie(rhs.challenge, rhs.timestamp, rhs.securityLevel, rhs.mac);
  }
  inline bool operator==(const VerificationToken& rhs) const {
    return std::tie(challenge, timestamp, securityLevel, mac) == std::tie(rhs.challenge, rhs.timestamp, rhs.securityLevel, rhs.mac);
  }
  inline bool operator>(const VerificationToken& rhs) const {
    return std::tie(challenge, timestamp, securityLevel, mac) > std::tie(rhs.challenge, rhs.timestamp, rhs.securityLevel, rhs.mac);
  }
  inline bool operator>=(const VerificationToken& rhs) const {
    return std::tie(challenge, timestamp, securityLevel, mac) >= std::tie(rhs.challenge, rhs.timestamp, rhs.securityLevel, rhs.mac);
  }

  int64_t challenge = int64_t(0L);
  ::android::hardware::keymaster::Timestamp timestamp;
  ::android::hardware::keymaster::SecurityLevel securityLevel = ::android::hardware::keymaster::SecurityLevel(::android::hardware::keymaster::SecurityLevel::SOFTWARE);
  ::std::vector<uint8_t> mac;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.keymaster.VerificationToken");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "VerificationToken{";
    os << "challenge: " << ::android::internal::ToString(challenge);
    os << ", timestamp: " << ::android::internal::ToString(timestamp);
    os << ", securityLevel: " << ::android::internal::ToString(securityLevel);
    os << ", mac: " << ::android::internal::ToString(mac);
    os << "}";
    return os.str();
  }
};  // class VerificationToken

}  // namespace keymaster

}  // namespace hardware

}  // namespace android
