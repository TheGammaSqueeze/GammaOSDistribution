#pragma once

#include <binder/IInterface.h>
#include <android/content/pm/IDataLoaderStatusListener.h>

namespace android {

namespace content {

namespace pm {

class BnDataLoaderStatusListener : public ::android::BnInterface<IDataLoaderStatusListener> {
public:
  static constexpr uint32_t TRANSACTION_onStatusChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnDataLoaderStatusListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnDataLoaderStatusListener

}  // namespace pm

}  // namespace content

}  // namespace android
