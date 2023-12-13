#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IHintSession.h>

namespace android {

namespace os {

class BpHintSession : public ::android::BpInterface<IHintSession> {
public:
  explicit BpHintSession(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpHintSession() = default;
  ::android::binder::Status updateTargetWorkDuration(int64_t targetDurationNanos) override;
  ::android::binder::Status reportActualWorkDuration(const ::std::vector<int64_t>& actualDurationNanos, const ::std::vector<int64_t>& timeStampNanos) override;
  ::android::binder::Status close() override;
};  // class BpHintSession

}  // namespace os

}  // namespace android
