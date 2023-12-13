#pragma once

#include <android/gsi/AvbPublicKey.h>
#include <android/gsi/GsiProgress.h>
#include <android/gsi/IGsiServiceCallback.h>
#include <android/gsi/IImageService.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/ParcelFileDescriptor.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace gsi {

class IGsiService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(GsiService)
  enum  : int32_t {
    STATUS_NO_OPERATION = 0,
    STATUS_WORKING = 1,
    STATUS_COMPLETE = 2,
    INSTALL_OK = 0,
    INSTALL_ERROR_GENERIC = 1,
    INSTALL_ERROR_NO_SPACE = 2,
    INSTALL_ERROR_FILE_SYSTEM_CLUTTERED = 3,
  };
  virtual ::android::binder::Status commitGsiChunkFromStream(const ::android::os::ParcelFileDescriptor& stream, int64_t bytes, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getInstallProgress(::android::gsi::GsiProgress* _aidl_return) = 0;
  virtual ::android::binder::Status setGsiAshmem(const ::android::os::ParcelFileDescriptor& stream, int64_t size, bool* _aidl_return) = 0;
  virtual ::android::binder::Status commitGsiChunkFromAshmem(int64_t bytes, bool* _aidl_return) = 0;
  virtual ::android::binder::Status enableGsi(bool oneShot, const ::std::string& dsuSlot, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status enableGsiAsync(bool oneShot, const ::std::string& dsuSlot, const ::android::sp<::android::gsi::IGsiServiceCallback>& result) = 0;
  virtual ::android::binder::Status isGsiEnabled(bool* _aidl_return) = 0;
  virtual ::android::binder::Status cancelGsiInstall(bool* _aidl_return) = 0;
  virtual ::android::binder::Status isGsiInstallInProgress(bool* _aidl_return) = 0;
  virtual ::android::binder::Status removeGsi(bool* _aidl_return) = 0;
  virtual ::android::binder::Status removeGsiAsync(const ::android::sp<::android::gsi::IGsiServiceCallback>& result) = 0;
  virtual ::android::binder::Status disableGsi(bool* _aidl_return) = 0;
  virtual ::android::binder::Status isGsiInstalled(bool* _aidl_return) = 0;
  virtual ::android::binder::Status isGsiRunning(bool* _aidl_return) = 0;
  virtual ::android::binder::Status getActiveDsuSlot(::std::string* _aidl_return) = 0;
  virtual ::android::binder::Status getInstalledGsiImageDir(::std::string* _aidl_return) = 0;
  virtual ::android::binder::Status getInstalledDsuSlots(::std::vector<::std::string>* _aidl_return) = 0;
  virtual ::android::binder::Status openInstall(const ::std::string& installDir, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status closeInstall(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status createPartition(const ::std::string& name, int64_t size, bool readOnly, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status closePartition(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status zeroPartition(const ::std::string& name, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status openImageService(const ::std::string& prefix, ::android::sp<::android::gsi::IImageService>* _aidl_return) = 0;
  virtual ::android::binder::Status dumpDeviceMapperDevices(::std::string* _aidl_return) = 0;
  virtual ::android::binder::Status getAvbPublicKey(::android::gsi::AvbPublicKey* dst, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status suggestScratchSize(int64_t* _aidl_return) = 0;
};  // class IGsiService

class IGsiServiceDefault : public IGsiService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status commitGsiChunkFromStream(const ::android::os::ParcelFileDescriptor&, int64_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getInstallProgress(::android::gsi::GsiProgress*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setGsiAshmem(const ::android::os::ParcelFileDescriptor&, int64_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status commitGsiChunkFromAshmem(int64_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status enableGsi(bool, const ::std::string&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status enableGsiAsync(bool, const ::std::string&, const ::android::sp<::android::gsi::IGsiServiceCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isGsiEnabled(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status cancelGsiInstall(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isGsiInstallInProgress(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeGsi(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeGsiAsync(const ::android::sp<::android::gsi::IGsiServiceCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status disableGsi(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isGsiInstalled(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isGsiRunning(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getActiveDsuSlot(::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getInstalledGsiImageDir(::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getInstalledDsuSlots(::std::vector<::std::string>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status openInstall(const ::std::string&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status closeInstall(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createPartition(const ::std::string&, int64_t, bool, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status closePartition(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status zeroPartition(const ::std::string&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status openImageService(const ::std::string&, ::android::sp<::android::gsi::IImageService>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status dumpDeviceMapperDevices(::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAvbPublicKey(::android::gsi::AvbPublicKey*, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status suggestScratchSize(int64_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IGsiServiceDefault

}  // namespace gsi

}  // namespace android
