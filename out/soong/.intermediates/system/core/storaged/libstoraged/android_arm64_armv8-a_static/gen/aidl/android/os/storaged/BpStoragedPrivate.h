#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/storaged/IStoragedPrivate.h>

namespace android {

namespace os {

namespace storaged {

class BpStoragedPrivate : public ::android::BpInterface<IStoragedPrivate> {
public:
  explicit BpStoragedPrivate(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpStoragedPrivate() = default;
  ::android::binder::Status dumpUids(::std::vector<::android::os::storaged::UidInfo>* _aidl_return) override;
  ::android::binder::Status dumpPerfHistory(::std::vector<int32_t>* _aidl_return) override;
};  // class BpStoragedPrivate

}  // namespace storaged

}  // namespace os

}  // namespace android
