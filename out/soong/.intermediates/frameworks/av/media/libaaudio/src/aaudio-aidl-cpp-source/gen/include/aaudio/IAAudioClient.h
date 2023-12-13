#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace aaudio {

class IAAudioClient : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(AAudioClient)
  virtual ::android::binder::Status onStreamChange(int32_t handle, int32_t opcode, int32_t value) = 0;
};  // class IAAudioClient

class IAAudioClientDefault : public IAAudioClient {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onStreamChange(int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IAAudioClientDefault

}  // namespace aaudio
