#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioPortSessionExt : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioPortSessionExt& rhs) const {
    return std::tie(session) != std::tie(rhs.session);
  }
  inline bool operator<(const AudioPortSessionExt& rhs) const {
    return std::tie(session) < std::tie(rhs.session);
  }
  inline bool operator<=(const AudioPortSessionExt& rhs) const {
    return std::tie(session) <= std::tie(rhs.session);
  }
  inline bool operator==(const AudioPortSessionExt& rhs) const {
    return std::tie(session) == std::tie(rhs.session);
  }
  inline bool operator>(const AudioPortSessionExt& rhs) const {
    return std::tie(session) > std::tie(rhs.session);
  }
  inline bool operator>=(const AudioPortSessionExt& rhs) const {
    return std::tie(session) >= std::tie(rhs.session);
  }

  int32_t session = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioPortSessionExt");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioPortSessionExt{";
    os << "session: " << ::android::internal::ToString(session);
    os << "}";
    return os.str();
  }
};  // class AudioPortSessionExt

}  // namespace media

}  // namespace android
