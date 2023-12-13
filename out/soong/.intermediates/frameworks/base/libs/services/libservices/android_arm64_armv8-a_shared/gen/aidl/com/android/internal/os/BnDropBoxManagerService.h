#pragma once

#include <binder/IInterface.h>
#include <com/android/internal/os/IDropBoxManagerService.h>

namespace com {

namespace android {

namespace internal {

namespace os {

class BnDropBoxManagerService : public ::android::BnInterface<IDropBoxManagerService> {
public:
  static constexpr uint32_t TRANSACTION_addData = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_addFile = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_isTagEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getNextEntry = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getNextEntryWithAttribution = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  explicit BnDropBoxManagerService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnDropBoxManagerService

}  // namespace os

}  // namespace internal

}  // namespace android

}  // namespace com
