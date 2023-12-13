#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/security/keymint/KeyParameterValue.h>
#include <android/hardware/security/keymint/Tag.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

class KeyParameter : public ::android::Parcelable {
public:
  inline bool operator!=(const KeyParameter& rhs) const {
    return std::tie(tag, value) != std::tie(rhs.tag, rhs.value);
  }
  inline bool operator<(const KeyParameter& rhs) const {
    return std::tie(tag, value) < std::tie(rhs.tag, rhs.value);
  }
  inline bool operator<=(const KeyParameter& rhs) const {
    return std::tie(tag, value) <= std::tie(rhs.tag, rhs.value);
  }
  inline bool operator==(const KeyParameter& rhs) const {
    return std::tie(tag, value) == std::tie(rhs.tag, rhs.value);
  }
  inline bool operator>(const KeyParameter& rhs) const {
    return std::tie(tag, value) > std::tie(rhs.tag, rhs.value);
  }
  inline bool operator>=(const KeyParameter& rhs) const {
    return std::tie(tag, value) >= std::tie(rhs.tag, rhs.value);
  }

  ::android::hardware::security::keymint::Tag tag = ::android::hardware::security::keymint::Tag(::android::hardware::security::keymint::Tag::INVALID);
  ::android::hardware::security::keymint::KeyParameterValue value;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.security.keymint.KeyParameter");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "KeyParameter{";
    os << "tag: " << ::android::internal::ToString(tag);
    os << ", value: " << ::android::internal::ToString(value);
    os << "}";
    return os.str();
  }
};  // class KeyParameter

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
