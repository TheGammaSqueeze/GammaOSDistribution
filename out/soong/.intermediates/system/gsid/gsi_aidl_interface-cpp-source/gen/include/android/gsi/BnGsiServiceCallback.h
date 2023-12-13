#pragma once

#include <binder/IInterface.h>
#include <android/gsi/IGsiServiceCallback.h>

namespace android {

namespace gsi {

class BnGsiServiceCallback : public ::android::BnInterface<IGsiServiceCallback> {
public:
  static constexpr uint32_t TRANSACTION_onResult = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnGsiServiceCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnGsiServiceCallback

}  // namespace gsi

}  // namespace android
