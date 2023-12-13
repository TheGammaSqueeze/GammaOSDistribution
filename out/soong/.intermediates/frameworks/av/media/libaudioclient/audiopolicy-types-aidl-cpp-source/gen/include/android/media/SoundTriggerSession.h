#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class SoundTriggerSession : public ::android::Parcelable {
public:
  inline bool operator!=(const SoundTriggerSession& rhs) const {
    return std::tie(session, ioHandle, device) != std::tie(rhs.session, rhs.ioHandle, rhs.device);
  }
  inline bool operator<(const SoundTriggerSession& rhs) const {
    return std::tie(session, ioHandle, device) < std::tie(rhs.session, rhs.ioHandle, rhs.device);
  }
  inline bool operator<=(const SoundTriggerSession& rhs) const {
    return std::tie(session, ioHandle, device) <= std::tie(rhs.session, rhs.ioHandle, rhs.device);
  }
  inline bool operator==(const SoundTriggerSession& rhs) const {
    return std::tie(session, ioHandle, device) == std::tie(rhs.session, rhs.ioHandle, rhs.device);
  }
  inline bool operator>(const SoundTriggerSession& rhs) const {
    return std::tie(session, ioHandle, device) > std::tie(rhs.session, rhs.ioHandle, rhs.device);
  }
  inline bool operator>=(const SoundTriggerSession& rhs) const {
    return std::tie(session, ioHandle, device) >= std::tie(rhs.session, rhs.ioHandle, rhs.device);
  }

  int32_t session = int32_t(0);
  int32_t ioHandle = int32_t(0);
  int32_t device = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.SoundTriggerSession");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "SoundTriggerSession{";
    os << "session: " << ::android::internal::ToString(session);
    os << ", ioHandle: " << ::android::internal::ToString(ioHandle);
    os << ", device: " << ::android::internal::ToString(device);
    os << "}";
    return os.str();
  }
};  // class SoundTriggerSession

}  // namespace media

}  // namespace android
