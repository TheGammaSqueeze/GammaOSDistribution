#pragma once

#include <binder/IInterface.h>
#include <android/os/IIdmap2.h>

namespace android {

namespace os {

class BnIdmap2 : public ::android::BnInterface<IIdmap2> {
public:
  static constexpr uint32_t TRANSACTION_getIdmapPath = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_removeIdmap = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_verifyIdmap = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_createIdmap = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_createFabricatedOverlay = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_deleteFabricatedOverlay = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_acquireFabricatedOverlayIterator = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_releaseFabricatedOverlayIterator = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_nextFabricatedOverlayInfos = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_dumpIdmap = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  explicit BnIdmap2();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnIdmap2

}  // namespace os

}  // namespace android
