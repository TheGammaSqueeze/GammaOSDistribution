#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class RenderPosition : public ::android::Parcelable {
public:
  inline bool operator!=(const RenderPosition& rhs) const {
    return std::tie(halFrames, dspFrames) != std::tie(rhs.halFrames, rhs.dspFrames);
  }
  inline bool operator<(const RenderPosition& rhs) const {
    return std::tie(halFrames, dspFrames) < std::tie(rhs.halFrames, rhs.dspFrames);
  }
  inline bool operator<=(const RenderPosition& rhs) const {
    return std::tie(halFrames, dspFrames) <= std::tie(rhs.halFrames, rhs.dspFrames);
  }
  inline bool operator==(const RenderPosition& rhs) const {
    return std::tie(halFrames, dspFrames) == std::tie(rhs.halFrames, rhs.dspFrames);
  }
  inline bool operator>(const RenderPosition& rhs) const {
    return std::tie(halFrames, dspFrames) > std::tie(rhs.halFrames, rhs.dspFrames);
  }
  inline bool operator>=(const RenderPosition& rhs) const {
    return std::tie(halFrames, dspFrames) >= std::tie(rhs.halFrames, rhs.dspFrames);
  }

  int32_t halFrames = int32_t(0);
  int32_t dspFrames = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.RenderPosition");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "RenderPosition{";
    os << "halFrames: " << ::android::internal::ToString(halFrames);
    os << ", dspFrames: " << ::android::internal::ToString(dspFrames);
    os << "}";
    return os.str();
  }
};  // class RenderPosition

}  // namespace media

}  // namespace android
