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
#include <aidl/android/media/MediaResourceSubType.h>
#include <aidl/android/media/MediaResourceType.h>
namespace aidl {
namespace android {
namespace media {
class MediaResourceParcel {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  ::aidl::android::media::MediaResourceType type = ::aidl::android::media::MediaResourceType(0);
  ::aidl::android::media::MediaResourceSubType subType = ::aidl::android::media::MediaResourceSubType(0);
  std::vector<uint8_t> id;
  int64_t value = 0L;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const MediaResourceParcel& rhs) const {
    return std::tie(type, subType, id, value) != std::tie(rhs.type, rhs.subType, rhs.id, rhs.value);
  }
  inline bool operator<(const MediaResourceParcel& rhs) const {
    return std::tie(type, subType, id, value) < std::tie(rhs.type, rhs.subType, rhs.id, rhs.value);
  }
  inline bool operator<=(const MediaResourceParcel& rhs) const {
    return std::tie(type, subType, id, value) <= std::tie(rhs.type, rhs.subType, rhs.id, rhs.value);
  }
  inline bool operator==(const MediaResourceParcel& rhs) const {
    return std::tie(type, subType, id, value) == std::tie(rhs.type, rhs.subType, rhs.id, rhs.value);
  }
  inline bool operator>(const MediaResourceParcel& rhs) const {
    return std::tie(type, subType, id, value) > std::tie(rhs.type, rhs.subType, rhs.id, rhs.value);
  }
  inline bool operator>=(const MediaResourceParcel& rhs) const {
    return std::tie(type, subType, id, value) >= std::tie(rhs.type, rhs.subType, rhs.id, rhs.value);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "MediaResourceParcel{";
    os << "type: " << ::android::internal::ToString(type);
    os << ", subType: " << ::android::internal::ToString(subType);
    os << ", id: " << ::android::internal::ToString(id);
    os << ", value: " << ::android::internal::ToString(value);
    os << "}";
    return os.str();
  }
};
}  // namespace media
}  // namespace android
}  // namespace aidl
