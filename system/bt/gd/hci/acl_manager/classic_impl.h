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

#include "common/bind.h"
#include "hci/acl_manager/assembler.h"
#include "hci/acl_manager/event_checkers.h"
#include "hci/acl_manager/round_robin_scheduler.h"
#include "hci/controller.h"
#include "security/security_manager_listener.h"
#include "security/security_module.h"

namespace bluetooth {
namespace hci {
namespace acl_manager {

struct acl_connection {
  acl_connection(AddressWithType address_with_type, AclConnection::QueueDownEnd* queue_down_end, os::Handler* handler)
      : assembler_(address_with_type, queue_down_end, handler), address_with_type_(address_with_type) {}
  ~acl_connection() = default;
  struct acl_manager::assembler assembler_;
  AddressWithType address_with_type_;
  ConnectionManagementCallbacks* connection_management_callbacks_ = nullptr;
};

struct classic_impl : public security::ISecurityManagerListener {
  classic_impl(
      HciLayer* hci_layer,
      Controller* controller,
      os::Handler* handler,
      RoundRobinScheduler* round_robin_scheduler,
      bool crash_on_unknown_handle)
      : hci_layer_(hci_layer),
        controller_(controller),
        round_robin_scheduler_(round_robin_scheduler),
        crash_on_unknown_handle_(crash_on_unknown_handle) {
    hci_layer_ = hci_layer;
    controller_ = controller;
    handler_ = handler;
    should_accept_connection_ = common::Bind([](Address, ClassOfDevice) { return true; });
    acl_connection_interface_ = hci_layer_->GetAclConnectionInterface(
        handler_->BindOn(this, &classic_impl::on_classic_event),
        handler_->BindOn(this, &classic_impl::on_classic_disconnect),
        handler_->BindOn(this, &classic_impl::on_read_remote_version_information));
  }

  ~classic_impl() {
    for (auto event_code : AclConnectionEvents) {
      hci_layer_->UnregisterEventHandler(event_code);
    }
    acl_connections_.clear();
    security_manager_.reset();
  }

  ConnectionManagementCallbacks* get_callbacks(uint16_t handle) {
    auto conn = acl_connections_.find(handle);
    if (conn == acl_connections_.end()) {
      return nullptr;
    } else {
      return conn->second.connection_management_callbacks_;
    }
  }

  void on_classic_event(EventView event_packet) {
    EventCode event_code = event_packet.GetEventCode();
    switch (event_code) {
      case EventCode::CONNECTION_COMPLETE:
        on_connection_complete(event_packet);
        break;
      case EventCode::CONNECTION_REQUEST:
        on_incoming_connection(event_packet);
        break;
      case EventCode::CONNECTION_PACKET_TYPE_CHANGED:
        on_connection_packet_type_changed(event_packet);
        break;
      case EventCode::AUTHENTICATION_COMPLETE:
        on_authentication_complete(event_packet);
        break;
      case EventCode::READ_CLOCK_OFFSET_COMPLETE:
        on_read_clock_offset_complete(event_packet);
        break;
      case EventCode::MODE_CHANGE:
        on_mode_change(event_packet);
        break;
      case EventCode::SNIFF_SUBRATING:
        on_sniff_subrating(event_packet);
        break;
      case EventCode::QOS_SETUP_COMPLETE:
        on_qos_setup_complete(event_packet);
        break;
      case EventCode::ROLE_CHANGE:
        on_role_change(event_packet);
        break;
      case EventCode::FLOW_SPECIFICATION_COMPLETE:
        on_flow_specification_complete(event_packet);
        break;
      case EventCode::FLUSH_OCCURRED:
        on_flush_occurred(event_packet);
        break;
      case EventCode::READ_REMOTE_SUPPORTED_FEATURES_COMPLETE:
        on_read_remote_supported_features_complete(event_packet);
        break;
      case EventCode::READ_REMOTE_EXTENDED_FEATURES_COMPLETE:
        on_read_remote_extended_features_complete(event_packet);
        break;
      case EventCode::LINK_SUPERVISION_TIMEOUT_CHANGED:
        on_link_supervision_timeout_changed(event_packet);
        break;
      case EventCode::CENTRAL_LINK_KEY_COMPLETE:
        on_central_link_key_complete(event_packet);
        break;
      default:
        LOG_ALWAYS_FATAL("Unhandled event code %s", EventCodeText(event_code).c_str());
    }
  }

  void on_classic_disconnect(uint16_t handle, ErrorCode reason) {
    auto callbacks = get_callbacks(handle);
    if (callbacks != nullptr) {
      round_robin_scheduler_->Unregister(handle);
      callbacks->OnDisconnection(reason);
      acl_connections_.erase(handle);
    } else {
      // This handle is probably for SCO, so we use the callback workaround.
      if (sco_disconnect_callback_ != nullptr) {
        sco_disconnect_callback_(handle, static_cast<uint8_t>(reason));
      }
    }
  }

  void handle_register_callbacks(ConnectionCallbacks* callbacks, os::Handler* handler) {
    ASSERT(client_callbacks_ == nullptr);
    ASSERT(client_handler_ == nullptr);
    client_callbacks_ = callbacks;
    client_handler_ = handler;
  }

  void handle_unregister_callbacks(ConnectionCallbacks* callbacks, std::promise<void> promise) {
    ASSERT_LOG(client_callbacks_ == callbacks, "Registered callback entity is different then unregister request");
    client_callbacks_ = nullptr;
    client_handler_ = nullptr;
    promise.set_value();
  }

  void on_incoming_connection(EventView packet) {
    ConnectionRequestView request = ConnectionRequestView::Create(packet);
    ASSERT(request.IsValid());
    Address address = request.GetBdAddr();
    if (client_callbacks_ == nullptr) {
      LOG_ERROR("No callbacks to call");
      auto reason = RejectConnectionReason::LIMITED_RESOURCES;
      this->reject_connection(RejectConnectionRequestBuilder::Create(address, reason));
      return;
    }

    switch (request.GetLinkType()) {
      case ConnectionRequestLinkType::SCO:
        client_handler_->CallOn(
            client_callbacks_, &ConnectionCallbacks::HACK_OnScoConnectRequest, address, request.GetClassOfDevice());
        return;

      case ConnectionRequestLinkType::ACL:
        break;

      case ConnectionRequestLinkType::ESCO:
        client_handler_->CallOn(
            client_callbacks_, &ConnectionCallbacks::HACK_OnEscoConnectRequest, address, request.GetClassOfDevice());
        return;

      case ConnectionRequestLinkType::UNKNOWN:
        LOG_ERROR("Request has unknown ConnectionRequestLinkType.");
        return;
    }

    incoming_connecting_address_ = address;
    if (is_classic_link_already_connected(address)) {
      auto reason = RejectConnectionReason::UNACCEPTABLE_BD_ADDR;
      this->reject_connection(RejectConnectionRequestBuilder::Create(address, reason));
    } else if (should_accept_connection_.Run(address, request.GetClassOfDevice())) {
      this->accept_connection(address);
    } else {
      auto reason = RejectConnectionReason::LIMITED_RESOURCES;  // TODO: determine reason
      this->reject_connection(RejectConnectionRequestBuilder::Create(address, reason));
    }
  }

  bool is_classic_link_already_connected(Address address) {
    for (const auto& connection : acl_connections_) {
      if (connection.second.address_with_type_.GetAddress() == address) {
        return true;
      }
    }
    return false;
  }

  void create_connection(Address address) {
    // TODO: Configure default connection parameters?
    uint16_t packet_type = 0x4408 /* DM 1,3,5 */ | 0x8810 /*DH 1,3,5 */;
    PageScanRepetitionMode page_scan_repetition_mode = PageScanRepetitionMode::R1;
    uint16_t clock_offset = 0;
    ClockOffsetValid clock_offset_valid = ClockOffsetValid::INVALID;
    CreateConnectionRoleSwitch allow_role_switch = CreateConnectionRoleSwitch::ALLOW_ROLE_SWITCH;
    ASSERT(client_callbacks_ != nullptr);
    std::unique_ptr<CreateConnectionBuilder> packet = CreateConnectionBuilder::Create(
        address, packet_type, page_scan_repetition_mode, clock_offset, clock_offset_valid, allow_role_switch);

    if (incoming_connecting_address_ == Address::kEmpty && outgoing_connecting_address_ == Address::kEmpty) {
      if (is_classic_link_already_connected(address)) {
        LOG_WARN("already connected: %s", address.ToString().c_str());
        return;
      }
      outgoing_connecting_address_ = address;
      acl_connection_interface_->EnqueueCommand(std::move(packet), handler_->BindOnce([](CommandStatusView status) {
        ASSERT(status.IsValid());
        ASSERT(status.GetCommandOpCode() == OpCode::CREATE_CONNECTION);
      }));
    } else {
      pending_outgoing_connections_.emplace(address, std::move(packet));
    }
  }

  void on_connection_complete(EventView packet) {
    ConnectionCompleteView connection_complete = ConnectionCompleteView::Create(packet);
    ASSERT(connection_complete.IsValid());
    auto status = connection_complete.GetStatus();
    auto address = connection_complete.GetBdAddr();
    Role current_role = Role::CENTRAL;
    bool locally_initiated = true;
    if (outgoing_connecting_address_ == address) {
      outgoing_connecting_address_ = Address::kEmpty;
    } else {
      locally_initiated = false;
      if (incoming_connecting_address_ != address && status == ErrorCode::UNKNOWN_CONNECTION) {
        LOG_WARN("No matching connection to %s (%s)", address.ToString().c_str(), ErrorCodeText(status).c_str());
        LOG_WARN("Firmware error after RemoteNameRequestCancel?");
        return;
      }
      ASSERT_LOG(incoming_connecting_address_ == address, "No prior connection request for %s",
                 address.ToString().c_str());
      incoming_connecting_address_ = Address::kEmpty;
      current_role = Role::PERIPHERAL;
    }
    if (client_callbacks_ == nullptr) {
      LOG_WARN("No client callbacks registered for connection");
      return;
    }
    if (status != ErrorCode::SUCCESS) {
      client_handler_->Post(common::BindOnce(&ConnectionCallbacks::OnConnectFail, common::Unretained(client_callbacks_),
                                             address, status));
      return;
    }
    uint16_t handle = connection_complete.GetConnectionHandle();
    auto queue = std::make_shared<AclConnection::Queue>(10);
    auto conn_pair = acl_connections_.emplace(
        std::piecewise_construct,
        std::forward_as_tuple(handle),
        std::forward_as_tuple(
            AddressWithType{address, AddressType::PUBLIC_DEVICE_ADDRESS}, queue->GetDownEnd(), handler_));
    ASSERT(conn_pair.second);  // Make sure it's not a duplicate
    round_robin_scheduler_->Register(RoundRobinScheduler::ConnectionType::CLASSIC, handle, queue);
    std::unique_ptr<ClassicAclConnection> connection(
        new ClassicAclConnection(std::move(queue), acl_connection_interface_, handle, address));
    connection->locally_initiated_ = locally_initiated;
    auto& connection_proxy = conn_pair.first->second;
    connection_proxy.connection_management_callbacks_ = connection->GetEventCallbacks();
    if (delayed_role_change_ != nullptr) {
      if (delayed_role_change_->GetBdAddr() == address) {
        LOG_INFO("Sending delayed role change for %s", delayed_role_change_->GetBdAddr().ToString().c_str());
        connection_proxy.connection_management_callbacks_->OnRoleChange(
            delayed_role_change_->GetStatus(), delayed_role_change_->GetNewRole());
      }
      delayed_role_change_ = nullptr;
    } else {
      connection_proxy.connection_management_callbacks_->OnRoleChange(hci::ErrorCode::SUCCESS, current_role);
    }
    client_handler_->Post(common::BindOnce(&ConnectionCallbacks::OnConnectSuccess,
                                           common::Unretained(client_callbacks_), std::move(connection)));
    while (!pending_outgoing_connections_.empty()) {
      auto create_connection_packet_and_address = std::move(pending_outgoing_connections_.front());
      pending_outgoing_connections_.pop();
      if (!is_classic_link_already_connected(create_connection_packet_and_address.first)) {
        outgoing_connecting_address_ = create_connection_packet_and_address.first;
        acl_connection_interface_->EnqueueCommand(std::move(create_connection_packet_and_address.second),
                                                  handler_->BindOnce([](CommandStatusView status) {
                                                    ASSERT(status.IsValid());
                                                    ASSERT(status.GetCommandOpCode() == OpCode::CREATE_CONNECTION);
                                                  }));
        break;
      }
    }
  }

  void on_connection_packet_type_changed(EventView packet) {
    ConnectionPacketTypeChangedView packet_type_changed = ConnectionPacketTypeChangedView::Create(packet);
    if (!packet_type_changed.IsValid()) {
      LOG_ERROR("Received on_connection_packet_type_changed with invalid packet");
      return;
    } else if (packet_type_changed.GetStatus() != ErrorCode::SUCCESS) {
      auto status = packet_type_changed.GetStatus();
      std::string error_code = ErrorCodeText(status);
      LOG_ERROR("Received on_connection_packet_type_changed with error code %s", error_code.c_str());
      return;
    }
    uint16_t handle = packet_type_changed.GetConnectionHandle();
    auto callbacks = get_callbacks(handle);
    if (callbacks == nullptr) {
      LOG_WARN("Unknown connection handle 0x%04hx", handle);
      ASSERT(!crash_on_unknown_handle_);
      return;
    }
    // We don't handle this event; we didn't do this in legacy stack either.
  }

  void on_central_link_key_complete(EventView packet) {
    CentralLinkKeyCompleteView complete_view = CentralLinkKeyCompleteView::Create(packet);
    if (!complete_view.IsValid()) {
      LOG_ERROR("Received on_central_link_key_complete with invalid packet");
      return;
    } else if (complete_view.GetStatus() != ErrorCode::SUCCESS) {
      auto status = complete_view.GetStatus();
      std::string error_code = ErrorCodeText(status);
      LOG_ERROR("Received on_central_link_key_complete with error code %s", error_code.c_str());
      return;
    }
    uint16_t handle = complete_view.GetConnectionHandle();
    auto callbacks = get_callbacks(handle);
    if (callbacks == nullptr) {
      LOG_WARN("Unknown connection handle 0x%04hx", handle);
      ASSERT(!crash_on_unknown_handle_);
      return;
    }
    KeyFlag key_flag = complete_view.GetKeyFlag();
    callbacks->OnCentralLinkKeyComplete(key_flag);
  }

  void on_authentication_complete(EventView packet) {
    AuthenticationCompleteView authentication_complete = AuthenticationCompleteView::Create(packet);
    if (!authentication_complete.IsValid()) {
      LOG_ERROR("Received on_authentication_complete with invalid packet");
      return;
    }
    uint16_t handle = authentication_complete.GetConnectionHandle();
    auto callbacks = get_callbacks(handle);
    if (callbacks == nullptr) {
      LOG_WARN("Unknown connection handle 0x%04hx", handle);
      ASSERT(!crash_on_unknown_handle_);
      return;
    }
    callbacks->OnAuthenticationComplete(authentication_complete.GetStatus());
  }

  void cancel_connect(Address address) {
    if (outgoing_connecting_address_ == address) {
      LOG_INFO("Cannot cancel non-existent connection to %s", address.ToString().c_str());
      return;
    }
    std::unique_ptr<CreateConnectionCancelBuilder> packet = CreateConnectionCancelBuilder::Create(address);
    acl_connection_interface_->EnqueueCommand(
        std::move(packet), handler_->BindOnce(&check_command_complete<CreateConnectionCancelCompleteView>));
  }

  void central_link_key(KeyFlag key_flag) {
    std::unique_ptr<CentralLinkKeyBuilder> packet = CentralLinkKeyBuilder::Create(key_flag);
    acl_connection_interface_->EnqueueCommand(
        std::move(packet), handler_->BindOnce(&check_command_status<CentralLinkKeyStatusView>));
  }

  void switch_role(Address address, Role role) {
    std::unique_ptr<SwitchRoleBuilder> packet = SwitchRoleBuilder::Create(address, role);
    acl_connection_interface_->EnqueueCommand(std::move(packet),
                                              handler_->BindOnce(&check_command_status<SwitchRoleStatusView>));
  }

  void write_default_link_policy_settings(uint16_t default_link_policy_settings) {
    std::unique_ptr<WriteDefaultLinkPolicySettingsBuilder> packet =
        WriteDefaultLinkPolicySettingsBuilder::Create(default_link_policy_settings);
    acl_connection_interface_->EnqueueCommand(
        std::move(packet), handler_->BindOnce(&check_command_complete<WriteDefaultLinkPolicySettingsCompleteView>));
  }

  void accept_connection(Address address) {
    auto role = AcceptConnectionRequestRole::BECOME_CENTRAL;  // We prefer to be central
    acl_connection_interface_->EnqueueCommand(
        AcceptConnectionRequestBuilder::Create(address, role),
        handler_->BindOnceOn(this, &classic_impl::on_accept_connection_status, address));
  }

  void on_change_connection_link_key_complete(EventView packet) {
    ChangeConnectionLinkKeyCompleteView complete_view = ChangeConnectionLinkKeyCompleteView::Create(packet);
    if (!complete_view.IsValid()) {
      LOG_ERROR("Received on_change_connection_link_key_complete with invalid packet");
      return;
    } else if (complete_view.GetStatus() != ErrorCode::SUCCESS) {
      auto status = complete_view.GetStatus();
      std::string error_code = ErrorCodeText(status);
      LOG_ERROR("Received on_change_connection_link_key_complete with error code %s", error_code.c_str());
      return;
    }
    uint16_t handle = complete_view.GetConnectionHandle();
    auto callbacks = get_callbacks(handle);
    if (callbacks == nullptr) {
      LOG_WARN("Unknown connection handle 0x%04hx", handle);
      ASSERT(!crash_on_unknown_handle_);
      return;
    }
    callbacks->OnChangeConnectionLinkKeyComplete();
  }

  void on_read_clock_offset_complete(EventView packet) {
    ReadClockOffsetCompleteView complete_view = ReadClockOffsetCompleteView::Create(packet);
    if (!complete_view.IsValid()) {
      LOG_ERROR("Received on_read_clock_offset_complete with invalid packet");
      return;
    } else if (complete_view.GetStatus() != ErrorCode::SUCCESS) {
      auto status = complete_view.GetStatus();
      std::string error_code = ErrorCodeText(status);
      LOG_ERROR("Received on_read_clock_offset_complete with error code %s", error_code.c_str());
      return;
    }
    uint16_t handle = complete_view.GetConnectionHandle();
    auto callbacks = get_callbacks(handle);
    if (callbacks == nullptr) {
      LOG_WARN("Unknown connection handle 0x%04hx", handle);
      ASSERT(!crash_on_unknown_handle_);
      return;
    }
    uint16_t clock_offset = complete_view.GetClockOffset();
    callbacks->OnReadClockOffsetComplete(clock_offset);
  }

  void on_mode_change(EventView packet) {
    ModeChangeView mode_change_view = ModeChangeView::Create(packet);
    if (!mode_change_view.IsValid()) {
      LOG_ERROR("Received on_mode_change with invalid packet");
      return;
    }
    uint16_t handle = mode_change_view.GetConnectionHandle();
    auto callbacks = get_callbacks(handle);
    if (callbacks == nullptr) {
      LOG_WARN("Unknown connection handle 0x%04hx", handle);
      ASSERT(!crash_on_unknown_handle_);
      return;
    }
    callbacks->OnModeChange(
        mode_change_view.GetStatus(), mode_change_view.GetCurrentMode(), mode_change_view.GetInterval());
  }

  void on_sniff_subrating(EventView packet) {
    SniffSubratingEventView sniff_subrating_view = SniffSubratingEventView::Create(packet);
    if (!sniff_subrating_view.IsValid()) {
      LOG_ERROR("Received on_sniff_subrating with invalid packet");
      return;
    }
    uint16_t handle = sniff_subrating_view.GetConnectionHandle();
    auto callbacks = get_callbacks(handle);
    if (callbacks == nullptr) {
      LOG_WARN("Unknown connection handle 0x%04hx", handle);
      ASSERT(!crash_on_unknown_handle_);
      return;
    }
    callbacks->OnSniffSubrating(
        sniff_subrating_view.GetStatus(),
        sniff_subrating_view.GetMaximumTransmitLatency(),
        sniff_subrating_view.GetMaximumReceiveLatency(),
        sniff_subrating_view.GetMinimumRemoteTimeout(),
        sniff_subrating_view.GetMinimumLocalTimeout());
  }

  void on_qos_setup_complete(EventView packet) {
    QosSetupCompleteView complete_view = QosSetupCompleteView::Create(packet);
    if (!complete_view.IsValid()) {
      LOG_ERROR("Received on_qos_setup_complete with invalid packet");
      return;
    } else if (complete_view.GetStatus() != ErrorCode::SUCCESS) {
      auto status = complete_view.GetStatus();
      std::string error_code = ErrorCodeText(status);
      LOG_ERROR("Received on_qos_setup_complete with error code %s", error_code.c_str());
      return;
    }
    uint16_t handle = complete_view.GetConnectionHandle();
    auto callbacks = get_callbacks(handle);
    if (callbacks == nullptr) {
      LOG_WARN("Unknown connection handle 0x%04hx", handle);
      ASSERT(!crash_on_unknown_handle_);
      return;
    }
    ServiceType service_type = complete_view.GetServiceType();
    uint32_t token_rate = complete_view.GetTokenRate();
    uint32_t peak_bandwidth = complete_view.GetPeakBandwidth();
    uint32_t latency = complete_view.GetLatency();
    uint32_t delay_variation = complete_view.GetDelayVariation();
    callbacks->OnQosSetupComplete(service_type, token_rate, peak_bandwidth, latency, delay_variation);
  }

  void on_role_change(EventView packet) {
    RoleChangeView role_change_view = RoleChangeView::Create(packet);
    if (!role_change_view.IsValid()) {
      LOG_ERROR("Received on_role_change with invalid packet");
      return;
    }
    bool sent = false;
    auto hci_status = role_change_view.GetStatus();
    Address bd_addr = role_change_view.GetBdAddr();
    Role new_role = role_change_view.GetNewRole();
    for (auto& connection_pair : acl_connections_) {
      if (connection_pair.second.address_with_type_.GetAddress() == bd_addr) {
        connection_pair.second.connection_management_callbacks_->OnRoleChange(hci_status, new_role);
        sent = true;
      }
    }
    if (!sent) {
      if (delayed_role_change_ != nullptr) {
        LOG_WARN("Second delayed role change (@%s dropped)", delayed_role_change_->GetBdAddr().ToString().c_str());
      }
      LOG_INFO(
          "Role change for %s with no matching connection (new role: %s)",
          role_change_view.GetBdAddr().ToString().c_str(),
          RoleText(role_change_view.GetNewRole()).c_str());
      delayed_role_change_ = std::make_unique<RoleChangeView>(role_change_view);
    }
  }

  void on_flow_specification_complete(EventView packet) {
    FlowSpecificationCompleteView complete_view = FlowSpecificationCompleteView::Create(packet);
    if (!complete_view.IsValid()) {
      LOG_ERROR("Received on_flow_specification_complete with invalid packet");
      return;
    } else if (complete_view.GetStatus() != ErrorCode::SUCCESS) {
      auto status = complete_view.GetStatus();
      std::string error_code = ErrorCodeText(status);
      LOG_ERROR("Received on_flow_specification_complete with error code %s", error_code.c_str());
      return;
    }
    uint16_t handle = complete_view.GetConnectionHandle();
    auto callbacks = get_callbacks(handle);
    if (callbacks == nullptr) {
      LOG_WARN("Unknown connection handle 0x%04hx", handle);
      ASSERT(!crash_on_unknown_handle_);
      return;
    }
    FlowDirection flow_direction = complete_view.GetFlowDirection();
    ServiceType service_type = complete_view.GetServiceType();
    uint32_t token_rate = complete_view.GetTokenRate();
    uint32_t token_bucket_size = complete_view.GetTokenBucketSize();
    uint32_t peak_bandwidth = complete_view.GetPeakBandwidth();
    uint32_t access_latency = complete_view.GetAccessLatency();
    callbacks->OnFlowSpecificationComplete(
        flow_direction, service_type, token_rate, token_bucket_size, peak_bandwidth, access_latency);
  }

  void on_flush_occurred(EventView packet) {
    FlushOccurredView flush_occurred_view = FlushOccurredView::Create(packet);
    if (!flush_occurred_view.IsValid()) {
      LOG_ERROR("Received on_flush_occurred with invalid packet");
      return;
    }
    uint16_t handle = flush_occurred_view.GetConnectionHandle();
    auto callbacks = get_callbacks(handle);
    if (callbacks == nullptr) {
      LOG_WARN("Unknown connection handle 0x%04hx", handle);
      ASSERT(!crash_on_unknown_handle_);
      return;
    }
    callbacks->OnFlushOccurred();
  }

  void on_read_remote_version_information(
      hci::ErrorCode hci_status, uint16_t handle, uint8_t version, uint16_t manufacturer_name, uint16_t sub_version) {
    auto callbacks = get_callbacks(handle);
    if (callbacks == nullptr) {
      LOG_WARN("Unknown connection handle 0x%04hx", handle);
      ASSERT(!crash_on_unknown_handle_);
      return;
    }
    callbacks->OnReadRemoteVersionInformationComplete(hci_status, version, manufacturer_name, sub_version);
  }

  void on_read_remote_supported_features_complete(EventView packet) {
    auto view = ReadRemoteSupportedFeaturesCompleteView::Create(packet);
    ASSERT_LOG(view.IsValid(), "Read remote supported features packet invalid");
    uint16_t handle = view.GetConnectionHandle();
    auto callbacks = get_callbacks(handle);
    if (callbacks == nullptr) {
      LOG_WARN("Unknown connection handle 0x%04hx", handle);
      ASSERT(!crash_on_unknown_handle_);
      return;
    }
    callbacks->OnReadRemoteSupportedFeaturesComplete(view.GetLmpFeatures());
  }

  void on_read_remote_extended_features_complete(EventView packet) {
    auto view = ReadRemoteExtendedFeaturesCompleteView::Create(packet);
    ASSERT_LOG(view.IsValid(), "Read remote extended features packet invalid");
    uint16_t handle = view.GetConnectionHandle();
    auto callbacks = get_callbacks(handle);
    if (callbacks == nullptr) {
      LOG_WARN("Unknown connection handle 0x%04hx", handle);
      ASSERT(!crash_on_unknown_handle_);
      return;
    }
    callbacks->OnReadRemoteExtendedFeaturesComplete(
        view.GetPageNumber(), view.GetMaximumPageNumber(), view.GetExtendedLmpFeatures());
  }

  void on_link_supervision_timeout_changed(EventView packet) {
    auto view = LinkSupervisionTimeoutChangedView::Create(packet);
    ASSERT_LOG(view.IsValid(), "Link supervision timeout changed packet invalid");
    LOG_INFO("UNIMPLEMENTED called");
  }

  void on_accept_connection_status(Address address, CommandStatusView status) {
    auto accept_status = AcceptConnectionRequestStatusView::Create(status);
    ASSERT(accept_status.IsValid());
    if (status.GetStatus() != ErrorCode::SUCCESS) {
      cancel_connect(address);
    }
  }

  void reject_connection(std::unique_ptr<RejectConnectionRequestBuilder> builder) {
    acl_connection_interface_->EnqueueCommand(
        std::move(builder), handler_->BindOnce(&check_command_status<RejectConnectionRequestStatusView>));
  }

  void OnDeviceBonded(bluetooth::hci::AddressWithType device) override {}
  void OnDeviceUnbonded(bluetooth::hci::AddressWithType device) override {}
  void OnDeviceBondFailed(bluetooth::hci::AddressWithType device, security::PairingFailure status) override {}

  void OnEncryptionStateChanged(EncryptionChangeView encryption_change_view) override {
    if (!encryption_change_view.IsValid()) {
      LOG_ERROR("Invalid packet");
      return;
    } else if (encryption_change_view.GetStatus() != ErrorCode::SUCCESS) {
      auto status = encryption_change_view.GetStatus();
      std::string error_code = ErrorCodeText(status);
      LOG_ERROR("error_code %s", error_code.c_str());
      return;
    }
    uint16_t handle = encryption_change_view.GetConnectionHandle();
    auto callbacks = get_callbacks(handle);
    if (callbacks == nullptr) {
      LOG_WARN("Unknown connection handle 0x%04hx", handle);
      ASSERT(!crash_on_unknown_handle_);
      return;
    }
    EncryptionEnabled enabled = encryption_change_view.GetEncryptionEnabled();
    callbacks->OnEncryptionChange(enabled);
  }

  void set_security_module(security::SecurityModule* security_module) {
    security_manager_ = security_module->GetSecurityManager();
    security_manager_->RegisterCallbackListener(this, handler_);
  }

  uint16_t HACK_get_handle(Address address) {
    for (auto it = acl_connections_.begin(); it != acl_connections_.end(); it++) {
      if (it->second.address_with_type_.GetAddress() == address) {
        return it->first;
      }
    }
    return 0xFFFF;
  }

  void HACK_SetScoDisconnectCallback(std::function<void(uint16_t, uint8_t)> callback) {
    sco_disconnect_callback_ = callback;
  }

  HciLayer* hci_layer_ = nullptr;
  Controller* controller_ = nullptr;
  RoundRobinScheduler* round_robin_scheduler_ = nullptr;
  AclConnectionInterface* acl_connection_interface_ = nullptr;
  os::Handler* handler_ = nullptr;
  ConnectionCallbacks* client_callbacks_ = nullptr;
  os::Handler* client_handler_ = nullptr;
  std::map<uint16_t, acl_connection> acl_connections_;
  Address outgoing_connecting_address_{Address::kEmpty};
  Address incoming_connecting_address_{Address::kEmpty};
  common::Callback<bool(Address, ClassOfDevice)> should_accept_connection_;
  std::queue<std::pair<Address, std::unique_ptr<CreateConnectionBuilder>>> pending_outgoing_connections_;
  std::unique_ptr<RoleChangeView> delayed_role_change_ = nullptr;

  std::unique_ptr<security::SecurityManager> security_manager_;
  bool crash_on_unknown_handle_ = false;

  std::function<void(uint16_t, uint8_t)> sco_disconnect_callback_;
};

}  // namespace acl_manager
}  // namespace hci
}  // namespace bluetooth
