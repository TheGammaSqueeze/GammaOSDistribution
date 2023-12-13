#pragma once

#include <binder/IInterface.h>
#include <android/IMediaExtractorService.h>

namespace android {

class BnMediaExtractorService : public ::android::BnInterface<IMediaExtractorService> {
public:
  static constexpr uint32_t TRANSACTION_makeExtractor = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_makeIDataSource = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getSupportedTypes = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  explicit BnMediaExtractorService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnMediaExtractorService

}  // namespace android
