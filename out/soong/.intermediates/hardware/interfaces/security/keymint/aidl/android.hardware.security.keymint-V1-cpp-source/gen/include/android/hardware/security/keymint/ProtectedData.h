#pragma once

#include <android/binder_to_string.h>
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

class ProtectedData : public ::android::Parcelable {
public:
  inline bool operator!=(const ProtectedData& rhs) const {
    return std::tie(protectedData) != std::tie(rhs.protectedData);
  }
  inline bool operator<(const ProtectedData& rhs) const {
    return std::tie(protectedData) < std::tie(rhs.protectedData);
  }
  inline bool operator<=(const ProtectedData& rhs) const {
    return std::tie(protectedData) <= std::tie(rhs.protectedData);
  }
  inline bool operator==(const ProtectedData& rhs) const {
    return std::tie(protectedData) == std::tie(rhs.protectedData);
  }
  inline bool operator>(const ProtectedData& rhs) const {
    return std::tie(protectedData) > std::tie(rhs.protectedData);
  }
  inline bool operator>=(const ProtectedData& rhs) const {
    return std::tie(protectedData) >= std::tie(rhs.protectedData);
  }

  ::std::vector<uint8_t> protectedData;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.security.keymint.ProtectedData");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "ProtectedData{";
    os << "protectedData: " << ::android::internal::ToString(protectedData);
    os << "}";
    return os.str();
  }
};  // class ProtectedData

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
