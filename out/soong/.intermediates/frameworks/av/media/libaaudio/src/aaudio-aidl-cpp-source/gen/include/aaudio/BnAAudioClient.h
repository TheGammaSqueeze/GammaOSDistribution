#pragma once

#include <binder/IInterface.h>
#include <aaudio/IAAudioClient.h>

namespace aaudio {

class BnAAudioClient : public ::android::BnInterface<IAAudioClient> {
public:
  static constexpr uint32_t TRANSACTION_onStreamChange = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnAAudioClient();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnAAudioClient

}  // namespace aaudio
