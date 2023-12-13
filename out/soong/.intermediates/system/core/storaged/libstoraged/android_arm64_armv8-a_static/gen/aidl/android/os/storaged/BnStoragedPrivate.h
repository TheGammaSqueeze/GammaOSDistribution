#pragma once

#include <binder/IInterface.h>
#include <android/os/storaged/IStoragedPrivate.h>

namespace android {

namespace os {

namespace storaged {

class BnStoragedPrivate : public ::android::BnInterface<IStoragedPrivate> {
public:
  static constexpr uint32_t TRANSACTION_dumpUids = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_dumpPerfHistory = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnStoragedPrivate();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnStoragedPrivate

}  // namespace storaged

}  // namespace os

}  // namespace android
