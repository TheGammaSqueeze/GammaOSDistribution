#pragma once

#include <android/hardware/gnss/BlocklistedSource.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

namespace gnss {

class IGnssConfiguration : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(GnssConfiguration)
  const int32_t VERSION = 1;
  const std::string HASH = "10839720b90aaec329521e810d9e0501cfcef0d3";
  enum  : int32_t {
    SUPL_MODE_MSB = 1,
    SUPL_MODE_MSA = 2,
    LPP_PROFILE_USER_PLANE = 1,
    LPP_PROFILE_CONTROL_PLANE = 2,
    GLONASS_POS_PROTOCOL_RRC_CPLANE = 1,
    GLONASS_POS_PROTOCOL_RRLP_UPLANE = 2,
    GLONASS_POS_PROTOCOL_LPP_UPLANE = 4,
  };
  virtual ::android::binder::Status setSuplVersion(int32_t version) = 0;
  virtual ::android::binder::Status setSuplMode(int32_t mode) = 0;
  virtual ::android::binder::Status setLppProfile(int32_t lppProfile) = 0;
  virtual ::android::binder::Status setGlonassPositioningProtocol(int32_t protocol) = 0;
  virtual ::android::binder::Status setEmergencySuplPdn(bool enable) = 0;
  virtual ::android::binder::Status setEsExtensionSec(int32_t emergencyExtensionSeconds) = 0;
  virtual ::android::binder::Status setBlocklist(const ::std::vector<::android::hardware::gnss::BlocklistedSource>& blocklist) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IGnssConfiguration

class IGnssConfigurationDefault : public IGnssConfiguration {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status setSuplVersion(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setSuplMode(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setLppProfile(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setGlonassPositioningProtocol(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setEmergencySuplPdn(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setEsExtensionSec(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setBlocklist(const ::std::vector<::android::hardware::gnss::BlocklistedSource>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IGnssConfigurationDefault

}  // namespace gnss

}  // namespace hardware

}  // namespace android
