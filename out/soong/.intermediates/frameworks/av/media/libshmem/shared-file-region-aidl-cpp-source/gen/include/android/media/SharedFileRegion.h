#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/ParcelFileDescriptor.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class SharedFileRegion : public ::android::Parcelable {
public:
  inline bool operator!=(const SharedFileRegion& rhs) const {
    return std::tie(fd, offset, size, writeable) != std::tie(rhs.fd, rhs.offset, rhs.size, rhs.writeable);
  }
  inline bool operator<(const SharedFileRegion& rhs) const {
    return std::tie(fd, offset, size, writeable) < std::tie(rhs.fd, rhs.offset, rhs.size, rhs.writeable);
  }
  inline bool operator<=(const SharedFileRegion& rhs) const {
    return std::tie(fd, offset, size, writeable) <= std::tie(rhs.fd, rhs.offset, rhs.size, rhs.writeable);
  }
  inline bool operator==(const SharedFileRegion& rhs) const {
    return std::tie(fd, offset, size, writeable) == std::tie(rhs.fd, rhs.offset, rhs.size, rhs.writeable);
  }
  inline bool operator>(const SharedFileRegion& rhs) const {
    return std::tie(fd, offset, size, writeable) > std::tie(rhs.fd, rhs.offset, rhs.size, rhs.writeable);
  }
  inline bool operator>=(const SharedFileRegion& rhs) const {
    return std::tie(fd, offset, size, writeable) >= std::tie(rhs.fd, rhs.offset, rhs.size, rhs.writeable);
  }

  ::android::os::ParcelFileDescriptor fd;
  int64_t offset = int64_t(0L);
  int64_t size = int64_t(0L);
  bool writeable = bool(false);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.SharedFileRegion");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "SharedFileRegion{";
    os << "fd: " << ::android::internal::ToString(fd);
    os << ", offset: " << ::android::internal::ToString(offset);
    os << ", size: " << ::android::internal::ToString(size);
    os << ", writeable: " << ::android::internal::ToString(writeable);
    os << "}";
    return os.str();
  }
};  // class SharedFileRegion

}  // namespace media

}  // namespace android
