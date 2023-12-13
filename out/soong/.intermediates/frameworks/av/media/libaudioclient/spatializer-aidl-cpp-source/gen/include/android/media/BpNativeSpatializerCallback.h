#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/INativeSpatializerCallback.h>

namespace android {

namespace media {

class BpNativeSpatializerCallback : public ::android::BpInterface<INativeSpatializerCallback> {
public:
  explicit BpNativeSpatializerCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpNativeSpatializerCallback() = default;
  ::android::binder::Status onLevelChanged(::android::media::SpatializationLevel level) override;
  ::android::binder::Status onOutputChanged(int32_t output) override;
};  // class BpNativeSpatializerCallback

}  // namespace media

}  // namespace android
