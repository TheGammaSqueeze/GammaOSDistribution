#pragma once

#include <binder/IInterface.h>
#include <android/os/incremental/IIncrementalServiceConnector.h>

namespace android {

namespace os {

namespace incremental {

class BnIncrementalServiceConnector : public ::android::BnInterface<IIncrementalServiceConnector> {
public:
  static constexpr uint32_t TRANSACTION_setStorageParams = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnIncrementalServiceConnector();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnIncrementalServiceConnector

}  // namespace incremental

}  // namespace os

}  // namespace android
