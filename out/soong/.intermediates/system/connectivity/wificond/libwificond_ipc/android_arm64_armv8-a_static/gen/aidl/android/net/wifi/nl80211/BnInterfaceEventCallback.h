#pragma once

#include <binder/IInterface.h>
#include <android/net/wifi/nl80211/IInterfaceEventCallback.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BnInterfaceEventCallback : public ::android::BnInterface<IInterfaceEventCallback> {
public:
  static constexpr uint32_t TRANSACTION_OnClientInterfaceReady = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_OnApInterfaceReady = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_OnClientTorndownEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_OnApTorndownEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  explicit BnInterfaceEventCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnInterfaceEventCallback

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
