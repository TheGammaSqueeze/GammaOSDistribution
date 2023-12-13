#pragma once

#include <aaudio/Endpoint.h>
#include <aaudio/IAAudioClient.h>
#include <aaudio/StreamParameters.h>
#include <aaudio/StreamRequest.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace aaudio {

class IAAudioService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(AAudioService)
  virtual ::android::binder::Status registerClient(const ::android::sp<::aaudio::IAAudioClient>& client) = 0;
  virtual ::android::binder::Status openStream(const ::aaudio::StreamRequest& request, ::aaudio::StreamParameters* paramsOut, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status closeStream(int32_t streamHandle, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getStreamDescription(int32_t streamHandle, ::aaudio::Endpoint* endpoint, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status startStream(int32_t streamHandle, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status pauseStream(int32_t streamHandle, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status stopStream(int32_t streamHandle, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status flushStream(int32_t streamHandle, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status registerAudioThread(int32_t streamHandle, int32_t clientThreadId, int64_t periodNanoseconds, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status unregisterAudioThread(int32_t streamHandle, int32_t clientThreadId, int32_t* _aidl_return) = 0;
};  // class IAAudioService

class IAAudioServiceDefault : public IAAudioService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status registerClient(const ::android::sp<::aaudio::IAAudioClient>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status openStream(const ::aaudio::StreamRequest&, ::aaudio::StreamParameters*, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status closeStream(int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getStreamDescription(int32_t, ::aaudio::Endpoint*, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status startStream(int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status pauseStream(int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stopStream(int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status flushStream(int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerAudioThread(int32_t, int32_t, int64_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unregisterAudioThread(int32_t, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IAAudioServiceDefault

}  // namespace aaudio
