/*
 * Copyright 2019 The Android Open Source Project
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

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <chrono>
#include <future>
#include <map>

#include "common/bind.h"
#include "hci/acl_manager.h"
#include "hci/address.h"
#include "hci/controller.h"
#include "hci/hci_layer.h"
#include "hci/le_scanning_manager.h"
#include "os/thread.h"
#include "packet/raw_builder.h"

namespace bluetooth {
namespace hci {
namespace {

using packet::kLittleEndian;
using packet::PacketView;
using packet::RawBuilder;

PacketView<kLittleEndian> GetPacketView(std::unique_ptr<packet::BasePacketBuilder> packet) {
  auto bytes = std::make_shared<std::vector<uint8_t>>();
  BitInserter i(*bytes);
  bytes->reserve(packet->size());
  packet->Serialize(i);
  return packet::PacketView<packet::kLittleEndian>(bytes);
}

class TestController : public Controller {
 public:
  bool IsSupported(OpCode op_code) const override {
    return supported_opcodes_.count(op_code) == 1;
  }

  void AddSupported(OpCode op_code) {
    supported_opcodes_.insert(op_code);
  }

 protected:
  void Start() override {}
  void Stop() override {}
  void ListDependencies(ModuleList* list) override {}

 private:
  std::set<OpCode> supported_opcodes_{};
};

class TestHciLayer : public HciLayer {
 public:
  void EnqueueCommand(
      std::unique_ptr<CommandBuilder> command,
      common::ContextualOnceCallback<void(CommandStatusView)> on_status) override {
    command_queue_.push(std::move(command));
    command_status_callbacks.push_back(std::move(on_status));
    if (command_promise_ != nullptr) {
      command_promise_->set_value();
      command_promise_.reset();
    }
  }

  void EnqueueCommand(
      std::unique_ptr<CommandBuilder> command,
      common::ContextualOnceCallback<void(CommandCompleteView)> on_complete) override {
    command_queue_.push(std::move(command));
    command_complete_callbacks.push_back(std::move(on_complete));
    if (command_promise_ != nullptr) {
      command_promise_->set_value();
      command_promise_.reset();
    }
  }

  std::future<void> GetCommandFuture() {
    ASSERT_LOG(command_promise_ == nullptr, "Promises promises ... Only one at a time");
    command_promise_ = std::make_unique<std::promise<void>>();
    return command_promise_->get_future();
  }

  CommandView GetLastCommand() {
    if (command_queue_.empty()) {
      return CommandView::Create(GetPacketView(nullptr));
    } else {
      auto last = std::move(command_queue_.front());
      command_queue_.pop();
      return CommandView::Create(GetPacketView(std::move(last)));
    }
  }

  ConnectionManagementCommandView GetCommand(OpCode op_code) {
    CommandView command_packet_view = GetLastCommand();
    auto command = ConnectionManagementCommandView::Create(AclCommandView::Create(command_packet_view));
    EXPECT_TRUE(command.IsValid());
    EXPECT_EQ(command.GetOpCode(), op_code);
    return command;
  }

  void RegisterEventHandler(EventCode event_code, common::ContextualCallback<void(EventView)> event_handler) override {
    registered_events_[event_code] = event_handler;
  }

  void UnregisterEventHandler(EventCode event_code) override {
    registered_events_.erase(event_code);
  }

  void RegisterLeEventHandler(SubeventCode subevent_code,
                              common::ContextualCallback<void(LeMetaEventView)> event_handler) override {
    registered_le_events_[subevent_code] = event_handler;
  }

  void UnregisterLeEventHandler(SubeventCode subevent_code) override {
    registered_le_events_.erase(subevent_code);
  }

  void IncomingEvent(std::unique_ptr<EventBuilder> event_builder) {
    auto packet = GetPacketView(std::move(event_builder));
    EventView event = EventView::Create(packet);
    ASSERT_TRUE(event.IsValid());
    EventCode event_code = event.GetEventCode();
    ASSERT_NE(registered_events_.find(event_code), registered_events_.end()) << EventCodeText(event_code);
    registered_events_[event_code].Invoke(event);
  }

  void IncomingLeMetaEvent(std::unique_ptr<LeMetaEventBuilder> event_builder) {
    auto packet = GetPacketView(std::move(event_builder));
    EventView event = EventView::Create(packet);
    LeMetaEventView meta_event_view = LeMetaEventView::Create(event);
    ASSERT_TRUE(meta_event_view.IsValid());
    SubeventCode subevent_code = meta_event_view.GetSubeventCode();
    ASSERT_NE(registered_le_events_.find(subevent_code), registered_le_events_.end())
        << SubeventCodeText(subevent_code);
    registered_le_events_[subevent_code].Invoke(meta_event_view);
  }

  void CommandCompleteCallback(EventView event) {
    CommandCompleteView complete_view = CommandCompleteView::Create(event);
    ASSERT_TRUE(complete_view.IsValid());
    ASSERT_NE(command_complete_callbacks.size(), 0);
    std::move(command_complete_callbacks.front()).Invoke(complete_view);
    command_complete_callbacks.pop_front();
  }

  void CommandStatusCallback(EventView event) {
    CommandStatusView status_view = CommandStatusView::Create(event);
    ASSERT_TRUE(status_view.IsValid());
    ASSERT_NE(command_status_callbacks.size(), 0);
    std::move(command_status_callbacks.front()).Invoke(status_view);
    command_status_callbacks.pop_front();
  }

  void ListDependencies(ModuleList* list) override {}
  void Start() override {
    RegisterEventHandler(EventCode::COMMAND_COMPLETE,
                         GetHandler()->BindOn(this, &TestHciLayer::CommandCompleteCallback));
    RegisterEventHandler(EventCode::COMMAND_STATUS, GetHandler()->BindOn(this, &TestHciLayer::CommandStatusCallback));
  }
  void Stop() override {}

 private:
  std::map<EventCode, common::ContextualCallback<void(EventView)>> registered_events_;
  std::map<SubeventCode, common::ContextualCallback<void(LeMetaEventView)>> registered_le_events_;
  std::list<common::ContextualOnceCallback<void(CommandCompleteView)>> command_complete_callbacks;
  std::list<common::ContextualOnceCallback<void(CommandStatusView)>> command_status_callbacks;

  std::queue<std::unique_ptr<CommandBuilder>> command_queue_;
  mutable std::mutex mutex_;
  std::unique_ptr<std::promise<void>> command_promise_{};
};

class TestLeAddressManager : public LeAddressManager {
 public:
  TestLeAddressManager(
      common::Callback<void(std::unique_ptr<CommandBuilder>)> enqueue_command,
      os::Handler* handler,
      Address public_address,
      uint8_t connect_list_size,
      uint8_t resolving_list_size)
      : LeAddressManager(enqueue_command, handler, public_address, connect_list_size, resolving_list_size) {}

  AddressPolicy Register(LeAddressManagerCallback* callback) override {
    return AddressPolicy::USE_STATIC_ADDRESS;
  }

  void Unregister(LeAddressManagerCallback* callback) override {}
};

class TestAclManager : public AclManager {
 public:
  LeAddressManager* GetLeAddressManager() override {
    return test_le_address_manager_;
  }

 protected:
  void Start() override {
    thread_ = new os::Thread("thread", os::Thread::Priority::NORMAL);
    handler_ = new os::Handler(thread_);
    Address address({0x01, 0x02, 0x03, 0x04, 0x05, 0x06});
    test_le_address_manager_ = new TestLeAddressManager(
        common::Bind(&TestAclManager::enqueue_command, common::Unretained(this)), handler_, address, 0x3F, 0x3F);
  }

  void Stop() override {
    delete test_le_address_manager_;
    handler_->Clear();
    delete handler_;
    delete thread_;
  }

  void ListDependencies(ModuleList* list) override {}

  void SetRandomAddress(Address address) {}

  void enqueue_command(std::unique_ptr<CommandBuilder> command_packet){};

  os::Thread* thread_;
  os::Handler* handler_;
  TestLeAddressManager* test_le_address_manager_;
};

class LeScanningManagerTest : public ::testing::Test {
 protected:
  void SetUp() override {
    test_hci_layer_ = new TestHciLayer;  // Ownership is transferred to registry
    test_controller_ = new TestController;
    test_controller_->AddSupported(param_opcode_);
    if (is_filter_support_) {
      test_controller_->AddSupported(OpCode::LE_ADV_FILTER);
    }
    if (is_batch_scan_support_) {
      test_controller_->AddSupported(OpCode::LE_BATCH_SCAN);
    }
    test_acl_manager_ = new TestAclManager;
    fake_registry_.InjectTestModule(&HciLayer::Factory, test_hci_layer_);
    fake_registry_.InjectTestModule(&Controller::Factory, test_controller_);
    fake_registry_.InjectTestModule(&AclManager::Factory, test_acl_manager_);
    client_handler_ = fake_registry_.GetTestModuleHandler(&HciLayer::Factory);
    std::future<void> config_future = test_hci_layer_->GetCommandFuture();
    fake_registry_.Start<LeScanningManager>(&thread_);
    le_scanning_manager =
        static_cast<LeScanningManager*>(fake_registry_.GetModuleUnderTest(&LeScanningManager::Factory));
    auto result = config_future.wait_for(std::chrono::duration(std::chrono::milliseconds(1000)));
    ASSERT_EQ(std::future_status::ready, result);
    auto packet = test_hci_layer_->GetCommand(enable_opcode_);
    test_hci_layer_->IncomingEvent(LeSetScanEnableCompleteBuilder::Create(1, ErrorCode::SUCCESS));
    config_future.wait_for(std::chrono::duration(std::chrono::milliseconds(1000)));
    ASSERT_EQ(std::future_status::ready, result);
    HandleConfiguration();
    le_scanning_manager->RegisterScanningCallback(&mock_callbacks_);
  }

  void TearDown() override {
    fake_registry_.SynchronizeModuleHandler(&LeScanningManager::Factory, std::chrono::milliseconds(20));
    fake_registry_.StopAll();
  }

  virtual void HandleConfiguration() {
    auto packet = test_hci_layer_->GetCommand(OpCode::LE_SET_SCAN_PARAMETERS);
    test_hci_layer_->IncomingEvent(LeSetScanParametersCompleteBuilder::Create(1, ErrorCode::SUCCESS));
  }

  void sync_client_handler() {
    std::promise<void> promise;
    auto future = promise.get_future();
    client_handler_->Call(common::BindOnce(&std::promise<void>::set_value, common::Unretained(&promise)));
    auto future_status = future.wait_for(std::chrono::seconds(1));
    ASSERT_EQ(future_status, std::future_status::ready);
  }

  TestModuleRegistry fake_registry_;
  TestHciLayer* test_hci_layer_ = nullptr;
  TestController* test_controller_ = nullptr;
  TestAclManager* test_acl_manager_ = nullptr;
  os::Thread& thread_ = fake_registry_.GetTestThread();
  LeScanningManager* le_scanning_manager = nullptr;
  os::Handler* client_handler_ = nullptr;

  class MockCallbacks : public bluetooth::hci::ScanningCallback {
   public:
    MOCK_METHOD(
        void,
        OnScannerRegistered,
        (const bluetooth::hci::Uuid app_uuid, ScannerId scanner_id, ScanningStatus status),
        (override));
    MOCK_METHOD(
        void,
        OnScanResult,
        (uint16_t event_type,
         uint8_t address_type,
         Address address,
         uint8_t primary_phy,
         uint8_t secondary_phy,
         uint8_t advertising_sid,
         int8_t tx_power,
         int8_t rssi,
         uint16_t periodic_advertising_interval,
         std::vector<uint8_t> advertising_data),
        (override));
    MOCK_METHOD(
        void,
        OnTrackAdvFoundLost,
        (bluetooth::hci::AdvertisingFilterOnFoundOnLostInfo on_found_on_lost_info),
        (override));
    MOCK_METHOD(
        void,
        OnBatchScanReports,
        (int client_if, int status, int report_format, int num_records, std::vector<uint8_t> data),
        (override));
    MOCK_METHOD(void, OnBatchScanThresholdCrossed, (int client_if), (override));
    MOCK_METHOD(void, OnTimeout, (), (override));
    MOCK_METHOD(void, OnFilterEnable, (Enable enable, uint8_t status), (override));
    MOCK_METHOD(void, OnFilterParamSetup, (uint8_t available_spaces, ApcfAction action, uint8_t status), (override));
    MOCK_METHOD(
        void,
        OnFilterConfigCallback,
        (ApcfFilterType filter_type, uint8_t available_spaces, ApcfAction action, uint8_t status),
        (override));
  } mock_callbacks_;

  OpCode param_opcode_{OpCode::LE_SET_ADVERTISING_PARAMETERS};
  OpCode enable_opcode_{OpCode::LE_SET_SCAN_ENABLE};
  bool is_filter_support_ = false;
  bool is_batch_scan_support_ = false;
};

class LeAndroidHciScanningManagerTest : public LeScanningManagerTest {
 protected:
  void SetUp() override {
    param_opcode_ = OpCode::LE_EXTENDED_SCAN_PARAMS;
    is_filter_support_ = true;
    is_batch_scan_support_ = true;
    LeScanningManagerTest::SetUp();
    test_controller_->AddSupported(OpCode::LE_ADV_FILTER);
  }

  void HandleConfiguration() override {
    auto packet = test_hci_layer_->GetCommand(OpCode::LE_EXTENDED_SCAN_PARAMS);
    test_hci_layer_->IncomingEvent(LeExtendedScanParamsCompleteBuilder::Create(1, ErrorCode::SUCCESS));
  }
};

class LeExtendedScanningManagerTest : public LeScanningManagerTest {
 protected:
  void SetUp() override {
    param_opcode_ = OpCode::LE_SET_EXTENDED_SCAN_PARAMETERS;
    enable_opcode_ = OpCode::LE_SET_EXTENDED_SCAN_ENABLE;
    LeScanningManagerTest::SetUp();
  }

  void HandleConfiguration() override {
    auto packet = test_hci_layer_->GetCommand(OpCode::LE_SET_EXTENDED_SCAN_PARAMETERS);
    test_hci_layer_->IncomingEvent(LeSetExtendedScanParametersCompleteBuilder::Create(1, ErrorCode::SUCCESS));
  }
};

TEST_F(LeScanningManagerTest, startup_teardown) {}

TEST_F(LeScanningManagerTest, start_scan_test) {
  auto next_command_future = test_hci_layer_->GetCommandFuture();
  le_scanning_manager->Scan(true);

  auto result = next_command_future.wait_for(std::chrono::duration(std::chrono::milliseconds(100)));
  ASSERT_EQ(std::future_status::ready, result);
  test_hci_layer_->IncomingEvent(LeSetScanEnableCompleteBuilder::Create(uint8_t{1}, ErrorCode::SUCCESS));

  LeAdvertisingReport report{};
  report.event_type_ = AdvertisingEventType::ADV_DIRECT_IND;
  report.address_type_ = AddressType::PUBLIC_DEVICE_ADDRESS;
  Address::FromString("12:34:56:78:9a:bc", report.address_);
  std::vector<GapData> gap_data{};
  GapData data_item{};
  data_item.data_type_ = GapDataType::FLAGS;
  data_item.data_ = {0x34};
  gap_data.push_back(data_item);
  data_item.data_type_ = GapDataType::COMPLETE_LOCAL_NAME;
  data_item.data_ = {'r', 'a', 'n', 'd', 'o', 'm', ' ', 'd', 'e', 'v', 'i', 'c', 'e'};
  gap_data.push_back(data_item);
  report.advertising_data_ = gap_data;

  EXPECT_CALL(mock_callbacks_, OnScanResult);

  test_hci_layer_->IncomingLeMetaEvent(LeAdvertisingReportBuilder::Create({report}));
}

TEST_F(LeAndroidHciScanningManagerTest, start_scan_test) {
  auto next_command_future = test_hci_layer_->GetCommandFuture();
  le_scanning_manager->Scan(true);

  auto result = next_command_future.wait_for(std::chrono::duration(std::chrono::milliseconds(100)));
  ASSERT_EQ(std::future_status::ready, result);
  test_hci_layer_->IncomingEvent(LeSetScanEnableCompleteBuilder::Create(uint8_t{1}, ErrorCode::SUCCESS));

  LeAdvertisingReport report{};
  report.event_type_ = AdvertisingEventType::ADV_DIRECT_IND;
  report.address_type_ = AddressType::PUBLIC_DEVICE_ADDRESS;
  Address::FromString("12:34:56:78:9a:bc", report.address_);
  std::vector<GapData> gap_data{};
  GapData data_item{};
  data_item.data_type_ = GapDataType::FLAGS;
  data_item.data_ = {0x34};
  gap_data.push_back(data_item);
  data_item.data_type_ = GapDataType::COMPLETE_LOCAL_NAME;
  data_item.data_ = {'r', 'a', 'n', 'd', 'o', 'm', ' ', 'd', 'e', 'v', 'i', 'c', 'e'};
  gap_data.push_back(data_item);
  report.advertising_data_ = gap_data;

  EXPECT_CALL(mock_callbacks_, OnScanResult);

  test_hci_layer_->IncomingLeMetaEvent(LeAdvertisingReportBuilder::Create({report}));
}

TEST_F(LeAndroidHciScanningManagerTest, scan_filter_enable_test) {
  auto next_command_future = test_hci_layer_->GetCommandFuture();
  le_scanning_manager->ScanFilterEnable(true);
  auto result = next_command_future.wait_for(std::chrono::duration(std::chrono::milliseconds(100)));
  ASSERT_EQ(std::future_status::ready, result);
  EXPECT_CALL(mock_callbacks_, OnFilterEnable);
  test_hci_layer_->IncomingEvent(
      LeAdvFilterEnableCompleteBuilder::Create(uint8_t{1}, ErrorCode::SUCCESS, Enable::ENABLED));
  sync_client_handler();
}

TEST_F(LeAndroidHciScanningManagerTest, scan_filter_parameter_test) {
  auto next_command_future = test_hci_layer_->GetCommandFuture();
  AdvertisingFilterParameter advertising_filter_parameter{};
  advertising_filter_parameter.delivery_mode = DeliveryMode::IMMEDIATE;
  le_scanning_manager->ScanFilterParameterSetup(ApcfAction::ADD, 0x01, advertising_filter_parameter);
  auto result = next_command_future.wait_for(std::chrono::duration(std::chrono::milliseconds(100)));
  ASSERT_EQ(std::future_status::ready, result);
  EXPECT_CALL(mock_callbacks_, OnFilterParamSetup);
  test_hci_layer_->IncomingEvent(
      LeAdvFilterSetFilteringParametersCompleteBuilder::Create(uint8_t{1}, ErrorCode::SUCCESS, ApcfAction::ADD, 0x0a));
  sync_client_handler();
}

TEST_F(LeAndroidHciScanningManagerTest, scan_filter_add_test) {
  auto next_command_future = test_hci_layer_->GetCommandFuture();
  std::vector<AdvertisingPacketContentFilterCommand> filters = {};
  AdvertisingPacketContentFilterCommand filter{};
  filter.filter_type = ApcfFilterType::BROADCASTER_ADDRESS;
  filter.address = Address::kEmpty;
  filter.application_address_type = ApcfApplicationAddressType::RANDOM;
  filters.push_back(filter);
  le_scanning_manager->ScanFilterAdd(0x01, filters);
  EXPECT_CALL(mock_callbacks_, OnFilterConfigCallback);
  auto result = next_command_future.wait_for(std::chrono::duration(std::chrono::milliseconds(100)));
  ASSERT_EQ(std::future_status::ready, result);
  test_hci_layer_->IncomingEvent(
      LeAdvFilterBroadcasterAddressCompleteBuilder::Create(uint8_t{1}, ErrorCode::SUCCESS, ApcfAction::ADD, 0x0a));
  sync_client_handler();
}

TEST_F(LeAndroidHciScanningManagerTest, read_batch_scan_result) {
  // Enable batch scan feature
  auto next_command_future = test_hci_layer_->GetCommandFuture();
  le_scanning_manager->BatchScanConifgStorage(100, 0, 95, 0x00);
  auto result = next_command_future.wait_for(std::chrono::duration(std::chrono::milliseconds(100)));
  ASSERT_EQ(std::future_status::ready, result);
  test_hci_layer_->IncomingEvent(LeBatchScanEnableCompleteBuilder::Create(uint8_t{1}, ErrorCode::SUCCESS));
  test_hci_layer_->IncomingEvent(
      LeBatchScanSetStorageParametersCompleteBuilder::Create(uint8_t{1}, ErrorCode::SUCCESS));

  // Enable batch scan
  next_command_future = test_hci_layer_->GetCommandFuture();
  le_scanning_manager->BatchScanEnable(BatchScanMode::FULL, 2400, 2400, BatchScanDiscardRule::OLDEST);
  result = next_command_future.wait_for(std::chrono::duration(std::chrono::milliseconds(100)));
  ASSERT_EQ(std::future_status::ready, result);
  test_hci_layer_->IncomingEvent(LeBatchScanSetScanParametersCompleteBuilder::Create(uint8_t{1}, ErrorCode::SUCCESS));

  // Read batch scan data
  next_command_future = test_hci_layer_->GetCommandFuture();
  le_scanning_manager->BatchScanReadReport(0x01, BatchScanMode::FULL);
  result = next_command_future.wait_for(std::chrono::duration(std::chrono::milliseconds(100)));
  ASSERT_EQ(std::future_status::ready, result);

  EXPECT_CALL(mock_callbacks_, OnBatchScanReports);
  std::vector<uint8_t> raw_data = {0x5c, 0x1f, 0xa2, 0xc3, 0x63, 0x5d, 0x01, 0xf5, 0xb3, 0x5e, 0x00, 0x0c, 0x02,
                                   0x01, 0x02, 0x05, 0x09, 0x6d, 0x76, 0x38, 0x76, 0x02, 0x0a, 0xf5, 0x00};
  next_command_future = test_hci_layer_->GetCommandFuture();
  // We will send read command while num_of_record != 0
  test_hci_layer_->IncomingEvent(LeBatchScanReadResultParametersCompleteRawBuilder::Create(
      uint8_t{1}, ErrorCode::SUCCESS, BatchScanDataRead::FULL_MODE_DATA, 1, raw_data));
  result = next_command_future.wait_for(std::chrono::duration(std::chrono::milliseconds(100)));
  ASSERT_EQ(std::future_status::ready, result);

  // OnBatchScanReports will be trigger when num_of_record == 0
  test_hci_layer_->IncomingEvent(LeBatchScanReadResultParametersCompleteRawBuilder::Create(
      uint8_t{1}, ErrorCode::SUCCESS, BatchScanDataRead::FULL_MODE_DATA, 0, {}));
}

TEST_F(LeExtendedScanningManagerTest, start_scan_test) {
  auto next_command_future = test_hci_layer_->GetCommandFuture();
  le_scanning_manager->Scan(true);

  auto result = next_command_future.wait_for(std::chrono::duration(std::chrono::milliseconds(100)));
  ASSERT_EQ(std::future_status::ready, result);
  test_hci_layer_->GetCommand(OpCode::LE_SET_EXTENDED_SCAN_ENABLE);
  test_hci_layer_->IncomingEvent(LeSetScanEnableCompleteBuilder::Create(uint8_t{1}, ErrorCode::SUCCESS));

  result = next_command_future.wait_for(std::chrono::duration(std::chrono::milliseconds(100)));
  ASSERT_EQ(std::future_status::ready, result);
  test_hci_layer_->GetCommand(OpCode::LE_SET_EXTENDED_SCAN_PARAMETERS);
  test_hci_layer_->IncomingEvent(LeSetExtendedScanParametersCompleteBuilder::Create(uint8_t{1}, ErrorCode::SUCCESS));

  result = next_command_future.wait_for(std::chrono::duration(std::chrono::milliseconds(100)));
  ASSERT_EQ(std::future_status::ready, result);
  test_hci_layer_->GetCommand(OpCode::LE_SET_EXTENDED_SCAN_ENABLE);

  test_hci_layer_->IncomingEvent(LeSetScanEnableCompleteBuilder::Create(uint8_t{1}, ErrorCode::SUCCESS));

  LeExtendedAdvertisingReport report{};
  report.connectable_ = 1;
  report.scannable_ = 0;
  report.address_type_ = DirectAdvertisingAddressType::PUBLIC_DEVICE_ADDRESS;
  Address::FromString("12:34:56:78:9a:bc", report.address_);
  std::vector<GapData> gap_data{};
  GapData data_item{};
  data_item.data_type_ = GapDataType::FLAGS;
  data_item.data_ = {0x34};
  gap_data.push_back(data_item);
  data_item.data_type_ = GapDataType::COMPLETE_LOCAL_NAME;
  data_item.data_ = {'r', 'a', 'n', 'd', 'o', 'm', ' ', 'd', 'e', 'v', 'i', 'c', 'e'};
  gap_data.push_back(data_item);
  std::vector<uint8_t> advertising_data = {};
  for (auto data : gap_data) {
    advertising_data.push_back((uint8_t)data.size() - 1);
    advertising_data.push_back((uint8_t)data.data_type_);
    advertising_data.insert(advertising_data.end(), data.data_.begin(), data.data_.end());
  }

  report.advertising_data_ = advertising_data;

  EXPECT_CALL(mock_callbacks_, OnScanResult);

  test_hci_layer_->IncomingLeMetaEvent(LeExtendedAdvertisingReportBuilder::Create({report}));
}

}  // namespace
}  // namespace hci
}  // namespace bluetooth
