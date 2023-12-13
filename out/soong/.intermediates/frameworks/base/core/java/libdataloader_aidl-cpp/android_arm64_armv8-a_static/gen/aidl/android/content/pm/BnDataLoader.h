#pragma once

#include <binder/IInterface.h>
#include <android/content/pm/IDataLoader.h>

namespace android {

namespace content {

namespace pm {

class BnDataLoader : public ::android::BnInterface<IDataLoader> {
public:
  static constexpr uint32_t TRANSACTION_create = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_start = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_stop = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_destroy = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_prepareImage = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  explicit BnDataLoader();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnDataLoader

}  // namespace pm

}  // namespace content

}  // namespace android
