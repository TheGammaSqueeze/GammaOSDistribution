#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IInputFlinger.h>

namespace android {

namespace os {

class BpInputFlinger : public ::android::BpInterface<IInputFlinger> {
public:
  explicit BpInputFlinger(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpInputFlinger() = default;
  ::android::binder::Status createInputChannel(const ::std::string& name, ::android::InputChannel* _aidl_return) override;
  ::android::binder::Status removeInputChannel(const ::android::sp<::android::IBinder>& connectionToken) override;
  ::android::binder::Status setFocusedWindow(const ::android::gui::FocusRequest& request) override;
};  // class BpInputFlinger

}  // namespace os

}  // namespace android
