#pragma once

#include <binder/IInterface.h>
#include <android/content/pm/IPackageInstallerSessionFileSystemConnector.h>

namespace android {

namespace content {

namespace pm {

class BnPackageInstallerSessionFileSystemConnector : public ::android::BnInterface<IPackageInstallerSessionFileSystemConnector> {
public:
  static constexpr uint32_t TRANSACTION_writeData = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnPackageInstallerSessionFileSystemConnector();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnPackageInstallerSessionFileSystemConnector

}  // namespace pm

}  // namespace content

}  // namespace android
