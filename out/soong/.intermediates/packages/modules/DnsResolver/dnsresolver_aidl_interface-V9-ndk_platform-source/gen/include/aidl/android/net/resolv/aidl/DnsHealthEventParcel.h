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
class DnsHealthEventParcel {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t netId = 0;
  int32_t healthResult = 0;
  std::vector<int32_t> successRttMicros;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const DnsHealthEventParcel& rhs) const {
    return std::tie(netId, healthResult, successRttMicros) != std::tie(rhs.netId, rhs.healthResult, rhs.successRttMicros);
  }
  inline bool operator<(const DnsHealthEventParcel& rhs) const {
    return std::tie(netId, healthResult, successRttMicros) < std::tie(rhs.netId, rhs.healthResult, rhs.successRttMicros);
  }
  inline bool operator<=(const DnsHealthEventParcel& rhs) const {
    return std::tie(netId, healthResult, successRttMicros) <= std::tie(rhs.netId, rhs.healthResult, rhs.successRttMicros);
  }
  inline bool operator==(const DnsHealthEventParcel& rhs) const {
    return std::tie(netId, healthResult, successRttMicros) == std::tie(rhs.netId, rhs.healthResult, rhs.successRttMicros);
  }
  inline bool operator>(const DnsHealthEventParcel& rhs) const {
    return std::tie(netId, healthResult, successRttMicros) > std::tie(rhs.netId, rhs.healthResult, rhs.successRttMicros);
  }
  inline bool operator>=(const DnsHealthEventParcel& rhs) const {
    return std::tie(netId, healthResult, successRttMicros) >= std::tie(rhs.netId, rhs.healthResult, rhs.successRttMicros);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "DnsHealthEventParcel{";
    os << "netId: " << ::android::internal::ToString(netId);
    os << ", healthResult: " << ::android::internal::ToString(healthResult);
    os << ", successRttMicros: " << ::android::internal::ToString(successRttMicros);
    os << "}";
    return os.str();
  }
};
}  // namespace aidl
}  // namespace resolv
}  // namespace net
}  // namespace android
}  // namespace aidl
