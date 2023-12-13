#pragma once

#include <binder/IInterface.h>
#include <android/os/incremental/IStorageLoadingProgressListener.h>

namespace android {

namespace os {

namespace incremental {

class BnStorageLoadingProgressListener : public ::android::BnInterface<IStorageLoadingProgressListener> {
public:
  static constexpr uint32_t TRANSACTION_onStorageLoadingProgressChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnStorageLoadingProgressListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnStorageLoadingProgressListener

}  // namespace incremental

}  // namespace os

}  // namespace android
