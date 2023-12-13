/*
 *  Copyright 2020 The Android Open Source Project
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#pragma once

#include <cstdint>

#include "stack/include/bt_types.h"
#include "stack/include/btm_api_types.h"
#include "types/raw_address.h"

// This header contains functions for HCIF-Security Management to invoke
//

void btm_create_conn_cancel_complete(uint8_t* p);
void btm_create_conn_cancel_complete(uint8_t* p);
void btm_io_capabilities_req(const RawAddress& p);
void btm_io_capabilities_rsp(uint8_t* p);
void btm_proc_sp_req_evt(tBTM_SP_EVT event, uint8_t* p);
void btm_read_inq_tx_power_complete(uint8_t* p);
void btm_read_local_oob_complete(uint8_t* p);
void btm_rem_oob_req(uint8_t* p);
void btm_sec_auth_complete(uint16_t handle, tHCI_STATUS status);
void btm_sec_disconnected(uint16_t handle, tHCI_STATUS reason);
void btm_sec_encrypt_change(uint16_t handle, tHCI_STATUS status,
                            uint8_t encr_enable);
void btm_sec_link_key_notification(const RawAddress& p_bda,
                                   const Octet16& link_key, uint8_t key_type);
void btm_sec_link_key_request(uint8_t* p_event);
void btm_sec_pin_code_request(uint8_t* p_event);
void btm_sec_rmt_host_support_feat_evt(uint8_t* p);
void btm_sec_rmt_name_request_complete(const RawAddress* bd_addr,
                                       uint8_t* bd_name, tHCI_STATUS status);
void btm_sec_update_clock_offset(uint16_t handle, uint16_t clock_offset);
void btm_simple_pair_complete(uint8_t* p);
