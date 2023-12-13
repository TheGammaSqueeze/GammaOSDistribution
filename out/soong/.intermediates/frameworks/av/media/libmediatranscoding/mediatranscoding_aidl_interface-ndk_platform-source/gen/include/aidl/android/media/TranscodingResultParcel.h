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
#include <aidl/android/media/TranscodingSessionStats.h>
namespace aidl {
namespace android {
namespace media {
class TranscodingResultParcel {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t sessionId = 0;
  int32_t actualBitrateBps = 0;
  std::optional<::aidl::android::media::TranscodingSessionStats> sessionStats;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const TranscodingResultParcel& rhs) const {
    return std::tie(sessionId, actualBitrateBps, sessionStats) != std::tie(rhs.sessionId, rhs.actualBitrateBps, rhs.sessionStats);
  }
  inline bool operator<(const TranscodingResultParcel& rhs) const {
    return std::tie(sessionId, actualBitrateBps, sessionStats) < std::tie(rhs.sessionId, rhs.actualBitrateBps, rhs.sessionStats);
  }
  inline bool operator<=(const TranscodingResultParcel& rhs) const {
    return std::tie(sessionId, actualBitrateBps, sessionStats) <= std::tie(rhs.sessionId, rhs.actualBitrateBps, rhs.sessionStats);
  }
  inline bool operator==(const TranscodingResultParcel& rhs) const {
    return std::tie(sessionId, actualBitrateBps, sessionStats) == std::tie(rhs.sessionId, rhs.actualBitrateBps, rhs.sessionStats);
  }
  inline bool operator>(const TranscodingResultParcel& rhs) const {
    return std::tie(sessionId, actualBitrateBps, sessionStats) > std::tie(rhs.sessionId, rhs.actualBitrateBps, rhs.sessionStats);
  }
  inline bool operator>=(const TranscodingResultParcel& rhs) const {
    return std::tie(sessionId, actualBitrateBps, sessionStats) >= std::tie(rhs.sessionId, rhs.actualBitrateBps, rhs.sessionStats);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "TranscodingResultParcel{";
    os << "sessionId: " << ::android::internal::ToString(sessionId);
    os << ", actualBitrateBps: " << ::android::internal::ToString(actualBitrateBps);
    os << ", sessionStats: " << ::android::internal::ToString(sessionStats);
    os << "}";
    return os.str();
  }
};
}  // namespace media
}  // namespace android
}  // namespace aidl
