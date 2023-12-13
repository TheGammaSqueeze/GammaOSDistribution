#pragma once
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
namespace aidl {
namespace android {
namespace net {
namespace resolv {
namespace aidl {
class PrivateDnsValidationEventParcel {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t netId = 0;
  std::string ipAddress;
  std::string hostname;
  int32_t validation = 0;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

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

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
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
};
}  // namespace aidl
}  // namespace resolv
}  // namespace net
}  // namespace android
}  // namespace aidl
