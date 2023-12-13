#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace os {

class IHintSession : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(HintSession)
  virtual ::android::binder::Status updateTargetWorkDuration(int64_t targetDurationNanos) = 0;
  virtual ::android::binder::Status reportActualWorkDuration(const ::std::vector<int64_t>& actualDurationNanos, const ::std::vector<int64_t>& timeStampNanos) = 0;
  virtual ::android::binder::Status close() = 0;
};  // class IHintSession

class IHintSessionDefault : public IHintSession {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status updateTargetWorkDuration(int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status reportActualWorkDuration(const ::std::vector<int64_t>&, const ::std::vector<int64_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status close() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IHintSessionDefault

}  // namespace os

}  // namespace android
