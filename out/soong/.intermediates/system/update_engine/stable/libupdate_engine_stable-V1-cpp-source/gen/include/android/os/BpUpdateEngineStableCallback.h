#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IUpdateEngineStableCallback.h>

namespace android {

namespace os {

class BpUpdateEngineStableCallback : public ::android::BpInterface<IUpdateEngineStableCallback> {
public:
  explicit BpUpdateEngineStableCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpUpdateEngineStableCallback() = default;
  ::android::binder::Status onStatusUpdate(int32_t status_code, float percentage) override;
  ::android::binder::Status onPayloadApplicationComplete(int32_t error_code) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpUpdateEngineStableCallback

}  // namespace os

}  // namespace android
