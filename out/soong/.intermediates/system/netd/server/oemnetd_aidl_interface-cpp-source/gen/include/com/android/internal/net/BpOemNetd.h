#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <com/android/internal/net/IOemNetd.h>

namespace com {

namespace android {

namespace internal {

namespace net {

class BpOemNetd : public ::android::BpInterface<IOemNetd> {
public:
  explicit BpOemNetd(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpOemNetd() = default;
  ::android::binder::Status isAlive(bool* _aidl_return) override;
  ::android::binder::Status registerOemUnsolicitedEventListener(const ::android::sp<::com::android::internal::net::IOemNetdUnsolicitedEventListener>& listener) override;
};  // class BpOemNetd

}  // namespace net

}  // namespace internal

}  // namespace android

}  // namespace com
