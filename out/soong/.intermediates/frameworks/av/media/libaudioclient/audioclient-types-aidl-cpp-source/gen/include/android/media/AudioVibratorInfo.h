#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioVibratorInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioVibratorInfo& rhs) const {
    return std::tie(id, resonantFrequency, qFactor, maxAmplitude) != std::tie(rhs.id, rhs.resonantFrequency, rhs.qFactor, rhs.maxAmplitude);
  }
  inline bool operator<(const AudioVibratorInfo& rhs) const {
    return std::tie(id, resonantFrequency, qFactor, maxAmplitude) < std::tie(rhs.id, rhs.resonantFrequency, rhs.qFactor, rhs.maxAmplitude);
  }
  inline bool operator<=(const AudioVibratorInfo& rhs) const {
    return std::tie(id, resonantFrequency, qFactor, maxAmplitude) <= std::tie(rhs.id, rhs.resonantFrequency, rhs.qFactor, rhs.maxAmplitude);
  }
  inline bool operator==(const AudioVibratorInfo& rhs) const {
    return std::tie(id, resonantFrequency, qFactor, maxAmplitude) == std::tie(rhs.id, rhs.resonantFrequency, rhs.qFactor, rhs.maxAmplitude);
  }
  inline bool operator>(const AudioVibratorInfo& rhs) const {
    return std::tie(id, resonantFrequency, qFactor, maxAmplitude) > std::tie(rhs.id, rhs.resonantFrequency, rhs.qFactor, rhs.maxAmplitude);
  }
  inline bool operator>=(const AudioVibratorInfo& rhs) const {
    return std::tie(id, resonantFrequency, qFactor, maxAmplitude) >= std::tie(rhs.id, rhs.resonantFrequency, rhs.qFactor, rhs.maxAmplitude);
  }

  int32_t id = int32_t(0);
  float resonantFrequency = float(0.000000f);
  float qFactor = float(0.000000f);
  float maxAmplitude = float(0.000000f);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioVibratorInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioVibratorInfo{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", resonantFrequency: " << ::android::internal::ToString(resonantFrequency);
    os << ", qFactor: " << ::android::internal::ToString(qFactor);
    os << ", maxAmplitude: " << ::android::internal::ToString(maxAmplitude);
    os << "}";
    return os.str();
  }
};  // class AudioVibratorInfo

}  // namespace media

}  // namespace android
