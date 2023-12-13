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
#include <aidl/android/media/TranscodingVideoCodecType.h>
namespace aidl {
namespace android {
namespace media {
class TranscodingVideoTrackFormat {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  ::aidl::android::media::TranscodingVideoCodecType codecType = ::aidl::android::media::TranscodingVideoCodecType(0);
  int32_t width = -1;
  int32_t height = -1;
  int32_t bitrateBps = -1;
  int32_t profile = -1;
  int32_t level = -1;
  int32_t decoderOperatingRate = -1;
  int32_t encoderOperatingRate = -1;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const TranscodingVideoTrackFormat& rhs) const {
    return std::tie(codecType, width, height, bitrateBps, profile, level, decoderOperatingRate, encoderOperatingRate) != std::tie(rhs.codecType, rhs.width, rhs.height, rhs.bitrateBps, rhs.profile, rhs.level, rhs.decoderOperatingRate, rhs.encoderOperatingRate);
  }
  inline bool operator<(const TranscodingVideoTrackFormat& rhs) const {
    return std::tie(codecType, width, height, bitrateBps, profile, level, decoderOperatingRate, encoderOperatingRate) < std::tie(rhs.codecType, rhs.width, rhs.height, rhs.bitrateBps, rhs.profile, rhs.level, rhs.decoderOperatingRate, rhs.encoderOperatingRate);
  }
  inline bool operator<=(const TranscodingVideoTrackFormat& rhs) const {
    return std::tie(codecType, width, height, bitrateBps, profile, level, decoderOperatingRate, encoderOperatingRate) <= std::tie(rhs.codecType, rhs.width, rhs.height, rhs.bitrateBps, rhs.profile, rhs.level, rhs.decoderOperatingRate, rhs.encoderOperatingRate);
  }
  inline bool operator==(const TranscodingVideoTrackFormat& rhs) const {
    return std::tie(codecType, width, height, bitrateBps, profile, level, decoderOperatingRate, encoderOperatingRate) == std::tie(rhs.codecType, rhs.width, rhs.height, rhs.bitrateBps, rhs.profile, rhs.level, rhs.decoderOperatingRate, rhs.encoderOperatingRate);
  }
  inline bool operator>(const TranscodingVideoTrackFormat& rhs) const {
    return std::tie(codecType, width, height, bitrateBps, profile, level, decoderOperatingRate, encoderOperatingRate) > std::tie(rhs.codecType, rhs.width, rhs.height, rhs.bitrateBps, rhs.profile, rhs.level, rhs.decoderOperatingRate, rhs.encoderOperatingRate);
  }
  inline bool operator>=(const TranscodingVideoTrackFormat& rhs) const {
    return std::tie(codecType, width, height, bitrateBps, profile, level, decoderOperatingRate, encoderOperatingRate) >= std::tie(rhs.codecType, rhs.width, rhs.height, rhs.bitrateBps, rhs.profile, rhs.level, rhs.decoderOperatingRate, rhs.encoderOperatingRate);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "TranscodingVideoTrackFormat{";
    os << "codecType: " << ::android::internal::ToString(codecType);
    os << ", width: " << ::android::internal::ToString(width);
    os << ", height: " << ::android::internal::ToString(height);
    os << ", bitrateBps: " << ::android::internal::ToString(bitrateBps);
    os << ", profile: " << ::android::internal::ToString(profile);
    os << ", level: " << ::android::internal::ToString(level);
    os << ", decoderOperatingRate: " << ::android::internal::ToString(decoderOperatingRate);
    os << ", encoderOperatingRate: " << ::android::internal::ToString(encoderOperatingRate);
    os << "}";
    return os.str();
  }
};
}  // namespace media
}  // namespace android
}  // namespace aidl
