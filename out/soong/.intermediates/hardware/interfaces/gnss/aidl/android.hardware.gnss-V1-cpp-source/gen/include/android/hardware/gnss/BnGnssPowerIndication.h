#pragma once

#include <binder/IInterface.h>
#include <android/hardware/gnss/IGnssPowerIndication.h>

namespace android {

namespace hardware {

namespace gnss {

class BnGnssPowerIndication : public ::android::BnInterface<IGnssPowerIndication> {
public:
  static constexpr uint32_t TRANSACTION_setCallback = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_requestGnssPowerStats = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getInterfaceVersion = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777214;
  static constexpr uint32_t TRANSACTION_getInterfaceHash = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777213;
  explicit BnGnssPowerIndication();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
  int32_t getInterfaceVersion() final;
  std::string getInterfaceHash();
};  // class BnGnssPowerIndication

}  // namespace gnss

}  // namespace hardware

}  // namespace android
