#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class ISendMgmtFrameEvent : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(SendMgmtFrameEvent)
  enum  : int32_t {
    SEND_MGMT_FRAME_ERROR_UNKNOWN = 1,
    SEND_MGMT_FRAME_ERROR_MCS_UNSUPPORTED = 2,
    SEND_MGMT_FRAME_ERROR_NO_ACK = 3,
    SEND_MGMT_FRAME_ERROR_TIMEOUT = 4,
    SEND_MGMT_FRAME_ERROR_ALREADY_STARTED = 5,
  };
  virtual ::android::binder::Status OnAck(int32_t elapsedTimeMs) = 0;
  virtual ::android::binder::Status OnFailure(int32_t reason) = 0;
};  // class ISendMgmtFrameEvent

class ISendMgmtFrameEventDefault : public ISendMgmtFrameEvent {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnAck(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnFailure(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ISendMgmtFrameEventDefault

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
