#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/IAudioFlingerClient.h>

namespace android {

namespace media {

class BpAudioFlingerClient : public ::android::BpInterface<IAudioFlingerClient> {
public:
  explicit BpAudioFlingerClient(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpAudioFlingerClient() = default;
  ::android::binder::Status ioConfigChanged(::android::media::AudioIoConfigEvent event, const ::android::media::AudioIoDescriptor& ioDesc) override;
};  // class BpAudioFlingerClient

}  // namespace media

}  // namespace android
