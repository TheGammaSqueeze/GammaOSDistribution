#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

namespace incremental {

class IStorageHealthListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(StorageHealthListener)
  enum  : int32_t {
    HEALTH_STATUS_OK = 0,
    HEALTH_STATUS_READS_PENDING = 1,
    HEALTH_STATUS_BLOCKED = 2,
    HEALTH_STATUS_UNHEALTHY = 3,
  };
  virtual ::android::binder::Status onHealthStatus(int32_t storageId, int32_t status) = 0;
};  // class IStorageHealthListener

class IStorageHealthListenerDefault : public IStorageHealthListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onHealthStatus(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IStorageHealthListenerDefault

}  // namespace incremental

}  // namespace os

}  // namespace android
