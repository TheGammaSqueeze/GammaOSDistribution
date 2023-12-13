#pragma once

#include <binder/IInterface.h>
#include <android/net/wifi/nl80211/IWificondEventCallback.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BnWificondEventCallback : public ::android::BnInterface<IWificondEventCallback> {
public:
  static constexpr uint32_t TRANSACTION_OnRegDomainChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnWificondEventCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnWificondEventCallback

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
