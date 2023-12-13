#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IUpdateEngineCallback.h>

namespace android {

namespace os {

class BpUpdateEngineCallback : public ::android::BpInterface<IUpdateEngineCallback> {
public:
  explicit BpUpdateEngineCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpUpdateEngineCallback() = default;
  ::android::binder::Status onStatusUpdate(int32_t status_code, float percentage) override;
  ::android::binder::Status onPayloadApplicationComplete(int32_t error_code) override;
};  // class BpUpdateEngineCallback

}  // namespace os

}  // namespace android
