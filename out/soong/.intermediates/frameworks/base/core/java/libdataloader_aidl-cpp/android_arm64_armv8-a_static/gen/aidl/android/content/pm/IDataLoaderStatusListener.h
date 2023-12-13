#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace content {

namespace pm {

class IDataLoaderStatusListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(DataLoaderStatusListener)
  enum  : int32_t {
    DATA_LOADER_DESTROYED = 0,
    DATA_LOADER_BINDING = 1,
    DATA_LOADER_BOUND = 2,
    DATA_LOADER_CREATED = 3,
    DATA_LOADER_STARTED = 4,
    DATA_LOADER_STOPPED = 5,
    DATA_LOADER_IMAGE_READY = 6,
    DATA_LOADER_IMAGE_NOT_READY = 7,
    DATA_LOADER_UNAVAILABLE = 8,
    DATA_LOADER_UNRECOVERABLE = 9,
  };
  virtual ::android::binder::Status onStatusChanged(int32_t dataLoaderId, int32_t status) = 0;
};  // class IDataLoaderStatusListener

class IDataLoaderStatusListenerDefault : public IDataLoaderStatusListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onStatusChanged(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IDataLoaderStatusListenerDefault

}  // namespace pm

}  // namespace content

}  // namespace android
