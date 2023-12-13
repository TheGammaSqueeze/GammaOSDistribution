#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/content/pm/IPackageInstallerSessionFileSystemConnector.h>

namespace android {

namespace content {

namespace pm {

class BpPackageInstallerSessionFileSystemConnector : public ::android::BpInterface<IPackageInstallerSessionFileSystemConnector> {
public:
  explicit BpPackageInstallerSessionFileSystemConnector(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpPackageInstallerSessionFileSystemConnector() = default;
  ::android::binder::Status writeData(const ::android::String16& name, int64_t offsetBytes, int64_t lengthBytes, const ::android::os::ParcelFileDescriptor& fd) override;
};  // class BpPackageInstallerSessionFileSystemConnector

}  // namespace pm

}  // namespace content

}  // namespace android
