#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <aaudio/IAAudioClient.h>

namespace aaudio {

class BpAAudioClient : public ::android::BpInterface<IAAudioClient> {
public:
  explicit BpAAudioClient(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpAAudioClient() = default;
  ::android::binder::Status onStreamChange(int32_t handle, int32_t opcode, int32_t value) override;
};  // class BpAAudioClient

}  // namespace aaudio
