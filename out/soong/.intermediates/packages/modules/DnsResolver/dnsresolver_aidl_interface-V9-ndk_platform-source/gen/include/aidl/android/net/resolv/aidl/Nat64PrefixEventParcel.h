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
class Nat64PrefixEventParcel {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t netId = 0;
  int32_t prefixOperation = 0;
  std::string prefixAddress;
  int32_t prefixLength = 0;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const Nat64PrefixEventParcel& rhs) const {
    return std::tie(netId, prefixOperation, prefixAddress, prefixLength) != std::tie(rhs.netId, rhs.prefixOperation, rhs.prefixAddress, rhs.prefixLength);
  }
  inline bool operator<(const Nat64PrefixEventParcel& rhs) const {
    return std::tie(netId, prefixOperation, prefixAddress, prefixLength) < std::tie(rhs.netId, rhs.prefixOperation, rhs.prefixAddress, rhs.prefixLength);
  }
  inline bool operator<=(const Nat64PrefixEventParcel& rhs) const {
    return std::tie(netId, prefixOperation, prefixAddress, prefixLength) <= std::tie(rhs.netId, rhs.prefixOperation, rhs.prefixAddress, rhs.prefixLength);
  }
  inline bool operator==(const Nat64PrefixEventParcel& rhs) const {
    return std::tie(netId, prefixOperation, prefixAddress, prefixLength) == std::tie(rhs.netId, rhs.prefixOperation, rhs.prefixAddress, rhs.prefixLength);
  }
  inline bool operator>(const Nat64PrefixEventParcel& rhs) const {
    return std::tie(netId, prefixOperation, prefixAddress, prefixLength) > std::tie(rhs.netId, rhs.prefixOperation, rhs.prefixAddress, rhs.prefixLength);
  }
  inline bool operator>=(const Nat64PrefixEventParcel& rhs) const {
    return std::tie(netId, prefixOperation, prefixAddress, prefixLength) >= std::tie(rhs.netId, rhs.prefixOperation, rhs.prefixAddress, rhs.prefixLength);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "Nat64PrefixEventParcel{";
    os << "netId: " << ::android::internal::ToString(netId);
    os << ", prefixOperation: " << ::android::internal::ToString(prefixOperation);
    os << ", prefixAddress: " << ::android::internal::ToString(prefixAddress);
    os << ", prefixLength: " << ::android::internal::ToString(prefixLength);
    os << "}";
    return os.str();
  }
};
}  // namespace aidl
}  // namespace resolv
}  // namespace net
}  // namespace android
}  // namespace aidl
