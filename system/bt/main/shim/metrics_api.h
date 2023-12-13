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

#pragma once

#include <frameworks/proto_logging/stats/enums/bluetooth/enums.pb.h>
#include <frameworks/proto_logging/stats/enums/bluetooth/hci/enums.pb.h>

#include <unordered_map>
#include "types/raw_address.h"

namespace bluetooth {
namespace shim {

/**
 * Log link layer connection event
 *
 * @param address Stack wide consistent Bluetooth address of this event,
 *                nullptr if unknown
 * @param connection_handle connection handle of this event,
 *                          {@link kUnknownConnectionHandle} if unknown
 * @param direction direction of this connection
 * @param link_type type of the link
 * @param hci_cmd HCI command opecode associated with this event, if any
 * @param hci_event HCI event code associated with this event, if any
 * @param hci_ble_event HCI BLE event code associated with this event, if any
 * @param cmd_status Command status associated with this event, if any
 * @param reason_code Reason code associated with this event, if any
 */
void LogMetricLinkLayerConnectionEvent(
    const RawAddress* address, uint32_t connection_handle,
    android::bluetooth::DirectionEnum direction, uint16_t link_type,
    uint32_t hci_cmd, uint16_t hci_event, uint16_t hci_ble_event,
    uint16_t cmd_status, uint16_t reason_code);

/**
 * Log A2DP audio buffer underrun event
 *
 * @param address A2DP device associated with this event
 * @param encoding_interval_millis encoding interval in milliseconds
 * @param num_missing_pcm_bytes number of PCM bytes that cannot be read from
 *                              the source
 */
void LogMetricA2dpAudioUnderrunEvent(const RawAddress& address,
                                     uint64_t encoding_interval_millis,
                                     int num_missing_pcm_bytes);

/**
 * Log A2DP audio buffer overrun event
 *
 * @param address A2DP device associated with this event
 * @param encoding_interval_millis encoding interval in milliseconds
 * @param num_dropped_buffers number of encoded buffers dropped from Tx queue
 * @param num_dropped_encoded_frames number of encoded frames dropped from Tx
 *                                   queue
 * @param num_dropped_encoded_bytes number of encoded bytes dropped from Tx
 *                                  queue
 */
void LogMetricA2dpAudioOverrunEvent(const RawAddress& address,
                                    uint64_t encoding_interval_millis,
                                    int num_dropped_buffers,
                                    int num_dropped_encoded_frames,
                                    int num_dropped_encoded_bytes);

/**
 * Log A2DP audio playback state changed event
 *
 * @param address A2DP device associated with this event
 * @param playback_state A2DP audio playback state, on/off
 * @param audio_coding_mode A2DP audio codec encoding mode, hw/sw
 */
void LogMetricA2dpPlaybackEvent(const RawAddress& raw_address,
                                int playback_state, int audio_coding_mode);

/**
 * Log read RSSI result
 *
 * @param address device associated with this event
 * @param handle connection handle of this event,
 *               {@link kUnknownConnectionHandle} if unknown
 * @param cmd_status command status from read RSSI command
 * @param rssi rssi value in dBm
 */
void LogMetricReadRssiResult(const RawAddress& address, uint16_t handle,
                             uint32_t cmd_status, int8_t rssi);

/**
 * Log failed contact counter report
 *
 * @param address device associated with this event
 * @param handle connection handle of this event,
 *               {@link kUnknownConnectionHandle} if unknown
 * @param cmd_status command status from read failed contact counter command
 * @param failed_contact_counter Number of consecutive failed contacts for a
 *                               connection corresponding to the Handle
 */
void LogMetricReadFailedContactCounterResult(const RawAddress& address,
                                             uint16_t handle,
                                             uint32_t cmd_status,
                                             int32_t failed_contact_counter);

/**
 * Log transmit power level for a particular device after read
 *
 * @param address device associated with this event
 * @param handle connection handle of this event,
 *               {@link kUnknownConnectionHandle} if unknown
 * @param cmd_status command status from read failed contact counter command
 * @param transmit_power_level transmit power level for connection to this
 *                             device
 */
void LogMetricReadTxPowerLevelResult(const RawAddress& address, uint16_t handle,
                                     uint32_t cmd_status,
                                     int32_t transmit_power_level);

/**
 * Logs when there is an event related to Bluetooth Security Manager Protocol
 *
 * @param address address of associated device
 * @param smp_cmd SMP command code associated with this event
 * @param direction direction of this SMP command
 * @param smp_fail_reason SMP pairing failure reason code from SMP spec
 */
void LogMetricSmpPairingEvent(const RawAddress& address, uint8_t smp_cmd,
                              android::bluetooth::DirectionEnum direction,
                              uint8_t smp_fail_reason);

/**
 * Logs there is an event related Bluetooth classic pairing
 *
 * @param address address of associated device
 * @param handle connection handle of this event,
 *               {@link kUnknownConnectionHandle} if unknown
 * @param hci_cmd HCI command associated with this event
 * @param hci_event HCI event associated with this event
 * @param cmd_status Command status associated with this event
 * @param reason_code Reason code associated with this event
 * @param event_value A status value related to this specific event
 */
void LogMetricClassicPairingEvent(const RawAddress& address, uint16_t handle,
                                  uint32_t hci_cmd, uint16_t hci_event,
                                  uint16_t cmd_status, uint16_t reason_code,
                                  int64_t event_value);

/**
 * Logs when certain Bluetooth SDP attributes are discovered
 *
 * @param address address of associated device
 * @param protocol_uuid 16 bit protocol UUID from Bluetooth Assigned Numbers
 * @param attribute_id 16 bit attribute ID from Bluetooth Assigned Numbers
 * @param attribute_size size of this attribute
 * @param attribute_value pointer to the attribute data, must be larger than
 *                        attribute_size
 */
void LogMetricSdpAttribute(const RawAddress& address, uint16_t protocol_uuid,
                           uint16_t attribute_id, size_t attribute_size,
                           const char* attribute_value);

/**
 * Logs when there is a change in Bluetooth socket connection state
 *
 * @param address address of associated device, empty if this is a server port
 * @param port port of this socket connection
 * @param type type of socket
 * @param connection_state socket connection state
 * @param tx_bytes number of bytes transmitted
 * @param rx_bytes number of bytes received
 * @param server_port server port of this socket, if any. When both
 *        |server_port| and |port| fields are populated, |port| must be spawned
 *        by |server_port|
 * @param socket_role role of this socket, server or connection
 * @param uid socket owner's uid
 */
void LogMetricSocketConnectionState(
    const RawAddress& address, int port, int type,
    android::bluetooth::SocketConnectionstateEnum connection_state,
    int64_t tx_bytes, int64_t rx_bytes, int uid, int server_port,
    android::bluetooth::SocketRoleEnum socket_role);

/**
 * Logs when a Bluetooth device's manufacturer information is learnt
 *
 * @param address address of associated device
 * @param source_type where is this device info obtained from
 * @param source_name name of the data source, internal or external
 * @param manufacturer name of the manufacturer of this device
 * @param model model of this device
 * @param hardware_version hardware version of this device
 * @param software_version software version of this device
 */
void LogMetricManufacturerInfo(
    const RawAddress& address,
    android::bluetooth::DeviceInfoSrcEnum source_type,
    const std::string& source_name, const std::string& manufacturer,
    const std::string& model, const std::string& hardware_version,
    const std::string& software_version);

}  // namespace shim
}  // namespace bluetooth
