#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <string>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace lpdump {

class ILpdump : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Lpdump)
  virtual ::android::binder::Status run(const ::std::vector<::std::string>& args, ::std::string* _aidl_return) = 0;
};  // class ILpdump

class ILpdumpDefault : public ILpdump {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status run(const ::std::vector<::std::string>&, ::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ILpdumpDefault

}  // namespace lpdump

}  // namespace android
