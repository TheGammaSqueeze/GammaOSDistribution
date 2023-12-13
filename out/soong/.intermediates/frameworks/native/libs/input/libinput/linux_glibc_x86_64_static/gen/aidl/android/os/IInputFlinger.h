#pragma once

#include <android/gui/FocusRequest.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <input/InputTransport.h>
#include <string>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IInputFlinger : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(InputFlinger)
  virtual ::android::binder::Status createInputChannel(const ::std::string& name, ::android::InputChannel* _aidl_return) = 0;
  virtual ::android::binder::Status removeInputChannel(const ::android::sp<::android::IBinder>& connectionToken) = 0;
  virtual ::android::binder::Status setFocusedWindow(const ::android::gui::FocusRequest& request) = 0;
};  // class IInputFlinger

class IInputFlingerDefault : public IInputFlinger {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status createInputChannel(const ::std::string&, ::android::InputChannel*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeInputChannel(const ::android::sp<::android::IBinder>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setFocusedWindow(const ::android::gui::FocusRequest&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IInputFlingerDefault

}  // namespace os

}  // namespace android
