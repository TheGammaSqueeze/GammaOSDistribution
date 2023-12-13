#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioPortConfigMixExtUseCase.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioPortConfigMixExt : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioPortConfigMixExt& rhs) const {
    return std::tie(hwModule, handle, usecase) != std::tie(rhs.hwModule, rhs.handle, rhs.usecase);
  }
  inline bool operator<(const AudioPortConfigMixExt& rhs) const {
    return std::tie(hwModule, handle, usecase) < std::tie(rhs.hwModule, rhs.handle, rhs.usecase);
  }
  inline bool operator<=(const AudioPortConfigMixExt& rhs) const {
    return std::tie(hwModule, handle, usecase) <= std::tie(rhs.hwModule, rhs.handle, rhs.usecase);
  }
  inline bool operator==(const AudioPortConfigMixExt& rhs) const {
    return std::tie(hwModule, handle, usecase) == std::tie(rhs.hwModule, rhs.handle, rhs.usecase);
  }
  inline bool operator>(const AudioPortConfigMixExt& rhs) const {
    return std::tie(hwModule, handle, usecase) > std::tie(rhs.hwModule, rhs.handle, rhs.usecase);
  }
  inline bool operator>=(const AudioPortConfigMixExt& rhs) const {
    return std::tie(hwModule, handle, usecase) >= std::tie(rhs.hwModule, rhs.handle, rhs.usecase);
  }

  int32_t hwModule = int32_t(0);
  int32_t handle = int32_t(0);
  ::android::media::AudioPortConfigMixExtUseCase usecase;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioPortConfigMixExt");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioPortConfigMixExt{";
    os << "hwModule: " << ::android::internal::ToString(hwModule);
    os << ", handle: " << ::android::internal::ToString(handle);
    os << ", usecase: " << ::android::internal::ToString(usecase);
    os << "}";
    return os.str();
  }
};  // class AudioPortConfigMixExt

}  // namespace media

}  // namespace android
