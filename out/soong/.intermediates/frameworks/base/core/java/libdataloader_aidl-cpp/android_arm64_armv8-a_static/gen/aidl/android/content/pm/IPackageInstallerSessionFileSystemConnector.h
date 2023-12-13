#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/ParcelFileDescriptor.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace content {

namespace pm {

class IPackageInstallerSessionFileSystemConnector : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(PackageInstallerSessionFileSystemConnector)
  virtual ::android::binder::Status writeData(const ::android::String16& name, int64_t offsetBytes, int64_t lengthBytes, const ::android::os::ParcelFileDescriptor& fd) = 0;
};  // class IPackageInstallerSessionFileSystemConnector

class IPackageInstallerSessionFileSystemConnectorDefault : public IPackageInstallerSessionFileSystemConnector {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status writeData(const ::android::String16&, int64_t, int64_t, const ::android::os::ParcelFileDescriptor&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IPackageInstallerSessionFileSystemConnectorDefault

}  // namespace pm

}  // namespace content

}  // namespace android
