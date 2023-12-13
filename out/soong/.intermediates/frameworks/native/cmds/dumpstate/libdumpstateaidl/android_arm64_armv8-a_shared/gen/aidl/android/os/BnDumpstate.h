#pragma once

#include <binder/IInterface.h>
#include <android/os/IDumpstate.h>

namespace android {

namespace os {

class BnDumpstate : public ::android::BnInterface<IDumpstate> {
public:
  static constexpr uint32_t TRANSACTION_startBugreport = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_cancelBugreport = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnDumpstate();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnDumpstate

}  // namespace os

}  // namespace android
