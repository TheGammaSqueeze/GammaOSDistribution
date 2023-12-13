#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/power/stats/IPowerStats.h>

namespace android {

namespace hardware {

namespace power {

namespace stats {

class BpPowerStats : public ::android::BpInterface<IPowerStats> {
public:
  explicit BpPowerStats(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpPowerStats() = default;
  ::android::binder::Status getPowerEntityInfo(::std::vector<::android::hardware::power::stats::PowerEntity>* _aidl_return) override;
  ::android::binder::Status getStateResidency(const ::std::vector<int32_t>& powerEntityIds, ::std::vector<::android::hardware::power::stats::StateResidencyResult>* _aidl_return) override;
  ::android::binder::Status getEnergyConsumerInfo(::std::vector<::android::hardware::power::stats::EnergyConsumer>* _aidl_return) override;
  ::android::binder::Status getEnergyConsumed(const ::std::vector<int32_t>& energyConsumerIds, ::std::vector<::android::hardware::power::stats::EnergyConsumerResult>* _aidl_return) override;
  ::android::binder::Status getEnergyMeterInfo(::std::vector<::android::hardware::power::stats::Channel>* _aidl_return) override;
  ::android::binder::Status readEnergyMeter(const ::std::vector<int32_t>& channelIds, ::std::vector<::android::hardware::power::stats::EnergyMeasurement>* _aidl_return) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpPowerStats

}  // namespace stats

}  // namespace power

}  // namespace hardware

}  // namespace android
