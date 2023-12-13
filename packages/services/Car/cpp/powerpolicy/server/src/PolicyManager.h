/**
 * Copyright (c) 2020, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CPP_POWERPOLICY_SERVER_SRC_POLICYMANAGER_H_
#define CPP_POWERPOLICY_SERVER_SRC_POLICYMANAGER_H_

#include <android-base/result.h>
#include <android/frameworks/automotive/powerpolicy/CarPowerPolicy.h>
#include <android/hardware/automotive/vehicle/2.0/IVehicle.h>

#include <tinyxml2.h>

#include <memory>
#include <string>
#include <unordered_map>

namespace android {
namespace frameworks {
namespace automotive {
namespace powerpolicy {

std::string toString(const CarPowerPolicy& policy);
std::string toString(const std::vector<PowerComponent>& components);
bool isSystemPowerPolicy(const std::string& policyId);

using CarPowerPolicyPtr = std::shared_ptr<CarPowerPolicy>;
using PolicyGroup = std::unordered_map<int32_t, std::string>;

constexpr const char* kSystemPolicyIdNoUserInteraction = "system_power_policy_no_user_interaction";
constexpr const char* kSystemPolicyIdAllOn = "system_power_policy_all_on";
constexpr const char* kSystemPolicyIdInitialOn = "system_power_policy_initiall_on";
constexpr const char* kSystemPolicyIdSuspendToRam = "system_power_policy_suspend_to_ram";

// Forward declaration for testing use only.
namespace internal {

class PolicyManagerPeer;

}  // namespace internal

// CarPowerPolicyMeta includes a car power policy and its meta information.
struct CarPowerPolicyMeta {
    CarPowerPolicyPtr powerPolicy = nullptr;
    bool isPreemptive = false;
};

/**
 * PolicyManager manages power policies, power policy mapping to power transision, and system power
 * policy.
 * It reads vendor policy information from /vendor/etc/power_policy.xml. If the XML file is invalid,
 * no power policy is registered and the system power policy is set to default.
 */
class PolicyManager {
public:
    void init();
    android::base::Result<CarPowerPolicyMeta> getPowerPolicy(const std::string& policyId) const;
    android::base::Result<CarPowerPolicyPtr> getDefaultPowerPolicyForState(
            const std::string& groupId,
            android::hardware::automotive::vehicle::V2_0::VehicleApPowerStateReport state) const;
    bool isPowerPolicyGroupAvailable(const std::string& groupId) const;
    bool isPreemptivePowerPolicy(const std::string& policyId) const;
    android::base::Result<void> definePowerPolicy(
            const std::string& policyId, const std::vector<std::string>& enabledComponents,
            const std::vector<std::string>& disabledComponents);
    android::base::Result<void> dump(int fd, const android::Vector<String16>& args);

private:
    void initRegularPowerPolicy();
    void initPreemptivePowerPolicy();
    void readPowerPolicyConfiguration();
    void readPowerPolicyFromXml(const tinyxml2::XMLDocument& xmlDoc);
    void reconstructNoUserInteractionPolicy(const std::vector<CarPowerPolicyPtr>& policyOverrides);

private:
    std::unordered_map<std::string, CarPowerPolicyPtr> mRegisteredPowerPolicies;
    std::unordered_map<std::string, CarPowerPolicyPtr> mPreemptivePowerPolicies;
    std::unordered_map<std::string, PolicyGroup> mPolicyGroups;

    // For unit tests.
    friend class internal::PolicyManagerPeer;
};

}  // namespace powerpolicy
}  // namespace automotive
}  // namespace frameworks
}  // namespace android

#endif  // CPP_POWERPOLICY_SERVER_SRC_POLICYMANAGER_H_
