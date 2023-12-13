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

#include "stack/include/btm_api_types.h"
#include "stack/include/btm_ble_api_types.h"
#include "stack/include/hci_error_code.h"

/****************************************
 *  Security Manager Callback Functions
 ****************************************/
/* Authorize device for service.  Parameters are
 *              Service Id (NULL - unknown service or unused
 *                                 [BTM_SEC_SERVICE_NAME_LEN set to 0])
 */
typedef uint8_t(tBTM_AUTHORIZE_CALLBACK)(uint8_t service_id);

/* Get PIN for the connection.  Parameters are
 *              BD Address of remote
 *              Device Class of remote
 *              BD Name of remote
 *              Flag indicating the minimum pin code length to be 16 digits
 */
typedef uint8_t(tBTM_PIN_CALLBACK)(const RawAddress& bd_addr,
                                   DEV_CLASS dev_class, tBTM_BD_NAME bd_name,
                                   bool min_16_digit);

/* New Link Key for the connection.  Parameters are
 *              BD Address of remote
 *              Link Key
 *              Key Type: Combination, Local Unit, or Remote Unit
 */
typedef uint8_t(tBTM_LINK_KEY_CALLBACK)(const RawAddress& bd_addr,
                                        DEV_CLASS dev_class,
                                        tBTM_BD_NAME bd_name,
                                        const LinkKey& key, uint8_t key_type);

/* Remote Name Resolved.  Parameters are
 *              BD Address of remote
 *              BD Name of remote
 */
typedef void(tBTM_RMT_NAME_CALLBACK)(const RawAddress& bd_addr, DEV_CLASS dc,
                                     tBTM_BD_NAME bd_name);

/* Authentication complete for the connection.  Parameters are
 *              BD Address of remote
 *              Device Class of remote
 *              BD Name of remote
 *
 */
typedef void(tBTM_AUTH_COMPLETE_CALLBACK)(const RawAddress& bd_addr,
                                          DEV_CLASS dev_class,
                                          tBTM_BD_NAME bd_name,
                                          tHCI_REASON reason);

struct tBTM_APPL_INFO {
  tBTM_PIN_CALLBACK* p_pin_callback{nullptr};
  tBTM_LINK_KEY_CALLBACK* p_link_key_callback{nullptr};
  tBTM_AUTH_COMPLETE_CALLBACK* p_auth_complete_callback{nullptr};
  tBTM_BOND_CANCEL_CMPL_CALLBACK* p_bond_cancel_cmpl_callback{nullptr};
  tBTM_SP_CALLBACK* p_sp_callback{nullptr};
  tBTM_LE_CALLBACK* p_le_callback{nullptr};
  tBTM_LE_KEY_CALLBACK* p_le_key_callback{nullptr};
};
