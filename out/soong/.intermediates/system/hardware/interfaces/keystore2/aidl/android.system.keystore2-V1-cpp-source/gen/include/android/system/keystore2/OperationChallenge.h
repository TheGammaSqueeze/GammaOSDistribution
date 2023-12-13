#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace system {

namespace keystore2 {

class OperationChallenge : public ::android::Parcelable {
public:
  inline bool operator!=(const OperationChallenge& rhs) const {
    return std::tie(challenge) != std::tie(rhs.challenge);
  }
  inline bool operator<(const OperationChallenge& rhs) const {
    return std::tie(challenge) < std::tie(rhs.challenge);
  }
  inline bool operator<=(const OperationChallenge& rhs) const {
    return std::tie(challenge) <= std::tie(rhs.challenge);
  }
  inline bool operator==(const OperationChallenge& rhs) const {
    return std::tie(challenge) == std::tie(rhs.challenge);
  }
  inline bool operator>(const OperationChallenge& rhs) const {
    return std::tie(challenge) > std::tie(rhs.challenge);
  }
  inline bool operator>=(const OperationChallenge& rhs) const {
    return std::tie(challenge) >= std::tie(rhs.challenge);
  }

  int64_t challenge = int64_t(0L);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.system.keystore2.OperationChallenge");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "OperationChallenge{";
    os << "challenge: " << ::android::internal::ToString(challenge);
    os << "}";
    return os.str();
  }
};  // class OperationChallenge

}  // namespace keystore2

}  // namespace system

}  // namespace android
