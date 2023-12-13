#pragma once

#include <android/media/SpatializationLevel.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace media {

class INativeSpatializerCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(NativeSpatializerCallback)
  virtual ::android::binder::Status onLevelChanged(::android::media::SpatializationLevel level) = 0;
  virtual ::android::binder::Status onOutputChanged(int32_t output) = 0;
};  // class INativeSpatializerCallback

class INativeSpatializerCallbackDefault : public INativeSpatializerCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onLevelChanged(::android::media::SpatializationLevel) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onOutputChanged(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class INativeSpatializerCallbackDefault

}  // namespace media

}  // namespace android
