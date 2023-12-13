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
 *   Functions generated:26
 */

#include <map>
#include <string>

extern std::map<std::string, int> mock_function_count_map;

#include <string.h>
#include "avdt_api.h"
#include "avdtc_api.h"
#include "bt_target.h"
#include "bt_types.h"
#include "bta/include/bta_api.h"
#include "btm_api.h"
#include "btu.h"
#include "l2c_api.h"
#include "main/shim/dumpsys.h"
#include "osi/include/log.h"
#include "stack/avdt/avdt_int.h"
#include "stack/btm/btm_sec.h"
#include "stack/include/a2dp_codec_api.h"

#ifndef UNUSED_ATTR
#define UNUSED_ATTR
#endif

uint16_t AVDT_CloseReq(uint8_t handle) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_ConfigRsp(uint8_t handle, uint8_t label, uint8_t error_code,
                        uint8_t category) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_ConnectReq(const RawAddress& bd_addr, uint8_t channel_index,
                         tAVDT_CTRL_CBACK* p_cback) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_CreateStream(uint8_t peer_id, uint8_t* p_handle,
                           const AvdtpStreamConfig& avdtp_stream_config) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_DelayReport(uint8_t handle, uint8_t seid, uint16_t delay) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_DisconnectReq(const RawAddress& bd_addr,
                            tAVDT_CTRL_CBACK* p_cback) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_DiscoverReq(const RawAddress& bd_addr, uint8_t channel_index,
                          tAVDT_SEP_INFO* p_sep_info, uint8_t max_seps,
                          tAVDT_CTRL_CBACK* p_cback) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_GetCapReq(const RawAddress& bd_addr, uint8_t channel_index,
                        uint8_t seid, AvdtpSepConfig* p_cfg,
                        tAVDT_CTRL_CBACK* p_cback, bool get_all_cap) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_GetL2CapChannel(uint8_t handle) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_OpenReq(uint8_t handle, const RawAddress& bd_addr,
                      uint8_t channel_index, uint8_t seid,
                      AvdtpSepConfig* p_cfg) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_ReconfigReq(uint8_t handle, AvdtpSepConfig* p_cfg) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_RemoveStream(uint8_t handle) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_SecurityReq(uint8_t handle, uint8_t* p_data, uint16_t len) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_SecurityRsp(uint8_t handle, uint8_t label, uint8_t error_code,
                          uint8_t* p_data, uint16_t len) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_StartReq(uint8_t* p_handles, uint8_t num_handles) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_SuspendReq(uint8_t* p_handles, uint8_t num_handles) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint16_t AVDT_WriteReqOpt(uint8_t handle, BT_HDR* p_pkt, uint32_t time_stamp,
                          uint8_t m_pt, tAVDT_DATA_OPT_MASK opt) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint8_t AVDT_SetTraceLevel(uint8_t new_level) {
  mock_function_count_map[__func__]++;
  return 0;
}
void AVDT_AbortReq(uint8_t handle) { mock_function_count_map[__func__]++; }
void AVDT_Deregister(void) { mock_function_count_map[__func__]++; }
void AVDT_Register(AvdtpRcb* p_reg, tAVDT_CTRL_CBACK* p_cback) {
  mock_function_count_map[__func__]++;
}
void avdt_ccb_idle_ccb_timer_timeout(void* data) {
  mock_function_count_map[__func__]++;
}
void avdt_ccb_ret_ccb_timer_timeout(void* data) {
  mock_function_count_map[__func__]++;
}
void avdt_ccb_rsp_ccb_timer_timeout(void* data) {
  mock_function_count_map[__func__]++;
}
void avdt_scb_transport_channel_timer_timeout(void* data) {
  mock_function_count_map[__func__]++;
}
void stack_debug_avdtp_api_dump(int fd) { mock_function_count_map[__func__]++; }
