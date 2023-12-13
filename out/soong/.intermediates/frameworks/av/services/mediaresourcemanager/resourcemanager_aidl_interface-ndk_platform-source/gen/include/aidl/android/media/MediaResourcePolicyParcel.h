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
namespace media {
class MediaResourcePolicyParcel {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  std::string type;
  std::string value;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const MediaResourcePolicyParcel& rhs) const {
    return std::tie(type, value) != std::tie(rhs.type, rhs.value);
  }
  inline bool operator<(const MediaResourcePolicyParcel& rhs) const {
    return std::tie(type, value) < std::tie(rhs.type, rhs.value);
  }
  inline bool operator<=(const MediaResourcePolicyParcel& rhs) const {
    return std::tie(type, value) <= std::tie(rhs.type, rhs.value);
  }
  inline bool operator==(const MediaResourcePolicyParcel& rhs) const {
    return std::tie(type, value) == std::tie(rhs.type, rhs.value);
  }
  inline bool operator>(const MediaResourcePolicyParcel& rhs) const {
    return std::tie(type, value) > std::tie(rhs.type, rhs.value);
  }
  inline bool operator>=(const MediaResourcePolicyParcel& rhs) const {
    return std::tie(type, value) >= std::tie(rhs.type, rhs.value);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "MediaResourcePolicyParcel{";
    os << "type: " << ::android::internal::ToString(type);
    os << ", value: " << ::android::internal::ToString(value);
    os << "}";
    return os.str();
  }
};
}  // namespace media
}  // namespace android
}  // namespace aidl
