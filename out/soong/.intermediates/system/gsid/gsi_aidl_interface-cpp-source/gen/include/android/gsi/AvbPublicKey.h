#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace gsi {

class AvbPublicKey : public ::android::Parcelable {
public:
  inline bool operator!=(const AvbPublicKey& rhs) const {
    return std::tie(bytes, sha1) != std::tie(rhs.bytes, rhs.sha1);
  }
  inline bool operator<(const AvbPublicKey& rhs) const {
    return std::tie(bytes, sha1) < std::tie(rhs.bytes, rhs.sha1);
  }
  inline bool operator<=(const AvbPublicKey& rhs) const {
    return std::tie(bytes, sha1) <= std::tie(rhs.bytes, rhs.sha1);
  }
  inline bool operator==(const AvbPublicKey& rhs) const {
    return std::tie(bytes, sha1) == std::tie(rhs.bytes, rhs.sha1);
  }
  inline bool operator>(const AvbPublicKey& rhs) const {
    return std::tie(bytes, sha1) > std::tie(rhs.bytes, rhs.sha1);
  }
  inline bool operator>=(const AvbPublicKey& rhs) const {
    return std::tie(bytes, sha1) >= std::tie(rhs.bytes, rhs.sha1);
  }

  ::std::vector<uint8_t> bytes;
  ::std::vector<uint8_t> sha1;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.gsi.AvbPublicKey");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AvbPublicKey{";
    os << "bytes: " << ::android::internal::ToString(bytes);
    os << ", sha1: " << ::android::internal::ToString(sha1);
    os << "}";
    return os.str();
  }
};  // class AvbPublicKey

}  // namespace gsi

}  // namespace android
