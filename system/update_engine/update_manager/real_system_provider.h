//
// Copyright (C) 2014 The Android Open Source Project
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

#ifndef UPDATE_ENGINE_UPDATE_MANAGER_REAL_SYSTEM_PROVIDER_H_
#define UPDATE_ENGINE_UPDATE_MANAGER_REAL_SYSTEM_PROVIDER_H_

#include <memory>
#include <string>

#include <base/version.h>

#include "update_engine/update_manager/system_provider.h"

namespace org {
namespace chromium {
class KioskAppServiceInterfaceProxyInterface;
}  // namespace chromium
}  // namespace org

namespace chromeos_update_manager {

// SystemProvider concrete implementation.
class RealSystemProvider : public SystemProvider {
 public:
  RealSystemProvider(
      org::chromium::KioskAppServiceInterfaceProxyInterface* kiosk_app_proxy)
      : kiosk_app_proxy_(kiosk_app_proxy) {}

  // Initializes the provider and returns whether it succeeded.
  bool Init();

  Variable<bool>* var_is_normal_boot_mode() override {
    return var_is_normal_boot_mode_.get();
  }

  Variable<bool>* var_is_official_build() override {
    return var_is_official_build_.get();
  }

  Variable<bool>* var_is_oobe_complete() override {
    return var_is_oobe_complete_.get();
  }

  Variable<unsigned int>* var_num_slots() override {
    return var_num_slots_.get();
  }

  Variable<std::string>* var_kiosk_required_platform_version() override {
    return var_kiosk_required_platform_version_.get();
  }

  Variable<base::Version>* var_chromeos_version() override {
    return var_chromeos_version_.get();
  }

 private:
  bool GetKioskAppRequiredPlatformVersion(
      std::string* required_platform_version);

  std::unique_ptr<Variable<bool>> var_is_normal_boot_mode_;
  std::unique_ptr<Variable<bool>> var_is_official_build_;
  std::unique_ptr<Variable<bool>> var_is_oobe_complete_;
  std::unique_ptr<Variable<unsigned int>> var_num_slots_;
  std::unique_ptr<Variable<std::string>> var_kiosk_required_platform_version_;
  std::unique_ptr<Variable<base::Version>> var_chromeos_version_;

  org::chromium::KioskAppServiceInterfaceProxyInterface* const kiosk_app_proxy_;

  DISALLOW_COPY_AND_ASSIGN(RealSystemProvider);
};

}  // namespace chromeos_update_manager

#endif  // UPDATE_ENGINE_UPDATE_MANAGER_REAL_SYSTEM_PROVIDER_H_
