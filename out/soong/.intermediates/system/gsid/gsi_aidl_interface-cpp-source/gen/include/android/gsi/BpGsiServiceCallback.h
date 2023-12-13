#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/gsi/IGsiServiceCallback.h>

namespace android {

namespace gsi {

class BpGsiServiceCallback : public ::android::BpInterface<IGsiServiceCallback> {
public:
  explicit BpGsiServiceCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpGsiServiceCallback() = default;
  ::android::binder::Status onResult(int32_t result) override;
};  // class BpGsiServiceCallback

}  // namespace gsi

}  // namespace android
