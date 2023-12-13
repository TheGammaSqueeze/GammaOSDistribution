#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <keystore/KeyAttestationApplicationId.h>
#include <utils/StrongPointer.h>

namespace android {

namespace security {

namespace keymaster {

class IKeyAttestationApplicationIdProvider : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(KeyAttestationApplicationIdProvider)
  virtual ::android::binder::Status getKeyAttestationApplicationId(int32_t uid, ::android::security::keymaster::KeyAttestationApplicationId* _aidl_return) = 0;
};  // class IKeyAttestationApplicationIdProvider

class IKeyAttestationApplicationIdProviderDefault : public IKeyAttestationApplicationIdProvider {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getKeyAttestationApplicationId(int32_t, ::android::security::keymaster::KeyAttestationApplicationId*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IKeyAttestationApplicationIdProviderDefault

}  // namespace keymaster

}  // namespace security

}  // namespace android
