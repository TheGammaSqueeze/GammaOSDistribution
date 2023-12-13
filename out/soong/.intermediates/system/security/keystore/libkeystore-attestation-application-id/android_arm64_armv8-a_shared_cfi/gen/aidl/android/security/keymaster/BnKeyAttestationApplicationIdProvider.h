#pragma once

#include <binder/IInterface.h>
#include <android/security/keymaster/IKeyAttestationApplicationIdProvider.h>

namespace android {

namespace security {

namespace keymaster {

class BnKeyAttestationApplicationIdProvider : public ::android::BnInterface<IKeyAttestationApplicationIdProvider> {
public:
  static constexpr uint32_t TRANSACTION_getKeyAttestationApplicationId = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnKeyAttestationApplicationIdProvider();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnKeyAttestationApplicationIdProvider

}  // namespace keymaster

}  // namespace security

}  // namespace android
