#pragma once

#include <android/hardware/gnss/IGnssCallback.h>
#include <android/hardware/gnss/IGnssConfiguration.h>
#include <android/hardware/gnss/IGnssMeasurementInterface.h>
#include <android/hardware/gnss/IGnssPowerIndication.h>
#include <android/hardware/gnss/IGnssPsds.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace gnss {

class IGnss : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Gnss)
  const int32_t VERSION = 1;
  const std::string HASH = "10839720b90aaec329521e810d9e0501cfcef0d3";
  enum  : int32_t {
    ERROR_INVALID_ARGUMENT = 1,
    ERROR_ALREADY_INIT = 2,
    ERROR_GENERIC = 3,
  };
  virtual ::android::binder::Status setCallback(const ::android::sp<::android::hardware::gnss::IGnssCallback>& callback) = 0;
  virtual ::android::binder::Status close() = 0;
  virtual ::android::binder::Status getExtensionPsds(::android::sp<::android::hardware::gnss::IGnssPsds>* _aidl_return) = 0;
  virtual ::android::binder::Status getExtensionGnssConfiguration(::android::sp<::android::hardware::gnss::IGnssConfiguration>* _aidl_return) = 0;
  virtual ::android::binder::Status getExtensionGnssMeasurement(::android::sp<::android::hardware::gnss::IGnssMeasurementInterface>* _aidl_return) = 0;
  virtual ::android::binder::Status getExtensionGnssPowerIndication(::android::sp<::android::hardware::gnss::IGnssPowerIndication>* _aidl_return) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IGnss

class IGnssDefault : public IGnss {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status setCallback(const ::android::sp<::android::hardware::gnss::IGnssCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status close() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getExtensionPsds(::android::sp<::android::hardware::gnss::IGnssPsds>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getExtensionGnssConfiguration(::android::sp<::android::hardware::gnss::IGnssConfiguration>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getExtensionGnssMeasurement(::android::sp<::android::hardware::gnss::IGnssMeasurementInterface>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getExtensionGnssPowerIndication(::android::sp<::android::hardware::gnss::IGnssPowerIndication>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IGnssDefault

}  // namespace gnss

}  // namespace hardware

}  // namespace android
