#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace identity {

class HardwareInformation : public ::android::Parcelable {
public:
  inline bool operator!=(const HardwareInformation& rhs) const {
    return std::tie(credentialStoreName, credentialStoreAuthorName, dataChunkSize, isDirectAccess, supportedDocTypes) != std::tie(rhs.credentialStoreName, rhs.credentialStoreAuthorName, rhs.dataChunkSize, rhs.isDirectAccess, rhs.supportedDocTypes);
  }
  inline bool operator<(const HardwareInformation& rhs) const {
    return std::tie(credentialStoreName, credentialStoreAuthorName, dataChunkSize, isDirectAccess, supportedDocTypes) < std::tie(rhs.credentialStoreName, rhs.credentialStoreAuthorName, rhs.dataChunkSize, rhs.isDirectAccess, rhs.supportedDocTypes);
  }
  inline bool operator<=(const HardwareInformation& rhs) const {
    return std::tie(credentialStoreName, credentialStoreAuthorName, dataChunkSize, isDirectAccess, supportedDocTypes) <= std::tie(rhs.credentialStoreName, rhs.credentialStoreAuthorName, rhs.dataChunkSize, rhs.isDirectAccess, rhs.supportedDocTypes);
  }
  inline bool operator==(const HardwareInformation& rhs) const {
    return std::tie(credentialStoreName, credentialStoreAuthorName, dataChunkSize, isDirectAccess, supportedDocTypes) == std::tie(rhs.credentialStoreName, rhs.credentialStoreAuthorName, rhs.dataChunkSize, rhs.isDirectAccess, rhs.supportedDocTypes);
  }
  inline bool operator>(const HardwareInformation& rhs) const {
    return std::tie(credentialStoreName, credentialStoreAuthorName, dataChunkSize, isDirectAccess, supportedDocTypes) > std::tie(rhs.credentialStoreName, rhs.credentialStoreAuthorName, rhs.dataChunkSize, rhs.isDirectAccess, rhs.supportedDocTypes);
  }
  inline bool operator>=(const HardwareInformation& rhs) const {
    return std::tie(credentialStoreName, credentialStoreAuthorName, dataChunkSize, isDirectAccess, supportedDocTypes) >= std::tie(rhs.credentialStoreName, rhs.credentialStoreAuthorName, rhs.dataChunkSize, rhs.isDirectAccess, rhs.supportedDocTypes);
  }

  ::std::string credentialStoreName;
  ::std::string credentialStoreAuthorName;
  int32_t dataChunkSize = int32_t(0);
  bool isDirectAccess = bool(false);
  ::std::vector<::std::string> supportedDocTypes;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.identity.HardwareInformation");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "HardwareInformation{";
    os << "credentialStoreName: " << ::android::internal::ToString(credentialStoreName);
    os << ", credentialStoreAuthorName: " << ::android::internal::ToString(credentialStoreAuthorName);
    os << ", dataChunkSize: " << ::android::internal::ToString(dataChunkSize);
    os << ", isDirectAccess: " << ::android::internal::ToString(isDirectAccess);
    os << ", supportedDocTypes: " << ::android::internal::ToString(supportedDocTypes);
    os << "}";
    return os.str();
  }
};  // class HardwareInformation

}  // namespace identity

}  // namespace hardware

}  // namespace android
