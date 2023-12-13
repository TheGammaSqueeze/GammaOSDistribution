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
#include <aidl/android/media/TranscodingRequestParcel.h>
#include <aidl/android/media/TranscodingVideoTrackFormat.h>
namespace aidl {
namespace android {
namespace media {
class TranscodingSessionParcel {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t sessionId = 0;
  ::aidl::android::media::TranscodingRequestParcel request;
  std::optional<::aidl::android::media::TranscodingVideoTrackFormat> videoTrackFormat;
  int32_t awaitNumberOfSessions = 0;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const TranscodingSessionParcel& rhs) const {
    return std::tie(sessionId, request, videoTrackFormat, awaitNumberOfSessions) != std::tie(rhs.sessionId, rhs.request, rhs.videoTrackFormat, rhs.awaitNumberOfSessions);
  }
  inline bool operator<(const TranscodingSessionParcel& rhs) const {
    return std::tie(sessionId, request, videoTrackFormat, awaitNumberOfSessions) < std::tie(rhs.sessionId, rhs.request, rhs.videoTrackFormat, rhs.awaitNumberOfSessions);
  }
  inline bool operator<=(const TranscodingSessionParcel& rhs) const {
    return std::tie(sessionId, request, videoTrackFormat, awaitNumberOfSessions) <= std::tie(rhs.sessionId, rhs.request, rhs.videoTrackFormat, rhs.awaitNumberOfSessions);
  }
  inline bool operator==(const TranscodingSessionParcel& rhs) const {
    return std::tie(sessionId, request, videoTrackFormat, awaitNumberOfSessions) == std::tie(rhs.sessionId, rhs.request, rhs.videoTrackFormat, rhs.awaitNumberOfSessions);
  }
  inline bool operator>(const TranscodingSessionParcel& rhs) const {
    return std::tie(sessionId, request, videoTrackFormat, awaitNumberOfSessions) > std::tie(rhs.sessionId, rhs.request, rhs.videoTrackFormat, rhs.awaitNumberOfSessions);
  }
  inline bool operator>=(const TranscodingSessionParcel& rhs) const {
    return std::tie(sessionId, request, videoTrackFormat, awaitNumberOfSessions) >= std::tie(rhs.sessionId, rhs.request, rhs.videoTrackFormat, rhs.awaitNumberOfSessions);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "TranscodingSessionParcel{";
    os << "sessionId: " << ::android::internal::ToString(sessionId);
    os << ", request: " << ::android::internal::ToString(request);
    os << ", videoTrackFormat: " << ::android::internal::ToString(videoTrackFormat);
    os << ", awaitNumberOfSessions: " << ::android::internal::ToString(awaitNumberOfSessions);
    os << "}";
    return os.str();
  }
};
}  // namespace media
}  // namespace android
}  // namespace aidl
