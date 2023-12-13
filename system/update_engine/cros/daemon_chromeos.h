//
// Copyright (C) 2015 The Android Open Source Project
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

#ifndef UPDATE_ENGINE_CROS_DAEMON_CHROMEOS_H_
#define UPDATE_ENGINE_CROS_DAEMON_CHROMEOS_H_

#include <memory>

#include "update_engine/common/daemon_base.h"
#include "update_engine/common/daemon_state_interface.h"
#include "update_engine/common/subprocess.h"
#include "update_engine/cros/dbus_service.h"
#include "update_engine/cros/real_system_state.h"

namespace chromeos_update_engine {

class DaemonChromeOS : public DaemonBase {
 public:
  DaemonChromeOS() = default;

 protected:
  int OnInit() override;

 private:
  // Run from the main loop when the |dbus_adaptor_| object is registered. At
  // this point we can request ownership of the DBus service name and continue
  // initialization.
  void OnDBusRegistered(bool succeeded);

  // |SystemState| is a global context, but we can't have a static singleton of
  // its object because the style guide does not allow that (it has non-trivial
  // dtor). We need an instance of |SystemState| in this class instead and have
  // a global pointer to it. This is better to be defined as the first variable
  // of this class so it is initialized first and destructed last.
  RealSystemState system_state_;

  // Main D-Bus service adaptor.
  std::unique_ptr<UpdateEngineAdaptor> dbus_adaptor_;

  // The Subprocess singleton class requires a brillo::MessageLoop in the
  // current thread, so we need to initialize it from this class instead of
  // the main() function.
  Subprocess subprocess_;

  DISALLOW_COPY_AND_ASSIGN(DaemonChromeOS);
};

}  // namespace chromeos_update_engine

#endif  // UPDATE_ENGINE_CROS_DAEMON_CHROMEOS_H_
