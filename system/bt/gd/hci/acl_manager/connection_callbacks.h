/*
 * Copyright 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <memory>
#include "hci/acl_manager/classic_acl_connection.h"
#include "hci/address.h"
#include "hci/class_of_device.h"
#include "hci/hci_packets.h"
#include "os/handler.h"

namespace bluetooth {
namespace hci {
namespace acl_manager {

class ConnectionCallbacks {
 public:
  virtual ~ConnectionCallbacks() = default;
  // Invoked when controller sends Connection Complete event with Success error code
  virtual void OnConnectSuccess(std::unique_ptr<ClassicAclConnection>) = 0;
  // Invoked when controller sends Connection Complete event with non-Success error code
  virtual void OnConnectFail(Address, ErrorCode reason) = 0;

  virtual void HACK_OnEscoConnectRequest(Address, ClassOfDevice) = 0;
  virtual void HACK_OnScoConnectRequest(Address, ClassOfDevice) = 0;
};

}  // namespace acl_manager
}  // namespace hci
}  // namespace bluetooth
