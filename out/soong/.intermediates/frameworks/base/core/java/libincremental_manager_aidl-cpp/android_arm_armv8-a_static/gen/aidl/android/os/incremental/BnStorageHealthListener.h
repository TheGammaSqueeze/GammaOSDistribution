#pragma once

#include <binder/IInterface.h>
#include <android/os/incremental/IStorageHealthListener.h>

namespace android {

namespace os {

namespace incremental {

class BnStorageHealthListener : public ::android::BnInterface<IStorageHealthListener> {
public:
  static constexpr uint32_t TRANSACTION_onHealthStatus = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnStorageHealthListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnStorageHealthListener

}  // namespace incremental

}  // namespace os

}  // namespace android
