#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <com/android/internal/net/IOemNetdUnsolicitedEventListener.h>

namespace com {

namespace android {

namespace internal {

namespace net {

class BpOemNetdUnsolicitedEventListener : public ::android::BpInterface<IOemNetdUnsolicitedEventListener> {
public:
  explicit BpOemNetdUnsolicitedEventListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpOemNetdUnsolicitedEventListener() = default;
  ::android::binder::Status onRegistered() override;
};  // class BpOemNetdUnsolicitedEventListener

}  // namespace net

}  // namespace internal

}  // namespace android

}  // namespace com
