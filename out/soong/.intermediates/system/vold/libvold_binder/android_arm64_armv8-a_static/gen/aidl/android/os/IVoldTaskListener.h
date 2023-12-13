#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/PersistableBundle.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IVoldTaskListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(VoldTaskListener)
  virtual ::android::binder::Status onStatus(int32_t status, const ::android::os::PersistableBundle& extras) = 0;
  virtual ::android::binder::Status onFinished(int32_t status, const ::android::os::PersistableBundle& extras) = 0;
};  // class IVoldTaskListener

class IVoldTaskListenerDefault : public IVoldTaskListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onStatus(int32_t, const ::android::os::PersistableBundle&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onFinished(int32_t, const ::android::os::PersistableBundle&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IVoldTaskListenerDefault

}  // namespace os

}  // namespace android
