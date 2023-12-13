#pragma once

#include <android/binder_to_string.h>
#include <android/security/identity/ResultNamespaceParcel.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace security {

namespace identity {

class GetEntriesResultParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const GetEntriesResultParcel& rhs) const {
    return std::tie(resultNamespaces, deviceNameSpaces, mac, staticAuthenticationData) != std::tie(rhs.resultNamespaces, rhs.deviceNameSpaces, rhs.mac, rhs.staticAuthenticationData);
  }
  inline bool operator<(const GetEntriesResultParcel& rhs) const {
    return std::tie(resultNamespaces, deviceNameSpaces, mac, staticAuthenticationData) < std::tie(rhs.resultNamespaces, rhs.deviceNameSpaces, rhs.mac, rhs.staticAuthenticationData);
  }
  inline bool operator<=(const GetEntriesResultParcel& rhs) const {
    return std::tie(resultNamespaces, deviceNameSpaces, mac, staticAuthenticationData) <= std::tie(rhs.resultNamespaces, rhs.deviceNameSpaces, rhs.mac, rhs.staticAuthenticationData);
  }
  inline bool operator==(const GetEntriesResultParcel& rhs) const {
    return std::tie(resultNamespaces, deviceNameSpaces, mac, staticAuthenticationData) == std::tie(rhs.resultNamespaces, rhs.deviceNameSpaces, rhs.mac, rhs.staticAuthenticationData);
  }
  inline bool operator>(const GetEntriesResultParcel& rhs) const {
    return std::tie(resultNamespaces, deviceNameSpaces, mac, staticAuthenticationData) > std::tie(rhs.resultNamespaces, rhs.deviceNameSpaces, rhs.mac, rhs.staticAuthenticationData);
  }
  inline bool operator>=(const GetEntriesResultParcel& rhs) const {
    return std::tie(resultNamespaces, deviceNameSpaces, mac, staticAuthenticationData) >= std::tie(rhs.resultNamespaces, rhs.deviceNameSpaces, rhs.mac, rhs.staticAuthenticationData);
  }

  ::std::vector<::android::security::identity::ResultNamespaceParcel> resultNamespaces;
  ::std::vector<uint8_t> deviceNameSpaces;
  ::std::vector<uint8_t> mac;
  ::std::vector<uint8_t> staticAuthenticationData;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.security.identity.GetEntriesResultParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "GetEntriesResultParcel{";
    os << "resultNamespaces: " << ::android::internal::ToString(resultNamespaces);
    os << ", deviceNameSpaces: " << ::android::internal::ToString(deviceNameSpaces);
    os << ", mac: " << ::android::internal::ToString(mac);
    os << ", staticAuthenticationData: " << ::android::internal::ToString(staticAuthenticationData);
    os << "}";
    return os.str();
  }
};  // class GetEntriesResultParcel

}  // namespace identity

}  // namespace security

}  // namespace android
