#pragma once

#include <android/os/DropBoxManager.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/ParcelFileDescriptor.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace com {

namespace android {

namespace internal {

namespace os {

class IDropBoxManagerService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(DropBoxManagerService)
  virtual ::android::binder::Status addData(const ::android::String16& tag, const ::std::vector<uint8_t>& data, int32_t flags) = 0;
  virtual ::android::binder::Status addFile(const ::android::String16& tag, const ::android::os::ParcelFileDescriptor& fd, int32_t flags) = 0;
  virtual ::android::binder::Status isTagEnabled(const ::android::String16& tag, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getNextEntry(const ::android::String16& tag, int64_t millis, const ::android::String16& packageName, ::android::os::DropBoxManager::Entry* _aidl_return) = 0;
  virtual ::android::binder::Status getNextEntryWithAttribution(const ::android::String16& tag, int64_t millis, const ::android::String16& packageName, const ::android::String16& attributionTag, ::android::os::DropBoxManager::Entry* _aidl_return) = 0;
};  // class IDropBoxManagerService

class IDropBoxManagerServiceDefault : public IDropBoxManagerService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status addData(const ::android::String16&, const ::std::vector<uint8_t>&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addFile(const ::android::String16&, const ::android::os::ParcelFileDescriptor&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isTagEnabled(const ::android::String16&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getNextEntry(const ::android::String16&, int64_t, const ::android::String16&, ::android::os::DropBoxManager::Entry*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getNextEntryWithAttribution(const ::android::String16&, int64_t, const ::android::String16&, const ::android::String16&, ::android::os::DropBoxManager::Entry*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IDropBoxManagerServiceDefault

}  // namespace os

}  // namespace internal

}  // namespace android

}  // namespace com
