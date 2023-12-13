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
class ResolverHostsParcel {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  std::string ipAddr;
  std::string hostName = "";

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const ResolverHostsParcel& rhs) const {
    return std::tie(ipAddr, hostName) != std::tie(rhs.ipAddr, rhs.hostName);
  }
  inline bool operator<(const ResolverHostsParcel& rhs) const {
    return std::tie(ipAddr, hostName) < std::tie(rhs.ipAddr, rhs.hostName);
  }
  inline bool operator<=(const ResolverHostsParcel& rhs) const {
    return std::tie(ipAddr, hostName) <= std::tie(rhs.ipAddr, rhs.hostName);
  }
  inline bool operator==(const ResolverHostsParcel& rhs) const {
    return std::tie(ipAddr, hostName) == std::tie(rhs.ipAddr, rhs.hostName);
  }
  inline bool operator>(const ResolverHostsParcel& rhs) const {
    return std::tie(ipAddr, hostName) > std::tie(rhs.ipAddr, rhs.hostName);
  }
  inline bool operator>=(const ResolverHostsParcel& rhs) const {
    return std::tie(ipAddr, hostName) >= std::tie(rhs.ipAddr, rhs.hostName);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "ResolverHostsParcel{";
    os << "ipAddr: " << ::android::internal::ToString(ipAddr);
    os << ", hostName: " << ::android::internal::ToString(hostName);
    os << "}";
    return os.str();
  }
};
}  // namespace net
}  // namespace android
}  // namespace aidl
