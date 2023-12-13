#pragma once

#include <android/os/IHintSession.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace os {

class IHintManager : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(HintManager)
  virtual ::android::binder::Status createHintSession(const ::android::sp<::android::IBinder>& token, const ::std::vector<int32_t>& tids, int64_t durationNanos, ::android::sp<::android::os::IHintSession>* _aidl_return) = 0;
  virtual ::android::binder::Status getHintSessionPreferredRate(int64_t* _aidl_return) = 0;
};  // class IHintManager

class IHintManagerDefault : public IHintManager {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status createHintSession(const ::android::sp<::android::IBinder>&, const ::std::vector<int32_t>&, int64_t, ::android::sp<::android::os::IHintSession>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getHintSessionPreferredRate(int64_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IHintManagerDefault

}  // namespace os

}  // namespace android
