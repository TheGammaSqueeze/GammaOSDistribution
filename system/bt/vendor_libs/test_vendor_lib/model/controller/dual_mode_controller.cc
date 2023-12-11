/*
 * Copyright 2015 The Android Open Source Project
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

#include "dual_mode_controller.h"

#include <memory>

#include <base/files/file_util.h>
#include <base/json/json_reader.h>
#include <base/values.h>

#include "os/log.h"
#include "packet/raw_builder.h"

namespace gd_hci = ::bluetooth::hci;
using gd_hci::ErrorCode;
using gd_hci::LoopbackMode;
using gd_hci::OpCode;
using std::vector;

namespace test_vendor_lib {
constexpr char DualModeController::kControllerPropertiesFile[];
constexpr uint16_t DualModeController::kSecurityManagerNumKeys;
constexpr uint16_t kNumCommandPackets = 0x01;
constexpr uint16_t kLeMaximumAdvertisingDataLength = 256;
constexpr uint16_t kLeMaximumDataLength = 64;
constexpr uint16_t kLeMaximumDataTime = 0x148;

// Device methods.
void DualModeController::Initialize(const std::vector<std::string>& args) {
  if (args.size() < 2) return;

  Address addr{};
  if (Address::FromString(args[1], addr)) {
    properties_.SetAddress(addr);
  } else {
    LOG_ALWAYS_FATAL("Invalid address: %s", args[1].c_str());
  }
};

std::string DualModeController::GetTypeString() const {
  return "Simulated Bluetooth Controller";
}

void DualModeController::IncomingPacket(
    model::packets::LinkLayerPacketView incoming) {
  link_layer_controller_.IncomingPacket(incoming);
}

void DualModeController::TimerTick() {
  link_layer_controller_.TimerTick();
}

void DualModeController::SendCommandCompleteUnknownOpCodeEvent(uint16_t command_opcode) const {
  std::unique_ptr<bluetooth::packet::RawBuilder> raw_builder_ptr =
      std::make_unique<bluetooth::packet::RawBuilder>();
  raw_builder_ptr->AddOctets1(kNumCommandPackets);
  raw_builder_ptr->AddOctets2(command_opcode);
  raw_builder_ptr->AddOctets1(
      static_cast<uint8_t>(ErrorCode::UNKNOWN_HCI_COMMAND));

  auto packet = gd_hci::EventBuilder::Create(
      gd_hci::EventCode::COMMAND_COMPLETE, std::move(raw_builder_ptr));
  send_event_(std::move(packet));
}

DualModeController::DualModeController(const std::string& properties_filename, uint16_t num_keys)
    : Device(properties_filename), security_manager_(num_keys) {
  loopback_mode_ = LoopbackMode::NO_LOOPBACK;

  Address public_address{};
  ASSERT(Address::FromString("3C:5A:B4:04:05:06", public_address));
  properties_.SetAddress(public_address);

  link_layer_controller_.RegisterRemoteChannel(
      [this](std::shared_ptr<model::packets::LinkLayerPacketBuilder> packet,
             Phy::Type phy_type) {
        DualModeController::SendLinkLayerPacket(packet, phy_type);
      });

  std::array<uint8_t, 64> supported_commands;
  for (size_t i = 0; i < 64; i++) {
    supported_commands[i] = 0;
  }

#define SET_HANDLER(name, method)                                  \
  active_hci_commands_[OpCode::name] = [this](CommandView param) { \
    method(std::move(param));                                      \
  };

#define SET_SUPPORTED(name, method)                                          \
  SET_HANDLER(name, method);                                                 \
  {                                                                          \
    uint16_t index = (uint16_t)bluetooth::hci::OpCodeIndex::name;            \
    uint16_t byte_index = index / 10;                                        \
    uint8_t bit = 1 << (index % 10);                                         \
    if (byte_index < 36) {                                                   \
      supported_commands[byte_index] = supported_commands[byte_index] | bit; \
    }                                                                        \
  }

  SET_SUPPORTED(RESET, Reset);
  SET_SUPPORTED(READ_BUFFER_SIZE, ReadBufferSize);
  SET_SUPPORTED(HOST_BUFFER_SIZE, HostBufferSize);
  SET_SUPPORTED(SNIFF_SUBRATING, SniffSubrating);
  SET_SUPPORTED(READ_ENCRYPTION_KEY_SIZE, ReadEncryptionKeySize);
  SET_SUPPORTED(READ_LOCAL_VERSION_INFORMATION, ReadLocalVersionInformation);
  SET_SUPPORTED(READ_BD_ADDR, ReadBdAddr);
  SET_HANDLER(READ_LOCAL_SUPPORTED_COMMANDS, ReadLocalSupportedCommands);
  SET_SUPPORTED(READ_LOCAL_SUPPORTED_FEATURES, ReadLocalSupportedFeatures);
  SET_SUPPORTED(READ_LOCAL_SUPPORTED_CODECS_V1, ReadLocalSupportedCodecs);
  SET_SUPPORTED(READ_LOCAL_EXTENDED_FEATURES, ReadLocalExtendedFeatures);
  SET_SUPPORTED(READ_REMOTE_EXTENDED_FEATURES, ReadRemoteExtendedFeatures);
  SET_SUPPORTED(SWITCH_ROLE, SwitchRole);
  SET_SUPPORTED(READ_REMOTE_SUPPORTED_FEATURES, ReadRemoteSupportedFeatures);
  SET_SUPPORTED(READ_CLOCK_OFFSET, ReadClockOffset);
  SET_SUPPORTED(IO_CAPABILITY_REQUEST_REPLY, IoCapabilityRequestReply);
  SET_SUPPORTED(USER_CONFIRMATION_REQUEST_REPLY, UserConfirmationRequestReply);
  SET_SUPPORTED(USER_CONFIRMATION_REQUEST_NEGATIVE_REPLY,
                UserConfirmationRequestNegativeReply);
  SET_SUPPORTED(USER_PASSKEY_REQUEST_REPLY, UserPasskeyRequestReply);
  SET_SUPPORTED(USER_PASSKEY_REQUEST_NEGATIVE_REPLY,
                UserPasskeyRequestNegativeReply);
  SET_SUPPORTED(PIN_CODE_REQUEST_REPLY, PinCodeRequestReply);
  SET_SUPPORTED(PIN_CODE_REQUEST_NEGATIVE_REPLY, PinCodeRequestNegativeReply);
  SET_SUPPORTED(REMOTE_OOB_DATA_REQUEST_REPLY, RemoteOobDataRequestReply);
  SET_SUPPORTED(REMOTE_OOB_DATA_REQUEST_NEGATIVE_REPLY,
                RemoteOobDataRequestNegativeReply);
  SET_SUPPORTED(IO_CAPABILITY_REQUEST_NEGATIVE_REPLY,
                IoCapabilityRequestNegativeReply);
  SET_SUPPORTED(REMOTE_OOB_EXTENDED_DATA_REQUEST_REPLY,
                RemoteOobExtendedDataRequestReply);
  SET_SUPPORTED(READ_INQUIRY_RESPONSE_TRANSMIT_POWER_LEVEL,
                ReadInquiryResponseTransmitPowerLevel);
  SET_SUPPORTED(SEND_KEYPRESS_NOTIFICATION, SendKeypressNotification);
  SET_HANDLER(SET_EVENT_MASK_PAGE_2, SetEventMaskPage2);
  SET_SUPPORTED(READ_LOCAL_OOB_DATA, ReadLocalOobData);
  SET_SUPPORTED(READ_LOCAL_OOB_EXTENDED_DATA, ReadLocalOobExtendedData);
  SET_SUPPORTED(WRITE_SIMPLE_PAIRING_MODE, WriteSimplePairingMode);
  SET_SUPPORTED(WRITE_LE_HOST_SUPPORT, WriteLeHostSupport);
  SET_SUPPORTED(WRITE_SECURE_CONNECTIONS_HOST_SUPPORT,
                WriteSecureConnectionsHostSupport);
  SET_SUPPORTED(SET_EVENT_MASK, SetEventMask);
  SET_SUPPORTED(READ_INQUIRY_MODE, ReadInquiryMode);
  SET_SUPPORTED(WRITE_INQUIRY_MODE, WriteInquiryMode);
  SET_SUPPORTED(READ_PAGE_SCAN_TYPE, ReadPageScanType);
  SET_SUPPORTED(WRITE_PAGE_SCAN_TYPE, WritePageScanType);
  SET_SUPPORTED(WRITE_INQUIRY_SCAN_TYPE, WriteInquiryScanType);
  SET_SUPPORTED(READ_INQUIRY_SCAN_TYPE, ReadInquiryScanType);
  SET_SUPPORTED(AUTHENTICATION_REQUESTED, AuthenticationRequested);
  SET_SUPPORTED(SET_CONNECTION_ENCRYPTION, SetConnectionEncryption);
  SET_SUPPORTED(CHANGE_CONNECTION_LINK_KEY, ChangeConnectionLinkKey);
  SET_SUPPORTED(CENTRAL_LINK_KEY, CentralLinkKey);
  SET_SUPPORTED(WRITE_AUTHENTICATION_ENABLE, WriteAuthenticationEnable);
  SET_SUPPORTED(READ_AUTHENTICATION_ENABLE, ReadAuthenticationEnable);
  SET_SUPPORTED(WRITE_CLASS_OF_DEVICE, WriteClassOfDevice);
  SET_SUPPORTED(READ_PAGE_TIMEOUT, ReadPageTimeout);
  SET_SUPPORTED(WRITE_PAGE_TIMEOUT, WritePageTimeout);
  SET_SUPPORTED(WRITE_LINK_SUPERVISION_TIMEOUT, WriteLinkSupervisionTimeout);
  SET_SUPPORTED(HOLD_MODE, HoldMode);
  SET_SUPPORTED(SNIFF_MODE, SniffMode);
  SET_SUPPORTED(EXIT_SNIFF_MODE, ExitSniffMode);
  SET_SUPPORTED(QOS_SETUP, QosSetup);
  SET_SUPPORTED(READ_DEFAULT_LINK_POLICY_SETTINGS,
                ReadDefaultLinkPolicySettings);
  SET_SUPPORTED(WRITE_DEFAULT_LINK_POLICY_SETTINGS,
                WriteDefaultLinkPolicySettings);
  SET_SUPPORTED(FLOW_SPECIFICATION, FlowSpecification);
  SET_SUPPORTED(WRITE_LINK_POLICY_SETTINGS, WriteLinkPolicySettings);
  SET_SUPPORTED(CHANGE_CONNECTION_PACKET_TYPE, ChangeConnectionPacketType);
  SET_SUPPORTED(WRITE_LOCAL_NAME, WriteLocalName);
  SET_SUPPORTED(READ_LOCAL_NAME, ReadLocalName);
  SET_SUPPORTED(WRITE_EXTENDED_INQUIRY_RESPONSE, WriteExtendedInquiryResponse);
  SET_SUPPORTED(REFRESH_ENCRYPTION_KEY, RefreshEncryptionKey);
  SET_SUPPORTED(WRITE_VOICE_SETTING, WriteVoiceSetting);
  SET_SUPPORTED(READ_NUMBER_OF_SUPPORTED_IAC, ReadNumberOfSupportedIac);
  SET_SUPPORTED(READ_CURRENT_IAC_LAP, ReadCurrentIacLap);
  SET_SUPPORTED(WRITE_CURRENT_IAC_LAP, WriteCurrentIacLap);
  SET_SUPPORTED(READ_PAGE_SCAN_ACTIVITY, ReadPageScanActivity);
  SET_SUPPORTED(WRITE_PAGE_SCAN_ACTIVITY, WritePageScanActivity);
  SET_SUPPORTED(READ_INQUIRY_SCAN_ACTIVITY, ReadInquiryScanActivity);
  SET_SUPPORTED(WRITE_INQUIRY_SCAN_ACTIVITY, WriteInquiryScanActivity);
  SET_SUPPORTED(READ_SCAN_ENABLE, ReadScanEnable);
  SET_SUPPORTED(WRITE_SCAN_ENABLE, WriteScanEnable);
  SET_SUPPORTED(SET_EVENT_FILTER, SetEventFilter);
  SET_SUPPORTED(INQUIRY, Inquiry);
  SET_SUPPORTED(INQUIRY_CANCEL, InquiryCancel);
  SET_SUPPORTED(ACCEPT_CONNECTION_REQUEST, AcceptConnectionRequest);
  SET_SUPPORTED(REJECT_CONNECTION_REQUEST, RejectConnectionRequest);
  SET_SUPPORTED(LINK_KEY_REQUEST_REPLY, LinkKeyRequestReply);
  SET_SUPPORTED(LINK_KEY_REQUEST_NEGATIVE_REPLY, LinkKeyRequestNegativeReply);
  SET_SUPPORTED(DELETE_STORED_LINK_KEY, DeleteStoredLinkKey);
  SET_SUPPORTED(REMOTE_NAME_REQUEST, RemoteNameRequest);
  SET_SUPPORTED(LE_SET_EVENT_MASK, LeSetEventMask);
  SET_SUPPORTED(LE_READ_BUFFER_SIZE_V1, LeReadBufferSize);
  SET_SUPPORTED(LE_READ_LOCAL_SUPPORTED_FEATURES, LeReadLocalSupportedFeatures);
  SET_SUPPORTED(LE_SET_RANDOM_ADDRESS, LeSetRandomAddress);
  SET_SUPPORTED(LE_SET_ADVERTISING_PARAMETERS, LeSetAdvertisingParameters);
  SET_SUPPORTED(LE_READ_ADVERTISING_PHYSICAL_CHANNEL_TX_POWER,
                LeReadAdvertisingPhysicalChannelTxPower);
  SET_SUPPORTED(LE_SET_ADVERTISING_DATA, LeSetAdvertisingData);
  SET_SUPPORTED(LE_SET_SCAN_RESPONSE_DATA, LeSetScanResponseData);
  SET_SUPPORTED(LE_SET_ADVERTISING_ENABLE, LeSetAdvertisingEnable);
  SET_SUPPORTED(LE_SET_SCAN_PARAMETERS, LeSetScanParameters);
  SET_SUPPORTED(LE_SET_SCAN_ENABLE, LeSetScanEnable);
  SET_SUPPORTED(LE_CREATE_CONNECTION, LeCreateConnection);
  SET_SUPPORTED(CREATE_CONNECTION, CreateConnection);
  SET_SUPPORTED(CREATE_CONNECTION_CANCEL, CreateConnectionCancel);
  SET_SUPPORTED(DISCONNECT, Disconnect);
  SET_SUPPORTED(LE_CREATE_CONNECTION_CANCEL, LeConnectionCancel);
  SET_SUPPORTED(LE_READ_CONNECT_LIST_SIZE, LeReadConnectListSize);
  SET_SUPPORTED(LE_CLEAR_CONNECT_LIST, LeClearConnectList);
  SET_SUPPORTED(LE_ADD_DEVICE_TO_CONNECT_LIST, LeAddDeviceToConnectList);
  SET_SUPPORTED(LE_REMOVE_DEVICE_FROM_CONNECT_LIST,
                LeRemoveDeviceFromConnectList);
  SET_SUPPORTED(LE_RAND, LeRand);
  SET_SUPPORTED(LE_READ_SUPPORTED_STATES, LeReadSupportedStates);
  SET_HANDLER(LE_GET_VENDOR_CAPABILITIES, LeVendorCap);
  SET_HANDLER(LE_MULTI_ADVT, LeVendorMultiAdv);
  SET_HANDLER(LE_ADV_FILTER, LeAdvertisingFilter);
  SET_HANDLER(LE_ENERGY_INFO, LeEnergyInfo);
  SET_SUPPORTED(LE_SET_EXTENDED_ADVERTISING_RANDOM_ADDRESS,
                LeSetExtendedAdvertisingRandomAddress);
  SET_SUPPORTED(LE_SET_EXTENDED_ADVERTISING_PARAMETERS,
                LeSetExtendedAdvertisingParameters);
  SET_SUPPORTED(LE_SET_EXTENDED_ADVERTISING_DATA, LeSetExtendedAdvertisingData);
  SET_SUPPORTED(LE_SET_EXTENDED_ADVERTISING_SCAN_RESPONSE,
                LeSetExtendedAdvertisingScanResponse);
  SET_SUPPORTED(LE_SET_EXTENDED_ADVERTISING_ENABLE,
                LeSetExtendedAdvertisingEnable);
  SET_SUPPORTED(LE_READ_MAXIMUM_ADVERTISING_DATA_LENGTH,
                LeReadMaximumAdvertisingDataLength);
  SET_SUPPORTED(LE_READ_NUMBER_OF_SUPPORTED_ADVERTISING_SETS,
                LeReadNumberOfSupportedAdvertisingSets);
  SET_SUPPORTED(LE_REMOVE_ADVERTISING_SET, LeRemoveAdvertisingSet);
  SET_SUPPORTED(LE_CLEAR_ADVERTISING_SETS, LeClearAdvertisingSets);
  SET_SUPPORTED(LE_READ_REMOTE_FEATURES, LeReadRemoteFeatures);
  SET_SUPPORTED(READ_REMOTE_VERSION_INFORMATION, ReadRemoteVersionInformation);
  SET_SUPPORTED(LE_CONNECTION_UPDATE, LeConnectionUpdate);
  SET_SUPPORTED(LE_START_ENCRYPTION, LeStartEncryption);
  SET_SUPPORTED(LE_LONG_TERM_KEY_REQUEST_REPLY, LeLongTermKeyRequestReply);
  SET_SUPPORTED(LE_LONG_TERM_KEY_REQUEST_NEGATIVE_REPLY,
                LeLongTermKeyRequestNegativeReply);
  SET_SUPPORTED(LE_ADD_DEVICE_TO_RESOLVING_LIST, LeAddDeviceToResolvingList);
  SET_SUPPORTED(LE_REMOVE_DEVICE_FROM_RESOLVING_LIST,
                LeRemoveDeviceFromResolvingList);
  SET_SUPPORTED(LE_CLEAR_RESOLVING_LIST, LeClearResolvingList);
  SET_SUPPORTED(LE_READ_RESOLVING_LIST_SIZE, LeReadResolvingListSize);
  SET_SUPPORTED(LE_READ_MAXIMUM_DATA_LENGTH, LeReadMaximumDataLength);

  SET_SUPPORTED(LE_SET_EXTENDED_SCAN_PARAMETERS, LeSetExtendedScanParameters);
  SET_SUPPORTED(LE_SET_EXTENDED_SCAN_ENABLE, LeSetExtendedScanEnable);
  SET_SUPPORTED(LE_EXTENDED_CREATE_CONNECTION, LeExtendedCreateConnection);
  SET_SUPPORTED(LE_SET_PRIVACY_MODE, LeSetPrivacyMode);
  SET_SUPPORTED(LE_READ_SUGGESTED_DEFAULT_DATA_LENGTH,
                LeReadSuggestedDefaultDataLength);
  // ISO Commands
  SET_SUPPORTED(LE_READ_ISO_TX_SYNC, LeReadIsoTxSync);
  SET_SUPPORTED(LE_SET_CIG_PARAMETERS, LeSetCigParameters);
  SET_SUPPORTED(LE_CREATE_CIS, LeCreateCis);
  SET_SUPPORTED(LE_REMOVE_CIG, LeRemoveCig);
  SET_SUPPORTED(LE_ACCEPT_CIS_REQUEST, LeAcceptCisRequest);
  SET_SUPPORTED(LE_REJECT_CIS_REQUEST, LeRejectCisRequest);
  SET_SUPPORTED(LE_CREATE_BIG, LeCreateBig);
  SET_SUPPORTED(LE_TERMINATE_BIG, LeTerminateBig);
  SET_SUPPORTED(LE_BIG_CREATE_SYNC, LeBigCreateSync);
  SET_SUPPORTED(LE_BIG_TERMINATE_SYNC, LeBigTerminateSync);
  SET_SUPPORTED(LE_REQUEST_PEER_SCA, LeRequestPeerSca);
  SET_SUPPORTED(LE_SETUP_ISO_DATA_PATH, LeSetupIsoDataPath);
  SET_SUPPORTED(LE_REMOVE_ISO_DATA_PATH, LeRemoveIsoDataPath);
  // Testing Commands
  SET_SUPPORTED(READ_LOOPBACK_MODE, ReadLoopbackMode);
  SET_SUPPORTED(WRITE_LOOPBACK_MODE, WriteLoopbackMode);

  SET_SUPPORTED(READ_CLASS_OF_DEVICE, ReadClassOfDevice);
  SET_SUPPORTED(READ_VOICE_SETTING, ReadVoiceSetting);
  SET_SUPPORTED(READ_CONNECTION_ACCEPT_TIMEOUT, ReadConnectionAcceptTimeout);
  SET_SUPPORTED(WRITE_CONNECTION_ACCEPT_TIMEOUT, WriteConnectionAcceptTimeout);
  SET_SUPPORTED(LE_SET_ADDRESS_RESOLUTION_ENABLE, LeSetAddressResolutionEnable);
  SET_SUPPORTED(LE_SET_RESOLVABLE_PRIVATE_ADDRESS_TIMEOUT, LeSetResovalablePrivateAddressTimeout);
#undef SET_HANDLER
#undef SET_SUPPORTED
  properties_.SetSupportedCommands(supported_commands);
}

void DualModeController::SniffSubrating(CommandView command) {
  auto command_view = gd_hci::SniffSubratingView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  send_event_(gd_hci::SniffSubratingCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS,
      command_view.GetConnectionHandle()));
}

void DualModeController::RegisterTaskScheduler(
    std::function<AsyncTaskId(std::chrono::milliseconds, const TaskCallback&)> oneshot_scheduler) {
  link_layer_controller_.RegisterTaskScheduler(oneshot_scheduler);
}

void DualModeController::RegisterPeriodicTaskScheduler(
    std::function<AsyncTaskId(std::chrono::milliseconds, std::chrono::milliseconds, const TaskCallback&)>
        periodic_scheduler) {
  link_layer_controller_.RegisterPeriodicTaskScheduler(periodic_scheduler);
}

void DualModeController::RegisterTaskCancel(std::function<void(AsyncTaskId)> task_cancel) {
  link_layer_controller_.RegisterTaskCancel(task_cancel);
}

void DualModeController::HandleAcl(std::shared_ptr<std::vector<uint8_t>> packet) {
  bluetooth::hci::PacketView<bluetooth::hci::kLittleEndian> raw_packet(packet);
  auto acl_packet = bluetooth::hci::AclView::Create(raw_packet);
  ASSERT(acl_packet.IsValid());
  if (loopback_mode_ == LoopbackMode::ENABLE_LOCAL) {
    uint16_t handle = acl_packet.GetHandle();

    std::vector<bluetooth::hci::CompletedPackets> completed_packets;
    bluetooth::hci::CompletedPackets cp;
    cp.connection_handle_ = handle;
    cp.host_num_of_completed_packets_ = kNumCommandPackets;
    completed_packets.push_back(cp);
    send_event_(bluetooth::hci::NumberOfCompletedPacketsBuilder::Create(
        completed_packets));
    return;
  }

  link_layer_controller_.SendAclToRemote(acl_packet);
}

void DualModeController::HandleSco(std::shared_ptr<std::vector<uint8_t>> packet) {
  bluetooth::hci::PacketView<bluetooth::hci::kLittleEndian> raw_packet(packet);
  auto sco_packet = bluetooth::hci::ScoView::Create(raw_packet);
  if (loopback_mode_ == LoopbackMode::ENABLE_LOCAL) {
    uint16_t handle = sco_packet.GetHandle();
    auto sco_builder = bluetooth::hci::ScoBuilder::Create(
        handle, sco_packet.GetPacketStatusFlag(), sco_packet.GetData());
    send_sco_(std::move(sco_builder));
    std::vector<bluetooth::hci::CompletedPackets> completed_packets;
    bluetooth::hci::CompletedPackets cp;
    cp.connection_handle_ = handle;
    cp.host_num_of_completed_packets_ = kNumCommandPackets;
    completed_packets.push_back(cp);
    send_event_(bluetooth::hci::NumberOfCompletedPacketsBuilder::Create(
        completed_packets));
    return;
  }
}

void DualModeController::HandleIso(
    std::shared_ptr<std::vector<uint8_t>> packet) {
  bluetooth::hci::PacketView<bluetooth::hci::kLittleEndian> raw_packet(packet);
  auto iso = bluetooth::hci::IsoView::Create(raw_packet);
  ASSERT(iso.IsValid());
  link_layer_controller_.HandleIso(iso);
}

void DualModeController::HandleCommand(std::shared_ptr<std::vector<uint8_t>> packet) {
  bluetooth::hci::PacketView<bluetooth::hci::kLittleEndian> raw_packet(packet);
  auto command_packet = bluetooth::hci::CommandView::Create(raw_packet);
  ASSERT(command_packet.IsValid());
  auto op = command_packet.GetOpCode();

  if (loopback_mode_ == LoopbackMode::ENABLE_LOCAL &&
      // Loopback exceptions.
      op != OpCode::RESET &&
      op != OpCode::SET_CONTROLLER_TO_HOST_FLOW_CONTROL &&
      op != OpCode::HOST_BUFFER_SIZE &&
      op != OpCode::HOST_NUM_COMPLETED_PACKETS &&
      op != OpCode::READ_BUFFER_SIZE && op != OpCode::READ_LOOPBACK_MODE &&
      op != OpCode::WRITE_LOOPBACK_MODE) {
    std::unique_ptr<bluetooth::packet::RawBuilder> raw_builder_ptr =
        std::make_unique<bluetooth::packet::RawBuilder>(255);
    raw_builder_ptr->AddOctets(*packet);
    send_event_(bluetooth::hci::LoopbackCommandBuilder::Create(
        std::move(raw_builder_ptr)));
  } else if (active_hci_commands_.count(op) > 0) {
    active_hci_commands_[op](command_packet);
  } else {
    uint16_t opcode = static_cast<uint16_t>(op);
    SendCommandCompleteUnknownOpCodeEvent(opcode);
    LOG_INFO("Unknown command, opcode: 0x%04X, OGF: 0x%04X, OCF: 0x%04X",
             opcode, (opcode & 0xFC00) >> 10, opcode & 0x03FF);
  }
}

void DualModeController::RegisterEventChannel(
    const std::function<void(std::shared_ptr<std::vector<uint8_t>>)>& callback) {
  send_event_ =
      [callback](std::shared_ptr<bluetooth::hci::EventBuilder> event) {
        auto bytes = std::make_shared<std::vector<uint8_t>>();
        bluetooth::packet::BitInserter bit_inserter(*bytes);
        bytes->reserve(event->size());
        event->Serialize(bit_inserter);
        callback(std::move(bytes));
      };
  link_layer_controller_.RegisterEventChannel(send_event_);
}

void DualModeController::RegisterAclChannel(
    const std::function<void(std::shared_ptr<std::vector<uint8_t>>)>& callback) {
  send_acl_ = [callback](std::shared_ptr<bluetooth::hci::AclBuilder> acl_data) {
    auto bytes = std::make_shared<std::vector<uint8_t>>();
    bluetooth::packet::BitInserter bit_inserter(*bytes);
    bytes->reserve(acl_data->size());
    acl_data->Serialize(bit_inserter);
    callback(std::move(bytes));
  };
  link_layer_controller_.RegisterAclChannel(send_acl_);
}

void DualModeController::RegisterScoChannel(
    const std::function<void(std::shared_ptr<std::vector<uint8_t>>)>& callback) {
  send_sco_ = [callback](std::shared_ptr<bluetooth::hci::ScoBuilder> sco_data) {
    auto bytes = std::make_shared<std::vector<uint8_t>>();
    bluetooth::packet::BitInserter bit_inserter(*bytes);
    bytes->reserve(sco_data->size());
    sco_data->Serialize(bit_inserter);
    callback(std::move(bytes));
  };
  link_layer_controller_.RegisterScoChannel(send_sco_);
}

void DualModeController::RegisterIsoChannel(
    const std::function<void(std::shared_ptr<std::vector<uint8_t>>)>&
        callback) {
  send_iso_ = [callback](std::shared_ptr<bluetooth::hci::IsoBuilder> iso_data) {
    auto bytes = std::make_shared<std::vector<uint8_t>>();
    bluetooth::packet::BitInserter bit_inserter(*bytes);
    bytes->reserve(iso_data->size());
    iso_data->Serialize(bit_inserter);
    callback(std::move(bytes));
  };
  link_layer_controller_.RegisterIsoChannel(send_iso_);
}

void DualModeController::Reset(CommandView command) {
  auto command_view = gd_hci::ResetView::Create(command);
  ASSERT(command_view.IsValid());
  link_layer_controller_.Reset();
  if (loopback_mode_ == LoopbackMode::ENABLE_LOCAL) {
    loopback_mode_ = LoopbackMode::NO_LOOPBACK;
  }

  send_event_(bluetooth::hci::ResetCompleteBuilder::Create(kNumCommandPackets,
                                                           ErrorCode::SUCCESS));
}

void DualModeController::ReadBufferSize(CommandView command) {
  auto command_view = gd_hci::ReadBufferSizeView::Create(command);
  ASSERT(command_view.IsValid());

  auto packet = bluetooth::hci::ReadBufferSizeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS,
      properties_.GetAclDataPacketSize(),
      properties_.GetSynchronousDataPacketSize(),
      properties_.GetTotalNumAclDataPackets(),
      properties_.GetTotalNumSynchronousDataPackets());
  send_event_(std::move(packet));
}

void DualModeController::ReadEncryptionKeySize(CommandView command) {
  auto command_view = gd_hci::ReadEncryptionKeySizeView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  auto packet = bluetooth::hci::ReadEncryptionKeySizeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS,
      command_view.GetConnectionHandle(), properties_.GetEncryptionKeySize());
  send_event_(std::move(packet));
}

void DualModeController::HostBufferSize(CommandView command) {
  auto command_view = gd_hci::HostBufferSizeView::Create(command);
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::HostBufferSizeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::ReadLocalVersionInformation(CommandView command) {
  auto command_view = gd_hci::ReadLocalVersionInformationView::Create(command);
  ASSERT(command_view.IsValid());

  bluetooth::hci::LocalVersionInformation local_version_information;
  local_version_information.hci_version_ =
      static_cast<bluetooth::hci::HciVersion>(properties_.GetVersion());
  local_version_information.hci_revision_ = properties_.GetRevision();
  local_version_information.lmp_version_ =
      static_cast<bluetooth::hci::LmpVersion>(properties_.GetLmpPalVersion());
  local_version_information.manufacturer_name_ =
      properties_.GetManufacturerName();
  local_version_information.lmp_subversion_ = properties_.GetLmpPalSubversion();
  auto packet =
      bluetooth::hci::ReadLocalVersionInformationCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS, local_version_information);
  send_event_(std::move(packet));
}

void DualModeController::ReadRemoteVersionInformation(CommandView command) {
  auto command_view = gd_hci::ReadRemoteVersionInformationView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  auto status = link_layer_controller_.SendCommandToRemoteByHandle(
      OpCode::READ_REMOTE_VERSION_INFORMATION, command.GetPayload(),
      command_view.GetConnectionHandle());

  auto packet =
      bluetooth::hci::ReadRemoteVersionInformationStatusBuilder::Create(
          status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::ReadBdAddr(CommandView command) {
  auto command_view = gd_hci::ReadBdAddrView::Create(command);
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::ReadBdAddrCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, properties_.GetAddress());
  send_event_(std::move(packet));
}

void DualModeController::ReadLocalSupportedCommands(CommandView command) {
  auto command_view = gd_hci::ReadLocalSupportedCommandsView::Create(command);
  ASSERT(command_view.IsValid());

  std::array<uint8_t, 64> supported_commands{};
  supported_commands.fill(0x00);
  size_t len = properties_.GetSupportedCommands().size();
  if (len > 64) {
    len = 64;
  }
  std::copy_n(properties_.GetSupportedCommands().begin(), len,
              supported_commands.begin());

  auto packet =
      bluetooth::hci::ReadLocalSupportedCommandsCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS, supported_commands);
  send_event_(std::move(packet));
}

void DualModeController::ReadLocalSupportedFeatures(CommandView command) {
  auto command_view = gd_hci::ReadLocalSupportedFeaturesView::Create(command);
  ASSERT(command_view.IsValid());
  auto packet =
      bluetooth::hci::ReadLocalSupportedFeaturesCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS,
          properties_.GetSupportedFeatures());
  send_event_(std::move(packet));
}

void DualModeController::ReadLocalSupportedCodecs(CommandView command) {
  auto command_view = gd_hci::ReadLocalSupportedCodecsV1View::Create(command);
  ASSERT(command_view.IsValid());
  auto packet =
      bluetooth::hci::ReadLocalSupportedCodecsV1CompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS,
          properties_.GetSupportedCodecs(),
          properties_.GetVendorSpecificCodecs());
  send_event_(std::move(packet));
}

void DualModeController::ReadLocalExtendedFeatures(CommandView command) {
  auto command_view = gd_hci::ReadLocalExtendedFeaturesView::Create(command);
  ASSERT(command_view.IsValid());
  uint8_t page_number = command_view.GetPageNumber();

  auto pakcet =
      bluetooth::hci::ReadLocalExtendedFeaturesCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS, page_number,
          properties_.GetExtendedFeaturesMaximumPageNumber(),
          properties_.GetExtendedFeatures(page_number));
  send_event_(std::move(pakcet));
}

void DualModeController::ReadRemoteExtendedFeatures(CommandView command) {
  auto command_view = gd_hci::ReadRemoteExtendedFeaturesView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  auto status = link_layer_controller_.SendCommandToRemoteByHandle(
      OpCode::READ_REMOTE_EXTENDED_FEATURES, command_view.GetPayload(),
      command_view.GetConnectionHandle());

  auto packet = bluetooth::hci::ReadRemoteExtendedFeaturesStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::SwitchRole(CommandView command) {
  auto command_view = gd_hci::SwitchRoleView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  auto status = link_layer_controller_.SwitchRole(
      command_view.GetBdAddr(), static_cast<uint8_t>(command_view.GetRole()));

  auto packet = bluetooth::hci::SwitchRoleStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::ReadRemoteSupportedFeatures(CommandView command) {
  auto command_view = gd_hci::ReadRemoteSupportedFeaturesView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  auto status = link_layer_controller_.SendCommandToRemoteByHandle(
      OpCode::READ_REMOTE_SUPPORTED_FEATURES, command_view.GetPayload(),
      command_view.GetConnectionHandle());

  auto packet =
      bluetooth::hci::ReadRemoteSupportedFeaturesStatusBuilder::Create(
          status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::ReadClockOffset(CommandView command) {
  auto command_view = gd_hci::ReadClockOffsetView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  uint16_t handle = command_view.GetConnectionHandle();

  auto status = link_layer_controller_.SendCommandToRemoteByHandle(
      OpCode::READ_CLOCK_OFFSET, command_view.GetPayload(), handle);

  auto packet = bluetooth::hci::ReadClockOffsetStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::IoCapabilityRequestReply(CommandView command) {
  auto command_view = gd_hci::IoCapabilityRequestReplyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  Address peer = command_view.GetBdAddr();
  uint8_t io_capability = static_cast<uint8_t>(command_view.GetIoCapability());
  uint8_t oob_data_present_flag =
      static_cast<uint8_t>(command_view.GetOobPresent());
  uint8_t authentication_requirements =
      static_cast<uint8_t>(command_view.GetAuthenticationRequirements());

  auto status = link_layer_controller_.IoCapabilityRequestReply(
      peer, io_capability, oob_data_present_flag, authentication_requirements);
  auto packet = bluetooth::hci::IoCapabilityRequestReplyCompleteBuilder::Create(
      kNumCommandPackets, status, peer);

  send_event_(std::move(packet));
}

void DualModeController::UserConfirmationRequestReply(CommandView command) {
  auto command_view = gd_hci::UserConfirmationRequestReplyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  Address peer = command_view.GetBdAddr();

  auto status = link_layer_controller_.UserConfirmationRequestReply(peer);
  auto packet =
      bluetooth::hci::UserConfirmationRequestReplyCompleteBuilder::Create(
          kNumCommandPackets, status, peer);

  send_event_(std::move(packet));
}

void DualModeController::UserConfirmationRequestNegativeReply(
    CommandView command) {
  auto command_view = gd_hci::UserConfirmationRequestNegativeReplyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  Address peer = command_view.GetBdAddr();

  auto status =
      link_layer_controller_.UserConfirmationRequestNegativeReply(peer);
  auto packet =
      bluetooth::hci::UserConfirmationRequestNegativeReplyCompleteBuilder::
          Create(kNumCommandPackets, status, peer);

  send_event_(std::move(packet));
}

void DualModeController::PinCodeRequestReply(CommandView command) {
  auto command_view = gd_hci::PinCodeRequestReplyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());
  LOG_INFO("%s", properties_.GetAddress().ToString().c_str());

  Address peer = command_view.GetBdAddr();
  uint8_t pin_length = command_view.GetPinCodeLength();
  std::array<uint8_t, 16> pin = command_view.GetPinCode();
  ErrorCode status = ErrorCode::INVALID_HCI_COMMAND_PARAMETERS;
  if (pin_length >= 1 && pin_length <= 0x10) {
    status = link_layer_controller_.PinCodeRequestReply(
        peer, std::vector<uint8_t>(pin.begin(), pin.begin() + pin_length));
  }

  send_event_(bluetooth::hci::PinCodeRequestReplyCompleteBuilder::Create(
      kNumCommandPackets, status, peer));
}

void DualModeController::PinCodeRequestNegativeReply(CommandView command) {
  auto command_view = gd_hci::PinCodeRequestNegativeReplyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());
  LOG_INFO("%s", properties_.GetAddress().ToString().c_str());

  Address peer = command_view.GetBdAddr();

  auto status = link_layer_controller_.PinCodeRequestNegativeReply(peer);
  auto packet =
      bluetooth::hci::PinCodeRequestNegativeReplyCompleteBuilder::Create(
          kNumCommandPackets, status, peer);

  send_event_(std::move(packet));
}

void DualModeController::UserPasskeyRequestReply(CommandView command) {
  auto command_view = gd_hci::UserPasskeyRequestReplyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  Address peer = command_view.GetBdAddr();
  uint32_t numeric_value = command_view.GetNumericValue();

  auto status =
      link_layer_controller_.UserPasskeyRequestReply(peer, numeric_value);
  auto packet = bluetooth::hci::UserPasskeyRequestReplyCompleteBuilder::Create(
      kNumCommandPackets, status, peer);

  send_event_(std::move(packet));
}

void DualModeController::UserPasskeyRequestNegativeReply(CommandView command) {
  auto command_view = gd_hci::UserPasskeyRequestNegativeReplyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  Address peer = command_view.GetBdAddr();

  auto status = link_layer_controller_.UserPasskeyRequestNegativeReply(peer);
  auto packet =
      bluetooth::hci::UserPasskeyRequestNegativeReplyCompleteBuilder::Create(
          kNumCommandPackets, status, peer);

  send_event_(std::move(packet));
}

void DualModeController::RemoteOobDataRequestReply(CommandView command) {
  auto command_view = gd_hci::RemoteOobDataRequestReplyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  Address peer = command_view.GetBdAddr();

  auto status = link_layer_controller_.RemoteOobDataRequestReply(
      peer, command_view.GetC(), command_view.GetR());

  send_event_(bluetooth::hci::RemoteOobDataRequestReplyCompleteBuilder::Create(
      kNumCommandPackets, status, peer));
}

void DualModeController::RemoteOobDataRequestNegativeReply(
    CommandView command) {
  auto command_view = gd_hci::RemoteOobDataRequestNegativeReplyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  Address peer = command_view.GetBdAddr();

  auto status = link_layer_controller_.RemoteOobDataRequestNegativeReply(peer);
  auto packet =
      bluetooth::hci::RemoteOobDataRequestNegativeReplyCompleteBuilder::Create(
          kNumCommandPackets, status, peer);

  send_event_(std::move(packet));
}

void DualModeController::IoCapabilityRequestNegativeReply(CommandView command) {
  auto command_view = gd_hci::IoCapabilityRequestNegativeReplyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  Address peer = command_view.GetBdAddr();
  ErrorCode reason = command_view.GetReason();

  auto status =
      link_layer_controller_.IoCapabilityRequestNegativeReply(peer, reason);
  auto packet =
      bluetooth::hci::IoCapabilityRequestNegativeReplyCompleteBuilder::Create(
          kNumCommandPackets, status, peer);

  send_event_(std::move(packet));
}

void DualModeController::RemoteOobExtendedDataRequestReply(
    CommandView command) {
  auto command_view = gd_hci::RemoteOobExtendedDataRequestReplyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  Address peer = command_view.GetBdAddr();

  auto status = link_layer_controller_.RemoteOobExtendedDataRequestReply(
      peer, command_view.GetC192(), command_view.GetR192(),
      command_view.GetC256(), command_view.GetR256());

  send_event_(
      bluetooth::hci::RemoteOobExtendedDataRequestReplyCompleteBuilder::Create(
          kNumCommandPackets, status, peer));
}

void DualModeController::ReadInquiryResponseTransmitPowerLevel(
    CommandView command) {
  auto command_view = gd_hci::ReadInquiryResponseTransmitPowerLevelView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());

  uint8_t tx_power = 20;  // maximum
  auto packet =
      bluetooth::hci::ReadInquiryResponseTransmitPowerLevelCompleteBuilder::
          Create(kNumCommandPackets, ErrorCode::SUCCESS, tx_power);
  send_event_(std::move(packet));
}

void DualModeController::SendKeypressNotification(CommandView command) {
  auto command_view = gd_hci::SendKeypressNotificationView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  auto peer = command_view.GetBdAddr();

  auto status = link_layer_controller_.SendKeypressNotification(
      peer, command_view.GetNotificationType());
  send_event_(bluetooth::hci::SendKeypressNotificationCompleteBuilder::Create(
      kNumCommandPackets, status, peer));
}

void DualModeController::SetEventMaskPage2(CommandView command) {
  auto payload =
      std::make_unique<bluetooth::packet::RawBuilder>(std::vector<uint8_t>(
          {static_cast<uint8_t>(bluetooth::hci::ErrorCode::SUCCESS)}));
  send_event_(bluetooth::hci::CommandCompleteBuilder::Create(
      kNumCommandPackets, command.GetOpCode(), std::move(payload)));
}

void DualModeController::ReadLocalOobData(CommandView command) {
  auto command_view = gd_hci::ReadLocalOobDataView::Create(
      gd_hci::SecurityCommandView::Create(command));
  link_layer_controller_.ReadLocalOobData();
}

void DualModeController::ReadLocalOobExtendedData(CommandView command) {
  auto command_view = gd_hci::ReadLocalOobExtendedDataView::Create(
      gd_hci::SecurityCommandView::Create(command));
  link_layer_controller_.ReadLocalOobExtendedData();
}

void DualModeController::WriteSimplePairingMode(CommandView command) {
  auto command_view = gd_hci::WriteSimplePairingModeView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  auto enabled = command_view.GetSimplePairingMode() == gd_hci::Enable::ENABLED;
  properties_.SetSecureSimplePairingSupport(enabled);
  auto packet = bluetooth::hci::WriteSimplePairingModeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::ChangeConnectionPacketType(CommandView command) {
  auto command_view = gd_hci::ChangeConnectionPacketTypeView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  uint16_t handle = command_view.GetConnectionHandle();
  uint16_t packet_type = static_cast<uint16_t>(command_view.GetPacketType());

  auto status =
      link_layer_controller_.ChangeConnectionPacketType(handle, packet_type);

  auto packet = bluetooth::hci::ChangeConnectionPacketTypeStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::WriteLeHostSupport(CommandView command) {
  auto command_view = gd_hci::WriteLeHostSupportView::Create(command);
  ASSERT(command_view.IsValid());
  auto le_support =
      command_view.GetLeSupportedHost() == gd_hci::Enable::ENABLED;
  properties_.SetLeHostSupport(le_support);
  auto packet = bluetooth::hci::WriteLeHostSupportCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::WriteSecureConnectionsHostSupport(
    CommandView command) {
  auto command_view = gd_hci::WriteSecureConnectionsHostSupportView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());
  properties_.SetSecureConnections(
      command_view.GetSecureConnectionsHostSupport() ==
      bluetooth::hci::Enable::ENABLED);
  auto packet =
      bluetooth::hci::WriteSecureConnectionsHostSupportCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::SetEventMask(CommandView command) {
  auto command_view = gd_hci::SetEventMaskView::Create(command);
  ASSERT(command_view.IsValid());
  properties_.SetEventMask(command_view.GetEventMask());
  auto packet = bluetooth::hci::SetEventMaskCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::ReadInquiryMode(CommandView command) {
  auto command_view = gd_hci::ReadInquiryModeView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  gd_hci::InquiryMode inquiry_mode = gd_hci::InquiryMode::STANDARD;
  auto packet = bluetooth::hci::ReadInquiryModeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, inquiry_mode);
  send_event_(std::move(packet));
}

void DualModeController::WriteInquiryMode(CommandView command) {
  auto command_view = gd_hci::WriteInquiryModeView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  link_layer_controller_.SetInquiryMode(
      static_cast<uint8_t>(command_view.GetInquiryMode()));
  auto packet = bluetooth::hci::WriteInquiryModeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::ReadPageScanType(CommandView command) {
  auto command_view = gd_hci::ReadPageScanTypeView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  gd_hci::PageScanType page_scan_type = gd_hci::PageScanType::STANDARD;
  auto packet = bluetooth::hci::ReadPageScanTypeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, page_scan_type);
  send_event_(std::move(packet));
}

void DualModeController::WritePageScanType(CommandView command) {
  auto command_view = gd_hci::WritePageScanTypeView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::WritePageScanTypeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::ReadInquiryScanType(CommandView command) {
  auto command_view = gd_hci::ReadInquiryScanTypeView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  gd_hci::InquiryScanType inquiry_scan_type = gd_hci::InquiryScanType::STANDARD;
  auto packet = bluetooth::hci::ReadInquiryScanTypeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, inquiry_scan_type);
  send_event_(std::move(packet));
}

void DualModeController::WriteInquiryScanType(CommandView command) {
  auto command_view = gd_hci::WriteInquiryScanTypeView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::WriteInquiryScanTypeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::AuthenticationRequested(CommandView command) {
  auto command_view = gd_hci::AuthenticationRequestedView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  uint16_t handle = command_view.GetConnectionHandle();
  auto status = link_layer_controller_.AuthenticationRequested(handle);

  auto packet = bluetooth::hci::AuthenticationRequestedStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::SetConnectionEncryption(CommandView command) {
  auto command_view = gd_hci::SetConnectionEncryptionView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  uint16_t handle = command_view.GetConnectionHandle();
  uint8_t encryption_enable =
      static_cast<uint8_t>(command_view.GetEncryptionEnable());
  auto status =
      link_layer_controller_.SetConnectionEncryption(handle, encryption_enable);

  auto packet = bluetooth::hci::SetConnectionEncryptionStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::ChangeConnectionLinkKey(CommandView command) {
  auto command_view = gd_hci::ChangeConnectionLinkKeyView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  uint16_t handle = command_view.GetConnectionHandle();

  auto status = link_layer_controller_.ChangeConnectionLinkKey(handle);

  auto packet = bluetooth::hci::ChangeConnectionLinkKeyStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::CentralLinkKey(CommandView command) {
  auto command_view = gd_hci::CentralLinkKeyView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  uint8_t key_flag = static_cast<uint8_t>(command_view.GetKeyFlag());

  auto status = link_layer_controller_.CentralLinkKey(key_flag);

  auto packet = bluetooth::hci::CentralLinkKeyStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::WriteAuthenticationEnable(CommandView command) {
  auto command_view = gd_hci::WriteAuthenticationEnableView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());
  properties_.SetAuthenticationEnable(
      static_cast<uint8_t>(command_view.GetAuthenticationEnable()));
  auto packet =
      bluetooth::hci::WriteAuthenticationEnableCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::ReadAuthenticationEnable(CommandView command) {
  auto command_view = gd_hci::ReadAuthenticationEnableView::Create(command);
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::ReadAuthenticationEnableCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS,
      static_cast<bluetooth::hci::AuthenticationEnable>(
          properties_.GetAuthenticationEnable()));
  send_event_(std::move(packet));
}

void DualModeController::WriteClassOfDevice(CommandView command) {
  auto command_view = gd_hci::WriteClassOfDeviceView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  ClassOfDevice class_of_device = command_view.GetClassOfDevice();
  properties_.SetClassOfDevice(class_of_device.cod[0], class_of_device.cod[1],
                               class_of_device.cod[2]);
  auto packet = bluetooth::hci::WriteClassOfDeviceCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::ReadPageTimeout(CommandView command) {
  auto command_view = gd_hci::ReadPageTimeoutView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  uint16_t page_timeout = 0x2000;
  auto packet = bluetooth::hci::ReadPageTimeoutCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, page_timeout);
  send_event_(std::move(packet));
}

void DualModeController::WritePageTimeout(CommandView command) {
  auto command_view = gd_hci::WritePageTimeoutView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::WritePageTimeoutCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::HoldMode(CommandView command) {
  auto command_view = gd_hci::HoldModeView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  uint16_t handle = command_view.GetConnectionHandle();
  uint16_t hold_mode_max_interval = command_view.GetHoldModeMaxInterval();
  uint16_t hold_mode_min_interval = command_view.GetHoldModeMinInterval();

  auto status = link_layer_controller_.HoldMode(handle, hold_mode_max_interval,
                                                hold_mode_min_interval);

  auto packet =
      bluetooth::hci::HoldModeStatusBuilder::Create(status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::SniffMode(CommandView command) {
  auto command_view = gd_hci::SniffModeView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  uint16_t handle = command_view.GetConnectionHandle();
  uint16_t sniff_max_interval = command_view.GetSniffMaxInterval();
  uint16_t sniff_min_interval = command_view.GetSniffMinInterval();
  uint16_t sniff_attempt = command_view.GetSniffAttempt();
  uint16_t sniff_timeout = command_view.GetSniffTimeout();

  auto status = link_layer_controller_.SniffMode(handle, sniff_max_interval,
                                                 sniff_min_interval,
                                                 sniff_attempt, sniff_timeout);

  auto packet = bluetooth::hci::SniffModeStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::ExitSniffMode(CommandView command) {
  auto command_view = gd_hci::ExitSniffModeView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  auto status =
      link_layer_controller_.ExitSniffMode(command_view.GetConnectionHandle());

  auto packet = bluetooth::hci::ExitSniffModeStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::QosSetup(CommandView command) {
  auto command_view = gd_hci::QosSetupView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  uint16_t handle = command_view.GetConnectionHandle();
  uint8_t service_type = static_cast<uint8_t>(command_view.GetServiceType());
  uint32_t token_rate = command_view.GetTokenRate();
  uint32_t peak_bandwidth = command_view.GetPeakBandwidth();
  uint32_t latency = command_view.GetLatency();
  uint32_t delay_variation = command_view.GetDelayVariation();

  auto status =
      link_layer_controller_.QosSetup(handle, service_type, token_rate,
                                      peak_bandwidth, latency, delay_variation);

  auto packet =
      bluetooth::hci::QosSetupStatusBuilder::Create(status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::ReadDefaultLinkPolicySettings(CommandView command) {
  auto command_view = gd_hci::ReadDefaultLinkPolicySettingsView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  uint16_t settings = link_layer_controller_.ReadDefaultLinkPolicySettings();
  auto packet =
      bluetooth::hci::ReadDefaultLinkPolicySettingsCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS, settings);
  send_event_(std::move(packet));
}

void DualModeController::WriteDefaultLinkPolicySettings(CommandView command) {
  auto command_view = gd_hci::WriteDefaultLinkPolicySettingsView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  ErrorCode status = link_layer_controller_.WriteDefaultLinkPolicySettings(
      command_view.GetDefaultLinkPolicySettings());
  auto packet =
      bluetooth::hci::WriteDefaultLinkPolicySettingsCompleteBuilder::Create(
          kNumCommandPackets, status);
  send_event_(std::move(packet));
}

void DualModeController::FlowSpecification(CommandView command) {
  auto command_view = gd_hci::FlowSpecificationView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  uint16_t handle = command_view.GetConnectionHandle();
  uint8_t flow_direction =
      static_cast<uint8_t>(command_view.GetFlowDirection());
  uint8_t service_type = static_cast<uint8_t>(command_view.GetServiceType());
  uint32_t token_rate = command_view.GetTokenRate();
  uint32_t token_bucket_size = command_view.GetTokenBucketSize();
  uint32_t peak_bandwidth = command_view.GetPeakBandwidth();
  uint32_t access_latency = command_view.GetAccessLatency();

  auto status = link_layer_controller_.FlowSpecification(
      handle, flow_direction, service_type, token_rate, token_bucket_size,
      peak_bandwidth, access_latency);

  auto packet = bluetooth::hci::FlowSpecificationStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::WriteLinkPolicySettings(CommandView command) {
  auto command_view = gd_hci::WriteLinkPolicySettingsView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  uint16_t handle = command_view.GetConnectionHandle();
  uint16_t settings = command_view.GetLinkPolicySettings();

  auto status =
      link_layer_controller_.WriteLinkPolicySettings(handle, settings);

  auto packet = bluetooth::hci::WriteLinkPolicySettingsCompleteBuilder::Create(
      kNumCommandPackets, status, handle);
  send_event_(std::move(packet));
}

void DualModeController::WriteLinkSupervisionTimeout(CommandView command) {
  auto command_view = gd_hci::WriteLinkSupervisionTimeoutView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  uint16_t handle = command_view.GetConnectionHandle();
  uint16_t timeout = command_view.GetLinkSupervisionTimeout();

  auto status =
      link_layer_controller_.WriteLinkSupervisionTimeout(handle, timeout);
  auto packet =
      bluetooth::hci::WriteLinkSupervisionTimeoutCompleteBuilder::Create(
          kNumCommandPackets, status, handle);
  send_event_(std::move(packet));
}

void DualModeController::ReadLocalName(CommandView command) {
  auto command_view = gd_hci::ReadLocalNameView::Create(command);
  ASSERT(command_view.IsValid());

  std::array<uint8_t, 248> local_name{};
  local_name.fill(0x00);
  size_t len = properties_.GetName().size();
  if (len > 247) {
    len = 247;  // one byte for NULL octet (0x00)
  }
  std::copy_n(properties_.GetName().begin(), len, local_name.begin());

  auto packet = bluetooth::hci::ReadLocalNameCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, local_name);
  send_event_(std::move(packet));
}

void DualModeController::WriteLocalName(CommandView command) {
  auto command_view = gd_hci::WriteLocalNameView::Create(command);
  ASSERT(command_view.IsValid());
  const auto local_name = command_view.GetLocalName();
  std::vector<uint8_t> name_vec(248);
  for (size_t i = 0; i < 248; i++) {
    name_vec[i] = local_name[i];
  }
  properties_.SetName(name_vec);
  auto packet = bluetooth::hci::WriteLocalNameCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::WriteExtendedInquiryResponse(CommandView command) {
  auto command_view = gd_hci::WriteExtendedInquiryResponseView::Create(command);
  ASSERT(command_view.IsValid());
  properties_.SetExtendedInquiryData(std::vector<uint8_t>(
      command_view.GetPayload().begin() + 1, command_view.GetPayload().end()));
  auto packet =
      bluetooth::hci::WriteExtendedInquiryResponseCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::RefreshEncryptionKey(CommandView command) {
  auto command_view = gd_hci::RefreshEncryptionKeyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());
  uint16_t handle = command_view.GetConnectionHandle();
  auto status_packet =
      bluetooth::hci::RefreshEncryptionKeyStatusBuilder::Create(
          ErrorCode::SUCCESS, kNumCommandPackets);
  send_event_(std::move(status_packet));
  // TODO: Support this in the link layer
  auto complete_packet =
      bluetooth::hci::EncryptionKeyRefreshCompleteBuilder::Create(
          ErrorCode::SUCCESS, handle);
  send_event_(std::move(complete_packet));
}

void DualModeController::WriteVoiceSetting(CommandView command) {
  auto command_view = gd_hci::WriteVoiceSettingView::Create(command);
  ASSERT(command_view.IsValid());

  properties_.SetVoiceSetting(command_view.GetVoiceSetting());

  auto packet = bluetooth::hci::WriteVoiceSettingCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::ReadNumberOfSupportedIac(CommandView command) {
  auto command_view = gd_hci::ReadNumberOfSupportedIacView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  uint8_t num_support_iac = 0x1;
  auto packet = bluetooth::hci::ReadNumberOfSupportedIacCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, num_support_iac);
  send_event_(std::move(packet));
}

void DualModeController::ReadCurrentIacLap(CommandView command) {
  auto command_view = gd_hci::ReadCurrentIacLapView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  gd_hci::Lap lap;
  lap.lap_ = 0x30;
  auto packet = bluetooth::hci::ReadCurrentIacLapCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, {lap});
  send_event_(std::move(packet));
}

void DualModeController::WriteCurrentIacLap(CommandView command) {
  auto command_view = gd_hci::WriteCurrentIacLapView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::WriteCurrentIacLapCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::ReadPageScanActivity(CommandView command) {
  auto command_view = gd_hci::ReadPageScanActivityView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  uint16_t interval = 0x1000;
  uint16_t window = 0x0012;
  auto packet = bluetooth::hci::ReadPageScanActivityCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, interval, window);
  send_event_(std::move(packet));
}

void DualModeController::WritePageScanActivity(CommandView command) {
  auto command_view = gd_hci::WritePageScanActivityView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::WritePageScanActivityCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::ReadInquiryScanActivity(CommandView command) {
  auto command_view = gd_hci::ReadInquiryScanActivityView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  uint16_t interval = 0x1000;
  uint16_t window = 0x0012;
  auto packet = bluetooth::hci::ReadInquiryScanActivityCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, interval, window);
  send_event_(std::move(packet));
}

void DualModeController::WriteInquiryScanActivity(CommandView command) {
  auto command_view = gd_hci::WriteInquiryScanActivityView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::WriteInquiryScanActivityCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::ReadScanEnable(CommandView command) {
  auto command_view = gd_hci::ReadScanEnableView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::ReadScanEnableCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, gd_hci::ScanEnable::NO_SCANS);
  send_event_(std::move(packet));
}

void DualModeController::WriteScanEnable(CommandView command) {
  auto command_view = gd_hci::WriteScanEnableView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  link_layer_controller_.SetInquiryScanEnable(
      command_view.GetScanEnable() ==
          gd_hci::ScanEnable::INQUIRY_AND_PAGE_SCAN ||
      command_view.GetScanEnable() == gd_hci::ScanEnable::INQUIRY_SCAN_ONLY);
  link_layer_controller_.SetPageScanEnable(
      command_view.GetScanEnable() ==
          gd_hci::ScanEnable::INQUIRY_AND_PAGE_SCAN ||
      command_view.GetScanEnable() == gd_hci::ScanEnable::PAGE_SCAN_ONLY);
  auto packet = bluetooth::hci::WriteScanEnableCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::SetEventFilter(CommandView command) {
  auto command_view = gd_hci::SetEventFilterView::Create(command);
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::SetEventFilterCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::Inquiry(CommandView command) {
  auto command_view = gd_hci::InquiryView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  link_layer_controller_.SetInquiryLAP(command_view.GetLap().lap_);
  link_layer_controller_.SetInquiryMaxResponses(command_view.GetNumResponses());
  link_layer_controller_.StartInquiry(
      std::chrono::milliseconds(command_view.GetInquiryLength() * 1280));

  auto packet = bluetooth::hci::InquiryStatusBuilder::Create(
      ErrorCode::SUCCESS, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::InquiryCancel(CommandView command) {
  auto command_view = gd_hci::InquiryCancelView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());
  link_layer_controller_.InquiryCancel();
  auto packet = bluetooth::hci::InquiryCancelCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::AcceptConnectionRequest(CommandView command) {
  auto command_view = gd_hci::AcceptConnectionRequestView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  Address addr = command_view.GetBdAddr();
  bool try_role_switch = command_view.GetRole() ==
                         gd_hci::AcceptConnectionRequestRole::BECOME_CENTRAL;
  auto status =
      link_layer_controller_.AcceptConnectionRequest(addr, try_role_switch);
  auto packet = bluetooth::hci::AcceptConnectionRequestStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::RejectConnectionRequest(CommandView command) {
  auto command_view = gd_hci::RejectConnectionRequestView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  Address addr = command_view.GetBdAddr();
  uint8_t reason = static_cast<uint8_t>(command_view.GetReason());
  auto status = link_layer_controller_.RejectConnectionRequest(addr, reason);
  auto packet = bluetooth::hci::RejectConnectionRequestStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::LinkKeyRequestReply(CommandView command) {
  auto command_view = gd_hci::LinkKeyRequestReplyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());
  Address addr = command_view.GetBdAddr();
  auto key = command_view.GetLinkKey();
  auto status = link_layer_controller_.LinkKeyRequestReply(addr, key);
  auto packet = bluetooth::hci::LinkKeyRequestReplyCompleteBuilder::Create(
      kNumCommandPackets, status);
  send_event_(std::move(packet));
}

void DualModeController::LinkKeyRequestNegativeReply(CommandView command) {
  auto command_view = gd_hci::LinkKeyRequestNegativeReplyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());
  Address addr = command_view.GetBdAddr();
  auto status = link_layer_controller_.LinkKeyRequestNegativeReply(addr);
  auto packet =
      bluetooth::hci::LinkKeyRequestNegativeReplyCompleteBuilder::Create(
          kNumCommandPackets, status, addr);
  send_event_(std::move(packet));
}

void DualModeController::DeleteStoredLinkKey(CommandView command) {
  auto command_view = gd_hci::DeleteStoredLinkKeyView::Create(
      gd_hci::SecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  uint16_t deleted_keys = 0;

  auto flag = command_view.GetDeleteAllFlag();
  if (flag == gd_hci::DeleteStoredLinkKeyDeleteAllFlag::SPECIFIED_BD_ADDR) {
    Address addr = command_view.GetBdAddr();
    deleted_keys = security_manager_.DeleteKey(addr);
  }

  if (flag == gd_hci::DeleteStoredLinkKeyDeleteAllFlag::ALL) {
    security_manager_.DeleteAllKeys();
  }

  auto packet = bluetooth::hci::DeleteStoredLinkKeyCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, deleted_keys);

  send_event_(std::move(packet));
}

void DualModeController::RemoteNameRequest(CommandView command) {
  auto command_view = gd_hci::RemoteNameRequestView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());

  Address remote_addr = command_view.GetBdAddr();

  auto status = link_layer_controller_.SendCommandToRemoteByAddress(
      OpCode::REMOTE_NAME_REQUEST, command_view.GetPayload(), remote_addr);

  auto packet = bluetooth::hci::RemoteNameRequestStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::LeSetEventMask(CommandView command) {
  auto command_view = gd_hci::LeSetEventMaskView::Create(command);
  ASSERT(command_view.IsValid());
  properties_.SetLeEventMask(command_view.GetLeEventMask());
  auto packet = bluetooth::hci::LeSetEventMaskCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::LeReadBufferSize(CommandView command) {
  auto command_view = gd_hci::LeReadBufferSizeV1View::Create(command);
  ASSERT(command_view.IsValid());

  bluetooth::hci::LeBufferSize le_buffer_size;
  le_buffer_size.le_data_packet_length_ = properties_.GetLeDataPacketLength();
  le_buffer_size.total_num_le_packets_ = properties_.GetTotalNumLeDataPackets();

  auto packet = bluetooth::hci::LeReadBufferSizeV1CompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, le_buffer_size);
  send_event_(std::move(packet));
}

void DualModeController::LeSetAddressResolutionEnable(CommandView command) {
    // NOP
    auto payload =
      std::make_unique<bluetooth::packet::RawBuilder>(std::vector<uint8_t>(
          {static_cast<uint8_t>(bluetooth::hci::ErrorCode::SUCCESS)}));
  send_event_(bluetooth::hci::CommandCompleteBuilder::Create(
      kNumCommandPackets, command.GetOpCode(), std::move(payload)));
}

void DualModeController::LeSetResovalablePrivateAddressTimeout(CommandView command) {
    // NOP
    auto payload =
      std::make_unique<bluetooth::packet::RawBuilder>(std::vector<uint8_t>(
          {static_cast<uint8_t>(bluetooth::hci::ErrorCode::SUCCESS)}));
  send_event_(bluetooth::hci::CommandCompleteBuilder::Create(
      kNumCommandPackets, command.GetOpCode(), std::move(payload)));
}

void DualModeController::LeReadLocalSupportedFeatures(CommandView command) {
  auto command_view = gd_hci::LeReadLocalSupportedFeaturesView::Create(command);
  ASSERT(command_view.IsValid());
  auto packet =
      bluetooth::hci::LeReadLocalSupportedFeaturesCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS,
          properties_.GetLeSupportedFeatures());
  send_event_(std::move(packet));
}

void DualModeController::LeSetRandomAddress(CommandView command) {
  auto command_view = gd_hci::LeSetRandomAddressView::Create(
      gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(command_view.IsValid());
  properties_.SetLeAddress(command_view.GetRandomAddress());
  auto packet = bluetooth::hci::LeSetRandomAddressCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::LeSetAdvertisingParameters(CommandView command) {
  auto command_view = gd_hci::LeSetAdvertisingParametersView::Create(
      gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto peer_address = command_view.GetPeerAddress();
  auto type = command_view.GetAdvtType();
  if (type != bluetooth::hci::AdvertisingType::ADV_DIRECT_IND &&
      type != bluetooth::hci::AdvertisingType::ADV_DIRECT_IND_LOW) {
    peer_address = Address::kEmpty;
  }
  properties_.SetLeAdvertisingParameters(
      command_view.GetIntervalMin(), command_view.GetIntervalMax(),
      static_cast<uint8_t>(type),
      static_cast<uint8_t>(command_view.GetOwnAddressType()),
      static_cast<uint8_t>(command_view.GetPeerAddressType()), peer_address,
      command_view.GetChannelMap(),
      static_cast<uint8_t>(command_view.GetFilterPolicy()));

  auto packet =
      bluetooth::hci::LeSetAdvertisingParametersCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::LeReadAdvertisingPhysicalChannelTxPower(
    CommandView command) {
  auto command_view =
      gd_hci::LeReadAdvertisingPhysicalChannelTxPowerView::Create(
          gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto packet =
      bluetooth::hci::LeReadAdvertisingPhysicalChannelTxPowerCompleteBuilder::
          Create(kNumCommandPackets, ErrorCode::SUCCESS,
                 properties_.GetLeAdvertisingPhysicalChannelTxPower());
  send_event_(std::move(packet));
}

void DualModeController::LeSetAdvertisingData(CommandView command) {
  auto command_view = gd_hci::LeSetAdvertisingDataView::Create(
      gd_hci::LeAdvertisingCommandView::Create(command));
  auto payload = command.GetPayload();
  auto data_size = *payload.begin();
  auto first_data = payload.begin() + 1;
  std::vector<uint8_t> payload_bytes{first_data, first_data + data_size};
  ASSERT_LOG(command_view.IsValid(), "%s command.size() = %zu",
             gd_hci::OpCodeText(command.GetOpCode()).c_str(), command.size());
  ASSERT(command_view.GetPayload().size() == 32);
  properties_.SetLeAdvertisement(payload_bytes);
  auto packet = bluetooth::hci::LeSetAdvertisingDataCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::LeSetScanResponseData(CommandView command) {
  auto command_view = gd_hci::LeSetScanResponseDataView::Create(
      gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(command_view.IsValid());
  ASSERT(command_view.GetPayload().size() == 32);
  properties_.SetLeScanResponse(std::vector<uint8_t>(
      command_view.GetPayload().begin() + 1, command_view.GetPayload().end()));
  auto packet = bluetooth::hci::LeSetScanResponseDataCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::LeSetAdvertisingEnable(CommandView command) {
  auto command_view = gd_hci::LeSetAdvertisingEnableView::Create(
      gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto status = link_layer_controller_.SetLeAdvertisingEnable(
      command_view.GetAdvertisingEnable() == gd_hci::Enable::ENABLED);
  send_event_(bluetooth::hci::LeSetAdvertisingEnableCompleteBuilder::Create(
      kNumCommandPackets, status));
}

void DualModeController::LeSetScanParameters(CommandView command) {
  auto command_view = gd_hci::LeSetScanParametersView::Create(
      gd_hci::LeScanningCommandView::Create(command));
  ASSERT(command_view.IsValid());
  link_layer_controller_.SetLeScanType(
      static_cast<uint8_t>(command_view.GetLeScanType()));
  link_layer_controller_.SetLeScanInterval(command_view.GetLeScanInterval());
  link_layer_controller_.SetLeScanWindow(command_view.GetLeScanWindow());
  link_layer_controller_.SetLeAddressType(command_view.GetOwnAddressType());
  link_layer_controller_.SetLeScanFilterPolicy(
      static_cast<uint8_t>(command_view.GetScanningFilterPolicy()));
  auto packet = bluetooth::hci::LeSetScanParametersCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::LeSetScanEnable(CommandView command) {
  auto command_view = gd_hci::LeSetScanEnableView::Create(
      gd_hci::LeScanningCommandView::Create(command));
  ASSERT(command_view.IsValid());
  if (command_view.GetLeScanEnable() == gd_hci::Enable::ENABLED) {
    link_layer_controller_.SetLeScanEnable(gd_hci::OpCode::LE_SET_SCAN_ENABLE);
  } else {
    link_layer_controller_.SetLeScanEnable(gd_hci::OpCode::NONE);
  }
  link_layer_controller_.SetLeFilterDuplicates(
      command_view.GetFilterDuplicates() == gd_hci::Enable::ENABLED);
  auto packet = bluetooth::hci::LeSetScanEnableCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::LeCreateConnection(CommandView command) {
  auto command_view = gd_hci::LeCreateConnectionView::Create(
      gd_hci::LeConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  link_layer_controller_.SetLeScanInterval(command_view.GetLeScanInterval());
  link_layer_controller_.SetLeScanWindow(command_view.GetLeScanWindow());
  uint8_t initiator_filter_policy =
      static_cast<uint8_t>(command_view.GetInitiatorFilterPolicy());
  link_layer_controller_.SetLeInitiatorFilterPolicy(initiator_filter_policy);

  if (initiator_filter_policy == 0) {  // Connect list not used
    uint8_t peer_address_type =
        static_cast<uint8_t>(command_view.GetPeerAddressType());
    Address peer_address = command_view.GetPeerAddress();
    link_layer_controller_.SetLePeerAddressType(peer_address_type);
    link_layer_controller_.SetLePeerAddress(peer_address);
  }
  link_layer_controller_.SetLeAddressType(command_view.GetOwnAddressType());
  link_layer_controller_.SetLeConnectionIntervalMin(
      command_view.GetConnIntervalMin());
  link_layer_controller_.SetLeConnectionIntervalMax(
      command_view.GetConnIntervalMax());
  link_layer_controller_.SetLeConnectionLatency(command_view.GetConnLatency());
  link_layer_controller_.SetLeSupervisionTimeout(
      command_view.GetSupervisionTimeout());
  link_layer_controller_.SetLeMinimumCeLength(
      command_view.GetMinimumCeLength());
  link_layer_controller_.SetLeMaximumCeLength(
      command_view.GetMaximumCeLength());

  auto status = link_layer_controller_.SetLeConnect(true);

  auto packet = bluetooth::hci::LeCreateConnectionStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::LeConnectionUpdate(CommandView command) {
  auto command_view = gd_hci::LeConnectionUpdateView::Create(
      gd_hci::LeConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  ErrorCode status = link_layer_controller_.LeConnectionUpdate(command_view);

  auto status_packet = bluetooth::hci::LeConnectionUpdateStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(status_packet));
}

void DualModeController::CreateConnection(CommandView command) {
  auto command_view = gd_hci::CreateConnectionView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  Address address = command_view.GetBdAddr();
  uint16_t packet_type = command_view.GetPacketType();
  uint8_t page_scan_mode =
      static_cast<uint8_t>(command_view.GetPageScanRepetitionMode());
  uint16_t clock_offset =
      (command_view.GetClockOffsetValid() == gd_hci::ClockOffsetValid::VALID
           ? command_view.GetClockOffset()
           : 0);
  uint8_t allow_role_switch =
      static_cast<uint8_t>(command_view.GetAllowRoleSwitch());

  auto status = link_layer_controller_.CreateConnection(
      address, packet_type, page_scan_mode, clock_offset, allow_role_switch);

  auto packet = bluetooth::hci::CreateConnectionStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::CreateConnectionCancel(CommandView command) {
  auto command_view = gd_hci::CreateConnectionCancelView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  Address address = command_view.GetBdAddr();

  auto status = link_layer_controller_.CreateConnectionCancel(address);

  auto packet = bluetooth::hci::CreateConnectionCancelCompleteBuilder::Create(
      kNumCommandPackets, status, address);
  send_event_(std::move(packet));
}

void DualModeController::Disconnect(CommandView command) {
  auto command_view = gd_hci::DisconnectView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  uint16_t handle = command_view.GetConnectionHandle();
  uint8_t reason = static_cast<uint8_t>(command_view.GetReason());

  auto status = link_layer_controller_.Disconnect(handle, reason);

  auto packet = bluetooth::hci::DisconnectStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::LeConnectionCancel(CommandView command) {
  auto command_view = gd_hci::LeCreateConnectionCancelView::Create(
      gd_hci::LeConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  ErrorCode status = link_layer_controller_.SetLeConnect(false);
  send_event_(bluetooth::hci::LeCreateConnectionCancelCompleteBuilder::Create(
      kNumCommandPackets, status));

  send_event_(bluetooth::hci::LeConnectionCompleteBuilder::Create(
      ErrorCode::UNKNOWN_CONNECTION, kReservedHandle,
      bluetooth::hci::Role::CENTRAL,
      bluetooth::hci::AddressType::PUBLIC_DEVICE_ADDRESS,
      bluetooth::hci::Address(), 1 /* connection_interval */,
      2 /* connection_latency */, 3 /* supervision_timeout*/,
      static_cast<bluetooth::hci::ClockAccuracy>(0x00)));
}

void DualModeController::LeReadConnectListSize(CommandView command) {
  auto command_view = gd_hci::LeReadConnectListSizeView::Create(
      gd_hci::LeConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::LeReadConnectListSizeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS,
      properties_.GetLeConnectListSize());
  send_event_(std::move(packet));
}

void DualModeController::LeClearConnectList(CommandView command) {
  auto command_view = gd_hci::LeClearConnectListView::Create(
      gd_hci::LeConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  link_layer_controller_.LeConnectListClear();
  auto packet = bluetooth::hci::LeClearConnectListCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::LeAddDeviceToConnectList(CommandView command) {
  auto command_view = gd_hci::LeAddDeviceToConnectListView::Create(
      gd_hci::LeConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  uint8_t addr_type = static_cast<uint8_t>(command_view.GetAddressType());
  Address address = command_view.GetAddress();
  ErrorCode result =
      link_layer_controller_.LeConnectListAddDevice(address, addr_type);
  auto packet = bluetooth::hci::LeAddDeviceToConnectListCompleteBuilder::Create(
      kNumCommandPackets, result);
  send_event_(std::move(packet));
}

void DualModeController::LeRemoveDeviceFromConnectList(CommandView command) {
  auto command_view = gd_hci::LeRemoveDeviceFromConnectListView::Create(
      gd_hci::LeConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  uint8_t addr_type = static_cast<uint8_t>(command_view.GetAddressType());
  Address address = command_view.GetAddress();
  link_layer_controller_.LeConnectListRemoveDevice(address, addr_type);
  auto packet =
      bluetooth::hci::LeRemoveDeviceFromConnectListCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::LeClearResolvingList(CommandView command) {
  auto command_view = gd_hci::LeClearResolvingListView::Create(
      gd_hci::LeSecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());
  link_layer_controller_.LeResolvingListClear();
  auto packet = bluetooth::hci::LeClearResolvingListCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::LeReadResolvingListSize(CommandView command) {
  auto command_view = gd_hci::LeReadResolvingListSizeView::Create(
      gd_hci::LeSecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::LeReadResolvingListSizeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS,
      properties_.GetLeResolvingListSize());
  send_event_(std::move(packet));
}

void DualModeController::LeReadMaximumDataLength(CommandView command) {
  auto command_view = gd_hci::LeReadMaximumDataLengthView::Create(
      gd_hci::LeSecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());
  bluetooth::hci::LeMaximumDataLength data_length;
  data_length.supported_max_rx_octets_ = kLeMaximumDataLength;
  data_length.supported_max_rx_time_ = kLeMaximumDataTime;
  data_length.supported_max_tx_octets_ = kLeMaximumDataLength + 10;
  data_length.supported_max_tx_time_ = kLeMaximumDataTime + 10;
  send_event_(bluetooth::hci::LeReadMaximumDataLengthCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, data_length));
}

void DualModeController::LeReadSuggestedDefaultDataLength(CommandView command) {
  auto command_view = gd_hci::LeReadSuggestedDefaultDataLengthView::Create(
      gd_hci::LeConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  send_event_(bluetooth::hci::LeReadSuggestedDefaultDataLengthCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, kLeMaximumDataLength, kLeMaximumDataTime));
}

void DualModeController::LeAddDeviceToResolvingList(CommandView command) {
  auto command_view = gd_hci::LeAddDeviceToResolvingListView::Create(
      gd_hci::LeSecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  uint8_t addr_type =
      static_cast<uint8_t>(command_view.GetPeerIdentityAddressType());
  Address address = command_view.GetPeerIdentityAddress();
  std::array<uint8_t, LinkLayerController::kIrk_size> peerIrk =
      command_view.GetPeerIrk();
  std::array<uint8_t, LinkLayerController::kIrk_size> localIrk =
      command_view.GetLocalIrk();

  auto status = link_layer_controller_.LeResolvingListAddDevice(
      address, addr_type, peerIrk, localIrk);
  auto packet =
      bluetooth::hci::LeAddDeviceToResolvingListCompleteBuilder::Create(
          kNumCommandPackets, status);
  send_event_(std::move(packet));
}

void DualModeController::LeRemoveDeviceFromResolvingList(CommandView command) {
  auto command_view = gd_hci::LeRemoveDeviceFromResolvingListView::Create(
      gd_hci::LeSecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  uint8_t addr_type =
      static_cast<uint8_t>(command_view.GetPeerIdentityAddressType());
  Address address = command_view.GetPeerIdentityAddress();
  link_layer_controller_.LeResolvingListRemoveDevice(address, addr_type);
  auto packet =
      bluetooth::hci::LeRemoveDeviceFromResolvingListCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::LeSetExtendedScanParameters(CommandView command) {
  auto command_view = gd_hci::LeSetExtendedScanParametersView::Create(
      gd_hci::LeScanningCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto parameters = command_view.GetParameters();
  // Multiple phys are not supported.
  ASSERT(command_view.GetScanningPhys() == 1);
  ASSERT(parameters.size() == 1);

  auto status = ErrorCode::SUCCESS;
  if (link_layer_controller_.GetLeScanEnable() == OpCode::NONE) {
    link_layer_controller_.SetLeScanType(
        static_cast<uint8_t>(parameters[0].le_scan_type_));
    link_layer_controller_.SetLeScanInterval(parameters[0].le_scan_interval_);
    link_layer_controller_.SetLeScanWindow(parameters[0].le_scan_window_);
    link_layer_controller_.SetLeAddressType(command_view.GetOwnAddressType());
    link_layer_controller_.SetLeScanFilterPolicy(
        static_cast<uint8_t>(command_view.GetScanningFilterPolicy()));
  } else {
    status = ErrorCode::COMMAND_DISALLOWED;
  }
  send_event_(
      bluetooth::hci::LeSetExtendedScanParametersCompleteBuilder::Create(
          kNumCommandPackets, status));
}

void DualModeController::LeSetExtendedScanEnable(CommandView command) {
  auto command_view = gd_hci::LeSetExtendedScanEnableView::Create(
      gd_hci::LeScanningCommandView::Create(command));
  ASSERT(command_view.IsValid());
  if (command_view.GetEnable() == gd_hci::Enable::ENABLED) {
    link_layer_controller_.SetLeScanEnable(
        gd_hci::OpCode::LE_SET_EXTENDED_SCAN_ENABLE);
  } else {
    link_layer_controller_.SetLeScanEnable(gd_hci::OpCode::NONE);
  }
  link_layer_controller_.SetLeFilterDuplicates(
      command_view.GetFilterDuplicates() == gd_hci::FilterDuplicates::ENABLED);
  auto packet = bluetooth::hci::LeSetExtendedScanEnableCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::LeExtendedCreateConnection(CommandView command) {
  auto command_view = gd_hci::LeExtendedCreateConnectionView::Create(
      gd_hci::LeConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());
  ASSERT_LOG(command_view.GetInitiatingPhys() == 1, "Only LE_1M is supported");
  auto params = command_view.GetPhyScanParameters();
  link_layer_controller_.SetLeScanInterval(params[0].scan_interval_);
  link_layer_controller_.SetLeScanWindow(params[0].scan_window_);
  auto initiator_filter_policy = command_view.GetInitiatorFilterPolicy();
  link_layer_controller_.SetLeInitiatorFilterPolicy(
      static_cast<uint8_t>(initiator_filter_policy));

  if (initiator_filter_policy ==
      gd_hci::InitiatorFilterPolicy::USE_PEER_ADDRESS) {
    link_layer_controller_.SetLePeerAddressType(
        static_cast<uint8_t>(command_view.GetPeerAddressType()));
    link_layer_controller_.SetLePeerAddress(command_view.GetPeerAddress());
  }
  link_layer_controller_.SetLeAddressType(command_view.GetOwnAddressType());
  link_layer_controller_.SetLeConnectionIntervalMin(
      params[0].conn_interval_min_);
  link_layer_controller_.SetLeConnectionIntervalMax(
      params[0].conn_interval_max_);
  link_layer_controller_.SetLeConnectionLatency(params[0].conn_latency_);
  link_layer_controller_.SetLeSupervisionTimeout(
      params[0].supervision_timeout_);
  link_layer_controller_.SetLeMinimumCeLength(params[0].min_ce_length_);
  link_layer_controller_.SetLeMaximumCeLength(params[0].max_ce_length_);

  auto status = link_layer_controller_.SetLeConnect(true);

  send_event_(bluetooth::hci::LeExtendedCreateConnectionStatusBuilder::Create(
      status, kNumCommandPackets));
}

void DualModeController::LeSetPrivacyMode(CommandView command) {
  auto command_view = gd_hci::LeSetPrivacyModeView::Create(
      gd_hci::LeSecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  uint8_t peer_identity_address_type =
      static_cast<uint8_t>(command_view.GetPeerIdentityAddressType());
  Address peer_identity_address = command_view.GetPeerIdentityAddress();
  uint8_t privacy_mode = static_cast<uint8_t>(command_view.GetPrivacyMode());

  if (link_layer_controller_.LeResolvingListContainsDevice(
          peer_identity_address, peer_identity_address_type)) {
    link_layer_controller_.LeSetPrivacyMode(
        peer_identity_address_type, peer_identity_address, privacy_mode);
  }

  auto packet = bluetooth::hci::LeSetPrivacyModeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::LeReadIsoTxSync(CommandView command) {
  auto iso_command_view = gd_hci::LeIsoCommandView::Create(command);
  ASSERT(iso_command_view.IsValid());
  auto command_view =
      gd_hci::LeReadIsoTxSyncView::Create(std::move(iso_command_view));
  ASSERT(command_view.IsValid());
  link_layer_controller_.LeReadIsoTxSync(command_view.GetConnectionHandle());
}

void DualModeController::LeSetCigParameters(CommandView command) {
  auto iso_command_view = gd_hci::LeIsoCommandView::Create(command);
  ASSERT(iso_command_view.IsValid());
  auto command_view =
      gd_hci::LeSetCigParametersView::Create(std::move(iso_command_view));
  ASSERT(command_view.IsValid());
  link_layer_controller_.LeSetCigParameters(
      command_view.GetCigId(), command_view.GetSduIntervalMToS(),
      command_view.GetSduIntervalSToM(),
      command_view.GetPeripheralsClockAccuracy(), command_view.GetPacking(),
      command_view.GetFraming(), command_view.GetMaxTransportLatencyMToS(),
      command_view.GetMaxTransportLatencySToM(), command_view.GetCisConfig());
}

void DualModeController::LeCreateCis(CommandView command) {
  auto iso_command_view = gd_hci::LeIsoCommandView::Create(command);
  ASSERT(iso_command_view.IsValid());
  auto command_view =
      gd_hci::LeCreateCisView::Create(std::move(iso_command_view));
  ASSERT(command_view.IsValid());
  ErrorCode status =
      link_layer_controller_.LeCreateCis(command_view.GetCisConfig());
  send_event_(bluetooth::hci::LeCreateCisStatusBuilder::Create(
      status, kNumCommandPackets));
}

void DualModeController::LeRemoveCig(CommandView command) {
  auto iso_command_view = gd_hci::LeIsoCommandView::Create(command);
  ASSERT(iso_command_view.IsValid());
  auto command_view =
      gd_hci::LeRemoveCigView::Create(std::move(iso_command_view));
  ASSERT(command_view.IsValid());
  uint8_t cig = command_view.GetCigId();
  ErrorCode status = link_layer_controller_.LeRemoveCig(cig);
  send_event_(bluetooth::hci::LeRemoveCigCompleteBuilder::Create(
      kNumCommandPackets, status, cig));
}

void DualModeController::LeAcceptCisRequest(CommandView command) {
  auto iso_command_view = gd_hci::LeIsoCommandView::Create(command);
  ASSERT(iso_command_view.IsValid());
  auto command_view =
      gd_hci::LeAcceptCisRequestView::Create(std::move(iso_command_view));
  ASSERT(command_view.IsValid());
  ErrorCode status = link_layer_controller_.LeAcceptCisRequest(
      command_view.GetConnectionHandle());
  send_event_(bluetooth::hci::LeAcceptCisRequestStatusBuilder::Create(
      status, kNumCommandPackets));
}

void DualModeController::LeRejectCisRequest(CommandView command) {
  auto iso_command_view = gd_hci::LeIsoCommandView::Create(command);
  ASSERT(iso_command_view.IsValid());
  auto command_view =
      gd_hci::LeRejectCisRequestView::Create(std::move(iso_command_view));
  ASSERT(command_view.IsValid());
  link_layer_controller_.LeRejectCisRequest(command_view.GetConnectionHandle(),
                                            command_view.GetReason());
}

void DualModeController::LeCreateBig(CommandView command) {
  auto iso_command_view = gd_hci::LeIsoCommandView::Create(command);
  ASSERT(iso_command_view.IsValid());
  auto command_view =
      gd_hci::LeCreateBigView::Create(std::move(iso_command_view));
  ASSERT(command_view.IsValid());
  ErrorCode status = link_layer_controller_.LeCreateBig(
      command_view.GetBigHandle(), command_view.GetAdvertisingHandle(),
      command_view.GetNumBis(), command_view.GetSduInterval(),
      command_view.GetMaxSdu(), command_view.GetMaxTransportLatency(),
      command_view.GetRtn(), command_view.GetPhy(), command_view.GetPacking(),
      command_view.GetFraming(), command_view.GetEncryption(),
      command_view.GetBroadcastCode());
  send_event_(bluetooth::hci::LeCreateBigStatusBuilder::Create(
      status, kNumCommandPackets));
}

void DualModeController::LeTerminateBig(CommandView command) {
  auto iso_command_view = gd_hci::LeIsoCommandView::Create(command);
  ASSERT(iso_command_view.IsValid());
  auto command_view =
      gd_hci::LeTerminateBigView::Create(std::move(iso_command_view));
  ASSERT(command_view.IsValid());
  ErrorCode status = link_layer_controller_.LeTerminateBig(
      command_view.GetBigHandle(), command_view.GetReason());
  send_event_(bluetooth::hci::LeTerminateBigStatusBuilder::Create(
      status, kNumCommandPackets));
}

void DualModeController::LeBigCreateSync(CommandView command) {
  auto iso_command_view = gd_hci::LeIsoCommandView::Create(command);
  ASSERT(iso_command_view.IsValid());
  auto command_view =
      gd_hci::LeBigCreateSyncView::Create(std::move(iso_command_view));
  ASSERT(command_view.IsValid());
  ErrorCode status = link_layer_controller_.LeBigCreateSync(
      command_view.GetBigHandle(), command_view.GetSyncHandle(),
      command_view.GetEncryption(), command_view.GetBroadcastCode(),
      command_view.GetMse(), command_view.GetBigSyncTimeout(),
      command_view.GetBis());
  send_event_(bluetooth::hci::LeBigCreateSyncStatusBuilder::Create(
      status, kNumCommandPackets));
}

void DualModeController::LeBigTerminateSync(CommandView command) {
  auto iso_command_view = gd_hci::LeIsoCommandView::Create(command);
  ASSERT(iso_command_view.IsValid());
  auto command_view =
      gd_hci::LeBigTerminateSyncView::Create(std::move(iso_command_view));
  ASSERT(command_view.IsValid());
  link_layer_controller_.LeBigTerminateSync(command_view.GetBigHandle());
}

void DualModeController::LeRequestPeerSca(CommandView command) {
  auto command_view = gd_hci::LeRequestPeerScaView::Create(std::move(command));
  ASSERT(command_view.IsValid());
  ErrorCode status = link_layer_controller_.LeRequestPeerSca(
      command_view.GetConnectionHandle());
  send_event_(bluetooth::hci::LeRequestPeerScaStatusBuilder::Create(
      status, kNumCommandPackets));
}

void DualModeController::LeSetupIsoDataPath(CommandView command) {
  auto iso_command_view = gd_hci::LeIsoCommandView::Create(command);
  ASSERT(iso_command_view.IsValid());
  auto command_view =
      gd_hci::LeSetupIsoDataPathView::Create(std::move(iso_command_view));
  ASSERT(command_view.IsValid());
  link_layer_controller_.LeSetupIsoDataPath(
      command_view.GetConnectionHandle(), command_view.GetDataPathDirection(),
      command_view.GetDataPathId(), command_view.GetCodecId(),
      command_view.GetControllerDelay(), command_view.GetCodecConfiguration());
}

void DualModeController::LeRemoveIsoDataPath(CommandView command) {
  auto iso_command_view = gd_hci::LeIsoCommandView::Create(command);
  ASSERT(iso_command_view.IsValid());
  auto command_view =
      gd_hci::LeRemoveIsoDataPathView::Create(std::move(iso_command_view));
  ASSERT(command_view.IsValid());
  link_layer_controller_.LeRemoveIsoDataPath(
      command_view.GetConnectionHandle(), command_view.GetDataPathDirection());
}

void DualModeController::LeReadRemoteFeatures(CommandView command) {
  auto command_view = gd_hci::LeReadRemoteFeaturesView::Create(
      gd_hci::LeConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  uint16_t handle = command_view.GetConnectionHandle();

  auto status = link_layer_controller_.SendCommandToRemoteByHandle(
      OpCode::LE_READ_REMOTE_FEATURES, command_view.GetPayload(), handle);

  auto packet = bluetooth::hci::LeReadRemoteFeaturesStatusBuilder::Create(
      status, kNumCommandPackets);
  send_event_(std::move(packet));
}

void DualModeController::LeRand(CommandView command) {
  auto command_view = gd_hci::LeRandView::Create(
      gd_hci::LeSecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());
  uint64_t random_val = 0;
  for (size_t rand_bytes = 0; rand_bytes < sizeof(uint64_t); rand_bytes += sizeof(RAND_MAX)) {
    random_val = (random_val << (8 * sizeof(RAND_MAX))) | random();
  }

  auto packet = bluetooth::hci::LeRandCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, random_val);
  send_event_(std::move(packet));
}

void DualModeController::LeReadSupportedStates(CommandView command) {
  auto command_view = gd_hci::LeReadSupportedStatesView::Create(command);
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::LeReadSupportedStatesCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS,
      properties_.GetLeSupportedStates());
  send_event_(std::move(packet));
}

void DualModeController::LeVendorCap(CommandView command) {
  auto command_view = gd_hci::LeGetVendorCapabilitiesView::Create(
      gd_hci::VendorCommandView::Create(command));
  ASSERT(command_view.IsValid());
  vector<uint8_t> caps = properties_.GetLeVendorCap();
  if (caps.size() == 0) {
    SendCommandCompleteUnknownOpCodeEvent(
        static_cast<uint16_t>(OpCode::LE_GET_VENDOR_CAPABILITIES));
    return;
  }

  std::unique_ptr<bluetooth::packet::RawBuilder> raw_builder_ptr =
      std::make_unique<bluetooth::packet::RawBuilder>();
  raw_builder_ptr->AddOctets1(static_cast<uint8_t>(ErrorCode::SUCCESS));
  raw_builder_ptr->AddOctets(properties_.GetLeVendorCap());

  auto packet = bluetooth::hci::CommandCompleteBuilder::Create(
      kNumCommandPackets, OpCode::LE_GET_VENDOR_CAPABILITIES,
      std::move(raw_builder_ptr));
  send_event_(std::move(packet));
}

void DualModeController::LeVendorMultiAdv(CommandView command) {
  auto command_view = gd_hci::LeMultiAdvtView::Create(
      gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(command_view.IsValid());
  SendCommandCompleteUnknownOpCodeEvent(
      static_cast<uint16_t>(OpCode::LE_MULTI_ADVT));
}

void DualModeController::LeAdvertisingFilter(CommandView command) {
  auto command_view = gd_hci::LeAdvFilterView::Create(
      gd_hci::LeScanningCommandView::Create(command));
  ASSERT(command_view.IsValid());
  SendCommandCompleteUnknownOpCodeEvent(
      static_cast<uint16_t>(OpCode::LE_ADV_FILTER));
}

void DualModeController::LeEnergyInfo(CommandView command) {
  auto command_view = gd_hci::LeEnergyInfoView::Create(
      gd_hci::VendorCommandView::Create(command));
  ASSERT(command_view.IsValid());
  SendCommandCompleteUnknownOpCodeEvent(
      static_cast<uint16_t>(OpCode::LE_ENERGY_INFO));
}

void DualModeController::LeSetExtendedAdvertisingRandomAddress(
    CommandView command) {
  auto command_view = gd_hci::LeSetExtendedAdvertisingRandomAddressView::Create(
      gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(command_view.IsValid());
  link_layer_controller_.SetLeExtendedAddress(
      command_view.GetAdvertisingHandle(),
      command_view.GetAdvertisingRandomAddress());
  send_event_(
      bluetooth::hci::LeSetExtendedAdvertisingRandomAddressCompleteBuilder::
          Create(kNumCommandPackets, ErrorCode::SUCCESS));
}

void DualModeController::LeSetExtendedAdvertisingParameters(
    CommandView command) {
  auto command_view =
      gd_hci::LeSetExtendedAdvertisingLegacyParametersView::Create(
          gd_hci::LeAdvertisingCommandView::Create(command));
  // TODO: Support non-legacy parameters
  ASSERT(command_view.IsValid());
  link_layer_controller_.SetLeExtendedAdvertisingParameters(
      command_view.GetAdvertisingHandle(),
      command_view.GetPrimaryAdvertisingIntervalMin(),
      command_view.GetPrimaryAdvertisingIntervalMax(),
      command_view.GetAdvertisingEventLegacyProperties(),
      command_view.GetOwnAddressType(), command_view.GetPeerAddressType(),
      command_view.GetPeerAddress(), command_view.GetAdvertisingFilterPolicy());

  send_event_(
      bluetooth::hci::LeSetExtendedAdvertisingParametersCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS, 0xa5));
}

void DualModeController::LeSetExtendedAdvertisingData(CommandView command) {
  auto command_view = gd_hci::LeSetExtendedAdvertisingDataView::Create(
      gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto raw_command_view = gd_hci::LeSetExtendedAdvertisingDataRawView::Create(
      gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(raw_command_view.IsValid());
  link_layer_controller_.SetLeExtendedAdvertisingData(
      command_view.GetAdvertisingHandle(),
      raw_command_view.GetAdvertisingData());
  auto packet =
      bluetooth::hci::LeSetExtendedAdvertisingDataCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::LeSetExtendedAdvertisingScanResponse(
    CommandView command) {
  auto command_view = gd_hci::LeSetExtendedAdvertisingScanResponseView::Create(
      gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(command_view.IsValid());
  properties_.SetLeScanResponse(std::vector<uint8_t>(
      command_view.GetPayload().begin() + 1, command_view.GetPayload().end()));
  send_event_(
      bluetooth::hci::LeSetExtendedAdvertisingScanResponseCompleteBuilder::
          Create(kNumCommandPackets, ErrorCode::SUCCESS));
}

void DualModeController::LeSetExtendedAdvertisingEnable(CommandView command) {
  auto command_view = gd_hci::LeSetExtendedAdvertisingEnableView::Create(
      gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto enabled_sets = command_view.GetEnabledSets();
  ErrorCode status = ErrorCode::SUCCESS;
  if (enabled_sets.size() == 0) {
    link_layer_controller_.LeDisableAdvertisingSets();
  } else {
    status = link_layer_controller_.SetLeExtendedAdvertisingEnable(
        command_view.GetEnable(), command_view.GetEnabledSets());
  }
  send_event_(
      bluetooth::hci::LeSetExtendedAdvertisingEnableCompleteBuilder::Create(
          kNumCommandPackets, status));
}

void DualModeController::LeReadMaximumAdvertisingDataLength(
    CommandView command) {
  auto command_view = gd_hci::LeReadMaximumAdvertisingDataLengthView::Create(
      gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(command_view.IsValid());
  send_event_(
      bluetooth::hci::LeReadMaximumAdvertisingDataLengthCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS,
          kLeMaximumAdvertisingDataLength));
}

void DualModeController::LeReadNumberOfSupportedAdvertisingSets(
    CommandView command) {
  auto command_view =
      gd_hci::LeReadNumberOfSupportedAdvertisingSetsView::Create(
          gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(command_view.IsValid());
  send_event_(
      bluetooth::hci::LeReadNumberOfSupportedAdvertisingSetsCompleteBuilder::
          Create(
              kNumCommandPackets, ErrorCode::SUCCESS,
              link_layer_controller_.LeReadNumberOfSupportedAdvertisingSets()));
}

void DualModeController::LeRemoveAdvertisingSet(CommandView command) {
  auto command_view = gd_hci::LeRemoveAdvertisingSetView::Create(
      gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto status = link_layer_controller_.LeRemoveAdvertisingSet(
      command_view.GetAdvertisingHandle());
  send_event_(bluetooth::hci::LeRemoveAdvertisingSetCompleteBuilder::Create(
      kNumCommandPackets, status));
}

void DualModeController::LeClearAdvertisingSets(CommandView command) {
  auto command_view = gd_hci::LeClearAdvertisingSetsView::Create(
      gd_hci::LeAdvertisingCommandView::Create(command));
  ASSERT(command_view.IsValid());
  auto status = link_layer_controller_.LeClearAdvertisingSets();
  send_event_(bluetooth::hci::LeClearAdvertisingSetsCompleteBuilder::Create(
      kNumCommandPackets, status));
}

void DualModeController::LeExtendedScanParams(CommandView command) {
  auto command_view = gd_hci::LeExtendedScanParamsView::Create(
      gd_hci::LeScanningCommandView::Create(command));
  ASSERT(command_view.IsValid());
  SendCommandCompleteUnknownOpCodeEvent(
      static_cast<uint16_t>(OpCode::LE_EXTENDED_SCAN_PARAMS));
}

void DualModeController::LeStartEncryption(CommandView command) {
  auto command_view = gd_hci::LeStartEncryptionView::Create(
      gd_hci::LeSecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  ErrorCode status = link_layer_controller_.LeEnableEncryption(
      command_view.GetConnectionHandle(), command_view.GetRand(),
      command_view.GetEdiv(), command_view.GetLtk());

  send_event_(bluetooth::hci::LeStartEncryptionStatusBuilder::Create(
      status, kNumCommandPackets));
}

void DualModeController::LeLongTermKeyRequestReply(CommandView command) {
  auto command_view = gd_hci::LeLongTermKeyRequestReplyView::Create(
      gd_hci::LeSecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  uint16_t handle = command_view.GetConnectionHandle();
  ErrorCode status = link_layer_controller_.LeLongTermKeyRequestReply(
      handle, command_view.GetLongTermKey());

  send_event_(bluetooth::hci::LeLongTermKeyRequestReplyCompleteBuilder::Create(
      kNumCommandPackets, status, handle));
}

void DualModeController::LeLongTermKeyRequestNegativeReply(
    CommandView command) {
  auto command_view = gd_hci::LeLongTermKeyRequestNegativeReplyView::Create(
      gd_hci::LeSecurityCommandView::Create(command));
  ASSERT(command_view.IsValid());

  uint16_t handle = command_view.GetConnectionHandle();
  ErrorCode status =
      link_layer_controller_.LeLongTermKeyRequestNegativeReply(handle);

  send_event_(
      bluetooth::hci::LeLongTermKeyRequestNegativeReplyCompleteBuilder::Create(
          kNumCommandPackets, status, handle));
}

void DualModeController::ReadClassOfDevice(CommandView command) {
  auto command_view = gd_hci::ReadClassOfDeviceView::Create(
      gd_hci::DiscoveryCommandView::Create(command));
  ASSERT(command_view.IsValid());

  auto packet = bluetooth::hci::ReadClassOfDeviceCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, properties_.GetClassOfDevice());
  send_event_(std::move(packet));
}

void DualModeController::ReadVoiceSetting(CommandView command) {
  auto command_view = gd_hci::ReadVoiceSettingView::Create(command);
  ASSERT(command_view.IsValid());

  auto packet = bluetooth::hci::ReadVoiceSettingCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS, properties_.GetVoiceSetting());
  send_event_(std::move(packet));
}

void DualModeController::ReadConnectionAcceptTimeout(CommandView command) {
  auto command_view = gd_hci::ReadConnectionAcceptTimeoutView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  auto packet =
      bluetooth::hci::ReadConnectionAcceptTimeoutCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS,
          properties_.GetConnectionAcceptTimeout());
  send_event_(std::move(packet));
}

void DualModeController::WriteConnectionAcceptTimeout(CommandView command) {
  auto command_view = gd_hci::WriteConnectionAcceptTimeoutView::Create(
      gd_hci::ConnectionManagementCommandView::Create(
          gd_hci::AclCommandView::Create(command)));
  ASSERT(command_view.IsValid());

  properties_.SetConnectionAcceptTimeout(command_view.GetConnAcceptTimeout());

  auto packet =
      bluetooth::hci::WriteConnectionAcceptTimeoutCompleteBuilder::Create(
          kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::ReadLoopbackMode(CommandView command) {
  auto command_view = gd_hci::ReadLoopbackModeView::Create(command);
  ASSERT(command_view.IsValid());
  auto packet = bluetooth::hci::ReadLoopbackModeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS,
      static_cast<LoopbackMode>(loopback_mode_));
  send_event_(std::move(packet));
}

void DualModeController::WriteLoopbackMode(CommandView command) {
  auto command_view = gd_hci::WriteLoopbackModeView::Create(command);
  ASSERT(command_view.IsValid());
  loopback_mode_ = command_view.GetLoopbackMode();
  // ACL channel
  uint16_t acl_handle = 0x123;
  auto packet_acl = bluetooth::hci::ConnectionCompleteBuilder::Create(
      ErrorCode::SUCCESS, acl_handle, properties_.GetAddress(),
      bluetooth::hci::LinkType::ACL, bluetooth::hci::Enable::DISABLED);
  send_event_(std::move(packet_acl));
  // SCO channel
  uint16_t sco_handle = 0x345;
  auto packet_sco = bluetooth::hci::ConnectionCompleteBuilder::Create(
      ErrorCode::SUCCESS, sco_handle, properties_.GetAddress(),
      bluetooth::hci::LinkType::SCO, bluetooth::hci::Enable::DISABLED);
  send_event_(std::move(packet_sco));
  auto packet = bluetooth::hci::WriteLoopbackModeCompleteBuilder::Create(
      kNumCommandPackets, ErrorCode::SUCCESS);
  send_event_(std::move(packet));
}

void DualModeController::SetAddress(Address address) {
  properties_.SetAddress(address);
}

}  // namespace test_vendor_lib
