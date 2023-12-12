/*
 * Copyright 2018 The Android Open Source Project
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

#include "acl_connection_handler.h"

#include <hci/hci_packets.h>

#include "hci/address.h"
#include "os/log.h"

namespace test_vendor_lib {

using ::bluetooth::hci::Address;
using ::bluetooth::hci::AddressType;
using ::bluetooth::hci::AddressWithType;

bool AclConnectionHandler::HasHandle(uint16_t handle) const {
  return acl_connections_.count(handle) != 0;
}

uint16_t AclConnectionHandler::GetUnusedHandle() {
  while (HasHandle(last_handle_) ||
         isochronous_connection_handler_.HasHandle(last_handle_)) {
    last_handle_ = (last_handle_ + 1) % kReservedHandle;
  }
  uint16_t unused_handle = last_handle_;
  last_handle_ = (last_handle_ + 1) % kReservedHandle;
  return unused_handle;
}

bool AclConnectionHandler::CreatePendingConnection(
    Address addr, bool authenticate_on_connect) {
  if (classic_connection_pending_) {
    return false;
  }
  classic_connection_pending_ = true;
  pending_connection_address_ = addr;
  authenticate_pending_classic_connection_ = authenticate_on_connect;
  return true;
}

bool AclConnectionHandler::HasPendingConnection(Address addr) const {
  return classic_connection_pending_ && pending_connection_address_ == addr;
}

bool AclConnectionHandler::AuthenticatePendingConnection() const {
  return authenticate_pending_classic_connection_;
}

bool AclConnectionHandler::CancelPendingConnection(Address addr) {
  if (!classic_connection_pending_ || pending_connection_address_ != addr) {
    return false;
  }
  classic_connection_pending_ = false;
  pending_connection_address_ = Address::kEmpty;
  return true;
}

bool AclConnectionHandler::CreatePendingLeConnection(AddressWithType addr) {
  bool device_connected = false;
  for (auto pair : acl_connections_) {
    auto connection = std::get<AclConnection>(pair);
    if (connection.GetAddress() == addr) {
      device_connected = true;
    }
  }
  if (device_connected) {
    LOG_INFO("%s: %s is already connected", __func__, addr.ToString().c_str());
    return false;
  }
  if (le_connection_pending_) {
    LOG_INFO("%s: connection already pending", __func__);
    return false;
  }
  le_connection_pending_ = true;
  pending_le_connection_address_ = addr;
  return true;
}

bool AclConnectionHandler::HasPendingLeConnection(AddressWithType addr) const {
  return le_connection_pending_ && pending_le_connection_address_ == addr;
}

bool AclConnectionHandler::CancelPendingLeConnection(AddressWithType addr) {
  if (!le_connection_pending_ || pending_le_connection_address_ != addr) {
    return false;
  }
  le_connection_pending_ = false;
  pending_le_connection_address_ =
      AddressWithType{Address::kEmpty, AddressType::PUBLIC_DEVICE_ADDRESS};
  return true;
}

uint16_t AclConnectionHandler::CreateConnection(Address addr,
                                                Address own_addr) {
  if (CancelPendingConnection(addr)) {
    uint16_t handle = GetUnusedHandle();
    acl_connections_.emplace(
        handle,
        AclConnection{
            AddressWithType{addr, AddressType::PUBLIC_DEVICE_ADDRESS},
            AddressWithType{own_addr, AddressType::PUBLIC_DEVICE_ADDRESS},
            Phy::Type::BR_EDR});
    return handle;
  }
  return kReservedHandle;
}

uint16_t AclConnectionHandler::CreateLeConnection(AddressWithType addr,
                                                  AddressWithType own_addr) {
  if (CancelPendingLeConnection(addr)) {
    uint16_t handle = GetUnusedHandle();
    acl_connections_.emplace(
        handle, AclConnection{addr, own_addr, Phy::Type::LOW_ENERGY});
    return handle;
  }
  return kReservedHandle;
}

bool AclConnectionHandler::Disconnect(uint16_t handle) {
  return acl_connections_.erase(handle) > 0;
}

uint16_t AclConnectionHandler::GetHandle(AddressWithType addr) const {
  for (auto pair : acl_connections_) {
    if (std::get<AclConnection>(pair).GetAddress() == addr) {
      return std::get<0>(pair);
    }
  }
  return kReservedHandle;
}

uint16_t AclConnectionHandler::GetHandleOnlyAddress(
    bluetooth::hci::Address addr) const {
  for (auto pair : acl_connections_) {
    if (std::get<AclConnection>(pair).GetAddress().GetAddress() == addr) {
      return std::get<0>(pair);
    }
  }
  return kReservedHandle;
}

AddressWithType AclConnectionHandler::GetAddress(uint16_t handle) const {
  ASSERT_LOG(HasHandle(handle), "Handle unknown %hd", handle);
  return acl_connections_.at(handle).GetAddress();
}

AddressWithType AclConnectionHandler::GetOwnAddress(uint16_t handle) const {
  ASSERT_LOG(HasHandle(handle), "Handle unknown %hd", handle);
  return acl_connections_.at(handle).GetOwnAddress();
}

void AclConnectionHandler::Encrypt(uint16_t handle) {
  if (!HasHandle(handle)) {
    return;
  }
  acl_connections_.at(handle).Encrypt();
}

bool AclConnectionHandler::IsEncrypted(uint16_t handle) const {
  if (!HasHandle(handle)) {
    return false;
  }
  return acl_connections_.at(handle).IsEncrypted();
}

void AclConnectionHandler::SetAddress(uint16_t handle,
                                      AddressWithType address) {
  if (!HasHandle(handle)) {
    return;
  }
  auto connection = acl_connections_.at(handle);
  connection.SetAddress(address);
}

Phy::Type AclConnectionHandler::GetPhyType(uint16_t handle) const {
  if (!HasHandle(handle)) {
    return Phy::Type::BR_EDR;
  }
  return acl_connections_.at(handle).GetPhyType();
}

std::unique_ptr<bluetooth::hci::LeSetCigParametersCompleteBuilder>
AclConnectionHandler::SetCigParameters(
    uint8_t id, uint32_t sdu_interval_m_to_s, uint32_t sdu_interval_s_to_m,
    bluetooth::hci::ClockAccuracy accuracy, bluetooth::hci::Packing packing,
    bluetooth::hci::Enable framed, uint16_t max_transport_latency_m_to_s_,
    uint16_t max_transport_latency_s_to_m_,
    std::vector<bluetooth::hci::CisParametersConfig>& streams) {
  std::vector<uint16_t> handles;
  GroupParameters group_parameters{
      .id = id,
      .sdu_interval_m_to_s = sdu_interval_m_to_s,
      .sdu_interval_s_to_m = sdu_interval_s_to_m,
      .interleaved = packing == bluetooth::hci::Packing::INTERLEAVED,
      .framed = framed == bluetooth::hci::Enable::ENABLED,
      .max_transport_latency_m_to_s = max_transport_latency_m_to_s_,
      .max_transport_latency_s_to_m = max_transport_latency_s_to_m_};
  std::vector<StreamParameters> stream_parameters;
  for (size_t i = 0; i < streams.size(); i++) {
    auto handle = GetUnusedHandle();
    StreamParameters a{.group_id = group_parameters.id,
                       .stream_id = streams[i].cis_id_,
                       .max_sdu_m_to_s = streams[i].max_sdu_m_to_s_,
                       .max_sdu_s_to_m = streams[i].max_sdu_s_to_m_,
                       .rtn_m_to_s = streams[i].rtn_m_to_s_,
                       .rtn_s_to_m = streams[i].rtn_s_to_m_,
                       .handle = handle};
    handles.push_back(handle);
    stream_parameters.push_back(std::move(a));
  }

  return isochronous_connection_handler_.SetCigParameters(
      group_parameters, stream_parameters, std::move(handles));
}

void AclConnectionHandler::CreatePendingCis(
    bluetooth::hci::CreateCisConfig config) {
  CisHandles handles;
  handles.cis_handle_ = config.cis_connection_handle_;
  handles.acl_handle_ = config.acl_connection_handle_;
  handles.remote_cis_handle_ = kReservedHandle;
  pending_streams_.emplace_back(std::move(handles));
}

bool AclConnectionHandler::ConnectCis(uint16_t handle) {
  size_t position;
  CisHandles connection;
  for (position = 0; position < pending_streams_.size(); position++) {
    if (handle == pending_streams_[position].cis_handle_) {
      LOG_INFO("Found handle 0x%04hx", handle);
      connection = pending_streams_[position];
      pending_streams_.erase(pending_streams_.begin() + position);
      connected_streams_.push_back(connection);
      ASSERT(connection.cis_handle_ != kReservedHandle);
      ASSERT(connection.acl_handle_ != kReservedHandle);
      ASSERT(connection.remote_cis_handle_ != kReservedHandle);
      return true;
    }
  }

  LOG_INFO("No pending CIS connection with handle 0x%04hx", handle);
  return false;
}

void AclConnectionHandler::SetRemoteCisHandle(uint16_t handle,
                                              uint16_t remote_handle) {
  for (size_t position = 0; position < pending_streams_.size(); position++) {
    if (handle == pending_streams_[position].cis_handle_) {
      LOG_INFO("Added remote handle 0x%04hx to handle 0x%04hx", remote_handle,
               pending_streams_[position].cis_handle_);
      pending_streams_[position].remote_cis_handle_ = remote_handle;
      return;
    }
  }
  LOG_INFO("Couldn't find CIS connection with handle 0x%04hx", handle);
}

bool AclConnectionHandler::RejectCis(uint16_t handle) {
  size_t position;
  for (position = 0; position < pending_streams_.size(); position++) {
    if (handle == pending_streams_[position].cis_handle_) {
      pending_streams_.erase(pending_streams_.begin() + position);
      break;
    }
  }
  if (position == pending_streams_.size()) {
    LOG_INFO("No pending connection with handle 0x%hx", handle);
    return false;
  }
  return true;
}

uint16_t AclConnectionHandler::GetPendingAclHandle(uint16_t cis_handle) const {
  size_t position;
  uint16_t handle = 0xffff;
  for (position = 0; position < pending_streams_.size(); position++) {
    if (cis_handle == pending_streams_[position].cis_handle_) {
      handle = pending_streams_[position].acl_handle_;
      break;
    }
  }
  if (position == pending_streams_.size()) {
    LOG_INFO("No pending connection with handle 0x%hx", cis_handle);
  }
  return handle;
}

bool AclConnectionHandler::DisconnectCis(uint16_t cis_handle) {
  size_t position;
  for (position = 0; position < connected_streams_.size(); position++) {
    if (cis_handle == connected_streams_[position].cis_handle_) {
      connected_streams_.erase(connected_streams_.begin() + position);
      break;
    }
  }
  if (position == connected_streams_.size()) {
    LOG_INFO("No connected stream 0x%hx", cis_handle);
    return false;
  }
  return true;
}

bluetooth::hci::ErrorCode AclConnectionHandler::RemoveCig(uint8_t cig_id) {
  for (const auto& stream : connected_streams_) {
    if (isochronous_connection_handler_.GetGroupId(stream.cis_handle_) ==
        cig_id) {
      return bluetooth::hci::ErrorCode::COMMAND_DISALLOWED;
    }
  }
  for (const auto& stream : pending_streams_) {
    if (isochronous_connection_handler_.GetGroupId(stream.cis_handle_) ==
        cig_id) {
      return bluetooth::hci::ErrorCode::COMMAND_DISALLOWED;
    }
  }
  auto status = isochronous_connection_handler_.RemoveCig(cig_id);
  if (status == bluetooth::hci::ErrorCode::SUCCESS) {
    // Clean up?
  }
  return status;
}

bool AclConnectionHandler::HasPendingCisConnection(uint16_t handle) const {
  for (const auto& config : pending_streams_) {
    if (config.cis_handle_ == handle) {
      return true;
    }
  }
  return false;
}

bool AclConnectionHandler::HasPendingCis() const {
  return !pending_streams_.empty();
}

bool AclConnectionHandler::HasConnectedCis(uint16_t handle) const {
  for (const auto& cs : connected_streams_) {
    if (handle == cs.cis_handle_) {
      return true;
    }
  }
  return false;
}

bool AclConnectionHandler::HasCisHandle(uint16_t handle) const {
  for (const auto& cs : pending_streams_) {
    if (handle == cs.cis_handle_) {
      return true;
    }
  }
  for (const auto& cs : connected_streams_) {
    if (handle == cs.cis_handle_) {
      return true;
    }
  }
  return isochronous_connection_handler_.HasHandle(handle);
}

uint16_t AclConnectionHandler::GetAclHandleForCisHandle(
    uint16_t cis_handle) const {
  for (const auto& cs : connected_streams_) {
    if (cis_handle == cs.cis_handle_) {
      return cs.acl_handle_;
    }
  }
  return kReservedHandle;
}

uint16_t AclConnectionHandler::GetRemoteCisHandleForCisHandle(
    uint16_t cis_handle) const {
  for (const auto& cs : connected_streams_) {
    if (cis_handle == cs.cis_handle_) {
      return cs.remote_cis_handle_;
    }
  }
  return kReservedHandle;
}

GroupParameters AclConnectionHandler::GetGroupParameters(uint8_t id) const {
  return isochronous_connection_handler_.GetGroupParameters(id);
}

StreamParameters AclConnectionHandler::GetStreamParameters(
    uint16_t handle) const {
  return isochronous_connection_handler_.GetStreamParameters(handle);
}

}  // namespace test_vendor_lib
