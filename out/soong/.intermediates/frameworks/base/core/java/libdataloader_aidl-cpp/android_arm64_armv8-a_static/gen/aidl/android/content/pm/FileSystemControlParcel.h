#pragma once

#include <android/binder_to_string.h>
#include <android/content/pm/IPackageInstallerSessionFileSystemConnector.h>
#include <android/os/incremental/IIncrementalServiceConnector.h>
#include <android/os/incremental/IncrementalFileSystemControlParcel.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <optional>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace content {

namespace pm {

class FileSystemControlParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const FileSystemControlParcel& rhs) const {
    return std::tie(incremental, service, callback) != std::tie(rhs.incremental, rhs.service, rhs.callback);
  }
  inline bool operator<(const FileSystemControlParcel& rhs) const {
    return std::tie(incremental, service, callback) < std::tie(rhs.incremental, rhs.service, rhs.callback);
  }
  inline bool operator<=(const FileSystemControlParcel& rhs) const {
    return std::tie(incremental, service, callback) <= std::tie(rhs.incremental, rhs.service, rhs.callback);
  }
  inline bool operator==(const FileSystemControlParcel& rhs) const {
    return std::tie(incremental, service, callback) == std::tie(rhs.incremental, rhs.service, rhs.callback);
  }
  inline bool operator>(const FileSystemControlParcel& rhs) const {
    return std::tie(incremental, service, callback) > std::tie(rhs.incremental, rhs.service, rhs.callback);
  }
  inline bool operator>=(const FileSystemControlParcel& rhs) const {
    return std::tie(incremental, service, callback) >= std::tie(rhs.incremental, rhs.service, rhs.callback);
  }

  ::std::optional<::android::os::incremental::IncrementalFileSystemControlParcel> incremental;
  ::android::sp<::android::os::incremental::IIncrementalServiceConnector> service;
  ::android::sp<::android::content::pm::IPackageInstallerSessionFileSystemConnector> callback;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.content.pm.FileSystemControlParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "FileSystemControlParcel{";
    os << "incremental: " << ::android::internal::ToString(incremental);
    os << ", service: " << ::android::internal::ToString(service);
    os << ", callback: " << ::android::internal::ToString(callback);
    os << "}";
    return os.str();
  }
};  // class FileSystemControlParcel

}  // namespace pm

}  // namespace content

}  // namespace android
