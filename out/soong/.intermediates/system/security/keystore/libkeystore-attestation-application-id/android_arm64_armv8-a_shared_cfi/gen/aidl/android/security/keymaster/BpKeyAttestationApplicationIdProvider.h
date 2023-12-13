#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/security/keymaster/IKeyAttestationApplicationIdProvider.h>

namespace android {

namespace security {

namespace keymaster {

class BpKeyAttestationApplicationIdProvider : public ::android::BpInterface<IKeyAttestationApplicationIdProvider> {
public:
  explicit BpKeyAttestationApplicationIdProvider(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpKeyAttestationApplicationIdProvider() = default;
  ::android::binder::Status getKeyAttestationApplicationId(int32_t uid, ::android::security::keymaster::KeyAttestationApplicationId* _aidl_return) override;
};  // class BpKeyAttestationApplicationIdProvider

}  // namespace keymaster

}  // namespace security

}  // namespace android
