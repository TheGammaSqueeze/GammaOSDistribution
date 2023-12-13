#pragma once

#include <aaudio/RingBuffer.h>
#include <android/binder_to_string.h>
#include <android/media/SharedFileRegion.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace aaudio {

class Endpoint : public ::android::Parcelable {
public:
  inline bool operator!=(const Endpoint& rhs) const {
    return std::tie(upMessageQueueParcelable, downMessageQueueParcelable, upDataQueueParcelable, downDataQueueParcelable, sharedMemories) != std::tie(rhs.upMessageQueueParcelable, rhs.downMessageQueueParcelable, rhs.upDataQueueParcelable, rhs.downDataQueueParcelable, rhs.sharedMemories);
  }
  inline bool operator<(const Endpoint& rhs) const {
    return std::tie(upMessageQueueParcelable, downMessageQueueParcelable, upDataQueueParcelable, downDataQueueParcelable, sharedMemories) < std::tie(rhs.upMessageQueueParcelable, rhs.downMessageQueueParcelable, rhs.upDataQueueParcelable, rhs.downDataQueueParcelable, rhs.sharedMemories);
  }
  inline bool operator<=(const Endpoint& rhs) const {
    return std::tie(upMessageQueueParcelable, downMessageQueueParcelable, upDataQueueParcelable, downDataQueueParcelable, sharedMemories) <= std::tie(rhs.upMessageQueueParcelable, rhs.downMessageQueueParcelable, rhs.upDataQueueParcelable, rhs.downDataQueueParcelable, rhs.sharedMemories);
  }
  inline bool operator==(const Endpoint& rhs) const {
    return std::tie(upMessageQueueParcelable, downMessageQueueParcelable, upDataQueueParcelable, downDataQueueParcelable, sharedMemories) == std::tie(rhs.upMessageQueueParcelable, rhs.downMessageQueueParcelable, rhs.upDataQueueParcelable, rhs.downDataQueueParcelable, rhs.sharedMemories);
  }
  inline bool operator>(const Endpoint& rhs) const {
    return std::tie(upMessageQueueParcelable, downMessageQueueParcelable, upDataQueueParcelable, downDataQueueParcelable, sharedMemories) > std::tie(rhs.upMessageQueueParcelable, rhs.downMessageQueueParcelable, rhs.upDataQueueParcelable, rhs.downDataQueueParcelable, rhs.sharedMemories);
  }
  inline bool operator>=(const Endpoint& rhs) const {
    return std::tie(upMessageQueueParcelable, downMessageQueueParcelable, upDataQueueParcelable, downDataQueueParcelable, sharedMemories) >= std::tie(rhs.upMessageQueueParcelable, rhs.downMessageQueueParcelable, rhs.upDataQueueParcelable, rhs.downDataQueueParcelable, rhs.sharedMemories);
  }

  ::aaudio::RingBuffer upMessageQueueParcelable;
  ::aaudio::RingBuffer downMessageQueueParcelable;
  ::aaudio::RingBuffer upDataQueueParcelable;
  ::aaudio::RingBuffer downDataQueueParcelable;
  ::std::vector<::android::media::SharedFileRegion> sharedMemories;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"aaudio.Endpoint");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "Endpoint{";
    os << "upMessageQueueParcelable: " << ::android::internal::ToString(upMessageQueueParcelable);
    os << ", downMessageQueueParcelable: " << ::android::internal::ToString(downMessageQueueParcelable);
    os << ", upDataQueueParcelable: " << ::android::internal::ToString(upDataQueueParcelable);
    os << ", downDataQueueParcelable: " << ::android::internal::ToString(downDataQueueParcelable);
    os << ", sharedMemories: " << ::android::internal::ToString(sharedMemories);
    os << "}";
    return os.str();
  }
};  // class Endpoint

}  // namespace aaudio
