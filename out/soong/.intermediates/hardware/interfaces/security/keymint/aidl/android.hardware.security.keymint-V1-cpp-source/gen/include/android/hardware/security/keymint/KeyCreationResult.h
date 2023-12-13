#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/security/keymint/Certificate.h>
#include <android/hardware/security/keymint/KeyCharacteristics.h>
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

class KeyCreationResult : public ::android::Parcelable {
public:
  inline bool operator!=(const KeyCreationResult& rhs) const {
    return std::tie(keyBlob, keyCharacteristics, certificateChain) != std::tie(rhs.keyBlob, rhs.keyCharacteristics, rhs.certificateChain);
  }
  inline bool operator<(const KeyCreationResult& rhs) const {
    return std::tie(keyBlob, keyCharacteristics, certificateChain) < std::tie(rhs.keyBlob, rhs.keyCharacteristics, rhs.certificateChain);
  }
  inline bool operator<=(const KeyCreationResult& rhs) const {
    return std::tie(keyBlob, keyCharacteristics, certificateChain) <= std::tie(rhs.keyBlob, rhs.keyCharacteristics, rhs.certificateChain);
  }
  inline bool operator==(const KeyCreationResult& rhs) const {
    return std::tie(keyBlob, keyCharacteristics, certificateChain) == std::tie(rhs.keyBlob, rhs.keyCharacteristics, rhs.certificateChain);
  }
  inline bool operator>(const KeyCreationResult& rhs) const {
    return std::tie(keyBlob, keyCharacteristics, certificateChain) > std::tie(rhs.keyBlob, rhs.keyCharacteristics, rhs.certificateChain);
  }
  inline bool operator>=(const KeyCreationResult& rhs) const {
    return std::tie(keyBlob, keyCharacteristics, certificateChain) >= std::tie(rhs.keyBlob, rhs.keyCharacteristics, rhs.certificateChain);
  }

  ::std::vector<uint8_t> keyBlob;
  ::std::vector<::android::hardware::security::keymint::KeyCharacteristics> keyCharacteristics;
  ::std::vector<::android::hardware::security::keymint::Certificate> certificateChain;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.security.keymint.KeyCreationResult");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "KeyCreationResult{";
    os << "keyBlob: " << ::android::internal::ToString(keyBlob);
    os << ", keyCharacteristics: " << ::android::internal::ToString(keyCharacteristics);
    os << ", certificateChain: " << ::android::internal::ToString(certificateChain);
    os << "}";
    return os.str();
  }
};  // class KeyCreationResult

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
