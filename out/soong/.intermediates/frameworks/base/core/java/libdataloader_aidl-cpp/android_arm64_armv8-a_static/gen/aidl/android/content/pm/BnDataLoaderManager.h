#pragma once

#include <binder/IInterface.h>
#include <android/content/pm/IDataLoaderManager.h>

namespace android {

namespace content {

namespace pm {

class BnDataLoaderManager : public ::android::BnInterface<IDataLoaderManager> {
public:
  static constexpr uint32_t TRANSACTION_bindToDataLoader = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getDataLoader = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_unbindFromDataLoader = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  explicit BnDataLoaderManager();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnDataLoaderManager

}  // namespace pm

}  // namespace content

}  // namespace android
