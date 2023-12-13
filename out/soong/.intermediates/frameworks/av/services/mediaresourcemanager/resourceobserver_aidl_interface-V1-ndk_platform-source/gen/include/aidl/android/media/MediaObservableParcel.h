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
#include <aidl/android/media/MediaObservableType.h>
namespace aidl {
namespace android {
namespace media {
class MediaObservableParcel {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  ::aidl::android::media::MediaObservableType type = ::aidl::android::media::MediaObservableType(0);
  int64_t value = 0L;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const MediaObservableParcel& rhs) const {
    return std::tie(type, value) != std::tie(rhs.type, rhs.value);
  }
  inline bool operator<(const MediaObservableParcel& rhs) const {
    return std::tie(type, value) < std::tie(rhs.type, rhs.value);
  }
  inline bool operator<=(const MediaObservableParcel& rhs) const {
    return std::tie(type, value) <= std::tie(rhs.type, rhs.value);
  }
  inline bool operator==(const MediaObservableParcel& rhs) const {
    return std::tie(type, value) == std::tie(rhs.type, rhs.value);
  }
  inline bool operator>(const MediaObservableParcel& rhs) const {
    return std::tie(type, value) > std::tie(rhs.type, rhs.value);
  }
  inline bool operator>=(const MediaObservableParcel& rhs) const {
    return std::tie(type, value) >= std::tie(rhs.type, rhs.value);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "MediaObservableParcel{";
    os << "type: " << ::android::internal::ToString(type);
    os << ", value: " << ::android::internal::ToString(value);
    os << "}";
    return os.str();
  }
};
}  // namespace media
}  // namespace android
}  // namespace aidl
