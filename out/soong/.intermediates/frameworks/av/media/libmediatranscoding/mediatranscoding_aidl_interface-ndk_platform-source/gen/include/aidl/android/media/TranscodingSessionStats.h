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
class TranscodingSessionStats {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int64_t sessionCreatedTimeUs = 0L;
  int64_t sessionFinishedTimeUs = 0L;
  int64_t totalProcessingTimeUs = 0L;
  int64_t totalTimeUs = 0L;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const TranscodingSessionStats& rhs) const {
    return std::tie(sessionCreatedTimeUs, sessionFinishedTimeUs, totalProcessingTimeUs, totalTimeUs) != std::tie(rhs.sessionCreatedTimeUs, rhs.sessionFinishedTimeUs, rhs.totalProcessingTimeUs, rhs.totalTimeUs);
  }
  inline bool operator<(const TranscodingSessionStats& rhs) const {
    return std::tie(sessionCreatedTimeUs, sessionFinishedTimeUs, totalProcessingTimeUs, totalTimeUs) < std::tie(rhs.sessionCreatedTimeUs, rhs.sessionFinishedTimeUs, rhs.totalProcessingTimeUs, rhs.totalTimeUs);
  }
  inline bool operator<=(const TranscodingSessionStats& rhs) const {
    return std::tie(sessionCreatedTimeUs, sessionFinishedTimeUs, totalProcessingTimeUs, totalTimeUs) <= std::tie(rhs.sessionCreatedTimeUs, rhs.sessionFinishedTimeUs, rhs.totalProcessingTimeUs, rhs.totalTimeUs);
  }
  inline bool operator==(const TranscodingSessionStats& rhs) const {
    return std::tie(sessionCreatedTimeUs, sessionFinishedTimeUs, totalProcessingTimeUs, totalTimeUs) == std::tie(rhs.sessionCreatedTimeUs, rhs.sessionFinishedTimeUs, rhs.totalProcessingTimeUs, rhs.totalTimeUs);
  }
  inline bool operator>(const TranscodingSessionStats& rhs) const {
    return std::tie(sessionCreatedTimeUs, sessionFinishedTimeUs, totalProcessingTimeUs, totalTimeUs) > std::tie(rhs.sessionCreatedTimeUs, rhs.sessionFinishedTimeUs, rhs.totalProcessingTimeUs, rhs.totalTimeUs);
  }
  inline bool operator>=(const TranscodingSessionStats& rhs) const {
    return std::tie(sessionCreatedTimeUs, sessionFinishedTimeUs, totalProcessingTimeUs, totalTimeUs) >= std::tie(rhs.sessionCreatedTimeUs, rhs.sessionFinishedTimeUs, rhs.totalProcessingTimeUs, rhs.totalTimeUs);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "TranscodingSessionStats{";
    os << "sessionCreatedTimeUs: " << ::android::internal::ToString(sessionCreatedTimeUs);
    os << ", sessionFinishedTimeUs: " << ::android::internal::ToString(sessionFinishedTimeUs);
    os << ", totalProcessingTimeUs: " << ::android::internal::ToString(totalProcessingTimeUs);
    os << ", totalTimeUs: " << ::android::internal::ToString(totalTimeUs);
    os << "}";
    return os.str();
  }
};
}  // namespace media
}  // namespace android
}  // namespace aidl
