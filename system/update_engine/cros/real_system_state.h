//
// Copyright (C) 2013 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef UPDATE_ENGINE_CROS_REAL_SYSTEM_STATE_H_
#define UPDATE_ENGINE_CROS_REAL_SYSTEM_STATE_H_

#include "update_engine/common/system_state.h"

#include <memory>
#include <set>

#include <policy/device_policy.h>
#include <kiosk-app/dbus-proxies.h>

#include "update_engine/certificate_checker.h"
#include "update_engine/common/boot_control_interface.h"
#include "update_engine/common/clock.h"
#include "update_engine/common/daemon_state_interface.h"
#include "update_engine/common/dlcservice_interface.h"
#include "update_engine/common/hardware_interface.h"
#include "update_engine/common/metrics_reporter_interface.h"
#include "update_engine/common/prefs.h"
#include "update_engine/cros/connection_manager_interface.h"
#include "update_engine/cros/metrics_reporter_omaha.h"
#include "update_engine/cros/p2p_manager.h"
#include "update_engine/cros/payload_state.h"
#include "update_engine/cros/power_manager_interface.h"
#include "update_engine/cros/update_attempter.h"
#include "update_engine/update_manager/update_manager.h"

namespace chromeos_update_engine {

// A real implementation of the SystemStateInterface which is
// used by the actual product code.
class RealSystemState : public SystemState {
 public:
  // Constructs all system objects that do not require separate initialization;
  // see Initialize() below for the remaining ones.
  RealSystemState() = default;
  ~RealSystemState() = default;

  static void SetInstance(RealSystemState* system_state) {
    CHECK(g_pointer_ == nullptr) << "SystemState has been previously set.";
    g_pointer_ = system_state;
    LOG_IF(FATAL, !system_state->Initialize())
        << "Failed to initialize system state.";
  }

  // SystemState overrides.
  void set_device_policy(const policy::DevicePolicy* device_policy) override {
    device_policy_ = device_policy;
  }

  const policy::DevicePolicy* device_policy() override {
    return device_policy_;
  }

  BootControlInterface* boot_control() override { return boot_control_.get(); }

  ClockInterface* clock() override { return &clock_; }

  ConnectionManagerInterface* connection_manager() override {
    return connection_manager_.get();
  }

  HardwareInterface* hardware() override { return hardware_.get(); }

  MetricsReporterInterface* metrics_reporter() override {
    return &metrics_reporter_;
  }

  PrefsInterface* prefs() override { return prefs_.get(); }

  PrefsInterface* powerwash_safe_prefs() override {
    return powerwash_safe_prefs_.get();
  }

  PayloadStateInterface* payload_state() override { return &payload_state_; }

  UpdateAttempter* update_attempter() override {
    return update_attempter_.get();
  }

  OmahaRequestParams* request_params() override { return &request_params_; }

  P2PManager* p2p_manager() override { return p2p_manager_.get(); }

  chromeos_update_manager::UpdateManager* update_manager() override {
    return update_manager_.get();
  }

  PowerManagerInterface* power_manager() override {
    return power_manager_.get();
  }

  bool system_rebooted() override { return system_rebooted_; }

  DlcServiceInterface* dlcservice() override { return dlcservice_.get(); }

 private:
  // Initializes and sets systems objects that require an initialization
  // separately from construction. Returns |true| on success.
  bool Initialize();

  // Real DBus proxies using the DBus connection.
  std::unique_ptr<org::chromium::KioskAppServiceInterfaceProxy>
      kiosk_app_proxy_;

  // Interface for the power manager.
  std::unique_ptr<PowerManagerInterface> power_manager_;

  // Interface for dlcservice.
  std::unique_ptr<DlcServiceInterface> dlcservice_;

  // Interface for the bootloader control.
  std::unique_ptr<BootControlInterface> boot_control_;

  // Interface for the clock.
  Clock clock_;

  // The latest device policy object from the policy provider.
  const policy::DevicePolicy* device_policy_{nullptr};

  // The connection manager object that makes download decisions depending on
  // the current type of connection.
  std::unique_ptr<ConnectionManagerInterface> connection_manager_;

  // Interface for the hardware functions.
  std::unique_ptr<HardwareInterface> hardware_;

  // The Metrics reporter for reporting UMA stats.
  MetricsReporterOmaha metrics_reporter_;

  // Interface for persisted store.
  std::unique_ptr<PrefsInterface> prefs_;

  // Interface for persisted store that persists across powerwashes.
  std::unique_ptr<PrefsInterface> powerwash_safe_prefs_;

  // All state pertaining to payload state such as response, URL, backoff
  // states.
  PayloadState payload_state_;

  // OpenSSLWrapper and CertificateChecker used for checking SSL certificates.
  OpenSSLWrapper openssl_wrapper_;
  std::unique_ptr<CertificateChecker> certificate_checker_;

  // Pointer to the update attempter object.
  std::unique_ptr<UpdateAttempter> update_attempter_;

  // Common parameters for all Omaha requests.
  OmahaRequestParams request_params_;

  std::unique_ptr<P2PManager> p2p_manager_;

  std::unique_ptr<chromeos_update_manager::UpdateManager> update_manager_;

  policy::PolicyProvider policy_provider_;

  // If true, this is the first instance of the update engine since the system
  // rebooted. Important for tracking whether you are running instance of the
  // update engine on first boot or due to a crash/restart.
  bool system_rebooted_{false};
};

}  // namespace chromeos_update_engine

#endif  // UPDATE_ENGINE_CROS_REAL_SYSTEM_STATE_H_
