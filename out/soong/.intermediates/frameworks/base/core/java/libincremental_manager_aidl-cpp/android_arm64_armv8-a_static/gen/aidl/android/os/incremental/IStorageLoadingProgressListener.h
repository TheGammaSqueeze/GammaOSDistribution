#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

namespace incremental {

class IStorageLoadingProgressListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(StorageLoadingProgressListener)
  virtual ::android::binder::Status onStorageLoadingProgressChanged(int32_t storageId, float progress) = 0;
};  // class IStorageLoadingProgressListener

class IStorageLoadingProgressListenerDefault : public IStorageLoadingProgressListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onStorageLoadingProgressChanged(int32_t, float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IStorageLoadingProgressListenerDefault

}  // namespace incremental

}  // namespace os

}  // namespace android
