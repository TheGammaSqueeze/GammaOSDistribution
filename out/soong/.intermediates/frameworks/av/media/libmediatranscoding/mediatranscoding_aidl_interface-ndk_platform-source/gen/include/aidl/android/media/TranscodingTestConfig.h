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
class TranscodingTestConfig {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  bool passThroughMode = false;
  int32_t processingTotalTimeMs = 0;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const TranscodingTestConfig& rhs) const {
    return std::tie(passThroughMode, processingTotalTimeMs) != std::tie(rhs.passThroughMode, rhs.processingTotalTimeMs);
  }
  inline bool operator<(const TranscodingTestConfig& rhs) const {
    return std::tie(passThroughMode, processingTotalTimeMs) < std::tie(rhs.passThroughMode, rhs.processingTotalTimeMs);
  }
  inline bool operator<=(const TranscodingTestConfig& rhs) const {
    return std::tie(passThroughMode, processingTotalTimeMs) <= std::tie(rhs.passThroughMode, rhs.processingTotalTimeMs);
  }
  inline bool operator==(const TranscodingTestConfig& rhs) const {
    return std::tie(passThroughMode, processingTotalTimeMs) == std::tie(rhs.passThroughMode, rhs.processingTotalTimeMs);
  }
  inline bool operator>(const TranscodingTestConfig& rhs) const {
    return std::tie(passThroughMode, processingTotalTimeMs) > std::tie(rhs.passThroughMode, rhs.processingTotalTimeMs);
  }
  inline bool operator>=(const TranscodingTestConfig& rhs) const {
    return std::tie(passThroughMode, processingTotalTimeMs) >= std::tie(rhs.passThroughMode, rhs.processingTotalTimeMs);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "TranscodingTestConfig{";
    os << "passThroughMode: " << ::android::internal::ToString(passThroughMode);
    os << ", processingTotalTimeMs: " << ::android::internal::ToString(processingTotalTimeMs);
    os << "}";
    return os.str();
  }
};
}  // namespace media
}  // namespace android
}  // namespace aidl
