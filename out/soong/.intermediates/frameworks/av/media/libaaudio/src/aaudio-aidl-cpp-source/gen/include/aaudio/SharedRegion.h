#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace aaudio {

class SharedRegion : public ::android::Parcelable {
public:
  inline bool operator!=(const SharedRegion& rhs) const {
    return std::tie(sharedMemoryIndex, offsetInBytes, sizeInBytes) != std::tie(rhs.sharedMemoryIndex, rhs.offsetInBytes, rhs.sizeInBytes);
  }
  inline bool operator<(const SharedRegion& rhs) const {
    return std::tie(sharedMemoryIndex, offsetInBytes, sizeInBytes) < std::tie(rhs.sharedMemoryIndex, rhs.offsetInBytes, rhs.sizeInBytes);
  }
  inline bool operator<=(const SharedRegion& rhs) const {
    return std::tie(sharedMemoryIndex, offsetInBytes, sizeInBytes) <= std::tie(rhs.sharedMemoryIndex, rhs.offsetInBytes, rhs.sizeInBytes);
  }
  inline bool operator==(const SharedRegion& rhs) const {
    return std::tie(sharedMemoryIndex, offsetInBytes, sizeInBytes) == std::tie(rhs.sharedMemoryIndex, rhs.offsetInBytes, rhs.sizeInBytes);
  }
  inline bool operator>(const SharedRegion& rhs) const {
    return std::tie(sharedMemoryIndex, offsetInBytes, sizeInBytes) > std::tie(rhs.sharedMemoryIndex, rhs.offsetInBytes, rhs.sizeInBytes);
  }
  inline bool operator>=(const SharedRegion& rhs) const {
    return std::tie(sharedMemoryIndex, offsetInBytes, sizeInBytes) >= std::tie(rhs.sharedMemoryIndex, rhs.offsetInBytes, rhs.sizeInBytes);
  }

  int32_t sharedMemoryIndex = int32_t(0);
  int32_t offsetInBytes = int32_t(0);
  int32_t sizeInBytes = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"aaudio.SharedRegion");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "SharedRegion{";
    os << "sharedMemoryIndex: " << ::android::internal::ToString(sharedMemoryIndex);
    os << ", offsetInBytes: " << ::android::internal::ToString(offsetInBytes);
    os << ", sizeInBytes: " << ::android::internal::ToString(sizeInBytes);
    os << "}";
    return os.str();
  }
};  // class SharedRegion

}  // namespace aaudio
