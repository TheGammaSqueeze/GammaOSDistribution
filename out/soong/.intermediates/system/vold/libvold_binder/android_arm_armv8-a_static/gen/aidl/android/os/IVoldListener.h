#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IVoldListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(VoldListener)
  virtual ::android::binder::Status onDiskCreated(const ::std::string& diskId, int32_t flags) = 0;
  virtual ::android::binder::Status onDiskScanned(const ::std::string& diskId) = 0;
  virtual ::android::binder::Status onDiskMetadataChanged(const ::std::string& diskId, int64_t sizeBytes, const ::std::string& label, const ::std::string& sysPath) = 0;
  virtual ::android::binder::Status onDiskDestroyed(const ::std::string& diskId) = 0;
  virtual ::android::binder::Status onVolumeCreated(const ::std::string& volId, int32_t type, const ::std::string& diskId, const ::std::string& partGuid, int32_t userId) = 0;
  virtual ::android::binder::Status onVolumeStateChanged(const ::std::string& volId, int32_t state) = 0;
  virtual ::android::binder::Status onVolumeMetadataChanged(const ::std::string& volId, const ::std::string& fsType, const ::std::string& fsUuid, const ::std::string& fsLabel) = 0;
  virtual ::android::binder::Status onVolumePathChanged(const ::std::string& volId, const ::std::string& path) = 0;
  virtual ::android::binder::Status onVolumeInternalPathChanged(const ::std::string& volId, const ::std::string& internalPath) = 0;
  virtual ::android::binder::Status onVolumeDestroyed(const ::std::string& volId) = 0;
};  // class IVoldListener

class IVoldListenerDefault : public IVoldListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onDiskCreated(const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onDiskScanned(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onDiskMetadataChanged(const ::std::string&, int64_t, const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onDiskDestroyed(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onVolumeCreated(const ::std::string&, int32_t, const ::std::string&, const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onVolumeStateChanged(const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onVolumeMetadataChanged(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onVolumePathChanged(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onVolumeInternalPathChanged(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onVolumeDestroyed(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IVoldListenerDefault

}  // namespace os

}  // namespace android
