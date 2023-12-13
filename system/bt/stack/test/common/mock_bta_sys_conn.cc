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

/*
 * Generated mock file from original source file
 *   Functions generated:17
 */

#include <map>
#include <string>

extern std::map<std::string, int> mock_function_count_map;

#include <stddef.h>
#include "bt_common.h"
#include "bta/include/bta_api.h"
#include "bta/include/utl.h"
#include "bta/sys/bta_sys.h"
#include "bta/sys/bta_sys_int.h"
#include "osi/include/osi.h"

#ifndef UNUSED_ATTR
#define UNUSED_ATTR
#endif

void bta_sys_app_close(uint8_t id, uint8_t app_id,
                       const RawAddress& peer_addr) {
  mock_function_count_map[__func__]++;
}
void bta_sys_app_open(uint8_t id, uint8_t app_id, const RawAddress& peer_addr) {
  mock_function_count_map[__func__]++;
}
void bta_sys_busy(uint8_t id, uint8_t app_id, const RawAddress& peer_addr) {
  mock_function_count_map[__func__]++;
}
void bta_sys_collision_register(uint8_t bta_id, tBTA_SYS_CONN_CBACK* p_cback) {
  mock_function_count_map[__func__]++;
}
void bta_sys_conn_close(uint8_t id, uint8_t app_id,
                        const RawAddress& peer_addr) {
  mock_function_count_map[__func__]++;
}
void bta_sys_conn_open(uint8_t id, uint8_t app_id,
                       const RawAddress& peer_addr) {
  mock_function_count_map[__func__]++;
}
void bta_sys_idle(uint8_t id, uint8_t app_id, const RawAddress& peer_addr) {
  mock_function_count_map[__func__]++;
}
void bta_sys_notify_collision(const RawAddress& peer_addr) {
  mock_function_count_map[__func__]++;
}
void bta_sys_notify_role_chg(const RawAddress& peer_addr, uint8_t new_role,
                             tHCI_STATUS hci_status) {
  mock_function_count_map[__func__]++;
}
void bta_sys_pm_register(tBTA_SYS_CONN_CBACK* p_cback) {
  mock_function_count_map[__func__]++;
}
void bta_sys_rm_register(tBTA_SYS_CONN_CBACK* p_cback) {
  mock_function_count_map[__func__]++;
}
void bta_sys_role_chg_register(tBTA_SYS_CONN_CBACK* p_cback) {
  mock_function_count_map[__func__]++;
}
void bta_sys_sco_close(uint8_t id, uint8_t app_id,
                       const RawAddress& peer_addr) {
  mock_function_count_map[__func__]++;
}
void bta_sys_sco_open(uint8_t id, uint8_t app_id, const RawAddress& peer_addr) {
  mock_function_count_map[__func__]++;
}
void bta_sys_sco_register(tBTA_SYS_CONN_CBACK* p_cback) {
  mock_function_count_map[__func__]++;
}
void bta_sys_sco_unuse(uint8_t id, uint8_t app_id,
                       const RawAddress& peer_addr) {
  mock_function_count_map[__func__]++;
}
void bta_sys_sco_use(UNUSED_ATTR uint8_t id, uint8_t app_id,
                     const RawAddress& peer_addr) {
  mock_function_count_map[__func__]++;
}
