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

#pragma once

#include <cstdint>

#include "stack/include/bt_types.h"
#include "stack/include/hci_error_code.h"
#include "types/bt_transport.h"
#include "types/hci_role.h"
#include "types/raw_address.h"

void BTA_dm_acl_up(const RawAddress bd_addr, tBT_TRANSPORT transport);
void BTA_dm_acl_down(const RawAddress bd_addr, tBT_TRANSPORT transport);
void BTA_dm_report_role_change(const RawAddress bd_addr, tHCI_ROLE new_role,
                               tHCI_STATUS hci_status);
void BTA_dm_notify_remote_features_complete(const RawAddress bd_addr);
