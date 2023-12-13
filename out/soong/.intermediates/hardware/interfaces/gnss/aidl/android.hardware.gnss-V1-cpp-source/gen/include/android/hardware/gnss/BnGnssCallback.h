#pragma once

#include <binder/IInterface.h>
#include <android/hardware/gnss/IGnssCallback.h>

namespace android {

namespace hardware {

namespace gnss {

class BnGnssCallback : public ::android::BnInterface<IGnssCallback> {
public:
  static constexpr uint32_t TRANSACTION_gnssSetCapabilitiesCb = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getInterfaceVersion = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777214;
  static constexpr uint32_t TRANSACTION_getInterfaceHash = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777213;
  explicit BnGnssCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
  int32_t getInterfaceVersion() final;
  std::string getInterfaceHash();
};  // class BnGnssCallback

}  // namespace gnss

}  // namespace hardware

}  // namespace android
