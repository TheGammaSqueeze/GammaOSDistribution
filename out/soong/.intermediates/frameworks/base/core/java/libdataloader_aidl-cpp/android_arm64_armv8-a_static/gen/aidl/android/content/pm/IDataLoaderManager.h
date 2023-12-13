#pragma once

#include <android/content/pm/DataLoaderParamsParcel.h>
#include <android/content/pm/IDataLoader.h>
#include <android/content/pm/IDataLoaderStatusListener.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace content {

namespace pm {

class IDataLoaderManager : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(DataLoaderManager)
  virtual ::android::binder::Status bindToDataLoader(int32_t id, const ::android::content::pm::DataLoaderParamsParcel& params, int64_t bindDelayMs, const ::android::sp<::android::content::pm::IDataLoaderStatusListener>& listener, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getDataLoader(int32_t dataLoaderId, ::android::sp<::android::content::pm::IDataLoader>* _aidl_return) = 0;
  virtual ::android::binder::Status unbindFromDataLoader(int32_t dataLoaderId) = 0;
};  // class IDataLoaderManager

class IDataLoaderManagerDefault : public IDataLoaderManager {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status bindToDataLoader(int32_t, const ::android::content::pm::DataLoaderParamsParcel&, int64_t, const ::android::sp<::android::content::pm::IDataLoaderStatusListener>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getDataLoader(int32_t, ::android::sp<::android::content::pm::IDataLoader>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unbindFromDataLoader(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IDataLoaderManagerDefault

}  // namespace pm

}  // namespace content

}  // namespace android
