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
 *   Functions generated:7
 */

#include <map>
#include <string>

extern std::map<std::string, int> mock_function_count_map;

#include <cstdint>
#include "bt_target.h"
#include "bta/include/utl.h"
#include "stack/include/btm_api.h"

#ifndef UNUSED_ATTR
#define UNUSED_ATTR
#endif

bool utl_isdialchar(const char d) {
  mock_function_count_map[__func__]++;
  return false;
}
bool utl_isdialstr(const char* p_s) {
  mock_function_count_map[__func__]++;
  return false;
}
bool utl_isintstr(const char* p_s) {
  mock_function_count_map[__func__]++;
  return false;
}
bool utl_set_device_class(tBTA_UTL_COD* p_cod, uint8_t cmd) {
  mock_function_count_map[__func__]++;
  return false;
}
int utl_strucmp(const char* p_s, const char* p_t) {
  mock_function_count_map[__func__]++;
  return 0;
}
int16_t utl_str2int(const char* p_s) {
  mock_function_count_map[__func__]++;
  return 0;
}
uint8_t utl_itoa(uint16_t i, char* p_s) {
  mock_function_count_map[__func__]++;
  return 0;
}
