#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/gsi/IGsiService.h>

namespace android {

namespace gsi {

class BpGsiService : public ::android::BpInterface<IGsiService> {
public:
  explicit BpGsiService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpGsiService() = default;
  ::android::binder::Status commitGsiChunkFromStream(const ::android::os::ParcelFileDescriptor& stream, int64_t bytes, bool* _aidl_return) override;
  ::android::binder::Status getInstallProgress(::android::gsi::GsiProgress* _aidl_return) override;
  ::android::binder::Status setGsiAshmem(const ::android::os::ParcelFileDescriptor& stream, int64_t size, bool* _aidl_return) override;
  ::android::binder::Status commitGsiChunkFromAshmem(int64_t bytes, bool* _aidl_return) override;
  ::android::binder::Status enableGsi(bool oneShot, const ::std::string& dsuSlot, int32_t* _aidl_return) override;
  ::android::binder::Status enableGsiAsync(bool oneShot, const ::std::string& dsuSlot, const ::android::sp<::android::gsi::IGsiServiceCallback>& result) override;
  ::android::binder::Status isGsiEnabled(bool* _aidl_return) override;
  ::android::binder::Status cancelGsiInstall(bool* _aidl_return) override;
  ::android::binder::Status isGsiInstallInProgress(bool* _aidl_return) override;
  ::android::binder::Status removeGsi(bool* _aidl_return) override;
  ::android::binder::Status removeGsiAsync(const ::android::sp<::android::gsi::IGsiServiceCallback>& result) override;
  ::android::binder::Status disableGsi(bool* _aidl_return) override;
  ::android::binder::Status isGsiInstalled(bool* _aidl_return) override;
  ::android::binder::Status isGsiRunning(bool* _aidl_return) override;
  ::android::binder::Status getActiveDsuSlot(::std::string* _aidl_return) override;
  ::android::binder::Status getInstalledGsiImageDir(::std::string* _aidl_return) override;
  ::android::binder::Status getInstalledDsuSlots(::std::vector<::std::string>* _aidl_return) override;
  ::android::binder::Status openInstall(const ::std::string& installDir, int32_t* _aidl_return) override;
  ::android::binder::Status closeInstall(int32_t* _aidl_return) override;
  ::android::binder::Status createPartition(const ::std::string& name, int64_t size, bool readOnly, int32_t* _aidl_return) override;
  ::android::binder::Status closePartition(int32_t* _aidl_return) override;
  ::android::binder::Status zeroPartition(const ::std::string& name, int32_t* _aidl_return) override;
  ::android::binder::Status openImageService(const ::std::string& prefix, ::android::sp<::android::gsi::IImageService>* _aidl_return) override;
  ::android::binder::Status dumpDeviceMapperDevices(::std::string* _aidl_return) override;
  ::android::binder::Status getAvbPublicKey(::android::gsi::AvbPublicKey* dst, int32_t* _aidl_return) override;
  ::android::binder::Status suggestScratchSize(int64_t* _aidl_return) override;
};  // class BpGsiService

}  // namespace gsi

}  // namespace android
