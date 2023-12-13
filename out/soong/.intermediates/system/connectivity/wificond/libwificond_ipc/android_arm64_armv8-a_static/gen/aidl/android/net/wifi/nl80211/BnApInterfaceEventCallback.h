#pragma once

#include <binder/IInterface.h>
#include <android/net/wifi/nl80211/IApInterfaceEventCallback.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BnApInterfaceEventCallback : public ::android::BnInterface<IApInterfaceEventCallback> {
public:
  static constexpr uint32_t TRANSACTION_onConnectedClientsChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onSoftApChannelSwitched = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnApInterfaceEventCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnApInterfaceEventCallback

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
