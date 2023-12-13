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

#define LOG_TAG "bt_headless"

#include <dlfcn.h>  //  dlopen
#include <algorithm>
#include <iostream>
#include <map>

#include "base/logging.h"  // LOG() stdout and android log
#include "include/hardware/bluetooth.h"
#include "osi/include/log.h"  // android log only
#include "test/headless/get_options.h"
#include "test/headless/headless.h"
#include "test/headless/interface.h"

extern bt_interface_t bluetoothInterface;

using namespace bluetooth::test::headless;

std::map<const std::string, std::list<callback_function_t>>
    interface_api_callback_map_;

void headless_add_callback(const std::string interface_name,
                           callback_function_t function) {
  if (interface_api_callback_map_.find(interface_name) ==
      interface_api_callback_map_.end()) {
    interface_api_callback_map_.emplace(interface_name,
                                        std::list<callback_function_t>());
  }
  interface_api_callback_map_[interface_name].push_back(function);
}

void headless_remove_callback(const std::string interface_name,
                              callback_function_t function) {
  if (interface_api_callback_map_.find(interface_name) ==
      interface_api_callback_map_.end()) {
    ASSERT_LOG(false, "No callbacks registered for interface:%s",
               interface_name.c_str());
  }
  interface_api_callback_map_[interface_name].remove(function);
}

namespace {
std::mutex adapter_state_mutex_;
std::condition_variable adapter_state_cv_;
bt_state_t bt_state_{BT_STATE_OFF};

void adapter_state_changed(bt_state_t state) {
  std::unique_lock<std::mutex> lck(adapter_state_mutex_);
  bt_state_ = state;
  adapter_state_cv_.notify_all();
}
void adapter_properties(bt_status_t status, int num_properties,
                        bt_property_t* properties) {
  LOG_INFO("%s", __func__);
}

void remote_device_properties(bt_status_t status, RawAddress* bd_addr,
                              int num_properties, bt_property_t* properties) {
  LOG_INFO("%s", __func__);
}

void device_found(int num_properties, bt_property_t* properties) {
  LOG_INFO("%s", __func__);
}

void discovery_state_changed(bt_discovery_state_t state) {
  LOG_INFO("%s", __func__);
}

/** Bluetooth Legacy PinKey Request callback */
void pin_request(RawAddress* remote_bd_addr, bt_bdname_t* bd_name, uint32_t cod,
                 bool min_16_digit) {
  LOG_INFO("%s", __func__);
}

void ssp_request(RawAddress* remote_bd_addr, bt_bdname_t* bd_name, uint32_t cod,
                 bt_ssp_variant_t pairing_variant, uint32_t pass_key) {
  LOG_INFO("%s", __func__);
}

/** Bluetooth Bond state changed callback */
/* Invoked in response to create_bond, cancel_bond or remove_bond */
void bond_state_changed(bt_status_t status, RawAddress* remote_bd_addr,
                        bt_bond_state_t state) {
  LOG_INFO("%s", __func__);
}

/** Bluetooth ACL connection state changed callback */
void acl_state_changed(bt_status_t status, RawAddress* remote_bd_addr,
                       bt_acl_state_t state, bt_hci_error_code_t hci_reason) {
  auto callback_list = interface_api_callback_map_.at(__func__);
  for (auto callback : callback_list) {
    interface_data_t params{
        .name = __func__,
        .params.acl_state_changed.status = status,
        .params.acl_state_changed.remote_bd_addr = remote_bd_addr,
        .params.acl_state_changed.state = state,
        .params.acl_state_changed.hci_reason = hci_reason,
    };
    (callback)(params);
  }
  LOG_INFO("%s status:%s device:%s state:%s", __func__,
           bt_status_text(status).c_str(), remote_bd_addr->ToString().c_str(),
           (state) ? "disconnected" : "connected");
}

/** Bluetooth Link Quality Report callback */
void link_quality_report(uint64_t timestamp, int report_id, int rssi, int snr,
    int retransmission_count, int packets_not_receive_count,
    int negative_acknowledgement_count) {
  LOG_INFO("%s", __func__);
}

void thread_event(bt_cb_thread_evt evt) { LOG_INFO("%s", __func__); }

void dut_mode_recv(uint16_t opcode, uint8_t* buf, uint8_t len) {
  LOG_INFO("%s", __func__);
}

void le_test_mode(bt_status_t status, uint16_t num_packets) {
  LOG_INFO("%s", __func__);
}

void energy_info(bt_activity_energy_info* energy_info,
                 bt_uid_traffic_t* uid_data) {
  LOG_INFO("%s", __func__);
}

bt_callbacks_t bt_callbacks{
    /** set to sizeof(bt_callbacks_t) */
    .size = sizeof(bt_callbacks_t),
    .adapter_state_changed_cb = adapter_state_changed,
    .adapter_properties_cb = adapter_properties,
    .remote_device_properties_cb = remote_device_properties,
    .device_found_cb = device_found,
    .discovery_state_changed_cb = discovery_state_changed,
    .pin_request_cb = pin_request,
    .ssp_request_cb = ssp_request,
    .bond_state_changed_cb = bond_state_changed,
    .acl_state_changed_cb = acl_state_changed,
    .thread_evt_cb = thread_event,
    .dut_mode_recv_cb = dut_mode_recv,
    .le_test_mode_cb = le_test_mode,
    .energy_info_cb = energy_info,
    .link_quality_report_cb = link_quality_report,
};
// HAL HARDWARE CALLBACKS

// OS CALLOUTS
bool set_wake_alarm_co(uint64_t delay_millis, bool should_wake, alarm_cb cb,
                       void* data) {
  LOG_INFO("%s", __func__);
  return true;
}
int acquire_wake_lock_co(const char* lock_name) {
  LOG_INFO("%s", __func__);
  return 1;
}

int release_wake_lock_co(const char* lock_name) {
  LOG_INFO("%s", __func__);
  return 0;
}

bt_os_callouts_t bt_os_callouts{
    .size = sizeof(bt_os_callouts_t),
    .set_wake_alarm = set_wake_alarm_co,
    .acquire_wake_lock = acquire_wake_lock_co,
    .release_wake_lock = release_wake_lock_co,
};
}  // namespace

void HeadlessStack::SetUp() {
  LOG(INFO) << __func__ << " Entry";

  const bool start_restricted = false;
  const bool is_common_criteria_mode = false;
  const int config_compare_result = 0;
  const bool is_atv = false;
  int status = bluetoothInterface.init(
      &bt_callbacks, start_restricted, is_common_criteria_mode,
      config_compare_result, StackInitFlags(), is_atv);

  (status == BT_STATUS_SUCCESS)
      ? LOG(INFO) << __func__ << " Initialized bluetooth callbacks"
      : LOG(FATAL) << "Failed to initialize Bluetooth stack";

  status = bluetoothInterface.set_os_callouts(&bt_os_callouts);
  (status == BT_STATUS_SUCCESS)
      ? LOG(INFO) << __func__ << " Initialized os callouts"
      : LOG(ERROR) << "Failed to set up Bluetooth OS callouts";

  bluetoothInterface.enable();
  LOG_INFO("%s HeadlessStack stack has enabled", __func__);

  std::unique_lock<std::mutex> lck(adapter_state_mutex_);
  while (bt_state_ != BT_STATE_ON) adapter_state_cv_.wait(lck);
  LOG_INFO("%s HeadlessStack stack is operational", __func__);
}

void HeadlessStack::TearDown() {
  LOG_INFO("Stack has disabled");
  int status = bluetoothInterface.disable();

  LOG(INFO) << __func__ << " Interface has been disabled status:" << status;

  bluetoothInterface.cleanup();
  LOG(INFO) << __func__ << " Cleaned up hal bluetooth library";

  std::unique_lock<std::mutex> lck(adapter_state_mutex_);
  while (bt_state_ != BT_STATE_OFF) adapter_state_cv_.wait(lck);
  LOG_INFO("%s HeadlessStack stack has exited", __func__);
}
