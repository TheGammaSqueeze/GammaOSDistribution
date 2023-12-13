#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/midi/IMidiDeviceServer.h>

namespace android {

namespace media {

namespace midi {

class BpMidiDeviceServer : public ::android::BpInterface<IMidiDeviceServer> {
public:
  explicit BpMidiDeviceServer(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpMidiDeviceServer() = default;
  ::android::binder::Status openInputPort(const ::android::sp<::android::IBinder>& token, int32_t portNumber, ::android::base::unique_fd* _aidl_return) override;
  ::android::binder::Status openOutputPort(const ::android::sp<::android::IBinder>& token, int32_t portNumber, ::android::base::unique_fd* _aidl_return) override;
  ::android::binder::Status closePort(const ::android::sp<::android::IBinder>& token) override;
  ::android::binder::Status closeDevice() override;
  ::android::binder::Status connectPorts(const ::android::sp<::android::IBinder>& token, ::android::base::unique_fd fd, int32_t outputPortNumber, int32_t* _aidl_return) override;
  ::android::binder::Status getDeviceInfo(::android::media::midi::MidiDeviceInfo* _aidl_return) override;
  ::android::binder::Status setDeviceInfo(const ::android::media::midi::MidiDeviceInfo& deviceInfo) override;
};  // class BpMidiDeviceServer

}  // namespace midi

}  // namespace media

}  // namespace android
