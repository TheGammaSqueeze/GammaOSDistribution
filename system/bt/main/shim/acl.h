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

#include <future>
#include <memory>

#include "gd/hci/acl_manager/connection_callbacks.h"
#include "gd/hci/acl_manager/le_connection_callbacks.h"
#include "gd/hci/address.h"
#include "gd/hci/address_with_type.h"
#include "gd/hci/class_of_device.h"
#include "gd/os/handler.h"
#include "gd/packet/raw_builder.h"
#include "main/shim/acl_legacy_interface.h"
#include "main/shim/link_connection_interface.h"
#include "main/shim/link_policy_interface.h"
#include "stack/include/bt_types.h"

namespace bluetooth {
namespace shim {
namespace legacy {

class Acl : public hci::acl_manager::ConnectionCallbacks,
            public hci::acl_manager::LeConnectionCallbacks,
            public LinkConnectionInterface,
            public LinkPolicyInterface {
 public:
  Acl(os::Handler* handler, const acl_interface_t& acl_interface,
      uint8_t max_acceptlist_size);
  ~Acl();

  // hci::acl_manager::ConnectionCallbacks
  void OnConnectSuccess(
      std::unique_ptr<hci::acl_manager::ClassicAclConnection>) override;
  void OnConnectFail(hci::Address, hci::ErrorCode reason) override;

  void HACK_OnEscoConnectRequest(hci::Address, hci::ClassOfDevice) override;
  void HACK_OnScoConnectRequest(hci::Address, hci::ClassOfDevice) override;

  void OnClassicLinkDisconnected(uint16_t handle, hci::ErrorCode reason);

  // hci::acl_manager::LeConnectionCallbacks
  void OnLeConnectSuccess(
      hci::AddressWithType,
      std::unique_ptr<hci::acl_manager::LeAclConnection>) override;
  void OnLeConnectFail(hci::AddressWithType, hci::ErrorCode reason) override;
  void OnLeLinkDisconnected(uint16_t handle, hci::ErrorCode reason);
  bluetooth::hci::AddressWithType GetConnectionLocalAddress(
      const RawAddress& remote_bda);

  // LinkConnectionInterface
  void CreateClassicConnection(const hci::Address& address) override;
  void CancelClassicConnection(const hci::Address& address) override;
  void AcceptLeConnectionFrom(const hci::AddressWithType& address_with_type,
                              bool is_direct,
                              std::promise<bool> promise) override;
  void IgnoreLeConnectionFrom(
      const hci::AddressWithType& address_with_type) override;
  void DisconnectClassic(uint16_t handle, tHCI_REASON reason) override;
  void DisconnectLe(uint16_t handle, tHCI_REASON reason) override;

  // LinkPolicyInterface
  bool HoldMode(uint16_t hci_handle, uint16_t max_interval,
                uint16_t min_interval) override;
  bool SniffMode(uint16_t hci_handle, uint16_t max_interval,
                 uint16_t min_interval, uint16_t attempt,
                 uint16_t timeout) override;
  bool ExitSniffMode(uint16_t hci_handle) override;
  bool SniffSubrating(uint16_t hci_handle, uint16_t maximum_latency,
                      uint16_t minimum_remote_timeout,
                      uint16_t minimum_local_timeout) override;

  void HACK_OnScoDisconnected(uint16_t handle, uint8_t reason);

  void WriteData(uint16_t hci_handle,
                 std::unique_ptr<packet::RawBuilder> packet);

  void ConfigureLePrivacy(bool is_le_privacy_enabled);

  void Dump(int fd) const;
  void DumpConnectionHistory(int fd) const;

  void Shutdown();
  void FinalShutdown();

  void ClearAcceptList();

 protected:
  void on_incoming_acl_credits(uint16_t handle, uint16_t credits);
  void write_data_sync(uint16_t hci_handle,
                       std::unique_ptr<packet::RawBuilder> packet);

 private:
  os::Handler* handler_;
  const acl_interface_t acl_interface_;

  bool CheckForOrphanedAclConnections() const;

  struct impl;
  std::unique_ptr<impl> pimpl_;
  DISALLOW_COPY_AND_ASSIGN(Acl);
};

}  // namespace legacy
}  // namespace shim
}  // namespace bluetooth
