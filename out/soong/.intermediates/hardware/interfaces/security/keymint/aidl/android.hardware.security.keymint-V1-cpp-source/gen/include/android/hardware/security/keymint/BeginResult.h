#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/security/keymint/IKeyMintOperation.h>
#include <android/hardware/security/keymint/KeyParameter.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

class BeginResult : public ::android::Parcelable {
public:
  inline bool operator!=(const BeginResult& rhs) const {
    return std::tie(challenge, params, operation) != std::tie(rhs.challenge, rhs.params, rhs.operation);
  }
  inline bool operator<(const BeginResult& rhs) const {
    return std::tie(challenge, params, operation) < std::tie(rhs.challenge, rhs.params, rhs.operation);
  }
  inline bool operator<=(const BeginResult& rhs) const {
    return std::tie(challenge, params, operation) <= std::tie(rhs.challenge, rhs.params, rhs.operation);
  }
  inline bool operator==(const BeginResult& rhs) const {
    return std::tie(challenge, params, operation) == std::tie(rhs.challenge, rhs.params, rhs.operation);
  }
  inline bool operator>(const BeginResult& rhs) const {
    return std::tie(challenge, params, operation) > std::tie(rhs.challenge, rhs.params, rhs.operation);
  }
  inline bool operator>=(const BeginResult& rhs) const {
    return std::tie(challenge, params, operation) >= std::tie(rhs.challenge, rhs.params, rhs.operation);
  }

  int64_t challenge = int64_t(0L);
  ::std::vector<::android::hardware::security::keymint::KeyParameter> params;
  ::android::sp<::android::hardware::security::keymint::IKeyMintOperation> operation;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.security.keymint.BeginResult");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "BeginResult{";
    os << "challenge: " << ::android::internal::ToString(challenge);
    os << ", params: " << ::android::internal::ToString(params);
    os << ", operation: " << ::android::internal::ToString(operation);
    os << "}";
    return os.str();
  }
};  // class BeginResult

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
