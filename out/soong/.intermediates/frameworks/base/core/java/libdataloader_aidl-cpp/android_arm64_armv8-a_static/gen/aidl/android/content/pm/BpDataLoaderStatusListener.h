#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/content/pm/IDataLoaderStatusListener.h>

namespace android {

namespace content {

namespace pm {

class BpDataLoaderStatusListener : public ::android::BpInterface<IDataLoaderStatusListener> {
public:
  explicit BpDataLoaderStatusListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpDataLoaderStatusListener() = default;
  ::android::binder::Status onStatusChanged(int32_t dataLoaderId, int32_t status) override;
};  // class BpDataLoaderStatusListener

}  // namespace pm

}  // namespace content

}  // namespace android
