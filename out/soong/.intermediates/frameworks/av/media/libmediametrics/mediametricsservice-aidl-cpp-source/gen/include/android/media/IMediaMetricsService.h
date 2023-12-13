#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace media {

class IMediaMetricsService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(MediaMetricsService)
  virtual ::android::binder::Status submitBuffer(const ::std::vector<uint8_t>& buffer) = 0;
};  // class IMediaMetricsService

class IMediaMetricsServiceDefault : public IMediaMetricsService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status submitBuffer(const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IMediaMetricsServiceDefault

}  // namespace media

}  // namespace android
