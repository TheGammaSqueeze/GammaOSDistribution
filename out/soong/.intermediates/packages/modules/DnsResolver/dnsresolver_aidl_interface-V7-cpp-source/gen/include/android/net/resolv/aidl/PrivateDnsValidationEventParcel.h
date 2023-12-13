#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace net {

namespace resolv {

namespace aidl {

class PrivateDnsValidationEventParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const PrivateDnsValidationEventParcel& rhs) const {
    return std::tie(netId, ipAddress, hostname, validation) != std::tie(rhs.netId, rhs.ipAddress, rhs.hostname, rhs.validation);
  }
  inline bool operator<(const PrivateDnsValidationEventParcel& rhs) const {
    return std::tie(netId, ipAddress, hostname, validation) < std::tie(rhs.netId, rhs.ipAddress, rhs.hostname, rhs.validation);
  }
  inline bool operator<=(const PrivateDnsValidationEventParcel& rhs) const {
    return std::tie(netId, ipAddress, hostname, validation) <= std::tie(rhs.netId, rhs.ipAddress, rhs.hostname, rhs.validation);
  }
  inline bool operator==(const PrivateDnsValidationEventParcel& rhs) const {
    return std::tie(netId, ipAddress, hostname, validation) == std::tie(rhs.netId, rhs.ipAddress, rhs.hostname, rhs.validation);
  }
  inline bool operator>(const PrivateDnsValidationEventParcel& rhs) const {
    return std::tie(netId, ipAddress, hostname, validation) > std::tie(rhs.netId, rhs.ipAddress, rhs.hostname, rhs.validation);
  }
  inline bool operator>=(const PrivateDnsValidationEventParcel& rhs) const {
    return std::tie(netId, ipAddress, hostname, validation) >= std::tie(rhs.netId, rhs.ipAddress, rhs.hostname, rhs.validation);
  }

  int32_t netId = int32_t(0);
  ::std::string ipAddress;
  ::std::string hostname;
  int32_t validation = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.resolv.aidl.PrivateDnsValidationEventParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "PrivateDnsValidationEventParcel{";
    os << "netId: " << ::android::internal::ToString(netId);
    os << ", ipAddress: " << ::android::internal::ToString(ipAddress);
    os << ", hostname: " << ::android::internal::ToString(hostname);
    os << ", validation: " << ::android::internal::ToString(validation);
    os << "}";
    return os.str();
  }
};  // class PrivateDnsValidationEventParcel

}  // namespace aidl

}  // namespace resolv

}  // namespace net

}  // namespace android
