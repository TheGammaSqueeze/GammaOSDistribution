#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace system {

namespace keystore2 {

class EphemeralStorageKeyResponse : public ::android::Parcelable {
public:
  inline bool operator!=(const EphemeralStorageKeyResponse& rhs) const {
    return std::tie(ephemeralKey, upgradedBlob) != std::tie(rhs.ephemeralKey, rhs.upgradedBlob);
  }
  inline bool operator<(const EphemeralStorageKeyResponse& rhs) const {
    return std::tie(ephemeralKey, upgradedBlob) < std::tie(rhs.ephemeralKey, rhs.upgradedBlob);
  }
  inline bool operator<=(const EphemeralStorageKeyResponse& rhs) const {
    return std::tie(ephemeralKey, upgradedBlob) <= std::tie(rhs.ephemeralKey, rhs.upgradedBlob);
  }
  inline bool operator==(const EphemeralStorageKeyResponse& rhs) const {
    return std::tie(ephemeralKey, upgradedBlob) == std::tie(rhs.ephemeralKey, rhs.upgradedBlob);
  }
  inline bool operator>(const EphemeralStorageKeyResponse& rhs) const {
    return std::tie(ephemeralKey, upgradedBlob) > std::tie(rhs.ephemeralKey, rhs.upgradedBlob);
  }
  inline bool operator>=(const EphemeralStorageKeyResponse& rhs) const {
    return std::tie(ephemeralKey, upgradedBlob) >= std::tie(rhs.ephemeralKey, rhs.upgradedBlob);
  }

  ::std::vector<uint8_t> ephemeralKey;
  ::std::optional<::std::vector<uint8_t>> upgradedBlob;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.system.keystore2.EphemeralStorageKeyResponse");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "EphemeralStorageKeyResponse{";
    os << "ephemeralKey: " << ::android::internal::ToString(ephemeralKey);
    os << ", upgradedBlob: " << ::android::internal::ToString(upgradedBlob);
    os << "}";
    return os.str();
  }
};  // class EphemeralStorageKeyResponse

}  // namespace keystore2

}  // namespace system

}  // namespace android
