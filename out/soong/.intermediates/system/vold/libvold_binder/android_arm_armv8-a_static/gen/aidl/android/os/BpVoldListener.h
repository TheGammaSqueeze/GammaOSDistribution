#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IVoldListener.h>

namespace android {

namespace os {

class BpVoldListener : public ::android::BpInterface<IVoldListener> {
public:
  explicit BpVoldListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpVoldListener() = default;
  ::android::binder::Status onDiskCreated(const ::std::string& diskId, int32_t flags) override;
  ::android::binder::Status onDiskScanned(const ::std::string& diskId) override;
  ::android::binder::Status onDiskMetadataChanged(const ::std::string& diskId, int64_t sizeBytes, const ::std::string& label, const ::std::string& sysPath) override;
  ::android::binder::Status onDiskDestroyed(const ::std::string& diskId) override;
  ::android::binder::Status onVolumeCreated(const ::std::string& volId, int32_t type, const ::std::string& diskId, const ::std::string& partGuid, int32_t userId) override;
  ::android::binder::Status onVolumeStateChanged(const ::std::string& volId, int32_t state) override;
  ::android::binder::Status onVolumeMetadataChanged(const ::std::string& volId, const ::std::string& fsType, const ::std::string& fsUuid, const ::std::string& fsLabel) override;
  ::android::binder::Status onVolumePathChanged(const ::std::string& volId, const ::std::string& path) override;
  ::android::binder::Status onVolumeInternalPathChanged(const ::std::string& volId, const ::std::string& internalPath) override;
  ::android::binder::Status onVolumeDestroyed(const ::std::string& volId) override;
};  // class BpVoldListener

}  // namespace os

}  // namespace android
