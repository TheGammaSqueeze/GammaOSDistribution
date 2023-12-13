/*
 * Copyright 2021 The Android Open Source Project
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

#include <frameworks/proto_logging/stats/enums/bluetooth/enums.pb.h>
#include <frameworks/proto_logging/stats/enums/bluetooth/hci/enums.pb.h>

#include "common/metrics.h"
#include "main/shim/metrics_api.h"
#include "main/shim/shim.h"
#include "stack/include/stack_metrics_logging.h"
#include "types/raw_address.h"

void log_classic_pairing_event(const RawAddress& address, uint16_t handle,
                               uint32_t hci_cmd, uint16_t hci_event,
                               uint16_t cmd_status, uint16_t reason_code,
                               int64_t event_value) {
  if (bluetooth::shim::is_any_gd_enabled()) {
    bluetooth::shim::LogMetricClassicPairingEvent(address, handle, hci_cmd,
                                                  hci_event, cmd_status,
                                                  reason_code, event_value);
  } else {
    bluetooth::common::LogClassicPairingEvent(address, handle, hci_cmd,
                                              hci_event, cmd_status,
                                              reason_code, event_value);
  }
}

void log_link_layer_connection_event(
    const RawAddress* address, uint32_t connection_handle,
    android::bluetooth::DirectionEnum direction, uint16_t link_type,
    uint32_t hci_cmd, uint16_t hci_event, uint16_t hci_ble_event,
    uint16_t cmd_status, uint16_t reason_code) {
  if (bluetooth::shim::is_any_gd_enabled()) {
    bluetooth::shim::LogMetricLinkLayerConnectionEvent(
        address, connection_handle, direction, link_type, hci_cmd, hci_event,
        hci_ble_event, cmd_status, reason_code);
  } else {
    bluetooth::common::LogLinkLayerConnectionEvent(
        address, connection_handle, direction, link_type, hci_cmd, hci_event,
        hci_ble_event, cmd_status, reason_code);
  }
}

void log_smp_pairing_event(const RawAddress& address, uint8_t smp_cmd,
                           android::bluetooth::DirectionEnum direction,
                           uint8_t smp_fail_reason) {
  if (bluetooth::shim::is_any_gd_enabled()) {
    bluetooth::shim::LogMetricSmpPairingEvent(address, smp_cmd, direction,
                                              smp_fail_reason);
  } else {
    bluetooth::common::LogSmpPairingEvent(address, smp_cmd, direction,
                                          smp_fail_reason);
  }
}

void log_sdp_attribute(const RawAddress& address, uint16_t protocol_uuid,
                       uint16_t attribute_id, size_t attribute_size,
                       const char* attribute_value) {
  if (bluetooth::shim::is_any_gd_enabled()) {
    bluetooth::shim::LogMetricSdpAttribute(address, protocol_uuid, attribute_id,
                                           attribute_size, attribute_value);
  } else {
    bluetooth::common::LogSdpAttribute(address, protocol_uuid, attribute_id,
                                       attribute_size, attribute_value);
  }
}

void log_manufacturer_info(const RawAddress& address,
                           android::bluetooth::DeviceInfoSrcEnum source_type,
                           const std::string& source_name,
                           const std::string& manufacturer,
                           const std::string& model,
                           const std::string& hardware_version,
                           const std::string& software_version) {
  if (bluetooth::shim::is_any_gd_enabled()) {
    bluetooth::shim::LogMetricManufacturerInfo(
        address, source_type, source_name, manufacturer, model,
        hardware_version, software_version);
  } else {
    bluetooth::common::LogManufacturerInfo(address, source_type, source_name,
                                           manufacturer, model,
                                           hardware_version, software_version);
  }
}