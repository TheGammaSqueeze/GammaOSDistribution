#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

namespace incremental {

class IIncrementalServiceConnector : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(IncrementalServiceConnector)
  virtual ::android::binder::Status setStorageParams(bool enableReadLogs, int32_t* _aidl_return) = 0;
};  // class IIncrementalServiceConnector

class IIncrementalServiceConnectorDefault : public IIncrementalServiceConnector {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status setStorageParams(bool, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IIncrementalServiceConnectorDefault

}  // namespace incremental

}  // namespace os

}  // namespace android
