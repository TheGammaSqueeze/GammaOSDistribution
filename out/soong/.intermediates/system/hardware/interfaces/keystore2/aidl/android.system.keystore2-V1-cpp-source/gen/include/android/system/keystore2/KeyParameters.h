#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/security/keymint/KeyParameter.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace system {

namespace keystore2 {

class KeyParameters : public ::android::Parcelable {
public:
  inline bool operator!=(const KeyParameters& rhs) const {
    return std::tie(keyParameter) != std::tie(rhs.keyParameter);
  }
  inline bool operator<(const KeyParameters& rhs) const {
    return std::tie(keyParameter) < std::tie(rhs.keyParameter);
  }
  inline bool operator<=(const KeyParameters& rhs) const {
    return std::tie(keyParameter) <= std::tie(rhs.keyParameter);
  }
  inline bool operator==(const KeyParameters& rhs) const {
    return std::tie(keyParameter) == std::tie(rhs.keyParameter);
  }
  inline bool operator>(const KeyParameters& rhs) const {
    return std::tie(keyParameter) > std::tie(rhs.keyParameter);
  }
  inline bool operator>=(const KeyParameters& rhs) const {
    return std::tie(keyParameter) >= std::tie(rhs.keyParameter);
  }

  ::std::vector<::android::hardware::security::keymint::KeyParameter> keyParameter;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.system.keystore2.KeyParameters");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "KeyParameters{";
    os << "keyParameter: " << ::android::internal::ToString(keyParameter);
    os << "}";
    return os.str();
  }
};  // class KeyParameters

}  // namespace keystore2

}  // namespace system

}  // namespace android
