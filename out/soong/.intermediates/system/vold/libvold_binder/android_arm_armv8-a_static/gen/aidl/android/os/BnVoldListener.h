#pragma once

#include <binder/IInterface.h>
#include <android/os/IVoldListener.h>

namespace android {

namespace os {

class BnVoldListener : public ::android::BnInterface<IVoldListener> {
public:
  static constexpr uint32_t TRANSACTION_onDiskCreated = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onDiskScanned = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onDiskMetadataChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onDiskDestroyed = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onVolumeCreated = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_onVolumeStateChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_onVolumeMetadataChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_onVolumePathChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_onVolumeInternalPathChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_onVolumeDestroyed = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  explicit BnVoldListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnVoldListener

}  // namespace os

}  // namespace android
