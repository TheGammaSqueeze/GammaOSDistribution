#pragma once

#include <aaudio/SharedRegion.h>
#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace aaudio {

class RingBuffer : public ::android::Parcelable {
public:
  inline bool operator!=(const RingBuffer& rhs) const {
    return std::tie(readCounterParcelable, writeCounterParcelable, dataParcelable, bytesPerFrame, framesPerBurst, capacityInFrames, flags) != std::tie(rhs.readCounterParcelable, rhs.writeCounterParcelable, rhs.dataParcelable, rhs.bytesPerFrame, rhs.framesPerBurst, rhs.capacityInFrames, rhs.flags);
  }
  inline bool operator<(const RingBuffer& rhs) const {
    return std::tie(readCounterParcelable, writeCounterParcelable, dataParcelable, bytesPerFrame, framesPerBurst, capacityInFrames, flags) < std::tie(rhs.readCounterParcelable, rhs.writeCounterParcelable, rhs.dataParcelable, rhs.bytesPerFrame, rhs.framesPerBurst, rhs.capacityInFrames, rhs.flags);
  }
  inline bool operator<=(const RingBuffer& rhs) const {
    return std::tie(readCounterParcelable, writeCounterParcelable, dataParcelable, bytesPerFrame, framesPerBurst, capacityInFrames, flags) <= std::tie(rhs.readCounterParcelable, rhs.writeCounterParcelable, rhs.dataParcelable, rhs.bytesPerFrame, rhs.framesPerBurst, rhs.capacityInFrames, rhs.flags);
  }
  inline bool operator==(const RingBuffer& rhs) const {
    return std::tie(readCounterParcelable, writeCounterParcelable, dataParcelable, bytesPerFrame, framesPerBurst, capacityInFrames, flags) == std::tie(rhs.readCounterParcelable, rhs.writeCounterParcelable, rhs.dataParcelable, rhs.bytesPerFrame, rhs.framesPerBurst, rhs.capacityInFrames, rhs.flags);
  }
  inline bool operator>(const RingBuffer& rhs) const {
    return std::tie(readCounterParcelable, writeCounterParcelable, dataParcelable, bytesPerFrame, framesPerBurst, capacityInFrames, flags) > std::tie(rhs.readCounterParcelable, rhs.writeCounterParcelable, rhs.dataParcelable, rhs.bytesPerFrame, rhs.framesPerBurst, rhs.capacityInFrames, rhs.flags);
  }
  inline bool operator>=(const RingBuffer& rhs) const {
    return std::tie(readCounterParcelable, writeCounterParcelable, dataParcelable, bytesPerFrame, framesPerBurst, capacityInFrames, flags) >= std::tie(rhs.readCounterParcelable, rhs.writeCounterParcelable, rhs.dataParcelable, rhs.bytesPerFrame, rhs.framesPerBurst, rhs.capacityInFrames, rhs.flags);
  }

  ::aaudio::SharedRegion readCounterParcelable;
  ::aaudio::SharedRegion writeCounterParcelable;
  ::aaudio::SharedRegion dataParcelable;
  int32_t bytesPerFrame = int32_t(0);
  int32_t framesPerBurst = int32_t(0);
  int32_t capacityInFrames = int32_t(0);
  int32_t flags = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"aaudio.RingBuffer");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "RingBuffer{";
    os << "readCounterParcelable: " << ::android::internal::ToString(readCounterParcelable);
    os << ", writeCounterParcelable: " << ::android::internal::ToString(writeCounterParcelable);
    os << ", dataParcelable: " << ::android::internal::ToString(dataParcelable);
    os << ", bytesPerFrame: " << ::android::internal::ToString(bytesPerFrame);
    os << ", framesPerBurst: " << ::android::internal::ToString(framesPerBurst);
    os << ", capacityInFrames: " << ::android::internal::ToString(capacityInFrames);
    os << ", flags: " << ::android::internal::ToString(flags);
    os << "}";
    return os.str();
  }
};  // class RingBuffer

}  // namespace aaudio
