#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/gsi/IProgressCallback.h>

namespace android {

namespace gsi {

class BpProgressCallback : public ::android::BpInterface<IProgressCallback> {
public:
  explicit BpProgressCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpProgressCallback() = default;
  ::android::binder::Status onProgress(int64_t current, int64_t total) override;
};  // class BpProgressCallback

}  // namespace gsi

}  // namespace android
