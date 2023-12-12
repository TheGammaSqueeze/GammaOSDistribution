/******************************************************************************
 *
 *  Copyright (C) 2009-2012 Broadcom Corporation
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
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "bt_utils.h"
#include "bta_api.h"
#include "bta_dm_ci.h"
#include "bta_dm_co.h"
#include "bta_sys.h"
#include "bte_appl.h"
#include "btif_dm.h"
#include "btif_storage.h"
#include "osi/include/osi.h"

// tBTE_APPL_CFG.ble_io_cap is set to BTM_IO_CAP_UNKNOWN at structure
// initialization since btif_storage isn't ready yet for data to be fetched.
// This value is initialized properly during first use by fetching properly
// from btif_storage.
tBTE_APPL_CFG bte_appl_cfg = {
    BTA_LE_AUTH_REQ_SC_MITM_BOND,  // Authentication requirements
    BTM_IO_CAP_UNKNOWN, BTM_BLE_INITIATOR_KEY_SIZE, BTM_BLE_RESPONDER_KEY_SIZE,
    BTM_BLE_MAX_KEY_SIZE};

/*******************************************************************************
 *
 * Function         bta_dm_co_get_compress_memory
 *
 * Description      This callout function is executed by DM to get memory for
 compression

 * Parameters       id  -  BTA SYS ID
 *                  memory_p - memory return by callout
 *                  memory_size - memory size
 *
 * Returns          true for success, false for fail.
 *
 ******************************************************************************/
bool bta_dm_co_get_compress_memory(UNUSED_ATTR tBTA_SYS_ID id,
                                   UNUSED_ATTR uint8_t** memory_p,
                                   UNUSED_ATTR uint32_t* memory_size) {
  return true;
}

/*******************************************************************************
 *
 * Function         bta_dm_co_lk_upgrade
 *
 * Description      This callout function is executed by DM to check if the
 *                  platform wants allow link key upgrade
 *
 * Parameters       bd_addr  - The peer device
 *                  *p_upgrade - true, if link key upgrade is desired.
 *
 * Returns          void.
 *
 ******************************************************************************/
void bta_dm_co_lk_upgrade(UNUSED_ATTR const RawAddress& bd_addr,
                          UNUSED_ATTR bool* p_upgrade) {}

// REMOVE FOR BLUEDROID ?

#if (BTM_SCO_HCI_INCLUDED == TRUE) && (BTM_SCO_INCLUDED == TRUE)

/*******************************************************************************
 *
 * Function         btui_sco_codec_callback
 *
 * Description      Callback for btui codec.
 *
 *
 * Returns          void
 *
 ******************************************************************************/
static void btui_sco_codec_callback(uint16_t event, uint16_t sco_handle) {
  bta_dm_sco_ci_data_ready(event, sco_handle);
}

/*******************************************************************************
 *
 * Function         bta_dm_sco_co_open
 *
 * Description      This function is executed when a SCO connection is open.
 *
 *
 * Returns          void
 *
 ******************************************************************************/
void bta_dm_sco_co_open(uint16_t handle, uint8_t pkt_size, uint16_t event) {
  tBTUI_SCO_CODEC_CFG cfg;

  if (btui_cb.sco_hci) {
    BTIF_TRACE_DEBUG("bta_dm_sco_co_open handle:%d pkt_size:%d", handle,
                     pkt_size);
    cfg.p_cback = btui_sco_codec_callback;
    cfg.pkt_size = pkt_size;
    cfg.cb_event = event;
    /* open and start the codec */
    btui_sco_codec_open(&cfg);
    btui_sco_codec_start(handle);
  }
}

/*******************************************************************************
 *
 * Function         bta_dm_sco_co_close
 *
 * Description      This function is called when a SCO connection is closed
 *
 *
 * Returns          void
 *
 ******************************************************************************/
void bta_dm_sco_co_close(void) {
  if (btui_cb.sco_hci) {
    BTIF_TRACE_DEBUG("bta_dm_sco_co_close close codec");
    /* close sco codec */
    btui_sco_codec_close();

    btui_cb.sco_hci = false;
  }
}

/*******************************************************************************
 *
 * Function         bta_dm_sco_co_in_data
 *
 * Description      This function is called to send incoming SCO data to
 *                  application.
 *
 * Returns          void
 *
 ******************************************************************************/
void bta_dm_sco_co_in_data(BT_HDR* p_buf) {
  if (btui_cfg.sco_use_mic)
    btui_sco_codec_inqdata(p_buf);
  else
    osi_free(p_buf);
}

/*******************************************************************************
 *
 * Function         bta_dm_sco_co_out_data
 *
 * Description      This function is called to send SCO data over HCI.
 *
 * Returns          void
 *
 ******************************************************************************/
void bta_dm_sco_co_out_data(BT_HDR** p_buf) { btui_sco_codec_readbuf(p_buf); }

#endif /* (BTM_SCO_HCI_INCLUDED == TRUE) && (BTM_SCO_INCLUDED == TRUE)*/

/*******************************************************************************
 *
 * Function         bta_dm_co_le_io_key_req
 *
 * Description      This callout function is executed by DM to get BLE key
 *                  information
 *                  before SMP pairing gets going.
 *
 * Parameters       bd_addr  - The peer device
 *                  *p_max_key_size - max key size local device supported.
 *                  *p_init_key - initiator keys.
 *                  *p_resp_key - responder keys.
 *
 * Returns          void.
 *
 ******************************************************************************/
void bta_dm_co_le_io_key_req(UNUSED_ATTR const RawAddress& bd_addr,
                             uint8_t* p_max_key_size,
                             tBTA_LE_KEY_TYPE* p_init_key,
                             tBTA_LE_KEY_TYPE* p_resp_key) {
  BTIF_TRACE_ERROR("##################################");
  BTIF_TRACE_ERROR("bta_dm_co_le_io_key_req: only setting max size to 16");
  BTIF_TRACE_ERROR("##################################");
  *p_max_key_size = 16;
  *p_init_key = *p_resp_key =
      (BTA_LE_KEY_PENC | BTA_LE_KEY_PID | BTA_LE_KEY_PCSRK | BTA_LE_KEY_LENC |
       BTA_LE_KEY_LID | BTA_LE_KEY_LCSRK);
}

/*******************************************************************************
 *
 * Function         bta_dm_co_ble_local_key_reload
 *
 * Description      This callout function is to load the local BLE keys if
 *                  available on the device.
 *
 * Parameters       none
 *
 * Returns          void.
 *
 ******************************************************************************/
void bta_dm_co_ble_load_local_keys(tBTA_DM_BLE_LOCAL_KEY_MASK* p_key_mask,
                                   Octet16* p_er,
                                   tBTA_BLE_LOCAL_ID_KEYS* p_id_keys) {
  BTIF_TRACE_DEBUG("##################################");
  BTIF_TRACE_DEBUG(
      "bta_dm_co_ble_load_local_keys:  Load local keys if any are persisted");
  BTIF_TRACE_DEBUG("##################################");
  btif_dm_get_ble_local_keys(p_key_mask, p_er, p_id_keys);
}

/*******************************************************************************
 *
 * Function         bta_dm_co_ble_io_req
 *
 * Description      This callout function is executed by DM to get BLE IO
 *                  capabilities before SMP pairing gets going.
 *
 * Parameters       bd_addr  - The peer device
 *                  *p_io_cap - The local Input/Output capabilities
 *                  *p_oob_data - true, if OOB data is available for the peer
 *                                device.
 *                  *p_auth_req -  Auth request setting (Bonding and MITM
 *                                 required or not)
 *                  *p_max_key_size - max key size local device supported.
 *                  *p_init_key - initiator keys.
 *                  *p_resp_key - responder keys.
 *
 * Returns          void.
 *
 ******************************************************************************/
void bta_dm_co_ble_io_req(const RawAddress& bd_addr, tBTA_IO_CAP* p_io_cap,
                          tBTA_OOB_DATA* p_oob_data,
                          tBTA_LE_AUTH_REQ* p_auth_req, uint8_t* p_max_key_size,
                          tBTA_LE_KEY_TYPE* p_init_key,
                          tBTA_LE_KEY_TYPE* p_resp_key) {
  bte_appl_cfg.ble_io_cap = btif_storage_get_local_io_caps_ble();

  /* Retrieve the properties from file system if possible */
  tBTE_APPL_CFG nv_config;
  if (btif_dm_get_smp_config(&nv_config)) bte_appl_cfg = nv_config;

  /* *p_auth_req by default is false for devices with NoInputNoOutput; true for
   * other devices. */

  if (bte_appl_cfg.ble_auth_req)
    *p_auth_req = bte_appl_cfg.ble_auth_req |
                  (bte_appl_cfg.ble_auth_req & 0x04) | ((*p_auth_req) & 0x04);

  /* if OOB is not supported, this call-out function does not need to do
   * anything
   * otherwise, look for the OOB data associated with the address and set
   * *p_oob_data accordingly.
   * If the answer can not be obtained right away,
   * set *p_oob_data to BTA_OOB_UNKNOWN and call bta_dm_ci_io_req() when the
   * answer is available.
   */

  btif_dm_set_oob_for_le_io_req(bd_addr, p_oob_data, p_auth_req);

  if (bte_appl_cfg.ble_io_cap <= 4) *p_io_cap = bte_appl_cfg.ble_io_cap;

  if (bte_appl_cfg.ble_init_key <= BTM_BLE_INITIATOR_KEY_SIZE)
    *p_init_key = bte_appl_cfg.ble_init_key;

  if (bte_appl_cfg.ble_resp_key <= BTM_BLE_RESPONDER_KEY_SIZE)
    *p_resp_key = bte_appl_cfg.ble_resp_key;

  if (bte_appl_cfg.ble_max_key_size > 7 && bte_appl_cfg.ble_max_key_size <= 16)
    *p_max_key_size = bte_appl_cfg.ble_max_key_size;
}
