#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace os {

namespace incremental {

class IncrementalNewFileParams : public ::android::Parcelable {
public:
  inline bool operator!=(const IncrementalNewFileParams& rhs) const {
    return std::tie(size, fileId, metadata, signature) != std::tie(rhs.size, rhs.fileId, rhs.metadata, rhs.signature);
  }
  inline bool operator<(const IncrementalNewFileParams& rhs) const {
    return std::tie(size, fileId, metadata, signature) < std::tie(rhs.size, rhs.fileId, rhs.metadata, rhs.signature);
  }
  inline bool operator<=(const IncrementalNewFileParams& rhs) const {
    return std::tie(size, fileId, metadata, signature) <= std::tie(rhs.size, rhs.fileId, rhs.metadata, rhs.signature);
  }
  inline bool operator==(const IncrementalNewFileParams& rhs) const {
    return std::tie(size, fileId, metadata, signature) == std::tie(rhs.size, rhs.fileId, rhs.metadata, rhs.signature);
  }
  inline bool operator>(const IncrementalNewFileParams& rhs) const {
    return std::tie(size, fileId, metadata, signature) > std::tie(rhs.size, rhs.fileId, rhs.metadata, rhs.signature);
  }
  inline bool operator>=(const IncrementalNewFileParams& rhs) const {
    return std::tie(size, fileId, metadata, signature) >= std::tie(rhs.size, rhs.fileId, rhs.metadata, rhs.signature);
  }

  int64_t size = int64_t(0L);
  ::std::vector<uint8_t> fileId;
  ::std::vector<uint8_t> metadata;
  ::std::optional<::std::vector<uint8_t>> signature;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.os.incremental.IncrementalNewFileParams");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "IncrementalNewFileParams{";
    os << "size: " << ::android::internal::ToString(size);
    os << ", fileId: " << ::android::internal::ToString(fileId);
    os << ", metadata: " << ::android::internal::ToString(metadata);
    os << ", signature: " << ::android::internal::ToString(signature);
    os << "}";
    return os.str();
  }
};  // class IncrementalNewFileParams

}  // namespace incremental

}  // namespace os

}  // namespace android
