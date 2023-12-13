#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/IMediaMetricsService.h>

namespace android {

namespace media {

class BpMediaMetricsService : public ::android::BpInterface<IMediaMetricsService> {
public:
  explicit BpMediaMetricsService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpMediaMetricsService() = default;
  ::android::binder::Status submitBuffer(const ::std::vector<uint8_t>& buffer) override;
};  // class BpMediaMetricsService

}  // namespace media

}  // namespace android
