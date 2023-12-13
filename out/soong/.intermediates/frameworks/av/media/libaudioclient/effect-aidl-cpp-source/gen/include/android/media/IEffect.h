#pragma once

#include <android/media/SharedFileRegion.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace media {

class IEffect : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Effect)
  virtual ::android::binder::Status enable(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status disable(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status command(int32_t cmdCode, const ::std::vector<uint8_t>& cmdData, int32_t maxResponseSize, ::std::vector<uint8_t>* response, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status disconnect() = 0;
  virtual ::android::binder::Status getCblk(::android::media::SharedFileRegion* _aidl_return) = 0;
};  // class IEffect

class IEffectDefault : public IEffect {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status enable(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status disable(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status command(int32_t, const ::std::vector<uint8_t>&, int32_t, ::std::vector<uint8_t>*, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status disconnect() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCblk(::android::media::SharedFileRegion*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IEffectDefault

}  // namespace media

}  // namespace android
