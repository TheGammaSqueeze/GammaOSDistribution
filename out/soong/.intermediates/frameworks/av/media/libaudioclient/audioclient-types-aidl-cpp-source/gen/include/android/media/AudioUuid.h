#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace media {

class AudioUuid : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioUuid& rhs) const {
    return std::tie(timeLow, timeMid, timeHiAndVersion, clockSeq, node) != std::tie(rhs.timeLow, rhs.timeMid, rhs.timeHiAndVersion, rhs.clockSeq, rhs.node);
  }
  inline bool operator<(const AudioUuid& rhs) const {
    return std::tie(timeLow, timeMid, timeHiAndVersion, clockSeq, node) < std::tie(rhs.timeLow, rhs.timeMid, rhs.timeHiAndVersion, rhs.clockSeq, rhs.node);
  }
  inline bool operator<=(const AudioUuid& rhs) const {
    return std::tie(timeLow, timeMid, timeHiAndVersion, clockSeq, node) <= std::tie(rhs.timeLow, rhs.timeMid, rhs.timeHiAndVersion, rhs.clockSeq, rhs.node);
  }
  inline bool operator==(const AudioUuid& rhs) const {
    return std::tie(timeLow, timeMid, timeHiAndVersion, clockSeq, node) == std::tie(rhs.timeLow, rhs.timeMid, rhs.timeHiAndVersion, rhs.clockSeq, rhs.node);
  }
  inline bool operator>(const AudioUuid& rhs) const {
    return std::tie(timeLow, timeMid, timeHiAndVersion, clockSeq, node) > std::tie(rhs.timeLow, rhs.timeMid, rhs.timeHiAndVersion, rhs.clockSeq, rhs.node);
  }
  inline bool operator>=(const AudioUuid& rhs) const {
    return std::tie(timeLow, timeMid, timeHiAndVersion, clockSeq, node) >= std::tie(rhs.timeLow, rhs.timeMid, rhs.timeHiAndVersion, rhs.clockSeq, rhs.node);
  }

  int32_t timeLow = int32_t(0);
  int32_t timeMid = int32_t(0);
  int32_t timeHiAndVersion = int32_t(0);
  int32_t clockSeq = int32_t(0);
  ::std::vector<uint8_t> node;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioUuid");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioUuid{";
    os << "timeLow: " << ::android::internal::ToString(timeLow);
    os << ", timeMid: " << ::android::internal::ToString(timeMid);
    os << ", timeHiAndVersion: " << ::android::internal::ToString(timeHiAndVersion);
    os << ", clockSeq: " << ::android::internal::ToString(clockSeq);
    os << ", node: " << ::android::internal::ToString(node);
    os << "}";
    return os.str();
  }
};  // class AudioUuid

}  // namespace media

}  // namespace android
