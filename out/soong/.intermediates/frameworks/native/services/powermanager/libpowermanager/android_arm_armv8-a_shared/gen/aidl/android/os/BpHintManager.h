#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IHintManager.h>

namespace android {

namespace os {

class BpHintManager : public ::android::BpInterface<IHintManager> {
public:
  explicit BpHintManager(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpHintManager() = default;
  ::android::binder::Status createHintSession(const ::android::sp<::android::IBinder>& token, const ::std::vector<int32_t>& tids, int64_t durationNanos, ::android::sp<::android::os::IHintSession>* _aidl_return) override;
  ::android::binder::Status getHintSessionPreferredRate(int64_t* _aidl_return) override;
};  // class BpHintManager

}  // namespace os

}  // namespace android
