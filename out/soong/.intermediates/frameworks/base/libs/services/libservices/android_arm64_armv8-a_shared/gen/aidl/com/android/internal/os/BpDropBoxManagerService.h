#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <com/android/internal/os/IDropBoxManagerService.h>

namespace com {

namespace android {

namespace internal {

namespace os {

class BpDropBoxManagerService : public ::android::BpInterface<IDropBoxManagerService> {
public:
  explicit BpDropBoxManagerService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpDropBoxManagerService() = default;
  ::android::binder::Status addData(const ::android::String16& tag, const ::std::vector<uint8_t>& data, int32_t flags) override;
  ::android::binder::Status addFile(const ::android::String16& tag, const ::android::os::ParcelFileDescriptor& fd, int32_t flags) override;
  ::android::binder::Status isTagEnabled(const ::android::String16& tag, bool* _aidl_return) override;
  ::android::binder::Status getNextEntry(const ::android::String16& tag, int64_t millis, const ::android::String16& packageName, ::android::os::DropBoxManager::Entry* _aidl_return) override;
  ::android::binder::Status getNextEntryWithAttribution(const ::android::String16& tag, int64_t millis, const ::android::String16& packageName, const ::android::String16& attributionTag, ::android::os::DropBoxManager::Entry* _aidl_return) override;
};  // class BpDropBoxManagerService

}  // namespace os

}  // namespace internal

}  // namespace android

}  // namespace com
