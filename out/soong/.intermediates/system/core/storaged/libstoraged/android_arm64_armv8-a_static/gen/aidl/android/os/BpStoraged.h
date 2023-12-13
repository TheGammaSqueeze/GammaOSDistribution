#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IStoraged.h>

namespace android {

namespace os {

class BpStoraged : public ::android::BpInterface<IStoraged> {
public:
  explicit BpStoraged(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpStoraged() = default;
  ::android::binder::Status onUserStarted(int32_t userId) override;
  ::android::binder::Status onUserStopped(int32_t userId) override;
  ::android::binder::Status getRecentPerf(int32_t* _aidl_return) override;
};  // class BpStoraged

}  // namespace os

}  // namespace android
