#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/IEffect.h>

namespace android {

namespace media {

class BpEffect : public ::android::BpInterface<IEffect> {
public:
  explicit BpEffect(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpEffect() = default;
  ::android::binder::Status enable(int32_t* _aidl_return) override;
  ::android::binder::Status disable(int32_t* _aidl_return) override;
  ::android::binder::Status command(int32_t cmdCode, const ::std::vector<uint8_t>& cmdData, int32_t maxResponseSize, ::std::vector<uint8_t>* response, int32_t* _aidl_return) override;
  ::android::binder::Status disconnect() override;
  ::android::binder::Status getCblk(::android::media::SharedFileRegion* _aidl_return) override;
};  // class BpEffect

}  // namespace media

}  // namespace android
