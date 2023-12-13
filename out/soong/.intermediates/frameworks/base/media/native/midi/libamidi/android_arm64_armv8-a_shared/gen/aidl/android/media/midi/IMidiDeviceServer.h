#pragma once

#include <MidiDeviceInfo.h>
#include <android-base/unique_fd.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace media {

namespace midi {

class IMidiDeviceServer : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(MidiDeviceServer)
  virtual ::android::binder::Status openInputPort(const ::android::sp<::android::IBinder>& token, int32_t portNumber, ::android::base::unique_fd* _aidl_return) = 0;
  virtual ::android::binder::Status openOutputPort(const ::android::sp<::android::IBinder>& token, int32_t portNumber, ::android::base::unique_fd* _aidl_return) = 0;
  virtual ::android::binder::Status closePort(const ::android::sp<::android::IBinder>& token) = 0;
  virtual ::android::binder::Status closeDevice() = 0;
  virtual ::android::binder::Status connectPorts(const ::android::sp<::android::IBinder>& token, ::android::base::unique_fd fd, int32_t outputPortNumber, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getDeviceInfo(::android::media::midi::MidiDeviceInfo* _aidl_return) = 0;
  virtual ::android::binder::Status setDeviceInfo(const ::android::media::midi::MidiDeviceInfo& deviceInfo) = 0;
};  // class IMidiDeviceServer

class IMidiDeviceServerDefault : public IMidiDeviceServer {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status openInputPort(const ::android::sp<::android::IBinder>&, int32_t, ::android::base::unique_fd*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status openOutputPort(const ::android::sp<::android::IBinder>&, int32_t, ::android::base::unique_fd*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status closePort(const ::android::sp<::android::IBinder>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status closeDevice() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status connectPorts(const ::android::sp<::android::IBinder>&, ::android::base::unique_fd, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getDeviceInfo(::android::media::midi::MidiDeviceInfo*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setDeviceInfo(const ::android::media::midi::MidiDeviceInfo&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IMidiDeviceServerDefault

}  // namespace midi

}  // namespace media

}  // namespace android
