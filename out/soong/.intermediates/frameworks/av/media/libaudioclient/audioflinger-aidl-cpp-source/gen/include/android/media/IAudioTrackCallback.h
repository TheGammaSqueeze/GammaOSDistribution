#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace media {

class IAudioTrackCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(AudioTrackCallback)
  virtual ::android::binder::Status onCodecFormatChanged(const ::std::vector<uint8_t>& audioMetadata) = 0;
};  // class IAudioTrackCallback

class IAudioTrackCallbackDefault : public IAudioTrackCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onCodecFormatChanged(const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IAudioTrackCallbackDefault

}  // namespace media

}  // namespace android
