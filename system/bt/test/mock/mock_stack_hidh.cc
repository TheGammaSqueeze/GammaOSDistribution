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
 *   Functions generated:11
 */

#include <cstdint>
#include <map>
#include <string>

extern std::map<std::string, int> mock_function_count_map;

#include "stack/include/hiddefs.h"
#include "stack/include/hidh_api.h"
#include "stack/include/sdp_api.h"
#include "types/raw_address.h"

#ifndef UNUSED_ATTR
#define UNUSED_ATTR
#endif

tHID_STATUS HID_HostAddDev(const RawAddress& addr, uint16_t attr_mask,
                           uint8_t* handle) {
  mock_function_count_map[__func__]++;
  return HID_SUCCESS;
}
tHID_STATUS HID_HostCloseDev(uint8_t dev_handle) {
  mock_function_count_map[__func__]++;
  return HID_SUCCESS;
}
tHID_STATUS HID_HostDeregister(void) {
  mock_function_count_map[__func__]++;
  return HID_SUCCESS;
}
tHID_STATUS HID_HostGetSDPRecord(const RawAddress& addr,
                                 tSDP_DISCOVERY_DB* p_db, uint32_t db_len,
                                 tHID_HOST_SDP_CALLBACK* sdp_cback) {
  mock_function_count_map[__func__]++;
  return HID_SUCCESS;
}
tHID_STATUS HID_HostOpenDev(uint8_t dev_handle) {
  mock_function_count_map[__func__]++;
  return HID_SUCCESS;
}
tHID_STATUS HID_HostRegister(tHID_HOST_DEV_CALLBACK* dev_cback) {
  mock_function_count_map[__func__]++;
  return HID_SUCCESS;
}
tHID_STATUS HID_HostRemoveDev(uint8_t dev_handle) {
  mock_function_count_map[__func__]++;
  return HID_SUCCESS;
}
tHID_STATUS HID_HostWriteDev(uint8_t dev_handle, uint8_t t_type, uint8_t param,
                             uint16_t data, uint8_t report_id, BT_HDR* pbuf) {
  mock_function_count_map[__func__]++;
  return HID_SUCCESS;
}
uint8_t HID_HostSetTraceLevel(uint8_t new_level) {
  mock_function_count_map[__func__]++;
  return HID_SUCCESS;
}
void HID_HostInit(void) { mock_function_count_map[__func__]++; }
void hidh_get_str_attr(tSDP_DISC_REC* p_rec, uint16_t attr_id, uint16_t max_len,
                       char* str) {
  mock_function_count_map[__func__]++;
}
