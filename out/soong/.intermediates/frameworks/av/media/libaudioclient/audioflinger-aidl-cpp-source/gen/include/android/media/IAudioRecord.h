#pragma once

#include <android/media/MicrophoneInfoData.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace media {

class IAudioRecord : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(AudioRecord)
  virtual ::android::binder::Status start(int32_t event, int32_t triggerSession) = 0;
  virtual ::android::binder::Status stop() = 0;
  virtual ::android::binder::Status getActiveMicrophones(::std::vector<::android::media::MicrophoneInfoData>* activeMicrophones) = 0;
  virtual ::android::binder::Status setPreferredMicrophoneDirection(int32_t direction) = 0;
  virtual ::android::binder::Status setPreferredMicrophoneFieldDimension(float zoom) = 0;
  virtual ::android::binder::Status shareAudioHistory(const ::std::string& sharedAudioPackageName, int64_t sharedAudioStartMs) = 0;
};  // class IAudioRecord

class IAudioRecordDefault : public IAudioRecord {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status start(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stop() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getActiveMicrophones(::std::vector<::android::media::MicrophoneInfoData>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPreferredMicrophoneDirection(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPreferredMicrophoneFieldDimension(float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status shareAudioHistory(const ::std::string&, int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IAudioRecordDefault

}  // namespace media

}  // namespace android
