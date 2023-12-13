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
#include <aidl/android/net/ResolverHostsParcel.h>
namespace aidl {
namespace android {
namespace net {
class ResolverOptionsParcel {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  std::vector<::aidl::android::net::ResolverHostsParcel> hosts = {};
  int32_t tcMode = 0;
  bool enforceDnsUid = false;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const ResolverOptionsParcel& rhs) const {
    return std::tie(hosts, tcMode, enforceDnsUid) != std::tie(rhs.hosts, rhs.tcMode, rhs.enforceDnsUid);
  }
  inline bool operator<(const ResolverOptionsParcel& rhs) const {
    return std::tie(hosts, tcMode, enforceDnsUid) < std::tie(rhs.hosts, rhs.tcMode, rhs.enforceDnsUid);
  }
  inline bool operator<=(const ResolverOptionsParcel& rhs) const {
    return std::tie(hosts, tcMode, enforceDnsUid) <= std::tie(rhs.hosts, rhs.tcMode, rhs.enforceDnsUid);
  }
  inline bool operator==(const ResolverOptionsParcel& rhs) const {
    return std::tie(hosts, tcMode, enforceDnsUid) == std::tie(rhs.hosts, rhs.tcMode, rhs.enforceDnsUid);
  }
  inline bool operator>(const ResolverOptionsParcel& rhs) const {
    return std::tie(hosts, tcMode, enforceDnsUid) > std::tie(rhs.hosts, rhs.tcMode, rhs.enforceDnsUid);
  }
  inline bool operator>=(const ResolverOptionsParcel& rhs) const {
    return std::tie(hosts, tcMode, enforceDnsUid) >= std::tie(rhs.hosts, rhs.tcMode, rhs.enforceDnsUid);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "ResolverOptionsParcel{";
    os << "hosts: " << ::android::internal::ToString(hosts);
    os << ", tcMode: " << ::android::internal::ToString(tcMode);
    os << ", enforceDnsUid: " << ::android::internal::ToString(enforceDnsUid);
    os << "}";
    return os.str();
  }
};
}  // namespace net
}  // namespace android
}  // namespace aidl
