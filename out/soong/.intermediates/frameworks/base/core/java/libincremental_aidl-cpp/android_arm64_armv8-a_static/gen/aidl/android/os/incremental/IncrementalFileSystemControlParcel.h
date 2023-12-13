#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/ParcelFileDescriptor.h>
#include <binder/Status.h>
#include <optional>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace os {

namespace incremental {

class IncrementalFileSystemControlParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const IncrementalFileSystemControlParcel& rhs) const {
    return std::tie(cmd, pendingReads, log, blocksWritten) != std::tie(rhs.cmd, rhs.pendingReads, rhs.log, rhs.blocksWritten);
  }
  inline bool operator<(const IncrementalFileSystemControlParcel& rhs) const {
    return std::tie(cmd, pendingReads, log, blocksWritten) < std::tie(rhs.cmd, rhs.pendingReads, rhs.log, rhs.blocksWritten);
  }
  inline bool operator<=(const IncrementalFileSystemControlParcel& rhs) const {
    return std::tie(cmd, pendingReads, log, blocksWritten) <= std::tie(rhs.cmd, rhs.pendingReads, rhs.log, rhs.blocksWritten);
  }
  inline bool operator==(const IncrementalFileSystemControlParcel& rhs) const {
    return std::tie(cmd, pendingReads, log, blocksWritten) == std::tie(rhs.cmd, rhs.pendingReads, rhs.log, rhs.blocksWritten);
  }
  inline bool operator>(const IncrementalFileSystemControlParcel& rhs) const {
    return std::tie(cmd, pendingReads, log, blocksWritten) > std::tie(rhs.cmd, rhs.pendingReads, rhs.log, rhs.blocksWritten);
  }
  inline bool operator>=(const IncrementalFileSystemControlParcel& rhs) const {
    return std::tie(cmd, pendingReads, log, blocksWritten) >= std::tie(rhs.cmd, rhs.pendingReads, rhs.log, rhs.blocksWritten);
  }

  ::android::os::ParcelFileDescriptor cmd;
  ::android::os::ParcelFileDescriptor pendingReads;
  ::android::os::ParcelFileDescriptor log;
  ::std::optional<::android::os::ParcelFileDescriptor> blocksWritten;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.os.incremental.IncrementalFileSystemControlParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "IncrementalFileSystemControlParcel{";
    os << "cmd: " << ::android::internal::ToString(cmd);
    os << ", pendingReads: " << ::android::internal::ToString(pendingReads);
    os << ", log: " << ::android::internal::ToString(log);
    os << ", blocksWritten: " << ::android::internal::ToString(blocksWritten);
    os << "}";
    return os.str();
  }
};  // class IncrementalFileSystemControlParcel

}  // namespace incremental

}  // namespace os

}  // namespace android
