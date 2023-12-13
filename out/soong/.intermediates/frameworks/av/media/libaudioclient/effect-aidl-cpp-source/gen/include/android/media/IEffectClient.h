#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace media {

class IEffectClient : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(EffectClient)
  virtual ::android::binder::Status controlStatusChanged(bool controlGranted) = 0;
  virtual ::android::binder::Status enableStatusChanged(bool enabled) = 0;
  virtual ::android::binder::Status commandExecuted(int32_t cmdCode, const ::std::vector<uint8_t>& cmdData, const ::std::vector<uint8_t>& replyData) = 0;
  virtual ::android::binder::Status framesProcessed(int32_t frames) = 0;
};  // class IEffectClient

class IEffectClientDefault : public IEffectClient {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status controlStatusChanged(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status enableStatusChanged(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status commandExecuted(int32_t, const ::std::vector<uint8_t>&, const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status framesProcessed(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IEffectClientDefault

}  // namespace media

}  // namespace android
