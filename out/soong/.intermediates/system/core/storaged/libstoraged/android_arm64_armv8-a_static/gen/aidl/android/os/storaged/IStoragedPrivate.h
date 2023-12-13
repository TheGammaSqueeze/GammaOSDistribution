#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <include/uid_info.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace os {

namespace storaged {

class IStoragedPrivate : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(StoragedPrivate)
  virtual ::android::binder::Status dumpUids(::std::vector<::android::os::storaged::UidInfo>* _aidl_return) = 0;
  virtual ::android::binder::Status dumpPerfHistory(::std::vector<int32_t>* _aidl_return) = 0;
};  // class IStoragedPrivate

class IStoragedPrivateDefault : public IStoragedPrivate {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status dumpUids(::std::vector<::android::os::storaged::UidInfo>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status dumpPerfHistory(::std::vector<int32_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IStoragedPrivateDefault

}  // namespace storaged

}  // namespace os

}  // namespace android
