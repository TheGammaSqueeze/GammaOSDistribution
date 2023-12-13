#pragma once

#include <binder/IInterface.h>
#include <android/net/wifi/nl80211/IApInterface.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BnApInterface : public ::android::BnInterface<IApInterface> {
public:
  static constexpr uint32_t TRANSACTION_registerCallback = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getInterfaceName = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnApInterface();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnApInterface

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
