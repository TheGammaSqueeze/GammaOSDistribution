#pragma once

#include <binder/IInterface.h>
#include <android/os/IThermalService.h>

namespace android {

namespace os {

class BnThermalService : public ::android::BnInterface<IThermalService> {
public:
  static constexpr uint32_t TRANSACTION_registerThermalEventListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_registerThermalEventListenerWithType = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_unregisterThermalEventListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getCurrentTemperatures = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getCurrentTemperaturesWithType = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_registerThermalStatusListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_unregisterThermalStatusListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_getCurrentThermalStatus = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_getCurrentCoolingDevices = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_getCurrentCoolingDevicesWithType = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_getThermalHeadroom = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  explicit BnThermalService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnThermalService

}  // namespace os

}  // namespace android
