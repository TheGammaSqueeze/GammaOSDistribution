#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IUpdateEngineStable.h>

namespace android {

namespace os {

class BpUpdateEngineStable : public ::android::BpInterface<IUpdateEngineStable> {
public:
  explicit BpUpdateEngineStable(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpUpdateEngineStable() = default;
  ::android::binder::Status applyPayloadFd(const ::android::os::ParcelFileDescriptor& pfd, int64_t payload_offset, int64_t payload_size, const ::std::vector<::android::String16>& headerKeyValuePairs) override;
  ::android::binder::Status bind(const ::android::sp<::android::os::IUpdateEngineStableCallback>& callback, bool* _aidl_return) override;
  ::android::binder::Status unbind(const ::android::sp<::android::os::IUpdateEngineStableCallback>& callback, bool* _aidl_return) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpUpdateEngineStable

}  // namespace os

}  // namespace android
