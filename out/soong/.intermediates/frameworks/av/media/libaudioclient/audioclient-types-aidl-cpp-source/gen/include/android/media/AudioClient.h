#pragma once

#include <android/binder_to_string.h>
#include <android/content/AttributionSourceState.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioClient : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioClient& rhs) const {
    return std::tie(clientTid, attributionSource) != std::tie(rhs.clientTid, rhs.attributionSource);
  }
  inline bool operator<(const AudioClient& rhs) const {
    return std::tie(clientTid, attributionSource) < std::tie(rhs.clientTid, rhs.attributionSource);
  }
  inline bool operator<=(const AudioClient& rhs) const {
    return std::tie(clientTid, attributionSource) <= std::tie(rhs.clientTid, rhs.attributionSource);
  }
  inline bool operator==(const AudioClient& rhs) const {
    return std::tie(clientTid, attributionSource) == std::tie(rhs.clientTid, rhs.attributionSource);
  }
  inline bool operator>(const AudioClient& rhs) const {
    return std::tie(clientTid, attributionSource) > std::tie(rhs.clientTid, rhs.attributionSource);
  }
  inline bool operator>=(const AudioClient& rhs) const {
    return std::tie(clientTid, attributionSource) >= std::tie(rhs.clientTid, rhs.attributionSource);
  }

  int32_t clientTid = int32_t(0);
  ::android::content::AttributionSourceState attributionSource;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioClient");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioClient{";
    os << "clientTid: " << ::android::internal::ToString(clientTid);
    os << ", attributionSource: " << ::android::internal::ToString(attributionSource);
    os << "}";
    return os.str();
  }
};  // class AudioClient

}  // namespace media

}  // namespace android
