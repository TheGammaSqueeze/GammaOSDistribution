#pragma once

#include <android/hardware/power/stats/Channel.h>
#include <android/hardware/power/stats/EnergyConsumer.h>
#include <android/hardware/power/stats/EnergyConsumerResult.h>
#include <android/hardware/power/stats/EnergyMeasurement.h>
#include <android/hardware/power/stats/PowerEntity.h>
#include <android/hardware/power/stats/StateResidencyResult.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

namespace power {

namespace stats {

class IPowerStats : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(PowerStats)
  const int32_t VERSION = 1;
  const std::string HASH = "93253458fae451cf1187db6120a59fab428f7d02";
  virtual ::android::binder::Status getPowerEntityInfo(::std::vector<::android::hardware::power::stats::PowerEntity>* _aidl_return) = 0;
  virtual ::android::binder::Status getStateResidency(const ::std::vector<int32_t>& powerEntityIds, ::std::vector<::android::hardware::power::stats::StateResidencyResult>* _aidl_return) = 0;
  virtual ::android::binder::Status getEnergyConsumerInfo(::std::vector<::android::hardware::power::stats::EnergyConsumer>* _aidl_return) = 0;
  virtual ::android::binder::Status getEnergyConsumed(const ::std::vector<int32_t>& energyConsumerIds, ::std::vector<::android::hardware::power::stats::EnergyConsumerResult>* _aidl_return) = 0;
  virtual ::android::binder::Status getEnergyMeterInfo(::std::vector<::android::hardware::power::stats::Channel>* _aidl_return) = 0;
  virtual ::android::binder::Status readEnergyMeter(const ::std::vector<int32_t>& channelIds, ::std::vector<::android::hardware::power::stats::EnergyMeasurement>* _aidl_return) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IPowerStats

class IPowerStatsDefault : public IPowerStats {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getPowerEntityInfo(::std::vector<::android::hardware::power::stats::PowerEntity>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getStateResidency(const ::std::vector<int32_t>&, ::std::vector<::android::hardware::power::stats::StateResidencyResult>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getEnergyConsumerInfo(::std::vector<::android::hardware::power::stats::EnergyConsumer>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getEnergyConsumed(const ::std::vector<int32_t>&, ::std::vector<::android::hardware::power::stats::EnergyConsumerResult>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getEnergyMeterInfo(::std::vector<::android::hardware::power::stats::Channel>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status readEnergyMeter(const ::std::vector<int32_t>&, ::std::vector<::android::hardware::power::stats::EnergyMeasurement>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IPowerStatsDefault

}  // namespace stats

}  // namespace power

}  // namespace hardware

}  // namespace android
