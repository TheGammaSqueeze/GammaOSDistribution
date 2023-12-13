#pragma once

#include <binder/IInterface.h>
#include <android/media/IMediaMetricsService.h>

namespace android {

namespace media {

class BnMediaMetricsService : public ::android::BnInterface<IMediaMetricsService> {
public:
  static constexpr uint32_t TRANSACTION_submitBuffer = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnMediaMetricsService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnMediaMetricsService

}  // namespace media

}  // namespace android
