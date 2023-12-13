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

#include <cstdint>

#include "types/raw_address.h"

extern void btm_delete_stored_link_key_complete(uint8_t* p);
extern void btm_vendor_specific_evt(uint8_t* p, uint8_t evt_len);
extern void btm_vsc_complete(uint8_t* p, uint16_t cc_opcode, uint16_t evt_len,
                             tBTM_VSC_CMPL_CB* p_vsc_cplt_cback);
extern void btm_read_local_name_complete(uint8_t* p, uint16_t evt_len);
