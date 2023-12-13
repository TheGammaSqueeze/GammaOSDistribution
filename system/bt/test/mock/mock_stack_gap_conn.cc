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

/*
 * Generated mock file from original source file
 *   Functions generated:13
 */

#include <map>
#include <string>

extern std::map<std::string, int> mock_function_count_map;

#include <base/strings/stringprintf.h>
#include <string.h>
#include "bt_target.h"
#include "device/include/controller.h"
#include "gap_api.h"
#include "l2c_api.h"
#include "l2cdefs.h"
#include "osi/include/fixed_queue.h"
#include "osi/include/mutex.h"
#include "stack/btm/btm_sec.h"

#ifndef UNUSED_ATTR
#define UNUSED_ATTR
#endif

const RawAddress* GAP_ConnGetRemoteAddr(uint16_t gap_handle) {
  mock_function_count_map[__func__]++;
  return nullptr;
}
int GAP_GetRxQueueCnt(uint16_t handle, uint32_t* p_rx_queue_count) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t GAP_ConnClose(uint16_t gap_handle) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t GAP_ConnGetL2CAPCid(uint16_t gap_handle) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t GAP_ConnGetRemMtuSize(uint16_t gap_handle) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t GAP_ConnOpen(const char* p_serv_name, uint8_t service_id,
                      bool is_server, const RawAddress* p_rem_bda, uint16_t psm,
                      uint16_t le_mps, tL2CAP_CFG_INFO* p_cfg,
                      tL2CAP_ERTM_INFO* ertm_info, uint16_t security,
                      tGAP_CONN_CALLBACK* p_cb, tBT_TRANSPORT transport) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t GAP_ConnReadData(uint16_t gap_handle, uint8_t* p_data,
                          uint16_t max_len, uint16_t* p_len) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t GAP_ConnWriteData(uint16_t gap_handle, BT_HDR* msg) {
  mock_function_count_map[__func__]++;
  return 0;
}
void GAP_Init(void) { mock_function_count_map[__func__]++; }
void gap_tx_complete_ind(uint16_t l2cap_cid, uint16_t sdu_sent) {
  mock_function_count_map[__func__]++;
}
