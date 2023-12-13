#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class VolumeShaperState : public ::android::Parcelable {
public:
  inline bool operator!=(const VolumeShaperState& rhs) const {
    return std::tie(volume, xOffset) != std::tie(rhs.volume, rhs.xOffset);
  }
  inline bool operator<(const VolumeShaperState& rhs) const {
    return std::tie(volume, xOffset) < std::tie(rhs.volume, rhs.xOffset);
  }
  inline bool operator<=(const VolumeShaperState& rhs) const {
    return std::tie(volume, xOffset) <= std::tie(rhs.volume, rhs.xOffset);
  }
  inline bool operator==(const VolumeShaperState& rhs) const {
    return std::tie(volume, xOffset) == std::tie(rhs.volume, rhs.xOffset);
  }
  inline bool operator>(const VolumeShaperState& rhs) const {
    return std::tie(volume, xOffset) > std::tie(rhs.volume, rhs.xOffset);
  }
  inline bool operator>=(const VolumeShaperState& rhs) const {
    return std::tie(volume, xOffset) >= std::tie(rhs.volume, rhs.xOffset);
  }

  float volume = float(0.000000f);
  float xOffset = float(0.000000f);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.VolumeShaperState");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "VolumeShaperState{";
    os << "volume: " << ::android::internal::ToString(volume);
    os << ", xOffset: " << ::android::internal::ToString(xOffset);
    os << "}";
    return os.str();
  }
};  // class VolumeShaperState

}  // namespace media

}  // namespace android
