#pragma once

#include <android/media/AudioIoConfigEvent.h>
#include <android/media/AudioIoDescriptor.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace media {

class IAudioFlingerClient : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(AudioFlingerClient)
  virtual ::android::binder::Status ioConfigChanged(::android::media::AudioIoConfigEvent event, const ::android::media::AudioIoDescriptor& ioDesc) = 0;
};  // class IAudioFlingerClient

class IAudioFlingerClientDefault : public IAudioFlingerClient {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status ioConfigChanged(::android::media::AudioIoConfigEvent, const ::android::media::AudioIoDescriptor&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IAudioFlingerClientDefault

}  // namespace media

}  // namespace android
