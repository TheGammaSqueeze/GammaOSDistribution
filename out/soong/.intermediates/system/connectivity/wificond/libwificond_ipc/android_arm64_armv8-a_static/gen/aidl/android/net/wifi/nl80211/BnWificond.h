#pragma once

#include <binder/IInterface.h>
#include <android/net/wifi/nl80211/IWificond.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BnWificond : public ::android::BnInterface<IWificond> {
public:
  static constexpr uint32_t TRANSACTION_createApInterface = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_createClientInterface = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_tearDownApInterface = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_tearDownClientInterface = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_tearDownInterfaces = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_GetClientInterfaces = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_GetApInterfaces = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_getAvailable2gChannels = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_getAvailable5gNonDFSChannels = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_getAvailableDFSChannels = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_getAvailable6gChannels = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_getAvailable60gChannels = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_RegisterCallback = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_UnregisterCallback = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_registerWificondEventCallback = ::android::IBinder::FIRST_CALL_TRANSACTION + 14;
  static constexpr uint32_t TRANSACTION_unregisterWificondEventCallback = ::android::IBinder::FIRST_CALL_TRANSACTION + 15;
  static constexpr uint32_t TRANSACTION_getDeviceWiphyCapabilities = ::android::IBinder::FIRST_CALL_TRANSACTION + 16;
  explicit BnWificond();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnWificond

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
