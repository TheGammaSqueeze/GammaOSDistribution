#pragma once

#include <binder/IInterface.h>
#include <android/media/midi/IMidiDeviceServer.h>

namespace android {

namespace media {

namespace midi {

class BnMidiDeviceServer : public ::android::BnInterface<IMidiDeviceServer> {
public:
  static constexpr uint32_t TRANSACTION_openInputPort = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_openOutputPort = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_closePort = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_closeDevice = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_connectPorts = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_getDeviceInfo = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_setDeviceInfo = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  explicit BnMidiDeviceServer();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnMidiDeviceServer

}  // namespace midi

}  // namespace media

}  // namespace android
