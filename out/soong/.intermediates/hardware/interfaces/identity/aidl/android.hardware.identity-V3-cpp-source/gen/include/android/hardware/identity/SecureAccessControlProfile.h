#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/identity/Certificate.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace identity {

class SecureAccessControlProfile : public ::android::Parcelable {
public:
  inline bool operator!=(const SecureAccessControlProfile& rhs) const {
    return std::tie(id, readerCertificate, userAuthenticationRequired, timeoutMillis, secureUserId, mac) != std::tie(rhs.id, rhs.readerCertificate, rhs.userAuthenticationRequired, rhs.timeoutMillis, rhs.secureUserId, rhs.mac);
  }
  inline bool operator<(const SecureAccessControlProfile& rhs) const {
    return std::tie(id, readerCertificate, userAuthenticationRequired, timeoutMillis, secureUserId, mac) < std::tie(rhs.id, rhs.readerCertificate, rhs.userAuthenticationRequired, rhs.timeoutMillis, rhs.secureUserId, rhs.mac);
  }
  inline bool operator<=(const SecureAccessControlProfile& rhs) const {
    return std::tie(id, readerCertificate, userAuthenticationRequired, timeoutMillis, secureUserId, mac) <= std::tie(rhs.id, rhs.readerCertificate, rhs.userAuthenticationRequired, rhs.timeoutMillis, rhs.secureUserId, rhs.mac);
  }
  inline bool operator==(const SecureAccessControlProfile& rhs) const {
    return std::tie(id, readerCertificate, userAuthenticationRequired, timeoutMillis, secureUserId, mac) == std::tie(rhs.id, rhs.readerCertificate, rhs.userAuthenticationRequired, rhs.timeoutMillis, rhs.secureUserId, rhs.mac);
  }
  inline bool operator>(const SecureAccessControlProfile& rhs) const {
    return std::tie(id, readerCertificate, userAuthenticationRequired, timeoutMillis, secureUserId, mac) > std::tie(rhs.id, rhs.readerCertificate, rhs.userAuthenticationRequired, rhs.timeoutMillis, rhs.secureUserId, rhs.mac);
  }
  inline bool operator>=(const SecureAccessControlProfile& rhs) const {
    return std::tie(id, readerCertificate, userAuthenticationRequired, timeoutMillis, secureUserId, mac) >= std::tie(rhs.id, rhs.readerCertificate, rhs.userAuthenticationRequired, rhs.timeoutMillis, rhs.secureUserId, rhs.mac);
  }

  int32_t id = int32_t(0);
  ::android::hardware::identity::Certificate readerCertificate;
  bool userAuthenticationRequired = bool(false);
  int64_t timeoutMillis = int64_t(0L);
  int64_t secureUserId = int64_t(0L);
  ::std::vector<uint8_t> mac;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.identity.SecureAccessControlProfile");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "SecureAccessControlProfile{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", readerCertificate: " << ::android::internal::ToString(readerCertificate);
    os << ", userAuthenticationRequired: " << ::android::internal::ToString(userAuthenticationRequired);
    os << ", timeoutMillis: " << ::android::internal::ToString(timeoutMillis);
    os << ", secureUserId: " << ::android::internal::ToString(secureUserId);
    os << ", mac: " << ::android::internal::ToString(mac);
    os << "}";
    return os.str();
  }
};  // class SecureAccessControlProfile

}  // namespace identity

}  // namespace hardware

}  // namespace android
