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
#include <aidl/android/frameworks/stats/VendorAtomValue.h>
namespace aidl {
namespace android {
namespace frameworks {
namespace stats {
class VendorAtom {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  std::string reverseDomainName;
  int32_t atomId = 0;
  std::vector<::aidl::android::frameworks::stats::VendorAtomValue> values;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const VendorAtom& rhs) const {
    return std::tie(reverseDomainName, atomId, values) != std::tie(rhs.reverseDomainName, rhs.atomId, rhs.values);
  }
  inline bool operator<(const VendorAtom& rhs) const {
    return std::tie(reverseDomainName, atomId, values) < std::tie(rhs.reverseDomainName, rhs.atomId, rhs.values);
  }
  inline bool operator<=(const VendorAtom& rhs) const {
    return std::tie(reverseDomainName, atomId, values) <= std::tie(rhs.reverseDomainName, rhs.atomId, rhs.values);
  }
  inline bool operator==(const VendorAtom& rhs) const {
    return std::tie(reverseDomainName, atomId, values) == std::tie(rhs.reverseDomainName, rhs.atomId, rhs.values);
  }
  inline bool operator>(const VendorAtom& rhs) const {
    return std::tie(reverseDomainName, atomId, values) > std::tie(rhs.reverseDomainName, rhs.atomId, rhs.values);
  }
  inline bool operator>=(const VendorAtom& rhs) const {
    return std::tie(reverseDomainName, atomId, values) >= std::tie(rhs.reverseDomainName, rhs.atomId, rhs.values);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "VendorAtom{";
    os << "reverseDomainName: " << ::android::internal::ToString(reverseDomainName);
    os << ", atomId: " << ::android::internal::ToString(atomId);
    os << ", values: " << ::android::internal::ToString(values);
    os << "}";
    return os.str();
  }
};
}  // namespace stats
}  // namespace frameworks
}  // namespace android
}  // namespace aidl
