#pragma once

#include <binder/IInterface.h>
#include <com/google/android/startop/iorap/ITaskListener.h>

namespace com {

namespace google {

namespace android {

namespace startop {

namespace iorap {

class BnTaskListener : public ::android::BnInterface<ITaskListener> {
public:
  static constexpr uint32_t TRANSACTION_onProgress = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onComplete = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnTaskListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnTaskListener

}  // namespace iorap

}  // namespace startop

}  // namespace android

}  // namespace google

}  // namespace com
